/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a4980; RVA 0xa4980
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ulonglong FUN_1400a4980(longlong param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = (ulonglong)(int)*param_2;
  if (*param_2 < 0x10) {
    lVar3 = uVar2 * 0xa8;
    lVar1 = *(longlong *)(lVar3 + 0x478 + param_1);
    uVar2 = 0;
    if (lVar1 != 0) {
      *(float *)(lVar3 + 0x48c + param_1) = *(float *)(lVar1 + 0x28) * DAT_1402d236c;
      return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}

