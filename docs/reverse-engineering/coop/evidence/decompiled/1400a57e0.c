/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a57e0; RVA 0xa57e0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1400a57e0(longlong param_1,undefined1 (*param_2) [16],undefined1 (*param_3) [16],
                  undefined4 *param_4,longlong *param_5)

{
  longlong *plVar1;
  undefined1 auVar2 [16];
  longlong lVar3;
  longlong *plVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  float fVar8;
  undefined1 (*pauVar9) [16];
  undefined1 (*pauVar10) [16];
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  longlong *plVar16;
  int iVar17;
  longlong lVar18;
  bool bVar19;
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  float fVar20;
  float fVar21;
  undefined1 auVar22 [64];
  float fVar23;
  float fVar24;
  undefined1 auVar25 [64];
  float fVar26;
  undefined1 auVar27 [64];
  float fVar28;
  float fVar29;
  float fVar30;
  uint uVar31;
  float fVar32;
  undefined1 (*local_res10) [16];
  undefined1 (*local_res18) [16];
  undefined4 *local_res20;
  float local_254;
  float local_250;
  float local_24c;
  undefined1 local_248 [8];
  float fStack_240;
  float fStack_23c;
  float local_238;
  undefined1 local_230 [8];
  float fStack_228;
  float fStack_224;
  float local_220;
  float local_21c;
  float local_218;
  float local_214;
  int local_210;
  undefined4 local_20c;
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  undefined1 local_1f8 [8];
  float fStack_1f0;
  float fStack_1ec;
  float local_1e8;
  float local_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  longlong local_1c8;
  longlong local_1c0;
  undefined1 local_1b8 [16];
  undefined1 local_1a8 [16];
  undefined1 local_198 [16];
  undefined1 local_188 [16];
  undefined4 local_178;
  float local_174;
  uint local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  uint local_158;
  float local_154;
  undefined4 local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  longlong local_f8;
  
  auVar2 = *param_2;
  auVar5 = vshufps_avx(auVar2,auVar2,0x55);
  auVar6 = vshufps_avx(auVar2,auVar2,0xaa);
  auVar7 = vshufps_avx(auVar2,auVar2,0xff);
  auVar2 = vinsertps_avx(ZEXT416((uint)(auVar2._0_4_ + *(float *)param_2[2])),
                         ZEXT416((uint)(auVar5._0_4_ + *(float *)(param_2[2] + 4))),0x10);
  auVar2 = vinsertps_avx(auVar2,ZEXT416((uint)(auVar6._0_4_ + *(float *)(param_2[2] + 8))),0x20);
  _local_248 = vinsertps_avx(auVar2,ZEXT416((uint)(auVar7._0_4_ + *(float *)(param_2[2] + 0xc))),
                             0x30);
  *param_3 = _local_248;
  local_210 = 0;
  local_198 = param_2[2];
  auVar22 = ZEXT1664(local_198);
  local_188 = vshufps_avx(local_198,local_198,0xaa);
  auVar25 = ZEXT1664(local_188);
  local_1a8 = vshufps_avx(local_198,local_198,0xff);
  auVar27 = ZEXT1664(local_1a8);
  local_1b8 = vshufps_avx(local_198,local_198,0x55);
  fVar32 = local_1b8._0_4_;
  local_20c = 0;
  iVar14 = 1 - (int)(*(float *)(param_2[4] + 8) * DAT_1402d2c5c);
  fVar28 = *(float *)(param_2[4] + 8) / (float)iVar14;
  fVar21 = local_198._0_4_;
  fVar23 = local_188._0_4_;
  fVar26 = local_1a8._0_4_;
  fVar20 = SQRT(fVar26 * fVar26 + fVar23 * fVar23 + fVar32 * fVar32 + fVar21 * fVar21);
  fVar30 = 0.0;
  iVar17 = 0;
  if (fVar20 != 0.0) {
    fVar20 = DAT_1402d22d0 / fVar20;
    auVar22 = ZEXT464((uint)(fVar21 * fVar20));
    fVar32 = fVar32 * fVar20;
    auVar25 = ZEXT464((uint)(fVar23 * fVar20));
    auVar27 = ZEXT464((uint)(fVar26 * fVar20));
    local_198 = ZEXT416((uint)(fVar21 * fVar20));
    local_1b8 = ZEXT416((uint)fVar32);
    local_188 = ZEXT416((uint)(fVar23 * fVar20));
    local_1a8 = ZEXT416((uint)(fVar26 * fVar20));
  }
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  local_21c = fVar28;
  _local_1f8 = _local_248;
  if (*(char *)(param_1 + 0x437) == '\x01') {
    plVar16 = (longlong *)**(longlong **)(param_1 + 0x10);
    plVar1 = plVar16 + (byte)param_2[5][0];
    if (plVar16 != plVar16 + *(byte *)((longlong)*(longlong **)(param_1 + 0x10) + 0x34)) {
      local_24c = fStack_240;
      local_250 = (float)local_248._4_4_;
      local_254 = (float)local_248._0_4_;
      local_220 = fStack_23c;
      do {
        lVar18 = *plVar16;
        if (((&DAT_1402accc0)
             [(ulonglong)*(byte *)(lVar18 + 0x15d) + (ulonglong)*(byte *)(*plVar1 + 0x15d) * 8] !=
             '\0') && ((*(byte *)(lVar18 + 0x120) & 7) != 0)) {
          local_f8 = (longlong)*(int *)(lVar18 + 0x118);
          local_1c8 = 0;
          if (0 < local_f8) {
            local_1c0 = 0;
            do {
              fVar32 = auVar27._0_4_;
              iVar17 = 0;
              lVar18 = *(longlong *)(*plVar16 + 0x110) + local_1c0;
              if (*(char *)(lVar18 + 0x234) == param_2[5][0]) {
                if (*(char *)(lVar18 + 0x235) != param_2[5][1]) goto LAB_1400a5a64;
              }
              else {
LAB_1400a5a64:
                if ((*(byte *)(lVar18 + 0x1f0) & 1) != 0) {
                  if (*(longlong **)(lVar18 + 0x1a0) != (longlong *)0x0) {
                    lVar3 = **(longlong **)(lVar18 + 0x1a0);
                    if (lVar3 != 0) {
                      plVar4 = *(longlong **)(lVar18 + 0x3a0);
                      local_238 = DAT_1402d2698;
                      if (*(char *)(lVar3 + 0x6f) == '\x01') {
                        local_238 = *(float *)(lVar3 + 0x40);
                      }
                      else if (plVar4 != (longlong *)0x0) {
                        local_238 = (float)(**(code **)(*plVar4 + 0xa0))(plVar4);
                        auVar22 = ZEXT1664(local_198);
                        fVar32 = local_1a8._0_4_;
                        param_2 = local_res10;
                      }
                      _local_230 = *(undefined1 (*) [16])(lVar18 + 600);
                      bVar19 = false;
                      local_218 = fVar28;
                      if (0 < iVar14) {
                        auVar25 = ZEXT464((uint)local_230._4_4_);
                        local_214 = fVar32 * fVar28;
                        fVar32 = local_1b8._0_4_ * fVar28;
                        fVar20 = auVar22._0_4_ * fVar28;
                        fVar28 = (float)local_188._0_4_ * fVar28;
                        local_1e8 = SQRT(local_214 * local_214 +
                                         fVar28 * fVar28 + fVar20 * fVar20 + fVar32 * fVar32);
                        fVar21 = fStack_228;
                        fVar23 = (float)local_230._0_4_;
                        local_1d0 = fVar30;
                        do {
                          auVar2 = *param_2;
                          local_208 = auVar22._0_4_ * local_1d0 + auVar2._0_4_;
                          local_1dc = fVar23 - local_208;
                          auVar5 = vshufps_avx(auVar2,auVar2,0x55);
                          local_204 = local_1b8._0_4_ * local_1d0 + auVar5._0_4_;
                          auVar5 = vshufps_avx(auVar2,auVar2,0xaa);
                          local_200 = (float)local_188._0_4_ * local_1d0 + auVar5._0_4_;
                          auVar2 = vshufps_avx(auVar2,auVar2,0xff);
                          local_1fc = (float)local_1a8._0_4_ * local_1d0 + auVar2._0_4_;
                          local_1d0 = local_218;
                          local_218 = local_218 + local_21c;
                          fVar29 = auVar25._0_4_;
                          local_1e0 = fVar29 - local_204;
                          fVar26 = local_1e8 + *(float *)(lVar18 + 0x41c);
                          local_1e4 = (fVar21 - local_200) * (fVar21 - local_200) +
                                      (fVar29 - local_204) * (fVar29 - local_204) +
                                      local_1dc * local_1dc;
                          local_248._4_4_ = fVar32 + local_204;
                          fStack_240 = fVar28 + local_200;
                          fStack_23c = local_214 + local_1fc;
                          local_248._0_4_ = fVar20 + local_208;
                          fVar23 = (float)local_230._0_4_;
                          local_1d8 = local_208;
                          local_1d4 = local_204;
                          if (local_1e4 <= fVar26 * fVar26) {
                            if ((((local_208 == fVar20 + local_208) &&
                                 (local_204 == (float)local_248._4_4_)) && (local_200 == fStack_240)
                                ) && (local_1fc == fStack_23c)) {
                              if (SQRT((local_1fc - fStack_224) * (local_1fc - fStack_224) +
                                       (local_200 - fVar21) * (local_200 - fVar21) +
                                       (local_204 - fVar29) * (local_204 - fVar29) +
                                       (local_208 - (float)local_230._0_4_) *
                                       (local_208 - (float)local_230._0_4_)) <= local_238)
                              goto LAB_1400a5cb8;
                            }
                            else {
                              fVar26 = local_238 * local_238;
                              fVar24 = (float)local_230._0_4_ - (fVar20 + local_208);
                              if ((((fStack_224 - fStack_23c) * (fStack_224 - fStack_23c) +
                                    (fVar21 - fStack_240) * (fVar21 - fStack_240) +
                                    (fVar29 - (float)local_248._4_4_) *
                                    (fVar29 - (float)local_248._4_4_) + fVar24 * fVar24 <= fVar26)
                                  || (fVar24 = fStack_224 - local_1fc,
                                     fVar24 * fVar24 + local_1e4 <= fVar26)) ||
                                 ((fVar24 = (local_214 * fVar24 +
                                            fVar28 * (fVar21 - local_200) +
                                            fVar20 * local_1dc + fVar32 * local_1e0) /
                                            (local_214 * local_214 +
                                            fVar28 * fVar28 + fVar20 * fVar20 + fVar32 * fVar32),
                                  fVar30 <= fVar24 &&
                                  ((fVar24 <= DAT_1402d22d0 &&
                                   (fVar8 = (fVar24 * fVar20 + local_208) - (float)local_230._0_4_,
                                   fVar29 = (fVar24 * fVar32 + local_204) - fVar29,
                                   fVar24 = (fVar24 * fVar28 + local_200) - fVar21,
                                   fVar24 * fVar24 + fVar29 * fVar29 + fVar8 * fVar8 <= fVar26))))))
                              {
LAB_1400a5cb8:
                                bVar19 = true;
                                if (*(char *)(lVar3 + 0x6f) == '\x02') {
                                  if (plVar4 == (longlong *)0x0) goto LAB_1400a6181;
                                  fVar26 = DAT_1402d22d0;
                                  auVar22._0_8_ =
                                       FUN_14026f3f3(*(undefined4 *)(lVar18 + 0x26c),
                                                     *(undefined4 *)(lVar18 + 0x268));
                                  auVar22._8_56_ = extraout_var;
                                  auVar2 = vpermilps_avx(auVar22._0_16_,1);
                                  auVar5 = vpermilps_avx(auVar22._0_16_,0xe);
                                  local_158 = (uint)auVar22._0_8_;
                                  local_170 = local_158 ^ DAT_1402d3770;
                                  local_178 = auVar2._0_4_;
                                  auVar2 = vpermilps_avx(auVar5,1);
                                  local_120 = auVar5._0_4_;
                                  local_114 = (float)((uint)local_120 ^ DAT_1402d3770);
                                  local_124 = auVar2._0_4_;
                                  uVar31 = DAT_1402d3770;
                                  local_174 = fVar30;
                                  local_16c = fVar30;
                                  local_168 = fVar30;
                                  local_164 = fVar26;
                                  local_160 = fVar30;
                                  local_15c = fVar30;
                                  local_154 = fVar30;
                                  local_150 = local_178;
                                  local_14c = fVar30;
                                  local_148 = fVar30;
                                  local_144 = fVar30;
                                  local_140 = fVar30;
                                  local_13c = fVar26;
                                  local_138 = fVar26;
                                  local_134 = fVar30;
                                  local_130 = fVar30;
                                  local_12c = fVar30;
                                  local_128 = fVar30;
                                  local_11c = fVar30;
                                  local_118 = fVar30;
                                  local_110 = local_124;
                                  local_10c = fVar30;
                                  local_108 = fVar30;
                                  local_104 = fVar30;
                                  local_100 = fVar30;
                                  local_fc = fVar26;
                                  FUN_140005940(&local_178,&local_178,&local_138);
                                  auVar27._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar18 + 0x270));
                                  auVar27._8_56_ = extraout_var_00;
                                  auVar2 = vpermilps_avx(auVar27._0_16_,1);
                                  local_134 = (float)auVar27._0_8_;
                                  local_128 = (float)((uint)local_134 ^ uVar31);
                                  local_138 = auVar2._0_4_;
                                  local_124 = local_138;
                                  local_120 = fVar30;
                                  local_114 = fVar30;
                                  local_110 = fVar26;
                                  FUN_140005940(&local_178,&local_178,&local_138);
                                  local_148 = fVar23 + local_148;
                                  local_144 = auVar25._0_4_ + local_144;
                                  local_140 = fVar21 + local_140;
                                  iVar12 = (**(code **)(*plVar4 + 0x120))
                                                     (plVar4,local_230,&local_178,&local_208,
                                                      local_248);
                                  if (iVar12 != 0) goto LAB_1400a6181;
                                  auVar25 = ZEXT464((uint)local_230._4_4_);
                                  local_254 = (float)local_248._0_4_;
                                  local_250 = (float)local_248._4_4_;
                                  local_24c = fStack_240;
                                  local_220 = fStack_23c;
                                  param_2 = local_res10;
                                  fVar21 = fStack_228;
                                  fVar23 = (float)local_230._0_4_;
                                }
                              }
                            }
                          }
                          auVar22 = ZEXT1664(local_198);
                          iVar17 = iVar17 + 1;
                        } while (iVar17 < iVar14);
                        fVar28 = local_21c;
                        if (bVar19) {
LAB_1400a6181:
                          *(float *)*local_res18 = local_254;
                          *(float *)(*local_res18 + 4) = local_250;
                          *(float *)(*local_res18 + 8) = local_24c;
                          *(float *)(*local_res18 + 0xc) = local_220;
                          *local_res20 = 1;
                          if (param_5 != (longlong *)0x0) {
                            *param_5 = lVar18;
                          }
                          iVar17 = 1;
                          goto LAB_1400a5f54;
                        }
                      }
                    }
                  }
                }
              }
              auVar22 = ZEXT1664(local_198);
              auVar27 = ZEXT1664(local_1a8);
              local_1c8 = local_1c8 + 1;
              local_1c0 = local_1c0 + 0x520;
            } while (local_1c8 < local_f8);
          }
        }
        plVar16 = plVar16 + 1;
      } while (plVar16 !=
               (longlong *)
               (**(longlong **)(param_1 + 0x10) +
               (ulonglong)*(byte *)((longlong)*(longlong **)(param_1 + 0x10) + 0x34) * 8));
      iVar17 = local_210;
LAB_1400a5f54:
      fVar32 = local_1b8._0_4_;
      auVar25 = ZEXT1664(local_188);
      fVar28 = local_220;
      goto LAB_1400a5f65;
    }
  }
  local_24c = fStack_240;
  local_250 = (float)local_248._4_4_;
  local_254 = (float)local_248._0_4_;
  fVar28 = fStack_23c;
LAB_1400a5f65:
  iVar12 = local_210;
  puVar11 = local_res20;
  pauVar10 = local_res18;
  pauVar9 = local_res10;
  if (*(char *)(param_1 + 0x436) == '\x01') {
    iVar15 = 0;
    _local_248 = ZEXT816(0);
    if (0 < iVar14) {
      fVar20 = (float)local_198._0_4_ * local_21c;
      fVar21 = (float)local_1a8._0_4_ * local_21c;
      fVar32 = fVar32 * local_21c;
      fVar23 = auVar25._0_4_ * local_21c;
      fVar26 = local_21c;
      fVar29 = local_21c;
      do {
        auVar2 = *pauVar9;
        local_230._0_4_ = (float)local_198._0_4_ * fVar30 + auVar2._0_4_;
        auVar5 = vshufps_avx(auVar2,auVar2,0xaa);
        auVar6 = vshufps_avx(auVar2,auVar2,0x55);
        local_230._4_4_ = (float)local_1b8._0_4_ * fVar30 + auVar6._0_4_;
        fStack_228 = auVar25._0_4_ * fVar30 + auVar5._0_4_;
        local_208 = (float)local_230._0_4_ + fVar20;
        auVar2 = vshufps_avx(auVar2,auVar2,0xff);
        fStack_224 = (float)local_1a8._0_4_ * fVar30 + auVar2._0_4_;
        local_204 = (float)local_230._4_4_ + fVar32;
        local_1fc = fStack_224 + fVar21;
        local_200 = fStack_228 + fVar23;
        fVar30 = fVar26;
        fVar26 = fVar26 + fVar29;
        iVar13 = FUN_1400782c0(*(undefined8 *)(param_1 + 0x18),local_248,&local_res10,local_230,
                               &local_208);
        if (iVar13 != 0) {
          iVar12 = 1;
          *(undefined4 *)*pauVar10 = local_248._0_4_;
          *(undefined4 *)(*pauVar10 + 4) = local_248._4_4_;
          *(float *)(*pauVar10 + 8) = fStack_240;
          *(float *)(*pauVar10 + 0xc) = fStack_23c;
          *puVar11 = local_res10._0_4_;
          local_1f8._0_4_ = local_248._0_4_;
          local_1f8._4_4_ = local_248._4_4_;
          fStack_1f0 = fStack_240;
          fStack_1ec = fStack_23c;
          local_20c = local_res10._0_4_;
          goto LAB_1400a6278;
        }
        auVar25 = ZEXT1664(local_188);
        iVar15 = iVar15 + 1;
      } while (iVar15 < iVar14);
    }
  }
LAB_1400a6278:
  if (iVar17 == 1) {
    if (iVar12 == 1) {
      auVar2 = *pauVar9;
      auVar5 = *pauVar9;
      fVar32 = auVar2._0_4_ - local_254;
      auVar6 = vshufps_avx(auVar2,auVar2,0x55);
      fVar30 = auVar6._0_4_ - local_250;
      auVar6 = vshufps_avx(auVar2,auVar2,0xaa);
      fVar20 = auVar6._0_4_ - local_24c;
      auVar6 = vshufps_avx(auVar5,auVar5,0x55);
      fVar21 = auVar6._0_4_ - (float)local_1f8._4_4_;
      auVar6 = vshufps_avx(auVar5,auVar5,0xaa);
      fVar23 = auVar6._0_4_ - fStack_1f0;
      fVar26 = auVar5._0_4_ - (float)local_1f8._0_4_;
      auVar2 = vshufps_avx(auVar2,auVar2,0xff);
      fVar29 = auVar2._0_4_ - fVar28;
      auVar2 = vshufps_avx(auVar5,auVar5,0xff);
      fVar24 = auVar2._0_4_ - fStack_1ec;
      if (SQRT(fVar29 * fVar29 + fVar20 * fVar20 + fVar30 * fVar30 + fVar32 * fVar32) <
          SQRT(fVar24 * fVar24 + fVar23 * fVar23 + fVar21 * fVar21 + fVar26 * fVar26)) {
        *(float *)*pauVar10 = local_254;
        *(float *)(*pauVar10 + 4) = local_250;
        *(float *)(*pauVar10 + 8) = local_24c;
        *(float *)(*pauVar10 + 0xc) = fVar28;
        *puVar11 = 1;
        return true;
      }
      *(undefined4 *)*pauVar10 = local_1f8._0_4_;
      *(undefined4 *)(*pauVar10 + 4) = local_1f8._4_4_;
      *(float *)(*pauVar10 + 8) = fStack_1f0;
      *(float *)(*pauVar10 + 0xc) = fStack_1ec;
      *puVar11 = local_20c;
    }
    bVar19 = true;
  }
  else {
    bVar19 = iVar12 == 1;
  }
  return bVar19;
}

