/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401efb80; RVA 0x1efb80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401efb80(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined4 *in_R9;
  
  uVar1 = *in_R9;
  plVar7 = &DAT_14031dfd0;
  uVar2 = in_R9[2];
  lVar8 = 0x10;
  uVar3 = in_R9[4];
  uVar4 = in_R9[6];
  uVar5 = in_R9[8];
  do {
    plVar6 = (longlong *)*plVar7;
    if (plVar6 != (longlong *)0x0) {
      (**(code **)(*plVar6 + 0x20))(plVar6,uVar1,uVar2,uVar3,uVar4,uVar5);
    }
    plVar7 = plVar7 + 1;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  if (DAT_14031dfc8 != (longlong *)0x0) {
    (**(code **)(*DAT_14031dfc8 + 0x20))(DAT_14031dfc8,uVar1,uVar2,uVar3,uVar4,uVar5);
  }
  return;
}

