/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a5100; RVA 0xa5100
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1400a5100(longlong *param_1,undefined8 param_2,longlong param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  byte bVar6;
  undefined1 uVar7;
  longlong lVar8;
  float *pfVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  undefined4 *puVar13;
  longlong lVar14;
  float fVar15;
  float fVar17;
  float fVar16;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined1 auVar22 [64];
  float fVar23;
  undefined1 auVar24 [64];
  float local_res10 [4];
  float local_res20;
  
  uVar11 = 1;
  pfVar12 = (float *)(param_1 + 0x96);
  lVar14 = 0x10;
  auVar22 = ZEXT464(DAT_1402d27b0);
  auVar24 = ZEXT464(DAT_1402d22d0);
  fVar20 = 0.0;
  do {
    if ((*(uint *)((longlong)param_1 + 0x5c) & uVar11) != 0) {
      lVar8 = param_1[1];
      bVar6 = (**(code **)(*param_1 + 0x90))(param_1);
      lVar8 = *(longlong *)(lVar8 + 0x66ee0);
      if (*(ushort *)(lVar8 + 0x2fe70) == 0) {
        puVar13 = (undefined4 *)0x0;
      }
      else if ((uint)bVar6 < (uint)*(ushort *)(lVar8 + 0x2fe72)) {
        puVar13 = *(undefined4 **)
                   (lVar8 + 0x2fcd0 +
                   ((ulonglong)((uint)bVar6 + (uint)*(ushort *)(lVar8 + 0x2fe70)) + 0xb5) * 0x10);
      }
      else {
        puVar13 = (undefined4 *)0x0;
      }
      pfVar9 = pfVar12 + -0x1e;
      FUN_1400a63f0(pfVar9,local_res10);
      auVar1 = *(undefined1 (*) [16])(pfVar12 + -4);
      auVar2 = vcmpss_avx(auVar24._0_16_,ZEXT416((uint)local_res10[0]),1);
      auVar2 = vblendvps_avx(ZEXT416((uint)local_res10[0]),auVar24._0_16_,auVar2);
      local_res10[0] = auVar2._0_4_;
      auVar2 = vshufps_avx(auVar1,auVar1,0xaa);
      fVar17 = auVar22._0_4_;
      fVar16 = *pfVar12 * fVar17 + *pfVar9;
      fVar15 = auVar1._0_4_ - fVar16;
      fVar18 = pfVar12[1] * fVar17 + pfVar12[-0x1d];
      fVar21 = pfVar12[2] * fVar17 + pfVar12[-0x1c];
      auVar3 = vshufps_avx(auVar1,auVar1,0x55);
      fVar17 = auVar3._0_4_ - fVar18;
      auVar1 = vshufps_avx(auVar1,auVar1,0xff);
      fVar23 = auVar24._0_4_;
      fVar4 = auVar1._0_4_ - fVar23;
      fVar5 = auVar2._0_4_ - fVar21;
      fVar19 = (fVar5 * (*(float *)(param_3 + 0x38) - fVar21) +
                fVar17 * (*(float *)(param_3 + 0x34) - fVar18) +
                (*(float *)(param_3 + 0x30) - fVar16) * fVar15 +
               (fVar4 * *(float *)(param_3 + 0x3c) - fVar4)) /
               (fVar4 * fVar4 + fVar5 * fVar5 + fVar17 * fVar17 + fVar15 * fVar15);
      local_res20 = local_res10[0];
      if (((fVar19 <= fVar23) && (fVar20 <= fVar19)) &&
         (fVar15 = *(float *)(param_3 + 0x30) - (fVar19 * fVar15 + fVar16),
         fVar17 = *(float *)(param_3 + 0x34) - (fVar19 * fVar17 + fVar18),
         fVar5 = *(float *)(param_3 + 0x38) - (fVar19 * fVar5 + fVar21),
         fVar4 = *(float *)(param_3 + 0x3c) - (fVar4 * fVar19 + fVar23),
         fVar15 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar17 * fVar17 + fVar15 * fVar15),
         fVar20 <= fVar15)) {
        if (fVar15 < (float)puVar13[1]) {
          *(undefined1 *)((longlong)pfVar12 + 0x2b) = 1;
          if (*(char *)(pfVar12 + -10) == '\0') {
            *(undefined1 *)((longlong)pfVar12 + 0x2a) = 1;
          }
          else {
            uVar7 = 0;
            if (*(char *)(pfVar12 + -10) == '\x01') {
              uVar7 = 2;
            }
            *(undefined1 *)((longlong)pfVar12 + 0x2a) = uVar7;
          }
        }
        if (fVar15 < (float)puVar13[1] + DAT_1402d271c) {
          iVar10 = 0;
          pfVar9 = (float *)((longlong)param_1 + 0x264);
          lVar8 = 0;
          do {
            if (fVar20 == *pfVar9) {
              *(float *)(lVar8 * 0x1c8 + 0x264 + (longlong)param_1) =
                   (fVar23 - fVar15 / ((float)puVar13[1] + DAT_1402d271c)) * local_res10[0];
              *(undefined4 *)(param_1 + lVar8 * 0x39 + 0x4d) = *puVar13;
              FUN_140014960((longlong)iVar10 * 0x1c8 + 0xa4 + (longlong)param_1,param_3);
              break;
            }
            iVar10 = iVar10 + 1;
            lVar8 = lVar8 + 1;
            pfVar9 = pfVar9 + 0x72;
          } while (lVar8 < 2);
        }
      }
      auVar22 = ZEXT464(DAT_1402d27b0);
    }
    uVar11 = uVar11 << 1 | (uint)((int)uVar11 < 0);
    pfVar12 = pfVar12 + 0x2a;
    lVar14 = lVar14 + -1;
    if (lVar14 == 0) {
      return param_2;
    }
  } while( true );
}

