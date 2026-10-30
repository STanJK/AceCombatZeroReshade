/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016f550; RVA 0x16f550
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016f550(longlong param_1,longlong *param_2)

{
  char cVar1;
  undefined1 uVar2;
  code *pcVar3;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    if (*(uint *)(param_1 + 0x1c) < 0xf) {
      cVar1 = (*(code *)(&PTR_FUN_140290e70)[*(uint *)(param_1 + 0x1c)])(param_1);
      if (cVar1 != '\0') {
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *(undefined1 *)(param_1 + 0x18) = uVar2;
    if ((DAT_14031e078 != '\0') || (DAT_14031e07c != 0)) {
      DAT_14031e07c = DAT_14031e07c + 1;
    }
    return;
  }
  FUN_1400d1780(*(undefined8 *)(param_1 + 8));
  cVar1 = *(char *)(*(longlong *)(param_1 + 8) + 0xa8822);
  if (cVar1 == '\x04') {
    pcVar3 = FUN_140179d10;
  }
  else if (cVar1 == '\x05') {
    DAT_14031ce30 = 1;
    pcVar3 = FUN_140178620;
  }
  else {
    if ((cVar1 != '\x06') && (cVar1 != '\b')) {
      return;
    }
    pcVar3 = FUN_140178620;
  }
  DAT_14030c8cc = 0;
  (&DAT_140328458)[DAT_14030cab4] = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x00014016f5df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x20))(param_2);
  return;
}

