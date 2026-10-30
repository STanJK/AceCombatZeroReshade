/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d5680; RVA 0xd5680
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400d5680(longlong param_1,char param_2)

{
  ushort *puVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  
  if (param_2 == '\0') {
    iVar4 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      lVar5 = 0;
      do {
        lVar2 = *(longlong *)(param_1 + 0xa8248);
        lVar5 = lVar5 + 0x27a0;
        iVar4 = iVar4 + 1;
        lVar3 = *(longlong *)(lVar2 + -0xf28 + lVar5);
        *(undefined1 *)(*(longlong *)(lVar3 + 0x30) + 0x36) = 0;
        *(undefined1 *)(*(longlong *)(lVar3 + 0x38) + 0x36) = 0;
        puVar1 = (ushort *)(lVar2 + -0xb80 + lVar5);
        *puVar1 = *puVar1 & 0xfeff;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      return;
    }
  }
  else if ((param_2 == '\x01') && (iVar4 = 0, *(char *)(param_1 + 0xa87e4) != '\0')) {
    lVar5 = 0;
    do {
      lVar2 = *(longlong *)(param_1 + 0xa8248);
      lVar5 = lVar5 + 0x27a0;
      iVar4 = iVar4 + 1;
      lVar3 = *(longlong *)(lVar2 + -0xf28 + lVar5);
      *(undefined1 *)(*(longlong *)(lVar3 + 0x30) + 0x36) = 1;
      *(undefined1 *)(*(longlong *)(lVar3 + 0x38) + 0x36) = 1;
      puVar1 = (ushort *)(lVar2 + -0xb80 + lVar5);
      *puVar1 = *puVar1 | 0x100;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  return;
}

