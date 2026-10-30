/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400cd880; RVA 0xcd880
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400cd880(longlong param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined1 auVar14 [16];
  undefined8 uVar15;
  undefined8 uVar16;
  ushort uVar17;
  int iVar18;
  longlong *plVar19;
  longlong *plVar20;
  undefined8 uVar21;
  byte bVar22;
  undefined8 *puVar23;
  longlong lVar24;
  ulonglong uVar25;
  longlong lVar26;
  int iVar27;
  float *pfVar28;
  uint uVar29;
  ulonglong uVar30;
  longlong lVar31;
  longlong unaff_GS_OFFSET;
  undefined1 auStack_238 [32];
  float local_218;
  undefined8 local_214;
  undefined8 uStack_20c;
  undefined2 local_204;
  undefined2 local_202;
  undefined2 local_200;
  undefined2 local_1fe;
  float local_1fc;
  float local_1f8;
  short local_1f4;
  undefined2 local_1f2;
  short local_1f0;
  undefined2 local_1ee;
  float local_1ec;
  uint local_78;
  undefined4 local_68;
  undefined2 local_64;
  ulonglong local_58;
  
  local_58 = DAT_140309040 ^ (ulonglong)auStack_238;
  *(undefined4 *)(param_1 + 0xa878c) = 0;
  *(undefined2 *)(param_1 + 0x69798) = 0;
  *(undefined8 *)(param_1 + 0x6979a) = 0;
  *(undefined8 *)(param_1 + 0x697a2) = 0;
  *(undefined8 *)(param_1 + 0x697aa) = 0;
  *(undefined4 *)(param_1 + 0x697b2) = 0;
  *(undefined2 *)(param_1 + 0x697b6) = 0;
  *(undefined2 **)(*(longlong *)(param_1 + 0xa8318) + 8) = (undefined2 *)(param_1 + 0x69798);
  plVar20 = *(longlong **)(param_1 + 0xa8318);
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8280) + 0x18);
  if (lVar24 != 0) {
    *plVar20 = lVar24;
    *(undefined1 *)(plVar20 + 4) = 0;
    lVar24 = *(longlong *)(lVar24 + 8);
    FUN_1400f5af0(plVar20[2],*(undefined8 *)(lVar24 + 0x10),0);
    puVar23 = (undefined8 *)plVar20[1];
    if ((puVar23 != (undefined8 *)0x0) &&
       (puVar12 = *(undefined8 **)(lVar24 + 8), puVar12 != (undefined8 *)0x0)) {
      puVar12 = (undefined8 *)*puVar12;
      if (((undefined8 *)((longlong)puVar12 + 0x1eU) < puVar23) ||
         ((undefined8 *)((longlong)puVar23 + 0x1eU) < puVar12)) {
        uVar21 = puVar12[1];
        uVar15 = puVar12[2];
        uVar16 = puVar12[3];
        *puVar23 = *puVar12;
        puVar23[1] = uVar21;
        puVar23[2] = uVar15;
        puVar23[3] = uVar16;
      }
      else {
        lVar26 = (longlong)puVar12 - (longlong)puVar23;
        lVar24 = 0x10;
        do {
          *(undefined2 *)puVar23 = *(undefined2 *)((longlong)puVar23 + lVar26);
          puVar23 = (undefined8 *)((longlong)puVar23 + 2);
          lVar24 = lVar24 + -1;
        } while (lVar24 != 0);
      }
    }
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(longlong *)(lVar24 + 0x300) = param_1 + 0x69748;
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(longlong *)(lVar24 + 0x2f8) = param_1 + 0x697b8;
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(undefined8 *)(lVar24 + 0x308) = *(undefined8 *)(param_1 + 0xa82a8);
  }
  lVar24 = *(longlong *)(param_1 + 0xa8318);
  if (*(longlong *)(lVar24 + 0x10) != 0) {
    *(longlong *)(*(longlong *)(lVar24 + 0x10) + 0x338) = param_1 + 0x240;
    lVar24 = *(longlong *)(param_1 + 0xa8318);
  }
  if (*(longlong *)(param_1 + 0xa82b0) != 0) {
    if (*(longlong *)(lVar24 + 0x10) != 0) {
      *(longlong *)(*(longlong *)(lVar24 + 0x10) + 800) = *(longlong *)(param_1 + 0xa82b0);
      lVar24 = *(longlong *)(param_1 + 0xa8318);
    }
    lVar26 = *(longlong *)(*(longlong *)(param_1 + 0xa82b0) + 0x10);
    if ((lVar26 != 0) && (*(longlong *)(lVar24 + 0x10) != 0)) {
      *(longlong *)(*(longlong *)(lVar24 + 0x10) + 0x310) = lVar26;
      lVar24 = *(longlong *)(param_1 + 0xa8318);
    }
    lVar26 = *(longlong *)(*(longlong *)(param_1 + 0xa82b0) + 0x18);
    if ((lVar26 != 0) && (*(longlong *)(lVar24 + 0x10) != 0)) {
      *(longlong *)(*(longlong *)(lVar24 + 0x10) + 0x318) = lVar26;
    }
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(undefined8 *)(lVar24 + 0x328) = *(undefined8 *)(param_1 + 0xa8270);
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(undefined1 *)(lVar24 + 0x3d1) = *(undefined1 *)(param_1 + 0xa8825);
  }
  uVar10 = *(undefined1 *)(param_1 + 0xa8795);
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  *(undefined1 *)(*(longlong *)(param_1 + 0xa8318) + 0x22) = uVar10;
  if (lVar24 != 0) {
    *(undefined1 *)(lVar24 + 0x3d6) = uVar10;
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(undefined1 *)(lVar24 + 0x3da) = *(undefined1 *)(param_1 + 0xa8827);
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(undefined1 *)(lVar24 + 0x3db) = *(undefined1 *)(param_1 + 0xa881d);
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar24 != 0) {
    *(longlong *)(lVar24 + 0x340) = param_1;
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if ((*(uint *)(param_1 + 0xa8790) & 0x800000) == 0) {
    if (lVar24 != 0) {
      *(uint *)(lVar24 + 0x3a8) = *(uint *)(lVar24 + 0x3a8) & 0xffffdfff;
    }
  }
  else if (lVar24 != 0) {
    *(uint *)(lVar24 + 0x3a8) = *(uint *)(lVar24 + 0x3a8) | 0x2000;
  }
  lVar24 = *(longlong *)(param_1 + 0xa8318);
  lVar26 = *(longlong *)(lVar24 + 0x10);
  *(undefined2 *)(lVar24 + 0x20) = 0;
  *(undefined1 *)(lVar24 + 0x23) = 0xff;
  if (lVar26 != 0) {
    *(undefined8 *)(lVar26 + 0x3b0) = 0;
    *(undefined1 *)(lVar26 + 0x3d7) = 0xff;
    *(undefined2 *)(lVar26 + 0x3c0) = 0xffff;
    *(undefined4 *)(lVar26 + 0x3dc) = 0xffff0000;
    *(undefined2 *)(lVar26 + 0x3e9) = 4;
    *(undefined8 *)(lVar26 + 0x3a0) = 0x3f800000;
    *(undefined8 *)(lVar26 + 0x394) = 0;
    *(undefined4 *)(lVar26 + 0x2a0) = 0x80;
    *(undefined4 *)(lVar26 + 0x3e0) = 0x6464ffff;
    *(undefined4 *)(lVar26 + 0x3ac) = 0;
    *(undefined1 *)(lVar26 + 0x3c8) = 0;
    *(undefined4 *)(lVar26 + 0x3c4) = 0;
  }
  plVar20 = *(longlong **)(param_1 + 0x697b8);
  uVar21 = *(undefined8 *)(param_1 + 0xa8318);
  plVar19 = plVar20;
  if (plVar20 != plVar20 + *(byte *)(param_1 + 0x697ec)) {
    do {
      lVar24 = *plVar19;
      iVar27 = 0;
      *(undefined8 *)(lVar24 + 0xd0) = uVar21;
      if (0 < *(int *)(lVar24 + 0x118)) {
        lVar26 = 0;
        do {
          lVar31 = *(longlong *)(lVar24 + 0x110);
          lVar13 = *(longlong *)(lVar31 + 8 + lVar26);
          *(undefined8 *)(lVar31 + 0x1c8 + lVar26) = uVar21;
          if (lVar13 != 0) {
            *(undefined8 *)(lVar13 + 0x88) = uVar21;
          }
          lVar31 = *(longlong *)(lVar31 + 0x10 + lVar26);
          if (lVar31 != 0) {
            *(undefined8 *)(lVar31 + 0x88) = uVar21;
          }
          iVar27 = iVar27 + 1;
          lVar26 = lVar26 + 0x520;
        } while (iVar27 < *(int *)(lVar24 + 0x118));
      }
      plVar20 = *(longlong **)(param_1 + 0x697b8);
      plVar19 = plVar19 + 1;
    } while (plVar19 != plVar20 + *(byte *)(param_1 + 0x697ec));
  }
  uVar10 = *(undefined1 *)(param_1 + 0xa881d);
  *(undefined8 *)(param_1 + 0x697e0) = *(undefined8 *)(param_1 + 0xa8308);
  if (plVar20 != plVar20 + *(byte *)(param_1 + 0x697ec)) {
    do {
      lVar24 = *plVar20;
      iVar27 = 0;
      *(undefined1 *)(lVar24 + 0x100) = uVar10;
      if (0 < *(int *)(lVar24 + 0x118)) {
        lVar26 = 0;
        do {
          iVar27 = iVar27 + 1;
          *(undefined1 *)(lVar26 + 0x24c + *(longlong *)(lVar24 + 0x110)) = uVar10;
          lVar26 = lVar26 + 0x520;
        } while (iVar27 < *(int *)(lVar24 + 0x118));
      }
      plVar20 = plVar20 + 1;
    } while (plVar20 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  FUN_1400a98c0(param_1 + 0x69748);
  if (*(int *)(*(longlong *)(param_1 + 0x67148) + 0x38) != 0) {
    FUN_14007f380();
  }
  FUN_14007fbe0(*(undefined8 *)(param_1 + 0x67130));
  FUN_140136040(param_1 + 0x697b8);
  FUN_1400c3680(param_1 + 0x697b8,
                CONCAT31((uint3)(*(uint *)(param_1 + 0xa8790) >> 0x1f),
                         (char)(*(uint *)(param_1 + 0xa8790) >> 0x17)) & 0xffffff01);
  plVar20 = *(longlong **)(param_1 + 0x697b8);
  if ((*(byte *)(**(longlong **)(param_1 + 0x67130) + 0x10) & 2) == 0) {
    if (plVar20 != plVar20 + *(byte *)(param_1 + 0x697ec)) {
      do {
        uVar25 = 0;
        lVar24 = *plVar20;
        uVar30 = uVar25;
        if (0 < *(int *)(lVar24 + 0x118)) {
          do {
            lVar26 = *(longlong *)(lVar24 + 0x110);
            plVar19 = *(longlong **)(uVar25 + 0x390 + lVar26);
            if (plVar19 != (longlong *)0x0) {
              (**(code **)(*plVar19 + 0x1d8))();
            }
            plVar19 = *(longlong **)(uVar25 + 0x398 + lVar26);
            if (plVar19 != (longlong *)0x0) {
              (**(code **)(*plVar19 + 0x1d8))();
            }
            uVar29 = (int)uVar30 + 1;
            uVar30 = (ulonglong)uVar29;
            uVar25 = uVar25 + 0x520;
          } while ((int)uVar29 < *(int *)(lVar24 + 0x118));
        }
        plVar20 = plVar20 + 1;
      } while (plVar20 !=
               (longlong *)
               (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
    }
  }
  else if (plVar20 != plVar20 + *(byte *)(param_1 + 0x697ec)) {
    do {
      uVar25 = 0;
      lVar24 = *plVar20;
      uVar30 = uVar25;
      if (0 < *(int *)(lVar24 + 0x118)) {
        do {
          lVar26 = *(longlong *)(lVar24 + 0x110);
          plVar19 = *(longlong **)(uVar25 + 0x390 + lVar26);
          if (plVar19 != (longlong *)0x0) {
            (**(code **)(*plVar19 + 0x1d0))();
          }
          plVar19 = *(longlong **)(uVar25 + 0x398 + lVar26);
          if (plVar19 != (longlong *)0x0) {
            (**(code **)(*plVar19 + 0x1d0))();
          }
          uVar29 = (int)uVar30 + 1;
          uVar30 = (ulonglong)uVar29;
          uVar25 = uVar25 + 0x520;
        } while ((int)uVar29 < *(int *)(lVar24 + 0x118));
      }
      plVar20 = plVar20 + 1;
    } while (plVar20 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  lVar24 = 0;
  uVar21 = FUN_140019ef0();
  FUN_140019f80(uVar21);
  *(undefined4 *)(param_1 + 0x6a818) = 0;
  *(undefined4 *)(param_1 + 0x6a820) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x6a824) = 0;
  *(undefined4 *)(param_1 + 0x6b508) = 0;
  *(undefined4 *)(param_1 + 0x6b510) = 0;
  *(undefined8 *)(param_1 + 0x6b514) = 0xffffffffffffffff;
  *(undefined2 *)(param_1 + 0x6b51c) = 0xffff;
  FUN_140140b50(param_1 + 0x6bc40);
  *(undefined1 *)(param_1 + 0x89ec0) = 0;
  FUN_140014960(*(undefined8 *)(param_1 + 0xa8298),*(undefined8 *)(param_1 + 0xa8240));
  FUN_140014960(param_1 + 0x69ab0,*(undefined8 *)(param_1 + 0xa8240));
  FUN_140014960(param_1 + 0x69c70);
  if (*(longlong *)(param_1 + 0xa82a8) != 0) {
    FUN_1401a5fc0();
    if (*(longlong *)(param_1 + 0xa82b0) != 0) {
      FUN_1401a8b40(*(longlong *)(param_1 + 0xa82b0),param_1 + 0x697b8,
                    *(undefined8 *)(param_1 + 0xa82a8));
    }
  }
  iVar27 = 0;
  DAT_14032c480 = 0;
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    lVar26 = 0;
    do {
      lVar31 = *(longlong *)(param_1 + 0xa8248);
      puVar1 = (uint *)(*(longlong *)
                         (*(longlong *)(*(longlong *)(param_1 + 0x697b8) + lVar26) + 0x110) + 0x1f0)
      ;
      *puVar1 = *puVar1 | 1;
      (**(code **)(**(longlong **)(lVar24 + 0x1fa8 + lVar31) + 8))();
      FUN_1400b95a0(lVar24 + 0x1868 + lVar31);
      lVar26 = lVar26 + 8;
      iVar27 = iVar27 + 1;
      lVar24 = lVar24 + 0x27a0;
    } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  FUN_140138120(param_1 + 0x697b8);
  if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437dad18) &&
     (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  FUN_1401c5740(&DAT_1437daee0);
  lVar24 = FUN_140189320();
  auVar14 = vpcmpeqd_avx(ZEXT116(*(byte *)(lVar24 + 0x28)),SUB6416(ZEXT464(0),0));
  auVar14 = vblendvps_avx(ZEXT416(DAT_1402d1f90),ZEXT816(0),auVar14);
  DAT_140328448 = auVar14._0_4_;
  if (*(longlong *)(param_1 + 0xa82a8) != 0) {
    lVar24 = FUN_140189320();
    bVar22 = *(byte *)(*(longlong *)(param_1 + 0xa82a8) + 0x52);
    if (*(char *)(lVar24 + 0x28) == '\0') {
      bVar22 = bVar22 & 0xfb;
    }
    else {
      bVar22 = bVar22 | 4;
    }
    *(byte *)(*(longlong *)(param_1 + 0xa82a8) + 0x52) = bVar22;
  }
  iVar27 = 0;
  DAT_140328440 = *(undefined8 *)(*(longlong *)(param_1 + 0x67130) + 0x1380);
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    do {
      FUN_140004e80(&local_218);
      local_78 = local_78 | 3;
      local_68 = 0x15000000;
      local_64 = 0x100;
      FUN_1401fbec0(&local_218);
      pfVar28 = *(float **)(param_1 + 0xa8240);
      uVar29 = (uint)*(byte *)(param_1 + 0xa87e4);
      lVar31 = (longlong)iVar27 * 0x27a0 + *(longlong *)(param_1 + 0xa8248);
      lVar26 = *(longlong *)
                (*(longlong *)(*(longlong *)(param_1 + 0x697b8) + (longlong)iVar27 * 8) + 0x110);
      FUN_140014960(&local_218,pfVar28);
      local_1ee = *(undefined2 *)((longlong)pfVar28 + 0x2a);
      local_1f8 = pfVar28[8];
      local_1fc = pfVar28[7];
      local_214 = *(undefined8 *)(pfVar28 + 1);
      uStack_20c = *(undefined8 *)(pfVar28 + 3);
      uVar2 = *(undefined4 *)(lVar26 + 0x264);
      uVar3 = *(undefined4 *)(lVar26 + 0x268);
      uVar4 = *(undefined4 *)(lVar26 + 0x26c);
      uVar5 = *(undefined4 *)(lVar26 + 0x270);
      uVar6 = *(undefined4 *)(lVar26 + 0x274);
      local_1f0 = (short)((int)*(short *)(pfVar28 + 10) / (int)uVar29);
      local_218 = *pfVar28 / (float)(int)uVar29;
      uVar7 = *(undefined4 *)(lVar26 + 600);
      local_1ec = pfVar28[0xb];
      local_1f2 = *(undefined2 *)((longlong)pfVar28 + 0x26);
      local_204 = *(undefined2 *)(pfVar28 + 5);
      local_202 = *(undefined2 *)((longlong)pfVar28 + 0x16);
      local_1f4 = ((ushort)iVar27 & 0xff) * local_1f0 + *(short *)(pfVar28 + 9);
      local_200 = *(undefined2 *)(pfVar28 + 6);
      local_1fe = *(undefined2 *)((longlong)pfVar28 + 0x1a);
      uVar8 = *(undefined4 *)(lVar26 + 0x260);
      uVar9 = *(undefined4 *)(lVar26 + 0x25c);
      *(undefined4 *)(lVar31 + 0x10e0) = uVar7;
      *(undefined4 *)(lVar31 + 0x10e4) = uVar9;
      *(undefined4 *)(lVar31 + 0x10e8) = uVar8;
      *(undefined4 *)(lVar31 + 0x10ec) = uVar2;
      *(undefined4 *)(lVar31 + 0x10f0) = uVar3;
      *(undefined4 *)(lVar31 + 0x10f4) = uVar4;
      *(undefined4 *)(lVar31 + 0x10f8) = uVar5;
      *(undefined4 *)(lVar31 + 0x10fc) = uVar6;
      *(undefined4 *)(lVar31 + 0x12ac) = 0x3f800000;
      *(undefined8 *)(lVar31 + 0x12a0) = 0;
      *(undefined4 *)(lVar31 + 0x12a8) = 0;
      *(undefined4 *)(lVar31 + 0x12b0) = uVar3;
      *(undefined4 *)(lVar31 + 0x12b4) = uVar4;
      *(undefined4 *)(lVar31 + 0x12b8) = uVar5;
      *(undefined4 *)(lVar31 + 0x12bc) = uVar6;
      *(undefined4 *)(lVar31 + 0x70) = uVar7;
      *(undefined4 *)(lVar31 + 0x74) = uVar9;
      *(undefined4 *)(lVar31 + 0x78) = uVar8;
      *(undefined4 *)(lVar31 + 0x7c) = uVar2;
      *(undefined4 *)(lVar31 + 0x80) = uVar3;
      *(undefined4 *)(lVar31 + 0x84) = uVar4;
      *(undefined4 *)(lVar31 + 0x88) = uVar5;
      *(undefined4 *)(lVar31 + 0x8c) = uVar6;
      lVar24 = lVar31 + 0x10b0;
      *(undefined4 *)(lVar31 + 0x17f8) = uVar7;
      *(undefined4 *)(lVar31 + 0x17fc) = uVar9;
      *(undefined4 *)(lVar31 + 0x1800) = uVar8;
      *(undefined4 *)(lVar31 + 0x1804) = uVar2;
      *(undefined4 *)(lVar31 + 0x1808) = uVar3;
      *(undefined4 *)(lVar31 + 0x180c) = uVar4;
      *(undefined4 *)(lVar31 + 0x1810) = uVar5;
      *(undefined4 *)(lVar31 + 0x1814) = uVar6;
      FUN_140014960(lVar24,&local_218);
      *(uint *)(lVar24 + 0x1a0) = *(uint *)(lVar24 + 0x1a0) | 3;
      FUN_1401fbec0();
      lVar24 = lVar31 + 0x1270;
      FUN_140014960(lVar24,&local_218);
      *(uint *)(lVar24 + 0x1a0) = *(uint *)(lVar24 + 0x1a0) | 3;
      FUN_1401fbec0();
      *(longlong *)(lVar31 + 0x1fc0) = param_1 + 0x240;
      *(longlong *)(lVar31 + 0x1fc8) = param_1 + 0x6a130;
      iVar18 = DAT_140316e48;
      if (DAT_14031cf18 != '\0') {
        iVar18 = DAT_14031ce00;
      }
      *(bool *)(lVar31 + 0x10a5) = iVar18 == 0;
      *(undefined8 *)(lVar31 + 0x1fd0) = *(undefined8 *)(param_1 + 0xa8298);
      *(undefined8 *)(lVar31 + 0x2050) = *(undefined8 *)(param_1 + 0xa82a0);
      uVar10 = *(undefined1 *)(lVar26 + 0x235);
      uVar11 = *(undefined1 *)(lVar26 + 0x234);
      *(undefined1 *)(lVar31 + 0x20a2) = uVar10;
      *(undefined1 *)(lVar31 + 0x20a1) = uVar11;
      *(undefined1 *)(lVar31 + 0x1eeb) = uVar10;
      *(undefined1 *)(lVar31 + 0x1eea) = uVar11;
      *(undefined1 *)(lVar31 + 0x1eca) = uVar10;
      *(undefined1 *)(lVar31 + 0x1ec9) = uVar11;
      *(undefined1 *)(lVar31 + 0x1e52) = uVar10;
      *(undefined1 *)(lVar31 + 0x1e51) = uVar11;
      *(undefined1 *)(lVar31 + 0x1e71) = uVar11;
      *(undefined1 *)(lVar31 + 0x1e72) = uVar10;
      *(undefined1 *)(lVar31 + 0x1e91) = uVar11;
      *(undefined1 *)(lVar31 + 0x1e92) = uVar10;
      *(undefined1 *)(lVar31 + 0x1eb1) = uVar11;
      *(undefined1 *)(lVar31 + 0x1eb2) = uVar10;
      *(char *)(lVar31 + 0x20b3) = (char)iVar27;
      if ((*(uint *)(param_1 + 0xa8790) & 0x100000) == 0) {
        bVar22 = *(byte *)(lVar31 + 0x1676) & 0xdf;
      }
      else {
        bVar22 = *(byte *)(lVar31 + 0x1676) | 0x20;
      }
      *(byte *)(lVar31 + 0x1676) = bVar22;
      FUN_1400ae310(lVar31 + 0x1868,0x1601);
      (**(code **)(**(longlong **)(lVar31 + 0x1888) + 0x40))();
      FUN_140102ab0(lVar31);
      lVar24 = FUN_140189320();
      if (*(char *)(lVar24 + 0x28) == '\0') {
        FUN_1400bab90(lVar31 + 0x1868,0);
        *(byte *)(lVar31 + 0x1da7) = *(byte *)(lVar31 + 0x1da7) & 0xfb;
      }
      else {
        FUN_1400bab90(lVar31 + 0x1868,1);
        *(byte *)(lVar31 + 0x1da7) = *(byte *)(lVar31 + 0x1da7) | 4;
      }
      if ((*(uint *)(param_1 + 0xa8790) & 0x8000000) == 0) {
        uVar17 = *(ushort *)(lVar31 + 0x1c20) | 0x80;
      }
      else {
        uVar17 = *(ushort *)(lVar31 + 0x1c20) & 0xff7f;
      }
      iVar27 = iVar27 + 1;
      *(ushort *)(lVar31 + 0x1c20) = uVar17;
    } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  lVar24 = *(longlong *)(param_1 + 0xa8318);
  if (lVar24 != 0) {
    lVar26 = *(longlong *)(param_1 + 0xa8248);
    lVar31 = *(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110);
    if (lVar31 != 0) {
      lVar13 = *(longlong *)(lVar24 + 0x10);
      uVar10 = *(undefined1 *)(lVar31 + 0x428);
      if (lVar13 != 0) {
        *(undefined1 *)(lVar13 + 0x3e2) = uVar10;
        *(undefined1 *)(lVar13 + 0x3e3) = uVar10;
        lVar24 = *(longlong *)(param_1 + 0xa8318);
      }
    }
    if (lVar26 != 0) {
      lVar24 = *(longlong *)(lVar24 + 0x10);
      uVar10 = *(undefined1 *)(lVar26 + 0x209a);
      uVar11 = *(undefined1 *)(lVar26 + 0x2099);
      if (lVar24 != 0) {
        *(undefined2 *)(lVar24 + 0x3c2) = *(undefined2 *)(lVar26 + 0x208e);
        *(undefined1 *)(lVar24 + 0x3e4) = uVar11;
        *(undefined1 *)(lVar24 + 0x3e5) = uVar10;
      }
    }
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  FUN_1401fbec0(*(longlong *)(param_1 + 0xa8248) + 0x10b0);
  lVar24 = lVar24 + 0xe0;
  FUN_140014960();
  *(uint *)(lVar24 + 0x1a0) = *(uint *)(lVar24 + 0x1a0) | 3;
  FUN_1401fbec0();
  lVar24 = *(longlong *)(param_1 + 0xa8298);
  *(undefined8 *)(lVar24 + 0x2a0) = 0;
  *(undefined4 *)(lVar24 + 0x2a8) = 0xffff0000;
  *(undefined2 *)(lVar24 + 0x2ac) = 0xffff;
  *(undefined4 *)(lVar24 + 0x26c) = 0xffff;
  *(undefined8 *)(lVar24 + 0x2b0) = 0;
  *(undefined1 *)(param_1 + 0xa8781) = 0;
  puVar1 = (uint *)(*(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110) + 0x1f0);
  *puVar1 = *puVar1 | 3;
  lVar24 = *(longlong *)(param_1 + 0x67120);
  *(undefined8 *)(lVar24 + 0x1bc48) = 0;
  *(undefined8 *)(lVar24 + 0x1bc50) = 0;
  *(undefined8 *)(lVar24 + 0x1bc58) = 0;
  *(undefined8 *)(lVar24 + 0x1bc60) = 0;
  *(undefined8 *)(lVar24 + 0x1bc68) = 0;
  *(undefined8 *)(lVar24 + 0x1bc70) = 0;
  *(undefined8 *)(lVar24 + 0x1bc78) = 0;
  *(undefined8 *)(lVar24 + 0x1bc80) = 0;
  *(int *)(lVar24 + 0x1bc8c) = *(int *)(lVar24 + 0x1bc8c) + 1;
  *(undefined4 *)(lVar24 + 0x1bc88) = 0;
  if (0xe < *(int *)(lVar24 + 0x1bc8c)) {
    *(undefined4 *)(lVar24 + 0x1bc8c) = 0;
  }
  if (*(char *)(param_1 + 0xa8822) == '\a') {
    FUN_14012c0a0(*(longlong *)(param_1 + 0xa8318),
                  *(char *)(*(longlong *)(param_1 + 0xa8318) + 0x20) + '\x01');
    *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10) + 0x3ea) = 2;
  }
  (**(code **)(**(longlong **)(param_1 + 0x67158) + 0x60))();
  DAT_14033bd60 = 0;
  DAT_140326f80 = 0;
  if (*(longlong *)(param_1 + 0xa8310) != 0) {
    FUN_140113820(*(longlong *)(param_1 + 0xa8310),param_1);
  }
  *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xbfffffff;
  *(undefined1 *)(param_1 + 0x697ef) = *(undefined1 *)(param_1 + 0xa87e4);
  *(undefined1 *)(param_1 + 0xa8822) = 1;
  return;
}

