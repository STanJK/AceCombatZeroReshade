/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c70e0; RVA 0xc70e0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1400c70e0(longlong param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint *puVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  int *piVar13;
  uint *puVar14;
  char *pcVar15;
  ulonglong uVar16;
  longlong lVar17;
  int *piVar18;
  int *piVar19;
  int iVar20;
  int *piVar21;
  longlong lVar22;
  int iVar23;
  int *piVar24;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined1 auStack_648 [32];
  longlong local_628;
  longlong local_620;
  uint *local_618;
  int *local_610;
  int *local_608;
  int *local_600;
  undefined8 local_5f8;
  int local_5e8;
  longlong local_5e0;
  uint *local_5d8;
  longlong local_5d0;
  longlong local_5c8;
  uint *local_5c0;
  longlong local_5b8;
  longlong local_5b0;
  int local_5a8;
  undefined8 *local_5a0;
  undefined **local_598 [3];
  undefined **local_580;
  undefined **local_468;
  undefined **local_430;
  undefined **local_390;
  undefined **local_388;
  undefined **local_290;
  undefined **local_288;
  undefined **local_190;
  undefined **local_188;
  ulonglong local_38;
  
  local_38 = DAT_140309040 ^ (ulonglong)auStack_648;
  cVar1 = *(char *)(param_1 + 0xa8824);
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xa8824) = 1;
  }
  else if (cVar1 == '\x01') {
    local_5e8 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      do {
        lVar22 = (longlong)local_5e8;
        lVar17 = 0;
        piVar13 = *(int **)(param_1 + 0xa88c0 + lVar22 * 8);
        lVar12 = lVar22 * 0x27a0 + *(longlong *)(param_1 + 0xa8248);
        iVar23 = *piVar13;
        local_5b0 = lVar22 * 0x70 + *(longlong *)(param_1 + 0x671c0);
        if (iVar23 < 2) {
LAB_1400c74ac:
          lVar22 = 0;
        }
        else {
          if (piVar13[2] != 0) {
            lVar17 = (longlong)piVar13 + (longlong)piVar13[2];
          }
          if (iVar23 < 0xd) goto LAB_1400c74ac;
          lVar22 = 0;
          if (piVar13[0xd] != 0) {
            lVar22 = (longlong)piVar13 + (longlong)piVar13[0xd];
          }
        }
        (*(code *)**(undefined8 **)(lVar12 + 0xda0))(lVar12 + 0xda0,lVar22);
        FUN_1401533a0(lVar12 + 0x110,lVar17);
        uVar3 = FUN_140153c20(lVar12 + 0x110);
        uVar6 = FUN_140200de0(DAT_14032c8f8,uVar3,0x10);
        uVar3 = (**(code **)(*(longlong *)(lVar12 + 0xda0) + 8))(lVar12 + 0xda0);
        uVar7 = FUN_140200de0(DAT_14032c8f8,uVar3,0x10);
        FUN_140154200(lVar12 + 0x110,uVar6);
        uVar6 = (**(code **)(*(longlong *)(lVar12 + 0xda0) + 0x10))(lVar12 + 0xda0,uVar7);
        if (iVar23 < 7) {
          *(undefined8 *)(lVar12 + 0xc10) = 0;
          puVar8 = (uint *)0x0;
          puVar14 = (uint *)0x0;
          piVar18 = (int *)0x0;
        }
        else {
          if (piVar13[7] == 0) {
            lVar17 = 0;
          }
          else {
            lVar17 = (longlong)piVar13[7] + (longlong)piVar13;
          }
          *(longlong *)(lVar12 + 0xc10) = lVar17;
          if (iVar23 < 8) {
            puVar8 = (uint *)0x0;
            puVar14 = (uint *)0x0;
            piVar18 = (int *)0x0;
          }
          else {
            if (piVar13[8] == 0) {
              puVar8 = (uint *)0x0;
            }
            else {
              puVar8 = (uint *)((longlong)piVar13[8] + (longlong)piVar13);
            }
            if (iVar23 < 9) {
              puVar14 = (uint *)0x0;
              piVar18 = (int *)0x0;
            }
            else {
              if (piVar13[9] == 0) {
                puVar14 = (uint *)0x0;
              }
              else {
                puVar14 = (uint *)((longlong)piVar13[9] + (longlong)piVar13);
              }
              if (iVar23 < 0xc) {
                piVar18 = (int *)0x0;
              }
              else {
                piVar18 = (int *)0x0;
                if (piVar13[0xc] != 0) {
                  piVar18 = (int *)((longlong)piVar13 + (longlong)piVar13[0xc]);
                }
              }
            }
          }
        }
        if (*puVar8 == 0) {
          lVar17 = 0;
        }
        else {
          lVar17 = (ulonglong)*puVar8 + (longlong)puVar8;
        }
        *(longlong *)(lVar12 + 0xfe0) = lVar17;
        if (*puVar14 == 0) {
          lVar17 = 0;
        }
        else {
          lVar17 = (ulonglong)*puVar14 + (longlong)puVar14;
        }
        *(longlong *)(lVar12 + 0xff8) = lVar17;
        iVar20 = *piVar18;
        if ((iVar20 < 1) ||
           (piVar21 = (int *)((longlong)piVar18 + (longlong)piVar18[1]), piVar18[1] == 0)) {
          piVar21 = (int *)0x0;
        }
        if (*piVar21 != 0) {
          uVar3 = FUN_1401029f0(puVar14,piVar21);
          puVar9 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,uVar3,0x10);
          *puVar9 = &PTR_FUN_1402ac750;
          *(undefined8 **)(lVar12 + 0xf90) = puVar9;
          FUN_140162780(puVar9,piVar21);
          FUN_140162a80(*(undefined8 *)(lVar12 + 0xf90),puVar9 + 9);
          uVar6 = FUN_140162840(*(undefined8 *)(lVar12 + 0xf90));
          uVar6 = FUN_1401029f0(uVar6,piVar21);
        }
        if ((iVar20 < 2) ||
           (piVar21 = (int *)((longlong)piVar18 + (longlong)piVar18[2]), piVar18[2] == 0)) {
          piVar21 = (int *)0x0;
        }
        if (*piVar21 != 0) {
          uVar3 = FUN_1401029f0(uVar6,piVar21);
          puVar9 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,uVar3,0x10);
          *puVar9 = &PTR_FUN_1402ac750;
          *(undefined8 **)(lVar12 + 0xfa8) = puVar9;
          FUN_140162780(puVar9,piVar21);
          FUN_140162a80(*(undefined8 *)(lVar12 + 0xfa8),puVar9 + 9);
          uVar6 = FUN_140162840(*(undefined8 *)(lVar12 + 0xfa8));
          uVar6 = FUN_1401029f0(uVar6,piVar21);
        }
        if ((iVar20 < 3) ||
           (piVar21 = (int *)((longlong)piVar18 + (longlong)piVar18[3]), piVar18[3] == 0)) {
          piVar21 = (int *)0x0;
        }
        if (*piVar21 != 0) {
          uVar3 = FUN_1401029f0(uVar6,piVar21);
          puVar9 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,uVar3,0x10);
          *puVar9 = &PTR_FUN_1402ac750;
          *(undefined8 **)(lVar12 + 0xfc0) = puVar9;
          FUN_140162780(puVar9,piVar21);
          FUN_140162a80(*(undefined8 *)(lVar12 + 0xfc0),puVar9 + 9);
          uVar6 = FUN_140162840(*(undefined8 *)(lVar12 + 0xfc0));
          FUN_1401029f0(uVar6,piVar21);
        }
        lVar17 = *(longlong *)
                  (param_1 + 0x89670 +
                  (ulonglong)
                  *(byte *)((ulonglong)*(byte *)(lVar12 + 0x279a) + 4 +
                           *(longlong *)(lVar12 + 0xff8)) * 8);
        if (lVar17 != 0) {
          *(undefined8 *)(lVar17 + 0x68 + (ulonglong)(byte)local_5e8 * 8) =
               **(undefined8 **)(lVar12 + 0xfd8);
        }
        *(uint *)(lVar12 + 0xc00) = (uint)*(byte *)(lVar12 + 0x279a);
        FUN_140158f80();
        puVar8 = (uint *)0x0;
        if ((2 < iVar23) && (piVar13[3] != 0)) {
          puVar8 = (uint *)((longlong)piVar13 + (longlong)piVar13[3]);
        }
        FUN_140189320();
        if (*puVar8 == 0) {
          puVar9 = (undefined8 *)0x0;
        }
        else {
          puVar9 = (undefined8 *)((ulonglong)*puVar8 + (longlong)puVar8);
        }
        puVar8 = (uint *)0x0;
        uVar6 = puVar9[1];
        uVar7 = puVar9[2];
        uVar2 = puVar9[3];
        *(undefined8 *)(lVar12 + 0x1c50) = *puVar9;
        *(undefined8 *)(lVar12 + 0x1c58) = uVar6;
        *(undefined8 *)(lVar12 + 0x1c60) = uVar7;
        *(undefined8 *)(lVar12 + 0x1c68) = uVar2;
        uVar6 = puVar9[5];
        uVar7 = puVar9[6];
        uVar2 = puVar9[7];
        *(undefined8 *)(lVar12 + 0x1c70) = puVar9[4];
        *(undefined8 *)(lVar12 + 0x1c78) = uVar6;
        *(undefined8 *)(lVar12 + 0x1c80) = uVar7;
        *(undefined8 *)(lVar12 + 0x1c88) = uVar2;
        uVar6 = puVar9[9];
        uVar7 = puVar9[10];
        uVar2 = puVar9[0xb];
        *(undefined8 *)(lVar12 + 0x1c90) = puVar9[8];
        *(undefined8 *)(lVar12 + 0x1c98) = uVar6;
        *(undefined8 *)(lVar12 + 0x1ca0) = uVar7;
        *(undefined8 *)(lVar12 + 0x1ca8) = uVar2;
        uVar6 = puVar9[0xd];
        uVar7 = puVar9[0xe];
        uVar2 = puVar9[0xf];
        *(undefined8 *)(lVar12 + 0x1cb0) = puVar9[0xc];
        *(undefined8 *)(lVar12 + 0x1cb8) = uVar6;
        *(undefined8 *)(lVar12 + 0x1cc0) = uVar7;
        *(undefined8 *)(lVar12 + 0x1cc8) = uVar2;
        uVar6 = puVar9[0x11];
        *(undefined8 *)(lVar12 + 0x1cd0) = puVar9[0x10];
        *(undefined8 *)(lVar12 + 0x1cd8) = uVar6;
        if ((9 < iVar23) && (piVar13[10] != 0)) {
          puVar8 = (uint *)((longlong)piVar13 + (longlong)piVar13[10]);
        }
        FUN_140189320();
        if (*puVar8 == 0) {
          lVar17 = 0;
        }
        else {
          lVar17 = (ulonglong)*puVar8 + (longlong)puVar8;
        }
        *(longlong *)(lVar12 + 0x1fb0) = lVar17;
        puVar8 = (uint *)0x0;
        *(longlong *)(lVar12 + 0x1ef0) = lVar17;
        *(longlong *)(lVar12 + 7000) = lVar17;
        if ((10 < iVar23) && (piVar13[0xb] != 0)) {
          puVar8 = (uint *)((longlong)piVar13 + (longlong)piVar13[0xb]);
        }
        FUN_140189320();
        if (*puVar8 == 0) {
          lVar17 = 0;
        }
        else {
          lVar17 = (ulonglong)*puVar8 + (longlong)puVar8;
        }
        *(longlong *)(lVar12 + 0x1fb8) = lVar17;
        puVar8 = (uint *)0x0;
        *(longlong *)(lVar12 + 0x1f08) = lVar17;
        *(longlong *)(lVar12 + 0x1f20) = lVar17;
        *(longlong *)(lVar12 + 0x1f38) = lVar17;
        *(longlong *)(lVar12 + 0x1f50) = lVar17;
        *(longlong *)(lVar12 + 0x1f68) = lVar17;
        *(longlong *)(lVar12 + 0x1f80) = lVar17;
        *(undefined4 *)(lVar12 + 0x1f98) = 0x3e4ccccd;
        *(undefined1 *)(lVar12 + 0x1fa0) = 8;
        uVar6 = DAT_14032c8f8;
        if ((5 < iVar23) && (piVar13[6] != 0)) {
          puVar8 = (uint *)((longlong)piVar13 + (longlong)piVar13[6]);
        }
        plVar10 = (longlong *)FUN_140200de0(DAT_14032c8f8,0x18,0x10);
        pcVar15 = (char *)0x0;
        *plVar10 = 0;
        plVar10[1] = 0;
        if (*puVar8 != 0) {
          pcVar15 = (char *)((longlong)puVar8 + (ulonglong)*puVar8);
        }
        *plVar10 = (longlong)pcVar15;
        uVar7 = FUN_140200de0(uVar6,*pcVar15 * 0x18,0x10);
        FUN_1401c6f40(plVar10,puVar8,uVar7);
        *(longlong **)(local_5b0 + 0x28) = plVar10;
        *(byte *)(local_5b0 + 0x40) = (byte)local_5e8 + '\x03';
        FUN_14010f560(lVar12);
        puVar8 = (uint *)0x0;
        if ((0 < iVar23) && (piVar13[1] != 0)) {
          puVar8 = (uint *)((longlong)piVar13 + (longlong)piVar13[1]);
        }
        if (*puVar8 == 0) {
          pcVar15 = (char *)0x0;
        }
        else {
          pcVar15 = (char *)((ulonglong)*puVar8 + (longlong)puVar8);
        }
        cVar1 = *pcVar15;
        if (cVar1 == '\0') {
          iVar20 = 0x20;
        }
        else if (cVar1 == '\x01') {
          iVar20 = 0x18;
        }
        else {
          iVar20 = 0;
          if (cVar1 == '\x02') {
            iVar20 = 0x18;
          }
        }
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)FUN_140200de0(uVar6,iVar20 + 0xfU & 0xfffffff0,0x10);
        pcVar15 = (char *)0x0;
        if (*puVar8 != 0) {
          pcVar15 = (char *)((longlong)puVar8 + (ulonglong)*puVar8);
        }
        piVar18 = (int *)0x0;
        if (puVar8[1] != 0) {
          piVar18 = (int *)((longlong)puVar8 + (ulonglong)puVar8[1]);
        }
        if ((*piVar18 < 1) ||
           ((puVar8 = (uint *)((ulonglong)(uint)piVar18[1] + (longlong)piVar18), *puVar8 == 0 &&
            (puVar8[1] == 0)))) {
          puVar8 = (uint *)0x0;
        }
        cVar1 = *pcVar15;
        if (cVar1 == '\0') {
          *plVar11 = 0;
          plVar11[1] = 0;
          plVar11[2] = 0;
          plVar11[3] = 0;
          FUN_140149270(plVar11,puVar8);
          plVar10 = plVar11;
        }
        else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
          *plVar11 = 0;
          if (*puVar8 == 0) {
            lVar17 = 0;
          }
          else {
            lVar17 = (ulonglong)*puVar8 + (longlong)puVar8;
          }
          *plVar11 = lVar17;
        }
        if (*pcVar15 == '\0') {
          FUN_140128fe0(lVar12 + 0x1430,plVar10);
        }
        if (iVar23 < 0x11) {
          lVar17 = 0;
        }
        else if (piVar13[0x11] == 0) {
          lVar17 = 0;
        }
        else {
          lVar17 = (longlong)piVar13[0x11] + (longlong)piVar13;
        }
        local_5e8 = local_5e8 + 1;
        *(longlong *)(lVar12 + 0x1fd8) = lVar17;
      } while (local_5e8 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
    }
    local_5e8 = 0;
    if (0 < *(int *)(param_1 + 0xa82f0)) {
      local_5a0 = (undefined8 *)(param_1 + 0xa88d0);
      local_5b0 = 0;
      do {
        lVar17 = local_5b0;
        piVar13 = (int *)*local_5a0;
        iVar23 = *piVar13;
        local_5a8 = iVar23;
        if (iVar23 < 1) {
          local_5b8 = 0;
          local_5c0 = (uint *)0x0;
          local_5c8 = 0;
          FUN_140189320();
LAB_1400c7b6b:
          uVar6 = FUN_140189320();
          local_5e0 = 0;
          if (2 < iVar23) goto LAB_1400c7bab;
          local_5d0 = 0;
          piVar18 = (int *)0x0;
          local_5e0 = 0;
          local_5d8 = (uint *)0x0;
        }
        else {
          if (piVar13[1] == 0) {
            local_5b8 = 0;
          }
          else {
            local_5b8 = (longlong)piVar13[1] + (longlong)piVar13;
          }
          if (iVar23 < 2) {
            local_5c0 = (uint *)0x0;
            local_5c8 = 0;
            FUN_140189320();
            goto LAB_1400c7b6b;
          }
          if (piVar13[2] == 0) {
            local_5c0 = (uint *)0x0;
          }
          else {
            local_5c0 = (uint *)((longlong)piVar13 + (longlong)piVar13[2]);
          }
          if (iVar23 < 5) {
            local_5c8 = 0;
            FUN_140189320();
            goto LAB_1400c7b6b;
          }
          if (piVar13[5] == 0) {
            local_5c8 = 0;
          }
          else {
            local_5c8 = (longlong)piVar13 + (longlong)piVar13[5];
          }
          FUN_140189320();
          if (iVar23 < 6) goto LAB_1400c7b6b;
          if (piVar13[6] == 0) {
            local_5e0 = 0;
          }
          else {
            local_5e0 = (longlong)piVar13 + (longlong)piVar13[6];
          }
          uVar6 = FUN_140189320();
LAB_1400c7bab:
          if (piVar13[3] == 0) {
            local_5d0 = 0;
          }
          else {
            local_5d0 = (longlong)piVar13 + (longlong)piVar13[3];
          }
          if (iVar23 < 4) {
            local_5d8 = (uint *)0x0;
            piVar18 = (int *)0x0;
          }
          else {
            if (piVar13[4] == 0) {
              local_5d8 = (uint *)0x0;
            }
            else {
              local_5d8 = (uint *)((longlong)piVar13 + (longlong)piVar13[4]);
            }
            if (iVar23 < 7) {
              piVar18 = (int *)0x0;
            }
            else if (piVar13[7] == 0) {
              piVar18 = (int *)0x0;
            }
            else {
              piVar18 = (int *)((longlong)piVar13[7] + (longlong)piVar13);
            }
          }
        }
        *(int **)(param_1 + 0xa8300) = piVar18;
        iVar23 = *piVar18;
        if ((iVar23 < 1) ||
           (piVar21 = (int *)((longlong)piVar18 + (longlong)piVar18[1]), piVar18[1] == 0)) {
          piVar21 = (int *)0x0;
        }
        if (*piVar21 == 0) {
          piVar21 = (int *)0x0;
        }
        if ((iVar23 < 2) ||
           (piVar24 = (int *)((longlong)piVar18 + (longlong)piVar18[2]), piVar18[2] == 0)) {
          piVar24 = (int *)0x0;
        }
        if (*piVar24 == 0) {
          piVar24 = (int *)0x0;
        }
        if ((iVar23 < 3) ||
           (piVar19 = (int *)((longlong)piVar18 + (longlong)piVar18[3]), piVar18[3] == 0)) {
          piVar19 = (int *)0x0;
        }
        iVar23 = 0;
        if (*piVar19 == 0) {
          piVar19 = (int *)0x0;
        }
        lVar17 = lVar17 + *(longlong *)(param_1 + 0xa82f8);
        if (local_5b8 != 0) {
          lVar22 = local_5b8;
          FUN_1400aba40(local_598);
          FUN_14014a8c0(local_598,lVar22);
          iVar23 = FUN_14014a9d0(local_598);
          local_188 = &PTR_FUN_1402adcf0;
          local_288 = &PTR_FUN_1402adcf0;
          iVar23 = iVar23 + 0x560;
          local_388 = &PTR_FUN_1402adcf0;
          local_598[0] = &PTR_FUN_1402ab4c0;
          local_190 = &PTR_FUN_1402ade48;
          local_290 = &PTR_FUN_1402ade48;
          local_390 = &PTR_FUN_1402ade48;
          local_580 = &PTR_FUN_1402ab6b0;
          local_430 = &PTR_FUN_1402ab8a0;
          local_468 = &PTR_FUN_1402ab8b0;
          uVar6 = extraout_XMM0_Qa;
        }
        if (local_5c0 != (uint *)0x0) {
          if (*local_5c0 == 0) {
            pcVar15 = (char *)0x0;
          }
          else {
            pcVar15 = (char *)((longlong)local_5c0 + (ulonglong)*local_5c0);
          }
          cVar1 = *pcVar15;
          if (cVar1 == '\0') {
            iVar20 = 0x20;
          }
          else if (cVar1 == '\x01') {
            iVar20 = 0x18;
          }
          else {
            iVar20 = 0;
            if (cVar1 == '\x02') {
              iVar20 = 0x18;
            }
          }
          iVar23 = iVar23 + ((iVar20 + 0xfU >> 4) + 0x66) * 0x10;
        }
        iVar20 = iVar23 + 0x18;
        if (local_5c8 == 0) {
          iVar20 = iVar23;
        }
        iVar23 = iVar20 + 0x18;
        if (local_5e0 == 0) {
          iVar23 = iVar20;
        }
        iVar20 = iVar23 + 0x18;
        if (local_5d0 == 0) {
          iVar20 = iVar23;
        }
        puVar8 = local_5d8;
        if (local_5d8 != (uint *)0x0) {
          iVar23 = iVar20 + 0x18;
          if (*local_5d8 == 0) {
            puVar8 = (uint *)0x0;
          }
          else {
            puVar8 = (uint *)((longlong)local_5d8 + (ulonglong)*local_5d8);
          }
          if ((char)puVar8[1] == '\b') {
            iVar23 = iVar20 + 0x28;
          }
          iVar4 = iVar23 + 0x10;
          if (*(char *)((longlong)puVar8 + 5) != '\b') {
            iVar4 = iVar23;
          }
          iVar20 = iVar4 + 0x10;
          if (*(char *)((longlong)puVar8 + 6) != '\b') {
            iVar20 = iVar4;
          }
        }
        iVar20 = iVar20 + 0x48;
        if (piVar21 != (int *)0x0) {
          iVar23 = FUN_1401029f0(puVar8,piVar21);
          iVar20 = iVar20 + iVar23;
          uVar6 = extraout_XMM0_Qa_00;
        }
        if (piVar24 != (int *)0x0) {
          iVar23 = FUN_1401029f0(uVar6,piVar24);
          iVar20 = iVar20 + iVar23;
          uVar6 = extraout_XMM0_Qa_01;
        }
        if (piVar19 != (int *)0x0) {
          iVar23 = FUN_1401029f0(uVar6,piVar19);
          iVar20 = iVar20 + iVar23;
        }
        local_5f8 = FUN_140200de0(DAT_14032c8f8,iVar20,0x10);
        local_618 = local_5d8;
        local_620 = local_5d0;
        local_628 = local_5e0;
        local_610 = piVar21;
        local_608 = piVar24;
        local_600 = piVar19;
        FUN_1400abff0(lVar17,local_5b8,local_5c0,local_5c8);
        lVar22 = *(longlong *)(lVar17 + 0x50 + (ulonglong)*(byte *)(lVar17 + 0x85) * 8);
        *(longlong *)(lVar17 + 0x68) = lVar22;
        if (lVar22 == 0) {
          uVar6 = 0;
          uVar16 = 0;
        }
        else {
          uVar16 = (ulonglong)*(byte *)(lVar22 + 0xd);
          uVar6 = **(undefined8 **)(lVar17 + 0x50 + (ulonglong)*(byte *)(lVar17 + 0x85) * 8);
        }
        lVar22 = *(longlong *)(param_1 + 0x89670 + uVar16 * 8);
        if (lVar22 != 0) {
          *(undefined8 *)(lVar22 + 0x70) = uVar6;
        }
        *(uint *)(*(longlong *)(lVar17 + 0x10) + 0x55c) = (uint)*(byte *)(lVar17 + 0x85);
        FUN_14014b4c0();
        *(undefined1 *)(lVar17 + 0x88) = *(undefined1 *)(lVar17 + 0x84);
        if (local_5a8 < 8) {
          lVar22 = 0;
        }
        else if (piVar13[8] == 0) {
          lVar22 = 0;
        }
        else {
          lVar22 = (longlong)piVar13[8] + (longlong)piVar13;
        }
        *(longlong *)(lVar17 + 0x40) = lVar22;
        local_5a0 = local_5a0 + 1;
        local_5e8 = local_5e8 + 1;
        local_5b0 = local_5b0 + 0x108;
      } while (local_5e8 < *(int *)(param_1 + 0xa82f0));
    }
    *(char *)(param_1 + 0xa8824) = *(char *)(param_1 + 0xa8824) + '\x01';
  }
  else {
    if (cVar1 == '\x02') {
      iVar23 = 0;
      if (*(char *)(param_1 + 0xa87e4) != '\0') {
        lVar17 = 0;
        do {
          piVar13 = *(int **)(param_1 + 0xa88c0 + lVar17);
          iVar20 = *piVar13;
          if (iVar20 < 5) {
            *(undefined8 *)(lVar17 + *(longlong *)(param_1 + 0x67188)) = 0;
            if (3 < iVar20) goto LAB_1400c73eb;
            lVar22 = 0;
          }
          else {
            if (piVar13[5] == 0) {
              *(undefined8 *)(lVar17 + *(longlong *)(param_1 + 0x67188)) = 0;
            }
            else {
              *(longlong *)(lVar17 + *(longlong *)(param_1 + 0x67188)) =
                   (longlong)piVar13 + (longlong)piVar13[5];
            }
LAB_1400c73eb:
            lVar22 = 0;
            if (piVar13[4] != 0) {
              lVar22 = (longlong)piVar13 + (longlong)piVar13[4];
            }
          }
          iVar23 = iVar23 + 1;
          *(longlong *)(lVar17 + *(longlong *)(param_1 + 0x67180)) = lVar22;
          lVar17 = lVar17 + 8;
          if ((int)(uint)*(byte *)(param_1 + 0xa87e4) <= iVar23) {
            *(char *)(param_1 + 0xa8824) = *(char *)(param_1 + 0xa8824) + '\x01';
            return 0;
          }
        } while( true );
      }
    }
    else {
      if (cVar1 != '\x03') {
        if (cVar1 == '\x04') {
          *(undefined1 *)(param_1 + 0xa8824) = 0;
          return 1;
        }
        return 0;
      }
      iVar23 = 0;
      if (*(char *)(param_1 + 0xa87e4) != '\0') {
        lVar17 = 0;
        puVar9 = (undefined8 *)(param_1 + 0xa88c0);
        do {
          piVar13 = (int *)*puVar9;
          lVar22 = *(longlong *)(param_1 + 0xa8248);
          iVar20 = *piVar13;
          if (iVar20 < 0xe) {
            lVar12 = 0;
LAB_1400c7188:
            *(longlong *)(lVar22 + 0x1fe8 + lVar17) = lVar12;
            piVar13 = (int *)0x0;
            *(undefined8 *)(lVar22 + 0x1fe0 + lVar17) = 0;
          }
          else {
            if (piVar13[0xe] == 0) {
              lVar12 = 0;
            }
            else {
              lVar12 = (longlong)piVar13[0xe] + (longlong)piVar13;
            }
            if (iVar20 < 0xf) goto LAB_1400c7188;
            if (piVar13[0xf] == 0) {
              lVar5 = 0;
            }
            else {
              lVar5 = (longlong)piVar13[0xf] + (longlong)piVar13;
            }
            *(longlong *)(lVar22 + 0x1fe0 + lVar17) = lVar5;
            *(longlong *)(lVar22 + 0x1fe8 + lVar17) = lVar12;
            if (iVar20 < 0x10) {
              piVar13 = (int *)0x0;
            }
            else if (piVar13[0x10] == 0) {
              piVar13 = (int *)0x0;
            }
            else {
              piVar13 = (int *)((longlong)piVar13[0x10] + (longlong)piVar13);
            }
          }
          iVar20 = *piVar13;
          lVar22 = *(longlong *)(param_1 + 0xa8248);
          if (iVar20 < 1) {
            lVar12 = 0;
LAB_1400c7203:
            *(longlong *)(lVar22 + 0x1ff8 + lVar17) = lVar12;
            lVar12 = 0;
            *(undefined8 *)(lVar22 + 0x1ff0 + lVar17) = 0;
            lVar22 = lVar17 + *(longlong *)(param_1 + 0xa8248);
LAB_1400c726f:
            *(longlong *)(lVar22 + 0x2018) = lVar12;
            lVar12 = 0;
            *(undefined8 *)(lVar22 + 0x2000) = 0;
            lVar22 = lVar17 + *(longlong *)(param_1 + 0xa8248);
LAB_1400c72d7:
            *(longlong *)(lVar22 + 0x2020) = lVar12;
            lVar5 = 0;
            *(undefined8 *)(lVar22 + 0x2008) = 0;
            lVar12 = 0;
            lVar22 = lVar17 + *(longlong *)(param_1 + 0xa8248);
          }
          else {
            if (piVar13[1] == 0) {
              lVar12 = 0;
            }
            else {
              lVar12 = (longlong)piVar13[1] + (longlong)piVar13;
            }
            if (iVar20 < 2) goto LAB_1400c7203;
            if (piVar13[2] == 0) {
              lVar5 = 0;
            }
            else {
              lVar5 = (longlong)piVar13[2] + (longlong)piVar13;
            }
            *(longlong *)(lVar22 + 0x1ff0 + lVar17) = lVar5;
            *(longlong *)(lVar22 + 0x1ff8 + lVar17) = lVar12;
            lVar22 = *(longlong *)(param_1 + 0xa8248) + lVar17;
            if (iVar20 < 3) {
              lVar12 = 0;
              goto LAB_1400c726f;
            }
            if (piVar13[3] == 0) {
              lVar12 = 0;
            }
            else {
              lVar12 = (longlong)piVar13[3] + (longlong)piVar13;
            }
            if (iVar20 < 4) goto LAB_1400c726f;
            if (piVar13[4] == 0) {
              lVar5 = 0;
            }
            else {
              lVar5 = (longlong)piVar13[4] + (longlong)piVar13;
            }
            *(longlong *)(lVar22 + 0x2000) = lVar5;
            *(longlong *)(lVar22 + 0x2018) = lVar12;
            lVar22 = *(longlong *)(param_1 + 0xa8248) + lVar17;
            if (iVar20 < 5) {
              lVar12 = 0;
              goto LAB_1400c72d7;
            }
            if (piVar13[5] == 0) {
              lVar12 = 0;
            }
            else {
              lVar12 = (longlong)piVar13[5] + (longlong)piVar13;
            }
            if (iVar20 < 6) goto LAB_1400c72d7;
            if (piVar13[6] == 0) {
              lVar5 = 0;
            }
            else {
              lVar5 = (longlong)piVar13[6] + (longlong)piVar13;
            }
            *(longlong *)(lVar22 + 0x2008) = lVar5;
            *(longlong *)(lVar22 + 0x2020) = lVar12;
            lVar22 = *(longlong *)(param_1 + 0xa8248) + lVar17;
            if (iVar20 < 7) {
              lVar12 = 0;
              lVar5 = 0;
            }
            else {
              lVar12 = 0;
              if (piVar13[7] != 0) {
                lVar12 = (longlong)piVar13 + (longlong)piVar13[7];
              }
              if (iVar20 < 8) {
                lVar5 = 0;
              }
              else if (piVar13[8] == 0) {
                lVar5 = 0;
              }
              else {
                lVar5 = (longlong)piVar13[8] + (longlong)piVar13;
              }
            }
          }
          *(longlong *)(lVar22 + 0x2010) = lVar5;
          iVar23 = iVar23 + 1;
          *(longlong *)(lVar22 + 0x2028) = lVar12;
          puVar9 = puVar9 + 1;
          lVar17 = lVar17 + 0x27a0;
        } while (iVar23 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      }
    }
    *(char *)(param_1 + 0xa8824) = *(char *)(param_1 + 0xa8824) + '\x01';
  }
  return 0;
}

