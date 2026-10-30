/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401adc40; RVA 0x1adc40
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1401adc40(undefined4 *param_1)

{
  float *pfVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  float fVar12;
  undefined1 auVar13 [16];
  float fVar14;
  ulonglong uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined1 auVar19 [64];
  undefined1 auVar20 [64];
  float fVar21;
  undefined1 auVar22 [64];
  float fVar23;
  float fVar24;
  undefined1 auVar25 [16];
  undefined4 *in_stack_ffffffffffffff10;
  undefined1 uVar26;
  undefined1 local_b0 [8];
  float fStack_a8;
  
  fVar12 = DAT_1402d22d0;
  auVar25._12_4_ = 0;
  auVar25._0_12_ = ZEXT812(0);
  auVar25 = auVar25 << 0x20;
  uVar2 = *(undefined8 *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  if ((param_1[0x19f] & 1) != 0) {
    param_1[0x19f] = param_1[0x19f] & 0xffffff1e;
    _local_b0 = ZEXT832(0);
    auVar19 = ZEXT1264(ZEXT812(0)) << 0x20;
    FUN_1401b71e0(param_1,local_b0,uVar2);
    in_stack_ffffffffffffff10 = param_1 + 0x146;
    param_1[0x182] = 0xffffffff;
    param_1[0x170] = 0;
    FUN_1401ac760(param_1);
    auVar25 = auVar19._0_16_;
    if ((*(byte *)(param_1 + 0x19f) & 8) == 0) {
      _local_b0 = ZEXT832(0);
      auVar19 = ZEXT1664(auVar25);
      fVar16 = DAT_1402d2440;
      FUN_1401b71e0();
      auVar13._0_4_ = (float)DAT_14033d9d1;
      auVar13._4_12_ = SUB1612(ZEXT816(0),4);
      fVar17 = DAT_1402d2474;
      FUN_1401b71e0(auVar13._0_8_,local_b0,uVar2,auVar13._0_4_ * DAT_1402d2474);
      if ((*(byte *)(param_1 + 0x19f) & 0x10) == 0) {
        auVar25 = *(undefined1 (*) [16])(param_1 + 4);
        auVar13 = *(undefined1 (*) [16])(param_1 + 0x14a);
        auVar4 = vshufps_avx(auVar13,auVar13,0x55);
        fVar21 = auVar13._0_4_ * fVar16 + auVar25._0_4_;
        auVar5 = vshufps_avx(auVar13,auVar13,0xaa);
        auVar6 = vshufps_avx(auVar25,auVar25,0x55);
        auVar7 = vshufps_avx(auVar25,auVar25,0xaa);
        fVar24 = auVar5._0_4_ * fVar16 + auVar7._0_4_;
        auVar5 = vshufps_avx(auVar25,auVar25,0x55);
        fVar23 = auVar4._0_4_ * fVar16 + auVar6._0_4_;
        auVar4 = vshufps_avx(auVar13,auVar13,0x55);
        fVar16 = auVar13._0_4_ * fVar17 + auVar25._0_4_;
        auVar25 = vshufps_avx(auVar25,auVar25,0xaa);
        auVar13 = vshufps_avx(auVar13,auVar13,0xaa);
        fVar18 = auVar13._0_4_ * fVar17 + auVar25._0_4_;
        fVar17 = auVar4._0_4_ * fVar17 + auVar5._0_4_;
      }
      else {
        fVar16 = (float)param_1[4];
        fVar17 = (float)param_1[5];
        fVar18 = (float)param_1[6];
        fVar21 = fVar16;
        fVar23 = fVar17;
        fVar24 = fVar18;
      }
      fVar21 = 0.0 - fVar21;
      fVar24 = 0.0 - fVar24;
      fVar23 = 0.0 - fVar23;
      fVar17 = (float)local_b0._4_4_ - fVar17;
      fVar16 = (float)local_b0._0_4_ - fVar16;
      fVar18 = fStack_a8 - fVar18;
      fVar14 = SQRT(fVar24 * fVar24 + fVar21 * fVar21 + fVar23 * fVar23);
      if (fVar14 != auVar19._0_4_) {
        fVar14 = fVar12 / fVar14;
        fVar21 = fVar14 * fVar21;
        fVar23 = fVar14 * fVar23;
        fVar24 = fVar14 * fVar24;
      }
      fVar14 = SQRT(fVar18 * fVar18 + fVar16 * fVar16 + fVar17 * fVar17);
      if (fVar14 != auVar19._0_4_) {
        fVar14 = fVar12 / fVar14;
        fVar16 = fVar14 * fVar16;
        fVar17 = fVar14 * fVar17;
        fVar18 = fVar14 * fVar18;
      }
      bVar3 = DAT_1402d229c < fVar24 * fVar18 + fVar21 * fVar16 + fVar23 * fVar17;
      iVar9 = FUN_140242630();
      auVar25 = vpcmpeqd_avx(ZEXT116(bVar3),SUB6416(ZEXT464(1),0));
      auVar25 = vblendvps_avx(ZEXT416(DAT_1402d1d70),ZEXT416(DAT_1402d1d58),auVar25);
      param_1[10] = (float)(iVar9 % 0x4e21 + -10000) * auVar25._0_4_;
      iVar9 = FUN_140242630();
      auVar25 = auVar19._0_16_;
      auVar13 = vpcmpeqd_avx(ZEXT116(bVar3),SUB6416(ZEXT464(1),0));
      auVar13 = vblendvps_avx(ZEXT416((uint)(DAT_1402d1d40 / (float)DAT_14033d9d1)),
                              ZEXT416((uint)(DAT_1402d1d30 / (float)DAT_14033d9d1)),auVar13);
      fVar16 = auVar13._0_4_ * (float)(iVar9 % 0x2711);
      param_1[0x173] = fVar16;
      if (auVar19._0_4_ < (float)param_1[10]) {
        fVar16 = (float)((uint)fVar16 ^ DAT_1402d3770);
        param_1[0x173] = fVar16;
      }
      if (!bVar3) {
        param_1[0x173] = -((DAT_1402d2080 / (float)DAT_14033d9d1) * (float)param_1[10]) + fVar16;
      }
    }
  }
  fVar18 = DAT_1402d20f0;
  auVar19 = ZEXT1664(*(undefined1 (*) [16])(param_1 + 8));
  param_1[0x10c] = param_1[0x108];
  fVar16 = *(float *)(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1a0) + 0x1c);
  fVar17 = *(float *)(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1a0) + 0x18);
  fVar21 = fVar17 - fVar16;
  auVar13 = ZEXT416((uint)(fVar16 - fVar17));
  auVar25 = vcmpss_avx(auVar13,auVar25,1);
  param_1[0x145] = 0;
  auVar25 = vblendvps_avx(auVar13,ZEXT416((uint)fVar21),auVar25);
  uVar15 = auVar25._0_8_;
  auVar22 = ZEXT464((uint)(auVar25._0_4_ * fVar18));
  if ((param_1[0x19f] & 0xe0) == 0) {
    if ((param_1[0x182] == -1) && (0 < (int)_DAT_14033d9b4)) {
      piVar10 = &DAT_14033bdb0;
      iVar9 = 0;
      do {
        if (((-1 < *piVar10) && (*(char *)((longlong)piVar10 + 0x13) == '\0')) &&
           ((char)piVar10[5] == '\0')) {
          uVar2 = *(undefined8 *)(piVar10 + 2);
          *(undefined8 *)(param_1 + 0x182) = *(undefined8 *)piVar10;
          *(undefined8 *)(param_1 + 0x184) = uVar2;
          *(undefined8 *)(param_1 + 0x186) = *(undefined8 *)(piVar10 + 4);
          fVar18 = (float)DAT_14033d9d1 * fVar18;
          uVar15 = (ulonglong)(uint)fVar18;
          param_1[0x170] = (int)(longlong)fVar18;
          param_1[0x19f] = param_1[0x19f] & 0xfffffdff | 0x20;
          param_1[0x145] = 1;
          param_1[0x12e] = *param_1;
          param_1[0x12f] = param_1[1];
          param_1[0x130] = param_1[2];
          param_1[0x131] = param_1[3];
          param_1[0x142] = 0;
          param_1[0x13e] = param_1[0x14a];
          param_1[0x13f] = param_1[0x14b];
          param_1[0x140] = param_1[0x14c];
          param_1[0x141] = param_1[0x14d];
          break;
        }
        piVar10 = piVar10 + 6;
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)_DAT_14033d9b4);
    }
    if ((-1 < (int)param_1[0x182]) && (*(char *)(param_1 + 0x186) != '\0')) {
      param_1[0x19f] = param_1[0x19f] & 0xffffffdf;
      param_1[0x182] = 0xffffffff;
      param_1[0x145] = 0;
    }
  }
  uVar11 = param_1[0x19f];
  if (((uVar11 & 0x20) != 0) && (param_1[0x170] == 0)) {
    param_1[0x19f] = uVar11 & 0xffffffdf | 0x40;
    uVar11 = uVar11 & 0xffffffdf | 0x440;
    uVar15 = (ulonglong)(uint)((float)DAT_14033d9d1 * DAT_1402d236c);
    param_1[0x170] = (int)(longlong)((float)DAT_14033d9d1 * DAT_1402d236c);
    param_1[0x19f] = uVar11;
  }
  uVar8 = DAT_1402d2968;
  auVar20 = ZEXT464(DAT_1402d2968);
  if ((uVar11 & 0xc0) == 0) {
    FUN_1401accb0(param_1,uVar15,fVar21,param_1 + 0x146);
  }
  else {
    pfVar1 = (float *)(param_1 + 4);
    *pfVar1 = *pfVar1 + (float)param_1[0x13e];
    param_1[5] = (float)param_1[0x13f] + (float)param_1[5];
    param_1[6] = (float)param_1[0x140] + (float)param_1[6];
    param_1[7] = (float)param_1[0x141] + (float)param_1[7];
    param_1[0x142] = param_1[0x142] + 1;
    FUN_1401b4a20(param_1,pfVar1,uVar8,1);
  }
  if ((*(byte *)(param_1 + 0x19f) & 0xc0) == 0) {
    FUN_1401ad010(param_1);
    auVar25 = auVar19._0_16_;
    *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2058) =
         *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2058) | 0x100000;
  }
  else {
    uVar26 = 1;
    uVar15 = (ulonglong)in_stack_ffffffffffffff10 & 0xffffffff00000000;
    FUN_1401ad010(param_1);
    FUN_1401ad2a0(param_1,DAT_1402d236c,auVar22._0_8_,auVar20._0_8_,param_1 + 0x12e,uVar15,uVar26);
    auVar25 = auVar19._0_16_;
    *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2058) =
         *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2058) & 0xffefffff;
  }
  if (param_1[0x170] != 0) {
    param_1[0x170] = param_1[0x170] + -1;
  }
  if ((*(byte *)(param_1 + 0x19f) & 8) == 0) {
    auVar13 = vshufps_avx(auVar25,auVar25,0x55);
    fVar16 = (float)param_1[9] - auVar13._0_4_;
    fVar17 = DAT_1402d2054 / (float)DAT_14033d9d1;
    if (((float)((uint)fVar17 ^ DAT_1402d3770) <= fVar16) && (fVar16 <= fVar17)) {
      fVar12 = (float)((uint)(fVar16 / fVar17) & _DAT_1402d3760);
      fVar12 = fVar12 * fVar12;
    }
    auVar25 = vshufps_avx(auVar25,auVar25,0xaa);
    fVar12 = fVar12 * (float)param_1[0x173] + auVar25._0_4_;
    bVar3 = DAT_1402d2d20 <= fVar12;
    param_1[10] = fVar12;
    if (bVar3) {
      if (DAT_1402d210c < fVar12) {
        param_1[10] = 0x3eb2b8c3;
      }
    }
    else {
      param_1[10] = 0xbeb2b8c3;
    }
  }
  FUN_1401b5120(param_1,param_1 + 4,param_1 + 8);
  if (((uint)DAT_14033d9d1 * 5 < (uint)(param_1[0x198] - param_1[0x199])) &&
     ((*(byte *)(param_1 + 0x19f) & 0xe0) == 0)) {
    return true;
  }
  return *(char *)(param_1 + 0x1a3) == '\x01';
}

