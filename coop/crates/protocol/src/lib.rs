//! Strict v1 draft wire format; no native pointers, serde layouts, or socket ownership.
#![forbid(unsafe_code)]
use acz_coop_contracts::*;
use std::collections::BTreeSet;
pub const HEADER_SIZE: usize = 40;
pub const VERSION: u16 = 1;

#[derive(Debug, Clone, PartialEq)]
pub struct Packet {
    pub session: [u8; 16],
    pub epoch: Epoch,
    pub sequence: u32,
    pub tick: u32,
    pub message: Message,
}
#[derive(Debug, Clone, PartialEq)]
pub enum Message {
    Prepare(Agreement),
    Ready,
    Start,
    Pause(bool),
    Input(InputSample),
    Snapshot(SnapshotChunk),
    Event(Event),
    Ack(Acknowledgement),
    Heartbeat,
}
impl Message {
    pub fn kind(&self) -> u16 {
        match self {
            Self::Prepare(_) => 1,
            Self::Ready => 2,
            Self::Start => 3,
            Self::Pause(_) => 4,
            Self::Input(_) => 5,
            Self::Snapshot(_) => 6,
            Self::Event(_) => 7,
            Self::Heartbeat => 8,
            Self::Ack(_) => 9,
        }
    }
    pub fn allowed_sender(&self, role: Role) -> bool {
        match self {
            Self::Ready | Self::Ack(_) => role == Role::Guest,
            Self::Input(_) | Self::Heartbeat => true,
            _ => role == Role::Host,
        }
    }
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Acknowledgement {
    pub event: u64,
    pub snapshot: u32,
    pub state_hash: [u8; 32],
}
#[derive(Debug, Clone, PartialEq)]
pub struct SnapshotChunk {
    pub id: u32,
    pub index: u16,
    pub count: u16,
    pub total: u32,
    pub poses: Vec<Pose>,
}
impl SnapshotChunk {
    pub fn validate(&self, epoch: Epoch) -> Result<()> {
        let total = self.total as usize;
        if total > MAX_ENTITIES {
            return Err(Error::Bounds("snapshot total"));
        }
        let count = total.div_ceil(POSES_PER_CHUNK).max(1);
        if self.count as usize != count || self.index >= self.count {
            return Err(Error::Invalid("snapshot chunks"));
        }
        let start = self.index as usize * POSES_PER_CHUNK;
        let n = total.saturating_sub(start).min(POSES_PER_CHUNK);
        if self.poses.len() != n {
            return Err(Error::Invalid("snapshot chunk length"));
        }
        let mut ids = BTreeSet::new();
        for p in &self.poses {
            p.validate()?;
            p.id.require_epoch(epoch)?;
            if !ids.insert(p.id) {
                return Err(Error::Conflict);
            }
        }
        Ok(())
    }
}
#[derive(Debug, Clone, PartialEq)]
pub struct Event {
    pub id: u64,
    pub change: Change,
}
#[derive(Debug, Clone, PartialEq)]
pub enum Change {
    Spawn {
        definition: u32,
        pose: Pose,
        hp: i16,
    },
    Despawn(EntityId),
    Damage {
        target: EntityId,
        attacker: Option<EntityId>,
        hp: i16,
        score: i32,
    },
    Result {
        verdict: Verdict,
        score: i32,
    },
}
impl Event {
    pub fn validate(&self, epoch: Epoch) -> Result<()> {
        if self.id == 0 {
            return Err(Error::Invalid("event id"));
        }
        match &self.change {
            Change::Spawn { pose, hp, .. } => {
                pose.validate()?;
                pose.id.require_epoch(epoch)?;
                if *hp < 0 {
                    return Err(Error::Invalid("initial health"));
                }
            }
            Change::Despawn(id) => id.require_epoch(epoch)?,
            Change::Damage {
                target,
                attacker,
                hp,
                ..
            } => {
                target.require_epoch(epoch)?;
                if let Some(a) = attacker {
                    a.require_epoch(epoch)?;
                }
                if *hp < 0 {
                    return Err(Error::Invalid("resolved health"));
                }
            }
            Change::Result { .. } => (),
        }
        Ok(())
    }
}

fn u16_out(b: &mut Vec<u8>, v: u16) {
    b.extend(v.to_le_bytes());
}
fn u32_out(b: &mut Vec<u8>, v: u32) {
    b.extend(v.to_le_bytes());
}
fn id_out(b: &mut Vec<u8>, v: EntityId) {
    u32_out(b, v.epoch().get());
    u32_out(b, v.serial());
}
fn pose_out(b: &mut Vec<u8>, v: &Pose) {
    id_out(b, v.id);
    for f in v
        .position
        .iter()
        .chain(v.orientation.iter())
        .chain(v.velocity.iter())
    {
        u32_out(b, f.to_bits());
    }
    u32_out(b, v.flags);
}
struct Cursor<'a> {
    data: &'a [u8],
    pos: usize,
}
impl<'a> Cursor<'a> {
    fn new(data: &'a [u8]) -> Self {
        Self { data, pos: 0 }
    }
    fn take<const N: usize>(&mut self) -> Result<[u8; N]> {
        let end = self.pos.checked_add(N).ok_or(Error::Bounds("cursor"))?;
        let bytes = self
            .data
            .get(self.pos..end)
            .ok_or(Error::Invalid("truncated packet"))?;
        self.pos = end;
        Ok(bytes.try_into().expect("bounded fixed field"))
    }
    fn u8(&mut self) -> Result<u8> {
        Ok(self.take::<1>()?[0])
    }
    fn u16(&mut self) -> Result<u16> {
        Ok(u16::from_le_bytes(self.take()?))
    }
    fn u32(&mut self) -> Result<u32> {
        Ok(u32::from_le_bytes(self.take()?))
    }
    fn id(&mut self) -> Result<EntityId> {
        EntityId::new(Epoch::new(self.u32()?)?, self.u32()?)
    }
    fn pose(&mut self) -> Result<Pose> {
        let id = self.id()?;
        let mut f = [0.; 10];
        for x in &mut f {
            *x = f32::from_bits(self.u32()?);
        }
        let p = Pose {
            id,
            position: f[..3].try_into().unwrap(),
            orientation: f[3..7].try_into().unwrap(),
            velocity: f[7..].try_into().unwrap(),
            flags: self.u32()?,
        };
        p.validate()?;
        Ok(p)
    }
    fn end(&self) -> Result<()> {
        if self.pos == self.data.len() {
            Ok(())
        } else {
            Err(Error::Invalid("trailing bytes"))
        }
    }
}
impl Packet {
    pub fn encode(&self) -> Result<Vec<u8>> {
        if self.session == [0; 16] {
            return Err(Error::Invalid("session id"));
        }
        let mut body = Vec::new();
        match &self.message {
            Message::Prepare(a) => {
                body.extend(a.build);
                body.extend(a.patch);
                body.extend(a.content);
                u32_out(&mut body, a.mission);
                body.push(a.difficulty);
            }
            Message::Ready | Message::Start | Message::Heartbeat => (),
            Message::Pause(v) => body.push(u8::from(*v)),
            Message::Ack(a) => {
                body.extend(a.event.to_le_bytes());
                u32_out(&mut body, a.snapshot);
                body.extend(a.state_hash);
            }
            Message::Input(i) => {
                u32_out(&mut body, i.sequence);
                body.extend([i.slot as u8, 0]);
                for axis in i.controls.axes {
                    body.extend(axis.to_le_bytes());
                }
                u16_out(&mut body, i.controls.buttons);
                body.extend(i.controls.triggers);
            }
            Message::Snapshot(s) => {
                s.validate(self.epoch)?;
                u32_out(&mut body, s.id);
                u32_out(&mut body, 0);
                u16_out(&mut body, s.index);
                u16_out(&mut body, s.count);
                u32_out(&mut body, s.total);
                for p in &s.poses {
                    pose_out(&mut body, p);
                }
            }
            Message::Event(e) => {
                e.validate(self.epoch)?;
                body.extend(e.id.to_le_bytes());
                match &e.change {
                    Change::Spawn {
                        definition,
                        pose,
                        hp,
                    } => {
                        body.push(0);
                        u32_out(&mut body, *definition);
                        pose_out(&mut body, pose);
                        body.extend(hp.to_le_bytes());
                    }
                    Change::Despawn(id) => {
                        body.push(1);
                        id_out(&mut body, *id);
                    }
                    Change::Damage {
                        target,
                        attacker,
                        hp,
                        score,
                    } => {
                        body.push(2);
                        id_out(&mut body, *target);
                        if let Some(a) = attacker {
                            id_out(&mut body, *a);
                        } else {
                            body.extend([0; 8]);
                        }
                        body.extend(hp.to_le_bytes());
                        body.extend(score.to_le_bytes());
                    }
                    Change::Result { verdict, score } => {
                        body.extend([3, verdict.wire()]);
                        body.extend(score.to_le_bytes());
                    }
                }
            }
        }
        if body.len() + HEADER_SIZE > MAX_DATAGRAM {
            return Err(Error::Bounds("packet"));
        }
        let mut b = Vec::with_capacity(HEADER_SIZE + body.len());
        b.extend(*b"ACZ2");
        u16_out(&mut b, VERSION);
        u16_out(&mut b, self.message.kind());
        b.extend(self.session);
        u32_out(&mut b, self.epoch.get());
        u32_out(&mut b, self.sequence);
        u32_out(&mut b, self.tick);
        u16_out(&mut b, body.len() as u16);
        u16_out(&mut b, 0);
        b.extend(body);
        Ok(b)
    }
    pub fn decode(data: &[u8]) -> Result<Self> {
        if data.len() > MAX_DATAGRAM {
            return Err(Error::Bounds("packet"));
        }
        let mut c = Cursor::new(data);
        if c.take::<4>()? != *b"ACZ2" || c.u16()? != VERSION {
            return Err(Error::Invalid("magic/version"));
        }
        let kind = c.u16()?;
        let session = c.take()?;
        if session == [0; 16] {
            return Err(Error::Invalid("session id"));
        }
        let epoch = Epoch::new(c.u32()?)?;
        let sequence = c.u32()?;
        let tick = c.u32()?;
        let len = c.u16()? as usize;
        if c.u16()? != 0 || len + HEADER_SIZE != data.len() {
            return Err(Error::Invalid("flags/length"));
        }
        let message = match kind {
            1 => Message::Prepare(Agreement {
                build: c.take()?,
                patch: c.take()?,
                content: c.take()?,
                mission: c.u32()?,
                difficulty: c.u8()?,
            }),
            2 => Message::Ready,
            3 => Message::Start,
            4 => Message::Pause(match c.u8()? {
                0 => false,
                1 => true,
                _ => return Err(Error::Invalid("pause")),
            }),
            5 => {
                let sequence = c.u32()?;
                let slot = Slot::try_from(c.u8()?)?;
                if c.u8()? != 0 {
                    return Err(Error::Invalid("input flags"));
                }
                let mut axes = [0; 4];
                for a in &mut axes {
                    *a = i16::from_le_bytes(c.take()?);
                }
                Message::Input(InputSample {
                    sequence,
                    slot,
                    controls: Controls {
                        axes,
                        buttons: c.u16()?,
                        triggers: c.take()?,
                    },
                })
            }
            6 => {
                let id = c.u32()?;
                if c.u32()? != 0 {
                    return Err(Error::Unsupported("delta snapshot"));
                }
                let index = c.u16()?;
                let count = c.u16()?;
                let total = c.u32()?;
                let bytes = data.len() - c.pos;
                if bytes % 52 != 0 || bytes / 52 > POSES_PER_CHUNK {
                    return Err(Error::Invalid("pose count"));
                }
                let mut poses = Vec::with_capacity(bytes / 52);
                for _ in 0..bytes / 52 {
                    poses.push(c.pose()?);
                }
                let s = SnapshotChunk {
                    id,
                    index,
                    count,
                    total,
                    poses,
                };
                s.validate(epoch)?;
                Message::Snapshot(s)
            }
            7 => {
                let id = u64::from_le_bytes(c.take()?);
                let change = match c.u8()? {
                    0 => Change::Spawn {
                        definition: c.u32()?,
                        pose: c.pose()?,
                        hp: i16::from_le_bytes(c.take()?),
                    },
                    1 => Change::Despawn(c.id()?),
                    2 => {
                        let target = c.id()?;
                        let a = c.u32()?;
                        let n = c.u32()?;
                        let attacker = if a == 0 && n == 0 {
                            None
                        } else {
                            Some(EntityId::new(Epoch::new(a)?, n)?)
                        };
                        Change::Damage {
                            target,
                            attacker,
                            hp: i16::from_le_bytes(c.take()?),
                            score: i32::from_le_bytes(c.take()?),
                        }
                    }
                    3 => Change::Result {
                        verdict: Verdict::try_from(c.u8()?)?,
                        score: i32::from_le_bytes(c.take()?),
                    },
                    _ => return Err(Error::Invalid("event kind")),
                };
                let e = Event { id, change };
                e.validate(epoch)?;
                Message::Event(e)
            }
            8 => Message::Heartbeat,
            9 => Message::Ack(Acknowledgement {
                event: u64::from_le_bytes(c.take()?),
                snapshot: c.u32()?,
                state_hash: c.take()?,
            }),
            _ => return Err(Error::Invalid("message kind")),
        };
        c.end()?;
        Ok(Self {
            session,
            epoch,
            sequence,
            tick,
            message,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn pose(n: u32) -> Pose {
        Pose {
            id: EntityId::new(Epoch::FIRST, n).unwrap(),
            position: [1., 2., 3.],
            orientation: [0., 0., 0., 1.],
            velocity: [4., 5., 6.],
            flags: 7,
        }
    }
    fn packet(message: Message) -> Packet {
        Packet {
            session: [1; 16],
            epoch: Epoch::FIRST,
            sequence: 7,
            tick: 9,
            message,
        }
    }
    #[test]
    fn golden_input() {
        let p = packet(Message::Input(InputSample {
            sequence: 0x12345678,
            slot: Slot::Guest,
            controls: Controls {
                axes: [-1, 2, -3, 4],
                buttons: 0xabcd,
                triggers: [8, 9],
            },
        }));
        let b = p.encode().unwrap();
        assert_eq!(&b[..8], b"ACZ2\x01\0\x05\0");
        assert_eq!(
            &b[24..40],
            &[1, 0, 0, 0, 7, 0, 0, 0, 9, 0, 0, 0, 18, 0, 0, 0]
        );
        assert_eq!(
            &b[40..],
            &[
                0x78, 0x56, 0x34, 0x12, 1, 0, 0xff, 0xff, 2, 0, 0xfd, 0xff, 4, 0, 0xcd, 0xab, 8, 9
            ]
        );
        assert_eq!(Packet::decode(&b), Ok(p));
    }
    #[test]
    fn every_variant_and_every_truncation() {
        let id = pose(1).id;
        let variants = [
            Message::Prepare(Agreement {
                build: TARGET_SHA256,
                patch: PATCH_COMPATIBILITY,
                content: [4; 32],
                mission: 3,
                difficulty: 2,
            }),
            Message::Ready,
            Message::Start,
            Message::Pause(true),
            Message::Heartbeat,
            Message::Ack(Acknowledgement {
                event: 3,
                snapshot: 4,
                state_hash: [5; 32],
            }),
            Message::Snapshot(SnapshotChunk {
                id: 3,
                index: 0,
                count: 1,
                total: 1,
                poses: vec![pose(1)],
            }),
            Message::Event(Event {
                id: 1,
                change: Change::Spawn {
                    definition: 12,
                    pose: pose(1),
                    hp: 100,
                },
            }),
            Message::Event(Event {
                id: 2,
                change: Change::Despawn(id),
            }),
            Message::Event(Event {
                id: 3,
                change: Change::Damage {
                    target: id,
                    attacker: Some(id),
                    hp: 7,
                    score: 13,
                },
            }),
            Message::Event(Event {
                id: 4,
                change: Change::Result {
                    verdict: Verdict::Success,
                    score: 100,
                },
            }),
        ];
        for m in variants {
            let p = packet(m);
            let b = p.encode().unwrap();
            assert_eq!(Packet::decode(&b), Ok(p));
            for cut in 0..b.len() {
                assert!(Packet::decode(&b[..cut]).is_err());
            }
            let mut extra = b;
            extra.push(0);
            assert!(Packet::decode(&extra).is_err());
        }
    }
    #[test]
    fn reject_flags_lengths_ids_and_nonfinite_pose() {
        let p = packet(Message::Snapshot(SnapshotChunk {
            id: 1,
            index: 0,
            count: 1,
            total: 1,
            poses: vec![pose(1)],
        }));
        let b = p.encode().unwrap();
        for (at, v) in [(0, 0), (4, 9), (6, 99), (38, 1), (36, 0), (24, 0), (56, 2)] {
            let mut bad = b.clone();
            bad[at] = v;
            assert!(Packet::decode(&bad).is_err(), "at {at}");
        }
        let mut bad = b.clone();
        bad[64..68].copy_from_slice(&f32::NAN.to_le_bytes());
        assert!(Packet::decode(&bad).is_err());
        let mut bad = b;
        bad[44] = 1;
        assert_eq!(
            Packet::decode(&bad),
            Err(Error::Unsupported("delta snapshot"))
        );
    }
    #[test]
    fn chunk_bounds_and_empty_world() {
        let empty = packet(Message::Snapshot(SnapshotChunk {
            id: 0,
            index: 0,
            count: 1,
            total: 0,
            poses: vec![],
        }));
        assert_eq!(Packet::decode(&empty.encode().unwrap()), Ok(empty));
        let s = SnapshotChunk {
            id: 0,
            index: 0,
            count: 1,
            total: 20,
            poses: (1..=20).map(pose).collect(),
        };
        assert_eq!(packet(Message::Snapshot(s)).encode().unwrap().len(), 1096);
        let s = SnapshotChunk {
            id: 0,
            index: 0,
            count: 1,
            total: 1,
            poses: vec![Pose {
                orientation: [0.; 4],
                ..pose(1)
            }],
        };
        assert!(packet(Message::Snapshot(s)).encode().is_err());
    }
    #[test]
    fn bounded_noise_does_not_panic() {
        let mut state = 0x1234_5678u32;
        for n in 0..1500 {
            let len = n % 1250;
            let mut b = vec![0; len];
            for x in &mut b {
                state ^= state << 13;
                state ^= state >> 17;
                state ^= state << 5;
                *x = state as u8;
            }
            let _ = Packet::decode(&b);
        }
    }
}
