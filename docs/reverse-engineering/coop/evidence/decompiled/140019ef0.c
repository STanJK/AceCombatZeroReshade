/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140019ef0; RVA 0x19ef0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined * FUN_140019ef0(void)

{
  longlong unaff_GS_OFFSET;
  
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437d9f84) {
    FUN_14022d540(&DAT_1437d9f84);
    if (DAT_1437d9f84 == -1) {
      FUN_140019f80(&DAT_14031e980);
      _Init_thread_footer(&DAT_1437d9f84);
      return &DAT_14031e980;
    }
  }
  return &DAT_14031e980;
}

