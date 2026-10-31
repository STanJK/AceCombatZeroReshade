/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14012f340; RVA 0x12f340
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14012f340(longlong param_1)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  bool bVar7;
  char cVar8;
  int iVar9;
  byte *pbVar10;
  byte bVar11;
  byte bVar12;
  int iVar13;
  ulonglong uVar14;
  byte bVar15;
  longlong lVar16;
  ulonglong uVar17;
  longlong lVar18;
  byte bVar19;
  char cVar20;
  uint uVar21;
  longlong lVar22;
  longlong lVar23;
  ulonglong *puVar24;
  ulonglong uVar25;
  longlong lVar26;
  longlong lVar27;
  float *pfVar28;
  ulonglong uVar29;
  short *psVar30;
  int iVar31;
  undefined4 *puVar32;
  longlong lVar33;
  short sVar34;
  int iVar35;
  longlong lVar36;
  bool bVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  undefined4 unaff_XMM6_Da;
  float fVar44;
  float fVar45;
  float fVar46;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined8 unaff_XMM7_Qa;
  undefined8 unaff_XMM7_Qb;
  undefined4 unaff_XMM8_Da;
  float fVar47;
  float fVar48;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  float fVar49;
  float fVar50;
  undefined8 unaff_XMM11_Qa;
  undefined8 unaff_XMM11_Qb;
  undefined8 unaff_XMM12_Qa;
  undefined8 unaff_XMM12_Qb;
  undefined8 unaff_XMM13_Qa;
  undefined8 unaff_XMM13_Qb;
  undefined1 auVar51 [16];
  undefined1 auVar52 [64];
  undefined1 auStack_258 [32];
  byte local_238;
  byte local_237;
  float local_234;
  float local_230;
  float local_22c;
  uint local_228;
  longlong local_220;
  ulonglong local_218;
  float local_210;
  byte local_20c;
  float local_208;
  float local_204;
  float local_200;
  longlong local_1f8;
  longlong local_1f0;
  longlong local_1e8;
  longlong local_1e0;
  ulonglong local_1d8;
  undefined1 local_1c8 [16];
  undefined1 local_1b8 [8];
  float fStack_1b0;
  float fStack_1ac;
  undefined1 local_1a8 [8];
  float fStack_1a0;
  float fStack_19c;
  undefined1 local_198 [8];
  float fStack_190;
  float fStack_18c;
  float local_188;
  undefined4 local_184;
  float local_180;
  undefined4 uStack_17c;
  float local_178;
  undefined4 local_174;
  float local_170;
  undefined4 local_16c;
  float local_168;
  undefined4 local_164;
  float local_160;
  undefined4 local_15c;
  float local_158;
  undefined4 local_154;
  float local_150;
  undefined8 local_14c;
  undefined4 local_13c;
  undefined1 local_138 [4];
  float afStack_134 [3];
  undefined1 local_128 [8];
  float fStack_120;
  float fStack_11c;
  undefined1 local_118 [8];
  float fStack_110;
  float fStack_10c;
  undefined1 local_108 [8];
  float fStack_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  undefined4 local_f0;
  byte abStack_eb [3];
  undefined4 local_e8;
  short local_e2 [9];
  ulonglong local_d0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_d0 = DAT_140309040 ^ (ulonglong)auStack_258;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 8);
  uVar29 = 0;
  bVar19 = 0;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0xc);
  iVar35 = 1;
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x24);
  iVar31 = *(int *)(param_1 + 0x118);
  local_237 = 0;
  local_1d8 = 1;
  local_220 = param_1;
  if (1 < iVar31) {
    lVar16 = 0x520;
    do {
      lVar23 = *(longlong *)(param_1 + 0x110);
      lVar18 = *(longlong *)(lVar16 + 0x1c0 + lVar23);
      if (lVar18 != 0) {
        FUN_1400ac780(lVar18);
        *(undefined1 *)(lVar18 + 0x82) = 0;
        puVar1 = (uint *)(lVar16 + 0x1f0 + lVar23);
        *puVar1 = *puVar1 | 0x20000;
        bVar12 = *(byte *)(lVar16 + 0x236 + lVar23);
        if ((bVar12 != 0xff) && (bVar15 = *(byte *)(lVar16 + 0x237 + lVar23), bVar15 != 0xff)) {
          lVar22 = (ulonglong)bVar15 * 0x520;
          lVar18 = *(longlong *)
                    (*(longlong *)(**(longlong **)(param_1 + 0x140) + (ulonglong)bVar12 * 8) + 0x110
                    );
          if (((*(uint *)(lVar18 + 0x1f0 + lVar22) & 0x10000) != 0) ||
             ((*(char *)(**(longlong **)(lVar18 + 0x1a0 + lVar22) + 0x71) == '\x03' ||
              ((*(byte *)(lVar18 + 500 + lVar22) & 0xc) != 0)))) {
            *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
          }
        }
      }
      iVar31 = *(int *)(param_1 + 0x118);
      iVar35 = iVar35 + 1;
      lVar16 = lVar16 + 0x520;
    } while (iVar35 < iVar31);
  }
  lVar16 = *(longlong *)(param_1 + 0x110);
  fVar43 = *(float *)(lVar16 + 600);
  fVar40 = *(float *)(lVar16 + 0x25c);
  fVar47 = *(float *)(lVar16 + 0x260);
  fVar50 = *(float *)(lVar16 + 0x264);
  if (((*(byte *)(*(longlong *)(param_1 + 0x140) + 0x69) & 4) != 0) && (iVar35 = 1, 1 < iVar31)) {
    lVar23 = 0x520;
    do {
      lVar18 = *(longlong *)(param_1 + 0x110);
      iVar35 = iVar35 + 1;
      puVar1 = (uint *)(lVar23 + 0x1f0 + lVar18);
      *puVar1 = *puVar1 & 0xffffff7f;
      *(undefined2 *)(lVar23 + 0x236 + lVar18) = 0xffff;
      *(undefined1 *)(lVar23 + 0x249 + lVar18) = 0;
      iVar31 = *(int *)(param_1 + 0x118);
      lVar23 = lVar23 + 0x520;
    } while (iVar35 < iVar31);
  }
  if (((*(byte *)(*(longlong *)(param_1 + 0x140) + 0x69) & 8) != 0) && (iVar35 = 1, 1 < iVar31)) {
    lVar23 = 0x520;
    do {
      lVar18 = *(longlong *)(param_1 + 0x110);
      if ((*(uint *)(lVar23 + 0x1f0 + lVar18) & 0x4000) == 0) {
        bVar12 = *(byte *)(lVar23 + 0x236 + lVar18);
        if ((((bVar12 != 0xff) && (*(char *)(lVar23 + 0x237 + lVar18) == -1)) &&
            ((*(uint *)(lVar23 + 0x1f8 + lVar18) & 0x100) != 0)) &&
           (lVar22 = *(longlong *)
                      (*(longlong *)
                        (**(longlong **)(lVar23 + 0x180 + lVar18) + (ulonglong)bVar12 * 8) + 0x110),
           lVar22 != -0x51ae0)) {
          *(uint *)(lVar22 + 0x51cdc) = *(uint *)(lVar22 + 0x51cdc) | 0x10;
          *(undefined1 *)(lVar22 + 0x51d1e) = *(undefined1 *)(lVar23 + 0x234 + lVar18);
          *(undefined1 *)(lVar22 + 0x51d1f) = *(undefined1 *)(lVar23 + 0x235 + lVar18);
        }
        *(undefined2 *)(lVar23 + 0x236 + lVar18) = 0xffff;
      }
      iVar31 = *(int *)(param_1 + 0x118);
      iVar35 = iVar35 + 1;
      lVar23 = lVar23 + 0x520;
    } while (iVar35 < iVar31);
  }
  fVar42 = DAT_1402d2c04;
  puVar24 = *(ulonglong **)(param_1 + 0x140);
  local_38 = unaff_XMM6_Da;
  uStack_34 = unaff_XMM6_Db;
  uStack_30 = unaff_XMM6_Dc;
  uStack_2c = unaff_XMM6_Dd;
  local_48 = unaff_XMM7_Qa;
  uStack_40 = unaff_XMM7_Qb;
  local_238 = (byte)puVar24[0xd];
  local_58 = unaff_XMM8_Da;
  uStack_54 = unaff_XMM8_Db;
  uStack_50 = unaff_XMM8_Dc;
  uStack_4c = unaff_XMM8_Dd;
  local_88 = unaff_XMM11_Qa;
  uStack_80 = unaff_XMM11_Qb;
  local_98 = unaff_XMM12_Qa;
  uStack_90 = unaff_XMM12_Qb;
  local_210 = DAT_1402d22d0;
  local_a8 = unaff_XMM13_Qa;
  uStack_a0 = unaff_XMM13_Qb;
  auVar51._12_4_ = 0;
  auVar51._0_12_ = ZEXT812(0);
  auVar51 = auVar51 << 0x20;
  auVar52 = ZEXT1264(ZEXT812(0)) << 0x20;
  local_230 = fVar43;
  local_22c = fVar40;
  local_208 = fVar47;
  local_204 = fVar50;
  local_1e0 = lVar16;
  if (local_238 == 0) {
    local_228 = 0;
    if (*(char *)((longlong)puVar24 + 0x34) != '\0') {
      local_1f8 = 0;
      fVar42 = DAT_1402d2d64;
      fVar41 = DAT_1402d2210;
      fVar46 = DAT_1402d2b50;
      fVar38 = DAT_1402d22d0;
      do {
        uVar14 = *puVar24;
        lVar23 = *(longlong *)(local_1f8 + uVar14);
        local_218 = uVar14;
        if ((*(char *)(lVar23 + 0x15c) != *(char *)(param_1 + 0x15c)) &&
           ((*(char *)(lVar23 + 0x15d) == '\x04' || (*(char *)(lVar23 + 0x15d) == '\x05')))) {
          local_200 = 0.0;
          if (0 < *(int *)(lVar23 + 0x118)) {
            local_1f0 = 0;
            do {
              lVar22 = local_1f0;
              uVar25 = 0;
              lVar23 = *(longlong *)(lVar23 + 0x110);
              lVar18 = **(longlong **)(lVar23 + 0x1a0 + local_1f0);
              local_1e8 = lVar23;
              if ((*(byte *)(lVar18 + 0x73) & 4) == 0) {
                uVar21 = *(uint *)(lVar23 + 0x1f0 + local_1f0);
                if ((uVar21 & 2) != 0) {
                  if ((*(byte *)(lVar23 + 500 + local_1f0) & 0xc) == 0) {
                    if ((uVar21 >> 0x10 & 1) == 0) {
                      if (*(char *)(lVar18 + 0x71) != '\x03') {
                        auVar51 = *(undefined1 (*) [16])(lVar23 + 600 + local_1f0);
                        fVar43 = auVar51._0_4_ - fVar43;
                        auVar5 = vshufps_avx(auVar51,auVar51,0x55);
                        fVar40 = auVar5._0_4_ - fVar40;
                        auVar5 = vshufps_avx(auVar51,auVar51,0xaa);
                        fVar47 = auVar5._0_4_ - fVar47;
                        auVar51 = vshufps_avx(auVar51,auVar51,0xff);
                        fVar50 = auVar51._0_4_ - fVar50;
                        fVar44 = SQRT(fVar50 * fVar50 +
                                      fVar47 * fVar47 + fVar43 * fVar43 + fVar40 * fVar40);
                        if (fVar44 <= fVar46) {
                          if (fVar44 != auVar52._0_4_) {
                            fVar38 = fVar38 / fVar44;
                            fVar43 = fVar38 * fVar43;
                            fVar40 = fVar38 * fVar40;
                            fVar47 = fVar38 * fVar47;
                            fVar50 = fVar38 * fVar50;
                          }
                          local_1c8 = ZEXT816(0);
                          _local_1b8 = ZEXT816(0);
                          _local_1a8 = local_1c8;
                          _local_198 = _local_1b8;
                          FUN_140202920(local_1c8,lVar16 + 0x268);
                          uVar14 = local_218;
                          fVar38 = local_210;
                          if (fVar41 <= fVar42 * fStack_19c * fVar50 +
                                        fVar42 * fStack_1a0 * fVar47 +
                                        fVar42 * (float)local_1a8._0_4_ * fVar43 +
                                        fVar42 * (float)local_1a8._4_4_ * fVar40) {
                            local_234 = 0.0;
                            bVar19 = (byte)uVar29;
                            uVar17 = uVar25;
                            fVar50 = local_204;
                            fVar43 = local_230;
                            fVar40 = local_22c;
                            fVar47 = local_208;
                            if (bVar19 != 0) {
LAB_14012f85b:
                              if (*(float *)(local_138 + uVar17 * 4) < fVar44)
                              goto code_r0x00014012f867;
                              lVar16 = uVar29 - 1;
                              if ((longlong)uVar17 <= lVar16) {
                                if ((longlong)((lVar16 - uVar17) + 1) < 4) goto LAB_14012fa4a;
                                psVar30 = local_e2 + lVar16;
                                puVar32 = (undefined4 *)(local_138 + lVar16 * 4 + -4);
                                do {
                                  if (lVar16 != 7) {
                                    puVar32[2] = puVar32[1];
                                    abStack_eb[lVar16 + 4] = abStack_eb[lVar16 + 3];
                                    abStack_eb[lVar16 + -4] = abStack_eb[lVar16 + -5];
                                    abStack_eb[lVar16 + -0xc] = abStack_eb[lVar16 + -0xd];
                                    psVar30[2] = psVar30[1];
                                  }
                                  if (lVar16 != 8) {
                                    puVar32[1] = *puVar32;
                                    abStack_eb[lVar16 + 3] = abStack_eb[lVar16 + 2];
                                    abStack_eb[lVar16 + -5] = abStack_eb[lVar16 + -6];
                                    abStack_eb[lVar16 + -0xd] = local_108[lVar16 + 0xf];
                                    psVar30[1] = *psVar30;
                                  }
                                  if (lVar16 != 9) {
                                    *puVar32 = puVar32[-1];
                                    abStack_eb[lVar16 + 2] = abStack_eb[lVar16 + 1];
                                    abStack_eb[lVar16 + -6] = abStack_eb[lVar16 + -7];
                                    local_108[lVar16 + 0xf] = local_108[lVar16 + 0xe];
                                    *psVar30 = psVar30[-1];
                                  }
                                  if (lVar16 != 10) {
                                    puVar32[-1] = puVar32[-2];
                                    abStack_eb[lVar16 + 1] = abStack_eb[lVar16];
                                    abStack_eb[lVar16 + -7] = abStack_eb[lVar16 + -8];
                                    local_108[lVar16 + 0xe] = local_108[lVar16 + 0xd];
                                    psVar30[-1] = psVar30[-2];
                                  }
                                  lVar16 = lVar16 + -4;
                                  puVar32 = puVar32 + -4;
                                  psVar30 = psVar30 + -4;
                                  lVar22 = local_1f0;
                                } while ((longlong)(uVar17 + 3) <= lVar16);
                                for (; (longlong)uVar17 <= lVar16; lVar16 = lVar16 + -1) {
LAB_14012fa4a:
                                  if (lVar16 != 7) {
                                    afStack_134[lVar16] = *(float *)(local_138 + lVar16 * 4);
                                    abStack_eb[lVar16 + 4] = abStack_eb[lVar16 + 3];
                                    abStack_eb[lVar16 + -4] = abStack_eb[lVar16 + -5];
                                    abStack_eb[lVar16 + -0xc] = abStack_eb[lVar16 + -0xd];
                                    local_e2[lVar16 + 2] = local_e2[lVar16 + 1];
                                  }
                                }
                              }
                              *(float *)(local_138 + uVar17 * 4) = fVar44;
                              abStack_eb[uVar17 + 3] = *(byte *)(local_1e8 + 0x234 + lVar22);
                              abStack_eb[uVar17 - 5] = *(byte *)(local_1e8 + 0x235 + lVar22);
                              if (7 < (uint)local_234) goto LAB_140132235;
                              local_e2[uVar17 + 1] = *(short *)(local_1e8 + 0x428 + lVar22);
                              abStack_eb[uVar17 - 0xd] = 0;
                              lVar16 = local_1e0;
                              if (bVar19 < 7) {
                                local_237 = bVar19 + 1;
                                uVar29 = (ulonglong)local_237;
                              }
                              goto LAB_14012fb22;
                            }
LAB_14012f875:
                            if (bVar19 < 8) {
                              local_237 = bVar19 + 1;
                              abStack_eb[uVar29 + 3] = *(byte *)(lVar23 + 0x234 + lVar22);
                              abStack_eb[uVar29 - 5] = *(byte *)(lVar23 + 0x235 + lVar22);
                              local_e2[uVar29 + 1] = *(short *)(lVar23 + 0x428 + lVar22);
                              *(float *)(local_138 + uVar29 * 4) = fVar44;
                              abStack_eb[uVar29 - 0xd] = 0;
                              uVar29 = (ulonglong)local_237;
                            }
                            goto LAB_14012fb22;
                          }
                        }
                        fVar50 = local_204;
                        fVar43 = local_230;
                        fVar40 = local_22c;
                        fVar47 = local_208;
                      }
                    }
                  }
                }
              }
LAB_14012fb22:
              local_1f0 = lVar22 + 0x520;
              local_200 = (float)((int)local_200 + 1);
              lVar23 = *(longlong *)(local_1f8 + uVar14);
            } while ((int)local_200 < *(int *)(lVar23 + 0x118));
            param_1 = local_220;
          }
        }
        auVar51 = auVar52._0_16_;
        local_228 = local_228 + 1;
        puVar24 = *(ulonglong **)(param_1 + 0x140);
        local_1f8 = local_1f8 + 8;
      } while ((int)local_228 < (int)(uint)*(byte *)((longlong)puVar24 + 0x34));
    }
    fVar40 = DAT_1402d2c28;
    fVar43 = DAT_1402d2c0c;
    iVar31 = 0;
    if ((char)uVar29 != '\0') {
      bVar19 = *(byte *)(lVar16 + 0x236);
      lVar23 = 0;
      do {
        if ((abStack_eb[lVar23 + 3] == bVar19) &&
           (abStack_eb[lVar23 + -5] == *(byte *)(lVar16 + 0x237))) {
          abStack_eb[lVar23 + -0xd] = 1;
          lVar18 = *(longlong *)
                    (*(longlong *)
                      (*(longlong *)(*puVar24 + (ulonglong)abStack_eb[lVar23 + 3] * 8) + 0x110) +
                     0x1a0 + (ulonglong)abStack_eb[lVar23 + -5] * 0x520);
          if ((lVar18 == 0) ||
             (plVar3 = *(longlong **)(lVar18 + 0x10), *(longlong *)(lVar16 + 0x1a0) == 0)) break;
          lVar18 = *(longlong *)(*(longlong *)(lVar16 + 0x1b8) + 0x1fb8);
          if (lVar18 != 0) {
            cVar20 = *(char *)(*(longlong *)(lVar16 + 0x1b8) + 0x2098);
            if (cVar20 == '\0') {
              bVar19 = 100;
              if (plVar3 != (longlong *)0x0) {
                bVar19 = *(byte *)(*plVar3 + 1);
              }
              bVar12 = *(byte *)(lVar18 + 0x49);
              abStack_eb[(longlong)iVar31 + -0xd] = 1;
              local_e2[(longlong)iVar31 + 1] =
                   local_e2[(longlong)iVar31 + 1] -
                   (short)((ulonglong)((uint)bVar12 * (uint)bVar19) / 100);
              break;
            }
            if (cVar20 == '\x01') {
              local_e2[lVar23 + 1] = local_e2[lVar23 + 1] - (ushort)*(byte *)(lVar18 + 0x49);
            }
          }
        }
        iVar31 = iVar31 + 1;
        lVar23 = lVar23 + 1;
      } while (iVar31 < (int)uVar29);
    }
    iVar31 = *(int *)(param_1 + 0x118);
    local_234 = 1.4013e-45;
    if (1 < iVar31) {
      local_1f8 = 1;
LAB_14012fc93:
      uVar14 = 0;
      lVar16 = local_1f8 * 0x520 + *(longlong *)(param_1 + 0x110);
      uVar21 = *(uint *)(lVar16 + 0x1f0);
      if ((uVar21 >> 0xe & 1) == 0) {
        if ((*(byte *)(lVar16 + 0x236) != 0xff) || (*(char *)(lVar16 + 0x237) != -1)) {
          lVar23 = *(longlong *)
                    (*(longlong *)
                      (**(longlong **)(param_1 + 0x140) + (ulonglong)*(byte *)(lVar16 + 0x236) * 8)
                    + 0x110);
          if ((uVar21 >> 0x17 & 1) != 0) {
            uVar21 = uVar21 & 0xffffff7f;
            *(undefined2 *)(lVar16 + 0x236) = 0xffff;
            *(uint *)(lVar16 + 0x1f0) = uVar21;
            *(undefined1 *)(lVar16 + 0x249) = 0;
          }
          if ((*(byte *)((ulonglong)*(byte *)(lVar16 + 0x237) * 0x520 + lVar23 + 0x1f0) & 2) == 0) {
            *(undefined2 *)(lVar16 + 0x236) = 0xffff;
            *(uint *)(lVar16 + 0x1f0) = uVar21 & 0xffffff7f;
            *(undefined1 *)(lVar16 + 0x249) = 0;
          }
          lVar23 = *(longlong *)(lVar16 + 0x1c0);
          if (*(ushort *)(lVar23 + 0x7e) < (ushort)((ushort)*(byte *)(param_1 + 0x15f) * 0x78)) {
            *(ushort *)(lVar23 + 0x7e) = *(ushort *)(lVar23 + 0x7e) + 1;
          }
          else {
            *(undefined2 *)(lVar23 + 0x7e) = 0;
            *(uint *)(lVar16 + 0x1f0) = *(uint *)(lVar16 + 0x1f0) & 0xffffff7f;
            *(undefined2 *)(lVar16 + 0x236) = 0xffff;
            *(undefined1 *)(lVar16 + 0x249) = 0;
          }
          goto LAB_1401302f6;
        }
        if ((uint)*(byte *)(lVar16 + 0x249) < (uint)*(byte *)(lVar16 + 0x24a) * 2) {
          *(byte *)(lVar16 + 0x249) = *(byte *)(lVar16 + 0x249) + 1;
          goto LAB_1401302f6;
        }
        cVar20 = (char)uVar29;
        if (cVar20 == '\0') goto LAB_1401302f6;
        if (*(longlong *)(lVar16 + 0x360) == 0) goto LAB_1401302f6;
        auVar5 = *(undefined1 (*) [16])(*(longlong *)(lVar16 + 0x360) + 0x4a8);
        fVar47 = auVar5._0_4_ - *(float *)(lVar16 + 600);
        auVar2 = vshufps_avx(auVar5,auVar5,0x55);
        fVar50 = auVar2._0_4_ - *(float *)(lVar16 + 0x25c);
        auVar2 = vshufps_avx(auVar5,auVar5,0xaa);
        fVar42 = auVar2._0_4_ - *(float *)(lVar16 + 0x260);
        auVar5 = vshufps_avx(auVar5,auVar5,0xff);
        fVar41 = auVar5._0_4_ - *(float *)(lVar16 + 0x264);
        if ((*(byte *)((longlong)*(longlong **)(param_1 + 0x140) + 0x69) & 8) == 0) {
          fVar46 = fVar43;
        }
        else {
          fVar46 = fVar40;
        }
        if (fVar46 < fVar41 * fVar41 + fVar42 * fVar42 + fVar47 * fVar47 + fVar50 * fVar50)
        goto LAB_1401302f6;
        local_238 = 0;
        if (*(longlong *)(lVar16 + 0x1a0) == 0) goto LAB_1401302f6;
        plVar3 = *(longlong **)(*(longlong *)(lVar16 + 0x1a0) + 0x28);
        lVar23 = *(longlong *)(lVar16 + 0x1c0);
        iVar31 = (int)uVar29;
        bVar19 = SUB41(local_234,0);
        if (cVar20 != '\0') {
          uVar25 = uVar14;
          do {
            if ((abStack_eb[uVar14 - 0xd] & 0xf) == 0) {
              bVar12 = abStack_eb[uVar14 - 5];
              lVar18 = (ulonglong)bVar12 * 0x520 +
                       *(longlong *)
                        (*(longlong *)
                          (**(longlong **)(param_1 + 0x140) + (ulonglong)abStack_eb[uVar14 + 3] * 8)
                        + 0x110);
              bVar15 = *(byte *)(*(longlong *)(lVar23 + 0x68) + 0xc);
              cVar8 = '\0';
              if ((bVar15 & 1) != 0) {
                cVar8 = '\0';
                if (*(char *)(lVar18 + 0x42b) == '\x01') {
                  cVar8 = (char)local_1d8;
                }
              }
              if ((((bVar15 & 2) != 0) && (*(char *)(lVar18 + 0x42b) == '\x02')) || (cVar8 != '\0'))
              {
                *(byte *)(lVar16 + 0x236) = abStack_eb[uVar14 + 3];
                *(byte *)(lVar16 + 0x237) = bVar12;
                *(byte *)(lVar23 + 0x82) = *(byte *)(lVar23 + 0x82) | 3;
                abStack_eb[uVar14 - 0xd] = '\x01' << (bVar19 & 0x1f);
                *(undefined2 *)(lVar23 + 0x7e) = 0;
                if (0xf < uVar14 * 2) goto LAB_140132235;
                local_e2[uVar14 + 1] = 0;
                uVar14 = 0;
                local_238 = 1;
                uVar25 = 0;
                goto LAB_14012fe24;
              }
            }
            uVar21 = (int)uVar25 + 1;
            uVar25 = (ulonglong)uVar21;
            uVar14 = uVar14 + 1;
          } while ((int)uVar21 < iVar31);
        }
        uVar25 = 0;
        uVar14 = uVar25;
        if (cVar20 != '\0') {
LAB_14012fe24:
          do {
            if ((abStack_eb[uVar25 - 0xd] & 0xf) == 0) {
              bVar12 = abStack_eb[uVar25 - 5];
              bVar15 = abStack_eb[uVar25 + 3];
              lVar18 = *(longlong *)
                        (*(longlong *)(**(longlong **)(local_220 + 0x140) + (ulonglong)bVar15 * 8) +
                        0x110);
              lVar22 = *(longlong *)(lVar18 + 0x1a0 + (ulonglong)bVar12 * 0x520);
              if (lVar22 != 0) {
                bVar11 = 100;
                if (*(longlong **)(lVar22 + 0x10) != (longlong *)0x0) {
                  bVar11 = *(byte *)(**(longlong **)(lVar22 + 0x10) + 1);
                }
                if (*(short *)(lVar18 + 0x428 + (ulonglong)bVar12 * 0x520) <=
                    (short)((ulonglong)((uint)*(byte *)(*plVar3 + 0x49) * (uint)bVar11) / 100)) {
                  if ((*(undefined8 **)(lVar22 + 8) != (undefined8 *)0x0) &&
                     (*(char *)**(undefined8 **)(lVar22 + 8) == '\x01')) {
                    *(uint *)(lVar16 + 0x1f0) = *(uint *)(lVar16 + 0x1f0) | 0x80;
                  }
                  if (((bVar15 == 0xff) && (bVar12 == 0xff)) &&
                     ((*(byte *)(lVar16 + 0x236) != 0xff &&
                      (((*(char *)(lVar16 + 0x237) == -1 &&
                        ((*(uint *)(lVar16 + 0x1f8) & 0x100) != 0)) &&
                       (lVar18 = *(longlong *)
                                  (*(longlong *)
                                    (**(longlong **)(lVar16 + 0x180) +
                                    (ulonglong)*(byte *)(lVar16 + 0x236) * 8) + 0x110),
                       lVar18 != -0x51ae0)))))) {
                    *(uint *)(lVar18 + 0x51cdc) = *(uint *)(lVar18 + 0x51cdc) | 0x10;
                    *(undefined1 *)(lVar18 + 0x51d1e) = *(undefined1 *)(lVar16 + 0x234);
                    *(undefined1 *)(lVar18 + 0x51d1f) = *(undefined1 *)(lVar16 + 0x235);
                  }
                  *(byte *)(lVar16 + 0x236) = bVar15;
                  *(byte *)(lVar16 + 0x237) = bVar12;
                  *(byte *)(lVar23 + 0x82) = *(byte *)(lVar23 + 0x82) | 1;
                  abStack_eb[uVar25 - 0xd] = '\x01' << (bVar19 & 0x1f);
                  *(undefined2 *)(lVar23 + 0x7e) = 0;
                  if (0xf < uVar25 * 2) {
LAB_140132235:
                    /* WARNING: Subroutine does not return */
                    FUN_14022d904();
                  }
                  local_e2[uVar25 + 1] = 0;
                  goto LAB_1401302f1;
                }
              }
            }
            uVar21 = (int)uVar14 + 1;
            uVar14 = (ulonglong)uVar21;
            uVar25 = uVar25 + 1;
          } while ((int)uVar21 < iVar31);
        }
        uVar14 = 0;
        if (local_238 == 0) {
          uVar25 = uVar14;
          if (cVar20 != '\0') {
            do {
              if (((abStack_eb[uVar25 - 0xd] & 1) != 0) &&
                 (sVar34 = local_e2[uVar25 + 1], 0 < sVar34)) {
                bVar12 = abStack_eb[uVar25 + 3];
                bVar15 = abStack_eb[uVar25 - 5];
                lVar18 = *(longlong *)
                          (*(longlong *)
                            (*(longlong *)
                              (**(longlong **)(local_220 + 0x140) + (ulonglong)bVar12 * 8) + 0x110)
                           + 0x1a0 + (ulonglong)bVar15 * 0x520);
                if (lVar18 != 0) goto LAB_140130201;
              }
              uVar21 = (int)uVar14 + 1;
              uVar14 = (ulonglong)uVar21;
              uVar25 = uVar25 + 1;
            } while ((int)uVar21 < iVar31);
          }
          uVar14 = 0;
          uVar25 = uVar14;
          if (cVar20 != '\0') {
            do {
              sVar34 = local_e2[uVar25 + 1];
              if (0 < sVar34) {
                bVar12 = abStack_eb[uVar25 + 3];
                bVar15 = abStack_eb[uVar25 - 5];
                lVar18 = *(longlong *)
                          (*(longlong *)
                            (*(longlong *)
                              (**(longlong **)(local_220 + 0x140) + (ulonglong)bVar12 * 8) + 0x110)
                           + 0x1a0 + (ulonglong)bVar15 * 0x520);
                if (lVar18 != 0) goto LAB_140130201;
              }
              uVar21 = (int)uVar14 + 1;
              uVar14 = (ulonglong)uVar21;
              uVar25 = uVar25 + 1;
            } while ((int)uVar21 < iVar31);
          }
          lVar18 = 0;
          if (cVar20 != '\0') {
            do {
              if ((abStack_eb[lVar18 + -0xd] & 1) != 0) {
                bVar12 = abStack_eb[lVar18 + 3];
                bVar15 = abStack_eb[lVar18 + -5];
                lVar22 = *(longlong *)
                          (*(longlong *)
                            (*(longlong *)
                              (**(longlong **)(local_220 + 0x140) + (ulonglong)bVar12 * 8) + 0x110)
                           + 0x1a0 + (ulonglong)bVar15 * 0x520);
                if (lVar22 != 0) {
                  if ((*(undefined8 **)(lVar22 + 8) != (undefined8 *)0x0) &&
                     (*(char *)**(undefined8 **)(lVar22 + 8) == '\x01')) {
                    *(uint *)(lVar16 + 0x1f0) = *(uint *)(lVar16 + 0x1f0) | 0x80;
                  }
                  if ((((bVar12 == 0xff) && (bVar15 == 0xff)) && (*(byte *)(lVar16 + 0x236) != 0xff)
                      ) && (((*(char *)(lVar16 + 0x237) == -1 &&
                             ((*(uint *)(lVar16 + 0x1f8) & 0x100) != 0)) &&
                            (lVar36 = *(longlong *)
                                       (*(longlong *)
                                         (**(longlong **)(lVar16 + 0x180) +
                                         (ulonglong)*(byte *)(lVar16 + 0x236) * 8) + 0x110),
                            lVar36 != -0x51ae0)))) {
                    *(uint *)(lVar36 + 0x51cdc) = *(uint *)(lVar36 + 0x51cdc) | 0x10;
                    *(undefined1 *)(lVar36 + 0x51d1e) = *(undefined1 *)(lVar16 + 0x234);
                    *(undefined1 *)(lVar36 + 0x51d1f) = *(undefined1 *)(lVar16 + 0x235);
                  }
                  *(byte *)(lVar16 + 0x236) = bVar12;
                  *(byte *)(lVar16 + 0x237) = bVar15;
                  *(byte *)(lVar23 + 0x82) = *(byte *)(lVar23 + 0x82) | 1;
                  bVar12 = 100;
                  abStack_eb[lVar18 + -0xd] = '\x01' << (bVar19 & 0x1f);
                  *(undefined2 *)(lVar23 + 0x7e) = 0;
                  if (*(longlong **)(lVar22 + 0x10) != (longlong *)0x0) {
                    bVar12 = *(byte *)(**(longlong **)(lVar22 + 0x10) + 1);
                  }
                  local_e2[lVar18 + 1] =
                       local_e2[lVar18 + 1] -
                       (short)((ulonglong)((uint)*(byte *)(*plVar3 + 0x49) * (uint)bVar12) / 100);
                }
              }
              lVar18 = lVar18 + 1;
            } while (lVar18 < (longlong)uVar29);
            uVar29 = (ulonglong)local_237;
          }
        }
        goto LAB_1401302f1;
      }
      goto LAB_1401302f6;
    }
  }
  else if (local_238 == 1) {
    local_238 = *(byte *)((longlong)puVar24 + 0x34);
    local_200 = 0.0;
    if (local_238 != 0) {
      uVar14 = *puVar24;
      local_f8 = uVar14;
      local_218 = 0;
      do {
        local_228 = 0;
        if (0 < *(int *)(*(longlong *)(local_218 + uVar14) + 0x118)) {
          pbVar10 = (byte *)(*(longlong *)(*(longlong *)(local_218 + uVar14) + 0x110) + 0x235);
          uVar14 = local_f8;
          do {
            uVar25 = 0;
            if ((*(byte *)(**(longlong **)(pbVar10 + -0x95) + 0x73) & 4) == 0) {
              if ((*(uint *)(pbVar10 + -0x45) & 2) != 0) {
                if (((pbVar10[1] != 0xff) && (pbVar10[1] == 0)) &&
                   ((pbVar10[2] == 0 &&
                    (((*(uint *)(pbVar10 + -0x45) >> 0x10 & 1) == 0 &&
                     (*(char *)(**(longlong **)(pbVar10 + -0x95) + 0x71) != '\x03')))))) {
                  auVar5 = *(undefined1 (*) [16])(pbVar10 + 0x23);
                  fVar41 = auVar5._0_4_ - fVar43;
                  auVar2 = vshufps_avx(auVar5,auVar5,0x55);
                  fVar46 = auVar2._0_4_ - fVar40;
                  auVar2 = vshufps_avx(auVar5,auVar5,0xaa);
                  fVar38 = auVar2._0_4_ - fVar47;
                  auVar5 = vshufps_avx(auVar5,auVar5,0xff);
                  fVar44 = auVar5._0_4_ - fVar50;
                  fVar41 = SQRT(fVar44 * fVar44 +
                                fVar38 * fVar38 + fVar46 * fVar46 + fVar41 * fVar41);
                  if (fVar41 <= DAT_1402d2ae0) {
                    bVar19 = (byte)uVar29;
                    uVar14 = uVar25;
                    if (bVar19 != 0) {
LAB_140130509:
                      if (*(float *)(local_138 + uVar25 * 4) < fVar41) goto code_r0x000140130512;
                      lVar16 = uVar29 - 1;
                      if ((longlong)uVar25 <= lVar16) {
                        if ((longlong)((lVar16 - uVar25) + 1) < 4) goto LAB_140130684;
                        psVar30 = local_e2 + lVar16;
                        puVar32 = (undefined4 *)(local_138 + lVar16 * 4 + -4);
                        do {
                          if (lVar16 != 7) {
                            puVar32[2] = puVar32[1];
                            abStack_eb[lVar16 + 4] = abStack_eb[lVar16 + 3];
                            abStack_eb[lVar16 + -4] = abStack_eb[lVar16 + -5];
                            psVar30[2] = psVar30[1];
                          }
                          if (lVar16 != 8) {
                            puVar32[1] = *puVar32;
                            abStack_eb[lVar16 + 3] = abStack_eb[lVar16 + 2];
                            abStack_eb[lVar16 + -5] = abStack_eb[lVar16 + -6];
                            psVar30[1] = *psVar30;
                          }
                          if (lVar16 != 9) {
                            *puVar32 = puVar32[-1];
                            abStack_eb[lVar16 + 2] = abStack_eb[lVar16 + 1];
                            abStack_eb[lVar16 + -6] = abStack_eb[lVar16 + -7];
                            *psVar30 = psVar30[-1];
                          }
                          if (lVar16 != 10) {
                            puVar32[-1] = puVar32[-2];
                            abStack_eb[lVar16 + 1] = abStack_eb[lVar16];
                            abStack_eb[lVar16 + -7] = abStack_eb[lVar16 + -8];
                            psVar30[-1] = psVar30[-2];
                          }
                          lVar16 = lVar16 + -4;
                          puVar32 = puVar32 + -4;
                          psVar30 = psVar30 + -4;
                        } while ((longlong)(uVar25 + 3) <= lVar16);
                        for (; (longlong)uVar25 <= lVar16; lVar16 = lVar16 + -1) {
LAB_140130684:
                          if (lVar16 != 7) {
                            afStack_134[lVar16] = *(float *)(local_138 + lVar16 * 4);
                            abStack_eb[lVar16 + 4] = abStack_eb[lVar16 + 3];
                            abStack_eb[lVar16 + -4] = abStack_eb[lVar16 + -5];
                            local_e2[lVar16 + 2] = local_e2[lVar16 + 1];
                          }
                        }
                      }
                      abStack_eb[uVar25 + 3] = pbVar10[-1];
                      abStack_eb[uVar25 - 5] = *pbVar10;
                      *(float *)(local_138 + uVar25 * 4) = fVar41;
                      if (7 < (uint)uVar14) goto LAB_140132235;
                      local_e2[uVar25 + 1] = *(short *)(pbVar10 + 499);
                      if (bVar19 < 7) {
                        uVar29 = (ulonglong)(byte)(bVar19 + 1);
                      }
                      uVar14 = local_f8;
                      goto LAB_140130718;
                    }
LAB_14013051d:
                    if (bVar19 < 8) {
                      abStack_eb[uVar29 + 3] = pbVar10[-1];
                      abStack_eb[uVar29 - 5] = *pbVar10;
                      local_e2[uVar29 + 1] = *(short *)(pbVar10 + 499);
                      *(float *)(local_138 + uVar29 * 4) = fVar41;
                      uVar29 = (ulonglong)(byte)(bVar19 + 1);
                    }
                  }
                }
              }
              uVar14 = local_f8;
            }
LAB_140130718:
            pbVar10 = pbVar10 + 0x520;
            local_228 = local_228 + 1;
          } while ((int)local_228 < *(int *)(*(longlong *)(local_218 + uVar14) + 0x118));
          uVar14 = local_f8;
        }
        bVar19 = (byte)uVar29;
        local_218 = local_218 + 8;
        local_200 = (float)((int)local_200 + 1);
      } while ((int)local_200 < (int)(uint)local_238);
    }
    iVar35 = 1;
    iVar31 = *(int *)(local_220 + 0x118);
    if (1 < iVar31) {
      lVar16 = 0x520;
      do {
        lVar23 = *(longlong *)(local_220 + 0x110);
        uVar21 = *(uint *)(lVar16 + 0x1f0 + lVar23);
        if ((uVar21 >> 0xe & 1) == 0) {
          bVar12 = *(byte *)(lVar16 + 0x236 + lVar23);
          lVar18 = *(longlong *)(lVar16 + 0x1c0 + lVar23);
          if ((bVar12 == 0xff) && (*(char *)(lVar16 + 0x237 + lVar23) == -1)) {
            bVar12 = *(byte *)(lVar16 + 0x249 + lVar23);
            if ((uint)bVar12 < (uint)*(byte *)(lVar16 + 0x24a + lVar23) * 2) {
              *(byte *)(lVar16 + 0x249 + lVar23) = bVar12 + 1;
            }
            else if ((bVar19 != 0) && (lVar22 = *(longlong *)(lVar16 + 0x360 + lVar23), lVar22 != 0)
                    ) {
              auVar5 = *(undefined1 (*) [16])(lVar22 + 0x4a8);
              fVar43 = auVar5._0_4_ - *(float *)(lVar16 + 600 + lVar23);
              auVar2 = vshufps_avx(auVar5,auVar5,0x55);
              fVar40 = auVar2._0_4_ - *(float *)(lVar16 + 0x25c + lVar23);
              auVar2 = vshufps_avx(auVar5,auVar5,0xaa);
              fVar47 = auVar2._0_4_ - *(float *)(lVar16 + 0x260 + lVar23);
              auVar5 = vshufps_avx(auVar5,auVar5,0xff);
              fVar50 = auVar5._0_4_ - *(float *)(lVar16 + 0x264 + lVar23);
              if ((fVar50 * fVar50 + fVar47 * fVar47 + fVar43 * fVar43 + fVar40 * fVar40 <= fVar42)
                 && (lVar22 = *(longlong *)(lVar16 + 0x1a0 + lVar23), lVar22 != 0)) {
                plVar3 = *(longlong **)(lVar22 + 0x28);
                iVar31 = 0;
                lVar22 = 0;
                if (bVar19 != 0) {
                  do {
                    sVar34 = local_e2[lVar22 + 1];
                    if (0 < sVar34) {
                      bVar12 = abStack_eb[lVar22 + 3];
                      bVar15 = abStack_eb[lVar22 + -5];
                      lVar36 = *(longlong *)
                                (*(longlong *)
                                  (*(longlong *)
                                    (**(longlong **)(local_220 + 0x140) + (ulonglong)bVar12 * 8) +
                                  0x110) + 0x1a0 + (ulonglong)bVar15 * 0x520);
                      if ((lVar36 != 0) && (plVar3 != (longlong *)0x0)) {
                        if ((*(undefined8 **)(lVar36 + 8) != (undefined8 *)0x0) &&
                           (*(char *)**(undefined8 **)(lVar36 + 8) == '\x01')) {
                          puVar1 = (uint *)(lVar16 + 0x1f0 + lVar23);
                          *puVar1 = *puVar1 | 0x80;
                        }
                        if ((((bVar12 == 0xff) && (bVar15 == 0xff)) &&
                            (bVar11 = *(byte *)(lVar16 + 0x236 + lVar23), bVar11 != 0xff)) &&
                           (((*(char *)(lVar16 + 0x237 + lVar23) == -1 &&
                             ((*(uint *)(lVar16 + 0x1f8 + lVar23) & 0x100) != 0)) &&
                            (lVar33 = *(longlong *)
                                       (*(longlong *)
                                         (**(longlong **)(lVar16 + 0x180 + lVar23) +
                                         (ulonglong)bVar11 * 8) + 0x110), lVar33 != -0x51ae0)))) {
                          *(uint *)(lVar33 + 0x51cdc) = *(uint *)(lVar33 + 0x51cdc) | 0x10;
                          *(undefined1 *)(lVar33 + 0x51d1e) =
                               *(undefined1 *)(lVar16 + 0x234 + lVar23);
                          *(undefined1 *)(lVar33 + 0x51d1f) =
                               *(undefined1 *)(lVar16 + 0x235 + lVar23);
                        }
                        *(byte *)(lVar16 + 0x236 + lVar23) = bVar12;
                        *(byte *)(lVar16 + 0x237 + lVar23) = bVar15;
                        bVar12 = 100;
                        *(byte *)(lVar18 + 0x82) = *(byte *)(lVar18 + 0x82) | 1;
                        *(undefined2 *)(lVar18 + 0x7e) = 0;
                        if (*(longlong **)(lVar36 + 0x10) != (longlong *)0x0) {
                          bVar12 = *(byte *)(**(longlong **)(lVar36 + 0x10) + 1);
                        }
                        local_e2[lVar22 + 1] =
                             sVar34 - (short)((ulonglong)
                                              ((uint)*(byte *)(*plVar3 + 0x49) * (uint)bVar12) / 100
                                             );
                        break;
                      }
                    }
                    iVar31 = iVar31 + 1;
                    lVar22 = lVar22 + 1;
                  } while (iVar31 < (int)(uint)bVar19);
                }
              }
            }
          }
          else {
            lVar22 = *(longlong *)
                      (*(longlong *)(**(longlong **)(local_220 + 0x140) + (ulonglong)bVar12 * 8) +
                      0x110);
            if ((uVar21 >> 0x17 & 1) != 0) {
              uVar21 = uVar21 & 0xffffff7f;
              *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
              *(uint *)(lVar16 + 0x1f0 + lVar23) = uVar21;
              *(undefined1 *)(lVar16 + 0x249 + lVar23) = 0;
            }
            if ((*(byte *)((ulonglong)*(byte *)(lVar16 + 0x237 + lVar23) * 0x520 + lVar22 + 0x1f0) &
                2) == 0) {
              *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
              *(uint *)(lVar16 + 0x1f0 + lVar23) = uVar21 & 0xffffff7f;
              *(undefined1 *)(lVar16 + 0x249 + lVar23) = 0;
            }
            if (*(ushort *)(lVar18 + 0x7e) < (ushort)((ushort)*(byte *)(local_220 + 0x15f) * 0x78))
            {
              *(ushort *)(lVar18 + 0x7e) = *(ushort *)(lVar18 + 0x7e) + 1;
            }
            else {
              *(undefined2 *)(lVar18 + 0x7e) = 0;
              puVar1 = (uint *)(lVar16 + 0x1f0 + lVar23);
              *puVar1 = *puVar1 & 0xffffff7f;
              *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
              *(undefined1 *)(lVar16 + 0x249 + lVar23) = 0;
            }
          }
        }
        iVar31 = *(int *)(local_220 + 0x118);
        iVar35 = iVar35 + 1;
        lVar16 = lVar16 + 0x520;
      } while (iVar35 < iVar31);
    }
    param_1 = local_220;
  }
  else if (1 < local_238) {
    local_20c = *(byte *)((longlong)puVar24 + 0x34);
    local_228 = 1;
    if (1 < local_20c) {
      local_218 = *puVar24;
      local_237 = *(byte *)(param_1 + 0x15c);
      local_1f0 = 8;
      do {
        lVar23 = *(longlong *)(local_1f0 + local_218);
        if ((*(byte *)(lVar23 + 0x15c) != local_237) &&
           ((*(char *)(lVar23 + 0x15d) == '\x04' || (*(char *)(lVar23 + 0x15d) == '\x05')))) {
          lVar18 = (longlong)*(int *)(lVar23 + 0x118);
          local_1f8 = 0;
          if (0 < *(int *)(lVar23 + 0x118)) {
            pbVar10 = (byte *)(*(longlong *)(lVar23 + 0x110) + 0x235);
            do {
              uVar14 = 0;
              lVar23 = **(longlong **)(pbVar10 + -0x95);
              local_1e8 = lVar18;
              if ((*(byte *)(lVar23 + 0x73) & 4) == 0) {
                if (((*(uint *)(pbVar10 + -0x45) & 2) != 0) && ((pbVar10[-0x41] & 0xc) == 0)) {
                  bVar37 = false;
                  if ((*(char *)(lVar23 + 0x75) == '\0') || (*(char *)(lVar23 + 0x75) == '\x01')) {
                    bVar37 = true;
                  }
                  if (local_238 == 3) {
                    bVar37 = !bVar37;
LAB_140130bb8:
                    if (bVar37) goto LAB_140130e34;
                  }
                  else if (local_238 == 4) goto LAB_140130bb8;
                  if (((*(uint *)(pbVar10 + -0x45) >> 0x10 & 1) == 0) &&
                     (*(char *)(lVar23 + 0x71) != '\x03')) {
                    auVar5 = *(undefined1 (*) [16])(pbVar10 + 0x23);
                    fVar42 = auVar5._0_4_ - fVar43;
                    auVar2 = vshufps_avx(auVar5,auVar5,0x55);
                    fVar41 = auVar2._0_4_ - fVar40;
                    auVar2 = vshufps_avx(auVar5,auVar5,0xaa);
                    fVar46 = auVar2._0_4_ - fVar47;
                    auVar5 = vshufps_avx(auVar5,auVar5,0xff);
                    fVar38 = auVar5._0_4_ - fVar50;
                    fVar42 = SQRT(fVar38 * fVar38 +
                                  fVar46 * fVar46 + fVar42 * fVar42 + fVar41 * fVar41);
                    if (fVar42 <= DAT_1402d2ae0) {
                      bVar19 = (byte)uVar29;
                      uVar25 = uVar14;
                      if (bVar19 != 0) {
LAB_140130c2b:
                        if (fVar42 < *(float *)(local_138 + uVar14 * 4)) goto code_r0x000140130c34;
                        lVar23 = uVar29 - 1;
                        if ((longlong)uVar14 <= lVar23) {
                          if ((longlong)((lVar23 - uVar14) + 1) < 4) goto LAB_140130dac;
                          puVar32 = (undefined4 *)(local_138 + lVar23 * 4 + -4);
                          do {
                            if (lVar23 != 7) {
                              puVar32[2] = puVar32[1];
                              abStack_eb[lVar23 + 4] = abStack_eb[lVar23 + 3];
                              abStack_eb[lVar23 + -4] = abStack_eb[lVar23 + -5];
                              abStack_eb[lVar23 + -0xc] = abStack_eb[lVar23 + -0xd];
                            }
                            if (lVar23 != 8) {
                              puVar32[1] = *puVar32;
                              abStack_eb[lVar23 + 3] = abStack_eb[lVar23 + 2];
                              abStack_eb[lVar23 + -5] = abStack_eb[lVar23 + -6];
                              abStack_eb[lVar23 + -0xd] = local_108[lVar23 + 0xf];
                            }
                            if (lVar23 != 9) {
                              *puVar32 = puVar32[-1];
                              abStack_eb[lVar23 + 2] = abStack_eb[lVar23 + 1];
                              abStack_eb[lVar23 + -6] = abStack_eb[lVar23 + -7];
                              local_108[lVar23 + 0xf] = local_108[lVar23 + 0xe];
                            }
                            if (lVar23 != 10) {
                              puVar32[-1] = puVar32[-2];
                              abStack_eb[lVar23 + 1] = abStack_eb[lVar23];
                              abStack_eb[lVar23 + -7] = abStack_eb[lVar23 + -8];
                              local_108[lVar23 + 0xe] = local_108[lVar23 + 0xd];
                            }
                            lVar23 = lVar23 + -4;
                            puVar32 = puVar32 + -4;
                          } while ((longlong)(uVar14 + 3) <= lVar23);
                          for (; (longlong)uVar14 <= lVar23; lVar23 = lVar23 + -1) {
LAB_140130dac:
                            if (lVar23 != 7) {
                              afStack_134[lVar23] = *(float *)(local_138 + lVar23 * 4);
                              abStack_eb[lVar23 + 4] = abStack_eb[lVar23 + 3];
                              abStack_eb[lVar23 + -4] = abStack_eb[lVar23 + -5];
                              abStack_eb[lVar23 + -0xc] = abStack_eb[lVar23 + -0xd];
                            }
                          }
                        }
                        abStack_eb[uVar14 + 3] = pbVar10[-1];
                        abStack_eb[uVar14 - 5] = *pbVar10;
                        *(float *)(local_138 + uVar14 * 4) = fVar42;
                        if (7 < (uint)uVar25) goto LAB_140132235;
                        abStack_eb[uVar14 - 0xd] = 0;
                        if (bVar19 < 7) {
                          uVar29 = (ulonglong)(byte)(bVar19 + 1);
                        }
                        goto LAB_140130e34;
                      }
LAB_140130c3f:
                      if (bVar19 < 8) {
                        abStack_eb[uVar29 + 3] = pbVar10[-1];
                        abStack_eb[uVar29 - 5] = *pbVar10;
                        *(float *)(local_138 + uVar29 * 4) = fVar42;
                        abStack_eb[uVar29 - 0xd] = 0;
                        uVar29 = (ulonglong)(byte)(bVar19 + 1);
                      }
                    }
                  }
                }
              }
LAB_140130e34:
              pbVar10 = pbVar10 + 0x520;
              local_1f8 = local_1f8 + 1;
            } while (local_1f8 < lVar18);
          }
        }
        bVar19 = (byte)uVar29;
        local_228 = local_228 + 1;
        local_1f0 = local_1f0 + 8;
      } while ((int)local_228 < (int)(uint)local_20c);
      param_1 = local_220;
    }
    iVar31 = 0;
    if (bVar19 != 0) {
      bVar12 = *(byte *)(lVar16 + 0x236);
      lVar23 = 0;
      plVar3 = *(longlong **)(param_1 + 0x140);
      do {
        if ((abStack_eb[lVar23 + 3] == bVar12) &&
           (abStack_eb[lVar23 + -5] == *(byte *)(lVar16 + 0x237))) {
          abStack_eb[lVar23 + -0xd] = 1;
          if ((*(longlong *)
                (*(longlong *)
                  (*(longlong *)(*plVar3 + (ulonglong)abStack_eb[lVar23 + 3] * 8) + 0x110) + 0x1a0 +
                (ulonglong)abStack_eb[lVar23 + -5] * 0x520) == 0) ||
             (*(longlong *)(lVar16 + 0x1a0) == 0)) break;
          if (*(longlong *)(*(longlong *)(lVar16 + 0x1b8) + 0x1fb8) != 0) {
            abStack_eb[(longlong)iVar31 + -0xd] = 1;
            break;
          }
        }
        iVar31 = iVar31 + 1;
        lVar23 = lVar23 + 1;
      } while (iVar31 < (int)(uint)bVar19);
    }
    iVar31 = *(int *)(param_1 + 0x118);
    iVar35 = 1;
    if (1 < iVar31) {
      lVar16 = 0x520;
      do {
        lVar23 = *(longlong *)(param_1 + 0x110);
        uVar21 = *(uint *)(lVar16 + 0x1f0 + lVar23);
        if ((uVar21 >> 0xe & 1) == 0) {
          bVar12 = *(byte *)(lVar16 + 0x236 + lVar23);
          lVar18 = *(longlong *)(lVar16 + 0x1c0 + lVar23);
          if ((bVar12 == 0xff) && (*(char *)(lVar16 + 0x237 + lVar23) == -1)) {
            bVar12 = *(byte *)(lVar16 + 0x249 + lVar23);
            if ((uint)bVar12 < (uint)*(byte *)(lVar16 + 0x24a + lVar23) * 2) {
              *(byte *)(lVar16 + 0x249 + lVar23) = bVar12 + 1;
            }
            else if (((bVar19 != 0) && (*(longlong *)(lVar16 + 0x360 + lVar23) != 0)) &&
                    (lVar22 = *(longlong *)(lVar16 + 0x1a0 + lVar23), lVar22 != 0)) {
              iVar31 = 0;
              lVar36 = 0;
              if (bVar19 != 0) {
                do {
                  if (((abStack_eb[lVar36 + -0xd] & 0xf) == 0) || (bVar19 < 2)) {
                    bVar12 = abStack_eb[lVar36 + 3];
                    bVar15 = abStack_eb[lVar36 + -5];
                    lVar33 = *(longlong *)
                              (*(longlong *)
                                (*(longlong *)
                                  (**(longlong **)(param_1 + 0x140) + (ulonglong)bVar12 * 8) + 0x110
                                ) + 0x1a0 + (ulonglong)bVar15 * 0x520);
                    if ((lVar33 != 0) && (*(longlong *)(lVar22 + 0x28) != 0)) {
                      puVar4 = *(undefined8 **)(lVar33 + 8);
                      if ((puVar4 != (undefined8 *)0x0) && (*(char *)*puVar4 == '\x01')) {
                        puVar1 = (uint *)(lVar16 + 0x1f0 + lVar23);
                        *puVar1 = *puVar1 | 0x80;
                      }
                      if (((((bVar12 == 0xff) && (bVar15 == 0xff)) &&
                           (bVar11 = *(byte *)(lVar16 + 0x236 + lVar23), bVar11 != 0xff)) &&
                          ((*(char *)(lVar16 + 0x237 + lVar23) == -1 &&
                           ((*(uint *)(lVar16 + 0x1f8 + lVar23) & 0x100) != 0)))) &&
                         (lVar22 = *(longlong *)
                                    (*(longlong *)
                                      (**(longlong **)(lVar16 + 0x180 + lVar23) +
                                      (ulonglong)bVar11 * 8) + 0x110), lVar22 != -0x51ae0)) {
                        *(uint *)(lVar22 + 0x51cdc) = *(uint *)(lVar22 + 0x51cdc) | 0x10;
                        *(undefined1 *)(lVar22 + 0x51d1e) = *(undefined1 *)(lVar16 + 0x234 + lVar23)
                        ;
                        *(undefined1 *)(lVar22 + 0x51d1f) = *(undefined1 *)(lVar16 + 0x235 + lVar23)
                        ;
                      }
                      *(byte *)(lVar16 + 0x236 + lVar23) = bVar12;
                      *(byte *)(lVar16 + 0x237 + lVar23) = bVar15;
                      *(byte *)(lVar18 + 0x82) = *(byte *)(lVar18 + 0x82) | 1;
                      abStack_eb[lVar36 + -0xd] = '\x01' << ((byte)iVar35 & 0x1f);
                      *(undefined2 *)(lVar18 + 0x7e) = 0;
                      break;
                    }
                  }
                  iVar31 = iVar31 + 1;
                  lVar36 = lVar36 + 1;
                } while (iVar31 < (int)(uint)bVar19);
              }
            }
          }
          else {
            lVar22 = *(longlong *)
                      (*(longlong *)(**(longlong **)(param_1 + 0x140) + (ulonglong)bVar12 * 8) +
                      0x110);
            if (((uVar21 >> 0x17 & 1) != 0) && (*(short *)(lVar18 + 0x86) == 0)) {
              uVar21 = uVar21 & 0xffffff7f;
              *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
              *(uint *)(lVar16 + 0x1f0 + lVar23) = uVar21;
              *(undefined1 *)(lVar16 + 0x249 + lVar23) = 0;
            }
            if ((*(byte *)((ulonglong)*(byte *)(lVar16 + 0x237 + lVar23) * 0x520 + lVar22 + 0x1f0) &
                2) == 0) {
              *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
              *(uint *)(lVar16 + 0x1f0 + lVar23) = uVar21 & 0xffffff7f;
              *(undefined1 *)(lVar16 + 0x249 + lVar23) = 0;
            }
            if (*(ushort *)(lVar18 + 0x7e) < (ushort)((ushort)*(byte *)(param_1 + 0x15f) * 0x78)) {
              *(ushort *)(lVar18 + 0x7e) = *(ushort *)(lVar18 + 0x7e) + 1;
            }
            else {
              *(undefined2 *)(lVar18 + 0x7e) = 0;
              puVar1 = (uint *)(lVar16 + 0x1f0 + lVar23);
              *puVar1 = *puVar1 & 0xffffff7f;
              *(undefined2 *)(lVar16 + 0x236 + lVar23) = 0xffff;
              *(undefined1 *)(lVar16 + 0x249 + lVar23) = 0;
            }
          }
        }
        iVar31 = *(int *)(param_1 + 0x118);
        iVar35 = iVar35 + 1;
        lVar16 = lVar16 + 0x520;
      } while (iVar35 < iVar31);
    }
  }
LAB_1401311db:
  if ((*(byte *)(param_1 + 0x120) & 0x10) == 0) {
    local_234 = 1.4013e-45;
    auVar52 = ZEXT1664(auVar51);
    if (1 < iVar31) {
      lVar16 = 0x520;
      do {
        lVar23 = *(longlong *)(param_1 + 0x110) + lVar16;
        if (((*(uint *)(lVar23 + 0x1f0) & 0x4000) != 0) &&
           ((*(byte *)(*(longlong *)(lVar23 + 0x10) + 0xa8) & 0x80) != 0)) {
          plVar3 = *(longlong **)(param_1 + 0x140);
          local_188 = auVar51._0_4_;
          local_180 = local_188;
          local_178 = local_188;
          local_170 = local_188;
          local_168 = local_188;
          local_160 = local_188;
          local_158 = local_188;
          local_150 = local_188;
          local_184 = 0xffff;
          uVar29 = 0;
          uStack_17c = 0xffff;
          iVar31 = 0;
          local_174 = 0xffff;
          local_16c = 0xffff;
          local_164 = 0xffff;
          local_15c = 0xffff;
          local_154 = 0xffff;
          local_14c = 0xffff;
          auVar5 = vmaxss_avx(ZEXT416(*(uint *)(*(longlong *)(lVar23 + 0x10) + 0x94)),auVar52._0_16_
                             );
          auVar52 = ZEXT1664(auVar5);
          if (*(char *)((longlong)plVar3 + 0x34) != '\0') {
            uVar21 = *(uint *)(param_1 + 0x120);
            lVar18 = 0;
            do {
              lVar22 = *plVar3;
              if ((uVar21 & 2) != 0) {
                lVar36 = *(longlong *)(lVar18 + lVar22);
                if ((*(byte *)(param_1 + 0x15d) != *(byte *)(lVar36 + 0x15d)) &&
                   (2 < *(byte *)(lVar36 + 0x15d))) {
                  iVar35 = 0;
                  if (0 < *(int *)(lVar36 + 0x118)) {
                    lVar33 = 0;
                    do {
                      lVar27 = *(longlong *)(lVar36 + 0x110);
                      if ((*(byte *)(lVar27 + 0x1f0 + lVar33) & 2) != 0) {
                        auVar2 = *(undefined1 (*) [16])(lVar27 + 600 + lVar33);
                        fVar43 = auVar2._0_4_ - *(float *)(lVar23 + 600);
                        auVar6 = vshufps_avx(auVar2,auVar2,0x55);
                        fVar40 = auVar6._0_4_ - *(float *)(lVar23 + 0x25c);
                        auVar6 = vshufps_avx(auVar2,auVar2,0xaa);
                        fVar47 = auVar6._0_4_ - *(float *)(lVar23 + 0x260);
                        auVar2 = vshufps_avx(auVar2,auVar2,0xff);
                        fVar50 = auVar2._0_4_ - *(float *)(lVar23 + 0x264);
                        fVar43 = SQRT(fVar50 * fVar50 +
                                      fVar47 * fVar47 + fVar43 * fVar43 + fVar40 * fVar40);
                        if (fVar43 < auVar5._0_4_) {
                          lVar26 = 0;
                          iVar9 = 0;
                          local_218 = (ulonglong)
                                      CONCAT34(CONCAT12(*(undefined1 *)(lVar36 + 0x15d),
                                                        CONCAT11(*(undefined1 *)
                                                                  (lVar27 + 0x235 + lVar33),
                                                                 *(undefined1 *)
                                                                  (lVar27 + 0x234 + lVar33))),fVar43
                                              );
                          iVar13 = (int)uVar29;
                          if (0 < iVar13) {
LAB_1401313c0:
                            if (*(float *)(local_138 + lVar26 * 8 + -0x50) <= fVar43)
                            goto code_r0x0001401313cd;
                            for (lVar36 = (longlong)(iVar13 + -1); lVar26 < lVar36;
                                lVar36 = lVar36 + -1) {
                              *(undefined8 *)(local_138 + lVar36 * 8 + -0x50) =
                                   *(undefined8 *)(local_198 + lVar36 * 8 + 8);
                            }
                            *(ulonglong *)(local_138 + lVar26 * 8 + -0x50) = local_218;
                            uVar29 = (ulonglong)local_14c._4_4_;
                            if (local_14c._4_4_ < 8) {
                              *(undefined8 *)(local_138 + uVar29 * 8 + -0x50) =
                                   *(undefined8 *)
                                    (local_138 + (longlong)(local_14c._4_4_ + -1) * 8 + -0x50);
                              goto LAB_1401313e8;
                            }
                            goto LAB_1401313f0;
                          }
LAB_1401313d6:
                          if (iVar13 < 8) {
                            *(ulonglong *)(local_138 + (longlong)iVar13 * 8 + -0x50) = local_218;
LAB_1401313e8:
                            uVar29 = (ulonglong)(local_14c._4_4_ + 1U);
                            local_14c = CONCAT44(local_14c._4_4_ + 1U,(undefined4)local_14c);
                          }
                        }
                      }
LAB_1401313f0:
                      lVar36 = *(longlong *)(lVar18 + lVar22);
                      iVar35 = iVar35 + 1;
                      lVar33 = lVar33 + 0x520;
                    } while (iVar35 < *(int *)(lVar36 + 0x118));
                    param_1 = local_220;
                  }
                }
              }
              iVar31 = iVar31 + 1;
              lVar18 = lVar18 + 8;
            } while (iVar31 < (int)(uint)*(byte *)((longlong)plVar3 + 0x34));
          }
          bVar19 = *(byte *)(lVar23 + 0x236);
          lVar18 = *(longlong *)(lVar23 + 0x10);
          lVar22 = **(longlong **)(lVar23 + 0x1a0);
          iVar31 = (int)uVar29;
          if ((bVar19 == 0xff) && (*(char *)(lVar23 + 0x237) == -1)) {
            bVar19 = *(byte *)(lVar18 + 0xb6);
            if (bVar19 != 0xff) {
              bVar12 = *(byte *)(lVar18 + 0xb7);
              uVar29 = (ulonglong)bVar19;
              lVar36 = *plVar3;
              if (bVar12 == 0xff) {
                iVar35 = 0;
                if (0 < iVar31) {
                  pfVar28 = &local_188;
                  do {
                    bVar12 = *(byte *)(pfVar28 + 1);
                    if ((bVar12 == bVar19) &&
                       ((*(char *)(lVar23 + 0x234) == '\0' ||
                        (*pfVar28 <= *(float *)(lVar22 + 0x44))))) {
                      cVar20 = *(char *)((longlong)pfVar28 + 5);
                      if ((bVar12 == 0xff) &&
                         ((((cVar20 == -1 && (*(byte *)(lVar23 + 0x236) != 0xff)) &&
                           (*(char *)(lVar23 + 0x237) == -1)) &&
                          (((*(uint *)(lVar23 + 0x1f8) & 0x100) != 0 &&
                           (lVar18 = *(longlong *)
                                      (*(longlong *)
                                        (**(longlong **)(lVar23 + 0x180) +
                                        (ulonglong)*(byte *)(lVar23 + 0x236) * 8) + 0x110),
                           lVar18 != -0x51ae0)))))) {
                        *(uint *)(lVar18 + 0x51cdc) = *(uint *)(lVar18 + 0x51cdc) | 0x10;
                        *(undefined1 *)(lVar18 + 0x51d1e) = *(undefined1 *)(lVar23 + 0x234);
                        *(undefined1 *)(lVar18 + 0x51d1f) = *(undefined1 *)(lVar23 + 0x235);
                      }
                      *(uint *)(lVar23 + 0x1f0) = *(uint *)(lVar23 + 0x1f0) | 8;
                      *(byte *)(lVar23 + 0x236) = bVar12;
                      *(char *)(lVar23 + 0x237) = cVar20;
                      goto LAB_140131708;
                    }
                    iVar35 = iVar35 + 1;
                    pfVar28 = pfVar28 + 2;
                  } while (iVar35 < iVar31);
                }
              }
              else {
                lVar27 = (ulonglong)bVar12 * 0x520;
                lVar33 = *(longlong *)(*(longlong *)(lVar36 + (ulonglong)bVar19 * 8) + 0x110);
                if ((*(byte *)(lVar27 + 0x1f0 + lVar33) & 2) != 0) {
                  auVar5 = *(undefined1 (*) [16])(lVar23 + 600);
                  fVar43 = auVar5._0_4_ - *(float *)(lVar27 + 600 + lVar33);
                  auVar2 = vshufps_avx(auVar5,auVar5,0xaa);
                  fVar40 = auVar2._0_4_ - *(float *)(lVar27 + 0x260 + lVar33);
                  auVar2 = vshufps_avx(auVar5,auVar5,0x55);
                  fVar47 = auVar2._0_4_ - *(float *)(lVar27 + 0x25c + lVar33);
                  auVar5 = vshufps_avx(auVar5,auVar5,0xff);
                  fVar50 = auVar5._0_4_ - *(float *)(lVar27 + 0x264 + lVar33);
                  bVar37 = *(float *)(lVar18 + 0x94) <=
                           SQRT(fVar50 * fVar50 +
                                fVar40 * fVar40 + fVar47 * fVar47 + fVar43 * fVar43);
                  if (bVar37) {
                    bVar12 = 0xff;
                    bVar19 = 0xff;
                  }
                  *(byte *)(lVar23 + 0x236) = bVar19;
                  *(byte *)(lVar23 + 0x237) = bVar12;
                  uVar14 = 0;
                  lVar36 = *(longlong *)(lVar36 + uVar29 * 8);
                  iVar31 = *(int *)(lVar36 + 0x118);
                  if (0 < iVar31) {
                    do {
                      if ((*(byte *)(uVar14 * 0x520 + 0x1f0 + *(longlong *)(lVar36 + 0x110)) & 2) !=
                          0) {
                        cVar20 = *(char *)(lVar18 + 0xb6);
                        if (((cVar20 == -1) && ((char)uVar14 == -1)) &&
                           ((*(byte *)(lVar23 + 0x236) != 0xff &&
                            (((bVar12 == 0xff && ((*(uint *)(lVar23 + 0x1f8) & 0x100) != 0)) &&
                             (lVar18 = *(longlong *)
                                        (*(longlong *)
                                          (**(longlong **)(lVar23 + 0x180) +
                                          (ulonglong)*(byte *)(lVar23 + 0x236) * 8) + 0x110),
                             lVar18 != -0x51ae0)))))) {
                          *(uint *)(lVar18 + 0x51cdc) = *(uint *)(lVar18 + 0x51cdc) | 0x10;
                          *(undefined1 *)(lVar18 + 0x51d1e) = *(undefined1 *)(lVar23 + 0x234);
                          *(undefined1 *)(lVar18 + 0x51d1f) = *(undefined1 *)(lVar23 + 0x235);
                        }
                        *(char *)(lVar23 + 0x236) = cVar20;
                        *(char *)(lVar23 + 0x237) = (char)uVar14;
                        goto LAB_1401318a6;
                      }
                      uVar21 = (int)uVar14 + 1;
                      uVar14 = (ulonglong)uVar21;
                    } while ((int)uVar21 < iVar31);
                  }
                  if (!bVar37) goto LAB_1401318a6;
LAB_140131708:
                  iVar31 = local_14c._4_4_;
                }
              }
            }
            iVar35 = 0;
            if (0 < iVar31) {
              pfVar28 = &local_188;
              do {
                if ((*pfVar28 <= *(float *)(lVar22 + 0x44)) &&
                   ((*(uint *)(lVar23 + 0x1f0) & 0x10000) == 0)) {
                  bVar19 = *(byte *)(pfVar28 + 1);
                  bVar12 = *(byte *)((longlong)pfVar28 + 5);
                  if ((*(byte *)(**(longlong **)
                                   (*(longlong *)
                                     (*(longlong *)
                                       (**(longlong **)(param_1 + 0x140) + (ulonglong)bVar19 * 8) +
                                     0x110) + 0x1a0 + (ulonglong)bVar12 * 0x520) + 0x73) & 4) == 0)
                  {
                    if (((bVar19 == 0xff) && (bVar12 == 0xff)) &&
                       ((*(byte *)(lVar23 + 0x236) != 0xff &&
                        (((*(char *)(lVar23 + 0x237) == -1 &&
                          ((*(uint *)(lVar23 + 0x1f8) & 0x100) != 0)) &&
                         (lVar18 = *(longlong *)
                                    (*(longlong *)
                                      (**(longlong **)(lVar23 + 0x180) +
                                      (ulonglong)*(byte *)(lVar23 + 0x236) * 8) + 0x110),
                         lVar18 != -0x51ae0)))))) {
                      *(uint *)(lVar18 + 0x51cdc) = *(uint *)(lVar18 + 0x51cdc) | 0x10;
                      *(undefined1 *)(lVar18 + 0x51d1e) = *(undefined1 *)(lVar23 + 0x234);
                      *(undefined1 *)(lVar18 + 0x51d1f) = *(undefined1 *)(lVar23 + 0x235);
                    }
                    *(uint *)(lVar23 + 0x1f0) = *(uint *)(lVar23 + 0x1f0) | 8;
                    *(byte *)(lVar23 + 0x236) = bVar19;
                    *(byte *)(lVar23 + 0x237) = bVar12;
                    break;
                  }
                }
                iVar35 = iVar35 + 1;
                pfVar28 = pfVar28 + 2;
              } while (iVar35 < iVar31);
            }
          }
          else if ((*(byte *)(*(longlong *)(*(longlong *)(*plVar3 + (ulonglong)bVar19 * 8) + 0x110)
                              + 0x1f0 + (ulonglong)*(byte *)(lVar23 + 0x237) * 0x520) & 2) == 0) {
            *(uint *)(lVar23 + 0x1f0) = *(uint *)(lVar23 + 0x1f0) & 0xffffff77;
            *(undefined2 *)(lVar23 + 0x236) = 0xffff;
            *(undefined1 *)(lVar23 + 0x249) = 0;
          }
          else if (*(byte *)(lVar18 + 0xb6) != bVar19) {
            bVar7 = false;
            bVar37 = false;
            if (0 < iVar31) {
              pbVar10 = (byte *)((longlong)&local_184 + 1);
              uVar29 = uVar29 & 0xffffffff;
              do {
                if (pbVar10[-1] == bVar19) {
                  bVar37 = bVar7;
                  if (*pbVar10 == *(byte *)(lVar23 + 0x237)) {
                    bVar37 = true;
                    bVar7 = true;
                  }
                }
                pbVar10 = pbVar10 + 8;
                uVar29 = uVar29 - 1;
              } while (uVar29 != 0);
              if (bVar37) goto LAB_1401318a6;
            }
            *(uint *)(lVar23 + 0x1f0) = *(uint *)(lVar23 + 0x1f0) & 0xffffff77;
            *(undefined2 *)(lVar23 + 0x236) = 0xffff;
            *(undefined1 *)(lVar23 + 0x249) = 0;
          }
        }
LAB_1401318a6:
        iVar31 = *(int *)(param_1 + 0x118);
        local_234 = (float)((int)local_234 + 1);
        lVar16 = lVar16 + 0x520;
      } while ((int)local_234 < iVar31);
    }
  }
  if (1 < iVar31) {
    auVar52 = ZEXT464(DAT_1402d2504);
    lVar23 = 0x520;
    local_228 = DAT_1402d2504;
    lVar16 = local_220;
    fVar50 = DAT_1402d2a04;
    fVar40 = DAT_1402d2a54;
    fVar47 = DAT_1402d2c14;
    fVar43 = DAT_1402d291c;
    fVar42 = DAT_1402d2aac;
    fVar41 = DAT_1402d2eb8;
    do {
      lVar22 = local_1e0;
      lVar36 = *(longlong *)(lVar16 + 0x110) + lVar23;
      lVar18 = *(longlong *)(lVar36 + 0x360);
      pfVar28 = (float *)**(undefined8 **)(lVar36 + 0x1a8);
      if (lVar18 != 0) {
        *(undefined2 *)(lVar18 + 0x4cd) = 0;
        if (((*(byte *)(lVar36 + 0x236) == 0xff) && (*(char *)(lVar36 + 0x237) == -1)) ||
           ((*(uint *)(lVar36 + 0x1f0) & 0x2003) != 3)) {
          if ((*(uint *)(lVar36 + 0x1f0) & 0x4000) == 0) {
            auVar51 = *(undefined1 (*) [16])(lVar36 + 600);
            fVar44 = auVar51._0_4_ - local_230;
            fVar43 = *pfVar28;
            fVar40 = pfVar28[1];
            fVar47 = pfVar28[2];
            _local_138 = ZEXT816(0);
            auVar5 = vshufps_avx(auVar51,auVar51,0x55);
            fVar39 = auVar5._0_4_ - local_22c;
            _local_128 = ZEXT816(0);
            auVar5 = vshufps_avx(auVar51,auVar51,0xaa);
            fVar48 = auVar5._0_4_ - local_208;
            auVar51 = vshufps_avx(auVar51,auVar51,0xff);
            fVar49 = auVar51._0_4_ - local_204;
            local_200 = SQRT(fVar49 * fVar49 + fVar48 * fVar48 + fVar44 * fVar44 + fVar39 * fVar39);
            auVar51 = vcmpss_avx(ZEXT416((uint)local_200),
                                 ZEXT416((uint)(*(float *)(lVar36 + 0x410) +
                                               *(float *)(local_1e0 + 0x410))),1);
            auVar51 = vblendvps_avx(ZEXT416((uint)local_210),auVar52._0_16_,auVar51);
            auVar5 = vpcmpeqd_avx(ZEXT116(*(byte *)(*(longlong *)(lVar16 + 0x140) + 0x68)),
                                  SUB6416(ZEXT464(2),0));
            auVar51 = vblendvps_avx(auVar51,auVar52._0_16_,auVar5);
            auVar52 = ZEXT1664(auVar51);
            _local_118 = _local_138;
            _local_108 = _local_128;
            FUN_140202920(local_138,param_1 + 0x18);
            fVar45 = auVar52._0_4_;
            fVar50 = fVar45 * (float)local_118._4_4_ * fVar47 +
                     fVar45 * afStack_134[0] * fVar43 + fVar45 * (float)local_128._4_4_ * fVar40 +
                     (float)local_108._4_4_ * fVar45 + *(float *)(lVar16 + 0xc);
            fVar46 = fVar45 * (float)local_118._0_4_ * fVar47 +
                     fVar45 * (float)local_128._0_4_ * fVar40 + fVar45 * (float)local_138 * fVar43 +
                     fVar45 * (float)local_108._0_4_ + *(float *)(lVar16 + 8);
            fVar38 = fVar45 * fStack_110 * fVar47 +
                     fVar45 * afStack_134[1] * fVar43 + fVar45 * fStack_120 * fVar40 +
                     fVar45 * fStack_100 + *(float *)(lVar16 + 0x10);
            local_e8 = fStack_10c * fVar45 * fVar47 +
                       fVar45 * afStack_134[2] * fVar43 + fVar45 * fStack_11c * fVar40 +
                       uStack_fc * fVar45;
            auVar51 = vpcmpeqd_avx(ZEXT416(*(uint *)(lVar22 + 0x1f0) & 2),SUB6416(ZEXT464(0),0));
            auVar51 = vblendvps_avx(ZEXT416((uint)fVar50),ZEXT416((uint)(fVar50 + DAT_1402d2a54)),
                                    auVar51);
            if (local_200 != DAT_1402d1cf8) {
              fVar43 = local_210 / local_200;
              fVar44 = fVar43 * fVar44;
              fVar39 = fVar43 * fVar39;
              fVar48 = fVar43 * fVar48;
              fVar49 = fVar43 * fVar49;
            }
            auVar52 = ZEXT1664(auVar51);
            if ((DAT_1402d2a54 < local_200) &&
               (DAT_1402d2cfc <
                (uStack_fc * fVar49 + fVar48 * fStack_100 +
                (float)local_108._4_4_ * fVar39 + fVar44 * (float)local_108._0_4_) -
                (fStack_10c * fVar49 + fVar48 * fStack_110 +
                fVar39 * (float)local_118._4_4_ + fVar44 * (float)local_118._0_4_))) {
              auVar52 = ZEXT464((uint)(auVar51._0_4_ + DAT_1402d2a04));
            }
            fVar50 = DAT_1402d2a04;
            local_234 = fVar38;
            local_f0 = fVar46;
            fVar44 = (float)FUN_140079410(*(undefined8 *)(lVar16 + 0x148),fVar46,fVar38);
            fVar47 = DAT_1402d2c14;
            fVar40 = DAT_1402d2a54;
            fVar43 = DAT_1402d291c;
            fVar44 = fVar44 + DAT_1402d2998;
            *(float *)(lVar18 + 0x4a8) = fVar46;
            *(float *)(lVar18 + 0x4b0) = fVar38;
            *(float *)(lVar18 + 0x4b4) = local_e8;
            auVar51 = vmaxss_avx(ZEXT416((uint)fVar44),auVar52._0_16_);
            *(int *)(lVar18 + 0x4ac) = auVar51._0_4_;
            *(undefined4 *)(lVar18 + 0x4b8) = *(undefined4 *)(param_1 + 0x18);
            *(undefined4 *)(lVar18 + 0x4bc) = *(undefined4 *)(lVar16 + 0x1c);
            *(undefined4 *)(lVar18 + 0x4c0) = *(undefined4 *)(lVar16 + 0x20);
            *(undefined4 *)(lVar18 + 0x4c4) = *(undefined4 *)(lVar16 + 0x24);
            *(undefined4 *)(lVar36 + 0x218) =
                 *(undefined4 *)(*(longlong *)(lVar22 + 0x1b8) + 0x1848);
          }
          else {
            puVar32 = *(undefined4 **)(lVar36 + 0x10);
            *(undefined4 *)(lVar18 + 0x4a8) = *puVar32;
            *(undefined4 *)(lVar18 + 0x4ac) = puVar32[1];
            *(undefined4 *)(lVar18 + 0x4b0) = puVar32[2];
            *(undefined4 *)(lVar18 + 0x4b4) = puVar32[3];
            lVar22 = *(longlong *)(lVar36 + 0x10);
            *(undefined4 *)(lVar18 + 0x4b8) = *(undefined4 *)(lVar22 + 0x10);
            *(undefined4 *)(lVar18 + 0x4bc) = *(undefined4 *)(lVar22 + 0x14);
            *(undefined4 *)(lVar18 + 0x4c0) = *(undefined4 *)(lVar22 + 0x18);
            *(undefined4 *)(lVar18 + 0x4c4) = *(undefined4 *)(lVar22 + 0x1c);
          }
        }
        else {
          lVar22 = *(longlong *)
                    (*(longlong *)
                      (**(longlong **)(lVar16 + 0x140) + (ulonglong)*(byte *)(lVar36 + 0x236) * 8) +
                    0x110) + (ulonglong)*(byte *)(lVar36 + 0x237) * 0x520;
          if (((*(longlong **)(lVar22 + 0x1a0) == (longlong *)0x0) ||
              (lVar33 = **(longlong **)(lVar22 + 0x1a0), lVar33 == 0)) ||
             ((cVar20 = *(char *)(lVar33 + 0x75), cVar20 != '\0' && (cVar20 != '\x01')))) {
            auVar51 = *(undefined1 (*) [16])(lVar22 + 600);
            fVar46 = auVar51._0_4_ - *(float *)(lVar36 + 600);
            auVar5 = vshufps_avx(auVar51,auVar51,0x55);
            fVar50 = auVar5._0_4_ - *(float *)(lVar36 + 0x25c);
            auVar5 = vshufps_avx(auVar51,auVar51,0xaa);
            fVar38 = auVar5._0_4_ - *(float *)(lVar36 + 0x260);
            auVar51 = vshufps_avx(auVar51,auVar51,0xff);
            fVar44 = auVar51._0_4_ - *(float *)(lVar36 + 0x264);
            fVar39 = fVar44 * fVar44 + fVar38 * fVar38 + fVar46 * fVar46 + fVar50 * fVar50;
            if (SQRT(fVar39) != DAT_1402d1cf8) {
              fVar48 = local_210 / SQRT(fVar39);
              fVar50 = fVar48 * fVar50;
              fVar46 = fVar48 * fVar46;
              fVar38 = fVar48 * fVar38;
              fVar44 = fVar48 * fVar44;
            }
            _local_128 = ZEXT816(0);
            _local_138 = ZEXT816(0);
            _local_118 = ZEXT816(0);
            _local_108 = _local_128;
            FUN_140202920(local_138,lVar36 + 0x268);
            fVar48 = fVar44 * (uStack_fc - fStack_10c) +
                     fVar38 * (fStack_100 - fStack_110) +
                     fVar50 * ((float)local_108._4_4_ - (float)local_118._4_4_) +
                     ((float)local_108._0_4_ - (float)local_118._0_4_) * fVar46;
            if (DAT_1402d2bf4 <= fVar39) {
              if ((fVar39 < fVar47) && (fVar48 < DAT_1402d1cf8)) goto LAB_140131fb9;
              *(undefined4 *)(lVar18 + 0x4a8) = *(undefined4 *)(lVar22 + 600);
              fVar50 = *(float *)(lVar22 + 0x25c);
              *(float *)(lVar18 + 0x4ac) = fVar50;
              *(undefined4 *)(lVar18 + 0x4b0) = *(undefined4 *)(lVar22 + 0x260);
              *(undefined4 *)(lVar18 + 0x4b4) = *(undefined4 *)(lVar22 + 0x264);
              *(undefined4 *)(lVar18 + 0x4b8) = *(undefined4 *)(lVar22 + 0x268);
              *(undefined4 *)(lVar18 + 0x4bc) = *(undefined4 *)(lVar22 + 0x26c);
              *(undefined4 *)(lVar18 + 0x4c0) = *(undefined4 *)(lVar22 + 0x270);
              *(undefined4 *)(lVar18 + 0x4c4) = *(undefined4 *)(lVar22 + 0x274);
              fVar50 = fVar50 + fVar43;
            }
            else {
              if (fVar48 < DAT_1402d1cf8) {
LAB_140131fb9:
                fVar39 = fVar41;
              }
              else {
                fVar39 = fVar42;
              }
              auVar51 = *(undefined1 (*) [16])(lVar22 + 600);
              *(float *)(lVar18 + 0x4a8) = auVar51._0_4_ + fVar46 * fVar39;
              auVar5 = vshufps_avx(auVar51,auVar51,0x55);
              auVar2 = vshufps_avx(auVar51,auVar51,0xaa);
              *(float *)(lVar18 + 0x4ac) = auVar5._0_4_ + fVar50 * fVar39;
              *(float *)(lVar18 + 0x4b0) = auVar2._0_4_ + fVar38 * fVar39;
              auVar51 = vshufps_avx(auVar51,auVar51,0xff);
              *(float *)(lVar18 + 0x4b4) = auVar51._0_4_ + fVar44 * fVar39;
              *(undefined4 *)(lVar18 + 0x4b8) = *(undefined4 *)(lVar22 + 0x268);
              *(undefined4 *)(lVar18 + 0x4bc) = *(undefined4 *)(lVar22 + 0x26c);
              *(undefined4 *)(lVar18 + 0x4c0) = *(undefined4 *)(lVar22 + 0x270);
              *(undefined4 *)(lVar18 + 0x4c4) = *(undefined4 *)(lVar22 + 0x274);
              fVar50 = fVar40 + *(float *)(lVar22 + 0x25c);
            }
            *(float *)(lVar18 + 0x4ac) = fVar50;
            *(uint *)(lVar36 + 0x1f0) = *(uint *)(lVar36 + 0x1f0) | 0x80;
            fVar50 = DAT_1402d2a04;
          }
          else {
            bVar19 = *(byte *)(lVar22 + 0x42d);
            local_1c8 = ZEXT816(0);
            _local_1b8 = ZEXT816(0);
            _local_1a8 = local_1c8;
            _local_198 = _local_1b8;
            FUN_140202920(local_1c8,lVar22 + 0x268);
            iVar31 = (uint)bVar19 * 0x20;
            fVar48 = (float)iVar31;
            fVar49 = (float)(iVar31 + 0x100);
            fVar38 = fVar49 * (float)local_1a8._0_4_ + fVar48 * (float)local_1b8._0_4_ +
                     (float)local_198._0_4_ + *(float *)(lVar22 + 600);
            fVar44 = fVar48 * fStack_1b0 + fVar49 * fStack_1a0 +
                     fStack_190 + *(float *)(lVar22 + 0x260);
            fVar39 = (float)FUN_140079410(*(undefined8 *)(local_220 + 0x148),fVar38,fVar44);
            fVar46 = *(float *)(lVar22 + 0x25c);
            *(float *)(lVar18 + 0x4a8) = fVar38;
            *(float *)(lVar18 + 0x4b0) = fVar44;
            auVar51 = vmaxss_avx(ZEXT416((uint)(fVar39 + fVar50)),
                                 ZEXT416((uint)(fVar48 * (float)local_1b8._4_4_ +
                                                fVar49 * (float)local_1a8._4_4_ +
                                               (float)local_198._4_4_ + fVar46)));
            *(int *)(lVar18 + 0x4ac) = auVar51._0_4_;
            *(float *)(lVar18 + 0x4b4) = fVar48 * fStack_1ac + fVar49 * fStack_19c + fStack_18c;
            *(undefined4 *)(lVar18 + 0x4b8) = *(undefined4 *)(lVar22 + 0x268);
            *(undefined4 *)(lVar18 + 0x4bc) = *(undefined4 *)(lVar22 + 0x26c);
            *(undefined4 *)(lVar18 + 0x4c0) = *(undefined4 *)(lVar22 + 0x270);
            *(undefined4 *)(lVar18 + 0x4c4) = *(undefined4 *)(lVar22 + 0x274);
            *(char *)(lVar22 + 0x42d) = *(char *)(lVar22 + 0x42d) + '\x01';
            *(uint *)(lVar36 + 0x1f0) = *(uint *)(lVar36 + 0x1f0) & 0xffffff7f;
            lVar16 = local_220;
          }
          if ((*(byte *)(*(longlong *)(lVar16 + 0x140) + 0x69) & 1) != 0) {
            FUN_14012c8c0(lVar16,lVar36,lVar22);
          }
        }
        auVar52 = ZEXT464(local_228);
        if (*(int *)(*(longlong *)(lVar36 + 0x178) + 0x16fcc) != 0) {
          *(undefined4 *)(lVar18 + 0x4ac) = 0x461c4000;
        }
      }
      lVar23 = lVar23 + 0x520;
      uVar21 = (int)local_1d8 + 1;
      local_1d8 = (ulonglong)uVar21;
    } while ((int)uVar21 < *(int *)(lVar16 + 0x118));
    param_1 = local_220;
  }
  pbVar10 = (byte *)(*(longlong *)(param_1 + 0x140) + 0x69);
  *pbVar10 = *pbVar10 & 0xf7;
  cVar20 = *(char *)(*(longlong *)(param_1 + 0x140) + 0x6b);
  if (cVar20 != '\0') {
    *(char *)(*(longlong *)(param_1 + 0x140) + 0x6b) = cVar20 + -1;
  }
  lVar16 = *(longlong *)(param_1 + 0x140);
  if (*(ushort *)(lVar16 + 0x66) < (ushort)((ushort)*(byte *)(param_1 + 0x15f) * 10)) {
    *(ushort *)(lVar16 + 0x66) = *(ushort *)(lVar16 + 0x66) + 1;
  }
  else {
    *(undefined2 *)(lVar16 + 0x66) = 0;
    lVar16 = *(longlong *)(param_1 + 0x140);
    if ((int)(uint)*(byte *)(lVar16 + 0x6c) < *(int *)(param_1 + 0x118) + -1) {
      *(byte *)(lVar16 + 0x6c) = *(byte *)(lVar16 + 0x6c) + 1;
    }
    else {
      *(undefined1 *)(lVar16 + 0x6c) = 1;
    }
  }
  return;
code_r0x00014012f867:
  local_234 = (float)((int)uVar25 + 1);
  uVar25 = (ulonglong)(uint)local_234;
  uVar17 = uVar17 + 1;
  if ((longlong)uVar29 <= (longlong)uVar17) goto LAB_14012f875;
  goto LAB_14012f85b;
LAB_140130201:
  if ((*(undefined8 **)(lVar18 + 8) != (undefined8 *)0x0) &&
     (*(char *)**(undefined8 **)(lVar18 + 8) == '\x01')) {
    *(uint *)(lVar16 + 0x1f0) = *(uint *)(lVar16 + 0x1f0) | 0x80;
  }
  if (((((bVar12 == 0xff) && (bVar15 == 0xff)) && (*(byte *)(lVar16 + 0x236) != 0xff)) &&
      ((*(char *)(lVar16 + 0x237) == -1 && ((*(uint *)(lVar16 + 0x1f8) & 0x100) != 0)))) &&
     (lVar22 = *(longlong *)
                (*(longlong *)
                  (**(longlong **)(lVar16 + 0x180) + (ulonglong)*(byte *)(lVar16 + 0x236) * 8) +
                0x110), lVar22 != -0x51ae0)) {
    *(uint *)(lVar22 + 0x51cdc) = *(uint *)(lVar22 + 0x51cdc) | 0x10;
    *(undefined1 *)(lVar22 + 0x51d1e) = *(undefined1 *)(lVar16 + 0x234);
    *(undefined1 *)(lVar22 + 0x51d1f) = *(undefined1 *)(lVar16 + 0x235);
  }
  *(byte *)(lVar16 + 0x237) = bVar15;
  *(byte *)(lVar16 + 0x236) = bVar12;
  *(byte *)(lVar23 + 0x82) = *(byte *)(lVar23 + 0x82) | 1;
  bVar12 = 100;
  abStack_eb[uVar25 - 0xd] = '\x01' << (bVar19 & 0x1f);
  *(undefined2 *)(lVar23 + 0x7e) = 0;
  if (*(longlong **)(lVar18 + 0x10) != (longlong *)0x0) {
    bVar12 = *(byte *)(**(longlong **)(lVar18 + 0x10) + 1);
  }
  local_e2[uVar25 + 1] =
       sVar34 - (short)((ulonglong)((uint)*(byte *)(*plVar3 + 0x49) * (uint)bVar12) / 100);
LAB_1401302f1:
  param_1 = local_220;
LAB_1401302f6:
  local_234 = (float)((int)local_234 + 1);
  iVar31 = *(int *)(param_1 + 0x118);
  local_1f8 = local_1f8 + 1;
  if (iVar31 <= (int)local_234) goto LAB_1401311db;
  goto LAB_14012fc93;
code_r0x000140130512:
  uVar14 = (ulonglong)((uint)uVar14 + 1);
  uVar25 = uVar25 + 1;
  if ((longlong)uVar29 <= (longlong)uVar25) goto LAB_14013051d;
  goto LAB_140130509;
code_r0x000140130c34:
  uVar25 = (ulonglong)((uint)uVar25 + 1);
  uVar14 = uVar14 + 1;
  if ((longlong)uVar29 <= (longlong)uVar14) goto LAB_140130c3f;
  goto LAB_140130c2b;
code_r0x0001401313cd:
  iVar9 = iVar9 + 1;
  lVar26 = lVar26 + 1;
  if (iVar13 <= iVar9) goto LAB_1401313d6;
  goto LAB_1401313c0;
}

