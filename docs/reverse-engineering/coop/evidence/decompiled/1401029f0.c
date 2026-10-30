/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401029f0; RVA 0x1029f0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

int FUN_1401029f0(undefined8 param_1,int *param_2)

{
  int iVar1;
  undefined **local_58;
  int *local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
  iVar1 = *param_2;
  local_58 = &PTR_FUN_1402ac750;
  local_30 = 0;
  if (iVar1 < 1) {
    local_48 = 0;
    local_40 = 0;
    local_38 = 0;
  }
  else {
    if (param_2[1] == 0) {
      local_48 = 0;
    }
    else {
      local_48 = (longlong)param_2[1] + (longlong)param_2;
    }
    if (iVar1 < 2) {
      local_40 = 0;
      local_38 = 0;
    }
    else {
      if (param_2[2] == 0) {
        local_40 = 0;
      }
      else {
        local_40 = (longlong)param_2[2] + (longlong)param_2;
      }
      if (iVar1 < 3) {
        local_38 = 0;
      }
      else {
        if (param_2[3] == 0) {
          local_38 = 0;
        }
        else {
          local_38 = (longlong)param_2[3] + (longlong)param_2;
        }
        if ((3 < iVar1) && (param_2[4] != 0)) {
          local_30 = (longlong)param_2 + (longlong)param_2[4];
        }
      }
    }
  }
  local_50 = param_2;
  iVar1 = FUN_140162840(&local_58);
  return iVar1 + 0x48;
}

