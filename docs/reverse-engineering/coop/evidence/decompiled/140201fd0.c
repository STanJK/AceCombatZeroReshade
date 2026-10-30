/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140201fd0; RVA 0x201fd0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ulonglong FUN_140201fd0(byte param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong in_RAX;
  
  if (*(char *)((ulonglong)param_1 + 0x80 + DAT_14032c8c0) == -1) {
    return in_RAX & 0xffffffffffffff00;
  }
  lVar3 = *(longlong *)(DAT_14032c8c0 + (ulonglong)param_1 * 8);
  bVar1 = *(byte *)((ulonglong)param_2 + 0x10 +
                   (longlong)*(char *)(lVar3 + 0x2e) * 0x1b + DAT_14032c8c0);
  uVar2 = *(uint *)(lVar3 + 0x38 + (ulonglong)(bVar1 >> 5) * 4);
  return (ulonglong)CONCAT31((int3)(uVar2 >> 8),(uVar2 >> (bVar1 & 0x1f) & 1) != 0);
}

