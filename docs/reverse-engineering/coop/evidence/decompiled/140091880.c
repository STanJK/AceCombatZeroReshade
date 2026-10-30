/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140091880; RVA 0x91880
 * Ghidra-generated research pseudocode, inferred types, not original source. */

char FUN_140091880(longlong param_1,float *param_2,float param_3,float param_4,longlong param_5)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  longlong lVar5;
  float fVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  int iVar14;
  byte bVar15;
  uint uVar16;
  longlong lVar17;
  char cVar18;
  bool bVar19;
  undefined1 auVar20 [16];
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined1 auVar21 [64];
  undefined1 auVar22 [64];
  undefined1 auVar23 [64];
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  uint uVar28;
  float fVar29;
  longlong *local_res10;
  byte bStack0000000000000030;
  
  plVar8 = *(longlong **)(param_1 + 0x10);
  cVar18 = '\0';
  uVar16 = 0;
  bVar1 = *(byte *)(param_2 + 0x14);
  lVar5 = *plVar8;
  lVar10 = *(longlong *)(lVar5 + (ulonglong)bVar1 * 8);
  lVar12 = (ulonglong)*(byte *)((longlong)param_2 + 0x51) * 0x520 + *(longlong *)(lVar10 + 0x110);
  bVar15 = *(byte *)(lVar10 + 0x15d);
  if (*(char *)((longlong)plVar8 + 0x34) != '\0') {
    fVar29 = 0.0;
    fVar27 = DAT_1402d2478;
    uVar28 = DAT_1402d3770;
    bStack0000000000000030 = bVar15;
    do {
      local_res10 = (longlong *)(*plVar8 + (longlong)(int)uVar16 * 8);
      lVar10 = *local_res10;
      bVar2 = *(byte *)(lVar10 + 0x15d);
      if ((bVar2 != bVar15) &&
         ((&DAT_1402accc0)
          [(ulonglong)*(byte *)(*(longlong *)(lVar5 + (ulonglong)bVar1 * 8) + 0x15d) +
           (ulonglong)bVar2 * 8] != '\0')) {
        if (bVar15 == 4) {
          bVar19 = bVar2 == 5;
LAB_1400919d3:
          if (bVar19) goto LAB_140091ce5;
        }
        else if (bVar15 == 5) {
          bVar19 = bVar2 == 4;
          goto LAB_1400919d3;
        }
        if ((*(byte *)(lVar10 + 0x120) & 4) != 0) {
          puVar7 = operator_new((longlong)*(int *)(lVar10 + 0x118));
          iVar14 = 0;
          lVar10 = *local_res10;
          if (0 < *(int *)(lVar10 + 0x118)) {
            puVar9 = puVar7;
            do {
              *puVar9 = 0;
              puVar9 = puVar9 + 1;
              iVar14 = iVar14 + 1;
              lVar10 = *local_res10;
            } while (iVar14 < *(int *)(lVar10 + 0x118));
          }
          uVar11 = 0;
          if (0 < *(int *)(lVar10 + 0x118)) {
            lVar17 = 0;
            do {
              lVar10 = *(longlong *)(lVar10 + 0x110) + lVar17;
              if (((((param_5 == 0) || (uVar16 != *(byte *)(param_5 + 0x234))) ||
                   (uVar11 != *(byte *)(param_5 + 0x235))) &&
                  ((uVar16 != *(byte *)(param_2 + 0x14) ||
                   (uVar11 != *(byte *)((longlong)param_2 + 0x51))))) &&
                 ((((cVar3 = *(char *)(**(longlong **)(lVar12 + 0x388) + 0x15d), cVar3 != '\0' &&
                    (cVar3 != '\x02')) || (*(char *)(lVar12 + 0x235) == '\0')) ||
                  (((cVar3 = *(char *)(**(longlong **)(lVar10 + 0x388) + 0x15d), cVar3 != '\0' &&
                    (cVar3 != '\x02')) || (*(char *)(lVar10 + 0x235) != '\0')))))) {
                fVar26 = *(float *)(lVar10 + 600) - *param_2;
                fVar24 = *(float *)(lVar10 + 0x25c) - param_2[1];
                fVar25 = *(float *)(lVar10 + 0x260) - param_2[2];
                fVar6 = *(float *)(lVar10 + 0x264) - param_2[3];
                if (SQRT(fVar6 * fVar6 + fVar25 * fVar25 + fVar26 * fVar26 + fVar24 * fVar24) <=
                    param_3 * fVar27) {
                  if (*(short *)(**(longlong **)(lVar10 + 0x1a0) + 0x6c) == 0x46) {
                    fVar26 = *(float *)(lVar10 + 600) - *param_2;
                    fVar24 = *(float *)(lVar10 + 0x25c) - param_2[1];
                    fVar25 = *(float *)(lVar10 + 0x260) - param_2[2];
                    auVar22._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar10 + 0x268));
                    auVar22._8_56_ = extraout_var;
                    auVar20 = auVar22._0_16_;
                    auVar22 = ZEXT1664(auVar20);
                    auVar20 = vshufps_avx(auVar20,auVar20,1);
                    auVar23 = ZEXT1664(auVar20);
                    auVar21._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar10 + 0x26c));
                    auVar21._8_56_ = extraout_var_00;
                    auVar20 = vshufps_avx(auVar21._0_16_,auVar21._0_16_,1);
                    if (auVar20._0_4_ * auVar23._0_4_ * fVar25 +
                        fVar26 * (float)auVar21._0_8_ * auVar23._0_4_ +
                        (float)((uint)(auVar22._0_4_ * fVar24) ^ uVar28) < fVar29)
                    goto LAB_140091c96;
                  }
                  lVar13 = *(longlong *)
                            (*(longlong *)
                              (**(longlong **)(param_1 + 0x10) +
                              (ulonglong)*(byte *)(param_2 + 0x14) * 8) + 0x110) +
                           (ulonglong)*(byte *)((longlong)param_2 + 0x51) * 0x520;
                  FUN_140118040(lVar10,&local_res10,puVar7,
                                (int)((float)*(byte *)(*(longlong *)(param_2 + 0x10) + 0x49) *
                                     param_4) & 0xff,2,lVar13,3);
                  if ((*(uint *)(lVar10 + 0x1f0) & 0x1000002) == 0x1000002) {
                    *(uint *)(lVar13 + 0x1fc) = *(uint *)(lVar13 + 0x1fc) | 0x80000;
                  }
                  uVar4 = *(undefined1 *)(lVar10 + 0x235);
                  *(undefined1 *)(lVar13 + 0x240) = *(undefined1 *)(lVar10 + 0x234);
                  *(undefined1 *)(lVar13 + 0x241) = uVar4;
                  cVar3 = *(char *)(**(longlong **)(lVar10 + 0x388) + 0x15d);
                  if (((cVar3 == '\0') || (cVar3 == '\x02')) && (*(char *)(lVar10 + 0x235) == '\0'))
                  {
                    cVar18 = *(char *)(lVar10 + 0x234) + '\x01';
                  }
                }
              }
LAB_140091c96:
              uVar11 = uVar11 + 1;
              lVar17 = lVar17 + 0x520;
              lVar10 = *local_res10;
            } while ((int)uVar11 < *(int *)(lVar10 + 0x118));
          }
          thunk_FUN_1402500f0(puVar7);
          bVar15 = bStack0000000000000030;
        }
      }
LAB_140091ce5:
      plVar8 = *(longlong **)(param_1 + 0x10);
      uVar16 = uVar16 + 1;
    } while ((int)uVar16 < (int)(uint)*(byte *)((longlong)plVar8 + 0x34));
  }
  return cVar18;
}

