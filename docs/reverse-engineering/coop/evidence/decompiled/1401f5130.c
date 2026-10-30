/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401f5130; RVA 0x1f5130
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401f5130(void)

{
  undefined4 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined4 *in_R9;
  
  uVar1 = *in_R9;
  plVar3 = &DAT_14031dfd0;
  lVar4 = 0x10;
  do {
    plVar2 = (longlong *)*plVar3;
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x680))(plVar2,uVar1);
    }
    plVar3 = plVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if (DAT_14031dfc8 != (longlong *)0x0) {
    (**(code **)(*DAT_14031dfc8 + 0x680))(DAT_14031dfc8,uVar1);
  }
  return;
}

