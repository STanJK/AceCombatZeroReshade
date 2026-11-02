/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400ae510; RVA 0xae510
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_1400ae510(undefined8 *param_1,undefined8 *param_2,longlong param_3,longlong *param_4,
             ulonglong param_5)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  uint uVar5;
  byte bVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  longlong *plVar12;
  int iVar13;
  int iVar14;
  char cVar15;
  float fVar16;
  float fVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [64];
  undefined1 auVar20 [16];
  undefined1 auVar21 [64];
  undefined1 auVar22 [16];
  undefined1 auVar23 [64];
  
  lVar3 = param_5;
  *(uint *)(param_1 + 0x69) = *(uint *)(param_1 + 0x69) & 0xfbffffff;
  if (param_5 == 0) {
    return param_2;
  }
  iVar14 = 0;
  *(undefined4 *)(param_1 + 0x70) = 0x3f800000;
  uVar5 = DAT_1402d2d90;
  uVar11 = DAT_1402d2368;
  auVar21 = ZEXT464(DAT_1402d2d90);
  auVar23 = ZEXT464(DAT_1402d2368);
  *(float *)((longlong)param_1 + 900) = *(float *)(param_3 + 0x19c) / *(float *)(param_3 + 0x198);
  auVar18 = *(undefined1 (*) [16])((longlong)param_1 + 0x54);
  auVar19 = ZEXT1664(auVar18);
  auVar4 = vshufps_avx(auVar18,auVar18,0x55);
  auVar20 = ZEXT416(uVar5);
  auVar4 = vmaxss_avx(auVar4,auVar20);
  auVar22 = ZEXT416(uVar11);
  auVar4 = vminss_avx(auVar4,auVar22);
  fVar17 = 0.0;
  if (auVar4._0_4_ == 0.0) {
    iVar13 = 0;
  }
  else {
    fVar17 = 0.0;
    fVar16 = (float)FUN_140275cc0();
    auVar22 = auVar23._0_16_;
    auVar20 = auVar21._0_16_;
    auVar18 = auVar19._0_16_;
    iVar13 = (int)(short)(int)(fVar16 * *(float *)(param_3 + 8) * *(float *)(param_3 + 0x198));
  }
  *(int *)(param_1 + 0x72) = iVar13;
  auVar18 = vmaxss_avx(auVar18,auVar20);
  auVar18 = vminss_avx(auVar18,auVar22);
  if (auVar18._0_4_ == fVar17) {
    iVar7 = 0;
  }
  else {
    fVar17 = (float)FUN_140275cc0(CONCAT44(auVar18._4_4_ ^ _UNK_1402d3774,
                                           (uint)auVar18._0_4_ ^ DAT_1402d3770));
    iVar7 = (int)(short)(int)(float)((uint)(fVar17 * *(float *)(param_3 + 8) *
                                           *(float *)(param_3 + 0x19c)) ^ DAT_1402d3770);
  }
  *(int *)((longlong)param_1 + 0x394) = iVar7;
  if (iVar13 < -0x300) {
    *(undefined4 *)(param_1 + 0x72) = 0xfffffd00;
  }
  else if (0x300 < iVar13) {
    *(undefined4 *)(param_1 + 0x72) = 0x300;
  }
  if (iVar7 < -0x300) {
    *(undefined4 *)((longlong)param_1 + 0x394) = 0xfffffd00;
  }
  else if (0x300 < iVar7) {
    *(undefined4 *)((longlong)param_1 + 0x394) = 0x300;
  }
  uVar8 = FUN_140203b30(param_1[0x60] + 0x40,param_2);
  uVar8 = FUN_140203b30(param_1[0x60] + 0x88,uVar8);
  uVar8 = FUN_1401fc350(param_3,uVar8);
  puVar9 = (undefined8 *)FUN_1400bf810(uVar8,0);
  *puVar9 = 0x10000002;
  puVar10 = puVar9 + 6;
  *(undefined4 *)(puVar9 + 1) = 0;
  *(undefined4 *)((longlong)puVar9 + 0xc) = 0x50000002;
  *(undefined4 *)(puVar9 + 2) = 0x8001;
  *(undefined4 *)((longlong)puVar9 + 0x14) = 0x10000000;
  puVar9[3] = 0xe;
  puVar9[4] = 0;
  *(undefined4 *)(puVar9 + 5) = 0x14;
  if ((*(byte *)(param_1 + 0x77) & 4) != 0) {
    return puVar10;
  }
  param_5 = 0;
  if (*(char *)((longlong)param_1 + 0x3cb) != '\0') {
    if (*(char *)((longlong)param_1 + 0x3ca) == '\0') {
      param_5 = 0xffffff80;
    }
    else {
      uVar11 = 0;
      if (*(char *)((longlong)param_1 + 0x3ca) == '\x01') {
        uVar11 = 0x80;
      }
      param_5 = (ulonglong)uVar11;
    }
  }
  lVar2 = *(longlong *)
           (*(longlong *)(*param_4 + (ulonglong)*(byte *)((longlong)param_1 + 0x3ca) * 8) + 0x110);
  if (lVar2 == 0) {
    return puVar10;
  }
  if (*(short *)(lVar2 + 0x428) < 1) {
    return puVar10;
  }
  cVar15 = *(char *)((longlong)param_1 + 0x177);
  pbVar1 = (byte *)(param_1 + 0x2f);
  if (cVar15 != '\0') goto LAB_1400ae7c9;
  bVar6 = *pbVar1;
  if ((byte)(bVar6 - 0xc) < 6) {
    bVar6 = bVar6 - 0xc;
LAB_1400ae7f2:
    if (bVar6 != 0) {
      puVar10 = (undefined8 *)FUN_1400af750(param_1,puVar10,param_3,param_4);
    }
  }
  else {
    if ((byte)(bVar6 - 0x14) < 7) {
      cVar15 = '\x05';
      bVar6 = *pbVar1 - 0x14;
      if (5 < (byte)(*pbVar1 - 0x14)) goto LAB_1400ae7c9;
    }
    else {
LAB_1400ae7c9:
      bVar6 = *pbVar1;
      if (*pbVar1 == 0x1a) {
        bVar6 = 4;
      }
    }
    if (cVar15 == '\x06') {
      puVar10 = (undefined8 *)FUN_1400aeb80(param_1,puVar10,param_3,param_4);
    }
    else if (cVar15 == '\x04') goto LAB_1400ae7f2;
  }
  uVar8 = (**(code **)(*(longlong *)param_1[2] + 0x40))
                    ((longlong *)param_1[2],puVar10,param_3,*(undefined1 *)(param_1 + 0x78));
  uVar8 = (**(code **)(*(longlong *)param_1[3] + 0x40))
                    ((longlong *)param_1[3],uVar8,param_3,*(undefined1 *)(param_1 + 0x78));
  if (*(char *)((longlong)param_1 + 0x3cb) == '\0') {
    uVar8 = (**(code **)(*(longlong *)param_1[4] + 0x48))
                      ((longlong *)param_1[4],uVar8,param_3,*(undefined1 *)(param_1 + 0x78));
  }
  uVar8 = (**(code **)(*(longlong *)param_1[5] + 0x40))
                    ((longlong *)param_1[5],uVar8,param_3,*(undefined1 *)(param_1 + 0x78));
  if ((((*(byte *)((longlong)param_1 + 0x283) & 1) == 0) && ((*(byte *)(param_1 + 0x77) & 1) == 0))
     && (*(char *)((longlong)param_1 + 0x3cb) == '\0')) {
    uVar8 = (**(code **)(*(longlong *)param_1[6] + 0x40))
                      ((longlong *)param_1[6],uVar8,param_3,*(undefined1 *)(param_1 + 0x78));
  }
  uVar8 = (**(code **)(*(longlong *)param_1[7] + 0x40))
                    ((longlong *)param_1[7],uVar8,param_3,*(undefined1 *)(param_1 + 0x78));
  uVar8 = FUN_1400b9a60(param_1,uVar8,param_3,param_4);
  uVar8 = FUN_1400afd00(param_1,uVar8,param_3,param_4);
  uVar8 = FUN_1400b05e0(param_1,uVar8,param_3,lVar3,param_4,&param_5);
  uVar8 = FUN_1400b2d00(param_1,uVar8,param_3,param_4,&param_5);
  uVar8 = FUN_1400b1680(param_1,uVar8);
  puVar10 = (undefined8 *)FUN_1400b30f0(param_1,uVar8,param_3,param_4);
  if ((*(byte *)((longlong)param_1 + 0x283) & 1) == 0) {
    puVar10 = (undefined8 *)FUN_1400b3560(param_1,puVar10,param_3);
  }
  if ((code *)param_1[0x7c] != (code *)0x0) {
    puVar10 = (undefined8 *)
              (*(code *)param_1[0x7c])
                        (param_1,puVar10,param_3,param_4,lVar3,
                         *(char *)((longlong)param_1 + 0xfc) == '\x01',&param_5);
  }
  if (*(char *)((longlong)param_1 + 0x3c9) == '\0') {
    uVar11 = 0x68;
    *(undefined4 *)(param_1 + 0x53) = 0x68;
    *(undefined4 *)(param_1 + 0x52) = 0x45;
    *(undefined4 *)((longlong)param_1 + 0x294) = 0x163;
    *(undefined4 *)((longlong)param_1 + 0x29c) = 0x80;
    if ((*(byte *)(param_1 + 0x77) & 0x20) != 0) {
      uVar11 = 0x4e;
      iVar14 = 3;
      *(undefined4 *)(param_1 + 0x53) = 0x4e;
    }
    uVar11 = uVar11 >> 1;
    *(int *)(param_1 + 0x55) = iVar14 + 0x45;
    *(int *)(param_1 + 0x56) = iVar14 + 0x45;
    *(undefined4 *)(param_1 + 0x54) = 0x45;
    *(undefined4 *)((longlong)param_1 + 0x2a4) = 0x173;
    *(undefined4 *)((longlong)param_1 + 0x2ac) = 0x163;
    *(uint *)(param_1 + 0x58) = (iVar14 - uVar11) + 0x45;
    *(uint *)((longlong)param_1 + 0x2c4) = uVar11 + 0x45 + iVar14;
    *(undefined4 *)((longlong)param_1 + 0x2b4) = 0x173;
    *(uint *)(param_1 + 0x57) = uVar11;
    *(undefined4 *)((longlong)param_1 + 700) = 0x40;
    *(undefined4 *)(param_1 + 0x59) = 0x123;
    *(undefined4 *)((longlong)param_1 + 0x2cc) = 0x1a3;
    *(undefined4 *)(param_1 + 0x5a) = 0x4c;
    if ((*(char *)((longlong)param_1 + 0x3cb) != '\0') &&
       (*(char *)((longlong)param_1 + 0x3ca) == '\x01')) {
      *(int *)(param_1 + 0x55) = iVar14 + 0x13f;
      *(int *)(param_1 + 0x56) = iVar14 + 0x13f;
      *(uint *)(param_1 + 0x58) = (iVar14 - uVar11) + 0x13f;
      *(uint *)((longlong)param_1 + 0x2c4) = uVar11 + 0x13f + iVar14;
    }
    plVar12 = (longlong *)*param_1;
  }
  else {
    if ((*(char *)((longlong)param_1 + 0x3cb) != '\0') &&
       (*(char *)((longlong)param_1 + 0x3c9) == '\x03')) goto LAB_1400aead1;
    plVar12 = (longlong *)param_1[1];
  }
  puVar10 = (undefined8 *)
            (**(code **)(*plVar12 + 0x40))(plVar12,puVar10,param_3,*(undefined1 *)(param_1 + 0x78));
LAB_1400aead1:
  if (((*(byte *)((longlong)param_1 + 0x283) & 1) != 0) && ((*(byte *)(param_1 + 0x77) & 1) == 0)) {
    puVar10 = (undefined8 *)FUN_1400bbe30(param_1 + 0x4c,puVar10,param_3);
  }
  if ((*(char *)((longlong)param_1 + 0x3cb) == '\0') ||
     (*(char *)((longlong)param_1 + 0x3c9) == '\x03')) {
    lVar3 = param_1[2];
    *(undefined1 *)(*(longlong *)(lVar3 + 0x30) + 0x35) = 1;
    *(undefined1 *)(*(longlong *)(lVar3 + 0x38) + 0x35) = 1;
    *(undefined1 *)(*(longlong *)(lVar3 + 0x48) + 0x3a) = 0;
  }
  else {
    lVar3 = param_1[2];
    *(undefined1 *)(*(longlong *)(lVar3 + 0x30) + 0x35) = 0;
    *(undefined1 *)(*(longlong *)(lVar3 + 0x38) + 0x35) = 0;
    *(undefined1 *)(*(longlong *)(lVar3 + 0x48) + 0x3a) = 1;
  }
  return puVar10;
}

