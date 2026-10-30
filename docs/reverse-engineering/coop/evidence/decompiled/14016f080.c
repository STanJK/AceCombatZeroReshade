/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016f080; RVA 0x16f080
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016f080(longlong param_1)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  undefined8 *puVar4;
  byte bVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  longlong lVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  longlong lVar16;
  undefined4 *puVar17;
  longlong lVar18;
  longlong lVar19;
  undefined4 *puVar20;
  
  lVar6 = FUN_140189320();
  *(byte *)(*(longlong *)(param_1 + 8) + 0xa87e1) = -(*(char *)(lVar6 + 0x1c) != '\0') & 2;
  FUN_1400cd880(*(undefined8 *)(param_1 + 8));
  lVar6 = DAT_14032c8f0;
  if (DAT_14031cf18 == '\0') {
    lVar18 = 0x140316e38;
    puVar12 = &DAT_140316e3c;
    puVar7 = &DAT_140316e40;
    puVar20 = &DAT_140316e44;
    puVar17 = &DAT_140316e48;
  }
  else {
    lVar18 = 0x14031cdf0;
    puVar12 = &DAT_14031cdf4;
    puVar7 = &DAT_14031cdf8;
    puVar20 = &DAT_14031cdfc;
    puVar17 = &DAT_14031ce00;
  }
  lVar13 = *(longlong *)(param_1 + 8);
  uVar10 = 0;
  if (*(char *)(lVar13 + 0xa87e4) != '\0') {
    do {
      lVar19 = (longlong)(int)uVar10;
      lVar16 = lVar19 * 0x1c;
      uVar15 = (ulonglong)(uVar10 & 0xff);
      lVar9 = uVar15 * 0x27a0;
      cVar3 = *(char *)(lVar16 + lVar18);
      *(char *)(lVar9 + 0x20ac + *(longlong *)(lVar13 + 0xa8248)) = cVar3;
      if (cVar3 == '\x01') {
        pbVar1 = (byte *)(lVar9 + 0x1676 + *(longlong *)(lVar13 + 0xa8248));
        *pbVar1 = *pbVar1 | 0x20;
      }
      else {
        pbVar1 = (byte *)(lVar9 + 0x1676 + *(longlong *)(lVar13 + 0xa8248));
        *pbVar1 = *pbVar1 & 0xdf;
      }
      bVar5 = *(byte *)(puVar12 + lVar19 * 7) & 0xf;
      lVar13 = uVar15 * 0xa8;
      *(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20ad + lVar9) = bVar5;
      if (bVar5 == 0) {
        *(undefined2 *)(lVar13 + 0x12 + lVar6) = 0xff0e;
        *(undefined1 *)(lVar13 + 0x20 + lVar6) = 1;
      }
      else if ((bVar5 == 1) || (bVar5 == 2)) {
        *(undefined2 *)(lVar13 + 0x12 + lVar6) = 0xff01;
        *(undefined1 *)(lVar13 + 0x20 + lVar6) = 0xe;
      }
      bVar5 = *(byte *)(puVar12 + lVar19 * 7);
      *(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20ae + lVar9) = bVar5 & 0xf0
      ;
      bVar5 = bVar5 >> 4;
      if (bVar5 == 0) {
        *(undefined2 *)(lVar13 + 0x27 + lVar6) = 0x611;
        *(undefined2 *)(lVar13 + 0x21 + lVar6) = 0x712;
      }
      else if (bVar5 == 1) {
        *(undefined2 *)(lVar13 + 0x27 + lVar6) = 0x712;
        *(undefined2 *)(lVar13 + 0x21 + lVar6) = 0x611;
      }
      *(undefined1 *)(lVar13 + 0x34 + lVar6) = *(undefined1 *)(lVar13 + 0x28 + lVar6);
      *(undefined1 *)(lVar13 + 0x35 + lVar6) = *(undefined1 *)(lVar13 + 0x27 + lVar6);
      cVar3 = *(char *)(puVar7 + lVar19 * 7);
      *(char *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x20af + lVar9) = cVar3;
      lVar13 = lVar13 + 0x24 + lVar6;
      lVar14 = 4;
      do {
        if (cVar3 == '\0') {
          *(undefined2 *)(lVar13 + -1) = 0xc0b;
        }
        else if (cVar3 == '\x01') {
          *(undefined2 *)(lVar13 + -1) = 0xb0c;
        }
        lVar13 = lVar13 + 0x2a;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
      FUN_1400d55c0(*(undefined8 *)(param_1 + 8),uVar15,*(undefined1 *)(puVar20 + lVar19 * 7));
      lVar13 = *(longlong *)(param_1 + 8);
      cVar3 = *(char *)(lVar16 + (longlong)puVar17);
      *(char *)(lVar9 + 0x20b1 + *(longlong *)(lVar13 + 0xa8248)) = cVar3;
      *(bool *)(lVar9 + 0x10a5 + *(longlong *)(lVar13 + 0xa8248)) = cVar3 == '\0';
      lVar13 = *(longlong *)(param_1 + 8);
      cVar3 = *(char *)(&DAT_140310e7c + lVar19 * 8);
      *(char *)(lVar9 + 0x20b2 + *(longlong *)(lVar13 + 0xa8248)) = cVar3;
      lVar13 = *(longlong *)(lVar13 + 0xa8248);
      if (cVar3 == '\0') {
        puVar2 = (uint *)(lVar9 + 0x2058 + lVar13);
        *puVar2 = *puVar2 & 0xfffeffff;
        pbVar1 = (byte *)(lVar9 + 0x1aea + lVar13);
        *pbVar1 = *pbVar1 & 0xfe;
      }
      else {
        puVar2 = (uint *)(lVar9 + 0x2058 + lVar13);
        *puVar2 = *puVar2 | 0x10000;
        pbVar1 = (byte *)(lVar9 + 0x1aea + lVar13);
        *pbVar1 = *pbVar1 | 1;
      }
      lVar13 = *(longlong *)(param_1 + 8);
      uVar10 = uVar10 + 1;
    } while ((int)uVar10 < (int)(uint)*(byte *)(lVar13 + 0xa87e4));
  }
  cVar3 = (char)DAT_140310e80;
  uVar11 = 0;
  *(char *)(lVar13 + 0xa88b3) = (char)DAT_140310e80;
  if (cVar3 == '\0') {
    lVar6 = FUN_140189320();
    *(undefined1 *)(lVar6 + 0x33) = 1;
  }
  else {
    lVar6 = FUN_140189320();
    *(undefined1 *)(lVar6 + 0x33) = 0;
  }
  FUN_1400d5680(*(undefined8 *)(param_1 + 8),(undefined1)DAT_140310e84);
  uVar8 = DAT_140316e30;
  if (DAT_14031cf18 != '\0') {
    uVar8 = DAT_14031cde8;
  }
  *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x2780) = uVar8;
  uVar8 = DAT_140316e30;
  if (DAT_14031cf18 != '\0') {
    uVar8 = DAT_14031cde8;
  }
  *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xa8248) + 0x2784) = uVar8;
  if ((*(int *)((longlong)DAT_14032c8b0 + 0xc) == -1) && (0 < (int)DAT_14032c8b0[1])) {
    lVar6 = DAT_14032c8b0[3];
    lVar18 = *DAT_14032c8b0;
    *(undefined4 *)((longlong)DAT_14032c8b0 + 0xc) = 0;
    puVar4 = *(undefined8 **)(lVar18 + 8);
    if (*(char *)(lVar6 + 0x21) == '\0') {
      *(undefined1 *)(lVar6 + 0x21) = 1;
      uVar11 = *(undefined8 *)(lVar6 + 0x10);
    }
    else {
      uVar11 = 0;
    }
    *puVar4 = 0x20000000;
    FUN_140197b30(puVar4,uVar11);
    puVar4[1] = 0;
  }
  uVar11 = FUN_1400ce700(*(undefined8 *)(param_1 + 8),uVar11);
  FUN_1402011a0(DAT_14032c8b0,uVar11);
  return 1;
}

