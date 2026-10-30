/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b4eb0; RVA 0x1b4eb0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ulonglong FUN_1401b4eb0(longlong param_1,longlong param_2)

{
  byte bVar1;
  bool bVar2;
  ulonglong in_RAX;
  uint7 uVar3;
  longlong lVar4;
  longlong *plVar5;
  
  bVar1 = *(byte *)(param_2 + 0x236);
  if (bVar1 != 0xff) {
    in_RAX = *(ulonglong *)(param_1 + 0x6b8);
    plVar5 = (longlong *)(*(longlong *)(in_RAX + 0x697b8) + (ulonglong)bVar1 * 8);
    if (*(byte *)(param_2 + 0x237) == 0xff) {
      lVar4 = 0;
    }
    else {
      lVar4 = (ulonglong)*(byte *)(param_2 + 0x237) * 0x520 +
              *(longlong *)
               (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)bVar1 * 8) + 0x110
               );
      in_RAX = DAT_14033d9d8;
    }
    if ((lVar4 != 0) && (plVar5 != (longlong *)0x0)) {
      if (((*(byte *)(lVar4 + 0x1f0) & 8) == 0) || ((*(byte *)(*plVar5 + 0x120) & 4) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      uVar3 = (uint7)((ulonglong)*(longlong **)(param_2 + 0x1a0) >> 8);
      if ((*(char *)(**(longlong **)(param_2 + 0x1a0) + 0x71) == '\x03') ||
         ((*(uint *)(param_2 + 0x1f0) & 0x10000) != 0)) {
        in_RAX = (ulonglong)uVar3 << 8;
      }
      else {
        in_RAX = CONCAT71(uVar3,1);
      }
      if ((bVar2) && ((char)in_RAX != '\0')) {
        return CONCAT71((int7)(in_RAX >> 8),bVar1 != 0);
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}

