/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140166f80; RVA 0x166f80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140166f80(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = &DAT_14031dfd0;
  lVar3 = 0x10;
  do {
    plVar1 = (longlong *)*plVar2;
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))(plVar1,0);
    }
    plVar2 = plVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if (DAT_14031dfc8 != (longlong *)0x0) {
    (**(code **)(*DAT_14031dfc8 + 0x10))(DAT_14031dfc8,0);
  }
  DAT_14031dfc8 = (longlong *)0x0;
  if (0 < *(int *)(param_1 + 0x10)) {
    FUN_1401f6b40(param_1 + 0x70);
    FUN_1401ef180(param_1 + 0x38);
    FUN_1401cba00(param_1 + 0x20);
  }
  if (DAT_14032c488 != 0) {
    if (0 < *(int *)(DAT_14032c8f8 + 0x18)) {
      plVar2 = *(longlong **)(DAT_14032c8f8 + 0x10);
      lVar3 = 0;
      do {
        if (*plVar2 == DAT_14032c488) {
          *plVar2 = 0;
          plVar2[1] = 0;
          *(undefined1 *)(plVar2 + 2) = 0;
          break;
        }
        lVar3 = lVar3 + 1;
        plVar2 = plVar2 + 3;
      } while (lVar3 < *(int *)(DAT_14032c8f8 + 0x18));
    }
    DAT_14032c488 = 0;
  }
  FUN_140202100();
  return;
}

