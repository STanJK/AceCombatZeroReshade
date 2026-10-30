/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c11c0; RVA 0xc11c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c11c0(longlong param_1)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auVar6 [16];
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  longlong *plVar11;
  char cVar12;
  longlong lVar13;
  longlong lVar14;
  int iVar15;
  bool bVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [8];
  float fStack_70;
  float fStack_6c;
  undefined1 local_68 [8];
  float fStack_60;
  float fStack_5c;
  
  if ((*(byte *)(param_1 + 0xb2) == 0xff) && (*(char *)(param_1 + 0xb3) == -1)) {
    return;
  }
  bVar16 = *(char *)(*(longlong *)(param_1 + 0xa0) + 0x2098) == '\x01';
  *(bool *)(param_1 + 0x1e) = bVar16;
  *(bool *)(param_1 + 0x3e) = bVar16;
  *(bool *)(param_1 + 0x5e) = bVar16;
  *(bool *)(param_1 + 0x7e) = bVar16;
  local_98 = ZEXT816(0);
  local_88 = ZEXT816(0);
  lVar13 = (ulonglong)*(byte *)(param_1 + 0xb3) * 0x520;
  lVar5 = *(longlong *)
           (*(longlong *)
             (**(longlong **)(param_1 + 0x98) + (ulonglong)*(byte *)(param_1 + 0xb2) * 8) + 0x110);
  _local_78 = local_98;
  _local_68 = local_88;
  FUN_140202920(local_98,lVar5 + 0x268 + lVar13);
  plVar11 = *(longlong **)(param_1 + 0x98);
  iVar15 = 0;
  if (*(char *)((longlong)plVar11 + 0x34) != '\0') {
    lVar14 = 0;
    do {
      lVar9 = *plVar11;
      iVar10 = 0;
      lVar7 = *(longlong *)(lVar14 + lVar9);
      if (0 < *(int *)(lVar7 + 0x118)) {
        lVar8 = 0;
        do {
          lVar8 = lVar8 + 0x520;
          iVar10 = iVar10 + 1;
          puVar1 = (uint *)(*(longlong *)(lVar7 + 0x110) + -0x330 + lVar8);
          *puVar1 = *puVar1 & 0xfffffff7;
          lVar7 = *(longlong *)(lVar14 + lVar9);
        } while (iVar10 < *(int *)(lVar7 + 0x118));
      }
      plVar11 = *(longlong **)(param_1 + 0x98);
      iVar15 = iVar15 + 1;
      lVar14 = lVar14 + 8;
    } while (iVar15 < (int)(uint)*(byte *)((longlong)plVar11 + 0x34));
  }
  bVar16 = false;
  if (*(byte *)(param_1 + 0xb4) != 0xff) {
    if (*(byte *)(param_1 + 0xb5) != 0xff) {
      lVar9 = (ulonglong)*(byte *)(param_1 + 0xb5) * 0x520;
      lVar14 = *(longlong *)
                (*(longlong *)(*plVar11 + (ulonglong)*(byte *)(param_1 + 0xb4) * 8) + 0x110);
      uVar4 = *(uint *)(lVar14 + 0x1f0 + lVar9);
      if ((uVar4 & 2) == 0) {
        *(undefined2 *)(param_1 + 0xb4) = 0xffff;
      }
      else if ((uVar4 >> 0xd & 1) == 0) {
        auVar2 = *(undefined1 (*) [16])(lVar14 + 600 + lVar9);
        fVar20 = auVar2._0_4_ - *(float *)(lVar5 + 600 + lVar13);
        auVar6 = vshufps_avx(auVar2,auVar2,0x55);
        fVar21 = auVar6._0_4_ - *(float *)(lVar5 + 0x25c + lVar13);
        auVar6 = vshufps_avx(auVar2,auVar2,0xaa);
        fVar22 = auVar6._0_4_ - *(float *)(lVar5 + 0x260 + lVar13);
        auVar2 = vshufps_avx(auVar2,auVar2,0xff);
        fVar19 = auVar2._0_4_ - *(float *)(lVar5 + 0x264 + lVar13);
        fVar18 = SQRT(fVar19 * fVar19 + fVar22 * fVar22 + fVar21 * fVar21 + fVar20 * fVar20);
        if (fVar18 <= DAT_1402d2b90) {
          if (fVar18 <= *(float *)(param_1 + 0xa8)) {
            if (fVar18 != 0.0) {
              fVar18 = DAT_1402d22d0 / fVar18;
              fVar20 = fVar18 * fVar20;
              fVar21 = fVar18 * fVar21;
              fVar22 = fVar18 * fVar22;
              fVar19 = fVar18 * fVar19;
            }
            bVar16 = false;
            if ((fStack_5c - fStack_6c) * fVar19 +
                (fStack_60 - fStack_70) * fVar22 +
                ((float)local_68._4_4_ - (float)local_78._4_4_) * fVar21 +
                fVar20 * ((float)local_68._0_4_ - (float)local_78._0_4_) <
                *(float *)(param_1 + 0xac)) {
              bVar16 = true;
            }
          }
          else {
            bVar16 = true;
          }
        }
        else {
          *(undefined2 *)(param_1 + 0xb4) = 0xffff;
        }
      }
      else {
        *(undefined2 *)(param_1 + 0xb4) = 0xffff;
      }
    }
  }
  bVar17 = *(short *)(param_1 + 0xb0) == 0;
  if (!bVar17) {
    *(short *)(param_1 + 0xb0) = *(short *)(param_1 + 0xb0) + -1;
  }
  cVar12 = '\0';
  if (((char)*(byte *)(param_1 + 0xb6) < '\0') && (*(longlong *)(param_1 + 0xa0) != 0)) {
    cVar12 = '\x05';
    FUN_1400c1f80(param_1);
  }
  else if ((*(byte *)(param_1 + 0xb6) & 0x40) != 0) {
    cVar12 = '\x04';
    FUN_1400c22c0(param_1);
  }
  if ((*(char *)(param_1 + 0xb4) == -1) && (*(char *)(param_1 + 0xb5) == -1)) {
    if ((*(byte *)(param_1 + 0xb6) & 3) != 0) {
      *(byte *)(param_1 + 0xb6) = *(byte *)(param_1 + 0xb6) & 0xef;
      FUN_1400c15d0(param_1);
      goto LAB_1400c1588;
    }
  }
  else {
    bVar3 = *(byte *)(param_1 + 0xb6);
    if (-1 < (char)bVar3) {
      if ((bVar3 & 1) == 0) {
        if ((bVar3 & 2) == 0) {
          if ((bVar3 & 0x20) == 0) goto LAB_1400c1588;
          goto LAB_1400c153e;
        }
        if ((bVar16) || (cVar12 = '\x03', bVar17)) {
          cVar12 = '\x01';
        }
        *(byte *)(param_1 + 0xb6) = bVar3 | 0x10;
      }
      else {
        if ((bVar16) || (cVar12 = '\x02', bVar17)) {
          cVar12 = '\x01';
        }
        *(byte *)(param_1 + 0xb6) = bVar3 | 0x10;
      }
    }
    if (cVar12 != '\x01') {
      if (cVar12 == '\x02') {
        FUN_1400c1c20(param_1);
      }
      goto LAB_1400c1588;
    }
  }
LAB_1400c153e:
  FUN_1400c15d0(param_1);
LAB_1400c1588:
  FUN_1400c0740(param_1);
  *(byte *)(param_1 + 0xb6) = *(byte *)(param_1 + 0xb6) & 0xfc;
  return;
}

