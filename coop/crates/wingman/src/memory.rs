use acz_coop_contracts::{Error, Result};
use acz_coop_game::MemoryReader;

pub(crate) fn address(base: usize, offset: usize) -> Result<usize> {
    if base == 0 {
        return Err(Error::Unavailable);
    }
    base.checked_add(offset)
        .ok_or(Error::Bounds("wingman address"))
}
pub(crate) struct Read<'a, M>(pub &'a M);
impl<M: MemoryReader> Read<'_, M> {
    pub fn bytes<const N: usize>(&self, base: usize, offset: usize) -> Result<[u8; N]> {
        let start = address(base, offset)?;
        start.checked_add(N).ok_or(Error::Bounds("wingman span"))?;
        let mut bytes = [0; N];
        self.0.read_exact(start, &mut bytes)?;
        Ok(bytes)
    }
    pub fn byte(&self, base: usize, offset: usize) -> Result<u8> {
        Ok(self.bytes::<1>(base, offset)?[0])
    }
    pub fn word(&self, base: usize, offset: usize) -> Result<u16> {
        Ok(u16::from_le_bytes(self.bytes(base, offset)?))
    }
    pub fn dword(&self, base: usize, offset: usize) -> Result<u32> {
        Ok(u32::from_le_bytes(self.bytes(base, offset)?))
    }
    pub fn optional_pointer(&self, base: usize, offset: usize) -> Result<Option<usize>> {
        let value = usize::try_from(u64::from_le_bytes(self.bytes(base, offset)?))
            .map_err(|_| Error::Bounds("wingman pointer width"))?;
        Ok((value != 0).then_some(value))
    }
    pub fn pointer(&self, base: usize, offset: usize) -> Result<usize> {
        self.optional_pointer(base, offset)?
            .ok_or(Error::Unavailable)
    }
}
