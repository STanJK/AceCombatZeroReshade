/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001b010; RVA 0x1b010
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14001b010(longlong param_1,undefined4 param_2,longlong param_3,undefined8 *param_4,
                  undefined1 param_5)

{
  byte bVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  float fVar8;
  undefined1 uVar9;
  int iVar10;
  longlong lVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  
  fVar8 = DAT_1402d2878;
  plVar3 = *(longlong **)(param_1 + 0x1a8);
  if (plVar3 != (longlong *)(param_1 + 0x1a0)) {
    lVar4 = *plVar3;
    plVar5 = (longlong *)plVar3[1];
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    *plVar3 = (longlong)plVar3;
    plVar3[1] = (longlong)plVar3;
    *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + -1;
    lVar4 = *(longlong *)(param_3 + 0x1b8);
    lVar6 = *(longlong *)(lVar4 + 0x1630);
    iVar10 = (int)(fVar8 * *(float *)(lVar6 + 0xa14));
    uVar14 = 0;
    if (0xff < iVar10) {
      iVar10 = 0xff;
    }
    iVar12 = 0;
    if (-1 < iVar10) {
      iVar12 = iVar10;
    }
    iVar10 = (int)(fVar8 * *(float *)(lVar6 + 0xa20));
    if (0xff < iVar10) {
      iVar10 = 0xff;
    }
    iVar13 = 0;
    if (-1 < iVar10) {
      iVar13 = iVar10;
    }
    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x428) + 0x67138);
    if (((lVar11 != 0) && (bVar1 = *(byte *)(*(longlong *)(param_1 + 0x428) + 0xa8829), bVar1 < 2))
       && (lVar11 = (longlong)(char)bVar1 * 0xd10 + lVar11, lVar11 != 0)) {
      uVar14 = *(undefined4 *)(lVar11 + 0xc80);
    }
    uVar9 = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
    *(undefined4 *)(plVar3 + 0xc) = param_2;
    *(undefined2 *)((longlong)plVar3 + 100) = *(undefined2 *)(param_3 + 0x228);
    *(undefined1 *)((longlong)plVar3 + 0x66) = *(undefined1 *)(param_3 + 0x234);
    *(undefined1 *)((longlong)plVar3 + 0x67) = *(undefined1 *)(param_3 + 0x235);
    *(undefined1 *)((longlong)plVar3 + 0x6a) = param_5;
    *(undefined1 *)(plVar3 + 0xd) = uVar9;
    *(undefined1 *)((longlong)plVar3 + 0x69) = 0;
    *(undefined1 *)((longlong)plVar3 + 0x6b) = 4;
    *(undefined4 *)(plVar3 + 4) = *(undefined4 *)(lVar6 + 0x9f0);
    *(undefined4 *)((longlong)plVar3 + 0x24) = *(undefined4 *)(lVar6 + 0x9f4);
    *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(lVar6 + 0xa10);
    *(undefined4 *)((longlong)plVar3 + 0x2c) = *(undefined4 *)(lVar4 + 0x1640);
    *(undefined4 *)(plVar3 + 6) = *(undefined4 *)(lVar4 + 0x1650);
    *(undefined4 *)((longlong)plVar3 + 0x34) = *(undefined4 *)(lVar4 + 0x1654);
    *(undefined4 *)(plVar3 + 7) = *(undefined4 *)(lVar4 + 0x1658);
    *(undefined4 *)((longlong)plVar3 + 0x3c) = *(undefined4 *)(lVar4 + 0x1664);
    *(undefined4 *)(plVar3 + 8) = *(undefined4 *)(lVar4 + 0x1668);
    *(undefined4 *)((longlong)plVar3 + 0x44) = *(undefined4 *)(lVar4 + 0x166c);
    uVar2 = *(undefined4 *)(lVar4 + 0x1670);
    *(undefined4 *)((longlong)plVar3 + 0x4c) = uVar14;
    *(undefined4 *)(plVar3 + 9) = uVar2;
    *(undefined1 *)(plVar3 + 10) = *(undefined1 *)(lVar4 + 0x1674);
    *(undefined1 *)((longlong)plVar3 + 0x51) = *(undefined1 *)(lVar4 + 0x1675);
    *(undefined1 *)((longlong)plVar3 + 0x52) = *(undefined1 *)(lVar4 + 0x1676);
    uVar9 = *(undefined1 *)(lVar4 + 0x1677);
    *(char *)((longlong)plVar3 + 0x54) = (char)iVar12;
    *(char *)((longlong)plVar3 + 0x55) = (char)iVar13;
    *(undefined1 *)((longlong)plVar3 + 0x53) = uVar9;
    if ((*(uint *)(lVar4 + 0xd48) & 0x20000) == 0) {
      uVar9 = 2;
    }
    else {
      uVar9 = *(undefined1 *)(lVar4 + 0xc3c);
    }
    *(undefined1 *)((longlong)plVar3 + 0x56) = uVar9;
    if ((*(uint *)(lVar4 + 0xd48) & 0x40000) == 0) {
      uVar9 = 2;
    }
    else {
      uVar9 = *(undefined1 *)(lVar4 + 0xc3d);
    }
    *(undefined1 *)((longlong)plVar3 + 0x57) = uVar9;
    lVar4 = *(longlong *)(param_3 + 0x3d8);
    if (lVar4 == 0) {
      plVar3[3] = 0;
    }
    else {
      plVar3[3] = lVar4;
      *(longlong **)(lVar4 + 0x10) = plVar3;
    }
    plVar3[2] = 0;
    *(longlong **)(param_3 + 0x3d8) = plVar3;
    puVar7 = *(undefined8 **)(param_1 + 0x28);
    *puVar7 = plVar3;
    *(longlong **)(param_1 + 0x28) = plVar3;
    *plVar3 = param_1 + 0x20;
    plVar3[1] = (longlong)puVar7;
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
  }
  return;
}

