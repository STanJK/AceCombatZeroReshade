/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140092e60; RVA 0x92e60
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8
FUN_140092e60(longlong param_1,undefined1 (*param_2) [16],undefined4 *param_3,undefined4 *param_4,
             longlong *param_5)

{
  float fVar1;
  float fVar2;
  undefined1 auVar3 [16];
  byte bVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auVar7 [16];
  float fVar8;
  float fVar9;
  undefined1 auVar10 [16];
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined4 uVar17;
  undefined1 auVar18 [64];
  undefined4 uVar19;
  undefined1 auVar20 [64];
  undefined4 uVar21;
  undefined1 auVar22 [64];
  float fVar23;
  undefined1 auVar24 [64];
  float fVar25;
  undefined4 uVar26;
  uint uVar27;
  uint local_res10;
  longlong local_1b8;
  undefined1 local_1b0 [16];
  float local_1a0;
  undefined1 auStack_19c [4];
  undefined8 uStack_198;
  undefined4 local_188;
  float local_184;
  uint local_180;
  float local_17c;
  float local_178;
  undefined4 local_174;
  float local_170;
  float local_16c;
  uint local_168;
  float local_164;
  undefined4 local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  undefined4 local_14c;
  undefined4 local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  undefined4 local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  undefined4 local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  undefined4 local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  longlong local_f8;
  longlong local_f0;
  ulonglong local_e8;
  longlong local_e0;
  ulonglong local_d8;
  
  auVar3 = *param_2;
  fVar25 = *(float *)param_2[2];
  fVar23 = *(float *)(param_2[2] + 4);
  fVar1 = *(float *)(param_2[2] + 8);
  fVar2 = *(float *)(param_2[2] + 0xc);
  uVar16 = (ulonglong)(byte)param_2[5][0];
  auVar7 = vshufps_avx(auVar3,auVar3,0x55);
  uStack_198 = auVar3._8_8_;
  auStack_19c = (undefined1  [4])auVar7._0_4_;
  local_108 = auVar3._0_4_ + fVar25;
  local_104 = auVar7._0_4_ + fVar23;
  auVar7 = vshufps_avx(auVar3,auVar3,0xaa);
  local_1a0 = auVar3._0_4_;
  auVar10 = _local_1a0;
  local_100 = auVar7._0_4_ + fVar1;
  uStack_198._4_4_ = auVar3._12_4_;
  _local_1a0 = auVar10._0_8_;
  uStack_198._0_4_ = auVar7._0_4_;
  auVar3 = vshufps_avx(auVar3,auVar3,0xff);
  local_fc = auVar3._0_4_ + fVar2;
  bVar4 = *(byte *)((longlong)*(longlong **)(param_1 + 0x10) + 0x34);
  local_d8 = (ulonglong)bVar4;
  lVar13 = **(longlong **)(param_1 + 0x10);
  local_res10 = 0;
  fVar25 = SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar25 * fVar25 + fVar23 * fVar23);
  if (bVar4 == 0) {
    return 0;
  }
  auVar24 = ZEXT464(DAT_1402d2698);
  local_1b8 = 0;
  fVar23 = 0.0;
  uVar26 = DAT_1402d22d0;
  uVar27 = DAT_1402d3770;
  local_e8 = uVar16;
  local_e0 = lVar13;
  do {
    local_f0 = **(longlong **)(param_1 + 0x10);
    lVar15 = *(longlong *)(local_f0 + local_1b8 * 8);
    bVar4 = *(byte *)(*(longlong *)(lVar13 + uVar16 * 8) + 0x15d);
    if (*(byte *)(lVar15 + 0x15d) != bVar4) {
      if ((&DAT_1402accc0)[(ulonglong)bVar4 + (ulonglong)*(byte *)(lVar15 + 0x15d) * 8] != '\0') {
        if ((*(byte *)(lVar15 + 0x120) & 4) != 0) {
          local_f8 = (longlong)*(int *)(lVar15 + 0x118);
          uVar14 = 0;
          lVar15 = 0;
          if (0 < local_f8) {
            lVar13 = 0;
            do {
              if (((local_res10 != (byte)param_2[5][0]) || (uVar14 != (byte)param_2[5][1])) &&
                 (lVar12 = *(longlong *)(*(longlong *)(local_f0 + local_1b8 * 8) + 0x110) + lVar13,
                 (*(byte *)(lVar12 + 0x1f0) & 1) != 0)) {
                local_1b0 = *(undefined1 (*) [16])(lVar12 + 600);
                auVar18 = ZEXT1664(local_1b0);
                fVar2 = local_1b0._0_4_ - local_1a0;
                auVar3 = vshufps_avx(local_1b0,local_1b0,0x55);
                auVar20 = ZEXT1664(auVar3);
                fVar8 = auVar3._0_4_ - (float)auStack_19c;
                auVar3 = vshufps_avx(local_1b0,local_1b0,0xaa);
                auVar22 = ZEXT1664(auVar3);
                fVar9 = auVar3._0_4_ - (float)uStack_198;
                fVar1 = fVar25 + *(float *)(lVar12 + 0x41c);
                if (fVar9 * fVar9 + fVar8 * fVar8 + fVar2 * fVar2 <= fVar1 * fVar1) {
                  plVar5 = *(longlong **)(lVar12 + 0x3a0);
                  lVar6 = **(longlong **)(lVar12 + 0x1a0);
                  if (*(char *)(lVar6 + 0x6f) == '\x01') {
                    uVar16 = (ulonglong)*(uint *)(lVar6 + 0x40);
                  }
                  else if (plVar5 == (longlong *)0x0) {
                    uVar16 = auVar24._0_8_;
                  }
                  else {
                    uVar16 = (**(code **)(*plVar5 + 0xa0))(plVar5);
                    auVar22 = ZEXT464((uint)local_1b0._8_4_);
                    auVar20 = ZEXT464((uint)local_1b0._4_4_);
                    auVar18 = ZEXT464((uint)local_1b0._0_4_);
                  }
                  iVar11 = FUN_14014d070(&local_1a0,&local_108,local_1b0,uVar16);
                  if (iVar11 != 0) {
                    uVar19 = auVar20._0_4_;
                    uVar21 = auVar22._0_4_;
                    uVar17 = auVar18._0_4_;
                    if (*(char *)(lVar6 + 0x6f) != '\x02') {
LAB_1400932fc:
                      *param_3 = uVar17;
                      param_3[1] = uVar19;
                      param_3[2] = uVar21;
                      param_3[3] = local_1b0._12_4_;
                      *param_4 = 1;
                      if (param_5 != (longlong *)0x0) {
                        *param_5 = lVar12;
                      }
                      return 1;
                    }
                    if (plVar5 != (longlong *)0x0) {
                      auVar18._0_8_ =
                           FUN_14026f3f3(*(undefined4 *)(lVar12 + 0x26c),
                                         *(undefined4 *)(lVar12 + 0x268));
                      auVar18._8_56_ = extraout_var;
                      auVar3 = vpermilps_avx(auVar18._0_16_,1);
                      auVar7 = vpermilps_avx(auVar18._0_16_,0xe);
                      local_168 = (uint)auVar18._0_8_;
                      local_180 = local_168 ^ uVar27;
                      local_188 = auVar3._0_4_;
                      auVar3 = vpermilps_avx(auVar7,1);
                      local_130 = auVar7._0_4_;
                      local_124 = (float)((uint)local_130 ^ uVar27);
                      local_134 = auVar3._0_4_;
                      local_184 = fVar23;
                      local_17c = fVar23;
                      local_178 = fVar23;
                      local_174 = uVar26;
                      local_170 = fVar23;
                      local_16c = fVar23;
                      local_164 = fVar23;
                      local_160 = local_188;
                      local_15c = fVar23;
                      local_158 = fVar23;
                      local_154 = fVar23;
                      local_150 = fVar23;
                      local_14c = uVar26;
                      local_148 = uVar26;
                      local_144 = fVar23;
                      local_140 = fVar23;
                      local_13c = fVar23;
                      local_138 = fVar23;
                      local_12c = fVar23;
                      local_128 = fVar23;
                      local_120 = local_134;
                      local_11c = fVar23;
                      local_118 = fVar23;
                      local_114 = fVar23;
                      local_110 = fVar23;
                      local_10c = uVar26;
                      FUN_140005940(&local_188,&local_188,&local_148);
                      auVar20._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar12 + 0x270));
                      auVar20._8_56_ = extraout_var_00;
                      auVar3 = vpermilps_avx(auVar20._0_16_,1);
                      local_144 = (float)auVar20._0_8_;
                      local_138 = (float)((uint)local_144 ^ uVar27);
                      local_148 = auVar3._0_4_;
                      local_134 = local_148;
                      local_130 = fVar23;
                      local_124 = fVar23;
                      local_120 = uVar26;
                      FUN_140005940(&local_188,&local_188,&local_148);
                      local_158 = local_158 + *(float *)(lVar12 + 600);
                      local_154 = local_154 + *(float *)(lVar12 + 0x25c);
                      local_150 = local_150 + *(float *)(lVar12 + 0x260);
                      iVar11 = (**(code **)(*plVar5 + 0x120))
                                         (plVar5,local_1b0,&local_188,&local_1a0,&local_108);
                      if (iVar11 != 0) {
                        uVar19 = local_1b0._4_4_;
                        uVar21 = local_1b0._8_4_;
                        uVar17 = local_1b0._0_4_;
                        goto LAB_1400932fc;
                      }
                    }
                  }
                }
              }
              uVar14 = uVar14 + 1;
              lVar15 = lVar15 + 1;
              lVar13 = lVar13 + 0x520;
            } while (lVar15 < local_f8);
            lVar13 = local_e0;
            uVar16 = local_e8;
          }
        }
      }
    }
    local_res10 = local_res10 + 1;
    local_1b8 = local_1b8 + 1;
    if ((longlong)local_d8 <= local_1b8) {
      return 0;
    }
  } while( true );
}

