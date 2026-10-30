/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14019fe80; RVA 0x19fe80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_14019fe80(longlong param_1,ushort param_2,ushort param_3,short *param_4)

{
  short sVar1;
  longlong lVar2;
  
  if (((((*(uint *)(param_1 + 0x40) & 0x8000) == 0) || (param_2 != 1)) &&
      ((short)param_2 <= *(short *)(param_1 + 0x28))) && (param_2 < 0x8000)) {
    if (*(short *)(param_1 + 0x2a) < (short)param_3) {
      return false;
    }
    if (0x7fff < param_3) {
      return false;
    }
    sVar1 = *(short *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + (longlong)(short)param_2 * 8) +
                      (longlong)(short)param_3 * 2);
    *param_4 = sVar1;
    if ((-1 < sVar1) && (*(longlong *)(param_1 + 0x20) != 0)) {
      lVar2 = FUN_1401a88c0(*(longlong *)(param_1 + 0x20) + 0x120);
      return lVar2 != 0;
    }
  }
  return false;
}

