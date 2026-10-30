/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d55c0; RVA 0xd55c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400d55c0(longlong param_1,byte param_2,char param_3)

{
  undefined1 *puVar1;
  longlong lVar2;
  longlong lVar3;
  
  *(char *)((ulonglong)param_2 * 0x27a0 + 0x20b0 + *(longlong *)(param_1 + 0xa8248)) = param_3;
  lVar2 = 3;
  lVar3 = (ulonglong)param_2 * 0xa8 + DAT_14032c8f0;
  puVar1 = (undefined1 *)(lVar3 + 0x2f);
  do {
    if (param_3 == '\0') {
      puVar1[-2] = 0x16;
      *puVar1 = 0x17;
    }
    else if (param_3 == '\x01') {
      puVar1[-2] = 0x17;
      *puVar1 = 0x16;
    }
    puVar1 = puVar1 + 0x2a;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (param_3 == '\0') {
    *(undefined1 *)(lVar3 + 0xab) = 4;
    *(undefined1 *)(lVar3 + 0xad) = 5;
  }
  else if (param_3 == '\x01') {
    *(undefined1 *)(lVar3 + 0xab) = 5;
    *(undefined1 *)(lVar3 + 0xad) = 4;
    return;
  }
  return;
}

