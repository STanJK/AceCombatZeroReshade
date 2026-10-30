/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016d740; RVA 0x16d740
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 * FUN_14016d740(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  
  *(undefined1 *)(param_1 + 5) = 0x3c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = &PTR_FUN_1402ac750;
  param_1[0x10] = &PTR_FUN_1402ac750;
  param_1[0x19] = &PTR_FUN_1402ac750;
  param_1[0x22] = &PTR_FUN_1402ac750;
  puVar1 = param_1 + 0x2b;
  lVar2 = 0x10;
  lVar3 = 0x10;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *(undefined4 *)(puVar1 + 7) = 0;
    puVar1[8] = 0;
    puVar1 = puVar1 + 0xb;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  param_1[0xdb] = 0;
  puVar1 = param_1 + 0xe1;
  param_1[0xdc] = 0;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(undefined4 *)(puVar1 + 6) = 0;
    puVar1[7] = 0;
    puVar1 = puVar1 + 0xb;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  param_1[400] = 0;
  puVar1 = param_1 + 0x19b;
  param_1[0x191] = 0;
  *(undefined4 *)(param_1 + 0xde) = 0xffffffff;
  lVar2 = 0x20;
  *(undefined4 *)(param_1 + 0xdd) = 0;
  lVar3 = 0x20;
  *(undefined4 *)((longlong)param_1 + 0x6ec) = 0x3c;
  *(undefined2 *)((longlong)param_1 + 0x6f4) = 0;
  param_1[0x195] = 0;
  param_1[0x196] = 0;
  param_1[0x197] = 0;
  param_1[0x198] = 0;
  *(undefined1 *)(param_1 + 0x199) = 0x3c;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1 = puVar1 + 7;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  puVar1 = param_1 + 0x280;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1 = puVar1 + 7;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(undefined4 *)(param_1 + 0x27b) = 0;
  *(undefined8 *)((longlong)param_1 + 0x13dc) = 0x3c;
  *(undefined8 *)((longlong)param_1 + 0x13e4) = 0xffffffffffffffff;
  *(undefined2 *)((longlong)param_1 + 0x13ec) = 0xffff;
  param_1[0x194] = 0;
  FUN_14013f8a0(param_1 + 0x362);
  FUN_14013f8a0(param_1 + 0x3fb4);
  *(undefined1 *)(param_1 + 0x3fb2) = 0;
  return param_1;
}

