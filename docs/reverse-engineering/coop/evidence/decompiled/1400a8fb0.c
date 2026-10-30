/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a8fb0; RVA 0xa8fb0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a8fb0(longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  _DAT_14030f690 = _DAT_1402d39c0;
  uRam000000014030f698 = _UNK_1402d39c8;
  uRam000000014030f6a0 = _UNK_1402d39d0;
  uRam000000014030f6a8 = _UNK_1402d39d8;
  _DAT_14030f6b0 = _DAT_1402d31c0;
  uRam000000014030f6b8 = _UNK_1402d31c8;
  _DAT_14030f6c0 = DAT_1402d2474;
  local_28 = *param_3;
  uStack_20 = param_3[1];
  _DAT_14030f6c4 = DAT_1402d24fc;
  local_18 = *param_2;
  uStack_10 = param_2[1];
  _DAT_14030f6d4 = 3000;
  _DAT_14030f6d8 = 0x50fe;
  DAT_14030f6da = 0xb4;
  *(undefined4 *)(param_1 + 0xec8) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0xecc) = *(undefined4 *)((longlong)param_2 + 4);
  *(undefined4 *)(param_1 + 0xed0) = *(undefined4 *)(param_2 + 1);
  *(undefined4 *)(param_1 + 0xed4) = *(undefined4 *)((longlong)param_2 + 0xc);
  *(undefined4 *)(param_1 + 0xed8) = *(undefined4 *)param_3;
  *(undefined4 *)(param_1 + 0xedc) = *(undefined4 *)((longlong)param_3 + 4);
  *(undefined4 *)(param_1 + 0xee0) = *(undefined4 *)(param_3 + 1);
  *(undefined4 *)(param_1 + 0xee4) = *(undefined4 *)((longlong)param_3 + 0xc);
  *(undefined4 *)(param_1 + 0xf14) = 0x453b8000;
  *(undefined1 *)(param_1 + 0xf18) = param_5;
  *(undefined1 *)(param_1 + 0xf19) = param_6;
  *(undefined2 *)(param_1 + 0xf1a) = 0;
  *(undefined **)(param_1 + 0xf08) = &DAT_14030f690;
  *(undefined1 *)(param_1 + 0xf38) = 0;
  FUN_1400a43c0(param_1,&local_18,&local_28,param_1,param_5,param_6,0,0,&DAT_14030f690);
  return;
}

