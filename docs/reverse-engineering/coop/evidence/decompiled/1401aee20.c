/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401aee20; RVA 0x1aee20
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1401aee20(undefined1 (*param_1) [16],int param_2)

{
  undefined1 (*pauVar1) [16];
  undefined4 *puVar2;
  uint *puVar3;
  longlong *plVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  longlong lVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar11;
  float fVar12;
  undefined1 auVar13 [16];
  bool bVar14;
  float fVar15;
  uint uVar16;
  int iVar17;
  undefined4 uVar18;
  undefined8 *puVar19;
  ulonglong uVar20;
  undefined1 (*pauVar21) [16];
  longlong lVar22;
  char cVar23;
  longlong lVar24;
  longlong lVar25;
  undefined8 uVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined1 auVar32 [16];
  undefined1 auVar33 [64];
  uint uVar34;
  float fVar35;
  undefined1 auVar36 [16];
  undefined1 auVar37 [64];
  float fVar38;
  undefined1 auVar39 [64];
  float fVar40;
  float fVar41;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined1 auStack_178 [8];
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined1 local_158 [8];
  float fStack_150;
  float fStack_14c;
  undefined8 local_148;
  float local_140;
  float local_13c;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  float local_108;
  float local_104;
  float local_100;
  undefined4 local_fc;
  undefined4 *local_f8;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  
  if (*(int *)(**(longlong **)(DAT_14033d9d8 + 0x697b8) + 0x118) <= param_2) {
    return true;
  }
  lVar25 = 0;
  lVar24 = (longlong)param_2 * 0x520 +
           *(longlong *)((*(longlong **)(DAT_14033d9d8 + 0x697b8))[DAT_14033d9d2] + 0x110);
  uVar7 = *(uint *)(param_1[0x67] + 0xc);
  pauVar21 = param_1;
  if ((uVar7 & 1) == 0) {
    if (param_1[0x67][8] == 0xff) {
      puVar19 = (undefined8 *)0x0;
    }
    else {
      puVar19 = (undefined8 *)
                (*(longlong *)(*(longlong *)(param_1[0x6b] + 8) + 0x697b8) +
                (ulonglong)(byte)param_1[0x67][8] * 8);
    }
    if ((param_1[0x67][9] != 0xff) && (puVar19 != (undefined8 *)0x0)) {
      pauVar21 = (undefined1 (*) [16])*puVar19;
      lVar25 = (ulonglong)(byte)param_1[0x67][9] * 0x520 + *(longlong *)pauVar21[0x11];
      if ((lVar25 != 0) && ((*(byte *)(lVar25 + 0x1f0) & 1) != 0)) goto LAB_1401aef1e;
    }
    bVar5 = param_1[0x68][0xb];
    pauVar21 = (undefined1 (*) [16])(ulonglong)bVar5;
    *(undefined2 *)(param_1[0x67] + 8) = 0xffff;
    if ((bVar5 == 1) || (bVar5 == 2)) {
      *(uint *)(param_1[0x67] + 0xc) = uVar7 | 0x400;
      return true;
    }
  }
LAB_1401aef1e:
  uVar34 = DAT_1402d3770;
  uVar16 = DAT_1402d27f4;
  bVar14 = false;
  auVar39 = ZEXT464(DAT_1402d27f4);
  if ((uVar7 & 1) != 0) {
    *(uint *)(param_1[0x67] + 0xc) = uVar7 & 0xfffffffe;
    FUN_1401b41c0(pauVar21,param_1 + 5,uVar16);
    auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
    auVar36 = vshufps_avx(auVar32,auVar32,0x55);
    auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
    local_148 = (float *)CONCAT44(auVar36._0_4_ + *(float *)(param_1[5] + 4),
                                  auVar32._0_4_ + *(float *)param_1[5]);
    local_140 = auVar9._0_4_ + *(float *)(param_1[5] + 8);
    auVar32 = vshufps_avx(auVar32,auVar32,0xff);
    local_13c = auVar32._0_4_ + *(float *)(param_1[5] + 0xc);
    iVar17 = FUN_1401b43a0(param_1,&local_148,lVar24 + 600);
    if (iVar17 == 1) {
      uVar7 = *(uint *)(param_1[5] + 4);
      *(uint *)param_1[5] = *(uint *)param_1[5] ^ uVar34;
      *(uint *)(param_1[5] + 8) = *(uint *)(param_1[5] + 8) ^ uVar34;
      *(uint *)(param_1[5] + 4) = uVar7 ^ uVar34;
      *(undefined4 *)(param_1[5] + 0xc) = 0;
    }
    bVar5 = *(byte *)(lVar24 + 0x236);
    param_1[0x67][8] = bVar5;
    bVar6 = *(byte *)(lVar24 + 0x237);
    param_1[0x67][9] = bVar6;
    if (bVar5 == 0xff) {
LAB_1401af0df:
      lVar25 = 0;
      cVar23 = '\0';
    }
    else {
      lVar8 = *(longlong *)(*(longlong *)(param_1[0x6b] + 8) + 0x697b8);
      plVar4 = (longlong *)(lVar8 + (ulonglong)bVar5 * 8);
      if (plVar4 == (longlong *)0x0) goto LAB_1401af0df;
      cVar23 = '\0';
      lVar25 = (ulonglong)bVar6 * 0x520 + *(longlong *)(*plVar4 + 0x110);
      if ((lVar25 != 0) &&
         (lVar22 = lVar25, iVar17 = FUN_1401b7140(lVar8,lVar25,(float)DAT_14033d9d1 * DAT_1402d23f0)
         , iVar17 == -0x80000000)) {
        auVar32 = *(undefined1 (*) [16])(lVar22 + 600);
        fVar31 = auVar32._0_4_ - *(float *)(lVar24 + 600);
        auVar36 = vshufps_avx(auVar32,auVar32,0x55);
        fVar28 = auVar36._0_4_ - *(float *)(lVar24 + 0x25c);
        auVar32 = vshufps_avx(auVar32,auVar32,0xaa);
        fVar29 = auVar32._0_4_ - *(float *)(lVar24 + 0x260);
        fVar31 = fVar29 * fVar29 + fVar28 * fVar28 + fVar31 * fVar31;
        if (DAT_1402d2c00 <= fVar31) {
          if (fVar31 < DAT_1402d2c20) {
            cVar23 = '\x02';
          }
        }
        else {
          cVar23 = '\x01';
        }
      }
    }
    pauVar21 = *(undefined1 (**) [16])param_1[0x6a];
    auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
    auVar36 = vshufps_avx(auVar32,auVar32,0x55);
    fVar31 = auVar32._0_4_ - *(float *)pauVar21[7];
    fVar28 = auVar36._0_4_ - *(float *)(pauVar21[7] + 4);
    auVar32 = vshufps_avx(auVar32,auVar32,0xaa);
    fVar29 = auVar32._0_4_ - *(float *)(pauVar21[7] + 8);
    if (DAT_1402d2be0 <= fVar29 * fVar29 + fVar28 * fVar28 + fVar31 * fVar31) {
LAB_1401af13a:
      if (cVar23 != '\0') goto LAB_1401af13f;
    }
    else {
      uVar20 = FUN_140242630();
      pauVar21 = *(undefined1 (**) [16])param_1[0x6a];
      if ((uVar20 & 1) != 0) goto LAB_1401af13a;
      cVar23 = '\x03';
LAB_1401af13f:
      if (cVar23 != param_1[0x68][0xb]) {
        *(uint *)(param_1[0x67] + 0xc) = *(uint *)(param_1[0x67] + 0xc) | 2;
        param_1[0x68][0xb] = cVar23;
        if (cVar23 == '\x03') {
          *(undefined4 *)param_1[6] = *(undefined4 *)pauVar21[7];
          *(undefined4 *)(param_1[6] + 4) = *(undefined4 *)(pauVar21[7] + 4);
          *(undefined4 *)(param_1[6] + 8) = *(undefined4 *)(pauVar21[7] + 8);
          *(undefined4 *)(param_1[6] + 0xc) = *(undefined4 *)(pauVar21[7] + 0xc);
          *(undefined4 *)(param_1[0x5b] + 8) = 0;
          *(undefined4 *)param_1[7] = 0;
          *(undefined8 *)(param_1[7] + 4) = 0x3f800000;
          *(undefined4 *)(param_1[7] + 0xc) = 0;
          bVar14 = true;
        }
        goto LAB_1401af1a5;
      }
    }
    *(uint *)(param_1[0x67] + 0xc) = *(uint *)(param_1[0x67] + 0xc) & 0xfffffffd;
    param_1[0x68][0xb] = 0;
  }
LAB_1401af1a5:
  fVar31 = DAT_1402d20b0;
  cVar23 = param_1[0x68][0xb];
  if (cVar23 == '\x01') {
    *(undefined4 *)(param_1[5] + 0xc) = 0;
    FUN_1400141a0(param_1 + 5);
    fVar38 = DAT_1402d2168;
    fVar31 = _UNK_1402d3724 * *(float *)(param_1[5] + 4);
    fVar28 = _UNK_1402d3728 * *(float *)(param_1[5] + 8);
    fVar29 = _UNK_1402d372c * *(float *)(param_1[5] + 0xc);
    *(float *)param_1[5] = _DAT_1402d3720 * *(float *)param_1[5];
    *(float *)(param_1[5] + 4) = fVar31;
    *(float *)(param_1[5] + 8) = fVar28;
    *(float *)(param_1[5] + 0xc) = fVar29;
    *(undefined4 *)(param_1[5] + 0xc) = 0x3f800000;
    pauVar21 = param_1 + 1;
    auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
    auVar36 = *(undefined1 (*) [16])(lVar25 + 600);
    fVar40 = auVar36._0_4_ - *(float *)(lVar24 + 600);
    auVar9 = vshufps_avx(auVar36,auVar36,0x55);
    fVar41 = auVar9._0_4_ - *(float *)(lVar24 + 0x25c);
    fVar31 = *(float *)(param_1[10] + 8);
    fVar28 = *(float *)(param_1[10] + 4);
    auVar13._4_12_ = auVar32._4_12_;
    auVar13._0_4_ = fVar40 * fVar38 + auVar32._0_4_;
    auVar9 = vshufps_avx(auVar32,auVar32,0x55);
    auVar10 = vshufps_avx(auVar32,auVar32,0xaa);
    auVar36 = vshufps_avx(auVar36,auVar36,0xaa);
    fVar35 = auVar36._0_4_ - *(float *)(lVar24 + 0x260);
    auVar10._4_12_ = auVar10._4_12_;
    auVar10._0_4_ = fVar35 * fVar38 + auVar10._0_4_;
    auVar9._4_12_ = auVar9._4_12_;
    auVar9._0_4_ = fVar41 * fVar38 + auVar9._0_4_;
    auVar36 = vinsertps_avx(auVar13,auVar9,0x10);
    auVar36 = vinsertps_avx(auVar36,auVar10,0x20);
    auVar32 = vshufps_avx(auVar32,auVar32,0xff);
    auVar32 = vinsertps_avx(auVar36,auVar32,0x30);
    *param_1 = auVar32;
    auVar36 = vshufps_avx(auVar32,auVar32,0x55);
    fVar29 = *(float *)(param_1[5] + 4);
    auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
    fVar30 = *(float *)(param_1[5] + 8);
    fVar27 = auVar32._0_4_ + *(float *)param_1[5];
    *(undefined4 *)(param_1[1] + 0xc) = 0x3f800000;
    *(float *)*pauVar21 = fVar27;
    local_f8 = (undefined4 *)CONCAT44(local_f8._4_4_,fVar41);
    local_148 = (float *)CONCAT44(local_148._4_4_,fVar35);
    *(float *)(param_1[1] + 4) = auVar36._0_4_ + fVar29;
    *(float *)(param_1[1] + 8) = auVar9._0_4_ + fVar30;
    FUN_1401b4110(fVar27,param_1 + 2,pauVar21,param_1);
    _auStack_178 = ZEXT816(0);
    local_188 = 0;
    uStack_180 = 0;
    local_168 = 0;
    uStack_160 = 0;
    _local_158 = _auStack_178;
    FUN_140202920(&local_188,param_1 + 2);
    local_108 = (float)local_158._0_4_ + *(float *)*pauVar21;
    local_100 = fStack_150 + *(float *)(param_1[1] + 8);
    local_104 = (float)local_158._4_4_ + *(float *)(param_1[1] + 4);
    local_138 = local_188;
    uStack_130 = uStack_180;
    uStack_128 = auStack_178;
    uStack_120 = uStack_170;
    local_fc = fStack_14c;
    local_118 = local_168;
    uStack_110 = uStack_160;
    auVar39 = ZEXT1664(auVar39._0_16_);
    FUN_14003a2e0(&local_138);
    fVar29 = *(float *)(lVar24 + 600);
    fVar30 = *(float *)(lVar24 + 0x25c);
    fVar27 = *(float *)(lVar24 + 0x260);
    auVar32 = ZEXT816(0);
    auVar36 = ZEXT816(0);
    fVar41 = fVar27 * local_118._4_4_ + fVar30 * uStack_128._4_4_ + local_138._4_4_ * fVar29 +
             local_104;
    fVar35 = fVar27 * (float)local_118 + fVar30 * (float)uStack_128 + (float)local_138 * fVar29 +
             local_108;
    if (fVar27 * (float)uStack_110 + fVar30 * (float)uStack_120 + fVar29 * (float)uStack_130 +
        local_100 < 0.0) {
      auVar36 = ZEXT416((uint)SQRT(fVar41 * fVar41 + fVar35 * fVar35));
    }
    auVar37 = ZEXT1664(auVar36);
    fVar29 = *(float *)(lVar25 + 600);
    fVar30 = *(float *)(lVar25 + 0x25c);
    fVar27 = *(float *)(lVar25 + 0x260);
    fVar41 = local_118._4_4_ * fVar27 + uStack_128._4_4_ * fVar30 + fVar29 * local_138._4_4_ +
             local_104;
    fVar35 = fVar27 * (float)local_118 + (float)uStack_128 * fVar30 + fVar29 * (float)local_138 +
             local_108;
    if (fVar27 * (float)uStack_110 + fVar30 * (float)uStack_120 + fVar29 * (float)uStack_130 +
        local_100 < 0.0) {
      auVar32 = ZEXT416((uint)SQRT(fVar35 * fVar35 + fVar41 * fVar41));
    }
    auVar33 = ZEXT1664(auVar32);
    *(undefined4 *)(param_1[5] + 0xc) = 0;
    FUN_1400141a0(param_1 + 5);
    auVar32 = vmaxss_avx(auVar33._0_16_,auVar37._0_16_);
    auVar32 = vmaxss_avx(ZEXT416((uint)(auVar32._0_4_ * fVar31 * (DAT_1402d23e8 / fVar28))),
                         auVar39._0_16_);
    fVar30 = auVar32._0_4_;
    fVar31 = *(float *)(param_1[5] + 4);
    fVar28 = *(float *)(param_1[5] + 8);
    fVar29 = *(float *)(param_1[5] + 0xc);
    *(float *)param_1[5] = fVar30 * *(float *)param_1[5];
    *(float *)(param_1[5] + 4) = fVar30 * fVar31;
    *(float *)(param_1[5] + 8) = fVar30 * fVar28;
    *(float *)(param_1[5] + 0xc) = fVar30 * fVar29;
    *(undefined4 *)(param_1[5] + 0xc) = 0;
    local_f0 = *(float *)*param_1;
    fStack_ec = *(float *)(*param_1 + 4);
    fStack_e8 = *(float *)(*param_1 + 8);
    uStack_e4 = *(undefined4 *)(*param_1 + 0xc);
    fVar31 = *(float *)param_1[5];
    fVar28 = *(float *)(param_1[5] + 4);
    fVar29 = *(float *)(param_1[5] + 8);
    *(undefined4 *)(param_1[1] + 0xc) = uStack_e4;
    *(float *)*pauVar21 = local_f0 + fVar31;
    *(float *)(param_1[1] + 4) = fStack_ec + fVar28;
    *(float *)(param_1[1] + 8) = fStack_e8 + fVar29;
    auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
    *(float *)*param_1 = fVar38 * fVar40 + auVar32._0_4_;
    auVar36 = vshufps_avx(auVar32,auVar32,0x55);
    *(float *)(*param_1 + 4) = fVar38 * local_f8._0_4_ + auVar36._0_4_;
    auVar36 = vshufps_avx(auVar32,auVar32,0xaa);
    *(float *)(*param_1 + 8) = fVar38 * (float)local_148 + auVar36._0_4_;
    uVar18 = vextractps_avx(auVar32,3);
    *(undefined4 *)(*param_1 + 0xc) = uVar18;
  }
  else {
    if (cVar23 == '\x02') {
      pauVar1 = param_1 + 1;
      *(undefined4 *)*pauVar1 = *(undefined4 *)(lVar24 + 600);
      *(undefined4 *)(param_1[1] + 4) = *(undefined4 *)(lVar24 + 0x25c);
      *(undefined4 *)(param_1[1] + 8) = *(undefined4 *)(lVar24 + 0x260);
      *(undefined4 *)(param_1[1] + 0xc) = *(undefined4 *)(lVar24 + 0x264);
      *(undefined4 *)*param_1 = *(undefined4 *)(lVar25 + 600);
      *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(lVar25 + 0x25c);
      *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(lVar25 + 0x260);
      *(undefined4 *)(*param_1 + 0xc) = *(undefined4 *)(lVar25 + 0x264);
      FUN_1401b4110(pauVar21,param_1 + 2,pauVar1,param_1);
      _auStack_178 = ZEXT816(0);
      local_188 = 0;
      uStack_180 = 0;
      local_168 = 0;
      uStack_160 = 0;
      _local_158 = _auStack_178;
      FUN_140202920(&local_188,param_1 + 2);
      fVar40 = DAT_1402d27f0;
      fVar35 = DAT_1402d25b8;
      auVar36._8_8_ = uStack_160;
      auVar36._0_8_ = local_168;
      fVar31 = *(float *)*pauVar1;
      fVar28 = *(float *)(param_1[1] + 8);
      fVar29 = *(float *)(param_1[1] + 4);
      fVar30 = DAT_1402d25b8 * (float)auStack_178._0_4_;
      fVar41 = (float)local_168 * DAT_1402d27f0;
      fVar27 = DAT_1402d25b8 * (float)auStack_178._4_4_;
      *(undefined4 *)*pauVar1 = 0;
      *(undefined4 *)(param_1[1] + 4) = 0x41ecbc0b;
      *(undefined4 *)(param_1[1] + 8) = 0x43318d08;
      *(undefined4 *)(param_1[1] + 0xc) = 0x3f800000;
      *(undefined4 *)*param_1 = *(undefined4 *)(lVar25 + 600);
      *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(lVar25 + 0x25c);
      *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(lVar25 + 0x260);
      uVar18 = *(undefined4 *)(lVar25 + 0x264);
      *(float *)*pauVar1 = fVar41 + fVar30 + (float)local_158._0_4_ + fVar31;
      auVar32 = vshufps_avx(auVar36,auVar36,0x55);
      *(float *)(param_1[1] + 4) = auVar32._0_4_ * fVar40 + fVar27 + (float)local_158._4_4_ + fVar29
      ;
      auVar32 = vshufps_avx(auVar36,auVar36,0xaa);
      auVar36 = vshufps_avx(auVar36,auVar36,0xff);
      *(float *)(param_1[1] + 8) =
           auVar32._0_4_ * fVar40 + fVar35 * (float)uStack_170 + fStack_150 + fVar28;
      *(float *)(param_1[1] + 0xc) = auVar36._0_4_ * fVar40 + fVar35 * uStack_170._4_4_ + fStack_14c
      ;
    }
    else {
      if (cVar23 == '\x03') {
        if (*(int *)(param_1[0x5b] + 8) == 0) {
          auVar32 = *(undefined1 (*) [16])(*(longlong *)param_1[0x6a] + 0x70);
          fVar28 = auVar32._0_4_ - *(float *)(lVar24 + 600);
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          fVar29 = auVar36._0_4_ - *(float *)(lVar24 + 0x25c);
          auVar32 = vshufps_avx(auVar32,auVar32,0xaa);
          fVar30 = auVar32._0_4_ - *(float *)(lVar24 + 0x260);
          fVar29 = SQRT(fVar30 * fVar30 + fVar29 * fVar29 + fVar28 * fVar28);
          fVar28 = ((*(float *)(param_1[10] + 4) * DAT_1402d20b0) / *(float *)(param_1[10] + 8)) *
                   fVar29;
          auVar37 = ZEXT864(0);
          if (fVar28 < 0.0) {
            fVar28 = ((*(float *)(param_1[10] + 4) * DAT_1402d2cfc) / *(float *)(param_1[10] + 8)) *
                     fVar29;
          }
          *(float *)param_1[1] = *(float *)(lVar24 + 600);
          *(undefined4 *)(param_1[1] + 4) = *(undefined4 *)(lVar24 + 0x25c);
          *(undefined4 *)(param_1[1] + 8) = *(undefined4 *)(lVar24 + 0x260);
          *(undefined4 *)(param_1[1] + 0xc) = *(undefined4 *)(lVar24 + 0x264);
          lVar25 = *(longlong *)param_1[0x6a];
          *(undefined4 *)*param_1 = *(undefined4 *)(lVar25 + 0x70);
          *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(lVar25 + 0x74);
          *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(lVar25 + 0x78);
          *(undefined4 *)(*param_1 + 0xc) = *(undefined4 *)(lVar25 + 0x7c);
          FUN_1401b4110(lVar25,param_1 + 2,param_1 + 1,param_1);
          _auStack_178 = ZEXT816(0);
          local_188 = 0;
          uStack_180 = 0;
          local_168 = 0;
          uStack_160 = 0;
          _local_158 = _auStack_178;
          FUN_140202920(&local_188,param_1 + 2);
          fVar29 = fStack_150 + (float)uStack_170;
          fVar30 = (float)local_158._4_4_ + (float)auStack_178._4_4_;
          fVar27 = (float)local_158._0_4_ + (float)auStack_178._0_4_;
          pauVar21 = param_1 + 7;
          if (fVar29 * *(float *)(param_1[7] + 8) +
              fVar27 * *(float *)*pauVar21 + fVar30 * *(float *)(param_1[7] + 4) < auVar37._0_4_) {
            fVar27 = (float)((uint)fVar27 ^ uVar34);
            fVar30 = (float)((uint)fVar30 ^ uVar34);
            fVar29 = (float)((uint)fVar29 ^ uVar34);
          }
          *(float *)*pauVar21 = fVar27;
          *(float *)(param_1[7] + 4) = fVar30;
          *(undefined4 *)(param_1[7] + 0xc) = 0;
          puVar2 = (undefined4 *)(param_1[6] + 0xc);
          local_148 = (float *)(param_1[7] + 8);
          *local_148 = fVar29;
          local_f8 = (undefined4 *)(param_1[7] + 0xc);
          auVar32 = *(undefined1 (*) [16])(*(longlong *)param_1[0x6a] + 0x70);
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
          fVar27 = -(fVar28 * fVar27) + auVar32._0_4_;
          fVar30 = -(fVar28 * fVar30) + auVar36._0_4_;
          *(float *)*param_1 = fVar27;
          *(float *)(*param_1 + 4) = fVar30;
          *(float *)(*param_1 + 8) = -(fVar28 * fVar29) + auVar9._0_4_;
          uVar18 = vextractps_avx(auVar32,3);
          *(undefined4 *)(*param_1 + 0xc) = uVar18;
          if (bVar14) {
            *(float *)param_1[6] = fVar27;
            *(float *)(param_1[6] + 4) = fVar30;
            *(undefined4 *)(param_1[6] + 8) = *(undefined4 *)(*param_1 + 8);
            *puVar2 = 0;
          }
          auVar32 = *param_1;
          auVar33 = ZEXT464((uint)DAT_1402d22d0);
          auVar36 = vmaxss_avx(ZEXT416((uint)(DAT_1402d22d0 -
                                             (float)(uint)(*(int *)param_1[0x66] -
                                                          *(int *)(param_1[0x66] + 4)) /
                                             (float)DAT_14033d9d1)),auVar37._0_16_);
          auVar36 = vminss_avx(auVar36,ZEXT416((uint)DAT_1402d22d0));
          fVar29 = auVar36._0_4_ * DAT_1402d20f0 + DAT_1402d21c0;
          fVar28 = fVar29 * (auVar32._0_4_ - *(float *)param_1[6]) + *(float *)param_1[6];
          *(float *)param_1[6] = fVar28;
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          *(float *)(param_1[6] + 4) =
               fVar29 * (auVar36._0_4_ - *(float *)(param_1[6] + 4)) + *(float *)(param_1[6] + 4);
          auVar36 = vshufps_avx(auVar32,auVar32,0xaa);
          *(float *)(param_1[6] + 8) =
               fVar29 * (auVar36._0_4_ - *(float *)(param_1[6] + 8)) + *(float *)(param_1[6] + 8);
          auVar32 = vshufps_avx(auVar32,auVar32,0xff);
          *(float *)(param_1[6] + 0xc) =
               fVar29 * (auVar32._0_4_ - *(float *)(param_1[6] + 0xc)) +
               *(float *)(param_1[6] + 0xc);
          *(float *)*param_1 = fVar28;
          *puVar2 = 0;
          *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(param_1[6] + 4);
          *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(param_1[6] + 8);
          *(undefined4 *)(*param_1 + 0xc) = 0x3f800000;
          FUN_1401b4110(puVar2,param_1 + 2,param_1 + 1,param_1);
          FUN_140202920(&local_188,param_1 + 2);
          fVar28 = fStack_150 + (float)uStack_170;
          fVar29 = (float)local_158._0_4_ + (float)auStack_178._0_4_;
          fVar30 = (float)local_158._4_4_ + (float)auStack_178._4_4_;
          fVar27 = auVar37._0_4_;
          if (fVar28 * *(float *)(param_1[7] + 8) +
              fVar29 * *(float *)*pauVar21 + fVar30 * *(float *)(param_1[7] + 4) < fVar27) {
            fVar29 = (float)((uint)fVar29 ^ uVar34);
            fVar30 = (float)((uint)fVar30 ^ uVar34);
            fVar28 = (float)((uint)fVar28 ^ uVar34);
          }
          *(float *)param_1[7] = fVar29;
          *(float *)(param_1[7] + 4) = fVar30;
          *local_148 = fVar28;
          *local_f8 = 0;
          fVar15 = DAT_1402d25e4;
          auVar32 = *param_1;
          fVar38 = auVar32._0_4_ - *(float *)(lVar24 + 600);
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          fVar11 = auVar36._0_4_ - *(float *)(lVar24 + 0x25c);
          auVar32 = vshufps_avx(auVar32,auVar32,0xaa);
          fVar12 = auVar32._0_4_ - *(float *)(lVar24 + 0x260);
          fVar41 = fVar12 * DAT_1402d2168;
          fVar35 = fVar38 * DAT_1402d2168;
          fVar40 = fVar11 * DAT_1402d2168;
          fVar31 = SQRT((fVar12 * fVar12 + fVar11 * fVar11 + fVar38 * fVar38) * fVar31);
          if (fVar31 != fVar27) {
            fVar31 = auVar33._0_4_ / fVar31;
            fVar35 = fVar31 * fVar35;
            fVar40 = fVar31 * fVar40;
            fVar41 = fVar31 * fVar41;
          }
          auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
          uVar18 = vextractps_avx(auVar32,3);
          *(undefined4 *)(param_1[1] + 0xc) = uVar18;
          fVar38 = auVar39._0_4_;
          fVar31 = fVar29 * fVar15 + -(fVar35 * fVar38) + auVar32._0_4_;
          *(float *)param_1[1] = fVar31;
          fVar29 = fVar30 * fVar15 + -(fVar40 * fVar38) + auVar36._0_4_;
          fVar28 = fVar28 * fVar15 + -(fVar41 * fVar38) + auVar9._0_4_;
          *(float *)(param_1[1] + 4) = fVar29;
          *(float *)(param_1[1] + 8) = fVar28;
          auVar32 = *param_1;
          fVar31 = auVar32._0_4_ - fVar31;
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          fVar29 = auVar36._0_4_ - fVar29;
          auVar32 = vshufps_avx(auVar32,auVar32,0xaa);
          fVar28 = auVar32._0_4_ - fVar28;
          fVar31 = SQRT(fVar28 * fVar28 + fVar29 * fVar29 + fVar31 * fVar31);
          if (fVar31 != fVar27) {
            fVar29 = fVar29 / fVar31;
          }
          if ((fVar29 < DAT_1402d2d60) || (DAT_1402d22b8 < fVar29)) {
            *(undefined4 *)(param_1[0x5b] + 8) = 1;
          }
        }
        if (*(int *)(param_1[0x5b] + 8) == 0) {
          FUN_1401b4110();
          auVar32 = param_1[1];
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          fVar31 = *(float *)(lVar24 + 0x25c);
          auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
          fVar28 = *(float *)(lVar24 + 0x260);
          auVar10 = vshufps_avx(auVar32,auVar32,0xff);
          fVar29 = *(float *)(lVar24 + 0x264);
          *(float *)param_1[8] = auVar32._0_4_ - *(float *)(lVar24 + 600);
          *(float *)(param_1[8] + 4) = auVar36._0_4_ - fVar31;
          *(float *)(param_1[8] + 8) = auVar9._0_4_ - fVar28;
          *(float *)(param_1[8] + 0xc) = auVar10._0_4_ - fVar29;
          *(undefined4 *)param_1[9] = *(undefined4 *)param_1[2];
          *(undefined4 *)(param_1[9] + 4) = *(undefined4 *)(param_1[2] + 4);
          *(undefined4 *)(param_1[9] + 8) = *(undefined4 *)(param_1[2] + 8);
          *(undefined4 *)(param_1[9] + 0xc) = *(undefined4 *)(param_1[2] + 0xc);
        }
        else {
          auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
          auVar36 = vshufps_avx(auVar32,auVar32,0x55);
          fVar31 = *(float *)(param_1[8] + 4);
          auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
          fVar28 = *(float *)(param_1[8] + 8);
          auVar10 = vshufps_avx(auVar32,auVar32,0xff);
          fVar29 = *(float *)(param_1[8] + 0xc);
          *(float *)param_1[1] = auVar32._0_4_ + *(float *)param_1[8];
          *(float *)(param_1[1] + 4) = auVar36._0_4_ + fVar31;
          *(float *)(param_1[1] + 8) = auVar9._0_4_ + fVar28;
          *(float *)(param_1[1] + 0xc) = auVar10._0_4_ + fVar29;
          *(undefined4 *)param_1[2] = *(undefined4 *)param_1[9];
          *(undefined4 *)(param_1[2] + 4) = *(undefined4 *)(param_1[9] + 4);
          *(undefined4 *)(param_1[2] + 8) = *(undefined4 *)(param_1[9] + 8);
          *(undefined4 *)(param_1[2] + 0xc) = *(undefined4 *)(param_1[9] + 0xc);
        }
        goto LAB_1401afce4;
      }
      auVar32 = *(undefined1 (*) [16])(lVar24 + 600);
      auVar36 = vshufps_avx(auVar32,auVar32,0x55);
      fVar31 = *(float *)(param_1[5] + 4);
      auVar9 = vshufps_avx(auVar32,auVar32,0xaa);
      fVar28 = *(float *)(param_1[5] + 8);
      auVar10 = vshufps_avx(auVar32,auVar32,0xff);
      fVar29 = *(float *)(param_1[5] + 0xc);
      *(float *)param_1[1] = auVar32._0_4_ + *(float *)param_1[5];
      *(float *)(param_1[1] + 4) = auVar36._0_4_ + fVar31;
      *(float *)(param_1[1] + 8) = auVar9._0_4_ + fVar28;
      *(float *)(param_1[1] + 0xc) = auVar10._0_4_ + fVar29;
      *(undefined4 *)*param_1 = *(undefined4 *)(lVar24 + 600);
      *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(lVar24 + 0x25c);
      *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(lVar24 + 0x260);
      uVar18 = *(undefined4 *)(lVar24 + 0x264);
    }
    *(undefined4 *)(*param_1 + 0xc) = uVar18;
  }
  uVar26 = FUN_1401b4a20(param_1,param_1 + 1,DAT_1402d273c,1);
  FUN_1401b4110(uVar26,param_1 + 2,param_1 + 1,param_1);
LAB_1401afce4:
  pauVar21 = param_1 + 2;
  auVar32 = param_1[1];
  fVar31 = auVar32._0_4_ - *(float *)(lVar24 + 600);
  auVar36 = vshufps_avx(auVar32,auVar32,0x55);
  fVar28 = auVar36._0_4_ - *(float *)(lVar24 + 0x25c);
  auVar32 = vshufps_avx(auVar32,auVar32,0xaa);
  fVar29 = auVar32._0_4_ - *(float *)(lVar24 + 0x260);
  if (SQRT(fVar29 * fVar29 + fVar31 * fVar31 + fVar28 * fVar28) < DAT_1402d27e4) {
    param_1[0x68][0xc] = 1;
  }
  uVar26 = FUN_1401aa420(param_1,DAT_1402d1f84,0x14);
  FUN_1401aa540(uVar26,&local_f0);
  FUN_140203050(pauVar21,&local_f0,pauVar21);
  auVar32 = vpcmpeqd_avx(ZEXT416(*(uint *)(*(longlong *)(param_1[0x6b] + 8) + 0xa8790) & 0x10),
                         SUB6416(ZEXT464(0),0));
  auVar32 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar32);
  *(int *)param_1[0x43] = auVar32._0_4_;
  puVar3 = (uint *)(*(longlong *)param_1[0x6a] + 0x2058);
  *puVar3 = *puVar3 & 0xffefffff;
  FUN_1401b5120(param_1,param_1 + 1,pauVar21);
  if (((uint)DAT_14033d9d1 * 5 < (uint)(*(int *)param_1[0x66] - *(int *)(param_1[0x66] + 4))) &&
     ((param_1[0x67][0xc] & 1) == 0)) {
    return true;
  }
  return param_1[0x68][0xc] == '\x01';
}

