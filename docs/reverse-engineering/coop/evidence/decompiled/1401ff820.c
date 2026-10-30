/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ff820; RVA 0x1ff820
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401ff820(undefined8 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  char cVar11;
  int iVar12;
  undefined8 *puVar13;
  byte bVar14;
  longlong unaff_GS_OFFSET;
  undefined1 local_48 [16];
  short local_38;
  
  plVar7 = DAT_14032c8b0;
  lVar5 = DAT_14032c8a8;
  if (DAT_14032c93c != '\0') {
    return true;
  }
  uVar10 = 0;
  if (*(char *)(DAT_14032c8a8 + 0x21) == '\0') {
    uVar10 = *(undefined8 *)(DAT_14032c8a8 + 0x10);
  }
  *(undefined8 *)(DAT_14032c8a8 + 0x10) = uVar10;
  *(undefined1 *)(lVar5 + 0x21) = 0;
  plVar7[3] = lVar5;
  if (*(char *)(lVar5 + 0x21) == '\0') {
    *(undefined1 *)(lVar5 + 0x21) = 1;
    puVar9 = *(undefined8 **)(lVar5 + 0x10);
  }
  else {
    puVar9 = (undefined8 *)0x0;
  }
  iVar12 = 0;
  puVar13 = (undefined8 *)*plVar7;
  if (0 < (int)plVar7[1]) {
    do {
      *puVar13 = puVar9;
      puVar13[2] = puVar9 + 2;
      puVar13[1] = puVar9;
      *(undefined4 *)(puVar13 + 3) = 0;
      *puVar9 = 0x20000000;
      FUN_140197b30(puVar9);
      puVar9[1] = 0;
      puVar13 = puVar13 + 4;
      puVar9 = puVar9 + 2;
      iVar12 = iVar12 + 1;
    } while (iVar12 < (int)plVar7[1]);
  }
  lVar5 = plVar7[3];
  plVar7[2] = (longlong)puVar9;
  if (*(char *)(lVar5 + 0x21) != '\0') {
    *(undefined8 **)(lVar5 + 0x10) = puVar9 + 2;
    *(undefined1 *)(lVar5 + 0x21) = 0;
  }
  lVar5 = FUN_140189320();
  *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
  FUN_140201dc0();
  cVar4 = (**(code **)(*(longlong *)*param_1 + 0x30))();
  (**(code **)(*(longlong *)*param_1 + 0x38))();
  plVar7 = DAT_14032c8b0;
  if (*(int *)((longlong)DAT_14032c8b0 + 0xc) == -1) {
    if ((int)DAT_14032c8b0[1] < 2) {
      uVar10 = 0;
    }
    else {
      lVar5 = DAT_14032c8b0[3];
      lVar6 = *DAT_14032c8b0;
      *(undefined4 *)((longlong)DAT_14032c8b0 + 0xc) = 1;
      puVar9 = *(undefined8 **)(lVar6 + 0x28);
      if (*(char *)(lVar5 + 0x21) == '\0') {
        *(undefined1 *)(lVar5 + 0x21) = 1;
        uVar10 = *(undefined8 *)(lVar5 + 0x10);
      }
      else {
        uVar10 = 0;
      }
      *puVar9 = 0x20000000;
      FUN_140197b30(puVar9,uVar10);
      plVar7 = DAT_14032c8b0;
      puVar9[1] = 0;
    }
  }
  else {
    uVar10 = 0;
  }
  FUN_1402011a0(plVar7,uVar10);
  plVar7 = DAT_14032c8b0;
  lVar5 = DAT_14032c8b0[3];
  if (*(char *)(lVar5 + 0x21) == '\0') {
    *(undefined1 *)(lVar5 + 0x21) = 1;
    uVar10 = *(undefined8 *)(lVar5 + 0x10);
  }
  else {
    uVar10 = 0;
  }
  puVar9 = (undefined8 *)plVar7[2];
  *puVar9 = 0x20000000;
  FUN_140197b30(puVar9,uVar10);
  puVar9[1] = 0;
  lVar5 = plVar7[3];
  if (*(char *)(lVar5 + 0x21) != '\0') {
    *(undefined8 *)(lVar5 + 0x10) = uVar10;
    *(undefined1 *)(lVar5 + 0x21) = 0;
  }
  if ((*(uint *)(DAT_14032c8b8 + 0xd4) & 0x20) == 0) {
    puVar9 = *(undefined8 **)(DAT_14032c8b8 + 0xc0);
    *(uint *)(DAT_14032c8b8 + 0xd4) = *(uint *)(DAT_14032c8b8 + 0xd4) | 0x20;
  }
  else {
    puVar9 = (undefined8 *)0x0;
  }
  lVar5 = DAT_14032c8a8;
  puVar3 = *(undefined8 **)(DAT_14032c8a8 + 0x10);
  *puVar3 = 0x10000001;
  puVar13 = puVar3 + 4;
  *(undefined4 *)(puVar3 + 1) = 0;
  *(undefined4 *)((longlong)puVar3 + 0xc) = 0x50000001;
  puVar3[2] = 0x8000;
  puVar3[3] = 0;
  uVar10 = *(undefined8 *)(lVar5 + (longlong)*(char *)(lVar5 + 0x20) * 8);
  *puVar9 = 0x20000000;
  FUN_140197b30(puVar9,uVar10);
  puVar9[1] = 0;
  *puVar13 = 0x20000000;
  FUN_140197b30(puVar13,puVar9 + 2);
  puVar3[5] = 0;
  uVar8 = ((int)puVar13 - *(int *)(lVar5 + (longlong)*(char *)(lVar5 + 0x20) * 8)) + 0x10;
  if (*(uint *)(lVar5 + 0x1c) < uVar8) {
    *(uint *)(lVar5 + 0x1c) = uVar8;
  }
  cVar11 = '\x01' - *(char *)(lVar5 + 0x20);
  *(char *)(lVar5 + 0x20) = cVar11;
  *(char *)(lVar5 + 0x22) =
       (char)(int)(((float)uVar8 / (float)*(uint *)(lVar5 + 0x18)) * DAT_1402d271c);
  *(undefined8 *)(lVar5 + 0x10) = *(undefined8 *)(lVar5 + (longlong)cVar11 * 8);
  lVar5 = DAT_14032c8b8;
  puVar1 = (uint *)(DAT_14032c8b8 + 0xd4);
  if ((*puVar1 & 0x20) != 0) {
    *(undefined8 **)(DAT_14032c8b8 + 0xc0) = puVar9 + 2;
    *(uint *)(lVar5 + 0xd4) = *puVar1 & 0xffffffdf;
  }
  lVar5 = FUN_1401c56d0();
  lVar6 = FUN_140189320();
  uVar2 = *(undefined4 *)(lVar6 + 0xc);
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401ca370(&DAT_1437daf20);
  if ((DAT_14031f8b1 & 1) != 0) {
    bVar14 = DAT_14031f8b1;
    iVar12 = FUN_140187060((int)(char)(&DAT_14031f8ae)[(ulonglong)DAT_14031f8b0 * -4],local_48);
    if ((iVar12 == 0) && (local_38 == 0)) {
      DAT_14031f8b1 = bVar14 & 0xfe;
    }
  }
  FUN_140184180(uVar2);
  FUN_140184780(uVar2);
  FUN_1401c6b70(lVar5);
  *(byte *)(lVar5 + 0x14) = *(byte *)(lVar5 + 0x14) & 0xfc;
  FUN_1401fe9c0(DAT_14032c8b8);
  return cVar4 == '\0';
}

