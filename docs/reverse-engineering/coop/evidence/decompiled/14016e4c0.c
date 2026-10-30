/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016e4c0; RVA 0x16e4c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14016e4c0(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  longlong lVar6;
  int iVar7;
  longlong lVar8;
  undefined4 *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong unaff_GS_OFFSET;
  undefined4 *local_res8;
  undefined4 *local_res10;
  
  if (DAT_14031cf18 == '\0') {
    local_res8 = &DAT_140316e40;
    lVar8 = 0x140316e38;
    local_res10 = &DAT_140316e44;
    puVar9 = &DAT_140316e3c;
    puVar1 = &DAT_140316e48;
  }
  else {
    local_res8 = &DAT_14031cdf8;
    lVar8 = 0x14031cdf0;
    local_res10 = &DAT_14031cdfc;
    puVar9 = &DAT_14031cdf4;
    puVar1 = &DAT_14031ce00;
  }
  lVar2 = *(longlong *)(param_1 + 8);
  uVar11 = 0;
  if (*(char *)(lVar2 + 0xa87e4) != '\0') {
    do {
      lVar6 = (uVar11 & 0xff) * 0x27a0;
      lVar10 = (longlong)(int)uVar11;
      *(uint *)(lVar10 * 0x1c + lVar8) =
           (uint)*(byte *)(*(longlong *)(lVar2 + 0xa8248) + 0x20ac + lVar6);
      bVar3 = *(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20ad + lVar6);
      puVar9[lVar10 * 7] = puVar9[lVar10 * 7] & 0xf0;
      uVar4 = bVar3 & 0xf;
      puVar9[lVar10 * 7] = puVar9[lVar10 * 7] | uVar4;
      lVar2 = FUN_140189320();
      *(char *)(lVar2 + 0x36) = (char)uVar4;
      bVar3 = *(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20ae + lVar6);
      puVar9[lVar10 * 7] = puVar9[lVar10 * 7] & 0xf;
      uVar4 = bVar3 & 0xf0;
      puVar9[lVar10 * 7] = puVar9[lVar10 * 7] | uVar4;
      lVar2 = FUN_140189320();
      *(char *)(lVar2 + 0x37) = (char)uVar4;
      local_res8[lVar10 * 7] =
           (uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20af + lVar6);
      local_res10[lVar10 * 7] =
           (uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20b0 + lVar6);
      uVar4 = (uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20b1 + lVar6);
      puVar1[lVar10 * 7] = uVar4;
      lVar2 = FUN_140189320();
      *(bool *)(lVar2 + 0x38) = uVar4 == 0;
      uVar4 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar4;
      (&DAT_140310e7c)[lVar10 * 8] =
           (uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20b2 + lVar6);
      lVar2 = *(longlong *)(param_1 + 8);
    } while ((int)uVar4 < (int)(uint)*(byte *)(lVar2 + 0xa87e4));
  }
  if (*(byte *)(lVar2 + 0xa87e4) < 2) {
    bVar3 = *(byte *)(lVar2 + 0xa88b3);
    DAT_140310e80 = (uint)bVar3;
    lVar8 = FUN_140189320();
    *(bool *)(lVar8 + 0x33) = bVar3 == 0;
  }
  piVar5 = (int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4);
  if ((*piVar5 < DAT_1437dad18) && (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  FUN_1401c5740(&DAT_1437daee0);
  DAT_14031f420 = 0;
  DAT_14031f428 = 0;
  DAT_14031f430 = 0;
  if ((*piVar5 < DAT_1437dad18) && (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  if ((*piVar5 < DAT_1437daf04) && (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
    FUN_1401c93c0();
    _Init_thread_footer(&DAT_1437daf04);
  }
  _DAT_1437decd0 = 0;
  lVar2 = FUN_140189320();
  lVar8 = DAT_14032c8f8;
  DAT_14032c933 = 0;
  DAT_14033dab0 = 0;
  *(undefined1 *)(lVar2 + 0x28) = 0;
  bVar3 = *(byte *)(lVar8 + 0x28);
  if (bVar3 == 0) {
    FUN_1401cb840("ERROR : Memory::freeMark : underflow!\n");
    return;
  }
  iVar7 = 0;
  if (0 < *(int *)(lVar8 + 0x18)) {
    lVar2 = 0;
    do {
      lVar6 = *(longlong *)(lVar8 + 0x10);
      if (bVar3 <= *(byte *)(lVar6 + 0x10 + lVar2)) {
        *(undefined8 *)(lVar6 + lVar2) = 0;
        *(undefined8 *)(lVar6 + 8 + lVar2) = 0;
        *(undefined1 *)(lVar6 + 0x10 + lVar2) = 0;
        bVar3 = *(byte *)(lVar8 + 0x28);
      }
      iVar7 = iVar7 + 1;
      lVar2 = lVar2 + 0x18;
    } while (iVar7 < *(int *)(lVar8 + 0x18));
  }
  *(byte *)(lVar8 + 0x28) = bVar3 - 1;
  return;
}

