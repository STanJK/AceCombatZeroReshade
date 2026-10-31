/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140167080; RVA 0x167080
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140167080(longlong *param_1,longlong *param_2)

{
  char cVar1;
  ulonglong uVar2;
  char cVar3;
  undefined4 uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  char cVar13;
  longlong *plVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  longlong unaff_GS_OFFSET;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  ulonglong uVar21;
  
  iVar9 = (int)param_1[2];
  if (iVar9 != 0) {
    if (iVar9 == 1) {
      if (((char)param_1[0x547] != '\0') && (0 < *(int *)((longlong)param_1 + 0x2a8c))) {
        *(int *)((longlong)param_1 + 0x2a8c) = *(int *)((longlong)param_1 + 0x2a8c) + -1;
      }
      if (param_1[5] != 0) {
        FUN_1401f8180();
      }
      FUN_14015b480(param_1 + 0x14);
      return;
    }
    if (iVar9 != 2) {
      return;
    }
    FUN_1401bff30(&PTR_PTR_14031df90);
    plVar14 = param_1 + 0x14;
    iVar9 = 0;
    if (0 < (char)param_1[0x4ed]) {
      plVar5 = param_1 + 0x4ee;
      do {
        if (((char)*plVar5 != '\0') && ((char)*plVar5 != '\x03')) {
          if (*(char *)((longlong)param_1 + 0x277e) == '\0') {
            iVar9 = FUN_14015ac40(plVar14);
            if (iVar9 == 0) {
              return;
            }
            *(undefined1 *)((longlong)param_1 + 0x277e) = 1;
            return;
          }
          cVar3 = *(char *)((longlong)param_1 + 0x2769);
          cVar13 = *(char *)((longlong)param_1 + 0x276a);
          if ((cVar13 != cVar3) &&
             (*(char *)((longlong)cVar3 + 0x26d0 + (longlong)plVar14) == '\x03')) {
            *(char *)((longlong)param_1 + 0x276a) = cVar3;
            cVar13 = cVar3;
          }
          cVar3 = *(char *)((longlong)param_1 + 0x276b);
          if (cVar3 == -1) goto LAB_1401672b3;
          cVar1 = *(char *)((longlong)cVar3 + 0x26d0 + (longlong)plVar14);
          if (cVar1 == '\x01') {
            if (cVar13 != cVar3) {
              *(undefined1 *)((longlong)param_1 + 0x277c) = 0;
            }
            if (('\0' < *(char *)((longlong)param_1 + 0x277c)) ||
               (cVar3 = FUN_140201760(), cVar3 == '\0')) goto LAB_14016758d;
            iVar9 = 0;
            if ((char)param_1[0x4ed] < '\x01') goto LAB_140167373;
            pcVar11 = (char *)((longlong)param_1 + 0x2774);
            goto LAB_140167340;
          }
          if (cVar1 != '\x02') {
            if (cVar1 == '\x03') goto LAB_1401672b3;
            goto LAB_1401675af;
          }
          plVar5 = (longlong *)FUN_1402014c0();
          if ((*(int *)((longlong)plVar5 + 0x7a4) != 0) && (*(int *)((longlong)plVar5 + 0x7a4) == 1)
             ) {
            plVar5 = plVar5 + 0x66;
          }
          cVar3 = (**(code **)(*plVar5 + 0x60))(plVar5,0);
          if (cVar3 == '\0') goto LAB_1401675af;
          if (DAT_14033bba0 < 0x101) {
            *(undefined1 *)
             ((longlong)*(char *)((longlong)param_1 + 0x276b) + 0x26d0 + (longlong)plVar14) = 0;
            goto LAB_1401672ac;
          }
          plVar5 = (longlong *)FUN_1402014c0();
          if ((*(int *)((longlong)plVar5 + 0x7a4) != 0) && (*(int *)((longlong)plVar5 + 0x7a4) == 1)
             ) {
            plVar5 = plVar5 + 0x66;
          }
          lVar6 = (**(code **)(*plVar5 + 0x68))(plVar5,0,0);
          cVar3 = *(char *)((longlong)param_1 + 0x276b);
          goto LAB_140167273;
        }
        iVar9 = iVar9 + 1;
        plVar5 = (longlong *)((longlong)plVar5 + 1);
      } while (iVar9 < (char)param_1[0x4ed]);
    }
    FUN_1401c56d0();
    plVar14 = &DAT_14033bc00;
    do {
      if (*(longlong *)(*plVar14 + 8) != 0) {
        FUN_140186bb0(*(longlong *)(*plVar14 + 8),0);
      }
      plVar14 = plVar14 + 1;
    } while ((longlong)plVar14 < 0x14033bc50);
    DAT_14031f8b0 = 0;
    if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
       (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
    FUN_1401cb090(&DAT_1437daf20);
    (**(code **)(*param_2 + 0x20))(param_2);
    return;
  }
  cVar3 = FUN_1401c0ef0(&PTR_PTR_14030f860);
  if (cVar3 == '\0') {
    if ((DAT_14031e078 == '\0') && (DAT_14031e07c == 0)) {
      return;
    }
    DAT_14031e07c = DAT_14031e07c + 1;
    return;
  }
  puVar8 = (undefined1 *)((longlong)param_1 + 0x276c);
  iVar9 = DAT_14030ffc4 + -0x16e;
  lVar7 = 4;
  lVar6 = 0;
  param_1[0x4e3] = 0;
  *(undefined1 *)((longlong)param_1 + 0x277e) = 0;
  *(undefined4 *)(param_1 + 0x4ec) = 0;
  do {
    puVar8[4] = 0;
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  *(undefined4 *)(param_1 + 0x4ed) = 0xffff0004;
  *(undefined2 *)((longlong)param_1 + 0x277c) = 0;
  *(undefined2 *)((longlong)param_1 + 0x277f) = 0;
  *(undefined4 *)(param_1 + 0x4df) = 0;
  *(undefined1 *)((longlong)param_1 + 0x26ff) = 4;
  uVar4 = (**(code **)(*param_1 + 0x30))(param_1);
  uVar18 = DAT_14032c8f8;
  *(undefined4 *)(param_1 + 0x14) = uVar4;
  lVar7 = FUN_140200de0(uVar18,0x880000,0x10);
  param_1[0x4e2] = lVar7;
  param_1[0x4e4] = lVar7 + 0x180000;
  param_1[0x4e5] = lVar7 + 0x380000;
  param_1[0x4e6] = lVar7 + 0x500000;
  param_1[0x4e7] = lVar7 + 0x700000;
  if ((int)param_1[0x4ec] == 0) {
    *(int *)((longlong)param_1 + 0x2764) = iVar9;
    *(undefined4 *)(param_1 + 0x4ec) = 1;
    *(char *)((longlong)param_1 + 0x2ac) = (char)iVar9;
  }
  *(undefined1 *)(param_1 + 0x4ed) = 2;
  *(undefined1 *)((longlong)param_1 + 0x26ff) = 2;
  *(undefined1 *)((longlong)param_1 + 0x2af) = 2;
  uVar18 = DAT_14030ff68;
  uVar21 = DAT_14030ff70;
  FUN_14015ae90(param_1 + 0x14,DAT_14030ff50,DAT_14030ff58,DAT_14030ff60,DAT_14030ff68,DAT_14030ff70
               );
  uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
  *(undefined1 *)((longlong)param_1 + 0x2769) = 0;
  plVar5 = param_1 + 0x4f2;
  *(undefined1 *)((longlong)param_1 + 0x277d) = 1;
  *(byte *)((longlong)param_1 + 0x276c) = *(byte *)((longlong)param_1 + 0x276c) | 1;
  uVar4 = (**(code **)(*param_1 + 0x30))(param_1);
  plVar14 = param_1 + 1;
  if (param_1 == (longlong *)0x0) {
    plVar14 = (longlong *)0x0;
  }
  FUN_1401bd460(plVar5,param_1 + 0x14,plVar14,&PTR_PTR_14030f868,CONCAT44(uVar20,2),
                uVar21 & 0xffffffffffffff00,uVar4);
  piVar17 = DAT_14030ffe8;
  iVar9 = *DAT_14030ffe8;
  DAT_14031dfc8 = plVar5;
  if (iVar9 < 3) {
    FUN_1401f6ac0(param_1 + 0xe,0);
    if (1 < iVar9) goto LAB_14016794d;
    FUN_1401eef00(param_1 + 7,0);
    if (iVar9 < 1) {
      lVar7 = 0;
      goto LAB_140167975;
    }
  }
  else {
    if (DAT_14030ffe8[3] == 0) {
      lVar7 = 0;
    }
    else {
      lVar7 = (longlong)DAT_14030ffe8 + (longlong)DAT_14030ffe8[3];
    }
    FUN_1401f6ac0(param_1 + 0xe,lVar7);
LAB_14016794d:
    if (piVar17[2] == 0) {
      lVar7 = 0;
    }
    else {
      lVar7 = (longlong)piVar17 + (longlong)piVar17[2];
    }
    FUN_1401eef00(param_1 + 7,lVar7);
  }
  lVar7 = 0;
  if (piVar17[1] != 0) {
    lVar7 = (longlong)piVar17 + (longlong)piVar17[1];
  }
LAB_140167975:
  if (param_1[5] == 0) {
    lVar7 = FUN_1401cbc80(param_1 + 4,lVar7);
    param_1[5] = lVar7;
    if (lVar7 != 0) {
      FUN_1401f7f30(lVar7);
    }
  }
  if ((4 < iVar9) && (piVar17[5] != 0)) {
    lVar6 = (longlong)piVar17 + (longlong)piVar17[5];
  }
  FUN_1401c5000(param_1 + 0x548,lVar6);
  FUN_1401be0d0(param_1 + 0x4f2,0);
  FUN_1401bfe40(&PTR_PTR_14031df90,0x2a);
  uVar4 = (**(code **)(*param_1 + 0x30))(param_1);
  FUN_1401eda90(&PTR_PTR_14031dfc0,uVar4);
  *(undefined4 *)(param_1 + 2) = 1;
  return;
LAB_140167369:
  iVar9 = iVar9 + 1;
  pcVar11 = pcVar11 + 1;
  if ((char)param_1[0x4ed] <= iVar9) goto LAB_140167373;
  goto LAB_140167340;
LAB_140167373:
  *(undefined1 *)((longlong)*(char *)((longlong)param_1 + 0x276b) + 0x26d0 + (longlong)plVar14) = 2;
  uVar10 = (uint)*(byte *)((longlong)*(char *)((longlong)param_1 + 0x276b) + 0x26d4 +
                          (longlong)plVar14);
  switch(*(undefined1 *)
          ((longlong)*(char *)((longlong)param_1 + 0x276b) + 0x26d8 + (longlong)plVar14)) {
  case 0:
    uVar10 = uVar10 + 0x172;
    break;
  case 1:
    uVar10 = uVar10 + 0x196;
    break;
  case 2:
    uVar10 = uVar10 + 0x1ba;
    break;
  case 3:
    uVar10 = uVar10 + 0x1de;
    break;
  case 4:
    uVar10 = uVar10 + 0x202;
    break;
  case 5:
    uVar10 = uVar10 + 0x226;
    break;
  case 6:
    uVar10 = uVar10 + 0x24a;
    break;
  case 7:
    uVar10 = uVar10 + 0x26e;
  }
  plVar14 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar14 + 0x7a4) != 0) && (*(int *)((longlong)plVar14 + 0x7a4) == 1)) {
    plVar14 = plVar14 + 0x66;
  }
  (**(code **)(*plVar14 + 0x38))(plVar14,uVar10);
  plVar14 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar14 + 0x7a4) != 0) && (*(int *)((longlong)plVar14 + 0x7a4) == 1)) {
    plVar14 = plVar14 + 0x66;
  }
  DAT_14033bba0 = (**(code **)(*plVar14 + 0x18))();
  param_1[(longlong)*(char *)((longlong)param_1 + 0x276b) + 0x4e8] =
       (longlong)(int)(DAT_14033bba0 + 0xf + (DAT_14033bba0 + 0xf >> 0x1f & 0xfU) & 0xfffffff0) +
       param_1[(longlong)*(char *)((longlong)param_1 + 0x276b) + 0x4e4];
  lVar6 = param_1[(longlong)*(char *)((longlong)param_1 + 0x276b) + 0x4e4];
  plVar14 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar14 + 0x7a4) != 0) && (*(int *)((longlong)plVar14 + 0x7a4) == 1)) {
    plVar14 = plVar14 + 0x66;
  }
  (**(code **)(*plVar14 + 0x48))(plVar14,lVar6);
LAB_14016758d:
  if ('\0' < *(char *)((longlong)param_1 + 0x277c)) {
    *(char *)((longlong)param_1 + 0x277c) = *(char *)((longlong)param_1 + 0x277c) + -1;
  }
  goto LAB_1401675af;
LAB_140167340:
  if (((pcVar11[-4] != '\x03') ||
      (lVar6 = (longlong)*(char *)((longlong)param_1 + 0x276b),
      *pcVar11 != *(char *)((longlong)param_1 + lVar6 + 0x2774))) ||
     (pcVar11[4] != *(char *)((longlong)param_1 + lVar6 + 0x2778))) goto LAB_140167369;
  uVar21 = param_1[lVar6 + 0x4e4];
  iVar15 = 0;
  uVar16 = (int)param_1[(longlong)iVar9 + 0x4e8] - (int)param_1[(longlong)iVar9 + 0x4e4];
  uVar2 = param_1[(longlong)iVar9 + 0x4e4];
  uVar10 = (int)(uVar16 + ((int)uVar16 >> 0x1f & 7U)) >> 3;
  lVar6 = (longlong)(int)uVar10;
  if (((0 < (int)uVar10) && (3 < uVar10)) &&
     ((uVar2 + (longlong)(int)(uVar10 - 1) * 8 < uVar21 ||
      (uVar21 + (longlong)(int)(uVar10 - 1) * 8 < uVar2)))) {
    FUN_140277ba0(uVar21,uVar2,lVar6 * 8);
    do {
      iVar15 = iVar15 + 1;
    } while (iVar15 < (int)uVar10);
  }
  lVar7 = (longlong)iVar15;
  if (lVar7 < lVar6) {
    puVar12 = (undefined8 *)(uVar21 + lVar7 * 8);
    lVar6 = lVar6 - lVar7;
    do {
      *puVar12 = *(undefined8 *)((uVar2 - uVar21) + (longlong)puVar12);
      puVar12 = puVar12 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  piVar17 = (int *)param_1[(longlong)*(char *)((longlong)param_1 + 0x276b) + 0x4e4];
  iVar9 = *piVar17;
  param_1[(longlong)*(char *)((longlong)param_1 + 0x276b) + 0x4e8] =
       (ulonglong)uVar16 + (longlong)piVar17;
  lVar6 = 0;
  if ((0 < iVar9) && (piVar17[1] != 0)) {
    lVar6 = (longlong)piVar17 + (longlong)piVar17[1];
  }
  cVar3 = *(char *)((longlong)param_1 + 0x276b);
LAB_140167273:
  FUN_140161170(plVar14 + (longlong)cVar3 * 0xf1 + 0x107,lVar6);
  FUN_140161580(plVar14 + (longlong)*(char *)((longlong)param_1 + 0x276b) * 0xf1 + 0x107,
                param_1[(longlong)*(char *)((longlong)param_1 + 0x276b) + 0x4e8]);
  *(undefined1 *)((longlong)*(char *)((longlong)param_1 + 0x276b) + 0x26d0 + (longlong)plVar14) = 3;
LAB_1401672ac:
  *(undefined1 *)((longlong)param_1 + 0x276b) = 0xff;
LAB_1401672b3:
  uVar10 = (int)(char)param_1[0x4ed] - 1;
  if (-1 < (int)uVar10) {
    while (*(char *)((ulonglong)uVar10 + 0x26d0 + (longlong)plVar14) != '\x01') {
      uVar10 = uVar10 - 1;
      if ((int)uVar10 < 0) goto LAB_1401675af;
    }
    *(char *)((longlong)param_1 + 0x276b) = (char)uVar10;
    *(undefined1 *)((longlong)param_1 + 0x277c) = 10;
  }
LAB_1401675af:
  if ((*(byte *)((longlong)param_1 + 0x277f) & 1) != 0) {
    iVar9 = 0;
    if ('\0' < (char)param_1[0x4ed]) {
      plVar14 = param_1 + 0x4ee;
      do {
        if ((char)*plVar14 != '\x03') goto LAB_1401675e4;
        iVar9 = iVar9 + 1;
        plVar14 = (longlong *)((longlong)plVar14 + 1);
      } while (iVar9 < (char)param_1[0x4ed]);
    }
    *(undefined1 *)((longlong)param_1 + 0x277e) = 3;
  }
LAB_1401675e4:
  if (*(char *)((longlong)param_1 + 0x277d) == '\x01') {
    if (*(char *)((longlong)param_1 + 0x277e) != '\0') {
      if (*(byte *)(param_1 + 0x4f0) < 0x80) {
        *(byte *)(param_1 + 0x4f0) = *(byte *)(param_1 + 0x4f0) + 2;
      }
      else {
        *(undefined1 *)(param_1 + 0x4f0) = 0x80;
        *(undefined1 *)((longlong)param_1 + 0x277d) = 2;
      }
    }
  }
  else if (*(char *)((longlong)param_1 + 0x277d) == '\x03') {
    if ((char)param_1[0x4f0] == '\0') {
      *(undefined1 *)((longlong)param_1 + 0x277d) = 0;
    }
    else {
      *(char *)(param_1 + 0x4f0) = (char)param_1[0x4f0] + -2;
    }
  }
  iVar9 = 0;
  if ('\0' < (char)param_1[0x4ed]) {
    plVar14 = param_1 + 0x4e0;
    piVar17 = (int *)((longlong)param_1 + 0x1034);
    uVar18 = _DAT_1402d3500;
    uVar19 = _UNK_1402d3508;
    do {
      if ((*piVar17 == 2) && ((int)*plVar14 != 0)) {
        lVar6 = **(longlong **)(unaff_GS_OFFSET + 0x58);
        if ((*(int *)(lVar6 + 4) < DAT_1437dad18) &&
           (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
          _DAT_1437daef0 = 0;
          DAT_1437daef4 = 0;
          _DAT_1437daee0 = uVar18;
          uRam00000001437daee8 = uVar19;
          _Init_thread_footer(&DAT_1437dad18);
        }
        if ((*(int *)(lVar6 + 4) < DAT_1437daf04) &&
           (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
          FUN_1401c93c0();
          _Init_thread_footer(&DAT_1437daf04);
        }
        FUN_1401cb010(&DAT_1437daf20,(longlong)param_1 + (longlong)iVar9 * 4 + 0x2700);
        *(int *)plVar14 = 0;
      }
      iVar9 = iVar9 + 1;
      plVar14 = (longlong *)((longlong)plVar14 + 4);
      piVar17 = piVar17 + 0x1e2;
    } while (iVar9 < (char)param_1[0x4ed]);
  }
  return;
}

