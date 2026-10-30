/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ac760; RVA 0x1ac760
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1401ac760(float *param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  undefined1 auVar6 [16];
  float fVar7;
  float fVar8;
  uint uVar10;
  undefined1 auVar9 [16];
  float fVar11;
  undefined1 auVar12 [16];
  undefined1 auVar13 [64];
  float fVar14;
  float fVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [64];
  undefined1 auVar18 [64];
  float fVar19;
  float *in_stack_00000030;
  undefined4 local_e8;
  undefined4 local_e4;
  float local_e0;
  float local_dc;
  undefined1 local_d8 [8];
  float fStack_d0;
  float fStack_cc;
  undefined1 auStack_c8 [32];
  undefined1 local_a8 [8];
  float fStack_a0;
  undefined1 local_98 [16];
  undefined1 local_88 [8];
  float fStack_80;
  undefined1 local_78 [8];
  float fStack_70;
  
  _local_d8 = ZEXT832(0);
  lVar1 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  FUN_1401b71e0(param_1,local_d8,lVar1);
  param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xffffffe7);
  iVar5 = FUN_140242630();
  if ((uint)(iVar5 % 100) < 0x1e) {
    param_1[0x19f] = (float)((uint)param_1[0x19f] | 8);
  }
  else if ((uint)(iVar5 % 100) < 0x32) {
    param_1[0x19f] = (float)((uint)param_1[0x19f] | 0x10);
  }
  if (((uint)param_1[0x19f] & 8) == 0) {
    auVar6 = vpcmpeqd_avx(ZEXT116(SUB41(param_1[0x19f],0) & 0x10),SUB6416(ZEXT464(0),0));
    auVar6 = vblendvps_avx(ZEXT416(DAT_1402d29d0),ZEXT416(DAT_1402d28ec),auVar6);
    auVar18 = ZEXT1664(auVar6);
  }
  else {
    auVar18 = ZEXT464(DAT_1402d256c);
  }
  fVar19 = 0.0;
  local_e8 = 0;
  local_e4 = 0;
  iVar5 = FUN_140242630();
  local_e0 = (float)(iVar5 % 10000) * DAT_1402d1e18 - DAT_1402d2420;
  local_98 = ZEXT816(0);
  _local_a8 = ZEXT416(0);
  local_dc = fVar19;
  _local_88 = _local_a8;
  _local_78 = local_98;
  FUN_140202920(local_a8,&local_e8);
  FUN_140202230(local_a8,local_a8,auStack_c8);
  fVar7 = auVar18._0_4_;
  fVar8 = fVar7 * (float)local_a8._4_4_ + (float)local_78._4_4_;
  auVar9 = ZEXT416((uint)fVar8);
  fVar14 = fVar7 * fStack_a0 + fStack_70;
  auVar16 = ZEXT416((uint)fVar14);
  fVar11 = fVar7 * local_a8._0_4_ + local_78._0_4_;
  auVar12._4_12_ = local_78._4_12_;
  auVar12._0_4_ = fVar11;
  auVar6 = vshufps_avx(_local_a8,_local_a8,0xff);
  auVar2 = vshufps_avx(_local_78,_local_78,0xff);
  fVar7 = fVar7 * auVar6._0_4_ + auVar2._0_4_;
  fVar11 = SQRT(fVar14 * fVar14 + fVar8 * fVar8 + fVar11 * fVar11);
  if (fVar11 != fVar19) {
    fVar8 = fVar8 / fVar11;
  }
  auVar13 = ZEXT464((uint)DAT_1402d22d0);
  if ((fVar8 < DAT_1402d2d5c) || (fVar11 = DAT_1402d22d0, DAT_1402d2280 < fVar8)) {
    FUN_140202920(local_a8,auStack_c8);
    fVar11 = DAT_1402d2d64 * (float)local_88._0_4_;
    fVar8 = DAT_1402d2d64 * (float)local_88._4_4_;
    fVar7 = SQRT(DAT_1402d2d64 * fStack_80 * DAT_1402d2d64 * fStack_80 +
                 fVar8 * fVar8 + fVar11 * fVar11);
    if (fVar7 != fVar19) {
      fVar7 = auVar13._0_4_ / fVar7;
      fVar11 = fVar7 * fVar11;
      fVar8 = fVar7 * fVar8;
    }
    uVar10 = 0;
    auVar6 = vmaxss_avx(ZEXT416((uint)fVar8),ZEXT416((uint)DAT_1402d2d64));
    auVar6 = vminss_avx(auVar6,auVar13._0_16_);
    local_e8 = FUN_140272150(auVar6._0_8_);
    local_e4 = FUN_140272370(CONCAT44(uVar10 ^ _UNK_1402d3774,(uint)fVar11 ^ DAT_1402d3770));
    local_98 = ZEXT816(0);
    _local_a8 = ZEXT816(0);
    _local_88 = ZEXT816(0);
    local_e0 = fVar19;
    local_dc = fVar19;
    _local_78 = local_98;
    FUN_140202920(local_a8,&local_e8);
    fVar11 = auVar13._0_4_;
    auVar6 = vshufps_avx(_local_78,_local_78,0x55);
    auVar2 = vshufps_avx(_local_78,_local_78,0xaa);
    auVar16 = vshufps_avx(_local_a8,_local_a8,0x55);
    auVar3 = vshufps_avx(_local_a8,_local_a8,0xaa);
    fVar8 = auVar18._0_4_;
    auVar12._4_12_ = local_78._4_12_;
    auVar12._0_4_ = fVar8 * local_a8._0_4_ + local_78._0_4_;
    auVar9 = vshufps_avx(_local_a8,_local_a8,0xff);
    auVar4 = vshufps_avx(_local_78,_local_78,0xff);
    fVar7 = fVar8 * auVar9._0_4_ + auVar4._0_4_;
    auVar9._4_12_ = auVar6._4_12_;
    auVar9._0_4_ = fVar8 * auVar16._0_4_ + auVar6._0_4_;
    auVar16._4_12_ = auVar2._4_12_;
    auVar16._0_4_ = fVar8 * auVar3._0_4_ + auVar2._0_4_;
  }
  auVar17 = ZEXT1664(auVar16);
  fVar15 = auVar16._0_4_;
  auVar13 = ZEXT1664(auVar12);
  fVar8 = auVar12._0_4_;
  auVar18 = ZEXT1664(auVar9);
  fVar14 = auVar9._0_4_;
  if (((uint)param_1[0x19f] & 8) != 0) {
    fVar7 = SQRT(fVar15 * fVar15 + fVar14 * fVar14 + fVar8 * fVar8);
    *in_stack_00000030 = fVar8;
    in_stack_00000030[1] = fVar14;
    in_stack_00000030[2] = fVar15;
    in_stack_00000030[3] = 0.0;
    if (fVar7 != fVar19) {
      fVar11 = fVar11 / fVar7;
      auVar13 = ZEXT464((uint)(fVar8 * fVar11));
      auVar18 = ZEXT464((uint)(fVar14 * fVar11));
      auVar17 = ZEXT464((uint)(fVar15 * fVar11));
    }
    iVar5 = FUN_140242630();
    fVar7 = 0.0;
    fVar15 = (float)(iVar5 % 10000) * DAT_1402d1f98;
    fVar8 = auVar13._0_4_ * fVar15;
    fVar14 = auVar18._0_4_ * fVar15;
    fVar15 = auVar17._0_4_ * fVar15;
  }
  in_stack_00000030[0xd] = fVar14 + (float)local_d8._4_4_;
  in_stack_00000030[0xe] = fVar15 + fStack_d0;
  in_stack_00000030[0xf] = fVar7 + fStack_cc;
  in_stack_00000030[0xc] = fVar8 + (float)local_d8._0_4_;
  param_1[4] = fVar8 + (float)local_d8._0_4_;
  param_1[5] = in_stack_00000030[0xd];
  param_1[6] = in_stack_00000030[0xe];
  param_1[7] = in_stack_00000030[0xf];
  fVar8 = *(float *)(lVar1 + 600);
  in_stack_00000030[8] = fVar8;
  in_stack_00000030[9] = *(float *)(lVar1 + 0x25c);
  in_stack_00000030[10] = *(float *)(lVar1 + 0x260);
  in_stack_00000030[0xb] = *(float *)(lVar1 + 0x264);
  *param_1 = fVar8;
  param_1[1] = in_stack_00000030[9];
  param_1[2] = in_stack_00000030[10];
  param_1[3] = in_stack_00000030[0xb];
  if (((uint)param_1[0x19f] & 0x18) == 0) {
    _local_d8 = ZEXT832(0);
    FUN_1401b71e0();
    fVar7 = DAT_1402d2520;
    fVar8 = *(float *)(lVar1 + 0x25c);
    fVar11 = *(float *)(lVar1 + 0x260);
    in_stack_00000030[4] = (float)local_d8._0_4_ - *(float *)(lVar1 + 600);
    in_stack_00000030[6] = fStack_d0 - fVar11;
    in_stack_00000030[5] = (float)local_d8._4_4_ - fVar8;
    in_stack_00000030[7] = 0.0;
    fVar7 = fVar7 / (float)DAT_14033d9d1;
    auVar6._0_4_ = fVar7 * in_stack_00000030[4];
    auVar6._4_4_ = fVar7 * in_stack_00000030[5];
    auVar6._8_4_ = fVar7 * in_stack_00000030[6];
    auVar6._12_4_ = fVar7 * in_stack_00000030[7];
    *(undefined1 (*) [16])(in_stack_00000030 + 4) = auVar6;
  }
  FUN_1401b4a20(param_1,param_1 + 4,DAT_1402d2968,1);
  return 1;
}

