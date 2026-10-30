/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ff340; RVA 0x1ff340
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401ff340(undefined8 *param_1)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  int iVar11;
  bool bVar12;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  cVar4 = FUN_14018d760();
  if (cVar4 != '\0') {
    plVar6 = (longlong *)_malloc_base(0x3ffeff0);
    iVar11 = 0;
    lVar8 = 0;
    plVar7 = plVar6 + 6;
    DAT_14032c8f8 = plVar6;
    plVar6[1] = 0x3ffefc0;
    *plVar6 = (longlong)plVar7;
    plVar6[2] = (longlong)plVar7;
    *(undefined4 *)(plVar6 + 3) = 0x400;
    do {
      lVar3 = plVar6[2];
      lVar8 = lVar8 + 0x18;
      iVar11 = iVar11 + 1;
      *(undefined8 *)(lVar3 + -0x18 + lVar8) = 0;
      *(undefined8 *)(lVar3 + -0x10 + lVar8) = 0;
      *(undefined1 *)(lVar3 + -8 + lVar8) = 0;
    } while (iVar11 < (int)plVar6[3]);
    puVar9 = (undefined8 *)plVar6[2];
    uVar5 = (int)plVar6[3] * 0x18;
    bVar12 = DAT_140326f82 == '\0';
    *puVar9 = plVar7;
    puVar9[1] = (ulonglong)uVar5;
    *(undefined1 *)(puVar9 + 2) = 0;
    plVar6[4] = (ulonglong)uVar5 + (longlong)plVar7;
    *(undefined1 *)(plVar6 + 5) = 1;
    *(undefined4 *)((longlong)plVar6 + 0xc) = 0;
    if (bVar12) {
      DAT_140326f82 = '\x01';
    }
    plVar7 = (longlong *)FUN_140200de0(plVar6,0x28,0x10);
    *(undefined4 *)((longlong)plVar7 + 0x23) = 0;
    *(undefined1 *)((longlong)plVar7 + 0x27) = 0;
    *(undefined2 *)(plVar7 + 4) = 0;
    *plVar7 = 0;
    plVar7[1] = 0;
    plVar7[2] = 0;
    plVar7[3] = 0x100000;
    *(undefined1 *)((longlong)plVar7 + 0x22) = 0;
    DAT_14032c8a8 = plVar7;
    lVar8 = FUN_140200de0(plVar6,0x200000,0x10);
    *plVar7 = lVar8;
    plVar7[1] = (ulonglong)*(uint *)(plVar7 + 3) + lVar8;
    plVar7[2] = plVar7[(char)plVar7[4]];
    lVar8 = FUN_140200de0(plVar6,0x110,0x10);
    DAT_14032c8b8 = lVar8;
    *(undefined8 *)(lVar8 + 0x10) = 0;
    *(undefined1 *)(lVar8 + 0xdf) = 0;
    *(undefined8 *)(lVar8 + 0xc0) = 0;
    *(undefined8 *)(lVar8 + 200) = 0;
    *(undefined8 *)(lVar8 + 0xa0) = 0;
    *(undefined8 *)(lVar8 + 0xb0) = 0;
    *(undefined8 *)(lVar8 + 0xa8) = 0;
    *(undefined8 *)(lVar8 + 0xb8) = 0;
    *(undefined4 *)(lVar8 + 0xe4) = 0x10000;
    *(undefined8 *)(lVar8 + 0xe8) = 0x1c00280;
    *(undefined8 *)(lVar8 + 0xf0) = *(undefined8 *)(lVar8 + 0xe4);
    *(undefined4 *)(lVar8 + 0xf8) = *(undefined4 *)(lVar8 + 0xec);
    *(undefined4 *)(lVar8 + 0xfc) = 0;
    *(undefined4 *)(lVar8 + 0x100) = 0x1c00280;
    *(undefined8 *)(lVar8 + 0x104) = *(undefined8 *)(lVar8 + 0xfc);
    *(undefined2 *)(lVar8 + 0xdc) = 0x1500;
    *(undefined1 *)(lVar8 + 0xde) = 0x31;
    *(undefined4 *)(lVar8 + 0x10c) = 0x80808080;
    *(undefined8 *)(lVar8 + 0xd0) = 0;
    *(undefined4 *)(lVar8 + 0xd8) = 0;
    *(undefined2 *)(lVar8 + 0xe0) = 0;
    *(undefined4 *)(lVar8 + 0x1c) = 0;
    FUN_1401fe800();
    lVar8 = DAT_14032c8b8;
    uVar5 = *(uint *)(DAT_14032c8b8 + 0xd0);
    uVar2 = *(uint *)(DAT_14032c8b8 + 0xd4);
    *(undefined4 *)(DAT_14032c8b8 + 0x104) = 0;
    *(undefined4 *)(lVar8 + 0x108) = 0x1c00200;
    *(undefined4 *)(lVar8 + 0xf0) = 0x10e00;
    *(undefined8 *)(lVar8 + 0xf4) = 0x1c00200;
    *(undefined2 *)(lVar8 + 0xdc) = 0x1500;
    *(undefined1 *)(lVar8 + 0xde) = 0x31;
    *(undefined4 *)(lVar8 + 0xd8) = 0x80000000;
    *(uint *)(lVar8 + 0xd4) = uVar2 & 0xfffffefd | 0xcd;
    *(uint *)(lVar8 + 0xd0) = uVar5 | 0x17;
    FUN_1401fe9c0();
    plVar7 = DAT_14032c8f8;
    puVar9 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,0x50,0x10);
    local_28 = 2;
    local_24 = 0xe;
    local_20 = 0xe;
    *puVar9 = &PTR_FUN_1402cdc90;
    puVar9[1] = 0;
    puVar9[2] = 0;
    puVar9[3] = 0;
    puVar9[4] = 0;
    puVar9[5] = 0;
    puVar9[6] = 0;
    puVar9[7] = 0;
    puVar9[8] = 0;
    *(undefined4 *)(puVar9 + 9) = 0xffffffff;
    *param_1 = puVar9;
    local_1c = 0x400;
    local_18 = 0x400;
    FUN_140201840(&PTR_FUN_1402cdc90,&local_28);
    lVar8 = FUN_140200de0(plVar7,0x158,0x10);
    FUN_1402777e0(lVar8,0,0x158);
    *(undefined1 *)(lVar8 + 0x2e) = 0xff;
    *(undefined2 *)(lVar8 + 0x30) = 0x41e;
    *(undefined1 *)(lVar8 + 0x7e) = 0xff;
    *(undefined2 *)(lVar8 + 0x80) = 0x41e;
    *(undefined1 *)(lVar8 + 0xce) = 0xff;
    *(undefined2 *)(lVar8 + 0xd0) = 0x41e;
    *(undefined1 *)(lVar8 + 0x11e) = 0xff;
    *(undefined2 *)(lVar8 + 0x120) = 0x41e;
    DAT_14032c8e8 = lVar8;
    lVar8 = FUN_140200de0(plVar7,0x48,0x40);
    DAT_14032c8e0 = lVar8;
    *(undefined1 *)(lVar8 + 0x22) = 0;
    *(undefined1 *)(lVar8 + 0x46) = 0;
    DAT_14032c8d0 = FUN_140200de0(plVar7,1,0x40);
    _DAT_14032c8c8 = FUN_140200de0(plVar7,1,0x40);
    uVar10 = FUN_140200de0(plVar7,0x90,0x10);
    DAT_14032c8c0 = FUN_140187480(uVar10);
    uVar10 = FUN_140200de0(plVar7,0x2c0,0x10);
    DAT_14032c8f0 = FUN_140187560(uVar10);
    uVar10 = FUN_140200de0(DAT_14032c8f8,0x80,0x10);
    DAT_14032c8d8 = FUN_140188490(uVar10);
    FUN_14021cd80();
    uVar10 = FUN_140189320();
    FUN_140189380(uVar10);
    FUN_140189320();
    *(undefined4 *)(DAT_14032c8c0 + 0x16) = 0xe0f0d10;
    lVar8 = FUN_140189320();
    bVar1 = *(byte *)(lVar8 + 0x3f);
    lVar8 = FUN_1402014c0();
    *(undefined4 *)(lVar8 + 0x7a0) = 1;
    *(undefined4 *)(lVar8 + 0x7a4) = 1;
    if ((bVar1 == 0) || (bVar1 - 1 < 2)) {
      *(uint *)(lVar8 + 0x7a8) = (uint)bVar1;
    }
    *(undefined4 *)(lVar8 + 0x7ac) = 0;
    uVar10 = FUN_1402014c0();
    FUN_140201520(uVar10);
    if ((char)DAT_14032c8f8[5] != -1) {
      *(char *)(DAT_14032c8f8 + 5) = (char)DAT_14032c8f8[5] + '\x01';
    }
  }
  return;
}

