/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016eb20; RVA 0x16eb20
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016eb20(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined *puVar3;
  uchar local_res8 [8];
  uchar local_res10 [8];
  uchar local_res18 [8];
  uchar local_res20 [8];
  ulonglong in_stack_ffffffffffffffb8;
  byte local_18 [4];
  uchar local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  if (DAT_14031cf18 == '\0') {
    puVar3 = &DAT_140310ec0;
    iVar1 = DAT_140316e20._4_4_;
  }
  else {
    puVar3 = &DAT_140316e78;
    iVar1 = DAT_14031cdd8._4_4_;
  }
  local_18[0] = puVar3[0x24c];
  uVar2 = (ulonglong)local_18[0];
  local_res18[0] = puVar3[0x254];
  local_res10[0] = puVar3[0x25c];
  local_14 = puVar3[uVar2 * 3 + 0x1e0];
  local_13 = puVar3[uVar2 * 3 + 0x1e1];
  local_12 = puVar3[uVar2 * 3 + 0x1e2];
  local_res8[0] = puVar3[0x260];
  local_res20[0] = *(int *)(puVar3 + 0x250) == 10;
  FUN_1400c6a50(*(uchar **)(param_1 + 8),(iVar1 - 0x20U < 10) + '\x01','\x01',local_18,local_res20,
                local_res18,in_stack_ffffffffffffffb8,local_res10,local_res8,&local_14);
  return 1;
}

