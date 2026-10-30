/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b9400; RVA 0x1b9400
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_1401b9400(longlong *param_1,longlong param_2)

{
  ushort *puVar1;
  byte *pbVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  undefined1 auVar6 [16];
  float fVar7;
  undefined1 auVar8 [32];
  longlong *plVar9;
  byte bVar10;
  int iVar11;
  longlong lVar12;
  undefined8 *puVar13;
  longlong lVar14;
  byte bVar15;
  uint uVar16;
  int *piVar17;
  ulonglong uVar18;
  longlong *plVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  uint uVar23;
  short sVar24;
  longlong unaff_GS_OFFSET;
  char cVar25;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 uVar26;
  undefined1 auVar27 [64];
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined1 extraout_var_01 [56];
  undefined1 extraout_var_02 [56];
  undefined1 extraout_var_03 [56];
  undefined1 extraout_var_04 [56];
  undefined1 extraout_var_05 [56];
  undefined1 extraout_var_06 [56];
  undefined1 extraout_var_07 [56];
  undefined1 extraout_var_08 [56];
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined8 uVar32;
  undefined8 uVar34;
  undefined1 auVar33 [64];
  float fVar35;
  undefined8 uVar37;
  undefined1 auVar36 [64];
  float fVar38;
  undefined4 uVar39;
  undefined1 auVar40 [16];
  float fVar41;
  undefined4 uVar42;
  undefined1 auVar43 [16];
  undefined1 auVar44 [64];
  float fVar45;
  undefined1 auVar46 [16];
  undefined1 auVar47 [64];
  float fVar48;
  undefined1 auVar49 [16];
  undefined1 auVar50 [64];
  float fVar51;
  float fVar52;
  float fVar53;
  float local_res8 [2];
  float local_res18;
  float local_res20;
  undefined8 in_stack_fffffffffffffcf8;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  longlong local_2d8;
  undefined8 uStack_2d0;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  float local_2a8;
  uint local_2a4;
  uint local_2a0;
  longlong local_298;
  undefined8 uStack_290;
  longlong local_288;
  undefined8 uStack_280;
  undefined1 local_278 [16];
  longlong local_268;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  float fStack_244;
  float fStack_240;
  float fStack_23c;
  undefined1 local_238 [16];
  undefined1 local_228 [16];
  undefined1 local_218 [16];
  undefined8 local_208;
  undefined8 local_200;
  float local_1f8;
  undefined1 local_1f4;
  longlong local_1e8;
  undefined8 uStack_1e0;
  undefined4 local_1d8;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined1 local_1b8 [16];
  undefined4 local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  undefined1 local_198 [16];
  undefined1 local_188 [16];
  undefined1 local_178 [16];
  undefined8 local_168;
  undefined8 local_160;
  float local_158;
  undefined1 local_154;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined1 local_e4;
  
  FUN_1401c56d0();
  DAT_1437dece8 = 0;
  DAT_14033d9b4 = 0;
  lVar20 = *(longlong *)(*(longlong *)(*param_1 + (ulonglong)DAT_14033d9d2 * 8) + 0x110);
  local_2d8 = *(longlong *)(lVar20 + 600);
  uStack_2d0 = *(undefined8 *)(lVar20 + 0x260);
  if (DAT_14033bd74 + 0x14 < DAT_14033bda0) {
    DAT_14033bda0 = DAT_14033bd74 + 0x14;
  }
  if (DAT_14033bda0 < DAT_14033bd74 + 1) {
    DAT_14033bda0 = DAT_14033bd74 + 1;
  }
  auVar27 = ZEXT464((uint)DAT_1402d2b84);
  auVar44 = ZEXT464((uint)DAT_1402d22d0);
  local_2a8 = DAT_1402d2b84;
  auVar33 = ZEXT864(0);
  if (DAT_14033bd98 != 0) {
    auVar36 = ZEXT464(DAT_1402d2c40);
    auVar47 = ZEXT464((uint)uStack_2d0);
    auVar50 = ZEXT464((uint)local_2d8);
    local_2a0 = (uint)local_2d8;
    local_2a4 = (uint)uStack_2d0;
    lVar20 = DAT_14033bd98;
    fVar28 = DAT_1402d1ea0;
    uVar32 = _DAT_1402d3760;
    fVar53 = DAT_1402d2108;
    do {
      auVar49 = auVar50._0_16_;
      auVar46 = auVar47._0_16_;
      auVar43 = auVar44._0_16_;
      auVar40 = auVar33._0_16_;
      sVar24 = 0x13c;
      lVar12 = *(longlong *)(lVar20 + 0x3d0);
      if (lVar12 == 0) {
LAB_1401b9c99:
        lVar12 = *(longlong *)(lVar20 + 0x3f8);
        if ((lVar12 != 0) && (lVar21 = *(longlong *)(lVar20 + 0x368), lVar21 != 0)) {
          lVar22 = *(longlong *)(lVar20 + 0x400);
          if (lVar22 == 0) {
            uVar42 = *(undefined4 *)(lVar12 + 0x28);
            uVar39 = *(undefined4 *)(lVar12 + 0x20);
            *(undefined4 *)(lVar21 + 0x27c) = *(undefined4 *)(lVar12 + 0x24);
            *(undefined4 *)(lVar21 + 0x280) = uVar42;
            *(undefined4 *)(lVar21 + 0x278) = uVar39;
            *(undefined4 *)(lVar21 + 0x284) = 0;
          }
          else {
            fVar28 = (float)(DAT_14033bd74 - *(int *)(lVar12 + 0x60));
            local_278 = ZEXT416(0);
            auVar6 = vminss_avx(ZEXT416((uint)(fVar28 * fVar53)),auVar43);
            local_2e8 = *(undefined4 *)(lVar12 + 0x20);
            local_2e4 = *(undefined4 *)(lVar12 + 0x24);
            local_2e0 = *(undefined4 *)(lVar12 + 0x28);
            local_2c8 = *(undefined4 *)(lVar12 + 0x2c);
            local_2c4 = *(undefined4 *)(lVar12 + 0x30);
            local_2c0 = *(undefined4 *)(lVar12 + 0x34);
            local_2dc = auVar40._0_4_;
            auVar33 = ZEXT1664(auVar6);
            auVar44 = ZEXT1664(CONCAT124(SUB1612(ZEXT816(0),4),
                                         fVar28 / (float)(*(int *)(lVar22 + 0x60) -
                                                         *(int *)(lVar12 + 0x60))));
            auVar27 = ZEXT1664(auVar40);
            auVar47 = ZEXT1664(auVar43);
            auVar50 = ZEXT1664(auVar46);
            auVar36 = ZEXT1664(auVar49);
            local_2bc = local_2dc;
            FUN_140203270(local_278,&local_2e8,&local_2c8);
            local_2f8 = *(undefined4 *)(lVar22 + 0x20);
            local_2d8 = 0;
            uStack_2d0 = 0;
            local_2f4 = *(undefined4 *)(lVar22 + 0x24);
            local_2b8 = *(undefined4 *)(lVar22 + 0x2c);
            local_2f0 = *(undefined4 *)(lVar22 + 0x28);
            local_2b0 = *(undefined4 *)(lVar22 + 0x34);
            local_2b4 = *(undefined4 *)(lVar22 + 0x30);
            local_2ec = auVar27._0_4_;
            local_2ac = local_2ec;
            FUN_140203270(&local_2d8,&local_2f8,&local_2b8,auVar33._0_8_);
            local_298 = 0;
            uStack_290 = 0;
            FUN_140203270(&local_298,&local_2e8,&local_2f8,auVar44._0_8_);
            local_288 = 0;
            uStack_280 = 0;
            FUN_140203270(&local_288,local_278,&local_2d8,auVar44._0_8_);
            fVar28 = auVar47._0_4_ - auVar44._0_4_;
            FUN_1400197d0(lVar21 + 0x278,&local_298,&local_288,(fVar28 + fVar28) * auVar44._0_4_);
            auVar49 = auVar36._0_16_;
            auVar46 = auVar50._0_16_;
            auVar43 = auVar47._0_16_;
            auVar40 = auVar27._0_16_;
          }
        }
        uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffcf8 >> 0x20);
        lVar12 = *(longlong *)(lVar20 + 1000);
        if (lVar12 != 0) {
          lVar21 = *(longlong *)(lVar20 + 0x3f0);
          local_res20 = *(float *)(lVar12 + 0x38);
          local_res18 = *(float *)(lVar12 + 0x3c);
          local_res8[0] = *(float *)(lVar12 + 0x48);
          fVar28 = *(float *)(lVar12 + 0x2c);
          fVar53 = *(float *)(lVar12 + 0x34);
          fVar52 = *(float *)(lVar12 + 0x30);
          fVar51 = *(float *)(lVar12 + 0x40);
          fVar48 = *(float *)(lVar12 + 0x44);
          fVar35 = *(float *)(lVar12 + 0x24);
          fVar31 = *(float *)(lVar12 + 0x20);
          fVar45 = *(float *)(lVar12 + 0x4c);
          fVar30 = *(float *)(lVar12 + 0x28);
          lVar22 = (ulonglong)*(byte *)(lVar20 + 0x234) * 0x27a0 + *(longlong *)(param_2 + 0xa8248);
          fVar41 = (float)*(byte *)(lVar12 + 0x55) * DAT_1402d1e98;
          fVar38 = (float)*(byte *)(lVar12 + 0x54) * DAT_1402d1e98;
          if (lVar21 != 0) {
            auVar40 = vcvtdq2ps_avx(ZEXT416((uint)(DAT_14033bd74 - *(int *)(lVar12 + 0x60))));
            auVar43 = vcvtdq2ps_avx(ZEXT416((uint)(*(int *)(lVar21 + 0x60) - *(int *)(lVar12 + 0x60)
                                                  )));
            fVar29 = auVar40._0_4_ / auVar43._0_4_;
            fVar7 = DAT_1402d22d0 - fVar29;
            fVar52 = fVar52 * fVar7 + fVar29 * *(float *)(lVar21 + 0x30);
            local_res20 = local_res20 * fVar7 + fVar29 * *(float *)(lVar21 + 0x38);
            fVar53 = fVar53 * fVar7 + fVar29 * *(float *)(lVar21 + 0x34);
            fVar48 = fVar48 * fVar7 + fVar29 * *(float *)(lVar21 + 0x44);
            local_res8[0] = fVar7 * local_res8[0] + fVar29 * *(float *)(lVar21 + 0x48);
            fVar28 = fVar28 * fVar7 + fVar29 * *(float *)(lVar21 + 0x2c);
            fVar51 = fVar51 * fVar7 + fVar29 * *(float *)(lVar21 + 0x40);
            local_res18 = fVar7 * local_res18 + fVar29 * *(float *)(lVar21 + 0x3c);
            fVar31 = fVar31 * fVar7 + fVar29 * *(float *)(lVar21 + 0x20);
            fVar35 = fVar35 * fVar7 + fVar29 * *(float *)(lVar21 + 0x24);
            auVar40 = vcvtdq2ps_avx(ZEXT116(*(byte *)(lVar21 + 0x54)));
            fVar38 = fVar38 * fVar7 + auVar40._0_4_ * fVar29 * DAT_1402d1e98;
            auVar40 = vcvtdq2ps_avx(ZEXT116(*(byte *)(lVar21 + 0x55)));
            fVar45 = fVar45 * fVar7 + fVar29 * *(float *)(lVar21 + 0x4c);
            fVar41 = fVar41 * fVar7 + auVar40._0_4_ * fVar29 * DAT_1402d1e98;
            fVar30 = fVar30 * fVar7 + fVar29 * *(float *)(lVar21 + 0x28);
          }
          lVar21 = *(longlong *)(lVar22 + 0x1630);
          fVar7 = fVar28 * DAT_1402d2614;
          *(float *)(lVar22 + 0x1650) = fVar52;
          *(float *)(lVar22 + 0x1654) = fVar53;
          *(float *)(lVar22 + 0x1658) = local_res20;
          *(float *)(lVar22 + 0x1640) = fVar28;
          *(float *)(lVar22 + 0x1848) = fVar7;
          *(float *)(lVar22 + 0x166c) = fVar48;
          *(float *)(lVar22 + 0x1854) = fVar48;
          *(float *)(lVar22 + 0x1668) = fVar51;
          *(float *)(lVar22 + 0x1850) = fVar51;
          *(float *)(lVar22 + 0x1670) = local_res8[0];
          *(float *)(lVar22 + 0x1664) = local_res18;
          *(float *)(lVar21 + 0x9f0) = fVar31;
          *(float *)(lVar21 + 0x9f4) = fVar35;
          *(float *)(*(longlong *)(lVar22 + 0x1630) + 0xa14) = fVar38;
          *(float *)(*(longlong *)(lVar22 + 0x1630) + 0xa20) = fVar41;
          lVar21 = *(longlong *)(lVar22 + 0x1630);
          puVar1 = (ushort *)(lVar21 + 0x9d4);
          *puVar1 = *puVar1 | 1;
          bVar5 = fVar30 < DAT_1402d1e40;
          *(float *)(lVar21 + 0xa10) = fVar30;
          if (bVar5) {
            puVar1 = (ushort *)(*(longlong *)(lVar22 + 0x1630) + 0x9d4);
            *puVar1 = *puVar1 & 0xfffe;
          }
          if (((*(longlong *)(param_2 + 0x67138) != 0) && (*(byte *)(param_2 + 0xa8829) < 2)) &&
             ((longlong)(char)*(byte *)(param_2 + 0xa8829) * 0xd10 +
              *(longlong *)(param_2 + 0x67138) != 0)) {
            lVar21 = FUN_140019ef0();
            *(float *)(lVar21 + 0x18) = fVar45;
          }
          uVar16 = *(uint *)(lVar22 + 0xd48) & 0x20000;
          if (uVar16 == 0) {
            cVar25 = '\x02';
          }
          else {
            cVar25 = *(char *)(lVar22 + 0xc3c);
          }
          cVar3 = *(char *)(lVar12 + 0x56);
          if (cVar3 == '\0') {
LAB_1401ba168:
            if (((byte)(cVar25 - 1U) < 2) && (uVar16 != 0)) {
              *(undefined1 *)(lVar22 + 0xc3c) = 3;
            }
          }
          else if ((cVar3 == '\x01') || (cVar3 == '\x02')) {
            if (((cVar25 == '\0') || (cVar25 == '\x03')) && (uVar16 != 0)) {
              *(undefined1 *)(lVar22 + 0xc3c) = 1;
            }
          }
          else if (cVar3 == '\x03') goto LAB_1401ba168;
          uVar23 = *(uint *)(lVar22 + 0xd48) & 0x40000;
          if (uVar23 == 0) {
            cVar25 = '\x02';
          }
          else {
            cVar25 = *(char *)(lVar22 + 0xc3d);
          }
          bVar10 = *(byte *)(lVar12 + 0x57);
          if (bVar10 == 0) {
            iVar11 = 0;
            if (((byte)(cVar25 - 1U) < 2) && (uVar23 != 0)) {
              *(undefined1 *)(lVar22 + 0xc3d) = 0;
              *(undefined4 *)(lVar22 + 0xc44) = 0x42480000;
            }
          }
          else if (bVar10 == 1) {
            iVar11 = 0;
            if (((cVar25 == '\0') || (cVar25 == '\x03')) && (uVar23 != 0)) {
              *(undefined1 *)(lVar22 + 0xc3d) = 1;
            }
          }
          else {
            iVar11 = bVar10 - 2;
            if (iVar11 == 0) {
              if (((cVar25 == '\0') || (cVar25 == '\x03')) && (uVar23 != 0)) {
                *(undefined1 *)(lVar22 + 0xc3d) = 2;
                *(undefined4 *)(lVar22 + 0xc44) = 0x42c80000;
              }
            }
            else if (((iVar11 == 1) && ((byte)(cVar25 - 1U) < 2)) && (uVar23 != 0)) {
              *(undefined1 *)(lVar22 + 0xc3d) = 3;
            }
          }
          in_stack_fffffffffffffcf8 = CONCAT44(uVar42,local_res18);
          FUN_14010ae70(lVar22,iVar11,uVar23,uVar16,fVar28,fVar48,fVar51,local_res8[0],
                        in_stack_fffffffffffffcf8);
          auVar43 = ZEXT416((uint)DAT_1402d22d0);
          auVar46 = ZEXT416(local_2a4);
          auVar49 = ZEXT416(local_2a0);
          auVar40 = ZEXT816(0);
          uVar32 = _DAT_1402d3760;
        }
        auVar33 = ZEXT1664(auVar40);
        auVar44 = ZEXT1664(auVar43);
        auVar47 = ZEXT1664(auVar46);
        auVar50 = ZEXT1664(auVar49);
        auVar27._0_8_ = FUN_140116e10(lVar20);
        auVar27._8_56_ = extraout_var;
        auVar36 = ZEXT464(DAT_1402d2c40);
        fVar28 = DAT_1402d1ea0;
LAB_1401ba297:
        fVar53 = DAT_1402d2108;
      }
      else {
        if (DAT_14033bd74 <= *(int *)(lVar12 + 0x60)) {
          for (lVar12 = *(longlong *)(lVar12 + 0x10); lVar12 != 0;
              lVar12 = *(longlong *)(lVar12 + 0x10)) {
            if (*(char *)(lVar12 + 0x6b) == '\0') goto LAB_1401b95a1;
          }
          lVar12 = 0;
LAB_1401b95a1:
          *(longlong *)(lVar20 + 0x3e0) = lVar12;
        }
        if (*(int *)(lVar20 + 0x3c0) <= DAT_14033bd74) {
          *(undefined4 *)(lVar20 + 0x288) = *(undefined4 *)(lVar20 + 600);
          *(undefined4 *)(lVar20 + 0x28c) = *(undefined4 *)(lVar20 + 0x25c);
          *(undefined4 *)(lVar20 + 0x290) = *(undefined4 *)(lVar20 + 0x260);
          *(undefined4 *)(lVar20 + 0x294) = *(undefined4 *)(lVar20 + 0x264);
          *(undefined4 *)(lVar20 + 0x298) = *(undefined4 *)(lVar20 + 0x268);
          *(undefined4 *)(lVar20 + 0x29c) = *(undefined4 *)(lVar20 + 0x26c);
          *(undefined4 *)(lVar20 + 0x2a0) = *(undefined4 *)(lVar20 + 0x270);
          *(undefined4 *)(lVar20 + 0x2a4) = *(undefined4 *)(lVar20 + 0x274);
          lVar21 = *(longlong *)(lVar20 + 0x3e0);
          lVar12 = *(longlong *)(lVar20 + 0x3e0);
          while( true ) {
            lVar22 = lVar12;
            if (lVar22 == 0) break;
            if (DAT_14033bd74 < *(int *)(lVar22 + 0x60)) {
              sVar24 = 0x13c;
              FUN_140126980(lVar20,*(undefined1 *)(lVar22 + 0x5c),*(undefined1 *)(lVar22 + 0x5d));
              break;
            }
            lVar12 = *(longlong *)(lVar22 + 0x10);
            while( true ) {
              lVar21 = lVar22;
              if (lVar12 == 0) {
                lVar22 = 0;
                goto LAB_1401b9682;
              }
              if (*(char *)(lVar12 + 0x6b) == '\0') break;
              lVar12 = *(longlong *)(lVar12 + 0x10);
            }
          }
LAB_1401b9682:
          if ((((*(short *)(lVar20 + 0x22e) == sVar24) || (*(short *)(lVar20 + 0x22e) == 0x13d)) &&
              ((*(byte *)(*(longlong *)(lVar20 + 0x3e0) + 0x50) & 2) == 0)) &&
             ((*(byte *)(lVar21 + 0x50) & 2) != 0)) {
            if (*(longlong **)(lVar20 + 0x390) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(lVar20 + 0x390) + 0x60))();
            }
            if (*(longlong **)(lVar20 + 0x398) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(lVar20 + 0x398) + 0x60))();
            }
          }
          *(longlong *)(lVar20 + 0x3e0) = lVar21;
          uVar16 = *(uint *)(lVar21 + 0x50);
          *(uint *)(lVar20 + 0x1f0) = uVar16;
          *(uint *)(lVar20 + 500) = (uint)*(ushort *)(lVar21 + 0x54);
          if (DAT_14033bd74 == *(int *)(lVar21 + 0x60)) {
            lVar12 = *(longlong *)(*param_1 + (ulonglong)*(byte *)(lVar20 + 0x234) * 8);
            *(uint *)(lVar12 + 0x120) =
                 (uint)*(ushort *)(lVar21 + 0x56) | *(uint *)(lVar12 + 0x120) & 0xffff0000;
          }
          cVar25 = *(char *)(lVar21 + 0x5c);
          cVar3 = *(char *)(lVar21 + 0x5d);
          if ((((cVar25 == -1) && (cVar3 == -1)) &&
              ((*(byte *)(lVar20 + 0x236) != 0xff &&
               ((*(char *)(lVar20 + 0x237) == -1 && ((*(uint *)(lVar20 + 0x1f8) & 0x100) != 0))))))
             && (lVar12 = *(longlong *)
                           (*(longlong *)
                             (**(longlong **)(lVar20 + 0x180) +
                             (ulonglong)*(byte *)(lVar20 + 0x236) * 8) + 0x110), lVar12 != -0x51ae0)
             ) {
            *(uint *)(lVar12 + 0x51cdc) = *(uint *)(lVar12 + 0x51cdc) | 0x10;
            *(undefined1 *)(lVar12 + 0x51d1e) = *(undefined1 *)(lVar20 + 0x234);
            *(undefined1 *)(lVar12 + 0x51d1f) = *(undefined1 *)(lVar20 + 0x235);
          }
          puVar13 = (undefined8 *)(lVar20 + 0x390);
          *(char *)(lVar20 + 0x236) = cVar25;
          *(char *)(lVar20 + 0x237) = cVar3;
          if ((*(uint *)(lVar20 + 0x1f0) & 2) == 0) {
            puVar13 = (undefined8 *)(lVar20 + 0x398);
          }
          *(undefined8 *)(lVar20 + 0x3a0) = *puVar13;
          if ((*(short *)(lVar20 + 0x44c) == 0) && ((uVar16 & 0x1080000) != 0)) {
            *(uint *)(lVar20 + 0x1f0) = *(uint *)(lVar20 + 0x1f0) | 2;
            *(undefined2 *)(lVar20 + 0x428) = 0;
            local_268 = 0;
            FUN_140118040(lVar20,&local_268,0,1000,
                          *(undefined1 *)(*(longlong *)(lVar20 + 0x3d0) + 0x40),0,
                          *(undefined1 *)(*(longlong *)(lVar20 + 0x3d0) + 0x41));
            *(short *)(lVar20 + 0x44c) = *(short *)(lVar20 + 0x44c) + 1;
          }
          fVar53 = auVar33._0_4_;
          if (((*(char *)(lVar20 + 0x234) == '\0') || ((*(byte *)(lVar20 + 500) & 0x80) != 0)) ||
             (*(short *)(lVar20 + 0x22e) == 0x646)) {
LAB_1401b98d3:
            if (lVar22 != 0) {
              auVar40 = ZEXT816(0);
              if (*(int *)(lVar21 + 0x60) == *(int *)(lVar22 + 0x60)) {
                local_208 = 0;
                local_258 = 0;
                uStack_254 = 0;
                uStack_250 = 0;
                uStack_24c = 0;
                local_200 = 0;
                local_1f4 = 0;
                uStack_248 = auVar36._0_4_;
                fStack_244 = fVar53;
                fStack_240 = fVar53;
                fStack_23c = fVar53;
                local_238 = auVar40;
                local_228 = ZEXT816(0);
                local_218 = auVar40;
                local_1f8 = fVar53;
                FUN_14001ddc0(&local_258,lVar22,auVar44._0_8_);
                auVar8._4_4_ = uStack_254;
                auVar8._0_4_ = local_258;
                auVar8._8_4_ = uStack_250;
                auVar8._12_4_ = uStack_24c;
                auVar8._16_4_ = uStack_248;
                auVar8._20_4_ = fStack_244;
                auVar8._24_4_ = fStack_240;
                auVar8._28_4_ = fStack_23c;
                *(undefined1 (*) [32])(lVar20 + 600) = auVar8;
                if (*(longlong *)(lVar20 + 0x360) != 0) {
                  *(float *)(*(longlong *)(lVar20 + 0x360) + 0x490) =
                       (float)*(byte *)(lVar22 + 0x5a) * fVar28;
                  fVar28 = (float)*(byte *)(lVar22 + 0x5b) * fVar28;
                  goto LAB_1401b9bae;
                }
              }
              else {
                local_168 = 0;
                local_160 = 0;
                local_154 = 0;
                local_1b8 = auVar40;
                local_1a8 = auVar36._0_4_;
                local_1a4 = fVar53;
                local_1a0 = fVar53;
                local_19c = fVar53;
                local_198 = auVar40;
                local_188 = ZEXT816(0);
                local_178 = auVar40;
                local_158 = fVar53;
                FUN_14001ddc0(local_1b8,lVar22,auVar44._0_8_);
                local_118 = ZEXT816(0);
                local_f8 = 0;
                local_f0 = 0;
                local_148 = 0;
                uStack_140 = 0;
                local_128 = 0;
                uStack_120 = 0;
                local_108 = 0;
                uStack_100 = 0;
                local_134 = auVar33._0_4_;
                local_138 = auVar36._0_4_;
                local_e4 = 0;
                local_130 = local_134;
                local_12c = local_134;
                local_e8 = local_134;
                FUN_14001ddc0(&local_148,lVar21,auVar44._0_8_);
                local_228 = ZEXT816(0);
                local_208 = 0;
                local_200 = 0;
                local_258 = 0;
                uStack_254 = 0;
                uStack_250 = 0;
                uStack_24c = 0;
                local_238 = ZEXT816(0);
                local_218 = ZEXT816(0);
                fStack_244 = auVar33._0_4_;
                uStack_248 = auVar36._0_4_;
                local_1f4 = 0;
                fStack_240 = fStack_244;
                fStack_23c = fStack_244;
                local_1f8 = fStack_244;
                FUN_14001df10(&local_258,&local_148,local_1b8,DAT_14033bd74);
                *(undefined4 *)(lVar20 + 600) = local_258;
                *(undefined4 *)(lVar20 + 0x25c) = uStack_254;
                *(undefined4 *)(lVar20 + 0x260) = uStack_250;
                *(undefined4 *)(lVar20 + 0x268) = uStack_248;
                *(float *)(lVar20 + 0x26c) = fStack_244;
                *(float *)(lVar20 + 0x270) = fStack_240;
                *(undefined4 *)(lVar20 + 0x264) = 0x3f800000;
                *(undefined4 *)(lVar20 + 0x274) = 0;
                if (*(longlong *)(lVar20 + 0x360) != 0) {
                  fVar53 = (float)((DAT_14033bd74 - *(int *)(lVar21 + 0x60)) /
                                  (*(int *)(lVar22 + 0x60) - *(int *)(lVar21 + 0x60)));
                  *(float *)(*(longlong *)(lVar20 + 0x360) + 0x490) =
                       (fVar53 * (float)*(byte *)(lVar21 + 0x5a) +
                       -((float)*(byte *)(lVar22 + 0x5a) * fVar53) + (float)*(byte *)(lVar22 + 0x5a)
                       ) * fVar28;
                  fVar28 = (fVar53 * (float)*(byte *)(lVar21 + 0x5b) +
                           -((float)*(byte *)(lVar22 + 0x5b) * fVar53) +
                           (float)*(byte *)(lVar22 + 0x5b)) * fVar28;
LAB_1401b9bae:
                  *(float *)(*(longlong *)(lVar20 + 0x360) + 0x494) = fVar28;
                }
              }
            }
            auVar49 = auVar50._0_16_;
            auVar46 = auVar47._0_16_;
            auVar43 = auVar44._0_16_;
            auVar40 = auVar33._0_16_;
            for (lVar12 = *(longlong *)(lVar21 + 0x10); lVar12 != 0;
                lVar12 = *(longlong *)(lVar12 + 0x10)) {
              auVar49 = auVar50._0_16_;
              auVar46 = auVar47._0_16_;
              auVar43 = auVar44._0_16_;
              auVar40 = auVar33._0_16_;
              if (*(int *)(lVar12 + 0x60) != DAT_14033bd74) break;
              cVar25 = *(char *)(lVar12 + 0x6b);
              if (cVar25 == '\x03') {
                if (*(short *)(lVar12 + 0x38) == 4) {
                  auVar33 = ZEXT1664(auVar40);
                  auVar44 = ZEXT1664(auVar43);
                  auVar47 = ZEXT1664(auVar46);
                  auVar50 = ZEXT1664(auVar49);
                  (**(code **)(**(longlong **)(lVar20 + 0x390) + 0x80))();
                }
                else if (*(short *)(lVar12 + 0x38) == 5) {
                  auVar33 = ZEXT1664(auVar40);
                  auVar44 = ZEXT1664(auVar43);
                  auVar47 = ZEXT1664(auVar46);
                  auVar50 = ZEXT1664(auVar49);
                  (**(code **)(**(longlong **)(lVar20 + 0x390) + 0x88))();
                }
              }
              else if (cVar25 == '\x04') {
                *(longlong *)(lVar20 + 1000) = lVar12;
                for (lVar21 = *(longlong *)(lVar12 + 0x10); lVar21 != 0;
                    lVar21 = *(longlong *)(lVar21 + 0x10)) {
                  if (*(char *)(lVar21 + 0x6b) == '\x04') goto LAB_1401b9c3d;
                }
                lVar21 = 0;
LAB_1401b9c3d:
                *(longlong *)(lVar20 + 0x3f0) = lVar21;
              }
              else if (cVar25 == '\x05') {
                *(longlong *)(lVar20 + 0x3f8) = lVar12;
                for (lVar21 = *(longlong *)(lVar12 + 0x10); lVar21 != 0;
                    lVar21 = *(longlong *)(lVar21 + 0x10)) {
                  if (*(char *)(lVar21 + 0x6b) == '\x05') goto LAB_1401b9c12;
                }
                lVar21 = 0;
LAB_1401b9c12:
                *(longlong *)(lVar20 + 0x400) = lVar21;
              }
              auVar49 = auVar50._0_16_;
              auVar46 = auVar47._0_16_;
              auVar43 = auVar44._0_16_;
              auVar40 = auVar33._0_16_;
            }
            fVar53 = DAT_1402d2108;
            goto LAB_1401b9c99;
          }
          fVar52 = fVar53;
          fVar51 = fVar53;
          fVar48 = fVar53;
          if (*(char *)(lVar21 + 0x6b) == '\0') {
            fVar52 = *(float *)(lVar21 + 0x20);
            fVar51 = *(float *)(lVar21 + 0x28);
            fVar48 = *(float *)(lVar21 + 0x24);
          }
          auVar27 = ZEXT464((uint)local_2a8);
          if (((float)((uint)(auVar50._0_4_ - fVar52) & (uint)uVar32) +
              (float)((uint)(auVar47._0_4_ - fVar51) & (uint)uVar32)) - local_2a8 <= fVar53)
          goto LAB_1401b98d3;
          *(float *)(lVar20 + 600) = fVar52;
          *(float *)(lVar20 + 0x25c) = fVar48;
          *(float *)(lVar20 + 0x260) = fVar51;
          *(undefined4 *)(lVar20 + 0x264) = 0x3f800000;
          iVar11 = DAT_14033bda0 + 1;
          *(int *)(lVar20 + 0x3c0) = DAT_14033bda0;
          DAT_14033bda0 = iVar11;
          goto LAB_1401ba297;
        }
      }
      lVar20 = *(longlong *)(lVar20 + 0x3b8);
    } while (lVar20 != 0);
  }
  iVar11 = (int)DAT_14033bd90[0xc];
  plVar9 = DAT_14033bd90;
  while ((plVar19 = plVar9, iVar11 != 0 && (iVar11 < DAT_14033bd74))) {
    plVar9 = (longlong *)*plVar19;
    DAT_14033bd90 = plVar19;
    iVar11 = *(int *)((longlong *)*plVar19 + 0xc);
  }
  iVar11 = (int)plVar19[0xc];
  if (iVar11 != 0) {
    uVar32 = _DAT_1402d3500;
    uVar34 = _UNK_1402d3508;
    lVar20 = _DAT_1402d35f0;
    uVar37 = _UNK_1402d35f8;
    do {
      if (iVar11 != DAT_14033bd74) break;
      lVar21 = (ulonglong)*(byte *)((longlong)plVar19 + 0x67) * 0x520 +
               *(longlong *)
                (*(longlong *)(*param_1 + (ulonglong)*(byte *)((longlong)plVar19 + 0x66) * 8) +
                0x110);
      lVar12 = **(longlong **)(unaff_GS_OFFSET + 0x58);
      DAT_14033bd90 = plVar19;
      if (*(int *)(lVar12 + 4) < DAT_1437dad18) {
        auVar27._0_8_ = FUN_14022d540(&DAT_1437dad18);
        auVar27._8_56_ = extraout_var_07;
        if (DAT_1437dad18 == -1) {
          _DAT_1437daef0 = 0;
          DAT_1437daef4 = 0;
          _DAT_1437daee0 = uVar32;
          uRam00000001437daee8 = uVar34;
          auVar27._0_8_ = _Init_thread_footer(&DAT_1437dad18);
          auVar27._8_56_ = extraout_var_08;
        }
      }
      uVar26 = auVar27._0_8_;
      cVar25 = *(char *)((longlong)plVar19 + 0x6b);
      uVar42 = auVar44._0_4_;
      if (cVar25 == '\x02') {
        sVar24 = (short)plVar19[4];
        uVar39 = auVar33._0_4_;
        if (sVar24 == 0) {
          _DAT_14033bda4 = (undefined4)plVar19[6];
          lVar12 = *(longlong *)(lVar21 + 0x178);
          local_2d8 = *(longlong *)((longlong)plVar19 + 0x34);
          local_278._12_4_ = uVar39;
          local_278._0_12_ = *(undefined1 (*) [12])(plVar19 + 8);
          uStack_2d0 = CONCAT44(uVar42,*(undefined4 *)((longlong)plVar19 + 0x3c));
          iVar11 = FUN_14013d140(lVar12,&local_2d8,local_278,
                                 *(undefined4 *)((longlong)plVar19 + 0x4c),
                                 *(undefined1 *)(lVar21 + 0x234),*(undefined1 *)(lVar21 + 0x235),
                                 *(undefined1 *)((longlong)plVar19 + 0x22),
                                 *(undefined1 *)((longlong)plVar19 + 0x23),plVar19[5],
                                 (char)plVar19[10]);
          auVar27._8_56_ = extraout_var_06;
          auVar27._0_8_ = extraout_XMM0_Qa_00;
          if (-1 < iVar11) {
            *(undefined1 *)(lVar12 + 0x1fd90) = 0;
            piVar17 = (int *)0x0;
            lVar12 = (longlong)DAT_14033d9b4;
            if (DAT_14033d9b4 < 0x80) {
              DAT_14033d9b4 = DAT_14033d9b4 + 1;
              lVar22 = lVar12 * 0x18;
              piVar17 = &DAT_14033bdb0 + lVar12 * 6;
              if (piVar17 != (int *)0x0) {
                (&DAT_14033bdc0)[lVar22] = 0;
                (&DAT_14033bdc1)[lVar22] = (char)plVar19[10];
                *piVar17 = iVar11;
                (&DAT_14033bdb8)[lVar12 * 3] = plVar19[5];
                (&DAT_14033bdc2)[lVar22] = (char)plVar19[10];
                (&DAT_14033bdc3)[lVar22] = *(undefined1 *)(lVar21 + 0x234);
                (&DAT_14033bdc4)[lVar22] = *(undefined1 *)(lVar21 + 0x235);
                (&DAT_14033bdc5)[lVar22] = *(undefined1 *)((longlong)plVar19 + 0x22);
                (&DAT_14033bdc6)[lVar22] = *(undefined1 *)((longlong)plVar19 + 0x23);
              }
            }
            if ((*(char *)((longlong)piVar17 + 0x13) == '\0') && ((char)piVar17[5] == '\0')) {
              DAT_14033d9b8 = DAT_14033d9b8 + 1;
              lVar12 = *(longlong *)(param_2 + 0xa8248);
              lVar21 = (ulonglong)*(byte *)((longlong)piVar17 + 0x13) * 0x27a0;
              cVar25 = *(char *)(lVar21 + lVar12 + 0x2099);
              if (cVar25 != '\0') {
                *(char *)(lVar21 + lVar12 + 0x2099) = cVar25 + -1;
              }
              uVar16 = (DAT_14033d9c0 - DAT_14033d9b8) + 1;
              uVar18 = (ulonglong)uVar16;
              cVar25 = DAT_14033d9c8;
              if (0 < (int)uVar16) {
                do {
                  cVar25 = cVar25 == '\0';
                  uVar18 = uVar18 - 1;
                } while (uVar18 != 0);
              }
              if (cVar25 == '\0') {
                pbVar2 = (byte *)(lVar21 + lVar12 + 0x1f18);
                *pbVar2 = *pbVar2 | 1;
              }
              else {
                pbVar2 = (byte *)(lVar21 + lVar12 + 0x1f30);
                *pbVar2 = *pbVar2 | 1;
              }
              *(bool *)(lVar21 + lVar12 + 0x209c) = cVar25 == '\0';
            }
          }
        }
        else if (sVar24 == 1) {
          _DAT_14033bda4 = (undefined4)plVar19[6];
          local_298 = plVar19[8];
          lVar12 = *(longlong *)(lVar21 + 0x178);
          local_288 = *(longlong *)((longlong)plVar19 + 0x34);
          uStack_290 = CONCAT44(uVar39,(int)plVar19[9]);
          uStack_280 = CONCAT44(uVar42,*(undefined4 *)((longlong)plVar19 + 0x3c));
          iVar11 = FUN_140141200(lVar12 + 0x1b10,&local_288,&local_298,
                                 *(undefined4 *)((longlong)plVar19 + 0x4c),
                                 *(undefined1 *)(lVar21 + 0x234),*(undefined1 *)(lVar21 + 0x235),
                                 *(undefined1 *)((longlong)plVar19 + 0x22),
                                 *(undefined1 *)((longlong)plVar19 + 0x23),plVar19[5],
                                 (char)plVar19[10]);
          auVar27._8_56_ = extraout_var_05;
          auVar27._0_8_ = extraout_XMM0_Qa;
          if (-1 < iVar11) {
            *(undefined1 *)(lVar12 + 0x1fd90) = 1;
            piVar17 = (int *)0x0;
            lVar12 = (longlong)DAT_14033d9b4;
            if (DAT_14033d9b4 < 0x80) {
              DAT_14033d9b4 = DAT_14033d9b4 + 1;
              lVar22 = lVar12 * 0x18;
              piVar17 = &DAT_14033bdb0 + lVar12 * 6;
              if (piVar17 != (int *)0x0) {
                (&DAT_14033bdc0)[lVar22] = 1;
                (&DAT_14033bdc1)[lVar22] = (char)plVar19[10];
                *piVar17 = iVar11;
                (&DAT_14033bdb8)[lVar12 * 3] = plVar19[5];
                (&DAT_14033bdc2)[lVar22] = (char)plVar19[10];
                (&DAT_14033bdc3)[lVar22] = *(undefined1 *)(lVar21 + 0x234);
                (&DAT_14033bdc4)[lVar22] = *(undefined1 *)(lVar21 + 0x235);
                (&DAT_14033bdc5)[lVar22] = *(undefined1 *)((longlong)plVar19 + 0x22);
                (&DAT_14033bdc6)[lVar22] = *(undefined1 *)((longlong)plVar19 + 0x23);
              }
            }
            if ((*(char *)((longlong)piVar17 + 0x13) == '\0') && ((char)piVar17[5] == '\0')) {
              _DAT_14033d9bc = _DAT_14033d9bc + 1;
              lVar12 = (ulonglong)*(byte *)((longlong)piVar17 + 0x13) * 0x27a0 +
                       *(longlong *)(param_2 + 0xa8248);
              if (*(char *)(lVar12 + 0x209a) != '\0') {
                *(char *)(lVar12 + 0x209a) = *(char *)(lVar12 + 0x209a) + -1;
              }
              bVar15 = *(byte *)(lVar12 + 0x209d) + 1;
              pbVar2 = (byte *)(lVar12 + ((ulonglong)*(byte *)(lVar12 + 0x209d) * 3 + 0x3e9) * 8);
              *pbVar2 = *pbVar2 | 1;
              bVar10 = 0;
              if (bVar15 < *(byte *)(lVar12 + 0x20b4)) {
                bVar10 = bVar15;
              }
              *(byte *)(lVar12 + 0x209d) = bVar10;
            }
          }
        }
        else if (sVar24 == 2) {
          local_1c8 = (undefined4)plVar19[8];
          local_1c4 = *(undefined4 *)((longlong)plVar19 + 0x44);
          local_1c0 = (undefined4)plVar19[9];
          local_268 = *(longlong *)((longlong)plVar19 + 0x34);
          local_260 = *(undefined4 *)((longlong)plVar19 + 0x3c);
          local_25c = uVar42;
          local_1bc = uVar39;
          auVar27._0_8_ =
               FUN_14013ace0(*(longlong *)(lVar21 + 0x178) + 0xca0,&local_268,&local_1c8,
                             *(undefined4 *)((longlong)plVar19 + 0x4c),
                             *(undefined1 *)(lVar21 + 0x234),*(undefined1 *)(lVar21 + 0x235),
                             plVar19[5],(char)plVar19[10] != '\0');
          auVar27._8_56_ = extraout_var_04;
          bVar10 = *(byte *)(lVar21 + 0x234);
          if (((bVar10 == 0) || ((bVar10 == 1 && (1 < *(byte *)(param_2 + 0xa87e4))))) &&
             (*(char *)(lVar21 + 0x235) == '\0')) {
            lVar12 = *(longlong *)(param_2 + 0xa8248);
            lVar22 = (ulonglong)bVar10 * 0x27a0;
            lVar21 = *(longlong *)(lVar22 + 0x1ef0 + lVar12);
            if (lVar21 == 0) {
              *(undefined1 *)(lVar22 + 0x272f + lVar12) = 1;
            }
            else {
              lVar14 = FUN_140189320();
              auVar27 = ZEXT1664(CONCAT124(SUB1612(ZEXT816(0),4),(float)*(int *)(lVar14 + 0xc)));
              *(char *)(lVar22 + 0x272f + lVar12) =
                   (char)(int)((float)*(int *)(lVar14 + 0xc) * *(float *)(lVar21 + 0x24)) + '\x01';
            }
          }
        }
      }
      else if (cVar25 == '\x03') {
        if ((short)plVar19[7] == 6) {
          local_1e8 = plVar19[4];
          uStack_1e0 = CONCAT44(uVar42,(int)plVar19[5]);
          local_1d8 = 0;
          auVar27._0_8_ = FUN_140031f80(*(undefined8 *)(param_1[4] + 0x66ee0),0x2a,&local_1e8,0);
          auVar27._8_56_ = extraout_var_03;
        }
      }
      else if (cVar25 == '\a') {
        if (*(char *)((longlong)plVar19 + 0x4c) == '\0') {
          if ((*(int *)(lVar12 + 4) < DAT_1437dad18) &&
             (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
            _DAT_1437daef0 = 0;
            DAT_1437daef4 = 0;
            _DAT_1437daee0 = uVar32;
            uRam00000001437daee8 = uVar34;
            _Init_thread_footer(&DAT_1437dad18);
          }
          local_2e8 = *(undefined4 *)((longlong)plVar19 + 0x2c);
          local_2f8 = (undefined4)plVar19[4];
          DAT_14032c480 = DAT_14032c480 + 1;
          uVar4 = *(ushort *)((longlong)plVar19 + 0x4a);
          local_2e0 = *(undefined4 *)((longlong)plVar19 + 0x34);
          local_2f4 = *(undefined4 *)((longlong)plVar19 + 0x24);
          local_2f0 = (undefined4)plVar19[5];
          local_2dc = auVar33._0_4_;
          local_2ec = auVar44._0_4_;
          if ((((short)plVar19[9] == 3) || ((short)plVar19[9] == 4)) && (uVar4 < 3)) {
            uVar4 = DAT_1437dece8;
          }
          local_res8[0] = (float)CONCAT22(local_res8[0]._2_2_,uVar4);
          local_2e4 = local_2e8;
          local_1e8 = lVar20;
          uStack_1e0 = uVar37;
          auVar27._0_8_ =
               FUN_1401c5d20(local_2f4,plVar19 + 9,local_res8,&local_2f8,&local_2e8,&local_1e8,
                             *(char *)((longlong)plVar19 + 0x4d) != '\0');
          auVar27._8_56_ = extraout_var_02;
          DAT_14032c480 = DAT_14032c480 + -1;
        }
        else {
          if ((*(int *)(lVar12 + 4) < DAT_1437dad18) &&
             (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
            _DAT_1437daef0 = 0;
            DAT_1437daef4 = 0;
            _DAT_1437daee0 = uVar32;
            uRam00000001437daee8 = uVar34;
            _Init_thread_footer(&DAT_1437dad18);
          }
          local_2b8 = *(undefined4 *)((longlong)plVar19 + 0x2c);
          local_2c8 = (undefined4)plVar19[4];
          DAT_14032c480 = DAT_14032c480 + 1;
          uVar4 = *(ushort *)((longlong)plVar19 + 0x4a);
          local_2b0 = *(undefined4 *)((longlong)plVar19 + 0x34);
          local_2c4 = *(undefined4 *)((longlong)plVar19 + 0x24);
          local_2c0 = (undefined4)plVar19[5];
          local_2ac = auVar33._0_4_;
          local_2bc = auVar44._0_4_;
          if ((((short)plVar19[9] == 3) || ((short)plVar19[9] == 4)) && (uVar4 < 3)) {
            uVar4 = DAT_1437dece8;
          }
          local_res8[0] = (float)CONCAT22(local_res8[0]._2_2_,uVar4);
          local_2b4 = local_2b8;
          auVar27._0_8_ =
               FUN_1401c5e10((longlong)plVar19 + 0x3c,plVar19 + 9,local_res8,&local_2c8,&local_2b8);
          auVar27._8_56_ = extraout_var_01;
          DAT_14032c480 = DAT_14032c480 + -1;
        }
      }
      else if (cVar25 == '\b') {
        if ((*(int *)(lVar12 + 4) < DAT_1437dad18) &&
           (uVar26 = FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
          _DAT_1437daef0 = 0;
          DAT_1437daef4 = 0;
          _DAT_1437daee0 = uVar32;
          uRam00000001437daee8 = uVar34;
          uVar26 = _Init_thread_footer(&DAT_1437dad18);
        }
        local_res8[0] =
             (float)CONCAT22(local_res8[0]._2_2_,*(undefined2 *)((longlong)plVar19 + 0x22));
        auVar27._0_8_ = FUN_1401c6150(uVar26,plVar19 + 4,local_res8);
        auVar27._8_56_ = extraout_var_00;
      }
      plVar19 = (longlong *)*plVar19;
      iVar11 = (int)plVar19[0xc];
    } while (iVar11 != 0);
  }
  DAT_14033bd74 = DAT_14033bd74 + 1;
  if (DAT_14033bd7c < DAT_14033bd74) {
    FUN_1401b8130(param_2,1);
  }
  return DAT_14033bd7c - DAT_14033bd74;
}

