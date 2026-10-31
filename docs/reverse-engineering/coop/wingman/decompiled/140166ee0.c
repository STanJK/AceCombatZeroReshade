/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140166ee0; RVA 0x166ee0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140166ee0(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = DAT_14032c8f8;
  if (*(char *)(DAT_14032c8f8 + 0x28) != -1) {
    *(char *)(DAT_14032c8f8 + 0x28) = *(char *)(DAT_14032c8f8 + 0x28) + '\x01';
  }
  if (DAT_14032c488 == 0) {
    DAT_14032c488 = FUN_140200de0(lVar1,0x200000,0x10);
    FUN_1401d7b70();
  }
  DAT_14030c8cc = 0;
  (&DAT_140328458)[DAT_14030cab4] = FUN_140178fc0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  _DAT_14031e07c = 0;
  DAT_14031e084 = 0;
  DAT_14031e078 = 1;
  return;
}

