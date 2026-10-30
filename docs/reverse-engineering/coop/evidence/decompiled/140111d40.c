/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140111d40; RVA 0x111d40
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140111d40(float *param_1,byte param_2,float *param_3)

{
  ushort uVar1;
  char *pcVar2;
  byte bVar3;
  ushort uVar4;
  longlong lVar5;
  undefined1 auVar6 [16];
  bool bVar7;
  bool bVar8;
  char cVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  byte bVar13;
  undefined7 uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  float fVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined1 auVar20 [16];
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined1 auVar28 [64];
  undefined1 auVar29 [64];
  undefined1 auVar30 [16];
  undefined1 auVar31 [64];
  float fVar32;
  undefined1 auVar33 [64];
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined1 auVar37 [64];
  float fVar38;
  undefined1 auVar39 [16];
  undefined1 auVar40 [64];
  float local_res8 [2];
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined1 local_130 [8];
  float fStack_128;
  undefined4 uStack_124;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined1 local_108 [8];
  float fStack_100;
  float fStack_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined1 local_e8 [8];
  float fStack_e0;
  float fStack_dc;
  
  fVar27 = DAT_1402d1ff8;
  auVar37 = ZEXT464(DAT_1402d237c);
  uVar16 = (ulonglong)param_2;
  bVar7 = false;
  cVar9 = (char)param_3;
  auVar31 = ZEXT864(0);
  auVar29 = ZEXT864(0);
  auVar28 = ZEXT864(0);
  if ((*(byte *)((longlong)param_1 + 0x157) & 1) == 0) {
    if ((*(char *)((longlong)param_1 + 0x156) == '\x01') &&
       ((*(byte *)((longlong)param_1 + 0x157) & 2) == 0)) {
      auVar20 = ZEXT816(0);
      if (*(longlong *)(param_1 + 0x42) != 0) {
        auVar30 = *(undefined1 (*) [16])(param_1 + 0x24);
        auVar6 = vshufps_avx(auVar30,auVar30,0xaa);
        auVar39 = vshufps_avx(auVar30,auVar30,0xff);
        local_150 = auVar30._0_4_;
        auVar30 = vshufps_avx(auVar30,auVar30,0x55);
        local_148 = auVar6._0_4_;
        local_144 = auVar39._0_4_;
        local_13c = auVar30._0_4_ + DAT_1402d2698;
        param_3 = local_res8;
        local_14c = DAT_1402d2e2c;
        local_140 = local_150;
        local_138 = local_148;
        local_134 = local_144;
        _local_130 = auVar20;
        uVar11 = FUN_1400782c0(*(longlong *)(param_1 + 0x42),local_130,param_3,&local_140,&local_150
                              );
        auVar20 = vpcmpeqd_avx(ZEXT416(uVar11),SUB6416(ZEXT464(0),0));
        auVar20 = vblendvps_avx(ZEXT416((uint)local_130._4_4_),auVar31._0_16_,auVar20);
      }
      if (param_1[0x25] < auVar20._0_4_ + DAT_1402d277c) {
        bVar7 = true;
        if ((param_1[0x2a] < DAT_1402d2d98) || (auVar37._0_4_ < param_1[0x2a])) {
          auVar29 = ZEXT464((uint)fVar27);
        }
      }
    }
  }
  else {
    auVar29 = ZEXT464((uint)param_1[0x4a]);
    auVar28 = ZEXT464((uint)param_1[0x4b]);
    bVar7 = true;
  }
  cVar10 = *(char *)((longlong)param_1 + 0x156);
  bVar8 = false;
  if (cVar10 == '\x01') {
    fVar26 = param_1[0x46];
  }
  else if (cVar10 == '\x02') {
    fVar26 = param_1[0x47];
  }
  else {
    fVar26 = param_1[0x45];
  }
  uVar34 = 0;
  uVar35 = 0;
  uVar36 = 0;
  local_res8[0] = DAT_1402d22d0;
  uVar14 = (undefined7)((ulonglong)param_3 >> 8);
  uVar11 = DAT_1402d3770;
  if (bVar7) {
    fVar22 = DAT_1402d22d0;
    if (cVar10 == '\x02') {
      uVar18 = FUN_140187ec0();
      uVar19 = FUN_140187ec0(uVar18,param_2,CONCAT71(uVar14,0x1b));
      auVar28 = ZEXT464((uint)((float)uVar19 - (float)uVar18));
      uVar18 = FUN_140187ec0(uVar19,uVar16,0x1f);
      fVar17 = (float)FUN_140187ec0(uVar18,uVar16,0x1d);
      auVar29 = ZEXT464((uint)(fVar17 - (float)uVar18));
    }
    param_1[0x48] = (fVar26 - param_1[0x48]) * DAT_1402d2168 + param_1[0x48];
    param_1[0x49] = fVar26;
    *(undefined1 *)((longlong)param_1 + 0x155) = 0;
    *(undefined2 *)((longlong)param_1 + 0x15b) = 0xff;
    *(undefined1 *)((longlong)param_1 + 0x15a) = 0xff;
    goto LAB_140112130;
  }
  fVar22 = DAT_1402d2168;
  if (cVar9 == '\0') {
    if ((cVar10 != '\0') || (fVar17 = (float)FUN_140187ec0(), fVar17 < fVar22)) goto LAB_140112024;
    fVar17 = ((fVar17 - fVar22) + fVar17) - fVar22;
  }
  else {
    fVar26 = param_1[0x45];
LAB_140112024:
    fVar17 = 0.0;
  }
  cVar9 = FUN_140187a40(DAT_14032c8f0,uVar16,0xe);
  if (cVar9 == '\0') {
    *(undefined1 *)((longlong)param_1 + 0x155) = 0;
    *(undefined2 *)((longlong)param_1 + 0x15b) = 0xff;
    *(undefined1 *)((longlong)param_1 + 0x15a) = 0xff;
LAB_1401120aa:
    param_1[0x49] = fVar26;
  }
  else {
    if (param_1[0x44] <=
        (float)*(byte *)((longlong)param_1 + 0x155) / (float)*(byte *)(param_1 + 0x55)) {
      fVar26 = fVar17 * (DAT_1402d2a54 - fVar26) + fVar26;
      bVar8 = true;
      goto LAB_1401120aa;
    }
    fVar26 = param_1[0x49];
    *(byte *)((longlong)param_1 + 0x155) = *(byte *)((longlong)param_1 + 0x155) + 1;
  }
  fVar17 = param_1[0x48];
  param_1[0x48] = (fVar26 - fVar17) * fVar22 + fVar17;
  if (((*(byte *)((longlong)param_1 + 0x157) & 2) == 0) || (cVar10 != '\x01')) {
    if (!bVar8) goto LAB_1401120e8;
    bVar3 = *(byte *)(param_1 + 0x56);
    pcVar2 = (char *)((longlong)param_1 + 0x159);
    if ((bVar3 == 0xff) && (*pcVar2 == -1)) {
      uVar15 = (ulonglong)*(byte *)((longlong)param_1 + 0x15a);
      if ((*(byte *)((longlong)param_1 + 0x15a) != 0xff) &&
         (*(byte *)((longlong)param_1 + 0x15b) != 0xff)) {
        if (((*(byte *)(*(longlong *)
                         (*(longlong *)(**(longlong **)(param_1 + 0x40) + uVar15 * 8) + 0x110) +
                        0x1f0 + (ulonglong)*(byte *)((longlong)param_1 + 0x15b) * 0x520) & 2) == 0)
           && (*(char *)(param_1 + 0x57) != '\0')) {
          *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x57) + -1;
        }
        else {
          uVar15 = 0xff;
          *(undefined2 *)((longlong)param_1 + 0x15a) = 0xffff;
          *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x55) * '\x03';
        }
      }
    }
    else {
      bVar13 = *(byte *)((longlong)param_1 + 0x15a);
      if ((bVar13 == 0xff) && (*(char *)((longlong)param_1 + 0x15b) == -1)) {
        uVar15 = (ulonglong)bVar3;
        *(char *)((longlong)param_1 + 0x15b) = *pcVar2;
        *(byte *)((longlong)param_1 + 0x15a) = bVar3;
        *(char *)(param_1 + 0x57) = *(char *)(param_1 + 0x55) * '\x03';
        bVar13 = bVar3;
LAB_1401123b2:
        if (*pcVar2 == *(char *)((longlong)param_1 + 0x15b)) goto LAB_14011242f;
      }
      else {
        uVar15 = (ulonglong)bVar13;
        if (bVar3 == bVar13) goto LAB_1401123b2;
      }
      if (((*(byte *)(*(longlong *)
                       (*(longlong *)(**(longlong **)(param_1 + 0x40) + (ulonglong)bVar13 * 8) +
                       0x110) + 0x1f0 + (ulonglong)*(byte *)((longlong)param_1 + 0x15b) * 0x520) & 2
           ) == 0) && (*(char *)(param_1 + 0x57) != '\0')) {
        cVar9 = *(char *)(param_1 + 0x57) + -1;
      }
      else {
        uVar15 = (ulonglong)bVar3;
        *(byte *)((longlong)param_1 + 0x15b) = *(byte *)((longlong)param_1 + 0x159);
        *(byte *)((longlong)param_1 + 0x15a) = bVar3;
        cVar9 = *(char *)(param_1 + 0x55) * '\x03';
      }
      *(char *)(param_1 + 0x57) = cVar9;
    }
LAB_14011242f:
    if (((char)uVar15 != -1) || (*(byte *)((longlong)param_1 + 0x15b) != 0xff)) {
      bVar3 = *(byte *)((longlong)param_1 + 0x15b);
      local_118 = 0;
      uStack_110 = 0;
      _local_108 = ZEXT816(0);
      lVar5 = *(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0x40) + uVar15 * 8) + 0x110);
      local_f8 = 0;
      uStack_f0 = 0;
      _local_e8 = ZEXT816(0);
      FUN_140202920(&local_118,param_1 + 0x28);
      auVar20 = *(undefined1 (*) [16])(lVar5 + 600 + (ulonglong)bVar3 * 0x520);
      fVar17 = auVar20._0_4_ - param_1[0x24];
      auVar30 = vshufps_avx(auVar20,auVar20,0x55);
      fVar25 = auVar30._0_4_ - param_1[0x25];
      auVar30 = vshufps_avx(auVar20,auVar20,0xaa);
      fVar23 = auVar30._0_4_ - param_1[0x26];
      auVar20 = vshufps_avx(auVar20,auVar20,0xff);
      fVar32 = auVar20._0_4_ - param_1[0x27];
      fVar26 = fVar32 * uStack_f0._4_4_ + fVar23 * (float)uStack_f0 +
               fVar25 * local_f8._4_4_ + fVar17 * (float)local_f8;
      fVar22 = fVar32 * fStack_fc + fVar23 * fStack_100 +
               fVar25 * (float)local_108._4_4_ + fVar17 * (float)local_108._0_4_;
      fVar17 = fVar32 * uStack_110._4_4_ + fVar23 * (float)uStack_110 +
               fVar25 * local_118._4_4_ + fVar17 * (float)local_118;
      fVar25 = local_res8[0] / SQRT(fVar26 * fVar26 + fVar22 * fVar22 + fVar17 * fVar17);
      auVar20 = vmaxss_avx(ZEXT416((uint)(fVar22 * fVar25)),ZEXT416(DAT_1402d2d64));
      auVar20 = vminss_avx(auVar20,ZEXT416((uint)local_res8[0]));
      fVar22 = local_res8[0];
      auVar29._0_8_ = FUN_140272150(auVar20._0_8_);
      auVar29._8_56_ = extraout_var;
      auVar29 = ZEXT1664(auVar29._0_16_);
      auVar28._0_8_ =
           FUN_140272370(CONCAT44(uVar34,(uint)(fVar17 * fVar25) ^ uVar11),
                         CONCAT44(uVar34,(uint)(fVar26 * fVar25) ^ uVar11));
      auVar28._8_56_ = extraout_var_00;
      auVar28 = ZEXT1664(auVar28._0_16_);
      goto LAB_140112130;
    }
    auVar29 = ZEXT864(0);
    auVar28 = ZEXT864(0);
  }
  else {
    bVar8 = false;
LAB_1401120e8:
    uVar18 = FUN_140187ec0(fVar17,uVar16,0x19);
    uVar19 = FUN_140187ec0(uVar18,uVar16,0x1b);
    auVar28 = ZEXT464((uint)((float)uVar19 - (float)uVar18));
    uVar18 = FUN_140187ec0(uVar19,uVar16,0x1f);
    fVar26 = (float)FUN_140187ec0(uVar18,uVar16,0x1d);
    auVar29 = ZEXT464((uint)(fVar26 - (float)uVar18));
  }
  fVar22 = local_res8[0];
LAB_140112130:
  _local_130 = ZEXT816(0);
  if (*(char *)((longlong)param_1 + 0x156) == '\x01') {
    local_130._4_4_ = param_1[0x4e] * DAT_1402d2c9c;
    local_130._0_4_ = param_1[0x4c] * DAT_1402d2cc0;
    fStack_128 = param_1[0x4d] * DAT_1402d2038;
    uStack_124 = 0;
  }
  bVar3 = *(byte *)((longlong)param_1 + 0x15e);
  auVar40 = ZEXT464(DAT_1402d2db4);
  auVar33 = ZEXT464(DAT_1402d2420);
  if (bVar3 != 0) {
    fVar17 = (float)*(byte *)(param_1 + 0x55);
    iVar12 = FUN_140242630();
    fVar17 = (((float)iVar12 * DAT_1402d1d98 - local_res8[0]) * (float)bVar3) / fVar17;
    fVar25 = (float)*(byte *)(param_1 + 0x55);
    fVar22 = (float)*(byte *)((longlong)param_1 + 0x15e);
    iVar12 = FUN_140242630();
    fVar26 = DAT_1402d1d98;
    *(char *)((longlong)param_1 + 0x15e) = *(char *)((longlong)param_1 + 0x15e) + -1;
    fVar25 = (((float)iVar12 * fVar26 - local_res8[0]) * fVar22) / fVar25;
    fVar22 = local_res8[0];
    if (*(char *)((longlong)param_1 + 0x156) == '\x01') {
      auVar20 = *(undefined1 (*) [16])(param_1 + 0x38);
      auVar30 = vshufps_avx(auVar20,auVar20,0x55);
      fVar27 = (fVar25 - param_1[0x39]) * DAT_1402d2034;
      auVar6 = vshufps_avx(auVar20,auVar20,0xaa);
      fVar26 = DAT_1402d2cdc * param_1[0x3a];
      auVar39 = vshufps_avx(auVar20,auVar20,0xff);
      fVar25 = DAT_1402d2cdc * param_1[0x3b];
      param_1[0x38] = (fVar17 - param_1[0x38]) * DAT_1402d2034 + auVar20._0_4_;
      param_1[0x39] = fVar27 + auVar30._0_4_;
      param_1[0x3a] = fVar26 + auVar6._0_4_;
      param_1[0x3b] = fVar25 + auVar39._0_4_;
    }
    else {
      param_1[0x38] = fVar17;
      auVar30._4_12_ = auVar29._4_12_;
      auVar30._0_4_ = fVar17 * fVar27 + auVar29._0_4_;
      auVar6._4_12_ = auVar28._4_12_;
      auVar6._0_4_ = fVar25 * fVar27 + auVar28._0_4_;
      auVar39 = auVar40._0_16_;
      auVar20 = vcmpss_avx(auVar30,auVar39,1);
      auVar20 = vblendvps_avx(auVar30,auVar39,auVar20);
      auVar20 = vminss_avx(auVar20,auVar33._0_16_);
      auVar29 = ZEXT1664(auVar20);
      auVar20 = vcmpss_avx(auVar6,auVar39,1);
      auVar20 = vblendvps_avx(auVar6,auVar39,auVar20);
      auVar20 = vminss_avx(auVar20,auVar33._0_16_);
      auVar28 = ZEXT1664(auVar20);
      param_1[0x39] = fVar25;
      param_1[0x3a] = 0.0;
      param_1[0x3b] = 0.0;
    }
  }
  fVar17 = DAT_1402d249c;
  fVar26 = auVar29._0_4_;
  fVar27 = auVar28._0_4_;
  auVar20 = auVar37._0_16_;
  if (*(ushort *)(param_1 + 0x50) != 0) {
    uVar4 = *(ushort *)((longlong)param_1 + 0x142);
    uVar1 = uVar4 + 1;
    *(ushort *)((longlong)param_1 + 0x142) = uVar1;
    if (uVar4 < *(ushort *)(param_1 + 0x50)) {
      fVar25 = param_1[0x52];
      fVar23 = (float)FUN_140275650(((float)((ulonglong)uVar1 %
                                            (ulonglong)*(ushort *)(param_1 + 0x51)) /
                                    (float)*(ushort *)(param_1 + 0x51)) * fVar17);
      fVar26 = auVar29._0_4_;
      fVar27 = auVar28._0_4_;
      auVar20 = auVar37._0_16_;
      param_1[0x52] = fVar25 * param_1[0x53];
      param_1[0x54] = fVar23 * fVar25;
      if ((*(char *)((longlong)param_1 + 0x156) == '\x02') ||
         (*(char *)((longlong)param_1 + 0x156) == '\0')) {
        param_1[0x28] = fVar23 * fVar25 + param_1[0x28];
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x50) = 0;
      param_1[0x54] = 0.0;
    }
  }
  fVar32 = auVar33._0_4_;
  fVar38 = auVar40._0_4_;
  cVar9 = *(char *)((longlong)param_1 + 0x156);
  fVar23 = auVar31._0_4_;
  auVar30 = auVar31._0_16_;
  fVar25 = auVar20._0_4_;
  if (cVar9 == '\x02') {
    if (bVar8) {
      fVar27 = fVar27 * DAT_1402d268c;
      if (fVar23 <= fVar27) {
        auVar20 = vminss_avx(ZEXT416((uint)fVar27),ZEXT416((uint)param_1[0xf]));
        fVar27 = auVar20._0_4_ / param_1[0xf];
      }
      else {
        auVar20._0_4_ = (uint)param_1[0x19] ^ uVar11;
        auVar20._4_4_ = uVar34;
        auVar20._8_4_ = uVar35;
        auVar20._12_4_ = uVar36;
        auVar20 = vmaxss_avx(auVar20,ZEXT416((uint)fVar27));
        fVar27 = auVar20._0_4_ / param_1[0x19];
      }
      fVar26 = fVar26 * DAT_1402d21a8;
    }
    if (fVar23 <= fVar27) {
      fVar21 = param_1[10] / param_1[0xf];
      fVar24 = param_1[0xb];
      if (fVar27 <= fVar21) {
        fVar22 = fVar24 * (fVar27 / fVar21) + -((fVar27 / fVar21) * param_1[9]) + param_1[9];
      }
      else {
        fVar22 = (fVar27 - fVar21) / (fVar22 - fVar21);
        fVar22 = fVar22 * param_1[0x10] + -(fVar24 * fVar22) + fVar24;
      }
    }
    else {
      fVar21 = param_1[0x14] / param_1[0x19];
      fVar24 = param_1[0x15];
      if ((float)((uint)fVar21 ^ uVar11) <= fVar27) {
        fVar22 = (float)((uint)(fVar27 / fVar21) ^ uVar11);
        fVar22 = fVar22 * fVar24 + -(fVar22 * param_1[9]) + param_1[9];
      }
      else {
        fVar22 = ((float)((uint)fVar27 ^ uVar11) - fVar21) / (fVar22 - fVar21);
        fVar22 = fVar22 * param_1[0x1a] + -(fVar24 * fVar22) + fVar24;
      }
    }
    if (fVar23 <= fVar26) {
      fVar26 = fVar26 * fVar25;
    }
    else {
      fVar26 = fVar22 * fVar26 * DAT_1402d1f38;
    }
    auVar20 = vpcmpeqd_avx(ZEXT116(*(byte *)((longlong)param_1 + 0x157) & 4),SUB6416(ZEXT464(0),0));
    auVar20 = vblendvps_avx(ZEXT416(DAT_1402d1f90),auVar30,auVar20);
    if (fVar23 <= fVar27) {
      fVar27 = fVar27 * (DAT_1402d1f38 * param_1[0xf] - auVar20._0_4_);
    }
    else {
      fVar27 = fVar27 * (DAT_1402d1f38 * param_1[0x19] - auVar20._0_4_);
    }
  }
  else if (!bVar8) {
    fVar26 = fVar26 * fVar25;
    auVar29 = ZEXT464((uint)fVar26);
    if (*(char *)(uVar16 + 0x82 + DAT_14032c8c0) == '\x03') {
      fVar25 = fVar27 * fVar25;
      auVar28 = ZEXT464((uint)fVar25);
      fVar27 = fVar25;
      if (!bVar7) {
        if ((cVar9 == '\x01') && (*(char *)((longlong)param_1 + 0x15d) == '\x01')) {
          auVar20 = vcmpss_avx(ZEXT416((uint)fVar26),auVar30,1);
          auVar20 = vblendvps_avx(ZEXT416((uint)fVar26),auVar30,auVar20);
          auVar29 = ZEXT1664(auVar20);
        }
        cVar10 = FUN_140187a40(DAT_14032c8f0,uVar16,0x21);
        fVar27 = auVar28._0_4_;
        fVar26 = auVar29._0_4_;
        fVar32 = auVar33._0_4_;
        fVar38 = auVar40._0_4_;
        if ((cVar10 != '\0') &&
           (((*(char *)((longlong)param_1 + 0x15d) != '\x02' || (cVar9 != '\x01')) &&
            (fVar27 = fVar27 + fVar32, auVar31._0_4_ < fVar25)))) {
          fVar27 = fVar25 - fVar32;
        }
      }
    }
    else {
      fVar27 = fVar27 * fVar32;
      if ((!bVar7) && (cVar9 == '\x01')) {
        if (*(char *)((longlong)param_1 + 0x15d) == '\x01') {
          if (fVar23 < fVar26) {
            fVar26 = 0.0;
          }
        }
        else if (*(char *)((longlong)param_1 + 0x15d) == '\x02') {
          auVar30 = vcmpss_avx(auVar20,ZEXT416((uint)fVar27),1);
          auVar20 = vblendvps_avx(ZEXT416((uint)fVar27),auVar20,auVar30);
          auVar20 = vmaxss_avx(auVar20,ZEXT416((uint)DAT_1402d2d98));
          fVar27 = auVar20._0_4_;
        }
      }
    }
  }
  fVar27 = fVar27 - param_1[0x3d];
  if (*(char *)((longlong)param_1 + 0x156) != '\x02') {
    if (fVar38 <= fVar27) {
      if (fVar32 < fVar27) {
        fVar27 = fVar27 - fVar17;
      }
    }
    else {
      fVar27 = fVar27 + fVar17;
    }
  }
  auVar20 = *(undefined1 (*) [16])(param_1 + 0x3c);
  param_1[0x3c] = (fVar26 - param_1[0x3c]) * DAT_1402d2034 + auVar20._0_4_;
  auVar30 = vshufps_avx(auVar20,auVar20,0x55);
  param_1[0x3d] = fVar27 * DAT_1402d2034 + auVar30._0_4_;
  auVar30 = vshufps_avx(auVar20,auVar20,0xaa);
  fVar27 = param_1[0x3e] * DAT_1402d2cdc;
  auVar20 = vshufps_avx(auVar20,auVar20,0xff);
  param_1[0x3f] = param_1[0x3f] * DAT_1402d2cdc + auVar20._0_4_;
  param_1[0x3e] = fVar27 + auVar30._0_4_;
  cVar9 = *(char *)((longlong)param_1 + 0x156);
  if (cVar9 == '\0') {
    FUN_140203050(param_1 + 0x34,param_1 + 0x28,param_1 + 0x3c);
    fVar26 = param_1[6];
    fVar22 = param_1[7];
    fVar17 = param_1[8];
    _local_108 = ZEXT816(0);
    local_118 = 0;
    uStack_110 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    _local_e8 = _local_108;
    FUN_140202920(&local_118,param_1 + 0x28);
    fVar25 = fVar17 * (float)uStack_f0 + fVar22 * fStack_100 + fVar26 * (float)uStack_110 +
             fStack_e0;
    fVar27 = fVar17 * local_f8._4_4_ + fVar22 * (float)local_108._4_4_ + fVar26 * local_118._4_4_ +
             (float)local_e8._4_4_;
    auVar20 = *(undefined1 (*) [16])(param_1 + 0x24);
    fVar17 = fVar17 * (float)local_f8 + fVar22 * (float)local_108._0_4_ + fVar26 * (float)local_118
             + (float)local_e8._0_4_;
    auVar30 = vshufps_avx(auVar20,auVar20,0x55);
    param_1[0x30] = fVar17 + auVar20._0_4_;
    auVar20 = vshufps_avx(auVar20,auVar20,0xaa);
    param_1[0x31] = fVar27 + auVar30._0_4_;
    param_1[0x32] = fVar25 + auVar20._0_4_;
    param_1[0x2e] = fVar25;
    param_1[0x33] = 1.0;
    param_1[0x2f] = 1.0;
  }
  else {
    if (cVar9 == '\x01') {
      FUN_140203050(param_1 + 0x34,param_1 + 0x28,local_130);
      FUN_140203050(param_1 + 0x34,param_1 + 0x34,param_1 + 0x3c);
      fVar27 = *param_1;
      fVar26 = param_1[2];
      fVar23 = -((float)((uint)(param_1[0x3c] * DAT_1402d21a8) & _DAT_1402d3760) * param_1[1]) +
               param_1[1];
      _local_108 = ZEXT816(0);
      local_118 = 0;
      uStack_110 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      _local_e8 = _local_108;
      FUN_140202920(&local_118,param_1 + 0x34);
      fVar22 = fVar26 * uStack_f0._4_4_ + fVar23 * fStack_fc + fVar27 * uStack_110._4_4_ + fStack_dc
      ;
      fVar17 = fVar26 * (float)uStack_f0 + fVar23 * fStack_100 + fVar27 * (float)uStack_110 +
               fStack_e0;
      fVar25 = fVar26 * (float)local_f8 +
               fVar23 * (float)local_108._0_4_ + fVar27 * (float)local_118 + (float)local_e8._0_4_;
      fVar23 = fVar26 * local_f8._4_4_ + fVar23 * (float)local_108._4_4_ + fVar27 * local_118._4_4_
               + (float)local_e8._4_4_;
      _local_108 = ZEXT816(0);
      local_118 = 0;
      uStack_110 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      _local_e8 = _local_108;
      FUN_140202920(&local_118,param_1 + 0x28);
      fVar27 = param_1[3];
      fVar26 = param_1[4];
      fVar24 = param_1[0x4f] * DAT_1402d24d0 + param_1[5];
      fVar32 = fVar24 * (float)uStack_f0 + fVar26 * fStack_100 + fVar27 * (float)uStack_110 +
               fStack_e0;
      fVar38 = fVar24 * (float)local_f8 +
               fVar26 * (float)local_108._0_4_ + fVar27 * (float)local_118 + (float)local_e8._0_4_;
      fVar27 = fVar24 * local_f8._4_4_ + fVar26 * (float)local_108._4_4_ + fVar27 * local_118._4_4_
               + (float)local_e8._4_4_;
      if (*(char *)((longlong)param_1 + 0x15e) != '\0') {
        auVar20 = *(undefined1 (*) [16])(param_1 + 0x34);
        auVar30 = vshufps_avx(auVar20,auVar20,0x55);
        fVar26 = DAT_1402d205c * param_1[0x39];
        auVar6 = vshufps_avx(auVar20,auVar20,0xaa);
        fVar24 = DAT_1402d205c * param_1[0x3a];
        auVar39 = vshufps_avx(auVar20,auVar20,0xff);
        fVar21 = DAT_1402d205c * param_1[0x3b];
        param_1[0x34] = DAT_1402d205c * param_1[0x38] + auVar20._0_4_;
        param_1[0x35] = fVar26 + auVar30._0_4_;
        param_1[0x36] = fVar24 + auVar6._0_4_;
        param_1[0x37] = fVar21 + auVar39._0_4_;
      }
      auVar20 = *(undefined1 (*) [16])(param_1 + 0x24);
      param_1[0x30] = auVar20._0_4_ + fVar25 + fVar38;
      auVar30 = vshufps_avx(auVar20,auVar20,0x55);
      param_1[0x31] = auVar30._0_4_ + fVar23 + fVar27;
      auVar30 = vshufps_avx(auVar20,auVar20,0xaa);
      param_1[0x32] = auVar30._0_4_ + fVar17 + fVar32;
      auVar20 = vshufps_avx(auVar20,auVar20,0xff);
      param_1[0x33] = auVar20._0_4_ + fVar22;
      param_1[0x2c] = fVar38 + fVar25;
      param_1[0x2e] = fVar32 + fVar17;
      param_1[0x2d] = fVar27 + fVar23;
      param_1[0x2f] = fVar22;
      return;
    }
    if (cVar9 != '\x02') {
      return;
    }
    FUN_140203050(param_1 + 0x34,param_1 + 0x28,param_1 + 0x3c);
    fVar27 = param_1[6];
    fVar26 = param_1[7];
    fVar22 = param_1[8];
    _local_108 = ZEXT816(0);
    local_118 = 0;
    uStack_110 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    fVar17 = param_1[0x3d] * DAT_1402d268c;
    if (auVar31._0_4_ <= param_1[0x3d]) {
      fVar25 = param_1[10];
      if (fVar17 <= fVar25) {
        fVar17 = fVar17 / fVar25;
        fVar27 = -(param_1[0xc] * fVar17) + fVar27;
        fVar26 = fVar17 * param_1[0xd] + fVar26;
        fVar22 = param_1[0xe] * fVar17 + fVar22;
      }
      else {
        fVar25 = (fVar17 - fVar25) / (param_1[0xf] - fVar25);
        fVar17 = local_res8[0] - fVar25;
        fVar26 = fVar25 * param_1[0x12] + param_1[0xd] * fVar17 + fVar26;
        fVar22 = fVar25 * param_1[0x13] + param_1[0xe] * fVar17 + fVar22;
        fVar27 = fVar27 - (fVar25 * param_1[0x11] + fVar17 * param_1[0xc]);
      }
    }
    else {
      fVar25 = param_1[0x14];
      if ((float)((uint)fVar25 ^ uVar11) <= fVar17) {
        fVar17 = (float)((uint)(fVar17 / fVar25) ^ uVar11);
        fVar27 = param_1[0x16] * fVar17 + fVar27;
        fVar26 = fVar17 * param_1[0x17] + fVar26;
        fVar22 = fVar17 * param_1[0x18] + fVar22;
      }
      else {
        fVar25 = ((float)((uint)fVar17 ^ uVar11) - fVar25) / (param_1[0x19] - fVar25);
        fVar17 = local_res8[0] - fVar25;
        fVar26 = fVar25 * param_1[0x1c] + param_1[0x17] * fVar17 + fVar26;
        fVar22 = fVar25 * param_1[0x1d] + fVar17 * param_1[0x18] + fVar22;
        fVar27 = fVar25 * param_1[0x1b] + fVar17 * param_1[0x16] + fVar27;
      }
    }
    _local_e8 = _local_108;
    FUN_140202920(&local_118,param_1 + 0x28);
    auVar20 = *(undefined1 (*) [16])(param_1 + 0x24);
    fVar25 = fVar22 * (float)uStack_f0 + fVar27 * (float)uStack_110 + fVar26 * fStack_100 +
             fStack_e0;
    fVar23 = fVar22 * uStack_f0._4_4_ + fVar27 * uStack_110._4_4_ + fVar26 * fStack_fc + fStack_dc;
    fVar17 = fVar22 * (float)local_f8 + fVar27 * (float)local_118 + fVar26 * (float)local_108._0_4_
             + (float)local_e8._0_4_;
    fVar27 = fVar22 * local_f8._4_4_ + fVar27 * local_118._4_4_ + fVar26 * (float)local_108._4_4_ +
             (float)local_e8._4_4_;
    param_1[0x30] = auVar20._0_4_ + fVar17;
    auVar30 = vshufps_avx(auVar20,auVar20,0x55);
    auVar6 = vshufps_avx(auVar20,auVar20,0xaa);
    param_1[0x31] = auVar30._0_4_ + fVar27;
    auVar20 = vshufps_avx(auVar20,auVar20,0xff);
    param_1[0x32] = auVar6._0_4_ + fVar25;
    param_1[0x33] = auVar20._0_4_ + fVar23;
    param_1[0x2e] = fVar25;
    param_1[0x2f] = fVar23;
  }
  param_1[0x2d] = fVar27;
  param_1[0x2c] = fVar17;
  return;
}

