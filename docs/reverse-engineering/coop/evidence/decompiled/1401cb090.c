/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401cb090; RVA 0x1cb090
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1401cb090(longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint *puVar5;
  
  puVar5 = (uint *)(param_1 + 0x1d8);
  lVar3 = 0x80;
  do {
    if ((short)puVar5[3] != 0) {
      uVar1 = *puVar5;
      if ((uVar1 != 0) && ((ushort)uVar1 < 0x80)) {
        if ((short)(uVar1 >> 0x10) == *(short *)(param_1 + 2 + (ulonglong)(uVar1 & 0xffff) * 2)) {
          lVar4 = (ulonglong)(uVar1 & 0xffff) * 0x78 + 0x1a0 + param_1;
          uVar1 = *(uint *)(lVar4 + 0x38);
          if (((uVar1 != 0) && ((ushort)uVar1 < 0x80)) &&
             ((short)(uVar1 >> 0x10) == *(short *)(param_1 + 2 + (ulonglong)(uVar1 & 0xffff) * 2)))
          {
            if ((*(byte *)(lVar4 + 0x70) & 8) != 0) {
              iVar2 = FUN_140184120(lVar4 + 0x4c);
              if (iVar2 != 0) goto LAB_1401cb113;
            }
            FUN_1401c9330(param_1,lVar4);
          }
        }
      }
    }
LAB_1401cb113:
    puVar5 = puVar5 + 0x1e;
    lVar3 = lVar3 + -1;
    if (lVar3 == 0) {
      return 1;
    }
  } while( true );
}

