/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401fbec0; RVA 0x1fbec0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401fbec0(float *param_1)

{
  undefined8 *puVar1;
  float fVar2;
  byte bVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  longlong lVar7;
  float *pfVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float local_e8 [6];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  
  FUN_140202c00(param_1 + 0x14,param_1 + 0x10,param_1 + 0xc);
  if (((uint)param_1[0x68] & 1) == 0) {
    fVar10 = param_1[0x67];
    fVar12 = param_1[0x66];
  }
  else {
    fVar12 = (float)(int)*(short *)(param_1 + 10) / *param_1;
    fVar10 = (float)(int)*(short *)((longlong)param_1 + 0x2a) / param_1[1];
    param_1[0x67] = fVar10;
    param_1[0x66] = fVar12;
  }
  fVar14 = DAT_1402d2168;
  if (((uint)param_1[0x68] & 2) != 0) {
    param_1[100] = -((float)(int)*(short *)(param_1 + 6) * DAT_1402d2168) + DAT_1402d2a04 +
                   (float)((int)*(short *)(param_1 + 5) + ((int)*(short *)(param_1 + 6) >> 1));
    param_1[0x65] =
         -((float)(int)*(short *)((longlong)param_1 + 0x1a) * fVar14) + DAT_1402d2a04 +
         (float)((int)*(short *)((longlong)param_1 + 0x16) +
                ((int)*(short *)((longlong)param_1 + 0x1a) >> 1));
  }
  FUN_140202c90(param_1 + 0x24,param_1[2],fVar12,fVar10,param_1[100],param_1[0x65],
                *(undefined2 *)(param_1 + 6),*(undefined2 *)((longlong)param_1 + 0x1a),param_1[7],
                param_1[8],param_1[3],param_1[4],*(undefined1 *)(param_1 + 0x6a),
                *(undefined1 *)((longlong)param_1 + 0x1a9),
                *(undefined1 *)((longlong)param_1 + 0x1aa));
  bVar3 = *(byte *)(param_1 + 0x6a);
  lVar7 = 0x90;
  fVar10 = (float)bVar3;
  if (bVar3 != 1) {
    param_1[0x66] = ((float)(int)*(short *)(param_1 + 10) / *param_1) * fVar10;
    param_1[0x67] = ((float)(int)*(short *)((longlong)param_1 + 0x2a) / param_1[1]) * fVar10;
  }
  local_e8[0] = DAT_1402d22d0;
  fVar12 = param_1[0xb];
  fVar2 = param_1[3];
  fVar10 = DAT_1402d22d0 / fVar10;
  if (bVar3 == 1) {
    fVar13 = 0.0;
    fVar11 = 0.0;
    fVar14 = DAT_1402d216c;
  }
  else {
    auVar4 = vcvtdq2ps_avx(ZEXT416(bVar3 - 1));
    auVar5 = vcvtdq2ps_avx(ZEXT116(*(byte *)((longlong)param_1 + 0x1a9)));
    auVar6 = vcvtdq2ps_avx(ZEXT116(*(byte *)((longlong)param_1 + 0x1aa)));
    fVar13 = auVar4._0_4_ - (auVar5._0_4_ + auVar5._0_4_);
    fVar11 = auVar4._0_4_ - (auVar6._0_4_ + auVar6._0_4_);
  }
  param_1[0x3f] = 1.0;
  param_1[0x34] = param_1[2] / (*param_1 * fVar14 * fVar10);
  fVar9 = local_e8[0] / (fVar12 - fVar2);
  param_1[0x39] = param_1[2] / (param_1[1] * fVar14 * fVar10);
  fVar10 = fVar12 * DAT_1402d2d9c;
  param_1[0x3e] = (fVar2 + fVar12) * fVar9;
  param_1[0x3c] = fVar13;
  param_1[0x3d] = fVar11;
  local_e8[5] = (float)DAT_1402d2d64;
  param_1[0x42] = fVar9 * fVar2 * fVar10;
  local_c0 = local_e8[5];
  param_1[0x37] = 0.0;
  param_1[0x38] = 0.0;
  param_1[0x40] = 0.0;
  param_1[0x41] = 0.0;
  param_1[0x35] = 0.0;
  param_1[0x36] = 0.0;
  param_1[0x3a] = 0.0;
  param_1[0x3b] = 0.0;
  param_1[0x43] = 0.0;
  local_a8 = *(undefined8 *)(param_1 + 0x34);
  uStack_a0 = *(undefined8 *)(param_1 + 0x36);
  uStack_98 = *(undefined8 *)(param_1 + 0x38);
  uStack_90 = *(undefined8 *)(param_1 + 0x3a);
  local_88 = *(undefined8 *)(param_1 + 0x3c);
  uStack_80 = *(undefined8 *)(param_1 + 0x3e);
  uStack_78 = *(undefined8 *)(param_1 + 0x40);
  uStack_70 = *(undefined8 *)(param_1 + 0x42);
  local_e8[4] = 0.0;
  local_c8 = 0;
  local_b8 = 0;
  local_e8[1] = 0.0;
  local_c4 = 0;
  local_b4 = 0;
  local_e8[2] = 0.0;
  local_d0 = 0;
  local_b0 = 0;
  local_e8[3] = 0.0;
  local_cc = 0;
  local_bc = 0;
  local_ac = local_e8[0];
  pfVar8 = param_1;
  FUN_140005940(&local_a8,&local_a8,local_e8);
  *(undefined8 *)(param_1 + 0x34) = local_a8;
  *(undefined8 *)(param_1 + 0x36) = uStack_a0;
  *(undefined8 *)(param_1 + 0x38) = uStack_98;
  *(undefined8 *)(param_1 + 0x3a) = uStack_90;
  *(undefined8 *)(param_1 + 0x3c) = local_88;
  *(undefined8 *)(param_1 + 0x3e) = uStack_80;
  *(undefined8 *)(param_1 + 0x40) = uStack_78;
  *(undefined8 *)(param_1 + 0x42) = uStack_70;
  puVar1 = (undefined8 *)((longlong)pfVar8 + lVar7);
  local_a8 = *puVar1;
  uStack_a0 = puVar1[1];
  uStack_98 = puVar1[2];
  uStack_90 = puVar1[3];
  puVar1 = (undefined8 *)((longlong)pfVar8 + lVar7 + 0x20);
  local_88 = *puVar1;
  uStack_80 = puVar1[1];
  uStack_78 = puVar1[2];
  uStack_70 = puVar1[3];
  FUN_140005940(&local_a8,&local_a8,param_1 + 0x14);
  *(undefined8 *)(param_1 + 0x44) = local_a8;
  *(undefined8 *)(param_1 + 0x46) = uStack_a0;
  *(undefined8 *)(param_1 + 0x48) = uStack_98;
  *(undefined8 *)(param_1 + 0x4a) = uStack_90;
  *(undefined8 *)(param_1 + 0x4c) = local_88;
  *(undefined8 *)(param_1 + 0x4e) = uStack_80;
  *(undefined8 *)(param_1 + 0x50) = uStack_78;
  *(undefined8 *)(param_1 + 0x52) = uStack_70;
  local_a8 = *(undefined8 *)(param_1 + 0x34);
  uStack_a0 = *(undefined8 *)(param_1 + 0x36);
  uStack_98 = *(undefined8 *)(param_1 + 0x38);
  uStack_90 = *(undefined8 *)(param_1 + 0x3a);
  local_88 = *(undefined8 *)(param_1 + 0x3c);
  uStack_80 = *(undefined8 *)(param_1 + 0x3e);
  uStack_78 = *(undefined8 *)(param_1 + 0x40);
  uStack_70 = *(undefined8 *)(param_1 + 0x42);
  FUN_140005940(&local_a8,&local_a8,param_1 + 0x14);
  *(undefined8 *)(param_1 + 0x54) = local_a8;
  *(undefined8 *)(param_1 + 0x56) = uStack_a0;
  *(undefined8 *)(param_1 + 0x58) = uStack_98;
  *(undefined8 *)(param_1 + 0x5a) = uStack_90;
  *(undefined8 *)(param_1 + 0x5c) = local_88;
  *(undefined8 *)(param_1 + 0x5e) = uStack_80;
  *(undefined8 *)(param_1 + 0x60) = uStack_78;
  *(undefined8 *)(param_1 + 0x62) = uStack_70;
  return;
}

