/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140102540; RVA 0x102540
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140102540(longlong *param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 2);
  if ((short)param_1[1] != 0) {
    *(short *)(param_1 + 1) = (short)param_1[1] + -1;
    *(byte *)(param_1 + 2) = bVar1 & 0xfe;
    return;
  }
  if ((bVar1 & 1) != 0) {
    *(short *)(param_1 + 1) =
         (short)(int)(*(float *)(*param_1 + 0x24) * *(float *)((longlong)param_1 + 0xc) *
                     (float)*(byte *)((longlong)param_1 + 0x11));
    *(byte *)(param_1 + 2) = bVar1 & 0xfe;
  }
  return;
}

