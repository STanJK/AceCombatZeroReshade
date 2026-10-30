/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ad010; RVA 0x1ad010
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401ad010(undefined1 (*param_1) [16],undefined8 param_2,undefined8 param_3,float param_4,
                  longlong param_5,int param_6,char param_7)

{
  undefined1 (*pauVar1) [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  longlong lVar4;
  bool bVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  float fVar9;
  float fVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  float fVar13;
  undefined1 local_68 [96];
  
  pauVar1 = param_1 + 1;
  lVar4 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  auVar2 = *(undefined1 (*) [16])(lVar4 + 600);
  auVar3 = *(undefined1 (*) [16])(lVar4 + 600);
  auVar6 = vshufps_avx(auVar2,auVar2,0x55);
  auVar7 = vshufps_avx(auVar2,auVar2,0xaa);
  fVar13 = auVar3._0_4_ - *(float *)*pauVar1;
  auVar8 = vshufps_avx(auVar3,auVar3,0x55);
  fVar9 = auVar8._0_4_ - *(float *)(param_1[1] + 4);
  auVar3 = vshufps_avx(auVar3,auVar3,0xaa);
  fVar10 = auVar3._0_4_ - *(float *)(param_1[1] + 8);
  fVar13 = SQRT(fVar10 * fVar10 + fVar9 * fVar9 + fVar13 * fVar13);
  if (DAT_1402d2994 <= fVar13) {
    if (DAT_1402d2a98 <= fVar13) {
      fVar13 = DAT_1402d1fd8;
    }
    else {
      fVar13 = (fVar13 - DAT_1402d2994) * (fVar13 - DAT_1402d2994);
      fVar13 = (-(fVar13 * DAT_1402d1d08) + DAT_1402d22d0) * DAT_1402d224c + fVar13 * DAT_1402d1d00;
    }
  }
  else {
    fVar13 = DAT_1402d224c;
  }
  *(float *)(param_5 + 0x20) =
       fVar13 * (auVar2._0_4_ - *(float *)(param_5 + 0x20)) + *(float *)(param_5 + 0x20);
  *(float *)(param_5 + 0x24) =
       fVar13 * (auVar6._0_4_ - *(float *)(param_5 + 0x24)) + *(float *)(param_5 + 0x24);
  *(float *)(param_5 + 0x28) =
       fVar13 * (auVar7._0_4_ - *(float *)(param_5 + 0x28)) + *(float *)(param_5 + 0x28);
  *(undefined4 *)*param_1 = *(undefined4 *)(param_5 + 0x20);
  *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(param_5 + 0x24);
  *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(param_5 + 0x28);
  *(undefined4 *)(*param_1 + 0xc) = *(undefined4 *)(param_5 + 0x2c);
  if (param_6 == 1) {
    auVar2 = *param_1;
    fVar13 = auVar2._0_4_ - *(float *)*pauVar1;
    auVar3 = vshufps_avx(auVar2,auVar2,0x55);
    fVar9 = auVar3._0_4_ - *(float *)(param_1[1] + 4);
    auVar2 = vshufps_avx(auVar2,auVar2,0xaa);
    fVar10 = auVar2._0_4_ - *(float *)(param_1[1] + 8);
    fVar13 = SQRT(fVar10 * fVar10 + fVar9 * fVar9 + fVar13 * fVar13) * *(float *)(param_1[10] + 4) *
             (DAT_1402d2168 / param_4);
    bVar5 = DAT_1402d291c <= fVar13;
    *(float *)param_1[0x43] = fVar13;
    if (bVar5) {
      if (DAT_1402d2a54 <= fVar13) {
        *(undefined4 *)param_1[0x43] = 0x45800000;
      }
    }
    else {
      *(undefined4 *)param_1[0x43] = 0x44000000;
    }
  }
  FUN_1401b4110(param_5,param_1 + 2,pauVar1,param_1);
  if (param_7 == '\0') {
    if ((*(uint *)(param_1[0x67] + 0xc) & 8) == 0) {
      if ((*(uint *)(param_1[0x67] + 0xc) & 0x10) == 0) {
        uVar11 = 0xf;
        uVar12 = DAT_1402d1ecc;
      }
      else {
        uVar11 = 0x14;
        uVar12 = DAT_1402d1efc;
      }
    }
    else {
      uVar11 = 0x14;
      uVar12 = DAT_1402d1f38;
    }
    uVar11 = FUN_1401aa420(param_1,uVar12,uVar11);
    FUN_1401aa540(uVar11,local_68);
    FUN_140203050(param_1 + 2,local_68,param_1 + 2);
  }
  return;
}

