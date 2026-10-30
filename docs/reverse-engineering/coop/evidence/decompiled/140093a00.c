/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140093a00; RVA 0x93a00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_140093a00(longlong param_1,byte param_2,byte param_3)

{
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [24];
  
  local_48 = ZEXT816(0);
  local_38 = ZEXT816(0);
  local_28 = local_48;
  local_18._0_16_ = local_38;
  FUN_140202920(local_48,*(longlong *)
                          (*(longlong *)(**(longlong **)(param_1 + 0x10) + (ulonglong)param_2 * 8) +
                          0x110) + 0x268 + (ulonglong)param_3 * 0x520);
  return (float)local_18._4_4_ + (float)local_38._4_4_ < 0.0;
}

