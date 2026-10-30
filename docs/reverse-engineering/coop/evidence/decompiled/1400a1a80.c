/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a1a80; RVA 0xa1a80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

char FUN_1400a1a80(longlong param_1,longlong *param_2,float *param_3,float *param_4,float *param_5,
                  float param_6)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined1 *puVar15;
  longlong *plVar16;
  ulonglong uVar17;
  undefined1 *puVar18;
  longlong lVar19;
  int iVar20;
  longlong lVar21;
  int iVar22;
  char cVar23;
  float fVar24;
  undefined1 auVar25 [16];
  undefined1 extraout_var [56];
  undefined1 extraout_var_00 [56];
  undefined1 auVar26 [64];
  undefined1 in_ZMM6 [64];
  undefined1 auVar27 [64];
  undefined1 auVar28 [64];
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  longlong *local_118;
  longlong local_110;
  ulonglong local_108;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  undefined1 local_58 [16];
  
  uVar17 = (ulonglong)*(byte *)(param_3 + 0x14);
  local_100 = *param_5;
  fStack_fc = param_5[1];
  fStack_f8 = param_5[2];
  fStack_f4 = param_5[3];
  fVar32 = local_100 - *param_4;
  fVar33 = fStack_fc - param_4[1];
  fVar34 = fStack_f8 - param_4[2];
  fVar5 = fVar33 * fVar33;
  fVar12 = fVar32 * fVar32;
  fVar35 = fStack_f4 - param_4[3];
  fVar13 = fVar34 * fVar34;
  lVar19 = *param_2;
  cVar23 = '\0';
  fVar14 = fVar35 * fVar35;
  param_5._0_4_ = 0;
  if (*(char *)((longlong)param_2 + 0x34) != '\0') {
    local_58 = in_ZMM6._0_16_;
    fVar36 = 0.0;
    local_110 = lVar19;
    local_108 = uVar17;
    do {
      plVar16 = (longlong *)(*param_2 + (longlong)(int)param_5 * 8);
      lVar21 = *plVar16;
      if ((*(byte *)(lVar21 + 0x120) & 4) != 0) {
        bVar1 = *(byte *)(*(longlong *)(lVar19 + uVar17 * 8) + 0x15d);
        if (*(byte *)(lVar21 + 0x15d) != bVar1) {
          if (((&DAT_1402accc0)[(ulonglong)bVar1 + (ulonglong)*(byte *)(lVar21 + 0x15d) * 8] != '\0'
              ) && (iVar20 = 0, 0 < *(int *)(lVar21 + 0x118))) {
            fVar30 = DAT_1402d22d0 / (fVar14 + fVar13 + fVar12 + fVar5);
            fVar31 = fVar30;
            local_118 = plVar16;
            do {
              lVar19 = (longlong)iVar20 * 0x520 + *(longlong *)(lVar21 + 0x110);
              auVar25 = *(undefined1 (*) [16])(lVar19 + 600);
              auVar27 = ZEXT1664(auVar25);
              if (*(char *)(**(longlong **)(lVar19 + 0x1a0) + 0x6f) == '\x01') {
                fVar24 = *(float *)(**(longlong **)(lVar19 + 0x1a0) + 0x40);
              }
              else if (*(longlong **)(lVar19 + 0x390) == (longlong *)0x0) {
                fVar24 = DAT_1402d2698;
              }
              else {
                fVar24 = (float)(**(code **)(**(longlong **)(lVar19 + 0x390) + 0xa0))();
                auVar25 = auVar27._0_16_;
                plVar16 = local_118;
              }
              auVar6 = vshufps_avx(auVar25,auVar25,0x55);
              auVar7 = vshufps_avx(auVar25,auVar25,0xaa);
              auVar8 = vshufps_avx(auVar25,auVar25,0xff);
              fVar29 = (fVar35 * (auVar8._0_4_ - param_4[3]) +
                       fVar34 * (auVar7._0_4_ - param_4[2]) +
                       (auVar25._0_4_ - *param_4) * fVar32 + (auVar6._0_4_ - param_4[1]) * fVar33) *
                       fVar31;
              if ((fVar29 <= DAT_1402d22d0) && (fVar36 <= fVar29)) {
                local_100 = *param_4;
                fStack_fc = fVar29 * fVar33 + param_4[1];
                fStack_f8 = fVar29 * fVar34 + param_4[2];
                fStack_f4 = fVar29 * fVar35 + param_4[3];
                fVar9 = auVar6._0_4_ - fStack_fc;
                fVar29 = auVar25._0_4_ - (fVar29 * fVar32 + local_100);
                fVar10 = auVar7._0_4_ - fStack_f8;
                fVar11 = auVar8._0_4_ - fStack_f4;
                if (SQRT(fVar11 * fVar11 + fVar10 * fVar10 + fVar29 * fVar29 + fVar9 * fVar9) <
                    fVar24 + param_6) {
                  uVar4 = *(uint *)(lVar19 + 0x1f0);
                  puVar15 = operator_new((longlong)*(int *)(*plVar16 + 0x118));
                  iVar22 = 0;
                  if (0 < *(int *)(*local_118 + 0x118)) {
                    puVar18 = puVar15;
                    do {
                      *puVar18 = 0;
                      puVar18 = puVar18 + 1;
                      iVar22 = iVar22 + 1;
                    } while (iVar22 < *(int *)(*local_118 + 0x118));
                  }
                  lVar21 = (ulonglong)*(byte *)((longlong)param_3 + 0x51) * 0x520 +
                           *(longlong *)
                            (*(longlong *)(*param_2 + (ulonglong)*(byte *)(param_3 + 0x14) * 8) +
                            0x110);
                  if (*(short *)(**(longlong **)(lVar19 + 0x1a0) + 0x6c) == 0x46) {
                    local_100 = *(float *)(lVar19 + 600);
                    fStack_fc = *(float *)(lVar19 + 0x25c);
                    fStack_f8 = *(float *)(lVar19 + 0x260);
                    fStack_f4 = *(float *)(lVar19 + 0x264);
                    fVar31 = local_100 - *param_3;
                    fVar24 = fStack_fc - param_3[1];
                    fVar29 = fStack_f8 - param_3[2];
                    auVar27._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar19 + 0x268));
                    auVar27._8_56_ = extraout_var;
                    auVar25 = auVar27._0_16_;
                    auVar27 = ZEXT1664(auVar25);
                    auVar25 = vshufps_avx(auVar25,auVar25,1);
                    auVar28 = ZEXT1664(auVar25);
                    auVar26._0_8_ = FUN_14026f3b0(*(undefined4 *)(lVar19 + 0x26c));
                    auVar26._8_56_ = extraout_var_00;
                    auVar25 = vshufps_avx(auVar26._0_16_,auVar26._0_16_,1);
                    if (fVar36 <= auVar25._0_4_ * auVar28._0_4_ * fVar29 +
                                  fVar31 * (float)auVar26._0_8_ * auVar28._0_4_ +
                                  (float)((uint)(auVar27._0_4_ * fVar24) ^ DAT_1402d3770))
                    goto LAB_1400a1e2e;
                  }
                  else {
LAB_1400a1e2e:
                    FUN_140118040(lVar19,&local_118,puVar15,
                                  *(undefined1 *)(*(longlong *)(param_3 + 0x10) + 0x49),2,lVar21,3);
                  }
                  if (((*(uint *)(lVar19 + 0x1f0) & 0x1000000) != 0) && ((uVar4 >> 1 & 1) != 0)) {
                    *(uint *)(lVar21 + 0x1fc) = *(uint *)(lVar21 + 0x1fc) | 0x80000;
                    *(char *)(param_1 + 0x7c) = (char)(int)param_5;
                    *(char *)(param_1 + 0x7d) = (char)iVar20;
                  }
                  uVar2 = *(undefined1 *)(lVar19 + 0x235);
                  *(undefined1 *)(lVar21 + 0x240) = *(undefined1 *)(lVar19 + 0x234);
                  *(undefined1 *)(lVar21 + 0x241) = uVar2;
                  cVar3 = *(char *)(**(longlong **)(lVar19 + 0x388) + 0x15d);
                  if (((cVar3 == '\0') || (cVar3 == '\x02')) && (*(char *)(lVar19 + 0x235) == '\0'))
                  {
                    cVar23 = *(char *)(lVar19 + 0x234) + '\x01';
                  }
                  thunk_FUN_1402500f0(puVar15);
                  plVar16 = local_118;
                  fVar31 = fVar30;
                }
              }
              lVar21 = *plVar16;
              iVar20 = iVar20 + 1;
            } while (iVar20 < *(int *)(lVar21 + 0x118));
          }
          uVar17 = local_108;
        }
        lVar19 = local_110;
      }
      param_5._0_4_ = (int)param_5 + 1;
    } while ((int)param_5 < (int)(uint)*(byte *)((longlong)param_2 + 0x34));
  }
  return cVar23;
}

