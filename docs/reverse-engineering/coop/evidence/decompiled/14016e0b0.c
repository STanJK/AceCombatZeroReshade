/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016e0b0; RVA 0x16e0b0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14016e0b0(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  uint *puVar12;
  bool bVar13;
  undefined1 auStack_458 [32];
  undefined1 local_438 [1040];
  ulonglong local_28;
  
  lVar5 = DAT_14032c8f8;
  local_28 = DAT_140309040 ^ (ulonglong)auStack_458;
  if (*(char *)(DAT_14032c8f8 + 0x28) != -1) {
    *(char *)(DAT_14032c8f8 + 0x28) = *(char *)(DAT_14032c8f8 + 0x28) + '\x01';
  }
  lVar6 = *(longlong *)(param_1 + 8);
  if (lVar6 != 0) goto LAB_14016e1f4;
  uVar4 = FUN_140200de0(lVar5,0xa8940,0x10);
  uVar4 = FUN_14016d940(uVar4);
  *(undefined8 *)(param_1 + 8) = uVar4;
  if (DAT_14031cf18 == '\0') {
    puVar12 = &DAT_140316e4c;
    uVar9 = (undefined1)DAT_140316e34;
  }
  else {
    puVar12 = &DAT_14031ce04;
    uVar9 = (undefined1)DAT_14031cdec;
  }
  lVar5 = FUN_140189320();
  *(undefined1 *)(lVar5 + 0x2f) = uVar9;
  bVar13 = DAT_140310e8c == 1;
  lVar5 = FUN_140189320();
  uVar9 = 0;
  uVar11 = 0;
  *(bool *)(lVar5 + 0x28) = bVar13;
  uVar10 = 0;
  uVar1 = *puVar12;
  uVar8 = uVar1 & 0xf;
  if ((uVar8 != 0) && (uVar8 == 1)) {
    uVar10 = 1;
  }
  lVar5 = FUN_140189320();
  *(undefined1 *)(lVar5 + 0x35) = uVar10;
  uVar10 = 0;
  switch(uVar1 & 0xf0) {
  case 0x10:
    uVar10 = 1;
    break;
  case 0x20:
switchD_14016e19f_caseD_20:
    uVar11 = uVar9;
    uVar10 = 2;
    break;
  case 0x30:
switchD_14016e19f_caseD_30:
    uVar11 = uVar9;
    uVar10 = 6;
    break;
  case 0x40:
switchD_14016e19f_caseD_40:
    uVar11 = uVar9;
    uVar10 = 3;
    break;
  case 0x50:
switchD_14016e19f_caseD_50:
    uVar11 = uVar9;
    uVar10 = 5;
    break;
  case 0x60:
switchD_14016e19f_caseD_60:
    uVar11 = uVar9;
    uVar10 = 4;
    break;
  case 0x70:
    uVar9 = 1;
    uVar11 = 1;
    uVar2 = FUN_14018e8e0();
    switch(uVar2) {
    case 1:
      uVar10 = 1;
      break;
    case 2:
      goto switchD_14016e19f_caseD_20;
    case 3:
      goto switchD_14016e19f_caseD_30;
    case 4:
      goto switchD_14016e19f_caseD_40;
    case 5:
      goto switchD_14016e19f_caseD_50;
    case 6:
      goto switchD_14016e19f_caseD_60;
    }
  }
  lVar5 = FUN_140189320();
  *(undefined1 *)(lVar5 + 0x43) = uVar10;
  lVar6 = FUN_140189320();
  lVar5 = DAT_14032c8f8;
  *(undefined1 *)(lVar6 + 0x3c) = uVar11;
  lVar6 = *(longlong *)(param_1 + 8);
LAB_14016e1f4:
  iVar3 = DAT_140316e20._4_4_;
  if (DAT_14031cf18 != '\0') {
    iVar3 = DAT_14031cdd8._4_4_;
  }
  if (iVar3 != 0x1c) {
    *(byte *)(lVar6 + 0x68f70) = *(byte *)(lVar6 + 0x68f70) | 1;
  }
  if (*(longlong *)(param_1 + 0x10) == 0) {
    lVar5 = FUN_140200de0(lVar5,0x1c0,0x10);
    FUN_1402777e0(lVar5,0,0x1c0);
    FUN_140004e80(lVar5);
    *(uint *)(lVar5 + 0x1a0) = *(uint *)(lVar5 + 0x1a0) | 3;
    *(undefined4 *)(lVar5 + 0x1b0) = 0x15000000;
    *(undefined2 *)(lVar5 + 0x1b4) = 0x100;
    FUN_1401fbec0();
    *(longlong *)(param_1 + 0x10) = lVar5;
  }
  *(undefined2 *)(*(longlong *)(param_1 + 8) + 0xa8794) = 0;
  lVar5 = *(longlong *)(param_1 + 8);
  FUN_1400c5950(local_438);
  puVar7 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,0x650,0x10);
  *puVar7 = 0;
  puVar7[2] = 0;
  puVar7[1] = 0;
  *(undefined2 *)((longlong)puVar7 + 0x21) = 0x100;
  *(undefined1 *)(puVar7 + 4) = 0;
  puVar7[3] = 0;
  *(undefined8 **)(lVar5 + 0xa8318) = puVar7;
  uVar4 = FUN_1400c5950(puVar7 + 5);
  puVar7[2] = uVar4;
  FUN_1400f41c0(uVar4,puVar7 + 0x86);
  FUN_1400c5950(local_438);
  *(undefined8 **)(lVar5 + 0xa82e8) = (undefined8 *)((longlong)puVar7 + 0x5cc);
  *(undefined8 *)((longlong)puVar7 + 0x5cc) = 0;
  *(undefined8 *)((longlong)puVar7 + 0x5d4) = 0;
  lVar6 = *(longlong *)(lVar5 + 0xa82e8);
  *(undefined8 *)(lVar6 + 0x18) = 0;
  *(undefined8 *)(lVar6 + 0x20) = 0;
  lVar6 = *(longlong *)(lVar5 + 0xa82e8);
  *(undefined8 *)(lVar6 + 0x30) = 0;
  *(undefined8 *)(lVar6 + 0x38) = 0;
  lVar6 = *(longlong *)(lVar5 + 0xa82e8);
  *(undefined8 *)(lVar6 + 0x48) = 0;
  *(undefined8 *)(lVar6 + 0x50) = 0;
  lVar5 = *(longlong *)(lVar5 + 0xa82e8);
  *(undefined8 *)(lVar5 + 0x60) = 0;
  *(undefined8 *)(lVar5 + 0x68) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8260) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8270) = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 8) + 0xa8825) = 0x3c;
  *(undefined1 *)(*(longlong *)(param_1 + 8) + 0xa8821) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8308) = 0;
  iVar3 = DAT_140316e20._4_4_;
  if (DAT_14031cf18 != '\0') {
    iVar3 = DAT_14031cdd8._4_4_;
  }
  DAT_14031e07c = 0;
  DAT_14031e078 = 1;
  DAT_14031e084 = 0;
  if (iVar3 == 0x1f) {
    _DAT_14031e080 = 5;
  }
  else if (iVar3 == 0x1d) {
    _DAT_14031e080 = 4;
  }
  else if (iVar3 < 0x14) {
    _DAT_14031e080 = (9 < iVar3) + 1;
  }
  else {
    _DAT_14031e080 = 3;
  }
  DAT_14032c933 = 1;
  DAT_14033dab0 = 0;
  return;
}

