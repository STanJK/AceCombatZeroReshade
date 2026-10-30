/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401c9e60; RVA 0x1c9e60
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ushort * FUN_1401c9e60(ushort *param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  
  iVar3 = 0;
  while( true ) {
    uVar4 = param_1[0x1ede] + 1;
    if (0x7e < (short)param_1[0x1ede]) {
      uVar4 = 0;
    }
    param_1[0x1ede] = uVar4;
    puVar1 = param_1 + (longlong)(short)uVar4 * 0x3c + 0xd0;
    uVar2 = *(uint *)(puVar1 + 0x1c);
    if (uVar2 == 0) break;
    if (0x7f < (ushort)uVar2) break;
    uVar5 = (ushort)(uVar2 >> 0x10);
    if (uVar5 != param_1[(ulonglong)(uVar2 & 0xffff) + 1]) {
      if (((ushort)uVar2 < 0x80) && (uVar5 == param_1[(ulonglong)(uVar2 & 0xffff) + 1])) {
        return puVar1;
      }
      break;
    }
    iVar3 = iVar3 + 1;
    if (0x7f < iVar3) {
      return (ushort *)0x0;
    }
  }
  uVar5 = *param_1 + 1;
  if (0xfffd < *param_1) {
    uVar5 = 1;
  }
  *param_1 = uVar5;
  param_1[(longlong)(short)uVar4 + 1] = uVar5;
  puVar1[0x1d] = *param_1;
  puVar1[0x1c] = uVar4;
  return puVar1;
}

