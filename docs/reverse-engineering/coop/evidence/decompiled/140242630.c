/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140242630; RVA 0x242630
 * Ghidra-generated research pseudocode, inferred types, not original source. */

uint FUN_140242630(void)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = FUN_14025244c();
  uVar2 = *(int *)(lVar1 + 0x28) * 0x343fd + 0x269ec3;
  *(uint *)(lVar1 + 0x28) = uVar2;
  return uVar2 >> 0x10 & 0x7fff;
}

