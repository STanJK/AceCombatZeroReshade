/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a4880; RVA 0xa4880
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a4880(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  float fVar2;
  float fVar3;
  float local_res8 [2];
  
  FUN_1400a63f0(param_2,local_res8);
  uVar1 = (**(code **)(*param_1 + 0x90))(param_1);
  FUN_1400a46f0(param_1,param_2,local_res8[0],uVar1);
  fVar3 = (DAT_1402d2134 - *(float *)(param_2 + 0x54)) * DAT_1402d23f0;
  if (0.0 < fVar3) {
    uVar1 = (**(code **)(*param_1 + 0x90))(param_1);
    fVar2 = (float)(**(code **)(*param_1 + 0xb0))(param_1);
    FUN_1400a4680(param_1,param_2 + 0x9e,param_2,fVar2 * fVar3,uVar1);
  }
  uVar1 = (**(code **)(*param_1 + 0x90))(param_1);
  fVar3 = (float)(**(code **)(*param_1 + 0xb8))(param_1);
  FUN_1400a4680(param_1,param_2 + 0x9c,param_2,fVar3 * local_res8[0],uVar1);
  return;
}

