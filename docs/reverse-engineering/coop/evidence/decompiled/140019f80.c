/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140019f80; RVA 0x19f80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140019f80(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  
  puVar2 = param_1 + 4;
  puVar1 = param_1 + 0x34;
  *puVar2 = puVar2;
  param_1[5] = puVar2;
  *(undefined4 *)(param_1 + 0x12) = 0;
  uVar5 = 0;
  puVar2 = param_1 + 0x52;
  *puVar1 = puVar1;
  *puVar2 = puVar2;
  param_1[0x53] = puVar2;
  *(undefined4 *)(param_1 + 0x60) = 0;
  param_1[0x35] = puVar1;
  *(undefined4 *)(param_1 + 0x42) = 0;
  if (*(int *)(param_1 + 0x33) != 0) {
    do {
      uVar3 = (ulonglong)uVar5;
      uVar5 = uVar5 + 1;
      puVar2 = (undefined8 *)param_1[0x35];
      puVar4 = (undefined8 *)(uVar3 * 0x70 + param_1[0x32]);
      *puVar2 = puVar4;
      param_1[0x35] = puVar4;
      *puVar4 = puVar1;
      puVar4[1] = puVar2;
      *(int *)(param_1 + 0x42) = *(int *)(param_1 + 0x42) + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x33));
  }
  puVar2 = param_1 + 0x13;
  iVar6 = 0;
  puVar1 = param_1 + 0x43;
  *puVar2 = puVar2;
  param_1[0x14] = puVar2;
  *(undefined4 *)(param_1 + 0x21) = 0;
  *puVar1 = puVar1;
  param_1[0x44] = puVar1;
  *(undefined4 *)(param_1 + 0x51) = 0;
  if (0 < *(int *)(param_1 + 0x61)) {
    lVar7 = 0;
    do {
      iVar6 = iVar6 + 1;
      puVar2 = (undefined8 *)param_1[0x44];
      puVar4 = (undefined8 *)(param_1[0x62] + lVar7);
      lVar7 = lVar7 + 0x70;
      *puVar2 = puVar4;
      param_1[0x44] = puVar4;
      *puVar4 = puVar1;
      puVar4[1] = puVar2;
      *(int *)(param_1 + 0x51) = *(int *)(param_1 + 0x51) + 1;
    } while (iVar6 < *(int *)(param_1 + 0x61));
  }
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 4;
  *(undefined8 *)((longlong)param_1 + 0xc) = 2;
  param_1[3] = 0;
  param_1[99] = 0;
  *(undefined2 *)(param_1 + 100) = 0xffff;
  *(undefined4 *)((longlong)param_1 + 0x324) = 0xffffffff;
  FUN_140019da0(param_1);
  return;
}

