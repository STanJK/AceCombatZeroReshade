/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401aa060; RVA 0x1aa060
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401aa060(longlong param_1)

{
  undefined1 auVar1 [16];
  char cVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  int iVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 *puVar11;
  longlong lVar12;
  undefined4 uVar13;
  float fVar14;
  undefined4 uVar15;
  undefined1 auVar16 [64];
  float fVar17;
  undefined1 local_res8 [8];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [6] [16];
  
  uVar8 = *(uint *)(param_1 + 0x67c) & 0xfffdffff;
  *(uint *)(param_1 + 0x67c) = uVar8;
  *(undefined2 *)(param_1 + 0x688) = 0;
  *(undefined1 *)(param_1 + 0x68a) = 0;
  iVar6 = *(int *)(**(longlong **)(DAT_14033d9d8 + 0x697b8) + 0x118);
  if (iVar6 == 1) {
    *(uint *)(param_1 + 0x67c) = uVar8 | 0x20000;
  }
  else if ((iVar6 < 4) && (lVar12 = (longlong)(iVar6 + -1), lVar12 < 3)) {
    FUN_1402777e0(lVar12 + 0x688 + param_1,CONCAT71((int7)((ulonglong)DAT_14033d9d8 >> 8),1),
                  3 - lVar12);
  }
  iVar6 = 1;
  if (1 < *(int *)(**(longlong **)(DAT_14033d9d8 + 0x697b8) + 0x118)) {
    iVar7 = 1;
    puVar11 = (undefined1 *)(param_1 + 0x688);
    lVar12 = 0x520;
    auVar16 = ZEXT864(0);
    uVar13 = DAT_1402d22d0;
    fVar14 = DAT_1402d2a34;
    uVar15 = DAT_1402d2e9c;
    fVar17 = DAT_1402d2784;
    do {
      local_88[0] = ZEXT816(0);
      lVar10 = *(longlong *)
                (*(longlong *)
                  (*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) + 0x110);
      auVar1 = *(undefined1 (*) [16])(lVar10 + 600 + lVar12);
      auVar5 = vshufps_avx(auVar1,auVar1,0xaa);
      local_a8 = auVar1._0_4_;
      auVar1 = vshufps_avx(auVar1,auVar1,0x55);
      local_a0 = auVar5._0_4_;
      local_94 = auVar1._0_4_ + fVar14;
      local_a4 = uVar15;
      local_9c = uVar13;
      local_98 = local_a8;
      local_90 = local_a0;
      local_8c = uVar13;
      uVar8 = FUN_1400782c0(*(undefined8 *)(param_1 + 0x6b0),local_88,local_res8,&local_98,&local_a8
                           );
      auVar1 = vpcmpeqd_avx(ZEXT416(uVar8),SUB6416(ZEXT464(0),0));
      auVar1 = vblendvps_avx(ZEXT416((uint)local_88[0]._4_4_),auVar16._0_16_,auVar1);
      if ((*(float *)(lVar10 + 0x25c + lVar12) < auVar1._0_4_ + fVar17) && (iVar7 + -1 < 3)) {
        *puVar11 = 1;
      }
      iVar7 = iVar7 + 1;
      lVar12 = lVar12 + 0x520;
      puVar11 = puVar11 + 1;
    } while (iVar7 < *(int *)(**(longlong **)(DAT_14033d9d8 + 0x697b8) + 0x118));
  }
  if (1 < *(int *)(**(longlong **)(DAT_14033d9d8 + 0x697b8) + 0x118)) {
    lVar10 = 0x520;
    puVar11 = (undefined1 *)(param_1 + 0x688);
    lVar12 = DAT_14033d9d8;
    do {
      lVar9 = *(longlong *)
               (*(longlong *)(*(longlong *)(lVar12 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
               0x110) + lVar10;
      if (lVar9 != 0) {
        lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x6b8) + 0xa8318) + 0x10);
        if ((((*(float *)(lVar9 + 600) < *(float *)(lVar3 + 0x348)) ||
             (*(float *)(lVar3 + 0x350) < *(float *)(lVar9 + 600))) ||
            (*(float *)(lVar9 + 0x260) < *(float *)(lVar3 + 0x34c))) ||
           (*(float *)(lVar3 + 0x354) < *(float *)(lVar9 + 0x260))) {
          *puVar11 = 1;
          lVar12 = DAT_14033d9d8;
        }
      }
      iVar6 = iVar6 + 1;
      lVar10 = lVar10 + 0x520;
      puVar11 = puVar11 + 1;
    } while (iVar6 < *(int *)(**(longlong **)(lVar12 + 0x697b8) + 0x118));
  }
  lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x6b8) + 0xa8318) + 0x10);
  if ((((lVar12 != 0) && (puVar4 = *(undefined8 **)(lVar12 + 0x2d8), puVar4 != (undefined8 *)0x0))
      && ((*(byte *)(lVar12 + 0x3c9) < *(byte *)*puVar4 &&
          (puVar4 = (undefined8 *)(puVar4[1] + (ulonglong)*(byte *)(lVar12 + 0x3c9) * 0x48),
          puVar4 != (undefined8 *)0x0)))) &&
     ((cVar2 = *(char *)*puVar4, cVar2 == '\x06' || (cVar2 == '\x04')))) {
    *(uint *)(param_1 + 0x67c) = *(uint *)(param_1 + 0x67c) | 0x20000;
  }
  if ((*(uint *)(param_1 + 0x67c) & 0x20000) != 0) {
    *(undefined2 *)(param_1 + 0x688) = 0x101;
    *(undefined1 *)(param_1 + 0x68a) = 1;
  }
  return;
}

