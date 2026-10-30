/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14016f860; RVA 0x16f860
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_14016f860(longlong param_1)

{
  uint *puVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  longlong lVar8;
  longlong *plVar9;
  byte bVar10;
  byte bVar11;
  longlong lVar12;
  longlong unaff_GS_OFFSET;
  
  lVar8 = FUN_140189320();
  auVar4 = vpcmpeqd_avx(ZEXT116(*(byte *)(lVar8 + 0x28)),SUB6416(ZEXT464(0),0));
  auVar4 = vblendvps_avx(ZEXT416(DAT_1402d28d0),ZEXT416(DAT_1402d290c),auVar4);
  *(int *)(*(longlong *)(param_1 + 0x10) + 4) = auVar4._0_4_;
  *(undefined1 *)(*(longlong *)(param_1 + 8) + 0xa881d) = 2;
  puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0xa8790);
  *puVar1 = *puVar1 & 0xfeffffff;
  uVar7 = DAT_14031ce48._4_4_;
  lVar8 = *(longlong *)(param_1 + 8);
  lVar12 = (longlong)(int)DAT_14031ce48._4_4_;
  plVar9 = (longlong *)FUN_140189320();
  if ((uVar7 < 7) && (*plVar9 != 0)) {
    uVar6 = *(undefined1 *)(*plVar9 + 0xc + lVar12 * 0x10);
  }
  else {
    uVar6 = 100;
  }
  *(undefined1 *)(lVar8 + 0xa88b0) = uVar6;
  uVar7 = DAT_14031ce48._4_4_;
  lVar8 = *(longlong *)(param_1 + 8);
  lVar12 = (longlong)(int)DAT_14031ce48._4_4_;
  plVar9 = (longlong *)FUN_140189320();
  if ((uVar7 < 7) && (*plVar9 != 0)) {
    uVar6 = *(undefined1 *)(*plVar9 + 0xd + lVar12 * 0x10);
  }
  else {
    uVar6 = 100;
  }
  *(undefined1 *)(lVar8 + 0xa88b1) = uVar6;
  uVar7 = DAT_14031ce48._4_4_;
  lVar8 = *(longlong *)(param_1 + 8);
  lVar12 = (longlong)(int)DAT_14031ce48._4_4_;
  plVar9 = (longlong *)FUN_140189320();
  if ((uVar7 < 7) && (*plVar9 != 0)) {
    bVar11 = *(byte *)(*plVar9 + 0xe + lVar12 * 0x10) & 1;
  }
  else {
    bVar11 = 0;
  }
  bVar2 = *(byte *)(lVar8 + 0xa88b2);
  bVar10 = bVar2 | 1;
  if (bVar11 == 0) {
    bVar10 = bVar2 & 0xfe;
  }
  *(byte *)(lVar8 + 0xa88b2) = bVar10;
  FUN_1400cbcc0(*(undefined8 *)(param_1 + 8));
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8260) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8220) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8240) = *(undefined8 *)(param_1 + 0x10);
  uVar3 = *(undefined8 *)(param_1 + 8);
  lVar8 = FUN_140189320();
  FUN_1400cd800(uVar3,*(char *)(lVar8 + 0x2c) != '\0');
  iVar5 = DAT_140316c04;
  if (DAT_14031cf18 != '\0') {
    iVar5 = DAT_14031cbbc;
  }
  uVar7 = *(uint *)(*(longlong *)(param_1 + 8) + 0xa8790);
  if (iVar5 == 0) {
    uVar7 = uVar7 & 0xff7fffff;
  }
  else {
    uVar7 = uVar7 | 0x800000;
  }
  *(uint *)(*(longlong *)(param_1 + 8) + 0xa8790) = uVar7;
  DAT_14031cec0 = DAT_14031cec4;
  DAT_14031cecc = DAT_14031ced0;
  FUN_1401c56d0();
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  DAT_1437dece0 = DAT_1437dece0 | 8;
  return 1;
}

