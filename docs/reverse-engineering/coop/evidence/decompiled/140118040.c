/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140118040; RVA 0x118040
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140118040(longlong *param_1,longlong *param_2,longlong param_3,uint param_4,char param_5,
                  longlong param_6,char param_7)

{
  int *piVar1;
  ushort uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  bool bVar5;
  char cVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  byte *pbVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined1 *puVar12;
  byte bVar13;
  short sVar14;
  ulonglong uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  ulonglong uVar19;
  undefined2 uVar20;
  longlong lVar21;
  longlong *local_res18;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if ((param_3 != 0) &&
     (*(char *)((ulonglong)*(byte *)((longlong)param_1 + 0x235) + param_3) != '\0')) {
    return;
  }
  if ((*(uint *)(param_1 + 0x3e) & 0x8000) != 0) {
    return;
  }
  bVar5 = false;
  if (((param_6 != 0) &&
      (((cVar6 = *(char *)(**(longlong **)(param_6 + 0x388) + 0x15d), cVar6 == '\0' ||
        (cVar6 == '\x02')) && (*(char *)(param_6 + 0x235) != '\0')))) &&
     (((*(uint *)((longlong)param_1 + 500) >> 3 & 1) != 0 ||
      ((*(uint *)((longlong)param_1 + 500) >> 2 & 1) != 0)))) {
    bVar5 = true;
  }
  if ((*(uint *)((longlong)param_1 + 500) >> 4 & 1) != 0) {
    return;
  }
  if (bVar5) {
    return;
  }
  bVar13 = 100;
  uVar20 = 100;
  if (param_7 == '\x03') {
    bVar5 = false;
    if (((param_6 != 0) &&
        (cVar6 = *(char *)(**(longlong **)(param_6 + 0x388) + 0x15d), cVar6 != '\0')) &&
       (cVar6 != '\x02')) {
      bVar5 = false;
      if (*(char *)(param_6 + 0x234) != -1) {
        bVar5 = true;
      }
    }
    if (param_1[0x37] == 0) {
      if (*(undefined8 **)(param_1[0x34] + 0x10) != (undefined8 *)0x0) {
        pbVar9 = (byte *)**(undefined8 **)(param_1[0x34] + 0x10);
        if (bVar5) {
          bVar13 = pbVar9[3];
        }
        else if (param_5 == '\0') {
          bVar13 = *pbVar9;
        }
        else if (param_5 == '\x01') {
          bVar13 = pbVar9[1];
        }
        else if (param_5 == '\x02') {
          bVar13 = pbVar9[2];
        }
        else if (param_5 == '\x03') {
          bVar13 = pbVar9[3];
        }
        else if (param_5 != '\x05') {
          bVar13 = 100;
          if (param_5 == '\x06') {
            bVar13 = 100;
          }
        }
      }
    }
    else {
      bVar13 = *(byte *)(*(longlong *)(param_1[0x37] + 0xfe0) + 0x10);
    }
  }
  uVar15 = 0;
  sVar14 = (short)((ulonglong)((uint)bVar13 * (param_4 & 0xffff)) / 100);
  if ((DAT_14033bd60 != '\0') && (param_1[0x37] != 0)) {
    sVar14 = 0;
  }
  if ((short)param_1[0x85] < 0) {
    if (param_6 == 0) goto LAB_140118275;
LAB_14011825f:
    *(undefined1 *)((longlong)param_1 + 0x23a) = *(undefined1 *)(param_6 + 0x234);
    uVar8 = *(undefined1 *)(param_6 + 0x235);
  }
  else {
    *(short *)(param_1 + 0x85) = (short)param_1[0x85] - sVar14;
    if (param_6 != 0) {
      if ((*(char *)(*(longlong *)param_1[0x34] + 0x71) != '\x03') &&
         ((*(uint *)(param_1 + 0x3e) & 0x10000) == 0)) {
        if (param_5 == '\0') {
          *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x800000;
        }
        else if (param_5 == '\x01') {
          *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x200000;
        }
        else if (param_5 == '\x02') {
          *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x2000000;
        }
      }
      goto LAB_14011825f;
    }
LAB_140118275:
    *(undefined1 *)((longlong)param_1 + 0x23a) = 0xff;
    uVar8 = 0xff;
  }
  *(undefined1 *)((longlong)param_1 + 0x23b) = uVar8;
  uVar17 = *(uint *)(param_1 + 0x3e);
  if (param_5 == '\0') {
    uVar17 = uVar17 | 0x200;
    *(uint *)(param_1 + 0x3e) = uVar17;
    if ((param_6 == 0) || (uVar20 = 100, cVar6 = FUN_140119e60(param_6), cVar6 == '\0'))
    goto LAB_1401182b2;
  }
  else {
LAB_1401182b2:
    uVar17 = uVar17 & 0xffdfffff;
    *(uint *)(param_1 + 0x3e) = uVar17;
  }
  if (param_3 != 0) {
    *(undefined1 *)((ulonglong)*(byte *)((longlong)param_1 + 0x235) + param_3) = 1;
    uVar17 = *(uint *)(param_1 + 0x3e);
  }
  uVar19 = (ulonglong)uVar17;
  if (((param_6 != 0) && (cVar6 = FUN_140119e60(param_6), cVar6 == '\x01')) &&
     ((&DAT_1402accc0)
      [(ulonglong)*(byte *)(*(longlong *)*param_2 + 0x15d) +
       (ulonglong)*(byte *)(**(longlong **)(param_6 + 0x388) + 0x15d) * 8] == (char)uVar15)) {
    *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x8000;
    uVar19 = (ulonglong)*(uint *)(param_1 + 0x3e);
  }
  if (param_5 == '\0') {
    *(uint *)((longlong)param_1 + 0x1fc) = *(uint *)((longlong)param_1 + 0x1fc) | 0x20000000;
  }
  else if (param_5 == '\x01') {
    *(uint *)((longlong)param_1 + 0x1fc) = *(uint *)((longlong)param_1 + 0x1fc) | 0x10000000;
  }
  else if (param_5 == '\x02') {
    *(uint *)((longlong)param_1 + 0x1fc) = *(uint *)((longlong)param_1 + 0x1fc) | 0x40000000;
  }
  if ((uVar19 & 2) == 0) {
    return;
  }
  if (param_1[0x7a] != 0) {
    *(undefined1 *)(param_1[0x7a] + 0x3f) = 0xff;
  }
  if ((short)uVar15 < (short)param_1[0x85]) {
    return;
  }
  cVar6 = FUN_140119e90(param_1);
  if (cVar6 == '\x01') {
    *(undefined2 *)(param_1 + 0x85) = uVar20;
    goto LAB_140118861;
  }
  if ((*(uint *)((longlong)param_1 + 500) >> 2 & 1) == 0) {
    lVar21 = *(longlong *)param_1[0x35];
    FUN_140189320();
    iVar16 = FUN_140242630();
    if (iVar16 % 100 + 1 <= (int)(uint)*(byte *)(lVar21 + 0x1c)) {
      if (((param_1[0x39] != 0) && (lVar21 = *(longlong *)(param_1[0x39] + 0x10), lVar21 != 0)) &&
         ((*(uint *)(lVar21 + 0x3a8) & 0x8000) != 0)) {
        FUN_1400a9c40(param_1[0x31]);
      }
      *(uint *)((longlong)param_1 + 500) = *(uint *)((longlong)param_1 + 500) | 0x1c;
      *(uint *)((longlong)param_1 + 0x204) = *(uint *)((longlong)param_1 + 0x204) | 1;
      local_68 = ZEXT816(0);
      local_58 = ZEXT816(0);
      *(undefined2 *)(param_1 + 0x85) = 1;
      *(undefined2 *)((longlong)param_1 + 0x236) = 0xffff;
      (**(code **)(*param_1 + 0x10))(param_1,local_68,local_58);
      auVar3 = vcmpss_avx(ZEXT816(0),ZEXT416((uint)local_68._0_4_),2);
      auVar3 = vblendvps_avx(ZEXT416(DAT_1402d2edc),ZEXT416(DAT_1402d2bd0),auVar3);
      auVar4 = vcmpss_avx(ZEXT816(0),ZEXT416((uint)local_68._8_4_),2);
      auVar4 = vblendvps_avx(ZEXT416(DAT_1402d2edc),ZEXT416(DAT_1402d2bd0),auVar4);
      local_2c = local_68._12_4_;
      local_48 = local_58._0_8_;
      uStack_40 = local_58._8_8_;
      local_34 = local_68._4_4_;
      local_38 = auVar3._0_4_;
      local_68._0_4_ = local_38;
      local_30 = auVar4._0_4_;
      local_68._8_4_ = local_30;
      local_68 = CONCAT412(local_2c,local_68._0_12_);
      (**(code **)(*param_1 + 8))(param_1,&local_38,&local_48);
      if (((*(undefined8 **)(param_1[0x34] + 8) != (undefined8 *)0x0) &&
          ((longlong *)param_1[0x74] != (longlong *)0x0)) &&
         (*(char *)**(undefined8 **)(param_1[0x34] + 8) == '\0')) {
        (**(code **)(*(longlong *)param_1[0x74] + 0x170))();
        if (param_1[0x6c] != 0) {
          pbVar9 = (byte *)(param_1[0x6c] + 0x49f);
          *pbVar9 = *pbVar9 | 0x10;
        }
      }
      if (param_6 != 0) {
        *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x40;
      }
      if (DAT_14033bd60 != '\0') {
        return;
      }
      if (param_6 != 0) {
        *(int *)(param_6 + 0x420) =
             *(int *)(param_6 + 0x420) + (int)*(short *)(*(longlong *)param_1[0x34] + 0x5c);
      }
      lVar21 = param_1[0x7a];
      if (lVar21 == 0) {
        return;
      }
      if (param_6 == 0) {
        return;
      }
      bVar13 = *(byte *)(param_6 + 0x234);
      lVar11 = *(longlong *)param_1[0x30];
      *(byte *)(lVar21 + 0x3d) = bVar13;
      *(undefined1 *)(lVar21 + 0x3e) = *(undefined1 *)(param_6 + 0x235);
      *(undefined1 *)(lVar21 + 0x3f) =
           *(undefined1 *)(*(longlong *)(lVar11 + (ulonglong)bVar13 * 8) + 0x15d);
      *(undefined1 *)(lVar21 + 0x2e) =
           *(undefined1 *)
            (*(longlong *)
              (*(longlong *)param_1[0x30] + (ulonglong)*(byte *)((longlong)param_1 + 0x234) * 8) +
            0x15d);
      return;
    }
    uVar15 = 0;
  }
  if ((((*(byte *)((longlong)param_1 + 0x24e) & 2) == 0) &&
      ((*(uint *)(param_1 + 0x3e) & 0x200000) != 0)) && (param_1[0x6c] != 0)) {
    *(char *)(param_1[0x30] + 0x36) = *(char *)(param_1[0x30] + 0x36) + '\x01';
  }
  plVar10 = (longlong *)param_1[0x30];
  if ((1 < *(byte *)((longlong)plVar10 + 0x37)) && (cVar6 = FUN_140119e60(param_1), cVar6 != '\0'))
  {
    if (*(char *)((longlong)param_1 + 0x234) == '\0') {
      lVar21 = ((longlong *)*plVar10)[1];
    }
    else {
      lVar21 = *(longlong *)*plVar10;
    }
    param_6 = *(longlong *)(lVar21 + 0x110);
  }
  if (param_6 == 0) goto LAB_140118861;
  lVar21 = *(longlong *)param_1[0x34];
  if (*(short *)(lVar21 + 0x5c) < 1) goto LAB_140118861;
  cVar6 = *(char *)(**(longlong **)(param_6 + 0x388) + 0x15d);
  if (((cVar6 == '\0') || (cVar6 == '\x02')) &&
     (((longlong *)param_1[0x34] != (longlong *)0x0 &&
      ((uVar2 = *(ushort *)(lVar21 + 0x86), -1 < (short)uVar2 &&
       (bVar13 = *(byte *)((longlong)plVar10 + 0x72), bVar13 < 0x1f)))))) {
    uVar15 = uVar15 & 0xffffffff;
    if (bVar13 != 0) {
      pbVar9 = (byte *)((longlong)plVar10 + 0x73);
      do {
        if (uVar2 == *pbVar9) goto LAB_1401186a0;
        uVar17 = (int)uVar15 + 1;
        uVar15 = (ulonglong)uVar17;
        pbVar9 = pbVar9 + 1;
      } while ((int)uVar17 < (int)(uint)bVar13);
    }
    *(char *)((ulonglong)*(byte *)((longlong)plVar10 + 0x72) + 0x73 + (longlong)plVar10) =
         (char)uVar2;
    *(char *)((longlong)plVar10 + 0x72) = *(char *)((longlong)plVar10 + 0x72) + '\x01';
  }
LAB_1401186a0:
  cVar6 = FUN_140119e60(param_6);
  if ((cVar6 == '\x01') && (lVar21 = *(longlong *)(param_6 + 0x1b8), lVar21 != 0)) {
    if (param_5 == '\0') {
      *(char *)(lVar21 + 0x272e) = *(char *)(lVar21 + 0x272e) + '\x01';
    }
    else if (param_5 == '\x01') {
      *(char *)(lVar21 + 0x272c) = *(char *)(lVar21 + 0x272c) + '\x01';
    }
    else {
      if (param_5 != '\x02') goto LAB_14011871c;
      *(char *)(lVar21 + 0x272d) = *(char *)(lVar21 + 0x272d) + '\x01';
    }
    iVar16 = FUN_140118b50(param_1);
    if (iVar16 == 0) {
LAB_1401186f6:
      iVar16 = FUN_140118b20(param_1);
      if ((iVar16 != 0) && (iVar16 = FUN_140118b20(), iVar16 != 1)) {
LAB_14011870c:
        *(short *)(lVar21 + 0x272a) = *(short *)(lVar21 + 0x272a) + 1;
        goto LAB_14011871c;
      }
    }
    else if (iVar16 != 1) {
      if (iVar16 != 2) goto LAB_1401186f6;
      goto LAB_14011870c;
    }
    *(short *)(lVar21 + 0x2728) = *(short *)(lVar21 + 0x2728) + 1;
  }
LAB_14011871c:
  cVar6 = FUN_140119e90(param_6);
  if ((cVar6 == '\x01') && (lVar21 = *(longlong *)(param_6 + 0x1c0), lVar21 != 0)) {
    iVar16 = FUN_140118b50(param_1);
    if (iVar16 == 0) {
LAB_14011874a:
      iVar16 = FUN_140118b20(param_1);
      if ((iVar16 != 0) && (iVar16 = FUN_140118b20(), iVar16 != 1)) {
LAB_140118760:
        *(short *)(lVar21 + 0x7a) = *(short *)(lVar21 + 0x7a) + 1;
        goto LAB_14011876a;
      }
    }
    else if (iVar16 != 1) {
      if (iVar16 != 2) goto LAB_14011874a;
      goto LAB_140118760;
    }
    *(short *)(lVar21 + 0x78) = *(short *)(lVar21 + 0x78) + 1;
  }
LAB_14011876a:
  if (param_5 == '\0') {
    *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x20000;
  }
  else if (param_5 == '\x01') {
    *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x10000;
  }
  else if (param_5 == '\x02') {
    *(uint *)(param_6 + 0x1fc) = *(uint *)(param_6 + 0x1fc) | 0x40000;
  }
  if (DAT_14033bd60 == '\0') {
    if ((((*(uint *)((longlong)param_1 + 500) >> 2 & 1) != 0) && (*(longlong *)param_1[0x35] != 0))
       && (*(longlong *)(param_6 + 0x1b8) != 0)) {
      piVar1 = (int *)(*(longlong *)(param_6 + 0x1b8) + 0x2784);
      *piVar1 = *piVar1 + (int)*(short *)(*(longlong *)param_1[0x35] + 0x18);
    }
    if (((*(uint *)(param_1 + 0x3e) & 0x2000) == 0) &&
       ((*(byte *)((longlong)param_1 + 0x24e) & 2) == 0)) {
      *(int *)(param_6 + 0x420) =
           *(int *)(param_6 + 0x420) + (int)*(short *)(*(longlong *)param_1[0x34] + 0x5c);
      lVar21 = param_1[0x7a];
      if (lVar21 != 0) {
        bVar13 = *(byte *)(param_6 + 0x234);
        lVar11 = *(longlong *)param_1[0x30];
        *(byte *)(lVar21 + 0x3d) = bVar13;
        *(undefined1 *)(lVar21 + 0x3e) = *(undefined1 *)(param_6 + 0x235);
        *(undefined1 *)(lVar21 + 0x3f) =
             *(undefined1 *)(*(longlong *)(lVar11 + (ulonglong)bVar13 * 8) + 0x15d);
        *(undefined1 *)(lVar21 + 0x2e) =
             *(undefined1 *)
              (*(longlong *)
                (*(longlong *)param_1[0x30] + (ulonglong)*(byte *)((longlong)param_1 + 0x234) * 8) +
              0x15d);
      }
    }
  }
LAB_140118861:
  if ((param_1[0x7a] != 0) && (DAT_14033bd60 == '\0')) {
    *(char *)(param_1[0x7a] + 0x40) = param_5;
    *(char *)(param_1[0x7a] + 0x41) = param_7;
  }
  FUN_140117a10(param_1,param_7);
  if (param_5 == '\x05') {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xfffffffe;
  }
  if (((param_1[0x6f] == 0) && (param_1[0x37] == 0)) && (param_1[0x73] == 0)) {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xfffffffe;
  }
  plVar10 = (longlong *)*param_2;
  if ((plVar10 != (longlong *)0x0) && (iVar16 = 0, 0 < *(int *)(*plVar10 + 0x118))) {
    lVar21 = 0;
    do {
      lVar11 = *(longlong *)(*plVar10 + 0x110) + lVar21;
      if (*(char *)(**(longlong **)(lVar11 + 0x1a8) + 0x1d) == *(char *)((longlong)param_1 + 0x235))
      {
        FUN_140118040(lVar11,param_2,param_3,1000,6,param_6,3);
      }
      plVar10 = (longlong *)*param_2;
      iVar16 = iVar16 + 1;
      lVar21 = lVar21 + 0x520;
    } while (iVar16 < *(int *)(*plVar10 + 0x118));
  }
  plVar10 = (longlong *)param_1[0x30];
  iVar16 = 0;
  if (*(char *)((longlong)plVar10 + 0x34) != '\0') {
    do {
      local_res18 = (longlong *)(*plVar10 + (longlong)iVar16 * 8);
      lVar21 = **(longlong **)(*local_res18 + 0x130);
      if ((*(char *)(lVar21 + 0x10) == *(char *)((longlong)param_1 + 0x234)) &&
         (*(char *)(lVar21 + 0x11) == *(char *)((longlong)param_1 + 0x235))) {
        puVar7 = operator_new((longlong)*(int *)(*local_res18 + 0x118));
        iVar18 = 0;
        lVar21 = *local_res18;
        if (0 < *(int *)(lVar21 + 0x118)) {
          puVar12 = puVar7;
          do {
            *puVar12 = 0;
            puVar12 = puVar12 + 1;
            iVar18 = iVar18 + 1;
            lVar21 = *local_res18;
          } while (iVar18 < *(int *)(lVar21 + 0x118));
        }
        iVar18 = 0;
        if (0 < *(int *)(lVar21 + 0x118)) {
          do {
            FUN_140118040((longlong)iVar18 * 0x520 + *(longlong *)(lVar21 + 0x110),&local_res18,
                          puVar7,1000,6,param_6,3);
            iVar18 = iVar18 + 1;
            lVar21 = *local_res18;
          } while (iVar18 < *(int *)(lVar21 + 0x118));
        }
        thunk_FUN_1402500f0(puVar7);
      }
      plVar10 = (longlong *)param_1[0x30];
      iVar16 = iVar16 + 1;
    } while (iVar16 < (int)(uint)*(byte *)((longlong)plVar10 + 0x34));
  }
  if (((param_1[0x39] != 0) && (lVar21 = *(longlong *)(param_1[0x39] + 0x10), lVar21 != 0)) &&
     ((*(uint *)(lVar21 + 0x3a8) & 0x8000) != 0)) {
    FUN_1400a9c40(param_1[0x31]);
  }
  return;
}

