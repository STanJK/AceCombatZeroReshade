/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b1860; RVA 0x1b1860
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1401b1860(undefined8 param_1,float *param_2)

{
  float fVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  uint uVar6;
  undefined1 extraout_var [56];
  float fVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [64];
  float fVar10;
  float fVar11;
  float fVar12;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  undefined1 local_d8 [8];
  float fStack_d0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [16];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  
  _local_d8 = ZEXT832(0);
  FUN_1401b71e0(*(longlong *)(DAT_14033d9d8 + 0x697b8),local_d8,
                *(undefined8 *)
                 (*(longlong *)
                   (*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) + 0x110))
  ;
  local_98 = ZEXT816(0);
  fVar11 = 0.0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_e8 = 0.0;
  local_78 = local_98;
  iVar5 = FUN_140242630();
  local_e4 = (float)(iVar5 % 10000) * DAT_1402d1e18;
  local_e0 = fVar11;
  local_dc = fVar11;
  FUN_140202920(&local_a8,&local_e8);
  fVar12 = DAT_1402d2aa4;
  auVar3._8_8_ = uStack_80;
  auVar3._0_8_ = local_88;
  fVar10 = (float)local_88 * DAT_1402d2aa4 + local_78._0_4_ + (float)local_d8._0_4_;
  auVar8 = vshufps_avx(local_78,local_78,0xaa);
  auVar2 = vshufps_avx(auVar3,auVar3,0xaa);
  fVar1 = auVar2._0_4_ * DAT_1402d2aa4 + auVar8._0_4_ + fStack_d0;
  auVar8 = vshufps_avx(local_78,local_78,0x55);
  auVar2 = vshufps_avx(auVar3,auVar3,0x55);
  fVar7 = auVar2._0_4_ * DAT_1402d2aa4 + auVar8._0_4_ + (float)local_d8._4_4_ + DAT_1402d2aa4;
  param_2[1] = fVar7;
  *param_2 = fVar10;
  param_2[2] = fVar1;
  param_2[3] = 1.0;
  param_2[7] = 0.0;
  auVar8._4_12_ = SUB1612(*(undefined1 (*) [16])(param_2 + 4),4);
  auVar8._0_4_ = local_d8._0_4_;
  auVar8 = vinsertps_avx(auVar8,ZEXT416((uint)local_d8._4_4_),0x10);
  auVar8 = vinsertps_avx(auVar8,ZEXT416((uint)fStack_d0),0x20);
  auVar2 = vshufps_avx(auVar8,auVar8,0x55);
  fVar10 = auVar8._0_4_ - fVar10;
  fVar7 = auVar2._0_4_ - fVar7;
  *(undefined1 (*) [16])(param_2 + 4) = auVar8;
  auVar8 = vshufps_avx(auVar8,auVar8,0xaa);
  fVar1 = auVar8._0_4_ - fVar1;
  fVar7 = SQRT(fVar1 * fVar1 + fVar7 * fVar7 + fVar10 * fVar10);
  if (fVar7 != fVar11) {
    fVar7 = DAT_1402d22d0 / fVar7;
    fVar10 = fVar10 * fVar7;
    fVar1 = fVar1 * fVar7;
  }
  fVar7 = (float)local_d8._4_4_;
  auVar9._0_8_ = FUN_140272370(CONCAT44(_UNK_1402d3774,(uint)fVar10 ^ DAT_1402d3770),
                               CONCAT44(_UNK_1402d3774,(uint)fVar1 ^ DAT_1402d3770));
  auVar9._8_56_ = extraout_var;
  auVar9 = ZEXT1664(auVar9._0_16_);
  iVar5 = FUN_140242630();
  auVar8 = vcmpss_avx(ZEXT416((uint)DAT_1402d2420),auVar9._0_16_,1);
  auVar8 = vblendvps_avx(ZEXT416((uint)(auVar9._0_4_ + DAT_1402d2420)),
                         ZEXT416((uint)(auVar9._0_4_ - DAT_1402d2420)),auVar8);
  auVar9 = ZEXT1664(auVar8);
  fVar10 = (float)(iVar5 % 10000) * DAT_1402d1d88 + DAT_1402d2054;
  uVar6 = FUN_140242630();
  uVar6 = uVar6 & 0x80000001;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
  }
  fVar10 = (float)(int)(uVar6 * 2 + -1) * fVar10 + auVar9._0_4_;
  auVar2._4_12_ = auVar9._4_12_;
  auVar2._0_4_ = fVar10;
  auVar8 = vcmpss_avx(ZEXT416((uint)DAT_1402d249c),auVar2,1);
  auVar8 = vblendvps_avx(auVar2,ZEXT416((uint)(fVar10 - DAT_1402d249c)),auVar8);
  local_e4 = auVar8._0_4_;
  local_e8 = fVar11;
  local_e0 = fVar11;
  local_dc = fVar11;
  FUN_140202920(&local_a8,&local_e8);
  fVar7 = fVar7 + DAT_1402d2a7c;
  auVar4._8_8_ = uStack_80;
  auVar4._0_8_ = local_88;
  param_2[0xb] = 0.0;
  param_2[8] = (float)local_88 * fVar12 + local_78._0_4_ + *param_2;
  param_2[9] = fVar7;
  auVar8 = vshufps_avx(local_78,local_78,0xaa);
  auVar2 = vshufps_avx(auVar4,auVar4,0xaa);
  param_2[10] = auVar2._0_4_ * fVar12 + auVar8._0_4_ + param_2[2];
  return 1;
}

