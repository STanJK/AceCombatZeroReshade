/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d03a0; RVA 0xd03a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1400d03a0(longlong param_1)

{
  undefined1 auVar1 [32];
  undefined1 uVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 auVar5 [16];
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined1 auVar15 [16];
  float fVar16;
  undefined1 auVar17 [16];
  undefined4 uVar18;
  undefined4 uVar19;
  undefined1 auVar20 [64];
  float fVar21;
  undefined1 auVar22 [64];
  float fVar23;
  float fVar24;
  
  uVar12 = 0;
  lVar9 = *(longlong *)(param_1 + 0xa8248);
  if ((*(uint *)(param_1 + 0xa87c0) == 0) || ((*(uint *)(param_1 + 0xa87c0) & 1) == 0)) {
    FUN_140189320();
  }
  lVar7 = FUN_140189320();
  auVar15 = vpcmpeqd_avx(ZEXT416((uint)*(byte *)(lVar7 + 0x28)),SUB6416(ZEXT464(0),0));
  auVar15 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar15);
  auVar22 = ZEXT1664(auVar15);
  uVar19 = auVar15._0_4_;
  auVar15 = vpcmpeqd_avx(ZEXT416((uint)*(byte *)(lVar7 + 0x28)),SUB6416(ZEXT464(0),0));
  auVar15 = vblendvps_avx(ZEXT416(DAT_1402d2928),ZEXT416(DAT_1402d293c),auVar15);
  auVar20 = ZEXT1664(auVar15);
  if (*(char *)(param_1 + 0xa87d8) == '\0') {
    *(uint *)(lVar9 + 0x2058) = *(uint *)(lVar9 + 0x2058) | 0x10;
    FUN_1400c5070(lVar9,1);
    uVar19 = auVar22._0_4_;
    *(undefined2 *)(*(longlong *)(*(longlong *)(lVar9 + 0x1fc0) + 0x66ee0) + 0x336d4) = 1;
  }
  else {
    if (*(char *)(param_1 + 0xa87d9) != '\0') {
      *(char *)(param_1 + 0xa87d9) = '\0';
      *(uint *)(lVar9 + 0x2058) = *(uint *)(lVar9 + 0x2058) & 0xffffffef;
      FUN_1400c5070(lVar9,2);
      uVar19 = auVar22._0_4_;
    }
    *(undefined2 *)(*(longlong *)(*(longlong *)(lVar9 + 0x1fc0) + 0x66ee0) + 0x336d4) = 2;
  }
  *(undefined4 *)(lVar9 + 0x1640) = 0;
  *(byte *)(lVar9 + 0x1863) = *(byte *)(lVar9 + 0x1863) | 1;
  *(undefined4 *)(lVar9 + 0x185c) = 0;
  *(undefined8 *)(lVar9 + 0x1d78) = 0;
  *(byte *)(lVar9 + 0x1da7) = *(byte *)(lVar9 + 0x1da7) | 1;
  *(uint *)(lVar9 + 0x2058) = *(uint *)(lVar9 + 0x2058) | 0x20;
  uVar18 = auVar20._0_4_;
  *(undefined4 *)(lVar9 + 0x1d64) = uVar18;
  *(undefined4 *)(lVar9 + 0x1d68) = uVar19;
  *(undefined4 *)(lVar9 + 0x1d6c) = uVar18;
  *(undefined4 *)(lVar9 + 0x1bd0) = uVar18;
  *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xfffffffb;
  FUN_140080620((longlong)*(char *)(param_1 + 0xa8829) * 0xd10 + *(longlong *)(param_1 + 0x67138));
  FUN_14007b080((longlong)*(char *)(param_1 + 0xa8829) * 0x1c8 + *(longlong *)(param_1 + 0x67140));
  *(uint *)(lVar9 + 0x2058) = *(uint *)(lVar9 + 0x2058) & 0xfffffffd;
  *(ushort *)(lVar9 + 0x1c20) = *(ushort *)(lVar9 + 0x1c20) & 0xffbf;
  lVar7 = FUN_140189320();
  if (*(char *)(lVar7 + 0x32) != '\0') {
    FUN_1400781c0(param_1 + 0x69598 + (longlong)*(char *)(param_1 + 0xa8829) * 0x18,
                  param_1 + 0x68f72,param_1 + 0x240);
  }
  FUN_140036fe0(*(undefined8 *)(param_1 + 0x67120));
  FUN_140136540(param_1 + 0x697b8,param_1 + 0xa87a0,*(undefined1 *)(param_1 + 0xa87e0));
  if (*(char *)(param_1 + 0xa87d8) == '\0') {
    lVar7 = param_1 + 0x69850;
    if (*(int *)(param_1 + 0xa87d0) == 0) {
      DAT_1437da3b0 = *(float *)(param_1 + 0x69880);
      DAT_1437da3b4 = *(float *)(param_1 + 0x69884);
      DAT_1437da3b8 = *(float *)(param_1 + 0x69888);
      _DAT_1437da3bc = *(undefined4 *)(param_1 + 0x6988c);
      _DAT_1437da3a0 = *(float *)(param_1 + 0x69890);
      auVar20 = ZEXT464((uint)_DAT_1437da3a0);
      fVar23 = *(float *)(param_1 + 0x69894);
      uVar19 = *(undefined4 *)(param_1 + 0x69898);
      _DAT_1437da3ac = *(undefined4 *)(param_1 + 0x6989c);
      _DAT_1437da3a4 = fVar23;
      _DAT_1437da3a8 = uVar19;
      uVar13 = FUN_140187ec0(_DAT_1437da3ac,0,0x1b);
      uVar14 = FUN_140187ec0(uVar13,0,0x19);
      fVar23 = ((float)uVar14 - (float)uVar13) * DAT_1402d1ff8 + fVar23;
      _DAT_1437da3a4 = fVar23;
      uVar13 = FUN_140187ec0(uVar14,0,0x1d);
      uVar14 = FUN_140187ec0(uVar13,0,0x1f);
      fVar16 = ((float)uVar14 - (float)uVar13) * DAT_1402d1ff8 + auVar20._0_4_;
      _DAT_1437da3a0 = fVar16;
      *(undefined4 *)(param_1 + 0x6989c) = 0;
      *(float *)(param_1 + 0x69890) = fVar16;
      *(float *)(param_1 + 0x69894) = fVar23;
      *(undefined4 *)(param_1 + 0x69898) = uVar19;
      uVar13 = FUN_140187ec0(uVar14,0,0x16);
      fVar23 = (float)FUN_140187ec0(uVar13,0,0x15);
      fVar23 = (fVar23 - (float)uVar13) * DAT_1402d2508;
      uVar19 = 0;
      fVar16 = 0.0;
      if ((char)DAT_14032c8c0[0x10] == -1) {
        fVar21 = 0.0;
      }
      else {
        lVar9 = *DAT_14032c8c0;
        lVar11 = (longlong)*(char *)(lVar9 + 0x2e) * 0x1b;
        fVar21 = (float)*(byte *)((ulonglong)*(byte *)(lVar11 + 0x1a + (longlong)DAT_14032c8c0) +
                                 lVar9) * DAT_1402d1f94;
        fVar16 = (float)*(byte *)((ulonglong)*(byte *)(lVar11 + 0x1b + (longlong)DAT_14032c8c0) +
                                 lVar9) * DAT_1402d1f94;
      }
      fVar21 = fVar21 - fVar16;
      fVar24 = DAT_1402d2508;
      uVar13 = FUN_140187ec0(fVar16,0,0x13);
      fVar16 = (float)FUN_140187ec0(uVar13,0,0x14);
      fVar24 = (fVar16 - (float)uVar13) * fVar24;
      auVar1 = *(undefined1 (*) [32])(param_1 + 0x698a0);
      auVar17 = auVar1._0_16_;
      auVar15 = vshufps_avx(auVar17,auVar17,0x55);
      auVar5 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar17 = vshufps_avx(auVar17,auVar17,0xff);
      DAT_1437da3b0 =
           auVar5._0_4_ * fVar24 + fVar23 * auVar1._0_4_ + auVar15._0_4_ * fVar21 + auVar17._0_4_ +
           DAT_1437da3b0;
      auVar17 = auVar1._16_16_;
      auVar15 = vshufps_avx(auVar17,auVar17,0x55);
      auVar5 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar17 = vshufps_avx(auVar17,auVar17,0xff);
      fVar16 = fVar24 * auVar5._0_4_ + auVar1._16_4_ * fVar23 + auVar15._0_4_ * fVar21 +
               auVar17._0_4_ + DAT_1437da3b4;
      auVar17 = SUB3216(*(undefined1 (*) [32])(param_1 + 0x698c0),0);
      auVar15 = vshufps_avx(auVar17,auVar17,0x55);
      auVar5 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar17 = vshufps_avx(auVar17,auVar17,0xff);
      fVar23 = fVar24 * auVar5._0_4_ +
               fVar21 * auVar15._0_4_ + SUB324(*(undefined1 (*) [32])(param_1 + 0x698c0),0) * fVar23
               + auVar17._0_4_ + DAT_1437da3b8;
      DAT_1437da3b4 = fVar16;
      DAT_1437da3b8 = fVar23;
      _DAT_1437da3c8 = uVar19;
      _DAT_1437da3cc = uVar19;
      _DAT_1437da3d0 = uVar19;
      *(float *)(param_1 + 0x69880) = DAT_1437da3b0;
      *(float *)(param_1 + 0x69884) = fVar16;
      *(float *)(param_1 + 0x69888) = fVar23;
      *(undefined4 *)(param_1 + 0x6988c) = 0x3f800000;
    }
    else {
      FUN_140014960(lVar7,*(undefined8 *)(param_1 + 0xa8240));
      *(undefined4 *)(param_1 + 0x6985c) = 0x40a00000;
      lVar11 = *(longlong *)(param_1 + 0xa87c8);
      if (lVar11 != 0) {
        lVar10 = *(longlong *)(*(longlong *)(lVar11 + 0x3c8) + 0x48);
        if ((lVar10 != 0) && (lVar10 = lVar10 + 0x90, lVar8 = lVar10, lVar10 != 0)) {
          do {
            iVar6 = strcmp("#cam_lens##",(char *)(lVar8 + 0x9c));
            if (iVar6 == 0) {
              fVar23 = *(float *)(lVar8 + 0x90);
              lVar8 = FUN_140189320();
              if (*(char *)(lVar8 + 0x28) != '\0') {
                fVar23 = fVar23 * DAT_1402d2254;
              }
              *(float *)(param_1 + 0x69858) = fVar23;
              uVar19 = auVar20._0_4_;
              *(undefined4 *)(lVar9 + 0x1d64) = uVar19;
              *(float *)(lVar9 + 0x1d68) = fVar23;
              *(undefined4 *)(lVar9 + 0x1d6c) = uVar19;
              *(undefined4 *)(lVar9 + 0x1bd0) = uVar19;
              break;
            }
            lVar8 = *(longlong *)(lVar8 + 0xf0);
          } while (lVar8 != 0);
          do {
            iVar6 = strcmp("#dtl_x#dtl_y#dtl_z",(char *)(lVar10 + 0x9c));
            if (iVar6 == 0) {
              fVar23 = *(float *)(lVar10 + 0x98);
              fVar16 = *(float *)(lVar10 + 0x94);
              *(float *)(lVar11 + 600) = fVar23 + *(float *)(lVar11 + 600);
              *(float *)(lVar11 + 0x260) = fVar23 + *(float *)(lVar11 + 0x260);
              *(float *)(lVar11 + 0x25c) = fVar16 + *(float *)(lVar11 + 0x25c);
              break;
            }
            lVar10 = *(longlong *)(lVar10 + 0xf0);
          } while (lVar10 != 0);
        }
        uVar19 = *(undefined4 *)(lVar11 + 0x260);
        uVar18 = *(undefined4 *)(lVar11 + 600);
        *(undefined4 *)(param_1 + 0x69884) = *(undefined4 *)(lVar11 + 0x25c);
        *(undefined4 *)(param_1 + 0x69888) = uVar19;
        *(undefined4 *)(param_1 + 0x69880) = uVar18;
        *(undefined4 *)(param_1 + 0x6988c) = 0x3f800000;
        uVar19 = *(undefined4 *)(lVar11 + 0x270);
        uVar18 = *(undefined4 *)(lVar11 + 0x268);
        *(undefined4 *)(param_1 + 0x69894) = *(undefined4 *)(lVar11 + 0x26c);
        *(undefined4 *)(param_1 + 0x69898) = uVar19;
        *(undefined4 *)(param_1 + 0x69890) = uVar18;
        *(undefined4 *)(param_1 + 0x6989c) = 0;
      }
    }
    FUN_1401fbec0(lVar7);
    if (*(int *)(param_1 + 0x67230) < 4) {
      *(longlong *)(param_1 + 0x671f0 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar7;
      *(longlong *)(param_1 + 0x67210 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar7;
      *(undefined4 *)(param_1 + 0x67234 + (longlong)*(int *)(param_1 + 0x67230) * 4) = 0;
      *(int *)(param_1 + 0x67230) = *(int *)(param_1 + 0x67230) + 1;
    }
  }
  else {
    if (*(char *)(param_1 + 0xa87d9) != '\0') {
      *(uint *)(lVar9 + 0x2058) = *(uint *)(lVar9 + 0x2058) & 0xffffffef;
      FUN_1400c5070(lVar9,2);
    }
    uVar2 = *(undefined1 *)(lVar9 + 0x1862);
    *(undefined1 *)(lVar9 + 0x1862) = 3;
    FUN_140106f30(lVar9);
    *(undefined1 *)(lVar9 + 0x1862) = uVar2;
    lVar7 = lVar9 + 0x10b0;
    FUN_1401fbec0(lVar7);
    lVar11 = lVar9 + 0x1270;
    FUN_1401fbec0(lVar11);
    FUN_1401fbec0(lVar7);
    FUN_1401fbec0(lVar11);
    if (*(int *)(param_1 + 0x67230) < 4) {
      *(longlong *)(param_1 + 0x671f0 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar7;
      *(longlong *)(param_1 + 0x67210 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar11;
      *(undefined4 *)(param_1 + 0x67234 + (longlong)*(int *)(param_1 + 0x67230) * 4) = 0;
      *(int *)(param_1 + 0x67230) = *(int *)(param_1 + 0x67230) + 1;
    }
    auVar15 = *(undefined1 (*) [16])(lVar9 + 0x10e0);
    *(int *)(param_1 + 0x69880) = auVar15._0_4_;
    uVar19 = vextractps_avx(auVar15,1);
    *(undefined4 *)(param_1 + 0x69884) = uVar19;
    uVar19 = vextractps_avx(auVar15,2);
    *(undefined4 *)(param_1 + 0x69888) = uVar19;
    uVar19 = vextractps_avx(auVar15,3);
    *(undefined4 *)(param_1 + 0x6988c) = uVar19;
    auVar15 = *(undefined1 (*) [16])(lVar9 + 0x10f0);
    *(int *)(param_1 + 0x69890) = auVar15._0_4_;
    uVar19 = vextractps_avx(auVar15,1);
    *(undefined4 *)(param_1 + 0x69894) = uVar19;
    uVar19 = vextractps_avx(auVar15,2);
    *(undefined4 *)(param_1 + 0x69898) = uVar19;
    uVar19 = vextractps_avx(auVar15,3);
    *(undefined4 *)(param_1 + 0x6989c) = uVar19;
    *(int *)(param_1 + 0x69858) = auVar20._0_4_;
    FUN_1401fbec0();
  }
  if (((*(int *)(param_1 + 0xa87d0) < 1) && (*(int *)(param_1 + 0xa87c0) != 0)) ||
     (*(char *)(param_1 + 0xa87db) != '\0')) {
    *(undefined1 *)(param_1 + 0xa87da) = 0;
    uVar12 = 1;
  }
  if (*(char *)(param_1 + 0xa87da) == '\0') {
    *(int *)(param_1 + 0xa87c0) = *(int *)(param_1 + 0xa87c0) + 1;
  }
  plVar3 = *(longlong **)(param_1 + 0xa8760);
  if (plVar3 != (longlong *)0x0) {
    pcVar4 = *(code **)(*plVar3 + 0x10);
    lVar9 = FUN_140189320();
    auVar15._0_4_ = (float)*(int *)(lVar9 + 0xc);
    auVar15._4_12_ = SUB1612(ZEXT816(0),4);
    (*pcVar4)(plVar3,auVar15._0_8_);
  }
  return uVar12;
}

