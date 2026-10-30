//! Atomic bounded snapshot assembly and ordered authoritative outcomes.
#![forbid(unsafe_code)]
use acz_coop_contracts::*;
use acz_coop_protocol::{Change, Event, SnapshotChunk};
use sha2::{Digest, Sha256};
use std::collections::{BTreeMap, BTreeSet, VecDeque};

#[derive(Debug, Clone, PartialEq)]
pub struct Snapshot {
    pub epoch: Epoch,
    pub id: u32,
    pub tick: u32,
    pub poses: Vec<Pose>,
}
struct Pending {
    id: u32,
    tick: u32,
    count: u16,
    total: u32,
    parts: Vec<Option<Vec<Pose>>>,
    ids: BTreeSet<EntityId>,
}
pub struct Assembler {
    epoch: Epoch,
    pending: Option<Pending>,
    last_delivered: Option<u32>,
}
impl Assembler {
    pub fn new(epoch: Epoch) -> Self {
        Self {
            epoch,
            pending: None,
            last_delivered: None,
        }
    }
    pub fn reset(&mut self, epoch: Epoch) -> Result<()> {
        if epoch != self.epoch.next()? {
            return Err(Error::Epoch);
        }
        *self = Self::new(epoch);
        Ok(())
    }
    pub fn push(
        &mut self,
        epoch: Epoch,
        tick: u32,
        chunk: SnapshotChunk,
    ) -> Result<Option<Snapshot>> {
        if epoch != self.epoch {
            return Err(Error::Epoch);
        }
        chunk.validate(epoch)?;
        if let Some(last) = self.last_delivered {
            forward_distance(chunk.id, last)?;
        }
        if let Some(p) = &self.pending {
            if p.id != chunk.id {
                forward_distance(chunk.id, p.id)?;
            } else {
                if p.tick != tick || p.count != chunk.count || p.total != chunk.total {
                    return Err(Error::Conflict);
                }
                if let Some(old) = &p.parts[chunk.index as usize] {
                    return if *old == chunk.poses {
                        Err(Error::Duplicate)
                    } else {
                        Err(Error::Conflict)
                    };
                }
                if chunk.poses.iter().any(|v| p.ids.contains(&v.id)) {
                    return Err(Error::Conflict);
                }
            }
        }
        if self.pending.as_ref().is_none_or(|p| p.id != chunk.id) {
            self.pending = Some(Pending {
                id: chunk.id,
                tick,
                count: chunk.count,
                total: chunk.total,
                parts: vec![None; chunk.count as usize],
                ids: BTreeSet::new(),
            });
        }
        let p = self.pending.as_mut().expect("pending initialized");
        for pose in &chunk.poses {
            p.ids.insert(pose.id);
        }
        p.parts[chunk.index as usize] = Some(chunk.poses);
        if p.parts.iter().any(Option::is_none) {
            return Ok(None);
        }
        let p = self.pending.take().expect("complete pending");
        let poses = p
            .parts
            .into_iter()
            .flat_map(|v| v.expect("checked all chunks"))
            .collect();
        self.last_delivered = Some(p.id);
        Ok(Some(Snapshot {
            epoch,
            id: p.id,
            tick,
            poses,
        }))
    }
}

pub fn split_snapshot(epoch: Epoch, id: u32, poses: &[Pose]) -> Result<Vec<SnapshotChunk>> {
    if poses.len() > MAX_ENTITIES {
        return Err(Error::Bounds("snapshot total"));
    }
    let mut ids = BTreeSet::new();
    for p in poses {
        p.validate()?;
        p.id.require_epoch(epoch)?;
        if !ids.insert(p.id) {
            return Err(Error::Conflict);
        }
    }
    let count = poses.len().div_ceil(POSES_PER_CHUNK).max(1) as u16;
    if poses.is_empty() {
        return Ok(vec![SnapshotChunk {
            id,
            index: 0,
            count: 1,
            total: 0,
            poses: vec![],
        }]);
    }
    Ok(poses
        .chunks(POSES_PER_CHUNK)
        .enumerate()
        .map(|(i, p)| SnapshotChunk {
            id,
            index: i as u16,
            count,
            total: poses.len() as u32,
            poses: p.to_vec(),
        })
        .collect())
}

pub struct HostIds {
    epoch: Epoch,
    last: u32,
}
impl HostIds {
    pub fn new(epoch: Epoch) -> Self {
        Self { epoch, last: 0 }
    }
    pub fn allocate(&mut self) -> Result<EntityId> {
        let n = self.last.checked_add(1).ok_or(Error::Exhausted)?;
        let id = EntityId::new(self.epoch, n)?;
        self.last = n;
        Ok(id)
    }
}

/// Cursor advances only if a transactional adapter reports successful application.
#[derive(Default)]
pub struct EventCursor {
    last: u64,
}
impl EventCursor {
    pub fn last(&self) -> u64 {
        self.last
    }
    pub fn apply_with(&mut self, id: u64, apply: impl FnOnce() -> Result<()>) -> Result<()> {
        self.check(id)?;
        apply()?;
        self.last = id;
        Ok(())
    }
    fn check(&self, id: u64) -> Result<()> {
        if id == 0 {
            return Err(Error::Invalid("event id"));
        }
        if id <= self.last {
            return Err(Error::Duplicate);
        }
        if id != self.last.checked_add(1).ok_or(Error::Exhausted)? {
            return Err(Error::Gap);
        }
        Ok(())
    }
}
#[derive(Debug, Clone, PartialEq)]
pub struct Entity {
    pub definition: u32,
    pub pose: Pose,
    pub hp: i16,
}
pub struct WorldState {
    epoch: Epoch,
    entities: BTreeMap<EntityId, Entity>,
    high_serial: u32,
    cursor: EventCursor,
    recent: VecDeque<Event>,
    last_snapshot: Option<(u32, u32)>,
    score: i32,
    verdict: Option<Verdict>,
}
impl WorldState {
    pub fn new(epoch: Epoch) -> Self {
        Self {
            epoch,
            entities: BTreeMap::new(),
            high_serial: 0,
            cursor: EventCursor::default(),
            recent: VecDeque::new(),
            last_snapshot: None,
            score: 0,
            verdict: None,
        }
    }
    pub fn epoch(&self) -> Epoch {
        self.epoch
    }
    pub fn entities(&self) -> &BTreeMap<EntityId, Entity> {
        &self.entities
    }
    pub fn score(&self) -> i32 {
        self.score
    }
    pub fn verdict(&self) -> Option<Verdict> {
        self.verdict
    }
    pub fn last_event(&self) -> u64 {
        self.cursor.last()
    }
    pub fn digest(&self) -> [u8; 32] {
        let mut h = Sha256::new();
        h.update(b"ACZ_STATE_V1");
        h.update(self.epoch.get().to_le_bytes());
        h.update(self.high_serial.to_le_bytes());
        h.update(self.cursor.last.to_le_bytes());
        h.update(self.score.to_le_bytes());
        h.update([self.verdict.map_or(255, Verdict::wire)]);
        match self.last_snapshot {
            Some((id, tick)) => {
                h.update([1]);
                h.update(id.to_le_bytes());
                h.update(tick.to_le_bytes());
            }
            None => h.update([0]),
        }
        h.update((self.entities.len() as u32).to_le_bytes());
        for (id, e) in &self.entities {
            h.update(id.epoch().get().to_le_bytes());
            h.update(id.serial().to_le_bytes());
            h.update(e.definition.to_le_bytes());
            h.update(e.hp.to_le_bytes());
            for f in e
                .pose
                .position
                .iter()
                .chain(e.pose.orientation.iter())
                .chain(e.pose.velocity.iter())
            {
                h.update((if *f == 0.0 { 0 } else { f.to_bits() }).to_le_bytes());
            }
            h.update(e.pose.flags.to_le_bytes());
        }
        h.finalize().into()
    }
    pub fn reset(&mut self, epoch: Epoch) -> Result<()> {
        if epoch != self.epoch.next()? {
            return Err(Error::Epoch);
        }
        *self = Self::new(epoch);
        Ok(())
    }
    pub fn apply_event(&mut self, sender: Role, epoch: Epoch, e: &Event) -> Result<()> {
        if sender != Role::Host {
            return Err(Error::Authority);
        }
        if epoch != self.epoch {
            return Err(Error::Epoch);
        }
        e.validate(epoch)?;
        if e.id <= self.cursor.last() {
            return match self.recent.iter().find(|old| old.id == e.id) {
                Some(old) if old == e => Err(Error::Duplicate),
                Some(_) => Err(Error::Conflict),
                None => Err(Error::Stale),
            };
        }
        self.cursor.check(e.id)?;
        if self.verdict.is_some() {
            return Err(Error::Phase);
        }
        // Every fallible check happens before the mutation match below.
        match &e.change {
            Change::Spawn { pose, .. } => {
                if pose.id.serial() <= self.high_serial {
                    return Err(Error::Stale);
                }
                if self.entities.len() >= MAX_ENTITIES {
                    return Err(Error::Bounds("entity table"));
                }
            }
            Change::Despawn(id) => {
                if !self.entities.contains_key(id) {
                    return Err(Error::Unavailable);
                }
            }
            Change::Damage {
                target, attacker, ..
            } => {
                if !self.entities.contains_key(target) {
                    return Err(Error::Unavailable);
                }
                // A projectile may arrive after its owner's despawn; an active pointer is not required.
                if attacker.is_some_and(|id| id.serial() > self.high_serial) {
                    return Err(Error::Unavailable);
                }
            }
            Change::Result { .. } => (),
        }
        match &e.change {
            Change::Spawn {
                definition,
                pose,
                hp,
            } => {
                self.high_serial = pose.id.serial();
                self.entities.insert(
                    pose.id,
                    Entity {
                        definition: *definition,
                        pose: *pose,
                        hp: *hp,
                    },
                );
            }
            Change::Despawn(id) => {
                self.entities.remove(id);
            }
            Change::Damage {
                target, hp, score, ..
            } => {
                self.entities.get_mut(target).expect("preflight target").hp = *hp;
                self.score = *score;
            }
            Change::Result { verdict, score } => {
                self.verdict = Some(*verdict);
                self.score = *score;
            }
        }
        self.cursor.last = e.id;
        if self.recent.len() == 64 {
            self.recent.pop_front();
        }
        self.recent.push_back(e.clone());
        Ok(())
    }
    pub fn apply_snapshot(&mut self, sender: Role, s: &Snapshot) -> Result<()> {
        if sender != Role::Host {
            return Err(Error::Authority);
        }
        if s.epoch != self.epoch {
            return Err(Error::Epoch);
        }
        if self.verdict.is_some() {
            return Err(Error::Phase);
        }
        if let Some((id, tick)) = self.last_snapshot {
            forward_distance(s.id, id)?;
            if signed_tick_distance(s.tick, tick)? < 0 {
                return Err(Error::Stale);
            }
        }
        if s.poses.len() != self.entities.len() {
            return Err(Error::Gap);
        }
        let mut ids = BTreeSet::new();
        for p in &s.poses {
            p.validate()?;
            p.id.require_epoch(self.epoch)?;
            if !self.entities.contains_key(&p.id) {
                return Err(Error::Gap);
            }
            if !ids.insert(p.id) {
                return Err(Error::Conflict);
            }
        }
        for p in &s.poses {
            self.entities.get_mut(&p.id).expect("preflight entity").pose = *p;
        }
        self.last_snapshot = Some((s.id, s.tick));
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn p(n: u32) -> Pose {
        Pose {
            id: EntityId::new(Epoch::FIRST, n).unwrap(),
            position: [n as f32, 0., 0.],
            orientation: [0., 0., 0., 1.],
            velocity: [0.; 3],
            flags: 0,
        }
    }
    fn spawn(n: u32, id: u64) -> Event {
        Event {
            id,
            change: Change::Spawn {
                definition: 1,
                pose: p(n),
                hp: 100,
            },
        }
    }
    #[test]
    fn reversed_chunks_commit_only_when_complete() {
        let e = Epoch::FIRST;
        let poses: Vec<_> = (1..=41).map(p).collect();
        let chunks = split_snapshot(e, 7, &poses).unwrap();
        let mut a = Assembler::new(e);
        assert_eq!(a.push(e, 9, chunks[2].clone()), Ok(None));
        assert_eq!(a.push(e, 9, chunks[0].clone()), Ok(None));
        let out = a.push(e, 9, chunks[1].clone()).unwrap().unwrap();
        assert_eq!(out.poses, poses);
        assert_eq!(a.push(e, 9, chunks[0].clone()), Err(Error::Duplicate));
    }
    #[test]
    fn conflicting_chunk_is_rejected_without_poisoning_pending() {
        let e = Epoch::FIRST;
        let chunks = split_snapshot(e, 7, &(1..=21).map(p).collect::<Vec<_>>()).unwrap();
        let mut a = Assembler::new(e);
        a.push(e, 9, chunks[0].clone()).unwrap();
        assert_eq!(a.push(e, 10, chunks[1].clone()), Err(Error::Conflict));
        let mut dup = chunks[1].clone();
        dup.poses[0] = p(1);
        assert_eq!(a.push(e, 9, dup), Err(Error::Conflict));
        assert_eq!(
            a.push(e, 9, chunks[1].clone())
                .unwrap()
                .unwrap()
                .poses
                .len(),
            21
        );
    }
    #[test]
    fn newer_snapshot_supersedes_missing_old_and_epoch_resets() {
        let e = Epoch::FIRST;
        let mut a = Assembler::new(e);
        let old = split_snapshot(e, 1, &(1..=21).map(p).collect::<Vec<_>>()).unwrap();
        a.push(e, 0, old[0].clone()).unwrap();
        let new = split_snapshot(e, 2, &[p(1)]).unwrap().remove(0);
        assert!(a.push(e, 1, new).unwrap().is_some());
        assert_eq!(a.push(e, 0, old[1].clone()), Err(Error::Stale));
        a.reset(e.next().unwrap()).unwrap();
        assert_eq!(a.push(e, 0, old[1].clone()), Err(Error::Epoch));
    }
    #[test]
    fn event_duplicate_gap_and_failure_do_not_half_commit() {
        let e = Epoch::FIRST;
        let mut w = WorldState::new(e);
        w.apply_event(Role::Host, e, &spawn(1, 1)).unwrap();
        let damage = Event {
            id: 2,
            change: Change::Damage {
                target: p(1).id,
                attacker: None,
                hp: 50,
                score: 200,
            },
        };
        assert_eq!(
            w.apply_event(Role::Guest, e, &damage),
            Err(Error::Authority)
        );
        w.apply_event(Role::Host, e, &damage).unwrap();
        assert_eq!(w.apply_event(Role::Host, e, &damage), Err(Error::Duplicate));
        let conflicting = Event {
            id: 2,
            change: Change::Damage {
                target: p(1).id,
                attacker: None,
                hp: 1,
                score: 999,
            },
        };
        assert_eq!(
            w.apply_event(Role::Host, e, &conflicting),
            Err(Error::Conflict)
        );
        assert_eq!(w.score(), 200);
        assert_eq!(w.entities()[&p(1).id].hp, 50);
        assert_eq!(w.apply_event(Role::Host, e, &spawn(2, 4)), Err(Error::Gap));
        assert_eq!(w.last_event(), 2);
        let missing = Event {
            id: 3,
            change: Change::Despawn(p(2).id),
        };
        assert_eq!(
            w.apply_event(Role::Host, e, &missing),
            Err(Error::Unavailable)
        );
        assert_eq!(w.last_event(), 2);
        w.apply_event(Role::Host, e, &spawn(2, 3)).unwrap();
        assert_eq!(w.entities().len(), 2);
    }
    #[test]
    fn snapshot_set_and_values_are_validated_before_any_pose_write() {
        let e = Epoch::FIRST;
        let mut w = WorldState::new(e);
        w.apply_event(Role::Host, e, &spawn(1, 1)).unwrap();
        w.apply_event(Role::Host, e, &spawn(2, 2)).unwrap();
        let changed = Pose {
            position: [99., 0., 0.],
            ..p(1)
        };
        let bad = Snapshot {
            epoch: e,
            id: 1,
            tick: 0,
            poses: vec![changed, p(3)],
        };
        assert_eq!(w.apply_snapshot(Role::Host, &bad), Err(Error::Gap));
        assert_eq!(w.entities()[&p(1).id].pose, p(1));
        let good = Snapshot {
            poses: vec![changed, p(2)],
            ..bad
        };
        w.apply_snapshot(Role::Host, &good).unwrap();
        assert_eq!(w.entities()[&p(1).id].pose, changed);
    }
    #[test]
    fn retired_id_is_not_reused_and_late_attacker_can_be_inactive() {
        let e = Epoch::FIRST;
        let mut w = WorldState::new(e);
        w.apply_event(Role::Host, e, &spawn(1, 1)).unwrap();
        w.apply_event(Role::Host, e, &spawn(2, 2)).unwrap();
        w.apply_event(
            Role::Host,
            e,
            &Event {
                id: 3,
                change: Change::Despawn(p(1).id),
            },
        )
        .unwrap();
        assert_eq!(
            w.apply_event(Role::Host, e, &spawn(1, 4)),
            Err(Error::Stale)
        );
        w.apply_event(
            Role::Host,
            e,
            &Event {
                id: 4,
                change: Change::Damage {
                    target: p(2).id,
                    attacker: Some(p(1).id),
                    hp: 80,
                    score: 5,
                },
            },
        )
        .unwrap();
        w.reset(e.next().unwrap()).unwrap();
        assert!(w.entities().is_empty());
        assert_eq!(w.score(), 0);
    }
    #[test]
    fn old_replays_outside_content_window_are_stale() {
        let e = Epoch::FIRST;
        let mut w = WorldState::new(e);
        for n in 1..=65 {
            w.apply_event(Role::Host, e, &spawn(n, n as u64)).unwrap();
        }
        assert_eq!(
            w.apply_event(Role::Host, e, &spawn(1, 1)),
            Err(Error::Stale)
        );
        assert_eq!(
            w.apply_event(Role::Host, e, &spawn(65, 65)),
            Err(Error::Duplicate)
        );
        assert_eq!(w.entities().len(), 65);
        assert_eq!(w.last_event(), 65);
    }
    #[test]
    fn cursor_commits_after_adapter_success_only() {
        let mut c = EventCursor::default();
        assert_eq!(
            c.apply_with(1, || Err(Error::Unavailable)),
            Err(Error::Unavailable)
        );
        assert_eq!(c.last(), 0);
        c.apply_with(1, || Ok(())).unwrap();
        assert_eq!(
            c.apply_with(1, || panic!("duplicate must not call adapter")),
            Err(Error::Duplicate)
        );
    }
}
