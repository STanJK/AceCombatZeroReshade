/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401f51a0; RVA 0x1f51a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401f51a0(undefined8 param_1,longlong *param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  
  uVar1 = *param_4;
  plVar5 = &DAT_14031dfd0;
  uVar2 = param_4[2];
  lVar6 = 0x10;
  do {
    plVar3 = (longlong *)*plVar5;
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x688))(plVar3,uVar1,uVar2);
    }
    plVar5 = plVar5 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  iVar4 = 0;
  if (DAT_14031dfc8 != (longlong *)0x0) {
    iVar4 = (**(code **)(*DAT_14031dfc8 + 0x688))(DAT_14031dfc8,uVar1,uVar2);
  }
  *param_2 = (longlong)iVar4;
  return;
}

