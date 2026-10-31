use crate::memory::{Read, address};
use acz_coop_contracts::{Error, Result};
use acz_coop_game::{MemoryReader, PLAYER_STRIDE};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CameraSource {
    Player(u8),
    External,
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct View {
    pub owner: u32,
    pub primary: usize,
    pub secondary: usize,
    pub source: CameraSource,
}
pub(crate) fn capture(
    m: &impl MemoryReader,
    world: usize,
    players: usize,
    player_count: u8,
) -> Result<Vec<View>> {
    let r = Read(m);
    let count = r.dword(world, 0x67230)?;
    if count > 4 {
        return Err(Error::Bounds("native view count"));
    }
    let mut views = Vec::with_capacity(count as usize);
    for i in 0..count as usize {
        let primary = r.pointer(world, 0x671f0 + i * 8)?;
        let secondary = r.pointer(world, 0x67210 + i * 8)?;
        let owner = r.dword(world, 0x67234 + i * 4)?;
        let mut source = CameraSource::External;
        for slot in 0..player_count {
            let p = address(players, slot as usize * PLAYER_STRIDE)?;
            if primary == address(p, 0x10b0)? && secondary == address(p, 0x1270)? {
                source = CameraSource::Player(slot);
            }
        }
        views.push(View {
            owner,
            primary,
            secondary,
            source,
        });
    }
    if count != r.dword(world, 0x67230)? {
        return Err(Error::Epoch);
    }
    Ok(views)
}
