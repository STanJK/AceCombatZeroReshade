/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401c97a0; RVA 0x1c97a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined * FUN_1401c97a0(void)

{
  longlong unaff_GS_OFFSET;
  
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  return &DAT_1437daf20;
}

