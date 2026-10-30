/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c51e0; RVA 0xc51e0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c51e0(longlong param_1,byte param_2)

{
  ulonglong uVar1;
  
  *(byte *)(param_1 + 0x279a) = param_2;
  uVar1 = (ulonglong)param_2;
  *(ulonglong *)(param_1 + 0xfd8) = param_1 + (uVar1 * 3 + 0x1f2) * 8;
  if ((*(longlong *)(param_1 + 0x2000 + uVar1 * 8) == 0) ||
     (*(longlong *)(param_1 + 0x2018 + uVar1 * 8) == 0)) {
    return;
  }
  FUN_1400adac0(*(undefined8 *)(param_1 + 0x1890));
  FUN_1400c5010(param_1);
  return;
}

