/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c6a50; RVA 0xc6a50
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_1400c6a50(uchar *arg1,uchar arg2,uchar arg3,uchar *arg4,uchar *arg5,uchar *arg6,
                  ulonglong arg7,uchar *arg8,uchar *arg9,uchar *arg10)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  uchar uVar4;
  undefined4 uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  longlong lVar11;
  uint uVar12;
  byte *pbVar13;
  uchar *puVar14;
  longlong lVar15;
  longlong lVar16;
  int iVar17;
  longlong lVar18;
  
  arg1[0xa87e4] = arg2;
  iVar17 = 0;
  if (arg2 != '\0') {
    puVar14 = arg6;
    do {
      uVar12 = 0;
      uVar4 = '\0';
      if (arg6 != (uchar *)0x0) {
        uVar4 = *puVar14;
      }
      if (arg4 != (uchar *)0x0) {
        uVar12 = (uint)puVar14[(longlong)arg4 - (longlong)arg6];
      }
      if (uVar4 == '\0') {
        iVar10 = 0x95;
      }
      else if (uVar4 == '\x01') {
        iVar10 = 0xb9;
      }
      else if (uVar4 == '\x02') {
        iVar10 = 0xdd;
      }
      else if (uVar4 == '\x04') {
        iVar10 = 0x101;
      }
      else if (uVar4 == '\x03') {
        iVar10 = 0x125;
      }
      else {
        iVar10 = 0x101;
        if (uVar4 == '\x05') {
          iVar10 = 0x149;
        }
      }
      plVar6 = (longlong *)FUN_1402014c0();
      if ((*(int *)((longlong)plVar6 + 0x7a4) != 0) && (*(int *)((longlong)plVar6 + 0x7a4) == 1)) {
        plVar6 = plVar6 + 0x66;
      }
      (**(code **)(*plVar6 + 0x38))(plVar6,iVar10 + uVar12);
      iVar17 = iVar17 + 1;
      puVar14[(longlong)(arg1 + (0xa881e - (longlong)arg6))] = (uchar)uVar12;
      puVar14 = puVar14 + 1;
    } while (iVar17 < (int)(uint)arg1[0xa87e4]);
  }
  lVar16 = 0;
  arg1[0xa82f0] = '\0';
  arg1[0xa82f1] = '\0';
  arg1[0xa82f2] = '\0';
  arg1[0xa82f3] = '\0';
  if ((arg5 != (uchar *)0x0) && (arg3 != '\0')) {
    lVar11 = 0;
    do {
      bVar2 = arg5[lVar11];
      if (bVar2 == 0xff) break;
      plVar6 = (longlong *)FUN_1402014c0();
      if ((*(int *)((longlong)plVar6 + 0x7a4) != 0) && (*(int *)((longlong)plVar6 + 0x7a4) == 1)) {
        plVar6 = plVar6 + 0x66;
      }
      (**(code **)(*plVar6 + 0x38))(plVar6,bVar2 + 0x16c);
      *(int *)(arg1 + 0xa82f0) = *(int *)(arg1 + 0xa82f0) + 1;
      lVar11 = lVar11 + 1;
    } while (lVar11 < (longlong)(ulonglong)arg3);
  }
  plVar6 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar6 + 0x7a4) != 0) && (*(int *)((longlong)plVar6 + 0x7a4) == 1)) {
    plVar6 = plVar6 + 0x66;
  }
  uVar5 = (**(code **)(*plVar6 + 0x18))();
  uVar7 = FUN_140200de0(DAT_14032c8f8,uVar5,0x10);
  plVar6 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar6 + 0x7a4) != 0) && (*(int *)((longlong)plVar6 + 0x7a4) == 1)) {
    plVar6 = plVar6 + 0x66;
  }
  (**(code **)(*plVar6 + 0x48))(plVar6,uVar7);
  uVar7 = DAT_14032c8f8;
  uVar8 = FUN_140200de0(DAT_14032c8f8,(uint)arg1[0xa87e4] * 0x27a0,0x10);
  *(undefined8 *)(arg1 + 0xa8248) = uVar8;
  uVar8 = FUN_140200de0(uVar7,(uint)arg1[0xa87e4] * 0x70,0x10);
  *(undefined8 *)(arg1 + 0x671c0) = uVar8;
  uVar8 = FUN_140200de0(uVar7,(ulonglong)arg1[0xa87e4] << 3,0x10);
  *(undefined8 *)(arg1 + 0x67180) = uVar8;
  uVar8 = FUN_140200de0(uVar7,(ulonglong)arg1[0xa87e4] << 3,0x10);
  iVar17 = 0;
  *(undefined8 *)(arg1 + 0x67188) = uVar8;
  if (arg1[0xa87e4] != '\0') {
    lVar11 = 0;
    lVar18 = 0;
    pbVar13 = arg8;
    do {
      *(undefined8 *)(lVar18 + *(longlong *)(arg1 + 0x67180)) = 0;
      *(undefined8 *)(lVar18 + *(longlong *)(arg1 + 0x67188)) = 0;
      lVar15 = *(longlong *)(arg1 + 0xa8248) + lVar16;
      FUN_1400c4660(lVar15);
      lVar3 = *(longlong *)(arg1 + 0x671c0);
      *(undefined ***)(lVar11 + lVar3) = &PTR_FUN_1402c7090;
      *(undefined8 *)(lVar11 + 0x4c + lVar3) = 0;
      *(undefined8 *)(lVar11 + 0x54 + lVar3) = 0;
      *(undefined8 *)(lVar11 + 0x5c + lVar3) = 0;
      *(undefined8 *)(lVar11 + 100 + lVar3) = 0;
      *(undefined8 *)(lVar11 + 0x28 + lVar3) = 0;
      *(undefined8 *)(lVar11 + 0x30 + lVar3) = 0;
      *(undefined4 *)(lVar11 + 0x38 + lVar3) = 0;
      *(undefined4 *)(lVar11 + 0x3c + lVar3) = 0xe0f;
      *(undefined4 *)(lVar11 + 0x40 + lVar3) = 0x3000003;
      *(undefined1 *)(lVar11 + 0x44 + lVar3) = 1;
      *(undefined8 *)(lVar11 + 8 + lVar3) = 0;
      *(undefined8 *)(lVar11 + 0x10 + lVar3) = 0;
      *(undefined8 *)(lVar11 + 0x18 + lVar3) = 0;
      *(undefined4 *)(lVar11 + 0x20 + lVar3) = 0;
      if (arg8 != (uchar *)0x0) {
        uVar9 = (ulonglong)*pbVar13;
        *(byte *)(lVar15 + 0x279a) = *pbVar13;
        *(ulonglong *)(lVar15 + 0xfd8) = lVar15 + (uVar9 * 3 + 0x1f2) * 8;
        if ((*(longlong *)(lVar15 + 0x2000 + uVar9 * 8) != 0) &&
           (*(longlong *)(lVar15 + 0x2018 + uVar9 * 8) != 0)) {
          FUN_1400adac0(*(undefined8 *)(lVar15 + 0x1890));
          FUN_1400c5010(lVar15);
        }
      }
      iVar17 = iVar17 + 1;
      lVar18 = lVar18 + 8;
      lVar16 = lVar16 + 0x27a0;
      lVar11 = lVar11 + 0x70;
      pbVar1 = pbVar13 + (longlong)(arg1 + (0xa881e - (longlong)arg8));
      pbVar13 = pbVar13 + 1;
      *(byte *)(lVar15 + 0x20a3) = *pbVar1;
      *(uchar *)(lVar15 + 0x20a9) = *arg10;
      *(uchar *)(lVar15 + 0x20aa) = arg10[1];
      *(uchar *)(lVar15 + 0x20ab) = arg10[2];
    } while (iVar17 < (int)(uint)arg1[0xa87e4]);
    uVar7 = DAT_14032c8f8;
  }
  if (0 < *(int *)(arg1 + 0xa82f0)) {
    uVar8 = FUN_140200de0(uVar7,*(int *)(arg1 + 0xa82f0) * 0x108,0x10);
    iVar17 = 0;
    *(undefined8 *)(arg1 + 0xa82f8) = uVar8;
    if (0 < *(int *)(arg1 + 0xa82f0)) {
      lVar16 = 0;
      pbVar13 = arg9;
      do {
        lVar11 = *(longlong *)(arg1 + 0xa82f8) + lVar16;
        *(undefined8 *)(lVar11 + 0x98) = 0;
        *(undefined8 *)(lVar11 + 0xa0) = 0;
        *(undefined8 *)(lVar11 + 0xa8) = 0;
        *(undefined8 *)(lVar11 + 0xb0) = 0;
        *(undefined8 *)(lVar11 + 0xb8) = 0;
        *(undefined8 *)(lVar11 + 0xc0) = 0;
        *(undefined8 *)(lVar11 + 200) = 0;
        *(undefined8 *)(lVar11 + 0xd0) = 0;
        *(undefined8 *)(lVar11 + 0xd8) = 0;
        *(undefined8 *)(lVar11 + 0xe0) = 0;
        *(undefined8 *)(lVar11 + 0xe8) = 0;
        *(undefined8 *)(lVar11 + 0xf0) = 0;
        *(undefined8 *)(lVar11 + 0x50) = 0;
        *(undefined8 *)(lVar11 + 0x58) = 0;
        *(undefined8 *)(lVar11 + 0x60) = 0;
        *(undefined4 *)(lVar11 + 0x84) = 0;
        *(undefined8 *)(lVar11 + 8) = 0;
        *(undefined8 *)(lVar11 + 0x10) = 0;
        *(undefined8 *)(lVar11 + 0x18) = 0;
        *(undefined8 *)(lVar11 + 0x20) = 0;
        *(undefined8 *)(lVar11 + 0x28) = 0;
        *(undefined8 *)(lVar11 + 0x30) = 0;
        *(undefined8 *)(lVar11 + 0x38) = 0;
        *(undefined8 *)(lVar11 + 0x40) = 0;
        *(undefined8 *)(lVar11 + 0x48) = 0;
        *(undefined8 *)(lVar11 + 0x70) = 0;
        *(undefined8 *)(lVar11 + 0x78) = 0;
        *(undefined4 *)(lVar11 + 0x80) = 0xff00003c;
        *(undefined1 *)(lVar11 + 0xf8) = 0;
        *(undefined1 *)(lVar11 + 0x88) = 0;
        if (arg5 != (uchar *)0x0) {
          *(byte *)(lVar11 + 0x84) = pbVar13[(longlong)arg5 - (longlong)arg9];
        }
        if (arg9 != (uchar *)0x0) {
          bVar2 = *pbVar13;
          *(byte *)(lVar11 + 0x85) = bVar2;
          *(undefined8 *)(lVar11 + 0x68) = *(undefined8 *)(lVar11 + 0x50 + (ulonglong)bVar2 * 8);
        }
        iVar17 = iVar17 + 1;
        lVar16 = lVar16 + 0x108;
        pbVar13 = pbVar13 + 1;
      } while (iVar17 < *(int *)(arg1 + 0xa82f0));
    }
  }
  uVar7 = FUN_140200de0(uVar7,(uint)arg1[0xa87e4] * 0x3a0,0x10);
  *(undefined8 *)(arg1 + 0xa8218) = uVar7;
  return;
}

