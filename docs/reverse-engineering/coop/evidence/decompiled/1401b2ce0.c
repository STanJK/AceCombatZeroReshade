/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b2ce0; RVA 0x1b2ce0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401b2ce0(longlong param_1)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  float fVar6;
  longlong lVar7;
  byte bVar8;
  byte bVar9;
  
  bVar8 = 0xff;
  bVar9 = 0xff;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x6b8) + 0xa8318) + 0x10);
  if (((*(longlong *)(lVar2 + 0x2d8) != 0) &&
      (lVar7 = *(longlong *)(*(longlong *)(lVar2 + 0x2d8) + 8), lVar7 != 0)) &&
     ((*(byte *)(lVar2 + 0x3a8) & 1) == 0)) {
    lVar2 = **(longlong **)(lVar7 + 0x20 + (ulonglong)*(byte *)(lVar2 + 0x3c9) * 0x48);
    bVar8 = *(byte *)(lVar2 + 0x20);
    bVar9 = *(byte *)(lVar2 + 0x21);
  }
  auVar1 = *(undefined1 (*) [16])
            (*(longlong *)
              (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8)
              + 0x110) + 600);
  auVar3 = vshufps_avx(auVar1,auVar1,0x55);
  lVar7 = (ulonglong)bVar9 * 0x520;
  lVar2 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)bVar8 * 8) + 0x110);
  fVar4 = auVar1._0_4_ - *(float *)(lVar2 + 600 + lVar7);
  fVar5 = auVar3._0_4_ - *(float *)(lVar2 + 0x25c + lVar7);
  auVar1 = vshufps_avx(auVar1,auVar1,0xaa);
  fVar6 = auVar1._0_4_ - *(float *)(lVar2 + 0x260 + lVar7);
  if (((DAT_1402d2e84 <= fVar4) && (fVar4 <= DAT_1402d28ec)) &&
     ((DAT_1402d2e4c <= fVar5 && ((fVar5 <= DAT_1402d2814 && (DAT_1402d26d4 <= fVar6)))))) {
    return fVar6 <= DAT_1402d29c8;
  }
  return false;
}

