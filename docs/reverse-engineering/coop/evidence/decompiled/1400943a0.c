/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400943a0; RVA 0x943a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1400943a0(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  uint uVar8;
  longlong lVar9;
  byte *pbVar10;
  uint uVar11;
  longlong lVar12;
  float fVar13;
  undefined1 auVar14 [64];
  undefined1 auVar15 [64];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [8];
  float fStack_70;
  undefined4 uStack_6c;
  
  pbVar10 = (byte *)(param_1 + 0xde);
  uVar11 = 1;
  lVar12 = 0x10;
  auVar14 = ZEXT464(DAT_1402d271c);
  auVar15 = ZEXT464(DAT_1402d291c);
  fVar13 = DAT_1402d264c;
  do {
    if ((*(uint *)(param_1 + 0x5c) & uVar11) != 0) {
      local_a8 = ZEXT816(0);
      local_98 = ZEXT816(0);
      lVar1 = *(longlong *)(param_1 + 0x68 + (ulonglong)*pbVar10 * 8);
      local_88 = local_a8;
      _local_78 = local_98;
      FUN_140202920(local_a8);
      auVar2 = _local_78;
      local_78._4_4_ = *(float *)(pbVar10 + -0x5a) + (float)local_78._4_4_;
      local_78._0_4_ = *(float *)(pbVar10 + -0x5e) + (float)local_78._0_4_;
      fStack_70 = auVar2._8_4_;
      uStack_6c = auVar2._12_4_;
      fStack_70 = *(float *)(pbVar10 + -0x56) + fStack_70;
      if (lVar1 != 0) {
        fVar3 = *(float *)(param_3 + 0x3c) - *(float *)(pbVar10 + -0x52);
        pfVar7 = *(float **)(lVar1 + 0x10);
        uVar8 = 0;
        fVar4 = *(float *)(param_3 + 0x30) - *(float *)(pbVar10 + -0x5e);
        fVar5 = *(float *)(param_3 + 0x34) - *(float *)(pbVar10 + -0x5a);
        fVar6 = *(float *)(param_3 + 0x38) - *(float *)(pbVar10 + -0x56);
        lVar9 = 0;
        do {
          if (SQRT(fVar3 * fVar3 + fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5) *
              (auVar15._0_4_ / *(float *)(param_3 + 8)) < *pfVar7) {
            if (uVar8 < 3) {
              auVar2 = vminss_avx(ZEXT416((uint)(fVar13 * *(float *)(pbVar10 + -10))),auVar14._0_16_
                                 );
              FUN_140162e80(lVar1,fVar13 * *(float *)(pbVar10 + -10),auVar2._0_8_);
              FUN_14015e840(*(undefined8 *)(lVar1 + 0x30 + lVar9 * 8));
              param_2 = FUN_14015e8a0(*(undefined8 *)(lVar1 + 0x30 + lVar9 * 8),param_2,local_a8);
            }
            break;
          }
          uVar8 = uVar8 + 1;
          lVar9 = lVar9 + 1;
          pfVar7 = pfVar7 + 1;
        } while (lVar9 < 3);
      }
    }
    uVar11 = uVar11 << 1 | (uint)((int)uVar11 < 0);
    pbVar10 = pbVar10 + 0x68;
    lVar12 = lVar12 + -1;
    if (lVar12 == 0) {
      return param_2;
    }
  } while( true );
}

