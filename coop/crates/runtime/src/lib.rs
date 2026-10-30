//! ReShade observer loader. Portable installation/configuration logic is separately testable.
use acz_coop_contracts::{Error, Result};
#[cfg(all(windows, target_arch = "x86_64"))]
mod windows;

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct ObserverConfig {
    pub hooks: bool,
}
impl ObserverConfig {
    pub fn parse(text: &str) -> Result<Self> {
        if text.len() > 4096 {
            return Err(Error::Bounds("observer config"));
        }
        let mut value = None;
        for line in text.lines() {
            let line = line.trim();
            if line.is_empty() || line.starts_with('#') {
                continue;
            }
            let (key, v) = line
                .split_once('=')
                .ok_or(Error::Invalid("observer config"))?;
            if key.trim() != "observer_hooks" {
                return Err(Error::Invalid("unknown observer option"));
            }
            if value.is_some() {
                return Err(Error::Conflict);
            }
            value = Some(match v.trim() {
                "true" => true,
                "false" => false,
                _ => return Err(Error::Invalid("observer boolean")),
            });
        }
        Ok(Self {
            hooks: value.unwrap_or(false),
        })
    }
}

pub trait HookBackend {
    fn create(&mut self, index: usize) -> Result<()>;
    fn discard_unenabled(&mut self, index: usize) -> Result<()>;
    fn enable_all(&mut self) -> Result<()>;
    fn disable_all(&mut self) -> Result<()>;
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum InstallPhase {
    Dormant,
    Active,
    Stopped,
    Failed,
}
pub struct HookPlan {
    phase: InstallPhase,
    retained: bool,
}
impl Default for HookPlan {
    fn default() -> Self {
        Self {
            phase: InstallPhase::Dormant,
            retained: false,
        }
    }
}
impl HookPlan {
    pub fn phase(&self) -> InstallPhase {
        self.phase
    }
    /// Once enable was attempted, trampoline/module lifetime is process-long.
    pub fn retained(&self) -> bool {
        self.retained
    }
    pub fn install(&mut self, b: &mut impl HookBackend, count: usize) -> Result<()> {
        if self.phase != InstallPhase::Dormant {
            return Err(Error::Phase);
        }
        if !(1..=16).contains(&count) {
            return Err(Error::Bounds("hook count"));
        }
        for i in 0..count {
            if let Err(e) = b.create(i) {
                for j in (0..i).rev() {
                    if b.discard_unenabled(j).is_err() {
                        self.retained = true;
                    }
                }
                self.phase = InstallPhase::Failed;
                return Err(e);
            }
        }
        self.retained = true;
        if let Err(e) = b.enable_all() {
            let _ = b.disable_all();
            self.phase = InstallPhase::Failed;
            return Err(e);
        }
        self.phase = InstallPhase::Active;
        Ok(())
    }
    /// Call only outside loader lock. Never destroys potentially in-flight trampolines.
    pub fn stop(&mut self, b: &mut impl HookBackend) -> Result<()> {
        if self.phase != InstallPhase::Active {
            return Err(Error::Phase);
        }
        if let Err(e) = b.disable_all() {
            self.phase = InstallPhase::Failed;
            return Err(e);
        }
        self.phase = InstallPhase::Stopped;
        Ok(())
    }
}
#[cfg(test)]
mod tests {
    use super::*;
    #[derive(Default)]
    struct Fake {
        calls: Vec<String>,
        fail_create: Option<usize>,
        fail_enable: bool,
    }
    impl HookBackend for Fake {
        fn create(&mut self, i: usize) -> Result<()> {
            self.calls.push(format!("create{i}"));
            if self.fail_create == Some(i) {
                Err(Error::Unavailable)
            } else {
                Ok(())
            }
        }
        fn discard_unenabled(&mut self, i: usize) -> Result<()> {
            self.calls.push(format!("discard{i}"));
            Ok(())
        }
        fn enable_all(&mut self) -> Result<()> {
            self.calls.push("enable".into());
            if self.fail_enable {
                Err(Error::Unavailable)
            } else {
                Ok(())
            }
        }
        fn disable_all(&mut self) -> Result<()> {
            self.calls.push("disable".into());
            Ok(())
        }
    }
    #[test]
    fn config_defaults_off_and_rejects_ambiguity() {
        assert!(!ObserverConfig::parse("# optional\n").unwrap().hooks);
        assert!(
            ObserverConfig::parse("observer_hooks = true")
                .unwrap()
                .hooks
        );
        assert!(ObserverConfig::parse("observer_hooks=true\nobserver_hooks=false").is_err());
        assert!(ObserverConfig::parse("other=true").is_err());
    }
    #[test]
    fn create_failure_rolls_back_without_enabling() {
        let mut b = Fake {
            fail_create: Some(2),
            ..Default::default()
        };
        let mut p = HookPlan::default();
        assert!(p.install(&mut b, 4).is_err());
        assert_eq!(
            b.calls,
            ["create0", "create1", "create2", "discard1", "discard0"]
        );
        assert!(!p.retained());
        assert_eq!(p.phase(), InstallPhase::Failed);
    }
    #[test]
    fn enable_failure_retains_trampolines_and_disables_only_owned_plan() {
        let mut b = Fake {
            fail_enable: true,
            ..Default::default()
        };
        let mut p = HookPlan::default();
        assert!(p.install(&mut b, 4).is_err());
        assert!(p.retained());
        assert_eq!(&b.calls[4..], ["enable", "disable"]);
        assert!(!b.calls.iter().any(|v| v.starts_with("discard")));
    }
    #[test]
    fn successful_plan_is_not_reentrant() {
        let mut b = Fake::default();
        let mut p = HookPlan::default();
        p.install(&mut b, 4).unwrap();
        assert_eq!(p.install(&mut b, 4), Err(Error::Phase));
        p.stop(&mut b).unwrap();
        assert_eq!(p.phase(), InstallPhase::Stopped);
        assert_eq!(p.stop(&mut b), Err(Error::Phase));
        assert!(p.retained());
    }
}
