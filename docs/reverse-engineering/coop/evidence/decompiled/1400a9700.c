/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a9700; RVA 0xa9700
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ulonglong FUN_1400a9700(longlong param_1,char param_2,char param_3)

{
  char *pcVar1;
  uint uVar2;
  
  pcVar1 = (char *)(param_1 + 0x489);
  uVar2 = 0;
  while ((((*(uint *)(param_1 + 0x5c) >> (uVar2 & 0x1f) & 1) == 0 || (pcVar1[-1] != param_2)) ||
         (*pcVar1 != param_3))) {
    uVar2 = uVar2 + 1;
    pcVar1 = pcVar1 + 0xa8;
    if (0xf < (int)uVar2) {
      return (ulonglong)pcVar1 & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)((ulonglong)pcVar1 >> 8),1);
}

