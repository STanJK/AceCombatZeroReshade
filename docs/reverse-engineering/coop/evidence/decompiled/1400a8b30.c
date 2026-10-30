/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a8b30; RVA 0xa8b30
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a8b30(undefined8 param_1,float *param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 extraout_var [56];
  float fVar9;
  float fVar10;
  float fVar11;
  undefined1 auVar12 [64];
  float fVar13;
  float fVar14;
  float fVar15;
  undefined1 local_b8 [8];
  float fStack_b0;
  float fStack_ac;
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [8];
  float fStack_80;
  float fStack_7c;
  
  cVar1 = *(char *)(**(longlong **)(param_3 + 0x388) + 0x15d);
  if (((cVar1 == '\0') || (cVar1 == '\x02')) && (*(char *)(param_3 + 0x235) == '\0')) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  _local_b8 = ZEXT816(0);
  local_a8 = ZEXT816(0);
  lVar7 = 0;
  if (bVar6) {
    lVar7 = *(longlong *)(param_3 + 0x1b8);
  }
  local_98 = _local_b8;
  _local_88 = local_a8;
  FUN_140202920(local_b8,(float *)(param_3 + 0x268));
  fVar13 = (float)local_88._0_4_ + *(float *)(param_3 + 600);
  fVar15 = fStack_80 + *(float *)(param_3 + 0x260);
  fVar14 = (float)local_88._4_4_ + *(float *)(param_3 + 0x25c);
  fVar9 = 0.0;
  fVar11 = 0.0;
  fVar10 = 0.0;
  if (lVar7 == 0) {
    auVar12._0_8_ = FUN_140118ab0(param_3);
    auVar12._8_56_ = extraout_var;
    auVar12 = ZEXT1664(auVar12._0_16_);
  }
  else {
    if (((0x43 < *(ushort *)(lVar7 + 0x1b8)) && (0x43 < *(ushort *)(lVar7 + 0x1bc))) &&
       (*(int *)(*(longlong *)(lVar7 + 0x1d0) + 0xc) != 0)) {
      lVar8 = (ulonglong)**(ushort **)(*(longlong *)(lVar7 + 0x1d8) + 0x18) * 800;
      lVar2 = *(longlong *)(lVar7 + 0x1b0);
      fVar9 = *(float *)(lVar8 + 0xc4 + lVar2);
      fVar11 = *(float *)(lVar8 + 200 + lVar2);
      fVar10 = *(float *)(lVar8 + 0xcc + lVar2);
    }
    auVar12 = ZEXT464(*(uint *)(lVar7 + 0x1848));
  }
  if (DAT_14033bd60 == '\0') {
    lVar7 = FUN_140189320();
    fVar10 = -(((auVar12._0_4_ * DAT_1402d1de4) / (float)*(int *)(lVar7 + 0xc)) * DAT_1402d2a78) +
             fVar10;
  }
  *param_2 = fVar11 * local_a8._0_4_ + fVar9 * (float)local_b8._0_4_ +
             fVar10 * local_98._0_4_ + fVar13;
  auVar3 = vshufps_avx(local_98,local_98,0x55);
  auVar4 = vshufps_avx(local_a8,local_a8,0xaa);
  auVar5 = vshufps_avx(local_a8,local_a8,0x55);
  param_2[1] = fVar11 * auVar5._0_4_ + fVar9 * (float)local_b8._4_4_ +
               fVar10 * auVar3._0_4_ + fVar14;
  auVar3 = vshufps_avx(local_98,local_98,0xaa);
  param_2[2] = fVar11 * auVar4._0_4_ + fVar9 * fStack_b0 + fVar10 * auVar3._0_4_ + fVar15;
  auVar3 = vshufps_avx(local_a8,local_a8,0xff);
  auVar4 = vshufps_avx(local_98,local_98,0xff);
  param_2[3] = fVar11 * auVar3._0_4_ + fVar9 * fStack_ac + fVar10 * auVar4._0_4_ + fStack_7c;
  param_2[4] = *(float *)(param_3 + 0x268);
  param_2[5] = *(float *)(param_3 + 0x26c);
  param_2[6] = *(float *)(param_3 + 0x270);
  param_2[7] = *(float *)(param_3 + 0x274);
  return;
}

