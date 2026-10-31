/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401228b0; RVA 0x1228b0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401228b0(longlong param_1)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  bool bVar7;
  bool bVar8;
  int iVar9;
  longlong lVar10;
  char cVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined1 auVar16 [64];
  undefined1 auVar17 [64];
  undefined1 auVar18 [64];
  float fVar19;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  
  FUN_140120f80();
  if (*(char *)(param_1 + 0x508) == '\x01') {
    *(undefined4 *)(param_1 + 0x4d8) = *(undefined4 *)(param_1 + 0x4a8);
    *(undefined4 *)(param_1 + 0x4dc) = *(undefined4 *)(param_1 + 0x4ac);
    *(undefined4 *)(param_1 + 0x4e0) = *(undefined4 *)(param_1 + 0x4b0);
    *(undefined4 *)(param_1 + 0x4e4) = *(undefined4 *)(param_1 + 0x4b4);
    cVar11 = *(char *)(param_1 + 0x508);
  }
  else {
    *(undefined1 *)(param_1 + 0x508) = 1;
    cVar11 = '\x01';
    *(undefined1 *)(param_1 + 0x247) = 0;
  }
  bVar8 = false;
  bVar7 = false;
  fVar19 = 0.0;
  if ((*(byte *)(param_1 + 0x61c) & 2) == 0) {
    fVar13 = DAT_1402d2998;
    fVar19 = 0.0;
    bVar7 = bVar8;
    if ((*(longlong *)(param_1 + 400) != 0) && (0.0 < *(float *)(param_1 + 0x1ec))) {
      fVar15 = *(float *)(param_1 + 0x3dc);
      fVar12 = (float)*(byte *)(param_1 + 0x24a) * DAT_1402d2504;
      fVar14 = fVar12 * *(float *)(param_1 + 0x3fc) + fVar15;
      fVar19 = 0.0;
      fVar12 = (float)FUN_140079410(*(longlong *)(param_1 + 400),
                                    fVar12 * *(float *)(param_1 + 0x3f8) +
                                    *(float *)(param_1 + 0x3d8),
                                    fVar12 * *(float *)(param_1 + 0x400) +
                                    *(float *)(param_1 + 0x3e0));
      if (fVar14 < fVar12) {
        *(float *)(param_1 + 0x618) = fVar15 + fVar13;
        bVar7 = true;
      }
    }
    if (*(float *)(param_1 + 0x3dc) < *(float *)(param_1 + 0x1ec)) {
      *(float *)(param_1 + 0x618) = *(float *)(param_1 + 0x1ec) + fVar13;
      bVar7 = true;
    }
  }
  if ((cVar11 != '\x02') && (bVar7)) {
    *(undefined1 *)(param_1 + 0x508) = 2;
    cVar11 = '\x02';
    *(undefined1 *)(param_1 + 0x247) = 0;
  }
  if (cVar11 != '\x03') {
    if (*(float *)(param_1 + 0x1e8) < *(float *)(param_1 + 0x3dc)) {
      *(undefined1 *)(param_1 + 0x508) = 3;
      *(undefined1 *)(param_1 + 0x247) = 0;
    }
    else if (cVar11 != '\x02') goto LAB_140122a93;
  }
  *(undefined4 *)(param_1 + 0x4d8) = *(undefined4 *)(param_1 + 0x3d8);
  *(undefined4 *)(param_1 + 0x4dc) = *(undefined4 *)(param_1 + 0x3dc);
  *(undefined4 *)(param_1 + 0x4e0) = *(undefined4 *)(param_1 + 0x3e0);
  *(undefined4 *)(param_1 + 0x4e4) = *(undefined4 *)(param_1 + 0x3e4);
LAB_140122a93:
  if ((((*(byte *)(param_1 + 0x234) != 0xff) && (*(byte *)(param_1 + 0x235) != 0xff)) &&
      (lVar10 = *(longlong *)
                 (*(longlong *)
                   (**(longlong **)(param_1 + 0x180) + (ulonglong)*(byte *)(param_1 + 0x234) * 8) +
                 0x110) + (ulonglong)*(byte *)(param_1 + 0x235) * 0x520, lVar10 != 0)) &&
     ((((byte)*(undefined4 *)(lVar10 + 500) & 0xd) == 1 &&
      (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x1c8) + 0x10), lVar2 != 0)))) {
    if ((((*(longlong **)(lVar10 + 0x1a0) != (longlong *)0x0) &&
         ((lVar3 = **(longlong **)(lVar10 + 0x1a0), lVar3 != 0 &&
          ((*(byte *)(param_1 + 0x61c) & 4) == 0)))) &&
        ((cVar11 = *(char *)(lVar3 + 0x6f), cVar11 == '\0' || (cVar11 == '\x01')))) &&
       ((((*(float *)(lVar10 + 600) < *(float *)(lVar2 + 0x348) - DAT_1402d2b8c ||
          (DAT_1402d2b8c + *(float *)(lVar2 + 0x350) < *(float *)(lVar10 + 600))) ||
         (*(float *)(lVar10 + 0x260) < *(float *)(lVar2 + 0x34c) - DAT_1402d2b8c)) ||
        (DAT_1402d2b8c + *(float *)(lVar2 + 0x354) < *(float *)(lVar10 + 0x260))))) {
      auVar1 = *(undefined1 (*) [16])(lVar10 + 600);
      auVar16 = ZEXT1664(auVar1);
      fVar15 = auVar1._0_4_;
      auVar4 = vshufps_avx(auVar1,auVar1,0x55);
      auVar17 = ZEXT1664(auVar4);
      fVar12 = auVar4._0_4_;
      auVar1 = vshufps_avx(auVar1,auVar1,0xaa);
      auVar18 = ZEXT1664(auVar1);
      fVar14 = auVar1._0_4_;
      fVar13 = SQRT(fVar14 * fVar14 + fVar12 * fVar12 + fVar15 * fVar15);
      if (fVar13 != fVar19) {
        fVar13 = DAT_1402d22d0 / fVar13;
        auVar16 = ZEXT464((uint)(fVar15 * fVar13));
        auVar17 = ZEXT464((uint)(fVar12 * fVar13));
        auVar18 = ZEXT464((uint)(fVar14 * fVar13));
      }
      local_98 = 0;
      uStack_90 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_68 = 0;
      uStack_60 = 0;
      fVar19 = DAT_1402d22d0;
      FUN_140202920(&local_98,lVar10 + 0x268);
      if (DAT_1402d1f20 <
          auVar18._0_4_ * (float)uStack_70 * DAT_1402d2d64 -
          (auVar17._0_4_ * fVar19 * local_78._4_4_ + fVar19 * (float)local_78 * auVar16._0_4_)) {
        *(byte *)(param_1 + 0x61c) = *(byte *)(param_1 + 0x61c) | 4;
      }
    }
    if ((*(byte *)(param_1 + 0x61c) & 4) != 0) {
      if (((*(float *)(lVar10 + 600) <= DAT_1402d2a78 + *(float *)(lVar2 + 0x348)) ||
          (*(float *)(lVar2 + 0x350) - DAT_1402d2a78 <= *(float *)(lVar10 + 600))) ||
         ((*(float *)(lVar10 + 0x260) <= DAT_1402d2a78 + *(float *)(lVar2 + 0x34c) ||
          (*(float *)(lVar2 + 0x354) - DAT_1402d2a78 <= *(float *)(lVar10 + 0x260))))) {
        *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xffffffbf;
        *(undefined1 *)(param_1 + 0x508) = 1;
        *(undefined4 *)(param_1 + 0x4d8) = 0;
        *(undefined4 *)(param_1 + 0x4dc) = *(undefined4 *)(param_1 + 0x1e8);
        *(undefined8 *)(param_1 + 0x4e0) = 0;
        *(undefined4 *)(param_1 + 0x484) = 0x40000000;
      }
      else {
        *(byte *)(param_1 + 0x61c) = *(byte *)(param_1 + 0x61c) & 0xfb;
      }
    }
  }
  if ((*(uint *)(param_1 + 0x1f0) & 2) == 0) {
    *(undefined2 *)(param_1 + 0x54c) = 2;
  }
  else if ((*(uint *)(param_1 + 0x1f0) & 0x40) == 0) {
    cVar11 = *(char *)(param_1 + 0x508);
    if (cVar11 == '\x01') {
      auVar1 = *(undefined1 (*) [16])(param_1 + 0x4d8);
      auVar4 = vshufps_avx(auVar1,auVar1,0x55);
      auVar5 = vshufps_avx(auVar1,auVar1,0xaa);
      auVar6 = vshufps_avx(auVar1,auVar1,0xff);
      *(float *)(param_1 + 0x528) = auVar1._0_4_ - *(float *)(param_1 + 0x518);
      *(float *)(param_1 + 0x52c) = auVar4._0_4_ - *(float *)(param_1 + 0x51c);
      *(float *)(param_1 + 0x530) = auVar5._0_4_ - *(float *)(param_1 + 0x520);
      *(float *)(param_1 + 0x534) = auVar6._0_4_ - *(float *)(param_1 + 0x524);
      *(undefined4 *)(param_1 + 0x518) = *(undefined4 *)(param_1 + 0x4d8);
      *(undefined4 *)(param_1 + 0x51c) = *(undefined4 *)(param_1 + 0x4dc);
      *(undefined4 *)(param_1 + 0x520) = *(undefined4 *)(param_1 + 0x4e0);
      *(undefined4 *)(param_1 + 0x524) = *(undefined4 *)(param_1 + 0x4e4);
      *(undefined2 *)(param_1 + 0x54c) = 1;
    }
    else if (cVar11 == '\x02') {
      if (*(char *)(param_1 + 0x54c) != '\x03') {
        *(undefined2 *)(param_1 + 0x54c) = 3;
      }
    }
    else if ((cVar11 == '\x03') && (*(char *)(param_1 + 0x54c) != '\x04')) {
      *(undefined2 *)(param_1 + 0x54c) = 4;
    }
  }
  else if ((*(char *)(param_1 + 0x54c) != '\x03') && (1 < (byte)(*(char *)(param_1 + 0x54c) - 4U)))
  {
    *(undefined2 *)(param_1 + 0x54c) = 5;
    *(undefined2 *)(param_1 + 0x220) = 0;
  }
  iVar9 = FUN_140122e80(param_1);
  if (iVar9 == 1) {
    *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xffffffbf;
    *(undefined2 *)(param_1 + 0x54c) = 0;
  }
  return;
}

