/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001df10; RVA 0x1df10
 * Ghidra-generated research pseudocode, inferred types, not original source. */

float * FUN_14001df10(float *param_1,undefined1 (*param_2) [16],undefined1 (*param_3) [16],
                     int param_4)

{
  undefined1 (*pauVar1) [16];
  float fVar2;
  float fVar3;
  float fVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  float fVar15;
  float fVar16;
  float fVar17;
  undefined1 auVar18 [64];
  float fVar19;
  float fVar20;
  undefined1 auVar21 [64];
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  
  param_1[0x18] = (float)param_4;
  if (param_2 == (undefined1 (*) [16])0x0) {
    if (param_3 == (undefined1 (*) [16])0x0) {
      return param_1;
    }
    param_1[0x16] = *(float *)(param_3[5] + 8);
    param_1[0x17] = *(float *)(param_3[5] + 0xc);
    *(undefined1 *)(param_1 + 0x19) = param_3[6][4];
    *param_1 = *(float *)*param_3;
    param_1[1] = *(float *)(*param_3 + 4);
    param_1[2] = *(float *)(*param_3 + 8);
    param_1[3] = *(float *)(*param_3 + 0xc);
    param_1[4] = *(float *)param_3[1];
    param_1[5] = *(float *)(param_3[1] + 4);
    param_1[6] = *(float *)(param_3[1] + 8);
    fVar15 = *(float *)(param_3[1] + 0xc);
  }
  else {
    param_1[0x16] = *(float *)(param_2[5] + 8);
    param_1[0x17] = *(float *)(param_2[5] + 0xc);
    *(undefined1 *)(param_1 + 0x19) = param_2[6][4];
    fVar15 = DAT_1402d2108;
    if (param_3 != (undefined1 (*) [16])0x0) {
      fVar16 = *(float *)param_2[6];
      if (fVar16 != *(float *)param_3[6]) {
        auVar5 = param_3[2];
        fVar20 = ((float)param_4 - fVar16) / (*(float *)param_3[6] - fVar16);
        auVar21 = ZEXT464((uint)fVar20);
        fVar16 = *(float *)param_2[2];
        fVar17 = DAT_1402d22d0 - fVar20;
        param_1[8] = fVar16;
        fVar2 = *(float *)(param_2[2] + 4);
        param_1[9] = fVar2;
        fVar3 = *(float *)(param_2[2] + 8);
        param_1[10] = fVar3;
        fVar4 = *(float *)(param_2[2] + 0xc);
        param_1[8] = fVar17 * fVar16 + auVar5._0_4_ * fVar20;
        auVar9 = vshufps_avx(auVar5,auVar5,0x55);
        param_1[9] = fVar17 * fVar2 + auVar9._0_4_ * fVar20;
        auVar9 = vshufps_avx(auVar5,auVar5,0xaa);
        param_1[10] = fVar17 * fVar3 + auVar9._0_4_ * fVar20;
        auVar5 = vshufps_avx(auVar5,auVar5,0xff);
        param_1[0xb] = fVar17 * fVar4 + auVar5._0_4_ * fVar20;
        if (((*(float *)*param_2 == *(float *)*param_3) &&
            (*(float *)(*param_3 + 4) == *(float *)(*param_2 + 4))) &&
           (*(float *)(*param_3 + 8) == *(float *)(*param_2 + 8))) {
          *param_1 = *(float *)*param_2;
          param_1[1] = *(float *)(*param_2 + 4);
          param_1[2] = *(float *)(*param_2 + 8);
          fVar16 = *(float *)(*param_2 + 0xc);
        }
        else {
          fVar2 = (*(float *)param_3[6] - *(float *)param_2[6]) * fVar15;
          auVar5 = param_2[2];
          auVar9 = *param_2;
          fVar19 = (float)((uint)fVar2 ^ DAT_1402d3770);
          auVar6 = param_3[2];
          auVar7 = *param_3;
          fVar3 = fVar17 * fVar17 * fVar17;
          fVar4 = fVar17 * DAT_1402d241c * fVar17 * fVar20;
          fVar8 = fVar17 * DAT_1402d241c * fVar20 * fVar20;
          auVar10 = vshufps_avx(auVar6,auVar6,0x55);
          fVar20 = fVar20 * fVar20 * fVar20;
          *param_1 = auVar7._0_4_ * fVar20 +
                     fVar8 * (auVar6._0_4_ * fVar19 + auVar7._0_4_) +
                     fVar4 * (auVar5._0_4_ * fVar2 + auVar9._0_4_) + fVar3 * auVar9._0_4_;
          auVar11 = vshufps_avx(auVar9,auVar9,0x55);
          auVar12 = vshufps_avx(auVar5,auVar5,0x55);
          auVar13 = vshufps_avx(auVar7,auVar7,0x55);
          auVar14 = vshufps_avx(auVar9,auVar9,0xaa);
          param_1[1] = auVar13._0_4_ * fVar20 +
                       fVar8 * (auVar10._0_4_ * fVar19 + auVar13._0_4_) +
                       fVar4 * (auVar12._0_4_ * fVar2 + auVar11._0_4_) + fVar3 * auVar11._0_4_;
          fVar15 = DAT_1402d2108;
          auVar10 = vshufps_avx(auVar5,auVar5,0xaa);
          auVar11 = vshufps_avx(auVar7,auVar7,0xaa);
          auVar12 = vshufps_avx(auVar6,auVar6,0xaa);
          auVar9 = vshufps_avx(auVar9,auVar9,0xff);
          auVar7 = vshufps_avx(auVar7,auVar7,0xff);
          auVar5 = vshufps_avx(auVar5,auVar5,0xff);
          auVar6 = vshufps_avx(auVar6,auVar6,0xff);
          fVar16 = fVar20 * auVar7._0_4_ +
                   fVar8 * (auVar6._0_4_ * fVar19 + auVar7._0_4_) +
                   fVar4 * (auVar5._0_4_ * fVar2 + auVar9._0_4_) + fVar3 * auVar9._0_4_;
          param_1[2] = auVar11._0_4_ * fVar20 +
                       fVar8 * (auVar12._0_4_ * fVar19 + auVar11._0_4_) +
                       fVar4 * (auVar10._0_4_ * fVar2 + auVar14._0_4_) + fVar3 * auVar14._0_4_;
        }
        auVar18 = ZEXT464((uint)fVar15);
        param_1[3] = fVar16;
        pauVar1 = param_2 + 1;
        if (((*(float *)*pauVar1 == *(float *)param_3[1]) &&
            (*(float *)(param_3[1] + 4) == *(float *)(param_2[1] + 4))) &&
           (*(float *)(param_3[1] + 8) == *(float *)(param_2[1] + 8))) {
          param_1[4] = *(float *)*pauVar1;
          param_1[5] = *(float *)(param_2[1] + 4);
          param_1[6] = *(float *)(param_2[1] + 8);
          param_1[7] = *(float *)(param_2[1] + 0xc);
          return param_1;
        }
        local_d8 = ZEXT816(0);
        FUN_140203270(local_d8,pauVar1,param_2 + 3,DAT_1402d2d1c);
        local_e8 = 0;
        uStack_e0 = 0;
        FUN_140203270(&local_e8,param_3 + 1,param_3 + 3,auVar18._0_8_);
        local_b8 = 0;
        uStack_b0 = 0;
        FUN_140203270(&local_b8,pauVar1,param_3 + 1,auVar21._0_8_);
        local_c8 = 0;
        uStack_c0 = 0;
        FUN_140203270(&local_c8,local_d8,&local_e8,auVar21._0_8_);
        FUN_140203270(param_1 + 4,&local_b8,&local_c8,(fVar17 + fVar17) * auVar21._0_4_);
        return param_1;
      }
    }
    *param_1 = *(float *)*param_2;
    param_1[1] = *(float *)(*param_2 + 4);
    param_1[2] = *(float *)(*param_2 + 8);
    param_1[3] = *(float *)(*param_2 + 0xc);
    param_1[4] = *(float *)param_2[1];
    param_1[5] = *(float *)(param_2[1] + 4);
    param_1[6] = *(float *)(param_2[1] + 8);
    fVar15 = *(float *)(param_2[1] + 0xc);
  }
  param_1[7] = fVar15;
  return param_1;
}

