/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401eda90; RVA 0x1eda90
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401eda90(longlong param_1,undefined4 param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = (longlong *)(param_1 + 0x10);
  lVar3 = 0x10;
  do {
    plVar1 = (longlong *)*plVar2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))(plVar1,param_2);
    }
    plVar2 = plVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  plVar2 = *(longlong **)(param_1 + 8);
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x10))(plVar2,param_2);
  }
  return;
}

