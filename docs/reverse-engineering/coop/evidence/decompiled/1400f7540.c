/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400f7540; RVA 0xf7540
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400f7540(longlong param_1,longlong *param_2)

{
  uint *puVar1;
  ushort *puVar2;
  byte *pbVar3;
  byte bVar4;
  ushort uVar5;
  longlong lVar6;
  longlong *plVar7;
  char cVar8;
  short sVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong *plVar13;
  uint uVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  int iVar19;
  int iVar20;
  undefined8 *puVar21;
  longlong lVar22;
  float fVar23;
  undefined8 extraout_XMM0_Qa;
  undefined8 uVar24;
  undefined8 extraout_XMM0_Qa_00;
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 local_res8;
  undefined8 local_res10;
  uint local_res18 [2];
  longlong local_res20;
  ulonglong in_stack_ffffffffffffff08;
  
  lVar6 = *param_2;
  lVar22 = *(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x2f8) + 0x110);
  lVar17 = *(longlong *)(lVar22 + 0x1b8);
  lVar12 = param_1;
  local_res20 = FUN_1401c56d0();
  local_res18[0] = (uint)lVar12;
  uVar10 = *(uint *)(param_1 + 0x3a8);
  if ((uVar10 & 4) == 0) {
    if ((*(longlong *)(param_1 + 0x2f8) == 0) ||
       (lVar12 = *(longlong *)(param_1 + 0x340), (*(uint *)(lVar12 + 0xa8790) & 0x40000000) == 0)) {
      *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
    }
    local_res18[0] = (uint)lVar12;
    *(int *)(param_1 + 0x378) = *(int *)(param_1 + 0x378) + 1;
    *(int *)(param_1 + 0x38c) = *(int *)(param_1 + 0x38c) + 1;
    *(int *)(param_1 + 0x394) = *(int *)(param_1 + 0x394) + 1;
  }
  fVar23 = DAT_1402d22d0;
  if (DAT_1402d22d0 <= *(float *)(lVar6 + 0x20)) {
    uVar10 = uVar10 & 0xffffffdf;
  }
  else {
    local_res18[0] = uVar10 | 0x20;
    uVar10 = uVar10 & 0xffffffdf;
    if (*(int *)(param_1 + 0x378) < (int)(uint)*(byte *)(param_1 + 0x3d1)) {
      uVar10 = local_res18[0];
    }
  }
  *(uint *)(param_1 + 0x3a8) = uVar10;
  if (((uVar10 & 4) == 0) && ((*(byte *)(param_1 + 0x3d0) & 2) != 0)) {
    bVar4 = *(byte *)(param_1 + 0x3d1);
    iVar19 = *(int *)(param_1 + 900);
    auVar25._0_4_ = (float)bVar4;
    auVar25._4_12_ = SUB1612(ZEXT816(0),4);
    iVar20 = (int)((float)*(int *)(param_1 + 0x3f0) * auVar25._0_4_);
    if (iVar19 < iVar20) {
      local_res18[0] = (uint)bVar4 * 5;
      if (iVar19 < (int)(iVar20 + (uint)bVar4 * -5)) {
        local_res18[0] = (uint)bVar4 * 10;
        if (((int)(iVar20 + (uint)bVar4 * -10) <= iVar19) &&
           ((iVar20 - iVar19) % (int)(uint)bVar4 == 0)) {
          local_res8 = (float)((uint)local_res8._2_2_ << 0x10);
          goto LAB_1400f76cd;
        }
      }
      else if ((iVar20 - iVar19) % (int)(uint)bVar4 == 0) {
        local_res8 = (float)CONCAT22(local_res8._2_2_,1);
LAB_1400f76cd:
        local_res10 = CONCAT62(local_res10._2_6_,1);
        FUN_1401c6150(auVar25._0_8_,&local_res10,&local_res8);
        uVar10 = *(uint *)(param_1 + 0x3a8);
      }
    }
  }
  fVar32 = DAT_1402d2994;
  fVar33 = DAT_1402d2338;
  uVar14 = *(uint *)(lVar6 + 0x40);
  fVar31 = 0.0;
  if (((uVar14 >> 0xb & 1) != 0) && ((uVar10 >> 8 & 1) == 0)) {
    lVar12 = (*(undefined8 **)(param_1 + 0x300))[3];
    if (lVar12 == 0) {
LAB_1400f775c:
      local_res18[0] = 0;
    }
    else {
      puVar21 = (undefined8 *)**(undefined8 **)(param_1 + 0x300);
      if (puVar21 == (undefined8 *)0x0) {
        local_res18[0] = 0;
      }
      else {
        if (*(ushort *)*puVar21 <= *(ushort *)(lVar6 + 0x56)) goto LAB_1400f775c;
        local_res18[0] = (uint)*(ushort *)(lVar12 + (ulonglong)*(ushort *)(lVar6 + 0x56) * 2);
      }
    }
    if ((short)local_res18[0] == *(short *)(lVar6 + 0x58)) {
      if ((uVar14 >> 0xf & 1) == 0) {
        if ((uVar14 >> 10 & 1) == 0) {
          if ((*(byte *)(lVar22 + 0x1f0) & 2) != 0) {
            fVar28 = DAT_1402d2994 * *(float *)(lVar6 + 0x38);
            sVar9 = *(short *)(lVar6 + 0x5e);
            bVar4 = DAT_14031f8b1 & 1;
            (&DAT_140310a64)[(ulonglong)*(byte *)(local_res20 + 0xc) * 8] =
                 (float)*(byte *)(lVar6 + 0x6a) * DAT_1402d2338;
            if ((((bVar4 == 0) && (lVar12 = (longlong)*(short *)(local_res20 + 4), -1 < sVar9)) &&
                ((int)sVar9 < *(int *)(&DAT_14031f838 + lVar12 * 0x18))) &&
               (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) != 0)) {
              in_stack_ffffffffffffff08 =
                   CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),
                            (int)(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]);
              uVar24 = (&DAT_14033bc00)
                       [(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]];
              FUN_140186f20(uVar24,&DAT_14031f438 + lVar12 * 0x100,
                            *(undefined4 *)
                             (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) + (longlong)sVar9 * 4),
                            (int)fVar28,in_stack_ffffffffffffff08,0,0,1);
              local_res18[0] = (uint)uVar24;
              *(int *)(&DAT_14031f898 + lVar12 * 4) = (int)sVar9;
            }
          }
        }
        else {
          local_res18[0] = (uint)(DAT_1402d2994 * *(float *)(lVar6 + 0x38));
          uVar11 = (ulonglong)*(byte *)(local_res20 + 0xc);
          fVar28 = (float)*(byte *)(lVar6 + 0x6a) * DAT_1402d2338;
          (&DAT_140310a70)[uVar11 * 8] = fVar28;
          if (local_res18[0] == 0) {
            fVar28 = 0.0;
          }
          else {
            fVar28 = (fVar28 - (float)(&DAT_140310a64)[uVar11 * 8]) / (float)(int)local_res18[0];
          }
          *(float *)(&DAT_140310a74 + uVar11 * 0x20) = fVar28;
          (&DAT_140310a6c)[uVar11 * 8] = local_res18[0];
          (&DAT_140310a78)[uVar11 * 0x20] = 2;
        }
      }
      else if ((*(byte *)(lVar22 + 0x1f0) & 2) != 0) {
        local_res8 = (float)*(byte *)(lVar6 + 0x6a) * DAT_1402d1ef4;
        local_res10 = CONCAT44(local_res10._4_4_,(int)(DAT_1402d2994 * *(float *)(lVar6 + 0x38)));
        in_stack_ffffffffffffff08 = param_1 + 0x2c4;
        local_res18[0] = 2;
        lVar12 = local_res20;
        FUN_1401c66a0(local_res20,local_res18,&local_res10,&local_res8,in_stack_ffffffffffffff08);
        local_res18[0] = (uint)lVar12;
      }
      uVar10 = *(uint *)(param_1 + 0x3a8) | 0x100;
      *(uint *)(param_1 + 0x3a8) = uVar10;
    }
  }
  uVar14 = DAT_1402d3770;
  local_res18[0] = local_res18[0] & 0xffffff00;
  local_res8 = (float)((uint)local_res8 & 0xffffff00);
  if ((((uVar10 >> 0x15 & 1) != 0) && (*(float *)(param_1 + 0x368) <= *(float *)(lVar22 + 600))) &&
     (*(float *)(lVar22 + 0x260) <= *(float *)(param_1 + 0x374) &&
      (*(float *)(param_1 + 0x36c) <= *(float *)(lVar22 + 0x260) &&
      *(float *)(lVar22 + 600) <= *(float *)(param_1 + 0x370)))) {
    *(undefined1 *)(param_1 + 0x3cc) = 0xb;
    fVar28 = (float)(*(uint *)(lVar22 + 600) ^ uVar14);
    fVar27 = (float)(*(uint *)(lVar22 + 0x25c) ^ uVar14);
    fVar29 = (float)(*(uint *)(lVar22 + 0x260) ^ uVar14);
    fVar30 = (float)(*(uint *)(lVar22 + 0x264) ^ uVar14);
    fVar27 = SQRT(fVar30 * fVar30 + fVar29 * fVar29 + fVar27 * fVar27 + fVar28 * fVar28);
    if (fVar27 != fVar31) {
      fVar23 = fVar23 / fVar27;
      fVar28 = fVar23 * fVar28;
      fVar29 = fVar29 * fVar23;
      fVar30 = fVar23 * fVar30;
    }
    fVar23 = (float)FUN_140272370(fVar28,fVar29);
    fVar27 = DAT_1402d2420;
    fVar23 = fVar23 + DAT_1402d2420;
    *(float *)(param_1 + 0xc4) = fVar23;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    if (fVar27 < fVar23) {
      *(float *)(param_1 + 0xc4) = fVar23 - DAT_1402d249c;
    }
    fVar23 = DAT_1402d291c;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    auVar25 = *(undefined1 (*) [16])(lVar22 + 600);
    *(float *)(param_1 + 0xb0) = fVar28 * fVar23 + auVar25._0_4_;
    *(undefined4 *)(param_1 + 0xb4) = 0x465ac000;
    auVar26 = vshufps_avx(auVar25,auVar25,0xaa);
    *(float *)(param_1 + 0xb8) = fVar29 * fVar23 + auVar26._0_4_;
    auVar25 = vshufps_avx(auVar25,auVar25,0xff);
    *(float *)(param_1 + 0xbc) = fVar30 * fVar23 + auVar25._0_4_;
    *(undefined1 *)(param_1 + 0x3e2) = *(undefined1 *)(lVar22 + 0x428);
    *(undefined2 *)(param_1 + 0x3c2) = *(undefined2 *)(lVar17 + 0x208e);
    *(undefined1 *)(param_1 + 0x3e4) = *(undefined1 *)(lVar17 + 0x2099);
    *(undefined1 *)(param_1 + 0x3e5) = *(undefined1 *)(lVar17 + 0x209a);
  }
  if (*(char *)(param_1 + 0x402) == '\0') {
    if ((*(byte *)(lVar22 + 0x1f0) & 2) != 0) goto LAB_1400f7dc1;
    lVar12 = FUN_140189320();
    lVar18 = 0x1a;
    if (*(char *)(lVar12 + 0x3e) == '\x01') {
      lVar18 = 3;
    }
    bVar4 = DAT_14031f8b1 & 1;
    (&DAT_140310a64)[(ulonglong)*(byte *)(local_res20 + 0xc) * 8] = 0x42fe0000;
    if (((bVar4 == 0) &&
        (lVar12 = (longlong)*(short *)(local_res20 + 4),
        (int)lVar18 < *(int *)(&DAT_14031f838 + lVar12 * 0x18))) &&
       (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) != 0)) {
      in_stack_ffffffffffffff08 =
           CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),
                    (int)(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]);
      FUN_140186f20((&DAT_14033bc00)[(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]],
                    &DAT_14031f438 + lVar12 * 0x100,
                    *(undefined4 *)(*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) + lVar18 * 4),0,
                    in_stack_ffffffffffffff08,0,0,1);
      *(int *)(&DAT_14031f898 + lVar12 * 4) = (int)lVar18;
    }
    cVar8 = '\x01';
    *(uint *)(param_1 + 0x3a8) = *(uint *)(param_1 + 0x3a8) | 0x40;
    local_res8 = (float)CONCAT31(local_res8._1_3_,1);
    *(ushort *)(param_1 + 0x3ba) = (ushort)*(byte *)(param_1 + 0x3d1) * 7;
    if ((*(byte *)(param_1 + 0x3d0) & 1) != 0) {
      *(byte *)(lVar17 + 0x1863) = *(byte *)(lVar17 + 0x1863) | 1;
      *(undefined4 *)(lVar17 + 0x185c) = 0;
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x3a8) & 4) == 0) {
      lVar12 = *(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x2f8) + 0x110);
      puVar1 = (uint *)(*(longlong *)(lVar12 + 0x1b8) + 0x2058);
      *puVar1 = *puVar1 & 0xfeffffff;
      if ((*(byte *)(lVar12 + 0x1f0) & 2) == 0) {
        plVar7 = (longlong *)**(undefined8 **)(param_1 + 0x2f8);
        lVar18 = *plVar7;
        puVar21 = *(undefined8 **)(*(longlong *)(lVar18 + 0x130) + 8);
        if ((puVar21 != (undefined8 *)0x0) && (uVar10 = 0, *(char *)*puVar21 != '\0')) {
          do {
            puVar21 = *(undefined8 **)
                       (*(longlong *)(*(longlong *)(*(longlong *)(lVar18 + 0x130) + 8) + 8) + 8 +
                       (longlong)(int)uVar10 * 0x10);
            if (*(char *)*puVar21 == '\0') {
              lVar18 = *(longlong *)(lVar18 + 0x110);
              lVar15 = *(longlong *)(lVar18 + 0x1b8) + 0x1430;
              FUN_140129300();
              uVar24 = puVar21[1];
              *(undefined8 *)(lVar15 + 0x3f8) = 0;
              *(undefined8 *)(lVar15 + 0x400) = 0;
              in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffffffffff00;
              FUN_140126fd0(*plVar7 + 0x48,uVar24,uVar10 & 0xff,0,in_stack_ffffffffffffff08,1);
              if ((*(byte *)(*plVar7 + 0xf6) & 2) != 0) {
                FUN_140133cd0(*plVar7,1);
                if ((*(byte *)(*plVar7 + 0xf6) & 1) != 0) {
                  FUN_140133ae0();
                }
                *(ushort *)(lVar18 + 0x428) = (ushort)*(byte *)(lVar18 + 0x42a);
              }
            }
            lVar18 = *plVar7;
            uVar10 = uVar10 + 1;
          } while ((int)uVar10 <
                   (int)(uint)*(byte *)**(undefined8 **)(*(longlong *)(lVar18 + 0x130) + 8));
        }
        if ((*(byte *)(lVar12 + 0x1f0) & 2) == 0) {
          FUN_1400f73c0();
        }
      }
      lVar12 = *(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0x2f8) + 8) + 0x110);
      puVar1 = (uint *)(*(longlong *)(lVar12 + 0x1b8) + 0x2058);
      *puVar1 = *puVar1 & 0xfeffffff;
      if ((*(byte *)(lVar12 + 0x1f0) & 2) == 0) {
        lVar18 = **(longlong **)(param_1 + 0x2f8);
        lVar15 = *(longlong *)(lVar18 + 8);
        puVar21 = *(undefined8 **)(*(longlong *)(lVar15 + 0x130) + 8);
        if ((puVar21 != (undefined8 *)0x0) && (uVar10 = 0, *(char *)*puVar21 != '\0')) {
          do {
            puVar21 = *(undefined8 **)
                       (*(longlong *)(*(longlong *)(*(longlong *)(lVar15 + 0x130) + 8) + 8) + 8 +
                       (longlong)(int)uVar10 * 0x10);
            if (*(char *)*puVar21 == '\0') {
              lVar15 = *(longlong *)(lVar15 + 0x110);
              lVar16 = *(longlong *)(lVar15 + 0x1b8) + 0x1430;
              FUN_140129300();
              uVar24 = puVar21[1];
              *(undefined8 *)(lVar16 + 0x3f8) = 0;
              *(undefined8 *)(lVar16 + 0x400) = 0;
              in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffffffffff00;
              FUN_140126fd0(*(longlong *)(lVar18 + 8) + 0x48,uVar24,uVar10 & 0xff,0,
                            in_stack_ffffffffffffff08,1);
              if ((*(byte *)(*(longlong *)(lVar18 + 8) + 0xf6) & 2) != 0) {
                FUN_140133cd0(*(longlong *)(lVar18 + 8),1);
                if ((*(byte *)(*(longlong *)(lVar18 + 8) + 0xf6) & 1) != 0) {
                  FUN_140133ae0();
                }
                *(ushort *)(lVar15 + 0x428) = (ushort)*(byte *)(lVar15 + 0x42a);
              }
            }
            lVar15 = *(longlong *)(lVar18 + 8);
            uVar10 = uVar10 + 1;
          } while ((int)uVar10 <
                   (int)(uint)*(byte *)**(undefined8 **)(*(longlong *)(lVar15 + 0x130) + 8));
        }
        if ((*(byte *)(lVar12 + 0x1f0) & 2) == 0) {
          FUN_1400f73c0();
        }
      }
    }
LAB_1400f7dc1:
    cVar8 = '\0';
  }
  if (*(char *)(param_1 + 0x402) == '\0') {
    if ((*(float *)(lVar22 + 0x260) <= *(float *)(param_1 + 0x354)) &&
       (*(float *)(param_1 + 0x34c) <= *(float *)(lVar22 + 0x260) &&
        (*(float *)(lVar22 + 600) <= *(float *)(param_1 + 0x350) &&
        *(float *)(param_1 + 0x348) <= *(float *)(lVar22 + 600)))) goto LAB_1400f7f1a;
    lVar12 = FUN_140189320();
    lVar22 = local_res20;
    lVar18 = 0x1a;
    if (*(char *)(lVar12 + 0x3e) == '\x01') {
      lVar18 = 3;
    }
    bVar4 = DAT_14031f8b1 & 1;
    (&DAT_140310a64)[(ulonglong)*(byte *)(local_res20 + 0xc) * 8] = 0x42fe0000;
    if (bVar4 == 0) {
      lVar12 = (longlong)*(short *)(local_res20 + 4);
      if (((int)lVar18 < *(int *)(&DAT_14031f838 + lVar12 * 0x18)) &&
         (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) != 0)) {
        in_stack_ffffffffffffff08 =
             CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),
                      (int)(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]);
        FUN_140186f20((&DAT_14033bc00)
                      [(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]],
                      &DAT_14031f438 + lVar12 * 0x100,
                      *(undefined4 *)(*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) + lVar18 * 4),0,
                      in_stack_ffffffffffffff08,0,0,1);
        *(int *)(&DAT_14031f898 + lVar12 * 4) = (int)lVar18;
      }
    }
    cVar8 = '\x01';
    local_res8 = (float)CONCAT31(local_res8._1_3_,1);
    *(ushort *)(param_1 + 0x3ba) = (ushort)*(byte *)(param_1 + 0x3d1) * 7;
    if (*(longlong *)(param_1 + 0x308) != 0) {
      puVar2 = (ushort *)(*(longlong *)(param_1 + 0x308) + 0x90c);
      *puVar2 = *puVar2 | 4;
      FUN_1401a5f00(*(undefined8 *)(param_1 + 0x308));
    }
  }
  else {
    fVar23 = *(float *)(param_1 + 0x34c);
    fVar28 = *(float *)(param_1 + 0x354);
    lVar22 = *(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x2f8) + 0x110);
    if (((fVar28 < *(float *)(lVar22 + 0x260)) ||
        (*(float *)(lVar22 + 0x260) < fVar23 ||
         (*(float *)(param_1 + 0x350) < *(float *)(lVar22 + 600) ||
         *(float *)(lVar22 + 600) < *(float *)(param_1 + 0x348)))) &&
       ((*(byte *)(lVar22 + 0x1f0) & 2) != 0)) {
      in_stack_ffffffffffffff08 = CONCAT71((int7)(in_stack_ffffffffffffff08 >> 8),6);
      local_res10 = 0;
      FUN_140118040(lVar22,&local_res10,0,1000,in_stack_ffffffffffffff08,0,3);
      fVar23 = *(float *)(param_1 + 0x34c);
      fVar28 = *(float *)(param_1 + 0x354);
    }
    lVar22 = *(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0x2f8) + 8) + 0x110);
    if (((fVar28 < *(float *)(lVar22 + 0x260)) ||
        (*(float *)(lVar22 + 0x260) < fVar23 ||
         (*(float *)(param_1 + 0x350) < *(float *)(lVar22 + 600) ||
         *(float *)(lVar22 + 600) < *(float *)(param_1 + 0x348)))) &&
       ((*(byte *)(lVar22 + 0x1f0) & 2) != 0)) {
      in_stack_ffffffffffffff08 = CONCAT71((int7)(in_stack_ffffffffffffff08 >> 8),6);
      local_res10 = 0;
      FUN_140118040(lVar22,&local_res10,0,1000,in_stack_ffffffffffffff08,0,3);
    }
LAB_1400f7f1a:
    lVar22 = local_res20;
  }
  auVar26._0_4_ = (float)*(byte *)(param_1 + 0x3d1);
  auVar26._4_12_ = SUB1612(ZEXT816(0),4);
  uVar24 = auVar26._0_8_;
  if ((int)((float)*(int *)(param_1 + 0x3f0) * auVar26._0_4_) <= *(int *)(param_1 + 900)) {
    lVar12 = *(longlong *)(param_1 + 0x308);
    if (lVar12 != 0) {
      FUN_1401a7df0(lVar12,0);
    }
    if (*(char *)(param_1 + 0x402) == '\0') {
      *(short *)(param_1 + 0x3ba) =
           (short)(int)((float)*(byte *)(param_1 + 0x3d1) * *(float *)(lVar6 + 0x30));
      local_res8 = (float)CONCAT31(local_res8._1_3_,1);
    }
    else {
      local_res18[0] = (uint)CONCAT71((int7)((ulonglong)lVar12 >> 8),1);
    }
    *(undefined1 *)(param_1 + 0x3e6) = 5;
    lVar12 = FUN_140189320();
    lVar18 = 0x1a;
    if (*(char *)(lVar12 + 0x3e) == '\x01') {
      lVar18 = 3;
    }
    bVar4 = DAT_14031f8b1 & 1;
    (&DAT_140310a64)[(ulonglong)*(byte *)(lVar22 + 0xc) * 8] = 0x42fe0000;
    uVar24 = extraout_XMM0_Qa;
    if (bVar4 == 0) {
      lVar12 = (longlong)*(short *)(lVar22 + 4);
      if (((int)lVar18 < *(int *)(&DAT_14031f838 + lVar12 * 0x18)) &&
         (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) != 0)) {
        in_stack_ffffffffffffff08 =
             CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),
                      (int)(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]);
        uVar24 = FUN_140186f20((&DAT_14033bc00)
                               [(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]],
                               &DAT_14031f438 + lVar12 * 0x100,
                               *(undefined4 *)
                                (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) + lVar18 * 4),0,
                               in_stack_ffffffffffffff08,0,0,1);
        *(int *)(&DAT_14031f898 + lVar12 * 4) = (int)lVar18;
      }
    }
    if (*(longlong *)(param_1 + 0x308) != 0) {
      puVar2 = (ushort *)(*(longlong *)(param_1 + 0x308) + 0x90c);
      *puVar2 = *puVar2 | 4;
      uVar24 = FUN_1401a5f00(*(undefined8 *)(param_1 + 0x308));
    }
    cVar8 = (char)local_res8;
  }
  uVar5 = *(ushort *)(lVar6 + 0x4e);
  if (uVar5 == 0xffff) {
LAB_1400f8447:
    if (cVar8 != '\0') goto LAB_1400f8450;
  }
  else {
    lVar12 = (*(undefined8 **)(param_1 + 0x300))[3];
    if (lVar12 == 0) {
LAB_1400f831c:
      sVar9 = 0;
    }
    else {
      puVar21 = (undefined8 *)**(undefined8 **)(param_1 + 0x300);
      if (puVar21 == (undefined8 *)0x0) {
        sVar9 = 0;
      }
      else {
        if (*(ushort *)*puVar21 <= uVar5) goto LAB_1400f831c;
        sVar9 = *(short *)(lVar12 + (ulonglong)uVar5 * 2);
      }
    }
    if (*(short *)(lVar6 + 0x50) != sVar9) goto LAB_1400f8447;
    cVar8 = '\x01';
    *(short *)(param_1 + 0x3ba) =
         (short)(int)((float)*(byte *)(param_1 + 0x3d1) * *(float *)(lVar6 + 0x30));
    lVar12 = FUN_140189320();
    lVar18 = 0x1a;
    if (*(char *)(lVar12 + 0x3e) == '\x01') {
      lVar18 = 3;
    }
    bVar4 = DAT_14031f8b1 & 1;
    (&DAT_140310a64)[(ulonglong)*(byte *)(lVar22 + 0xc) * 8] = 0x42fe0000;
    uVar24 = extraout_XMM0_Qa_00;
    if (bVar4 == 0) {
      lVar12 = (longlong)*(short *)(lVar22 + 4);
      if (((int)lVar18 < *(int *)(&DAT_14031f838 + lVar12 * 0x18)) &&
         (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) != 0)) {
        in_stack_ffffffffffffff08 =
             CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),
                      (int)(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]);
        uVar24 = FUN_140186f20((&DAT_14033bc00)
                               [(char)(&DAT_14031f8a8)[lVar12 + (ulonglong)DAT_14031f8b0 * 4]],
                               &DAT_14031f438 + lVar12 * 0x100,
                               *(undefined4 *)
                                (*(longlong *)(&DAT_14031f840 + lVar12 * 0x18) + lVar18 * 4),0,
                               in_stack_ffffffffffffff08,0,0,1);
        *(int *)(&DAT_14031f898 + lVar12 * 4) = (int)lVar18;
      }
    }
    *(byte *)(lVar17 + 0x1863) = *(byte *)(lVar17 + 0x1863) | 1;
    *(undefined4 *)(lVar17 + 0x185c) = 0x3f800000;
    if (*(longlong *)(param_1 + 0x308) != 0) {
      in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffffffffff00;
      uVar24 = FUN_1401a61a0(*(longlong *)(param_1 + 0x308),*(undefined2 *)(lVar6 + 0x48),0,1,
                             in_stack_ffffffffffffff08);
    }
LAB_1400f8450:
    plVar7 = *(longlong **)(param_1 + 0x2f8);
    *(undefined1 *)(param_1 + 0x3cc) = 5;
    *(undefined4 *)(param_1 + 0x378) = 0;
    if (plVar7 != (longlong *)0x0) {
      plVar13 = (longlong *)*plVar7;
      if (plVar13 != plVar13 + *(byte *)((longlong)plVar7 + 0x34)) {
        do {
          lVar17 = *plVar13;
          iVar19 = 0;
          if (0 < *(int *)(lVar17 + 0x118)) {
            lVar12 = 0;
            do {
              lVar18 = *(longlong *)(lVar17 + 0x110);
              iVar19 = iVar19 + 1;
              pbVar3 = (byte *)(lVar12 + 0x24e + lVar18);
              *pbVar3 = *pbVar3 | 2;
              puVar1 = (uint *)(lVar12 + 0x1f0 + lVar18);
              *puVar1 = *puVar1 | 0x2000;
              *(undefined2 *)(lVar12 + 0x236 + lVar18) = 0xffff;
              lVar12 = lVar12 + 0x520;
            } while (iVar19 < *(int *)(lVar17 + 0x118));
          }
          plVar13 = plVar13 + 1;
        } while (plVar13 !=
                 (longlong *)(*plVar7 + (ulonglong)*(byte *)((longlong)plVar7 + 0x34) * 8));
      }
      plVar7 = *(longlong **)(param_1 + 0x2f8);
      plVar13 = (longlong *)*plVar7;
      if (plVar13 != plVar13 + *(byte *)((longlong)plVar7 + 0x34)) {
        do {
          lVar17 = *plVar13;
          iVar19 = 0;
          if (0 < *(int *)(lVar17 + 0x118)) {
            lVar12 = 0;
            do {
              lVar18 = *(longlong *)(lVar17 + 0x110);
              iVar19 = iVar19 + 1;
              pbVar3 = (byte *)(lVar12 + 0x24e + lVar18);
              *pbVar3 = *pbVar3 | 1;
              *(undefined2 *)(lVar12 + 0x236 + lVar18) = 0xffff;
              lVar12 = lVar12 + 0x520;
            } while (iVar19 < *(int *)(lVar17 + 0x118));
          }
          *(uint *)(lVar17 + 0x120) = *(uint *)(lVar17 + 0x120) | 0x10;
          plVar13 = plVar13 + 1;
        } while (plVar13 !=
                 (longlong *)(*plVar7 + (ulonglong)*(byte *)((longlong)plVar7 + 0x34) * 8));
      }
    }
    *(undefined2 *)(param_1 + 0x3be) = 0;
    local_res8 = (float)CONCAT22(local_res8._2_2_,0x16);
    local_res10 = CONCAT62(local_res10._2_6_,1);
    FUN_1401c6150(uVar24,&local_res10,&local_res8);
    if (*(char *)(param_1 + 0x3e6) != '\x05') {
      *(undefined1 *)(param_1 + 0x3e6) = 4;
    }
    *(byte *)(param_1 + 0x3dc) = *(byte *)(param_1 + 0x3dc) | 1;
  }
  uVar5 = *(ushort *)(lVar6 + 0x4a);
  if (uVar5 == 0xffff) {
    uVar10 = local_res18[0];
    goto LAB_1400f8644;
  }
  lVar17 = (*(undefined8 **)(param_1 + 0x300))[3];
  if (lVar17 != 0) {
    puVar21 = (undefined8 *)**(undefined8 **)(param_1 + 0x300);
    if (puVar21 == (undefined8 *)0x0) {
      uVar10 = local_res18[0] & 0xff;
      if (*(short *)(lVar6 + 0x4c) == 0) {
        uVar10 = 1;
      }
      goto LAB_1400f8644;
    }
    if (uVar5 < *(ushort *)*puVar21) {
      uVar10 = local_res18[0] & 0xff;
      if (*(short *)(lVar17 + (ulonglong)uVar5 * 2) == *(short *)(lVar6 + 0x4c)) {
        uVar10 = 1;
      }
      goto LAB_1400f8644;
    }
  }
  uVar10 = local_res18[0] & 0xff;
  if (*(short *)(lVar6 + 0x4c) == 0) {
    uVar10 = 1;
  }
LAB_1400f8644:
  if (*(char *)(param_1 + 0x402) != '\0') {
    if (*(int *)(param_1 + 0x3f4) <=
        *(int *)(*(longlong *)(*(longlong *)**(longlong **)(param_1 + 0x2f8) + 0x110) + 0x420)) {
      uVar10 = 1;
    }
    uVar10 = uVar10 & 0xff;
    if (*(int *)(param_1 + 0x3f4) <=
        *(int *)(*(longlong *)(((longlong *)**(longlong **)(param_1 + 0x2f8))[1] + 0x110) + 0x420))
    {
      uVar10 = 1;
    }
  }
  uVar14 = 0;
  if (cVar8 == '\0') {
    uVar14 = uVar10 & 0xff;
  }
  if ((char)uVar14 != '\0') {
    *(undefined1 *)(param_1 + 0x3cc) = 4;
    *(undefined4 *)(param_1 + 0x378) = 0;
    if ((*(uint *)(lVar6 + 0x40) >> 0xc & 1) != 0) {
      if ((*(uint *)(lVar6 + 0x40) >> 0xe & 1) != 0) {
        local_res8 = (float)(int)*(short *)(lVar22 + 4);
        FUN_1401cb5c0(&DAT_14031f000,&local_res8,param_1 + 0x2c4);
      }
      uVar14 = (uint)(fVar32 * *(float *)(lVar6 + 0x3c));
      uVar11 = (ulonglong)*(byte *)(lVar22 + 0xc);
      fVar33 = (float)*(byte *)(lVar6 + 0x69) * fVar33;
      (&DAT_140310a70)[uVar11 * 8] = fVar33;
      if (uVar14 != 0) {
        fVar31 = (fVar33 - (float)(&DAT_140310a64)[uVar11 * 8]) / (float)(int)uVar14;
      }
      *(float *)(&DAT_140310a74 + uVar11 * 0x20) = fVar31;
      (&DAT_140310a6c)[uVar11 * 8] = uVar14;
      (&DAT_140310a78)[uVar11 * 0x20] = 2;
    }
    if ((*(byte *)(lVar6 + 0x40) & 0x40) != 0) {
      local_res10 = CONCAT62(local_res10._2_6_,1);
      local_res8 = (float)CONCAT22(local_res8._2_2_,0x15);
      FUN_1401c6150(uVar14,&local_res10,&local_res8);
      plVar7 = *(longlong **)(param_1 + 0x2f8);
      if (plVar7 != (longlong *)0x0) {
        plVar13 = (longlong *)*plVar7;
        if (plVar13 != plVar13 + *(byte *)((longlong)plVar7 + 0x34)) {
          do {
            lVar22 = *plVar13;
            iVar19 = 0;
            if (0 < *(int *)(lVar22 + 0x118)) {
              lVar17 = 0;
              do {
                lVar12 = *(longlong *)(lVar22 + 0x110);
                iVar19 = iVar19 + 1;
                pbVar3 = (byte *)(lVar17 + 0x24e + lVar12);
                *pbVar3 = *pbVar3 | 2;
                puVar1 = (uint *)(lVar17 + 0x1f0 + lVar12);
                *puVar1 = *puVar1 | 0x2000;
                *(undefined2 *)(lVar17 + 0x236 + lVar12) = 0xffff;
                lVar17 = lVar17 + 0x520;
              } while (iVar19 < *(int *)(lVar22 + 0x118));
            }
            plVar13 = plVar13 + 1;
          } while (plVar13 !=
                   (longlong *)(*plVar7 + (ulonglong)*(byte *)((longlong)plVar7 + 0x34) * 8));
        }
        plVar7 = *(longlong **)(param_1 + 0x2f8);
        plVar13 = (longlong *)*plVar7;
        if (plVar13 != plVar13 + *(byte *)((longlong)plVar7 + 0x34)) {
          do {
            lVar22 = *plVar13;
            iVar19 = 0;
            if (0 < *(int *)(lVar22 + 0x118)) {
              lVar17 = 0;
              do {
                lVar12 = *(longlong *)(lVar22 + 0x110);
                iVar19 = iVar19 + 1;
                pbVar3 = (byte *)(lVar17 + 0x24e + lVar12);
                *pbVar3 = *pbVar3 | 1;
                *(undefined2 *)(lVar17 + 0x236 + lVar12) = 0xffff;
                lVar17 = lVar17 + 0x520;
              } while (iVar19 < *(int *)(lVar22 + 0x118));
            }
            *(uint *)(lVar22 + 0x120) = *(uint *)(lVar22 + 0x120) | 0x10;
            plVar13 = plVar13 + 1;
          } while (plVar13 !=
                   (longlong *)(*plVar7 + (ulonglong)*(byte *)((longlong)plVar7 + 0x34) * 8));
        }
      }
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x340) + 0xa8790);
      *puVar1 = *puVar1 | 0x40000000;
      *(undefined1 *)(param_1 + 0x3e6) = 3;
    }
    lVar22 = *(longlong *)(param_1 + 0x308);
    if ((lVar22 != 0) && (sVar9 = *(short *)(lVar6 + 0x46), -1 < sVar9)) {
      *(ushort *)(lVar22 + 0x90c) = *(ushort *)(lVar22 + 0x90c) | 8;
      cVar8 = FUN_1401a61a0(lVar22,sVar9,0,1,in_stack_ffffffffffffff08 & 0xffffffffffffff00);
      if (cVar8 == '\0') {
        *(ushort *)(lVar22 + 0x90c) = *(ushort *)(lVar22 + 0x90c) & 0xfff7;
      }
    }
  }
  return;
}

