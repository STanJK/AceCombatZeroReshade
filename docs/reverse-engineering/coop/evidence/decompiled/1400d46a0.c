/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d46a0; RVA 0xd46a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400d46a0(longlong param_1,int param_2)

{
  undefined *puVar1;
  longlong lVar2;
  longlong lVar3;
  float *pfVar4;
  undefined *puVar5;
  longlong lVar6;
  longlong lVar7;
  
  DAT_1403283a8 = 0;
  DAT_1403283ac = 0;
  lVar6 = *(longlong *)
           (param_1 + ((longlong)param_2 + 0xce32 + (longlong)*(char *)(param_1 + 0xa8829) * 2) * 8)
  ;
  *(longlong *)((longlong)*(char *)(param_1 + 0xa8829) * 5000 + *(longlong *)(param_1 + 0x67130)) =
       lVar6 + 0x2f0;
  lVar2 = *(longlong *)(param_1 + 0x67138);
  lVar7 = (longlong)*(char *)(param_1 + 0xa8829) * 0xd10;
  lVar3 = *(longlong *)(param_1 + 0x671b0 + (longlong)*(char *)(param_1 + 0xa8829) * 8);
  *(longlong *)(lVar2 + 8 + lVar7) = lVar6 + 0x50;
  *(longlong *)(lVar2 + lVar7) = lVar6 + 0x30;
  *(longlong *)(lVar2 + 0xaa8 + lVar7) = lVar3 + 0xb0;
  *(longlong *)(lVar2 + 0xaa0 + lVar7) = lVar3;
  *(longlong *)(lVar2 + 0x1f8 + lVar7) = lVar3;
  *(longlong *)(lVar2 + 0xd00 + lVar7) = lVar3;
  *(longlong *)(lVar2 + 0x9e0 + lVar7) = lVar6 + 0x270;
  *(longlong *)(lVar2 + 0x968 + lVar7) = lVar6 + 0x270;
  *(longlong *)(lVar2 + 0x978 + lVar7) = lVar6 + 0x280;
  *(longlong *)(lVar2 + 0x988 + lVar7) = lVar6 + 0x290;
  *(longlong *)(lVar2 + 0x998 + lVar7) = lVar6 + 0x2a0;
  *(longlong *)(lVar2 + 0x9a8 + lVar7) = lVar6 + 0x2b0;
  *(longlong *)(lVar2 + 0x9b8 + lVar7) = lVar6 + 0x2c0;
  *(longlong *)(lVar2 + 0x9c8 + lVar7) = lVar6 + 0x2d0;
  *(longlong *)(lVar2 + 0x9d8 + lVar7) = lVar6 + 0x2e0;
  *(longlong *)(lVar2 + 0x7f8 + lVar7) = *(longlong *)(lVar2 + lVar7) + 0x160;
  FUN_14006da40();
  pfVar4 = *(float **)(lVar2 + lVar7);
  *(int *)(lVar2 + 0xa80 + lVar7) = (int)*(short *)(pfVar4 + 6);
  *(uint *)(lVar2 + 0xa84 + lVar7) =
       (((uint)(longlong)pfVar4[2] | 0xffff8000) << 8 | (uint)(longlong)pfVar4[1]) << 8 |
       (uint)(longlong)*pfVar4;
  *(longlong *)((longlong)*(char *)(param_1 + 0xa8829) * 0x1c8 + *(longlong *)(param_1 + 0x67140)) =
       lVar6;
  *(longlong *)((longlong)*(char *)(param_1 + 0xa8829) * 0x140 + *(longlong *)(param_1 + 0x67148)) =
       lVar6 + 0x20;
  puVar1 = (undefined *)(lVar6 + 0x310);
  lVar6 = (longlong)*(char *)(param_1 + 0xa8829) * 0xe90;
  puVar5 = &DAT_14031edb0;
  if (puVar1 != (undefined *)0x0) {
    puVar5 = puVar1;
  }
  *(undefined **)(lVar6 + 0x67e08 + param_1) = puVar1;
  *(undefined **)(lVar6 + 0x67e18 + param_1) = puVar5;
  FUN_140189320();
  return;
}

