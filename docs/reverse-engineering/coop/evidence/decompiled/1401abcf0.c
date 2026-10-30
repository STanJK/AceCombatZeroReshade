/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401abcf0; RVA 0x1abcf0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1401abcf0(undefined1 (*param_1) [16])

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  float fVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  undefined4 uVar19;
  longlong lVar20;
  int iVar21;
  ulonglong uVar22;
  float *pfVar23;
  longlong lVar24;
  longlong *plVar25;
  undefined1 (*pauVar26) [16];
  int *piVar27;
  ulonglong extraout_XMM0_Qa;
  undefined8 uVar28;
  undefined1 auVar29 [16];
  uint uVar30;
  uint uVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  longlong local_res10;
  undefined1 local_138 [8];
  float fStack_130;
  float fStack_12c;
  undefined1 local_128 [16];
  undefined1 local_118 [8];
  float fStack_110;
  float fStack_10c;
  undefined1 local_108 [8];
  float fStack_100;
  undefined1 local_f8 [8];
  float fStack_f0;
  float fStack_ec;
  
  lVar20 = DAT_14033d9d8;
  lVar24 = *(longlong *)(DAT_14033d9d8 + 0x697b8);
  lVar5 = *(longlong *)(*(longlong *)(lVar24 + (ulonglong)DAT_14033d9d2 * 8) + 0x110);
  bVar2 = *(byte *)(lVar5 + 0x237);
  bVar3 = *(byte *)(lVar5 + 0x236);
  uVar22 = (ulonglong)(bVar2 != 0xff);
  if (bVar3 == 0xff || bVar2 == 0xff) {
    local_res10 = 0;
  }
  else {
    uVar22 = *(ulonglong *)(lVar24 + (ulonglong)bVar3 * 8);
    local_res10 = (ulonglong)bVar2 * 0x520 + *(longlong *)(uVar22 + 0x110);
  }
  plVar25 = (longlong *)0x0;
  if (bVar3 != 0xff) {
    plVar25 = (longlong *)(lVar24 + (ulonglong)bVar3 * 8);
  }
  uVar30 = *(uint *)(param_1[0x67] + 0xc);
  if ((uVar30 & 1) != 0) {
    *(uint *)(param_1[0x67] + 0xc) = uVar30 & 0xfffffffe;
    if ((uVar30 >> 0x10 & 1) == 0) {
      FUN_1401b41c0(uVar22,param_1 + 5,DAT_1402d2784);
      auVar29 = *(undefined1 (*) [16])(lVar5 + 600);
      auVar10 = vshufps_avx(auVar29,auVar29,0x55);
      auVar11 = vshufps_avx(auVar29,auVar29,0xaa);
      local_138._4_4_ = auVar10._0_4_ + *(float *)(param_1[5] + 4);
      local_138._0_4_ = auVar29._0_4_ + *(float *)param_1[5];
      auVar29 = vshufps_avx(auVar29,auVar29,0xff);
      fStack_130 = auVar11._0_4_ + *(float *)(param_1[5] + 8);
      fStack_12c = auVar29._0_4_ + *(float *)(param_1[5] + 0xc);
      iVar21 = FUN_1401b43a0(param_1,local_138,lVar5 + 600);
      uVar30 = DAT_1402d3770;
      if (iVar21 == 1) {
        uVar31 = *(uint *)(param_1[5] + 4) ^ DAT_1402d3770;
        *(uint *)param_1[5] = *(uint *)param_1[5] ^ DAT_1402d3770;
        *(uint *)(param_1[5] + 8) = *(uint *)(param_1[5] + 8) ^ uVar30;
        *(uint *)(param_1[5] + 4) = uVar31;
        *(undefined4 *)(param_1[5] + 0xc) = 0;
      }
    }
    else {
      auVar29 = *(undefined1 (*) [16])(lVar5 + 600);
      auVar10 = vshufps_avx(auVar29,auVar29,0x55);
      fVar34 = *(float *)(param_1[0x65] + 4);
      auVar11 = vshufps_avx(auVar29,auVar29,0xaa);
      fVar33 = *(float *)(param_1[0x65] + 8);
      *(float *)param_1[5] = auVar29._0_4_ - *(float *)param_1[0x65];
      *(float *)(param_1[5] + 4) = auVar10._0_4_ - fVar34;
      *(float *)(param_1[5] + 8) = auVar11._0_4_ - fVar33;
      *(undefined4 *)(param_1[5] + 0xc) = 0;
      FUN_1400141a0(param_1 + 5);
      auVar29._0_4_ = _DAT_1402d36f0 * *(float *)param_1[5];
      auVar29._4_4_ = _UNK_1402d36f4 * *(float *)(param_1[5] + 4);
      auVar29._8_4_ = _UNK_1402d36f8 * *(float *)(param_1[5] + 8);
      auVar29._12_4_ = _UNK_1402d36fc * *(float *)(param_1[5] + 0xc);
      param_1[5] = auVar29;
      *(undefined4 *)(param_1[5] + 0xc) = 0x3f800000;
      uVar22 = FUN_140242630();
      if ((uVar22 & 1) == 0) {
        uVar31 = *(uint *)(param_1[5] + 8) ^ DAT_1402d3770;
        uVar30 = *(uint *)(param_1[5] + 4) ^ DAT_1402d3770;
        *(uint *)param_1[5] = *(uint *)param_1[5] ^ DAT_1402d3770;
        *(uint *)(param_1[5] + 4) = uVar30;
        *(uint *)(param_1[5] + 8) = uVar31;
        *(undefined4 *)(param_1[5] + 0xc) = 0x3f800000;
      }
    }
    param_1[0x68][0xb] = 0;
    *(undefined4 *)(param_1[0x5b] + 0xc) = *(undefined4 *)param_1[0x66];
  }
  bVar18 = false;
  if (param_1[0x68][0xb] == '\0') {
    if ((local_res10 != 0) && (plVar25 != (longlong *)0x0)) {
      if (((*(byte *)(local_res10 + 0x1f0) & 8) == 0) || ((*(byte *)(*plVar25 + 0x120) & 4) == 0)) {
        bVar16 = false;
      }
      else {
        bVar16 = true;
      }
      if ((*(char *)(**(longlong **)(lVar5 + 0x1a0) + 0x71) == '\x03') ||
         ((*(uint *)(lVar5 + 0x1f0) & 0x10000) != 0)) {
        bVar17 = false;
      }
      else {
        bVar17 = true;
      }
      if (((bVar16) && (bVar17)) && (*(char *)(lVar5 + 0x236) != '\0')) {
        *(undefined4 *)(param_1[0x5b] + 0xc) = *(undefined4 *)param_1[0x66];
      }
    }
    if ((((uint)DAT_14033d9d1 * 3 <= (uint)(*(int *)param_1[0x66] - *(int *)(param_1[0x5b] + 0xc)))
        && ((*(uint *)(param_1[0x67] + 0xc) & 2) == 0)) &&
       ((*(uint *)(param_1[0x67] + 0xc) >> 0x10 & 1) == 0)) {
      FUN_140242630();
      lVar24 = *(longlong *)(*(longlong *)(lVar20 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8);
      iVar21 = *(int *)(lVar24 + 0x118);
      if (1 < iVar21) {
        pfVar23 = (float *)(*(longlong *)(lVar24 + 0x110) + 0x778);
        lVar24 = 1;
        do {
          if (((uint)pfVar23[-0x1a] & 1) != 0) {
            auVar29 = *(undefined1 (*) [16])(*(longlong *)param_1[0x6a] + 0x70);
            fVar34 = auVar29._0_4_ - *pfVar23;
            auVar10 = vshufps_avx(auVar29,auVar29,0x55);
            fVar33 = auVar10._0_4_ - pfVar23[1];
            auVar29 = vshufps_avx(auVar29,auVar29,0xaa);
            fVar15 = auVar29._0_4_ - pfVar23[2];
            if (SQRT(fVar15 * fVar15 + fVar33 * fVar33 + fVar34 * fVar34) < DAT_1402d28f4)
            goto LAB_1401ac108;
          }
          lVar24 = lVar24 + 1;
          pfVar23 = pfVar23 + 0x148;
        } while (lVar24 < iVar21);
      }
      *(undefined4 *)(param_1[0x5b] + 0xc) = *(undefined4 *)param_1[0x66];
      param_1[0x68][0xb] = 1;
      uVar31 = FUN_140242630();
      uVar30 = DAT_1402d22d0;
      *(uint *)(param_1[0x67] + 0xc) = *(uint *)(param_1[0x67] + 0xc) | 0x402;
      auVar29 = vpcmpeqd_avx(ZEXT416(uVar31 & 1),SUB6416(ZEXT464(0),0));
      auVar29 = vblendvps_avx(ZEXT416(DAT_1402d2d64),ZEXT416(uVar30),auVar29);
      *(int *)(param_1[0x5c] + 8) = auVar29._0_4_;
    }
  }
LAB_1401ac108:
  piVar27 = (int *)(param_1[0x5b] + 0xc);
  if (param_1[0x68][0xb] == '\0') {
    auVar29 = *(undefined1 (*) [16])(lVar5 + 600);
    auVar10 = vshufps_avx(auVar29,auVar29,0x55);
    fVar34 = *(float *)(param_1[5] + 4);
    auVar11 = vshufps_avx(auVar29,auVar29,0xaa);
    fVar33 = *(float *)(param_1[5] + 8);
    auVar12 = vshufps_avx(auVar29,auVar29,0xff);
    fVar15 = *(float *)(param_1[5] + 0xc);
    *(float *)param_1[1] = auVar29._0_4_ + *(float *)param_1[5];
    *(float *)(param_1[1] + 0xc) = auVar12._0_4_ + fVar15;
    *(float *)(param_1[1] + 4) = auVar10._0_4_ + fVar34;
    *(float *)(param_1[1] + 8) = auVar11._0_4_ + fVar33;
    local_128 = ZEXT816(0);
    lVar24 = *(longlong *)(*(longlong *)param_1[0x6a] + 0x1a0);
    _local_118 = ZEXT816(0);
    _local_108 = ZEXT816(0);
    _local_f8 = ZEXT816(0);
    fVar34 = *(float *)(lVar24 + 0x18);
    fVar33 = *(float *)(lVar24 + 0x1c);
    FUN_140202920(local_128,lVar5 + 0x268);
    fVar15 = (fVar33 + fVar34) * DAT_1402d2168;
    fVar34 = *(float *)(lVar5 + 0x25c);
    fVar33 = *(float *)(lVar5 + 0x260);
    *(float *)*param_1 = fVar15 * local_108._0_4_ + (float)local_f8._0_4_ + *(float *)(lVar5 + 600);
    auVar29 = vshufps_avx(_local_108,_local_108,0xff);
    *(float *)(*param_1 + 0xc) = fVar15 * auVar29._0_4_ + fStack_ec;
    *(float *)(*param_1 + 4) = fVar15 * (float)local_108._4_4_ + (float)local_f8._4_4_ + fVar34;
    *(float *)(*param_1 + 8) = fVar15 * fStack_100 + fStack_f0 + fVar33;
    iVar21 = FUN_1401b43a0(param_1,param_1 + 1,param_1);
    uVar22 = extraout_XMM0_Qa;
    if (iVar21 == 1) {
      auVar29 = param_1[1];
      fVar34 = auVar29._0_4_ - *(float *)*param_1;
      auVar10 = vshufps_avx(auVar29,auVar29,0x55);
      fVar33 = auVar10._0_4_ - *(float *)(*param_1 + 4);
      auVar29 = vshufps_avx(auVar29,auVar29,0xaa);
      fVar15 = auVar29._0_4_ - *(float *)(*param_1 + 8);
      uVar22 = (ulonglong)(uint)fVar15;
      if (fVar15 * fVar15 + fVar33 * fVar33 + fVar34 * fVar34 < DAT_1402d2c18) {
        bVar18 = true;
      }
    }
    FUN_1401b4110(uVar22,param_1 + 2,param_1 + 1,param_1);
    uVar28 = FUN_1401aa420(param_1,DAT_1402d1f84,0x14);
    FUN_1401aa540(uVar28,local_138);
    FUN_140203050(param_1 + 2,local_138,param_1 + 2);
    auVar29 = vpcmpeqd_avx(ZEXT416(*(uint *)(*(longlong *)(param_1[0x6b] + 8) + 0xa8790) & 0x10),
                           SUB6416(ZEXT464(0),0));
    auVar29 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar29);
    *(int *)param_1[0x43] = auVar29._0_4_;
  }
  else if (param_1[0x68][0xb] == '\x01') {
    _local_118 = ZEXT816(0);
    local_128 = ZEXT816(0);
    fStack_12c = SUB164(*(undefined1 (*) [16])(lVar5 + 0x268),0xc);
    local_138 = SUB168(*(undefined1 (*) [16])(lVar5 + 0x268),0);
    fStack_130 = 0.0;
    _local_108 = local_128;
    _local_f8 = _local_118;
    FUN_140202920(local_128,local_138);
    fVar6 = (float)local_f8._0_4_ + *(float *)(lVar5 + 600);
    lVar24 = *(longlong *)(*(longlong *)param_1[0x6a] + 0x1a0);
    iVar21 = *(int *)param_1[0x66];
    iVar4 = *piVar27;
    fVar7 = (float)local_f8._4_4_ + *(float *)(lVar5 + 0x25c);
    fVar8 = fStack_f0 + *(float *)(lVar5 + 0x260);
    uVar30 = (uint)DAT_14033d9d1;
    fVar34 = *(float *)(lVar24 + 0x1c);
    fVar33 = *(float *)(lVar24 + 0x18);
    fVar15 = *(float *)(lVar24 + 0x18);
    *(undefined8 *)*param_1 = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0x3f800000;
    fVar1 = DAT_1402d28c8;
    auVar29 = vinsertps_avx(*param_1,ZEXT416((uint)((fVar34 - fVar33) *
                                                    ((float)(uint)(iVar21 - iVar4) /
                                                    (float)(uVar30 << 2)) + fVar15)),0x20);
    *param_1 = auVar29;
    auVar10 = vshufps_avx(auVar29,auVar29,0xaa);
    auVar11 = vshufps_avx(auVar29,auVar29,0x55);
    fVar9 = auVar11._0_4_ + DAT_1402d2524;
    fVar35 = fVar1 * *(float *)(param_1[0x5c] + 8) + auVar29._0_4_;
    _local_138 = vshufps_avx(auVar29,auVar29,0xff);
    auVar29 = vshufps_avx(local_128,local_128,0x55);
    auVar11 = vshufps_avx(_local_108,_local_108,0x55);
    fVar32 = auVar10._0_4_;
    fVar36 = local_138._0_4_;
    auVar10 = vshufps_avx(local_128,local_128,0xaa);
    auVar12 = vshufps_avx(_local_108,_local_108,0xaa);
    auVar13 = vshufps_avx(local_128,local_128,0xff);
    *(float *)param_1[1] =
         fVar6 * fVar36 +
         fVar32 * local_108._0_4_ + fVar35 * local_128._0_4_ + fVar9 * (float)local_118._0_4_;
    *(float *)(param_1[1] + 4) =
         fVar7 * fVar36 +
         fVar32 * auVar11._0_4_ + fVar35 * auVar29._0_4_ + fVar9 * (float)local_118._4_4_;
    *(float *)(param_1[1] + 8) =
         fVar36 * fVar8 + fVar32 * auVar12._0_4_ + fVar35 * auVar10._0_4_ + fVar9 * fStack_110;
    fVar34 = *(float *)(*param_1 + 4);
    auVar14 = vshufps_avx(_local_108,_local_108,0xff);
    fVar33 = *(float *)(*param_1 + 0xc);
    fVar15 = *(float *)(*param_1 + 8);
    fVar1 = *(float *)*param_1;
    *(float *)(param_1[1] + 0xc) =
         fVar35 * auVar13._0_4_ + fVar9 * fStack_10c + fVar36 * fStack_ec + auVar14._0_4_ * fVar32;
    *(float *)*param_1 =
         fVar33 * fVar6 +
         fVar15 * local_108._0_4_ + local_128._0_4_ * fVar1 + fVar34 * (float)local_118._0_4_;
    *(float *)(*param_1 + 8) =
         fVar33 * fVar8 + fVar15 * auVar12._0_4_ + auVar10._0_4_ * fVar1 + fVar34 * fStack_110;
    *(float *)(*param_1 + 4) =
         fVar33 * fVar7 +
         fVar15 * auVar11._0_4_ + auVar29._0_4_ * fVar1 + fVar34 * (float)local_118._4_4_;
    uVar19 = DAT_1402d273c;
    *(float *)(*param_1 + 0xc) =
         auVar13._0_4_ * fVar1 + fVar34 * fStack_10c + fVar15 * auVar14._0_4_ + fVar33 * fStack_ec;
    uVar28 = FUN_1401b4a20(param_1,param_1 + 1,uVar19,0);
    FUN_1401b4110(uVar28,param_1 + 2,param_1 + 1,param_1);
    uVar28 = FUN_1401aa420(param_1,DAT_1402d1e58,10);
    FUN_1401aa540(uVar28,local_138);
    FUN_140203050(param_1 + 2,local_138,param_1 + 2);
    iVar21 = *(int *)param_1[0x66];
    iVar4 = *piVar27;
    *(undefined4 *)param_1[0x43] = 0x457a0000;
    if (((uint)DAT_14033d9d1 << 2 <= (uint)(iVar21 - iVar4)) ||
       ((*(uint *)(param_1[0x67] + 0xc) & 0x10000) != 0)) {
      *(uint *)(param_1[0x67] + 0xc) = *(uint *)(param_1[0x67] + 0xc) | 0x401;
      *(int *)(param_1[0x66] + 4) = iVar21 + 1;
      param_1[0x68][0xb] = 0;
      *piVar27 = iVar21;
    }
  }
  pauVar26 = param_1 + 0x66;
  FUN_1401b52f0(param_1,param_1 + 1,lVar5 + 600,param_1 + 2);
  if ((((uint)DAT_14033d9d1 * 5 < (uint)(*(int *)*pauVar26 - *(int *)(param_1[0x66] + 4))) &&
      (param_1[0x68][0xb] == '\0')) || (bVar18)) {
    return true;
  }
  return param_1[0x68][0xc] == '\x01';
}

