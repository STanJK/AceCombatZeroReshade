/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140189320; RVA 0x189320
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined * FUN_140189320(void)

{
  longlong unaff_GS_OFFSET;
  
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437dab74) {
    FUN_14022d540(&DAT_1437dab74);
    if (DAT_1437dab74 == -1) {
      atexit((_func_5014 *)&DAT_1402790e0);
      _Init_thread_footer(&DAT_1437dab74);
    }
  }
  return &DAT_14031eed0;
}

