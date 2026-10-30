/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b8130; RVA 0x1b8130
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1401b8130(longlong param_1,char param_2)

{
  undefined8 *puVar1;
  ushort *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  float fVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  char *pcVar9;
  longlong *plVar10;
  longlong *plVar11;
  uint uVar12;
  undefined8 *puVar13;
  int iVar14;
  longlong lVar15;
  int iVar16;
  ulonglong uVar17;
  char cVar18;
  longlong unaff_GS_OFFSET;
  undefined8 uVar19;
  undefined4 uVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [64];
  undefined2 local_res8 [4];
  undefined2 local_res10 [4];
  
  local_res10[0] = CONCAT11(local_res10[0]._1_1_,param_2);
  if (param_2 == '\0') {
    if (((*(longlong *)(param_1 + 0x67138) != 0) && (*(byte *)(param_1 + 0xa8829) < 2)) &&
       (lVar7 = (longlong)(char)*(byte *)(param_1 + 0xa8829) * 0xd10 +
                *(longlong *)(param_1 + 0x67138), lVar7 != 0)) {
      uVar20 = *(undefined4 *)(lVar7 + 0xc80);
      lVar7 = FUN_140019ef0();
      *(undefined4 *)(lVar7 + 0x1c) = uVar20;
    }
    uVar17 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      do {
        iVar16 = (int)uVar17;
        lVar7 = *(longlong *)(param_1 + 0xa8248);
        lVar15 = uVar17 * 0x27a0;
        *(undefined4 *)(lVar15 + 0x20d0 + lVar7) = *(undefined4 *)(lVar15 + 0x70 + lVar7);
        *(undefined4 *)(lVar15 + 0x20d4 + lVar7) = *(undefined4 *)(lVar15 + 0x74 + lVar7);
        *(undefined4 *)(lVar15 + 0x20d8 + lVar7) = *(undefined4 *)(lVar15 + 0x78 + lVar7);
        *(undefined4 *)(lVar15 + 0x20dc + lVar7) = *(undefined4 *)(lVar15 + 0x7c + lVar7);
        *(undefined4 *)(lVar15 + 0x20e0 + lVar7) = *(undefined4 *)(lVar15 + 0x80 + lVar7);
        *(undefined4 *)(lVar15 + 0x20e4 + lVar7) = *(undefined4 *)(lVar15 + 0x84 + lVar7);
        *(undefined4 *)(lVar15 + 0x20e8 + lVar7) = *(undefined4 *)(lVar15 + 0x88 + lVar7);
        *(undefined4 *)(lVar15 + 0x20ec + lVar7) = *(undefined4 *)(lVar15 + 0x8c + lVar7);
        FUN_1401b5680(lVar15 + 0x2100 + lVar7,lVar15 + 0x1430 + lVar7);
        FUN_1401b6130(lVar15 + 0x2538 + lVar7,lVar15 + 0xc08 + lVar7);
        uVar17 = (ulonglong)(iVar16 + 1U);
        puVar13 = (undefined8 *)(lVar15 + 0x1f08 + lVar7);
        uVar6 = puVar13[1];
        uVar19 = *(undefined8 *)(lVar15 + 0x1f18 + lVar7);
        uVar20 = *(undefined4 *)(lVar15 + 0x2058 + lVar7);
        *(undefined1 *)(lVar15 + 0x271c + lVar7) = *(undefined1 *)(lVar15 + 0x2094 + lVar7);
        *(undefined1 *)(lVar15 + 0x271d + lVar7) = *(undefined1 *)(lVar15 + 0x272c + lVar7);
        *(undefined1 *)(lVar15 + 0x271e + lVar7) = *(undefined1 *)(lVar15 + 0x272d + lVar7);
        *(undefined1 *)(lVar15 + 0x271f + lVar7) = *(undefined1 *)(lVar15 + 0x272e + lVar7);
        *(undefined1 *)(lVar15 + 0x2723 + lVar7) = *(undefined1 *)(lVar15 + 0x2099 + lVar7);
        *(undefined1 *)(lVar15 + 0x2724 + lVar7) = *(undefined1 *)(lVar15 + 0x209a + lVar7);
        *(undefined1 *)(lVar15 + 0x2721 + lVar7) = *(undefined1 *)(lVar15 + 0x209c + lVar7);
        uVar4 = *(undefined1 *)(lVar15 + 0x209d + lVar7);
        puVar1 = (undefined8 *)(lVar15 + 0x2680 + lVar7);
        *puVar1 = *puVar13;
        puVar1[1] = uVar6;
        puVar13 = (undefined8 *)(lVar15 + 0x1f20 + lVar7);
        uVar6 = puVar13[1];
        *(undefined1 *)(lVar15 + 0x2722 + lVar7) = uVar4;
        *(undefined8 *)(lVar15 + 0x2690 + lVar7) = uVar19;
        uVar19 = *(undefined8 *)(lVar15 + 0x1f30 + lVar7);
        puVar1 = (undefined8 *)(lVar15 + 0x2698 + lVar7);
        *puVar1 = *puVar13;
        puVar1[1] = uVar6;
        *(undefined4 *)(lVar15 + 0x2718 + lVar7) = uVar20;
        *(undefined8 *)(lVar15 + 0x26a8 + lVar7) = uVar19;
        puVar13 = (undefined8 *)(lVar15 + 0x1f38 + lVar7);
        uVar6 = puVar13[1];
        uVar19 = *(undefined8 *)(lVar15 + 0x1f48 + lVar7);
        puVar1 = (undefined8 *)(lVar15 + 0x26b0 + lVar7);
        *puVar1 = *puVar13;
        puVar1[1] = uVar6;
        *(undefined8 *)(lVar15 + 0x26c0 + lVar7) = uVar19;
        puVar13 = (undefined8 *)(lVar15 + 0x1f50 + lVar7);
        uVar19 = puVar13[1];
        puVar1 = (undefined8 *)(lVar15 + 0x26c8 + lVar7);
        *puVar1 = *puVar13;
        puVar1[1] = uVar19;
        *(undefined8 *)(lVar15 + 0x26d8 + lVar7) = *(undefined8 *)(lVar15 + 0x1f60 + lVar7);
        puVar13 = (undefined8 *)(lVar15 + 0x1f68 + lVar7);
        uVar19 = puVar13[1];
        puVar1 = (undefined8 *)(lVar15 + 0x26e0 + lVar7);
        *puVar1 = *puVar13;
        puVar1[1] = uVar19;
        *(undefined8 *)(lVar15 + 0x26f0 + lVar7) = *(undefined8 *)(lVar15 + 0x1f78 + lVar7);
        puVar13 = (undefined8 *)(lVar15 + 0x1f80 + lVar7);
        uVar19 = puVar13[1];
        puVar1 = (undefined8 *)(lVar15 + 0x26f8 + lVar7);
        *puVar1 = *puVar13;
        puVar1[1] = uVar19;
        *(undefined8 *)(lVar15 + 0x2708 + lVar7) = *(undefined8 *)(lVar15 + 0x1f90 + lVar7);
        *(undefined4 *)(lVar15 + 10000 + lVar7) = *(undefined4 *)(lVar15 + 0x1640 + lVar7);
        *(undefined4 *)(lVar15 + 0x2714 + lVar7) = *(undefined4 *)(lVar15 + 0x1848 + lVar7);
        *(undefined4 *)(lVar15 + 0x20f0 + lVar7) = *(undefined4 *)(lVar15 + 0x1818 + lVar7);
        *(undefined4 *)(lVar15 + 0x20f4 + lVar7) = *(undefined4 *)(lVar15 + 0x181c + lVar7);
        *(undefined4 *)(lVar15 + 0x20f8 + lVar7) = *(undefined4 *)(lVar15 + 0x1820 + lVar7);
        *(undefined4 *)(lVar15 + 0x20fc + lVar7) = *(undefined4 *)(lVar15 + 0x1824 + lVar7);
      } while (iVar16 + 1U < (uint)*(byte *)(param_1 + 0xa87e4));
    }
    FUN_140277ba0(param_1 + 0x6a830,param_1 + 0x6a288,0x580);
    *(undefined4 *)(param_1 + 0x6adb0) = *(undefined4 *)(param_1 + 0x6a808);
    *(undefined4 *)(param_1 + 0x6adb4) = *(undefined4 *)(param_1 + 0x6a80c);
    *(undefined4 *)(param_1 + 0x6adb8) = *(undefined4 *)(param_1 + 0x6a810);
    *(undefined4 *)(param_1 + 0x6adbc) = *(undefined4 *)(param_1 + 0x6a814);
    *(undefined4 *)(param_1 + 0x6adc0) = *(undefined4 *)(param_1 + 0x6a818);
    *(undefined4 *)(param_1 + 0x6adc8) = *(undefined4 *)(param_1 + 0x6a820);
    *(undefined2 *)(param_1 + 0x6adcc) = *(undefined2 *)(param_1 + 0x6a824);
    FUN_140277ba0(param_1 + 0x6b530,param_1 + 0x6ae08,0x700);
    *(undefined4 *)(param_1 + 0x6bc30) = *(undefined4 *)(param_1 + 0x6b508);
    *(undefined8 *)(param_1 + 0x6b514) = 0xffffffffffffffff;
    *(undefined4 *)(param_1 + 0x6b510) = 0;
    *(undefined2 *)(param_1 + 0x6b51c) = 0xffff;
    FUN_140277ba0(param_1 + 0x89ed0,param_1 + 0x6bc40,0x1e280);
    *(undefined1 *)(param_1 + 0xa8150) = *(undefined1 *)(param_1 + 0x89ec0);
    *(longlong *)(param_1 + 0x67120) = param_1 + 0x339b0;
  }
  iVar16 = 0;
  if (*(char *)(param_1 + 0x697ec) != '\0') {
    lVar7 = *(longlong *)(param_1 + 0x697b8);
    lVar15 = 0;
    do {
      iVar14 = 0;
      if (0 < *(int *)(*(longlong *)(lVar15 + lVar7) + 0x118)) {
        lVar8 = 0;
        do {
          lVar8 = lVar8 + 0x520;
          iVar14 = iVar14 + 1;
          lVar7 = *(longlong *)(*(longlong *)(lVar15 + lVar7) + 0x110);
          *(undefined8 *)(lVar7 + -0x138 + lVar8) = 0;
          *(undefined8 *)(lVar7 + -0x130 + lVar8) = 0;
          *(undefined8 *)(lVar7 + -0x128 + lVar8) = 0;
          *(undefined8 *)(lVar7 + -0x120 + lVar8) = 0;
          lVar7 = *(longlong *)(param_1 + 0x697b8);
        } while (iVar14 < *(int *)(*(longlong *)(lVar15 + lVar7) + 0x118));
      }
      iVar16 = iVar16 + 1;
      lVar15 = lVar15 + 8;
    } while (iVar16 < (int)(uint)*(byte *)(param_1 + 0x697ec));
  }
  lVar7 = FUN_140019ef0();
  uVar20 = *(undefined4 *)(lVar7 + 0x1c);
  lVar7 = FUN_140019ef0();
  *(undefined4 *)(lVar7 + 0x18) = uVar20;
  *(undefined4 *)(param_1 + 0x6a820) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x6a824) = 0;
  *(undefined4 *)(param_1 + 0x6a818) = 0;
  *(undefined4 *)(param_1 + 0x6b508) = 0;
  *(undefined4 *)(param_1 + 0x6b510) = 0;
  *(undefined8 *)(param_1 + 0x6b514) = 0xffffffffffffffff;
  *(undefined2 *)(param_1 + 0x6b51c) = 0xffff;
  FUN_140140b50(param_1 + 0x6bc40);
  DAT_14033bd64 = DAT_1402d2c40;
  *(undefined1 *)(param_1 + 0x89ec0) = 0;
  cVar18 = (char)local_res10[0];
  auVar22 = ZEXT864(0);
  DAT_14033bd68 = 0;
  DAT_14033bd6c = 0;
  DAT_14033bd70 = 0;
  FUN_1401b6480(&DAT_14033bd60,(char)local_res10[0]);
  FUN_1401a9a20(param_1 + 0x69a10);
  auVar21 = auVar22._0_16_;
  lVar7 = *(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110);
  uVar20 = *(undefined4 *)(lVar7 + 0x25c);
  fVar5 = *(float *)(lVar7 + 0x260) + DAT_1402d2814;
  *(undefined4 *)(param_1 + 0x69880) = *(undefined4 *)(lVar7 + 600);
  *(undefined4 *)(param_1 + 0x69884) = uVar20;
  *(float *)(param_1 + 0x69888) = fVar5;
  *(undefined4 *)(param_1 + 0x6988c) = 0x3f800000;
  DAT_14032c480 = 0;
  lVar7 = *(longlong *)(param_1 + 0x67120);
  *(undefined8 *)(lVar7 + 0x1bc48) = 0;
  *(undefined8 *)(lVar7 + 0x1bc50) = 0;
  *(undefined8 *)(lVar7 + 0x1bc58) = 0;
  *(undefined8 *)(lVar7 + 0x1bc60) = 0;
  *(undefined8 *)(lVar7 + 0x1bc68) = 0;
  *(undefined8 *)(lVar7 + 0x1bc70) = 0;
  *(undefined8 *)(lVar7 + 0x1bc78) = 0;
  *(undefined8 *)(lVar7 + 0x1bc80) = 0;
  *(int *)(lVar7 + 0x1bc8c) = *(int *)(lVar7 + 0x1bc8c) + 1;
  *(undefined4 *)(lVar7 + 0x1bc88) = 0;
  if (0xe < *(int *)(lVar7 + 0x1bc8c)) {
    *(undefined4 *)(lVar7 + 0x1bc8c) = 0;
  }
  uVar12 = 0;
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    do {
      lVar7 = *(longlong *)(param_1 + 0xa8248);
      lVar15 = (ulonglong)uVar12 * 0x27a0;
      *(undefined1 *)(lVar15 + 0x18a8 + lVar7) = 1;
      *(undefined8 *)(lVar15 + 0x1bf0 + lVar7) = 0;
      *(undefined8 *)(lVar15 + 0x1bdc + lVar7) = 0xffffffffffffffff;
      *(undefined8 *)(lVar15 + 0x1bb0 + lVar7) = 0xfffffff;
      *(undefined8 *)(lVar15 + 0x1c0a + lVar7) = 0xffffffffffffffff;
      *(undefined4 *)(lVar15 + 0x1c12 + lVar7) = 0xffffffff;
      *(undefined4 *)(lVar15 + 0x1c16 + lVar7) = 0xffffff;
      *(undefined2 *)(lVar15 + 0x1c26 + lVar7) = 0xffff;
      *(undefined8 *)(lVar15 + 0x1bfc + lVar7) = 0;
      *(undefined4 *)(lVar15 + 0x1bf8 + lVar7) = 0;
      puVar2 = (ushort *)(lVar15 + 0x1c20 + lVar7);
      *puVar2 = *puVar2 & 0xa1;
      *(undefined2 *)(lVar15 + 0x1c04 + lVar7) = 0xffff;
      *(undefined1 *)(lVar15 + 0x1c29 + lVar7) = 0;
      *(undefined1 *)(lVar15 + 0x1c2b + lVar7) = 1;
      auVar22 = ZEXT1664(auVar22._0_16_);
      (**(code **)(**(longlong **)(lVar15 + 0x1868 + lVar7) + 0x60))();
      (**(code **)(**(longlong **)(lVar15 + 0x1870 + lVar7) + 0x60))();
      auVar21 = auVar22._0_16_;
      uVar12 = uVar12 + 1;
      *(undefined1 *)(lVar15 + 0x272f + *(longlong *)(param_1 + 0xa8248)) = 0;
      *(undefined2 *)(lVar15 + 0x208c + *(longlong *)(param_1 + 0xa8248)) = 0;
    } while (uVar12 < *(byte *)(param_1 + 0xa87e4));
    cVar18 = (char)local_res10[0];
  }
  if (*(longlong *)(param_1 + 0xa82a8) != 0) {
    puVar2 = (ushort *)(*(longlong *)(param_1 + 0xa82a8) + 0x90c);
    *puVar2 = *puVar2 | 0x10;
  }
  lVar7 = **(longlong **)(unaff_GS_OFFSET + 0x58);
  if (*(int *)(lVar7 + 4) < DAT_1437dad18) {
    auVar22 = ZEXT1664(auVar21);
    FUN_14022d540(&DAT_1437dad18);
    auVar21 = auVar22._0_16_;
    if (DAT_1437dad18 == -1) {
      _DAT_1437daef0 = 0;
      _DAT_1437daee0 = _DAT_1402d3500;
      uRam00000001437daee8 = _UNK_1402d3508;
      DAT_1437daef4 = 0;
      _Init_thread_footer(&DAT_1437dad18);
      auVar21 = auVar22._0_16_;
    }
  }
  if (*(int *)(lVar7 + 4) < DAT_1437daf04) {
    auVar22 = ZEXT1664(auVar21);
    FUN_14022d540(&DAT_1437daf04);
    auVar21 = auVar22._0_16_;
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
      auVar21 = auVar22._0_16_;
    }
  }
  auVar22 = ZEXT1664(auVar21);
  uVar19 = FUN_1401cb090(&DAT_1437daf20);
  if ((DAT_14031f8b1 & 1) == 0) {
    uVar19 = FUN_140187110((int)(char)(&DAT_14031f8a8)
                                      [(longlong)DAT_1437daee6 + (ulonglong)DAT_14031f8b0 * 4],0);
  }
  if ((*(int *)(lVar7 + 4) < DAT_1437daf04) &&
     (uVar19 = FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
    FUN_1401c93c0();
    uVar19 = _Init_thread_footer(&DAT_1437daf04);
  }
  DAT_1437dece0 = DAT_1437dece0 | 1;
  if (cVar18 == '\0') {
    local_res8[0] = 1;
    local_res10[0] = 0x9a;
    FUN_1401c5fe0(uVar19,local_res8,local_res10,param_1 + 0x671c8);
    if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
       (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
    DAT_1437dece0 = DAT_1437dece0 & 0xfd;
    if (DAT_14033b1b0 != 0) {
      DAT_14033b1b0 = 0;
      puVar13 = &DAT_1403569c0;
      pcVar9 = &DAT_14032dba1;
      do {
        if ((*pcVar9 != '\0') && (*pcVar9 != '\x02')) {
          FUN_140229640(*puVar13,0);
        }
        pcVar9 = pcVar9 + 0x90;
        puVar13 = puVar13 + 1;
      } while ((longlong)pcVar9 < 0x140336ba1);
    }
  }
  plVar11 = *(longlong **)(param_1 + 0x697b8);
  plVar10 = plVar11;
  if (plVar11 != plVar11 + *(byte *)(param_1 + 0x697ec)) {
    do {
      lVar7 = *plVar10;
      iVar16 = 0;
      if (0 < *(int *)(lVar7 + 0x118)) {
        do {
          FUN_140115a70((longlong)iVar16 * 0x520 + *(longlong *)(lVar7 + 0x110));
          iVar16 = iVar16 + 1;
        } while (iVar16 < *(int *)(lVar7 + 0x118));
      }
      plVar11 = *(longlong **)(param_1 + 0x697b8);
      plVar10 = plVar10 + 1;
    } while (plVar10 != plVar11 + *(byte *)(param_1 + 0x697ec));
  }
  uVar12 = 0;
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    do {
      lVar15 = (ulonglong)uVar12 * 0x27a0;
      puVar3 = (uint *)(lVar15 + 0x2058 + *(longlong *)(param_1 + 0xa8248));
      *puVar3 = *puVar3 | 0x200;
      (**(code **)(**(longlong **)(lVar15 + 0x1fa8 + *(longlong *)(param_1 + 0xa8248)) + 8))();
      FUN_1400b95a0(lVar15 + 0x1868 + *(longlong *)(param_1 + 0xa8248));
      lVar7 = *(longlong *)(param_1 + 0xa8248);
      *(undefined4 *)(lVar15 + 0x2084 + lVar7) = 0;
      (**(code **)**(undefined8 **)(lVar15 + 0x1fa8 + lVar7))();
      uVar12 = uVar12 + 1;
    } while (uVar12 < *(byte *)(param_1 + 0xa87e4));
    plVar11 = *(longlong **)(param_1 + 0x697b8);
  }
  _DAT_140326f90 = _DAT_140326f90 | 1;
  if (plVar11 != plVar11 + *(byte *)(param_1 + 0x697ec)) {
    do {
      *(undefined4 *)(*plVar11 + 0x120) = *(undefined4 *)(*plVar11 + 0x16c);
      lVar7 = (longlong)*(int *)(*plVar11 + 0x118);
      if (0 < lVar7) {
        lVar15 = 0;
        do {
          lVar8 = *(longlong *)(*(longlong *)(*plVar11 + 0x110) + 0x1c0 + lVar15);
          if ((lVar8 != 0) && (plVar10 = *(longlong **)(lVar8 + 0x10), plVar10 != (longlong *)0x0))
          {
            (**(code **)(*plVar10 + 0x158))(plVar10);
            (**(code **)(*plVar10 + 0x168))(plVar10);
            (**(code **)(*plVar10 + 0x138))(plVar10,auVar22._0_8_,auVar22._0_8_);
            (**(code **)(*plVar10 + 0x140))(plVar10,auVar22._0_8_);
          }
          lVar15 = lVar15 + 0x520;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
      }
      plVar11 = plVar11 + 1;
    } while (plVar11 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  return 1;
}

