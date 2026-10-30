/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140187390; RVA 0x187390
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140187390(longlong param_1)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  
  uVar3 = *(uint *)(param_1 + 0x24);
  puVar1 = (uint *)(param_1 + 0x28);
  if ((*(uint *)(param_1 + 0x38) == uVar3) && (*(uint *)(param_1 + 0x3c) == *puVar1)) {
    bVar2 = *(byte *)(param_1 + 0x30);
    bVar5 = *(byte *)(param_1 + 0x32);
    if ((uint)bVar5 < (uint)bVar2 + (uint)*(byte *)(param_1 + 0x31) * 10) {
      if (bVar5 < bVar2) {
        *(undefined8 *)(param_1 + 0x48) = 0;
      }
      else {
        uVar4 = *puVar1;
        if ((uint)bVar5 % (uint)*(byte *)(param_1 + 0x31) != 0) {
          uVar3 = 0;
          uVar4 = uVar3;
        }
        *(uint *)(param_1 + 0x48) = uVar3;
        *(uint *)(param_1 + 0x4c) = uVar4;
      }
    }
    else {
      *(byte *)(param_1 + 0x32) = bVar2;
      bVar5 = bVar2;
    }
    cVar6 = bVar5 + 1;
  }
  else {
    *(uint *)(param_1 + 0x48) = (uVar3 ^ *(uint *)(param_1 + 0x38)) & uVar3;
    cVar6 = '\0';
    *(uint *)(param_1 + 0x4c) = (*puVar1 ^ *(uint *)(param_1 + 0x3c)) & *puVar1;
  }
  *(char *)(param_1 + 0x32) = cVar6;
  uVar3 = *(uint *)(param_1 + 0x24);
  uVar4 = *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x40) = (uVar3 ^ *(uint *)(param_1 + 0x38)) & uVar3;
  *(uint *)(param_1 + 0x38) = uVar3;
  *(uint *)(param_1 + 0x44) = (uVar4 ^ *(uint *)(param_1 + 0x3c)) & uVar4;
  *(uint *)(param_1 + 0x3c) = uVar4;
  return;
}

