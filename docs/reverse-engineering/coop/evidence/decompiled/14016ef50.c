/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016ef50; RVA 0x16ef50
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016ef50(longlong param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar5 = FUN_140189320();
  auVar3 = vpcmpeqd_avx(ZEXT116(*(byte *)(lVar5 + 0x28)),SUB6416(ZEXT464(0),0));
  auVar3 = vblendvps_avx(ZEXT416(DAT_1402d28d0),ZEXT416(DAT_1402d290c),auVar3);
  *(int *)(*(longlong *)(param_1 + 0x10) + 4) = auVar3._0_4_;
  lVar5 = *(longlong *)(param_1 + 8);
  lVar6 = FUN_140189320();
  *(undefined1 *)(lVar5 + 0xa881d) = *(undefined1 *)(lVar6 + 0x2f);
  lVar5 = FUN_140189320();
  if (*(char *)(lVar5 + 0x2f) == '\x06') {
    puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xa8790);
    *puVar1 = *puVar1 | 0x1000000;
  }
  else {
    puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xa8790);
    *puVar1 = *puVar1 & 0xfeffffff;
  }
  FUN_1400cbcc0(*(undefined8 *)(param_1 + 8));
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8260) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8220) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8240) = *(undefined8 *)(param_1 + 0x10);
  uVar2 = *(undefined8 *)(param_1 + 8);
  lVar5 = FUN_140189320();
  FUN_1400cd800(uVar2,*(char *)(lVar5 + 0x2c) != '\0');
  iVar4 = DAT_140316c04;
  if (DAT_14031cf18 != '\0') {
    iVar4 = DAT_14031cbbc;
  }
  if (iVar4 == 0) {
    puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xa8790);
    *puVar1 = *puVar1 & 0xff7fffff;
    return 1;
  }
  puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xa8790);
  *puVar1 = *puVar1 | 0x800000;
  return CONCAT71((uint7)(uint3)((uint)iVar4 >> 8),1);
}

