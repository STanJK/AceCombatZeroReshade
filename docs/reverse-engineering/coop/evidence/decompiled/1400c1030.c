/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c1030; RVA 0xc1030
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c1030(longlong param_1)

{
  uint *puVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(char *)(param_1 + 0x90) != '\0') {
    pbVar2 = (byte *)(param_1 + 0x1c);
    do {
      if ((pbVar2[-1] != 0xff) && (*pbVar2 != 0xff)) {
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (**(longlong **)(pbVar2 + -0x1c) + (ulonglong)pbVar2[-1] * 8) + 0x110)
                          + 0x1f0 + (ulonglong)*pbVar2 * 0x520);
        *puVar1 = *puVar1 & 0xffffffef;
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (**(longlong **)(pbVar2 + -0x1c) + (ulonglong)pbVar2[-1] * 8) + 0x110)
                          + 500 + (ulonglong)*pbVar2 * 0x520);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      pbVar2[-1] = 0xff;
      pbVar2[0] = 0xff;
      iVar3 = iVar3 + 1;
      pbVar2[-0xc] = 0;
      pbVar2[-0xb] = 0;
      pbVar2[-10] = 0;
      pbVar2[-9] = 0;
      pbVar2[-8] = 0;
      pbVar2[-7] = 0;
      pbVar2[-6] = 0;
      pbVar2[-5] = 0;
      pbVar2[1] = 0;
      pbVar2 = pbVar2 + 0x20;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x90));
  }
  return;
}

