/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016e880; RVA 0x16e880
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016e880(longlong param_1,longlong *param_2)

{
  char cVar1;
  bool bVar2;
  longlong lVar3;
  code *pcVar4;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    DAT_14033bba4 = DAT_14033bba4 + 1;
    if (*(uint *)(param_1 + 0x1c) < 0x12) {
      cVar1 = (*(code *)(&PTR_FUN_140290de0)[*(uint *)(param_1 + 0x1c)])(param_1);
      if (cVar1 != '\0') {
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      }
      bVar2 = false;
    }
    else {
      bVar2 = 0xef < DAT_14033bba4;
    }
    *(bool *)(param_1 + 0x18) = bVar2;
    if ((DAT_14031e078 != '\0') || (DAT_14031e07c != 0)) {
      DAT_14031e07c = DAT_14031e07c + 1;
    }
    return;
  }
  FUN_1400d1780(*(undefined8 *)(param_1 + 8));
  cVar1 = *(char *)(*(longlong *)(param_1 + 8) + 0xa8822);
  if (cVar1 == '\x04') {
    FUN_14018b9b0(&PTR_PTR_14031ce40);
LAB_14016e904:
    pcVar4 = FUN_1401798c0;
  }
  else {
    if (cVar1 == '\x05') {
      DAT_14031ce30 = 1;
      goto LAB_14016e904;
    }
    if (cVar1 != '\x06') {
      if (cVar1 != '\b') {
        return;
      }
      goto LAB_14016e904;
    }
    lVar3 = 0;
    if (DAT_14031ce34 == 1) {
      lVar3 = 2;
    }
    pcVar4 = (code *)(&PTR_FUN_140291248)[lVar3];
    if (pcVar4 == (code *)0x0) goto LAB_14016e928;
  }
  DAT_14030c8cc = 0;
  (&DAT_140328458)[DAT_14030cab4] = pcVar4;
LAB_14016e928:
                    /* WARNING: Could not recover jumptable at 0x00014016e938. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x20))(param_2);
  return;
}

