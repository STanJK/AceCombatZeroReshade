/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010f560; RVA 0x10f560
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14010f560(longlong param_1)

{
  byte bVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined4 uVar4;
  
  bVar1 = *(byte *)((ulonglong)*(byte *)(param_1 + 0x279a) + 4 + *(longlong *)(param_1 + 0xff8));
  auVar2 = vpcmpeqd_avx(ZEXT416((uint)bVar1),SUB6416(ZEXT464(0x15),0));
  auVar2 = vblendvps_avx(ZEXT416(DAT_1402d22d0),ZEXT416(DAT_1402d2494),auVar2);
  uVar4 = auVar2._0_4_;
  if (*(char *)(param_1 + 0x20a3) == '\"') {
    if (bVar1 == 0x14) {
      uVar4 = DAT_1402d23f0;
    }
  }
  else if (*(char *)(param_1 + 0x20a3) == '#') {
    auVar3 = vpcmpeqd_avx(ZEXT416((uint)bVar1),SUB6416(ZEXT464(0x14),0));
    auVar2 = vblendvps_avx(auVar2,ZEXT416(DAT_1402d2330),auVar3);
    uVar4 = auVar2._0_4_;
  }
  *(undefined4 *)(param_1 + 0x1f44) = uVar4;
  *(undefined4 *)(param_1 + 0x1f5c) = uVar4;
  *(undefined4 *)(param_1 + 0x1f74) = uVar4;
  *(undefined4 *)(param_1 + 0x1f8c) = uVar4;
  return;
}

