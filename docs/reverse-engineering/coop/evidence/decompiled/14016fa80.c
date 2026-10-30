/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016fa80; RVA 0x16fa80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016fa80(longlong param_1)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  longlong lVar9;
  undefined4 *puVar10;
  longlong *plVar11;
  int iVar12;
  int iVar13;
  longlong lVar14;
  longlong lVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined4 *puVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  longlong lVar22;
  undefined4 *puVar23;
  longlong lVar24;
  undefined4 *puVar25;
  
  lVar9 = FUN_140189320();
  *(byte *)(*(longlong *)(param_1 + 8) + 0xa87e1) = -(*(char *)(lVar9 + 0x1c) != '\0') & 2;
  FUN_1400cd880(*(undefined8 *)(param_1 + 8));
  lVar9 = DAT_14032c8f0;
  if (DAT_14031cf18 == '\0') {
    lVar24 = 0x140316e38;
    puVar18 = &DAT_140316e3c;
    puVar10 = &DAT_140316e40;
    puVar25 = &DAT_140316e44;
    puVar23 = &DAT_140316e48;
  }
  else {
    lVar24 = 0x14031cdf0;
    puVar18 = &DAT_14031cdf4;
    puVar10 = &DAT_14031cdf8;
    puVar25 = &DAT_14031cdfc;
    puVar23 = &DAT_14031ce00;
  }
  lVar19 = *(longlong *)(param_1 + 8);
  uVar16 = 0;
  if (*(char *)(lVar19 + 0xa87e4) != '\0') {
    do {
      lVar15 = (longlong)(int)uVar16;
      lVar22 = lVar15 * 0x1c;
      uVar21 = (ulonglong)(uVar16 & 0xff);
      lVar14 = uVar21 * 0x27a0;
      cVar3 = *(char *)(lVar22 + lVar24);
      *(char *)(lVar14 + 0x20ac + *(longlong *)(lVar19 + 0xa8248)) = cVar3;
      if (cVar3 == '\x01') {
        pbVar1 = (byte *)(lVar14 + 0x1676 + *(longlong *)(lVar19 + 0xa8248));
        *pbVar1 = *pbVar1 | 0x20;
      }
      else {
        pbVar1 = (byte *)(lVar14 + 0x1676 + *(longlong *)(lVar19 + 0xa8248));
        *pbVar1 = *pbVar1 & 0xdf;
      }
      bVar8 = *(byte *)(puVar18 + lVar15 * 7) & 0xf;
      lVar19 = uVar21 * 0xa8;
      *(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20ad + lVar14) = bVar8;
      if (bVar8 == 0) {
        *(undefined2 *)(lVar19 + 0x12 + lVar9) = 0xff0e;
        *(undefined1 *)(lVar19 + 0x20 + lVar9) = 1;
      }
      else if ((bVar8 == 1) || (bVar8 == 2)) {
        *(undefined2 *)(lVar19 + 0x12 + lVar9) = 0xff01;
        *(undefined1 *)(lVar19 + 0x20 + lVar9) = 0xe;
      }
      bVar8 = *(byte *)(puVar18 + lVar15 * 7);
      *(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20ae + lVar14) =
           bVar8 & 0xf0;
      bVar8 = bVar8 >> 4;
      if (bVar8 == 0) {
        *(undefined2 *)(lVar19 + 0x27 + lVar9) = 0x611;
        *(undefined2 *)(lVar19 + 0x21 + lVar9) = 0x712;
      }
      else if (bVar8 == 1) {
        *(undefined2 *)(lVar19 + 0x27 + lVar9) = 0x712;
        *(undefined2 *)(lVar19 + 0x21 + lVar9) = 0x611;
      }
      *(undefined1 *)(lVar19 + 0x34 + lVar9) = *(undefined1 *)(lVar19 + 0x28 + lVar9);
      *(undefined1 *)(lVar19 + 0x35 + lVar9) = *(undefined1 *)(lVar19 + 0x27 + lVar9);
      cVar3 = *(char *)(puVar10 + lVar15 * 7);
      *(char *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20af + lVar14) = cVar3;
      lVar19 = lVar19 + 0x24 + lVar9;
      lVar20 = 4;
      do {
        if (cVar3 == '\0') {
          *(undefined2 *)(lVar19 + -1) = 0xc0b;
        }
        else if (cVar3 == '\x01') {
          *(undefined2 *)(lVar19 + -1) = 0xb0c;
        }
        lVar19 = lVar19 + 0x2a;
        lVar20 = lVar20 + -1;
      } while (lVar20 != 0);
      FUN_1400d55c0(*(undefined8 *)(param_1 + 8),uVar21,*(undefined1 *)(puVar25 + lVar15 * 7));
      lVar19 = *(longlong *)(param_1 + 8);
      cVar3 = *(char *)(lVar22 + (longlong)puVar23);
      *(char *)(lVar14 + 0x20b1 + *(longlong *)(lVar19 + 0xa8248)) = cVar3;
      *(bool *)(*(longlong *)(lVar19 + 0xa8248) + 0x10a5 + lVar14) = cVar3 == '\0';
      lVar19 = *(longlong *)(param_1 + 8);
      cVar3 = *(char *)(&DAT_140310e7c + lVar15 * 8);
      *(char *)(lVar14 + 0x20b2 + *(longlong *)(lVar19 + 0xa8248)) = cVar3;
      lVar19 = *(longlong *)(lVar19 + 0xa8248);
      if (cVar3 == '\0') {
        puVar2 = (uint *)(lVar14 + 0x2058 + lVar19);
        *puVar2 = *puVar2 & 0xfffeffff;
        pbVar1 = (byte *)(lVar14 + 0x1aea + lVar19);
        *pbVar1 = *pbVar1 & 0xfe;
      }
      else {
        puVar2 = (uint *)(lVar14 + 0x2058 + lVar19);
        *puVar2 = *puVar2 | 0x10000;
        pbVar1 = (byte *)(lVar14 + 0x1aea + lVar19);
        *pbVar1 = *pbVar1 | 1;
      }
      lVar19 = *(longlong *)(param_1 + 8);
      uVar16 = uVar16 + 1;
    } while ((int)uVar16 < (int)(uint)*(byte *)(lVar19 + 0xa87e4));
  }
  uVar17 = 0;
  *(undefined1 *)(lVar19 + 0xa88b3) = 0;
  lVar9 = FUN_140189320();
  *(undefined1 *)(lVar9 + 0x33) = 1;
  FUN_1400d5680(*(undefined8 *)(param_1 + 8),(undefined1)DAT_140310e84);
  *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x2780) = DAT_14031cec0;
  *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x2784) = DAT_14031cec0;
  uVar6 = DAT_14031ce50;
  uVar16 = DAT_14031ce48._4_4_;
  lVar9 = (longlong)(int)DAT_14031ce50;
  lVar24 = (longlong)(int)DAT_14031ce48._4_4_;
  plVar11 = (longlong *)FUN_140189320();
  uVar7 = DAT_14031ce54;
  uVar5 = DAT_14031ce48._4_4_;
  if (((uVar16 < 7) && (uVar6 < 3)) && (*plVar11 != 0)) {
    iVar13 = (int)*(short *)(*plVar11 + (lVar9 + lVar24 * 8) * 2);
  }
  else {
    iVar13 = 0;
  }
  lVar24 = (longlong)(int)DAT_14031ce54;
  lVar9 = (longlong)(int)DAT_14031ce48._4_4_;
  plVar11 = (longlong *)FUN_140189320();
  if (((uVar5 < 7) && (uVar7 < 3)) && (*plVar11 != 0)) {
    iVar12 = (int)*(short *)(*plVar11 + 6 + (lVar24 + lVar9 * 8) * 2);
  }
  else {
    iVar12 = 0;
  }
  *(int *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8318) + 0x10) + 0x3f4) =
       iVar13;
  plVar11 = DAT_14032c8b0;
  *(int *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8318) + 0x10) + 0x3f8) =
       iVar12;
  if ((*(int *)((longlong)plVar11 + 0xc) == -1) && (0 < (int)plVar11[1])) {
    lVar9 = plVar11[3];
    *(undefined4 *)((longlong)plVar11 + 0xc) = 0;
    puVar4 = *(undefined8 **)(*plVar11 + 8);
    if (*(char *)(lVar9 + 0x21) == '\0') {
      *(undefined1 *)(lVar9 + 0x21) = 1;
      uVar17 = *(undefined8 *)(lVar9 + 0x10);
    }
    else {
      uVar17 = 0;
    }
    *puVar4 = 0x20000000;
    FUN_140197b30(puVar4,uVar17);
    puVar4[1] = 0;
  }
  uVar17 = FUN_1400ce700(*(undefined8 *)(param_1 + 8),uVar17);
  FUN_1402011a0(DAT_14032c8b0,uVar17);
  return 1;
}

