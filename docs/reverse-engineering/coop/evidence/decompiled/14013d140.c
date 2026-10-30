/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14013d140; RVA 0x13d140
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_14013d140(longlong *param_1,undefined1 (*param_2) [16],undefined1 (*param_3) [16],
                  float param_4,byte param_5,byte param_6,undefined1 param_7,undefined1 param_8,
                  longlong param_9,undefined1 param_10)

{
  undefined4 uVar1;
  undefined1 auVar2 [32];
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined4 uVar6;
  longlong lVar7;
  float fVar8;
  char cVar9;
  undefined2 uVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined4 *puVar14;
  longlong *plVar15;
  undefined4 *puVar16;
  uint uVar17;
  longlong lVar18;
  longlong lVar19;
  uint uVar20;
  float fVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [64];
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined1 auVar24 [16];
  float fVar25;
  undefined1 auVar27 [16];
  float fVar26;
  undefined1 auVar28 [64];
  undefined1 auVar29 [16];
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  undefined1 auVar34 [64];
  undefined1 auVar35 [16];
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined1 auStack_238 [32];
  undefined1 *local_218;
  undefined4 local_210;
  undefined4 local_208;
  undefined4 local_200;
  undefined4 local_1f8;
  undefined1 local_1f0;
  undefined1 local_1e8;
  char local_1d8;
  undefined1 local_1d0 [16];
  undefined4 local_1c0;
  undefined1 (*local_1b8) [16];
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined1 auStack_178 [16];
  undefined8 local_168;
  undefined8 uStack_160;
  undefined1 local_158 [16];
  undefined1 local_148 [16];
  undefined1 local_138 [16];
  undefined1 local_128 [64];
  ulonglong local_e8;
  
  auStack_178 = _DAT_1402d35f0;
  fVar8 = DAT_1402d2de4;
  fVar26 = DAT_1402d2420;
  local_e8 = DAT_140309040 ^ (ulonglong)auStack_238;
  if ((param_5 != 0xff) && (param_6 != 0xff)) {
    uVar17 = 0;
    local_1d8 = DAT_14033bd60;
    do {
      uVar20 = 1 << (uVar17 & 0x1f);
      if ((*(uint *)(param_1 + 0xdd) & uVar20) == 0) {
        uVar39 = *(undefined4 *)(*param_3 + 4);
        uVar36 = *(undefined4 *)*param_2;
        uVar37 = *(undefined4 *)(*param_2 + 4);
        uVar11 = (ulonglong)uVar17;
        lVar18 = uVar11 * 0x58;
        uVar38 = *(undefined4 *)(*param_2 + 8);
        param_4 = (((float)*(int *)(param_9 + 0x44) * DAT_1402d20dc) / (float)*(byte *)(param_1 + 5)
                  ) * DAT_1402d2478 + param_4;
        auVar24 = *param_3;
        auVar28 = ZEXT1664(auVar24);
        fVar21 = auVar24._0_4_;
        *(undefined4 *)(lVar18 + 0x164 + (longlong)param_1) = *(undefined4 *)(*param_2 + 0xc);
        uVar6 = *(undefined4 *)(*param_3 + 0xc);
        *(undefined4 *)(param_1 + uVar11 * 0xb + 0x2b) = uVar36;
        *(undefined4 *)(lVar18 + 0x15c + (longlong)param_1) = uVar37;
        *(undefined4 *)(param_1 + uVar11 * 0xb + 0x2c) = uVar38;
        *(undefined4 *)(lVar18 + 0x16c + (longlong)param_1) = uVar39;
        uVar39 = *(undefined4 *)(*param_3 + 8);
        *(undefined4 *)(lVar18 + 0x174 + (longlong)param_1) = uVar6;
        *(undefined4 *)(param_1 + uVar11 * 0xb + 0x2e) = uVar39;
        uStack_180 = _UNK_1402d3198;
        local_188 = _DAT_1402d3190;
        local_1a8 = _DAT_1402d38a0;
        uStack_1a0 = _UNK_1402d38a8;
        uStack_198 = _UNK_1402d38b0;
        uStack_190 = _UNK_1402d38b8;
        uVar39 = *(undefined4 *)*param_3;
        *(undefined4 *)(param_1 + uVar11 * 0xb + 0x2d) = uVar39;
        *(undefined1 *)(lVar18 + 0x19a + (longlong)param_1) = param_7;
        *(undefined1 *)(lVar18 + 0x19b + (longlong)param_1) = param_8;
        *(undefined1 *)(lVar18 + 0x19e + (longlong)param_1) = param_10;
        auVar29 = vshufps_avx(auVar24,auVar24,0xaa);
        auVar23 = ZEXT1664(auVar29);
        *(float *)(lVar18 + 0x194 + (longlong)param_1) = param_4;
        *(undefined4 *)(param_1 + uVar11 * 0xb + 0x32) = 0;
        *(byte *)(lVar18 + 0x19c + (longlong)param_1) = param_5;
        *(byte *)(lVar18 + 0x19d + (longlong)param_1) = param_6;
        param_1[uVar11 * 0xb + 0x31] = param_9;
        auVar24 = vshufps_avx(auVar24,auVar24,0x55);
        auVar34 = ZEXT1664(auVar24);
        while (fVar25 = auVar28._0_4_, fVar26 < fVar21) {
          fVar21 = fVar25 + fVar8;
          auVar28 = ZEXT464((uint)fVar21);
        }
        while (fVar25 < DAT_1402d2db4) {
          fVar25 = auVar28._0_4_ + DAT_1402d249c;
          auVar28 = ZEXT464((uint)fVar25);
        }
        fVar21 = auVar24._0_4_;
        while (fVar25 = auVar34._0_4_, fVar26 < fVar21) {
          fVar21 = fVar25 + fVar8;
          auVar34 = ZEXT464((uint)fVar21);
        }
        while (fVar25 < DAT_1402d2db4) {
          fVar25 = auVar34._0_4_ + DAT_1402d249c;
          auVar34 = ZEXT464((uint)fVar25);
        }
        fVar21 = auVar29._0_4_;
        while (fVar25 = auVar23._0_4_, fVar26 < fVar21) {
          fVar21 = fVar25 + fVar8;
          auVar23 = ZEXT464((uint)fVar21);
        }
        while (fVar25 < DAT_1402d2db4) {
          fVar25 = auVar23._0_4_ + DAT_1402d249c;
          auVar23 = ZEXT464((uint)fVar25);
        }
        auVar23 = ZEXT1664(auStack_178);
        local_1b8 = param_2;
        auVar28._0_8_ = FUN_14026f3f3();
        auVar28._8_56_ = extraout_var;
        uVar31 = 0;
        uVar32 = 0;
        uVar33 = 0;
        auVar35._12_4_ = 0;
        auVar35._0_12_ = ZEXT812(0);
        auVar34 = ZEXT1264(ZEXT812(0)) << 0x20;
        auVar22 = auVar28._0_16_;
        auVar29 = vpermilps_avx(auVar22,1);
        auVar27._0_4_ = (uint)auVar28._0_8_ ^ DAT_1402d3770;
        auVar27._4_4_ = (int)((ulonglong)auVar28._0_8_ >> 0x20);
        auVar27._8_4_ = extraout_var._0_4_;
        auVar27._12_4_ = extraout_var._4_4_;
        auVar24 = vinsertps_avx(auVar27,auVar29,0x10);
        auVar24 = vinsertps_avx(auVar24,auVar35 << 0x20,0x20);
        local_1d0 = vinsertps_avx(auVar24,auVar35 << 0x20,0x30);
        local_168 = CONCAT44((uint)auVar28._0_8_,auVar29._0_4_);
        uStack_160 = 0;
        auVar24 = vshufps_avx(auVar22,auVar22,0xe);
        auVar28 = ZEXT1664(auVar24);
        local_148._8_8_ = _UNK_1402d3198;
        local_148._0_8_ = _DAT_1402d3190;
        local_138 = auVar23._0_16_;
        uVar30 = DAT_1402d3770;
        local_158 = local_1d0;
        puVar12 = (undefined8 *)FUN_14006b730(&local_168,local_128,&local_1a8);
        auVar29 = vpermilps_avx(auVar28._0_16_,1);
        local_1a8 = *puVar12;
        uStack_1a0 = puVar12[1];
        uStack_198 = puVar12[2];
        uStack_190 = puVar12[3];
        local_188 = puVar12[4];
        uStack_180 = puVar12[5];
        auStack_178 = *(undefined1 (*) [16])(puVar12 + 6);
        local_168 = _DAT_1402d2f10;
        uStack_160 = _UNK_1402d2f18;
        auVar24 = vinsertps_avx(ZEXT816(0),auVar29,0x10);
        auVar24 = vinsertps_avx(auVar24,auVar28._0_16_,0x20);
        auVar35 = auVar34._0_16_;
        local_158 = vinsertps_avx(auVar24,auVar35,0x30);
        auVar24._0_4_ = auVar28._0_4_ ^ uVar30;
        auVar24._4_4_ = auVar28._4_4_ ^ uVar31;
        auVar24._8_4_ = auVar28._8_4_ ^ uVar32;
        auVar24._12_4_ = auVar28._12_4_ ^ uVar33;
        auVar24 = vinsertps_avx(ZEXT816(0),auVar24,0x10);
        auVar24 = vinsertps_avx(auVar24,auVar29,0x20);
        local_1d0 = vinsertps_avx(auVar24,auVar35,0x30);
        local_138 = auVar23._0_16_;
        auVar28 = ZEXT1664(auVar35);
        auVar34 = ZEXT1664(local_138);
        local_148 = local_1d0;
        puVar12 = (undefined8 *)FUN_14006b730(&local_168,local_128,&local_1a8);
        local_1a8 = *puVar12;
        uStack_1a0 = puVar12[1];
        uStack_198 = puVar12[2];
        uStack_190 = puVar12[3];
        local_188 = puVar12[4];
        uStack_180 = puVar12[5];
        auStack_178 = *(undefined1 (*) [16])(puVar12 + 6);
        auVar28 = ZEXT1664(auVar28._0_16_);
        auVar23 = ZEXT1664(auVar34._0_16_);
        auVar34._0_8_ = FUN_14026f3b0();
        auVar34._8_56_ = extraout_var_00;
        auVar29 = vpermilps_avx(auVar34._0_16_,1);
        auVar24 = vinsertps_avx(auVar34._0_16_,auVar28._0_16_,0x10);
        auVar24 = vinsertps_avx(auVar24,auVar29,0x20);
        local_1d0 = vinsertps_avx(auVar24,auVar28._0_16_,0x30);
        local_168 = CONCAT44(auVar28._0_4_,auVar29._0_4_);
        uStack_160 = CONCAT44(auVar28._0_4_,(uint)auVar34._0_8_ ^ uVar30);
        local_158._8_8_ = _UNK_1402d2f78;
        local_158._0_8_ = _DAT_1402d2f70;
        local_138 = auVar23._0_16_;
        local_148 = local_1d0;
        lVar13 = FUN_14006b730(&local_168,local_128,&local_1a8);
        auVar22 = auVar23._0_16_;
        auVar35 = auVar28._0_16_;
        auVar2 = *(undefined1 (*) [32])(lVar13 + 0x20);
        bVar3 = *(byte *)(lVar18 + 0x19c + (longlong)param_1);
        fVar26 = (float)((uint)param_4 ^ uVar30);
        *(float *)(param_1 + uVar11 * 0xb + 0x2f) = auVar2._0_4_ * fVar26;
        auVar29 = auVar2._0_16_;
        auVar24 = vshufps_avx(auVar29,auVar29,0x55);
        *(float *)(lVar18 + 0x17c + (longlong)param_1) = auVar24._0_4_ * fVar26;
        auVar24 = vshufps_avx(auVar29,auVar29,0xaa);
        *(float *)(param_1 + uVar11 * 0xb + 0x30) = auVar24._0_4_ * fVar26;
        auVar24 = vshufps_avx(auVar29,auVar29,0xff);
        *(float *)(lVar18 + 0x184 + (longlong)param_1) = auVar24._0_4_ * fVar26;
        lVar18 = (ulonglong)*(byte *)(lVar18 + 0x19d + (longlong)param_1) * 0x520 +
                 *(longlong *)
                  (*(longlong *)(*(longlong *)param_1[1] + (ulonglong)bVar3 * 8) + 0x110);
        if (*param_1 != 0) {
          cVar9 = *(char *)(**(longlong **)(lVar18 + 0x388) + 0x15d);
          if (((cVar9 == '\0') || (cVar9 == '\x02')) && (*(char *)(lVar18 + 0x235) == '\0')) {
            local_1c0 = 0;
          }
          else {
            local_1c0 = 1;
          }
          local_1d0 = *local_1b8;
          auVar28 = ZEXT1664(auVar35);
          auVar34 = ZEXT1664(auVar22);
          uVar10 = FUN_140031f80(*(undefined8 *)(*param_1 + 0x66ee0),0x30,local_1d0,0);
          auVar22 = auVar34._0_16_;
          auVar35 = auVar28._0_16_;
          *(undefined2 *)(param_1 + uVar11 * 0xb + 0x33) = uVar10;
        }
        if ((param_5 == 0) && (param_6 == 0)) {
          *(uint *)(param_1 + 0xde) = uVar17;
        }
        *(uint *)(param_1 + 0xdd) = *(uint *)(param_1 + 0xdd) | uVar20;
        if (local_1d8 == '\0') {
          auVar28 = ZEXT1664(auVar35);
          auVar34 = ZEXT1664(auVar22);
          puVar14 = (undefined4 *)FUN_140019ef0();
          plVar15 = (longlong *)FUN_14001b280(puVar14);
          auVar22 = auVar34._0_16_;
          auVar35 = auVar28._0_16_;
          if (plVar15 != (longlong *)0x0) {
            uVar6 = *(undefined4 *)(*param_3 + 4);
            uVar1 = *(undefined4 *)(*param_3 + 8);
            lVar19 = (ulonglong)param_6 * 0x520;
            lVar13 = *(longlong *)
                      (*(longlong *)(*(longlong *)(puVar14 + 0x10a) + 0x697b8) +
                      (ulonglong)param_5 * 8);
            lVar7 = *(longlong *)(lVar13 + 0x110);
            uVar4 = *(undefined1 *)(lVar13 + 0x15d);
            *(undefined4 *)(plVar15 + 0xc) = *puVar14;
            *(undefined2 *)((longlong)plVar15 + 100) = *(undefined2 *)(lVar19 + 0x228 + lVar7);
            *(undefined1 *)((longlong)plVar15 + 0x66) = *(undefined1 *)(lVar19 + 0x234 + lVar7);
            *(undefined1 *)((longlong)plVar15 + 0x67) = *(undefined1 *)(lVar19 + 0x235 + lVar7);
            *(undefined1 *)((longlong)plVar15 + 0x22) = param_7;
            *(undefined1 *)((longlong)plVar15 + 0x23) = param_8;
            plVar15[5] = param_9;
            *(undefined1 *)(plVar15 + 10) = param_10;
            *(undefined4 *)((longlong)plVar15 + 0x34) = uVar36;
            *(undefined4 *)(plVar15 + 7) = uVar37;
            *(undefined4 *)((longlong)plVar15 + 0x3c) = uVar38;
            *(undefined4 *)(plVar15 + 8) = uVar39;
            *(undefined4 *)((longlong)plVar15 + 0x44) = uVar6;
            *(undefined4 *)(plVar15 + 9) = uVar1;
            *(float *)((longlong)plVar15 + 0x4c) = param_4;
            *(undefined1 *)(plVar15 + 0xd) = uVar4;
            *(undefined2 *)((longlong)plVar15 + 0x69) = 0;
            *(undefined1 *)((longlong)plVar15 + 0x6b) = 2;
            *(undefined2 *)(plVar15 + 4) = 0;
            *(uint *)(plVar15 + 6) = uVar17;
            puVar12 = *(undefined8 **)(puVar14 + 0x28);
            *puVar12 = plVar15;
            *(longlong **)(puVar14 + 0x28) = plVar15;
            *plVar15 = (longlong)(puVar14 + 0x26);
            plVar15[1] = (longlong)puVar12;
            puVar14[0x42] = puVar14[0x42] + 1;
          }
        }
        cVar9 = *(char *)(**(longlong **)(lVar18 + 0x388) + 0x15d);
        if (((cVar9 != '\0') && (cVar9 != '\x02')) || (*(char *)(lVar18 + 0x235) != '\0')) {
          lVar13 = (ulonglong)param_6 * 0x520;
          lVar18 = *(longlong *)
                    (*(longlong *)(*(longlong *)param_1[1] + (ulonglong)param_5 * 8) + 0x110);
          puVar14 = (undefined4 *)(lVar18 + 600 + lVar13);
          auVar28 = ZEXT1664(auVar35);
          auVar34 = ZEXT1664(auVar22);
          if (*(char *)(**(longlong **)(lVar18 + 0x1a0 + lVar13) + 0x75) == '\0') {
            FUN_1401c56d0();
            local_218 = local_1d0;
            local_1e8 = 1;
            local_1f0 = 0;
            local_1f8 = auVar28._0_4_;
            local_200 = DAT_1402d2458;
            local_208 = DAT_1402d234c;
            local_210 = DAT_1402d2100;
            local_1d0 = auVar34._0_16_;
            cVar9 = FUN_1401c6a00(DAT_1402d2100,1,0x11b,puVar14);
            if (cVar9 == '\0') {
              return uVar17;
            }
            lVar18 = FUN_1401c97a0();
            if (*(char *)(lVar18 + 0x3dc2) < '\x02') {
              return uVar17;
            }
            uVar5 = *(ushort *)(lVar18 + 0x138);
            if ((~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar5 * 0x18) + 0x5882) & 1)
                == 0) {
              return uVar17;
            }
            puVar16 = (undefined4 *)FUN_1401c9e60(lVar18);
            if (puVar16 == (undefined4 *)0x0) {
              return uVar17;
            }
            *(ushort *)(puVar16 + 0x11) = uVar5;
            *(undefined2 *)((longlong)puVar16 + 0x46) = 0x11b;
            *puVar16 = *puVar14;
            puVar16[1] = puVar14[1];
            puVar16[2] = puVar14[2];
            puVar16[3] = puVar14[3];
            *(undefined8 *)(puVar16 + 4) = 0;
            puVar16[6] = 0;
            puVar16[7] = 0x3f800000;
            puVar16[8] = 0x3ea3d70a;
            puVar16[9] = 0x3fb33333;
            *(undefined8 *)(puVar16 + 10) = 0x40800000;
            puVar16[0xf] = 0x3f800000;
            *(undefined2 *)((longlong)puVar16 + 0x4a) = 0;
            *(byte *)(puVar16 + 0x1c) = *(byte *)(puVar16 + 0x1c) & 0xee | 0x26;
          }
          else {
            FUN_1401c56d0();
            local_218 = local_1d0;
            local_1e8 = 1;
            local_1f0 = 0;
            local_1f8 = auVar28._0_4_;
            local_200 = DAT_1402d2458;
            local_208 = DAT_1402d234c;
            local_210 = DAT_1402d2100;
            local_1d0 = auVar34._0_16_;
            cVar9 = FUN_1401c6a00(DAT_1402d2100,1,0x110,puVar14);
            if (cVar9 == '\0') {
              return uVar17;
            }
            lVar18 = FUN_1401c97a0();
            if (*(char *)(lVar18 + 0x3dc2) < '\x02') {
              return uVar17;
            }
            uVar5 = *(ushort *)(lVar18 + 0x138);
            if ((~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar5 * 0x18) + 0x5512) & 1)
                == 0) {
              return uVar17;
            }
            puVar16 = (undefined4 *)FUN_1401c9e60(lVar18);
            if (puVar16 == (undefined4 *)0x0) {
              return uVar17;
            }
            *(ushort *)(puVar16 + 0x11) = uVar5;
            *(undefined2 *)((longlong)puVar16 + 0x46) = 0x110;
            *puVar16 = *puVar14;
            puVar16[1] = puVar14[1];
            puVar16[2] = puVar14[2];
            puVar16[3] = puVar14[3];
            *(undefined8 *)(puVar16 + 4) = 0;
            puVar16[6] = 0;
            puVar16[7] = 0x3f800000;
            puVar16[8] = 0x3ea3d70a;
            puVar16[9] = 0x3fb33333;
            *(undefined8 *)(puVar16 + 10) = 0x40800000;
            puVar16[0xf] = 0x3f800000;
            *(undefined2 *)((longlong)puVar16 + 0x4a) = 0;
            *(byte *)(puVar16 + 0x1c) = *(byte *)(puVar16 + 0x1c) & 0xee | 0x26;
          }
          *(code **)(puVar16 + 0xc) = FUN_1401caa00;
        }
        return uVar17;
      }
      uVar17 = uVar17 + 1;
    } while ((int)uVar17 < 0x10);
  }
  return 0xffffffff;
}

