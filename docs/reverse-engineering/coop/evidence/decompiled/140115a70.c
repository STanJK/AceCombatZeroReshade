/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140115a70; RVA 0x115a70
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140115a70(longlong param_1)

{
  longlong lVar1;
  longlong unaff_GS_OFFSET;
  
  if (*(longlong **)(param_1 + 0x340) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x340) + 8))();
    lVar1 = *(longlong *)(param_1 + 0x340);
    *(undefined4 *)(lVar1 + 0x4c) = *(undefined4 *)(param_1 + 600);
    *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_1 + 0x25c);
    *(undefined4 *)(lVar1 + 0x54) = *(undefined4 *)(param_1 + 0x260);
    *(undefined4 *)(lVar1 + 0x58) = *(undefined4 *)(param_1 + 0x264);
    lVar1 = *(longlong *)(param_1 + 0x340);
    *(undefined4 *)(lVar1 + 0x5c) = *(undefined4 *)(param_1 + 0x268);
    *(undefined4 *)(lVar1 + 0x60) = *(undefined4 *)(param_1 + 0x26c);
    *(undefined4 *)(lVar1 + 100) = *(undefined4 *)(param_1 + 0x270);
    *(undefined4 *)(lVar1 + 0x68) = *(undefined4 *)(param_1 + 0x274);
  }
  FUN_1401c56d0();
  lVar1 = **(longlong **)(unaff_GS_OFFSET + 0x58);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x348);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x34c);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x350);
  *(undefined4 *)(param_1 + 0x354) = 0;
  *(undefined1 *)(param_1 + 0x42c) = 0;
  return;
}

