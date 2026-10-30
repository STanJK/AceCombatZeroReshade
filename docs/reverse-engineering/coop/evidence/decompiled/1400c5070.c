/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c5070; RVA 0xc5070
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c5070(longlong param_1,char param_2)

{
  char cVar1;
  longlong unaff_GS_OFFSET;
  undefined4 uVar2;
  
  if ((*(uint *)(param_1 + 0x2058) >> 0xd & 1) == 0) {
    *(uint *)(param_1 + 0x2058) = *(uint *)(param_1 + 0x2058) | 0x2000;
    cVar1 = *(char *)(param_1 + 0x2096);
    if (cVar1 == -1) {
      cVar1 = *(char *)(param_1 + 0x2094);
    }
    *(char *)(param_1 + 0x2095) = cVar1;
    *(undefined1 *)(param_1 + 0x2096) = 0xff;
  }
  *(char *)(param_1 + 0x2094) = param_2;
  *(char *)(param_1 + 0x1da6) = param_2;
  if (param_2 == '\x01') {
    uVar2 = *(undefined4 *)(param_1 + 0x1d68);
  }
  else if (param_2 == '\x02') {
    uVar2 = *(undefined4 *)(param_1 + 0x1d6c);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x1d64);
  }
  *(undefined4 *)(param_1 + 0x1d70) = uVar2;
  *(undefined4 *)(param_1 + 0x1d74) = uVar2;
  *(undefined8 *)(param_1 + 0x1d40) = 0;
  *(undefined8 *)(param_1 + 0x1d48) = 0;
  FUN_1401c56d0();
  if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
    FUN_14022d540(&DAT_1437daf04);
    if (DAT_1437daf04 == -1) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
  }
  DAT_1437dece0 = DAT_1437dece0 | 1;
  return;
}

