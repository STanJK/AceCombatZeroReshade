use super::*;
use acz_coop_contracts::{Error, Result};
use acz_coop_game::{
    ACTOR_STRIDE, CAMPAIGN_VTABLE, MemoryReader, NativeFrame, NativePlayer, PLAYER_STRIDE,
};
use std::{cell::Cell, collections::BTreeMap};

const IMAGE: usize = 0x140000000;
const MODE: usize = 0x100000;
const W: usize = 0x200000;
const PLAYERS: usize = 0x400000;
const GROUPS: usize = 0x500000;
const GROUP: usize = 0x510000;
const ACTORS: usize = 0x520000;
const GDEF: usize = 0x530000;
const DEF: usize = 0x540000;
const HELPERS: usize = 0x550000;
const PLANE: usize = 0x560000;
const WRAPPER: usize = 0x570000;
const CONTROLLER: usize = 0x580000;
const TABLE: usize = 0x590000;
const HEADER: usize = 0x5a0000;
const RECORDS: usize = 0x5b0000;
const KIND: usize = 0x5c0000;
#[derive(Clone, Default)]
struct Memory(BTreeMap<usize, u8>);
impl Memory {
    fn put(&mut self, address: usize, bytes: &[u8]) {
        self.0
            .extend(bytes.iter().enumerate().map(|(i, b)| (address + i, *b)));
    }
    fn p(&mut self, address: usize, value: usize) {
        self.put(address, &(value as u64).to_le_bytes())
    }
    fn d(&mut self, address: usize, value: u32) {
        self.put(address, &value.to_le_bytes())
    }
}
impl MemoryReader for Memory {
    fn read_exact(&self, address: usize, out: &mut [u8]) -> Result<()> {
        for (i, b) in out.iter_mut().enumerate() {
            *b = *self.0.get(&(address + i)).ok_or(Error::Unavailable)?
        }
        Ok(())
    }
}
fn profile(m: &mut Memory, offset: usize, ids: [u32; 2]) {
    for (i, id) in ids.into_iter().enumerate() {
        m.d(IMAGE + offset + 0x24c + i * 4, id);
        m.d(IMAGE + offset + 0x254 + i * 4, 3 + i as u32);
        m.d(IMAGE + offset + 0x25c + i * 4, 10 + i as u32);
        if id < 36 {
            m.put(IMAGE + offset + 0x1e0 + id as usize * 3, &[i as u8, 2, 3])
        }
    }
}
fn fixture() -> (Memory, NativeFrame) {
    let mut m = Memory::default();
    m.p(MODE, IMAGE + CAMPAIGN_VTABLE);
    m.p(MODE + 8, W);
    m.put(MODE + 0x18, &[1]);
    m.put(W + 0xa87e4, &[1]);
    m.p(W + 0xa8248, PLAYERS);
    m.put(PLAYERS + 0x20a1, &[0, 0]);
    m.put(W + 0x697ec, &[1]);
    m.p(W + 0x697b8, GROUPS);
    m.p(GROUPS, GROUP);
    m.put(GROUP + 0x15c, &[0, 0]);
    m.d(GROUP + 0x118, 2);
    m.p(GROUP + 0x110, ACTORS);
    m.p(GROUP + 0x130, GDEF);
    m.p(GDEF, DEF);
    m.put(DEF + 0xd, &[0]);
    m.d(W + 0xa82f0, 1);
    m.p(W + 0xa82f8, HELPERS);
    m.p(HELPERS + 0x18, PLANE);
    let a = ACTORS + ACTOR_STRIDE;
    m.put(a + 0x234, &[0, 1]);
    m.p(a + 0x1b8, 0);
    m.p(a + 0x1c0, HELPERS);
    m.p(a + 0x360, PLANE);
    m.put(a + 0x228, &19u16.to_le_bytes());
    m.d(a + 0x1f0, 1);
    m.d(W + 0xa8790, 0);
    m.put(W + 0xa8822, &[1]);
    m.put(W + 0xa8794, &[0]);
    m.p(W + 0xa8318, WRAPPER);
    m.p(WRAPPER + 0x10, CONTROLLER);
    m.p(CONTROLLER + 0x2d8, TABLE);
    m.put(CONTROLLER + 0x3c9, &[0]);
    m.put(CONTROLLER + 0x3cc, &[3]);
    m.d(CONTROLLER + 0x3a8, 0x40);
    m.p(TABLE, HEADER);
    m.put(HEADER, &[1]);
    m.p(TABLE + 8, RECORDS);
    m.p(RECORDS, KIND);
    m.put(KIND, &[2]);
    m.d(W + 0x67230, 1);
    m.p(W + 0x671f0, PLAYERS + 0x10b0);
    m.p(W + 0x67210, PLAYERS + 0x1270);
    m.d(W + 0x67234, 0);
    m.put(IMAGE + 0x31cf18, &[0]);
    profile(&mut m, 0x310ec0, [4, 9]);
    profile(&mut m, 0x316e78, [2, 35]);
    let f = NativeFrame {
        generation: 7,
        sample: 1,
        thread: 2,
        mode: MODE,
        world: W,
        ready: true,
        setup: 18,
        tick: Some(100),
        phase: Some(1),
        players: vec![NativePlayer {
            slot: 0,
            group: 0,
            actor: 0,
            native_id: 18,
            context_position: [0.; 4],
            position: [0.; 4],
            orientation_like: [0.; 4],
            hp: 100,
            flags: 1,
        }],
    };
    (m, f)
}
#[test]
fn helper_topology_is_recorded_without_claiming_story_role_or_human_control() {
    let (m, f) = fixture();
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert_eq!(s.candidates.len(), 1);
    let c = &s.candidates[0];
    assert_eq!(c.actor_index, 1);
    assert!(c.helper_bound && c.model_bound);
    assert_eq!(c.native_id, 19);
    assert_eq!(c.human_slot, None);
    let r = assess(&s);
    assert_eq!(r.candidate_index, Some(1));
    assert!(!r.native_takeover_ready());
    assert!(r.blockers.contains(&Blocker::NoSecondPlayer));
    assert!(r.blockers.contains(&Blocker::OriginalRoleUnverified));
}
#[test]
fn vs_p2_binding_and_even_two_views_do_not_prove_campaign_wingman_takeover() {
    let (mut m, mut f) = fixture();
    m.put(W + 0xa87e4, &[2]);
    m.put(PLAYERS + PLAYER_STRIDE + 0x20a1, &[1, 0]);
    let mut p = f.players[0];
    p.slot = 1;
    p.group = 1;
    f.players.push(p);
    m.d(W + 0x67230, 2);
    m.p(W + 0x671f8, PLAYERS + PLAYER_STRIDE + 0x10b0);
    m.p(W + 0x67218, PLAYERS + PLAYER_STRIDE + 0x1270);
    m.d(W + 0x67238, 1);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    let r = assess(&s);
    assert!(r.blockers.contains(&Blocker::WrongPlayerBinding));
    assert!(!r.blockers.contains(&Blocker::NoTwoPlayerViews));
    assert!(!r.native_takeover_ready());
}
#[test]
fn second_player_link_and_selectors_must_both_match_original_candidate() {
    let (mut m, mut f) = fixture();
    m.put(W + 0xa87e4, &[2]);
    m.put(PLAYERS + PLAYER_STRIDE + 0x20a1, &[0, 1]);
    let mut p = f.players[0];
    p.slot = 1;
    p.actor = 1;
    f.players.push(p);
    m.p(ACTORS + ACTOR_STRIDE + 0x1b8, PLAYERS + PLAYER_STRIDE);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    let r = assess(&s);
    assert!(!r.blockers.contains(&Blocker::WrongPlayerBinding));
    assert!(r.blockers.contains(&Blocker::AiExclusionUnimplemented));
    assert!(
        r.blockers
            .contains(&Blocker::ActorIndexAdaptationUnimplemented)
    );
}
#[test]
fn foreign_human_link_and_broken_helper_binding_cannot_produce_candidate() {
    let (mut m, f) = fixture();
    m.p(ACTORS + ACTOR_STRIDE + 0x1b8, 0x123456);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert_eq!(assess(&s).candidate_index, None);
    m.p(ACTORS + ACTOR_STRIDE + 0x1b8, 0);
    m.p(ACTORS + ACTOR_STRIDE + 0x1c0, HELPERS + 0x108);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert_eq!(assess(&s).candidate_index, None);
}
#[test]
fn no_helper_is_valid_evidence_and_never_implies_spawn_permission() {
    let (mut m, f) = fixture();
    m.d(W + 0xa82f0, 0);
    m.0.remove(&(W + 0xa82f8));
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert!(s.candidates.is_empty());
    assert!(assess(&s).blockers.contains(&Blocker::NoBoundHelperActor));
}
#[test]
fn indices_counts_and_partial_memory_fail_closed() {
    let (mut m, f) = fixture();
    let saved = m.clone();
    for (addr, bytes) in [
        (W + 0xa82f0, 9u32.to_le_bytes().to_vec()),
        (W + 0x67230, 5u32.to_le_bytes().to_vec()),
        (ACTORS + ACTOR_STRIDE + 0x234, vec![1, 0]),
    ] {
        m = saved.clone();
        m.put(addr, &bytes);
        assert!(native::capture_at(&m, IMAGE, &f).is_err());
    }
    m = saved;
    m.0.remove(&(HELPERS + 0x18));
    assert_eq!(native::capture_at(&m, IMAGE, &f), Err(Error::Unavailable));
    assert!(memory::address(usize::MAX, 1).is_err());
    assert!(memory::address(0, 1).is_err());
}
#[test]
fn event_kind_is_indirect_and_phase_one_does_not_classify_critical_event() {
    let (mut m, f) = fixture();
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert_eq!(s.event.as_ref().unwrap().kind, Some(2));
    assert_eq!(s.event.as_ref().unwrap().substate, 3);
    assert!(
        assess(&s)
            .blockers
            .contains(&Blocker::EventPolicyUnverified)
    );
    m.put(CONTROLLER + 0x3c9, &[1]);
    m.0.remove(&RECORDS);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert_eq!(s.event.unwrap().kind, None);
}
#[test]
fn selection_profiles_and_color_bounds_do_not_alias_low_byte() {
    let (mut m, _) = fixture();
    assert_eq!(selection::capture(&m, IMAGE).unwrap().slots[1].aircraft, 9);
    m.put(IMAGE + 0x31cf18, &[1]);
    assert_eq!(selection::capture(&m, IMAGE).unwrap().slots[1].aircraft, 35);
    m.d(IMAGE + 0x3170c8, 0x104);
    let s = selection::capture(&m, IMAGE).unwrap();
    assert_eq!(s.slots[1].aircraft, 0x104);
    assert_eq!(s.slots[1].color, None);
}
#[test]
fn external_event_camera_is_distinct_from_native_player_pair() {
    let (mut m, f) = fixture();
    m.p(W + 0x671f0, PLANE);
    m.p(W + 0x67210, PLANE);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert_eq!(s.views[0].source, CameraSource::External);
    m.d(W + 0x67230, 0);
    let s = native::capture_at(&m, IMAGE, &f).unwrap();
    assert!(s.views.is_empty());
}
#[test]
fn relocation_during_capture_and_stale_lifecycle_inputs_are_rejected() {
    let (m, mut f) = fixture();
    struct Relocate(Memory, Cell<u32>);
    impl MemoryReader for Relocate {
        fn read_exact(&self, address: usize, out: &mut [u8]) -> Result<()> {
            if address == MODE + 8 {
                let n = self.1.get() + 1;
                self.1.set(n);
                if n > 1 {
                    out.copy_from_slice(&((W + 8) as u64).to_le_bytes());
                    return Ok(());
                }
            }
            self.0.read_exact(address, out)
        }
    }
    assert_eq!(
        native::capture_at(&Relocate(m.clone(), Cell::new(0)), IMAGE, &f),
        Err(Error::Epoch)
    );
    f.generation = 0;
    assert_eq!(native::capture_at(&m, IMAGE, &f), Err(Error::Phase));
    f.generation = 7;
    f.ready = false;
    assert_eq!(native::capture_at(&m, IMAGE, &f), Err(Error::Phase));
}
