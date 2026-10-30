/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016fff0; RVA 0x16fff0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016fff0(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (DAT_14031cf18 == '\0') {
    puVar4 = &DAT_140316e28;
    piVar3 = (int *)&DAT_140316e20;
    iVar5 = (int)DAT_140316e20;
  }
  else {
    puVar4 = &DAT_14031cde0;
    piVar3 = (int *)&DAT_14031cdd8;
    iVar5 = (int)DAT_14031cdd8;
  }
  if (DAT_14031ce34 == 1) {
    FUN_14018c6c0(&PTR_PTR_14031ce40,1);
    DAT_14030c8cc = 0;
    (&DAT_140328458)[DAT_14030cab4] = FUN_140178560;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
    lVar2 = (longlong)DAT_14030cab4;
    DAT_14030c8cc = 0;
    (&DAT_140328458)[lVar2] = FUN_140178530;
    if (iVar1 == 0xf) {
      DAT_14031cf08 = DAT_14031cf08 | 0x4000;
    }
    if (*(int *)(param_1 + 8) == 0x10) {
      FUN_14018c6c0(&PTR_PTR_14031ce40,0);
      DAT_14031cf08 = DAT_14031cf08 | 0x4000;
      *piVar3 = *piVar3 + 1;
      *puVar4 = 0;
    }
    else {
      if (*(int *)(param_1 + 8) == 0x11) {
        if (piVar3[2] == 0) {
          FUN_14018c6c0(&PTR_PTR_14031ce40,1);
          *puVar4 = 1;
          goto LAB_140170104;
        }
      }
      else if (iVar5 < 0x13) goto LAB_140170104;
      (&DAT_140328458)[lVar2] = FUN_1401782b0;
    }
  }
LAB_140170104:
                    /* WARNING: Could not recover jumptable at 0x000140170119. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x20))(param_2);
  return;
}

