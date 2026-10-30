/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400aac80; RVA 0xaac80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400aac80(longlong param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 0x4a8) = *param_2;
  *(undefined4 *)(param_1 + 0x4ac) = param_2[1];
  *(undefined4 *)(param_1 + 0x4b0) = param_2[2];
  *(undefined4 *)(param_1 + 0x4b4) = param_2[3];
  *(undefined4 *)(param_1 + 0x4b8) = *param_3;
  *(undefined4 *)(param_1 + 0x4bc) = param_3[1];
  *(undefined4 *)(param_1 + 0x4c0) = param_3[2];
  *(undefined4 *)(param_1 + 0x4c4) = param_3[3];
  return;
}

