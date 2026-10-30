/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400781c0; RVA 0x781c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400781c0(longlong *param_1,short *param_2,longlong param_3)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong local_18;
  int local_10;
  
  if ((char)param_1[2] != '\0') {
    sVar2 = *param_2;
    while (sVar2 != -1) {
      uVar6 = (int)sVar2 >> 0x1f & 0x3f;
      uVar3 = (int)sVar2 + uVar6;
      uVar6 = (uVar3 & 0x3f) - uVar6;
      uVar7 = (int)uVar3 >> 6 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      uVar5 = uVar6 & 0x80000003;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
      }
      lVar4 = (longlong)(int)(uVar5 + uVar7 * 4) +
              (longlong)
              (((int)(((int)uVar3 >> 0x1f & 3U) + ((int)uVar3 >> 6)) >> 2) * 0x10 +
              ((int)(uVar6 + ((int)uVar6 >> 0x1f & 3U)) >> 2)) * 0x20;
      local_10 = (int)*(short *)(*param_1 + 0x20 + lVar4 * 2);
      if (local_10 != 0) {
        local_18 = (longlong)*(short *)(*param_1 + lVar4 * 2) * 0x40 + param_1[1];
        FUN_140031f80(*(undefined8 *)(param_3 + 0x66ee0),0x7f,&local_18,0);
      }
      psVar1 = param_2 + 1;
      param_2 = param_2 + 1;
      sVar2 = *psVar1;
    }
  }
  return;
}

