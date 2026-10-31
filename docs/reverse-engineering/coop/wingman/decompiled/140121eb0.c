/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140121eb0; RVA 0x121eb0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140121eb0(longlong param_1)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  float fVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  float fVar10;
  float fVar11;
  bool bVar12;
  bool bVar13;
  char cVar14;
  undefined2 uVar15;
  undefined1 (*pauVar16) [16];
  longlong lVar17;
  undefined4 *puVar18;
  uint uVar19;
  longlong *plVar20;
  longlong *plVar21;
  int iVar22;
  undefined8 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined4 uVar28;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined4 local_158;
  float local_150;
  float local_14c;
  float local_148;
  undefined4 local_144;
  undefined1 local_138 [8];
  float fStack_130;
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined1 local_108 [8];
  float fStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [16];
  undefined1 auStack_a8 [16];
  undefined1 local_98 [16];
  undefined1 auStack_88 [16];
  
  fVar24 = DAT_1402d22d0;
  if ((*(uint *)(param_1 + 0x1f0) >> 8 & 1) == 0) {
    uVar28 = 0;
    if (*(float *)(param_1 + 0x1e0) <= 0.0) {
      if (*(char *)(param_1 + 0x248) != '\0') {
        bVar13 = true;
        pauVar16 = (undefined1 (*) [16])(*(longlong *)(param_1 + 0x178) + 0x158);
        bVar12 = false;
        uVar19 = 0;
        do {
          if ((((*(uint *)(*(longlong *)(param_1 + 0x178) + 0x6e8) >> (uVar19 & 0x1f) & 1) != 0) &&
              (pauVar16[4][2] == *(char *)(param_1 + 0x234))) &&
             (pauVar16[4][3] == *(char *)(param_1 + 0x235))) {
            auVar2 = *pauVar16;
            fVar24 = auVar2._0_4_ - *(float *)(param_1 + 0x3d8);
            auVar8 = vshufps_avx(auVar2,auVar2,0xaa);
            fVar7 = auVar8._0_4_ - *(float *)(param_1 + 0x3e0);
            auVar8 = vshufps_avx(auVar2,auVar2,0x55);
            fVar10 = auVar8._0_4_ - *(float *)(param_1 + 0x3dc);
            auVar2 = vshufps_avx(auVar2,auVar2,0xff);
            fVar11 = auVar2._0_4_ - *(float *)(param_1 + 0x3e4);
            if (fVar11 * fVar11 + fVar7 * fVar7 + fVar10 * fVar10 + fVar24 * fVar24 <= DAT_1402d2c04
               ) {
              lVar17 = *(longlong *)
                        (*(longlong *)
                          (**(longlong **)(param_1 + 0x180) + (ulonglong)(byte)pauVar16[4][4] * 8) +
                        0x110) + (ulonglong)(byte)pauVar16[4][5] * 0x520;
              if (lVar17 != 0) {
                puVar1 = (uint *)(lVar17 + 0x204);
                *puVar1 = *puVar1 | 2;
              }
              goto LAB_140122414;
            }
          }
          uVar19 = uVar19 + 1;
          pauVar16 = (undefined1 (*) [16])(pauVar16[5] + 8);
        } while ((int)uVar19 < 0x10);
        iVar22 = 0;
        bVar13 = false;
        plVar21 = (longlong *)**(undefined8 **)(param_1 + 0x180);
        iVar4 = *(int *)(*plVar21 + 0x118);
        fVar24 = DAT_1402d2c04;
        if (0 < iVar4) {
          do {
            uVar19 = 0;
            lVar17 = *(longlong *)(*plVar21 + 0x110);
            cVar14 = -1;
            lVar5 = *(longlong *)(lVar17 + 0x1b8);
            if (lVar5 != 0) {
              cVar14 = *(char *)((ulonglong)*(byte *)(lVar5 + 0x279a) + 4 +
                                *(longlong *)(lVar5 + 0xff8));
            }
            lVar17 = *(longlong *)(lVar17 + 0x1c0);
            if (lVar17 != 0) {
              cVar14 = *(char *)((ulonglong)*(byte *)(lVar17 + 0x85) + 4 +
                                **(longlong **)(lVar17 + 0x48));
            }
            lVar17 = *(longlong *)(param_1 + 0x178);
            if (cVar14 == '\r') {
              plVar20 = (longlong *)(lVar17 + 0x13b58);
LAB_1401221e8:
              do {
                if ((((*(uint *)((longlong)plVar20 + 0x5c) >> (uVar19 & 0x1f) & 1) != 0) &&
                    (pauVar16 = (undefined1 (*) [16])(**(code **)(*plVar20 + 0x68))(plVar20,uVar19),
                    pauVar16 != (undefined1 (*) [16])0x0)) &&
                   ((pauVar16[5][2] == *(char *)(param_1 + 0x234) &&
                    (pauVar16[5][3] == *(char *)(param_1 + 0x235))))) {
                  auVar2 = *pauVar16;
                  fVar7 = auVar2._0_4_ - *(float *)(param_1 + 0x3d8);
                  auVar8 = vshufps_avx(auVar2,auVar2,0xaa);
                  fVar10 = auVar8._0_4_ - *(float *)(param_1 + 0x3e0);
                  auVar8 = vshufps_avx(auVar2,auVar2,0x55);
                  fVar11 = auVar8._0_4_ - *(float *)(param_1 + 0x3dc);
                  auVar2 = vshufps_avx(auVar2,auVar2,0xff);
                  fVar25 = auVar2._0_4_ - *(float *)(param_1 + 0x3e4);
                  if (fVar25 * fVar25 + fVar10 * fVar10 + fVar11 * fVar11 + fVar7 * fVar7 <= fVar24)
                  {
                    lVar17 = *(longlong *)
                              (*(longlong *)
                                (**(longlong **)(param_1 + 0x180) +
                                (ulonglong)(byte)pauVar16[5][0] * 8) + 0x110) +
                             (ulonglong)(byte)pauVar16[5][1] * 0x520;
                    if (lVar17 != 0) {
                      puVar1 = (uint *)(lVar17 + 0x204);
                      *puVar1 = *puVar1 | 4;
                    }
                    bVar12 = true;
                    goto LAB_1401222b9;
                  }
                }
                uVar19 = uVar19 + 1;
              } while ((int)uVar19 < 0x10);
            }
            else {
              if (cVar14 == '\x0e') {
                plVar20 = (longlong *)(lVar17 + 0x13458);
                goto LAB_1401221e8;
              }
              if (cVar14 == '\x0f') {
                plVar20 = (longlong *)(lVar17 + 0x14258);
                goto LAB_1401221e8;
              }
              if (cVar14 == '\x10') {
                plVar20 = (longlong *)(lVar17 + 0x14958);
                goto LAB_1401221e8;
              }
            }
            iVar22 = iVar22 + 1;
          } while (iVar22 < iVar4);
        }
LAB_1401222b9:
        iVar22 = 0;
        lVar17 = **(longlong **)(param_1 + 0x180);
        iVar4 = *(int *)(*(longlong *)(lVar17 + 8) + 0x118);
        if (0 < iVar4) {
          do {
            uVar19 = 0;
            lVar5 = *(longlong *)(*(longlong *)(lVar17 + 8) + 0x110);
            cVar14 = -1;
            lVar6 = *(longlong *)(lVar5 + 0x1b8);
            if (lVar6 != 0) {
              cVar14 = *(char *)((ulonglong)*(byte *)(lVar6 + 0x279a) + 4 +
                                *(longlong *)(lVar6 + 0xff8));
            }
            lVar5 = *(longlong *)(lVar5 + 0x1c0);
            if (lVar5 != 0) {
              cVar14 = *(char *)((ulonglong)*(byte *)(lVar5 + 0x85) + 4 +
                                **(longlong **)(lVar5 + 0x48));
            }
            lVar5 = *(longlong *)(param_1 + 0x178);
            if (cVar14 == '\r') {
              plVar21 = (longlong *)(lVar5 + 0x13b58);
LAB_140122362:
              do {
                if ((((*(uint *)((longlong)plVar21 + 0x5c) >> (uVar19 & 0x1f) & 1) != 0) &&
                    (pauVar16 = (undefined1 (*) [16])(**(code **)(*plVar21 + 0x68))(plVar21,uVar19),
                    pauVar16 != (undefined1 (*) [16])0x0)) &&
                   ((pauVar16[5][2] == *(char *)(param_1 + 0x234) &&
                    (pauVar16[5][3] == *(char *)(param_1 + 0x235))))) {
                  auVar2 = *pauVar16;
                  fVar7 = auVar2._0_4_ - *(float *)(param_1 + 0x3d8);
                  auVar8 = vshufps_avx(auVar2,auVar2,0xaa);
                  fVar10 = auVar8._0_4_ - *(float *)(param_1 + 0x3e0);
                  auVar8 = vshufps_avx(auVar2,auVar2,0x55);
                  fVar11 = auVar8._0_4_ - *(float *)(param_1 + 0x3dc);
                  auVar2 = vshufps_avx(auVar2,auVar2,0xff);
                  fVar25 = auVar2._0_4_ - *(float *)(param_1 + 0x3e4);
                  if (fVar25 * fVar25 + fVar10 * fVar10 + fVar11 * fVar11 + fVar7 * fVar7 <= fVar24)
                  {
                    lVar17 = *(longlong *)
                              (*(longlong *)
                                (**(longlong **)(param_1 + 0x180) +
                                (ulonglong)(byte)pauVar16[5][0] * 8) + 0x110) +
                             (ulonglong)(byte)pauVar16[5][1] * 0x520;
                    if (lVar17 != 0) {
                      puVar1 = (uint *)(lVar17 + 0x204);
                      *puVar1 = *puVar1 | 4;
                    }
                    goto LAB_140122414;
                  }
                }
                uVar19 = uVar19 + 1;
              } while ((int)uVar19 < 0x10);
              if (bVar12) goto LAB_140122414;
            }
            else {
              if (cVar14 == '\x0e') {
                plVar21 = (longlong *)(lVar5 + 0x13458);
                goto LAB_140122362;
              }
              if (cVar14 == '\x0f') {
                plVar21 = (longlong *)(lVar5 + 0x14258);
                goto LAB_140122362;
              }
              if (cVar14 == '\x10') {
                plVar21 = (longlong *)(lVar5 + 0x14958);
                goto LAB_140122362;
              }
            }
            iVar22 = iVar22 + 1;
          } while (iVar22 < iVar4);
        }
        if (bVar12) {
LAB_140122414:
          _local_138 = ZEXT816(0);
          local_128 = ZEXT816(0);
          *(undefined8 *)(param_1 + 0x5f0) = 0;
          *(undefined4 *)(param_1 + 0x5f8) = *(undefined4 *)(param_1 + 0x468);
          *(undefined4 *)(param_1 + 0x5fc) = 0x3f800000;
          local_118 = _local_138;
          _local_108 = local_128;
          FUN_140202920(local_138,param_1 + 1000);
          fVar24 = *(float *)(param_1 + 0x5f4);
          fVar7 = *(float *)(param_1 + 0x5f0);
          fVar10 = *(float *)(param_1 + 0x5fc);
          fVar11 = *(float *)(param_1 + 0x5f8);
          *(float *)(param_1 + 0x5f0) =
               local_128._0_4_ * fVar24 + fVar7 * (float)local_138._0_4_ +
               local_118._0_4_ * fVar11 + fVar10 * (float)local_108._0_4_;
          auVar2 = vshufps_avx(local_128,local_128,0x55);
          auVar8 = vshufps_avx(local_118,local_118,0x55);
          *(float *)(param_1 + 0x5f4) =
               auVar2._0_4_ * fVar24 + fVar7 * (float)local_138._4_4_ +
               auVar8._0_4_ * fVar11 + fVar10 * (float)local_108._4_4_;
          uStack_160 = _UNK_1402d2f08;
          local_168 = _DAT_1402d2f00;
          local_b8 = ZEXT816(0);
          auVar2 = vshufps_avx(local_128,local_128,0xaa);
          auVar8 = vshufps_avx(local_118,local_118,0xaa);
          *(float *)(param_1 + 0x5f8) =
               auVar2._0_4_ * fVar24 + fVar7 * fStack_130 +
               auVar8._0_4_ * fVar11 + fVar10 * fStack_100;
          fVar24 = DAT_1402d2894;
          auStack_a8 = ZEXT816(0);
          *(undefined4 *)(param_1 + 0x5fc) = 0;
          fVar24 = fVar24 / (float)*(byte *)(param_1 + 0x24a);
          local_98 = local_b8;
          auStack_88 = auStack_a8;
          FUN_140202920(local_b8,&local_168);
          local_f8 = local_b8._0_8_;
          uStack_f0 = local_b8._8_8_;
          uStack_e8 = auStack_a8._0_8_;
          uStack_e0 = auStack_a8._8_8_;
          local_d8 = local_98._0_8_;
          uStack_d0 = local_98._8_8_;
          uStack_c8 = auStack_88._0_8_;
          uStack_c0 = auStack_88._8_8_;
          FUN_140005940(&local_f8,&local_f8,local_138);
          fVar25 = fVar24 * (float)uStack_d0 + (float)uStack_c0;
          fVar26 = fVar24 * local_d8._4_4_ + uStack_c8._4_4_;
          fVar27 = fVar24 * (float)local_d8 + (float)uStack_c8;
          local_168 = *(undefined8 *)(param_1 + 0x5f0);
          fVar11 = *(float *)(param_1 + 0x5fc);
          uStack_160 = *(undefined8 *)(param_1 + 0x5f8);
          fVar7 = fVar26 + *(float *)(param_1 + 0x5f4);
          fVar10 = fVar25 + *(float *)(param_1 + 0x5f8);
          *(float *)(param_1 + 0x5f4) = fVar7;
          *(float *)(param_1 + 0x5f8) = fVar10;
          *(float *)(param_1 + 0x5fc) = fVar11;
          fVar24 = *(float *)(param_1 + 0x5f0) + fVar27;
          *(float *)(param_1 + 0x5f0) = fVar24;
          auVar2 = *(undefined1 (*) [16])(param_1 + 0x3d8);
          auVar8 = vshufps_avx(auVar2,auVar2,0xaa);
          auVar9 = vshufps_avx(auVar2,auVar2,0x55);
          fVar24 = fVar24 + auVar2._0_4_;
          fVar7 = auVar9._0_4_ + fVar7;
          fVar10 = auVar8._0_4_ + fVar10;
          auVar2 = vshufps_avx(auVar2,auVar2,0xff);
          fVar11 = auVar2._0_4_ + fVar11;
          *(float *)(param_1 + 0x5ec) = fVar11;
          *(float *)(param_1 + 0x5e0) = fVar24;
          *(float *)(param_1 + 0x5e4) = fVar7;
          *(float *)(param_1 + 0x5e8) = fVar10;
          local_150 = fVar27;
          local_14c = fVar26;
          local_148 = fVar25;
          local_144 = uVar28;
          if (*(longlong *)(param_1 + 0x198) != 0) {
            local_158 = 0;
            local_168 = CONCAT44(fVar7,fVar24);
            uStack_160 = CONCAT44(fVar11,fVar10);
            uVar23 = *(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0);
            if (bVar13) {
              uVar15 = FUN_140031f80(uVar23,0x21,&local_168,0);
              *(undefined1 *)(param_1 + 0x604) = 0;
            }
            else {
              uVar15 = FUN_140031f80(uVar23,0x22,&local_168,0);
              *(undefined1 *)(param_1 + 0x604) = 1;
            }
            *(undefined2 *)(param_1 + 0x222) = uVar15;
          }
          uVar23 = FUN_1401c56d0();
          cVar14 = FUN_1401c6a00(uVar23,1,0x17,param_1 + 0x3d8,&local_150,uVar28,uVar28,uVar28,
                                 uVar28,0,0);
          if ((((cVar14 != '\0') && (lVar17 = FUN_1401c97a0(), '\x01' < *(char *)(lVar17 + 0x3dc2)))
              && (uVar3 = *(ushort *)(lVar17 + 0x138),
                 (~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar3 * 0x18) + 0x742) & 1)
                 != 0)) &&
             (puVar18 = (undefined4 *)FUN_1401c9e60(lVar17), puVar18 != (undefined4 *)0x0)) {
            *(ushort *)(puVar18 + 0x11) = uVar3;
            *(undefined2 *)((longlong)puVar18 + 0x46) = 0x17;
            *puVar18 = *(undefined4 *)(param_1 + 0x3d8);
            puVar18[1] = *(undefined4 *)(param_1 + 0x3dc);
            puVar18[2] = *(undefined4 *)(param_1 + 0x3e0);
            uVar28 = *(undefined4 *)(param_1 + 0x3e4);
            puVar18[4] = fVar27;
            puVar18[5] = fVar26;
            puVar18[6] = fVar25;
            puVar18[3] = uVar28;
            *(undefined8 *)(puVar18 + 7) = 0;
            *(undefined8 *)(puVar18 + 9) = 0;
            *(undefined2 *)((longlong)puVar18 + 0x4a) = 0;
            puVar18[0xb] = 0x3f800000;
            puVar18[0xf] = 0x3f800000;
            *(byte *)(puVar18 + 0x1c) = *(byte *)(puVar18 + 0x1c) & 0xee | 6;
            *(code **)(puVar18 + 0xc) = FUN_1401caa00;
          }
          *(char *)(param_1 + 0x248) = *(char *)(param_1 + 0x248) + -1;
          *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) | 0x100;
          *(undefined4 *)(param_1 + 0x600) = 0x3f800000;
          *(undefined4 *)(param_1 + 0x1e0) = 0x41200000;
        }
      }
    }
    else {
      *(float *)(param_1 + 0x1e0) =
           *(float *)(param_1 + 0x1e0) - DAT_1402d22d0 / (float)*(byte *)(param_1 + 0x24a);
    }
  }
  else {
    if (*(float *)(param_1 + 0x600) <= 0.0) {
      *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xfffffeff;
    }
    else {
      fVar7 = DAT_1402d2470 /
              ((float)*(byte *)(param_1 + 0x24a) * (float)*(byte *)(param_1 + 0x24a)) +
              *(float *)(param_1 + 0x5f4);
      *(float *)(param_1 + 0x5f4) = fVar7;
      auVar2 = *(undefined1 (*) [16])(param_1 + 0x5e0);
      auVar8 = vshufps_avx(auVar2,auVar2,0xaa);
      auVar9 = vshufps_avx(auVar2,auVar2,0xff);
      *(float *)(param_1 + 0x5e0) = auVar2._0_4_ + *(float *)(param_1 + 0x5f0);
      *(float *)(param_1 + 0x5e8) = auVar8._0_4_ + *(float *)(param_1 + 0x5f8);
      *(float *)(param_1 + 0x5ec) = auVar9._0_4_ + *(float *)(param_1 + 0x5fc);
      auVar2 = vshufps_avx(auVar2,auVar2,0x55);
      *(float *)(param_1 + 0x5e4) = fVar7 + auVar2._0_4_;
      *(float *)(param_1 + 0x600) =
           *(float *)(param_1 + 0x600) - fVar24 / (float)*(byte *)(param_1 + 0x24a);
    }
    *(float *)(param_1 + 0x1e0) =
         *(float *)(param_1 + 0x1e0) - fVar24 / (float)*(byte *)(param_1 + 0x24a);
  }
  return;
}

