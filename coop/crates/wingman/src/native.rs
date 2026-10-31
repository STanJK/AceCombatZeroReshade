use crate::{
    SelectionSnapshot, View,
    memory::{Read, address},
    selection, views,
};
use acz_coop_contracts::{Error, Result};
use acz_coop_game::{
    ACTOR_STRIDE, CAMPAIGN_VTABLE, MemoryReader, NativeFrame, PLAYER_STRIDE, VS_VTABLE,
    VerifiedImage,
};

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Candidate {
    pub actor_index: u8,
    pub address: usize,
    pub helper: usize,
    pub helper_bound: bool,
    pub model_bound: bool,
    pub human_slot: Option<u8>,
    pub foreign_human_link: bool,
    pub native_id: u16,
    pub flags: u32,
}
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct EventSnapshot {
    pub controller: usize,
    pub flags: u32,
    pub index: u8,
    pub substate: u8,
    pub kind: Option<u8>,
}
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct WingmanSnapshot {
    pub generation: u64,
    pub sample: u64,
    pub mode: usize,
    pub world: usize,
    pub campaign: bool,
    pub player_count: u8,
    pub player_selectors: Vec<[u8; 2]>,
    pub world_flags: u32,
    pub world_phase: u8,
    pub camera_mode: u8,
    pub group: usize,
    pub group_category: u8,
    pub control_definition: u8,
    pub helper_count: u32,
    pub candidates: Vec<Candidate>,
    pub event: Option<EventSnapshot>,
    pub selection: SelectionSnapshot,
    pub views: Vec<View>,
}
fn event(m: &impl MemoryReader, world: usize) -> Result<Option<EventSnapshot>> {
    let r = Read(m);
    let Some(wrapper) = r.optional_pointer(world, 0xa8318)? else {
        return Ok(None);
    };
    let Some(controller) = r.optional_pointer(wrapper, 0x10)? else {
        return Ok(None);
    };
    let index = r.byte(controller, 0x3c9)?;
    let mut kind = None;
    if let Some(table) = r.optional_pointer(controller, 0x2d8)? {
        let header = r.pointer(table, 0)?;
        if index < r.byte(header, 0)? {
            let records = r.pointer(table, 8)?;
            let record = address(records, index as usize * 0x48)?;
            kind = Some(r.byte(r.pointer(record, 0)?, 0)?);
        }
    }
    Ok(Some(EventSnapshot {
        controller,
        index,
        kind,
        substate: r.byte(controller, 0x3cc)?,
        flags: r.dword(controller, 0x3a8)?,
    }))
}
/// Called only after native update, while Observer still validates the same live world/thread.
/// A candidate is an observed helper/Actor relation, not a proven story role or control lease.
pub fn capture(
    m: &impl MemoryReader,
    image: &VerifiedImage,
    frame: &NativeFrame,
) -> Result<WingmanSnapshot> {
    capture_at(m, image.base(), frame)
}
pub(crate) fn capture_at(
    m: &impl MemoryReader,
    image_base: usize,
    frame: &NativeFrame,
) -> Result<WingmanSnapshot> {
    if !frame.ready || frame.generation == 0 || frame.thread == 0 {
        return Err(Error::Phase);
    }
    let r = Read(m);
    let vtable = r.pointer(frame.mode, 0)?;
    let campaign = vtable == address(image_base, CAMPAIGN_VTABLE)?;
    if !campaign && vtable != address(image_base, VS_VTABLE)? {
        return Err(Error::Invalid("wingman mode"));
    }
    let w = frame.world;
    if r.pointer(frame.mode, 8)? != w || r.byte(frame.mode, 0x18)? != 1 {
        return Err(Error::Epoch);
    }
    let count = r.byte(w, 0xa87e4)?;
    if !(1..=2).contains(&count) || frame.players.len() != count as usize {
        return Err(Error::Bounds("wingman players"));
    }
    let players = r.pointer(w, 0xa8248)?;
    let mut selectors = Vec::with_capacity(count as usize);
    for slot in 0..count {
        let p = address(players, slot as usize * PLAYER_STRIDE)?;
        let selector = r.bytes::<2>(p, 0x20a1)?;
        let old = &frame.players[slot as usize];
        if old.slot != slot || [old.group, old.actor] != selector {
            return Err(Error::Epoch);
        }
        selectors.push(selector);
    }
    if r.byte(w, 0x697ec)? == 0 {
        return Err(Error::Bounds("wingman groups"));
    }
    let groups = r.pointer(w, 0x697b8)?;
    let group = r.pointer(groups, 0)?;
    if r.byte(group, 0x15c)? != 0 {
        return Err(Error::Conflict);
    }
    let actor_count = r.dword(group, 0x118)?;
    if !(1..=255).contains(&actor_count) {
        return Err(Error::Bounds("wingman actors"));
    }
    let actors = r.pointer(group, 0x110)?;
    let definition = r.pointer(r.pointer(group, 0x130)?, 0)?;
    let helper_count = r.dword(w, 0xa82f0)?;
    // Research bound, not a claim that the native allocator only supports eight.
    if helper_count > 8 {
        return Err(Error::Bounds("wingman probe helpers"));
    }
    let mut candidates = Vec::new();
    if helper_count != 0 {
        let helpers = r.pointer(w, 0xa82f8)?;
        for j in 0..helper_count as usize {
            if j + 1 >= actor_count as usize {
                break;
            }
            let helper = address(helpers, j * 0x108)?;
            let actor = address(actors, (j + 1) * ACTOR_STRIDE)?;
            if r.bytes::<2>(actor, 0x234)? != [0, (j + 1) as u8] {
                return Err(Error::Conflict);
            }
            let link = r.optional_pointer(actor, 0x1b8)?;
            let human_slot =
                (0..count).find(|i| link == players.checked_add(*i as usize * PLAYER_STRIDE));
            let model = r.optional_pointer(helper, 0x18)?;
            candidates.push(Candidate {
                actor_index: (j + 1) as u8,
                address: actor,
                helper,
                helper_bound: r.optional_pointer(actor, 0x1c0)? == Some(helper),
                model_bound: model.is_some() && model == r.optional_pointer(actor, 0x360)?,
                foreign_human_link: link.is_some() && human_slot.is_none(),
                human_slot,
                native_id: r.word(actor, 0x228)?,
                flags: r.dword(actor, 0x1f0)?,
            });
        }
    }
    let result = WingmanSnapshot {
        generation: frame.generation,
        sample: frame.sample,
        mode: frame.mode,
        world: w,
        campaign,
        player_count: count,
        player_selectors: selectors,
        world_flags: r.dword(w, 0xa8790)?,
        world_phase: r.byte(w, 0xa8822)?,
        camera_mode: r.byte(w, 0xa8794)?,
        group,
        group_category: r.byte(group, 0x15d)?,
        control_definition: r.byte(definition, 0xd)?,
        helper_count,
        candidates,
        event: event(m, w)?,
        selection: selection::capture(m, image_base)?,
        views: views::capture(m, w, players, count)?,
    };
    // This detects relocation during capture. It does not replace the game-thread/lifecycle contract.
    if r.pointer(frame.mode, 0)? != vtable
        || r.pointer(frame.mode, 8)? != w
        || r.byte(frame.mode, 0x18)? != 1
        || r.pointer(w, 0xa8248)? != players
        || r.pointer(w, 0x697b8)? != groups
        || r.pointer(groups, 0)? != group
        || r.pointer(group, 0x110)? != actors
        || r.dword(group, 0x118)? != actor_count
        || r.dword(w, 0xa82f0)? != helper_count
        || r.byte(w, 0xa87e4)? != count
    {
        return Err(Error::Epoch);
    }
    Ok(result)
}
