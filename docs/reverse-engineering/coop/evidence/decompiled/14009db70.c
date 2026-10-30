/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14009db70; RVA 0x9db70
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14009db70(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auVar4 [64];
  
  auVar4 = ZEXT464(DAT_1402d23c0);
  lVar2 = param_1 + 0x80;
  iVar3 = 0;
  uVar1 = 1;
  do {
    if ((*(uint *)(param_1 + 0x5c) & uVar1) != 0) {
      FUN_140091d80(param_1,iVar3,lVar2,auVar4._0_8_,2,0);
    }
    iVar3 = iVar3 + 1;
    uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    lVar2 = lVar2 + 0x68;
  } while (iVar3 < 0x10);
  return;
}

