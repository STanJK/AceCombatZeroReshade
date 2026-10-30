/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140201c00; RVA 0x201c00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140201c00(void)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  
  lVar1 = DAT_14032c8f8;
  if (0 < *(int *)(DAT_14032c8f8 + 0x18)) {
    lVar3 = 0;
    plVar2 = *(longlong **)(DAT_14032c8f8 + 0x10);
    do {
      if (*plVar2 == DAT_14032c8d8) {
        *plVar2 = 0;
        plVar2[1] = 0;
        *(undefined1 *)(plVar2 + 2) = 0;
        break;
      }
      lVar3 = lVar3 + 1;
      plVar2 = plVar2 + 3;
    } while (lVar3 < *(int *)(DAT_14032c8f8 + 0x18));
  }
  DAT_14032c8d8 = 0;
  if (0 < *(int *)(lVar1 + 0x18)) {
    lVar3 = 0;
    plVar2 = *(longlong **)(lVar1 + 0x10);
    do {
      if (*plVar2 == DAT_14032c8f0) {
        *plVar2 = 0;
        plVar2[1] = 0;
        *(undefined1 *)(plVar2 + 2) = 0;
        break;
      }
      lVar3 = lVar3 + 1;
      plVar2 = plVar2 + 3;
    } while (lVar3 < *(int *)(lVar1 + 0x18));
  }
  DAT_14032c8f0 = 0;
  if (0 < *(int *)(lVar1 + 0x18)) {
    lVar3 = 0;
    plVar2 = *(longlong **)(lVar1 + 0x10);
    do {
      if (*plVar2 == DAT_14032c8c0) {
        *plVar2 = 0;
        plVar2[1] = 0;
        *(undefined1 *)(plVar2 + 2) = 0;
        break;
      }
      lVar3 = lVar3 + 1;
      plVar2 = plVar2 + 3;
    } while (lVar3 < *(int *)(lVar1 + 0x18));
  }
  DAT_14032c8c0 = 0;
  if (0 < *(int *)(lVar1 + 0x18)) {
    lVar3 = 0;
    plVar2 = *(longlong **)(lVar1 + 0x10);
    do {
      if (*plVar2 == DAT_14032c8d0) {
        *plVar2 = 0;
        plVar2[1] = 0;
        *(undefined1 *)(plVar2 + 2) = 0;
        break;
      }
      lVar3 = lVar3 + 1;
      plVar2 = plVar2 + 3;
    } while (lVar3 < *(int *)(lVar1 + 0x18));
  }
  DAT_14032c8d0 = 0;
  if (0 < *(int *)(lVar1 + 0x18)) {
    lVar3 = 0;
    plVar2 = *(longlong **)(lVar1 + 0x10);
    do {
      if (*plVar2 == DAT_14032c8e0) {
        *plVar2 = 0;
        plVar2[1] = 0;
        *(undefined1 *)(plVar2 + 2) = 0;
        break;
      }
      lVar3 = lVar3 + 1;
      plVar2 = plVar2 + 3;
    } while (lVar3 < *(int *)(lVar1 + 0x18));
  }
  DAT_14032c8e0 = 0;
  if (0 < *(int *)(lVar1 + 0x18)) {
    lVar3 = 0;
    plVar2 = *(longlong **)(lVar1 + 0x10);
    while (*plVar2 != DAT_14032c8e8) {
      lVar3 = lVar3 + 1;
      plVar2 = plVar2 + 3;
      if (*(int *)(lVar1 + 0x18) <= lVar3) {
        DAT_14032c8e8 = 0;
        return;
      }
    }
    *plVar2 = 0;
    plVar2[1] = 0;
    *(undefined1 *)(plVar2 + 2) = 0;
  }
  DAT_14032c8e8 = 0;
  return;
}

