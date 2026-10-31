/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016d1c0; RVA 0x16d1c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016d1c0(longlong param_1)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined8 *puVar5;
  undefined1 (*pauVar6) [16];
  longlong lVar7;
  uint *puVar8;
  undefined **ppuVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  undefined4 local_18;
  int iStack_14;
  
  pauVar6 = (undefined1 (*) [16])&DAT_14031cdec;
  if (DAT_14031cf18 != '\0') {
    DAT_14031111c = DAT_1403170d4;
    DAT_140311114 = DAT_1403170cc;
    DAT_14031110c = DAT_1403170c4;
  }
  else {
    pauVar6 = (undefined1 (*) [16])&DAT_140316e34;
  }
  auVar4 = *pauVar6;
  auVar3 = *pauVar6;
  uVar1 = *(undefined8 *)pauVar6[1];
  uVar2 = *(uint *)((longlong)pauVar6[1] + 8);
  if (DAT_14031cf18 != '\0') {
    DAT_140311120 = DAT_1403170d8;
    DAT_140311118 = DAT_1403170d0;
    DAT_140311110 = DAT_1403170c8;
  }
  uVar13 = (uint)*(undefined8 *)((longlong)*pauVar6 + 8);
  DAT_14031cf18 = '\0';
  uVar12 = uVar13 & 0xf;
  DAT_14031ce34 = 0;
  DAT_140316e3c = DAT_140316e3c & 0xf0 | uVar12;
  lVar7 = FUN_140189320();
  *(char *)(lVar7 + 0x36) = (char)uVar12;
  if (DAT_14031cf18 == '\0') {
    puVar8 = &DAT_140316e3c;
    uVar12 = DAT_140316e3c;
  }
  else {
    puVar8 = &DAT_14031cdf4;
    uVar12 = DAT_14031cdf4;
  }
  uVar13 = uVar13 & 0xf0;
  *puVar8 = uVar12 & 0xf | uVar13;
  lVar7 = FUN_140189320();
  puVar5 = &DAT_14031cdec;
  *(char *)(lVar7 + 0x37) = (char)uVar13;
  if (DAT_14031cf18 == '\0') {
    puVar5 = &DAT_140316e34;
  }
  *(int *)((longlong)puVar5 + 4) = auVar3._4_4_;
  if (DAT_14031cf18 == '\0') {
    puVar8 = &DAT_140316e4c;
    uVar12 = DAT_140316e4c;
  }
  else {
    puVar8 = &DAT_14031ce04;
    uVar12 = DAT_14031ce04;
  }
  uVar13 = uVar2 & 0xf;
  *puVar8 = uVar12 & 0xf0 | uVar13;
  if (uVar13 == 0) {
    lVar7 = FUN_140189320();
    *(undefined1 *)(lVar7 + 0x35) = 0;
  }
  else if (uVar13 == 1) {
    lVar7 = FUN_140189320();
    *(undefined1 *)(lVar7 + 0x35) = 1;
  }
  ppuVar9 = &PTR_PTR_140316e70;
  if (DAT_14031cf18 == '\0') {
    ppuVar9 = &PTR_PTR_140310eb8;
  }
  FUN_14018a160(ppuVar9,uVar2);
  puVar10 = &DAT_14031cdf8;
  if (DAT_14031cf18 == '\0') {
    puVar10 = &DAT_140316e40;
  }
  *puVar10 = auVar4._12_4_;
  puVar10 = &DAT_14031cdfc;
  if (DAT_14031cf18 == '\0') {
    puVar10 = &DAT_140316e44;
  }
  local_18 = (undefined4)uVar1;
  *puVar10 = local_18;
  piVar11 = &DAT_14031ce00;
  if (DAT_14031cf18 == '\0') {
    piVar11 = &DAT_140316e48;
  }
  iStack_14 = (int)((ulonglong)uVar1 >> 0x20);
  *piVar11 = iStack_14;
  lVar7 = FUN_140189320();
  *(bool *)(lVar7 + 0x38) = iStack_14 == 0;
  *(undefined4 *)(param_1 + 0x3b8) = 2;
  return;
}

