/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016f4c0; RVA 0x16f4c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016f4c0(undefined8 param_1)

{
  undefined8 uVar1;
  longlong unaff_GS_OFFSET;
  
  FUN_1401c56d0();
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  DAT_1437dece0 = DAT_1437dece0 & 0xf7;
  uVar1 = FUN_1401c56d0();
  FUN_1401c5740(uVar1);
  DAT_14031f420 = 0;
  DAT_14031f428 = 0;
  DAT_14031f430 = 0;
  FUN_14016e4c0(param_1);
  return;
}

