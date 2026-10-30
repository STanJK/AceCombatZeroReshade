/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14014b4c0; RVA 0x14b4c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14014b4c0(longlong param_1,int param_2)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  
  if (param_2 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x68);
    lVar5 = 0;
    if ((*(ushort *)(lVar3 + 0x98) < 0x36) || (*(ushort *)(lVar3 + 0x9a) < 0x36)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xd4);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1a8);
    }
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar1) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar6 < iVar4);
    }
    lVar3 = *(longlong *)(param_1 + 0x68);
    if ((*(ushort *)(lVar3 + 0x98) < 0x37) || (*(ushort *)(lVar3 + 0x9a) < 0x37)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xd8);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1b0);
    }
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar1) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 | 2;
      } while (lVar6 < iVar4);
    }
    lVar3 = *(longlong *)(param_1 + 0x68);
    if ((*(ushort *)(lVar3 + 0x98) < 0x38) || (*(ushort *)(lVar3 + 0x9a) < 0x38)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xdc);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1b8);
    }
    if (0 < iVar4) {
      do {
        lVar6 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar6) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
    }
  }
  else if (param_2 == 1) {
    lVar3 = *(longlong *)(param_1 + 0x68);
    lVar5 = 0;
    if ((*(ushort *)(lVar3 + 0x98) < 0x37) || (*(ushort *)(lVar3 + 0x9a) < 0x37)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xd8);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1b0);
    }
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar1) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar6 < iVar4);
    }
    lVar3 = *(longlong *)(param_1 + 0x68);
    if ((*(ushort *)(lVar3 + 0x98) < 0x36) || (*(ushort *)(lVar3 + 0x9a) < 0x36)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xd4);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1a8);
    }
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar1) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 | 2;
      } while (lVar6 < iVar4);
    }
    lVar3 = *(longlong *)(param_1 + 0x68);
    if ((*(ushort *)(lVar3 + 0x98) < 0x38) || (*(ushort *)(lVar3 + 0x9a) < 0x38)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xdc);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1b8);
    }
    if (0 < iVar4) {
      do {
        lVar6 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar6) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
      return;
    }
  }
  else if (param_2 == 2) {
    lVar3 = *(longlong *)(param_1 + 0x68);
    lVar5 = 0;
    if ((*(ushort *)(lVar3 + 0x98) < 0x38) || (*(ushort *)(lVar3 + 0x9a) < 0x38)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xdc);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1b8);
    }
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar1) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 & 0xfffffffd;
      } while (lVar6 < iVar4);
    }
    lVar3 = *(longlong *)(param_1 + 0x68);
    if ((*(ushort *)(lVar3 + 0x98) < 0x36) || (*(ushort *)(lVar3 + 0x9a) < 0x36)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xd4);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1a8);
    }
    if (0 < iVar4) {
      lVar6 = 0;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar1) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 | 2;
      } while (lVar6 < iVar4);
    }
    lVar3 = *(longlong *)(param_1 + 0x68);
    if ((*(ushort *)(lVar3 + 0x98) < 0x37) || (*(ushort *)(lVar3 + 0x9a) < 0x37)) {
      iVar4 = 0;
      lVar7 = 0;
    }
    else {
      iVar4 = *(int *)(*(longlong *)(lVar3 + 0xa0) + 0xd8);
      lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0x1b0);
    }
    if (0 < iVar4) {
      do {
        lVar6 = lVar5 * 2;
        lVar5 = lVar5 + 1;
        puVar2 = (uint *)((ulonglong)*(ushort *)(lVar7 + lVar6) * 800 + 0x31c +
                         *(longlong *)(lVar3 + 0x90));
        *puVar2 = *puVar2 | 2;
      } while (lVar5 < iVar4);
      return;
    }
  }
  return;
}

