/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401f5030; RVA 0x1f5030
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401f5030(undefined8 param_1,longlong *param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  
  uVar1 = *param_4;
  plVar4 = &DAT_14031dfd0;
  lVar5 = 0x10;
  do {
    plVar2 = (longlong *)*plVar4;
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x670))(plVar2,uVar1);
    }
    plVar4 = plVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  iVar3 = 0;
  if (DAT_14031dfc8 != (longlong *)0x0) {
    iVar3 = (**(code **)(*DAT_14031dfc8 + 0x670))(DAT_14031dfc8,uVar1);
  }
  *param_2 = (longlong)iVar3;
  return;
}

