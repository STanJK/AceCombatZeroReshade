/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401accb0; RVA 0x1accb0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401accb0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined1 (*param_4) [16]
                  )

{
  undefined1 (*pauVar1) [16];
  float *pfVar2;
  float *pfVar3;
  undefined1 auVar4 [16];
  longlong lVar5;
  float fVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  fVar6 = DAT_1402d241c;
  fVar12 = DAT_1402d22d0;
  fVar14 = DAT_1402d1ff8;
  fVar13 = DAT_1402d1ef4;
  pauVar1 = (undefined1 (*) [16])(param_1 + 0x10);
  pfVar2 = (float *)(param_1 + 0x18);
  lVar5 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  if ((*(uint *)(param_1 + 0x67c) & 8) == 0) {
    pfVar3 = (float *)(param_1 + 0x14);
    if ((*(uint *)(param_1 + 0x67c) & 0x10) == 0) {
      *(float *)*pauVar1 = *(float *)param_4[1] + *(float *)*pauVar1;
      *pfVar3 = *(float *)(param_4[1] + 4) + *pfVar3;
      *pfVar2 = *(float *)(param_4[1] + 8) + *pfVar2;
      *(float *)(param_1 + 0x1c) = *(float *)(param_4[1] + 0xc) + *(float *)(param_1 + 0x1c);
    }
    else {
      *(undefined4 *)*pauVar1 = *(undefined4 *)param_4[3];
      *pfVar3 = *(float *)(param_4[3] + 4);
      *pfVar2 = *(float *)(param_4[3] + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_4[3] + 0xc);
    }
  }
  else {
    pfVar3 = (float *)(param_1 + 0x14);
    fVar15 = ((float)*(int *)(param_1 + 0x660) - (float)*(uint *)(param_1 + 0x664)) /
             (float)DAT_14033d9d1;
    if (DAT_1402d1ff8 <= fVar15) {
      if (DAT_1402d23c0 <= fVar15) {
        auVar4 = param_4[3];
        auVar10 = vshufps_avx(auVar4,auVar4,0x55);
        fVar17 = *(float *)(*param_4 + 4);
        auVar7 = vshufps_avx(auVar4,auVar4,0xaa);
        fVar18 = *(float *)(*param_4 + 8);
        auVar8 = vshufps_avx(auVar4,auVar4,0xff);
        fVar15 = auVar8._0_4_ + *(float *)(*param_4 + 0xc);
        *(float *)*pauVar1 = auVar4._0_4_ + *(float *)*param_4;
        *pfVar3 = auVar10._0_4_ + fVar17;
        *pfVar2 = auVar7._0_4_ + fVar18;
      }
      else {
        fVar15 = fVar15 - DAT_1402d1ff8;
        fVar17 = fVar15 * DAT_1402d2178;
        fVar18 = (DAT_1402d22d0 - fVar17) * DAT_1402d241c;
        auVar4 = *param_4;
        auVar10 = param_4[3];
        auVar7 = vshufps_avx(auVar4,auVar4,0x55);
        fVar17 = fVar17 * fVar15 * fVar15 * DAT_1402d20d4 +
                 (DAT_1402d22d0 - fVar17) * fVar18 * fVar17 * DAT_1402d1ef4 +
                 fVar18 * fVar17 * fVar17 * DAT_1402d22a0;
        *(float *)*pauVar1 = fVar17 * auVar4._0_4_ + auVar10._0_4_;
        auVar8 = vshufps_avx(auVar10,auVar10,0x55);
        auVar9 = vshufps_avx(auVar4,auVar4,0xaa);
        *pfVar3 = fVar17 * auVar7._0_4_ + auVar8._0_4_;
        auVar7 = vshufps_avx(auVar10,auVar10,0xaa);
        auVar10 = vshufps_avx(auVar10,auVar10,0xff);
        auVar4 = vshufps_avx(auVar4,auVar4,0xff);
        fVar15 = fVar17 * auVar4._0_4_ + auVar10._0_4_;
        *pfVar2 = fVar17 * auVar9._0_4_ + auVar7._0_4_;
      }
    }
    else {
      *(undefined4 *)*pauVar1 = *(undefined4 *)param_4[3];
      *pfVar3 = *(float *)(param_4[3] + 4);
      *pfVar2 = *(float *)(param_4[3] + 8);
      fVar15 = *(float *)(param_4[3] + 0xc);
    }
    *(float *)(param_1 + 0x1c) = fVar15;
  }
  auVar4 = *pauVar1;
  fVar15 = auVar4._0_4_ - *(float *)(lVar5 + 600);
  auVar10 = vshufps_avx(auVar4,auVar4,0x55);
  fVar17 = auVar10._0_4_ - *(float *)(lVar5 + 0x25c);
  auVar4 = vshufps_avx(auVar4,auVar4,0xaa);
  fVar18 = auVar4._0_4_ - *(float *)(lVar5 + 0x260);
  fVar19 = SQRT(fVar18 * fVar18 + fVar17 * fVar17 + fVar15 * fVar15);
  if (fVar19 < DAT_1402d2604) {
    if (fVar19 != 0.0) {
      fVar16 = fVar12 / fVar19;
      fVar15 = fVar15 * fVar16;
      fVar17 = fVar17 * fVar16;
      fVar18 = fVar18 * fVar16;
    }
    fVar11 = DAT_1402d2604 - fVar19;
    fVar16 = fVar11 * DAT_1402d1f54;
    fVar12 = fVar12 - fVar16;
    fVar6 = fVar12 * fVar6;
    fVar19 = (fVar16 * fVar11 * fVar11 * DAT_1402d1e14 +
             fVar6 * fVar16 * fVar16 * fVar14 + fVar6 * fVar12 * fVar16 * fVar13) * fVar19;
    *(float *)*pauVar1 = fVar19 * fVar15 + *(float *)*pauVar1;
    *(float *)(param_1 + 0x14) = fVar17 * fVar19 + *(float *)(param_1 + 0x14);
    *pfVar2 = fVar18 * fVar19 + *pfVar2;
  }
  FUN_1401b4a20(param_1,pauVar1,DAT_1402d2968,0);
  return;
}

