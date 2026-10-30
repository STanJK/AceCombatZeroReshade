/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b11d0; RVA 0x1b11d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1401b11d0(longlong param_1,undefined1 (*param_2) [16])

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 auVar17 [64];
  undefined1 auVar18 [64];
  float fVar19;
  float fVar20;
  float fVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [64];
  undefined1 auStack_9a8 [32];
  float *local_988;
  undefined8 local_978;
  undefined8 uStack_970;
  uint local_964;
  float local_960;
  undefined4 local_95c;
  float local_958;
  float local_954;
  undefined8 local_950;
  undefined8 uStack_948;
  undefined1 local_940 [8];
  float fStack_938;
  undefined4 uStack_934;
  undefined8 local_918;
  undefined8 uStack_910;
  undefined1 local_908 [16];
  undefined8 local_8f8;
  undefined8 uStack_8f0;
  undefined1 local_8e8 [16];
  longlong alStack_8d8 [256];
  ulonglong local_d8;
  
  local_d8 = DAT_140309040 ^ (ulonglong)auStack_9a8;
  lVar10 = *(longlong *)(param_1 + 0x6b8);
  if (lVar10 == 0) {
    auVar22 = ZEXT416(local_964);
  }
  else if ((*(uint *)(lVar10 + 0xa8790) & 0x100) == 0) {
    auVar22 = ZEXT416(DAT_1402d287c);
  }
  else {
    auVar22 = ZEXT416((uint)(*(float *)(*(longlong *)
                                         ((longlong)*(char *)(lVar10 + 0xa8829) * 0xe90 + 0x67e18 +
                                         lVar10) + 0x10) * DAT_1402d23fc));
  }
  _local_940 = ZEXT832(0);
  auVar23 = ZEXT1664(auVar22);
  FUN_1401b71e0(*(longlong *)(DAT_14033d9d8 + 0x697b8),local_940,
                *(undefined8 *)
                 (*(longlong *)
                   (*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) + 0x110))
  ;
  uVar8 = 0;
  uVar5 = (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x6b8) + 0x697ec);
  if (1 < uVar5) {
    plVar9 = *(longlong **)(*(longlong *)(param_1 + 0x6b8) + 0x697b8);
    lVar10 = uVar5 - 1;
    auVar17 = ZEXT864(0);
    fVar12 = DAT_1402d2c24;
    fVar19 = fStack_938;
    fVar20 = (float)local_940._0_4_;
    fVar21 = (float)local_940._4_4_;
    do {
      plVar9 = plVar9 + 1;
      lVar6 = *plVar9;
      if (((*(byte *)(lVar6 + 0x120) & 4) != 0) &&
         (lVar7 = (longlong)*(int *)(lVar6 + 0x118), 0 < lVar7)) {
        lVar6 = *(longlong *)(lVar6 + 0x110);
        do {
          if ((((((byte)*(undefined4 *)(lVar6 + 0x1f0) & 3) == 3) &&
               (*(longlong *)(lVar6 + 0x3a0) != 0)) && (**(longlong **)(lVar6 + 0x1a0) != 0)) &&
             (((cVar3 = *(char *)(**(longlong **)(lVar6 + 0x1a0) + 0x71), cVar3 != '\0' ||
               (cVar3 = *(char *)(lVar6 + 0x42b), cVar3 != '\x01')) &&
              ((cVar3 == '\x02' && (fVar11 = (float)FUN_140118ab0(), fVar11 <= auVar17._0_4_)))))) {
            auVar22 = *(undefined1 (*) [16])(lVar6 + 600);
            auVar1 = vshufps_avx(auVar22,auVar22,0x55);
            fVar11 = auVar22._0_4_ - fVar20;
            fVar15 = auVar1._0_4_ - fVar21;
            auVar22 = vshufps_avx(auVar22,auVar22,0xaa);
            fVar16 = auVar22._0_4_ - fVar19;
            if ((fVar16 * fVar16 + fVar15 * fVar15 + fVar11 * fVar11 < fVar12) && (uVar8 < 0x100)) {
              uVar5 = (ulonglong)uVar8;
              uVar8 = uVar8 + 1;
              alStack_8d8[uVar5] = lVar6;
            }
          }
          lVar6 = lVar6 + 0x520;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
      }
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    if (uVar8 != 0) {
      uVar5 = FUN_140242630();
      lVar10 = alStack_8d8[(char)((uVar5 & 0xffffffff) % (ulonglong)uVar8)];
      if (lVar10 != 0) {
        local_988 = &local_960;
        local_950 = 0;
        uStack_948 = 0;
        local_978 = CONCAT44(fVar21 + DAT_1402d2a34,fVar20);
        local_95c = DAT_1402d2e9c;
        local_954 = DAT_1402d22d0;
        uStack_970 = CONCAT44(DAT_1402d22d0,fVar19);
        fVar11 = DAT_1402d22d0;
        local_960 = fVar20;
        local_958 = fVar19;
        uVar8 = FUN_1400782c0(*(undefined8 *)(param_1 + 0x6b0),&local_950,&local_964,&local_978);
        auVar22 = vpcmpeqd_avx(ZEXT416(uVar8),SUB6416(ZEXT464(0),0));
        auVar22 = vblendvps_avx(ZEXT416(local_950._4_4_),auVar17._0_16_,auVar22);
        fVar12 = fVar21 - auVar22._0_4_;
        if ((DAT_1402d291c < fVar12) && (fVar12 < DAT_1402d2aa4)) {
          auVar22 = *(undefined1 (*) [16])(lVar10 + 600);
          fVar15 = auVar22._0_4_ - fVar20;
          auVar22 = vshufps_avx(auVar22,auVar22,0xaa);
          fVar16 = auVar22._0_4_ - fVar19;
          fVar14 = SQRT(fVar16 * fVar16 + fVar15 * fVar15);
          fVar12 = auVar17._0_4_;
          if (fVar14 != fVar12) {
            fVar14 = fVar11 / fVar14;
            fVar15 = fVar14 * fVar15;
            fVar16 = fVar14 * fVar16;
          }
          if (*(longlong **)(lVar10 + 0x3a0) != (longlong *)0x0) {
            fVar12 = (float)(**(code **)(**(longlong **)(lVar10 + 0x3a0) + 0xa0))();
          }
          if ((*(longlong **)(lVar10 + 0x1a0) != (longlong *)0x0) &&
             (lVar6 = **(longlong **)(lVar10 + 0x1a0), *(char *)(lVar6 + 0x6f) == '\x01')) {
            fVar12 = *(float *)(lVar6 + 0x40);
          }
          auVar22 = *(undefined1 (*) [16])(lVar10 + 600);
          auVar1 = vmaxss_avx(ZEXT416((uint)(fVar12 * DAT_1402d24b0)),ZEXT416(DAT_1402d2a24));
          auVar18 = ZEXT1664(auVar1);
          fVar14 = auVar1._0_4_;
          *(float *)*param_2 = fVar14 * fVar15 + auVar22._0_4_;
          auVar1 = vshufps_avx(auVar22,auVar22,0xaa);
          *(float *)(*param_2 + 8) = fVar14 * fVar16 + auVar1._0_4_;
          uVar13 = vextractps_avx(auVar22,1);
          *(undefined4 *)(*param_2 + 4) = uVar13;
          uVar13 = vextractps_avx(auVar22,3);
          *(undefined4 *)(*param_2 + 0xc) = uVar13;
          fVar12 = *(float *)(param_1 + 0xa4);
          fVar15 = *(float *)(param_1 + 0x420);
          fVar14 = ((fVar12 * DAT_1402d2110) / fVar15) * fVar14;
          uVar5 = FUN_140242630();
          if ((uVar5 & 1) == 0) {
            fVar14 = ((fVar12 * DAT_1402d2d24) / fVar15) * auVar18._0_4_;
          }
          auVar22 = *param_2;
          fVar12 = fVar20 - auVar22._0_4_;
          auVar22 = vshufps_avx(auVar22,auVar22,0xaa);
          fVar15 = fVar19 - auVar22._0_4_;
          fVar15 = SQRT(fVar12 * fVar12 + fVar15 * fVar15);
          if (fVar15 != auVar17._0_4_) {
            fVar12 = (fVar11 / fVar15) * fVar12;
          }
          local_978 = CONCAT44(local_978._4_4_,auVar17._0_4_);
          uVar13 = FUN_140272370(CONCAT44(_UNK_1402d3774,(uint)fVar12 ^ DAT_1402d3770));
          local_908 = ZEXT816(0);
          local_978 = CONCAT44(uVar13,(undefined4)local_978);
          local_918 = 0;
          uStack_910 = 0;
          local_8f8 = 0;
          uStack_8f0 = 0;
          uStack_970 = CONCAT44(auVar17._0_4_,auVar17._0_4_);
          local_8e8 = local_908;
          FUN_140202920(&local_918,&local_978);
          auVar2._8_8_ = uStack_910;
          auVar2._0_8_ = local_918;
          auVar22 = vshufps_avx(auVar2,auVar2,0x55);
          *(float *)*param_2 = fVar14 * (float)local_918 + local_8e8._0_4_ + *(float *)*param_2;
          auVar1 = vshufps_avx(local_8e8,local_8e8,0x55);
          *(float *)(*param_2 + 4) =
               fVar14 * auVar22._0_4_ + auVar1._0_4_ + *(float *)(*param_2 + 4);
          auVar22 = vshufps_avx(local_8e8,local_8e8,0xaa);
          auVar1 = vshufps_avx(auVar2,auVar2,0xaa);
          *(float *)(*param_2 + 8) =
               fVar14 * auVar1._0_4_ + auVar22._0_4_ + *(float *)(*param_2 + 8);
          FUN_1401b4a20(param_1,param_2,auVar23._0_8_,1);
          *(undefined4 *)(*param_2 + 0xc) = 0x3f800000;
          if (((*(longlong **)(lVar10 + 0x1a0) == (longlong *)0x0) ||
              (lVar6 = **(longlong **)(lVar10 + 0x1a0), lVar6 == 0)) ||
             (*(short *)(lVar6 + 0x6c) != 0x150)) {
            local_978 = *(undefined8 *)*param_2;
            uStack_970 = *(undefined8 *)(*param_2 + 8);
            cVar3 = FUN_1401b4f70(param_1,&local_978);
            if (cVar3 == '\0') {
              local_960 = *(float *)*param_2;
              local_988 = (float *)&local_978;
              local_950 = 0;
              uStack_948 = 0;
              local_95c = *(undefined4 *)(*param_2 + 4);
              local_958 = *(float *)(*param_2 + 8);
              local_978 = *(undefined8 *)(lVar10 + 600);
              uStack_970 = CONCAT44(fVar11,*(undefined4 *)(lVar10 + 0x260));
              local_954 = fVar11;
              iVar4 = FUN_1400782c0(*(undefined8 *)(param_1 + 0x6b0),&local_950,&local_964,
                                    &local_960);
              if (iVar4 == 0) {
                *(undefined4 *)(param_2[1] + 0xc) = uStack_934;
                *(float *)param_2[1] = fVar20;
                *(float *)(param_2[1] + 4) = fVar21;
                *(float *)(param_2[1] + 8) = fVar19;
                return 1;
              }
            }
          }
          else {
            local_978 = *(undefined8 *)*param_2;
            uStack_970 = *(undefined8 *)(*param_2 + 8);
            FUN_1401b4f70(param_1,&local_978);
          }
        }
      }
    }
  }
  return 0;
}

