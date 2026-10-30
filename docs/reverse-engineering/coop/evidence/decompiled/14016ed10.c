/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016ed10; RVA 0x16ed10
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016ed10(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(longlong *)(lVar1 + 0xa8270) == 0) {
    return 1;
  }
  plVar3 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar3 + 0x7a4) != 0) && (*(int *)((longlong)plVar3 + 0x7a4) == 1)) {
    plVar3 = plVar3 + 0x66;
  }
  cVar2 = (**(code **)(*plVar3 + 0x60))(plVar3,0);
  if (cVar2 == '\0') {
    return 0;
  }
  iVar5 = 0;
  if (0 < *(int *)(lVar1 + 0xa8918)) {
    lVar6 = 0;
    do {
      plVar3 = (longlong *)FUN_1402014c0();
      if ((*(int *)((longlong)plVar3 + 0x7a4) != 0) && (*(int *)((longlong)plVar3 + 0x7a4) == 1)) {
        plVar3 = plVar3 + 0x66;
      }
      uVar4 = (**(code **)(*plVar3 + 0x70))(plVar3,iVar5);
      iVar5 = iVar5 + 1;
      *(undefined8 *)(lVar6 + *(longlong *)(lVar1 + 0xa88f8)) = uVar4;
      lVar6 = lVar6 + 8;
    } while (iVar5 < *(int *)(lVar1 + 0xa8918));
  }
  return 1;
}

