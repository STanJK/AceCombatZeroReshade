/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a56d0; RVA 0xa56d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a56d0(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int *piVar4;
  longlong unaff_GS_OFFSET;
  
  FUN_1401c56d0();
  plVar1 = *(longlong **)(unaff_GS_OFFSET + 0x58);
  lVar3 = 0x10;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  piVar4 = (int *)(*plVar1 + 4);
  *(undefined2 *)(param_1 + 100) = 0;
  *(undefined2 *)(param_1 + 0x7c) = 0xffff;
  puVar2 = (undefined8 *)(param_1 + 0x4cc);
  do {
    if (*piVar4 < DAT_1437daf04) {
      FUN_14022d540(&DAT_1437daf04);
      if (DAT_1437daf04 == -1) {
        FUN_1401c93c0();
        _Init_thread_footer(&DAT_1437daf04);
      }
    }
    FUN_1401cb010(&DAT_1437daf20,(longlong)puVar2 + 4);
    if (*piVar4 < DAT_1437daf04) {
      FUN_14022d540(&DAT_1437daf04);
      if (DAT_1437daf04 == -1) {
        FUN_1401c93c0();
        _Init_thread_footer(&DAT_1437daf04);
      }
    }
    FUN_1401cb010(&DAT_1437daf20,puVar2);
    *puVar2 = 0;
    puVar2 = puVar2 + 0x15;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}

