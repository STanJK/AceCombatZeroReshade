/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016e9b0; RVA 0x16e9b0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016e9b0(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + 0x18) != '\0') {
    FUN_1400d2580(*(undefined8 *)(param_1 + 8));
    return;
  }
  uVar4 = 0;
  if ((*(int *)((longlong)DAT_14032c8b0 + 0xc) == -1) && (0 < (int)DAT_14032c8b0[1])) {
    lVar1 = *DAT_14032c8b0;
    lVar2 = DAT_14032c8b0[3];
    *(undefined4 *)((longlong)DAT_14032c8b0 + 0xc) = 0;
    puVar3 = *(undefined8 **)(lVar1 + 8);
    if (*(char *)(lVar2 + 0x21) == '\0') {
      *(undefined1 *)(lVar2 + 0x21) = 1;
      uVar4 = *(undefined8 *)(lVar2 + 0x10);
    }
    else {
      uVar4 = 0;
    }
    *puVar3 = 0x20000000;
    FUN_140197b30(puVar3,uVar4);
    puVar3[1] = 0;
  }
  uVar4 = FUN_140205050(&PTR_PTR_14031e060,uVar4);
  FUN_1402011a0(DAT_14032c8b0,uVar4);
  return;
}

