/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d2580; RVA 0xd2580
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d2580(longlong param_1)

{
  int iVar1;
  undefined1 (*pauVar2) [16];
  undefined4 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  char cVar6;
  undefined1 uVar7;
  ushort uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined8 *puVar15;
  undefined1 uVar16;
  uint uVar17;
  undefined1 uVar18;
  char cVar19;
  int iVar20;
  longlong *plVar21;
  longlong lVar22;
  undefined8 *puVar23;
  int iVar24;
  byte bVar25;
  uint uVar26;
  ulonglong uVar27;
  int iVar28;
  uint uVar29;
  longlong lVar30;
  longlong *plVar31;
  longlong lVar32;
  bool bVar33;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  undefined8 extraout_XMM0_Qa_04;
  undefined1 extraout_var [56];
  undefined1 auVar34 [16];
  float fVar35;
  undefined1 auVar36 [64];
  undefined1 auVar37 [64];
  undefined1 auVar38 [64];
  undefined1 auVar39 [64];
  undefined1 auVar40 [64];
  undefined1 auVar41 [64];
  undefined1 auVar42 [64];
  undefined1 auVar43 [64];
  undefined1 auVar44 [64];
  undefined1 auStack_2e8 [32];
  undefined1 *local_2c8;
  undefined8 *local_2c0;
  int local_2a8;
  int local_2a4;
  longlong local_2a0;
  longlong local_298;
  longlong local_290;
  longlong local_288;
  longlong local_280;
  longlong local_278;
  longlong local_270;
  int local_268 [4];
  longlong local_258;
  undefined1 local_248 [16];
  undefined1 local_238 [16];
  longlong local_228;
  longlong *local_220;
  longlong *local_218;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined1 local_1b8 [16];
  undefined1 local_1a8 [16];
  undefined1 local_198 [16];
  undefined1 local_188 [16];
  undefined8 local_178;
  undefined8 uStack_170;
  undefined1 local_168 [16];
  ulonglong local_c8;
  
  local_c8 = DAT_140309040 ^ (ulonglong)auStack_2e8;
  lVar11 = (longlong)*(char *)(param_1 + 0xa8829);
  local_280 = lVar11 * 5000 + *(longlong *)(param_1 + 0x67130);
  lVar32 = lVar11 * 0xd10 + *(longlong *)(param_1 + 0x67138);
  local_228 = *(longlong *)(param_1 + 0x67178) + lVar11 * 0x28;
  local_290 = lVar32;
  FUN_140201a40(0,1,1);
  FUN_140201a40(1,7,3);
  if (*(int *)(param_1 + 0x67230) != 1) {
    FUN_140201a40(0,0,2);
    FUN_140201a40(2,7,4);
  }
  cVar6 = FUN_1400c5bc0();
  lVar11 = DAT_14032c8b0;
  if (cVar6 == '\x02') {
    uVar12 = FUN_140201120(DAT_14032c8b0 + 0x30,0);
    if ((*(longlong *)(param_1 + 0xa8270) != 0) && (*(char *)(param_1 + 0xa891c) == '\0')) {
      if (*(char *)(param_1 + 0xa891e) == '\0') {
        uVar13 = FUN_14017f520(extraout_XMM0_Qa,*(undefined1 *)(param_1 + 0xa891d),uVar12);
        plVar31 = *(longlong **)(param_1 + 0xa8278);
        uVar12 = extraout_XMM0_Qa_00;
        if (plVar31 != (longlong *)0x0) {
          lVar32 = FUN_140181690();
          bVar33 = 0 < *(int *)(lVar32 + 0x584);
          if ((bVar33 == (bool)*(char *)((longlong)plVar31 + 0x21)) ||
             ((*(byte *)((longlong)plVar31 + 0x1e) & 1) != 0)) {
            *(bool *)((longlong)plVar31 + 0x21) = bVar33;
            (**(code **)(*plVar31 + 0x40))(plVar31);
          }
          cVar6 = FUN_14017f630();
          uVar12 = extraout_XMM0_Qa_01;
          if (cVar6 != '\0') {
            plVar31 = *(longlong **)(param_1 + 0xa8278);
            pcVar4 = *(code **)(*plVar31 + 0x10);
            lVar32 = FUN_140189320();
            auVar34._0_4_ = (float)*(int *)(lVar32 + 0xc);
            auVar34._4_12_ = SUB1612(ZEXT816(0),4);
            (*pcVar4)(plVar31,auVar34._0_8_);
            plVar31 = *(longlong **)(param_1 + 0xa8278);
            pcVar4 = *(code **)(*plVar31 + 8);
            lVar32 = FUN_140181690();
            lVar14 = FUN_140181690();
            uVar13 = (*pcVar4)(plVar31,uVar13,*(int *)(lVar14 + 0x510) + 0x700,lVar32 + 0x5b0);
            uVar12 = extraout_XMM0_Qa_02;
          }
        }
        uVar12 = FUN_14017f550(uVar12,uVar13);
        FUN_140181690();
        lVar32 = FUN_140181690();
        if (*(int *)(lVar32 + 0x5ac) == 3) {
          *(undefined1 *)(param_1 + 0xa891c) = 1;
        }
      }
      else {
        cVar6 = (**(code **)(**(longlong **)(param_1 + 0xa8278) + 0x20))();
        if (cVar6 != '\0') {
          *(undefined1 *)(param_1 + 0xa891e) = 0;
        }
      }
    }
    lVar32 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if ((lVar32 != 0) && (*(char *)(lVar32 + 0x3cc) == '\x02')) {
      uVar12 = FUN_1400ce700(param_1,uVar12);
    }
    FUN_1402011a0(lVar11 + 0x30,uVar12);
    return;
  }
  local_268[0] = 1;
  local_268[1] = 2;
  local_268[2] = 3;
  local_268[3] = 4;
  if ((*(int *)(param_1 + 0x67230) == 2) && (FUN_14020ea20(0xffffffff,0), DAT_14030cab8 != -1)) {
    FUN_14020e000();
    FUN_14020e490();
  }
  local_2a4 = 0;
  if (*(int *)(param_1 + 0x67230) < 1) {
    return;
  }
  local_220 = (longlong *)(param_1 + 0x89678);
  auVar38 = ZEXT464(DAT_1402d2ebc);
  auVar39 = ZEXT464(DAT_1402d1db0);
  auVar40 = ZEXT464(DAT_1402d25d0);
  auVar41 = ZEXT464(DAT_1402d22d0);
  auVar42 = ZEXT464(DAT_1402d1dc4);
  auVar43 = ZEXT464(DAT_1402d1e40);
  auVar44 = ZEXT464(DAT_1402d2350);
  local_270 = 0;
  local_298 = 0x20;
  do {
    lVar14 = local_270;
    lVar11 = 0;
    if (local_2a4 < 4) {
      lVar22 = *(longlong *)(param_1 + 0x67210 + local_270 * 8);
      lVar30 = *(longlong *)(param_1 + 0x671f0 + local_270 * 8);
    }
    else {
      lVar22 = lVar11;
      lVar30 = lVar11;
    }
    if (*(byte *)(param_1 + 0xa87e4) < 2) {
      uVar7 = *(undefined1 *)(param_1 + 0x234);
      uVar16 = *(undefined1 *)(param_1 + 0x230);
      *(undefined1 *)(lVar30 + 0x1a8) = *(undefined1 *)(param_1 + 0x228);
      *(undefined1 *)(lVar30 + 0x1a9) = uVar16;
      *(undefined1 *)(lVar30 + 0x1aa) = uVar7;
      uVar7 = *(undefined1 *)(param_1 + 0x234);
      uVar16 = *(undefined1 *)(param_1 + 0x230);
      uVar18 = *(undefined1 *)(param_1 + 0x228);
    }
    else {
      uVar7 = 0;
      *(undefined2 *)(lVar30 + 0x1a8) = 1;
      uVar16 = 0;
      *(undefined1 *)(lVar30 + 0x1aa) = 0;
      uVar18 = 1;
    }
    *(undefined1 *)(lVar22 + 0x1a8) = uVar18;
    *(undefined1 *)(lVar22 + 0x1a9) = uVar16;
    *(undefined1 *)(lVar22 + 0x1aa) = uVar7;
    local_288 = lVar30;
    local_278 = lVar22;
    FUN_1401fbec0(lVar30);
    FUN_1401fbec0(lVar22);
    plVar31 = (longlong *)((longlong)local_268[lVar14] * 0x30 + DAT_14032c8b0);
    local_258 = (longlong)local_268[lVar14 + 2] * 0x30 + DAT_14032c8b0;
    local_218 = plVar31;
    if ((*(int *)((longlong)plVar31 + 0xc) == -1) && (0 < (int)plVar31[1])) {
      lVar14 = plVar31[3];
      *(undefined4 *)((longlong)plVar31 + 0xc) = 0;
      puVar15 = *(undefined8 **)(*plVar31 + 8);
      if (*(char *)(lVar14 + 0x21) == '\0') {
        *(undefined1 *)(lVar14 + 0x21) = 1;
        lVar11 = *(longlong *)(lVar14 + 0x10);
      }
      *puVar15 = 0x20000000;
      FUN_140197b30(puVar15,lVar11);
      puVar15[1] = 0;
    }
    local_2a0 = 8;
    puVar15 = (undefined8 *)FUN_1401fc350(lVar30,lVar11);
    if (*(int *)((longlong)plVar31 + 0xc) != -1) {
      *(undefined8 **)((longlong)*(int *)((longlong)plVar31 + 0xc) * 0x20 + 8 + *plVar31) = puVar15;
      uVar12 = *(undefined8 *)((longlong)*(int *)((longlong)plVar31 + 0xc) * 0x20 + 0x10 + *plVar31)
      ;
      *puVar15 = 0x20000000;
      FUN_140197b30(puVar15,uVar12);
      puVar15[1] = 0;
      lVar11 = plVar31[3];
      *(undefined4 *)((longlong)plVar31 + 0xc) = 0xffffffff;
      if (*(char *)(lVar11 + 0x21) != '\0') {
        *(undefined1 *)(lVar11 + 0x21) = 0;
        *(undefined8 **)(lVar11 + 0x10) = puVar15 + 2;
      }
    }
    FUN_140080940(lVar32);
    lVar11 = local_280;
    uVar9 = *(undefined4 *)(lVar32 + 0xc8c);
    uVar10 = *(undefined4 *)(lVar32 + 0xc88);
    *(undefined4 *)(local_280 + 0x298) = uVar10;
    *(undefined4 *)(local_280 + 0x294) = uVar9;
    *(longlong *)(local_280 + 0x280) = lVar30;
    *(undefined4 *)(local_280 + 0x18) = *(undefined4 *)(lVar30 + 0x30);
    *(undefined4 *)(local_280 + 0x1c) = *(undefined4 *)(lVar30 + 0x34);
    *(undefined4 *)(local_280 + 0x20) = *(undefined4 *)(lVar30 + 0x38);
    *(undefined4 *)(local_280 + 0x24) = *(undefined4 *)(lVar30 + 0x3c);
    *(undefined4 *)(local_280 + 0x28) = *(undefined4 *)(lVar30 + 0x40);
    *(undefined4 *)(local_280 + 0x2c) = *(undefined4 *)(lVar30 + 0x44);
    *(undefined4 *)(local_280 + 0x30) = *(undefined4 *)(lVar30 + 0x48);
    *(undefined4 *)(local_280 + 0x34) = *(undefined4 *)(lVar30 + 0x4c);
    *(undefined4 *)(local_280 + 0x288) = *(undefined4 *)(lVar30 + 0x198);
    *(undefined4 *)(local_280 + 0x28c) = *(undefined4 *)(lVar30 + 0x19c);
    uVar3 = *(undefined4 *)(lVar30 + 8);
    *(undefined4 *)(local_280 + 0x29c) = uVar9;
    *(undefined4 *)(local_280 + 0x2a0) = uVar10;
    *(undefined4 *)(local_280 + 0x290) = uVar3;
    *(undefined4 *)(lVar30 + 0x2c) = uVar9;
    FUN_1401fbec0(lVar30);
    uVar12 = *(undefined8 *)(lVar30 + 0x158);
    uVar13 = *(undefined8 *)(lVar30 + 0x160);
    uVar5 = *(undefined8 *)(lVar30 + 0x168);
    *(undefined8 *)(lVar11 + 0x38) = *(undefined8 *)(lVar30 + 0x150);
    *(undefined8 *)(lVar11 + 0x40) = uVar12;
    *(undefined8 *)(lVar11 + 0x48) = uVar13;
    *(undefined8 *)(lVar11 + 0x50) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0x178);
    uVar13 = *(undefined8 *)(lVar30 + 0x180);
    uVar5 = *(undefined8 *)(lVar30 + 0x188);
    *(undefined8 *)(lVar11 + 0x58) = *(undefined8 *)(lVar30 + 0x170);
    *(undefined8 *)(lVar11 + 0x60) = uVar12;
    *(undefined8 *)(lVar11 + 0x68) = uVar13;
    *(undefined8 *)(lVar11 + 0x70) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0x118);
    uVar13 = *(undefined8 *)(lVar30 + 0x120);
    uVar5 = *(undefined8 *)(lVar30 + 0x128);
    *(undefined8 *)(lVar11 + 0x78) = *(undefined8 *)(lVar30 + 0x110);
    *(undefined8 *)(lVar11 + 0x80) = uVar12;
    *(undefined8 *)(lVar11 + 0x88) = uVar13;
    *(undefined8 *)(lVar11 + 0x90) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0x138);
    uVar13 = *(undefined8 *)(lVar30 + 0x140);
    uVar5 = *(undefined8 *)(lVar30 + 0x148);
    *(undefined8 *)(lVar11 + 0x98) = *(undefined8 *)(lVar30 + 0x130);
    *(undefined8 *)(lVar11 + 0xa0) = uVar12;
    *(undefined8 *)(lVar11 + 0xa8) = uVar13;
    *(undefined8 *)(lVar11 + 0xb0) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0xd8);
    uVar13 = *(undefined8 *)(lVar30 + 0xe0);
    uVar5 = *(undefined8 *)(lVar30 + 0xe8);
    *(undefined8 *)(lVar11 + 0x138) = *(undefined8 *)(lVar30 + 0xd0);
    *(undefined8 *)(lVar11 + 0x140) = uVar12;
    *(undefined8 *)(lVar11 + 0x148) = uVar13;
    *(undefined8 *)(lVar11 + 0x150) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0xf8);
    uVar13 = *(undefined8 *)(lVar30 + 0x100);
    uVar5 = *(undefined8 *)(lVar30 + 0x108);
    *(undefined8 *)(lVar11 + 0x158) = *(undefined8 *)(lVar30 + 0xf0);
    *(undefined8 *)(lVar11 + 0x160) = uVar12;
    *(undefined8 *)(lVar11 + 0x168) = uVar13;
    *(undefined8 *)(lVar11 + 0x170) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0x98);
    uVar13 = *(undefined8 *)(lVar30 + 0xa0);
    uVar5 = *(undefined8 *)(lVar30 + 0xa8);
    *(undefined8 *)(lVar11 + 0x178) = *(undefined8 *)(lVar30 + 0x90);
    *(undefined8 *)(lVar11 + 0x180) = uVar12;
    *(undefined8 *)(lVar11 + 0x188) = uVar13;
    *(undefined8 *)(lVar11 + 400) = uVar5;
    uVar12 = *(undefined8 *)(lVar30 + 0xb8);
    uVar13 = *(undefined8 *)(lVar30 + 0xc0);
    uVar5 = *(undefined8 *)(lVar30 + 200);
    local_1b8 = ZEXT816(0);
    *(undefined8 *)(lVar11 + 0x198) = *(undefined8 *)(lVar30 + 0xb0);
    *(undefined8 *)(lVar11 + 0x1a0) = uVar12;
    *(undefined8 *)(lVar11 + 0x1a8) = uVar13;
    *(undefined8 *)(lVar11 + 0x1b0) = uVar5;
    local_1a8 = ZEXT816(0);
    local_238 = *(undefined1 (*) [16])(lVar11 + 0x28);
    auVar38 = ZEXT1664(auVar38._0_16_);
    auVar39 = ZEXT1664(auVar39._0_16_);
    auVar40 = ZEXT1664(auVar40._0_16_);
    auVar41 = ZEXT1664(auVar41._0_16_);
    auVar42 = ZEXT1664(auVar42._0_16_);
    auVar43 = ZEXT1664(auVar43._0_16_);
    auVar44 = ZEXT1664(auVar44._0_16_);
    local_198 = local_1b8;
    local_188 = local_1a8;
    FUN_140202920(local_1b8,local_238);
    FUN_14003a2e0(local_1b8);
    local_1f8 = *(undefined8 *)(lVar11 + 0x178);
    uStack_1f0 = *(undefined8 *)(lVar11 + 0x180);
    uStack_1e8 = *(undefined8 *)(lVar11 + 0x188);
    uStack_1e0 = *(undefined8 *)(lVar11 + 400);
    local_1d8 = *(undefined8 *)(lVar11 + 0x198);
    uStack_1d0 = *(undefined8 *)(lVar11 + 0x1a0);
    uStack_1c8 = *(undefined8 *)(lVar11 + 0x1a8);
    uStack_1c0 = *(undefined8 *)(lVar11 + 0x1b0);
    auVar38 = ZEXT1664(auVar38._0_16_);
    auVar39 = ZEXT1664(auVar39._0_16_);
    auVar40 = ZEXT1664(auVar40._0_16_);
    auVar41 = ZEXT1664(auVar41._0_16_);
    auVar42 = ZEXT1664(auVar42._0_16_);
    auVar43 = ZEXT1664(auVar43._0_16_);
    auVar44 = ZEXT1664(auVar44._0_16_);
    FUN_140005940(&local_1f8,&local_1f8,local_1b8);
    *(undefined8 *)(lVar11 + 0xf8) = local_1f8;
    *(undefined8 *)(lVar11 + 0x100) = uStack_1f0;
    *(undefined8 *)(lVar11 + 0x108) = uStack_1e8;
    *(undefined8 *)(lVar11 + 0x110) = uStack_1e0;
    *(undefined8 *)(lVar11 + 0x118) = local_1d8;
    *(undefined8 *)(lVar11 + 0x120) = uStack_1d0;
    *(undefined8 *)(lVar11 + 0x128) = uStack_1c8;
    *(undefined8 *)(lVar11 + 0x130) = uStack_1c0;
    local_1f8 = *(undefined8 *)(lVar11 + 0x138);
    uStack_1f0 = *(undefined8 *)(lVar11 + 0x140);
    uStack_1e8 = *(undefined8 *)(lVar11 + 0x148);
    uStack_1e0 = *(undefined8 *)(lVar11 + 0x150);
    local_1d8 = *(undefined8 *)(lVar11 + 0x158);
    uStack_1d0 = *(undefined8 *)(lVar11 + 0x160);
    uStack_1c8 = *(undefined8 *)(lVar11 + 0x168);
    uStack_1c0 = *(undefined8 *)(lVar11 + 0x170);
    auVar38 = ZEXT1664(auVar38._0_16_);
    auVar39 = ZEXT1664(auVar39._0_16_);
    auVar40 = ZEXT1664(auVar40._0_16_);
    auVar41 = ZEXT1664(auVar41._0_16_);
    auVar42 = ZEXT1664(auVar42._0_16_);
    auVar43 = ZEXT1664(auVar43._0_16_);
    auVar44 = ZEXT1664(auVar44._0_16_);
    FUN_140005940(&local_1f8,&local_1f8,local_1b8);
    *(undefined8 *)(lVar11 + 0xb8) = local_1f8;
    *(undefined8 *)(lVar11 + 0xc0) = uStack_1f0;
    *(undefined8 *)(lVar11 + 200) = uStack_1e8;
    *(undefined8 *)(lVar11 + 0xd0) = uStack_1e0;
    *(undefined8 *)(lVar11 + 0xd8) = local_1d8;
    *(undefined8 *)(lVar11 + 0xe0) = uStack_1d0;
    *(undefined8 *)(lVar11 + 0xe8) = uStack_1c8;
    *(undefined8 *)(lVar11 + 0xf0) = uStack_1c0;
    auVar38 = ZEXT1664(auVar38._0_16_);
    auVar39 = ZEXT1664(auVar39._0_16_);
    auVar40 = ZEXT1664(auVar40._0_16_);
    auVar41 = ZEXT1664(auVar41._0_16_);
    auVar42 = ZEXT1664(auVar42._0_16_);
    auVar43 = ZEXT1664(auVar43._0_16_);
    auVar44 = ZEXT1664(auVar44._0_16_);
    uVar9 = FUN_1400804a0(lVar32);
    fVar35 = auVar44._0_4_ * *(float *)(lVar11 + 0x29c);
    *(undefined4 *)(lVar11 + 0x2a4) = uVar9;
    *(float *)(lVar11 + 0x2b8) = *(float *)(lVar11 + 0x18) - fVar35;
    *(float *)(lVar11 + 700) = *(float *)(lVar11 + 0x20) - fVar35;
    *(float *)(lVar11 + 0x2c0) = *(float *)(lVar11 + 0x18) + fVar35;
    *(float *)(lVar11 + 0x2c4) = *(float *)(lVar11 + 0x20) + fVar35;
    DAT_140328424 = *(undefined4 *)(lVar32 + 0x10);
    DAT_14030f7f4 = *(undefined4 *)(lVar11 + 0x1c8);
    DAT_14030f7f8 = *(undefined4 *)(lVar11 + 0x1d8);
    DAT_14030f7f0 = *(undefined4 *)(lVar11 + 0x1b8);
    DAT_14030f7fc = *(undefined4 *)(lVar11 + 0x1e8);
    FUN_140081880(lVar32,plVar31,local_258);
    if (*(int *)((longlong)plVar31 + 0xc) == -1) {
      if ((int)plVar31[1] < 3) {
        uVar12 = 0;
      }
      else {
        lVar32 = plVar31[3];
        *(undefined4 *)((longlong)plVar31 + 0xc) = 2;
        puVar15 = *(undefined8 **)(*plVar31 + 0x48);
        if (*(char *)(lVar32 + 0x21) == '\0') {
          *(undefined1 *)(lVar32 + 0x21) = 1;
          uVar12 = *(undefined8 *)(lVar32 + 0x10);
        }
        else {
          uVar12 = 0;
        }
        *puVar15 = 0x20000000;
        FUN_140197b30(puVar15,uVar12);
        puVar15[1] = 0;
      }
    }
    else {
      uVar12 = 0;
    }
    FUN_1401fc350(lVar30,uVar12);
    puVar15 = (undefined8 *)FUN_140077c50(local_228);
    lVar11 = FUN_140189320();
    lVar32 = local_290;
    if ((*(char *)(lVar11 + 0x27) != '\0') &&
       ((lVar11 = (longlong)*(char *)(param_1 + 0xa8829), *(char *)(param_1 + 0xa8829) == '\0' ||
        ((*(byte *)(param_1 + 0x68f70) & 1) == 0)))) {
      uVar10 = FUN_1400804a0(local_290);
      uVar9 = *(undefined4 *)(lVar32 + 0xc8c);
      lVar11 = lVar11 * 0xe90;
      lVar14 = lVar11 + 0x67250 + param_1;
      *(undefined4 *)(lVar11 + 0x67e20 + param_1) = *(undefined4 *)(lVar32 + 0xc88);
      *(undefined4 *)(lVar11 + 0x67e24 + param_1) = uVar9;
      *(undefined4 *)(lVar11 + 0x67e28 + param_1) = uVar10;
      if (*(char *)(lVar14 + 0xe80) == '\x03') {
        local_168 = ZEXT816(0);
        _DAT_1403283f0 = 0;
        local_178 = 0;
        uStack_170 = 0;
        uVar12 = FUN_14008a3a0(lVar14,puVar15,&local_178,lVar30);
        uVar12 = FUN_14008a690(lVar14 + 0xba0,uVar12,&local_178,*(undefined8 *)(lVar14 + 0xbc8));
        puVar15 = (undefined8 *)FUN_140089f80(lVar14,&local_178,uVar12);
        puVar15[1] = 0;
        puVar15[2] = 0x60000000;
        FUN_140197b30(puVar15 + 2,0);
        puVar15[3] = 0;
        *puVar15 = 0x20000000;
        FUN_140197b30(puVar15,puVar15 + 4);
        puVar15[4] = 0x50000000;
        FUN_140197b30(puVar15 + 4);
        puVar15[5] = 0;
        puVar15 = puVar15 + 6;
      }
    }
    lVar32 = FUN_140189320();
    if (*(char *)(lVar32 + 0x32) != '\0') {
      lVar32 = 0;
      iVar20 = (int)(auVar42._0_4_ * *(float *)(local_290 + 0xc8c) + auVar41._0_4_);
      iVar28 = (int)(auVar39._0_4_ * *(float *)(lVar30 + 0x38) + auVar40._0_4_);
      iVar24 = (int)(auVar39._0_4_ * *(float *)(lVar30 + 0x30) + auVar40._0_4_);
      for (uVar29 = iVar28 - iVar20; (int)uVar29 <= iVar28 + iVar20; uVar29 = uVar29 + 1) {
        if (uVar29 < 0x40) {
          iVar1 = iVar24 + iVar20;
          uVar17 = iVar24 - iVar20;
          if ((int)uVar17 <= iVar1) {
            uVar26 = uVar17;
            do {
              if (uVar26 < 0x40) {
                if (0x310 < lVar32) {
                  lVar32 = lVar32 + 1;
                  break;
                }
                *(short *)(param_1 + 0x68f72 + lVar32 * 2) = (short)uVar29 * 0x40 + (short)uVar17;
                lVar32 = lVar32 + 1;
              }
              uVar17 = uVar17 + 1;
              uVar26 = uVar26 + 1;
            } while ((int)uVar17 <= iVar1);
          }
        }
      }
      *(undefined2 *)(param_1 + 0x68f72 + lVar32 * 2) = 0xffff;
    }
    FUN_1402011a0(plVar31,puVar15);
    if (*(int *)((longlong)plVar31 + 0xc) == -1) {
      if (*(int *)(local_2a0 + (longlong)plVar31) < 5) {
        uVar12 = 0;
      }
      else {
        lVar32 = plVar31[3];
        *(undefined4 *)((longlong)plVar31 + 0xc) = 4;
        puVar15 = *(undefined8 **)(*plVar31 + 0x88);
        if (*(char *)(lVar32 + 0x21) == '\0') {
          *(undefined1 *)(lVar32 + 0x21) = 1;
          uVar12 = *(undefined8 *)(lVar32 + 0x10);
        }
        else {
          uVar12 = 0;
        }
        *puVar15 = 0x20000000;
        FUN_140197b30(puVar15,uVar12);
        puVar15[1] = 0;
      }
    }
    else {
      uVar12 = 0;
    }
    uVar12 = FUN_1400791f0(local_280,uVar12);
    DAT_14030c960 = 0xa8;
    puVar15 = (undefined8 *)FUN_140079310(extraout_XMM0_Qa_03,uVar12);
    *puVar15 = 0x50000000;
    FUN_140197b30(puVar15,&DAT_1402a5310);
    *(undefined4 *)(puVar15 + 1) = 0;
    *(undefined4 *)((longlong)puVar15 + 0xc) = 0x11000000;
    puVar15[2] = 0x50000000;
    FUN_140197b30(puVar15 + 2,&DAT_1402a76a0);
    *(undefined4 *)(puVar15 + 3) = 0x3000040;
    *(undefined4 *)((longlong)puVar15 + 0x1c) = 0x2000198;
    puVar15[4] = 0x1000000a;
    *(undefined4 *)(puVar15 + 10) = 1;
    *(undefined4 *)(puVar15 + 0x12) = 1;
    *(undefined4 *)(puVar15 + 5) = 0;
    *(undefined4 *)((longlong)puVar15 + 0x2c) = 0x5000000a;
    *(undefined4 *)(puVar15 + 6) = 0x8009;
    *(undefined4 *)((longlong)puVar15 + 0x34) = 0x10000000;
    puVar15[7] = 0xe;
    *(undefined4 *)(puVar15 + 8) = 0x7040d;
    *(undefined4 *)(puVar15 + 9) = 0x47;
    *(undefined4 *)(puVar15 + 0xb) = 0x46;
    *(undefined4 *)(puVar15 + 0xc) = 0x44;
    *(undefined4 *)((longlong)puVar15 + 100) = 0x80;
    *(undefined4 *)(puVar15 + 0xd) = 0x42;
    puVar15[0xe] = 0x60;
    *(undefined4 *)(puVar15 + 0xf) = 0x14;
    puVar15[0x10] = 0;
    *(undefined4 *)(puVar15 + 0x11) = 8;
    *(undefined4 *)(puVar15 + 0x13) = 0x4a;
    puVar15[0x14] = 0x60;
    *(undefined4 *)(puVar15 + 0x15) = 0x15;
    *(undefined4 *)(puVar15 + 0x16) = 0x5000d;
    *(undefined4 *)(puVar15 + 0x17) = 0x48;
    puVar15[0x18] = 5;
    *(undefined4 *)(puVar15 + 0x19) = 9;
    puVar15[0x1a] = 0x10000002;
    FUN_140197b30(puVar15 + 0x1a,0);
    uVar29 = DAT_14030c960 | 0x31000000;
    *(undefined4 *)(puVar15 + 0x1b) = 0x1000404;
    *(uint *)(puVar15 + 0x1c) = uVar29;
    *(uint *)(puVar15 + 0x1e) = uVar29;
    *(undefined4 *)((longlong)puVar15 + 0xdc) = 0x6c024009;
    *(undefined4 *)((longlong)puVar15 + 0xe4) = 0;
    *(undefined4 *)(puVar15 + 0x1d) = 0x4e;
    *(undefined4 *)((longlong)puVar15 + 0xf4) = 1;
    *(undefined4 *)(puVar15 + 0x1f) = 0x4e;
    DAT_140328450._0_4_ = 0x103b;
    uVar12 = FUN_140203b30(&DAT_14030f800,puVar15 + 0x20);
    uVar12 = FUN_14013f4a0(param_1 + 0x6a130,uVar12,lVar30);
    lVar32 = 0x20;
    plVar31 = local_220;
    do {
      plVar21 = (longlong *)*plVar31;
      if (plVar21 != (longlong *)0x0) {
        uVar12 = (**(code **)(*plVar21 + 0x50))(plVar21,uVar12,lVar30);
      }
      plVar31 = plVar31 + 1;
      lVar32 = lVar32 + -1;
    } while (lVar32 != 0);
    puVar15 = (undefined8 *)FUN_140203b30(&DAT_14030f800,uVar12);
    plVar31 = *(longlong **)(param_1 + 0x697b8);
    uVar27 = (ulonglong)*(byte *)(param_1 + 0x697ec);
    if (plVar31 != plVar31 + uVar27) {
      plVar21 = plVar31;
      do {
        lVar32 = *plVar21;
        bVar25 = (byte)uVar27;
        if ((((*(uint *)(lVar32 + 0x120) & 1) != 0) && ((*(uint *)(lVar32 + 0x120) & 4) != 0)) &&
           (iVar20 = 0, 0 < *(int *)(lVar32 + 0x118))) {
          do {
            puVar15 = (undefined8 *)
                      FUN_140117620((longlong)iVar20 * 0x520 + *(longlong *)(lVar32 + 0x110),puVar15
                                    ,lVar30);
            iVar20 = iVar20 + 1;
          } while (iVar20 < *(int *)(lVar32 + 0x118));
          bVar25 = *(byte *)(param_1 + 0x697ec);
          plVar31 = *(longlong **)(param_1 + 0x697b8);
        }
        uVar27 = (ulonglong)bVar25;
        plVar21 = plVar21 + 1;
      } while (plVar21 != plVar31 + bVar25);
    }
    local_2a8 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      lVar32 = 0;
      do {
        lVar11 = local_288;
        lVar14 = (longlong)
                 *(int *)(*(longlong *)(lVar32 + *(longlong *)(param_1 + 0x697b8)) + 0x118);
        if (1 < lVar14) {
          lVar22 = 0x520;
          lVar14 = lVar14 + -1;
          do {
            lVar30 = *(longlong *)(*(longlong *)(lVar32 + *(longlong *)(param_1 + 0x697b8)) + 0x110)
            ;
            if ((*(longlong *)(lVar30 + 0x1c0 + lVar22) != 0) && (((byte)DAT_14032844c & 4) != 0)) {
              pauVar2 = (undefined1 (*) [16])(lVar30 + 600 + lVar22);
              local_208 = *(undefined8 *)*pauVar2;
              uStack_200 = *(undefined8 *)(*pauVar2 + 8);
              local_238 = ZEXT816(0);
              local_248._8_8_ = SUB168(*pauVar2,8);
              local_248._0_4_ = SUB164(*pauVar2,0);
              local_248._4_4_ = auVar38._0_4_;
              FUN_14007ada0(*(undefined8 *)(lVar30 + 400 + lVar22),local_238,&local_208,local_248);
              local_2c0 = &local_208;
              puVar23 = (undefined8 *)(lVar30 + 0x268 + lVar22);
              local_208 = *puVar23;
              uStack_200 = puVar23[1];
              local_248 = *(undefined1 (*) [16])(lVar30 + 600 + lVar22);
              local_2c8 = local_248;
              puVar15 = (undefined8 *)
                        FUN_14014b970(*(undefined8 *)(*(longlong *)(lVar30 + 0x1c0 + lVar22) + 0x10)
                                      ,puVar15,lVar11,local_238._4_4_);
            }
            lVar22 = lVar22 + 0x520;
            lVar14 = lVar14 + -1;
          } while (lVar14 != 0);
        }
        local_2a8 = local_2a8 + 1;
        lVar32 = lVar32 + 8;
      } while (local_2a8 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      lVar30 = local_288;
    }
    plVar31 = local_218;
    uVar12 = 0;
    *puVar15 = 0x10000002;
    *(undefined4 *)(puVar15 + 1) = 0x11000000;
    *(undefined4 *)((longlong)puVar15 + 0xc) = 0x50000002;
    *(undefined4 *)(puVar15 + 2) = 0x8001;
    *(undefined4 *)((longlong)puVar15 + 0x14) = 0x10000000;
    puVar15[3] = 0xe;
    *(undefined4 *)(puVar15 + 4) = 0;
    *(undefined4 *)(puVar15 + 5) = 0x4a;
    if (*(int *)((longlong)local_218 + 0xc) != -1) {
      puVar23 = puVar15 + 6;
      *(undefined8 **)((longlong)*(int *)((longlong)local_218 + 0xc) * 0x20 + 8 + *local_218) =
           puVar23;
      uVar13 = *(undefined8 *)
                ((longlong)*(int *)((longlong)local_218 + 0xc) * 0x20 + 0x10 + *local_218);
      *puVar23 = 0x20000000;
      FUN_140197b30(puVar23,uVar13);
      puVar15[7] = 0;
      lVar32 = plVar31[3];
      *(undefined4 *)((longlong)plVar31 + 0xc) = 0xffffffff;
      if (*(char *)(lVar32 + 0x21) != '\0') {
        *(undefined1 *)(lVar32 + 0x21) = 0;
        *(undefined8 **)(lVar32 + 0x10) = puVar15 + 8;
      }
    }
    lVar32 = local_2a0;
    if ((*(int *)((longlong)plVar31 + 0xc) == -1) && (10 < *(int *)(local_2a0 + (longlong)plVar31)))
    {
      lVar11 = plVar31[3];
      *(undefined4 *)((longlong)plVar31 + 0xc) = 10;
      puVar15 = *(undefined8 **)(*plVar31 + 0x148);
      if (*(char *)(lVar11 + 0x21) == '\0') {
        *(undefined1 *)(lVar11 + 0x21) = 1;
        uVar12 = *(undefined8 *)(lVar11 + 0x10);
      }
      *puVar15 = 0x20000000;
      FUN_140197b30(puVar15,uVar12);
      puVar15[1] = 0;
    }
    uVar12 = FUN_1400791f0(local_280,uVar12);
    puVar15 = (undefined8 *)FUN_140079310(extraout_XMM0_Qa_04,uVar12);
    if (*(int *)((longlong)plVar31 + 0xc) != -1) {
      *(undefined8 **)((longlong)*(int *)((longlong)plVar31 + 0xc) * 0x20 + 8 + *plVar31) = puVar15;
      uVar12 = *(undefined8 *)((longlong)*(int *)((longlong)plVar31 + 0xc) * 0x20 + 0x10 + *plVar31)
      ;
      *puVar15 = 0x20000000;
      FUN_140197b30(puVar15,uVar12);
      puVar15[1] = 0;
      lVar11 = plVar31[3];
      *(undefined4 *)((longlong)plVar31 + 0xc) = 0xffffffff;
      if (*(char *)(lVar11 + 0x21) != '\0') {
        *(undefined1 *)(lVar11 + 0x21) = 0;
        *(undefined8 **)(lVar11 + 0x10) = puVar15 + 2;
      }
    }
    lVar11 = local_278;
    iVar20 = *(int *)(param_1 + 0x67234 + local_270 * 4);
    if (*(char *)(param_1 + 0xa87e4) == '\x02') {
      local_2c0 = (undefined8 *)((ulonglong)local_2c0 & 0xffffffffffffff00);
      local_2c8 = *(undefined1 **)(param_1 + 0xa8240);
      FUN_140108620((longlong)(1 - iVar20) * 0x27a0 + *(longlong *)(param_1 + 0xa8248),plVar31,
                    lVar30,local_278);
    }
    lVar14 = (longlong)iVar20 * 0x27a0 + *(longlong *)(param_1 + 0xa8248);
    if ((*(byte *)(param_1 + 0xa8790) & 4) == 0) {
      *(ushort *)(lVar14 + 0x1c20) = *(ushort *)(lVar14 + 0x1c20) | 4;
    }
    else {
      lVar22 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
      if (lVar22 == 0) {
        bVar33 = (*(byte *)(*(longlong *)(param_1 + 0xa8298) + 0x2a6) & 0x42) != 2;
LAB_1400d36af:
        uVar8 = *(ushort *)(lVar14 + 0x1c20);
        if (bVar33) {
          *(ushort *)(lVar14 + 0x1c20) = uVar8 & 0xfffb;
          goto LAB_1400d36ec;
        }
      }
      else {
        puVar15 = *(undefined8 **)(lVar22 + 0x2d8);
        if (((puVar15 == (undefined8 *)0x0) || (*(byte *)*puVar15 <= *(byte *)(lVar22 + 0x3c9))) ||
           (puVar15 = (undefined8 *)(puVar15[1] + (ulonglong)*(byte *)(lVar22 + 0x3c9) * 0x48),
           puVar15 == (undefined8 *)0x0)) {
          cVar6 = -1;
        }
        else {
          cVar6 = *(char *)*puVar15;
        }
        cVar19 = *(char *)(lVar22 + 0x3cc);
        bVar33 = (*(byte *)(*(longlong *)(param_1 + 0xa8298) + 0x2a6) & 0x42) != 2;
        if (cVar6 == '\x05') {
          bVar33 = cVar19 != '\x04' && (cVar19 != '\x02' && bVar33);
          goto LAB_1400d36af;
        }
        if (cVar6 == '\x04') {
          if (cVar19 == '\x02') {
            bVar33 = false;
          }
          goto LAB_1400d36af;
        }
        if ((cVar6 != '\0') ||
           (((cVar19 != '\x06' && (cVar19 != '\x16')) && ((cVar19 != '\x18' && (cVar19 != '\x0e'))))
           )) goto LAB_1400d36af;
        uVar8 = *(ushort *)(lVar14 + 0x1c20);
      }
      *(ushort *)(lVar14 + 0x1c20) = uVar8 | 4;
    }
LAB_1400d36ec:
    local_2c8 = *(undefined1 **)(param_1 + 0xa8240);
    local_2c0 = (undefined8 *)CONCAT71(local_2c0._1_7_,1);
    FUN_140108620(lVar14,plVar31,lVar30,lVar11);
    uVar9 = *(undefined4 *)(local_290 + 0xc94);
    uVar10 = *(undefined4 *)(local_290 + 0xc90);
    *(undefined4 *)(param_1 + 0x338bc) = uVar10;
    *(undefined4 *)(param_1 + 0x338c0) = uVar9;
    *(undefined4 *)(param_1 + 0x6702c) = uVar10;
    *(undefined4 *)(param_1 + 0x67030) = uVar9;
    auVar36 = ZEXT464(*(uint *)(local_290 + 0xc88));
    auVar37 = ZEXT464(*(uint *)(local_290 + 0xc8c));
    lVar14 = local_290;
    uVar9 = FUN_1400804a0(local_290);
    FUN_1400c2830(param_1 + 0x240,uVar9,auVar37._0_8_,auVar36._0_8_);
    FUN_1400c2830(param_1 + 0x339b0);
    fVar35 = auVar43._0_4_ * *(float *)(*(longlong *)(lVar14 + 0x7f8) + 0x1c);
    uVar9 = *(undefined4 *)(*(longlong *)(lVar14 + 0x7f8) + 0x18);
    *(float *)(param_1 + 0x338b8) = fVar35;
    auVar36._0_8_ = FUN_14026f3b0(uVar9);
    auVar36._8_56_ = extraout_var;
    *(int *)(param_1 + 0x338a8) = (int)auVar36._0_8_;
    auVar34 = vpermilps_avx(auVar36._0_16_,1);
    *(int *)(param_1 + 0x338b0) = auVar34._0_4_;
    *(float *)(param_1 + 0x67028) = fVar35;
    *(int *)(param_1 + 0x67018) = (int)auVar36._0_8_;
    *(int *)(param_1 + 0x67020) = auVar34._0_4_;
    *(longlong **)(param_1 + 0x33930) = plVar31;
    *(undefined4 *)(param_1 + 0x33938) = 3;
    *(longlong **)(param_1 + 0x670a0) = plVar31;
    *(undefined4 *)(param_1 + 0x670a8) = 3;
    if (*(int *)((longlong)plVar31 + 0xc) == -1) {
      if (*(int *)(lVar32 + (longlong)plVar31) < 1) {
        uVar12 = 0;
      }
      else {
        lVar32 = plVar31[3];
        *(undefined4 *)((longlong)plVar31 + 0xc) = 0;
        puVar15 = *(undefined8 **)(*plVar31 + 8);
        if (*(char *)(lVar32 + 0x21) == '\0') {
          *(undefined1 *)(lVar32 + 0x21) = 1;
          uVar12 = *(undefined8 *)(lVar32 + 0x10);
        }
        else {
          uVar12 = 0;
        }
        *puVar15 = 0x20000000;
        FUN_140197b30(puVar15,uVar12);
        puVar15[1] = 0;
      }
    }
    else {
      uVar12 = 0;
    }
    puVar15 = (undefined8 *)FUN_1401fc350(lVar30,uVar12);
    if (*(int *)((longlong)plVar31 + 0xc) != -1) {
      *(undefined8 **)((longlong)*(int *)((longlong)plVar31 + 0xc) * 0x20 + 8 + *plVar31) = puVar15;
      uVar12 = *(undefined8 *)((longlong)*(int *)((longlong)plVar31 + 0xc) * 0x20 + 0x10 + *plVar31)
      ;
      *puVar15 = 0x20000000;
      FUN_140197b30(puVar15,uVar12);
      puVar15[1] = 0;
      lVar32 = plVar31[3];
      *(undefined4 *)((longlong)plVar31 + 0xc) = 0xffffffff;
      if (*(char *)(lVar32 + 0x21) != '\0') {
        *(undefined1 *)(lVar32 + 0x21) = 0;
        *(undefined8 **)(lVar32 + 0x10) = puVar15 + 2;
      }
    }
    iVar20 = local_2a4;
    local_2c8 = (undefined1 *)CONCAT44(local_2c8._4_4_,local_2a4);
    FUN_140039850(*(undefined8 *)(param_1 + 0x67120),lVar30,local_258,lVar11);
    local_2a4 = iVar20 + 1;
    local_270 = local_270 + 1;
    lVar32 = local_290;
  } while (local_2a4 < *(int *)(param_1 + 0x67230));
  if (*(int *)(param_1 + 0x67230) < 1) {
    return;
  }
  lVar11 = DAT_14032c8b0 + 0x30;
  FUN_140069370(param_1 + 0xa8160,lVar11);
  uVar13 = FUN_140201120(lVar11,0xd);
  uVar12 = *(undefined8 *)(param_1 + 0xa8240);
  plVar31 = (longlong *)(param_1 + 0x89678);
  lVar32 = 0x20;
  do {
    plVar21 = (longlong *)*plVar31;
    if (plVar21 != (longlong *)0x0) {
      uVar13 = (**(code **)(*plVar21 + 0x58))(plVar21,uVar13,uVar12);
      lVar32 = local_298;
    }
    plVar31 = plVar31 + 1;
    lVar32 = lVar32 + -1;
    local_298 = lVar32;
  } while (lVar32 != 0);
  FUN_1402011a0(lVar11);
  if (((*(longlong *)(param_1 + 0xa82a8) != 0) && (*(longlong *)(param_1 + 0xa8240) != 0)) &&
     (((*(byte *)(param_1 + 0xa8790) & 3) == 0 &&
      (lVar32 = FUN_140189320(), *(char *)(lVar32 + 0x3c) == '\0')))) {
    local_298 = FUN_140201120(lVar11,0xd);
    FUN_1401a7240(*(undefined8 *)(param_1 + 0xa82a8),&local_298,*(undefined8 *)(param_1 + 0xa8240));
    FUN_1402011a0(lVar11,local_298);
  }
  lVar32 = *(longlong *)(param_1 + 0xa8318);
  if (lVar32 == 0) {
LAB_1400d3b2f:
    if (((*(uint *)(param_1 + 0xa8790) & 3) == 0) || ((*(uint *)(param_1 + 0xa8790) & 0x20) != 0))
    goto LAB_1400d3b85;
    uVar12 = FUN_140201120(lVar11,0xd);
    local_2c8 = (undefined1 *)CONCAT44(local_2c8._4_4_,(uint)*(byte *)(param_1 + 0xa8825));
    uVar12 = (**(code **)(**(longlong **)(param_1 + 0x67158) + 0x70))
                       (*(longlong **)(param_1 + 0x67158),uVar12,*(undefined8 *)(param_1 + 0xa8240),
                        *(undefined8 *)(param_1 + 0x67210));
  }
  else {
    cVar6 = FUN_1400c5bc0(lVar32);
    if (*(longlong *)(lVar32 + 0x10) == 0) {
      cVar19 = -1;
    }
    else {
      cVar19 = *(char *)(*(longlong *)(lVar32 + 0x10) + 0x3cc);
    }
    if (cVar6 == '\0') {
      if (cVar19 == '\x06') goto LAB_1400d3a93;
LAB_1400d3ad3:
      if (cVar19 == '\a') {
        uVar12 = FUN_140201120(lVar11,0xd);
        uVar12 = (**(code **)(**(longlong **)(param_1 + 0x67168) + 0x60))
                           (*(longlong **)(param_1 + 0x67168),uVar12,
                            *(undefined8 *)(param_1 + 0xa8240),*(undefined1 *)(param_1 + 0xa8825));
        FUN_1402011a0(lVar11,uVar12);
      }
    }
    else if (cVar6 == '\x04') {
      if (cVar19 == '\x06') goto LAB_1400d3a93;
    }
    else if ((cVar6 == '\x06') && (cVar19 == '\x05')) {
LAB_1400d3a93:
      uVar12 = FUN_140201120(lVar11,0xd);
      uVar12 = (**(code **)(**(longlong **)(param_1 + 0x67150) + 0x60))
                         (*(longlong **)(param_1 + 0x67150),uVar12,
                          *(undefined8 *)(param_1 + 0xa8240),*(undefined1 *)(param_1 + 0xa8825));
      FUN_1402011a0(lVar11,uVar12);
      if (cVar6 == '\0') goto LAB_1400d3ad3;
    }
    if (*(char *)(param_1 + 0xa8827) != '\0') goto LAB_1400d3b2f;
    if (cVar6 == '\0') {
      bVar33 = cVar19 == '\t';
LAB_1400d3b29:
      if (!bVar33) goto LAB_1400d3b2f;
    }
    else {
      if (cVar6 == '\x04') {
        bVar33 = cVar19 == '\b';
        goto LAB_1400d3b29;
      }
      if ((cVar6 != '\x06') || (cVar19 != '\a')) goto LAB_1400d3b2f;
    }
    uVar12 = FUN_140201120(lVar11,0xd);
    local_2c8 = (undefined1 *)(param_1 + 0x69a10);
    uVar12 = FUN_1401bb140(param_1 + 0x671d0,uVar12,*(undefined8 *)(param_1 + 0xa8240),
                           param_1 + 0x697b8);
  }
  FUN_1402011a0(lVar11,uVar12);
LAB_1400d3b85:
  uVar12 = FUN_140201120(lVar11,0xd);
  lVar32 = *(longlong *)(param_1 + 0xa8318);
  cVar6 = FUN_1400c5bc0(lVar32);
  if (*(longlong *)(lVar32 + 0x10) == 0) {
    cVar19 = -1;
  }
  else {
    cVar19 = *(char *)(*(longlong *)(lVar32 + 0x10) + 0x3cc);
  }
  if ((cVar6 == '\0') && (cVar19 == '\x13')) {
    uVar12 = (**(code **)(**(longlong **)(param_1 + 0x67160) + 0x60))
                       (*(longlong **)(param_1 + 0x67160),uVar12,*(undefined8 *)(param_1 + 0xa8240),
                        *(undefined1 *)(param_1 + 0xa8825));
  }
  FUN_1402011a0(lVar11,uVar12);
  lVar32 = *(longlong *)(param_1 + 0xa8318);
  cVar6 = FUN_1400c5bc0(lVar32);
  if ((((cVar6 == '\x01') && (*(longlong *)(lVar32 + 0x10) != 0)) &&
      (*(char *)(*(longlong *)(lVar32 + 0x10) + 0x3cc) == '\x03')) &&
     (*(longlong *)(param_1 + 0xa8760) != 0)) {
    uVar12 = FUN_140201120(lVar11,0xd);
    uVar12 = (**(code **)(**(longlong **)(param_1 + 0xa8760) + 8))
                       (*(longlong **)(param_1 + 0xa8760),uVar12,0x400,
                        *(undefined8 *)(param_1 + 0xa8240));
    FUN_1402011a0(lVar11,uVar12);
  }
  if (*(longlong *)(param_1 + 0xa8310) != 0) {
    uVar12 = FUN_140201120(lVar11,0xd);
    iVar20 = *(int *)(*(longlong *)(param_1 + 0xa8310) + 0x28);
    if (((iVar20 == 2) || (iVar20 == 3)) || (iVar20 == 4)) {
      iVar20 = (int)*(short *)(*(longlong *)(param_1 + 0xa8240) + 0x2a) / 2;
      iVar24 = (int)*(short *)(*(longlong *)(param_1 + 0xa8240) + 0x28) / 2;
      local_2c0 = (undefined8 *)CONCAT44(local_2c0._4_4_,iVar20 * 0x10 + 0x8000);
      local_2c8 = (undefined1 *)CONCAT44(local_2c8._4_4_,iVar24 * 0x10 + 0x8000);
      uVar12 = FUN_140069270(*(longlong *)(param_1 + 0xa8310),uVar12,iVar24 * -0x10 + 0x8000,
                             iVar20 * -0x10 + 0x8000);
    }
    FUN_1402011a0(lVar11,uVar12);
  }
  uVar12 = FUN_140201120(lVar11,0xd);
  lVar32 = *(longlong *)(param_1 + 0xa8240);
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (0 < *(int *)(lVar14 + 0x3c4)) {
    fVar35 = *(float *)(lVar14 + 0x3a0) - auVar41._0_4_ / (float)*(byte *)(lVar14 + 0x3d1);
    *(float *)(lVar14 + 0x3a0) = fVar35;
    *(int *)(lVar14 + 0x3c4) = *(int *)(lVar14 + 0x3c4) + -1;
    if (fVar35 < 0.0) {
      *(undefined4 *)(lVar14 + 0x3a0) = 0;
    }
  }
  fVar35 = *(float *)(lVar14 + 0x3a0);
  if ((*(uint *)(lVar14 + 0x3a8) & 0x4000) != 0) {
    auVar34 = vmaxss_avx(ZEXT416(*(uint *)(lVar14 + 0x3a4)),ZEXT416((uint)fVar35));
    fVar35 = auVar34._0_4_;
  }
  if (*(char *)(lVar14 + 0x3c8) == '\0') {
    uVar29 = (uint)(longlong)(fVar35 * DAT_1402d277c) & 0xff;
  }
  else {
    *(char *)(lVar14 + 0x3c8) = *(char *)(lVar14 + 0x3c8) + -1;
    uVar29 = 0x80;
  }
  *(uint *)(lVar14 + 0x2a0) = uVar29;
  uVar12 = FUN_1401fc350(lVar32,uVar12);
  local_2c0 = (undefined8 *)CONCAT44(local_2c0._4_4_,(int)*(short *)(lVar32 + 0x2a) / 2);
  local_2c8 = (undefined1 *)CONCAT44(local_2c8._4_4_,(int)*(short *)(lVar32 + 0x28) / 2);
  uVar12 = FUN_140069270((uint *)(lVar14 + 0x2a0),uVar12,-((int)*(short *)(lVar32 + 0x28) / 2),
                         -((int)*(short *)(lVar32 + 0x2a) / 2));
  FUN_1402011a0(lVar11,uVar12);
  return;
}

