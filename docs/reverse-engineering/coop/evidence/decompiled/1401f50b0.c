/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401f50b0; RVA 0x1f50b0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401f50b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 *in_R9;
  
  uVar1 = *in_R9;
  plVar4 = &DAT_14031dfd0;
  uVar2 = in_R9[2];
  lVar5 = 0x10;
  do {
    plVar3 = (longlong *)*plVar4;
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x678))(plVar3,uVar1,uVar2);
    }
    plVar4 = plVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if (DAT_14031dfc8 != (longlong *)0x0) {
    (**(code **)(*DAT_14031dfc8 + 0x678))(DAT_14031dfc8,uVar1,uVar2);
  }
  return;
}

