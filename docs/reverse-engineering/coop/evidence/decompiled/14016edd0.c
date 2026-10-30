/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016edd0; RVA 0x16edd0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016edd0(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  longlong lVar12;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(longlong *)(lVar1 + 0xa8270) == 0) {
    return 1;
  }
  if (*(char *)(lVar1 + 0xa8824) == '\0') {
    iVar9 = 0;
    uVar11 = 0;
    if (0 < *(int *)(lVar1 + 0xa8918)) {
      lVar12 = 0;
      iVar8 = 0;
      do {
        uVar3 = FUN_1400d52c0(iVar8,*(undefined8 *)(lVar1 + 0xa8280),iVar9);
        *(char *)(lVar12 + *(longlong *)(lVar1 + 0xa8910)) = (char)uVar3;
        uVar6 = FUN_140181690();
        FUN_140181950(uVar6,uVar3);
        lVar7 = FUN_140181690();
        lVar12 = lVar12 + 1;
        iVar8 = *(int *)(lVar7 + 0x50c) * *(int *)(lVar7 + 0x508);
        iVar10 = (*(int *)(lVar7 + 0x514) + iVar8 * 2) * 2 + 0x11ffff;
        uVar4 = iVar10 + (iVar10 >> 0x1f & 0xfffffU) & 0xfff00000;
        if ((int)uVar4 <= (int)uVar11) {
          uVar4 = uVar11;
        }
        uVar11 = uVar4;
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(int *)(lVar1 + 0xa8918));
    }
    uVar6 = FUN_140200de0(DAT_14032c8f8,uVar11,0x40);
    *(undefined8 *)(lVar1 + 0xa8900) = uVar6;
    iVar8 = FUN_1400d53a0();
    iVar9 = 0;
    iVar10 = 0;
    if (0 < *(int *)(lVar1 + 0xa8918)) {
      lVar12 = 0;
      do {
        piVar2 = *(int **)(lVar12 + *(longlong *)(lVar1 + 0xa88f8));
        if (((iVar8 < 0) || (*piVar2 <= iVar8)) || (piVar2[(longlong)iVar8 + 1] == 0)) {
          lVar7 = 0;
        }
        else {
          lVar7 = (longlong)piVar2 + (longlong)piVar2[(longlong)iVar8 + 1];
        }
        iVar5 = FUN_1401fd570(*(undefined8 *)(lVar1 + 0xa8278),lVar7);
        if (iVar9 < iVar5) {
          iVar9 = iVar5;
        }
        iVar10 = iVar10 + 1;
        lVar12 = lVar12 + 8;
      } while (iVar10 < *(int *)(lVar1 + 0xa8918));
    }
    uVar6 = FUN_140200de0(DAT_14032c8f8,iVar9,0x10);
    *(char *)(lVar1 + 0xa8824) = *(char *)(lVar1 + 0xa8824) + '\x01';
    *(undefined8 *)(lVar1 + 0xa8908) = uVar6;
  }
  else if (*(char *)(lVar1 + 0xa8824) == '\x01') {
    return 1;
  }
  return 0;
}

