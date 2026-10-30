/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140090360; RVA 0x90360
 * Ghidra-generated research pseudocode, inferred types, not original source. */

uint FUN_140090360(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 100);
  return ((uint)uVar1 * 0xbe00 & 0xff0000 | (uint)uVar1 * 0x780000 & 0xff0000ff |
         (uint)uVar1 * 0xfa & 0xff00) >> 8 | 0x80000000;
}

