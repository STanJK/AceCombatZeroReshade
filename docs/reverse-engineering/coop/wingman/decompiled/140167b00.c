/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140167b00; RVA 0x167b00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140167b00(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar5 = 0;
    if ((*(int *)((longlong)DAT_14032c8b0 + 0xc) == -1) && (0 < (int)DAT_14032c8b0[1])) {
      lVar1 = DAT_14032c8b0[3];
      lVar2 = *DAT_14032c8b0;
      *(undefined4 *)((longlong)DAT_14032c8b0 + 0xc) = 0;
      puVar3 = *(undefined8 **)(lVar2 + 8);
      if (*(char *)(lVar1 + 0x21) == '\0') {
        *(undefined1 *)(lVar1 + 0x21) = 1;
        uVar5 = *(undefined8 *)(lVar1 + 0x10);
      }
      else {
        uVar5 = 0;
      }
      *puVar3 = 0x20000000;
      FUN_140197b30(puVar3,uVar5);
      puVar3[1] = 0;
    }
    uVar5 = FUN_140205050(&PTR_PTR_14031e060,uVar5);
  }
  else {
    if (*(int *)(param_1 + 0x10) != 1) {
      return;
    }
    if (*(int *)((longlong)DAT_14032c8b0 + 0xc) == -1) {
      if ((int)DAT_14032c8b0[1] < 1) {
        uVar5 = 0;
      }
      else {
        lVar1 = DAT_14032c8b0[3];
        lVar2 = *DAT_14032c8b0;
        *(undefined4 *)((longlong)DAT_14032c8b0 + 0xc) = 0;
        puVar3 = *(undefined8 **)(lVar2 + 8);
        if (*(char *)(lVar1 + 0x21) == '\0') {
          *(undefined1 *)(lVar1 + 0x21) = 1;
          uVar5 = *(undefined8 *)(lVar1 + 0x10);
        }
        else {
          uVar5 = 0;
        }
        *puVar3 = 0x20000000;
        FUN_140197b30(puVar3,uVar5);
        puVar3[1] = 0;
      }
    }
    else {
      uVar5 = 0;
    }
    uVar5 = FUN_14015b6f0(param_1 + 0xa0,uVar5);
    if (*(longlong *)(param_1 + 0x28) != 0) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x30) = uVar5;
      pcVar4 = *(char **)(param_1 + 0x28);
      if ((*pcVar4 == '\0') && (*(longlong **)(pcVar4 + 0x1b8) != (longlong *)0x0)) {
        (**(code **)(**(longlong **)(pcVar4 + 0x1b8) + 0x10))();
        pcVar4[0x218] = '\0';
        pcVar4[0x219] = '\0';
        pcVar4[0x21a] = '\0';
        pcVar4[0x21b] = '\0';
        pcVar4[0x21c] = '\0';
        pcVar4[0x21d] = '\0';
        pcVar4[0x21e] = '\0';
        pcVar4[0x21f] = '\0';
        FUN_1401fac80(*(undefined8 *)(pcVar4 + 0x1e0));
        (**(code **)(**(longlong **)(pcVar4 + 0x1b8) + 0x50))();
      }
      uVar5 = *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x30);
      *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x30) = 0;
    }
    if (*(char *)(param_1 + 0x2a38) != '\0') {
      uVar5 = FUN_1401c5140(param_1 + 0x2a40,uVar5);
    }
  }
  FUN_1402011a0(DAT_14032c8b0,uVar5);
  return;
}

