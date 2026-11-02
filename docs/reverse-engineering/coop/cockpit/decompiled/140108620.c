/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140108620; RVA 0x108620
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140108620(longlong param_1,longlong *param_2,float *param_3,float *param_4,
                  undefined8 param_5,char param_6)

{
  float fVar1;
  float fVar2;
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined4 uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  float *pfVar12;
  longlong lVar13;
  undefined8 uVar14;
  float *pfVar15;
  float *pfVar16;
  longlong lVar17;
  float *pfVar18;
  undefined8 *puVar19;
  undefined8 uVar20;
  undefined8 *puVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  float fVar24;
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [64];
  float fVar28;
  undefined8 *******pppppppuVar29;
  undefined1 auVar30 [16];
  undefined1 in_ZMM8 [64];
  undefined1 auVar31 [64];
  undefined1 auVar32 [16];
  undefined1 in_ZMM9 [64];
  undefined1 auVar33 [64];
  undefined1 auVar34 [16];
  undefined1 in_ZMM10 [64];
  undefined1 auVar35 [64];
  float fVar36;
  undefined1 auVar37 [16];
  undefined1 in_ZMM11 [64];
  undefined1 auVar38 [64];
  undefined1 auVar39 [16];
  undefined1 in_ZMM12 [64];
  undefined1 auVar40 [64];
  undefined1 auVar41 [16];
  undefined1 in_ZMM13 [64];
  undefined1 auVar42 [64];
  undefined1 auVar43 [16];
  undefined1 in_ZMM14 [64];
  undefined1 auVar44 [64];
  undefined1 auVar45 [16];
  undefined1 in_ZMM15 [64];
  undefined1 auVar46 [64];
  undefined1 auStack_468 [32];
  undefined8 *******local_448;
  undefined8 local_438;
  undefined8 uStack_430;
  undefined1 local_428 [16];
  undefined8 local_418 [2];
  undefined1 local_408 [16];
  undefined1 auStack_3f8 [16];
  undefined1 local_3e8 [16];
  undefined1 auStack_3d8 [8];
  float fStack_3d0;
  undefined4 uStack_3cc;
  undefined8 *******local_3c8;
  undefined8 uStack_3c0;
  undefined1 local_3b8 [8];
  float fStack_3b0;
  undefined1 auStack_3a8 [16];
  undefined1 local_398 [16];
  undefined1 auStack_388 [8];
  float fStack_380;
  undefined8 local_378;
  undefined8 uStack_370;
  undefined8 uStack_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 uStack_348;
  undefined8 uStack_340;
  ulonglong local_338;
  undefined8 uStack_330;
  undefined1 auStack_328 [16];
  undefined8 local_318;
  ulonglong uStack_310;
  undefined1 auStack_308 [8];
  float fStack_300;
  uint uStack_2fc;
  undefined1 local_2f8 [16];
  undefined1 auStack_2e8 [16];
  undefined1 local_2d8 [16];
  undefined1 auStack_2c8 [16];
  float local_2b8;
  float fStack_2b4;
  float fStack_2b0;
  float fStack_2ac;
  float fStack_2a8;
  undefined2 uStack_2a4;
  undefined2 uStack_2a2;
  short sStack_2a0;
  short sStack_29e;
  float fStack_29c;
  float local_298;
  undefined2 uStack_294;
  undefined2 uStack_292;
  undefined2 uStack_290;
  undefined2 uStack_28e;
  float fStack_28c;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
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
  uint local_118;
  ulonglong local_f8;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  
  local_f8 = DAT_140309040 ^ (ulonglong)auStack_468;
  uVar20 = 0;
  local_418[0] = param_5;
  local_438 = *(undefined8 ********)(param_1 + 0x1fc8);
  if ((*(byte *)(param_1 + 0x1c20) & 4) == 0) {
    *(int *)(param_1 + 0x1be4) = *(int *)(param_1 + 0x1be4) + 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1be4) = 0;
  }
  if (((param_6 != '\0') && (DAT_14033bd60 == '\0')) &&
     (lVar13 = FUN_140189320(), *(char *)(lVar13 + 0x33) != '\0')) {
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 0xc) {
        puVar19 = (undefined8 *)0x0;
      }
      else {
        lVar13 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 0xb;
        puVar21 = *(undefined8 **)(*param_2 + 0x168);
        local_428._0_8_ = puVar21;
        if (*(char *)(lVar13 + 0x21) == '\0') {
          *(undefined1 *)(lVar13 + 0x21) = 1;
          puVar19 = *(undefined8 **)(lVar13 + 0x10);
        }
        else {
          puVar19 = (undefined8 *)0x0;
        }
        *puVar21 = 0x20000000;
        FUN_140197b30(puVar21,puVar19);
        *(undefined8 *)(local_428._0_8_ + 8) = 0;
      }
    }
    else {
      puVar19 = (undefined8 *)0x0;
    }
    local_428._0_8_ = *(longlong *)(param_1 + 0x2040);
    if (*(longlong *)(param_1 + 0x2040) != 0) {
      uVar14 = FUN_140203b30(*(longlong *)(param_1 + 0x1b68) + 0x40,puVar19);
      uVar14 = FUN_140203b30(*(longlong *)(param_1 + 0x1b68) + 0x88,uVar14);
      uVar14 = FUN_1401fc350(local_418[0],uVar14);
      puVar19 = (undefined8 *)FUN_1400bf810(uVar14,0);
      *puVar19 = 0x10000002;
      FUN_140197b30(puVar19,0);
      *(undefined4 *)(puVar19 + 1) = 0;
      *(undefined4 *)((longlong)puVar19 + 0xc) = 0x50000002;
      *(undefined4 *)(puVar19 + 2) = 0x8001;
      *(undefined4 *)((longlong)puVar19 + 0x14) = 0x10000000;
      puVar19[3] = 0xe;
      puVar19[4] = 0;
      *(undefined4 *)(puVar19 + 5) = 0x14;
      puVar19 = puVar19 + 6;
      if ((*(ushort *)(param_1 + 0x1c20) & 0x10) == 0) {
        if ((*(ushort *)(param_1 + 0x1c20) & 8) == 0) {
          lVar13 = *(longlong *)
                    (*(longlong *)
                      (*(longlong *)local_428._0_8_ + (ulonglong)*(byte *)(param_1 + 0x1c32) * 8) +
                    0x110);
          if ((lVar13 == 0) || (*(short *)(lVar13 + 0x428) < 1)) {
            *(uint *)(param_1 + 0x1bb4) = *(uint *)(param_1 + 0x1bb4) & 0xfff0;
            *(undefined2 *)(param_1 + 0x1bdc) = 0xffff;
            *(undefined4 *)(param_1 + 0x1be0) = 0xffffffff;
          }
          puVar19 = (undefined8 *)FUN_1400b1b60(param_1 + 0x1868,puVar19,local_418[0]);
        }
        if ((*(char *)(param_1 + 0x1c33) != '\0') && (*(char *)(param_1 + 0x1c32) == '\0')) {
          puVar19 = (undefined8 *)
                    (**(code **)(**(longlong **)(param_1 + 0x1888) + 0x48))
                              (*(longlong **)(param_1 + 0x1888),puVar19,local_418[0],
                               *(undefined1 *)(param_1 + 0x1c28));
        }
        puVar19 = (undefined8 *)FUN_1400b2950(param_1 + 0x1868,puVar19);
      }
    }
    FUN_1402011a0(param_2,puVar19);
  }
  if ((*(byte *)(*(longlong *)
                  (*(longlong *)
                    (**(longlong **)(param_1 + 0x2040) + (ulonglong)*(byte *)(param_1 + 0x20a1) * 8)
                  + 0x110) + 0x1f0 + (ulonglong)*(byte *)(param_1 + 0x20a2) * 0x520) & 1) == 0) {
    return;
  }
  if (param_6 == '\0') {
    if ((*(int *)((longlong)param_2 + 0xc) == -1) && (4 < (int)param_2[1])) {
      lVar13 = param_2[3];
      *(undefined4 *)((longlong)param_2 + 0xc) = 4;
      puVar21 = *(undefined8 **)(*param_2 + 0x88);
      if (*(char *)(lVar13 + 0x21) == '\0') {
        *(undefined1 *)(lVar13 + 0x21) = 1;
        uVar20 = *(undefined8 *)(lVar13 + 0x10);
      }
      else {
        uVar20 = 0;
      }
      *puVar21 = 0x20000000;
      FUN_140197b30(puVar21,uVar20);
      puVar21[1] = 0;
    }
    local_408 = ZEXT816(0);
    auStack_3f8 = ZEXT816(0);
    local_3e8 = local_408;
    _auStack_3d8 = auStack_3f8;
    FUN_140202920(local_408,param_1 + 0x80);
    auVar30 = _auStack_3d8;
    auVar22 = *(undefined1 (*) [16])(param_1 + 0x70);
    fVar24 = auVar22._0_4_ - param_3[0xc];
    auVar23 = vshufps_avx(auVar22,auVar22,0xaa);
    auStack_3d8._4_4_ = (float)auStack_3d8._4_4_ + *(float *)(param_1 + 0x74);
    auStack_3d8._0_4_ = (float)auStack_3d8._0_4_ + *(float *)(param_1 + 0x70);
    auVar26 = vshufps_avx(auVar22,auVar22,0x55);
    fVar8 = auVar26._0_4_ - param_3[0xd];
    uStack_3cc = auVar30._12_4_;
    fStack_3d0 = fStack_3d0 + *(float *)(param_1 + 0x78);
    fVar1 = auVar23._0_4_ - param_3[0xe];
    auVar22 = vshufps_avx(auVar22,auVar22,0xff);
    fVar2 = auVar22._0_4_ - param_3[0xf];
    local_448 = (undefined8 *******)CONCAT44(local_448._4_4_,param_3[2]);
    uVar20 = (**(code **)(*(longlong *)(param_1 + 0xda0) + 0x118))
                       ((longlong *)(param_1 + 0xda0),uVar20,local_408,
                        SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar8 * fVar8 + fVar24 * fVar24));
    FUN_1402011a0(param_2,uVar20);
    return;
  }
  if (((1 < *(int *)(param_1 + 0x1be4)) && (DAT_14033bd60 == '\0')) &&
     (lVar13 = FUN_140189320(), *(char *)(lVar13 + 0x33) != '\0')) {
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 0xc) {
        uVar20 = 0;
      }
      else {
        lVar13 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 0xb;
        puVar21 = *(undefined8 **)(*param_2 + 0x168);
        local_428._0_8_ = puVar21;
        if (*(char *)(lVar13 + 0x21) == '\0') {
          *(undefined1 *)(lVar13 + 0x21) = 1;
          uVar20 = *(undefined8 *)(lVar13 + 0x10);
        }
        else {
          uVar20 = 0;
        }
        *puVar21 = 0x20000000;
        FUN_140197b30(puVar21,uVar20);
        *(undefined8 *)(local_428._0_8_ + 8) = 0;
      }
    }
    else {
      uVar20 = 0;
    }
    local_448 = local_438;
    uVar20 = FUN_1400ae510(param_1 + 0x1868,uVar20,param_1 + 0x10b0,
                           *(undefined8 *)(param_1 + 0x2040));
    FUN_1402011a0(param_2,uVar20);
  }
  auVar41 = in_ZMM15._0_16_;
  auVar39 = in_ZMM14._0_16_;
  auVar37 = in_ZMM13._0_16_;
  auVar34 = in_ZMM12._0_16_;
  auVar32 = in_ZMM11._0_16_;
  auVar30 = in_ZMM10._0_16_;
  auVar26 = in_ZMM9._0_16_;
  auVar23 = in_ZMM8._0_16_;
  lVar13 = 3;
  auVar27 = ZEXT464(DAT_1402d2168);
  auVar22 = ZEXT416(DAT_1402d2168);
  if (((byte)DAT_14032844c & 4) != 0) {
    local_2f8 = ZEXT816(0);
    auStack_2e8 = ZEXT816(0);
    local_2d8 = local_2f8;
    auStack_2c8 = auStack_2e8;
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 5) {
        puVar21 = (undefined8 *)0x0;
      }
      else {
        lVar17 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 4;
        local_438 = *(undefined8 ********)(*param_2 + 0x88);
        if (*(char *)(lVar17 + 0x21) == '\0') {
          *(undefined1 *)(lVar17 + 0x21) = 1;
          puVar21 = *(undefined8 **)(lVar17 + 0x10);
        }
        else {
          puVar21 = (undefined8 *)0x0;
        }
        *local_438 = (undefined8 ******)0x20000000;
        FUN_140197b30(local_438,puVar21);
        local_438[1] = (undefined8 ******)0x0;
      }
    }
    else {
      puVar21 = (undefined8 *)0x0;
    }
    DAT_140328450._0_4_ = 0x20;
    *puVar21 = 0x50000000;
    FUN_140197b30(puVar21,&DAT_140291cd0);
    *(undefined4 *)(puVar21 + 1) = 0;
    *(undefined4 *)((longlong)puVar21 + 0xc) = 0x11000000;
    puVar21[2] = 0x50000000;
    FUN_140197b30(puVar21 + 2,&DAT_140292d30);
    *(undefined4 *)(puVar21 + 3) = 0x3000040;
    *(undefined4 *)((longlong)puVar21 + 0x1c) = 0x2000198;
    auStack_3f8 = ZEXT816(0);
    local_408 = ZEXT816(0);
    local_3e8 = ZEXT816(0);
    puVar19 = puVar21 + 4;
    _auStack_3d8 = auStack_3f8;
    FUN_140202920(local_408,param_1 + 0x80);
    auVar22 = _auStack_3d8;
    lVar17 = DAT_140328440;
    auVar45 = in_ZMM15._0_16_;
    auVar43 = in_ZMM14._0_16_;
    auVar41 = in_ZMM13._0_16_;
    auVar39 = in_ZMM12._0_16_;
    auVar37 = in_ZMM11._0_16_;
    auVar34 = in_ZMM10._0_16_;
    auVar32 = in_ZMM9._0_16_;
    auVar30 = in_ZMM8._0_16_;
    auVar26 = auVar27._0_16_;
    fVar24 = (float)auStack_3d8._0_4_ + *(float *)(param_1 + 0x70);
    fVar8 = (float)auStack_3d8._4_4_ + *(float *)(param_1 + 0x74);
    auStack_3d8._0_4_ = fVar24;
    auVar23 = _auStack_3d8;
    fStack_3d0 = auVar22._8_4_;
    uStack_3cc = auVar22._12_4_;
    auStack_3d8 = auVar23._0_8_;
    fStack_3d0 = fStack_3d0 + *(float *)(param_1 + 0x78);
    auStack_3d8._4_4_ = fVar8;
    if (DAT_140328440 == 0) {
      local_3c8 = *(undefined8 ********)(param_1 + 0x70);
      uStack_430 = *(undefined8 *)(param_1 + 0x78);
      local_448 = (undefined8 *******)&local_438;
      local_428 = ZEXT816(0);
      local_438 = (undefined8 *******)CONCAT44(DAT_1402d2ebc,SUB84(local_3c8,0));
      uStack_3c0 = uStack_430;
      FUN_1400782c0(*(undefined8 *)(param_1 + 0x2038),local_428,local_418,&local_3c8);
      auVar45 = in_ZMM15._0_16_;
      auVar43 = in_ZMM14._0_16_;
      auVar41 = in_ZMM13._0_16_;
      auVar39 = in_ZMM12._0_16_;
      auVar37 = in_ZMM11._0_16_;
      auVar34 = in_ZMM10._0_16_;
      auVar32 = in_ZMM9._0_16_;
      auVar30 = in_ZMM8._0_16_;
      auVar26 = auVar27._0_16_;
      fVar24 = (float)local_428._4_4_;
    }
    else {
      auVar3 = *(undefined1 (*) [32])(param_3 + 0x44);
      auVar4 = *(undefined1 (*) [32])(param_3 + 0x4c);
      auVar5 = *(undefined1 (*) [32])(param_3 + 0x54);
      auVar6 = *(undefined1 (*) [32])(param_3 + 0x5c);
      auVar23 = auVar6._0_16_;
      *puVar19 = 0x10000008;
      *(undefined4 *)(puVar21 + 5) = 0x11000000;
      *(undefined4 *)((longlong)puVar21 + 0x2c) = 0x6c084010;
      *(int *)(puVar21 + 6) = auVar3._0_4_;
      auVar22 = auVar3._0_16_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 0x34) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 7) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0x3c) = uVar7;
      auVar22 = auVar3._16_16_;
      *(int *)(puVar21 + 8) = auVar3._16_4_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 0x44) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 9) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0x4c) = uVar7;
      *(int *)(puVar21 + 10) = auVar4._0_4_;
      auVar22 = auVar4._0_16_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 0x54) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 0xb) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0x5c) = uVar7;
      auVar22 = auVar4._16_16_;
      *(int *)(puVar21 + 0xc) = auVar4._16_4_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 100) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 0xd) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0x6c) = uVar7;
      *(int *)(puVar21 + 0xe) = auVar5._0_4_;
      auVar22 = auVar5._0_16_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 0x74) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 0xf) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0x7c) = uVar7;
      auVar22 = auVar5._16_16_;
      *(int *)(puVar21 + 0x10) = auVar5._16_4_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 0x84) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 0x11) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0x8c) = uVar7;
      *(int *)(puVar21 + 0x12) = auVar6._0_4_;
      uVar7 = vextractps_avx(auVar23,1);
      *(undefined4 *)((longlong)puVar21 + 0x94) = uVar7;
      uVar7 = vextractps_avx(auVar23,2);
      *(undefined4 *)(puVar21 + 0x13) = uVar7;
      uVar7 = vextractps_avx(auVar23,3);
      *(undefined4 *)((longlong)puVar21 + 0x9c) = uVar7;
      auVar22 = auVar6._16_16_;
      *(int *)(puVar21 + 0x14) = auVar6._16_4_;
      uVar7 = vextractps_avx(auVar22,1);
      *(undefined4 *)((longlong)puVar21 + 0xa4) = uVar7;
      uVar7 = vextractps_avx(auVar22,2);
      *(undefined4 *)(puVar21 + 0x15) = uVar7;
      uVar7 = vextractps_avx(auVar22,3);
      *(undefined4 *)((longlong)puVar21 + 0xac) = uVar7;
      auVar3 = *(undefined1 (*) [32])(param_3 + 0x14);
      auVar4 = *(undefined1 (*) [32])(param_3 + 0x1c);
      auVar25 = auVar4._0_16_;
      auVar22 = auVar3._0_16_;
      auVar23 = auVar3._16_16_;
      auStack_2e8._4_4_ = vextractps_avx(auVar23,1);
      auStack_2e8._0_4_ = auVar3._16_4_;
      auStack_2e8._8_4_ = vextractps_avx(auVar23,2);
      auStack_2e8._12_4_ = vextractps_avx(auVar23,3);
      auVar23 = auVar4._16_16_;
      auStack_2c8._4_4_ = vextractps_avx(auVar23,1);
      auStack_2c8._0_4_ = auVar4._16_4_;
      auStack_2c8._8_4_ = vextractps_avx(auVar23,2);
      auStack_2c8._12_4_ = vextractps_avx(auVar23,3);
      local_2f8._4_4_ = vextractps_avx(auVar22,1);
      local_2f8._0_4_ = auVar3._0_4_;
      local_2f8._8_4_ = vextractps_avx(auVar22,2);
      local_2f8._12_4_ = vextractps_avx(auVar22,3);
      local_2d8._4_4_ = vextractps_avx(auVar25,1);
      local_2d8._0_4_ = auVar4._0_4_;
      local_2d8._8_4_ = vextractps_avx(auVar25,2);
      local_2d8._12_4_ = vextractps_avx(auVar25,3);
      puVar19 = puVar21 + 0x16;
      if (lVar17 != 0) {
        auVar27 = ZEXT1664(auVar26);
        auVar31 = ZEXT1664(auVar30);
        auVar33 = ZEXT1664(auVar32);
        auVar35 = ZEXT1664(auVar34);
        auVar38 = ZEXT1664(auVar37);
        auVar40 = ZEXT1664(auVar39);
        auVar42 = ZEXT1664(auVar41);
        auVar44 = ZEXT1664(auVar43);
        auVar46 = ZEXT1664(auVar45);
        puVar21 = (undefined8 *)FUN_140158d00(lVar17,puVar19);
        auStack_328 = ZEXT816(0);
        *puVar21 = 0x10000006;
        *(undefined4 *)(puVar21 + 1) = 0;
        *(undefined4 *)((longlong)puVar21 + 0xc) = 0x50000006;
        *(undefined4 *)(puVar21 + 2) = 0x8005;
        *(undefined4 *)((longlong)puVar21 + 0x14) = 0x10000000;
        puVar21[3] = 0xe;
        *(undefined4 *)(puVar21 + 4) = 0x50000;
        *(undefined4 *)(puVar21 + 5) = 0x47;
        *(undefined4 *)(puVar21 + 6) = 1;
        *(undefined4 *)(puVar21 + 7) = 0x46;
        *(undefined4 *)(puVar21 + 8) = 0x68;
        *(undefined4 *)((longlong)puVar21 + 0x44) = 0x80;
        *(undefined4 *)(puVar21 + 9) = 0x42;
        *(undefined4 *)(puVar21 + 10) = 0x80000000;
        *(undefined4 *)((longlong)puVar21 + 0x54) = 0x3f800000;
        *(undefined4 *)(puVar21 + 0xb) = 1;
        *(undefined4 *)(puVar21 + 0xc) = 0x10000a8;
        *(undefined4 *)((longlong)puVar21 + 100) = 1;
        *(undefined4 *)(puVar21 + 0xd) = 0x4e;
        local_338 = 0;
        uStack_330 = 0;
        local_318 = 0;
        uStack_310 = 0;
        _auStack_308 = auStack_328;
        FUN_140202920(&local_338,&DAT_14033bb90);
        auVar22 = _auStack_308;
        fVar24 = (float)auStack_308._0_4_ + DAT_14033bb80;
        fVar8 = (float)auStack_308._4_4_ + DAT_14033bb84;
        auStack_308._0_4_ = fVar24;
        auVar23 = _auStack_308;
        fStack_300 = auVar22._8_4_;
        uStack_2fc = auVar22._12_4_;
        auStack_308 = auVar23._0_8_;
        fStack_300 = fStack_300 + DAT_14033bb88;
        auStack_308._4_4_ = fVar8;
        FUN_14015e140(DAT_140328440,1,param_1 + 0x960);
        FUN_14015e840();
        puVar19 = (undefined8 *)FUN_14015e8a0(DAT_140328440,puVar21 + 0xe,&local_338);
        auVar45 = auVar46._0_16_;
        auVar43 = auVar44._0_16_;
        auVar41 = auVar42._0_16_;
        auVar39 = auVar40._0_16_;
        auVar37 = auVar38._0_16_;
        auVar34 = auVar35._0_16_;
        auVar32 = auVar33._0_16_;
        auVar30 = auVar31._0_16_;
        auVar26 = auVar27._0_16_;
        lVar17 = DAT_140328440;
      }
      fVar24 = DAT_14033bb84 + *(float *)(*(longlong *)(lVar17 + 0x80) + 0x14);
    }
    lVar17 = 3;
    pfVar18 = param_3;
    pfVar12 = &local_2b8;
    do {
      pfVar16 = pfVar12;
      pfVar15 = pfVar18;
      uVar9 = *(undefined8 *)(pfVar15 + 2);
      uVar10 = *(undefined8 *)(pfVar15 + 4);
      uVar11 = *(undefined8 *)(pfVar15 + 6);
      uVar20 = *(undefined8 *)(pfVar15 + 0x1c);
      uVar14 = *(undefined8 *)(pfVar15 + 0x1e);
      *(undefined8 *)pfVar16 = *(undefined8 *)pfVar15;
      *(undefined8 *)(pfVar16 + 2) = uVar9;
      *(undefined8 *)(pfVar16 + 4) = uVar10;
      *(undefined8 *)(pfVar16 + 6) = uVar11;
      uVar9 = *(undefined8 *)(pfVar15 + 10);
      uVar10 = *(undefined8 *)(pfVar15 + 0xc);
      uVar11 = *(undefined8 *)(pfVar15 + 0xe);
      *(undefined8 *)(pfVar16 + 8) = *(undefined8 *)(pfVar15 + 8);
      *(undefined8 *)(pfVar16 + 10) = uVar9;
      *(undefined8 *)(pfVar16 + 0xc) = uVar10;
      *(undefined8 *)(pfVar16 + 0xe) = uVar11;
      uVar9 = *(undefined8 *)(pfVar15 + 0x12);
      uVar10 = *(undefined8 *)(pfVar15 + 0x14);
      uVar11 = *(undefined8 *)(pfVar15 + 0x16);
      *(undefined8 *)(pfVar16 + 0x10) = *(undefined8 *)(pfVar15 + 0x10);
      *(undefined8 *)(pfVar16 + 0x12) = uVar9;
      *(undefined8 *)(pfVar16 + 0x14) = uVar10;
      *(undefined8 *)(pfVar16 + 0x16) = uVar11;
      uVar9 = *(undefined8 *)(pfVar15 + 0x1a);
      *(undefined8 *)(pfVar16 + 0x18) = *(undefined8 *)(pfVar15 + 0x18);
      *(undefined8 *)(pfVar16 + 0x1a) = uVar9;
      *(undefined8 *)(pfVar16 + 0x1c) = uVar20;
      *(undefined8 *)(pfVar16 + 0x1e) = uVar14;
      lVar17 = lVar17 + -1;
      pfVar18 = pfVar15 + 0x20;
      pfVar12 = pfVar16 + 0x20;
    } while (lVar17 != 0);
    uVar20 = *(undefined8 *)(pfVar15 + 0x22);
    uVar14 = *(undefined8 *)(pfVar15 + 0x24);
    uVar9 = *(undefined8 *)(pfVar15 + 0x26);
    fStack_2b4 = auVar26._0_4_;
    fStack_2b0 = fStack_2b4 * param_4[2];
    local_2b8 = fStack_2b4 * *param_3;
    *(undefined8 *)(pfVar16 + 0x20) = *(undefined8 *)(pfVar15 + 0x20);
    *(undefined8 *)(pfVar16 + 0x22) = uVar20;
    *(undefined8 *)(pfVar16 + 0x24) = uVar14;
    *(undefined8 *)(pfVar16 + 0x26) = uVar9;
    uVar20 = *(undefined8 *)(pfVar15 + 0x2a);
    uVar14 = *(undefined8 *)(pfVar15 + 0x2c);
    uVar9 = *(undefined8 *)(pfVar15 + 0x2e);
    uStack_2a4 = *(undefined2 *)(param_3 + 5);
    *(undefined8 *)(pfVar16 + 0x28) = *(undefined8 *)(pfVar15 + 0x28);
    *(undefined8 *)(pfVar16 + 0x2a) = uVar20;
    *(undefined8 *)(pfVar16 + 0x2c) = uVar14;
    *(undefined8 *)(pfVar16 + 0x2e) = uVar9;
    fStack_2b4 = fStack_2b4 * param_3[1];
    local_118 = local_118 | 3;
    uStack_2a2 = *(undefined2 *)((longlong)param_3 + 0x16);
    sStack_2a0 = *(short *)(param_3 + 6) / 2;
    sStack_29e = *(short *)((longlong)param_3 + 0x1a) / 2;
    uStack_294 = *(undefined2 *)(param_3 + 9);
    fStack_2ac = param_3[3];
    uStack_292 = *(undefined2 *)((longlong)param_3 + 0x26);
    fStack_2a8 = param_3[4];
    fStack_28c = param_3[0xb];
    uStack_290 = *(undefined2 *)(param_3 + 10);
    local_298 = param_3[8];
    fStack_29c = param_3[7];
    uStack_28e = *(undefined2 *)((longlong)param_3 + 0x2a);
    auVar27 = ZEXT1664(auVar26);
    auVar31 = ZEXT1664(auVar30);
    auVar33 = ZEXT1664(auVar32);
    auVar35 = ZEXT1664(auVar34);
    auVar38 = ZEXT1664(auVar37);
    auVar40 = ZEXT1664(auVar39);
    auVar42 = ZEXT1664(auVar41);
    auVar44 = ZEXT1664(auVar43);
    auVar46 = ZEXT1664(auVar45);
    FUN_1401fbec0(&local_2b8);
    local_378 = uStack_1a8;
    uStack_370 = uStack_1a0;
    uStack_368 = local_198;
    uStack_360 = uStack_190;
    local_358 = uStack_188;
    uStack_350 = uStack_180;
    uStack_348 = uStack_178;
    uStack_340 = uStack_170;
    *puVar19 = 0x10000008;
    *(undefined4 *)(puVar19 + 1) = 0x11000000;
    *(undefined4 *)((longlong)puVar19 + 0xc) = 0x6c084010;
    puVar19[2] = uStack_1a8;
    puVar19[3] = uStack_1a0;
    puVar19[4] = local_198;
    puVar19[5] = uStack_190;
    puVar19[10] = local_168;
    puVar19[0xb] = uStack_160;
    puVar19[0xc] = uStack_158;
    puVar19[0xd] = uStack_150;
    puVar19[6] = uStack_188;
    puVar19[7] = uStack_180;
    puVar19[8] = uStack_178;
    puVar19[9] = uStack_170;
    puVar19[0xe] = local_148;
    puVar19[0xf] = uStack_140;
    puVar19[0x10] = uStack_138;
    puVar19[0x11] = uStack_130;
    local_448 = (undefined8 *******)CONCAT44(local_448._4_4_,fVar24);
    auVar27 = ZEXT1664(auVar27._0_16_);
    auVar31 = ZEXT1664(auVar31._0_16_);
    auVar33 = ZEXT1664(auVar33._0_16_);
    auVar35 = ZEXT1664(auVar35._0_16_);
    auVar38 = ZEXT1664(auVar38._0_16_);
    auVar40 = ZEXT1664(auVar40._0_16_);
    auVar42 = ZEXT1664(auVar42._0_16_);
    auVar44 = ZEXT1664(auVar44._0_16_);
    auVar46 = ZEXT1664(auVar46._0_16_);
    uVar20 = FUN_1401572e0(param_1 + 0x110,puVar19 + 0x12,local_408,local_2f8);
    FUN_1402011a0(param_2,uVar20);
    auVar41 = auVar46._0_16_;
    auVar39 = auVar44._0_16_;
    auVar37 = auVar42._0_16_;
    auVar34 = auVar40._0_16_;
    auVar32 = auVar38._0_16_;
    auVar30 = auVar35._0_16_;
    auVar26 = auVar33._0_16_;
    auVar23 = auVar31._0_16_;
    auVar22 = auVar27._0_16_;
  }
  pfVar18 = (float *)(param_1 + 0x80);
  if ((*(byte *)(param_1 + 0x2058) & 0x10) != 0) {
    _local_3b8 = *(undefined1 (*) [16])(param_3 + 0x44);
    auStack_3a8 = *(undefined1 (*) [16])(param_3 + 0x48);
    local_398 = *(undefined1 (*) [16])(param_3 + 0x4c);
    _auStack_388 = *(undefined1 (*) [16])(param_3 + 0x50);
    local_338 = *(ulonglong *)(param_3 + 0x54);
    uStack_330 = *(undefined8 *)(param_3 + 0x56);
    auStack_328 = *(undefined1 (*) [16])(param_3 + 0x58);
    local_318 = *(undefined8 *)(param_3 + 0x5c);
    uStack_310 = *(ulonglong *)(param_3 + 0x5e);
    _auStack_308 = *(undefined1 (*) [16])(param_3 + 0x60);
    local_408 = ZEXT816(0);
    auStack_3f8 = ZEXT816(0);
    local_3e8 = local_408;
    _auStack_3d8 = auStack_3f8;
    FUN_140202920(local_408);
    auVar22 = _auStack_3d8;
    fVar24 = (float)auStack_3d8._0_4_ + *(float *)(param_1 + 0x70);
    fVar8 = (float)auStack_3d8._4_4_ + *(float *)(param_1 + 0x74);
    auStack_3d8._0_4_ = fVar24;
    auVar23 = _auStack_3d8;
    fStack_3d0 = auVar22._8_4_;
    uStack_3cc = auVar22._12_4_;
    auStack_3d8 = auVar23._0_8_;
    fStack_3d0 = fStack_3d0 + *(float *)(param_1 + 0x78);
    auStack_3d8._4_4_ = fVar8;
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 5) {
        uVar20 = 0;
      }
      else {
        lVar13 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 4;
        puVar21 = *(undefined8 **)(*param_2 + 0x88);
        if (*(char *)(lVar13 + 0x21) == '\0') {
          *(undefined1 *)(lVar13 + 0x21) = 1;
          uVar20 = *(undefined8 *)(lVar13 + 0x10);
        }
        else {
          uVar20 = 0;
        }
        *puVar21 = 0x20000000;
        FUN_140197b30(puVar21,uVar20);
        puVar21[1] = 0;
      }
    }
    else {
      uVar20 = 0;
    }
    puVar21 = (undefined8 *)FUN_1401fc350(param_3,uVar20);
    *puVar21 = 0x50000000;
    FUN_140197b30(puVar21,&DAT_1402a5310);
    *(undefined4 *)(puVar21 + 1) = 0;
    *(undefined4 *)((longlong)puVar21 + 0xc) = 0x11000000;
    puVar21[2] = 0x50000000;
    uVar20 = FUN_140197b30(puVar21 + 2,&DAT_1402a76a0);
    *(undefined4 *)(puVar21 + 3) = 0x3000040;
    *(undefined4 *)((longlong)puVar21 + 0x1c) = 0x2000198;
    DAT_14030cab0 = 0x80;
    puVar21 = (undefined8 *)FUN_140157f40(uVar20,puVar21 + 4,local_3b8,&local_338);
    DAT_140328450._0_4_ = 0x83b;
    if ((*(char *)(param_1 + 0x2094) == '\x01') || (*(char *)(param_1 + 0x2094) == '\x02')) {
      local_3c8 = *(undefined8 ********)(param_3 + 0xc);
      uStack_3c0 = *(undefined8 *)(param_3 + 0xe);
      local_448 = (undefined8 *******)(param_1 + 0x80);
      puVar21 = (undefined8 *)FUN_140109dc0(param_1,puVar21,&local_3c8,param_1 + 0x70);
      if ((*(byte *)(*(longlong *)(param_1 + 0xff8) + 0xc) &
          (byte)(8 << (*(byte *)(param_1 + 0x279a) & 0x1f))) == 0) {
        local_3c8 = *(undefined8 ********)(param_1 + 0x80);
        uStack_3c0 = *(undefined8 *)(param_1 + 0x88);
        local_438 = *(undefined8 ********)(param_1 + 0x70);
        uStack_430 = *(undefined8 *)(param_1 + 0x78);
        local_428 = *(undefined1 (*) [16])(param_3 + 0xc);
        local_448 = &local_3c8;
        puVar21 = (undefined8 *)FUN_14010a2e0(param_1,puVar21,local_428,&local_438);
      }
    }
    if ((*(uint *)(param_1 + 0x2058) & 0x100000) != 0) {
      *puVar21 = 0x50000000;
      FUN_140197b30(puVar21,&DAT_140292e90);
      *(undefined4 *)(puVar21 + 1) = 0;
      *(undefined4 *)((longlong)puVar21 + 0xc) = 0x11000000;
      puVar21[2] = 0x50000000;
      uVar20 = FUN_140197b30(puVar21 + 2,&DAT_140292e80);
      *(undefined4 *)(puVar21 + 3) = 0x3000040;
      *(undefined4 *)((longlong)puVar21 + 0x1c) = 0x2000198;
      DAT_14030cab0 = 0x80;
      puVar21 = (undefined8 *)FUN_140157f40(uVar20,puVar21 + 4,local_3b8,&local_338);
      DAT_140328450._0_4_ = 0x81b;
    }
    uVar20 = FUN_140156d10(param_1 + 0x110,puVar21,local_408);
    FUN_1402011a0(param_2,uVar20);
    return;
  }
  local_338 = *(ulonglong *)(param_4 + 0x44);
  uStack_330 = *(undefined8 *)(param_4 + 0x46);
  auStack_328 = *(undefined1 (*) [16])(param_4 + 0x48);
  local_318 = *(undefined8 *)(param_4 + 0x4c);
  uStack_310 = *(ulonglong *)(param_4 + 0x4e);
  _auStack_308 = *(undefined1 (*) [16])(param_4 + 0x50);
  local_408 = *(undefined1 (*) [16])(param_4 + 0x54);
  auStack_3f8 = *(undefined1 (*) [16])(param_4 + 0x58);
  local_3e8 = *(undefined1 (*) [16])(param_4 + 0x5c);
  _auStack_3d8 = *(undefined1 (*) [16])(param_4 + 0x60);
  _local_3b8 = ZEXT816(0);
  auStack_3a8 = ZEXT816(0);
  local_3c8 = _DAT_1402d35f0;
  uStack_3c0 = _UNK_1402d35f8;
  if (*(short *)(param_1 + 0x1d90) != 0) {
    uStack_430 = *(undefined8 *)(param_1 + 0x88);
    local_438 = (undefined8 *******)
                CONCAT44(*(undefined4 *)(param_1 + 0x84),*pfVar18 + *(float *)(param_1 + 0x1da0));
    pfVar18 = (float *)&local_438;
  }
  auVar27 = ZEXT1664(auVar22);
  auVar31 = ZEXT1664(auVar23);
  auVar33 = ZEXT1664(auVar26);
  auVar35 = ZEXT1664(auVar30);
  auVar38 = ZEXT1664(auVar32);
  auVar40 = ZEXT1664(auVar34);
  auVar42 = ZEXT1664(auVar37);
  auVar44 = ZEXT1664(auVar39);
  auVar46 = ZEXT1664(auVar41);
  pppppppuVar29 = _DAT_1402d35f0;
  uVar20 = _UNK_1402d35f8;
  local_398 = _local_3b8;
  _auStack_388 = auStack_3a8;
  uVar14 = FUN_140202920(local_3b8,pfVar18);
  DAT_140328450._0_4_ = 0x3b;
  if (*(char *)(param_1 + 0x2094) == '\x01') {
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 5) {
        puVar19 = (undefined8 *)0x0;
      }
      else {
        lVar17 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 4;
        puVar21 = *(undefined8 **)(*param_2 + 0x88);
        if (*(char *)(lVar17 + 0x21) == '\0') {
          *(undefined1 *)(lVar17 + 0x21) = 1;
          puVar19 = *(undefined8 **)(lVar17 + 0x10);
        }
        else {
          puVar19 = (undefined8 *)0x0;
        }
        *puVar21 = 0x20000000;
        uVar14 = FUN_140197b30(puVar21,puVar19);
        puVar21[1] = 0;
      }
    }
    else {
      puVar19 = (undefined8 *)0x0;
    }
    if (((byte)DAT_14032844c & 1) != 0) {
      if ((*(byte *)(param_1 + 0x5a8) & 0x10) != 0) {
        puVar19 = (undefined8 *)FUN_140158d00(uVar14,puVar19);
      }
      puVar19 = (undefined8 *)FUN_1401fc350(param_4,puVar19);
    }
    *puVar19 = 0x50000000;
    FUN_140197b30(puVar19,&DAT_140292e90);
    *(undefined4 *)(puVar19 + 1) = 0;
    *(undefined4 *)((longlong)puVar19 + 0xc) = 0x11000000;
    puVar19[2] = 0x50000000;
    uVar14 = FUN_140197b30(puVar19 + 2,&DAT_140292e80);
    *(undefined4 *)(puVar19 + 3) = 0x3000040;
    *(undefined4 *)((longlong)puVar19 + 0x1c) = 0x2000198;
    DAT_14030cab0 = 0x80;
    puVar21 = (undefined8 *)FUN_140157f40(uVar14,puVar19 + 4,&local_338,local_408);
  }
  else {
    if (*(char *)(param_1 + 0x2094) != '\x02') {
      DAT_140328450._0_4_ = 0x3b;
      return;
    }
    fVar24 = (float)DAT_1402d3530;
    auVar22._0_4_ = fVar24 * *(float *)(param_1 + 0x1cc8);
    auVar22._4_4_ = DAT_1402d3530._4_4_ * *(float *)(param_1 + 0x1ccc);
    auVar22._8_4_ = DAT_1402d3530._8_4_ * *(float *)(param_1 + 0x1cd0);
    auVar22._12_4_ = DAT_1402d3530._12_4_ * *(float *)(param_1 + 0x1cd4);
    *(float *)(param_1 + 0xd90) = fVar24 * *(float *)(param_1 + 0x1cd8);
    *(float *)(param_1 + 0xd94) = fVar24 * *(float *)(param_1 + 0x1cdc);
    *(undefined1 (*) [16])(param_1 + 0xd80) = auVar22;
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 5) {
        uVar14 = 0;
      }
      else {
        lVar17 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 4;
        puVar21 = *(undefined8 **)(*param_2 + 0x88);
        if (*(char *)(lVar17 + 0x21) == '\0') {
          *(undefined1 *)(lVar17 + 0x21) = 1;
          uVar14 = *(undefined8 *)(lVar17 + 0x10);
        }
        else {
          uVar14 = 0;
        }
        *puVar21 = 0x20000000;
        FUN_140197b30(puVar21,uVar14);
        puVar21[1] = 0;
      }
    }
    else {
      uVar14 = 0;
    }
    uVar14 = FUN_1401fc350(param_4,uVar14);
    local_448 = (undefined8 *******)CONCAT44(local_448._4_4_,*(undefined4 *)(param_1 + 0x1d44));
    puVar21 = (undefined8 *)FUN_1401580c0(param_1 + 0x110,uVar14,&local_338,local_408);
    *puVar21 = 0x10000002;
    FUN_140197b30(puVar21,0);
    *(undefined4 *)(puVar21 + 1) = 0x20000000;
    *(undefined4 *)((longlong)puVar21 + 0xc) = 0xcfcfcfcf;
    puVar21[2] = 0x70030020;
    puVar21[3] = 0;
    *(undefined4 *)(puVar21 + 4) = 0x68010026;
    *(undefined4 *)((longlong)puVar21 + 0x24) = DAT_14030f7e0;
    *(undefined4 *)(puVar21 + 5) = DAT_14030f7e4;
    *(undefined4 *)((longlong)puVar21 + 0x2c) = DAT_14030f7e8;
    uVar14 = FUN_14015e8a0(param_1 + 0x420,puVar21 + 6,local_3b8);
    FUN_1402011a0(param_2,uVar14);
    if (*(int *)((longlong)param_2 + 0xc) == -1) {
      if ((int)param_2[1] < 0xb) {
        uVar14 = 0;
      }
      else {
        lVar17 = param_2[3];
        *(undefined4 *)((longlong)param_2 + 0xc) = 10;
        puVar21 = *(undefined8 **)(*param_2 + 0x148);
        if (*(char *)(lVar17 + 0x21) == '\0') {
          *(undefined1 *)(lVar17 + 0x21) = 1;
          uVar14 = *(undefined8 *)(lVar17 + 0x10);
        }
        else {
          uVar14 = 0;
        }
        *puVar21 = 0x20000000;
        FUN_140197b30(puVar21,uVar14);
        puVar21[1] = 0;
      }
    }
    else {
      uVar14 = 0;
    }
    uVar14 = FUN_1401fc350(param_4,uVar14);
    local_448 = (undefined8 *******)CONCAT44(local_448._4_4_,*(undefined4 *)(param_1 + 0x1d44));
    puVar21 = (undefined8 *)FUN_1401580c0(param_1 + 0x110,uVar14,&local_338,local_408);
  }
  local_78 = auVar31._0_16_;
  local_a8 = auVar38._0_16_;
  local_98 = auVar35._0_16_;
  local_88 = auVar33._0_16_;
  if ((*(char *)(param_1 + 0x2094) == '\x01') || (*(char *)(param_1 + 0x2094) == '\x02')) {
    local_438 = *(undefined8 ********)(param_4 + 0xc);
    uStack_430 = *(undefined8 *)(param_4 + 0xe);
    local_448 = (undefined8 *******)(param_1 + 0x80);
    puVar21 = (undefined8 *)FUN_140109dc0(param_1,puVar21,&local_438,&local_3c8);
    local_78 = auVar31._0_16_;
    local_a8 = auVar38._0_16_;
    local_98 = auVar35._0_16_;
    local_88 = auVar33._0_16_;
    if ((*(byte *)(*(longlong *)(param_1 + 0xff8) + 0xc) &
        (byte)(8 << (*(byte *)(param_1 + 0x279a) & 0x1f))) == 0) {
      local_3c8 = *(undefined8 ********)(param_1 + 0x80);
      uStack_3c0 = *(undefined8 *)(param_1 + 0x88);
      local_428 = *(undefined1 (*) [16])(param_4 + 0xc);
      local_448 = &local_3c8;
      local_438 = pppppppuVar29;
      uStack_430 = uVar20;
      puVar21 = (undefined8 *)FUN_14010a2e0(param_1,puVar21,local_428,&local_438);
      local_78 = auVar31._0_16_;
      local_a8 = auVar38._0_16_;
      local_98 = auVar35._0_16_;
      local_88 = auVar33._0_16_;
    }
  }
  if (*(char *)(param_1 + 0x2094) == '\x01') {
    DAT_140328450._0_4_ = (uint)DAT_140328450 | 0x800;
    puVar21 = (undefined8 *)FUN_140156d10(param_1 + 0x110,puVar21,local_3b8);
    if (((byte)DAT_14032844c & 1) != 0) {
      local_b8 = auVar40._0_16_;
      local_c8 = auVar42._0_16_;
      local_d8 = auVar44._0_16_;
      local_e8 = auVar46._0_16_;
      pfVar18 = param_4;
      pfVar12 = &local_2b8;
      do {
        pfVar16 = pfVar12;
        pfVar15 = pfVar18;
        uVar9 = *(undefined8 *)(pfVar15 + 2);
        uVar10 = *(undefined8 *)(pfVar15 + 4);
        uVar11 = *(undefined8 *)(pfVar15 + 6);
        uVar20 = *(undefined8 *)(pfVar15 + 0x1c);
        uVar14 = *(undefined8 *)(pfVar15 + 0x1e);
        *(undefined8 *)pfVar16 = *(undefined8 *)pfVar15;
        *(undefined8 *)(pfVar16 + 2) = uVar9;
        *(undefined8 *)(pfVar16 + 4) = uVar10;
        *(undefined8 *)(pfVar16 + 6) = uVar11;
        uVar9 = *(undefined8 *)(pfVar15 + 10);
        uVar10 = *(undefined8 *)(pfVar15 + 0xc);
        uVar11 = *(undefined8 *)(pfVar15 + 0xe);
        *(undefined8 *)(pfVar16 + 8) = *(undefined8 *)(pfVar15 + 8);
        *(undefined8 *)(pfVar16 + 10) = uVar9;
        *(undefined8 *)(pfVar16 + 0xc) = uVar10;
        *(undefined8 *)(pfVar16 + 0xe) = uVar11;
        uVar9 = *(undefined8 *)(pfVar15 + 0x12);
        uVar10 = *(undefined8 *)(pfVar15 + 0x14);
        uVar11 = *(undefined8 *)(pfVar15 + 0x16);
        *(undefined8 *)(pfVar16 + 0x10) = *(undefined8 *)(pfVar15 + 0x10);
        *(undefined8 *)(pfVar16 + 0x12) = uVar9;
        *(undefined8 *)(pfVar16 + 0x14) = uVar10;
        *(undefined8 *)(pfVar16 + 0x16) = uVar11;
        uVar9 = *(undefined8 *)(pfVar15 + 0x1a);
        *(undefined8 *)(pfVar16 + 0x18) = *(undefined8 *)(pfVar15 + 0x18);
        *(undefined8 *)(pfVar16 + 0x1a) = uVar9;
        *(undefined8 *)(pfVar16 + 0x1c) = uVar20;
        *(undefined8 *)(pfVar16 + 0x1e) = uVar14;
        lVar13 = lVar13 + -1;
        pfVar18 = pfVar15 + 0x20;
        pfVar12 = pfVar16 + 0x20;
      } while (lVar13 != 0);
      uVar20 = *(undefined8 *)(pfVar15 + 0x22);
      uVar14 = *(undefined8 *)(pfVar15 + 0x24);
      uVar9 = *(undefined8 *)(pfVar15 + 0x26);
      fStack_2b4 = auVar27._0_4_;
      fStack_2b0 = fStack_2b4 * param_4[2];
      local_2b8 = fStack_2b4 * *param_4;
      *(undefined8 *)(pfVar16 + 0x20) = *(undefined8 *)(pfVar15 + 0x20);
      *(undefined8 *)(pfVar16 + 0x22) = uVar20;
      *(undefined8 *)(pfVar16 + 0x24) = uVar14;
      *(undefined8 *)(pfVar16 + 0x26) = uVar9;
      uVar20 = *(undefined8 *)(pfVar15 + 0x2a);
      uVar14 = *(undefined8 *)(pfVar15 + 0x2c);
      uVar9 = *(undefined8 *)(pfVar15 + 0x2e);
      uStack_2a4 = *(undefined2 *)(param_4 + 5);
      *(undefined8 *)(pfVar16 + 0x28) = *(undefined8 *)(pfVar15 + 0x28);
      *(undefined8 *)(pfVar16 + 0x2a) = uVar20;
      *(undefined8 *)(pfVar16 + 0x2c) = uVar14;
      *(undefined8 *)(pfVar16 + 0x2e) = uVar9;
      fStack_2b4 = fStack_2b4 * param_4[1];
      local_118 = local_118 | 3;
      uStack_2a2 = *(undefined2 *)((longlong)param_4 + 0x16);
      sStack_2a0 = *(short *)(param_4 + 6) / 2;
      sStack_29e = *(short *)((longlong)param_4 + 0x1a) / 2;
      uStack_294 = *(undefined2 *)(param_4 + 9);
      fStack_2ac = param_4[3];
      uStack_292 = *(undefined2 *)((longlong)param_4 + 0x26);
      fStack_2a8 = param_4[4];
      fStack_28c = param_4[0xb];
      uStack_290 = *(undefined2 *)(param_4 + 10);
      local_298 = param_4[8];
      fStack_29c = param_4[7];
      uStack_28e = *(undefined2 *)((longlong)param_4 + 0x2a);
      FUN_1401fbec0(&local_2b8);
      *puVar21 = 0x10000004;
      FUN_140197b30(puVar21,0);
      local_338 = (ulonglong)DAT_1402d22d0;
      local_318 = 0;
      _auStack_308 = ZEXT812(0);
      uStack_330 = 0;
      auStack_328 = ZEXT416(DAT_1402d22d0) << 0x20;
      uStack_310 = (ulonglong)DAT_1402d22d0;
      uStack_2fc = DAT_1402d22d0;
      local_378 = uStack_1a8;
      uStack_370 = uStack_1a0;
      uStack_368 = local_198;
      uStack_360 = uStack_190;
      local_358 = uStack_188;
      uStack_350 = uStack_180;
      uStack_348 = uStack_178;
      uStack_340 = uStack_170;
      *(undefined4 *)(puVar21 + 1) = 0x11000000;
      *(undefined4 *)((longlong)puVar21 + 0xc) = 0x6c044010;
      FUN_140005940(&local_378,&local_378,&local_338);
      puVar21[2] = local_378;
      puVar21[3] = uStack_370;
      puVar21[4] = uStack_368;
      puVar21[5] = uStack_360;
      puVar21[6] = local_358;
      puVar21[7] = uStack_350;
      puVar21[8] = uStack_348;
      puVar21[9] = uStack_340;
      puVar21[10] = 0x50000000;
      FUN_140197b30(puVar21 + 10,&DAT_140293f20);
      *(undefined4 *)(puVar21 + 0xb) = 0;
      *(undefined4 *)((longlong)puVar21 + 0x5c) = 0x11000000;
      puVar21[0xc] = 0x50000000;
      FUN_140197b30(puVar21 + 0xc,&DAT_140293f10);
      *(undefined4 *)(puVar21 + 0xd) = 0x3000030;
      *(undefined4 *)((longlong)puVar21 + 0x6c) = 0x20001e0;
      DAT_140328450._0_4_ = 0;
      puVar21 = (undefined8 *)FUN_140156eb0(param_1 + 0x110,puVar21 + 0xe,local_3b8);
    }
  }
  else if (*(char *)(param_1 + 0x2094) == '\x02') {
    puVar21 = (undefined8 *)FUN_14014ca50(param_1 + 0x940,puVar21);
    fVar24 = *(float *)(param_1 + 0xd70);
    fVar8 = *(float *)(param_1 + 0xd7c);
    fVar1 = *(float *)(param_1 + 0xd78);
    fVar2 = *(float *)(param_1 + 0xd74);
    fVar36 = fVar2 * auStack_3a8._0_4_ + fVar24 * (float)local_3b8._0_4_ +
             fVar1 * local_398._0_4_ + fVar8 * (float)auStack_388._0_4_;
    auVar22 = vshufps_avx(local_398,local_398,0x55);
    auVar23 = vshufps_avx(auStack_3a8,auStack_3a8,0x55);
    auVar26 = vshufps_avx(local_398,local_398,0xaa);
    fVar28 = fVar2 * auVar23._0_4_ + fVar24 * (float)local_3b8._4_4_ +
             fVar1 * auVar22._0_4_ + fVar8 * (float)auStack_388._4_4_;
    auVar22 = vshufps_avx(auStack_3a8,auStack_3a8,0xaa);
    *puVar21 = 0x10000002;
    fVar24 = fVar2 * auVar22._0_4_ + fVar24 * fStack_3b0 +
             fVar1 * auVar26._0_4_ + fVar8 * fStack_380;
    FUN_140197b30(puVar21,0);
    *(float *)((longlong)puVar21 + 0x14) = fVar36;
    *(float *)(puVar21 + 3) = fVar28;
    *(float *)((longlong)puVar21 + 0x1c) = fVar24;
    *(undefined4 *)(puVar21 + 1) = 0x20000000;
    *(undefined4 *)((longlong)puVar21 + 0xc) = 0xcfcfcfcf;
    *(undefined4 *)(puVar21 + 2) = 0x70030020;
    *(undefined4 *)(puVar21 + 4) = 0x68010026;
    *(undefined4 *)((longlong)puVar21 + 0x24) = DAT_14030f7e0;
    *(undefined4 *)(puVar21 + 5) = DAT_14030f7e4;
    *(undefined4 *)((longlong)puVar21 + 0x2c) = DAT_14030f7e8;
    puVar21 = (undefined8 *)FUN_14015e8a0(param_1 + 800,puVar21 + 6,local_3b8);
  }
  uVar20 = FUN_14010f220(param_1,puVar21,param_4);
  FUN_1402011a0(param_2,uVar20);
  return;
}

