/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010e220; RVA 0x10e220
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14010e220(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong unaff_GS_OFFSET;
  
  lVar2 = FUN_1401c56d0();
  if (param_2 == '\0') {
    DAT_140310a90 = DAT_1402d2778 * DAT_1437decf8;
    _DAT_140310ab0 = DAT_1402d2778 * DAT_1437decfc;
    DAT_140310a98 = 2;
    DAT_140310a94 = 0;
    _DAT_140310ab4 = 0;
    DAT_140310a8c = 0;
    _DAT_140310aac = 0;
    DAT_140310ab8 = 2;
    (**(code **)(**(longlong **)(param_1 + 0x1fa8) + 0x18))();
  }
  lVar1 = **(longlong **)(unaff_GS_OFFSET + 0x58);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x205c);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2060);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2064);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x206c);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2070);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2074);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2068);
  if (*(int *)(lVar1 + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  FUN_1401cb010(&DAT_1437daf20,param_1 + 0x2078);
  FUN_1400b95a0(param_1 + 0x1868);
  if ((DAT_14031f8b1 & 1) == 0) {
    FUN_140187110((int)(char)(&DAT_14031f8a8)
                             [(longlong)*(short *)(lVar2 + 6) + (ulonglong)DAT_14031f8b0 * 4],0);
  }
  return;
}

