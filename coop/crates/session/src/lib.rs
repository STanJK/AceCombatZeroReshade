//! Pure authority/lifecycle and exactly-once input selection. No socket or native object.
#![forbid(unsafe_code)]
use acz_coop_contracts::*;
use std::collections::VecDeque;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Phase {
    Lobby,
    Preparing,
    Armed,
    Playing,
    Paused,
    Result,
    Recovering,
}
pub struct Session {
    role: Role,
    phase: Phase,
    epoch: Option<Epoch>,
    agreement: Option<Agreement>,
    ready: u8,
    verdict: Option<Verdict>,
    save_taken: bool,
}
pub struct SavePermit {
    epoch: Epoch,
}
impl SavePermit {
    pub fn epoch(&self) -> Epoch {
        self.epoch
    }
}
impl Session {
    pub fn new(role: Role) -> Self {
        Self {
            role,
            phase: Phase::Lobby,
            epoch: None,
            agreement: None,
            ready: 0,
            verdict: None,
            save_taken: false,
        }
    }
    pub fn role(&self) -> Role {
        self.role
    }
    pub fn phase(&self) -> Phase {
        self.phase
    }
    pub fn epoch(&self) -> Option<Epoch> {
        self.epoch
    }
    pub fn agreement(&self) -> Option<Agreement> {
        self.agreement
    }
    fn require_role(&self, role: Role) -> Result<()> {
        if self.role == role {
            Ok(())
        } else {
            Err(Error::Authority)
        }
    }
    fn next_epoch(&self) -> Result<Epoch> {
        self.epoch.map_or(Ok(Epoch::FIRST), Epoch::next)
    }
    fn prepare(&mut self, epoch: Epoch, a: Agreement) -> Result<()> {
        if !matches!(self.phase, Phase::Lobby | Phase::Result) {
            return Err(Error::Phase);
        }
        if epoch != self.next_epoch()? {
            return Err(Error::Epoch);
        }
        a.compatible(a)?;
        self.phase = Phase::Preparing;
        self.epoch = Some(epoch);
        self.agreement = Some(a);
        self.ready = 0;
        self.verdict = None;
        self.save_taken = false;
        Ok(())
    }
    pub fn host_prepare(&mut self, a: Agreement) -> Result<Epoch> {
        self.require_role(Role::Host)?;
        let e = self.next_epoch()?;
        self.prepare(e, a)?;
        Ok(e)
    }
    /// Only a message received from an authenticated host may call this guest entry.
    pub fn guest_prepare(
        &mut self,
        epoch: Epoch,
        remote: Agreement,
        local: Agreement,
    ) -> Result<()> {
        self.require_role(Role::Guest)?;
        remote.compatible(local)?;
        self.prepare(epoch, remote)
    }
    pub fn local_ready(&mut self) -> Result<()> {
        if self.phase != Phase::Preparing {
            return Err(Error::Phase);
        }
        let bit = 1 << self.role.slot().index();
        if self.ready & bit != 0 {
            return Err(Error::Duplicate);
        }
        self.ready |= bit;
        self.arm_if_ready();
        Ok(())
    }
    pub fn receive_guest_ready(&mut self, epoch: Epoch) -> Result<()> {
        self.require_role(Role::Host)?;
        if self.epoch != Some(epoch) {
            return Err(Error::Epoch);
        }
        if self.phase != Phase::Preparing {
            return Err(Error::Phase);
        }
        if self.ready & 2 != 0 {
            return Err(Error::Duplicate);
        }
        self.ready |= 2;
        self.arm_if_ready();
        Ok(())
    }
    fn arm_if_ready(&mut self) {
        if self.ready == 3 {
            self.phase = Phase::Armed;
        }
    }
    pub fn host_start(&mut self) -> Result<()> {
        self.require_role(Role::Host)?;
        if self.phase != Phase::Armed {
            return Err(Error::Phase);
        }
        self.phase = Phase::Playing;
        Ok(())
    }
    pub fn guest_start(&mut self, epoch: Epoch) -> Result<()> {
        self.require_role(Role::Guest)?;
        if self.epoch != Some(epoch) {
            return Err(Error::Epoch);
        }
        if self.phase != Phase::Preparing || self.ready & 2 == 0 {
            return Err(Error::Phase);
        }
        self.phase = Phase::Playing;
        Ok(())
    }
    fn pause(&mut self, paused: bool) -> Result<()> {
        if (paused && self.phase != Phase::Playing) || (!paused && self.phase != Phase::Paused) {
            return Err(Error::Phase);
        }
        self.phase = if paused {
            Phase::Paused
        } else {
            Phase::Playing
        };
        Ok(())
    }
    pub fn host_pause(&mut self, paused: bool) -> Result<()> {
        self.require_role(Role::Host)?;
        self.pause(paused)
    }
    pub fn guest_follow_pause(&mut self, epoch: Epoch, paused: bool) -> Result<()> {
        self.require_role(Role::Guest)?;
        if self.epoch != Some(epoch) {
            return Err(Error::Epoch);
        }
        self.pause(paused)
    }
    fn finish(&mut self, verdict: Verdict) -> Result<()> {
        if !matches!(self.phase, Phase::Playing | Phase::Paused) {
            return Err(Error::Phase);
        }
        self.phase = Phase::Result;
        self.verdict = Some(verdict);
        Ok(())
    }
    pub fn host_finish(&mut self, verdict: Verdict) -> Result<()> {
        self.require_role(Role::Host)?;
        self.finish(verdict)
    }
    pub fn guest_follow_result(&mut self, epoch: Epoch, verdict: Verdict) -> Result<()> {
        self.require_role(Role::Guest)?;
        if self.epoch != Some(epoch) {
            return Err(Error::Epoch);
        }
        self.finish(verdict)
    }
    pub fn take_save_permit(&mut self) -> Result<SavePermit> {
        self.require_role(Role::Host)?;
        if self.phase != Phase::Result {
            return Err(Error::Phase);
        }
        if self.verdict != Some(Verdict::Success) {
            return Err(Error::Unsupported("non-success campaign commit"));
        }
        if self.save_taken {
            return Err(Error::Duplicate);
        }
        self.save_taken = true;
        Ok(SavePermit {
            epoch: self.epoch.ok_or(Error::Epoch)?,
        })
    }
    pub fn recover(&mut self) -> Result<()> {
        if matches!(self.phase, Phase::Lobby | Phase::Recovering) {
            return Err(Error::Phase);
        }
        self.phase = Phase::Recovering;
        Ok(())
    }
    pub fn return_to_lobby(&mut self) -> Result<()> {
        if !matches!(self.phase, Phase::Result | Phase::Recovering) {
            return Err(Error::Phase);
        }
        self.phase = Phase::Lobby;
        self.agreement = None;
        self.ready = 0;
        self.verdict = None;
        Ok(())
    }
}

#[derive(Debug, Clone, Copy)]
pub struct InputLimits {
    pub late: u32,
    pub ahead: u32,
    pub stale_after: u32,
}
impl Default for InputLimits {
    fn default() -> Self {
        Self {
            late: 6,
            ahead: 6,
            stale_after: 30,
        }
    }
}
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PilotInput {
    pub held: Controls,
    pub pressed: u16,
    pub released: u16,
    pub stale: bool,
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct InputFrame {
    pub tick: u32,
    pub pilots: [PilotInput; 2],
}
#[derive(Default)]
struct Lane {
    pending: VecDeque<(u32, InputSample)>,
    last_received: Option<(u32, u32)>,
    held: Controls,
    last_applied_tick: Option<u32>,
}
pub struct InputGate {
    epoch: Epoch,
    next_tick: u32,
    limits: InputLimits,
    lanes: [Lane; 2],
}
impl InputGate {
    pub fn new(epoch: Epoch, start_tick: u32, limits: InputLimits) -> Result<Self> {
        if limits.late > 120 || limits.ahead > 120 || limits.stale_after > 3600 {
            return Err(Error::Bounds("input limits"));
        }
        Ok(Self {
            epoch,
            next_tick: start_tick,
            limits,
            lanes: Default::default(),
        })
    }
    pub fn epoch(&self) -> Epoch {
        self.epoch
    }
    pub fn next_tick(&self) -> u32 {
        self.next_tick
    }
    pub fn submit(
        &mut self,
        sender: Role,
        epoch: Epoch,
        tick: u32,
        sample: InputSample,
    ) -> Result<()> {
        if epoch != self.epoch {
            return Err(Error::Epoch);
        }
        if sample.slot != sender.slot() {
            return Err(Error::Authority);
        }
        let delta = signed_tick_distance(tick, self.next_tick)?;
        if delta < -(self.limits.late as i32) || delta > self.limits.ahead as i32 {
            return Err(Error::Bounds("input tick window"));
        }
        let lane = &mut self.lanes[sample.slot.index()];
        if let Some((sequence, prior_tick)) = lane.last_received {
            forward_distance(sample.sequence, sequence)?;
            if signed_tick_distance(tick, prior_tick)? < 0 {
                return Err(Error::Stale);
            }
        }
        if lane.pending.len() >= 64 {
            return Err(Error::Bounds("input queue"));
        }
        lane.pending.push_back((tick, sample));
        lane.last_received = Some((sample.sequence, tick));
        Ok(())
    }
    pub fn consume(&mut self, tick: u32) -> Result<InputFrame> {
        if tick != self.next_tick {
            return Err(Error::Invalid("accepted tick order"));
        }
        // Preflight every comparison before mutating any lane.
        for l in &self.lanes {
            for (t, _) in &l.pending {
                signed_tick_distance(*t, tick)?;
            }
            if let Some(t) = l.last_applied_tick {
                signed_tick_distance(tick, t)?;
            }
        }
        let mut pilots = [PilotInput::default(); 2];
        for (i, l) in self.lanes.iter_mut().enumerate() {
            let before = l.held.buttons;
            while let Some((t, sample)) = l.pending.front() {
                if signed_tick_distance(*t, tick)? > 0 {
                    break;
                }
                l.held = sample.controls;
                l.last_applied_tick = Some(*t);
                l.pending.pop_front();
            }
            let stale = match l.last_applied_tick {
                Some(t) => signed_tick_distance(tick, t)? > self.limits.stale_after as i32,
                None => true,
            };
            if stale {
                l.held = Controls::default();
            }
            pilots[i] = PilotInput {
                held: l.held,
                pressed: l.held.buttons & !before,
                released: before & !l.held.buttons,
                stale,
            };
        }
        self.next_tick = self.next_tick.wrapping_add(1);
        Ok(InputFrame { tick, pilots })
    }
    pub fn reset(&mut self, epoch: Epoch, start_tick: u32) -> Result<()> {
        if epoch != self.epoch.next()? {
            return Err(Error::Epoch);
        }
        self.epoch = epoch;
        self.next_tick = start_tick;
        self.lanes = Default::default();
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn a() -> Agreement {
        Agreement {
            build: TARGET_SHA256,
            patch: PATCH_COMPATIBILITY,
            content: [1; 32],
            mission: 1,
            difficulty: 2,
        }
    }
    fn playing() -> (Session, Session) {
        let mut h = Session::new(Role::Host);
        let mut g = Session::new(Role::Guest);
        let e = h.host_prepare(a()).unwrap();
        g.guest_prepare(e, a(), a()).unwrap();
        h.local_ready().unwrap();
        g.local_ready().unwrap();
        h.receive_guest_ready(e).unwrap();
        h.host_start().unwrap();
        g.guest_start(e).unwrap();
        (h, g)
    }
    fn input(seq: u32, buttons: u16) -> InputSample {
        InputSample {
            sequence: seq,
            slot: Slot::Guest,
            controls: Controls {
                buttons,
                ..Default::default()
            },
        }
    }
    #[test]
    fn readiness_and_authority() {
        let mut h = Session::new(Role::Host);
        let mut g = Session::new(Role::Guest);
        assert_eq!(g.host_prepare(a()), Err(Error::Authority));
        let e = h.host_prepare(a()).unwrap();
        assert_eq!(h.host_start(), Err(Error::Phase));
        g.guest_prepare(e, a(), a()).unwrap();
        assert_eq!(g.guest_start(e), Err(Error::Phase));
        h.local_ready().unwrap();
        g.local_ready().unwrap();
        h.receive_guest_ready(e).unwrap();
        h.host_start().unwrap();
        g.guest_start(e).unwrap();
        assert_eq!(g.host_pause(true), Err(Error::Authority));
        h.host_pause(true).unwrap();
        g.guest_follow_pause(e, true).unwrap();
        assert_eq!(h.phase(), g.phase());
    }
    #[test]
    fn save_and_retry_are_single_owner_single_epoch() {
        let (mut h, mut g) = playing();
        h.host_finish(Verdict::Success).unwrap();
        g.guest_follow_result(Epoch::FIRST, Verdict::Success)
            .unwrap();
        assert_eq!(h.take_save_permit().unwrap().epoch(), Epoch::FIRST);
        assert!(matches!(h.take_save_permit(), Err(Error::Duplicate)));
        assert!(matches!(g.take_save_permit(), Err(Error::Authority)));
        let e = h.host_prepare(a()).unwrap();
        assert_eq!(e.get(), 2);
        g.guest_prepare(e, a(), a()).unwrap();
        assert_eq!(h.receive_guest_ready(Epoch::FIRST), Err(Error::Epoch));
        assert_eq!(
            g.guest_follow_result(Epoch::FIRST, Verdict::Success),
            Err(Error::Epoch)
        );
    }
    #[test]
    fn incompatible_prepare_does_not_advance_state() {
        let mut h = Session::new(Role::Host);
        assert_eq!(
            h.host_prepare(Agreement {
                build: [0; 32],
                ..a()
            }),
            Err(Error::BuildMismatch)
        );
        assert_eq!(h.phase(), Phase::Lobby);
        assert_eq!(h.epoch(), None);
    }
    #[test]
    fn input_once_edges_future_and_stale_release() {
        let e = Epoch::FIRST;
        let mut gate = InputGate::new(
            e,
            0,
            InputLimits {
                stale_after: 1,
                ..Default::default()
            },
        )
        .unwrap();
        gate.submit(Role::Guest, e, 1, input(1, 4)).unwrap();
        assert_eq!(gate.consume(0).unwrap().pilots[1].pressed, 0);
        assert_eq!(gate.consume(1).unwrap().pilots[1].pressed, 4);
        assert!(gate.consume(1).is_err());
        assert_eq!(
            gate.submit(Role::Guest, e, 1, input(1, 4)),
            Err(Error::Duplicate)
        );
        assert_eq!(gate.consume(2).unwrap().pilots[1].pressed, 0);
        let out = gate.consume(3).unwrap().pilots[1];
        assert_eq!(out.released, 4);
        assert!(out.stale);
    }
    #[test]
    fn input_spoof_window_wrap_and_retry() {
        let e = Epoch::FIRST;
        let mut gate = InputGate::new(e, u32::MAX, InputLimits::default()).unwrap();
        assert_eq!(
            gate.submit(Role::Host, e, u32::MAX, input(1, 4)),
            Err(Error::Authority)
        );
        assert!(gate.submit(Role::Guest, e, 100, input(1, 4)).is_err());
        gate.submit(Role::Guest, e, u32::MAX, input(u32::MAX, 4))
            .unwrap();
        gate.consume(u32::MAX).unwrap();
        gate.submit(Role::Guest, e, 0, input(0, 4)).unwrap();
        assert_eq!(gate.consume(0).unwrap().pilots[1].pressed, 0);
        let next = e.next().unwrap();
        gate.reset(next, 0).unwrap();
        assert_eq!(
            gate.submit(Role::Guest, e, 0, input(1, 4)),
            Err(Error::Epoch)
        );
        assert_eq!(gate.consume(0).unwrap().pilots[1].held, Controls::default());
    }
    #[test]
    fn input_queue_is_bounded_without_partial_sequence_commit() {
        let e = Epoch::FIRST;
        let mut gate = InputGate::new(e, 0, InputLimits::default()).unwrap();
        for n in 0..64 {
            gate.submit(Role::Guest, e, 0, input(n, 1)).unwrap();
        }
        assert_eq!(
            gate.submit(Role::Guest, e, 0, input(64, 1)),
            Err(Error::Bounds("input queue"))
        );
        gate.consume(0).unwrap();
        gate.submit(Role::Guest, e, 1, input(64, 1)).unwrap();
    }
}
