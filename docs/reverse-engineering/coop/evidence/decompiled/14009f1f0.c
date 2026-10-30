/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14009f1f0; RVA 0x9f1f0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14009f1f0(longlong param_1)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  undefined2 uVar6;
  longlong lVar7;
  longlong lVar8;
  float *pfVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  float fVar13;
  undefined8 uVar14;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  float fVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  undefined1 auVar21 [64];
  undefined1 auVar22 [64];
  float fVar23;
  undefined4 uVar24;
  undefined1 auVar25 [64];
  float local_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  float local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  float local_cc;
  undefined4 local_c8;
  
  auVar21 = ZEXT464(DAT_1402d2a1c);
  auVar22 = ZEXT464(DAT_1402d2504);
  auVar25 = ZEXT464(DAT_1402d25ec);
  pfVar9 = (float *)(param_1 + 0xa8);
  lVar12 = param_1 + 0x80;
  iVar11 = 0;
  uVar10 = 1;
  fVar17 = DAT_1402d22d0;
  fVar18 = DAT_1402d2570;
  fVar19 = DAT_1402d2c24;
  uVar20 = DAT_1402d2080;
  fVar23 = DAT_1402d2168;
  uVar24 = DAT_1402d27f4;
  do {
    if ((*(uint *)(param_1 + 0x5c) & uVar10) != 0) {
      auVar16 = *(undefined1 (*) [16])(pfVar9 + -10);
      if ((*(byte *)((longlong)pfVar9 + 0x2a) != 0xff) &&
         (*(byte *)((longlong)pfVar9 + 0x2b) != 0xff)) {
        lVar7 = (ulonglong)*(byte *)((longlong)pfVar9 + 0x2b) * 0x520;
        lVar8 = *(longlong *)
                 (*(longlong *)
                   (**(longlong **)(param_1 + 0x10) +
                   (ulonglong)*(byte *)((longlong)pfVar9 + 0x2a) * 8) + 0x110);
        if ((*(byte *)(lVar8 + 0x1f8 + lVar7) & 8) != 0) {
          auVar15 = *(undefined1 (*) [16])(lVar8 + 600 + lVar7);
          auVar2 = vshufps_avx(auVar15,auVar15,0x55);
          auVar3 = vshufps_avx(auVar16,auVar16,0x55);
          fVar13 = auVar2._0_4_ - auVar3._0_4_;
          fVar4 = auVar15._0_4_ - auVar16._0_4_;
          auVar15 = vshufps_avx(auVar15,auVar15,0xaa);
          auVar16 = vshufps_avx(auVar16,auVar16,0xaa);
          fVar5 = auVar15._0_4_ - auVar16._0_4_;
          if (fVar5 * fVar5 + fVar13 * fVar13 + fVar4 * fVar4 <= fVar19) {
            *(undefined2 *)((longlong)pfVar9 + 0x2a) = 0xffff;
          }
        }
      }
      uVar14 = FUN_140090cc0(param_1,lVar12,iVar11);
      if ((*(byte *)((longlong)pfVar9 + 0x2a) != 0xff) &&
         (*(byte *)((longlong)pfVar9 + 0x2b) != 0xff)) {
        lVar8 = *(longlong *)
                 (*(longlong *)
                   (**(longlong **)(param_1 + 0x10) +
                   (ulonglong)*(byte *)((longlong)pfVar9 + 0x2a) * 8) + 0x110) +
                (ulonglong)*(byte *)((longlong)pfVar9 + 0x2b) * 0x520;
        fVar13 = (float)FUN_140090910(pfVar9 + -10);
        auVar16 = *(undefined1 (*) [16])(lVar8 + 600);
        fVar13 = fVar13 * fVar23;
        local_f8 = fVar13 * (auVar16._0_4_ - pfVar9[2]) + auVar16._0_4_;
        auVar15 = vshufps_avx(auVar16,auVar16,0x55);
        auVar2 = vshufps_avx(auVar16,auVar16,0x55);
        fStack_f4 = fVar13 * (auVar15._0_4_ - pfVar9[3]) + auVar2._0_4_;
        auVar15 = vshufps_avx(auVar16,auVar16,0xaa);
        auVar2 = vshufps_avx(auVar16,auVar16,0xaa);
        fStack_f0 = fVar13 * (auVar15._0_4_ - pfVar9[4]) + auVar2._0_4_;
        auVar15 = vshufps_avx(auVar16,auVar16,0xff);
        pfVar9[2] = *(float *)(lVar8 + 600);
        pfVar9[3] = *(float *)(lVar8 + 0x25c);
        auVar16 = vshufps_avx(auVar16,auVar16,0xff);
        pfVar9[4] = *(float *)(lVar8 + 0x260);
        fStack_ec = fVar13 * (auVar15._0_4_ - pfVar9[5]) + auVar16._0_4_;
        pfVar9[5] = *(float *)(lVar8 + 0x264);
        FUN_1400907a0(param_1,pfVar9 + -10,lVar8,&local_f8);
        local_e8 = CONCAT44(fStack_f4,local_f8);
        uStack_e0 = CONCAT44(fStack_ec,fStack_f0);
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (**(longlong **)(param_1 + 0x10) +
                             (ulonglong)*(byte *)((longlong)pfVar9 + 0x2a) * 8) + 0x110) + 0x1fc +
                         (ulonglong)*(byte *)((longlong)pfVar9 + 0x2b) * 0x520);
        *puVar1 = *puVar1 | 0x4000000;
        auVar16._0_4_ = (float)*(byte *)(param_1 + 0x30);
        auVar16._4_12_ = SUB1612(ZEXT816(0),4);
        uVar14 = FUN_140090a20(pfVar9 + -10,&local_e8,auVar16._0_8_,auVar25._0_8_,uVar24);
      }
      FUN_1400904d0(uVar14,pfVar9 + -10,auVar22._0_8_,auVar21._0_8_,uVar20);
      auVar15._0_4_ = pfVar9[-10] + pfVar9[-2];
      auVar15._4_4_ = pfVar9[-9] + pfVar9[-1];
      auVar15._8_4_ = pfVar9[-8] + *pfVar9;
      auVar15._12_4_ = pfVar9[-7] + pfVar9[1];
      *(undefined1 (*) [16])(pfVar9 + -10) = auVar15;
      if (*(longlong *)(param_1 + 8) != 0) {
        local_d4 = vextractps_avx(auVar15,1);
        local_d0 = vextractps_avx(auVar15,2);
        local_c8 = 1;
        local_d8 = auVar15._0_4_;
        local_cc = fVar17;
        uVar6 = FUN_140035b10(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x66ee0),0x30,&local_d8,
                              *(undefined2 *)(pfVar9 + 0xd),0xffff);
        *(undefined2 *)(pfVar9 + 0xd) = uVar6;
      }
      auVar16 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x30)));
      pfVar9[0xb] = fVar17 / auVar16._0_4_ + pfVar9[0xb];
      fVar13 = SQRT(pfVar9[1] * pfVar9[1] +
                    *pfVar9 * *pfVar9 + pfVar9[-1] * pfVar9[-1] + pfVar9[-2] * pfVar9[-2]) +
               pfVar9[8];
      pfVar9[8] = fVar13;
      if (fVar18 * *(float *)(*(longlong *)(pfVar9 + 6) + 0x14) < fVar13) {
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (**(longlong **)(param_1 + 0x10) +
                             (ulonglong)*(byte *)(pfVar9 + 10) * 8) + 0x110) + 0x1fc +
                         (ulonglong)*(byte *)((longlong)pfVar9 + 0x29) * 0x520);
        *puVar1 = *puVar1 | 0x1000000;
        FUN_140093480(param_1,*(undefined2 *)(pfVar9 + 0xd));
        *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & ~uVar10;
      }
    }
    iVar11 = iVar11 + 1;
    uVar10 = uVar10 << 1 | (uint)((int)uVar10 < 0);
    pfVar9 = pfVar9 + 0x1a;
    lVar12 = lVar12 + 0x68;
  } while (iVar11 < 0x10);
  return;
}

