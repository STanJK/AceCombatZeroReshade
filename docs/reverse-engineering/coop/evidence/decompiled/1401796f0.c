/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401796f0; RVA 0x1796f0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401796f0(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,0x20,0x10);
  *param_1 = puVar1;
  *puVar1 = &PTR_FUN_1402b3f90;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined1 *)(puVar1 + 3) = 0;
  *(undefined4 *)((longlong)puVar1 + 0x1c) = 0;
  DAT_14033bba4 = 0;
  return;
}

