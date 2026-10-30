/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d1780; RVA 0xd1780
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d1780(longlong param_1)

{
  uint *puVar1;
  ushort *puVar2;
  undefined4 uVar3;
  char cVar4;
  byte bVar5;
  undefined1 auVar6 [16];
  char cVar7;
  uint uVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  longlong lVar14;
  char cVar15;
  longlong lVar16;
  char *pcVar17;
  longlong lVar18;
  undefined8 *puVar19;
  int iVar20;
  ulonglong uVar21;
  longlong unaff_GS_OFFSET;
  bool bVar22;
  float fVar23;
  undefined8 uVar24;
  undefined1 auVar25 [16];
  undefined8 uVar27;
  undefined1 auVar26 [64];
  undefined1 auVar28 [16];
  undefined1 auVar29 [64];
  undefined2 local_res8 [4];
  undefined2 local_res10 [4];
  
  *(undefined4 *)(param_1 + 0x67230) = 0;
  *(undefined8 *)(param_1 + 0x671f0) = 0;
  *(undefined8 *)(param_1 + 0x67210) = 0;
  *(undefined8 *)(param_1 + 0x67234) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x671f8) = 0;
  *(undefined8 *)(param_1 + 0x67218) = 0;
  *(undefined8 *)(param_1 + 0x67200) = 0;
  *(undefined8 *)(param_1 + 0x67220) = 0;
  *(undefined8 *)(param_1 + 0x6723c) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x67208) = 0;
  *(undefined8 *)(param_1 + 0x67228) = 0;
  plVar10 = *(longlong **)(param_1 + 0x697b8);
  uVar21 = (ulonglong)*(byte *)(param_1 + 0x697ec);
  plVar9 = plVar10;
  if (plVar10 != plVar10 + uVar21) {
    do {
      lVar16 = *plVar9;
      iVar20 = 0;
      if (0 < *(int *)(lVar16 + 0x118)) {
        lVar14 = 0;
        do {
          lVar18 = *(longlong *)(lVar16 + 0x110);
          lVar14 = lVar14 + 0x520;
          iVar20 = iVar20 + 1;
          puVar1 = (uint *)(lVar18 + -0x330 + lVar14);
          *puVar1 = *puVar1 & 0xfeffffff;
          *(undefined1 *)(lVar18 + -0xf3 + lVar14) = 0;
        } while (iVar20 < *(int *)(lVar16 + 0x118));
      }
      uVar21 = (ulonglong)*(byte *)(param_1 + 0x697ec);
      plVar9 = plVar9 + 1;
      plVar10 = *(longlong **)(param_1 + 0x697b8);
    } while (plVar9 != plVar10 + uVar21);
  }
  if ((*(longlong *)(param_1 + 0x67138) != 0) &&
     (uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x67138) + 0xc8c), plVar10 != plVar10 + uVar21
     )) {
    do {
      lVar16 = *plVar10;
      plVar10 = plVar10 + 1;
      *(undefined4 *)(lVar16 + 300) = uVar3;
    } while (plVar10 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  lVar16 = 0;
  if (*(longlong *)(param_1 + 0xa8318) != 0) {
    lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if ((*(byte *)(param_1 + 0xa8790) & 3) == 0) {
      if (lVar16 != 0) {
        *(uint *)(lVar16 + 0x3a8) = *(uint *)(lVar16 + 0x3a8) & 0xfffffffb;
      }
    }
    else if (lVar16 != 0) {
      *(uint *)(lVar16 + 0x3a8) = *(uint *)(lVar16 + 0x3a8) | 4;
    }
    lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if (lVar16 != 0) {
      *(longlong *)(lVar16 + 0x330) =
           (longlong)*(char *)(param_1 + 0xa8829) * 0xd10 + *(longlong *)(param_1 + 0x67138);
    }
    FUN_14012bf60(*(undefined8 *)(param_1 + 0xa8318));
    lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if (((lVar16 != 0) && ((*(byte *)(lVar16 + 0x3a8) & 0x40) != 0)) &&
       (iVar20 = 0, *(char *)(param_1 + 0xa87e4) != '\0')) {
      do {
        FUN_14010e220((longlong)iVar20 * 0x27a0 + *(longlong *)(param_1 + 0xa8248),0);
        iVar20 = iVar20 + 1;
      } while (iVar20 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
    }
    lVar16 = *(longlong *)(param_1 + 0xa8318);
    if ((*(byte *)(lVar16 + 0x21) & 1) != 0) {
      *(undefined1 *)(param_1 + 0xa8822) = 4;
    }
  }
  lVar14 = *(longlong *)(lVar16 + 0x10);
  if (lVar14 == 0) {
    cVar7 = -1;
    cVar15 = -1;
  }
  else {
    puVar19 = *(undefined8 **)(lVar14 + 0x2d8);
    if (((puVar19 == (undefined8 *)0x0) || (*(byte *)*puVar19 <= *(byte *)(lVar14 + 0x3c9))) ||
       (puVar19 = (undefined8 *)(puVar19[1] + (ulonglong)*(byte *)(lVar14 + 0x3c9) * 0x48),
       puVar19 == (undefined8 *)0x0)) {
      cVar7 = -1;
    }
    else {
      cVar7 = *(char *)*puVar19;
    }
    cVar15 = *(char *)(lVar14 + 0x3cc);
  }
  cVar4 = *(char *)(param_1 + 0xa8822);
  if (((cVar4 == '\x04') || (cVar4 == '\b')) || (cVar4 == '\x05')) goto LAB_1400d22ac;
  if ((((lVar14 != 0) && (puVar19 = *(undefined8 **)(lVar14 + 0x2d8), puVar19 != (undefined8 *)0x0))
      && (*(byte *)(lVar14 + 0x3c9) < *(byte *)*puVar19)) &&
     ((puVar19 = (undefined8 *)(puVar19[1] + (ulonglong)*(byte *)(lVar14 + 0x3c9) * 0x48),
      puVar19 != (undefined8 *)0x0 && (*(char *)*puVar19 == '\x02')))) {
    if (((char)DAT_14032c8c0[0x10] != -1) &&
       (bVar5 = *(byte *)((longlong)*(char *)(*DAT_14032c8c0 + 0x2e) * 0x1b + 0x10 +
                         (longlong)DAT_14032c8c0),
       (*(uint *)(*DAT_14032c8c0 + 0x40 + (ulonglong)(bVar5 >> 5) * 4) >> (bVar5 & 0x1f) & 1) != 0))
    {
      FUN_1400c5c00(*(undefined8 *)(param_1 + 0xa8318));
    }
    goto LAB_1400d22ac;
  }
  auVar29 = ZEXT464(DAT_1402d22d0);
  if (cVar7 == '\x01') {
    cVar7 = FUN_140202020(0,0);
    if (cVar7 != '\0') {
      FUN_1400c5c00(lVar16);
    }
    if (cVar15 == '\x01') {
      *(undefined1 *)(param_1 + 0xa87e0) =
           *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10) + 0x3d5);
      cVar7 = FUN_1400d0c40(param_1);
      lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
      if (cVar7 == '\0') {
        if (lVar16 != 0) {
          *(undefined1 *)(lVar16 + 0x3cf) = 3;
        }
      }
      else if (lVar16 != 0) {
        *(undefined1 *)(lVar16 + 0x3cf) = 2;
      }
      iVar20 = 0;
      if (*(char *)(param_1 + 0xa87e4) != '\0') {
        lVar16 = 0;
        do {
          iVar20 = iVar20 + 1;
          puVar2 = (ushort *)(lVar16 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
          *puVar2 = *puVar2 | 0x1c;
          lVar16 = lVar16 + 0x27a0;
        } while (iVar20 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      }
      FUN_1400d46a0(param_1,1);
      iVar20 = 0;
      if (*(byte *)(param_1 + 0xa87e4) != 0) {
        uVar8 = *(uint *)(param_1 + 0xa8790);
        do {
          if ((char)iVar20 == '\0') {
            uVar8 = uVar8 & 0xfffffffe;
          }
          else if ((char)iVar20 == '\x01') {
            uVar8 = uVar8 & 0xfffffffd;
          }
          uVar8 = uVar8 & 0x7fffffff;
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
        *(uint *)(param_1 + 0xa8790) = uVar8;
      }
    }
    else if (cVar15 == '\x02') {
      if (((*(longlong **)(param_1 + 0xa8760) == (longlong *)0x0) ||
          (cVar7 = (**(code **)(**(longlong **)(param_1 + 0xa8760) + 0x20))(), cVar7 != '\0')) &&
         (lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10), lVar16 != 0)) {
        *(undefined1 *)(lVar16 + 0x3cf) = 3;
      }
    }
    else if (cVar15 == '\x03') {
      uVar8 = FUN_1400d03a0(param_1);
      lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
      if ((((lVar16 == 0) ||
           (puVar19 = *(undefined8 **)(lVar16 + 0x2d8), puVar19 == (undefined8 *)0x0)) ||
          (*(byte *)*puVar19 <= *(byte *)(lVar16 + 0x3c9))) ||
         (((puVar19 = (undefined8 *)(puVar19[1] + (ulonglong)*(byte *)(lVar16 + 0x3c9) * 0x48),
           puVar19 == (undefined8 *)0x0 || (*(char *)*puVar19 != '\x01')) ||
          (((*(uint *)(lVar16 + 0x3a8) & 0x4000) == 0 ||
           (auVar29._0_4_ != *(float *)(lVar16 + 0x3a4))))))) {
        bVar22 = false;
      }
      else {
        bVar22 = true;
      }
      if (((uVar8 & 1) != 0) || (bVar22)) {
        FUN_1400d1300(param_1);
        if (((*(uint *)(param_1 + 0xa8790) >> 9 & 1) == 0) &&
           (*(char *)(param_1 + 0xa8822) != '\x01')) {
          *(undefined1 *)(param_1 + 0xa8822) = 1;
        }
        fVar23 = DAT_1402d235c;
        *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xfffffdff;
        lVar16 = *(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110);
        lVar14 = *(longlong *)(lVar16 + 0x1b8);
        puVar1 = (uint *)(lVar16 + 0x1f0);
        *puVar1 = *puVar1 | 3;
        auVar26 = ZEXT464((uint)((fVar23 / (float)*(byte *)(lVar14 + 0x1674)) *
                                (float)*(ushort *)(lVar14 + 0x1444)));
        fVar23 = (float)FUN_140128d90(*(undefined4 *)(lVar14 + 0x15b4));
        *(float *)(lVar14 + 0x1640) =
             auVar26._0_4_ *
             (-(SQRT(fVar23 / *(float *)(lVar14 + 0x1648)) * DAT_1402d20f0) + DAT_1402d20f0) +
             auVar26._0_4_;
        FUN_1401023b0(*(undefined8 *)(*(longlong *)(param_1 + 0xa8318) + 0x10));
        FUN_1400d46a0(param_1,0);
      }
    }
  }
  else if (cVar7 == '\0') {
    if (cVar15 == '\b') {
LAB_1400d1e04:
      if (*(char *)(param_1 + 0xa8827) == '\0') {
        FUN_1401c56d0();
        DAT_140310ae4 = DAT_1402d27a8;
      }
      if (((*(uint *)(param_1 + 0xa8790) >> 9 & 1) == 0) && (*(char *)(param_1 + 0xa8822) != '\x03')
         ) {
        *(undefined1 *)(param_1 + 0xa8822) = 3;
        *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) | 0x200;
      }
      *(undefined2 *)(param_1 + 0x671e8) = 0x100;
      iVar20 = 0;
      *(undefined2 *)(param_1 + 0x671e3) = 0x300;
      *(undefined2 *)(param_1 + 0x671e0) = 0x101;
      *(undefined1 *)(param_1 + 0x671e2) = 1;
      *(undefined1 *)(param_1 + 0x671e5) = 1;
      if (*(char *)(param_1 + 0xa87e4) != '\0') {
        do {
          FUN_14010e220((longlong)iVar20 * 0x27a0 + *(longlong *)(param_1 + 0xa8248),0);
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      }
    }
    else {
      if (cVar15 == '\t') goto LAB_1400d1eb4;
      bVar22 = cVar15 == '\n';
LAB_1400d1d63:
      if (!bVar22) goto LAB_1400d1d69;
LAB_1400d2029:
      uVar24 = FUN_1401c56d0();
      iVar20 = 1;
      if ((DAT_14031f8b1 & 1) == 0) {
        FUN_140187190(uVar24,1);
      }
      if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
         (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
        FUN_1401c93c0();
        _Init_thread_footer(&DAT_1437daf04);
      }
      DAT_1437dece0 = DAT_1437dece0 | 2;
      if (DAT_14033b1b0 != 1) {
        DAT_14033b1b0 = 1;
        puVar19 = &DAT_1403569c0;
        pcVar17 = &DAT_14032dba1;
        do {
          if ((*pcVar17 != '\0') && (*pcVar17 != '\x02')) {
            FUN_140229640(*puVar19,1);
          }
          pcVar17 = pcVar17 + 0x90;
          puVar19 = puVar19 + 1;
        } while ((longlong)pcVar17 < 0x140336ba1);
      }
      FUN_1401b8c40(param_1);
      if (*(byte *)(param_1 + 0xa87e4) < 2) {
        FUN_1401023b0(*(undefined8 *)(*(longlong *)(param_1 + 0xa8318) + 0x10));
      }
      if (*(char *)(param_1 + 0xa8827) == '\0') {
        FUN_1401c56d0();
        DAT_140310ae4 = DAT_1402d2778;
      }
      if (((*(uint *)(param_1 + 0xa8790) >> 9 & 1) == 0) && (*(char *)(param_1 + 0xa8822) != '\x01')
         ) {
        *(undefined1 *)(param_1 + 0xa8822) = 1;
      }
      *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xfffffdff;
      lVar16 = *(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110) + 0x1b8);
      *(byte *)(lVar16 + 0x1863) = *(byte *)(lVar16 + 0x1863) & 0xfe;
      *(undefined4 *)(lVar16 + 0x185c) = 0;
      *(uint *)(lVar16 + 0x2058) = *(uint *)(lVar16 + 0x2058) & 0xffffffdf;
      if (cVar7 != '\0') {
        if (1 < *(byte *)(param_1 + 0x697ec)) {
          lVar14 = 8;
          do {
            lVar18 = *(longlong *)(param_1 + 0x697b8);
            iVar13 = 0;
            lVar11 = *(longlong *)(lVar14 + lVar18);
            if (0 < *(int *)(lVar11 + 0x118)) {
              lVar12 = 0;
              do {
                lVar12 = lVar12 + 0x520;
                iVar13 = iVar13 + 1;
                puVar1 = (uint *)(*(longlong *)(lVar11 + 0x110) + -0x330 + lVar12);
                *puVar1 = *puVar1 & 0xfffffffc;
                lVar11 = *(longlong *)(lVar14 + lVar18);
              } while (iVar13 < *(int *)(lVar11 + 0x118));
            }
            *(uint *)(lVar11 + 0x120) = *(uint *)(lVar11 + 0x120) & 0xfffffffc;
            iVar20 = iVar20 + 1;
            lVar14 = lVar14 + 8;
          } while (iVar20 < (int)(uint)*(byte *)(param_1 + 0x697ec));
        }
        if (cVar7 == '\x06') {
          (**(code **)(**(longlong **)(lVar16 + 0x1fa8) + 8))();
          *(undefined4 *)(lVar16 + 0x2084) = 0;
          (**(code **)**(undefined8 **)(lVar16 + 0x1fa8))();
          *(uint *)(lVar16 + 0x2058) = *(uint *)(lVar16 + 0x2058) & 0xfffffbff;
          *(undefined1 *)(lVar16 + 0xc39) = 0;
          *(undefined4 *)(lVar16 + 0xcbc) = 0x42480000;
        }
        *(undefined1 *)(lVar16 + 0x1dad) = 0;
      }
      if ((cVar7 == '\x04') && ((*(uint *)(param_1 + 0xa8790) >> 0x1d & 1) != 0)) {
        *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xdfffffff;
        FUN_1400c3910(param_1 + 0x697b8);
      }
    }
  }
  else if (cVar7 == '\x04') {
    if (cVar15 == '\a') goto LAB_1400d1e04;
    if (cVar15 != '\b') {
      bVar22 = cVar15 == '\t';
      goto LAB_1400d1d63;
    }
LAB_1400d1eb4:
    DAT_14032c933 = 0;
    DAT_14033dab0 = 0;
    cVar7 = FUN_1401b7480(param_1);
    if (cVar7 != '\0') {
      lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
      puVar19 = *(undefined8 **)(lVar16 + 0x2d8);
      if (((puVar19 != (undefined8 *)0x0) && (*(byte *)(lVar16 + 0x3c9) < *(byte *)*puVar19)) &&
         (puVar19 = (undefined8 *)(puVar19[1] + (ulonglong)*(byte *)(lVar16 + 0x3c9) * 0x48),
         puVar19 != (undefined8 *)0x0)) {
        cVar7 = *(char *)*puVar19;
        cVar15 = *(char *)(lVar16 + 0x3cc);
        if (cVar7 == '\0') {
          bVar22 = cVar15 == '\t';
        }
        else if (cVar7 == '\x04') {
          bVar22 = cVar15 == '\b';
        }
        else {
          if (cVar7 != '\x06') goto LAB_1400d1f35;
          bVar22 = cVar15 == '\a';
        }
        if (bVar22) {
          *(uint *)(lVar16 + 0x3a8) = *(uint *)(lVar16 + 0x3a8) | 0x80000;
        }
      }
    }
LAB_1400d1f35:
    cVar7 = FUN_140202020(0,0);
    if ((cVar7 != '\0') ||
       ((1 < *(byte *)(param_1 + 0xa87e4) && (cVar7 = FUN_140202020(1,0), cVar7 != '\0')))) {
      lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
      puVar19 = *(undefined8 **)(lVar16 + 0x2d8);
      if ((puVar19 != (undefined8 *)0x0) &&
         ((*(byte *)(lVar16 + 0x3c9) < *(byte *)*puVar19 &&
          (puVar19 = (undefined8 *)(puVar19[1] + (ulonglong)*(byte *)(lVar16 + 0x3c9) * 0x48),
          puVar19 != (undefined8 *)0x0)))) {
        cVar7 = *(char *)*puVar19;
        cVar15 = *(char *)(lVar16 + 0x3cc);
        if (cVar7 == '\0') {
          bVar22 = cVar15 == '\t';
        }
        else if (cVar7 == '\x04') {
          bVar22 = cVar15 == '\b';
        }
        else {
          if (cVar7 != '\x06') goto LAB_1400d1d71;
          bVar22 = cVar15 == '\a';
        }
        if ((bVar22) && ((*(uint *)(lVar16 + 0x3a8) >> 0x11 & 1) == 0)) {
          *(uint *)(lVar16 + 0x3a8) = *(uint *)(lVar16 + 0x3a8) | 0x20000;
          uVar24 = FUN_1401c56d0();
          local_res10[0] = 0;
          local_res8[0] = 2;
          FUN_1401c6150(uVar24,local_res10,local_res8);
        }
      }
    }
  }
  else {
    if (cVar7 == '\x06') {
      if (cVar15 == '\x06') goto LAB_1400d1e04;
      if (cVar15 == '\a') goto LAB_1400d1eb4;
      if (cVar15 == '\b') goto LAB_1400d2029;
    }
LAB_1400d1d69:
    FUN_1400ce880(param_1);
  }
LAB_1400d1d71:
  auVar28 = auVar29._0_16_;
  lVar16 = (longlong)*(char *)(param_1 + 0xa8829) * 0xd10 + *(longlong *)(param_1 + 0x67138);
  if ((lVar16 == 0) || (DAT_14033bd60 == '\0')) {
LAB_1400d2245:
    lVar14 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if (lVar14 == 0) {
      auVar25 = ZEXT816(0);
    }
    else {
      auVar25 = ZEXT416(*(uint *)(lVar14 + 0x398));
    }
    auVar6 = vpcmpeqd_avx(ZEXT416(*(uint *)(param_1 + 0xa8790) & 0x20000),SUB6416(ZEXT464(0),0));
    auVar28 = vblendvps_avx(auVar28,auVar25,auVar6);
    fVar23 = auVar28._0_4_;
  }
  else {
    lVar14 = FUN_140019ef0();
    auVar28 = auVar29._0_16_;
    if (lVar14 == 0) goto LAB_1400d2245;
    lVar14 = FUN_140019ef0();
    fVar23 = 0.0;
    if (0.0 <= *(float *)(lVar14 + 0x18)) {
      lVar14 = FUN_140019ef0();
      fVar23 = auVar29._0_4_;
      if (*(float *)(lVar14 + 0x18) <= fVar23) {
        lVar14 = FUN_140019ef0();
        fVar23 = *(float *)(lVar14 + 0x18);
      }
    }
  }
  *(float *)(lVar16 + 0xc80) = fVar23;
  if ((*(longlong *)(param_1 + 0xa8310) != 0) && ((*(byte *)(param_1 + 0xa8790) & 3) == 0)) {
    FUN_140113080(*(longlong *)(param_1 + 0xa8310),param_1);
  }
LAB_1400d22ac:
  cVar7 = *(char *)(param_1 + 0xa8822);
  if (((cVar7 == '\x04') || (cVar7 == '\x06')) || (cVar7 == '\b')) {
    FUN_1400c5ff0(param_1);
    *(uint *)(DAT_14032c8b8 + 0xd0) = *(uint *)(DAT_14032c8b8 + 0xd0) | 0x30;
  }
  if ((*(byte *)(*(longlong *)(param_1 + 0xa8318) + 0x21) & 2) != 0) {
    FUN_1400c5ff0(param_1);
    iVar20 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      puVar19 = (undefined8 *)(param_1 + 0xa88c0);
      do {
        iVar20 = iVar20 + 1;
        *puVar19 = *(undefined8 *)(param_1 + 0xa8920);
        puVar19 = puVar19 + 1;
      } while (iVar20 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
    }
    iVar20 = 0;
    if (0 < *(int *)(param_1 + 0xa82f0)) {
      puVar19 = (undefined8 *)(param_1 + 0xa88d0);
      do {
        iVar20 = iVar20 + 1;
        *puVar19 = *(undefined8 *)(param_1 + 0xa8928);
        puVar19 = puVar19 + 1;
      } while (iVar20 < *(int *)(param_1 + 0xa82f0));
    }
    *(undefined1 *)(param_1 + 0xa8822) = 7;
  }
  if (DAT_14033bd60 == '\0') {
    lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if ((*(byte *)(lVar16 + 0x3a8) & 8) == 0) {
      iVar20 = 0;
      if (0 < *(int *)(param_1 + 0x67230)) {
        lVar14 = 0;
        lVar16 = **(longlong **)(unaff_GS_OFFSET + 0x58);
        uVar24 = _DAT_1402d3500;
        uVar27 = _UNK_1402d3508;
        do {
          lVar18 = 0;
          if (lVar14 < 4) {
            lVar18 = *(longlong *)(param_1 + 0x671f0 + lVar14 * 8);
          }
          if ((*(int *)(lVar16 + 4) < DAT_1437dad18) &&
             (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
            _DAT_1437daef0 = 0;
            DAT_1437daef4 = 0;
            _DAT_1437daee0 = uVar24;
            uRam00000001437daee8 = uVar27;
            _Init_thread_footer(&DAT_1437dad18);
          }
          if ((*(int *)(lVar16 + 4) < DAT_1437daf04) &&
             (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
            FUN_1401c93c0();
            _Init_thread_footer(&DAT_1437daf04);
          }
          iVar20 = iVar20 + 1;
          lVar14 = lVar14 + 1;
          _DAT_1437decd0 = lVar18;
        } while (iVar20 < *(int *)(param_1 + 0x67230));
      }
    }
    else {
      FUN_1401c56d0();
      if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
         (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
        FUN_1401c93c0();
        _Init_thread_footer(&DAT_1437daf04);
      }
      _DAT_1437decd0 = lVar16 + 0xe0;
    }
  }
  else {
    FUN_1401c56d0();
    if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
       (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
    _DAT_1437decd0 = param_1 + 0x69ab0;
  }
  return;
}

