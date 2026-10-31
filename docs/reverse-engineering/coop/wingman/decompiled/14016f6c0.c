/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016f6c0; RVA 0x16f6c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016f6c0(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  uchar local_res8 [8];
  uchar local_res10 [8];
  uchar local_res18;
  undefined1 local_res19;
  uchar local_res20;
  undefined1 local_res21;
  ulonglong in_stack_ffffffffffffffb8;
  byte local_18;
  byte local_17;
  uchar local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  
  local_res10[0] = '\0';
  puVar3 = &DAT_140316e78;
  local_res8[0] = '\0';
  if (DAT_14031cf18 == '\0') {
    puVar3 = &DAT_140310ec0;
  }
  local_18 = puVar3[0x24c];
  uVar1 = (ulonglong)local_18;
  local_17 = puVar3[0x250];
  uVar2 = (ulonglong)local_17;
  local_res20 = puVar3[0x254];
  local_res21 = puVar3[600];
  local_res18 = puVar3[0x25c];
  local_res19 = puVar3[0x260];
  local_14 = puVar3[uVar1 * 3 + 0x1e0];
  local_13 = puVar3[uVar1 * 3 + 0x1e1];
  local_12 = puVar3[uVar1 * 3 + 0x1e2];
  local_11 = puVar3[uVar2 * 3 + 0x1e0];
  local_10 = puVar3[uVar2 * 3 + 0x1e1];
  local_f = puVar3[uVar2 * 3 + 0x1e2];
  FUN_1400c6a50(*(uchar **)(param_1 + 8),'\x02','\0',&local_18,local_res10,&local_res20,
                in_stack_ffffffffffffffb8,&local_res18,local_res8,&local_14);
  return 1;
}

