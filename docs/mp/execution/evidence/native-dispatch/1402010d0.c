/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1402010d0; RVA 0x2010d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1402010d0(longlong param_1)

{
  longlong *plVar1;
  
  if (*(int *)(param_1 + 0x48) < 0) {
    return 0;
  }
  plVar1 = *(longlong **)(param_1 + 8 + (longlong)*(int *)(param_1 + 0x48) * 8);
  (**(code **)(*plVar1 + 0x20))(plVar1,param_1);
  return 1;
}

