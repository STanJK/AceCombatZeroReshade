/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010c9a0; RVA 0x10c9a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14010c9a0(longlong param_1,longlong param_2)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auVar5 [16];
  bool bVar6;
  bool bVar7;
  undefined1 auVar8 [16];
  char cVar9;
  char cVar10;
  short sVar11;
  longlong lVar12;
  undefined4 *puVar13;
  longlong lVar14;
  byte bVar15;
  byte bVar16;
  longlong *plVar17;
  ulonglong uVar18;
  short sVar19;
  uint uVar20;
  uint uVar21;
  longlong unaff_GS_OFFSET;
  float fVar22;
  float fVar23;
  uint uVar24;
  undefined1 auVar26 [16];
  undefined8 extraout_XMM0_Qa_00;
  undefined8 uVar25;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  undefined8 extraout_XMM0_Qa_04;
  undefined1 auVar27 [16];
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_05;
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined1 auVar28 [64];
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  undefined4 uVar33;
  undefined1 auVar34 [64];
  undefined1 auVar35 [64];
  float fVar36;
  undefined1 auVar37 [64];
  float fVar38;
  float fVar39;
  undefined4 uVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  uint local_res20;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  undefined8 local_1a0;
  undefined8 uStack_198;
  float local_190;
  int local_18c;
  int local_188;
  undefined1 local_178 [16];
  undefined1 local_168 [16];
  undefined1 local_158 [8];
  float fStack_150;
  float fStack_14c;
  undefined1 local_148 [16];
  float local_138;
  longlong local_130;
  undefined4 local_128;
  uint local_124;
  undefined4 local_120;
  undefined4 local_11c;
  uint local_118;
  undefined4 local_114;
  uint local_110;
  undefined4 local_10c;
  undefined4 local_108;
  uint local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  longlong local_e8;
  longlong local_e0;
  
  cVar10 = DAT_14033bd60;
  DAT_14032c480 = DAT_14032c480 + 1;
  local_1b4 = 0.0;
  local_1b0 = 0.0;
  local_1ac = 0.0;
  uVar40 = 0;
  fVar22 = 0.0;
  if ((DAT_14033bd60 != '\0') && (param_2 != 0)) {
    local_1b4 = *(float *)(param_2 + 0x10);
    fVar22 = *(float *)(param_2 + 0x1c);
    local_1b0 = *(float *)(param_2 + 0x14);
    local_1ac = *(float *)(param_2 + 0x18);
  }
  fVar41 = DAT_1402d2a78 * *(float *)(param_1 + 0x15d0);
  fVar42 = DAT_1402d2a78 * *(float *)(param_1 + 0x15d4);
  fVar43 = DAT_1402d2a78 * *(float *)(param_1 + 0x15d8);
  fVar39 = DAT_1402d2a78 * *(float *)(param_1 + 0x15dc);
  fVar23 = *(float *)(param_1 + 0x1848);
  local_178 = ZEXT816(0);
  local_168 = ZEXT816(0);
  local_1a0 = CONCAT44(fVar42,fVar41);
  uStack_198 = CONCAT44(fVar39,fVar43);
  fVar44 = DAT_1402d2a78;
  _local_158 = local_178;
  local_148 = local_168;
  FUN_140202920(local_178,param_1 + 0x80);
  local_1b8 = fVar23 * (float)local_158._0_4_;
  local_1a8 = fVar23 * (float)local_158._4_4_;
  local_1a4 = fVar23 * fStack_150;
  local_190 = fVar23 * fStack_14c;
  auVar34 = ZEXT464((uint)local_190);
  fVar30 = local_1a8;
  fVar23 = local_1a4;
  FUN_1401c56d0();
  fVar38 = DAT_14033bd70;
  fVar36 = DAT_14033bd6c;
  fVar29 = DAT_14033bd68;
  fVar31 = DAT_14033bd64;
  fVar32 = auVar34._0_4_;
  if (cVar10 != '\0') {
    if (DAT_14033bd64 == DAT_1402d2c40) {
      *(uint *)(param_1 + 0x2058) = *(uint *)(param_1 + 0x2058) | 0x200;
    }
    fVar31 = local_1b4 - fVar31;
    fVar29 = local_1b0 - fVar29;
    fVar36 = local_1ac - fVar36;
    lVar12 = FUN_140189320();
    local_190 = 0.0;
    fVar39 = (fVar22 - fVar38) * DAT_1402d1dd0;
    fVar30 = (float)*(int *)(lVar12 + 0xc);
    local_1b8 = fVar31 * DAT_1402d21cc * fVar30;
    fVar42 = fVar29 * DAT_1402d1dd0;
    fVar43 = fVar36 * DAT_1402d1dd0;
    fVar41 = fVar31 * DAT_1402d1dd0;
    fVar23 = fVar36 * DAT_1402d21cc * fVar30;
    fVar30 = fVar29 * DAT_1402d21cc * fVar30;
    local_1a0 = CONCAT44(fVar42,fVar41);
    uStack_198 = CONCAT44(fVar39,fVar43);
    fVar32 = 0.0;
    local_1a8 = fVar30;
    local_1a4 = fVar23;
  }
  plVar17 = *(longlong **)(param_1 + 0x2040);
  local_138 = SQRT(fVar32 * fVar32 + fVar23 * fVar23 + fVar30 * fVar30 + local_1b8 * local_1b8);
  bVar7 = false;
  local_188 = 0;
  if (*(char *)((longlong)plVar17 + 0x34) != '\0') {
    auVar34 = ZEXT464(DAT_1402d22d0);
    local_130 = 0;
    do {
      local_e0 = *plVar17;
      lVar12 = *(longlong *)(local_130 + local_e0);
      if ((((byte)*(undefined4 *)(lVar12 + 0x120) & 5) == 5) &&
         (local_18c = 0, 0 < *(int *)(lVar12 + 0x118))) {
        local_e8 = 0;
        do {
          lVar12 = local_e8 + *(longlong *)(lVar12 + 0x110);
          if ((*(char *)(lVar12 + 0x234) == *(char *)(param_1 + 0x20a1)) &&
             (*(char *)(lVar12 + 0x235) == *(char *)(param_1 + 0x20a2))) {
            bVar6 = true;
          }
          else {
            bVar6 = false;
          }
          fVar22 = DAT_1402d2c40;
          if (cVar10 != '\0') {
            fVar22 = local_1b4 - *(float *)(lVar12 + 600);
            fVar23 = local_1b0 - *(float *)(lVar12 + 0x25c);
            fVar30 = local_1ac - *(float *)(lVar12 + 0x260);
            fVar22 = SQRT(fVar30 * fVar30 + fVar23 * fVar23 + fVar22 * fVar22);
          }
          if ((*(byte *)(lVar12 + 0x1f0) & 1) != 0) {
            fVar23 = fVar22;
            if (cVar10 == '\0') {
              fVar23 = *(float *)(lVar12 + 0x20c + (ulonglong)*(byte *)(param_1 + 0x1c32) * 4);
            }
            if (((fVar23 <= fVar44) &&
                (((!bVar6 || (cVar10 != '\0')) &&
                 (*(longlong **)(lVar12 + 0x1a0) != (longlong *)0x0)))) &&
               (lVar14 = **(longlong **)(lVar12 + 0x1a0), lVar14 != 0)) {
              switch(*(undefined1 *)(lVar14 + 0x79)) {
              case 1:
              case 6:
switchD_14010cd94_caseD_1:
                uVar21 = 0x9b;
                uVar20 = 0x9f;
                local_res20 = 0x9b;
                break;
              case 2:
                uVar21 = 0x9c;
                uVar20 = 0xa8;
                local_res20 = 0x9c;
                break;
              case 3:
                uVar21 = 0x9d;
                uVar20 = 0xab;
                local_res20 = 0x9d;
                break;
              case 4:
                uVar21 = 0x9c;
                uVar20 = 0xae;
                local_res20 = 0x9c;
                break;
              case 5:
                uVar21 = 0x9d;
                uVar20 = 0xb1;
                local_res20 = 0x9d;
                break;
              default:
                if (bVar6) goto switchD_14010cd94_caseD_1;
                uVar20 = 0xffffffff;
                uVar21 = 0xffffffff;
                local_res20 = 0xffffffff;
              }
              lVar14 = *(longlong *)(lVar12 + 0x360);
              if ((((lVar14 != 0) || (*(longlong *)(lVar12 + 0x370) != 0)) || (bVar6)) &&
                 ((-1 < (int)uVar20 && (-1 < (int)uVar21)))) {
                if (cVar10 == '\0') {
                  fVar22 = *(float *)(lVar12 + 0x20c + (ulonglong)*(byte *)(param_1 + 0x1c32) * 4);
                }
                auVar37 = ZEXT464((uint)(fVar22 * DAT_1402d1dd0));
                if ((fVar22 * DAT_1402d1dd0 < *(float *)(param_1 + 0x2760)) &&
                   ((lVar14 != 0 || (bVar6)))) {
                  bVar7 = true;
                }
                fVar23 = (float)FUN_140118ab0(lVar12);
                fVar22 = (float)((uint)*(byte *)(param_1 + 0x20a0) * 0xe10);
                if (cVar10 == '\0') {
                  auVar35._0_8_ =
                       FUN_14026f3f3(*(undefined4 *)(lVar12 + 0x26c),*(undefined4 *)(lVar12 + 0x268)
                                    );
                  auVar5 = _local_158;
                  auVar35._8_56_ = extraout_var;
                  auVar26 = vpermilps_avx(auVar35._0_16_,1);
                  auVar27 = vpermilps_avx(auVar35._0_16_,0xe);
                  uVar24 = (uint)auVar35._0_8_;
                  local_158._0_4_ = uVar24;
                  auVar8 = _local_158;
                  local_178._8_4_ = uVar24 ^ DAT_1402d3770;
                  local_110 = auVar27._0_4_;
                  local_104 = local_110 ^ DAT_1402d3770;
                  fStack_14c = auVar5._12_4_;
                  local_158 = auVar8._0_8_;
                  fStack_150 = (float)auVar26._0_4_;
                  auVar27 = vpermilps_avx(auVar27,1);
                  local_178._4_4_ = uVar40;
                  local_178._0_4_ = auVar26._0_4_;
                  local_128 = auVar34._0_4_;
                  local_168._4_4_ = local_128;
                  local_168._0_4_ = uVar40;
                  local_158._4_4_ = uVar40;
                  local_148._4_4_ = uVar40;
                  local_148._0_4_ = uVar40;
                  local_168._8_4_ = uVar40;
                  local_148._8_4_ = uVar40;
                  local_178._12_4_ = uVar40;
                  local_168._12_4_ = uVar40;
                  fStack_14c = (float)uVar40;
                  local_148._12_4_ = local_128;
                  local_114 = auVar27._0_4_;
                  local_124 = uVar40;
                  local_120 = uVar40;
                  local_11c = uVar40;
                  local_118 = uVar40;
                  local_10c = uVar40;
                  local_108 = uVar40;
                  local_100 = local_114;
                  local_fc = uVar40;
                  local_f8 = uVar40;
                  local_f4 = uVar40;
                  local_f0 = uVar40;
                  local_ec = local_128;
                  FUN_140005940(local_178,local_178,&local_128);
                  auVar28._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar12 + 0x270));
                  auVar28._8_56_ = extraout_var_00;
                  local_124 = (uint)auVar28._0_8_;
                  local_118 = local_124 ^ DAT_1402d3770;
                  auVar26 = vpermilps_avx(auVar28._0_16_,1);
                  local_128 = auVar26._0_4_;
                  local_100 = auVar34._0_4_;
                  local_114 = local_128;
                  local_110 = uVar40;
                  local_104 = uVar40;
                  FUN_140005940(local_178,local_178,&local_128);
                  fVar31 = fVar23 * fVar22 * DAT_1402d1dd0;
                  fVar22 = fVar31 * (float)local_158._4_4_;
                  fVar23 = fVar31 * (float)local_158._0_4_;
                  fVar30 = fVar31 * fStack_14c;
                  fVar31 = fVar31 * fStack_150;
                  fVar29 = (fVar30 * local_190 +
                           fVar31 * local_1a4 + fVar22 * local_1a8 + fVar23 * local_1b8) /
                           (SQRT(fVar30 * fVar30 +
                                 fVar31 * fVar31 + fVar22 * fVar22 + fVar23 * fVar23) * local_138);
                  fVar22 = local_138 -
                           SQRT(fVar29 * fVar30 * fVar29 * fVar30 +
                                fVar29 * fVar31 * fVar29 * fVar31 +
                                fVar29 * fVar22 * fVar29 * fVar22 +
                                fVar29 * fVar23 * fVar29 * fVar23);
                  fVar22 = fVar22 * fVar22;
                }
                else {
                  auVar26 = *(undefined1 (*) [16])(lVar12 + 600);
                  fVar22 = fVar22 * DAT_1402d1dd0;
                  auVar27 = vshufps_avx(auVar26,auVar26,0x55);
                  auVar5 = vshufps_avx(auVar26,auVar26,0xaa);
                  fVar30 = (auVar26._0_4_ - *(float *)(lVar12 + 0x288)) * fVar22 - local_1b8;
                  fVar23 = (auVar27._0_4_ - *(float *)(lVar12 + 0x28c)) * fVar22 - local_1a8;
                  fVar22 = (auVar5._0_4_ - *(float *)(lVar12 + 0x290)) * fVar22 - local_1a4;
                  fVar22 = fVar22 * fVar22 + fVar23 * fVar23 + fVar30 * fVar30;
                }
                auVar26 = auVar37._0_16_;
                fVar23 = auVar37._0_4_;
                bVar16 = *(byte *)(lVar12 + 0x42c);
                fVar22 = SQRT(fVar22);
                if (*(float *)(param_1 + 0x2740) <= fVar23) {
                  bVar15 = bVar16 & 0xfc;
                }
                else {
                  bVar15 = bVar16 | 2;
                  if ((bVar16 & 1) != 0) {
                    bVar15 = bVar16 & 0xfd;
                  }
                  bVar15 = bVar15 | 1;
                }
                *(byte *)(lVar12 + 0x42c) = bVar15;
                if (*(float *)(param_1 + 0x2734) <= fVar23) {
                  bVar16 = bVar15 & 0xf3;
                }
                else {
                  bVar16 = bVar15 & 0xf7;
                  if ((bVar15 & 4) == 0) {
                    bVar16 = bVar15 | 8;
                  }
                  bVar16 = bVar16 | 4;
                }
                *(byte *)(lVar12 + 0x42c) = bVar16;
                if ((lVar14 != 0) || (bVar6)) {
                  fVar30 = *(float *)(param_1 + 0x2744);
                  uVar18 = (ulonglong)(uint)fVar30;
                  auVar35 = ZEXT1664(auVar34._0_16_);
                  if (fVar23 < fVar30) {
                    auVar26._0_4_ = fVar23 / fVar30;
                    auVar26._4_12_ = auVar37._4_12_;
                    uVar18 = auVar26._0_8_;
                    auVar35 = ZEXT464((uint)(-(*(float *)(param_1 + 0x2748) * auVar26._0_4_) +
                                             *(float *)(param_1 + 0x2748) + auVar34._0_4_));
                  }
                  puVar1 = (uint *)(lVar12 + 0x34c);
                  cVar9 = FUN_1401c5910(uVar18,lVar12 + 0x350);
                  uVar25 = extraout_XMM0_Qa;
                  if (cVar9 != '\0') {
                    cVar9 = FUN_1401c6500(extraout_XMM0_Qa,lVar12 + 0x350);
                    iVar3 = *(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4);
                    if (cVar9 == '\0') {
                      uVar25 = extraout_XMM0_Qa_00;
                      if ((iVar3 < DAT_1437daf04) &&
                         (uVar25 = FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
                        FUN_1401c93c0();
                        uVar25 = _Init_thread_footer(&DAT_1437daf04);
                      }
                      uVar21 = *(uint *)(lVar12 + 0x350);
                      if ((((uVar21 != 0) && ((ushort)uVar21 < 0x80)) &&
                          (uVar18 = (ulonglong)(uVar21 & 0xffff),
                          (short)(uVar21 >> 0x10) == *(short *)(&DAT_1437daf22 + uVar18 * 2))) &&
                         (lVar14 = uVar18 * 0x78, ((&DAT_1437db130)[lVar14] & 2) != 0)) {
                        *(undefined4 *)(&DAT_1437db0c0 + uVar18 * 0xf) =
                             *(undefined4 *)(lVar12 + 600);
                        *(undefined4 *)((longlong)&DAT_1437db0c0 + lVar14 + 4) =
                             *(undefined4 *)(lVar12 + 0x25c);
                        (&DAT_1437db0c8)[uVar18 * 0x1e] = *(undefined4 *)(lVar12 + 0x260);
                        uVar33 = *(undefined4 *)(lVar12 + 0x264);
                        *(float *)((longlong)&DAT_1437db0cc + lVar14 + 4) = fVar41;
                        *(float *)(&DAT_1437db0d4 + uVar18 * 0xf) = fVar42;
                        *(float *)((longlong)&DAT_1437db0d4 + lVar14 + 4) = fVar43;
                        *(float *)(&DAT_1437db0dc + uVar18 * 0xf) = fVar39;
                        *(int *)(&DAT_1437db0fc + uVar18 * 0xf) = auVar35._0_4_;
                        *(undefined4 *)(&DAT_1437db0cc + uVar18 * 0xf) = uVar33;
                        *(undefined8 *)((longlong)&DAT_1437db0dc + lVar14 + 4) = 0;
                        *(undefined4 *)((longlong)&DAT_1437db0e4 + lVar14 + 4) = 0;
                        (&DAT_1437db0ec)[uVar18 * 0x1e] = 0x3f800000;
                        *(undefined2 *)((longlong)&DAT_1437db104 + lVar14 + 6) = 0;
                      }
                    }
                    else {
                      if ((iVar3 < DAT_1437daf04) &&
                         (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
                        FUN_1401c93c0();
                        _Init_thread_footer(&DAT_1437daf04);
                      }
                      uVar25 = FUN_1401cb010(&DAT_1437daf20,lVar12 + 0x350);
                    }
                  }
                  cVar9 = FUN_1401c5910(uVar25,puVar1);
                  auVar26 = auVar37._0_16_;
                  uVar21 = local_res20;
                  if (cVar9 != '\0') {
                    cVar9 = FUN_1401c6500(extraout_XMM0_Qa_01,puVar1);
                    if (cVar9 == '\0') {
                      fVar23 = *(float *)(param_1 + 0x2758);
                      sVar19 = (short)(int)(-((fVar23 / *(float *)(lVar12 + 0x354)) * fVar22) +
                                           fVar23);
                      if (sVar19 < 1) {
                        sVar11 = (short)(int)*(float *)(param_1 + 0x275c);
                        if (sVar19 < sVar11) {
                          sVar19 = sVar11;
                        }
                      }
                      else {
                        sVar19 = 0;
                      }
                      FUN_1401c6260(fVar23,puVar1,param_1 + 0x70);
                      auVar26 = auVar37._0_16_;
                      if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
                        FUN_14022d540(&DAT_1437daf04);
                        auVar26 = auVar37._0_16_;
                        if (DAT_1437daf04 == -1) {
                          FUN_1401c93c0();
                          _Init_thread_footer(&DAT_1437daf04);
                          auVar26 = auVar37._0_16_;
                        }
                      }
                      uVar21 = *puVar1;
                      if (((uVar21 != 0) && ((ushort)uVar21 < 0x80)) &&
                         ((short)(uVar21 >> 0x10) ==
                          *(short *)(&DAT_1437daf22 + (ulonglong)(uVar21 & 0xffff) * 2))) {
                        *(short *)((longlong)&DAT_1437db104 +
                                  (ulonglong)(uVar21 & 0xffff) * 0x78 + 6) = sVar19;
                      }
                      goto LAB_14010d7f0;
                    }
                    if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
                       (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
                      FUN_1401c93c0();
                      _Init_thread_footer(&DAT_1437daf04);
                    }
                    FUN_1401cb010(&DAT_1437daf20,puVar1);
                    auVar26 = auVar37._0_16_;
                    goto LAB_14010d7ea;
                  }
                  if (((fVar22 <= *(float *)(param_1 + 0x274c)) ||
                      ((*(byte *)(lVar12 + 0x42c) & 2) == 0)) ||
                     (((*(uint *)(param_1 + 0x2058) & 0x200) != 0 ||
                      (*(char *)(param_1 + 0x278d) == '\0')))) goto LAB_14010d7ea;
                  *(float *)(lVar12 + 0x354) = fVar22;
                  if (fVar22 <= *(float *)(param_1 + 0x2754)) {
                    uVar25 = extraout_XMM0_Qa_01;
                    if (fVar22 < *(float *)(param_1 + 0x2750)) {
                      uVar20 = uVar20 + 1;
                    }
                  }
                  else {
                    cVar9 = FUN_1401c6a00(extraout_XMM0_Qa_01,1,uVar20 & 0xffff,lVar12 + 600,
                                          &local_1a0,uVar40,uVar40,uVar40,auVar35._0_4_,0,0);
                    uVar25 = extraout_XMM0_Qa_02;
                    if (cVar9 != '\0') {
                      lVar14 = FUN_1401c97a0();
                      uVar24 = *(uint *)(lVar12 + 0x350);
                      uVar25 = extraout_XMM0_Qa_03;
                      if ((((uVar24 == 0) || (0x7f < (ushort)uVar24)) ||
                          ((short)(uVar24 >> 0x10) !=
                           *(short *)(lVar14 + 2 + (ulonglong)(uVar24 & 0xffff) * 2))) &&
                         ('\x01' < *(char *)(lVar14 + 0x3dc2))) {
                        uVar2 = *(ushort *)(lVar14 + 0x138);
                        bVar16 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar2 * 0x18) +
                                           0x12 + (ulonglong)(uVar20 & 0xffff) * 0x50);
                        puVar13 = (undefined4 *)FUN_1401c9e60(lVar14);
                        uVar25 = extraout_XMM0_Qa_04;
                        if (puVar13 != (undefined4 *)0x0) {
                          *(ushort *)(puVar13 + 0x11) = uVar2;
                          *(short *)((longlong)puVar13 + 0x46) = (short)uVar20;
                          *puVar13 = *(undefined4 *)(lVar12 + 600);
                          puVar13[1] = *(undefined4 *)(lVar12 + 0x25c);
                          puVar13[2] = *(undefined4 *)(lVar12 + 0x260);
                          uVar33 = *(undefined4 *)(lVar12 + 0x264);
                          puVar13[4] = fVar41;
                          puVar13[5] = fVar42;
                          puVar13[6] = fVar43;
                          puVar13[7] = fVar39;
                          puVar13[3] = uVar33;
                          *(undefined8 *)(puVar13 + 8) = 0;
                          puVar13[10] = 0;
                          *(undefined2 *)((longlong)puVar13 + 0x4a) = 0;
                          puVar13[0xb] = 0x3f800000;
                          puVar13[0xf] = auVar35._0_4_;
                          *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xef | 2;
                          *(undefined4 *)(lVar12 + 0x350) = puVar13[0xe];
                          if ((bVar16 & 1) == 0) {
                            *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfa;
                            uVar20 = uVar20 - 1;
                            *(code **)(puVar13 + 0xc) = FUN_1401caa00;
                          }
                          else {
                            *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfb | 1;
                            uVar20 = uVar20 - 1;
                            *(code **)(puVar13 + 0xc) = FUN_1401ca740;
                          }
                          goto LAB_14010d635;
                        }
                      }
                    }
                    uVar20 = uVar20 - 1;
                  }
LAB_14010d635:
                  cVar9 = FUN_1401c6a00(uVar25,1,uVar20 & 0xffff,lVar12 + 600,&local_1a0,uVar40,
                                        uVar40,uVar40,auVar35._0_4_,0,0);
                  auVar26 = auVar37._0_16_;
                  if (cVar9 == '\0') goto LAB_14010d7ea;
                  lVar14 = FUN_1401c97a0();
                  auVar26 = auVar37._0_16_;
                  uVar24 = *(uint *)(lVar12 + 0x34c);
                  if (((uVar24 == 0) || (0x7f < (ushort)uVar24)) ||
                     ((short)(uVar24 >> 0x10) !=
                      *(short *)(lVar14 + 2 + (ulonglong)(uVar24 & 0xffff) * 2))) {
                    if ('\x01' < *(char *)(lVar14 + 0x3dc2)) {
                      uVar2 = *(ushort *)(lVar14 + 0x138);
                      bVar16 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar2 * 0x18) +
                                         0x12 + (ulonglong)(uVar20 & 0xffff) * 0x50);
                      puVar13 = (undefined4 *)FUN_1401c9e60(lVar14);
                      auVar26 = auVar37._0_16_;
                      if (puVar13 != (undefined4 *)0x0) {
                        *(ushort *)(puVar13 + 0x11) = uVar2;
                        *(short *)((longlong)puVar13 + 0x46) = (short)uVar20;
                        *puVar13 = *(undefined4 *)(lVar12 + 600);
                        puVar13[1] = *(undefined4 *)(lVar12 + 0x25c);
                        puVar13[2] = *(undefined4 *)(lVar12 + 0x260);
                        uVar33 = *(undefined4 *)(lVar12 + 0x264);
                        puVar13[4] = fVar41;
                        puVar13[5] = fVar42;
                        puVar13[6] = fVar43;
                        puVar13[7] = fVar39;
                        puVar13[3] = uVar33;
                        *(undefined8 *)(puVar13 + 8) = 0;
                        puVar13[10] = 0;
                        *(undefined2 *)((longlong)puVar13 + 0x4a) = 0;
                        puVar13[0xb] = 0x3f800000;
                        puVar13[0xf] = auVar35._0_4_;
                        *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xef | 2;
                        *(uint *)(lVar12 + 0x34c) = puVar13[0xe];
                        if ((bVar16 & 1) == 0) {
                          *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfa;
                          *(code **)(puVar13 + 0xc) = FUN_1401caa00;
                        }
                        else {
                          *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfb | 1;
                          *(code **)(puVar13 + 0xc) = FUN_1401ca740;
                        }
                        goto LAB_14010d7f0;
                      }
                    }
                    goto LAB_14010d7ea;
                  }
                }
                else {
LAB_14010d7ea:
                  local_res20 = uVar21;
                }
LAB_14010d7f0:
                fVar23 = *(float *)(param_1 + 0x2738);
                uVar18 = (ulonglong)(uint)fVar23;
                auVar37 = ZEXT1664(auVar34._0_16_);
                if (auVar26._0_4_ < fVar23) {
                  auVar27._0_4_ = auVar26._0_4_ / fVar23;
                  auVar27._4_12_ = auVar26._4_12_;
                  uVar18 = auVar27._0_8_;
                  auVar37 = ZEXT464((uint)(-(*(float *)(param_1 + 0x273c) * auVar27._0_4_) +
                                           *(float *)(param_1 + 0x273c) + auVar34._0_4_));
                }
                cVar9 = FUN_1401c5910(uVar18,lVar12 + 0x348);
                if (cVar9 == '\0') {
                  if ((((*(float *)(param_1 + 0x2730) < fVar22) &&
                       ((*(byte *)(lVar12 + 0x42c) & 8) != 0)) &&
                      ((*(uint *)(param_1 + 0x2058) & 0x200) == 0)) &&
                     ((*(char *)(param_1 + 0x278c) != '\0' &&
                      (cVar9 = FUN_1401c6a00(extraout_XMM0_Qa_05,1,local_res20 & 0xffff,lVar12 + 600
                                             ,&local_1a0,uVar40,uVar40,uVar40,auVar37._0_4_,0,0),
                      cVar9 != '\0')))) {
                    lVar14 = FUN_1401c97a0();
                    uVar21 = *(uint *)(lVar12 + 0x348);
                    if (((uVar21 == 0) ||
                        ((0x7f < (ushort)uVar21 ||
                         ((short)(uVar21 >> 0x10) !=
                          *(short *)(lVar14 + 2 + (ulonglong)(uVar21 & 0xffff) * 2))))) &&
                       ('\x01' < *(char *)(lVar14 + 0x3dc2))) {
                      uVar2 = *(ushort *)(lVar14 + 0x138);
                      bVar16 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar2 * 0x18) +
                                         0x12 + (ulonglong)(local_res20 & 0xffff) * 0x50);
                      puVar13 = (undefined4 *)FUN_1401c9e60(lVar14);
                      if (puVar13 != (undefined4 *)0x0) {
                        *(short *)((longlong)puVar13 + 0x46) = (short)local_res20;
                        *(ushort *)(puVar13 + 0x11) = uVar2;
                        *puVar13 = *(undefined4 *)(lVar12 + 600);
                        puVar13[1] = *(undefined4 *)(lVar12 + 0x25c);
                        puVar13[2] = *(undefined4 *)(lVar12 + 0x260);
                        uVar33 = *(undefined4 *)(lVar12 + 0x264);
                        puVar13[4] = fVar41;
                        puVar13[5] = fVar42;
                        puVar13[6] = fVar43;
                        puVar13[7] = fVar39;
                        puVar13[0xf] = auVar37._0_4_;
                        puVar13[3] = uVar33;
                        *(undefined8 *)(puVar13 + 8) = 0;
                        puVar13[10] = 0;
                        puVar13[0xb] = 0x3f800000;
                        *(undefined2 *)((longlong)puVar13 + 0x4a) = 0;
                        *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xef | 2;
                        *(undefined4 *)(lVar12 + 0x348) = puVar13[0xe];
                        if ((bVar16 & 1) == 0) {
                          *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfa;
                          *(code **)(puVar13 + 0xc) = FUN_1401caa00;
                        }
                        else {
                          *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfb | 1;
                          *(code **)(puVar13 + 0xc) = FUN_1401ca740;
                        }
                      }
                    }
                  }
                }
                else {
                  cVar9 = FUN_1401c6500(extraout_XMM0_Qa_05,lVar12 + 0x348);
                  uVar33 = auVar37._0_4_;
                  if ((cVar9 == '\0') && ((*(byte *)(lVar12 + 0x42c) & 4) != 0)) {
                    if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
                      FUN_14022d540(&DAT_1437daf04);
                      uVar33 = auVar37._0_4_;
                      if (DAT_1437daf04 == -1) {
                        FUN_1401c93c0();
                        _Init_thread_footer(&DAT_1437daf04);
                        uVar33 = auVar37._0_4_;
                      }
                    }
                    uVar21 = *(uint *)(lVar12 + 0x348);
                    if ((((uVar21 != 0) && ((ushort)uVar21 < 0x80)) &&
                        (uVar18 = (ulonglong)(uVar21 & 0xffff),
                        (short)(uVar21 >> 0x10) == *(short *)(&DAT_1437daf22 + uVar18 * 2))) &&
                       (lVar14 = uVar18 * 0x78, ((&DAT_1437db130)[lVar14] & 2) != 0)) {
                      *(undefined4 *)(&DAT_1437db0c0 + uVar18 * 0xf) = *(undefined4 *)(lVar12 + 600)
                      ;
                      *(undefined4 *)((longlong)&DAT_1437db0c0 + lVar14 + 4) =
                           *(undefined4 *)(lVar12 + 0x25c);
                      (&DAT_1437db0c8)[uVar18 * 0x1e] = *(undefined4 *)(lVar12 + 0x260);
                      uVar4 = *(undefined4 *)(lVar12 + 0x264);
                      *(float *)((longlong)&DAT_1437db0cc + lVar14 + 4) = fVar41;
                      *(float *)(&DAT_1437db0d4 + uVar18 * 0xf) = fVar42;
                      *(float *)((longlong)&DAT_1437db0d4 + lVar14 + 4) = fVar43;
                      *(float *)(&DAT_1437db0dc + uVar18 * 0xf) = fVar39;
                      *(undefined4 *)(&DAT_1437db0fc + uVar18 * 0xf) = uVar33;
                      *(undefined4 *)(&DAT_1437db0cc + uVar18 * 0xf) = uVar4;
                      *(undefined8 *)((longlong)&DAT_1437db0dc + lVar14 + 4) = 0;
                      *(undefined4 *)((longlong)&DAT_1437db0e4 + lVar14 + 4) = 0;
                      (&DAT_1437db0ec)[uVar18 * 0x1e] = 0x3f800000;
                      *(undefined2 *)((longlong)&DAT_1437db104 + lVar14 + 6) = 0;
                    }
                  }
                  else {
                    if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
                       (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
                      FUN_1401c93c0();
                      _Init_thread_footer(&DAT_1437daf04);
                    }
                    FUN_1401cb010(&DAT_1437daf20,lVar12 + 0x348);
                  }
                }
              }
            }
          }
          local_18c = local_18c + 1;
          local_e8 = local_e8 + 0x520;
          lVar12 = *(longlong *)(local_130 + local_e0);
        } while (local_18c < *(int *)(lVar12 + 0x118));
      }
      local_188 = local_188 + 1;
      plVar17 = *(longlong **)(param_1 + 0x2040);
      local_130 = local_130 + 8;
    } while (local_188 < (int)(uint)*(byte *)((longlong)plVar17 + 0x34));
    if ((bVar7) &&
       (lVar12 = (ulonglong)*(byte *)(param_1 + 0x20a2) * 0x520,
       (*(byte *)(*(longlong *)
                   (*(longlong *)(*plVar17 + (ulonglong)*(byte *)(param_1 + 0x20a1) * 8) + 0x110) +
                  0x1f0 + lVar12) & 2) != 0)) {
      cVar10 = FUN_1401c6260(lVar12,param_1 + 0x2078,param_1 + 0x70);
      if (cVar10 == '\0') {
        local_1a0 = _DAT_1402d35f0;
        uStack_198 = _UNK_1402d35f8;
        cVar10 = FUN_1401c6a00(_DAT_1402d35f0,1,0x99,param_1 + 0x70,&local_1a0,uVar40,uVar40,uVar40,
                               uVar40,0,0);
        if (cVar10 != '\0') {
          lVar12 = FUN_1401c97a0();
          uVar21 = *(uint *)(param_1 + 0x2078);
          if ((((uVar21 == 0) || (0x7f < (ushort)uVar21)) ||
              ((short)(uVar21 >> 0x10) != *(short *)(lVar12 + 2 + (ulonglong)(uVar21 & 0xffff) * 2))
              ) && ('\x01' < *(char *)(lVar12 + 0x3dc2))) {
            uVar2 = *(ushort *)(lVar12 + 0x138);
            bVar16 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar2 * 0x18) + 0x2fe2);
            puVar13 = (undefined4 *)FUN_1401c9e60(lVar12);
            if (puVar13 != (undefined4 *)0x0) {
              *(ushort *)(puVar13 + 0x11) = uVar2;
              *(undefined2 *)((longlong)puVar13 + 0x46) = 0x99;
              *puVar13 = *(undefined4 *)(param_1 + 0x70);
              puVar13[1] = *(undefined4 *)(param_1 + 0x74);
              puVar13[2] = *(undefined4 *)(param_1 + 0x78);
              puVar13[3] = *(undefined4 *)(param_1 + 0x7c);
              *(undefined8 *)(puVar13 + 4) = 0;
              puVar13[6] = 0;
              *(undefined8 *)(puVar13 + 7) = 0x3f800000;
              *(undefined8 *)(puVar13 + 9) = 0;
              puVar13[0xb] = 0x3f800000;
              puVar13[0xf] = 0x3f800000;
              *(undefined2 *)((longlong)puVar13 + 0x4a) = 0;
              *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xef | 2;
              *(undefined4 *)(param_1 + 0x2078) = puVar13[0xe];
              if ((bVar16 & 1) == 0) {
                *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfa;
                *(code **)(puVar13 + 0xc) = FUN_1401caa00;
              }
              else {
                *(byte *)(puVar13 + 0x1c) = *(byte *)(puVar13 + 0x1c) & 0xfb | 1;
                *(code **)(puVar13 + 0xc) = FUN_1401ca740;
              }
            }
          }
        }
      }
      goto LAB_14010de1f;
    }
  }
  if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
     (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
    FUN_1401c93c0();
    _Init_thread_footer(&DAT_1437daf04);
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2078);
LAB_14010de1f:
  *(uint *)(param_1 + 0x2058) = *(uint *)(param_1 + 0x2058) & 0xfffffdff;
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

