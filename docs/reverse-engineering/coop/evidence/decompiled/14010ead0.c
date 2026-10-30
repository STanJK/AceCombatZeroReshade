/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010ead0; RVA 0x10ead0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14010ead0(longlong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 auVar6 [32];
  bool bVar7;
  longlong lVar8;
  float *pfVar9;
  uint uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  int iVar13;
  longlong lVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined1 auVar17 [16];
  undefined1 auVar19 [16];
  undefined1 auVar18 [32];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [64];
  undefined1 auVar23 [64];
  undefined1 auVar24 [64];
  undefined1 auVar25 [64];
  undefined1 auVar26 [64];
  undefined1 auVar27 [64];
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined1 auVar31 [64];
  undefined4 local_188;
  uint local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  uint local_174;
  undefined4 local_170;
  undefined4 local_16c;
  uint local_168;
  undefined4 local_164;
  uint local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined1 local_108 [16];
  undefined1 auStack_f8 [16];
  undefined1 local_e8 [16];
  undefined1 auStack_d8 [8];
  undefined8 uStack_d0;
  
  fVar2 = DAT_1402d2e08;
  fVar1 = DAT_1402d2818;
  uVar10 = 0;
  if ((*(ushort *)(param_1 + 0x1b8) < 0x50) || (*(ushort *)(param_1 + 0x1bc) < 0x50)) {
    iVar13 = 0;
  }
  else {
    iVar13 = *(int *)(*(longlong *)(param_1 + 0x1d0) + 0x3c);
  }
  if (*(char *)(param_1 + 0x60) == '\x01') {
    local_108 = ZEXT816(0);
    auStack_f8 = ZEXT816(0);
    local_e8 = local_108;
    _auStack_d8 = auStack_f8;
    FUN_140202920(local_108,param_1 + 0x80);
    auVar17 = _auStack_d8;
    fVar1 = (float)auStack_d8._0_4_ + *(float *)(param_1 + 0x70);
    fVar2 = (float)auStack_d8._4_4_ + *(float *)(param_1 + 0x74);
    auStack_d8._0_4_ = fVar1;
    auVar19 = _auStack_d8;
    uStack_d0._0_4_ = auVar17._8_4_;
    uStack_d0._4_4_ = auVar17._12_4_;
    auStack_d8 = auVar19._0_8_;
    uStack_d0._0_4_ = (float)uStack_d0 + *(float *)(param_1 + 0x78);
    auStack_d8._4_4_ = fVar2;
    if (iVar13 < 1) {
      return;
    }
    auVar23 = ZEXT464(DAT_1402d22d0);
    auVar22 = ZEXT464(DAT_1402d2d64);
    puVar11 = (undefined4 *)(param_1 + 0x28);
    lVar14 = 0;
    auVar31 = ZEXT464(DAT_1402d3770);
    do {
      if (((*(ushort *)(param_1 + 0x1b8) < 0x50) || (*(ushort *)(param_1 + 0x1bc) < 0x50)) ||
         (*(uint *)(*(longlong *)(param_1 + 0x1d0) + 0x3c) <= uVar10)) {
        auVar18 = _DAT_1402d38a0;
        auVar6 = _DAT_1402d4140;
      }
      else {
        lVar8 = (ulonglong)
                *(ushort *)(lVar14 + *(longlong *)(*(longlong *)(param_1 + 0x1d8) + 0x78)) * 800;
        auVar18 = *(undefined1 (*) [32])(lVar8 + 0x94 + *(longlong *)(param_1 + 0x1b0));
        auVar6 = *(undefined1 (*) [32])(lVar8 + 0xb4 + *(longlong *)(param_1 + 0x1b0));
      }
      auVar17 = auVar18._0_16_;
      auVar19 = auVar18._16_16_;
      local_178 = auVar18._16_4_;
      local_170 = vextractps_avx(auVar19,2);
      auVar20 = auVar6._0_16_;
      auVar21 = auVar6._16_16_;
      local_158 = auVar6._16_4_;
      local_174 = vextractps_avx(auVar19,1);
      local_150 = vextractps_avx(auVar21,2);
      local_16c = vextractps_avx(auVar19,3);
      local_148 = local_108._0_8_;
      uStack_140 = local_108._8_8_;
      uStack_138 = auStack_f8._0_8_;
      uStack_130 = auStack_f8._8_8_;
      local_154 = vextractps_avx(auVar21,1);
      local_128 = local_e8._0_8_;
      uStack_120 = local_e8._8_8_;
      uStack_118 = auStack_d8;
      uStack_110 = uStack_d0;
      local_188 = auVar18._0_4_;
      local_184 = vextractps_avx(auVar17,1);
      local_180 = vextractps_avx(auVar17,2);
      local_17c = vextractps_avx(auVar17,3);
      local_168 = auVar6._0_4_;
      local_164 = vextractps_avx(auVar20,1);
      local_160 = vextractps_avx(auVar20,2);
      local_15c = vextractps_avx(auVar20,3);
      local_14c = vextractps_avx(auVar21,3);
      auVar22 = ZEXT1664(auVar22._0_16_);
      auVar23 = ZEXT1664(auVar23._0_16_);
      auVar31 = ZEXT1664(auVar31._0_16_);
      FUN_140005940(&local_148,&local_148,&local_188);
      auVar24 = ZEXT464(local_148._4_4_);
      auVar25 = ZEXT464(uStack_138._4_4_);
      auVar26 = ZEXT464((uint)local_128);
      auVar27 = ZEXT464((uint)uStack_120);
      local_188 = (undefined4)local_148;
      local_180 = (undefined4)uStack_140;
      local_178 = (undefined4)uStack_138;
      local_17c = uStack_140._4_4_;
      local_170 = (undefined4)uStack_130;
      local_16c = uStack_130._4_4_;
      local_15c = uStack_120._4_4_;
      local_14c = uStack_110._4_4_;
      local_184 = local_148._4_4_;
      local_174 = uStack_138._4_4_;
      local_168 = (uint)local_128;
      local_160 = (uint)uStack_120;
      local_158 = (undefined4)uStack_118;
      local_154 = uStack_118._4_4_;
      local_150 = (undefined4)uStack_110;
      auVar17 = auVar22._0_16_;
      if (local_128._4_4_ <= auVar23._0_4_) {
        auVar19 = vcmpss_avx(ZEXT416((uint)local_128._4_4_),auVar17,1);
        auVar19 = vblendvps_avx(ZEXT416((uint)local_128._4_4_),auVar17,auVar19);
      }
      else {
        auVar19 = auVar23._0_16_;
      }
      auVar17 = vmaxss_avx(auVar19,auVar17);
      auVar17 = vminss_avx(auVar17,auVar23._0_16_);
      uVar28 = (undefined4)uStack_118;
      uVar29 = uStack_118._4_4_;
      uVar30 = (undefined4)uStack_110;
      uVar15 = FUN_140272150(auVar17._0_8_);
      puVar11[-2] = uVar15 ^ auVar31._0_4_;
      uVar16 = FUN_140272370(auVar26._0_8_,auVar27._0_8_);
      puVar11[-1] = uVar16;
      uVar16 = FUN_140272370(auVar24._0_8_,auVar25._0_8_);
      *puVar11 = uVar16;
      puVar11[-10] = uVar28;
      puVar11[-9] = uVar29;
      puVar11[-8] = uVar30;
      puVar11[-7] = 0x3f800000;
      uVar10 = uVar10 + 1;
      puVar11 = puVar11 + 4;
      lVar14 = lVar14 + 2;
    } while ((int)uVar10 < iVar13);
    return;
  }
  if (*(char *)(param_1 + 0x60) != '\x02') {
    return;
  }
  bVar7 = false;
  if (iVar13 < 4) {
    if (iVar13 < 1) goto LAB_14010f1ef;
    lVar14 = 0;
LAB_14010f169:
    uVar12 = (ulonglong)(iVar13 - uVar10);
    pfVar9 = (float *)(param_1 + 0x44 + lVar14 * 0x10);
    do {
      fVar3 = *pfVar9 - fVar1 / ((float)*(byte *)(param_1 + 0x20a0) *
                                (float)*(byte *)(param_1 + 0x20a0));
      *pfVar9 = fVar3;
      auVar17 = *(undefined1 (*) [16])(pfVar9 + -0x11);
      auVar19 = vshufps_avx(auVar17,auVar17,0x55);
      fVar3 = fVar3 + auVar19._0_4_;
      auVar19 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar20 = vshufps_avx(auVar17,auVar17,0xff);
      if (fVar2 <= fVar3) {
        bVar7 = true;
      }
      pfVar9[-0x11] = auVar17._0_4_ + pfVar9[-1];
      pfVar9[-0x10] = fVar3;
      pfVar9[-0xf] = auVar19._0_4_ + pfVar9[1];
      pfVar9[-0xe] = auVar20._0_4_ + pfVar9[2];
      uVar12 = uVar12 - 1;
      pfVar9 = pfVar9 + 4;
    } while (uVar12 != 0);
  }
  else {
    pfVar9 = (float *)(param_1 + 0x44);
    uVar15 = (iVar13 - 4U >> 2) + 1;
    uVar12 = (ulonglong)uVar15;
    uVar10 = uVar15 * 4;
    lVar14 = (ulonglong)uVar15 * 4;
    do {
      fVar3 = *pfVar9 - fVar1 / ((float)*(byte *)(param_1 + 0x20a0) *
                                (float)*(byte *)(param_1 + 0x20a0));
      *pfVar9 = fVar3;
      auVar17 = *(undefined1 (*) [16])(pfVar9 + -0x11);
      auVar19 = vshufps_avx(auVar17,auVar17,0x55);
      fVar3 = fVar3 + auVar19._0_4_;
      auVar19 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar20 = vshufps_avx(auVar17,auVar17,0xff);
      pfVar9[-0x11] = auVar17._0_4_ + pfVar9[-1];
      pfVar9[-0xe] = auVar20._0_4_ + pfVar9[2];
      pfVar9[-0x10] = fVar3;
      pfVar9[-0xf] = auVar19._0_4_ + pfVar9[1];
      fVar4 = pfVar9[4] -
              fVar1 / ((float)*(byte *)(param_1 + 0x20a0) * (float)*(byte *)(param_1 + 0x20a0));
      pfVar9[4] = fVar4;
      auVar17 = *(undefined1 (*) [16])(pfVar9 + -0xd);
      auVar19 = vshufps_avx(auVar17,auVar17,0x55);
      fVar4 = fVar4 + auVar19._0_4_;
      auVar19 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar20 = vshufps_avx(auVar17,auVar17,0xff);
      pfVar9[-0xd] = auVar17._0_4_ + pfVar9[3];
      pfVar9[-10] = auVar20._0_4_ + pfVar9[6];
      pfVar9[-0xc] = fVar4;
      pfVar9[-0xb] = auVar19._0_4_ + pfVar9[5];
      fVar5 = pfVar9[8] -
              fVar1 / ((float)*(byte *)(param_1 + 0x20a0) * (float)*(byte *)(param_1 + 0x20a0));
      pfVar9[8] = fVar5;
      auVar17 = *(undefined1 (*) [16])(pfVar9 + -9);
      if (fVar2 <= fVar3) {
        bVar7 = true;
      }
      auVar19 = vshufps_avx(auVar17,auVar17,0x55);
      fVar5 = fVar5 + auVar19._0_4_;
      auVar19 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar20 = vshufps_avx(auVar17,auVar17,0xff);
      pfVar9[-9] = auVar17._0_4_ + pfVar9[7];
      pfVar9[-6] = auVar20._0_4_ + pfVar9[10];
      pfVar9[-8] = fVar5;
      pfVar9[-7] = auVar19._0_4_ + pfVar9[9];
      fVar3 = pfVar9[0xc] -
              fVar1 / ((float)*(byte *)(param_1 + 0x20a0) * (float)*(byte *)(param_1 + 0x20a0));
      if (fVar2 <= fVar4) {
        bVar7 = true;
      }
      pfVar9[0xc] = fVar3;
      auVar17 = *(undefined1 (*) [16])(pfVar9 + -5);
      auVar19 = vshufps_avx(auVar17,auVar17,0x55);
      fVar3 = fVar3 + auVar19._0_4_;
      if (fVar2 <= fVar5) {
        bVar7 = true;
      }
      auVar19 = vshufps_avx(auVar17,auVar17,0xaa);
      auVar20 = vshufps_avx(auVar17,auVar17,0xff);
      if (fVar2 <= fVar3) {
        bVar7 = true;
      }
      pfVar9[-5] = auVar17._0_4_ + pfVar9[0xb];
      pfVar9[-4] = fVar3;
      pfVar9[-3] = auVar19._0_4_ + pfVar9[0xd];
      pfVar9[-2] = auVar20._0_4_ + pfVar9[0xe];
      pfVar9 = pfVar9 + 0x10;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
    if ((int)uVar10 < iVar13) goto LAB_14010f169;
  }
  if (bVar7) {
    return;
  }
LAB_14010f1ef:
  *(undefined1 *)(param_1 + 0x60) = 0;
  return;
}

