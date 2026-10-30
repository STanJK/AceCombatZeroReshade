/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016ff00; RVA 0x16ff00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14016ff00(longlong param_1,longlong *param_2)

{
  undefined *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  
  lVar2 = DAT_14032c8f8;
  if (*(char *)(DAT_14032c8f8 + 0x28) != -1) {
    *(char *)(DAT_14032c8f8 + 0x28) = *(char *)(DAT_14032c8f8 + 0x28) + '\x01';
  }
  iVar4 = (int)DAT_140316e20;
  if (DAT_14031cf18 != '\0') {
    iVar4 = (int)DAT_14031cdd8;
  }
  *(int *)(param_1 + 8) = iVar4;
  iVar5 = DAT_140316e28;
  if (DAT_14031cf18 != '\0') {
    iVar5 = DAT_14031cde0;
  }
  lVar6 = (ulonglong)(iVar4 == 0x10) + 2;
  if (iVar4 == 0x11) {
    lVar6 = (ulonglong)(iVar5 != 0) + 3;
  }
  if (DAT_14031ce34 == 1) {
    lVar6 = 2;
  }
  puVar3 = (undefined8 *)FUN_140200de0(lVar2,0x18,0x10);
  puVar1 = (&PTR_FUN_140291048)[lVar6];
  iVar4 = DAT_14030cab4 + 1;
  DAT_14030cab4 = iVar4;
  *puVar3 = &PTR_FUN_1402ba0f0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  if (puVar1 != (undefined *)0x0) {
    DAT_14030c8cc = 0;
    (&DAT_140328458)[iVar4] = puVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00014016ffec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x18))(param_2);
  return;
}

