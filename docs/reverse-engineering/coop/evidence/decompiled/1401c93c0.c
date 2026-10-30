/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401c93c0; RVA 0x1c93c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_1401c93c0(void)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  
  _DAT_1437db040 = 0xffffffff;
  _DAT_1437daf20 = 0;
  _DAT_1437db044 = 0xffff;
  _DAT_1437db05c = 0xffff;
  lVar3 = 0x80;
  _DAT_1437db074 = 0xffff;
  _DAT_1437db08c = 0xffff;
  _DAT_1437db0a4 = 0xffff;
  _DAT_1437db0bc = 0xffff;
  puVar2 = (undefined8 *)&DAT_1437db0c8;
  _DAT_1437db030 = 0;
  _DAT_1437db038 = 0;
  DAT_1437db046 = 0;
  _DAT_1437db048 = 0;
  _DAT_1437db050 = 0;
  _DAT_1437db058 = 0xffffffff;
  DAT_1437db05e = 0;
  _DAT_1437db060 = (undefined1  [16])0x0;
  _DAT_1437db070 = 0xffffffff;
  DAT_1437db076 = 0;
  _DAT_1437db078 = 0;
  _DAT_1437db080 = 0;
  _DAT_1437db088 = 0xffffffff;
  DAT_1437db08e = 0;
  _DAT_1437db090 = 0;
  _DAT_1437db098 = 0;
  _DAT_1437db0a0 = 0xffffffff;
  DAT_1437db0a6 = 0;
  _DAT_1437db0a8 = 0;
  _DAT_1437db0b0 = 0;
  _DAT_1437db0b8 = 0xffffffff;
  DAT_1437db0be = 0;
  do {
    puVar2[-1] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    *(undefined4 *)(puVar2 + 6) = 0;
    *(undefined8 *)((longlong)puVar2 + 0x34) = 0x3f800000;
    *(undefined8 *)((longlong)puVar2 + 0x3c) = 0xff00ff;
    *(undefined1 *)(puVar2 + 0xd) = 4;
    puVar2 = puVar2 + 0xf;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  _DAT_1437decc0 = _DAT_1402d35f0;
  uRam00000001437decc8 = _UNK_1402d35f8;
  _DAT_1437decdc = 0;
  _DAT_1437decd0 = 0;
  _DAT_1437dece1 = 0;
  lVar3 = FUN_140189320();
  puVar4 = &DAT_1437db140;
  _DAT_1437decd8 = DAT_1402d2a8c / (float)*(int *)(lVar3 + 0xc);
  _DAT_1437decde = 0;
  puVar5 = &DAT_1437daf20;
  do {
    uVar1 = puVar4[-0x12];
    if (((uVar1 != 0) && ((ushort)uVar1 < 0x80)) &&
       ((short)(uVar1 >> 0x10) == *(short *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2))) {
      *(undefined2 *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2) = 0;
    }
    *(undefined8 *)(puVar4 + -0x20) = 0;
    puVar4[-0x1e] = 0;
    *(undefined8 *)(puVar4 + -0x1d) = 0x3f800000;
    *(undefined8 *)(puVar4 + -0x1b) = 0;
    *(undefined8 *)(puVar4 + -0x19) = 0x3f800000;
    *(undefined8 *)(puVar4 + -0x17) = 0;
    puVar4[-0x15] = 0x3f800000;
    *(undefined8 *)(puVar4 + -0x11) = 0x3f800000;
    *(undefined8 *)(puVar4 + -0xf) = 0xff00ff;
    *(undefined1 *)(puVar4 + -4) = 4;
    puVar4[-0x12] = 0;
    *(code **)(puVar4 + -0x14) = FUN_1400a3fa0;
    uVar1 = puVar4[0xc];
    if (((uVar1 != 0) && ((ushort)uVar1 < 0x80)) &&
       ((short)(uVar1 >> 0x10) == *(short *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2))) {
      *(undefined2 *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2) = 0;
    }
    *(undefined8 *)(puVar4 + -2) = 0;
    *puVar4 = 0;
    *(undefined8 *)(puVar4 + 1) = 0x3f800000;
    *(undefined8 *)(puVar4 + 3) = 0;
    *(undefined8 *)(puVar4 + 5) = 0x3f800000;
    *(undefined8 *)(puVar4 + 7) = 0;
    puVar4[9] = 0x3f800000;
    *(undefined8 *)(puVar4 + 0xd) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0xf) = 0xff00ff;
    *(undefined1 *)(puVar4 + 0x1a) = 4;
    puVar4[0xc] = 0;
    *(code **)(puVar4 + 10) = FUN_1400a3fa0;
    uVar1 = puVar4[0x2a];
    if (((uVar1 != 0) && ((ushort)uVar1 < 0x80)) &&
       ((short)(uVar1 >> 0x10) == *(short *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2))) {
      *(undefined2 *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2) = 0;
    }
    *(undefined8 *)(puVar4 + 0x1c) = 0;
    puVar4[0x1e] = 0;
    *(undefined8 *)(puVar4 + 0x1f) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x21) = 0;
    *(undefined8 *)(puVar4 + 0x23) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x25) = 0;
    puVar4[0x27] = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x2b) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x2d) = 0xff00ff;
    *(undefined1 *)(puVar4 + 0x38) = 4;
    puVar4[0x2a] = 0;
    *(code **)(puVar4 + 0x28) = FUN_1400a3fa0;
    uVar1 = puVar4[0x48];
    if (((uVar1 != 0) && ((ushort)uVar1 < 0x80)) &&
       ((short)(uVar1 >> 0x10) == *(short *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2))) {
      *(undefined2 *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2) = 0;
    }
    *(undefined8 *)(puVar4 + 0x3a) = 0;
    puVar4[0x3c] = 0;
    *(undefined8 *)(puVar4 + 0x3d) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x3f) = 0;
    *(undefined8 *)(puVar4 + 0x41) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x43) = 0;
    puVar4[0x45] = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x49) = 0x3f800000;
    *(undefined8 *)(puVar4 + 0x4b) = 0xff00ff;
    *(undefined1 *)(puVar4 + 0x56) = 4;
    puVar4[0x48] = 0;
    *(code **)(puVar4 + 0x46) = FUN_1400a3fa0;
    puVar4 = puVar4 + 0x78;
  } while ((longlong)puVar4 < 0x1437ded40);
  FUN_1401cb260(&DAT_1437daf20);
  return puVar5;
}

