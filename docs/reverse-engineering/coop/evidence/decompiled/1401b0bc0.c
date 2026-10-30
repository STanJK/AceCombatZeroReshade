/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b0bc0; RVA 0x1b0bc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401b0bc0(float *param_1,undefined1 (*param_2) [16])

{
  int *piVar1;
  float fVar2;
  undefined1 auVar3 [16];
  byte bVar4;
  byte bVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined4 uVar9;
  float *pfVar10;
  longlong lVar11;
  float *pfVar12;
  float fVar13;
  undefined8 uVar14;
  float fVar15;
  undefined1 local_38 [32];
  
  lVar11 = *(longlong *)
            (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
            0x110);
  bVar4 = *(byte *)(lVar11 + 0x237);
  bVar5 = *(byte *)(lVar11 + 0x236);
  if (bVar5 == 0xff || bVar4 == 0xff) {
    lVar11 = 0;
  }
  else {
    lVar11 = (ulonglong)bVar4 * 0x520 +
             *(longlong *)
              (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)bVar5 * 8) + 0x110)
    ;
  }
  if (((uint)param_1[0x19f] & 1) != 0) {
    param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffe);
  }
  fVar13 = (float)DAT_14033d9d1 * DAT_1402d2168 + (float)(int)param_1[0x198];
  if (((float)*(uint *)(param_2[2] + 8) <= fVar13) || (lVar11 != *(longlong *)param_2[2])) {
    auVar3 = *param_2;
    auVar6 = vmaxss_avx(ZEXT416((uint)((fVar13 - (float)*(uint *)(param_2[2] + 8)) *
                                      (DAT_1402d2168 / (float)DAT_14033d9d1))),ZEXT816(0));
    auVar6 = vminss_avx(auVar6,ZEXT416((uint)DAT_1402d22d0));
    fVar15 = auVar6._0_4_;
    fVar13 = DAT_1402d22d0 - fVar15;
    fVar13 = (fVar13 * fVar13 * fVar13 +
             fVar15 * DAT_1402d241c * fVar15 * fVar13 * DAT_1402d1ef4 +
             fVar15 * DAT_1402d241c * fVar13 * fVar13 * DAT_1402d1ff8) * DAT_1402d1fa8;
    param_1[4] = fVar13 * auVar3._0_4_ + param_1[4];
    auVar6 = vshufps_avx(auVar3,auVar3,0x55);
    param_1[5] = fVar13 * auVar6._0_4_ + param_1[5];
    auVar3 = vshufps_avx(auVar3,auVar3,0xaa);
    param_1[6] = fVar13 * auVar3._0_4_ + param_1[6];
    *param_1 = *(float *)param_2[1];
    param_1[1] = *(float *)(param_2[1] + 4);
    param_1[2] = *(float *)(param_2[1] + 8);
    param_1[3] = *(float *)(param_2[1] + 0xc);
  }
  else {
    auVar3 = *(undefined1 (*) [16])(lVar11 + 600);
    auVar6 = vshufps_avx(auVar3,auVar3,0x55);
    fVar13 = *(float *)(*param_2 + 4);
    auVar7 = vshufps_avx(auVar3,auVar3,0xaa);
    fVar15 = *(float *)(*param_2 + 8);
    auVar8 = vshufps_avx(auVar3,auVar3,0xff);
    fVar2 = *(float *)(*param_2 + 0xc);
    param_1[4] = auVar3._0_4_ + *(float *)*param_2;
    param_1[5] = auVar6._0_4_ + fVar13;
    param_1[6] = auVar7._0_4_ + fVar15;
    param_1[7] = auVar8._0_4_ + fVar2;
    *param_1 = *(float *)(lVar11 + 600);
    param_1[1] = *(float *)(lVar11 + 0x25c);
    param_1[2] = *(float *)(lVar11 + 0x260);
    param_1[3] = *(float *)(lVar11 + 0x264);
    *(undefined4 *)param_2[1] = *(undefined4 *)(lVar11 + 600);
    *(undefined4 *)(param_2[1] + 4) = *(undefined4 *)(lVar11 + 0x25c);
    *(undefined4 *)(param_2[1] + 8) = *(undefined4 *)(lVar11 + 0x260);
    *(undefined4 *)(param_2[1] + 0xc) = *(undefined4 *)(lVar11 + 0x264);
  }
  pfVar12 = param_1 + 4;
  uVar14 = FUN_1401aa420(param_1,DAT_1402d2504,0xf);
  pfVar10 = (float *)FUN_1401aa540(uVar14,local_38);
  *param_1 = *pfVar10 + *param_1;
  param_1[1] = pfVar10[1] + param_1[1];
  param_1[2] = pfVar10[2] + param_1[2];
  uVar9 = DAT_1402d273c;
  param_1[3] = pfVar10[3] + param_1[3];
  uVar14 = FUN_1401b4a20(param_1,pfVar12,uVar9,1);
  FUN_1401b4110(uVar14,param_1 + 8,pfVar12,param_1);
  auVar3 = vpcmpeqd_avx(ZEXT416(*(uint *)(*(longlong *)(param_1 + 0x1ae) + 0xa8790) & 0x10),
                        SUB6416(ZEXT464(0),0));
  auVar3 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar3);
  param_1[0x10c] = auVar3._0_4_;
  FUN_1401b5120(param_1,pfVar12,param_1 + 8);
  piVar1 = (int *)(param_2[2] + 0xc);
  *piVar1 = *piVar1 + -1;
  return *piVar1 == 0;
}

