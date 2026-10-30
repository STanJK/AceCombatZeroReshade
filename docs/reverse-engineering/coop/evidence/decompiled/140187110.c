/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140187110; RVA 0x187110
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_140187110(int param_1,undefined4 param_2)

{
  longlong *plVar1;
  
  plVar1 = &DAT_14033bc00;
  if (param_1 != -1) {
    if (*(longlong *)((&DAT_14033bc00)[param_1] + 8) != 0) {
      FUN_140186bb0();
    }
    return 0;
  }
  do {
    if (*(longlong *)(*plVar1 + 8) != 0) {
      FUN_140186bb0(*(longlong *)(*plVar1 + 8),param_2);
    }
    plVar1 = plVar1 + 1;
  } while ((longlong)plVar1 < 0x14033bc50);
  return 0;
}

