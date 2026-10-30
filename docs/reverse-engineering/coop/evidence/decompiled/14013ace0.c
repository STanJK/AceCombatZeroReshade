/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14013ace0; RVA 0x13ace0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_14013ace0(longlong *param_1,undefined1 (*param_2) [16],undefined4 *param_3,undefined8 param_4,
             byte param_5,byte param_6,longlong param_7,char param_8)

{
  float *pfVar1;
  undefined1 auVar2 [16];
  char cVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined1 auVar7 [16];
  char cVar8;
  undefined2 uVar9;
  int iVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined4 *puVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined4 *puVar16;
  byte bVar17;
  ulonglong uVar18;
  ushort uVar19;
  longlong lVar20;
  longlong lVar21;
  uint uVar22;
  undefined1 in_ZMM3 [64];
  float fVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  undefined1 auVar27 [64];
  undefined1 auVar28 [64];
  undefined1 auVar29 [64];
  undefined8 in_stack_fffffffffffffec0;
  longlong lVar30;
  undefined4 uVar31;
  undefined8 local_f8;
  undefined8 uStack_f0;
  uint local_e8;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [8];
  float fStack_a0;
  
  cVar8 = DAT_14033bd60;
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);
  uVar11 = 0;
  auVar28 = ZEXT1664(in_ZMM3._0_16_);
  while( true ) {
    uVar22 = 1 << ((uint)uVar11 & 0x1f);
    if ((*(uint *)(param_1 + 0xe7) & uVar22) == 0) break;
    uVar22 = (uint)uVar11 + 1;
    uVar11 = (ulonglong)uVar22;
    if (0x1f < (int)uVar22) {
      return 0;
    }
  }
  uVar18 = (ulonglong)param_5;
  lVar12 = uVar11 + 1;
  lVar21 = lVar12 * 0x38;
  lVar20 = (ulonglong)param_6 * 0x520;
  lVar15 = *(longlong *)(*(longlong *)(*(longlong *)param_1[1] + uVar18 * 8) + 0x110);
  iVar10 = FUN_140242630();
  fVar23 = (float)(iVar10 % 200 + -100);
  iVar10 = FUN_140242630();
  fVar25 = *(float *)(param_7 + 0x30) * DAT_1402d2420;
  uVar24 = 0;
  local_f8 = CONCAT44(fVar25 * (float)(iVar10 % 200 + -100) * DAT_1402d1d8c,
                      fVar25 * fVar23 * DAT_1402d1d8c);
  uStack_f0 = 0;
  FUN_140203050(&local_f8,param_3,&local_f8);
  local_c8 = ZEXT816(0);
  local_d8 = 0;
  uStack_d0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  _local_a8 = local_c8;
  FUN_140202920(&local_d8,&local_f8);
  auVar2 = *param_2;
  fVar25 = auVar2._0_4_ + (float)local_a8._0_4_;
  auVar7 = vshufps_avx(auVar2,auVar2,0x55);
  fVar23 = auVar7._0_4_ + (float)local_a8._4_4_;
  auVar7 = vshufps_avx(auVar2,auVar2,0xaa);
  fVar26 = auVar7._0_4_ + fStack_a0;
  *(float *)(lVar21 + 4 + (longlong)param_1) = fVar23;
  *(float *)(param_1 + lVar12 * 7 + 1) = fVar26;
  *(float *)(param_1 + lVar12 * 7) = fVar25;
  auVar2 = vshufps_avx(auVar2,auVar2,0xff);
  auVar27 = ZEXT1664(auVar2);
  pfVar1 = (float *)(param_1 + lVar12 * 7 + 2);
  *(byte *)(param_1 + lVar12 * 7 + 5) = param_5;
  *(int *)(lVar21 + 0xc + (longlong)param_1) = auVar2._0_4_;
  *(byte *)(lVar21 + 0x29 + (longlong)param_1) = param_6;
  *(undefined4 *)(lVar21 + 0x2c + (longlong)param_1) = 0;
  param_1[lVar12 * 7 + 4] = param_7;
  auVar28._0_4_ =
       (((float)*(int *)(param_7 + 0x44) * DAT_1402d20dc) / (float)*(byte *)(param_1 + 5)) *
       DAT_1402d2478 + auVar28._0_4_;
  auVar29 = ZEXT1664(auVar28._0_16_);
  FUN_14013a970((float)*(byte *)(param_1 + 5),pfVar1,&local_f8,auVar28._0_8_);
  *(uint *)(param_1 + 0xe7) = *(uint *)(param_1 + 0xe7) | uVar22;
  if (*param_1 != 0) {
    local_f8 = CONCAT44(fVar23,fVar25);
    uStack_f0 = CONCAT44(auVar27._0_4_,fVar26);
    local_e8 = (uint)(param_8 != '\0');
    uVar9 = FUN_140031f80(*(undefined8 *)(*param_1 + 0x66ee0),0x20,&local_f8,0);
    *(undefined2 *)(lVar21 + 0x2a + (longlong)param_1) = uVar9;
    if ((DAT_14033bd60 != '\0') &&
       ((((cVar3 = *(char *)(**(longlong **)(lVar20 + 0x388 + lVar15) + 0x15d), cVar3 == '\0' ||
          (cVar3 == '\x02')) && (*(char *)(lVar20 + 0x235 + lVar15) == '\0')) &&
        (param_5 == DAT_14033d9d2)))) {
      *(undefined4 *)(param_1 + 0xe8) = 0;
      *(undefined2 *)((longlong)param_1 + 0x744) = 0xffff;
      *(undefined4 *)((longlong)param_1 + 0x746) = 0xffffffff;
      *(undefined2 *)((longlong)param_1 + 0x74a) = 0xffff;
      lVar30 = (longlong)param_1 + 0x74c;
      FUN_1401518d0(*(longlong *)(lVar20 + 0x1b8 + lVar15) + 0xad0,*param_1,lVar20 + 600 + lVar15,
                    lVar20 + 0x268 + lVar15,(undefined2 *)((longlong)param_1 + 0x744),lVar30,0);
      uVar31 = (undefined4)((ulonglong)lVar30 >> 0x20);
    }
  }
  if (cVar8 == '\0') {
    puVar13 = (undefined4 *)FUN_140019ef0();
    plVar14 = (longlong *)FUN_14001b280(puVar13);
    if (plVar14 != (longlong *)0x0) {
      lVar30 = *(longlong *)(*(longlong *)(*(longlong *)(puVar13 + 0x10a) + 0x697b8) + uVar18 * 8);
      lVar5 = *(longlong *)(lVar30 + 0x110);
      uVar4 = *(undefined1 *)(lVar30 + 0x15d);
      *(undefined4 *)(plVar14 + 0xc) = *puVar13;
      *(undefined2 *)((longlong)plVar14 + 100) = *(undefined2 *)(lVar5 + 0x228 + lVar20);
      *(undefined1 *)((longlong)plVar14 + 0x66) = *(undefined1 *)(lVar5 + 0x234 + lVar20);
      *(undefined1 *)((longlong)plVar14 + 0x67) = *(undefined1 *)(lVar5 + 0x235 + lVar20);
      *(float *)((longlong)plVar14 + 0x34) = fVar25;
      *(float *)(plVar14 + 7) = fVar23;
      *(undefined4 *)(plVar14 + 8) = *param_3;
      *(undefined4 *)((longlong)plVar14 + 0x44) = param_3[1];
      *(undefined4 *)(plVar14 + 9) = param_3[2];
      plVar14[5] = param_7;
      *(float *)((longlong)plVar14 + 0x3c) = fVar26;
      *(int *)((longlong)plVar14 + 0x4c) = auVar29._0_4_;
      *(undefined1 *)(plVar14 + 0xd) = uVar4;
      *(undefined2 *)((longlong)plVar14 + 0x69) = 0;
      *(undefined1 *)((longlong)plVar14 + 0x6b) = 2;
      *(undefined2 *)(plVar14 + 4) = 2;
      *(char *)(plVar14 + 10) = param_8;
      puVar6 = *(undefined8 **)(puVar13 + 0x28);
      *puVar6 = plVar14;
      *(longlong **)(puVar13 + 0x28) = plVar14;
      *plVar14 = (longlong)(puVar13 + 0x26);
      plVar14[1] = (longlong)puVar6;
      puVar13[0x42] = puVar13[0x42] + 1;
    }
  }
  cVar8 = *(char *)(**(longlong **)(lVar20 + 0x388 + lVar15) + 0x15d);
  if (((cVar8 != '\0') && (cVar8 != '\x02')) || (*(char *)(lVar20 + 0x235 + lVar15) != '\0')) {
    lVar15 = *(longlong *)(*(longlong *)(*(longlong *)param_1[1] + uVar18 * 8) + 0x110);
    lVar30 = **(longlong **)(lVar15 + 0x1a0 + lVar20);
    cVar8 = *(char *)(lVar30 + 0x75);
    if (cVar8 == '\x03') {
      FUN_1401c56d0();
      local_f8 = _DAT_1402d35f0;
      uStack_f0 = _UNK_1402d35f8;
      puVar13 = (undefined4 *)(lVar15 + 600 + lVar20);
      uVar9 = 0x52;
      cVar8 = FUN_1401c6a00(DAT_1402d2100,1,0x52,puVar13,&local_f8,CONCAT44(uVar31,DAT_1402d2100),
                            DAT_1402d234c,DAT_1402d2458,uVar24,0,1);
      if ((cVar8 == '\0') || (lVar15 = FUN_1401c97a0(), *(char *)(lVar15 + 0x3dc2) < '\x02'))
      goto LAB_14013b529;
      uVar19 = *(ushort *)(lVar15 + 0x138);
      bVar17 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar19 * 0x18) + 0x19b2);
    }
    else if ((cVar8 - 2U & 0xfd) == 0) {
      FUN_1401c56d0();
      local_f8 = _DAT_1402d35f0;
      uStack_f0 = _UNK_1402d35f8;
      puVar13 = (undefined4 *)(lVar15 + 600 + lVar20);
      uVar9 = 0x115;
      cVar8 = FUN_1401c6a00(DAT_1402d2100,1,0x115,puVar13,&local_f8,CONCAT44(uVar31,DAT_1402d2100),
                            DAT_1402d234c,DAT_1402d2458,uVar24,0,1);
      if ((cVar8 == '\0') || (lVar15 = FUN_1401c97a0(), *(char *)(lVar15 + 0x3dc2) < '\x02'))
      goto LAB_14013b529;
      uVar19 = *(ushort *)(lVar15 + 0x138);
      bVar17 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar19 * 0x18) + 0x56a2);
    }
    else {
      if (1 < (byte)(cVar8 - 5U)) goto LAB_14013b529;
      puVar13 = (undefined4 *)(lVar15 + 600 + lVar20);
      if (*(short *)(lVar30 + 0x6c) == 0x61) {
        FUN_1401c56d0();
        uVar9 = 2;
        local_f8 = _DAT_1402d35f0;
        uStack_f0 = _UNK_1402d35f8;
        cVar8 = FUN_1401c6a00(DAT_1402d2100,2,2,puVar13,&local_f8,CONCAT44(uVar31,DAT_1402d2100),
                              DAT_1402d234c,DAT_1402d2458,uVar24,0,1);
        if ((cVar8 == '\0') || (lVar15 = FUN_1401c97a0(), *(char *)(lVar15 + 0x3dc2) < '\x03'))
        goto LAB_14013b529;
        uVar19 = *(ushort *)(lVar15 + 0x150);
        bVar17 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar19 * 0x18) + 0xb2);
      }
      else {
        FUN_1401c56d0();
        local_f8 = _DAT_1402d35f0;
        uStack_f0 = _UNK_1402d35f8;
        uVar9 = 0x118;
        cVar8 = FUN_1401c6a00(DAT_1402d2100,1,0x118,puVar13,&local_f8,CONCAT44(uVar31,DAT_1402d2100)
                              ,DAT_1402d234c,DAT_1402d2458,uVar24,0,1);
        if ((cVar8 == '\0') || (lVar15 = FUN_1401c97a0(), *(char *)(lVar15 + 0x3dc2) < '\x02'))
        goto LAB_14013b529;
        uVar19 = *(ushort *)(lVar15 + 0x138);
        bVar17 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar19 * 0x18) + 0x5792);
      }
    }
    if (((~bVar17 & 1) != 0) &&
       (puVar16 = (undefined4 *)FUN_1401c9e60(lVar15), puVar16 != (undefined4 *)0x0)) {
      *(ushort *)(puVar16 + 0x11) = uVar19;
      *(undefined2 *)((longlong)puVar16 + 0x46) = uVar9;
      *puVar16 = *puVar13;
      puVar16[1] = puVar13[1];
      puVar16[2] = puVar13[2];
      puVar16[3] = puVar13[3];
      *(undefined8 *)(puVar16 + 4) = 0;
      puVar16[6] = 0;
      puVar16[7] = 0x3f800000;
      puVar16[8] = 0x3ea3d70a;
      puVar16[9] = 0x3fb33333;
      *(undefined8 *)(puVar16 + 10) = 0x40800000;
      puVar16[0xf] = 0x3f800000;
      *(undefined2 *)((longlong)puVar16 + 0x4a) = 0;
      *(byte *)(puVar16 + 0x1c) = *(byte *)(puVar16 + 0x1c) & 0xee | 0x26;
      *(code **)(puVar16 + 0xc) = FUN_1401caa00;
    }
  }
LAB_14013b529:
  *(float *)(param_1 + lVar12 * 7) = *(float *)(param_1 + lVar12 * 7) + *pfVar1;
  *(float *)(lVar21 + 4 + (longlong)param_1) =
       pfVar1[1] + *(float *)(lVar21 + 4 + (longlong)param_1);
  *(float *)(param_1 + lVar12 * 7 + 1) = pfVar1[2] + *(float *)(param_1 + lVar12 * 7 + 1);
  *(float *)(lVar21 + 0xc + (longlong)param_1) =
       pfVar1[3] + *(float *)(lVar21 + 0xc + (longlong)param_1);
  return 1;
}

