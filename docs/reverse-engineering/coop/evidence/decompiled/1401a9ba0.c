/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401a9ba0; RVA 0x1a9ba0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401a9ba0(longlong param_1,longlong param_2)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  char cVar3;
  undefined1 auVar4 [16];
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  uint uVar13;
  bool bVar14;
  undefined4 uVar15;
  
  *(undefined1 *)(param_1 + 0x680) = 0;
  *(longlong *)(param_1 + 0x6b8) = param_2;
  iVar9 = DAT_14033bd84;
  iVar8 = DAT_14033bd80;
  lVar12 = FUN_140189320();
  cVar3 = *(char *)(lVar12 + 0x28);
  *(undefined4 *)(param_1 + 0xa0) = 0x44200000;
  *(undefined4 *)(param_1 + 0xa8) = 0x44000000;
  *(undefined4 *)(param_1 + 0xac) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xb0) = 0x477fff00;
  *(undefined4 *)(param_1 + 0xcc) = 0x477fff00;
  if (cVar3 == '\0') {
    uVar15 = DAT_1402d290c;
  }
  else {
    uVar15 = DAT_1402d28d0;
  }
  *(uint *)(param_1 + 0x240) = *(uint *)(param_1 + 0x240) | 1;
  iVar11 = 0;
  *(undefined4 *)(param_1 + 0xa4) = uVar15;
  *(uint *)(param_1 + 0x400) = *(uint *)(param_1 + 0x400) | 1;
  *(undefined4 *)(param_1 + 0x260) = 0x44200000;
  *(undefined4 *)(param_1 + 0x264) = uVar15;
  *(undefined4 *)(param_1 + 0x268) = 0x44000000;
  *(undefined4 *)(param_1 + 0x26c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x270) = 0x477fff00;
  *(undefined4 *)(param_1 + 0x28c) = 0x477fff00;
  uVar13 = *(uint *)(param_1 + 0x67c);
  lVar12 = *(longlong *)
            (*(longlong *)
              (*(longlong *)(*(longlong *)(param_1 + 0x6b8) + 0x697b8) +
              (ulonglong)DAT_14033d9d2 * 8) + 0x110);
  uVar10 = *(uint *)(lVar12 + 0x1f0) & 2;
  if ((uVar13 >> 0x12 & 1) == 0) {
    if (uVar10 == 0) {
      *(undefined2 *)(param_1 + 0x5d0) = 0;
      *(uint *)(param_1 + 0x67c) = uVar13 | 0x40000;
      *(undefined4 *)(param_1 + 0x6f8) = *(undefined4 *)(lVar12 + 600);
      *(undefined4 *)(param_1 + 0x6fc) = *(undefined4 *)(lVar12 + 0x25c);
      *(undefined4 *)(param_1 + 0x700) = *(undefined4 *)(lVar12 + 0x260);
      *(undefined4 *)(param_1 + 0x704) = *(undefined4 *)(lVar12 + 0x264);
      uVar13 = *(uint *)(param_1 + 0x67c);
      *(undefined4 *)(param_1 + 0x5c4) = 0;
      goto LAB_1401a9d24;
    }
  }
  else if (uVar10 != 0) {
    uVar13 = uVar13 & 0xfffbffff;
LAB_1401a9d24:
    uVar13 = uVar13 | 1;
    *(undefined4 *)(param_1 + 0x664) = *(undefined4 *)(param_1 + 0x660);
  }
  *(uint *)(param_1 + 0x67c) = uVar13 & 0xfffffbff;
  if ((uVar13 >> 0x12 & 1) == 0) {
    if (iVar8 == 0) {
      if (iVar9 == 0) {
LAB_1401a9e60:
        iVar11 = FUN_1401aa7a0(param_1);
      }
      else if (iVar9 == 1) {
        iVar11 = FUN_1401ab000(param_1,1);
      }
      else if (iVar9 == 2) {
        iVar11 = FUN_1401abcf0(param_1);
      }
      else {
        if (iVar9 != 3) goto LAB_1401a9e60;
        iVar11 = FUN_1401adc40(param_1);
      }
    }
    else if (iVar8 == 1) {
      if (iVar9 == 0) {
LAB_1401a9e21:
        iVar11 = FUN_1401ae440(param_1);
      }
      else if (iVar9 == 1) {
        iVar11 = FUN_1401ae950(param_1);
      }
      else if (iVar9 == 2) {
        iVar11 = FUN_1401aea20(param_1);
      }
      else {
        if (iVar9 != 3) goto LAB_1401a9e21;
        iVar11 = FUN_1401aead0(param_1);
      }
    }
    else if (iVar8 == 2) {
      if (iVar9 == 0) {
LAB_1401a9de4:
        iVar11 = FUN_1401aebf0(param_1);
      }
      else if (iVar9 == 1) {
        iVar11 = FUN_1401aee20(param_1,1);
      }
      else if (iVar9 == 2) {
        iVar11 = FUN_1401aee20(param_1,2);
      }
      else {
        if (iVar9 != 3) goto LAB_1401a9de4;
        iVar11 = FUN_1401aee20(param_1,3);
      }
    }
    else if (iVar8 == 3) {
      iVar11 = FUN_1401afe70(param_1);
    }
    lVar12 = DAT_14032c8b8;
    *(uint *)(DAT_14032c8b8 + 0xd0) = *(uint *)(DAT_14032c8b8 + 0xd0) | 0x100;
    *(undefined1 *)(lVar12 + 0x10f) = 0x60;
    if (iVar11 == 1) {
      *(undefined4 *)(param_1 + 0x664) = *(undefined4 *)(param_1 + 0x660);
      *(uint *)(param_1 + 0x67c) = *(uint *)(param_1 + 0x67c) | 1;
    }
  }
  else {
    FUN_1401b1b80(param_1);
    lVar12 = DAT_14032c8b8;
    *(uint *)(DAT_14032c8b8 + 0xd0) = *(uint *)(DAT_14032c8b8 + 0xd0) | 0x100;
    *(undefined1 *)(lVar12 + 0x10f) = 0x60;
  }
  *(undefined1 *)(param_1 + 0x68c) = 0;
  if (iVar8 == 3) {
    if ((*(int *)(param_1 + 0x6c0) == 3) &&
       ((*(int *)(param_1 + 0x6c4) == 3 || (*(int *)(param_1 + 0x6c4) == 2)))) goto LAB_1401a9faf;
    if (*(int *)(param_1 + 0x6c0) == 0) {
LAB_1401a9efa:
      bVar14 = *(int *)(param_1 + 0x6c4) == 1;
    }
    else {
      if (*(int *)(param_1 + 0x6c0) != 3) goto LAB_1401a9f07;
      bVar14 = *(int *)(param_1 + 0x6c4) == 0;
    }
    if (bVar14) goto LAB_1401a9faf;
  }
  else if (iVar8 == 0) {
    if (iVar9 == 1) goto LAB_1401a9faf;
    if (iVar9 == 0) goto LAB_1401a9efa;
  }
LAB_1401a9f07:
  if (*(char *)(param_1 + 0x680) == '\0') {
    auVar2 = *(undefined1 (*) [16])(param_1 + 0x10);
    auVar4 = vshufps_avx(auVar2,auVar2,0x55);
    lVar12 = *(longlong *)
              (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8)
              + 0x110);
    fVar5 = auVar4._0_4_ - *(float *)(lVar12 + 0x25c);
    fVar6 = auVar2._0_4_ - *(float *)(lVar12 + 600);
    auVar2 = vshufps_avx(auVar2,auVar2,0xaa);
    fVar7 = auVar2._0_4_ - *(float *)(lVar12 + 0x260);
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x6a0) + 0x1a0);
    if (SQRT(fVar7 * fVar7 + fVar5 * fVar5 + fVar6 * fVar6) <
        *(float *)(lVar12 + 0x1c) - *(float *)(lVar12 + 0x18)) {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x6a0) + 0x2058);
      *puVar1 = *puVar1 & 0xffefffff;
      *(uint *)(param_1 + 0x67c) = *(uint *)(param_1 + 0x67c) | 1;
      *(undefined4 *)(param_1 + 0x664) = *(undefined4 *)(param_1 + 0x660);
      *(undefined1 *)(param_1 + 0x68c) = 1;
    }
  }
LAB_1401a9faf:
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x420);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x424);
  FUN_1401fbec0(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x268) = *(undefined4 *)(param_1 + 0x428);
  *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(param_1 + 0x42c);
  FUN_1401fbec0(param_1 + 0x260);
  uVar13 = (uint)DAT_14033d9d2;
  if (*(int *)(param_2 + 0x67230) < 4) {
    *(longlong *)(param_2 + 0x671f0 + (longlong)*(int *)(param_2 + 0x67230) * 8) = param_1 + 0xa0;
    *(longlong *)(param_2 + 0x67210 + (longlong)*(int *)(param_2 + 0x67230) * 8) = param_1 + 0x260;
    *(uint *)(param_2 + 0x67234 + (longlong)*(int *)(param_2 + 0x67230) * 4) = uVar13;
    *(int *)(param_2 + 0x67230) = *(int *)(param_2 + 0x67230) + 1;
  }
  *(int *)(param_1 + 0x660) = *(int *)(param_1 + 0x660) + 1;
  return;
}

