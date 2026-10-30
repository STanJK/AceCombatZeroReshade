/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140136540; RVA 0x136540
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140136540(longlong *param_1,longlong param_2,char param_3)

{
  ushort *puVar1;
  int iVar2;
  float *pfVar3;
  longlong lVar4;
  undefined1 auVar5 [16];
  char cVar6;
  float fVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong lVar12;
  float *pfVar13;
  undefined8 *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined1 extraout_var_01 [56];
  undefined1 extraout_var_02 [56];
  undefined1 extraout_var_03 [56];
  undefined1 auVar19 [64];
  undefined8 uVar20;
  float fVar21;
  undefined4 uVar22;
  undefined1 in_ZMM6 [64];
  float fVar23;
  float fVar24;
  undefined1 auVar25 [16];
  undefined1 auVar26 [64];
  undefined4 uVar27;
  undefined4 uVar28;
  undefined1 in_ZMM8 [64];
  undefined1 auVar29 [64];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [64];
  float fVar34;
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  float fVar37;
  undefined1 in_ZMM11 [64];
  undefined1 auVar38 [64];
  undefined1 auVar39 [16];
  undefined1 in_ZMM12 [64];
  undefined1 auVar40 [64];
  undefined4 uVar41;
  undefined1 auVar42 [16];
  undefined1 in_ZMM13 [64];
  undefined1 auVar43 [64];
  undefined4 uVar44;
  undefined1 in_ZMM14 [64];
  undefined1 auVar45 [64];
  undefined4 uVar46;
  undefined1 in_ZMM15 [64];
  undefined1 auVar47 [64];
  undefined1 auVar48 [64];
  undefined1 auStack_2d8 [32];
  undefined4 *local_2b8;
  longlong local_2b0;
  undefined4 local_2a8;
  undefined4 local_2a0;
  undefined4 local_298;
  uint local_288;
  char local_284;
  float local_280;
  float local_27c;
  float local_278;
  uint local_274;
  longlong local_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  float local_248 [4];
  float local_238;
  float local_234;
  float local_230;
  float local_22c;
  int local_228;
  undefined1 local_220 [24];
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  uint local_1f0;
  float local_1ec;
  float local_1e8;
  uint local_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  longlong local_1c8;
  longlong local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  float local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 local_198 [16];
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_68 [16];
  undefined1 local_48 [16];
  
  local_e8 = DAT_140309040 ^ (ulonglong)auStack_2d8;
  *(uint *)(*(longlong *)*param_1 + 0x120) = *(uint *)(*(longlong *)*param_1 + 0x120) | 7;
  lVar12 = DAT_14032c8b8;
  if (*(char *)(param_2 + 0x38) == '\0') {
    *(uint *)(DAT_14032c8b8 + 0xd0) = *(uint *)(DAT_14032c8b8 + 0xd0) | 0x100;
    *(undefined1 *)(lVar12 + 0x10f) = 0x73;
  }
  local_228 = 1;
  if (*(byte *)((longlong)param_1 + 0x34) < 2) {
LAB_140137860:
    if (*(char *)(param_2 + 0x38) != '\0') {
      DAT_14032844c = DAT_14032844c & 0xfffffffb;
    }
    return 1;
  }
  local_48 = in_ZMM6._0_16_;
  auVar26 = ZEXT464(DAT_1402d271c);
  local_68 = in_ZMM8._0_16_;
  auVar33 = ZEXT464((uint)DAT_1402d22d0);
  local_98 = in_ZMM11._0_16_;
  local_a8 = in_ZMM12._0_16_;
  local_b8 = in_ZMM13._0_16_;
  local_c8 = in_ZMM14._0_16_;
  local_d8 = in_ZMM15._0_16_;
  local_274 = DAT_1402d271c;
  local_1c8 = 1;
  local_1c0 = 8;
  auVar47 = ZEXT864(0);
  local_284 = param_3;
  local_270 = param_2;
LAB_140136675:
  uVar15 = 0;
  lVar12 = *param_1;
  if ((*(char *)(**(longlong **)(*(longlong *)(lVar12 + local_1c0) + 0x130) + 0xe) == param_3) &&
     (local_288 = 0, 0 < *(int *)(*(longlong *)(lVar12 + local_1c0) + 0x118))) {
    uVar16 = uVar15;
LAB_1401366aa:
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + local_1c8 * 8) + 0x110);
    pfVar3 = *(float **)(lVar12 + 0x3c8 + uVar16);
    uVar8 = (uint)uVar15;
    if (pfVar3 != (float *)0x0) {
      if (pfVar3[0xd] == -NAN) {
        do {
          auVar26 = ZEXT1664(auVar26._0_16_);
          auVar33 = ZEXT1664(auVar33._0_16_);
          auVar47 = ZEXT1664(auVar47._0_16_);
          FUN_14000ee20(pfVar3);
        } while (*(int *)(*(longlong *)(pfVar3 + 0xe) + 0x24) == 0);
        pfVar3[0xb] = 1.4013e-45;
      }
      auVar17 = auVar26._0_16_;
      cVar6 = *(char *)(pfVar3 + 8);
      while( true ) {
        if ((cVar6 == '\0') ||
           (auVar17 = auVar26._0_16_,
           (int)pfVar3[0xb] < *(int *)(*(longlong *)(pfVar3 + 0xe) + 0x24))) break;
        auVar26 = ZEXT1664(auVar17);
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        FUN_14000ee20(pfVar3);
        auVar17 = auVar26._0_16_;
        cVar6 = *(char *)(pfVar3 + 8);
      }
      if (*(longlong *)(pfVar3 + 0x10) != 0) {
        auVar26 = ZEXT1664(auVar17);
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        FUN_14017ec40();
        auVar17 = auVar26._0_16_;
      }
      if (*(longlong *)(pfVar3 + 0x12) != 0) {
        auVar26 = ZEXT1664(auVar17);
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        FUN_14017ec40();
        auVar17 = auVar26._0_16_;
      }
      pfVar3[0xb] = (float)((int)pfVar3[0xb] + 1);
      lVar9 = *(longlong *)(pfVar3 + 0x10);
      auVar25 = auVar47._0_16_;
      auVar30 = auVar33._0_16_;
      if (lVar9 != 0) {
        iVar2 = *(int *)(lVar9 + 0x194);
        if ((*(uint *)(lVar12 + 0x1f0 + uVar16) & 0x4000000) != 0) {
          uVar8 = local_288;
          if (iVar2 == -0x80000000) {
            *(undefined8 *)(lVar12 + 0x268 + uVar16) = 0;
            *(undefined4 *)(lVar12 + 0x270 + uVar16) = 0;
            *(undefined8 *)(lVar12 + 600 + uVar16) = 0;
            *(undefined4 *)(lVar12 + 0x260 + uVar16) = 0;
          }
          goto LAB_14013777e;
        }
        local_27c = auVar47._0_4_;
        local_280 = auVar33._0_4_;
        auVar36 = auVar30;
        if (iVar2 == -0x7fffffff) {
          local_27c = *(float *)(lVar9 + 0x1a8);
          local_278 = *(float *)(lVar9 + 0x1b0);
          auVar18 = ZEXT416((uint)local_278);
          auVar31 = ZEXT416((uint)local_27c);
          auVar39 = ZEXT416(*(uint *)(lVar9 + 0x1ac));
          auVar42 = ZEXT416(*(uint *)(lVar9 + 0x19c));
          auVar32 = ZEXT416(*(uint *)(lVar9 + 0x198));
          auVar35 = ZEXT416(*(uint *)(lVar9 + 0x1a0));
        }
        else {
          auVar18 = auVar25;
          auVar31 = auVar25;
          auVar39 = auVar25;
          auVar42 = auVar25;
          auVar32 = auVar25;
          auVar35 = auVar25;
          local_278 = local_27c;
          if ((iVar2 + 0x80000000U & 0xfffffffd) != 0) {
            lVar10 = lVar9 + 0x90;
            while( true ) {
              auVar17 = auVar25;
              auVar30 = auVar25;
              auVar36 = auVar25;
              if (lVar10 == 0) break;
              if (*(int *)(lVar10 + 0xdc) == **(int **)(lVar9 + 0x1d8)) {
                auVar18 = ZEXT416(*(uint *)(lVar10 + 0x60));
                auVar42 = ZEXT416(*(uint *)(lVar10 + 0x70));
                auVar30 = ZEXT416(*(uint *)(lVar10 + 0x44));
                auVar36 = ZEXT416(*(uint *)(lVar10 + 0x54));
                auVar17 = ZEXT416(*(uint *)(lVar10 + 100));
                auVar39 = ZEXT416(*(uint *)(lVar10 + 0x74));
                auVar31 = ZEXT416(*(uint *)(lVar10 + 0x68));
                auVar32 = ZEXT416(*(uint *)(lVar10 + 0x78));
                break;
              }
              lVar10 = *(longlong *)(lVar10 + 0xf0);
            }
            auVar17 = vmaxss_avx(auVar17,ZEXT416(DAT_1402d2d64));
            auVar17 = vminss_avx(auVar17,ZEXT416((uint)DAT_1402d22d0));
            auVar17 = vmaxss_avx(auVar17,ZEXT416(DAT_1402d2d64));
            vminss_avx(auVar17,ZEXT416((uint)DAT_1402d22d0));
            auVar26 = ZEXT1664(auVar30);
            auVar33 = ZEXT1664(auVar36);
            auVar47 = ZEXT1664(auVar18);
            auVar19 = ZEXT1664(auVar31);
            auVar29 = ZEXT1664(auVar25);
            auVar40 = ZEXT1664(auVar39);
            auVar43 = ZEXT1664(auVar42);
            auVar45 = ZEXT1664(auVar32);
            uVar8 = FUN_140272150();
            local_27c = (float)(uVar8 ^ DAT_1402d3770);
            auVar38 = ZEXT1664(CONCAT412(extraout_var._4_4_ ^ _UNK_1402d377c,
                                         CONCAT48(extraout_var._0_4_ ^ _UNK_1402d3778,
                                                  (ulonglong)(uint)local_27c)));
            auVar47._0_8_ = FUN_140272370(auVar47._0_8_,auVar19._0_8_);
            auVar47._8_56_ = extraout_var_00;
            auVar47 = ZEXT1664(auVar47._0_16_);
            auVar26._0_8_ = FUN_140272370(auVar26._0_8_,auVar33._0_8_);
            auVar35 = auVar45._0_16_;
            auVar32 = auVar43._0_16_;
            auVar42 = auVar40._0_16_;
            auVar39 = auVar47._0_16_;
            auVar31 = auVar38._0_16_;
            auVar25 = auVar29._0_16_;
            auVar26._8_56_ = extraout_var_01;
            auVar30 = ZEXT416((uint)local_280);
            auVar17 = ZEXT416(local_274);
            auVar36 = ZEXT416((uint)DAT_1402d22d0);
            local_278 = (float)auVar26._0_8_;
            auVar18 = auVar26._0_16_;
          }
        }
        lVar10 = *(longlong *)(param_2 + 0x28);
        if (((lVar10 != 0) && (*(longlong *)(lVar9 + 0x88) != 0)) &&
           ((*(ushort *)(*(longlong *)(lVar9 + 0x88) + 0x58) & 0x10) != 0)) {
          auVar32 = ZEXT416((uint)(auVar32._0_4_ + *(float *)(lVar10 + 600)));
          auVar42 = ZEXT416((uint)(auVar42._0_4_ + *(float *)(lVar10 + 0x25c)));
          auVar35 = ZEXT416((uint)(auVar35._0_4_ + *(float *)(lVar10 + 0x260)));
        }
        auVar26 = ZEXT1664(auVar18);
        auVar19 = ZEXT1664(auVar17);
        auVar29 = ZEXT1664(auVar30);
        auVar33 = ZEXT1664(auVar36);
        auVar47 = ZEXT1664(auVar25);
        auVar38 = ZEXT1664(auVar31);
        auVar40 = ZEXT1664(auVar42);
        auVar43 = ZEXT1664(auVar32);
        auVar45 = ZEXT1664(auVar35);
        auVar48 = ZEXT1664(auVar39);
        FUN_140010340(pfVar3,1);
        auVar18 = auVar40._0_16_;
        auVar42 = auVar48._0_16_;
        auVar39 = auVar45._0_16_;
        auVar31 = auVar43._0_16_;
        auVar25 = auVar29._0_16_;
        auVar36 = auVar38._0_16_;
        auVar17 = auVar26._0_16_;
        auVar30 = auVar19._0_16_;
        if (*pfVar3 == DAT_1402d2c40) {
          fVar23 = auVar47._0_4_;
          auVar32 = auVar47._0_16_;
          fVar34 = fVar23;
          fVar7 = fVar23;
        }
        else {
          fVar34 = auVar40._0_4_ - pfVar3[1];
          fVar7 = auVar45._0_4_ - pfVar3[2];
          pfVar3[7] = auVar33._0_4_ - pfVar3[3];
          fVar23 = auVar43._0_4_ - *pfVar3;
          auVar32 = auVar33._0_16_;
        }
        pfVar3[4] = fVar23;
        pfVar3[5] = fVar34;
        pfVar3[6] = fVar7;
        pfVar3[7] = auVar32._0_4_;
        pfVar3[3] = 1.0;
        local_188 = 0;
        uStack_180 = 0;
        uStack_178 = 0;
        uStack_170 = 0;
        local_168 = 0;
        uStack_160 = 0;
        uStack_158 = 0;
        uStack_150 = 0;
        local_148 = 0;
        uStack_140 = 0;
        uStack_138 = 0;
        uStack_130 = 0;
        *pfVar3 = auVar43._0_4_;
        pfVar3[1] = auVar40._0_4_;
        pfVar3[2] = auVar45._0_4_;
        lVar9 = *(longlong *)(pfVar3 + 0x12);
        local_128 = 0;
        uStack_120 = 0;
        uStack_118 = 0;
        uStack_110 = 0;
        local_108 = 0;
        uStack_100 = 0;
        uStack_f8 = 0;
        uStack_f0 = 0;
        if ((lVar9 != 0) && (*(int *)(lVar9 + 0x1c8) == 0)) {
          for (lVar9 = lVar9 + 0x90; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0xf0)) {
            if (*(int *)(lVar9 + 0xdc) == 0) goto joined_r0x000140136a30;
          }
        }
        goto LAB_140136a95;
      }
      lVar12 = *(longlong *)(pfVar3 + 0x1e);
      if ((lVar12 != 0) && (*(char *)(lVar12 + 0x1c) != '\0')) {
        auVar33 = ZEXT1664(auVar30);
        auVar47 = ZEXT1664(auVar25);
        FUN_140012070(lVar12,*(undefined8 *)(param_2 + 0x10));
      }
      goto LAB_140137776;
    }
    goto LAB_14013777e;
  }
  goto LAB_1401377b6;
joined_r0x000140136a30:
  for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0xf0)) {
    if (*(char *)(lVar9 + 0x9c) == '!') {
      fVar34 = *(float *)(lVar9 + 0x94);
      fVar7 = *(float *)(lVar9 + 0x98);
      if (*(char *)(lVar9 + 0x9d) < 'X') {
        local_248[*(char *)(lVar9 + 0x9d)] = *(float *)(lVar9 + 0x90);
      }
      if (*(char *)(lVar9 + 0x9e) < 'X') {
        local_248[*(char *)(lVar9 + 0x9e)] = fVar34;
      }
      if (*(char *)(lVar9 + 0x9f) < 'X') {
        local_248[*(char *)(lVar9 + 0x9f)] = fVar7;
      }
    }
  }
LAB_140136a95:
  fVar34 = pfVar3[10];
  pfVar13 = pfVar3;
  if (fVar34 == 0.0) {
    lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
    if (lVar9 != 0) {
      if (*(longlong *)(lVar9 + 0x1b8) == 0) {
        if (*(longlong *)(lVar9 + 0x1c0) == 0) {
          pfVar3[10] = 2.8026e-45;
          fVar34 = 2.8026e-45;
        }
        else {
          pfVar3[10] = 4.2039e-45;
          fVar34 = 4.2039e-45;
        }
      }
      else {
        pfVar3[10] = 5.60519e-45;
        fVar34 = 5.60519e-45;
      }
      goto LAB_140136ac6;
    }
    pfVar3[10] = 1.4013e-45;
LAB_140136b3b:
    plVar11 = *(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390);
LAB_140136b46:
    if (plVar11 != (longlong *)0x0) {
LAB_140136b4b:
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar30);
      auVar29 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar33._0_16_);
      auVar47 = ZEXT1664(auVar47._0_16_);
      auVar38 = ZEXT1664(auVar36);
      auVar40 = ZEXT1664(auVar18);
      auVar43 = ZEXT1664(auVar31);
      auVar45 = ZEXT1664(auVar39);
      auVar48 = ZEXT1664(auVar42);
      (**(code **)(*plVar11 + 0x150))();
      auVar18 = auVar40._0_16_;
      auVar42 = auVar48._0_16_;
      auVar39 = auVar45._0_16_;
      auVar31 = auVar43._0_16_;
      auVar25 = auVar29._0_16_;
      auVar36 = auVar38._0_16_;
      auVar17 = auVar26._0_16_;
      auVar30 = auVar19._0_16_;
    }
  }
  else {
LAB_140136ac6:
    if (fVar34 == 1.4013e-45) goto LAB_140136b3b;
    if (fVar34 == 2.8026e-45) {
      plVar11 = *(longlong **)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x390);
      goto LAB_140136b46;
    }
    if (fVar34 == 4.2039e-45) {
      plVar11 = *(longlong **)
                 (*(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1c0) + 0x10)
      ;
      goto LAB_140136b4b;
    }
    if (fVar34 == 5.60519e-45) {
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1b8);
      puVar1 = (ushort *)(lVar9 + 0xae4);
      *puVar1 = *puVar1 | 1;
      *(undefined4 *)(lVar9 + 0xb20) = (undefined4)uStack_f0;
    }
  }
  fVar34 = auVar47._0_4_;
  if (fVar34 < uStack_150._4_4_) {
    fVar7 = pfVar3[10];
    if (fVar7 == 0.0) {
      lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
      if (lVar9 == 0) {
        pfVar3[10] = 1.4013e-45;
        goto LAB_140136bc2;
      }
      if (*(longlong *)(lVar9 + 0x1b8) == 0) {
        if (*(longlong *)(lVar9 + 0x1c0) == 0) {
          pfVar3[10] = 2.8026e-45;
          fVar7 = 2.8026e-45;
        }
        else {
          pfVar3[10] = 4.2039e-45;
          fVar7 = 4.2039e-45;
        }
      }
      else {
        pfVar3[10] = 5.60519e-45;
        fVar7 = 5.60519e-45;
      }
    }
    if (fVar7 == 5.60519e-45) {
      puVar1 = (ushort *)
               (*(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1b8) + 0xae4);
      *puVar1 = *puVar1 | 2;
    }
  }
LAB_140136bc2:
  fVar7 = pfVar3[10];
  if (fVar7 == 0.0) {
    lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
    if (lVar9 != 0) {
      if (*(longlong *)(lVar9 + 0x1b8) == 0) {
        if (*(longlong *)(lVar9 + 0x1c0) == 0) {
          pfVar3[10] = 2.8026e-45;
          fVar7 = 2.8026e-45;
        }
        else {
          pfVar3[10] = 4.2039e-45;
          fVar7 = 4.2039e-45;
        }
      }
      else {
        pfVar3[10] = 5.60519e-45;
        fVar7 = 5.60519e-45;
      }
      goto LAB_140136bf7;
    }
    pfVar3[10] = 1.4013e-45;
LAB_140136ceb:
    plVar11 = *(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390);
LAB_140136cf6:
    if (plVar11 != (longlong *)0x0) {
      lVar9 = *plVar11;
LAB_140136d0b:
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar30);
      auVar29 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar33._0_16_);
      auVar47 = ZEXT1664(auVar47._0_16_);
      auVar38 = ZEXT1664(auVar36);
      auVar40 = ZEXT1664(auVar18);
      auVar43 = ZEXT1664(auVar31);
      auVar45 = ZEXT1664(auVar39);
      auVar48 = ZEXT1664(auVar42);
      (**(code **)(lVar9 + 0x138))();
      auVar18 = auVar40._0_16_;
      auVar42 = auVar48._0_16_;
      auVar39 = auVar45._0_16_;
      auVar31 = auVar43._0_16_;
      auVar25 = auVar29._0_16_;
      auVar36 = auVar38._0_16_;
      auVar17 = auVar26._0_16_;
      auVar30 = auVar19._0_16_;
    }
  }
  else {
LAB_140136bf7:
    if (fVar7 == 1.4013e-45) goto LAB_140136ceb;
    if (fVar7 == 2.8026e-45) {
      plVar11 = *(longlong **)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x390);
      goto LAB_140136cf6;
    }
    if (fVar7 == 4.2039e-45) {
      pfVar13 = *(float **)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1c0);
      lVar9 = **(longlong **)(pfVar13 + 4);
      goto LAB_140136d0b;
    }
    if (fVar7 == 5.60519e-45) {
      pfVar13 = *(float **)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1b8);
      if ((*(byte *)(*(longlong *)(pfVar13 + 0x3fe) + 0xc) & 1) != 0) {
        fVar34 = uStack_158._4_4_;
      }
      pfVar13[0x2c0] = 0.0;
      pfVar13[0x2c1] = fVar34;
    }
  }
  uVar22 = (undefined4)((ulonglong)pfVar13 >> 0x20);
  fVar34 = pfVar3[10];
  lVar9 = param_1[4];
  auVar32 = auVar33._0_16_;
  auVar35 = auVar47._0_16_;
  if (fVar34 == 0.0) {
    lVar10 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
    if (lVar10 != 0) {
      if (*(longlong *)(lVar10 + 0x1b8) == 0) {
        if (*(longlong *)(lVar10 + 0x1c0) == 0) {
          pfVar3[10] = 2.8026e-45;
          fVar34 = 2.8026e-45;
        }
        else {
          pfVar3[10] = 4.2039e-45;
          fVar34 = 4.2039e-45;
        }
      }
      else {
        pfVar3[10] = 5.60519e-45;
        fVar34 = 5.60519e-45;
      }
      goto LAB_140136d50;
    }
    pfVar3[10] = 1.4013e-45;
LAB_140136e59:
    lVar10 = *(longlong *)(pfVar3 + 0x16);
LAB_140136e5d:
    if (*(longlong *)(lVar10 + 0x390) != 0) {
      local_2b0 = lVar10 + 0x268;
      local_2b8 = (undefined4 *)(lVar10 + 600);
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar30);
      auVar29 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar32);
      auVar47 = ZEXT1664(auVar35);
      auVar38 = ZEXT1664(auVar36);
      auVar40 = ZEXT1664(auVar18);
      auVar43 = ZEXT1664(auVar31);
      auVar45 = ZEXT1664(auVar39);
      auVar48 = ZEXT1664(auVar42);
      FUN_140010c30(pfVar3,lVar9);
      auVar18 = auVar40._0_16_;
      auVar39 = auVar45._0_16_;
      auVar31 = auVar43._0_16_;
      auVar42 = auVar48._0_16_;
      auVar25 = auVar29._0_16_;
      auVar17 = auVar26._0_16_;
      auVar36 = auVar38._0_16_;
      uVar22 = (undefined4)((ulonglong)lVar9 >> 0x20);
      auVar30 = auVar19._0_16_;
    }
  }
  else {
LAB_140136d50:
    if (fVar34 == 1.4013e-45) goto LAB_140136e59;
    if (fVar34 == 2.8026e-45) {
      lVar10 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
      goto LAB_140136e5d;
    }
    if (fVar34 == 4.2039e-45) {
      lVar10 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
      local_2b8 = (undefined4 *)(lVar10 + 600);
      local_2b0 = lVar10 + 0x268;
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar30);
      auVar29 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar32);
      auVar47 = ZEXT1664(auVar35);
      auVar38 = ZEXT1664(auVar36);
      auVar40 = ZEXT1664(auVar18);
      auVar43 = ZEXT1664(auVar31);
      auVar45 = ZEXT1664(auVar39);
      auVar48 = ZEXT1664(auVar42);
      FUN_140010c30(pfVar3,lVar9,lVar9,*(undefined8 *)(*(longlong *)(lVar10 + 0x1c0) + 0x10));
      auVar18 = auVar40._0_16_;
      auVar39 = auVar45._0_16_;
      auVar31 = auVar43._0_16_;
      auVar42 = auVar48._0_16_;
      auVar25 = auVar29._0_16_;
      auVar17 = auVar26._0_16_;
      auVar36 = auVar38._0_16_;
      uVar22 = (undefined4)((ulonglong)lVar9 >> 0x20);
      auVar30 = auVar19._0_16_;
    }
    else if (fVar34 == 5.60519e-45) {
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1b8);
      local_2b8 = (undefined4 *)(lVar10 + 0x70);
      local_2b0 = lVar10 + 0x80;
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar30);
      auVar29 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar32);
      auVar47 = ZEXT1664(auVar35);
      auVar38 = ZEXT1664(auVar36);
      auVar40 = ZEXT1664(auVar18);
      auVar43 = ZEXT1664(auVar31);
      auVar45 = ZEXT1664(auVar39);
      auVar48 = ZEXT1664(auVar42);
      FUN_1400108b0(pfVar3,lVar9,lVar9,lVar10 + 0x110);
      auVar18 = auVar40._0_16_;
      auVar39 = auVar45._0_16_;
      auVar31 = auVar43._0_16_;
      auVar42 = auVar48._0_16_;
      auVar25 = auVar29._0_16_;
      auVar17 = auVar26._0_16_;
      auVar36 = auVar38._0_16_;
      uVar22 = (undefined4)((ulonglong)lVar9 >> 0x20);
      auVar30 = auVar19._0_16_;
    }
  }
  fVar34 = pfVar3[10];
  if (fVar34 == 0.0) {
    lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
    if (lVar9 != 0) {
      if (*(longlong *)(lVar9 + 0x1b8) == 0) {
        if (*(longlong *)(lVar9 + 0x1c0) == 0) {
          pfVar3[10] = 2.8026e-45;
          fVar34 = 2.8026e-45;
        }
        else {
          pfVar3[10] = 4.2039e-45;
          fVar34 = 4.2039e-45;
        }
      }
      else {
        pfVar3[10] = 5.60519e-45;
        fVar34 = 5.60519e-45;
      }
      goto LAB_140136ec9;
    }
    pfVar3[10] = 1.4013e-45;
LAB_140136f9d:
    plVar11 = *(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390);
LAB_140136fa8:
    if (plVar11 != (longlong *)0x0) {
LAB_140136fad:
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar30);
      auVar29 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar33._0_16_);
      auVar47 = ZEXT1664(auVar47._0_16_);
      auVar38 = ZEXT1664(auVar36);
      auVar40 = ZEXT1664(auVar18);
      auVar43 = ZEXT1664(auVar31);
      auVar45 = ZEXT1664(auVar39);
      auVar48 = ZEXT1664(auVar42);
      (**(code **)(*plVar11 + 0x148))();
      auVar18 = auVar40._0_16_;
      auVar39 = auVar45._0_16_;
      auVar31 = auVar43._0_16_;
      auVar42 = auVar48._0_16_;
      auVar25 = auVar29._0_16_;
      auVar17 = auVar26._0_16_;
      auVar36 = auVar38._0_16_;
      auVar30 = auVar19._0_16_;
    }
  }
  else {
LAB_140136ec9:
    if (fVar34 == 1.4013e-45) goto LAB_140136f9d;
    if (fVar34 == 2.8026e-45) {
      plVar11 = *(longlong **)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x390);
      goto LAB_140136fa8;
    }
    if (fVar34 == 4.2039e-45) {
      plVar11 = *(longlong **)
                 (*(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1c0) + 0x10)
      ;
      goto LAB_140136fad;
    }
    if (fVar34 == 5.60519e-45) {
      *(undefined4 *)
       (*(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1b8) + 0xb30) =
           (undefined4)local_148;
    }
  }
  uVar28 = auVar17._0_4_;
  uVar41 = auVar36._0_4_;
  pfVar3[9] = (float)(int)(local_148._4_4_ + DAT_1402d1ff8);
  if (auVar47._0_4_ < uStack_140._4_4_) {
    lVar9 = param_1[4];
    auVar32 = *(undefined1 (*) [16])(*(longlong *)(pfVar3 + 0x16) + 600);
    local_2b8 = &local_1b8;
    local_220._0_16_ = ZEXT816(0);
    auVar35 = vshufps_avx(auVar32,auVar32,0xff);
    auVar5 = vshufps_avx(auVar32,auVar32,0xaa);
    local_1ac = auVar35._0_4_;
    local_1b8 = auVar32._0_4_;
    auVar32 = vshufps_avx(auVar32,auVar32,0x55);
    local_1a4 = auVar32._0_4_ + DAT_1402d2698;
    local_1b4 = DAT_1402d2e2c;
    local_1b0 = auVar5._0_4_;
    local_280 = 0.0;
    auVar26 = ZEXT1664(auVar17);
    auVar19 = ZEXT1664(auVar30);
    auVar29 = ZEXT1664(auVar25);
    auVar33 = ZEXT1664(auVar33._0_16_);
    auVar47 = ZEXT1664(auVar47._0_16_);
    auVar38 = ZEXT1664(auVar36);
    auVar40 = ZEXT1664(auVar18);
    auVar43 = ZEXT1664(auVar31);
    auVar45 = ZEXT1664(auVar39);
    auVar48 = ZEXT1664(auVar42);
    local_1a8 = local_1b8;
    local_1a0 = local_1b0;
    local_19c = local_1ac;
    uVar8 = FUN_1400782c0(*(undefined8 *)(*(longlong *)(pfVar3 + 0x1a) + 0x18),local_220,&local_280,
                          &local_1a8);
    lVar10 = *(longlong *)(pfVar3 + 0x16);
    uVar22 = 0;
    auVar17 = vpcmpeqd_avx(ZEXT416(uVar8),ZEXT416(0));
    auVar17 = vblendvps_avx(ZEXT416((uint)local_220._4_4_),auVar47._0_16_,auVar17);
    local_248[0] = *(float *)(lVar10 + 0x25c) - auVar17._0_4_;
    local_268 = *(undefined8 *)(lVar10 + 600);
    uStack_260 = *(undefined8 *)(lVar10 + 0x260);
    uStack_258 = *(undefined8 *)(*(longlong *)(lVar10 + 0x3c8) + 0x10);
    uStack_250 = *(undefined8 *)(*(longlong *)(lVar10 + 0x3c8) + 0x18);
    local_248[2] = local_280;
    local_248[1] = 0.0;
    auVar26 = ZEXT1664(auVar26._0_16_);
    auVar19 = ZEXT1664(auVar19._0_16_);
    auVar29 = ZEXT1664(auVar29._0_16_);
    auVar33 = ZEXT1664(auVar33._0_16_);
    auVar47 = ZEXT1664(auVar47._0_16_);
    auVar38 = ZEXT1664(auVar38._0_16_);
    auVar40 = ZEXT1664(auVar40._0_16_);
    auVar43 = ZEXT1664(auVar43._0_16_);
    auVar45 = ZEXT1664(auVar45._0_16_);
    auVar48 = ZEXT1664(auVar48._0_16_);
    FUN_140031f80(*(undefined8 *)(lVar9 + 0x66ee0),5,&local_268,0);
    auVar18 = auVar40._0_16_;
    auVar39 = auVar45._0_16_;
    auVar31 = auVar43._0_16_;
    auVar42 = auVar48._0_16_;
    auVar25 = auVar29._0_16_;
    uVar28 = auVar26._0_4_;
    uVar41 = auVar38._0_4_;
    auVar30 = auVar19._0_16_;
  }
  fVar34 = pfVar3[10];
  auVar17 = auVar47._0_16_;
  fVar7 = auVar47._0_4_;
  if (fVar34 == 0.0) {
    lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
    if (lVar9 != 0) {
      if (*(longlong *)(lVar9 + 0x1b8) == 0) {
        if (*(longlong *)(lVar9 + 0x1c0) == 0) {
          pfVar3[10] = 2.8026e-45;
          fVar34 = 2.8026e-45;
        }
        else {
          pfVar3[10] = 4.2039e-45;
          fVar34 = 4.2039e-45;
        }
      }
      else {
        pfVar3[10] = 5.60519e-45;
        fVar34 = 5.60519e-45;
      }
      goto LAB_140137170;
    }
    pfVar3[10] = 1.4013e-45;
LAB_140137182:
    lVar9 = *(longlong *)(lVar12 + 0x3a8 + uVar16);
    *(undefined4 *)(lVar12 + 0x274 + uVar16) = 0;
    *(undefined4 *)(lVar12 + 0x264 + uVar16) = 0x3f800000;
    *(undefined4 *)(lVar12 + 0x268 + uVar16) = uVar41;
    *(int *)(lVar12 + 0x26c + uVar16) = auVar42._0_4_;
    *(undefined4 *)(lVar12 + 0x270 + uVar16) = uVar28;
    *(int *)(lVar12 + 600 + uVar16) = auVar31._0_4_;
    *(float *)(lVar12 + 0x25c + uVar16) = auVar18._0_4_;
    *(int *)(lVar12 + 0x260 + uVar16) = auVar39._0_4_;
    if (lVar9 != 0) {
      *(undefined4 *)(lVar9 + 0x268) = uVar41;
      *(undefined4 *)(lVar9 + 0x26c) = *(undefined4 *)(lVar12 + 0x26c + uVar16);
      *(undefined4 *)(lVar9 + 0x270) = *(undefined4 *)(lVar12 + 0x270 + uVar16);
      *(undefined4 *)(lVar9 + 0x274) = *(undefined4 *)(lVar12 + 0x274 + uVar16);
      lVar9 = *(longlong *)(lVar12 + 0x3a8 + uVar16);
      *(undefined4 *)(lVar9 + 600) = *(undefined4 *)(lVar12 + 600 + uVar16);
      *(undefined4 *)(lVar9 + 0x25c) = *(undefined4 *)(lVar12 + 0x25c + uVar16);
      *(undefined4 *)(lVar9 + 0x260) = *(undefined4 *)(lVar12 + 0x260 + uVar16);
      *(undefined4 *)(lVar9 + 0x264) = *(undefined4 *)(lVar12 + 0x264 + uVar16);
    }
    plVar11 = *(longlong **)(lVar12 + 0x390 + uVar16);
    if (plVar11 == (longlong *)0x0) goto LAB_140137746;
    lVar9 = *(longlong *)(lVar12 + 0x3a8 + uVar16);
    auVar25 = auVar33._0_16_;
    if (lVar9 == 0) {
      if (*(longlong *)(lVar12 + 0x3a0 + uVar16) == 0) goto LAB_140137746;
      fVar34 = uStack_f8._4_4_ + DAT_1402d1e40;
      *(longlong **)(lVar12 + 0x3a0 + uVar16) = plVar11;
      if ((int)fVar34 == 1) {
        fVar34 = pfVar3[10];
        if (fVar34 == 0.0) {
          lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
          if (lVar9 != 0) {
            if (*(longlong *)(lVar9 + 0x1b8) == 0) {
              if (*(longlong *)(lVar9 + 0x1c0) == 0) {
                pfVar3[10] = 2.8026e-45;
                fVar34 = 2.8026e-45;
              }
              else {
                pfVar3[10] = 4.2039e-45;
                fVar34 = 4.2039e-45;
              }
            }
            else {
              pfVar3[10] = 5.60519e-45;
              fVar34 = 5.60519e-45;
            }
            goto LAB_140137625;
          }
          pfVar3[10] = 1.4013e-45;
        }
        else {
LAB_140137625:
          if (fVar34 != 1.4013e-45) goto LAB_14013772c;
        }
        plVar11 = *(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390);
        if (plVar11 != (longlong *)0x0) {
          auVar26 = ZEXT1664(auVar30);
          auVar33 = ZEXT1664(auVar25);
          auVar47 = ZEXT1664(auVar17);
          (**(code **)(*plVar11 + 0x1c8))(plVar11);
          fVar7 = DAT_1402d238c;
          fVar23 = auVar26._0_4_;
          *(float *)((longlong)plVar11 + 0x124) = fVar23 * local_188._4_4_;
          *(float *)(plVar11 + 0x25) = fVar23 * (float)uStack_180;
          *(float *)(plVar11 + 0x26) = fVar23 * uStack_180._4_4_;
          *(float *)((longlong)plVar11 + 0x134) = fVar23 * uStack_178._4_4_;
          fVar34 = fVar7 * uStack_170._4_4_ + *(float *)(plVar11 + 0x27);
          auVar36 = auVar47._0_16_;
          auVar17 = vcmpss_avx(ZEXT416((uint)fVar34),auVar36,1);
          auVar17 = vblendvps_avx(ZEXT416((uint)fVar34),ZEXT416((uint)(fVar34 + fVar23)),auVar17);
          auVar25 = auVar26._0_16_;
          auVar30 = vcmpss_avx(auVar25,auVar17,1);
          auVar17 = vblendvps_avx(auVar17,ZEXT416((uint)(auVar17._0_4_ - fVar23)),auVar30);
          *(int *)(plVar11 + 0x27) = auVar17._0_4_;
          fVar34 = fVar7 * (float)local_168 + *(float *)((longlong)plVar11 + 0x13c);
          auVar17 = vcmpss_avx(ZEXT416((uint)fVar34),auVar36,1);
          auVar17 = vblendvps_avx(ZEXT416((uint)fVar34),ZEXT416((uint)(fVar34 + fVar23)),auVar17);
          auVar30 = vcmpss_avx(auVar25,auVar17,1);
          auVar17 = vblendvps_avx(auVar17,ZEXT416((uint)(auVar17._0_4_ - fVar23)),auVar30);
          *(int *)((longlong)plVar11 + 0x13c) = auVar17._0_4_;
          fVar34 = fVar7 * (float)uStack_140 + *(float *)((longlong)plVar11 + 300);
          auVar17 = vcmpss_avx(ZEXT416((uint)fVar34),auVar36,1);
          auVar17 = vblendvps_avx(ZEXT416((uint)fVar34),ZEXT416((uint)(fVar34 + fVar23)),auVar17);
          auVar30 = vcmpss_avx(auVar25,auVar17,1);
          auVar17 = vblendvps_avx(auVar17,ZEXT416((uint)(auVar17._0_4_ - fVar23)),auVar30);
          *(int *)((longlong)plVar11 + 300) = auVar17._0_4_;
        }
      }
      else if ((int)fVar34 == 2) {
        fVar34 = pfVar3[10];
        if (fVar34 == 0.0) {
          lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
          if (lVar9 != 0) {
            if (*(longlong *)(lVar9 + 0x1b8) == 0) {
              if (*(longlong *)(lVar9 + 0x1c0) == 0) {
                pfVar3[10] = 2.8026e-45;
                fVar34 = 2.8026e-45;
              }
              else {
                pfVar3[10] = 4.2039e-45;
                fVar34 = 4.2039e-45;
              }
            }
            else {
              pfVar3[10] = 5.60519e-45;
              fVar34 = 5.60519e-45;
            }
            goto LAB_140137583;
          }
          pfVar3[10] = 1.4013e-45;
        }
        else {
LAB_140137583:
          if (fVar34 != 1.4013e-45) goto LAB_14013772c;
        }
        plVar11 = *(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390);
        if (plVar11 != (longlong *)0x0) {
          auVar26 = ZEXT1664(auVar30);
          auVar33 = ZEXT1664(auVar25);
          auVar47 = ZEXT1664(auVar17);
          (**(code **)(*plVar11 + 0x1c8))(plVar11);
          *(float *)((longlong)plVar11 + 0x13c) = auVar26._0_4_ * local_188._4_4_;
        }
      }
      else {
        if ((float)uStack_140 == fVar7) {
          auVar33 = ZEXT1664(auVar25);
          auVar47 = ZEXT1664(auVar17);
          (**(code **)(*plVar11 + 0x78))();
        }
        else {
          auVar33 = ZEXT1664(auVar25);
          auVar47 = ZEXT1664(auVar17);
          (**(code **)(*plVar11 + 0x70))();
        }
        if (auVar47._0_4_ < (float)uStack_178) {
          fVar34 = pfVar3[10];
          if (fVar34 == 0.0) {
            lVar9 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
            if (lVar9 != 0) {
              if (*(longlong *)(lVar9 + 0x1b8) == 0) {
                if (*(longlong *)(lVar9 + 0x1c0) == 0) {
                  pfVar3[10] = 2.8026e-45;
                  fVar34 = 2.8026e-45;
                }
                else {
                  pfVar3[10] = 4.2039e-45;
                  fVar34 = 4.2039e-45;
                }
              }
              else {
                pfVar3[10] = 5.60519e-45;
                fVar34 = 5.60519e-45;
              }
              goto LAB_1401374b0;
            }
            pfVar3[10] = 1.4013e-45;
          }
          else {
LAB_1401374b0:
            if (fVar34 != 1.4013e-45) {
              if (fVar34 == 2.8026e-45) {
                plVar11 = *(longlong **)
                           (*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x390);
                if (plVar11 != (longlong *)0x0) {
                  (**(code **)(*plVar11 + 0x68))();
                }
              }
              else if (fVar34 == 4.2039e-45) {
                (**(code **)(**(longlong **)
                               (*(longlong *)
                                 (*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1c0) +
                               0x10) + 0x68))();
              }
              goto LAB_14013772c;
            }
          }
          if (*(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390) + 0x68))();
          }
        }
      }
LAB_14013772c:
      if ((*(byte *)(lVar12 + 0x1f0 + uVar16) & 2) != 0) {
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        FUN_140010230(pfVar3,param_1[4]);
      }
    }
    else {
      plVar11 = *(longlong **)(lVar9 + 0x390);
      *(longlong **)(lVar9 + 0x3a0) = plVar11;
      if (plVar11 != (longlong *)0x0) {
        if ((float)uStack_140 == fVar7) {
          auVar33 = ZEXT1664(auVar25);
          auVar47 = ZEXT1664(auVar17);
          (**(code **)(*plVar11 + 0x78))();
        }
        else {
          auVar33 = ZEXT1664(auVar25);
          auVar47 = ZEXT1664(auVar17);
          (**(code **)(*plVar11 + 0x70))();
        }
        if ((*(byte *)(lVar12 + 0x1f0 + uVar16) & 2) != 0) {
          FUN_140010230(pfVar3,param_1[4]);
        }
        if (auVar47._0_4_ < (float)uStack_178) {
          fVar34 = pfVar3[10];
          if (fVar34 == 0.0) {
            lVar12 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
            if (lVar12 != 0) {
              if (*(longlong *)(lVar12 + 0x1b8) == 0) {
                if (*(longlong *)(lVar12 + 0x1c0) == 0) {
                  pfVar3[10] = 2.8026e-45;
                  fVar34 = 2.8026e-45;
                }
                else {
                  pfVar3[10] = 4.2039e-45;
                  fVar34 = 4.2039e-45;
                }
              }
              else {
                pfVar3[10] = 5.60519e-45;
                fVar34 = 5.60519e-45;
              }
              goto LAB_14013736c;
            }
            pfVar3[10] = 1.4013e-45;
          }
          else {
LAB_14013736c:
            if (fVar34 != 1.4013e-45) {
              if (fVar34 == 2.8026e-45) {
                plVar11 = *(longlong **)
                           (*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x390);
                if (plVar11 != (longlong *)0x0) {
                  (**(code **)(*plVar11 + 0x68))();
                }
              }
              else if (fVar34 == 4.2039e-45) {
                (**(code **)(**(longlong **)
                               (*(longlong *)
                                 (*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1c0) +
                               0x10) + 0x68))();
              }
              goto LAB_140137746;
            }
          }
          if (*(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390) + 0x68))();
          }
        }
      }
    }
LAB_140137746:
    lVar12 = *(longlong *)(pfVar3 + 0x20);
    if ((lVar12 != 0) && (0 < *(short *)(lVar12 + 0x52))) {
      auVar33 = ZEXT1664(auVar33._0_16_);
      auVar47 = ZEXT1664(auVar47._0_16_);
      FUN_14000c540(lVar12,param_1[4],&local_188);
      *(short *)(lVar12 + 0x52) = *(short *)(lVar12 + 0x52) + 1;
    }
  }
  else {
LAB_140137170:
    if ((fVar34 != 4.2039e-45) && (fVar34 != 5.60519e-45)) goto LAB_140137182;
    lVar9 = *(longlong *)(lVar12 + 0x3a8 + uVar16);
    lVar10 = *(longlong *)(pfVar3 + 0x22);
    if ((local_168._4_4_ != fVar7) && (*(char *)(lVar10 + 0x20) != '\0')) {
      auVar18 = ZEXT416((uint)(auVar18._0_4_ +
                              (DAT_1402aa31c - *(float *)(lVar10 + 4)) * local_168._4_4_));
    }
    if ((uStack_f0._4_4_ != fVar7) && (*(char *)(lVar10 + 0x21) != '\0')) {
      fVar7 = DAT_14030f0c0 - *(float *)(lVar10 + 0x10);
      fVar23 = DAT_14030f0c4 - *(float *)(lVar10 + 0x14);
      fVar24 = DAT_14030f0c8 - *(float *)(lVar10 + 0x18);
      fVar21 = DAT_14030f0cc - *(float *)(lVar10 + 0x1c);
      auVar47 = ZEXT1664(auVar17);
      auVar26 = ZEXT464((uint)uStack_f0._4_4_);
      auVar29 = ZEXT1664(auVar18);
      auVar38 = ZEXT1664(auVar31);
      auVar40 = ZEXT1664(auVar39);
      auVar43 = ZEXT1664(auVar42);
      auVar33._0_8_ = FUN_14026f3f3();
      auVar33._8_56_ = extraout_var_02;
      auVar17 = vpermilps_avx(auVar33._0_16_,1);
      auVar30 = vpermilps_avx(auVar33._0_16_,0xe);
      local_248[0] = (float)auVar33._0_8_;
      local_1f0 = auVar30._0_4_;
      local_1e4 = local_1f0 ^ DAT_1402d3770;
      local_248[2] = auVar17._0_4_;
      auVar17 = vpermilps_avx(auVar30,1);
      local_248[1] = auVar47._0_4_;
      local_268 = CONCAT44(local_248[1],local_248[2]);
      uStack_258 = CONCAT44(DAT_1402d22d0,local_248[1]);
      uStack_260 = CONCAT44(local_248[1],(uint)local_248[0] ^ DAT_1402d3770);
      uStack_250 = CONCAT44(local_248[1],local_248[1]);
      local_22c = DAT_1402d22d0;
      local_208 = DAT_1402d22d0;
      local_1f4 = auVar17._0_4_;
      local_1cc = DAT_1402d22d0;
      local_248[3] = local_248[1];
      local_238 = local_248[1];
      local_234 = local_248[1];
      local_230 = local_248[1];
      local_204 = local_248[1];
      local_200 = local_248[1];
      local_1fc = local_248[1];
      local_1f8 = local_248[1];
      local_1ec = local_248[1];
      local_1e8 = local_248[1];
      local_1e0 = local_1f4;
      local_1dc = local_248[1];
      local_1d8 = local_248[1];
      local_1d4 = local_248[1];
      local_1d0 = local_248[1];
      FUN_140005940(&local_268,&local_268,&local_208);
      auVar19._0_8_ = FUN_14026f3b0(local_278);
      auVar19._8_56_ = extraout_var_03;
      local_204 = (float)auVar19._0_8_;
      local_1f8 = (float)((uint)local_204 ^ DAT_1402d3770);
      auVar17 = vpermilps_avx(auVar19._0_16_,1);
      puVar14 = &local_268;
      local_1e0 = DAT_1402d22d0;
      local_208 = auVar17._0_4_;
      local_1f0 = auVar47._0_4_;
      local_1f4 = local_208;
      local_1e4 = local_1f0;
      FUN_140005940(&local_268,puVar14,&local_208);
      auVar42 = auVar43._0_16_;
      uVar22 = (undefined4)((ulonglong)puVar14 >> 0x20);
      fVar37 = auVar26._0_4_;
      auVar31 = ZEXT416((uint)(auVar38._0_4_ +
                              (fVar21 * local_238 + fVar24 * local_248[0] +
                              fVar23 * (float)uStack_258 + fVar7 * (float)local_268) * fVar37));
      auVar18 = ZEXT416((uint)(auVar29._0_4_ +
                              (fVar21 * local_234 + fVar24 * local_248[1] +
                              fVar23 * uStack_258._4_4_ + fVar7 * local_268._4_4_) * fVar37));
      auVar33 = ZEXT464((uint)DAT_1402d22d0);
      auVar39 = ZEXT416((uint)(auVar40._0_4_ +
                              (fVar21 * local_230 + fVar24 * local_248[2] +
                              fVar23 * (float)uStack_250 + fVar7 * (float)uStack_260) * fVar37));
      auVar25 = ZEXT416((uint)((fVar21 * local_22c + fVar24 * local_248[3] +
                               fVar23 * uStack_250._4_4_ + fVar7 * uStack_260._4_4_) * fVar37 +
                              DAT_1402d22d0));
    }
    auVar17 = ZEXT416((uint)local_278);
    *(float *)(lVar9 + 0x268) = local_27c;
    *(float *)(lVar9 + 0x270) = local_278;
    uVar46 = auVar42._0_4_;
    *(undefined4 *)(lVar9 + 0x26c) = uVar46;
    uVar41 = auVar31._0_4_;
    *(undefined4 *)(lVar12 + 600 + uVar16) = uVar41;
    *(undefined4 *)(lVar9 + 600) = uVar41;
    uVar28 = auVar18._0_4_;
    *(undefined4 *)(lVar12 + 0x25c + uVar16) = uVar28;
    *(undefined4 *)(lVar9 + 0x25c) = uVar28;
    uVar44 = auVar39._0_4_;
    *(undefined4 *)(lVar12 + 0x260 + uVar16) = uVar44;
    *(undefined4 *)(lVar9 + 0x260) = uVar44;
    *(undefined4 *)(lVar12 + 0x264 + uVar16) = 0x3f800000;
    *(undefined4 *)(lVar9 + 0x264) = 0x3f800000;
    if (fVar34 == 5.60519e-45) {
      lVar4 = *(longlong *)(lVar9 + 0x1b8);
      *(undefined4 *)(lVar4 + 0x10e0) = uVar41;
      *(undefined4 *)(lVar4 + 0x10e4) = uVar28;
      *(undefined4 *)(lVar4 + 0x10e8) = uVar44;
      uVar27 = auVar25._0_4_;
      *(undefined4 *)(lVar4 + 0x10ec) = uVar27;
      *(float *)(lVar4 + 0x10f0) = local_27c;
      *(undefined4 *)(lVar4 + 0x10f4) = uVar46;
      *(float *)(lVar4 + 0x10f8) = local_278;
      *(undefined4 *)(lVar4 + 0x10fc) = 0;
      *(undefined8 *)(lVar4 + 0x12a0) = 0;
      *(undefined4 *)(lVar4 + 0x12a8) = 0;
      *(undefined4 *)(lVar4 + 0x12ac) = 0x3f800000;
      *(float *)(lVar4 + 0x12b0) = local_27c;
      *(undefined4 *)(lVar4 + 0x12b4) = uVar46;
      *(float *)(lVar4 + 0x12b8) = local_278;
      *(undefined4 *)(lVar4 + 0x12bc) = 0;
      *(undefined4 *)(lVar4 + 0x70) = uVar41;
      *(undefined4 *)(lVar4 + 0x74) = uVar28;
      *(undefined4 *)(lVar4 + 0x78) = uVar44;
      *(undefined4 *)(lVar4 + 0x7c) = uVar27;
      *(float *)(lVar4 + 0x80) = local_27c;
      *(undefined4 *)(lVar4 + 0x84) = uVar46;
      *(float *)(lVar4 + 0x88) = local_278;
      *(undefined4 *)(lVar4 + 0x8c) = 0;
      *(undefined4 *)(lVar4 + 0x17f8) = uVar41;
      *(undefined4 *)(lVar4 + 0x17fc) = uVar28;
      *(undefined4 *)(lVar4 + 0x1800) = uVar44;
      *(undefined4 *)(lVar4 + 0x1804) = uVar27;
      *(float *)(lVar4 + 0x1808) = local_27c;
      *(undefined4 *)(lVar4 + 0x180c) = uVar46;
      *(float *)(lVar4 + 0x1810) = local_278;
      *(undefined4 *)(lVar4 + 0x1814) = 0;
      fVar34 = local_27c;
      if (auVar47._0_4_ < uStack_160._4_4_) {
        auVar26 = ZEXT464((uint)local_278);
        auVar19 = ZEXT1664(auVar25);
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        auVar29 = ZEXT1664(auVar18);
        auVar38 = ZEXT1664(auVar31);
        auVar40 = ZEXT1664(auVar39);
        auVar43 = ZEXT1664(auVar42);
        FUN_140011620(lVar10,CONCAT44(uVar22,(int)(uStack_160._4_4_ + DAT_1402d2160)));
        auVar42 = auVar43._0_16_;
        auVar39 = auVar40._0_16_;
        auVar31 = auVar38._0_16_;
        auVar18 = auVar29._0_16_;
        auVar25 = auVar19._0_16_;
        auVar17 = auVar26._0_16_;
      }
      if ((*(char *)(local_270 + 0x38) != '\0') || ((*(byte *)(lVar9 + 0x1f0) & 2) == 0)) {
        param_2 = local_270;
        goto LAB_140137779;
      }
      local_220._0_16_ = ZEXT816(0);
      local_198 = ZEXT816(0);
      auVar26 = ZEXT1664(auVar17);
      auVar19 = ZEXT1664(auVar25);
      auVar33 = ZEXT1664(auVar33._0_16_);
      auVar47 = ZEXT1664(auVar47._0_16_);
      auVar29 = ZEXT1664(auVar18);
      auVar38 = ZEXT1664(auVar31);
      auVar40 = ZEXT1664(auVar39);
      auVar43 = ZEXT1664(auVar42);
      cVar6 = FUN_140011800(lVar10,local_220,local_198);
      if (cVar6 != '\0') {
        fVar7 = auVar29._0_4_ + (float)local_220._4_4_;
        fVar34 = fVar34 + (float)local_198._0_4_;
        *(float *)(lVar12 + 0x25c + uVar16) = fVar7;
        *(float *)(lVar9 + 0x25c) = fVar7;
        *(float *)(lVar9 + 0x268) = fVar34;
        uVar41 = auVar38._0_4_;
        *(undefined4 *)(lVar4 + 0x10e0) = uVar41;
        *(float *)(lVar4 + 0x10e4) = fVar7;
        uVar44 = auVar40._0_4_;
        *(undefined4 *)(lVar4 + 0x10e8) = uVar44;
        uVar28 = auVar19._0_4_;
        *(undefined4 *)(lVar4 + 0x10ec) = uVar28;
        *(float *)(lVar4 + 0x10f0) = fVar34;
        uVar46 = auVar43._0_4_;
        *(undefined4 *)(lVar4 + 0x10f4) = uVar46;
        uVar22 = auVar26._0_4_;
        *(undefined4 *)(lVar4 + 0x10f8) = uVar22;
        *(undefined4 *)(lVar4 + 0x10fc) = 0;
        *(undefined8 *)(lVar4 + 0x12a0) = 0;
        *(undefined4 *)(lVar4 + 0x12a8) = 0;
        *(undefined4 *)(lVar4 + 0x12ac) = 0x3f800000;
        *(float *)(lVar4 + 0x12b0) = fVar34;
        *(undefined4 *)(lVar4 + 0x12b4) = uVar46;
        *(undefined4 *)(lVar4 + 0x12b8) = uVar22;
        *(undefined4 *)(lVar4 + 0x12bc) = 0;
        *(undefined4 *)(lVar4 + 0x70) = uVar41;
        *(float *)(lVar4 + 0x74) = fVar7;
        *(undefined4 *)(lVar4 + 0x78) = uVar44;
        *(undefined4 *)(lVar4 + 0x7c) = uVar28;
        *(float *)(lVar4 + 0x80) = fVar34;
        *(undefined4 *)(lVar4 + 0x84) = uVar46;
        *(undefined4 *)(lVar4 + 0x88) = uVar22;
        *(undefined4 *)(lVar4 + 0x8c) = 0;
        *(undefined4 *)(lVar4 + 0x17f8) = uVar41;
        *(float *)(lVar4 + 0x17fc) = fVar7;
        *(undefined4 *)(lVar4 + 0x1800) = uVar44;
        *(undefined4 *)(lVar4 + 0x1804) = uVar28;
        *(float *)(lVar4 + 0x1808) = fVar34;
        *(undefined4 *)(lVar4 + 0x180c) = uVar46;
        *(undefined4 *)(lVar4 + 0x1810) = uVar22;
        *(undefined4 *)(lVar4 + 0x1814) = 0;
        FUN_140011800(lVar10,local_220,local_198);
      }
      FUN_140155ec0(lVar4 + 0x110);
      FUN_140151ef0(lVar4 + 0xc08,lVar4 + 0x9b0);
      FUN_14015e840(lVar4 + 0x220);
      FUN_140010230(pfVar3,param_1[4]);
      if (*(longlong *)(pfVar3 + 0x12) == 0) {
        local_2a8 = auVar47._0_4_;
        local_2b0 = CONCAT44(local_2b0._4_4_,local_2a8);
        local_2b8 = (undefined4 *)CONCAT44(local_2b8._4_4_,local_2a8);
        uVar20 = auVar47._0_8_;
        local_2a0 = local_2a8;
        local_298 = local_2a8;
        FUN_14010ae70(lVar4,uVar20,uVar20,uVar20);
        param_2 = local_270;
      }
      else {
        local_298 = (float)local_168;
        local_2a0 = uStack_170._4_4_;
        local_2a8 = (undefined4)uStack_170;
        local_2b0 = CONCAT44(local_2b0._4_4_,uStack_178._4_4_);
        local_2b8 = (undefined4 *)CONCAT44(local_2b8._4_4_,(float)uStack_178);
        FUN_14010ae70(lVar4,local_188._4_4_,uStack_180 & 0xffffffff,uStack_180._4_4_);
        param_2 = local_270;
      }
    }
    else {
      if (auVar47._0_4_ < (float)uStack_178) {
        fVar34 = pfVar3[10];
        if (fVar34 == 0.0) {
          lVar12 = *(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8);
          if (lVar12 != 0) {
            if (*(longlong *)(lVar12 + 0x1b8) == 0) {
              if (*(longlong *)(lVar12 + 0x1c0) == 0) {
                pfVar3[10] = 2.8026e-45;
                fVar34 = 2.8026e-45;
              }
              else {
                pfVar3[10] = 4.2039e-45;
                fVar34 = 4.2039e-45;
              }
            }
            else {
              pfVar3[10] = 5.60519e-45;
              fVar34 = 5.60519e-45;
            }
            goto LAB_140137f77;
          }
          pfVar3[10] = 1.4013e-45;
LAB_140137fcf:
          plVar11 = *(longlong **)(*(longlong *)(pfVar3 + 0x16) + 0x390);
LAB_140137fda:
          if (plVar11 == (longlong *)0x0) goto LAB_140137fe8;
        }
        else {
LAB_140137f77:
          if (fVar34 == 1.4013e-45) goto LAB_140137fcf;
          if (fVar34 == 2.8026e-45) {
            plVar11 = *(longlong **)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x390);
            goto LAB_140137fda;
          }
          if (fVar34 != 4.2039e-45) goto LAB_140137fe8;
          plVar11 = *(longlong **)
                     (*(longlong *)(*(longlong *)(*(longlong *)(pfVar3 + 0x16) + 0x3a8) + 0x1c0) +
                     0x10);
        }
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        (**(code **)(*plVar11 + 0x68))();
      }
LAB_140137fe8:
      if (auVar47._0_4_ < uStack_160._4_4_) {
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        FUN_140011620(lVar10,CONCAT44(uVar22,(int)(uStack_160._4_4_ + DAT_1402d2160)));
      }
      param_2 = local_270;
      if ((*(byte *)(lVar9 + 0x1f0) & 2) != 0) {
        auVar33 = ZEXT1664(auVar33._0_16_);
        auVar47 = ZEXT1664(auVar47._0_16_);
        FUN_140010230(pfVar3,param_1[4]);
        param_2 = local_270;
      }
    }
  }
LAB_140137776:
LAB_140137779:
  uVar8 = local_288;
LAB_14013777e:
  lVar12 = *param_1;
  local_288 = uVar8 + 1;
  uVar15 = (ulonglong)local_288;
  uVar16 = uVar16 + 0x520;
  auVar26 = ZEXT464(local_274);
  if (*(int *)(*(longlong *)(lVar12 + local_1c8 * 8) + 0x118) <= (int)local_288)
  goto code_r0x0001401377ac;
  goto LAB_1401366aa;
code_r0x0001401377ac:
  param_3 = local_284;
LAB_1401377b6:
  local_228 = local_228 + 1;
  local_1c0 = local_1c0 + 8;
  local_1c8 = local_1c8 + 1;
  if ((int)(uint)*(byte *)((longlong)param_1 + 0x34) <= local_228) goto LAB_140137860;
  goto LAB_140136675;
}

