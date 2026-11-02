/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14020eeb0; RVA 0x20eeb0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14020eeb0(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 auStack_48 [32];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  ulonglong local_18;
  
  local_18 = DAT_140309040 ^ (ulonglong)auStack_48;
  if ((((param_1 != DAT_14031e0d0) || (param_2 != DAT_14031e0d4)) || (param_3 != DAT_14031e0d8)) ||
     (param_4 != DAT_14031e0dc)) {
    DAT_14031e0d0 = param_1;
    DAT_14031e0d4 = param_2;
    DAT_14031e0d8 = param_3;
    DAT_14031e0dc = param_4;
    if ((-1 < param_1) && (-1 < param_2)) {
      local_28 = param_1;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      (**(code **)(**(longlong **)(DAT_14033da48 + 0x10) + 0xb0))
                (*(longlong **)(DAT_14033da48 + 0x10),1,&local_28);
    }
  }
  return;
}

