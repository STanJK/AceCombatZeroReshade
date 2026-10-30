/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c2630; RVA 0xc2630
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c2630(longlong param_1,char param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0xb6) & 0xfb;
  if (param_2 == '\0') {
    bVar1 = *(byte *)(param_1 + 0xb6) | 4;
  }
  *(byte *)(param_1 + 0xb6) = bVar1;
  bVar1 = *(byte *)(param_1 + 0x95) & 0xfe;
  if (param_2 == '\0') {
    bVar1 = *(byte *)(param_1 + 0x95) | 1;
  }
  *(byte *)(param_1 + 0x95) = bVar1;
  return;
}

