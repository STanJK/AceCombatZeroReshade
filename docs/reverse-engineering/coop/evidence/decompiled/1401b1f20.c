/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b1f20; RVA 0x1b1f20
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401b1f20(void)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  if ((((DAT_1402d2ad8 <= *(float *)(lVar1 + 600)) && (*(float *)(lVar1 + 600) <= DAT_1402d2aec)) &&
      (*(float *)(lVar1 + 0x25c) <= DAT_1402d2a4c)) && (DAT_14030caf0 <= *(float *)(lVar1 + 0x260)))
  {
    return *(float *)(lVar1 + 0x260) <= DAT_14030cb94;
  }
  return false;
}

