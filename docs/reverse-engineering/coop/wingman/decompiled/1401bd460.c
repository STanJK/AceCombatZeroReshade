/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401bd460; RVA 0x1bd460
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401bd460(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  int param_5,undefined1 param_6,int param_7)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  byte bVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined **ppuVar9;
  ulonglong uVar10;
  
  *(undefined8 *)(param_1 + 0x20) = param_2;
  *(undefined8 *)(param_1 + 0x28) = param_4;
  *(undefined1 *)(param_1 + 0x10) = param_6;
  *(undefined8 *)(param_1 + 0x18) = param_3;
  *(int *)(param_1 + 0xc) = param_5;
  *(int *)(param_1 + 0x30) = param_7;
  *(int *)(param_1 + 0x11c) = param_7;
  *(int *)(param_1 + 0x240) = param_7;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 1;
  *(undefined4 *)(param_1 + 0x290) = 1;
  ppuVar9 = &PTR_PTR_140316e70;
  if (DAT_14031cf18 == '\0') {
    ppuVar9 = &PTR_PTR_140310eb8;
  }
  puVar7 = &DAT_1403170c8;
  *(undefined4 *)(param_1 + 0x254) =
       *(undefined4 *)((longlong)ppuVar9 + (longlong)param_7 * 4 + 0x254);
  if (DAT_14031cf18 == '\0') {
    puVar7 = &DAT_140311110;
  }
  *(undefined4 *)(param_1 + 0x2a4) = *puVar7;
  lVar3 = *(longlong *)(param_1 + 0x38);
  *(undefined8 *)(lVar3 + 0x10) = param_2;
  *(undefined8 *)(lVar3 + 0x18) = param_4;
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar4 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(lVar3 + 0x18) = uVar4;
  lVar3 = *(longlong *)(param_1 + 0x48);
  uVar4 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(lVar3 + 0x18) = uVar4;
  lVar3 = *(longlong *)(param_1 + 0x50);
  uVar4 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(lVar3 + 0x18) = uVar4;
  *(int *)(param_1 + 0x200) = param_5;
  if (param_5 == 0) {
    uVar8 = 5;
  }
  else {
    if (param_5 != 1) {
      return;
    }
    uVar8 = 10;
  }
  *(uint *)(param_1 + 0x158) = uVar8;
  if (*(char *)(param_1 + 0x13c) == '\0') {
    lVar3 = *(longlong *)(param_1 + 0x140);
    iVar5 = *(int *)(param_1 + 0x150) * 2;
    *(char *)(lVar3 + 0x26c9) = (char)iVar5;
    pbVar1 = (byte *)((longlong)iVar5 + 0x26cc + lVar3);
    *pbVar1 = *pbVar1 | 1;
    uVar8 = *(uint *)(param_1 + 0x158);
    lVar3 = *(longlong *)(param_1 + 0x140);
    uVar2 = *(uint *)(&DAT_1402917ec + (longlong)(int)uVar8 * 0x10);
    bVar6 = *(char *)(param_1 + 0x150) * '\x02';
    uVar10 = (ulonglong)bVar6;
    if (((*(char *)(uVar10 + 0x26d0 + lVar3) == '\0') ||
        (*(byte *)(uVar10 + 0x26d4 + lVar3) != uVar8)) ||
       (*(byte *)(uVar10 + 0x26d8 + lVar3) != uVar2)) {
      *(char *)(uVar10 + 0x26d4 + lVar3) = (char)uVar8;
      *(char *)(uVar10 + 0x26d8 + lVar3) = (char)uVar2;
      *(undefined1 *)(uVar10 + 0x26d0 + lVar3) = 1;
      if ((int)*(char *)(lVar3 + 0x26cb) == (uint)bVar6) {
        *(undefined1 *)(lVar3 + 0x26dc) = 10;
      }
    }
  }
  return;
}

