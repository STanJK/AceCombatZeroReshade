/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401fc350; RVA 0x1fc350
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 * FUN_1401fc350(longlong param_1,undefined8 *param_2)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  
  *param_2 = 0x1000000b;
  *(undefined4 *)((longlong)param_2 + 0xc) = 0x5000000b;
  *(undefined4 *)(param_2 + 2) = 0x800a;
  *(undefined4 *)(param_2 + 1) = 0;
  *(undefined4 *)((longlong)param_2 + 0x14) = 0x10000000;
  param_2[3] = 0xe;
  bVar1 = *(byte *)(param_1 + 0x1b4);
  iVar7 = *(short *)(param_1 + 0x18) + 0x3f;
  uVar2 = *(ushort *)(param_1 + 0x1b0);
  *(undefined4 *)((longlong)param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 5) = 0x4c;
  *(uint *)(param_2 + 4) =
       ((int)(iVar7 + (iVar7 >> 0x1f & 0x3fU)) >> 6 | (uint)bVar1 << 8) << 0x10 | uVar2 + 0x1f >> 5;
  bVar1 = *(byte *)(param_1 + 0x1b4);
  iVar7 = *(short *)(param_1 + 0x18) + 0x3f;
  uVar2 = *(ushort *)(param_1 + 0x1b0);
  *(undefined4 *)((longlong)param_2 + 0x34) = 0;
  *(undefined4 *)(param_2 + 7) = 0x4d;
  *(uint *)(param_2 + 6) =
       ((int)(iVar7 + (iVar7 >> 0x1f & 0x3fU)) >> 6 | (uint)bVar1 << 8) << 0x10 | uVar2 + 0x1f >> 5;
  uVar2 = *(ushort *)(param_1 + 0x1b2);
  bVar1 = *(byte *)(param_1 + 0x1b5);
  *(undefined4 *)((longlong)param_2 + 0x44) = 0;
  *(undefined4 *)(param_2 + 9) = 0x4e;
  *(uint *)(param_2 + 8) = uVar2 + 0x1f >> 5 | (uint)bVar1 << 0x18;
  uVar2 = *(ushort *)(param_1 + 0x1b2);
  bVar1 = *(byte *)(param_1 + 0x1b5);
  *(undefined4 *)((longlong)param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0xb) = 0x4f;
  *(uint *)(param_2 + 10) = uVar2 + 0x1f >> 5 | (uint)bVar1 << 0x18;
  sVar3 = *(short *)(param_1 + 0x26);
  sVar4 = *(short *)(param_1 + 0x24);
  sVar5 = *(short *)(param_1 + 0x2a);
  sVar6 = *(short *)(param_1 + 0x28);
  *(undefined4 *)(param_2 + 0xd) = 0x40;
  *(int *)((longlong)param_2 + 100) = (sVar5 + -1 + (int)sVar3) * 0x10000 | (int)sVar3;
  *(int *)(param_2 + 0xc) = (sVar6 + -1 + (int)sVar4) * 0x10000 | (int)sVar4;
  sVar3 = *(short *)(param_1 + 0x2a);
  sVar4 = *(short *)(param_1 + 0x26);
  *(int *)(param_2 + 0xe) =
       (*(short *)(param_1 + 0x28) + -1 + (int)*(short *)(param_1 + 0x24)) * 0x10000 |
       (int)*(short *)(param_1 + 0x24);
  *(int *)((longlong)param_2 + 0x74) = (sVar3 + -1 + (int)sVar4) * 0x10000 | (int)sVar4;
  *(undefined4 *)(param_2 + 0xf) = 0x41;
  sVar3 = *(short *)(param_1 + 0x24);
  sVar4 = *(short *)(param_1 + 0x28);
  *(int *)((longlong)param_2 + 0x84) =
       *(short *)(param_1 + 0x26) * -0x10 + ((int)*(short *)(param_1 + 0x2a) / 2) * -0x10 + 0x8000;
  *(undefined4 *)(param_2 + 0x11) = 0x18;
  *(int *)(param_2 + 0x10) = sVar3 * -0x10 + ((int)sVar4 / 2) * -0x10 + 0x8000;
  sVar3 = *(short *)(param_1 + 0x24);
  sVar4 = *(short *)(param_1 + 0x28);
  *(int *)((longlong)param_2 + 0x94) =
       *(short *)(param_1 + 0x26) * -0x10 + ((int)*(short *)(param_1 + 0x2a) / 2) * -0x10 + 0x8000;
  *(undefined4 *)(param_2 + 0x13) = 0x19;
  *(undefined4 *)(param_2 + 0x14) = 0x30003;
  *(undefined4 *)(param_2 + 0x15) = 0x47;
  *(int *)(param_2 + 0x12) = sVar3 * -0x10 + ((int)sVar4 / 2) * -0x10 + 0x8000;
  *(undefined4 *)(param_2 + 0x16) = 0x30003;
  *(undefined4 *)(param_2 + 0x17) = 0x48;
  return param_2 + 0x18;
}

