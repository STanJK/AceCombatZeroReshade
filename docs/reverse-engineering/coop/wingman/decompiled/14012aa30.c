/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14012aa30; RVA 0x12aa30
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14012aa30(float *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined1 auVar4 [16];
  char cVar5;
  undefined4 *puVar6;
  longlong *plVar7;
  longlong lVar8;
  int *piVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  undefined8 uVar13;
  float fVar14;
  float fVar15;
  undefined1 extraout_var [56];
  float fVar16;
  undefined1 auVar17 [16];
  float fVar18;
  ulonglong uVar19;
  undefined1 auVar20 [4];
  float fVar21;
  float fVar22;
  undefined1 auVar23 [4];
  float fVar24;
  uint uVar26;
  undefined1 auVar25 [64];
  float fVar27;
  undefined1 auVar28 [64];
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 uVar34;
  undefined1 auVar35 [64];
  undefined1 auVar36 [64];
  float local_res10 [2];
  float local_res18;
  float local_res20;
  undefined1 local_1a8 [4];
  undefined1 auStack_1a4 [4];
  undefined8 uStack_1a0;
  undefined1 local_198 [8];
  float fStack_190;
  float fStack_18c;
  undefined1 local_188 [8];
  float fStack_180;
  float fStack_17c;
  undefined1 local_178 [8];
  float fStack_170;
  float fStack_16c;
  undefined1 local_168 [8];
  float fStack_160;
  float fStack_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  undefined1 local_128 [8];
  float fStack_120;
  float fStack_11c;
  undefined1 local_118 [8];
  float fStack_110;
  float fStack_10c;
  undefined1 local_108 [8];
  float fStack_100;
  float fStack_fc;
  undefined1 local_f8 [8];
  float fStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  
  _local_128 = ZEXT816(0);
  _local_118 = ZEXT816(0);
  _local_108 = _local_128;
  _local_f8 = _local_118;
  FUN_140202920(local_128,param_1 + 100);
  local_res20 = (float)local_128._0_4_;
  local_158 = (float)local_128._4_4_;
  local_154 = fStack_120;
  local_150 = fStack_11c;
  local_14c = (float)local_118._4_4_;
  local_144 = fStack_110;
  local_140 = fStack_10c;
  local_148 = (float)local_118._0_4_;
  fVar14 = (float)FUN_140128d90(param_1[0x61]);
  fVar21 = DAT_1402d22d0;
  fVar15 = DAT_1402d2194;
  fVar30 = DAT_1402d2168;
  bVar12 = *(byte *)(param_1 + 0x91);
  auVar35 = ZEXT464((uint)DAT_1402d22d0);
  bVar1 = *(byte *)((longlong)param_1 + 0x247);
  fVar22 = (float)bVar12;
  local_res10[0] = DAT_1402d22d0 / fVar22;
  fVar16 = local_res10[0] * DAT_1402d2358;
  if ((bVar1 & 1) != 0) {
    fVar16 = fVar16 * DAT_1402d2168;
  }
  if ((bVar1 & 0x10) != 0) {
    fVar16 = fVar16 * DAT_1402d20f0;
  }
  local_res18 = param_1[100];
  fVar32 = local_res18 * DAT_1402d21a8;
  fVar18 = -(SQRT(fVar14 / param_1[0x86]) * DAT_1402d20f0) + DAT_1402d20f0;
  auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 5)));
  fVar24 = auVar17._0_4_ * fVar16;
  auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 6)));
  fVar24 = fVar24 * fVar18 + fVar24;
  fVar27 = auVar17._0_4_ * fVar16;
  auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)((longlong)param_1 + 0x16)));
  fVar27 = fVar27 * fVar18 + fVar27;
  fVar29 = auVar17._0_4_ * fVar16;
  auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)((longlong)param_1 + 0x1a)));
  fVar29 = fVar29 * fVar18 + fVar29;
  fVar31 = DAT_1402d22d0 / SQRT(fVar14 / param_1[0x86]);
  auVar4 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 7)));
  fVar14 = auVar17._0_4_ * fVar16 * fVar31;
  fVar33 = 0.0;
  fVar18 = auVar4._0_4_ * fVar16 * fVar31;
  if (fVar32 < 0.0) {
    auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 8)));
    fVar32 = auVar17._0_4_ * fVar16 * fVar31 * fVar32;
    auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)((longlong)param_1 + 0x1e)));
    auVar17 = vminss_avx(ZEXT416((uint)(auVar17._0_4_ * fVar16 * fVar31)),
                         ZEXT416((uint)(fVar29 - fVar32)));
    auVar36 = ZEXT1664(auVar17);
    fVar24 = fVar24 - fVar32;
    fVar27 = fVar27 - fVar32;
  }
  else {
    fVar16 = -(fVar32 * param_1[2] * DAT_1402d1ef4) + DAT_1402d22d0;
    auVar36 = ZEXT464((uint)(fVar29 * fVar16));
    fVar27 = fVar27 * fVar16;
    fVar24 = fVar24 * fVar16;
  }
  bVar11 = *(byte *)((longlong)param_1 + 0x246);
  fVar16 = auVar36._0_4_;
  bVar10 = bVar11;
  if ((bVar11 & 1) == 0) {
    fVar22 = param_1[0x8b];
    if (fVar22 < 0.0) {
      fVar22 = -(fVar22 * (fVar27 - fVar24));
    }
    else {
      fVar22 = fVar22 * (fVar16 - fVar24);
    }
    fVar16 = param_1[0x84];
    if (fVar22 + fVar24 < fVar16) {
      fVar29 = param_1[1];
    }
    else {
      fVar29 = *param_1;
    }
    fVar16 = ((fVar22 + fVar24) - fVar16) * DAT_1402d2194 * fVar29 * local_res10[0] + fVar16;
    param_1[0x84] = fVar16;
    fVar29 = fVar16;
    goto LAB_14012ae6a;
  }
  fVar29 = 0.0;
  if ((bVar1 & 2) == 0) {
    fVar29 = (DAT_1402d25dc / (fVar22 * fVar22)) * param_1[0x8b];
    bVar10 = bVar11 & 0xfd;
LAB_14012ad88:
    *(byte *)((longlong)param_1 + 0x246) = bVar10;
LAB_14012ad8e:
    bVar11 = bVar10;
  }
  else {
    if ((bVar11 & 2) == 0) {
      fVar29 = (param_1[0x8b] * DAT_1402d2618 - DAT_1402d26b0) / (fVar22 * fVar22);
      goto LAB_14012ad8e;
    }
    if ((uint)bVar12 * 2 <= (uint)*(byte *)(param_1 + 0x92)) {
      if (param_1[0x84] == 0.0) {
        param_1[0x84] = fVar14;
        bVar10 = bVar11 | 0x40;
      }
      else {
        param_1[0x84] = (DAT_1402d2618 / (fVar22 * fVar22)) * param_1[0x8b] + param_1[0x84];
        bVar10 = bVar11 & 0xbf;
      }
      goto LAB_14012ad88;
    }
    if (DAT_1402d22d0 == param_1[0x8b]) {
      *(byte *)(param_1 + 0x92) = *(byte *)(param_1 + 0x92) + 1;
    }
    else {
      if (param_1[0x84] == 0.0) {
        *(undefined1 *)(param_1 + 0x92) = 0;
      }
      bVar10 = *(byte *)((longlong)param_1 + 0x246);
    }
  }
  fVar29 = fVar29 + param_1[0x84];
  param_1[0x84] = fVar29;
  if (fVar29 < 0.0) {
    bVar10 = *(byte *)((longlong)param_1 + 0x246);
    param_1[0x84] = 0.0;
    fVar29 = 0.0;
    bVar11 = bVar10;
  }
  if (fVar16 < fVar29) {
    bVar10 = *(byte *)((longlong)param_1 + 0x246);
    param_1[0x84] = fVar16;
    fVar29 = fVar16;
  }
  if ((fVar29 == 0.0) && (bVar11 = bVar10, (bVar10 & 2) == 0)) {
    bVar11 = bVar10 | 2;
    *(undefined1 *)(param_1 + 0x92) = 0;
    *(byte *)((longlong)param_1 + 0x246) = bVar11;
    bVar10 = bVar11;
  }
  fVar16 = param_1[0x84];
LAB_14012ae6a:
  if ((bVar11 & 1) == 0) {
    if (fVar14 <= fVar29) {
      if (fVar18 <= fVar29) {
        param_1[0x8c] = 0.0;
      }
      else {
        param_1[0x8c] = (fVar18 - fVar29) / (fVar18 - fVar14);
      }
    }
    else {
      param_1[0x8c] = fVar21;
    }
    fVar29 = param_1[0x89];
    fVar22 = param_1[0x88];
    fVar27 = fVar29;
  }
  else {
    param_1[0x8c] = 0.0;
    fVar29 = param_1[0x89];
    fVar22 = fVar30 * param_1[0x88];
    fVar16 = param_1[0x84];
    fVar27 = 0.0;
  }
  fVar24 = DAT_1402d2cd4;
  uVar26 = 0;
  uVar19 = (ulonglong)(uint)fVar22;
  auVar28 = ZEXT464((uint)param_1[0x8a]);
  fVar32 = fVar30;
  if ((bVar10 & 0x20) == 0) {
    FUN_140128e00(param_1,param_1 + 0x6c,bVar12,fVar16,param_1[0x19],param_1[0x1a],fVar14,fVar18,
                  param_1 + 0x3c,param_1 + 0x40);
    FUN_140128e00(param_1,param_1 + 0x6e,
                  CONCAT44(uVar26 ^ _UNK_1402d3774,(uint)fVar27 ^ DAT_1402d3770),param_1[0x84],
                  param_1[0x27],param_1[0x28],fVar14,fVar18,param_1 + 0x48,param_1 + 0x4c);
    FUN_140128e00(param_1,param_1 + 0x6d,auVar28._0_8_,param_1[0x84],param_1[0x38],param_1[0x39],
                  fVar14,fVar18,param_1 + 0x54,param_1 + 0x58);
  }
  else {
    param_1[0x8a] = (float)((uint)fVar29 ^ DAT_1402d3770);
    if ((fVar22 <= fVar24) || (DAT_1402d1ff8 <= fVar22)) {
      auVar28 = ZEXT464(DAT_1402d2c44);
      param_1[0x87] = local_res18;
    }
    else {
      fVar15 = fVar29 * DAT_1402d2d4c;
      fVar16 = param_1[0x66];
      uVar26 = 0;
      if (fVar15 - DAT_1402d1fc8 <= fVar16) {
        if (fVar15 - DAT_1402d1f34 <= fVar16) {
          if (fVar15 + DAT_1402d1f34 <= fVar16) {
            if (fVar15 + DAT_1402d1fc8 <= fVar16) {
              auVar28 = ZEXT464((uint)DAT_1402d2d64);
            }
            else {
              auVar28 = ZEXT464((uint)((fVar16 - fVar15) * DAT_1402d2c88));
            }
          }
          else {
            auVar28 = ZEXT464(DAT_1402d2c44);
          }
        }
        else {
          auVar28 = ZEXT464((uint)((fVar16 - fVar15) * DAT_1402d2c88));
        }
      }
      else {
        auVar28 = ZEXT464((uint)fVar21);
      }
      auVar25._0_8_ = FUN_140275650(local_res18 - param_1[0x87]);
      auVar25._8_56_ = extraout_var;
      auVar25 = ZEXT1664(auVar25._0_16_);
      fVar16 = (float)FUN_140272c30(CONCAT44(uVar26 & _UNK_1402d3764,(uint)fVar16 & _DAT_1402d3760))
      ;
      auVar17._0_4_ = auVar25._0_4_ / fVar16;
      auVar17._4_12_ = auVar25._4_12_;
      auVar25 = ZEXT464((uint)DAT_1402d2d64);
      auVar17 = vmaxss_avx(auVar17,ZEXT416((uint)DAT_1402d2d64));
      auVar17 = vminss_avx(auVar17,auVar35._0_16_);
      fVar16 = (float)FUN_140272150(auVar17._0_8_);
      if (fVar33 <= fVar16) {
        if (DAT_1402d1f34 <= fVar16) {
          if (DAT_1402d1fc8 <= fVar16) {
            uVar19 = auVar25._0_8_;
          }
          else {
            uVar19 = (ulonglong)(uint)(fVar16 * DAT_1402d2e00);
          }
        }
        else {
          uVar19 = 0;
        }
      }
      else {
        uVar19 = auVar35._0_8_;
      }
    }
    FUN_140128e00(param_1,param_1 + 0x6c,uVar19,param_1[0x84],param_1[0x19],param_1[0x1a],fVar14,
                  fVar18,param_1 + 0x3c,param_1 + 0x40);
    FUN_140128e00(param_1,param_1 + 0x6e,auVar28._0_8_,param_1[0x84],param_1[0x27],param_1[0x28],
                  fVar14,fVar18,param_1 + 0x48,param_1 + 0x4c);
    FUN_140128e00(param_1,param_1 + 0x6d,fVar29 * DAT_1402d2d50,param_1[0x84],param_1[0x19],
                  param_1[0x1a],fVar14,fVar18,param_1 + 0x3c,param_1 + 0x40);
    fVar15 = DAT_1402d2194;
  }
  if ((*(byte *)((longlong)param_1 + 0x246) & 1) == 0) {
    fVar16 = DAT_1402d2d64 * fStack_fc;
    fVar21 = DAT_1402d2d64 * fStack_100;
    fVar14 = DAT_1402d2d64 * (float)local_108._0_4_;
    fVar22 = (float)local_108._4_4_ * DAT_1402d2d64 - DAT_1402d2080;
    fVar18 = SQRT(fVar16 * fVar16 + fVar21 * fVar21 + fVar14 * fVar14 + fVar22 * fVar22);
    fVar29 = auVar35._0_4_;
    if (fVar18 != fVar33) {
      fVar18 = fVar29 / fVar18;
      fVar14 = fVar18 * fVar14;
      fVar22 = fVar18 * fVar22;
      fVar21 = fVar18 * fVar21;
      fVar16 = fVar18 * fVar16;
    }
    if ((*(byte *)((longlong)param_1 + 0x246) & 0x20) == 0) {
      auVar17 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x91)));
      fVar27 = fVar29 / auVar17._0_4_;
      fVar18 = (fVar16 * local_140 + fVar21 * local_144 + fVar14 * local_148 + fVar22 * local_14c) -
               DAT_1402d2cf0;
      param_1[0x6d] =
           -(fVar27 * (fVar16 * local_150 +
                      fVar21 * local_154 + fVar22 * local_158 + fVar14 * local_res20) *
                      param_1[0x37] * fVar15) + param_1[0x6d];
      param_1[0x6c] = fVar27 * fVar18 * param_1[0x18] * fVar15 + param_1[0x6c];
    }
    fVar16 = param_1[0x8c];
    if (fVar32 < fVar16) {
      _local_198 = ZEXT816(0);
      _local_188 = ZEXT816(0);
      fVar16 = fVar16 + fVar16;
      fVar29 = fVar16 - fVar29;
      _local_178 = _local_198;
      _local_168 = _local_188;
      FUN_140202920(local_198,param_1 + 100);
      fVar15 = fStack_160 - fStack_170;
      fVar21 = fStack_15c - fStack_16c;
      fVar14 = (float)local_168._0_4_ - (float)local_178._0_4_;
      fVar22 = ((float)local_168._4_4_ - (float)local_178._4_4_) -
               ((fVar29 * fVar16 - fVar29) * param_1[3] * DAT_1402d2194) /
               (float)*(byte *)(param_1 + 0x91);
      fVar29 = fVar21 * fStack_16c +
               fVar15 * fStack_170 +
               fVar22 * (float)local_178._4_4_ + fVar14 * (float)local_178._0_4_;
      fVar16 = fVar15 * fStack_190 + fVar21 * fStack_18c +
               fVar22 * (float)local_198._4_4_ + fVar14 * (float)local_198._0_4_;
      auVar28 = ZEXT464((uint)fVar16);
      fVar16 = (float)FUN_140272370(fVar22 * (float)local_188._4_4_ +
                                    fVar14 * (float)local_188._0_4_ +
                                    fVar15 * fStack_180 + fVar21 * fStack_17c,
                                    SQRT(fVar29 * fVar29 + fVar16 * fVar16));
      param_1[0x6c] = fVar16;
      fVar16 = (float)FUN_140272370(auVar28._0_8_);
      fVar15 = DAT_1402d2420;
      fVar16 = fVar16 + DAT_1402d2420;
      param_1[0x6d] = fVar16;
      param_1[0x6e] = 0.0;
      param_1[0x6f] = 0.0;
      fVar32 = fVar30;
      if (fVar15 < fVar16) {
        param_1[0x6d] = fVar16 - DAT_1402d249c;
      }
    }
  }
  _local_1a8 = ZEXT816(0);
  fVar16 = DAT_1402d2c90;
  if ((*(byte *)((longlong)param_1 + 0x246) & 1) == 0) {
    FUN_140203050(param_1 + 100,param_1 + 100,param_1 + 0x6c);
    fVar14 = auVar35._0_4_;
    auVar23 = *(undefined1 (*) [4])*(undefined1 (*) [16])(param_1 + 100);
    auVar20 = (undefined1  [4])param_1[0x65];
    fVar15 = param_1[0x66];
    fVar21 = param_1[0x67];
    _local_1a8 = *(undefined1 (*) [16])(param_1 + 100);
  }
  else {
    FUN_1401293b0(param_1,&local_138);
    fVar15 = fVar16;
    if (DAT_1402d1ff8 < param_1[0x88]) {
      fVar15 = DAT_1402d2c74;
    }
    local_138 = local_138 + fVar15;
    local_134 = fVar33;
    FUN_140203050(param_1 + 100,param_1 + 100,param_1 + 0x6c);
    FUN_140203050(local_1a8,param_1 + 100,&local_138);
    fVar14 = auVar35._0_4_;
    auVar20 = auStack_1a4;
    auVar23 = local_1a8;
    fVar21 = uStack_1a0._4_4_;
    fVar15 = (float)uStack_1a0;
  }
  _local_198 = ZEXT816(0);
  param_1[0x68] = param_1[0x60];
  param_1[0x69] = param_1[0x61];
  _local_188 = ZEXT816(0);
  param_1[0x6a] = param_1[0x62];
  param_1[0x6b] = param_1[99];
  fVar22 = (param_1[4] * DAT_1402d2478) / (float)*(byte *)(param_1 + 0x91);
  _local_178 = _local_198;
  _local_168 = _local_188;
  if (fVar14 <= param_1[0x85]) {
    param_1[0x70] = (float)auVar23;
    param_1[0x71] = (float)auVar20;
    param_1[0x72] = fVar15;
    param_1[0x73] = fVar21;
  }
  else {
    FUN_140203270(param_1 + 0x70,param_1 + 0x70,local_1a8,param_1[0x85]);
  }
  FUN_140202920(local_198,param_1 + 0x70);
  uVar26 = DAT_1402d3770;
  fVar15 = param_1[0x84];
  uVar34 = 0;
  fVar27 = (float)((uint)fVar15 ^ DAT_1402d3770);
  fVar14 = fVar27 * fStack_16c;
  fVar29 = fVar27 * fStack_170;
  fVar18 = fVar27 * (float)local_178._0_4_;
  fVar21 = param_1[0x8c] * param_1[0x8c] * DAT_1402d2474;
  bVar12 = *(byte *)((longlong)param_1 + 0x247) & 1;
  if (bVar12 != 0) {
    fVar21 = fVar21 * fVar32;
  }
  fVar21 = fVar27 * (float)local_178._4_4_ - fVar21;
  if ((*(byte *)((longlong)param_1 + 0x246) & 0x20) == 0) {
    fVar21 = -(fVar22 * param_1[0x66] * param_1[0x66] * DAT_1402d1ffc) + fVar21;
  }
  if ((*(byte *)((longlong)param_1 + 0x247) & 8) != 0) {
    fVar22 = SQRT(fVar14 * fVar14 + fVar29 * fVar29 + fVar18 * fVar18 + fVar21 * fVar21);
    fVar27 = auVar36._0_4_;
    if (fVar27 < fVar22) {
      fVar22 = fVar27 / fVar22;
      fVar18 = fVar18 * fVar22;
      fVar21 = fVar21 * fVar22;
      fVar29 = fVar29 * fVar22;
      fVar14 = fVar22 * fVar14;
      param_1[0x84] = fVar27;
      fVar15 = fVar27;
    }
  }
  fVar22 = DAT_1402d21e4;
  if (bVar12 != 0) {
    if ((*(byte *)((longlong)param_1 + 0x246) & 1) == 0) {
      fVar16 = ((float)*(ushort *)(param_1 + 5) * DAT_1402d21e4) / (float)*(byte *)(param_1 + 0x91);
      if (fVar15 < fVar16) {
        fVar21 = fVar21 - (-((fVar15 / fVar16) * fVar32) + fVar32);
      }
      fVar21 = fVar21 + DAT_1402d2cd4;
    }
    else {
      fVar21 = fVar21 + fVar16;
    }
  }
  auVar17 = *(undefined1 (*) [16])(param_1 + 0x60);
  param_1[0x60] = fVar18 + auVar17._0_4_;
  auVar4 = vshufps_avx(auVar17,auVar17,0x55);
  param_1[0x61] = fVar21 + auVar4._0_4_;
  auVar4 = vshufps_avx(auVar17,auVar17,0xaa);
  param_1[0x62] = fVar29 + auVar4._0_4_;
  auVar17 = vshufps_avx(auVar17,auVar17,0xff);
  param_1[99] = fVar14 + auVar17._0_4_;
  if ((*(byte *)((longlong)param_1 + 0x247) & 1) != 0) {
    cVar5 = FUN_140129660(param_1);
    bVar12 = *(byte *)((longlong)param_1 + 0x246);
    if (cVar5 == '\0') {
      if ((bVar12 & 1) != 0) {
        if (*(byte *)((longlong)param_1 + 0x249) < *(byte *)(param_1 + 0x91) >> 1) {
          uVar13 = *(undefined8 *)(param_1 + 0x80);
          cVar5 = '\0';
          if (((float)*(ushort *)(param_1 + 5) * fVar22) / (float)*(byte *)(param_1 + 0x91) <=
              param_1[0x84]) {
            cVar5 = *(byte *)((longlong)param_1 + 0x249) + 1;
          }
          *(char *)((longlong)param_1 + 0x249) = cVar5;
          FUN_1400110b0(uVar13,&local_138);
          FUN_1400111f0(uVar13,local_1a8);
          FUN_140011150(uVar13,&local_e8);
          _local_188 = ZEXT816(0);
          _local_198 = ZEXT816(0);
          _local_178 = ZEXT816(0);
          _local_168 = _local_188;
          FUN_140202920(local_198,param_1 + 100);
          local_res20 = (float)local_168._0_4_ + param_1[0x60];
          fVar15 = fStack_160 + param_1[0x62];
          local_res18 = (float)local_168._4_4_ + param_1[0x61];
          local_144 = local_138 * fStack_18c + local_134 * fStack_17c +
                      local_130 * fStack_16c + fStack_15c * local_12c;
          local_140 = local_138 * fStack_190 + local_134 * fStack_180 +
                      fVar15 * local_12c + fStack_170 * local_130;
          local_148 = local_res18 * local_12c + local_130 * (float)local_178._4_4_ +
                      (float)local_198._4_4_ * local_138 + local_134 * (float)local_188._4_4_;
          fVar16 = local_res20 * local_12c + (float)local_178._0_4_ * local_130 +
                   (float)local_198._0_4_ * local_138 + local_134 * (float)local_188._0_4_;
          local_158 = (float)uStack_1a0 * fStack_16c + fStack_15c * uStack_1a0._4_4_ +
                      (float)auStack_1a4 * fStack_17c + (float)local_1a8 * fStack_18c;
          local_154 = uStack_1a0._4_4_ * fVar15 + fStack_170 * (float)uStack_1a0 +
                      (float)auStack_1a4 * fStack_180 + (float)local_1a8 * fStack_190;
          local_14c = (float)local_188._4_4_ * (float)auStack_1a4 +
                      (float)local_1a8 * (float)local_198._4_4_ +
                      uStack_1a0._4_4_ * local_res18 + (float)uStack_1a0 * (float)local_178._4_4_;
          local_150 = (float)local_188._0_4_ * (float)auStack_1a4 +
                      (float)local_1a8 * (float)local_198._0_4_ +
                      uStack_1a0._4_4_ * local_res20 + (float)local_178._0_4_ * (float)uStack_1a0;
          fVar21 = (float)local_188._4_4_ * local_e8._4_4_ +
                   (float)local_e8 * (float)local_198._4_4_ +
                   uStack_e0._4_4_ * local_res18 + (float)uStack_e0 * (float)local_178._4_4_;
          uStack_1a0._4_4_ = local_144;
          local_1a8 = (undefined1  [4])fVar16;
          uStack_1a0._0_4_ = local_140;
          auStack_1a4 = (undefined1  [4])local_148;
          fVar16 = local_148;
          if (local_14c < local_148) {
            local_1a8 = (undefined1  [4])local_150;
            uStack_1a0._0_4_ = local_154;
            uStack_1a0._4_4_ = local_158;
            auStack_1a4 = (undefined1  [4])local_14c;
            fVar16 = local_14c;
          }
          if (fVar21 < fVar16) {
            auStack_1a4 = (undefined1  [4])fVar21;
            local_1a8 = (undefined1  [4])
                        ((float)local_188._0_4_ * local_e8._4_4_ +
                         (float)local_e8 * (float)local_198._0_4_ +
                        uStack_e0._4_4_ * local_res20 + (float)local_178._0_4_ * (float)uStack_e0);
            uStack_1a0._0_4_ =
                 uStack_e0._4_4_ * fVar15 + fStack_170 * (float)uStack_e0 +
                 local_e8._4_4_ * fStack_180 + (float)local_e8 * fStack_190;
            uStack_1a0._4_4_ =
                 (float)uStack_e0 * fStack_16c + fStack_15c * uStack_e0._4_4_ +
                 local_e8._4_4_ * fStack_17c + (float)local_e8 * fStack_18c;
            fVar16 = fVar21;
          }
          local_res10[0] = 0.0;
          local_e8 = _local_1a8;
          uStack_e0 = uStack_1a0;
          fVar15 = (float)FUN_140078db0(*(undefined8 *)(param_1 + 0x7c),&local_e8,local_res10);
          if (param_1[0x84] <
              ((float)*(ushort *)(param_1 + 5) * DAT_1402d21e4) / (float)*(byte *)(param_1 + 0x91))
          {
            param_1[0x61] = param_1[0x61] - ((fVar16 - fVar15) + fVar30);
          }
          FUN_140129660(param_1);
          uVar34 = 0;
          uVar26 = DAT_1402d3770;
        }
        else {
          *(byte *)((longlong)param_1 + 0x246) = bVar12 & 0xfe;
        }
      }
      *(byte *)((longlong)param_1 + 0x246) = *(byte *)((longlong)param_1 + 0x246) & 0xf3;
    }
    else if ((bVar12 & 1) == 0) {
      *(byte *)((longlong)param_1 + 0x246) = bVar12 | 1;
      if (((bVar12 & 2) == 0) &&
         (*(byte *)((longlong)param_1 + 0x246) = bVar12 | 0xd, DAT_14033bd60 == '\0')) {
        puVar6 = (undefined4 *)FUN_140019ef0();
        FUN_14001a7c0(puVar6,*(undefined8 *)
                              (**(longlong **)(*(longlong *)(puVar6 + 0x10a) + 0x697b8) + 0x110),3);
        puVar6[1] = *puVar6;
        puVar6 = (undefined4 *)FUN_140019ef0();
        plVar7 = (longlong *)FUN_14001b280(puVar6);
        if (plVar7 != (longlong *)0x0) {
          lVar8 = *(longlong *)(**(longlong **)(*(longlong *)(puVar6 + 0x10a) + 0x697b8) + 0x110);
          uVar2 = *(undefined1 *)(**(longlong **)(*(longlong *)(puVar6 + 0x10a) + 0x697b8) + 0x15d);
          *(undefined4 *)(plVar7 + 0xc) = *puVar6;
          *(undefined2 *)((longlong)plVar7 + 100) = *(undefined2 *)(lVar8 + 0x228);
          *(undefined1 *)((longlong)plVar7 + 0x66) = *(undefined1 *)(lVar8 + 0x234);
          *(undefined1 *)((longlong)plVar7 + 0x67) = *(undefined1 *)(lVar8 + 0x235);
          *(undefined1 *)(plVar7 + 0xd) = uVar2;
          *(undefined2 *)((longlong)plVar7 + 0x69) = 0;
          *(undefined1 *)((longlong)plVar7 + 0x6b) = 8;
          *(undefined4 *)(plVar7 + 4) = 0xe30001;
          puVar3 = *(undefined8 **)(puVar6 + 0x28);
          *puVar3 = plVar7;
          *(longlong **)(puVar6 + 0x28) = plVar7;
          *plVar7 = (longlong)(puVar6 + 0x26);
          plVar7[1] = (longlong)puVar3;
          puVar6[0x42] = puVar6[0x42] + 1;
        }
      }
      *(undefined1 *)((longlong)param_1 + 0x249) = 0;
    }
    else {
      *(undefined1 *)((longlong)param_1 + 0x249) = 0;
      *(byte *)((longlong)param_1 + 0x246) = bVar12 & 0xf3;
    }
    if (DAT_14033bd60 == '\0') {
      lVar8 = FUN_140019ef0();
      piVar9 = (int *)FUN_140019ef0();
      if (*(int *)(lVar8 + 4) == *piVar9 + -8) {
        lVar8 = FUN_140019ef0();
        *(undefined1 *)
         (*(longlong *)(**(longlong **)(*(longlong *)(lVar8 + 0x428) + 0x697b8) + 0x110) + 0x40c) =
             1;
      }
    }
  }
  auVar17 = *(undefined1 (*) [16])(param_1 + 0x60);
  fVar16 = auVar17._0_4_ - param_1[0x68];
  auVar4 = vshufps_avx(auVar17,auVar17,0x55);
  fVar30 = auVar4._0_4_ - param_1[0x69];
  auVar4 = vshufps_avx(auVar17,auVar17,0xaa);
  fVar15 = auVar4._0_4_ - param_1[0x6a];
  auVar17 = vshufps_avx(auVar17,auVar17,0xff);
  fVar21 = auVar17._0_4_ - param_1[0x6b];
  param_1[0x68] = fVar16;
  param_1[0x69] = fVar30;
  param_1[0x6a] = fVar15;
  param_1[0x6b] = fVar21;
  if ((*(byte *)((longlong)param_1 + 0x247) & 8) != 0) {
    FUN_140202920(local_128,param_1 + 100);
    _local_198 = _local_128;
    _local_188 = _local_118;
    _local_178 = _local_108;
    local_168._4_4_ = (float)local_f8._4_4_ + param_1[0x61];
    local_168._0_4_ = (float)local_f8._0_4_ + param_1[0x60];
    fStack_160 = fStack_f0 + param_1[0x62];
    fStack_15c = (float)uStack_ec;
    FUN_14003a2e0(local_198);
    fVar14 = fVar16 * fStack_190 + fVar30 * fStack_180 + fVar21 * fStack_160 + fVar15 * fStack_170;
    auVar36 = ZEXT464((uint)fVar14);
    fVar22 = fVar16 * (float)local_198._4_4_ + fVar30 * (float)local_188._4_4_ +
             fVar21 * (float)local_168._4_4_ + fVar15 * (float)local_178._4_4_;
    auVar35 = ZEXT464((uint)fVar22);
    fVar14 = (float)FUN_140272370(fVar22,CONCAT44(uVar34,(uint)fVar14 ^ uVar26));
    param_1[0x8d] = fVar14;
    auVar17 = vinsertps_avx(ZEXT416((uint)(fVar30 * (float)local_188._0_4_ +
                                           fVar16 * (float)local_198._0_4_ +
                                          fVar21 * (float)local_168._0_4_ +
                                          fVar15 * (float)local_178._0_4_)),auVar35._0_16_,0x10);
    fVar14 = DAT_1402d2d64 / auVar36._0_4_;
    auVar17 = vinsertps_avx(auVar17,auVar36._0_16_,0x20);
    auVar17 = vinsertps_avx(auVar17,ZEXT416((uint)(fVar16 * fStack_18c + fVar30 * fStack_17c +
                                                  fVar21 * fStack_15c + fVar15 * fStack_16c)),0x30);
    param_1[0x78] = fVar14 * auVar17._0_4_;
    param_1[0x79] = fVar14 * auVar17._4_4_;
    param_1[0x7a] = fVar14 * auVar17._8_4_;
    param_1[0x7b] = fVar14 * auVar17._12_4_;
    param_1[0x7b] = 1.0;
  }
  return;
}

