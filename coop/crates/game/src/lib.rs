//! Same-build read-only native boundary. No native writes or guessed flight conversion.
#![forbid(unsafe_code)]
use acz_coop_contracts::*;
use sha2::{Digest, Sha256};
use std::ops::Range;

#[derive(Debug)]
pub struct HookSpec {
    pub name: &'static str,
    pub rva: usize,
    pub bytes: [u8; 32],
}
include!("build_manifest.rs");
pub const CAMPAIGN_VTABLE: usize = 0x2b3f90;
pub const VS_VTABLE: usize = 0x2b3fc8;
pub const PLAYER_STRIDE: usize = 0x27a0;
pub const ACTOR_STRIDE: usize = 0x520;
pub trait MemoryReader {
    fn read_exact(&self, address: usize, out: &mut [u8]) -> Result<()>;
}
fn at(base: usize, offset: usize) -> Result<usize> {
    base.checked_add(offset)
        .filter(|v| *v != 0)
        .ok_or(Error::Bounds("native address"))
}
fn read<const N: usize>(m: &impl MemoryReader, address: usize) -> Result<[u8; N]> {
    let mut b = [0; N];
    address.checked_add(N).ok_or(Error::Bounds("native read"))?;
    m.read_exact(address, &mut b)?;
    Ok(b)
}
fn byte(m: &impl MemoryReader, b: usize, o: usize) -> Result<u8> {
    Ok(read::<1>(m, at(b, o)?)?[0])
}
fn word(m: &impl MemoryReader, b: usize, o: usize) -> Result<u16> {
    Ok(u16::from_le_bytes(read(m, at(b, o)?)?))
}
fn dword(m: &impl MemoryReader, b: usize, o: usize) -> Result<u32> {
    Ok(u32::from_le_bytes(read(m, at(b, o)?)?))
}
fn pointer(m: &impl MemoryReader, b: usize, o: usize) -> Result<usize> {
    let p = usize::try_from(u64::from_le_bytes(read(m, at(b, o)?)?))
        .map_err(|_| Error::Bounds("pointer width"))?;
    if p == 0 {
        Err(Error::Unavailable)
    } else {
        Ok(p)
    }
}
fn vector(m: &impl MemoryReader, b: usize, o: usize) -> Result<[f32; 4]> {
    let bytes = read::<16>(m, at(b, o)?)?;
    let mut v = [0.; 4];
    for (f, b) in v.iter_mut().zip(bytes.chunks_exact(4)) {
        *f = f32::from_le_bytes(b.try_into().unwrap());
    }
    if v.iter().any(|x| !x.is_finite()) {
        return Err(Error::Invalid("native non-finite vector"));
    }
    Ok(v)
}
fn file_u16(b: &[u8], o: usize) -> Result<u16> {
    Ok(u16::from_le_bytes(
        b.get(o..o + 2)
            .ok_or(Error::Invalid("PE bounds"))?
            .try_into()
            .unwrap(),
    ))
}
fn file_u32(b: &[u8], o: usize) -> Result<u32> {
    Ok(u32::from_le_bytes(
        b.get(o..o + 4)
            .ok_or(Error::Invalid("PE bounds"))?
            .try_into()
            .unwrap(),
    ))
}

#[derive(Debug, Clone)]
pub struct VerifiedImage {
    base: usize,
    size: usize,
    code: Vec<Range<usize>>,
}
impl VerifiedImage {
    pub fn from_pe(bytes: &[u8], base: usize) -> Result<Self> {
        let hash: [u8; 32] = Sha256::digest(bytes).into();
        if hash != TARGET_SHA256 {
            return Err(Error::BuildMismatch);
        }
        let image = Self::parse_metadata(bytes, base)?;
        for h in HOOKS {
            let offset = image.file_offset(bytes, h.rva)?;
            if bytes.get(offset..offset + 32) != Some(h.bytes.as_slice()) {
                return Err(Error::BuildMismatch);
            }
        }
        Ok(image)
    }
    fn parse_metadata(bytes: &[u8], base: usize) -> Result<Self> {
        if base == 0 || bytes.get(..2) != Some(b"MZ") {
            return Err(Error::Invalid("PE header"));
        }
        let pe = file_u32(bytes, 0x3c)? as usize;
        if bytes.get(pe..pe.checked_add(4).ok_or(Error::Bounds("PE offset"))?) != Some(b"PE\0\0")
            || file_u16(bytes, pe + 4)? != 0x8664
        {
            return Err(Error::Invalid("PE AMD64"));
        }
        let count = file_u16(bytes, pe + 6)? as usize;
        let optional_size = file_u16(bytes, pe + 20)? as usize;
        if !(1..=96).contains(&count) || optional_size < 0x70 || file_u16(bytes, pe + 24)? != 0x20b
        {
            return Err(Error::Invalid("PE32+"));
        }
        let size = file_u32(bytes, pe + 24 + 56)? as usize;
        if size < 0x33d9e0 {
            return Err(Error::Invalid("PE image size"));
        }
        at(base, size)?;
        let table = pe
            .checked_add(24 + optional_size)
            .ok_or(Error::Bounds("PE sections"))?;
        let mut code = Vec::new();
        for i in 0..count {
            let section = table + i * 40;
            let virtual_size = file_u32(bytes, section + 8)? as usize;
            let rva = file_u32(bytes, section + 12)? as usize;
            let raw_size = file_u32(bytes, section + 16)? as usize;
            let raw = file_u32(bytes, section + 20)? as usize;
            if raw.checked_add(raw_size).is_none_or(|v| v > bytes.len())
                || rva.checked_add(virtual_size).is_none_or(|v| v > size)
            {
                return Err(Error::Invalid("PE section bounds"));
            }
            if file_u32(bytes, section + 36)? & 0x2000_0000 != 0 {
                code.push(rva..rva + virtual_size);
            }
        }
        Ok(Self { base, size, code })
    }
    fn file_offset(&self, bytes: &[u8], rva: usize) -> Result<usize> {
        let pe = file_u32(bytes, 0x3c)? as usize;
        let table = pe + 24 + file_u16(bytes, pe + 20)? as usize;
        for i in 0..file_u16(bytes, pe + 6)? as usize {
            let p = table + i * 40;
            let start = file_u32(bytes, p + 12)? as usize;
            let len = file_u32(bytes, p + 16)? as usize;
            if rva >= start && rva.checked_add(32).is_some_and(|v| v <= start + len) {
                return Ok(file_u32(bytes, p + 20)? as usize + rva - start);
            }
        }
        Err(Error::Invalid("unbacked RVA"))
    }
    pub fn base(&self) -> usize {
        self.base
    }
    pub fn size(&self) -> usize {
        self.size
    }
    pub fn executable_address(&self, rva: usize) -> Result<usize> {
        if !self.code.iter().any(|r| r.contains(&rva)) {
            return Err(Error::Bounds("non-executable hook"));
        }
        at(self.base, rva)
    }
    pub fn verify_loaded(&self, m: &impl MemoryReader) -> Result<()> {
        for h in HOOKS {
            let address = self.executable_address(h.rva)?;
            if read::<32>(m, address)? != h.bytes {
                return Err(Error::BuildMismatch);
            }
        }
        Ok(())
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct NativePlayer {
    pub slot: u8,
    pub group: u8,
    pub actor: u8,
    pub native_id: u16,
    pub context_position: [f32; 4],
    pub position: [f32; 4],
    pub orientation_like: [f32; 4],
    pub hp: i16,
    pub flags: u32,
}
#[derive(Debug, Clone, PartialEq)]
pub struct NativeFrame {
    pub generation: u64,
    pub sample: u64,
    pub thread: u32,
    pub mode: usize,
    pub world: usize,
    pub ready: bool,
    pub setup: u32,
    pub tick: Option<u32>,
    pub phase: Option<u8>,
    pub players: Vec<NativePlayer>,
}
#[derive(Clone, Copy)]
struct Live {
    mode: usize,
    world: usize,
    thread: u32,
    generation: u64,
    vtable: usize,
}
pub struct Observer {
    image: VerifiedImage,
    live: Option<Live>,
    generation: u64,
    sample: u64,
}
impl Observer {
    pub fn new(image: VerifiedImage) -> Self {
        Self {
            image,
            live: None,
            generation: 0,
            sample: 0,
        }
    }
    pub fn is_live(&self) -> bool {
        self.live.is_some()
    }
    fn mode_vtable(&self, m: &impl MemoryReader, mode: usize) -> Result<usize> {
        let v = pointer(m, mode, 0)?;
        if v != at(self.image.base, CAMPAIGN_VTABLE)? && v != at(self.image.base, VS_VTABLE)? {
            return Err(Error::Invalid("mode vtable"));
        }
        Ok(v)
    }
    pub fn enter(&mut self, m: &impl MemoryReader, mode: usize, thread: u32) -> Result<u64> {
        if thread == 0 {
            return Err(Error::WrongThread);
        }
        let vtable = self.mode_vtable(m, mode)?;
        let world = pointer(m, mode, 8)?;
        if let Some(old) = self.live {
            if old.mode == mode && old.world == world && old.thread == thread {
                return Ok(old.generation);
            }
            return Err(Error::Conflict);
        }
        let generation = self.generation.checked_add(1).ok_or(Error::Exhausted)?;
        self.live = Some(Live {
            mode,
            world,
            thread,
            generation,
            vtable,
        });
        self.generation = generation;
        self.sample = 0;
        Ok(generation)
    }
    pub fn leave(&mut self, mode: usize, thread: u32) -> Result<()> {
        // Invalidate first even if a surprising leave call reports a contract failure.
        let live = self.live.take().ok_or(Error::Unavailable)?;
        if live.mode != mode {
            return Err(Error::Conflict);
        }
        if live.thread != thread {
            return Err(Error::WrongThread);
        }
        Ok(())
    }
    pub fn observe(
        &mut self,
        m: &impl MemoryReader,
        mode: usize,
        thread: u32,
    ) -> Result<NativeFrame> {
        let sample = self.sample.checked_add(1).ok_or(Error::Exhausted)?;
        let frame = self.capture(m, mode, thread, sample)?;
        self.sample = sample;
        Ok(frame)
    }
    /// Validate current lifecycle and read state without advancing the pre-update sample number.
    /// Used after native update; never adopts a world that was invalidated during that update.
    pub fn inspect(&self, m: &impl MemoryReader, mode: usize, thread: u32) -> Result<NativeFrame> {
        self.capture(m, mode, thread, self.sample)
    }
    fn capture(
        &self,
        m: &impl MemoryReader,
        mode: usize,
        thread: u32,
        sample: u64,
    ) -> Result<NativeFrame> {
        let live = self.live.ok_or(Error::Unavailable)?;
        if live.thread != thread {
            return Err(Error::WrongThread);
        }
        if live.mode != mode {
            return Err(Error::Conflict);
        }
        if self.mode_vtable(m, mode)? != live.vtable || pointer(m, mode, 8)? != live.world {
            return Err(Error::Epoch);
        }
        let ready = byte(m, mode, 0x18)?;
        if ready > 1 {
            return Err(Error::Invalid("readiness"));
        }
        let setup = dword(m, mode, 0x1c)?;
        let max = if live.vtable == at(self.image.base, VS_VTABLE)? {
            15
        } else {
            18
        };
        if setup > max {
            return Err(Error::Invalid("setup index"));
        }
        let w = live.world;
        let mut players = Vec::new();
        let (mut tick, mut phase) = (None, None);
        if ready == 1 {
            let count = byte(m, w, 0xa87e4)?;
            let group_count = byte(m, w, 0x697ec)?;
            if !(1..=2).contains(&count) || group_count == 0 {
                return Err(Error::Bounds("player/group count"));
            }
            let contexts = pointer(m, w, 0xa8248)?;
            let groups = pointer(m, w, 0x697b8)?;
            for slot in 0..count {
                let p = at(contexts, slot as usize * PLAYER_STRIDE)?;
                if pointer(m, p, 0x1fc0)? != at(w, 0x240)?
                    || pointer(m, p, 0x2040)? != at(w, 0x697b8)?
                {
                    return Err(Error::Conflict);
                }
                let group = byte(m, p, 0x20a1)?;
                let actor = byte(m, p, 0x20a2)?;
                if group >= group_count {
                    return Err(Error::Bounds("group selector"));
                }
                let g = pointer(m, groups, group as usize * 8)?;
                let actors = dword(m, g, 0x118)? as i32;
                if actors <= 0 || i32::from(actor) >= actors {
                    return Err(Error::Bounds("actor selector"));
                }
                let a = at(pointer(m, g, 0x110)?, actor as usize * ACTOR_STRIDE)?;
                if pointer(m, a, 0x1b8)? != p
                    || byte(m, a, 0x234)? != group
                    || byte(m, a, 0x235)? != actor
                {
                    return Err(Error::Conflict);
                }
                players.push(NativePlayer {
                    slot,
                    group,
                    actor,
                    native_id: word(m, a, 0x228)?,
                    context_position: vector(m, p, 0x70)?,
                    position: vector(m, a, 0x258)?,
                    orientation_like: vector(m, a, 0x268)?,
                    hp: word(m, a, 0x428)? as i16,
                    flags: dword(m, a, 0x1f0)?,
                });
            }
            tick = Some(dword(m, w, 0xa878c)?);
            phase = Some(byte(m, w, 0xa8822)?);
        }
        if pointer(m, mode, 8)? != w || byte(m, mode, 0x18)? != ready {
            return Err(Error::Conflict);
        }
        Ok(NativeFrame {
            generation: live.generation,
            sample,
            thread,
            mode,
            world: w,
            ready: ready == 1,
            setup,
            tick,
            phase,
            players,
        })
    }
}

#[derive(Debug, Clone, Copy)]
pub enum Operation {
    Observe,
    InjectInput,
    ConstructGuest,
    WriteFlight,
    SpawnDespawn,
    Weapons,
    Damage,
    Mission,
    Save,
}
pub fn require_capability(op: Operation) -> Result<()> {
    match op {
        Operation::Observe => Ok(()),
        _ => Err(Error::Unsupported(
            "native write contract/runtime gate not closed",
        )),
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::cell::Cell;
    use std::collections::BTreeMap;
    const BASE: usize = 0x140000000;
    const MODE: usize = 0x6000000;
    const W: usize = 0x7000000;
    const P: usize = 0x8000000;
    const GROUPS: usize = 0x9000000;
    const G: usize = 0xa000000;
    const A: usize = 0xb000000;
    struct Mem {
        bytes: BTreeMap<usize, u8>,
        reads: Cell<usize>,
    }
    impl Mem {
        fn put(&mut self, address: usize, data: &[u8]) {
            for (i, v) in data.iter().enumerate() {
                self.bytes.insert(address + i, *v);
            }
        }
        fn u64(&mut self, a: usize, v: usize) {
            self.put(a, &(v as u64).to_le_bytes());
        }
        fn u32(&mut self, a: usize, v: u32) {
            self.put(a, &v.to_le_bytes());
        }
    }
    impl MemoryReader for Mem {
        fn read_exact(&self, a: usize, out: &mut [u8]) -> Result<()> {
            self.reads.set(self.reads.get() + 1);
            for (i, b) in out.iter_mut().enumerate() {
                *b = *self.bytes.get(&(a + i)).ok_or(Error::Unavailable)?;
            }
            Ok(())
        }
    }
    fn image() -> VerifiedImage {
        VerifiedImage {
            base: BASE,
            size: 0x4000000,
            code: std::iter::once(0x1000..0x27b000).collect(),
        }
    }
    fn memory() -> Mem {
        let mut m = Mem {
            bytes: BTreeMap::new(),
            reads: Cell::new(0),
        };
        m.u64(MODE, BASE + CAMPAIGN_VTABLE);
        m.u64(MODE + 8, W);
        m.put(MODE + 0x18, &[1]);
        m.u32(MODE + 0x1c, 18);
        m.put(W + 0xa87e4, &[1]);
        m.put(W + 0x697ec, &[1]);
        m.u64(W + 0xa8248, P);
        m.u64(W + 0x697b8, GROUPS);
        m.u32(W + 0xa878c, 42);
        m.put(W + 0xa8822, &[1]);
        m.u64(P + 0x1fc0, W + 0x240);
        m.u64(P + 0x2040, W + 0x697b8);
        m.put(P + 0x20a1, &[0, 0]);
        m.u64(GROUPS, G);
        m.u32(G + 0x118, 1);
        m.u64(G + 0x110, A);
        m.u64(A + 0x1b8, P);
        m.put(A + 0x234, &[0, 0]);
        m.put(A + 0x228, &7u16.to_le_bytes());
        m.put(A + 0x428, &100i16.to_le_bytes());
        m.u32(A + 0x1f0, 3);
        for addr in [P + 0x70, A + 0x258, A + 0x268] {
            for i in 0..4 {
                m.put(addr + i * 4, &(i as f32).to_le_bytes());
            }
        }
        m
    }
    #[test]
    fn real_file_hash_required_and_rva_must_be_code() {
        assert!(matches!(
            VerifiedImage::from_pe(b"wrong", BASE),
            Err(Error::BuildMismatch)
        ));
        assert!(image().executable_address(0x32c933).is_err());
        assert_eq!(image().executable_address(0x16e880), Ok(BASE + 0x16e880));
    }
    #[test]
    fn loaded_bytes_must_match_all_candidates() {
        let mut m = memory();
        for h in HOOKS {
            m.put(BASE + h.rva, &h.bytes);
        }
        assert!(image().verify_loaded(&m).is_ok());
        m.put(BASE + HOOKS[0].rva, &[0xcc]);
        assert_eq!(image().verify_loaded(&m), Err(Error::BuildMismatch));
    }
    #[test]
    fn lifecycle_read_validates_binding_and_preserves_raw_orientation() {
        let m = memory();
        let mut o = Observer::new(image());
        assert_eq!(o.enter(&m, MODE, 7), Ok(1));
        assert_eq!(o.enter(&m, MODE, 7), Ok(1));
        let f = o.observe(&m, MODE, 7).unwrap();
        assert_eq!(f.tick, Some(42));
        assert_eq!(f.players[0].hp, 100);
        assert_eq!(f.players[0].orientation_like, [0., 1., 2., 3.]);
        o.leave(MODE, 7).unwrap();
        let n = m.reads.get();
        assert_eq!(o.observe(&m, MODE, 7), Err(Error::Unavailable));
        assert_eq!(m.reads.get(), n);
        assert_eq!(o.enter(&m, MODE, 7), Ok(2));
    }
    #[test]
    fn wrong_thread_and_leave_fail_closed() {
        let m = memory();
        let mut o = Observer::new(image());
        o.enter(&m, MODE, 7).unwrap();
        let n = m.reads.get();
        assert_eq!(o.observe(&m, MODE, 8), Err(Error::WrongThread));
        assert_eq!(m.reads.get(), n);
        assert_eq!(o.leave(MODE, 8), Err(Error::WrongThread));
        assert!(!o.is_live());
    }
    #[test]
    fn partial_setup_never_reads_uninitialized_world_fields() {
        let mut m = memory();
        m.put(MODE + 0x18, &[0]);
        m.u32(MODE + 0x1c, 3);
        m.bytes.retain(|a, _| *a < W || *a >= W + 0xa8940);
        let mut o = Observer::new(image());
        o.enter(&m, MODE, 7).unwrap();
        let f = o.observe(&m, MODE, 7).unwrap();
        assert!(!f.ready);
        assert!(f.players.is_empty());
        assert_eq!(f.tick, None);
    }
    #[test]
    fn invalid_selection_and_memory_failure_do_not_emit_frame() {
        let mut m = memory();
        let mut o = Observer::new(image());
        o.enter(&m, MODE, 7).unwrap();
        m.put(P + 0x20a1, &[1]);
        assert!(o.observe(&m, MODE, 7).is_err());
        m.put(P + 0x20a1, &[0]);
        m.bytes.remove(&(A + 0x428));
        assert_eq!(o.observe(&m, MODE, 7), Err(Error::Unavailable));
        m.put(A + 0x428, &100i16.to_le_bytes());
        assert_eq!(o.observe(&m, MODE, 7).unwrap().sample, 1);
    }
    #[test]
    fn corrected_world_subobject_pointer_matches_assembly_not_old_documentation() {
        let mut m = memory();
        let mut o = Observer::new(image());
        o.enter(&m, MODE, 7).unwrap();
        m.u64(P + 0x1fc0, W);
        assert_eq!(o.observe(&m, MODE, 7), Err(Error::Conflict));
        m.u64(P + 0x1fc0, W + 0x240);
        assert!(o.observe(&m, MODE, 7).is_ok());
    }
    #[test]
    fn write_capabilities_are_not_inferred_from_read_success() {
        assert_eq!(require_capability(Operation::Observe), Ok(()));
        for op in [
            Operation::InjectInput,
            Operation::ConstructGuest,
            Operation::WriteFlight,
            Operation::SpawnDespawn,
            Operation::Weapons,
            Operation::Damage,
            Operation::Mission,
            Operation::Save,
        ] {
            assert!(matches!(require_capability(op), Err(Error::Unsupported(_))));
        }
    }
    #[test]
    fn post_update_inspection_preserves_sample_and_never_adopts_after_leave() {
        let m = memory();
        let mut o = Observer::new(image());
        o.enter(&m, MODE, 7).unwrap();
        let pre = o.observe(&m, MODE, 7).unwrap();
        let post = o.inspect(&m, MODE, 7).unwrap();
        assert_eq!(pre.sample, post.sample);
        assert_eq!(pre.generation, post.generation);
        assert_eq!(o.inspect(&m, MODE, 8), Err(Error::WrongThread));
        assert_eq!(o.observe(&m, MODE, 7).unwrap().sample, pre.sample + 1);
        o.leave(MODE, 7).unwrap();
        assert_eq!(o.inspect(&m, MODE, 7), Err(Error::Unavailable));
    }
}
