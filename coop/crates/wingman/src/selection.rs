use crate::memory::{Read, address};
use acz_coop_contracts::Result;
use acz_coop_game::MemoryReader;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Selection {
    // Native profile fields are DWORDs; world constructors consume their low byte.
    pub aircraft: u32,
    pub weapon: u32,
    pub option: u32,
    pub color: Option<[u8; 3]>,
}
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SelectionSnapshot {
    pub alternate_profile: bool,
    pub slots: [Selection; 2],
}
pub(crate) fn capture(m: &impl MemoryReader, base: usize) -> Result<SelectionSnapshot> {
    let r = Read(m);
    let alternate_profile = r.byte(base, 0x31cf18)? != 0;
    let profile = address(
        base,
        if alternate_profile {
            0x316e78
        } else {
            0x310ec0
        },
    )?;
    let slot = |i: usize| -> Result<Selection> {
        let aircraft = r.dword(profile, 0x24c + i * 4)?;
        // 1E0..24C holds 36 color triples. A larger raw ID is retained, never indexed.
        let color = if aircraft < 36 {
            Some(r.bytes(profile, 0x1e0 + aircraft as usize * 3)?)
        } else {
            None
        };
        Ok(Selection {
            aircraft,
            weapon: r.dword(profile, 0x254 + i * 4)?,
            option: r.dword(profile, 0x25c + i * 4)?,
            color,
        })
    };
    let result = SelectionSnapshot {
        alternate_profile,
        slots: [slot(0)?, slot(1)?],
    };
    if (r.byte(base, 0x31cf18)? != 0) != alternate_profile {
        return Err(acz_coop_contracts::Error::Epoch);
    }
    Ok(result)
}
