/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ab000; RVA 0x1ab000
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1401ab000(float *param_1)

{
  longlong *plVar1;
  float fVar2;
  float fVar3;
  undefined1 auVar4 [16];
  byte bVar5;
  undefined1 uVar6;
  float fVar7;
  longlong lVar8;
  undefined8 *puVar9;
  float fVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  char cVar18;
  uint uVar19;
  int *piVar20;
  float *pfVar21;
  ulonglong uVar22;
  float *pfVar23;
  int iVar24;
  ulonglong uVar25;
  longlong lVar26;
  ulonglong uVar27;
  longlong lVar28;
  undefined1 (*pauVar29) [16];
  undefined8 uVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined1 local_108 [16];
  float local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  float fStack_ec;
  undefined1 local_e8 [8];
  float fStack_e0;
  float fStack_dc;
  
  lVar26 = DAT_14033d9d8;
  lVar8 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  bVar5 = *(byte *)(lVar8 + 0x236);
  if (bVar5 == 0xff || *(byte *)(lVar8 + 0x237) == 0xff) {
    pfVar21 = (float *)0x0;
  }
  else {
    pfVar21 = (float *)((ulonglong)*(byte *)(lVar8 + 0x237) * 0x520 +
                       *(longlong *)
                        (*(longlong *)
                          (*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)bVar5 * 8) + 0x110));
  }
  pfVar23 = (float *)0x0;
  if (bVar5 != 0) {
    pfVar23 = pfVar21;
  }
  if (((uint)param_1[0x19f] & 1) != 0) {
    param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffe);
    uVar19 = FUN_140242630();
    uVar19 = uVar19 & 0x80000001;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffffe) + 1;
    }
    fVar31 = (float)(int)(uVar19 * 2 + -1) * DAT_1402d2520;
    uVar19 = FUN_140242630();
    fVar10 = DAT_1402d267c;
    fVar32 = DAT_1402d2320;
    uVar19 = uVar19 & 0x80000001;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffffe) + 1;
    }
    param_1[0x111] = fVar31;
    param_1[0x112] = 96.0;
    param_1[0x113] = 1.0;
    param_1[0x114] = 0.0;
    pfVar21 = param_1 + 0x1a8;
    param_1[0x110] = (float)(int)(uVar19 * 2 + -1) * DAT_1402d2544;
    param_1[0x115] = 12.0;
    param_1[0x116] = 96.0;
    param_1[0x117] = 1.0;
    uVar19 = DAT_1402d3770;
    if (*(char *)(param_1 + 0x11d) == '\x01') {
      *(undefined1 *)(param_1 + 0x11d) = 0;
    }
    else {
      fVar33 = (float)((uint)param_1[0x112] ^ DAT_1402d3770);
      param_1[0x112] = fVar33;
      param_1[0x110] = (float)((uint)param_1[0x110] ^ uVar19);
      *(undefined1 *)(param_1 + 0x11d) = 1;
      param_1[0x113] = 1.0;
      param_1[0x111] = (float)((uint)param_1[0x111] ^ uVar19);
      fVar31 = fVar10 + *(float *)(*(longlong *)(*(longlong *)pfVar21 + 0x1a0) + 0x18);
      if (fVar31 < 0.0) {
        param_1[0x112] = fVar31 * fVar32 + fVar33;
      }
    }
    fVar10 = fVar10 + *(float *)(*(longlong *)(*(longlong *)pfVar21 + 0x1a0) + 0x18);
    if (fVar10 < 0.0) {
      param_1[0x116] = -(fVar10 * fVar32) + param_1[0x116];
    }
    *(undefined1 *)((longlong)param_1 + 0x68b) = 0;
    *(undefined2 *)(param_1 + 0x11c) = 0;
  }
  if (*(char *)((longlong)param_1 + 0x68b) == '\0') {
    if (*(char *)(param_1 + 0x11d) == '\0') {
LAB_1401ab241:
      if (((uint)param_1[0x19f] & 4) == 0) {
        param_1[0x182] = -NAN;
        if (0 < (int)_DAT_14033d9b4) {
          piVar20 = &DAT_14033bdb0;
          iVar24 = 0;
          uVar25 = _DAT_14033d9b4 & 0xffffffff;
          uVar27 = _DAT_14033d9b4 & 0xffffffff;
          uVar22 = _DAT_14033d9b4;
          while( true ) {
            uVar19 = (uint)uVar22;
            if (((-1 < *piVar20) &&
                (uVar19 = (uint)uVar25, *(char *)((longlong)piVar20 + 0x13) == '\0')) &&
               (uVar19 = (uint)uVar27, (char)piVar20[5] == '\0')) break;
            piVar20 = piVar20 + 6;
            iVar24 = iVar24 + 1;
            if ((int)uVar19 <= iVar24) goto LAB_1401ab2c7;
            uVar22 = (ulonglong)uVar19;
            uVar25 = (ulonglong)uVar19;
            uVar27 = (ulonglong)uVar19;
          }
          uVar30 = *(undefined8 *)(piVar20 + 2);
          *(undefined8 *)(param_1 + 0x182) = *(undefined8 *)piVar20;
          *(undefined8 *)(param_1 + 0x184) = uVar30;
          *(undefined8 *)(param_1 + 0x186) = *(undefined8 *)(piVar20 + 4);
        }
LAB_1401ab2c7:
        if (-1 < (int)param_1[0x182]) {
          param_1[0x19f] = (float)((uint)param_1[0x19f] | 4);
          lVar28 = *(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0);
          if (lVar28 != 0) {
            *(undefined8 *)(lVar28 + 0x2a0) = 0;
            *(undefined4 *)(lVar28 + 0x2a8) = 0xffff0000;
            *(undefined2 *)(lVar28 + 0x2ac) = 0xffff;
            *(undefined4 *)(lVar28 + 0x26c) = 0xffff;
            *(undefined8 *)(lVar28 + 0x2b0) = 0;
            FUN_1401417e0(*(undefined8 *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0),
                          *(undefined1 *)(param_1 + 0x182),*(char *)(param_1 + 0x186) != '\0',
                          *(undefined1 *)((longlong)param_1 + 0x61a),0,0,
                          *(undefined1 *)((longlong)param_1 + 0x61d),
                          *(undefined1 *)((longlong)param_1 + 0x61e));
          }
        }
      }
      else if (*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0) != 0) {
        FUN_140141950(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0),
                      CONCAT71((int7)((ulonglong)pfVar21 >> 8),1));
        bVar5 = *(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0) + 0x2a6);
        if ((bVar5 == 0) || ((bVar5 & 8) != 0)) {
          param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffb);
        }
        else if ((bVar5 & 2) != 0) {
          *(undefined1 *)((longlong)param_1 + 0x68b) = 2;
          param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffb | 0x400);
        }
      }
    }
  }
  else if (*(char *)((longlong)param_1 + 0x68b) == '\x01') goto LAB_1401ab241;
  cVar18 = *(char *)((longlong)param_1 + 0x68b);
  if (cVar18 == '\0') {
    FUN_1401aaa70(param_1,param_1 + 0x110,lVar8);
    lVar26 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x1ae) + 0xa8318) + 0x10);
    if (((((lVar26 == 0) || (puVar9 = *(undefined8 **)(lVar26 + 0x2d8), puVar9 == (undefined8 *)0x0)
          ) || ((*(byte *)*puVar9 <= *(byte *)(lVar26 + 0x3c9) ||
                (puVar9 = (undefined8 *)(puVar9[1] + (ulonglong)*(byte *)(lVar26 + 0x3c9) * 0x48),
                puVar9 == (undefined8 *)0x0)))) ||
        ((cVar18 = *(char *)*puVar9, cVar18 != '\x06' && (cVar18 != '\x04')))) &&
       ((cVar18 = FUN_1401b4eb0(param_1,lVar8), cVar18 == '\x01' &&
        ((((((uint)param_1[0x19f] & 4) == 0 && (((uint)param_1[0x19f] >> 0x10 & 1) == 0)) &&
          (*(longlong *)(param_1 + 0x19c) != 0)) &&
         ((ushort)(int)((float)DAT_14033d9d1 + (float)DAT_14033d9d1) < *(ushort *)(param_1 + 0x11c))
         ))))) {
      auVar4 = *(undefined1 (*) [16])(pfVar23 + 0x96);
      fVar10 = auVar4._0_4_ - *(float *)(lVar8 + 600);
      auVar11 = vshufps_avx(auVar4,auVar4,0x55);
      fVar31 = auVar11._0_4_ - *(float *)(lVar8 + 0x25c);
      auVar4 = vshufps_avx(auVar4,auVar4,0xaa);
      fVar32 = auVar4._0_4_ - *(float *)(lVar8 + 0x260);
      if (fVar32 * fVar32 + fVar10 * fVar10 + fVar31 * fVar31 < DAT_1402d2c1c) {
        param_1[0x199] = param_1[0x198];
        *(undefined1 *)((longlong)param_1 + 0x68b) = 1;
        param_1[0x118] = pfVar23[0x96];
        param_1[0x119] = pfVar23[0x97];
        param_1[0x11a] = pfVar23[0x98];
        param_1[0x11b] = pfVar23[0x99];
        *(undefined2 *)(param_1 + 0x11c) = 0;
        *(undefined1 *)((longlong)param_1 + 0x472) = *(undefined1 *)(pfVar23 + 0x8d);
        uVar6 = *(undefined1 *)((longlong)pfVar23 + 0x235);
        param_1[0x19f] = (float)((uint)param_1[0x19f] | 0x400);
        *(undefined1 *)((longlong)param_1 + 0x473) = uVar6;
      }
    }
    *(short *)(param_1 + 0x11c) = *(short *)(param_1 + 0x11c) + 1;
    FUN_1401b52f0(param_1,param_1 + 4,lVar8 + 600,param_1 + 8);
    goto LAB_1401abc70;
  }
  if (cVar18 == '\x01') {
    lVar28 = 0;
    if (((*(byte *)((longlong)param_1 + 0x472) == 0xff) ||
        (*(byte *)((longlong)param_1 + 0x473) == 0xff)) ||
       ((plVar1 = (longlong *)
                  (*(longlong *)(lVar26 + 0x697b8) +
                  (ulonglong)*(byte *)((longlong)param_1 + 0x472) * 8), plVar1 == (longlong *)0x0 ||
        ((lVar26 = *(longlong *)(*plVar1 + 0x110) +
                   (ulonglong)*(byte *)((longlong)param_1 + 0x473) * 0x520, lVar26 == 0 ||
         (((byte)*(undefined4 *)(lVar26 + 0x1f0) & 3) != 3)))))) {
      *(undefined1 *)((longlong)param_1 + 0x472) = 0xff;
      pauVar29 = (undefined1 (*) [16])0x258;
      *(undefined1 *)((longlong)param_1 + 0x473) = 0xff;
      fVar31 = param_1[0x118];
      fVar10 = param_1[0x119];
      fVar32 = param_1[0x11a];
      fVar33 = param_1[0x11b];
    }
    else {
      pauVar29 = (undefined1 (*) [16])(lVar26 + 600);
      fVar31 = *(float *)*pauVar29;
      param_1[0x118] = fVar31;
      fVar10 = *(float *)(lVar26 + 0x25c);
      param_1[0x119] = fVar10;
      fVar32 = *(float *)(lVar26 + 0x260);
      param_1[0x11a] = fVar32;
      fVar33 = *(float *)(lVar26 + 0x264);
      param_1[0x11b] = fVar33;
      lVar28 = lVar26;
    }
    param_1[4] = *(float *)(lVar8 + 600);
    param_1[5] = *(float *)(lVar8 + 0x25c);
    param_1[6] = *(float *)(lVar8 + 0x260);
    fVar7 = *(float *)(lVar8 + 0x264);
    *param_1 = fVar31;
    param_1[1] = fVar10;
    param_1[2] = fVar32;
    param_1[3] = fVar33;
    param_1[7] = fVar7;
    FUN_1401b4110((longlong)param_1 + 0x472,param_1 + 8,param_1 + 4,param_1);
    local_108 = ZEXT816(0);
    local_118 = 0;
    uStack_110 = 0;
    local_f8 = 0.0;
    uStack_f4 = 0;
    uStack_f0 = 0;
    fStack_ec = 0.0;
    _local_e8 = local_108;
    FUN_140202920(&local_118,param_1 + 8);
    fVar10 = param_1[0x114];
    auVar11._4_4_ = uStack_f4;
    auVar11._0_4_ = local_f8;
    auVar11._8_4_ = uStack_f0;
    auVar11._12_4_ = fStack_ec;
    auVar16._8_8_ = uStack_110;
    auVar16._0_8_ = local_118;
    local_128 = (float)local_e8._0_4_ + param_1[4];
    local_120 = fStack_e0 + param_1[6];
    local_124 = (float)local_e8._4_4_ + param_1[5];
    param_1[4] = fVar10;
    fVar31 = param_1[0x115];
    param_1[5] = fVar31;
    fVar32 = param_1[0x116];
    param_1[6] = fVar32;
    fVar33 = param_1[0x117];
    param_1[7] = fVar33;
    fVar7 = param_1[0x114];
    *param_1 = fVar7;
    fVar2 = param_1[0x115];
    param_1[1] = fVar2;
    auVar4 = vshufps_avx(auVar11,auVar11,0x55);
    auVar11 = vshufps_avx(auVar11,auVar11,0xaa);
    param_1[2] = param_1[0x116];
    fVar3 = param_1[0x117];
    auVar12 = vshufps_avx(local_108,local_108,0x55);
    auVar13 = vshufps_avx(auVar16,auVar16,0x55);
    param_1[5] = fVar33 * local_124 +
                 fVar32 * auVar4._0_4_ + fVar10 * auVar13._0_4_ + auVar12._0_4_ * fVar31;
    auVar14 = vshufps_avx(local_108,local_108,0xaa);
    auVar15 = vshufps_avx(auVar16,auVar16,0xaa);
    param_1[4] = local_128 * fVar33 +
                 fVar32 * local_f8 + fVar10 * (float)local_118 + local_108._0_4_ * fVar31;
    param_1[6] = fVar33 * local_120 +
                 fVar32 * auVar11._0_4_ + fVar10 * auVar15._0_4_ + auVar14._0_4_ * fVar31;
    auVar16 = vshufps_avx(auVar16,auVar16,0xff);
    auVar17 = vshufps_avx(local_108,local_108,0xff);
    param_1[7] = fVar32 * fStack_ec + fStack_dc * fVar33 +
                 auVar16._0_4_ * fVar10 + auVar17._0_4_ * fVar31;
    *param_1 = fVar3 * local_128 + fVar2 * local_108._0_4_ + (float)local_118 * fVar7;
    param_1[1] = fVar3 * local_124 + fVar2 * auVar12._0_4_ + auVar13._0_4_ * fVar7;
    param_1[3] = fVar3 * fStack_dc + fVar2 * auVar17._0_4_ + auVar16._0_4_ * fVar7;
    fVar10 = param_1[0x116];
    local_128 = fVar10 * local_f8 + local_128;
    param_1[2] = fVar3 * local_120 + fVar2 * auVar14._0_4_ + auVar15._0_4_ * fVar7;
    local_124 = fVar10 * auVar4._0_4_ + local_124;
    local_11c = fVar10 * fStack_ec + fStack_dc;
    local_120 = fVar10 * auVar11._0_4_ + local_120;
    uVar30 = FUN_1401b43a0(param_1,param_1 + 4,&local_128);
    FUN_1401b4110(uVar30,param_1 + 8,param_1 + 4,param_1);
    uVar30 = FUN_1401aa420(param_1,DAT_1402d1f60,0x14);
    FUN_1401aa540(uVar30,&local_128);
    FUN_140203050(param_1 + 8,&local_128,param_1 + 8);
    fVar10 = param_1[0x19f];
    if ((((uint)fVar10 & 4) == 0) &&
       ((ushort)(int)((float)DAT_14033d9d1 * DAT_1402d241c) < *(ushort *)(param_1 + 0x11c))) {
      if (lVar28 == 0) {
        *(undefined1 *)((longlong)param_1 + 0x68b) = 0;
      }
      else {
        auVar4 = *pauVar29;
        fVar31 = auVar4._0_4_ - *(float *)(lVar8 + 600);
        auVar11 = vshufps_avx(auVar4,auVar4,0x55);
        fVar32 = auVar11._0_4_ - *(float *)(lVar8 + 0x25c);
        auVar4 = vshufps_avx(auVar4,auVar4,0xaa);
        fVar33 = auVar4._0_4_ - *(float *)(lVar8 + 0x260);
        cVar18 = FUN_1401b4eb0(param_1,lVar8);
        if ((cVar18 == '\0') ||
           (DAT_1402d2c1c < fVar33 * fVar33 + fVar32 * fVar32 + fVar31 * fVar31)) {
          *(undefined1 *)((longlong)param_1 + 0x68b) = 0;
          cVar18 = '\0';
        }
        else {
          cVar18 = *(char *)((longlong)param_1 + 0x68b);
        }
        if (cVar18 != '\0') goto LAB_1401abb0a;
      }
      param_1[0x19f] = (float)((uint)fVar10 | 0x400);
      *(undefined2 *)(param_1 + 0x11c) = 0;
      param_1[0x199] = param_1[0x198];
    }
LAB_1401abb0a:
    auVar4 = vpcmpeqd_avx(ZEXT416(*(uint *)(*(longlong *)(param_1 + 0x1ae) + 0xa8790) & 0x10),
                          SUB6416(ZEXT464(0),0));
    auVar4 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar4);
    param_1[0x10c] = auVar4._0_4_;
    *(short *)(param_1 + 0x11c) = *(short *)(param_1 + 0x11c) + 1;
    FUN_1401b52f0(param_1,param_1 + 4,lVar8 + 600,param_1 + 8);
    goto LAB_1401abc70;
  }
  if (cVar18 != '\x02') goto LAB_1401abc70;
  if ((int)param_1[0x182] < 0) {
    *(undefined2 *)(param_1 + 0x11c) = 0;
LAB_1401abc4e:
    *(undefined1 *)((longlong)param_1 + 0x68b) = 0;
    param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffb | 0x400);
  }
  else {
    if (*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0) != 0) {
      FUN_140141950(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x1fd0),1);
    }
    lVar8 = *(longlong *)(param_1 + 0x1a8);
    lVar26 = *(longlong *)(lVar8 + 0x1fd0);
    if ((*(byte *)(lVar26 + 0x2a6) & 2) == 0) {
      param_1[0x182] = -NAN;
      goto LAB_1401abc4e;
    }
    param_1[4] = *(float *)(lVar26 + 0x1c0);
    param_1[5] = *(float *)(lVar26 + 0x1c4);
    param_1[6] = *(float *)(lVar26 + 0x1c8);
    param_1[7] = *(float *)(lVar26 + 0x1cc);
    lVar26 = *(longlong *)(lVar8 + 0x1fd0);
    param_1[8] = *(float *)(lVar26 + 0x1d0);
    param_1[9] = *(float *)(lVar26 + 0x1d4);
    param_1[10] = *(float *)(lVar26 + 0x1d8);
    param_1[0xb] = *(float *)(lVar26 + 0x1dc);
    param_1[0x10c] = *(float *)(*(longlong *)(lVar8 + 0x1fd0) + 0x260);
  }
  FUN_1401b5120(param_1,param_1 + 4,param_1 + 8);
LAB_1401abc70:
  if (((uint)DAT_14033d9d1 * 5 < (uint)((int)param_1[0x198] - (int)param_1[0x199])) &&
     (*(char *)((longlong)param_1 + 0x68b) != '\x02')) {
    return true;
  }
  return *(char *)(param_1 + 0x1a3) == '\x01';
}

