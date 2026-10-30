/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400abff0; RVA 0xabff0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400abff0(longlong param_1,longlong param_2,uint *param_3,uint *param_4,uint *param_5,
                  uint *param_6,uint *param_7,longlong param_8,longlong param_9,longlong param_10,
                  longlong *param_11)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  
  if (param_2 != 0) {
    puVar3 = (undefined8 *)FUN_1400aba40();
    *(undefined8 **)(param_1 + 0x10) = puVar3;
    (**(code **)*puVar3)(puVar3,param_2);
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x508) = DAT_14030f800;
    (**(code **)(**(longlong **)(param_1 + 0x10) + 0x10))
              (*(longlong **)(param_1 + 0x10),param_11 + 0xac);
    iVar2 = (**(code **)(**(longlong **)(param_1 + 0x10) + 8))();
    param_11 = (longlong *)((longlong)iVar2 + (longlong)(param_11 + 0xac));
  }
  if (param_3 != (uint *)0x0) {
    *param_11 = 0;
    param_11[1] = 0;
    param_11[2] = 0;
    param_11[3] = 0;
    *(longlong **)(param_1 + 0x20) = param_11;
    FUN_1401491e0(param_11,param_3,param_11 + 4);
    if (*param_3 == 0) {
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = (char *)((ulonglong)*param_3 + (longlong)param_3);
    }
    cVar1 = *pcVar4;
    if (cVar1 == '\0') {
      lVar5 = 0x20;
    }
    else {
      lVar5 = 0x18;
      if ((cVar1 != '\x01') && (lVar5 = 0, cVar1 == '\x02')) {
        lVar5 = 0x18;
      }
    }
    lVar6 = (lVar5 + 0xfU & 0xfffffffffffffff0) + (longlong)(param_11 + 4);
    lVar5 = FUN_1400aaab0(lVar6);
    param_11 = (longlong *)(lVar6 + 0x640);
    *(longlong *)(param_1 + 0x18) = lVar5;
    FUN_140128fe0(lVar5 + 600,*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8));
  }
  plVar9 = param_11;
  if (param_4 != (uint *)0x0) {
    *param_11 = 0;
    *(longlong **)(param_1 + 0x28) = param_11;
    plVar9 = param_11 + 3;
    if (*param_4 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = (ulonglong)*param_4 + (longlong)param_4;
    }
    *param_11 = lVar5;
  }
  plVar8 = plVar9;
  if (param_5 != (uint *)0x0) {
    *plVar9 = 0;
    *(longlong **)(param_1 + 0x30) = plVar9;
    plVar8 = plVar9 + 3;
    if (*param_5 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = (ulonglong)*param_5 + (longlong)param_5;
    }
    *plVar9 = lVar5;
  }
  plVar9 = plVar8;
  if (param_6 != (uint *)0x0) {
    *plVar8 = 0;
    *(longlong **)(param_1 + 0x38) = plVar8;
    plVar9 = plVar8 + 3;
    if (*param_6 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = (ulonglong)*param_6 + (longlong)param_6;
    }
    *plVar8 = lVar5;
  }
  plVar8 = plVar9;
  if (param_7 != (uint *)0x0) {
    *plVar9 = 0;
    *(longlong **)(param_1 + 0x48) = plVar9;
    plVar7 = plVar9 + 3;
    if (*param_7 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = (ulonglong)*param_7 + (longlong)param_7;
    }
    *plVar9 = lVar5;
    plVar8 = plVar7;
    if (*(char *)((ulonglong)*(byte *)(param_1 + 0x85) + 4 + **(longlong **)(param_1 + 0x48)) ==
        '\b') {
      *(undefined4 *)((longlong)plVar9 + 0x1c) = 0x3c000000;
      *(undefined1 *)((longlong)plVar9 + 0x21) = 0;
      plVar8 = plVar9 + 5;
      *(longlong **)(param_1 + 8) = plVar7;
      *(undefined4 *)plVar7 = 0x3e4ccccd;
      *(undefined1 *)(plVar9 + 4) = 8;
    }
  }
  *plVar8 = 0;
  *(undefined4 *)(plVar8 + 1) = 0x3f800000;
  *(undefined4 *)((longlong)plVar8 + 0xc) = 0x1000000;
  *(longlong **)(param_1 + 0x50) = plVar8;
  plVar8[3] = 0;
  *(undefined4 *)(plVar8 + 4) = 0x3f800000;
  *(undefined4 *)((longlong)plVar8 + 0x24) = 0x1000000;
  *(longlong **)(param_1 + 0x58) = plVar8 + 3;
  plVar8[6] = 0;
  plVar9 = plVar8 + 9;
  *(undefined4 *)(plVar8 + 7) = 0x3f800000;
  *(undefined4 *)((longlong)plVar8 + 0x3c) = 0x1000000;
  *(longlong **)(param_1 + 0x60) = plVar8 + 6;
  if (param_8 != 0) {
    puVar3 = *(undefined8 **)(param_1 + 0x50);
    *plVar9 = (longlong)&PTR_FUN_1402ac750;
    *puVar3 = plVar9;
    FUN_140162780(plVar9,param_8);
    FUN_140162a80(*puVar3,plVar8 + 0x12);
    FUN_140162840(*puVar3);
    if (*(longlong *)(param_1 + 0x38) != 0) {
      FUN_140102800(*(undefined8 *)(param_1 + 0x50),
                    *(undefined1 *)(**(longlong **)(param_1 + 0x48) + 4));
    }
    iVar2 = FUN_1401029f0();
    plVar9 = (longlong *)((longlong)plVar9 + (longlong)iVar2);
  }
  if (param_9 != 0) {
    puVar3 = *(undefined8 **)(param_1 + 0x58);
    *plVar9 = (longlong)&PTR_FUN_1402ac750;
    *puVar3 = plVar9;
    FUN_140162780(plVar9,param_9);
    FUN_140162a80(*puVar3,plVar9 + 9);
    FUN_140162840(*puVar3);
    if (*(longlong *)(param_1 + 0x38) != 0) {
      FUN_140102800(*(undefined8 *)(param_1 + 0x58),
                    *(undefined1 *)(**(longlong **)(param_1 + 0x48) + 5));
    }
    iVar2 = FUN_1401029f0();
    plVar9 = (longlong *)((longlong)plVar9 + (longlong)iVar2);
  }
  if (param_10 != 0) {
    puVar3 = *(undefined8 **)(param_1 + 0x60);
    *plVar9 = (longlong)&PTR_FUN_1402ac750;
    *puVar3 = plVar9;
    FUN_140162780(plVar9,param_10);
    FUN_140162a80(*puVar3,plVar9 + 9);
    FUN_140162840(*puVar3);
    if (*(longlong *)(param_1 + 0x38) != 0) {
      FUN_140102800(*(undefined8 *)(param_1 + 0x60),
                    *(undefined1 *)(**(longlong **)(param_1 + 0x48) + 6));
    }
    FUN_1401029f0();
  }
  return;
}

