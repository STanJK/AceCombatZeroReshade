/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400cbcc0; RVA 0xcbcc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1400cbcc0(longlong param_1)

{
  uint *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  ushort uVar4;
  code *pcVar5;
  undefined4 *puVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  ushort *puVar10;
  undefined1 auVar11 [16];
  float fVar12;
  float fVar13;
  int *piVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined8 *puVar17;
  longlong lVar18;
  ulonglong uVar19;
  undefined8 *puVar20;
  uint uVar21;
  ulonglong uVar22;
  longlong *plVar23;
  byte bVar24;
  uint uVar25;
  undefined8 *puVar26;
  longlong lVar27;
  longlong lVar28;
  float *pfVar29;
  char cVar30;
  longlong lVar31;
  int iVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  longlong *plVar35;
  ulonglong uVar36;
  int iVar37;
  undefined8 extraout_XMM0_Qa;
  float fVar38;
  undefined4 local_res8;
  
  if (*(char *)(param_1 + 0xa8827) != '\0') {
    *(undefined1 *)(param_1 + 0xa881d) = 2;
  }
  lVar27 = *(longlong *)(param_1 + 0x67130);
  if (*(longlong *)(lVar27 + 0x1378) != 0) {
    uVar15 = FUN_140078ed0(lVar27);
    uVar16 = FUN_140200de0(DAT_14032c8f8,uVar15,0x10);
    FUN_140078fb0(lVar27,uVar16);
  }
  lVar27 = *(longlong *)(param_1 + 0x67148);
  if (*(int *)(lVar27 + 0x38) != 0) {
    uVar15 = FUN_14007e230(lVar27);
    uVar16 = FUN_140200de0(DAT_14032c8f8,uVar15,0x10);
    FUN_14007e480(lVar27,uVar16);
  }
  FUN_14007ef20(*(undefined8 *)(param_1 + 0x67148));
  if (*(char *)(param_1 + 0xa8828) == '\x02') {
    lVar27 = *(longlong *)(param_1 + 0x67130);
    if (*(longlong *)(lVar27 + 0x2700) != 0) {
      uVar15 = FUN_140078ed0(lVar27 + 5000);
      uVar16 = FUN_140200de0(DAT_14032c8f8,uVar15,0x10);
      FUN_140078fb0(lVar27 + 5000,uVar16);
    }
    lVar27 = *(longlong *)(param_1 + 0x67148);
    if (*(int *)(lVar27 + 0x178) != 0) {
      uVar15 = FUN_14007e230(lVar27 + 0x140);
      uVar16 = FUN_140200de0(DAT_14032c8f8,uVar15,0x10);
      FUN_14007e480(lVar27 + 0x140,uVar16);
    }
    FUN_14007ef20(*(longlong *)(param_1 + 0x67148) + 0x140);
  }
  lVar27 = param_1 + 0x240;
  *(longlong *)(param_1 + 0x6add0) = lVar27;
  *(longlong *)(param_1 + 0x6a130) = lVar27;
  uVar16 = FUN_1400c2980(param_1 + 0x6bc40,lVar27);
  lVar31 = param_1 + 0x697b8;
  *(longlong *)(param_1 + 0x6add8) = lVar31;
  *(longlong *)(param_1 + 0x6a138) = lVar31;
  FUN_1400c2b90(uVar16,lVar31);
  *(undefined8 *)(param_1 + 0x6ade0) = *(undefined8 *)(param_1 + 0x67170);
  *(undefined8 *)(param_1 + 0x6a140) = *(undefined8 *)(param_1 + 0x67170);
  uVar16 = FUN_1400c2da0();
  uVar16 = FUN_1400c2fb0(uVar16,*(undefined8 *)(param_1 + 0xa82a8));
  FUN_1400c31c0(uVar16,*(undefined8 *)(param_1 + 0xa8318));
  *(undefined1 *)(param_1 + 0x6adf8) = *(undefined1 *)(param_1 + 0xa8825);
  *(undefined1 *)(param_1 + 0x6a158) = *(undefined1 *)(param_1 + 0xa8825);
  FUN_1400c33d0();
  *(undefined4 *)(param_1 + 0xa8194) = 1;
  lVar31 = param_1 + 0xa8328;
  *(undefined4 *)(param_1 + 0xa8160) = 0;
  *(undefined8 *)(param_1 + 0xa8174) = 0;
  *(longlong *)(param_1 + 0x80108) = param_1 + 0x69748;
  *(undefined8 *)(param_1 + 0xa817c) = 0;
  *(undefined8 *)(param_1 + 0xa8184) = 0;
  *(undefined8 *)(param_1 + 0xa818c) = 0;
  FUN_1400bd780(lVar31);
  piVar14 = DAT_14032c8f8;
  DAT_140328418 = lVar31;
  puVar17 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,0x2b0,0x10);
  *puVar17 = &PTR_FUN_1402ac520;
  *(undefined2 *)(puVar17 + 1) = 1;
  *(undefined1 *)((longlong)puVar17 + 10) = 0;
  puVar17[9] = 0;
  *(undefined4 *)(puVar17 + 10) = 1;
  *(undefined8 *)((longlong)puVar17 + 0x54) = 0xffffffffffffffff;
  *(undefined8 *)((longlong)puVar17 + 0x25c) = 0;
  *(undefined1 *)((longlong)puVar17 + 0x264) = 0;
  puVar17[0x4d] = 0;
  puVar17[0x4e] = 0;
  puVar17[0x4f] = 0;
  puVar17[0x50] = 0;
  puVar17[0x51] = 0;
  puVar17[0x52] = 0;
  puVar17[0x53] = 0;
  puVar17[0x54] = 0;
  puVar17[0x55] = 0;
  *(undefined8 **)(param_1 + 0x67158) = puVar17;
  puVar17 = (undefined8 *)FUN_140200de0(piVar14,0x270,0x10);
  *puVar17 = &PTR_FUN_1402ac4a8;
  *(undefined2 *)(puVar17 + 1) = 1;
  *(undefined1 *)((longlong)puVar17 + 10) = 0;
  puVar17[9] = 0;
  *(undefined4 *)(puVar17 + 10) = 1;
  *(undefined8 *)((longlong)puVar17 + 0x54) = 0xffffffffffffffff;
  *(undefined8 *)((longlong)puVar17 + 0x25c) = 0;
  *(undefined1 *)((longlong)puVar17 + 0x264) = 0;
  puVar17[0x4d] = 0x10;
  *(undefined8 **)(param_1 + 0x67150) = puVar17;
  puVar17 = (undefined8 *)FUN_140200de0(piVar14,0x338,0x10);
  *(undefined2 *)(puVar17 + 1) = 1;
  *(undefined1 *)((longlong)puVar17 + 10) = 0;
  *puVar17 = &PTR_FUN_1402ac620;
  puVar17[9] = 0;
  *(undefined4 *)(puVar17 + 10) = 1;
  *(undefined8 *)((longlong)puVar17 + 0x54) = 0xffffffffffffffff;
  *(undefined8 *)((longlong)puVar17 + 0x25c) = 0;
  *(undefined1 *)((longlong)puVar17 + 0x264) = 0;
  puVar17[0x4e] = 0;
  puVar17[0x4f] = 0;
  puVar17[0x50] = 0;
  puVar17[0x4d] = 0;
  puVar17[0x51] = 0;
  puVar17[0x52] = 0;
  puVar17[0x53] = 0;
  *(undefined4 *)(puVar17 + 0x54) = 1;
  *(undefined1 *)((longlong)puVar17 + 0x2a4) = 1;
  *(undefined4 *)(puVar17 + 0x55) = 0;
  puVar17[0x57] = 0;
  puVar17[0x58] = 0;
  puVar17[0x59] = 0;
  puVar17[0x56] = 0;
  puVar17[0x5a] = 0;
  puVar17[0x5b] = 0;
  puVar17[0x5c] = 0;
  *(undefined4 *)(puVar17 + 0x5d) = 1;
  *(undefined1 *)((longlong)puVar17 + 0x2ec) = 1;
  *(undefined4 *)(puVar17 + 0x5e) = 0;
  puVar17[0x5f] = 0;
  puVar17[0x60] = 0;
  puVar17[0x61] = 0;
  puVar17[0x62] = 0;
  puVar17[99] = 0;
  puVar17[100] = 0;
  puVar17[0x65] = 0;
  *(undefined4 *)((longlong)puVar17 + 0x333) = 1;
  *(undefined8 **)(param_1 + 0x67160) = puVar17;
  puVar17 = (undefined8 *)FUN_140200de0(piVar14,0x270,0x10);
  *(undefined2 *)(puVar17 + 1) = 1;
  *(undefined1 *)((longlong)puVar17 + 10) = 0;
  puVar17[9] = 0;
  *(undefined4 *)(puVar17 + 10) = 1;
  *(undefined8 *)((longlong)puVar17 + 0x54) = 0xffffffffffffffff;
  *(undefined8 *)((longlong)puVar17 + 0x25c) = 0;
  *(undefined1 *)((longlong)puVar17 + 0x264) = 0;
  *puVar17 = &PTR_FUN_1402ac5a0;
  *(undefined4 *)(puVar17 + 0x4d) = 0x10;
  *(undefined4 *)((longlong)puVar17 + 0x26c) = 1;
  *(undefined8 **)(param_1 + 0x67168) = puVar17;
  (**(code **)(**(longlong **)(param_1 + 0x67150) + 8))();
  plVar23 = *(longlong **)(param_1 + 0x67150);
  pcVar5 = *(code **)(*plVar23 + 0x18);
  lVar18 = FUN_140189320();
  (*pcVar5)(plVar23,*(char *)(lVar18 + 0x28) != '\0');
  puVar1 = (uint *)(*(longlong *)(param_1 + 0x67150) + 0x50);
  *puVar1 = *puVar1 | 1;
  (**(code **)(**(longlong **)(param_1 + 0x67168) + 8))();
  plVar23 = *(longlong **)(param_1 + 0x67168);
  pcVar5 = *(code **)(*plVar23 + 0x18);
  lVar18 = FUN_140189320();
  (*pcVar5)(plVar23,*(char *)(lVar18 + 0x28) != '\0');
  puVar1 = (uint *)(*(longlong *)(param_1 + 0x67168) + 0x50);
  *puVar1 = *puVar1 | 1;
  puVar1 = (uint *)(*(longlong *)(param_1 + 0x67168) + 0x50);
  *puVar1 = *puVar1 | 2;
  *(undefined8 *)(*(longlong *)(param_1 + 0x67158) + 0x278) = *(undefined8 *)(param_1 + 0xa82c8);
  *(undefined8 *)(*(longlong *)(param_1 + 0x67158) + 0x280) = *(undefined8 *)(param_1 + 0xa82e0);
  plVar23 = *(longlong **)(param_1 + 0x67158);
  if (*(byte *)(param_1 + 0xa87e4) < 2) {
    (**(code **)(*plVar23 + 0x58))(plVar23,0,*(char *)(param_1 + 0xa8794) == '\x13');
  }
  else {
    (**(code **)(*plVar23 + 0x58))(plVar23,1,2);
  }
  plVar23 = *(longlong **)(param_1 + 0x67158);
  pcVar5 = *(code **)(*plVar23 + 0x18);
  lVar18 = FUN_140189320();
  (*pcVar5)(plVar23,*(char *)(lVar18 + 0x28) != '\0');
  *(undefined8 *)(*(longlong *)(param_1 + 0x67160) + 0x2f8) = *(undefined8 *)(param_1 + 0xa82d0);
  *(undefined8 *)(*(longlong *)(param_1 + 0x67160) + 0x300) = *(undefined8 *)(param_1 + 0xa82d8);
  FUN_1400c5d40(*(undefined8 *)(param_1 + 0x67160),
                *(undefined8 *)(*(longlong *)(param_1 + 0xa8248) + 0x1fd8));
  if (*(int *)(param_1 + 0xa82f0) == 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x67160) + 0x333) = 0;
  }
  else {
    FUN_1400c5e80(*(undefined8 *)(param_1 + 0x67160),
                  *(undefined8 *)(*(longlong *)(param_1 + 0xa82f8) + 0x40));
  }
  (**(code **)(**(longlong **)(param_1 + 0x67160) + 8))();
  plVar23 = *(longlong **)(param_1 + 0x67160);
  pcVar5 = *(code **)(*plVar23 + 0x18);
  lVar18 = FUN_140189320();
  (*pcVar5)(plVar23,*(char *)(lVar18 + 0x28) != '\0');
  local_res8 = 0;
  puVar1 = (uint *)(*(longlong *)(param_1 + 0x67160) + 0x50);
  *puVar1 = *puVar1 | 1;
  *(longlong *)(param_1 + 0x671d8) = lVar31;
  *(undefined4 *)(param_1 + 0x671d0) = *(undefined4 *)(param_1 + 0xa8614);
  *(undefined1 *)(param_1 + 0x671e6) = *(undefined1 *)(param_1 + 0xa8825);
  bVar24 = *(byte *)(param_1 + 0xa87e4);
  if (bVar24 != 0) {
    iVar37 = 0;
    do {
      lVar28 = (longlong)iVar37 * 0x27a0 + *(longlong *)(param_1 + 0xa8248);
      *(bool *)(lVar28 + 0x20c8) = 1 < bVar24;
      FUN_1400ade70(lVar28 + 0x1868,1 < bVar24,iVar37);
      *(undefined1 *)(lVar28 + 0x1c1d) = *(undefined1 *)(*(longlong *)(lVar28 + 0xff8) + 0xd);
      FUN_1400ad7a0(*(undefined8 *)(lVar28 + 0x1890),*(undefined8 *)(lVar28 + 0x1fe8),
                    *(undefined8 *)(lVar28 + 0x1fe0));
      FUN_1400ad900(*(undefined8 *)(lVar28 + 0x1890),*(undefined8 *)(lVar28 + 0x1ff8),
                    *(undefined8 *)(lVar28 + 0x1ff0));
      FUN_1400adac0(*(undefined8 *)(lVar28 + 0x1890),
                    *(undefined8 *)(lVar28 + 0x2018 + (ulonglong)*(byte *)(lVar28 + 0x279a) * 8),
                    *(undefined8 *)(lVar28 + 0x2000 + (ulonglong)*(byte *)(lVar28 + 0x279a) * 8));
      *(short *)(lVar28 + 0xae2) = (short)iVar37;
      lVar18 = param_1 + 0x697b8;
      *(longlong *)(lVar28 + 0x1840) = lVar18;
      *(longlong *)(lVar28 + 0x1d50) = lVar18;
      *(longlong *)(lVar28 + 0x1ed0) = lVar18;
      *(longlong *)(lVar28 + 0x1eb8) = lVar18;
      *(longlong *)(lVar28 + 0x2040) = lVar18;
      *(longlong *)(lVar28 + 0x1e38) = lVar18;
      *(longlong *)(lVar28 + 0x1e58) = lVar18;
      *(longlong *)(lVar28 + 0x1e78) = lVar18;
      *(longlong *)(lVar28 + 0x1e98) = lVar18;
      uVar16 = *(undefined8 *)(param_1 + 0x67140);
      *(undefined8 *)(lVar28 + 0x2030) = uVar16;
      *(undefined8 *)(lVar28 + 0x1628) = uVar16;
      *(undefined8 *)(lVar28 + 0x1b50) = uVar16;
      uVar16 = *(undefined8 *)(param_1 + 0x67170);
      *(undefined8 *)(lVar28 + 0x2038) = uVar16;
      *(undefined8 *)(lVar28 + 0x1838) = uVar16;
      *(undefined8 *)(lVar28 + 0x1620) = uVar16;
      *(undefined8 *)(lVar28 + 0x1d58) = uVar16;
      *(longlong *)(lVar28 + 0x1b68) = lVar31;
      *(longlong *)(lVar28 + 0x1ae0) = lVar31;
      *(undefined4 *)(lVar28 + 0x1ac8) = *(undefined4 *)(param_1 + 0xa8600);
      lVar18 = *(longlong *)(lVar28 + 0x1ae0);
      *(undefined4 *)(lVar28 + 0x1acc) = *(undefined4 *)(lVar18 + 0x2dc);
      *(undefined4 *)(lVar28 + 0x1ad0) = *(undefined4 *)(lVar18 + 0x2e0);
      *(undefined4 *)(lVar28 + 0x1ad4) = *(undefined4 *)(lVar18 + 0x2e4);
      *(undefined4 *)(lVar28 + 0x1ad8) = *(undefined4 *)(lVar18 + 0x2e8);
      lVar18 = *(longlong *)(lVar28 + 0x1b68);
      DAT_140328418 = lVar18;
      *(undefined4 *)(lVar28 + 0x1a18) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a1c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a20) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a24) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a28) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a2c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a30) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a34) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a38) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a3c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a40) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a44) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a48) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a4c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a50) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a54) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a58) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a5c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a60) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a64) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a68) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a6c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a70) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a74) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a78) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a7c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a80) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a84) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a88) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a8c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a90) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a94) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a98) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a9c) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1aa0) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1aa4) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1aa8) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1aac) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1ab0) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1ab4) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1ab8) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1abc) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1ac0) = *(undefined4 *)(lVar18 + 0x238);
      *(undefined4 *)(lVar28 + 0x1a4c) = *(undefined4 *)(lVar18 + 0x268);
      *(undefined4 *)(lVar28 + 0x1a5c) = *(undefined4 *)(lVar18 + 0x26c);
      *(undefined4 *)(lVar28 + 0x1a50) = *(undefined4 *)(lVar18 + 0x270);
      *(undefined4 *)(lVar28 + 0x1a68) = *(undefined4 *)(lVar18 + 0x240);
      *(undefined4 *)(lVar28 + 0x1a60) = *(undefined4 *)(lVar18 + 0x244);
      *(undefined4 *)(lVar28 + 0x1a64) = *(undefined4 *)(lVar18 + 0x23c);
      *(undefined4 *)(lVar28 + 0x1a90) = *(undefined4 *)(lVar18 + 0x310);
      *(undefined4 *)(lVar28 + 0x1a94) = *(undefined4 *)(lVar18 + 0x310);
      *(undefined4 *)(lVar28 + 0x1a98) = *(undefined4 *)(lVar18 + 0x314);
      *(undefined4 *)(lVar28 + 0x1a9c) = *(undefined4 *)(lVar18 + 0x318);
      *(undefined4 *)(lVar28 + 0x1aa0) = *(undefined4 *)(lVar18 + 0x31c);
      *(undefined4 *)(lVar28 + 0x1aa4) = *(undefined4 *)(lVar18 + 0x310);
      *(undefined4 *)(lVar28 + 0x1aa8) = *(undefined4 *)(lVar18 + 0x314);
      *(undefined4 *)(lVar28 + 0x1aac) = *(undefined4 *)(lVar18 + 0x314);
      *(longlong *)(lVar28 + 0x1fa8) = (longlong)iVar37 * 0x70 + *(longlong *)(param_1 + 0x671c0);
      *(longlong *)(lVar28 + 0x1fc0) = lVar27;
      uVar3 = *(undefined1 *)(param_1 + 0xa8825);
      *(undefined1 *)(lVar28 + 0x20a0) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f01) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f19) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f31) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f49) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f61) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f79) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f91) = uVar3;
      *(undefined1 *)(lVar28 + 0x1f9f) = uVar3;
      *(undefined1 *)(lVar28 + 0x1864) = uVar3;
      *(undefined1 *)(lVar28 + 0x1674) = uVar3;
      *(undefined1 *)(lVar28 + 0x1c28) = uVar3;
      *(undefined1 *)(lVar28 + 0x1aec) = uVar3;
      *(longlong *)(lVar28 + 0x1b60) = param_1 + 0x69798;
      puVar6 = *(undefined4 **)(param_1 + 0xa8830);
      *(undefined4 *)(lVar28 + 0x1070) = *puVar6;
      *(undefined4 **)(lVar28 + 0x1080) = puVar6 + 1;
      *(undefined4 **)(lVar28 + 0x1078) = puVar6;
      lVar18 = FUN_140189320();
      cVar30 = *(char *)(lVar18 + 0x30);
      uVar25 = *(uint *)(lVar28 + 0x2058) | 4;
      if (cVar30 == '\0') {
        uVar25 = *(uint *)(lVar28 + 0x2058) & 0xfffffffb;
      }
      *(uint *)(lVar28 + 0x2058) = uVar25;
      bVar24 = *(byte *)(lVar28 + 0x1e20) | 1;
      if (cVar30 == '\0') {
        bVar24 = *(byte *)(lVar28 + 0x1e20) & 0xfe;
      }
      *(byte *)(lVar28 + 0x1e20) = bVar24;
      lVar18 = FUN_140189320();
      uVar25 = *(uint *)(lVar28 + 0x2058) | 8;
      if (*(char *)(lVar18 + 0x31) == '\0') {
        uVar25 = *(uint *)(lVar28 + 0x2058) & 0xfffffff7;
      }
      iVar37 = iVar37 + 1;
      *(uint *)(lVar28 + 0x2058) = uVar25;
      bVar24 = *(byte *)(param_1 + 0xa87e4);
    } while (iVar37 < (int)(uint)bVar24);
  }
  lVar18 = param_1 + 0x6a130;
  puVar17 = (undefined8 *)(param_1 + 0x69748);
  iVar37 = FUN_140242630();
  fVar38 = DAT_1402d22d0;
  fVar13 = DAT_1402d1cfc;
  pfVar29 = (float *)&DAT_1403273a0;
  lVar31 = 0x400;
  uVar25 = iVar37 * 0xee29 + 1;
  do {
    uVar21 = uVar25 * 0x10dcd + 1;
    uVar25 = uVar21 * 0x10dcd + 1;
    fVar12 = (float)(uVar25 >> 0x10 | uVar21 & 0xffff0000) * fVar13;
    *pfVar29 = fVar12;
    if (fVar12 == fVar38) {
      *pfVar29 = 0.99;
    }
    pfVar29 = pfVar29 + 1;
    lVar31 = lVar31 + -1;
  } while (lVar31 != 0);
  uVar15 = FUN_140242630();
  lVar31 = FUN_140189320();
  *(undefined4 *)(lVar31 + 8) = uVar15;
  FUN_14024265c(uVar15);
  puVar20 = *(undefined8 **)(*(longlong *)(param_1 + 0xa8280) + 0x10);
  *(undefined8 *)(param_1 + 0x69758) = *(undefined8 *)(param_1 + 0xa8318);
  *puVar17 = puVar20;
  *(longlong *)(param_1 + 0x69750) = param_1 + 0x697b8;
  if (puVar20 == (undefined8 *)0x0) {
    iVar37 = 0;
  }
  else {
    iVar37 = 0;
    iVar32 = 0;
    uVar25 = 0;
    uVar4 = *(ushort *)*puVar20;
    local_res8 = (uint)uVar4 * 2;
    if ((ulonglong)uVar4 < 2) {
      if (uVar4 != 0) {
        puVar20 = (undefined8 *)puVar20[2];
        lVar31 = 0;
        goto LAB_1400cc9b6;
      }
    }
    else {
      puVar20 = (undefined8 *)puVar20[2];
      lVar28 = ((ulonglong)uVar4 - 2 >> 1) + 1;
      lVar31 = lVar28 * 2;
      puVar26 = puVar20;
      do {
        iVar37 = iVar37 + (uint)*(byte *)*puVar26;
        iVar32 = iVar32 + (uint)*(byte *)puVar26[2];
        lVar28 = lVar28 + -1;
        puVar26 = puVar26 + 4;
      } while (lVar28 != 0);
      uVar25 = 0;
      if (lVar31 < (longlong)(ulonglong)(uint)uVar4) {
LAB_1400cc9b6:
        uVar25 = (uint)*(byte *)puVar20[lVar31 * 2];
      }
    }
    iVar37 = local_res8 + uVar25 + iVar32 + iVar37;
  }
  uVar36 = 0;
  lVar28 = param_1 + 0x697b8;
  lVar31 = FUN_140200de0(DAT_14032c8f8,iVar37,0x10);
  uVar16 = extraout_XMM0_Qa;
  if ((undefined8 *)*puVar17 != (undefined8 *)0x0) {
    *(longlong *)(param_1 + 0x69760) = lVar31;
    *(ulonglong *)(param_1 + 0x69768) = lVar31 + (ulonglong)**(ushort **)*puVar17 * 2;
    uVar16 = FUN_1400a98c0(puVar17);
  }
  *(undefined1 *)(param_1 + 0x69770) = *(undefined1 *)(param_1 + 0xa8825);
  uVar15 = FUN_140135b50(uVar16,*(undefined8 *)(*(longlong *)(param_1 + 0xa8280) + 8),
                         param_1 + 0x695c8,*(undefined8 *)(param_1 + 0xa8288));
  uVar16 = FUN_140200de0(DAT_14032c8f8,uVar15,0x10);
  FUN_140135cb0(lVar28,*(undefined8 *)(*(longlong *)(param_1 + 0xa8280) + 8),param_1 + 0x695c8,
                *(undefined8 *)(param_1 + 0xa8288),param_1 + 0xa87a0,
                *(undefined8 *)(param_1 + 0xa82e8),uVar16);
  plVar23 = (longlong *)(param_1 + 0x697b8);
  plVar35 = (longlong *)*plVar23;
  uVar22 = (ulonglong)*(byte *)(param_1 + 0x697ec);
  if (plVar35 != plVar35 + uVar22) {
    do {
      lVar31 = *plVar35;
      *(longlong **)(lVar31 + 0xc0) = plVar23;
      *(longlong **)(lVar31 + 0x140) = plVar23;
      if (0 < *(int *)(lVar31 + 0x118)) {
        uVar22 = uVar36;
        uVar34 = uVar36;
        do {
          lVar7 = *(longlong *)(lVar31 + 0x110);
          lVar8 = *(longlong *)(uVar22 + 0x378 + lVar7);
          if (lVar8 != 0) {
            *(longlong **)(lVar8 + 0x180) = plVar23;
            if (*(longlong *)(lVar8 + 8) != 0) {
              *(longlong **)(*(longlong *)(lVar8 + 8) + 0x78) = plVar23;
            }
            if (*(longlong *)(lVar8 + 0x10) != 0) {
              *(longlong **)(*(longlong *)(lVar8 + 0x10) + 0x78) = plVar23;
            }
          }
          lVar8 = *(longlong *)(uVar22 + 8 + lVar7);
          *(longlong **)(uVar22 + 0x180 + lVar7) = plVar23;
          if (lVar8 != 0) {
            *(longlong **)(lVar8 + 0x78) = plVar23;
          }
          lVar7 = *(longlong *)(uVar22 + 0x10 + lVar7);
          if (lVar7 != 0) {
            *(longlong **)(lVar7 + 0x78) = plVar23;
          }
          uVar25 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar25;
          uVar22 = uVar22 + 0x520;
        } while ((int)uVar25 < *(int *)(lVar31 + 0x118));
      }
      uVar22 = (ulonglong)*(byte *)(param_1 + 0x697ec);
      plVar35 = plVar35 + 1;
    } while (plVar35 != (longlong *)(*plVar23 + uVar22 * 8));
  }
  *(undefined8 **)(param_1 + 0x697c0) = puVar17;
  plVar23 = *(longlong **)(param_1 + 0x697b8);
  if (plVar23 != plVar23 + uVar22) {
    do {
      lVar31 = *plVar23;
      *(undefined8 **)(lVar31 + 0xb8) = puVar17;
      *(undefined8 **)(lVar31 + 0x150) = puVar17;
      if (0 < *(int *)(lVar31 + 0x118)) {
        uVar22 = uVar36;
        uVar34 = uVar36;
        do {
          lVar7 = *(longlong *)(lVar31 + 0x110);
          lVar8 = *(longlong *)(uVar22 + 8 + lVar7);
          *(undefined8 **)(uVar22 + 0x188 + lVar7) = puVar17;
          if (lVar8 != 0) {
            *(undefined8 **)(lVar8 + 0x70) = puVar17;
          }
          lVar7 = *(longlong *)(uVar22 + 0x10 + lVar7);
          if (lVar7 != 0) {
            *(undefined8 **)(lVar7 + 0x70) = puVar17;
          }
          uVar25 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar25;
          uVar22 = uVar22 + 0x520;
        } while ((int)uVar25 < *(int *)(lVar31 + 0x118));
      }
      plVar23 = plVar23 + 1;
    } while (plVar23 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
    uVar22 = (ulonglong)*(byte *)(param_1 + 0x697ec);
  }
  *(longlong *)(param_1 + 0x697d0) = lVar18;
  plVar23 = *(longlong **)(param_1 + 0x697b8);
  if (plVar23 != plVar23 + uVar22) {
    do {
      lVar31 = *plVar23;
      if (0 < *(int *)(lVar31 + 0x118)) {
        uVar22 = uVar36;
        uVar34 = uVar36;
        do {
          lVar7 = *(longlong *)(lVar31 + 0x110);
          lVar8 = *(longlong *)(lVar7 + 0x378 + uVar22);
          if (lVar8 != 0) {
            *(longlong *)(lVar8 + 0x178) = lVar18;
          }
          *(longlong *)(lVar7 + 0x178 + uVar22) = lVar18;
          uVar25 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar25;
          uVar22 = uVar22 + 0x520;
        } while ((int)uVar25 < *(int *)(lVar31 + 0x118));
      }
      plVar23 = plVar23 + 1;
    } while (plVar23 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  FUN_140138080(lVar28,*(undefined8 *)(param_1 + 0x67140));
  *(longlong *)(param_1 + 0x697d8) = lVar27;
  uVar22 = (ulonglong)*(byte *)(param_1 + 0x697ec);
  plVar23 = *(longlong **)(param_1 + 0x697b8);
  plVar35 = plVar23;
  if (plVar23 != plVar23 + *(byte *)(param_1 + 0x697ec)) {
    do {
      lVar31 = *plVar35;
      if (0 < *(int *)(lVar31 + 0x118)) {
        uVar22 = uVar36;
        uVar34 = uVar36;
        do {
          uVar25 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar25;
          *(longlong *)(uVar22 + 0x198 + *(longlong *)(lVar31 + 0x110)) = lVar27;
          uVar22 = uVar22 + 0x520;
        } while ((int)uVar25 < *(int *)(lVar31 + 0x118));
      }
      uVar22 = (ulonglong)*(byte *)(param_1 + 0x697ec);
      plVar35 = plVar35 + 1;
      plVar23 = *(longlong **)(param_1 + 0x697b8);
    } while (plVar35 != plVar23 + uVar22);
  }
  if (plVar23 != plVar23 + uVar22) {
    do {
      lVar27 = *plVar23;
      if (0 < *(int *)(lVar27 + 0x118)) {
        uVar22 = uVar36;
        uVar34 = uVar36;
        do {
          uVar22 = uVar22 + 0x520;
          uVar25 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar25;
          *(longlong *)(*(longlong *)(lVar27 + 0x110) + -0x1f0 + uVar22) = param_1 + 0x69798;
        } while ((int)uVar25 < *(int *)(lVar27 + 0x118));
      }
      uVar22 = (ulonglong)*(byte *)(param_1 + 0x697ec);
      plVar23 = plVar23 + 1;
    } while (plVar23 != (longlong *)(*(longlong *)(param_1 + 0x697b8) + uVar22 * 8));
  }
  uVar3 = *(undefined1 *)(param_1 + 0xa8825);
  *(undefined1 *)(param_1 + 0x697ed) = uVar3;
  plVar23 = *(longlong **)(param_1 + 0x697b8);
  if (plVar23 != plVar23 + uVar22) {
    do {
      lVar27 = *plVar23;
      *(undefined1 *)(lVar27 + 0xfb) = uVar3;
      *(undefined1 *)(lVar27 + 0x15f) = uVar3;
      if (0 < *(int *)(lVar27 + 0x118)) {
        uVar22 = uVar36;
        uVar34 = uVar36;
        do {
          lVar31 = *(longlong *)(lVar27 + 0x110);
          lVar18 = *(longlong *)(lVar31 + 8 + uVar22);
          *(undefined1 *)(lVar31 + 0x24a + uVar22) = uVar3;
          if (lVar18 != 0) {
            *(undefined1 *)(lVar18 + 0xb3) = uVar3;
          }
          lVar31 = *(longlong *)(lVar31 + 0x10 + uVar22);
          if (lVar31 != 0) {
            *(undefined1 *)(lVar31 + 0xb3) = uVar3;
          }
          uVar25 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar25;
          uVar22 = uVar22 + 0x520;
        } while ((int)uVar25 < *(int *)(lVar27 + 0x118));
      }
      plVar23 = plVar23 + 1;
    } while (plVar23 !=
             (longlong *)
             (*(longlong *)(param_1 + 0x697b8) + (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  FUN_1401381c0(lVar28);
  fVar13 = DAT_1402d236c;
  bVar24 = *(byte *)(param_1 + 0xa87e4);
  if (bVar24 != 0) {
    uVar22 = uVar36;
    uVar34 = uVar36;
    uVar33 = uVar36;
    do {
      lVar27 = *(longlong *)(param_1 + 0xa8248);
      lVar31 = *(longlong *)(uVar33 + 0xfe0 + lVar27);
      if (bVar24 < 2) {
        cVar30 = *(char *)(param_1 + 0xa881d);
        if ((cVar30 == '\x01') || (cVar30 == '\0')) {
          lVar27 = *(longlong *)(uVar33 + 0x1fb8 + lVar27);
          if (cVar30 == '\x01') {
            fVar38 = fVar13 * *(float *)(lVar27 + 0x2c);
LAB_1400ccf96:
            *(float *)(lVar27 + 0x2c) = fVar38;
          }
          else if (cVar30 == '\0') {
            fVar38 = *(float *)(lVar27 + 0x2c) + *(float *)(lVar27 + 0x2c);
            goto LAB_1400ccf96;
          }
          bVar24 = *(byte *)(lVar31 + 10);
          if (bVar24 != 0) {
            if (*(char *)(param_1 + 0xa881d) == '\0') {
              bVar24 = 99;
            }
            else if (*(char *)(param_1 + 0xa881d) == '\x01') {
              bVar24 = (char)((byte)((char)((int)(100 - (uint)bVar24) / 2) + bVar24) + 1 >> 1) *
                       '\x02';
            }
          }
          *(byte *)(lVar31 + 10) = bVar24;
        }
      }
      else {
        bVar24 = *(byte *)(param_1 + 0xa88b0);
        if (bVar24 == 0) {
          cVar30 = '\0';
        }
        else if (bVar24 == 1) {
          cVar30 = '\x01';
        }
        else {
          uVar19 = (ulonglong)((uint)*(byte *)(lVar31 + 10) * (uint)bVar24) / 100;
          if ((uint)uVar19 < 2) {
            uVar19 = 2;
          }
          cVar30 = (char)uVar19 + '\x01';
          if ((uVar19 & 1) == 0) {
            cVar30 = (char)uVar19;
          }
        }
        *(char *)(lVar31 + 10) = cVar30;
        if (*(byte *)(param_1 + 0xa88b1) == 0) {
          *(undefined2 *)(lVar31 + 0xb) = 0;
          uVar19 = 0;
        }
        else {
          uVar19 = (ulonglong)((uint)*(byte *)(param_1 + 0xa88b1) * (uint)*(byte *)(lVar31 + 0xb)) /
                   100;
          if ((int)uVar19 == 0) {
            uVar19 = 1;
          }
          *(char *)(lVar31 + 0xb) = (char)uVar19;
          uVar19 = (ulonglong)((uint)*(byte *)(param_1 + 0xa88b1) * (uint)*(byte *)(lVar31 + 0xc)) /
                   100;
          if ((int)uVar19 == 0) {
            uVar19 = 1;
          }
          *(char *)(lVar31 + 0xc) = (char)uVar19;
          uVar19 = (ulonglong)((uint)*(byte *)(param_1 + 0xa88b1) * (uint)*(byte *)(lVar31 + 0xd)) /
                   100;
          if ((int)uVar19 == 0) {
            uVar19 = 1;
          }
        }
        *(char *)(lVar31 + 0xd) = (char)uVar19;
        if ((*(byte *)(param_1 + 0xa88b2) & 1) != 0) {
          *(undefined1 *)(*(longlong *)(uVar33 + 0x1fb8 + lVar27) + 0x49) = 0xff;
          *(undefined1 *)(lVar31 + 0x10) = 0xff;
        }
      }
      cVar30 = *(char *)**(undefined8 **)(param_1 + 0xa8280);
      if (cVar30 == '\x02') {
LAB_1400ccfff:
        *(undefined2 *)(lVar31 + 8) = 10000;
      }
      else if (cVar30 == '\0') {
        if (*(byte *)(param_1 + 0xa881d) < 3) goto LAB_1400ccfff;
      }
      else if (cVar30 == '\x01') goto LAB_1400ccfff;
      uVar25 = (int)uVar34 + 1;
      uVar34 = (ulonglong)uVar25;
      *(undefined2 *)
       (**(longlong **)
          (*(longlong *)(*(longlong *)(uVar22 + *(longlong *)(param_1 + 0x697b8)) + 0x110) + 0x1a0)
       + 0x7f) = 0x101;
      plVar23 = (longlong *)(uVar22 + *(longlong *)(param_1 + 0x697b8));
      uVar22 = uVar22 + 8;
      lVar27 = *(longlong *)(*plVar23 + 0x110);
      lVar31 = *(longlong *)(param_1 + 0xa8248) + uVar33;
      uVar33 = uVar33 + 0x27a0;
      *(longlong *)(lVar27 + 0x1b8) = lVar31;
      *(undefined1 *)(lVar27 + 0x42b) = 1;
      bVar24 = *(byte *)(param_1 + 0xa87e4);
    } while ((int)uVar25 < (int)(uint)bVar24);
  }
  iVar37 = *(int *)(param_1 + 0xa82f0);
  if (0 < iVar37) {
    lVar27 = 0x520;
    uVar22 = uVar36;
    uVar34 = uVar36;
    do {
      lVar31 = *(longlong *)(param_1 + 0xa82f8);
      pbVar2 = (byte *)(lVar31 + 0x81 + uVar34);
      *pbVar2 = *pbVar2 & 0xf9;
      lVar18 = *(longlong *)(param_1 + 0xa82f8) + uVar34;
      if ((int)uVar22 + 1 < *(int *)(**(longlong **)(param_1 + 0x697b8) + 0x118)) {
        lVar28 = *(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110);
        *(longlong *)(lVar28 + 0x1c0 + lVar27) = lVar18;
        puVar6 = (undefined4 *)**(undefined8 **)(lVar18 + 0x48);
        if ((*(byte *)(puVar6 + 3) & 2) != 0) {
          puVar1 = (uint *)(lVar28 + 0x1f0 + lVar27);
          *puVar1 = *puVar1 | 0x8000000;
        }
        if ((*(byte *)(puVar6 + 3) & 4) != 0) {
          puVar1 = (uint *)(lVar28 + 0x1f0 + lVar27);
          *puVar1 = *puVar1 | 0x10000000;
          *(undefined4 *)(lVar28 + 0x208 + lVar27) = *puVar6;
        }
        if (*(longlong *)(lVar18 + 0x10) != 0) {
          *(longlong *)(lVar28 + 0x390 + lVar27) = *(longlong *)(lVar18 + 0x10);
          *(undefined8 *)(lVar28 + 0x398 + lVar27) = *(undefined8 *)(lVar18 + 0x10);
        }
        uVar33 = *(ulonglong *)(lVar18 + 0x18);
        uVar19 = uVar36;
        if (uVar33 != 0) {
          uVar19 = uVar33;
        }
        *(ulonglong *)(lVar28 + 0x360 + lVar27) = uVar19;
        *(bool *)(lVar28 + 0x42b + lVar27) = uVar33 != 0;
        if (*(longlong *)(lVar18 + 0x20) != 0) {
          *(longlong *)(*(longlong *)(lVar28 + 0x1a0 + lVar27) + 8) = *(longlong *)(lVar18 + 0x20);
        }
        plVar23 = *(longlong **)(lVar28 + 0x1a0 + lVar27);
        if ((*(byte *)(puVar6 + 3) & 4) != 0) {
          lVar28 = *plVar23;
          *(undefined1 *)(lVar28 + 0x7b) = 1;
          *(undefined4 *)(lVar28 + 0x4c) = *puVar6;
        }
        plVar23[4] = *(longlong *)(lVar18 + 0x28);
        plVar23[5] = *(longlong *)(lVar18 + 0x30);
      }
      *(longlong *)(lVar31 + 0x70 + uVar34) = param_1 + 0x6a130;
      uVar25 = (int)uVar22 + 1;
      uVar22 = (ulonglong)uVar25;
      iVar37 = *(int *)(param_1 + 0xa82f0);
      uVar34 = uVar34 + 0x108;
      lVar27 = lVar27 + 0x520;
    } while ((int)uVar25 < iVar37);
  }
  local_res8._0_1_ = 0;
  local_res8._1_1_ = 0;
  local_res8 = 0;
  local_res8._2_1_ = 0;
  local_res8._3_1_ = 0;
  if (*(byte *)(param_1 + 0xa87e4) != 0) {
    plVar23 = *(longlong **)(param_1 + 0x697b8);
    plVar35 = (longlong *)(*(longlong *)(param_1 + 0xa8248) + 0xff8);
    uVar34 = (ulonglong)*(byte *)(param_1 + 0xa87e4);
    uVar22 = uVar36;
    do {
      lVar27 = *plVar23;
      *(undefined1 *)((longlong)&local_res8 + uVar22) =
           *(undefined1 *)((ulonglong)*(byte *)((longlong)plVar35 + 0x17a2) + 4 + *plVar35);
      uVar22 = uVar22 + 1;
      iVar32 = *(int *)(lVar27 + 0x118);
      if (iVar37 < *(int *)(lVar27 + 0x118)) {
        iVar32 = iVar37;
      }
      if (1 < (longlong)iVar32) {
        puVar17 = (undefined8 *)(*(longlong *)(param_1 + 0xa82f8) + 0x48);
        lVar27 = (longlong)iVar32 + -1;
        do {
          plVar9 = (longlong *)*puVar17;
          pbVar2 = (byte *)((longlong)puVar17 + 0x3d);
          puVar17 = puVar17 + 0x21;
          *(undefined1 *)((longlong)&local_res8 + uVar22) =
               *(undefined1 *)((ulonglong)*pbVar2 + 4 + *plVar9);
          uVar22 = uVar22 + 1;
          lVar27 = lVar27 + -1;
        } while (lVar27 != 0);
      }
      plVar35 = plVar35 + 0x4f4;
      plVar23 = plVar23 + 1;
      uVar34 = uVar34 - 1;
    } while (uVar34 != 0);
  }
  *(undefined1 *)(param_1 + 0x89660) = (undefined1)local_res8;
  *(undefined1 *)(param_1 + 0x89661) = local_res8._1_1_;
  *(undefined1 *)(param_1 + 0x89662) = local_res8._2_1_;
  *(undefined1 *)(param_1 + 0x89663) = local_res8._3_1_;
  FUN_140140c60(param_1 + 0x6bc40,*(undefined1 *)(param_1 + 0xa881e),
                *(undefined1 *)(param_1 + 0xa881f),*(undefined1 *)(param_1 + 0xa8820),
                *(undefined1 *)(param_1 + 0xa8821));
  *(longlong *)(param_1 + 0xa87a8) = param_1 + 0x697b8;
  *(undefined8 *)(param_1 + 0xa87b8) = *(undefined8 *)(param_1 + 0x67170);
  piVar14 = DAT_14032c8f8;
  *(longlong *)(param_1 + 0xa87b0) = param_1 + 0xa8160;
  *(longlong *)(param_1 + 0xa87a0) = param_1;
  *(undefined4 *)(param_1 + 0xa87c0) = 0;
  *(undefined8 *)(param_1 + 0xa87c8) = 0;
  *(undefined8 *)(param_1 + 0xa87d0) = 0;
  *(undefined8 *)(param_1 + 0xa87d8) = 0;
  uVar16 = FUN_140200de0(piVar14,0x300,0x10);
  lVar27 = FUN_140141670(uVar16);
  piVar14 = DAT_14032c8f8;
  *(longlong *)(param_1 + 0xa8298) = lVar27;
  *(longlong *)(lVar27 + 0x280) = param_1 + 0x6a130;
  *(longlong *)(*(longlong *)(param_1 + 0xa8298) + 0x288) = param_1 + 0x697b8;
  *(undefined1 *)(*(longlong *)(param_1 + 0xa8298) + 0x2ae) = *(undefined1 *)(param_1 + 0xa8825);
  *(undefined8 *)(*(longlong *)(param_1 + 0xa8298) + 0x290) = *(undefined8 *)(param_1 + 0x67170);
  *(longlong *)(*(longlong *)(param_1 + 0xa8298) + 0x298) = param_1;
  if (*(longlong *)(*(longlong *)(param_1 + 0xa8280) + 0x28) == 0) {
    *(undefined8 *)(param_1 + 0xa8320) = 0;
    goto LAB_1400cd56b;
  }
  puVar17 = (undefined8 *)FUN_140200de0(piVar14,0x20,0x10);
  *puVar17 = 0;
  puVar17[1] = 0;
  puVar17[2] = 0;
  puVar17[3] = 0;
  *(undefined8 **)(param_1 + 0xa8320) = puVar17;
  *puVar17 = *(undefined8 *)(*(longlong *)(param_1 + 0xa8280) + 0x28);
  *(longlong *)(*(longlong *)(param_1 + 0xa8320) + 8) = param_1 + 0x69748;
  puVar17 = *(undefined8 **)(param_1 + 0xa8320);
  uVar22 = uVar36;
  if (((undefined8 *)*puVar17 != (undefined8 *)0x0) &&
     (puVar10 = *(ushort **)*puVar17, puVar10 != (ushort *)0x0)) {
    uVar22 = (ulonglong)*puVar10 << 2;
  }
  puVar20 = (undefined8 *)FUN_140200de0(piVar14,uVar22,0x10);
  if (((puVar20 != (undefined8 *)0x0) && ((undefined8 *)*puVar17 != (undefined8 *)0x0)) &&
     (puVar10 = *(ushort **)*puVar17, puVar10 != (ushort *)0x0)) {
    uVar4 = *puVar10;
    uVar34 = (ulonglong)uVar4;
    puVar17[3] = puVar20;
    uVar22 = uVar36;
    if (((uVar4 != 0) && (7 < uVar4)) &&
       ((puVar17 + 3 < puVar20 ||
        ((undefined8 *)((longlong)puVar20 + uVar34 * 4 + -4) < puVar17 + 3)))) {
      do {
        uVar25 = (int)uVar22 + 8;
        uVar22 = (ulonglong)uVar25;
      } while ((int)uVar25 < (int)(uVar4 & 0xfffffff8));
      FUN_1402777e0(puVar20,0,(ulonglong)(uVar4 >> 3) << 5);
    }
    lVar27 = (longlong)(int)uVar22;
    if (lVar27 < (longlong)uVar34) {
      if (3 < (longlong)(uVar34 - lVar27)) {
        lVar31 = lVar27 * 4;
        do {
          *(undefined4 *)(lVar31 + puVar17[3]) = 0;
          *(undefined4 *)(puVar17[3] + 4 + lVar27 * 4) = 0;
          *(undefined4 *)(puVar17[3] + 8 + lVar27 * 4) = 0;
          *(undefined4 *)(puVar17[3] + 0xc + lVar27 * 4) = 0;
          lVar27 = lVar27 + 4;
          lVar31 = lVar31 + 0x10;
        } while (lVar27 < (longlong)(uVar34 - 3));
        if ((longlong)uVar34 <= lVar27) goto LAB_1400cd550;
      }
      do {
        *(undefined4 *)(puVar17[3] + lVar27 * 4) = 0;
        lVar27 = lVar27 + 1;
      } while (lVar27 < (longlong)uVar34);
    }
  }
LAB_1400cd550:
  *(longlong *)(*(longlong *)(param_1 + 0xa8320) + 0x10) = param_1 + 0x697b8;
LAB_1400cd56b:
  lVar27 = (longlong)piVar14[6];
  uVar22 = uVar36;
  if (0 < lVar27) {
    plVar23 = *(longlong **)(piVar14 + 4);
    uVar34 = uVar36;
    do {
      plVar35 = plVar23 + 1;
      lVar31 = *plVar23;
      plVar23 = plVar23 + 3;
      uVar22 = *plVar35 + lVar31;
      if ((ulonglong)(*plVar35 + lVar31) <= uVar34) {
        uVar22 = uVar34;
      }
      lVar27 = lVar27 + -1;
      uVar34 = uVar22;
    } while (lVar27 != 0);
  }
  uVar25 = ((piVar14[2] - piVar14[3]) - (int)uVar22) + -0x4000 + *piVar14 & 0xfffffff0;
  uVar16 = FUN_140200de0(piVar14,uVar25,0x10);
  lVar27 = FUN_140019ef0();
  auVar11._8_8_ = 0;
  auVar11._0_8_ = (longlong)(int)uVar25;
  lVar31 = SUB168(ZEXT816(0x2492492492492493) * auVar11,8);
  iVar37 = 0x2000;
  *(undefined8 *)(lVar27 + 0x310) = uVar16;
  iVar32 = (int)(((ulonglong)((int)uVar25 - lVar31) >> 1) + lVar31 >> 6);
  if (iVar32 < 0x2000) {
    iVar37 = iVar32 / 2;
  }
  *(int *)(lVar27 + 0x308) = iVar37;
  lVar31 = lVar27 + 0x218;
  lVar18 = lVar27 + 0x98;
  *(longlong *)lVar31 = lVar31;
  *(longlong *)lVar18 = lVar18;
  *(longlong *)(lVar27 + 0xa0) = lVar18;
  *(undefined4 *)(lVar27 + 0x108) = 0;
  *(longlong *)(lVar27 + 0x220) = lVar31;
  *(undefined4 *)(lVar27 + 0x288) = 0;
  iVar37 = *(int *)(lVar27 + 0x308);
  if (0 < iVar37) {
    uVar22 = uVar36;
    uVar34 = uVar36;
    do {
      uVar25 = (int)uVar34 + 1;
      uVar34 = (ulonglong)uVar25;
      puVar17 = *(undefined8 **)(lVar27 + 0x220);
      plVar23 = (longlong *)(*(longlong *)(lVar27 + 0x310) + uVar22);
      uVar22 = uVar22 + 0x70;
      *puVar17 = plVar23;
      *(longlong **)(lVar27 + 0x220) = plVar23;
      *plVar23 = lVar31;
      plVar23[1] = (longlong)puVar17;
      *(int *)(lVar27 + 0x288) = *(int *)(lVar27 + 0x288) + 1;
      iVar37 = *(int *)(lVar27 + 0x308);
    } while ((int)uVar25 < iVar37);
  }
  *(int *)(lVar27 + 0x198) = iVar32 - iVar37;
  lVar31 = lVar27 + 0x1a0;
  *(longlong *)(lVar27 + 400) = (longlong)iVar37 * 0x70 + *(longlong *)(lVar27 + 0x310);
  *(longlong *)lVar31 = lVar31;
  *(longlong *)(lVar27 + 0x1a8) = lVar31;
  *(undefined4 *)(lVar27 + 0x210) = 0;
  uVar22 = uVar36;
  if (*(int *)(lVar27 + 0x198) != 0) {
    do {
      uVar25 = (int)uVar22 + 1;
      puVar17 = *(undefined8 **)(lVar27 + 0x1a8);
      plVar23 = (longlong *)(uVar22 * 0x70 + *(longlong *)(lVar27 + 400));
      *puVar17 = plVar23;
      *(longlong **)(lVar27 + 0x1a8) = plVar23;
      *plVar23 = lVar31;
      plVar23[1] = (longlong)puVar17;
      *(int *)(lVar27 + 0x210) = *(int *)(lVar27 + 0x210) + 1;
      uVar22 = (ulonglong)uVar25;
    } while (uVar25 < *(uint *)(lVar27 + 0x198));
  }
  DAT_14033d9d1 = *(undefined1 *)(param_1 + 0xa8825);
  DAT_14033d9d8 = param_1;
  lVar27 = FUN_140019ef0();
  *(longlong *)(lVar27 + 0x428) = param_1;
  if (*(char *)(param_1 + 0x697ec) != '\0') {
    uVar22 = uVar36;
    uVar34 = uVar36;
    do {
      lVar27 = *(longlong *)(*(longlong *)(param_1 + 0x697b8) + uVar34);
      iVar37 = *(int *)(lVar27 + 0x118);
      if (0 < iVar37) {
        plVar23 = (longlong *)(*(longlong *)(lVar27 + 0x110) + 0x1a0);
        uVar33 = uVar36;
        do {
          if ((((longlong *)*plVar23 != (longlong *)0x0) &&
              (lVar27 = *(longlong *)*plVar23, lVar27 != 0)) && (*(short *)(lVar27 + 0x6c) == 0x208)
             ) {
            lVar27 = FUN_140200de0(DAT_14032c8f8,0x34,0x10);
            *(undefined8 *)(lVar27 + 0x28) = 0;
            *(undefined2 *)(lVar27 + 0x32) = 300;
            *(undefined4 *)(lVar27 + 0x24) = 0;
            *(longlong *)(param_1 + 0xa8310) = lVar27;
            return 1;
          }
          uVar25 = (int)uVar33 + 1;
          uVar33 = (ulonglong)uVar25;
          plVar23 = plVar23 + 0xa4;
        } while ((int)uVar25 < iVar37);
      }
      uVar25 = (int)uVar22 + 1;
      uVar22 = (ulonglong)uVar25;
      uVar34 = uVar34 + 8;
    } while ((int)uVar25 < (int)(uint)*(byte *)(param_1 + 0x697ec));
  }
  *(undefined8 *)(param_1 + 0xa8310) = 0;
  return 1;
}

