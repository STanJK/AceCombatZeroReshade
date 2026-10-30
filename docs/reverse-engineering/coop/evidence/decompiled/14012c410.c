/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14012c410; RVA 0x12c410
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_14012c410(longlong *param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  longlong lVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_598 [32];
  undefined1 local_578;
  undefined8 local_570;
  undefined1 local_568 [416];
  longlong local_3c8;
  longlong local_3c0;
  ulonglong local_48;
  
  local_48 = DAT_140309040 ^ (ulonglong)auStack_598;
  lVar1 = *param_1;
  iVar5 = 0;
  uVar3 = 0;
  if (((undefined8 *)param_1[1] != (undefined8 *)0x0) &&
     (pbVar2 = *(byte **)param_1[1], pbVar2 != (byte *)0x0)) {
    uVar3 = *pbVar2 + 0xf & 0xfffffff0;
  }
  iVar6 = (uint)*(byte *)(lVar1 + 0xc) * 0x520 + uVar3;
  if (*(byte *)(lVar1 + 0xe) == 0xff) {
    param_3 = 0;
  }
  else {
    param_3 = param_3 + (ulonglong)*(byte *)(lVar1 + 0xe) * 0x28;
  }
  if (*(byte *)(lVar1 + 0xc) != 0) {
    do {
      FUN_14012c1a0(local_568);
      local_3c0 = (longlong)iVar5 * 0x10 + param_1[2];
      local_3c8 = (longlong)iVar5 * 0x38 + param_1[3];
      local_578 = (undefined1)iVar5;
      local_570 = param_4;
      iVar4 = FUN_140113ca0(local_568,param_1[1],param_2,param_3);
      iVar6 = iVar6 + iVar4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(byte *)(lVar1 + 0xc));
  }
  return iVar6;
}

