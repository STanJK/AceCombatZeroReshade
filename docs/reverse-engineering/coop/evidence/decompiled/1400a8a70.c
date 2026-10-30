/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a8a70; RVA 0xa8a70
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a8a70(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x90))();
  FUN_1400a46f0(param_1,param_2,0,uVar1);
  uVar1 = (**(code **)(*param_1 + 0x90))(param_1);
  uVar2 = (**(code **)(*param_1 + 0xa0))(param_1);
  FUN_1400a4680(param_1,param_2 + 0x9e,param_2,uVar2,uVar1);
  uVar1 = (**(code **)(*param_1 + 0x90))(param_1);
  uVar2 = (**(code **)(*param_1 + 0xa8))(param_1);
  FUN_1400a4680(param_1,param_2 + 0x9c,param_2,uVar2,uVar1);
  return;
}

