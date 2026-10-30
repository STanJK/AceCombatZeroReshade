/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14012bf60; RVA 0x12bf60
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14012bf60(undefined8 *param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  
  if (param_1[2] == 0) {
    return;
  }
  FUN_1400f4d40();
  lVar2 = param_1[2];
  if (((((*(byte *)(lVar2 + 0x3dc) & 1) != 0) &&
       (puVar3 = *(undefined8 **)(lVar2 + 0x2d8), puVar3 != (undefined8 *)0x0)) &&
      (*(byte *)(lVar2 + 0x3c9) < *(byte *)*puVar3)) &&
     (puVar3 = (undefined8 *)(puVar3[1] + (ulonglong)*(byte *)(lVar2 + 0x3c9) * 0x48),
     puVar3 != (undefined8 *)0x0)) {
    cVar5 = *(char *)*puVar3;
    if (cVar5 == '\0') {
      *(int *)(param_1 + 3) = *(int *)(param_1 + 3) + 1;
    }
    else if ((cVar5 - 4U & 0xfd) == 0) {
      iVar4 = *(int *)((longlong)param_1 + 0x1c) + 1;
      *(int *)((longlong)param_1 + 0x1c) = iVar4;
      if (lVar2 != 0) {
        *(int *)(lVar2 + 0x3ac) = iVar4;
      }
    }
  }
  bVar6 = *(byte *)((longlong)param_1 + 0x21) & 0xfd;
  *(byte *)((longlong)param_1 + 0x21) = bVar6;
  uVar1 = *(uint *)(param_1[2] + 0x3a8);
  if ((uVar1 & 1) != 0) {
    if ((uVar1 >> 0x14 & 1) == 0) {
      if ((int)(**(byte **)*param_1 - 1) <= (int)(uint)*(byte *)(param_1 + 4)) {
        *(byte *)((longlong)param_1 + 0x21) = bVar6 | 1;
        goto LAB_14012c03d;
      }
      cVar5 = *(byte *)(param_1 + 4) + 1;
    }
    else {
      cVar5 = *(char *)(param_1[2] + 0x3eb);
    }
    FUN_14012c0a0(param_1,cVar5);
    if (*(char *)((longlong)param_1 + 0x23) == '\x01') {
      FUN_1400f4d40(param_1[2]);
    }
  }
LAB_14012c03d:
  lVar2 = param_1[2];
  if (((lVar2 == 0) || (puVar3 = *(undefined8 **)(lVar2 + 0x2d8), puVar3 == (undefined8 *)0x0)) ||
     ((*(byte *)*puVar3 <= *(byte *)(lVar2 + 0x3c9) ||
      (puVar3 = (undefined8 *)(puVar3[1] + (ulonglong)*(byte *)(lVar2 + 0x3c9) * 0x48),
      puVar3 == (undefined8 *)0x0)))) {
    *(undefined1 *)((longlong)param_1 + 0x23) = 0xff;
    return;
  }
  *(undefined1 *)((longlong)param_1 + 0x23) = *(undefined1 *)*puVar3;
  return;
}

