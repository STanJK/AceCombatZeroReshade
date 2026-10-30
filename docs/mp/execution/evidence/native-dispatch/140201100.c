/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140201100; RVA 0x201100
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140201100(longlong param_1)

{
  if (*(int *)(param_1 + 0x48) < 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140201110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 8 + (longlong)*(int *)(param_1 + 0x48) * 8) + 0x28))();
  return;
}

