/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14007b080; RVA 0x7b080
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14007b080(longlong *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = DAT_1402d2d2c;
  fVar1 = DAT_1402d2168;
  fVar4 = DAT_1402d1f2c;
  fVar3 = *(float *)(*param_1 + 0xc) * DAT_1402d1f2c + *(float *)(param_1 + 0x15);
  *(float *)(param_1 + 0x15) = fVar3;
  if (fVar3 <= fVar1) {
    if (fVar3 < fVar2) {
      *(undefined4 *)(param_1 + 0x15) = 0x3f000000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x15) = 0xbf000000;
  }
  fVar4 = *(float *)(*param_1 + 0x10) * fVar4 + *(float *)((longlong)param_1 + 0xac);
  *(float *)((longlong)param_1 + 0xac) = fVar4;
  if (fVar1 < fVar4) {
    *(undefined4 *)((longlong)param_1 + 0xac) = 0xbf000000;
    return;
  }
  if (fVar4 < fVar2) {
    *(undefined4 *)((longlong)param_1 + 0xac) = 0x3f000000;
  }
  return;
}

