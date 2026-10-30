/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401788d0; RVA 0x1788d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 * FUN_1401788d0(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,0x3c8,0x10);
  *param_1 = puVar1;
  FUN_1402777e0(puVar1,0,0x3c8);
  puVar1[2] = &PTR_FUN_1402cbb50;
  puVar1[3] = &PTR_FUN_1402c8518;
  puVar1[6] = &PTR_FUN_1402cbb20;
  puVar1[0xd] = &PTR_FUN_1402cd410;
  puVar1[0x12] = &PTR_FUN_1402cdd80;
  *puVar1 = &PTR_FUN_1402bcd00;
  puVar1[1] = &PTR_LAB_1402bd5e8;
  *(undefined4 *)(puVar1 + 0x13) = 0x20;
  return puVar1;
}

