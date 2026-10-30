/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1402014c0; RVA 0x2014c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined * FUN_1402014c0(void)

{
  longlong unaff_GS_OFFSET;
  
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437df52c) {
    FUN_14022d540(&DAT_1437df52c);
    if (DAT_1437df52c == -1) {
      FUN_140201220();
      atexit(FUN_140279ee0);
      _Init_thread_footer(&DAT_1437df52c);
    }
  }
  return &DAT_1437df540;
}

