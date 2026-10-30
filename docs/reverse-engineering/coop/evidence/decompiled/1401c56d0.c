/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401c56d0; RVA 0x1c56d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * FUN_1401c56d0(void)

{
  longlong unaff_GS_OFFSET;
  
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437dad18) {
    FUN_14022d540(&DAT_1437dad18);
    if (DAT_1437dad18 == -1) {
      _DAT_1437daef0 = 0;
      _DAT_1437daee0 = _DAT_1402d3500;
      uRam00000001437daee8 = _UNK_1402d3508;
      DAT_1437daef4 = 0;
      _Init_thread_footer(&DAT_1437dad18);
    }
  }
  return &DAT_1437daee0;
}

