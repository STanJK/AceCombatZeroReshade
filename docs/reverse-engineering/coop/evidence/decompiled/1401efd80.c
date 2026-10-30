/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401efd80; RVA 0x1efd80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401efd80(void)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = &DAT_14031dfd0;
  lVar2 = 0x10;
  do {
    if ((longlong *)*plVar1 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar1 + 0x50))();
    }
    plVar1 = plVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (DAT_14031dfc8 != (longlong *)0x0) {
    (**(code **)(*DAT_14031dfc8 + 0x50))();
  }
  return;
}

