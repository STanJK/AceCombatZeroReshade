/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ad2a0; RVA 0x1ad2a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401ad2a0(undefined1 (*param_1) [16],undefined8 param_2,float param_3,undefined8 param_4,
                  undefined1 (*param_5) [16])

{
  float *pfVar1;
  undefined4 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  uint uVar7;
  undefined1 (*pauVar8) [16];
  longlong lVar9;
  longlong lVar10;
  undefined4 uVar11;
  bool bVar12;
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [64];
  undefined1 local_c8 [176];
  
  uVar7 = *(uint *)(param_1[0x67] + 0xc);
  lVar9 = CONCAT71(DAT_14033d9d8._1_7_,(undefined1)DAT_14033d9d8);
  lVar10 = 0;
  if ((uVar7 >> 9 & 1) == 0) {
    if ((((param_1[0x61][0xd] == 0xff) || (param_1[0x61][0xe] == 0xff)) ||
        (lVar10 = *(longlong *)
                   (*(longlong *)
                     (*(longlong *)(lVar9 + 0x697b8) + (ulonglong)(byte)param_1[0x61][0xd] * 8) +
                   0x110) + (ulonglong)(byte)param_1[0x61][0xe] * 0x520, lVar10 == 0)) ||
       (((byte)*(undefined4 *)(lVar10 + 0x1f0) & 3) != 3)) {
      uVar7 = uVar7 | 0x200;
      *(uint *)(param_1[0x67] + 0xc) = uVar7;
    }
    else {
      *(undefined4 *)param_5[1] = *(undefined4 *)(lVar10 + 600);
      *(undefined4 *)(param_5[1] + 4) = *(undefined4 *)(lVar10 + 0x25c);
      *(undefined4 *)(param_5[1] + 8) = *(undefined4 *)(lVar10 + 0x260);
      *(undefined4 *)(param_5[1] + 0xc) = *(undefined4 *)(lVar10 + 0x264);
      uVar7 = *(uint *)(param_1[0x67] + 0xc);
    }
  }
  fVar15 = DAT_1402d241c;
  if ((uVar7 & 0xc0) == 0) {
    *(undefined4 *)(param_5[5] + 0xc) = 0;
    return;
  }
  if ((uVar7 & 0x40) == 0) {
    if ((char)uVar7 < '\0') {
      auVar21._4_12_ = SUB1612(ZEXT816(0),4);
      auVar21._0_4_ = (float)DAT_14033d9d1 * DAT_1402d241c - (float)*(uint *)param_1[0x5c];
      auVar21 = vmaxss_avx(auVar21,ZEXT816(0));
      fVar16 = auVar21._0_4_ / (float)DAT_14033d9d1;
      if (((param_1[0x61][0xd] != 0xff) && (param_1[0x61][0xe] != 0xff)) &&
         ((lVar9 = *(longlong *)
                    (*(longlong *)
                      (*(longlong *)(lVar9 + 0x697b8) + (ulonglong)(byte)param_1[0x61][0xd] * 8) +
                    0x110) + (ulonglong)(byte)param_1[0x61][0xe] * 0x520, lVar9 != 0 &&
          ((*(byte *)(lVar9 + 0x1f0) & 1) != 0)))) {
        *(undefined4 *)param_5[1] = *(undefined4 *)(lVar9 + 600);
        *(undefined4 *)(param_5[1] + 4) = *(undefined4 *)(lVar9 + 0x25c);
        *(undefined4 *)(param_5[1] + 8) = *(undefined4 *)(lVar9 + 0x260);
        *(undefined4 *)(param_5[1] + 0xc) = *(undefined4 *)(lVar9 + 0x264);
      }
      fVar17 = DAT_1402d23c0;
      fVar14 = DAT_1402d2320;
      fVar20 = DAT_1402d2134;
      fVar19 = DAT_1402d2080;
      uVar2 = *(undefined4 *)param_1[0x43];
      uVar11 = 0x14;
      if (DAT_1402d2080 <= fVar16) {
        if (DAT_1402d2134 <= fVar16) {
          bVar12 = DAT_1402d21c4 <= fVar16;
          *(undefined4 *)param_5[2] = *(undefined4 *)param_5[1];
          *(undefined4 *)(param_5[2] + 4) = *(undefined4 *)(param_5[1] + 4);
          *(undefined4 *)(param_5[2] + 8) = *(undefined4 *)(param_5[1] + 8);
          *(undefined4 *)(param_5[2] + 0xc) = *(undefined4 *)(param_5[1] + 0xc);
          if (bVar12) {
            if (DAT_1402d22f4 <= fVar16) {
              if (DAT_1402d23a8 <= fVar16) {
                *(undefined4 *)param_1[0x43] = DAT_1402d2a08;
                fVar17 = DAT_1402d22d0;
                goto LAB_1401adb1e;
              }
              fVar16 = fVar16 - DAT_1402d22f4;
              fVar20 = fVar16 * DAT_1402d232c;
              fVar15 = (DAT_1402d22d0 - fVar20) * fVar15;
              fVar15 = fVar20 * fVar16 * fVar16 * DAT_1402d294c +
                       fVar15 * fVar20 * fVar20 * DAT_1402d28e8 +
                       fVar15 * (DAT_1402d22d0 - fVar20) * fVar20 * DAT_1402d28e4 + DAT_1402d29ec;
            }
            else {
              fVar15 = DAT_1402d29ec;
            }
          }
          else {
            fVar16 = fVar16 - fVar20;
            fVar20 = fVar16 * DAT_1402d2434;
            fVar15 = (DAT_1402d22d0 - fVar20) * fVar15;
            fVar15 = (DAT_1402d29ec - *(float *)(param_5[5] + 8)) *
                     (fVar20 * fVar16 * fVar16 * DAT_1402d2514 +
                     fVar15 * fVar20 * fVar20 * DAT_1402d22cc +
                     fVar15 * (DAT_1402d22d0 - fVar20) * fVar20 * DAT_1402d22c8) +
                     *(float *)(param_5[5] + 8);
          }
          *(float *)param_1[0x43] = fVar15;
          fVar17 = DAT_1402d236c;
          uVar11 = 0xf;
          if (DAT_1402d291c <= fVar15) {
            if (DAT_1402d2a54 < fVar15) {
              *(undefined4 *)param_1[0x43] = 0x45800000;
            }
          }
          else {
            *(undefined4 *)param_1[0x43] = 0x44000000;
          }
        }
        else {
          auVar21 = param_5[1];
          auVar13 = vshufps_avx(auVar21,auVar21,0x55);
          fVar15 = *(float *)(param_5[2] + 4);
          auVar3 = vshufps_avx(auVar21,auVar21,0xaa);
          fVar16 = *(float *)(param_5[2] + 8);
          auVar4 = vshufps_avx(auVar21,auVar21,0xff);
          fVar20 = *(float *)(param_5[2] + 0xc);
          fVar14 = DAT_1402d2520 / (float)DAT_14033d9d1;
          *(float *)param_5[2] =
               fVar14 * (auVar21._0_4_ - *(float *)param_5[2]) + *(float *)param_5[2];
          *(float *)(param_5[2] + 4) =
               fVar14 * (auVar13._0_4_ - fVar15) + *(float *)(param_5[2] + 4);
          *(float *)(param_5[2] + 8) = fVar14 * (auVar3._0_4_ - fVar16) + *(float *)(param_5[2] + 8)
          ;
          *(float *)(param_5[2] + 0xc) =
               fVar14 * (auVar4._0_4_ - fVar20) + *(float *)(param_5[2] + 0xc);
          *(undefined4 *)(param_5[5] + 8) = *(undefined4 *)param_1[0x43];
        }
      }
      else {
        auVar21 = param_5[3];
        *(float *)param_5[2] = auVar21._0_4_ * DAT_1402d2320 + *(float *)param_5[2];
        auVar13 = vshufps_avx(auVar21,auVar21,0x55);
        *(float *)(param_5[2] + 4) = auVar13._0_4_ * fVar14 + *(float *)(param_5[2] + 4);
        auVar13 = vshufps_avx(auVar21,auVar21,0xaa);
        *(float *)(param_5[2] + 8) = auVar13._0_4_ * fVar14 + *(float *)(param_5[2] + 8);
        auVar21 = vshufps_avx(auVar21,auVar21,0xff);
        *(float *)(param_5[2] + 0xc) = auVar21._0_4_ * fVar14 + *(float *)(param_5[2] + 0xc);
      }
LAB_1401adb1e:
      fVar15 = DAT_1402d2168;
      if ((*(uint *)(param_1[0x67] + 0xc) & 0x100) != 0) {
        *(undefined4 *)param_1[0x43] = uVar2;
        uVar11 = 0x14;
        fVar17 = fVar15;
      }
      *(undefined4 *)(param_5[2] + 0xc) = 0;
      auVar21 = param_5[2];
      fVar16 = (auVar21._0_4_ - *(float *)*param_5) * fVar19 + *(float *)*param_5;
      *(float *)*param_5 = fVar16;
      auVar13 = vshufps_avx(auVar21,auVar21,0x55);
      *(float *)(*param_5 + 4) =
           (auVar13._0_4_ - *(float *)(*param_5 + 4)) * fVar19 + *(float *)(*param_5 + 4);
      auVar13 = vshufps_avx(auVar21,auVar21,0xaa);
      *(float *)(*param_5 + 8) =
           (auVar13._0_4_ - *(float *)(*param_5 + 8)) * fVar19 + *(float *)(*param_5 + 8);
      auVar21 = vshufps_avx(auVar21,auVar21,0xff);
      fVar15 = auVar21._0_4_ - *(float *)(*param_5 + 0xc);
      *(float *)(*param_5 + 0xc) = fVar15 * fVar19 + *(float *)(*param_5 + 0xc);
      *(float *)*param_1 = fVar16;
      *(undefined4 *)(*param_1 + 4) = *(undefined4 *)(*param_5 + 4);
      *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_5 + 8);
      *(undefined4 *)(*param_1 + 0xc) = 0;
      if (*(int *)param_1[0x5c] == 0) {
        *(uint *)(param_1[0x67] + 0xc) = *(uint *)(param_1[0x67] + 0xc) & 0xffffff7f | 0x400;
      }
      FUN_1401b4110(fVar15,param_1 + 2,param_1 + 1,param_1);
      FUN_1401aa4b0(param_1,fVar17 * DAT_1402d1f38,uVar11);
      FUN_1401aa540(param_1,local_c8);
      FUN_140203050(param_1 + 2,local_c8,param_1 + 2);
      *(undefined4 *)(param_5[5] + 0xc) = 0;
      return;
    }
    goto LAB_1401ad7b1;
  }
  bVar12 = true;
  auVar22 = ZEXT464((uint)DAT_1402d22d0);
  auVar21 = ZEXT416((uint)DAT_1402d22d0);
  pfVar1 = (float *)((longlong)(int)*(uint *)(param_1[0x60] + 8) * 0x58 + 0x158 +
                    *(longlong *)(param_1[0x6a] + 8));
  if ((pfVar1 == (float *)0x0) ||
     (uVar7 = 1 << (*(uint *)(param_1[0x60] + 8) & 0x1f) &
              *(uint *)(*(longlong *)(param_1[0x6a] + 8) + 0x6e8), bVar12 = uVar7 == 0, uVar7 == 0))
  {
    auVar13 = param_5[2];
    fVar15 = auVar13._0_4_ + *(float *)param_5[3];
    auVar3 = vshufps_avx(auVar13,auVar13,0xff);
    fVar20 = auVar3._0_4_ + *(float *)(param_5[3] + 0xc);
    auVar3 = vshufps_avx(auVar13,auVar13,0x55);
    fVar16 = auVar3._0_4_ + *(float *)(param_5[3] + 4);
    auVar13 = vshufps_avx(auVar13,auVar13,0xaa);
    fVar19 = auVar13._0_4_ + *(float *)(param_5[3] + 8);
    bVar6 = true;
    if (bVar12) goto LAB_1401ad460;
  }
  else {
    fVar15 = *pfVar1;
    fVar16 = pfVar1[1];
    fVar19 = pfVar1[2];
    fVar20 = pfVar1[3];
    bVar6 = bVar12;
LAB_1401ad460:
    pauVar8 = param_5 + 2;
    auVar13 = vcvtdq2ps_avx(ZEXT116(DAT_14033d9d1));
    auVar13 = vmaxss_avx(ZEXT416((uint)((DAT_1402d236c -
                                        (float)*(uint *)param_1[0x5c] / auVar13._0_4_) *
                                       DAT_1402d21b0)),ZEXT816(0));
    fVar18 = auVar13._0_4_;
    fVar14 = DAT_1402d22d0 - fVar18;
    fVar17 = fVar18 * fVar18 * fVar18 +
             fVar14 * fVar14 * DAT_1402d241c * fVar18 * DAT_1402d1ef4 +
             fVar18 * fVar14 * DAT_1402d241c * fVar18 * DAT_1402d1ff8;
    auVar13 = vinsertps_avx(ZEXT416((uint)(fVar17 * (fVar15 - *(float *)*param_5) +
                                          *(float *)*param_5)),
                            ZEXT416((uint)(fVar17 * (fVar16 - *(float *)(*param_5 + 4)) +
                                          *(float *)(*param_5 + 4))),0x10);
    auVar13 = vinsertps_avx(auVar13,ZEXT416((uint)(fVar17 * (fVar19 - *(float *)(*param_5 + 8)) +
                                                  *(float *)(*param_5 + 8))),0x20);
    auVar3 = vinsertps_avx(auVar13,ZEXT416((uint)(fVar17 * (fVar20 - *(float *)(*param_5 + 0xc)) +
                                                 *(float *)(*param_5 + 0xc))),0x30);
    *param_5 = auVar3;
    auVar13 = *(undefined1 (*) [16])(param_1[0x53] + 8);
    auVar4 = vshufps_avx(auVar3,auVar3,0x55);
    *(float *)*param_1 = fVar14 * auVar13._0_4_ + auVar3._0_4_ * fVar18;
    auVar5 = vshufps_avx(auVar13,auVar13,0x55);
    auVar3 = vshufps_avx(auVar3,auVar3,0xaa);
    auVar13 = vshufps_avx(auVar13,auVar13,0xaa);
    *(float *)(*param_1 + 8) = fVar14 * auVar13._0_4_ + auVar3._0_4_ * fVar18;
    *(float *)(*param_1 + 4) = fVar14 * auVar5._0_4_ + auVar4._0_4_ * fVar18;
    *(undefined4 *)(*param_1 + 0xc) = 0;
    if (*(int *)(param_5[5] + 0xc) == 1) {
      *(float *)*pauVar8 = fVar15;
      *(float *)(param_5[2] + 4) = fVar16;
      *(float *)(param_5[2] + 8) = fVar19;
      *(float *)(param_5[2] + 0xc) = fVar20;
    }
    fVar14 = *(float *)(param_5[2] + 4);
    fVar17 = *(float *)(param_5[2] + 8);
    fVar18 = *(float *)(param_5[2] + 0xc);
    *(float *)param_5[3] = fVar15 - *(float *)*pauVar8;
    *(float *)(param_5[3] + 4) = fVar16 - fVar14;
    *(float *)(param_5[3] + 8) = fVar19 - fVar17;
    *(float *)(param_5[3] + 0xc) = fVar20 - fVar18;
    *(float *)*pauVar8 = fVar15;
    *(float *)(param_5[2] + 4) = fVar16;
    *(float *)(param_5[2] + 8) = fVar19;
    *(float *)(param_5[2] + 0xc) = fVar20;
    *(float *)param_5[1] = fVar15;
    *(float *)(param_5[1] + 4) = fVar16;
    *(float *)(param_5[1] + 8) = fVar19;
    *(float *)(param_5[1] + 0xc) = fVar20;
    if (bVar6) {
      *(undefined4 *)(param_1[0x60] + 8) = 0xffffffff;
      *(int *)param_1[0x5c] = (int)(longlong)((float)DAT_14033d9d1 * DAT_1402d241c);
      uVar7 = *(uint *)(param_1[0x67] + 0xc) & 0xfffffebf;
      *(uint *)(param_1[0x67] + 0xc) = uVar7 | 0x80;
      if (lVar10 == 0) {
        *(uint *)(param_1[0x67] + 0xc) = uVar7 | 0x180;
      }
      else {
        if (*(char *)(**(longlong **)(lVar10 + 0x1a0) + 0x6f) == '\x01') {
          fVar15 = *(float *)(**(longlong **)(lVar10 + 0x1a0) + 0x40);
        }
        else if (*(longlong **)(lVar10 + 0x3a0) == (longlong *)0x0) {
          fVar15 = DAT_1402d2698;
        }
        else {
          fVar15 = (float)(**(code **)(**(longlong **)(lVar10 + 0x3a0) + 0xa0))();
          auVar21 = auVar22._0_16_;
        }
        auVar13 = *(undefined1 (*) [16])(lVar10 + 600);
        fVar16 = auVar13._0_4_ - *(float *)param_5[1];
        auVar3 = vshufps_avx(auVar13,auVar13,0x55);
        fVar19 = auVar3._0_4_ - *(float *)(param_5[1] + 4);
        auVar13 = vshufps_avx(auVar13,auVar13,0xaa);
        fVar20 = auVar13._0_4_ - *(float *)(param_5[1] + 8);
        if (fVar15 < SQRT(fVar20 * fVar20 + fVar19 * fVar19 + fVar16 * fVar16)) {
          *(uint *)(param_1[0x67] + 0xc) = *(uint *)(param_1[0x67] + 0xc) | 0x100;
        }
      }
    }
  }
  auVar13 = *param_1;
  auVar3 = vshufps_avx(auVar13,auVar13,0x55);
  fVar15 = auVar13._0_4_ - *(float *)param_1[1];
  fVar16 = auVar3._0_4_ - *(float *)(param_1[1] + 4);
  auVar13 = vshufps_avx(auVar13,auVar13,0xaa);
  fVar19 = auVar13._0_4_ - *(float *)(param_1[1] + 8);
  auVar13._0_4_ = auVar21._0_4_ / param_3;
  auVar13._4_12_ = auVar21._4_12_;
  fVar15 = (auVar13._0_4_ *
            SQRT(fVar19 * fVar19 + fVar16 * fVar16 + fVar15 * fVar15) * *(float *)(param_1[10] + 4)
            * DAT_1402d2168 - *(float *)param_1[0x43]) * DAT_1402d1ff8 + *(float *)param_1[0x43];
  bVar12 = DAT_1402d291c <= fVar15;
  *(float *)param_1[0x43] = fVar15;
  if (bVar12) {
    if (DAT_1402d2a54 <= fVar15) {
      *(undefined4 *)param_1[0x43] = 0x45800000;
    }
  }
  else {
    *(undefined4 *)param_1[0x43] = 0x44000000;
  }
  FUN_1401b4110(auVar13._0_8_,param_1 + 2,param_1 + 1,param_1);
  FUN_1401aa4b0(param_1,DAT_1402d1eec,0x14);
  FUN_1401aa540(param_1,local_c8);
  FUN_140203050(param_1 + 2,local_c8,param_1 + 2);
LAB_1401ad7b1:
  *(undefined4 *)(param_5[5] + 0xc) = 0;
  return;
}

