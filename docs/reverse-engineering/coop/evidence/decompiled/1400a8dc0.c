/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a8dc0; RVA 0xa8dc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a8dc0(undefined8 param_1,undefined4 *param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  longlong lVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined8 extraout_XMM0_Qa;
  
  DAT_14032c480 = DAT_14032c480 + 1;
  uVar8 = FUN_1401c56d0();
  cVar4 = FUN_1401c5910(uVar8,param_2 + 0x25);
  if (cVar4 != '\0') {
    FUN_1401c6260(extraout_XMM0_Qa,param_2 + 0x25,param_2);
    DAT_14032c480 = DAT_14032c480 + -1;
    return;
  }
  cVar4 = FUN_1401c6a00(0,1,0x91,param_2,param_2 + 8,0,0,0,0,0,0);
  if (cVar4 != '\0') {
    lVar5 = FUN_1401c97a0();
    uVar3 = param_2[0x25];
    if ((((uVar3 == 0) || (0x7f < (ushort)uVar3)) ||
        ((short)(uVar3 >> 0x10) != *(short *)(lVar5 + 2 + (ulonglong)(uVar3 & 0xffff) * 2))) &&
       ('\x01' < *(char *)(lVar5 + 0x3dc2))) {
      uVar2 = *(ushort *)(lVar5 + 0x138);
      bVar1 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar2 * 0x18) + 0x2d62);
      puVar6 = (undefined4 *)FUN_1401c9e60(lVar5);
      if (puVar6 != (undefined4 *)0x0) {
        *(ushort *)(puVar6 + 0x11) = uVar2;
        *(undefined2 *)((longlong)puVar6 + 0x46) = 0x91;
        *puVar6 = *param_2;
        puVar6[1] = param_2[1];
        puVar6[2] = param_2[2];
        puVar6[3] = param_2[3];
        puVar6[4] = param_2[8];
        puVar6[5] = param_2[9];
        puVar6[6] = param_2[10];
        puVar6[7] = param_2[0xb];
        *(undefined8 *)(puVar6 + 8) = 0;
        puVar6[10] = 0;
        *(undefined2 *)((longlong)puVar6 + 0x4a) = 0;
        puVar6[0xb] = 0x3f800000;
        puVar6[0xf] = 0x3f800000;
        *(byte *)(puVar6 + 0x1c) = *(byte *)(puVar6 + 0x1c) & 0xef | 2;
        param_2[0x25] = puVar6[0xe];
        if ((bVar1 & 1) == 0) {
          *(byte *)(puVar6 + 0x1c) = *(byte *)(puVar6 + 0x1c) & 0xfa;
          pcVar7 = FUN_1401caa00;
        }
        else {
          *(byte *)(puVar6 + 0x1c) = *(byte *)(puVar6 + 0x1c) & 0xfb | 1;
          pcVar7 = FUN_1401ca740;
        }
        *(code **)(puVar6 + 0xc) = pcVar7;
      }
    }
  }
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

