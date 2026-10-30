//! Shared pointer-free contracts. Native transforms are deliberately a different type.
#![forbid(unsafe_code)]
use std::fmt;

pub const TARGET_SHA256: [u8; 32] = [
    0x43, 0x81, 0x4d, 0x4b, 0x32, 0x92, 0xef, 0xd0, 0xa0, 0x7f, 0xd7, 0x1b, 0xef, 0x2f, 0x16, 0x70,
    0xc0, 0xe5, 0xac, 0x7c, 0xf2, 0x59, 0x5c, 0x9e, 0x13, 0x6d, 0x78, 0x45, 0x13, 0x80, 0xa6, 0x64,
];
include!("compatibility.rs");
pub const MAX_ENTITIES: usize = 2048;
pub const MAX_DATAGRAM: usize = 1200;
pub const POSES_PER_CHUNK: usize = 20;
pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Error {
    Invalid(&'static str),
    Bounds(&'static str),
    Phase,
    Authority,
    Epoch,
    Duplicate,
    Stale,
    Gap,
    Exhausted,
    Conflict,
    WrongThread,
    BuildMismatch,
    Unavailable,
    Unsupported(&'static str),
}
impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{self:?}")
    }
}
impl std::error::Error for Error {}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
#[repr(u8)]
pub enum Slot {
    Host = 0,
    Guest = 1,
}
impl TryFrom<u8> for Slot {
    type Error = Error;
    fn try_from(v: u8) -> Result<Self> {
        match v {
            0 => Ok(Self::Host),
            1 => Ok(Self::Guest),
            _ => Err(Error::Invalid("slot")),
        }
    }
}
impl Slot {
    pub fn index(self) -> usize {
        self as usize
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum Role {
    Host = 0,
    Guest = 1,
}
impl Role {
    pub fn slot(self) -> Slot {
        match self {
            Self::Host => Slot::Host,
            Self::Guest => Slot::Guest,
        }
    }
    pub fn peer(self) -> Self {
        match self {
            Self::Host => Self::Guest,
            Self::Guest => Self::Host,
        }
    }
}
impl TryFrom<u8> for Role {
    type Error = Error;
    fn try_from(v: u8) -> Result<Self> {
        match v {
            0 => Ok(Self::Host),
            1 => Ok(Self::Guest),
            _ => Err(Error::Invalid("role")),
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct Epoch(u32);
impl Epoch {
    pub const FIRST: Self = Self(1);
    pub fn new(v: u32) -> Result<Self> {
        if v == 0 {
            Err(Error::Epoch)
        } else {
            Ok(Self(v))
        }
    }
    pub fn get(self) -> u32 {
        self.0
    }
    pub fn next(self) -> Result<Self> {
        self.0.checked_add(1).map(Self).ok_or(Error::Exhausted)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct EntityId {
    epoch: Epoch,
    serial: u32,
}
impl EntityId {
    pub fn new(epoch: Epoch, serial: u32) -> Result<Self> {
        if serial == 0 {
            Err(Error::Invalid("entity serial"))
        } else {
            Ok(Self { epoch, serial })
        }
    }
    pub fn epoch(self) -> Epoch {
        self.epoch
    }
    pub fn serial(self) -> u32 {
        self.serial
    }
    pub fn require_epoch(self, expected: Epoch) -> Result<()> {
        if self.epoch == expected {
            Ok(())
        } else {
            Err(Error::Epoch)
        }
    }
}

/// RFC-style serial comparison: exactly half of the range is ambiguous, never "new".
pub fn forward_distance(new: u32, old: u32) -> Result<u32> {
    let d = new.wrapping_sub(old);
    match d {
        0 => Err(Error::Duplicate),
        0x8000_0000 => Err(Error::Invalid("ambiguous serial")),
        1..=0x7fff_ffff => Ok(d),
        _ => Err(Error::Stale),
    }
}
pub fn signed_tick_distance(tick: u32, now: u32) -> Result<i32> {
    let d = tick.wrapping_sub(now);
    if d == 0x8000_0000 {
        Err(Error::Invalid("ambiguous tick"))
    } else {
        Ok(d as i32)
    }
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct Controls {
    pub axes: [i16; 4],
    pub buttons: u16,
    pub triggers: [u8; 2],
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct InputSample {
    pub sequence: u32,
    pub slot: Slot,
    pub controls: Controls,
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Pose {
    pub id: EntityId,
    pub position: [f32; 3],
    pub orientation: [f32; 4],
    pub velocity: [f32; 3],
    pub flags: u32,
}
impl Pose {
    pub fn validate(&self) -> Result<()> {
        if self
            .position
            .iter()
            .chain(self.orientation.iter())
            .chain(self.velocity.iter())
            .any(|x| !x.is_finite())
        {
            return Err(Error::Invalid("non-finite pose"));
        }
        let norm: f32 = self.orientation.iter().map(|x| x * x).sum();
        if !(0.999..=1.001).contains(&norm) {
            return Err(Error::Invalid("non-unit network quaternion"));
        }
        Ok(())
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Agreement {
    pub build: [u8; 32],
    pub patch: [u8; 32],
    pub content: [u8; 32],
    pub mission: u32,
    pub difficulty: u8,
}
impl Agreement {
    pub fn compatible(self, other: Self) -> Result<()> {
        if self.build != TARGET_SHA256 || other.build != TARGET_SHA256 {
            return Err(Error::BuildMismatch);
        }
        if self.patch != PATCH_COMPATIBILITY || other.patch != PATCH_COMPATIBILITY {
            return Err(Error::Conflict);
        }
        if self != other {
            return Err(Error::Conflict);
        }
        Ok(())
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Verdict {
    Success,
    Failure,
    Abort,
}
impl TryFrom<u8> for Verdict {
    type Error = Error;
    fn try_from(v: u8) -> Result<Self> {
        match v {
            0 => Ok(Self::Success),
            1 => Ok(Self::Failure),
            2 => Ok(Self::Abort),
            _ => Err(Error::Invalid("verdict")),
        }
    }
}
impl Verdict {
    pub fn wire(self) -> u8 {
        match self {
            Self::Success => 0,
            Self::Failure => 1,
            Self::Abort => 2,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn slots_and_epochs_are_bounded() {
        assert_eq!(Slot::try_from(2), Err(Error::Invalid("slot")));
        assert_eq!(Epoch::new(0), Err(Error::Epoch));
        assert_eq!(Epoch::new(u32::MAX).unwrap().next(), Err(Error::Exhausted));
        assert_eq!(
            EntityId::new(Epoch::FIRST, 0),
            Err(Error::Invalid("entity serial"))
        );
        assert_eq!(
            EntityId::new(Epoch::FIRST, 7)
                .unwrap()
                .require_epoch(Epoch::FIRST.next().unwrap()),
            Err(Error::Epoch)
        );
    }
    #[test]
    fn serial_wrap_and_half_range() {
        assert_eq!(forward_distance(0, u32::MAX), Ok(1));
        assert_eq!(forward_distance(7, 7), Err(Error::Duplicate));
        assert_eq!(forward_distance(5, 7), Err(Error::Stale));
        assert!(forward_distance(0x8000_0000, 0).is_err());
        assert_eq!(signed_tick_distance(0, u32::MAX), Ok(1));
        assert_eq!(signed_tick_distance(u32::MAX, 0), Ok(-1));
    }
    #[test]
    fn network_pose_rejects_nan_and_degenerate_orientation() {
        let mut p = Pose {
            id: EntityId::new(Epoch::FIRST, 1).unwrap(),
            position: [0.; 3],
            orientation: [0., 0., 0., 1.],
            velocity: [0.; 3],
            flags: 0,
        };
        assert!(p.validate().is_ok());
        p.position[0] = f32::NAN;
        assert!(p.validate().is_err());
        p.position[0] = 0.;
        p.orientation = [0., 0., 0., 0.8];
        assert!(p.validate().is_err());
        p.orientation = [0.; 4];
        assert!(p.validate().is_err());
        p.orientation = [f32::INFINITY; 4];
        assert!(p.validate().is_err());
    }
    #[test]
    fn agreement_requires_target_and_identical_content() {
        let a = Agreement {
            build: TARGET_SHA256,
            patch: PATCH_COMPATIBILITY,
            content: [3; 32],
            mission: 1,
            difficulty: 2,
        };
        assert_eq!(a.compatible(a), Ok(()));
        assert_eq!(
            a.compatible(Agreement {
                content: [4; 32],
                ..a
            }),
            Err(Error::Conflict)
        );
        assert_eq!(
            a.compatible(Agreement {
                build: [0; 32],
                ..a
            }),
            Err(Error::BuildMismatch)
        );
    }
}
