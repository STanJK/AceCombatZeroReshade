/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d1110; RVA 0xd1110
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400d1110(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  int iVar9;
  longlong lVar10;
  
  DAT_140326f80 = 1;
  iVar9 = 0;
  if (*(char *)(param_1 + 0x697ec) != '\0') {
    lVar10 = 0;
    do {
      lVar8 = 0;
      lVar7 = (longlong)*(int *)(*(longlong *)(lVar10 + *(longlong *)(param_1 + 0x697b8)) + 0x118);
      if (0 < lVar7) {
        do {
          lVar3 = *(longlong *)(*(longlong *)(lVar10 + *(longlong *)(param_1 + 0x697b8)) + 0x110);
          if ((*(char *)(lVar3 + 0x234 + lVar8) == '\0') &&
             (*(char *)(lVar3 + 0x235 + lVar8) == '\0')) {
            lVar4 = *(longlong *)(lVar3 + 0x1b8 + lVar8);
            uVar2 = *(uint *)(lVar4 + 0xd48);
            if ((uVar2 >> 0x10 & 1) != 0) {
              *(undefined1 *)(lVar4 + 0xc3b) = 3;
            }
            if ((uVar2 >> 0x11 & 1) != 0) {
              *(undefined1 *)(lVar4 + 0xc3c) = 3;
            }
            if ((uVar2 >> 0x12 & 1) != 0) {
              *(undefined1 *)(lVar4 + 0xc3d) = 3;
            }
          }
          lVar4 = *(longlong *)(lVar3 + 0x3c8 + lVar8);
          if (lVar4 != 0) {
            lVar5 = *(longlong *)(lVar4 + 0x78);
            *(undefined4 *)(lVar4 + 0x2c) = 0;
            *(undefined1 *)(lVar4 + 0x20) = 1;
            *(undefined4 *)(lVar4 + 0x34) = 0xffffffff;
            *(undefined8 *)(lVar4 + 0x38) = 0;
            *(undefined8 *)(lVar4 + 0x50) = 0;
            if (lVar5 != 0) {
              *(undefined8 *)(lVar5 + 4) = 0;
              *(undefined1 *)(lVar5 + 0x1c) = 0;
            }
            puVar1 = (uint *)(*(longlong *)(lVar4 + 0x58) + 0x1f0);
            *puVar1 = *puVar1 & 0xfffffffc;
            lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x58) + 0x3a8);
            if ((lVar5 != 0) &&
               ((*(longlong *)(lVar5 + 0x1b8) != 0 || (*(longlong *)(lVar5 + 0x1c0) != 0)))) {
              uVar6 = FUN_140011290(lVar4 + 0x500);
              *(undefined8 *)(lVar4 + 0x88) = uVar6;
            }
            lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x3c8 + lVar8) + 0x80);
            if (lVar3 != 0) {
              *(undefined2 *)(lVar3 + 0x52) = 0;
            }
          }
          lVar8 = lVar8 + 0x520;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
      }
      iVar9 = iVar9 + 1;
      lVar10 = lVar10 + 8;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x697ec));
  }
  FUN_14000e850(param_1 + 0x697b8,*(undefined1 *)(param_1 + 0xa87e0));
  return;
}

