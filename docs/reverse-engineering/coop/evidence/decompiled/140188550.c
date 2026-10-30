/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140188550; RVA 0x188550
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_140188550(ushort arg1,uchar *arg2,uchar *arg3)

{
  byte bVar1;
  float fVar2;
  uchar uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uchar uVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  uint local_res10 [6];
  
  *arg3 = -((arg1 & 8) != 0);
  arg3[1] = -((arg1 & 1) != 0);
  fVar2 = DAT_1402d231c;
  arg3[2] = arg2[4];
  arg3[3] = arg2[5];
  arg3[4] = arg2[6];
  arg3[5] = arg2[7];
  if (arg2[0xc] < 0xd9) {
    iVar4 = (int)((float)arg2[0xc] * fVar2);
    if (0xfe < (ushort)iVar4) {
      iVar4 = 0xff;
    }
  }
  else {
    iVar4 = 0xff;
  }
  arg3[6] = (uchar)iVar4;
  arg3[7] = arg2[0xe];
  arg3[8] = -((arg1 & 2) != 0);
  bVar1 = arg2[2];
  if (bVar1 < 0x80) {
    uVar8 = (ushort)bVar1 * -2 + 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar3 = (uchar)uVar8;
    uVar7 = '\0';
  }
  else {
    uVar8 = (ushort)bVar1 * 2 - 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar7 = (uchar)uVar8;
    uVar3 = '\0';
  }
  arg3[9] = uVar7;
  arg3[10] = uVar3;
  bVar1 = arg2[3];
  if (bVar1 < 0x80) {
    uVar8 = (ushort)bVar1 * -2 + 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar3 = (uchar)uVar8;
    uVar7 = '\0';
  }
  else {
    uVar8 = (ushort)bVar1 * 2 - 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar7 = (uchar)uVar8;
    uVar3 = '\0';
  }
  arg3[0xb] = uVar3;
  arg3[0xc] = uVar7;
  arg3[0xd] = arg2[9];
  arg3[0xe] = arg2[0xb];
  arg3[0xf] = arg2[8];
  arg3[0x10] = arg2[10];
  if (arg2[0xd] < 0xd9) {
    iVar4 = (int)((float)arg2[0xd] * fVar2);
    if (0xfe < (ushort)iVar4) {
      iVar4 = 0xff;
    }
  }
  else {
    iVar4 = 0xff;
  }
  arg3[0x11] = (uchar)iVar4;
  arg3[0x12] = arg2[0xf];
  arg3[0x13] = -((arg1 & 4) != 0);
  bVar1 = *arg2;
  if (bVar1 < 0x80) {
    uVar8 = (ushort)bVar1 * -2 + 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar3 = (uchar)uVar8;
    uVar7 = '\0';
  }
  else {
    uVar8 = (ushort)bVar1 * 2 - 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar7 = (uchar)uVar8;
    uVar3 = '\0';
  }
  arg3[0x14] = uVar7;
  arg3[0x15] = uVar3;
  bVar1 = arg2[1];
  if (bVar1 < 0x80) {
    uVar8 = (ushort)bVar1 * -2 + 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar3 = (uchar)uVar8;
    uVar7 = '\0';
  }
  else {
    uVar8 = (ushort)bVar1 * 2 - 0x100;
    if (0xfd < uVar8) {
      uVar8 = 0xff;
    }
    uVar7 = (uchar)uVar8;
    uVar3 = '\0';
  }
  arg3[0x16] = uVar3;
  arg3[0x17] = uVar7;
  local_res10[0] = 0;
  local_res10[1] = 0;
  uVar9 = 1;
  uVar10 = 2;
  do {
    uVar6 = uVar10 - 2 >> 5;
    if (arg3[uVar10 - 2] < 0x20) {
      uVar5 = ~uVar9 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar9 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 - 1 >> 5;
    if (arg3[uVar10 - 1] < 0x20) {
      uVar5 = ~(uVar9 << 1) & local_res10[uVar6];
    }
    else {
      uVar5 = local_res10[uVar6] | uVar9 << 1;
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar9 << 2 | uVar9 >> 0x1e;
    if (arg3[uVar10] < 0x20) {
      uVar6 = ~uVar6 & local_res10[uVar10 >> 5];
    }
    else {
      uVar6 = uVar6 | local_res10[uVar10 >> 5];
    }
    local_res10[uVar10 >> 5] = uVar6;
    uVar6 = uVar10 + 1 >> 5;
    uVar5 = uVar9 << 3 | uVar9 >> 0x1d;
    if (arg3[uVar10 + 1] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 2 >> 5;
    uVar5 = uVar9 << 4 | uVar9 >> 0x1c;
    if (arg3[uVar10 + 2] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 3 >> 5;
    uVar5 = uVar9 << 5 | uVar9 >> 0x1b;
    if (arg3[uVar10 + 3] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 4 >> 5;
    uVar5 = uVar9 << 6 | uVar9 >> 0x1a;
    if (arg3[uVar10 + 4] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 5 >> 5;
    uVar5 = uVar9 << 7 | uVar9 >> 0x19;
    if (arg3[uVar10 + 5] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 6 >> 5;
    uVar5 = uVar9 << 8 | uVar9 >> 0x18;
    if (arg3[uVar10 + 6] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 7 >> 5;
    uVar5 = uVar9 << 9 | uVar9 >> 0x17;
    if (arg3[uVar10 + 7] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 8 >> 5;
    uVar5 = uVar9 << 10 | uVar9 >> 0x16;
    if (arg3[uVar10 + 8] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 9 >> 5;
    uVar5 = uVar9 << 0xb | uVar9 >> 0x15;
    if (arg3[uVar10 + 9] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 10 >> 5;
    uVar5 = uVar9 << 0xc | uVar9 >> 0x14;
    if (arg3[uVar10 + 10] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 0xb >> 5;
    uVar5 = uVar9 << 0xd | uVar9 >> 0x13;
    if (arg3[uVar10 + 0xb] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 0xc >> 5;
    uVar5 = uVar9 << 0xe | uVar9 >> 0x12;
    if (arg3[uVar10 + 0xc] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 0xd >> 5;
    uVar5 = uVar9 << 0xf | uVar9 >> 0x11;
    if (arg3[uVar10 + 0xd] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 0xe >> 5;
    uVar5 = uVar9 >> 0x10 | uVar9 << 0x10;
    if (arg3[uVar10 + 0xe] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar6 = uVar10 + 0xf >> 5;
    uVar5 = uVar9 >> 0xf | uVar9 << 0x11;
    if (arg3[uVar10 + 0xf] < 0x20) {
      uVar5 = ~uVar5 & local_res10[uVar6];
    }
    else {
      uVar5 = uVar5 | local_res10[uVar6];
    }
    local_res10[uVar6] = uVar5;
    uVar9 = uVar9 << 0x12 | uVar9 >> 0xe;
    uVar6 = uVar10 + 0x10;
    uVar10 = uVar10 + 0x12;
  } while (uVar6 < 0x24);
  *(uint *)(arg3 + 0x24) = local_res10[0];
  *(uint *)(arg3 + 0x28) = local_res10[1];
  return;
}

