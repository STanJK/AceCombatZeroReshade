/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14021d4c0; RVA 0x21d4c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14021d4c0(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  int *piVar7;
  char cVar8;
  int iVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong *puVar13;
  ulonglong *puVar14;
  longlong lVar15;
  undefined8 *puVar16;
  longlong lVar17;
  uint uVar18;
  int *piVar19;
  ulonglong *puVar20;
  bool bVar21;
  undefined8 uVar22;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  undefined1 auStack_708 [32];
  int *local_6e8;
  uint local_6d8;
  uint local_6d4;
  undefined8 local_6d0;
  undefined8 local_6c8;
  undefined8 uStack_6c0;
  undefined8 uStack_6b8;
  undefined8 uStack_6b0;
  uint local_6a8;
  undefined8 *local_6a4;
  undefined4 local_69c;
  undefined8 local_698;
  undefined4 uStack_690;
  undefined4 local_688;
  undefined1 local_684 [524];
  short local_478 [524];
  byte local_60;
  ulonglong local_38;
  
  local_38 = DAT_140309040 ^ (ulonglong)auStack_708;
  puVar10 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_14031e578);
  uVar22 = (**(code **)(*(longlong *)*puVar10 + 0x18))((longlong *)*puVar10,1);
  if (DAT_14032c935 != '\0') {
    iVar9 = tm_api_update(0,&local_6d4);
    uVar22 = extraout_XMM0_Qa;
    if ((iVar9 == 0) && ((local_6d4 & 3) != 0)) {
      tm_api_get_device_count(&local_6d8);
      uVar22 = FUN_1402777e0(local_684,0,0x644);
      puVar20 = DAT_14033b188;
      local_688 = 0x648;
      if (((local_6d4 & 2) != 0) && (DAT_14033b180 != DAT_14033b188)) {
        puVar14 = DAT_14033b180 + 10;
        do {
          if ((int)puVar14[9] != 0) {
            uVar18 = 0;
            if (local_6d8 != 0) {
              do {
                iVar9 = tm_api_get_device_info(uVar18,&local_688);
                if ((iVar9 == 0) && ((local_60 & 0xf0) != 0)) {
                  uVar11 = 0xffffffffffffffff;
                  do {
                    uVar11 = uVar11 + 1;
                  } while (local_478[uVar11] != 0);
                  puVar13 = puVar14;
                  if (7 < puVar14[3]) {
                    puVar13 = (ulonglong *)*puVar14;
                  }
                  uVar22 = extraout_XMM0_Qa_00;
                  if (puVar14[2] == uVar11) {
                    if (puVar14[2] == 0) {
                      bVar21 = false;
                    }
                    else {
                      iVar9 = FUN_140220fc0(puVar13,local_478);
                      bVar21 = iVar9 != 0;
                      uVar22 = extraout_XMM0_Qa_01;
                    }
                  }
                  else {
                    bVar21 = true;
                  }
                  if (!bVar21) goto LAB_14021d61a;
                }
                uVar18 = uVar18 + 1;
              } while (uVar18 < local_6d8);
            }
            uVar22 = tm_api_close_device((int)puVar14[9]);
            *(undefined4 *)(puVar14 + 9) = 0;
          }
LAB_14021d61a:
          puVar13 = puVar14 + 10;
          puVar14 = puVar14 + 0x14;
        } while (puVar13 != puVar20);
      }
      puVar20 = DAT_14033b188;
      if (((local_6d4 & 1) != 0) && (DAT_14033b180 != DAT_14033b188)) {
        puVar14 = DAT_14033b180 + 0xd;
        do {
          if (((((int)puVar14[-0xd] == 0) && (*(char *)((longlong)puVar14 + 0x34) != '\0')) &&
              ((int)puVar14[6] == 0)) && (uVar18 = 0, local_6d8 != 0)) {
            do {
              iVar9 = tm_api_get_device_info(uVar18,&local_688);
              uVar22 = extraout_XMM0_Qa_02;
              if ((iVar9 == 0) && ((local_60 & 0xf0) != 0)) {
                uVar11 = 0xffffffffffffffff;
                do {
                  uVar11 = uVar11 + 1;
                } while (local_478[uVar11] != 0);
                puVar13 = puVar14 + -3;
                if (7 < *puVar14) {
                  puVar13 = (ulonglong *)*puVar13;
                }
                if (puVar14[-1] == uVar11) {
                  if (puVar14[-1] == 0) {
                    bVar21 = false;
                  }
                  else {
                    iVar9 = FUN_140220fc0(puVar13,local_478);
                    bVar21 = iVar9 != 0;
                    uVar22 = extraout_XMM0_Qa_03;
                  }
                }
                else {
                  bVar21 = true;
                }
                if (!bVar21) {
                  uVar22 = tm_api_open_device(uVar18,puVar14 + 6);
                  break;
                }
              }
              uVar18 = uVar18 + 1;
            } while (uVar18 < local_6d8);
          }
          puVar13 = puVar14 + 7;
          puVar14 = puVar14 + 0x14;
        } while (puVar13 != puVar20);
      }
    }
  }
  lVar15 = CONCAT44(local_698._4_4_,(undefined4)local_698);
  lVar12 = 0;
  lVar17 = param_1;
  do {
    *(undefined4 *)(lVar12 + 4 + param_1) = 1;
    *(undefined2 *)(lVar12 + 0x28 + param_1) = 0;
    *(undefined8 *)(lVar12 + 0xc + param_1) = 0;
    *(undefined8 *)(lVar12 + 0x14 + param_1) = 0;
    *(undefined8 *)(lVar12 + 0x1c + param_1) = 0;
    *(undefined4 *)(lVar12 + 0x24 + param_1) = 0;
    lVar12 = lVar12 + 0x30;
    *(undefined4 *)(lVar17 + 8) = 0;
    piVar7 = DAT_14033b940;
    piVar19 = DAT_14033b938;
    lVar17 = lVar17 + 0x30;
  } while (lVar12 < 0x60);
  if ((DAT_14032c93d != '\0') || (DAT_14032c93b != '\0')) {
    uVar18 = 0;
    DAT_1437d9af8 = 10;
    if (((longlong)DAT_14033b940 - (longlong)DAT_14033b938 >> 4) * -0x3333333333333333 == 0) {
      DAT_1437d9af8 = 10;
      return;
    }
    uVar11 = 0;
    do {
      piVar19 = DAT_14033b938 + uVar11 * 0x14;
      cVar8 = FUN_14021cca0(piVar19);
      if ((cVar8 != '\0') && ((int)DAT_14033b180[(longlong)*piVar19 * 0x14] == 0)) {
        if ((int)DAT_14033b180[(longlong)*piVar19 * 0x14 + 0x13] != 0) {
          local_6a4 = &local_698;
          local_698._4_4_ = 0;
          uStack_690 = 0;
          local_6c8 = 0;
          uStack_6c0 = 0;
          uStack_6b8 = 0;
          uStack_6b0 = 0;
          local_698._0_4_ = 0xc;
          local_6a8 = 0;
          local_6d0 = 0x1000000038;
          local_69c = 0xc;
          tm_api_set_properties
                    ((int)DAT_14033b180[(longlong)*piVar19 * 0x14 + 0x13],0x3003000,&local_6d0);
        }
        puVar10 = *(undefined8 **)(piVar19 + 10);
        for (puVar16 = *(undefined8 **)(piVar19 + 8); puVar16 != puVar10; puVar16 = puVar16 + 1) {
          (**(code **)(*(longlong *)*puVar16 + 0x40))();
        }
        puVar10 = *(undefined8 **)(piVar19 + 0x10);
        for (puVar16 = *(undefined8 **)(piVar19 + 0xe); puVar16 != puVar10; puVar16 = puVar16 + 1) {
          (**(code **)(*(longlong *)*puVar16 + 0x40))();
        }
        (**(code **)(**(longlong **)(piVar19 + 4) + 0x40))();
      }
      if (DAT_14033b938[uVar11 * 0x14 + 1] < 0x1e) {
        DAT_14033b938[uVar11 * 0x14 + 1] = DAT_14033b938[uVar11 * 0x14 + 1] + 1;
        *(undefined4 *)(param_1 + 4 + uVar11 * 0x30) = 0;
      }
      uVar18 = uVar18 + 1;
      uVar11 = (ulonglong)uVar18;
    } while (uVar11 < (ulonglong)
                      (((longlong)DAT_14033b940 - (longlong)DAT_14033b938 >> 4) *
                      -0x3333333333333333));
    return;
  }
  if (DAT_1437d9af8 != 0) {
    DAT_1437d9af8 = DAT_1437d9af8 + -1;
    return;
  }
  if (DAT_14032c930 != '\0') {
    if (((longlong)DAT_14033b940 - (longlong)DAT_14033b938 >> 4) * -0x3333333333333333 !=
        ((longlong)DAT_14033b188 - (longlong)DAT_14033b180 >> 5) * -0x3333333333333333) {
      if (DAT_14033b938 != DAT_14033b940) {
        do {
          uVar22 = FUN_14021c9c0(piVar19);
          piVar19 = piVar19 + 0x14;
        } while (piVar19 != piVar7);
        DAT_14033b940 = DAT_14033b938;
      }
      FUN_14021ee20(uVar22,((longlong)DAT_14033b188 - (longlong)DAT_14033b180 >> 5) *
                           -0x3333333333333333);
      lVar15 = CONCAT44(local_698._4_4_,(undefined4)local_698);
      local_6d8 = 0;
      piVar19 = DAT_14033b938;
      if (((longlong)DAT_14033b188 - (longlong)DAT_14033b180 >> 5) * -0x3333333333333333 != 0) {
        lVar15 = 0;
        lVar17 = 0;
        puVar20 = DAT_14033b180;
        puVar14 = DAT_14033b188;
        do {
          uVar18 = local_6d8;
          local_698 = lVar15;
          local_6d4 = FUN_14021ea80(*(undefined8 *)(lVar15 + 0x28 + (longlong)puVar20));
          plVar6 = DAT_14033b198;
          if (-1 < (int)local_6d4) {
            if ((ulonglong)(longlong)(int)local_6d4 <
                (ulonglong)(((longlong)puVar14 - (longlong)puVar20 >> 5) * -0x3333333333333333)) {
              puVar20 = puVar20 + (longlong)(int)local_6d4 * 0x14;
              iVar9 = (int)*puVar20;
              if (iVar9 == 0) {
                cVar8 = FUN_140219e60(puVar20,lVar17 + 0x10 + (longlong)piVar19,
                                      lVar17 + 0x20 + (longlong)piVar19);
                if (cVar8 != '\0') goto LAB_14021da29;
              }
              else if (iVar9 == 3) {
                plVar1 = (longlong *)(lVar17 + 0x10 + (longlong)piVar19);
                plVar4 = (longlong *)*plVar1;
                plVar2 = (longlong *)(lVar17 + 0x18 + (longlong)piVar19);
                pcVar5 = *(code **)(*DAT_14033b198 + 0x18);
                if (plVar4 != (longlong *)0x0) {
                  *plVar1 = 0;
                  (**(code **)(*plVar4 + 0x10))();
                }
                iVar9 = (*pcVar5)(plVar6,&DAT_14027bd90,plVar1,0);
                lVar15 = local_698;
                if (-1 < iVar9) {
                  iVar9 = (**(code **)(*(longlong *)*plVar1 + 0x58))
                                    ((longlong *)*plVar1,&DAT_14027bdf0);
                  lVar15 = local_698;
                  if (-1 < iVar9) {
                    iVar9 = (**(code **)(*(longlong *)*plVar1 + 0x68))
                                      ((longlong *)*plVar1,DAT_1403589c8,6);
                    lVar15 = local_698;
                    if (-1 < iVar9) {
                      (**(code **)(*(longlong *)*plVar1 + 0x38))();
                      plVar1 = DAT_14033b198;
                      plVar6 = (longlong *)*plVar2;
                      pcVar5 = *(code **)(*DAT_14033b198 + 0x18);
                      if (plVar6 != (longlong *)0x0) {
                        *plVar2 = 0;
                        (**(code **)(*plVar6 + 0x10))();
                      }
                      iVar9 = (*pcVar5)(plVar1,&DAT_14027bd80,plVar2);
                      lVar15 = local_698;
                      if (-1 < iVar9) {
                        iVar9 = (**(code **)(*(longlong *)*plVar2 + 0x58))
                                          ((longlong *)*plVar2,&DAT_14027be10);
                        lVar15 = local_698;
                        if (-1 < iVar9) {
                          iVar9 = (**(code **)(*(longlong *)*plVar2 + 0x68))
                                            ((longlong *)*plVar2,DAT_1403589c8,6);
                          lVar15 = local_698;
                          if (-1 < iVar9) {
                            (**(code **)(*(longlong *)*plVar2 + 0x38))();
                            lVar15 = local_698;
                            uVar18 = local_6d8;
                            goto LAB_14021da29;
                          }
                        }
                      }
                    }
                  }
                }
                uVar18 = local_6d8;
              }
              else {
                if (iVar9 == 2) {
                  *(ulonglong *)(lVar17 + 8 + (longlong)piVar19) = puVar20[5];
                }
LAB_14021da29:
                *(uint *)(lVar17 + (longlong)piVar19) = local_6d4;
              }
              piVar19 = DAT_14033b938;
              puVar20 = DAT_14033b180;
              puVar14 = DAT_14033b188;
            }
          }
          local_6d8 = uVar18 + 1;
          lVar15 = lVar15 + 0xa0;
          lVar17 = lVar17 + 0x50;
        } while ((ulonglong)(longlong)(int)local_6d8 <
                 (ulonglong)(((longlong)puVar14 - (longlong)puVar20 >> 5) * -0x3333333333333333));
      }
    }
    lVar17 = 0;
    iVar9 = 0;
    if (((longlong)DAT_14033b940 - (longlong)piVar19 >> 4) * -0x3333333333333333 != 0) {
      do {
        piVar19 = (int *)(lVar17 + (longlong)piVar19);
        local_6d0 = 0;
        local_6c8 = 0;
        uStack_6c0 = 0;
        uStack_6b8 = 0;
        uStack_6b0 = 0;
        local_6a8 = local_6a8 & 0xffff0000;
        local_6a4 = (undefined8 *)((ulonglong)local_6a4 & 0xffffffff00000000);
        local_698 = lVar15;
        cVar8 = FUN_14021cca0(piVar19);
        lVar15 = local_698;
        if (cVar8 != '\0') {
          iVar3 = (int)DAT_14033b180[(longlong)*piVar19 * 0x14];
          if (iVar3 == 0) {
            local_6e8 = piVar19 + 0xe;
            FUN_14021a480(&local_6d0,DAT_14033b180 + (longlong)*piVar19 * 0x14,piVar19 + 4,
                          piVar19 + 8);
            lVar15 = local_698;
          }
          else if (iVar3 == 3) {
            FUN_14021aaa0(&local_6d0,piVar19 + 4,piVar19 + 6);
            lVar15 = local_698;
          }
          else if (DAT_14032c931 == '\0') {
            FUN_14021c530(&local_6d0);
            lVar15 = local_698;
          }
        }
        iVar9 = iVar9 + 1;
        *(ushort *)(param_1 + 0x28) = *(ushort *)(param_1 + 0x28) | (ushort)local_6a8;
        lVar17 = lVar17 + 0x50;
        piVar19 = DAT_14033b938;
      } while ((ulonglong)(longlong)iVar9 <
               (ulonglong)
               (((longlong)DAT_14033b940 - (longlong)DAT_14033b938 >> 4) * -0x3333333333333333));
    }
    DAT_14032c930 = 0;
    DAT_14032c931 = 0;
    return;
  }
  if ((longlong)DAT_14033b940 - (longlong)DAT_14033b938 != 0xa0) {
    return;
  }
  cVar8 = FUN_14021cca0(DAT_14033b938);
  if (cVar8 == '\0') {
LAB_14021dc03:
    if (DAT_14033b938[1] < 0x1e) {
      DAT_14033b938[1] = DAT_14033b938[1] + 1;
      *(undefined4 *)(param_1 + 4) = 0;
    }
  }
  else {
    iVar9 = (int)DAT_14033b180[(longlong)*piVar19 * 0x14];
    if (iVar9 == 0) {
      local_6e8 = piVar19 + 0xe;
      cVar8 = FUN_14021a480(param_1,DAT_14033b180 + (longlong)*piVar19 * 0x14,piVar19 + 4,
                            piVar19 + 8);
    }
    else if (iVar9 == 3) {
      cVar8 = FUN_14021aaa0(param_1,piVar19 + 4,piVar19 + 6);
    }
    else {
      if (DAT_14032c931 != '\0') goto LAB_14021dc03;
      cVar8 = FUN_14021c530(param_1);
    }
    if (cVar8 == '\0') goto LAB_14021dc03;
    DAT_14033b938[1] = 0;
  }
  piVar19 = DAT_14033b938;
  cVar8 = FUN_14021cca0(DAT_14033b938 + 0x14);
  if (cVar8 != '\0') {
    iVar9 = (int)DAT_14033b180[(longlong)piVar19[0x14] * 0x14];
    if (iVar9 == 0) {
      local_6e8 = piVar19 + 0x22;
      cVar8 = FUN_14021a480(param_1 + 0x30,DAT_14033b180 + (longlong)piVar19[0x14] * 0x14,
                            piVar19 + 0x18,piVar19 + 0x1c);
    }
    else if (iVar9 == 3) {
      cVar8 = FUN_14021aaa0(param_1 + 0x30,piVar19 + 0x18,piVar19 + 0x1a);
    }
    else {
      if (DAT_14032c931 != '\0') goto LAB_14021dca2;
      cVar8 = FUN_14021c530(param_1 + 0x30);
    }
    if (cVar8 != '\0') {
      DAT_14033b938[0x15] = 0;
      goto LAB_14021dcba;
    }
  }
LAB_14021dca2:
  if (DAT_14033b938[0x15] < 0x1e) {
    DAT_14033b938[0x15] = DAT_14033b938[0x15] + 1;
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
LAB_14021dcba:
  if (DAT_14032c933 != DAT_14032c932) {
    if (((DAT_14032c933 == '\0') && (*(int *)(param_1 + 4 + (longlong)DAT_14033dab0 * 0x30) != 1))
       && ((*(ushort *)(param_1 + 0x28 + (longlong)DAT_14033dab0 * 0x30) & 0x6008) != 0)) {
      lVar17 = 0;
      lVar15 = param_1;
      do {
        *(undefined2 *)(lVar17 + 0x28 + param_1) = 0;
        *(undefined8 *)(lVar17 + 0xc + param_1) = 0;
        *(undefined8 *)(lVar17 + 0x14 + param_1) = 0;
        *(undefined8 *)(lVar17 + 0x1c + param_1) = 0;
        *(undefined4 *)(lVar17 + 0x24 + param_1) = 0;
        lVar17 = lVar17 + 0x30;
        *(undefined4 *)(lVar15 + 8) = 0;
        lVar15 = lVar15 + 0x30;
      } while (lVar17 < 0x60);
    }
    else {
      DAT_14032c932 = DAT_14032c933;
    }
  }
  return;
}

