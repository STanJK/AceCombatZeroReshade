/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b6480; RVA 0x1b6480
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401b6480(undefined1 *param_1,char param_2)

{
  ulonglong *puVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined4 *puVar15;
  longlong lVar16;
  longlong lVar17;
  uint uVar18;
  int *piVar19;
  ulonglong uVar20;
  longlong lVar21;
  undefined **ppuVar22;
  short sVar23;
  undefined8 uVar24;
  longlong lVar25;
  ulonglong uVar26;
  longlong unaff_GS_OFFSET;
  char cVar27;
  bool bVar28;
  undefined1 auVar29 [16];
  undefined1 auVar30 [64];
  undefined1 auVar31 [16];
  undefined1 auVar32 [64];
  longlong local_res8;
  longlong local_res20;
  undefined1 local_d8 [16];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  ulonglong local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined1 local_74;
  
  lVar5 = *(longlong *)(param_1 + 0x1c78);
  lVar11 = FUN_140019ef0();
  uVar14 = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(*(longlong *)(lVar11 + 0x28) + 0x60);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(lVar11 + 0x98);
  if (param_2 == '\0') {
    *(undefined8 *)(param_1 + 0x20) = 3;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x1c50) = 0;
  *param_1 = 1;
  *(undefined8 *)(param_1 + 0x48) = 0;
  for (puVar6 = *(undefined8 **)(lVar11 + 0x20); puVar6 != (undefined8 *)(lVar11 + 0x20);
      puVar6 = (undefined8 *)*puVar6) {
    if ((*(char *)((longlong)puVar6 + 0x6b) == '\x03') && (*(short *)(puVar6 + 7) == 3)) {
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(puVar6 + 0xc);
    }
    if (*(char *)((longlong)puVar6 + 0x6b) == '\x06') {
      puVar15 = (undefined4 *)(param_1 + ((longlong)*(int *)(param_1 + 0x1c50) + 0xc5) * 0x10);
      iVar9 = *(int *)(param_1 + 0x1c50) + 1;
      *(int *)(param_1 + 0x1c50) = iVar9;
      if (iVar9 < 0x101) {
        *puVar15 = *(undefined4 *)(puVar6 + 0xc);
        puVar15[1] = *(undefined4 *)(puVar6 + 4);
        *(undefined1 *)(puVar15 + 2) = *(undefined1 *)((longlong)puVar6 + 0x34);
        *(undefined1 *)((longlong)puVar15 + 9) = *(undefined1 *)(puVar6 + 7);
        *(undefined1 *)((longlong)puVar15 + 10) = *(undefined1 *)((longlong)puVar6 + 0x3f);
        *(undefined1 *)((longlong)puVar15 + 0xb) = *(undefined1 *)(puVar6 + 8);
        *(undefined1 *)(puVar15 + 3) = *(undefined1 *)((longlong)puVar6 + 0x41);
      }
      if (((*(char *)((longlong)puVar6 + 0x6b) == '\x06') &&
          (*(char *)((longlong)puVar6 + 0x34) == '\x04')) && (*(char *)(puVar6 + 7) == '\x04')) {
        *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(puVar6 + 0xc);
      }
    }
  }
  iVar9 = 0;
  auVar32 = ZEXT464(DAT_1402d2c40);
  auVar31 = ZEXT416(DAT_1402d2c40);
  uVar24 = 0xffffffff;
  uVar18 = 0xffffffff;
  auVar30 = ZEXT864(0);
  auVar29 = auVar30._0_16_;
  lVar21 = lVar5;
  if (*(char *)(lVar5 + 0x697ec) != '\0') {
    lVar16 = *(longlong *)(lVar5 + 0x697b8);
    lVar25 = 0;
    uVar20 = uVar14;
    do {
      if (param_2 == '\0') {
        *(undefined4 *)(*(longlong *)(lVar16 + lVar25) + 0x16c) =
             *(undefined4 *)(*(longlong *)(lVar16 + lVar25) + 0x120);
      }
      lVar16 = *(longlong *)(lVar21 + 0x697b8);
      uVar13 = uVar20 & 0xffffffff;
      uVar14 = uVar20;
      if (0 < *(int *)(*(longlong *)(lVar16 + (longlong)iVar9 * 8) + 0x118)) {
        do {
          lVar16 = *(longlong *)(*(longlong *)(lVar25 + lVar16) + 0x110) + uVar20;
          if (param_2 == '\0') {
            auVar30 = ZEXT1664(auVar30._0_16_);
            auVar32 = ZEXT1664(auVar32._0_16_);
            FUN_140119280(lVar16);
            uVar14 = 0;
            uVar24 = 0xffffffff;
            lVar21 = lVar5;
          }
          *(undefined2 *)(lVar16 + 0x428) = 0xff;
          *(int *)(lVar16 + 0x3c0) = (int)uVar14;
          *(short *)(lVar16 + 0x442) = (short)uVar24;
          *(short *)(lVar16 + 0x22a) = (short)uVar14;
          if (*(longlong *)(lVar16 + 0x3d0) != 0) {
            for (lVar7 = *(longlong *)(*(longlong *)(lVar16 + 0x3d0) + 0x10); lVar7 != 0;
                lVar7 = *(longlong *)(lVar7 + 0x10)) {
              if (*(char *)(lVar7 + 0x6b) == '\0') {
                local_d8 = ZEXT816(0);
                local_a8 = ZEXT816(0);
                uStack_c4 = auVar30._0_4_;
                uStack_c8 = auVar32._0_4_;
                local_80 = 0;
                local_74 = 0;
                auVar30 = ZEXT1664(auVar30._0_16_);
                auVar32 = ZEXT1664(auVar32._0_16_);
                uStack_c0 = uStack_c4;
                uStack_bc = uStack_c4;
                local_b8 = local_d8;
                local_98 = local_d8;
                local_88 = uVar14;
                local_78 = uStack_c4;
                FUN_14001ddc0(local_d8);
                *(undefined8 *)(lVar16 + 600) = local_d8._0_8_;
                *(undefined8 *)(lVar16 + 0x260) = local_d8._8_8_;
                *(ulonglong *)(lVar16 + 0x268) = CONCAT44(uStack_c4,uStack_c8);
                *(ulonglong *)(lVar16 + 0x270) = CONCAT44(uStack_bc,uStack_c0);
                break;
              }
            }
          }
          lVar16 = *(longlong *)(lVar21 + 0x697b8);
          uVar18 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar18;
          uVar20 = uVar20 + 0x520;
        } while ((int)uVar18 < *(int *)(*(longlong *)(lVar25 + lVar16) + 0x118));
      }
      auVar31 = auVar32._0_16_;
      auVar29 = auVar30._0_16_;
      uVar18 = (uint)uVar24;
      iVar9 = iVar9 + 1;
      lVar25 = lVar25 + 8;
      uVar20 = uVar14;
    } while (iVar9 < (int)(uint)*(byte *)(lVar21 + 0x697ec));
  }
  uVar26 = (ulonglong)uVar18;
  iVar10 = -0x80000000;
  iVar9 = 0x20;
  uVar18 = 0x80000000;
  uVar20 = *(ulonglong *)(*(longlong *)(**(longlong **)(lVar21 + 0x697b8) + 0x110) + 0x3d0);
  *(undefined1 *)(*(longlong *)(param_1 + 0x1c78) + 0x6a09d) = 0;
  *(int *)(param_1 + 0x18) = 0x20;
  uVar13 = uVar20;
  if (uVar20 == 0) {
LAB_1401b687f:
    *(undefined4 *)(param_1 + 0x18) = 0x20;
  }
  else {
    do {
      if (*(char *)(uVar13 + 0x6b) == '\x06') {
        bVar3 = *(byte *)(uVar13 + 0x34);
        if (bVar3 == 0) {
          uVar14 = CONCAT71((int7)(uVar14 >> 8),10 < *(byte *)(uVar13 + 0x38)) & 0xffffffff;
        }
        else {
          uVar14 = 0xffffffff;
        }
        iVar4 = *(int *)(uVar13 + 0x20);
        if ((iVar4 == iVar10) && (bVar3 == uVar18)) {
          if (bVar3 == 0) {
            if ((int)uVar14 != (int)uVar26) goto LAB_1401b67b8;
          }
        }
        else {
LAB_1401b67b8:
          *(int *)(param_1 + 0x18) = *(int *)(uVar13 + 0x60) + 0x1e;
          uVar26 = uVar14;
          uVar18 = (uint)bVar3;
          iVar10 = iVar4;
        }
        uVar14 = 0;
      }
      puVar1 = (ulonglong *)(uVar13 + 0x10);
      uVar13 = *puVar1;
    } while (*puVar1 != 0);
    if (uVar18 - 4 < 3) goto LAB_1401b68fb;
    uVar13 = uVar20;
    do {
      if ((*(char *)(uVar13 + 0x6b) == '\x06') &&
         (((cVar27 = *(char *)(uVar13 + 0x34), cVar27 == '\x04' || ((byte)(cVar27 - 5U) < 2)) ||
          ((cVar27 == '\0' && (10 < *(byte *)(uVar13 + 0x38))))))) {
        uVar14 = uVar13;
      }
      uVar13 = *(ulonglong *)(uVar13 + 0x10);
    } while (uVar13 != 0);
    if (uVar14 == 0) goto LAB_1401b687f;
    iVar9 = *(int *)(uVar14 + 0x60) + 0x1e;
    *(int *)(param_1 + 0x18) = iVar9;
    lVar21 = *(longlong *)(uVar14 + 0x10);
    if (lVar21 != 0) {
      do {
        if (*(char *)(lVar21 + 0x6b) == '\x06') {
          iVar9 = *(int *)(lVar21 + 0x60) + 0x1e;
          *(int *)(param_1 + 0x18) = iVar9;
          goto LAB_1401b6882;
        }
        lVar21 = *(longlong *)(lVar21 + 0x10);
      } while (lVar21 != 0);
      iVar9 = *(int *)(param_1 + 0x18);
    }
  }
LAB_1401b6882:
  piVar19 = (int *)(param_1 + 0x18);
  lVar21 = *(longlong *)(param_1 + 0x1c78);
  if (*(char *)(lVar21 + 0xa8820) == '\x01') {
    if (4 < *(uint *)(lVar11 + 0xc)) {
      *(undefined1 *)(lVar21 + 0x6a09d) = 1;
      iVar9 = *piVar19;
      if (5 < *(uint *)(lVar11 + 0xc)) goto LAB_1401b68ea;
    }
    if ((1 < *(uint *)(lVar11 + 0x108)) &&
       (iVar10 = *(int *)(*(longlong *)(lVar11 + 0x98) + 0x60), iVar9 < iVar10)) {
      *piVar19 = iVar10;
    }
  }
  else {
    if (*(char *)(lVar21 + 0xa8820) == '\0') {
      if (4 < *(uint *)(lVar11 + 0xc)) {
        *(undefined1 *)(lVar21 + 0x6a09d) = 1;
      }
      iVar10 = *(int *)(param_1 + 0x1c) + -900;
      bVar28 = SBORROW4(*piVar19,iVar10);
      iVar9 = *piVar19 - iVar10;
    }
    else {
LAB_1401b68ea:
      iVar10 = *(int *)(param_1 + 0x1c) + -900;
      bVar28 = SBORROW4(iVar9,iVar10);
      iVar9 = iVar9 - iVar10;
    }
    if (bVar28 != iVar9 < 0) {
      *piVar19 = iVar10;
    }
  }
LAB_1401b68fb:
  iVar10 = *(int *)(param_1 + 0x1c) + -0x1e;
  iVar9 = *(int *)(param_1 + 0x18);
  if (iVar10 < *(int *)(param_1 + 0x18)) {
    *(int *)(param_1 + 0x18) = iVar10;
    iVar9 = iVar10;
  }
  if (iVar9 < 2) {
    *(undefined4 *)(param_1 + 0x18) = 2;
  }
  auVar30 = ZEXT1664(auVar29);
  auVar32 = ZEXT1664(auVar31);
  FUN_140019da0(lVar11);
  uVar24 = 0;
  if (0xf0 < *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) {
    uVar18 = 0;
    for (; uVar20 != 0; uVar20 = *(ulonglong *)(uVar20 + 0x10)) {
      if ((*(char *)(uVar20 + 0x6b) == '\x06') &&
         ((*(char *)(uVar20 + 0x34) == '\x01' || ((byte)(*(char *)(uVar20 + 0x34) - 2U) < 2)))) {
        *(undefined4 *)(lVar11 + 0x110 + (longlong)(int)uVar18 * 4) = *(undefined4 *)(uVar20 + 0x60)
        ;
        uVar18 = uVar18 + 1 & 0x8000001f;
        if ((int)uVar18 < 0) {
          uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
        }
      }
    }
  }
  lVar21 = *(longlong *)(param_1 + 0x1c78);
  lVar16 = 0;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x18);
  param_1[0x1c72] = 0;
  if ((1 < *(byte *)(lVar21 + 0xa87e4)) &&
     (*(int *)(*(longlong *)(**(longlong **)(lVar21 + 0x697b8) + 0x110) + 0x420) <
      *(int *)(*(longlong *)((*(longlong **)(lVar21 + 0x697b8))[1] + 0x110) + 0x420))) {
    param_1[0x1c72] = 1;
    lVar16 = 1;
  }
  *(undefined8 *)(param_1 + 0x1c60) = 0;
  *(undefined8 *)(param_1 + 0x1c58) = 0;
  *(uint *)(param_1 + 0x1c68) =
       (uint)*(byte *)(lVar16 * 0x27a0 + 0x2721 + *(longlong *)(lVar21 + 0xa8248));
  *(uint *)(param_1 + 0x1c6c) =
       (uint)*(byte *)(lVar16 * 0x27a0 + 0x2722 + *(longlong *)(lVar21 + 0xa8248));
  for (puVar6 = *(undefined8 **)(lVar11 + 0x98); puVar6 != (undefined8 *)(lVar11 + 0x98);
      puVar6 = (undefined8 *)*puVar6) {
    if ((((*(int *)(param_1 + 0x18) <= *(int *)(puVar6 + 0xc)) &&
         (*(char *)((longlong)puVar6 + 0x6b) == '\x02')) &&
        (*(char *)((longlong)puVar6 + 0x66) == '\0')) &&
       (*(char *)((longlong)puVar6 + 0x67) == '\0')) {
      if (*(short *)(puVar6 + 4) == 0) {
        *(int *)(param_1 + 0x1c60) = *(int *)(param_1 + 0x1c60) + 1;
      }
      else if (*(short *)(puVar6 + 4) == 1) {
        *(int *)(param_1 + 0x1c64) = *(int *)(param_1 + 0x1c64) + 1;
      }
    }
  }
  if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437d9f84) &&
     (FUN_14022d540(&DAT_1437d9f84), DAT_1437d9f84 == -1)) {
    _DAT_14031e9b0 = 0;
    PTR_LOOP_14031ea18 = (undefined *)&PTR_LOOP_14031ea18;
    PTR_LOOP_14031ea20 = (undefined *)&PTR_LOOP_14031ea18;
    PTR_LOOP_14031eb20 = (undefined *)&PTR_LOOP_14031eb20;
    PTR_LOOP_14031eb28 = (undefined *)&PTR_LOOP_14031eb20;
    PTR_LOOP_14031eb98 = (undefined *)&PTR_LOOP_14031eb98;
    PTR_LOOP_14031eba0 = (undefined *)&PTR_LOOP_14031eb98;
    PTR_LOOP_14031ec10 = (undefined *)&PTR_LOOP_14031ec10;
    PTR_LOOP_14031ec18 = (undefined *)&PTR_LOOP_14031ec10;
    _DAT_14031e9b8 = 0;
    _DAT_14031ea06 = 0xffff;
    PTR_LOOP_14031e9a0 = (undefined *)&PTR_LOOP_14031e9a0;
    PTR_LOOP_14031e9a8 = (undefined *)&PTR_LOOP_14031e9a0;
    _DAT_14031ea10 = 0;
    _DAT_14031ea28 = 0;
    _DAT_14031ea30 = 0;
    _DAT_14031ea7e = 0xffff;
    _DAT_14031ea88 = 0;
    _DAT_14031eb30 = 0;
    _DAT_14031eb38 = 0;
    _DAT_14031eb86 = 0xffff;
    _DAT_14031eb90 = 0;
    _DAT_14031eba8 = 0;
    _DAT_14031ebb0 = 0;
    _DAT_14031ebfe = 0xffff;
    _DAT_14031ec08 = 0;
    _DAT_14031ec20 = (undefined1  [16])0x0;
    _DAT_14031ec76 = 0xffff;
    _DAT_14031ec80 = 0;
    _DAT_14031eda8 = 0;
    DAT_14031eca8 = 0;
    _DAT_14031eb18 = 0;
    _DAT_14031ec88 = 0;
    FUN_140019f80(&DAT_14031e980);
    _Init_thread_footer(&DAT_1437d9f84);
  }
  ppuVar22 = (undefined **)PTR_LOOP_14031e9a0;
  if ((undefined **)PTR_LOOP_14031e9a0 != &PTR_LOOP_14031e9a0) {
    do {
      if (*(char *)((longlong)ppuVar22 + 0x6b) == '\x01') {
        lVar21 = (ulonglong)*(byte *)((longlong)ppuVar22 + 0x67) * 0x520;
        lVar11 = *(longlong *)
                  (*(longlong *)
                    (*(longlong *)(lVar5 + 0x697b8) +
                    (ulonglong)*(byte *)((longlong)ppuVar22 + 0x66) * 8) + 0x110);
        *(undefined8 *)(lVar11 + 0x3a0 + lVar21) = *(undefined8 *)(lVar11 + 0x390 + lVar21);
      }
      if (*(int *)(param_1 + 0x18) <= *(int *)(ppuVar22 + 0xc)) {
        *(undefined ***)(param_1 + 0x28) = ppuVar22;
        break;
      }
      ppuVar22 = (undefined **)*ppuVar22;
    } while (ppuVar22 != &PTR_LOOP_14031e9a0);
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  uVar14 = (ulonglong)*(byte *)(lVar5 + 0x697ec);
joined_r0x0001401b6b67:
  do {
    uVar14 = uVar14 - 1;
    if ((longlong)uVar14 < 0) {
      lVar11 = (ulonglong)(byte)param_1[0x1c72] * 0x27a0;
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x1c78) + 0xa8248);
      *(undefined2 *)(lVar11 + 0x1f10 + lVar5) = 0;
      *(undefined2 *)(lVar11 + 0x1f28 + lVar5) = 0;
      *(undefined2 *)(lVar11 + 8000 + lVar5) = 0;
      *(undefined2 *)(lVar11 + 0x1f58 + lVar5) = 0;
      *(undefined2 *)(lVar11 + 0x1f70 + lVar5) = 0;
      *(undefined2 *)(lVar11 + 0x1f88 + lVar5) = 0;
      *(char *)(lVar11 + 0x2099 + lVar5) =
           *(char *)((ulonglong)(byte)param_1[0x1c72] * 0x27a0 + 0x2723 +
                    *(longlong *)(*(longlong *)(param_1 + 0x1c78) + 0xa8248)) + param_1[0x1c60];
      *(char *)(lVar11 + 0x209a + lVar5) =
           *(char *)((ulonglong)(byte)param_1[0x1c72] * 0x27a0 + 0x2724 +
                    *(longlong *)(*(longlong *)(param_1 + 0x1c78) + 0xa8248)) + param_1[0x1c64];
      uVar14 = (ulonglong)*(uint *)(param_1 + 0x1c60);
      cVar27 = param_1[0x1c68];
      if (0 < (int)*(uint *)(param_1 + 0x1c60)) {
        do {
          cVar27 = cVar27 == '\0';
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      *(char *)(lVar11 + 0x209c + lVar5) = cVar27;
      uVar14 = (ulonglong)*(uint *)(param_1 + 0x1c64);
      cVar27 = param_1[0x1c6c];
      if (0 < (int)*(uint *)(param_1 + 0x1c64)) {
        do {
          if (cVar27 == '\0') {
            cVar27 = *(char *)(lVar11 + 0x20b4 + lVar5);
          }
          cVar27 = cVar27 + -1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      *(char *)(lVar11 + 0x209d + lVar5) = cVar27;
      if (1 < *(byte *)(*(longlong *)(param_1 + 0x1c78) + 0xa87e4)) {
        if ((*(int *)((longlong)DAT_14032c8b0 + 0xc) == -1) && (0 < (int)DAT_14032c8b0[1])) {
          lVar21 = DAT_14032c8b0[3];
          lVar16 = *DAT_14032c8b0;
          *(undefined4 *)((longlong)DAT_14032c8b0 + 0xc) = 0;
          puVar6 = *(undefined8 **)(lVar16 + 8);
          if (*(char *)(lVar21 + 0x21) == '\0') {
            *(undefined1 *)(lVar21 + 0x21) = 1;
            uVar24 = *(undefined8 *)(lVar21 + 0x10);
          }
          else {
            uVar24 = 0;
          }
          *puVar6 = 0x20000000;
          FUN_140197b30(puVar6,uVar24);
          puVar6[1] = 0;
        }
        uVar24 = FUN_14014ca50(lVar11 + 0x920 + lVar5,uVar24);
        FUN_1402011a0(DAT_14032c8b0,uVar24);
      }
      return;
    }
    lVar11 = *(longlong *)(lVar5 + 0x697b8);
    iVar9 = *(int *)(*(longlong *)(lVar11 + uVar14 * 8) + 0x118) + -1;
    local_res8 = (longlong)iVar9;
  } while (iVar9 < 0);
  local_res20 = local_res8 * 0x520;
LAB_1401b6b9a:
  sVar23 = 1;
  bVar28 = false;
  lVar25 = *(longlong *)(*(longlong *)(lVar11 + uVar14 * 8) + 0x110) + local_res20;
  lVar21 = local_res8;
  lVar16 = local_res20;
  if (*(longlong *)(lVar25 + 0x3d0) != 0) {
    for (lVar7 = *(longlong *)(*(longlong *)(lVar25 + 0x3d0) + 0x10); lVar7 != 0;
        lVar7 = *(longlong *)(lVar7 + 0x10)) {
      if (*(char *)(lVar7 + 0x6b) == '\0') {
        *(longlong *)(lVar25 + 0x3e0) = lVar7;
        if (lVar7 == 0) goto LAB_1401b6bdf;
        lVar17 = lVar7;
        goto LAB_1401b6d00;
      }
    }
    *(undefined8 *)(lVar25 + 0x3e0) = 0;
    goto LAB_1401b6bdf;
  }
  goto LAB_1401b6dca;
LAB_1401b6d00:
  lVar12 = lVar7;
  if (*(int *)(param_1 + 0x18) < *(int *)(lVar12 + 0x60)) goto LAB_1401b6d27;
  lVar7 = *(longlong *)(lVar12 + 0x10);
  while( true ) {
    lVar17 = lVar12;
    if (lVar7 == 0) goto LAB_1401b6d27;
    if (*(char *)(lVar7 + 0x6b) == '\0') break;
    lVar7 = *(longlong *)(lVar7 + 0x10);
  }
  if (lVar7 == 0) goto LAB_1401b6d27;
  goto LAB_1401b6d00;
LAB_1401b6d27:
  if (lVar17 == 0) {
LAB_1401b6bdf:
    for (lVar17 = *(longlong *)(*(longlong *)(lVar25 + 0x3d0) + 0x10); lVar17 != 0;
        lVar17 = *(longlong *)(lVar17 + 0x10)) {
      if (*(char *)(lVar17 + 0x6b) == '\0') goto LAB_1401b6c01;
    }
    lVar17 = 0;
LAB_1401b6c01:
    if (lVar17 == 0) goto LAB_1401b6dca;
  }
  uVar18 = *(uint *)(lVar17 + 0x50);
  *(uint *)(lVar25 + 0x1f0) = uVar18;
  local_d8 = ZEXT816(0);
  *(uint *)(lVar25 + 500) = (uint)*(ushort *)(lVar17 + 0x54);
  local_a8 = ZEXT816(0);
  *(ushort *)(lVar25 + 0x44c) = (ushort)((uVar18 & 0x1080002) != 2);
  uStack_c4 = auVar30._0_4_;
  uStack_c8 = auVar32._0_4_;
  local_88 = 0;
  local_80 = 0;
  local_74 = 0;
  auVar30 = ZEXT1664(auVar30._0_16_);
  auVar32 = ZEXT1664(auVar32._0_16_);
  uStack_c0 = uStack_c4;
  uStack_bc = uStack_c4;
  local_b8 = local_d8;
  local_98 = local_d8;
  local_78 = uStack_c4;
  FUN_14001ddc0(local_d8,lVar17);
  *(undefined8 *)(lVar25 + 600) = local_d8._0_8_;
  *(undefined8 *)(lVar25 + 0x260) = local_d8._8_8_;
  *(ulonglong *)(lVar25 + 0x268) = CONCAT44(uStack_c4,uStack_c8);
  *(ulonglong *)(lVar25 + 0x270) = CONCAT44(uStack_bc,uStack_c0);
  if ((*(uint *)(lVar25 + 0x1f0) & 0x20000000) != 0) {
    if (*(longlong **)(lVar25 + 0x398) != (longlong *)0x0) {
      if (*(longlong *)(lVar25 + 0x1c0) == 0) {
        lVar21 = **(longlong **)(lVar25 + 0x398);
        if (*(short *)(lVar17 + 0x58) < sVar23) {
          auVar30 = ZEXT1664(auVar30._0_16_);
          auVar32 = ZEXT1664(auVar32._0_16_);
          (**(code **)(lVar21 + 0x58))();
          auVar29._0_4_ = (float)(int)*(short *)(lVar17 + 0x58);
          auVar29._4_12_ = SUB1612(ZEXT816(0),4);
          (**(code **)(**(longlong **)(lVar25 + 0x398) + 0x40))
                    (*(longlong **)(lVar25 + 0x398),1,auVar29._0_8_);
        }
        else {
          auVar30 = ZEXT1664(auVar30._0_16_);
          auVar32 = ZEXT1664(auVar32._0_16_);
          (**(code **)(lVar21 + 0x60))();
        }
        lVar21 = local_res8;
        lVar16 = local_res20;
      }
    }
  }
  do {
    if ((*(byte *)(lVar17 + 0x50) & 3) != 0) {
      bVar28 = true;
      puVar2 = (uint *)(*(longlong *)(lVar11 + uVar14 * 8) + 0x120);
      *puVar2 = *puVar2 | 5;
    }
    lVar17 = *(longlong *)(lVar17 + 0x10);
    while( true ) {
      if (lVar17 == 0) goto LAB_1401b6db4;
      if (*(char *)(lVar17 + 0x6b) == '\0') break;
      lVar17 = *(longlong *)(lVar17 + 0x10);
    }
  } while (lVar17 != 0);
LAB_1401b6db4:
  if (bVar28) {
    uVar8 = *(undefined8 *)(param_1 + 0x38);
    *(longlong *)(param_1 + 0x38) = lVar25;
    *(undefined8 *)(lVar25 + 0x3b8) = uVar8;
  }
LAB_1401b6dca:
  local_res8 = lVar21 + -1;
  local_res20 = lVar16 + -0x520;
  if (local_res8 < 0) goto joined_r0x0001401b6b67;
  goto LAB_1401b6b9a;
}

