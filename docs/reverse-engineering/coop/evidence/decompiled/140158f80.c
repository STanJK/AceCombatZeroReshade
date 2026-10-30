/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140158f80; RVA 0x158f80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140158f80(longlong param_1,int param_2)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  
  if (param_2 == 0) {
    lVar3 = 0;
    if ((*(ushort *)(param_1 + 0xa8) < 0x36) || (*(ushort *)(param_1 + 0xaa) < 0x36)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xd4);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1a8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0xa8) < 0x37) || (*(ushort *)(param_1 + 0xaa) < 0x37)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xd8);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1b0);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0xa8) < 0x38) || (*(ushort *)(param_1 + 0xaa) < 0x38)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xdc);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1b8);
    }
    if (0 < iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x36) || (*(ushort *)(param_1 + 0x3aa) < 0x36)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xd4);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1a8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x37) || (*(ushort *)(param_1 + 0x3aa) < 0x37)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xd8);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1b0);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x38) || (*(ushort *)(param_1 + 0x3aa) < 0x38)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xdc);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1b8);
    }
    if (0 < iVar4) {
      do {
        lVar5 = lVar3 * 2;
        lVar3 = lVar3 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar5) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 | 2;
      } while (lVar3 < iVar4);
    }
  }
  else if (param_2 == 1) {
    lVar3 = 0;
    if ((*(ushort *)(param_1 + 0xa8) < 0x37) || (*(ushort *)(param_1 + 0xaa) < 0x37)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xd8);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1b0);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0xa8) < 0x36) || (*(ushort *)(param_1 + 0xaa) < 0x36)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xd4);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1a8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0xa8) < 0x38) || (*(ushort *)(param_1 + 0xaa) < 0x38)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xdc);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1b8);
    }
    if (0 < iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x37) || (*(ushort *)(param_1 + 0x3aa) < 0x37)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xd8);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1b0);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x36) || (*(ushort *)(param_1 + 0x3aa) < 0x36)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xd4);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1a8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x38) || (*(ushort *)(param_1 + 0x3aa) < 0x38)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xdc);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1b8);
    }
    if (0 < iVar4) {
      do {
        lVar5 = lVar3 * 2;
        lVar3 = lVar3 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar5) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 | 2;
      } while (lVar3 < iVar4);
    }
  }
  else if (param_2 == 2) {
    lVar3 = 0;
    if ((*(ushort *)(param_1 + 0xa8) < 0x38) || (*(ushort *)(param_1 + 0xaa) < 0x38)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xdc);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1b8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0xa8) < 0x36) || (*(ushort *)(param_1 + 0xaa) < 0x36)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xd4);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1a8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0xa8) < 0x37) || (*(ushort *)(param_1 + 0xaa) < 0x37)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0xb0) + 0xd8);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x1b0);
    }
    if (0 < iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0xa0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x38) || (*(ushort *)(param_1 + 0x3aa) < 0x38)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xdc);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1b8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x36) || (*(ushort *)(param_1 + 0x3aa) < 0x36)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xd4);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1a8);
    }
    if (0 < (longlong)iVar4) {
      lVar5 = 0;
      do {
        lVar1 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar1) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
    if ((*(ushort *)(param_1 + 0x3a8) < 0x37) || (*(ushort *)(param_1 + 0x3aa) < 0x37)) {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(param_1 + 0x3b0) + 0xd8);
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x3b8) + 0x1b0);
    }
    if (0 < iVar4) {
      do {
        lVar5 = lVar3 * 2;
        lVar3 = lVar3 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar6 + lVar5) * 800 + 0x31c +
                         *(longlong *)(param_1 + 0x3a0));
        *puVar2 = *puVar2 | 2;
      } while (lVar3 < iVar4);
    }
  }
  return;
}

