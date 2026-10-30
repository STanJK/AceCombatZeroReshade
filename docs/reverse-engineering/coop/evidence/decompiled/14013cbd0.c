/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14013cbd0; RVA 0x13cbd0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

int FUN_14013cbd0(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined **local_68;
  int *local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  
  iVar4 = *param_1;
  lVar5 = 0;
  local_68 = &PTR_FUN_1402ac750;
  if (iVar4 < 1) {
    local_58 = 0;
    local_40 = 0;
    local_50 = 0;
    local_48 = 0;
  }
  else {
    if (param_1[1] == 0) {
      local_58 = 0;
    }
    else {
      local_58 = (longlong)param_1[1] + (longlong)param_1;
    }
    if (iVar4 < 2) {
      local_50 = 0;
      local_40 = 0;
      local_48 = 0;
    }
    else {
      if (param_1[2] == 0) {
        local_50 = 0;
      }
      else {
        local_50 = (longlong)param_1[2] + (longlong)param_1;
      }
      if (iVar4 < 3) {
        local_48 = 0;
        local_40 = 0;
      }
      else {
        if (param_1[3] == 0) {
          local_48 = 0;
        }
        else {
          local_48 = (longlong)param_1[3] + (longlong)param_1;
        }
        if (iVar4 < 4) {
          local_40 = 0;
        }
        else if (param_1[4] == 0) {
          local_40 = 0;
        }
        else {
          local_40 = (longlong)param_1[4] + (longlong)param_1;
        }
      }
    }
  }
  local_60 = param_1;
  iVar1 = FUN_140162840(&local_68);
  iVar4 = *param_2;
  if (iVar4 < 1) {
    local_58 = 0;
    local_40 = 0;
    local_50 = 0;
    local_48 = 0;
  }
  else {
    if (param_2[1] == 0) {
      local_58 = 0;
    }
    else {
      local_58 = (longlong)param_2[1] + (longlong)param_2;
    }
    if (iVar4 < 2) {
      local_50 = 0;
      local_40 = 0;
      local_48 = 0;
    }
    else {
      if (param_2[2] == 0) {
        local_50 = 0;
      }
      else {
        local_50 = (longlong)param_2[2] + (longlong)param_2;
      }
      if (iVar4 < 3) {
        local_48 = 0;
        local_40 = 0;
      }
      else {
        if (param_2[3] == 0) {
          local_48 = 0;
        }
        else {
          local_48 = (longlong)param_2[3] + (longlong)param_2;
        }
        if (iVar4 < 4) {
          local_40 = 0;
        }
        else if (param_2[4] == 0) {
          local_40 = 0;
        }
        else {
          local_40 = (longlong)param_2[4] + (longlong)param_2;
        }
      }
    }
  }
  local_60 = param_2;
  iVar2 = FUN_140162840(&local_68);
  iVar4 = *param_3;
  if (iVar4 < 1) {
    local_58 = 0;
    local_40 = 0;
    local_50 = 0;
    local_48 = 0;
  }
  else {
    if (param_3[1] == 0) {
      local_58 = 0;
    }
    else {
      local_58 = (longlong)param_3[1] + (longlong)param_3;
    }
    if (iVar4 < 2) {
      local_50 = 0;
      local_40 = 0;
      local_48 = 0;
    }
    else {
      if (param_3[2] == 0) {
        local_50 = 0;
      }
      else {
        local_50 = (longlong)param_3[2] + (longlong)param_3;
      }
      if (iVar4 < 3) {
        local_48 = 0;
        local_40 = 0;
      }
      else {
        if (param_3[3] == 0) {
          local_48 = 0;
        }
        else {
          local_48 = (longlong)param_3[3] + (longlong)param_3;
        }
        if (iVar4 < 4) {
          local_40 = 0;
        }
        else if (param_3[4] == 0) {
          local_40 = 0;
        }
        else {
          local_40 = (longlong)param_3[4] + (longlong)param_3;
        }
      }
    }
  }
  local_60 = param_3;
  iVar3 = FUN_140162840(&local_68);
  iVar4 = *param_4;
  if (iVar4 < 1) {
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
  }
  else {
    if (param_4[1] == 0) {
      local_58 = 0;
    }
    else {
      local_58 = (longlong)param_4[1] + (longlong)param_4;
    }
    if (iVar4 < 2) {
      local_50 = 0;
      local_48 = 0;
    }
    else {
      if (param_4[2] == 0) {
        local_50 = 0;
      }
      else {
        local_50 = (longlong)param_4[2] + (longlong)param_4;
      }
      if (iVar4 < 3) {
        local_48 = 0;
      }
      else {
        if (param_4[3] == 0) {
          local_48 = 0;
        }
        else {
          local_48 = (longlong)param_4[3] + (longlong)param_4;
        }
        if ((3 < iVar4) && (param_4[4] != 0)) {
          lVar5 = (longlong)param_4 + (longlong)param_4[4];
        }
      }
    }
  }
  local_60 = param_4;
  local_40 = lVar5;
  iVar4 = FUN_140162840(&local_68);
  return iVar4 + iVar1 + iVar2 + iVar3;
}

