/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a3b80; RVA 0xa3b80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a3b80(longlong param_1,float *param_2)

{
  undefined1 auVar1 [16];
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  char cVar8;
  longlong lVar9;
  float *pfVar10;
  code *pcVar11;
  undefined8 extraout_XMM0_Qa;
  undefined8 uVar12;
  undefined8 extraout_XMM0_Qa_00;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined2 local_res8 [4];
  undefined8 in_stack_fffffffffffffef0;
  undefined8 *puVar22;
  undefined4 uVar23;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 uVar24;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
  uVar24 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  DAT_14032c480 = DAT_14032c480 + 1;
  FUN_1401c56d0();
  auVar1 = *(undefined1 (*) [16])(param_2 + 0x1e);
  fVar14 = auVar1._0_4_;
  auVar5 = vshufps_avx(auVar1,auVar1,0xaa);
  fVar15 = auVar5._0_4_;
  auVar5 = vshufps_avx(auVar1,auVar1,0xff);
  fVar16 = auVar5._0_4_;
  auVar1 = vshufps_avx(auVar1,auVar1,0x55);
  fVar18 = auVar1._0_4_;
  uVar17 = 0;
  lVar9 = *(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x110);
  lVar4 = *(longlong *)(lVar9 + 0x1b8);
  auVar1 = *(undefined1 (*) [16])(lVar4 + 0x70);
  auVar5 = vshufps_avx(auVar1,auVar1,0x55);
  auVar6 = vshufps_avx(auVar1,auVar1,0xaa);
  auVar7 = vshufps_avx(auVar1,auVar1,0xff);
  fVar13 = SQRT(fVar16 * fVar16 + fVar15 * fVar15 + fVar18 * fVar18 + fVar14 * fVar14);
  if (fVar13 != 0.0) {
    fVar13 = DAT_1402d22d0 / fVar13;
    fVar14 = fVar14 * fVar13;
    fVar18 = fVar18 * fVar13;
    fVar15 = fVar15 * fVar13;
    fVar16 = fVar16 * fVar13;
  }
  fVar13 = fVar14 * (auVar1._0_4_ - *param_2) + (auVar5._0_4_ - param_2[1]) * fVar18 +
           fVar16 * (auVar7._0_4_ - param_2[3]) + (auVar6._0_4_ - param_2[2]) * fVar15;
  fVar21 = fVar18 * fVar13 + param_2[1];
  fVar18 = fVar21 - *(float *)(lVar4 + 0x74);
  fVar20 = fVar14 * fVar13 + *param_2;
  fVar14 = fVar20 - *(float *)(lVar4 + 0x70);
  fVar19 = fVar15 * fVar13 + param_2[2];
  fVar13 = fVar16 * fVar13 + param_2[3];
  fVar15 = fVar19 - *(float *)(lVar4 + 0x78);
  fVar16 = fVar13 - *(float *)(lVar4 + 0x7c);
  pfVar10 = param_2 + 0x26;
  local_d8 = fVar20;
  local_d4 = fVar21;
  local_d0 = fVar19;
  local_cc = fVar13;
  if (DAT_1402d2bcc <= fVar16 * fVar16 + fVar15 * fVar15 + fVar18 * fVar18 + fVar14 * fVar14) {
    uVar12 = FUN_1401c6490(fVar14,pfVar10);
  }
  else {
    cVar8 = FUN_1401c5910();
    if (cVar8 == '\0') {
      uVar12 = extraout_XMM0_Qa;
      if (0 < *(short *)(lVar9 + 0x428)) {
        puVar22 = &local_c8;
        local_res8[0] = 2;
        local_c8 = _DAT_1402d35f0;
        uStack_c0 = _UNK_1402d35f8;
        local_b8 = _DAT_1402d35f0;
        uStack_b0 = _UNK_1402d35f8;
        uVar12 = FUN_1401c5c30(_DAT_1402d35f0,local_res8,param_1 + 0xeca,&local_d8,&local_b8,puVar22
                               ,pfVar10);
        uVar23 = (undefined4)((ulonglong)puVar22 >> 0x20);
        uVar24 = (undefined4)((ulonglong)pfVar10 >> 0x20);
      }
    }
    else {
      uVar12 = FUN_1401c6260(extraout_XMM0_Qa,pfVar10,&local_d8);
    }
  }
  param_2 = param_2 + 0x25;
  cVar8 = FUN_1401c5910(uVar12,param_2);
  if (cVar8 == '\0') {
    local_b8 = _DAT_1402d35f0;
    uStack_b0 = _UNK_1402d35f8;
    cVar8 = FUN_1401c6a00(_DAT_1402d35f0,2,*(undefined2 *)(param_1 + 0xec8),&local_d8,&local_b8,
                          CONCAT44(uVar23,uVar17),CONCAT44(uVar24,uVar17),uVar17,uVar17,0,0);
    if (cVar8 != '\0') {
      lVar9 = FUN_1401c97a0();
      fVar14 = *param_2;
      if ((((fVar14 == 0.0) || (0x7f < SUB42(fVar14,0))) ||
          ((short)((uint)fVar14 >> 0x10) !=
           *(short *)(lVar9 + 2 + (ulonglong)((uint)fVar14 & 0xffff) * 2))) &&
         ('\x02' < *(char *)(lVar9 + 0x3dc2))) {
        uVar3 = *(ushort *)(lVar9 + 0x150);
        bVar2 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar3 * 0x18) + 0x12 +
                         (ulonglong)*(ushort *)(param_1 + 0xec8) * 0x50);
        pfVar10 = (float *)FUN_1401c9e60(lVar9);
        if (pfVar10 != (float *)0x0) {
          *(ushort *)(pfVar10 + 0x11) = uVar3;
          *(undefined2 *)((longlong)pfVar10 + 0x46) = *(undefined2 *)(param_1 + 0xec8);
          *pfVar10 = fVar20;
          pfVar10[1] = fVar21;
          pfVar10[2] = fVar19;
          pfVar10[3] = fVar13;
          pfVar10[4] = 0.0;
          pfVar10[5] = 0.0;
          pfVar10[6] = 0.0;
          pfVar10[7] = 1.0;
          pfVar10[8] = 0.0;
          pfVar10[9] = 0.0;
          pfVar10[10] = 0.0;
          pfVar10[0xb] = 1.0;
          pfVar10[0xf] = 1.0;
          *(undefined2 *)((longlong)pfVar10 + 0x4a) = 0;
          *(byte *)(pfVar10 + 0x1c) = *(byte *)(pfVar10 + 0x1c) & 0xef | 2;
          *param_2 = pfVar10[0xe];
          if ((bVar2 & 1) == 0) {
            *(byte *)(pfVar10 + 0x1c) = *(byte *)(pfVar10 + 0x1c) & 0xfa;
            pcVar11 = FUN_1401caa00;
          }
          else {
            *(byte *)(pfVar10 + 0x1c) = *(byte *)(pfVar10 + 0x1c) & 0xfb | 1;
            pcVar11 = FUN_1401ca740;
          }
          *(code **)(pfVar10 + 0xc) = pcVar11;
        }
      }
    }
  }
  else {
    FUN_1401c6260(extraout_XMM0_Qa_00,param_2,&local_d8);
  }
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

