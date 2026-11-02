/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140193cc0; RVA 0x193cc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Removing unreachable block (ram,0x000140194239) */
/* WARNING: Removing unreachable block (ram,0x00014019417f) */
/* WARNING: Removing unreachable block (ram,0x00014019427a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140193cc0(longlong param_1,undefined4 *param_2,undefined1 *param_3,undefined4 *param_4,
                  undefined1 *param_5)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  float fVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint *puVar11;
  ulonglong *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong *puVar16;
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  longlong lVar22;
  undefined4 uVar23;
  byte *pbVar24;
  uint uVar25;
  ulonglong *puVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [64];
  float fVar33;
  float fVar34;
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  float fVar37;
  undefined4 uStack_16c;
  ulonglong *local_168;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  
  puVar26 = (ulonglong *)(param_1 + 0x328);
  lVar9 = 0x1a0;
  if ((*(byte *)(param_1 + 0x198) & 1) != 0) {
    lVar9 = 200;
  }
  if ((*(uint *)(lVar9 + param_1) >> 9 & 1) == 0) {
    local_168 = (ulonglong *)(param_1 + 0x188);
    puVar16 = (ulonglong *)(param_1 + 0x338);
    puVar12 = (ulonglong *)(param_1 + 0x2c8);
  }
  else {
    local_168 = (ulonglong *)(param_1 + 400);
    puVar12 = (ulonglong *)(param_1 + 0x2d0);
    puVar16 = (ulonglong *)(param_1 + 0x340);
    puVar26 = (ulonglong *)(param_1 + 0x330);
  }
  uVar15 = *puVar12;
  uVar14 = *puVar12;
  uVar19 = (uint)uVar15 & 0xfff;
  uVar6 = (uint)(uVar14 >> 0x10) & 0xfff;
  uVar25 = (uint)(uVar14 >> 0x20) & 0xfff;
  uVar7 = uVar6 + 1;
  uVar18 = ((ushort)(uVar14 >> 0x30) & 0xfff) + 1;
  if (*puVar26 >> 0x20 == 0xff000000) {
    *param_3 = 0;
  }
  else if (*puVar26 >> 0x20 == 0xffffff) {
    *param_2 = 8;
  }
  if ((*puVar16 & 0x100000000) != 0) {
    *param_5 = 0;
  }
  uVar21 = 0;
  uVar8 = (uint)*puVar26 & 0x1ff;
  lVar9 = 0;
  if ((uVar8 == 0x8c) || (uVar8 == 0x70)) {
    if (DAT_14030cac4 != -1) {
      FUN_14020e490();
    }
    *(float *)(param_1 + 0x73c) = (float)DAT_1403566c8;
    iVar20 = -1;
    *(float *)(param_1 + 0x740) = (float)(int)DAT_1403566cc;
    *param_4 = 3;
    DAT_14030cac4 = -1;
  }
  else {
    uVar10 = (ulonglong)uVar8 << 5;
    uVar13 = ((uVar10 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^ (ulonglong)(uVar8 >> 3)) *
             -0x3aad8475ae2c2d25 & *(ulonglong *)(param_1 + 0x78);
    lVar22 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8 + uVar13 * 0x10);
    if (lVar22 == *(longlong *)(param_1 + 0x50)) {
LAB_140193e81:
      lVar22 = 0;
    }
    else {
      uVar2 = *(ulonglong *)(lVar22 + 0x10);
      while (uVar10 != uVar2) {
        if (lVar22 == *(longlong *)(*(longlong *)(param_1 + 0x60) + uVar13 * 0x10))
        goto LAB_140193e81;
        lVar22 = *(longlong *)(lVar22 + 8);
        uVar2 = *(ulonglong *)(lVar22 + 0x10);
      }
    }
    if ((lVar22 != 0) && (lVar22 != *(longlong *)(param_1 + 0x50))) {
      lVar9 = *(longlong *)(lVar22 + 0x18);
    }
    if (DAT_14030cac4 != *(int *)(lVar9 + 0x28)) {
      if (DAT_14030cac4 != -1) {
        FUN_14020e490(DAT_14030cac4);
      }
      FUN_14020e000(*(undefined4 *)(lVar9 + 0x28));
      DAT_14030cac4 = *(int *)(lVar9 + 0x28);
    }
    iVar20 = DAT_14030cac4;
    if ((int)uVar10 == 0) {
      if (((uint)*puVar26 >> 0x1e & 1) == 0) goto LAB_140193f03;
    }
    else if ((int)uVar10 == 0x3360) {
LAB_140193f03:
      *(float *)(param_1 + 0x73c) = (float)DAT_1403566c0;
      *(float *)(param_1 + 0x740) = (float)DAT_1403566c4;
      if (((uint)*puVar26 >> 0x10 & 0x3f) == 10) {
        if ((DAT_140310e8c == 1) && (DAT_14032c92a != '\0')) {
          *(undefined4 *)(param_1 + 0x73c) = DAT_1402d2958;
        }
        else {
          *(float *)(param_1 + 0x73c) =
               (float)((int)(DAT_1403566c0 * 0x280 + (DAT_1403566c0 * 0x280 >> 0x1f & 0x1ffU)) >> 9)
          ;
        }
      }
      else {
        lVar22 = FUN_140189320();
        iVar20 = DAT_14030cac4;
        if (*(char *)(lVar22 + 0x28) != '\0') {
          *(undefined4 *)(param_1 + 0x73c) = 0x44000000;
        }
      }
      goto LAB_140193ffb;
    }
    *(float *)(param_1 + 0x73c) = (float)*(int *)(lVar9 + 0x14);
    *(float *)(param_1 + 0x740) = (float)*(int *)(lVar9 + 0x18);
  }
LAB_140193ffb:
  fVar27 = DAT_1402d1fbc;
  fVar28 = DAT_1402d1ef4;
  fVar5 = DAT_1402d1ed4;
  uVar8 = (uint)*puVar26;
  uVar10 = (ulonglong)(uVar8 & 0x1ff);
  if ((uVar10 == 0x108) ||
     (((uVar10 * 0x20 - 0x2140 & 0xffffffffffffff3f) == 0 && (uVar10 != 0x110)))) {
    pbVar24 = (byte *)(param_1 + 200);
    if ((*(byte *)(param_1 + 0x198) & 1) == 0) {
      pbVar24 = (byte *)(param_1 + 0x1a0);
    }
    if (uVar10 == 0x108) {
      lVar22 = 0;
    }
    else if (uVar10 == 0x10a) {
      lVar22 = 1;
    }
    else if ((uVar8 & 0x1ff) == 0x10c) {
      lVar22 = 2;
    }
    else {
      lVar22 = 0;
      if ((uVar8 & 0x1ff) == 0x10e) {
        lVar22 = 3;
      }
    }
    if ((*pbVar24 >> 4 & 1) == 0) {
      *(undefined8 *)(&DAT_14033bc60 + lVar22 * 4) = 0;
      (&DAT_14033bc68)[lVar22 * 4] = 0x3f800000;
      (&DAT_14033bc6c)[lVar22 * 4] = 0x3f800000;
    }
    else if ((*(byte *)(param_1 + 200) & 7) == 6) {
      uVar10 = (ulonglong)*(uint *)(param_1 + 0x708);
      auVar32 = ZEXT464(DAT_1402d2a54);
      auVar30 = ZEXT416(DAT_1402d2a54);
      auVar35 = ZEXT816(0);
      auVar36 = ZEXT816(0);
      auVar31 = auVar30;
      if (0 < (int)*(uint *)(param_1 + 0x708)) {
        puVar11 = *(uint **)(param_1 + 0x6f8);
        do {
          uVar8 = *puVar11;
          puVar1 = puVar11 + 1;
          puVar11 = puVar11 + 0x10;
          auVar31 = vminss_avx(ZEXT416(uVar8),auVar32._0_16_);
          auVar32 = ZEXT1664(auVar31);
          auVar35 = vmaxss_avx(ZEXT416(uVar8),auVar35);
          auVar30 = vminss_avx(ZEXT416(*puVar1),auVar30);
          auVar36 = vmaxss_avx(ZEXT416(*puVar1),auVar36);
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      uVar10 = *local_168;
      fVar37 = (float)(uVar10 & 0xffff);
      (&DAT_14033bc60)[lVar22 * 4] =
           (-(fVar37 * DAT_1402d1fbc) + auVar31._0_4_) * DAT_1402d1ed4 - DAT_1402d1ef4;
      fVar29 = (float)((uint)(uVar10 >> 0x20) & 0xffff);
      (&DAT_14033bc64)[lVar22 * 4] = (-(fVar29 * fVar27) + auVar30._0_4_) * fVar5 - fVar28;
      (&DAT_14033bc68)[lVar22 * 4] = (-(fVar37 * fVar27) + auVar35._0_4_) * fVar5 + fVar28;
      (&DAT_14033bc6c)[lVar22 * 4] = (-(fVar29 * fVar27) + auVar36._0_4_) * fVar5 + fVar28;
    }
  }
  fVar5 = DAT_1402d2168;
  uVar10 = *puVar26;
  fVar28 = (float)(ushort)*local_168;
  if ((uVar10 & 0x400001ff) == 0) {
    *(float *)(param_1 + 0x744) =
         fVar28 * fVar27 + (float)((ulonglong)((uint)(uVar10 >> 0x10) & 0x3f) << 5);
    fVar29 = (float)*(ushort *)((longlong)local_168 + 4);
    fVar28 = (float)(DAT_1403566c4 / 2);
  }
  else if (((uint)uVar10 & 0x1ff) == 0x19b) {
    *(float *)(param_1 + 0x744) = fVar28 * fVar27 + DAT_1402d287c;
    fVar29 = (float)*(ushort *)((longlong)local_168 + 4);
    fVar28 = DAT_1402d2840;
  }
  else {
    fVar29 = *(float *)(param_1 + 0x740);
    *(float *)(param_1 + 0x744) = fVar28 * fVar27 + DAT_1402d2168 * *(float *)(param_1 + 0x73c);
    fVar28 = (float)*(ushort *)((longlong)local_168 + 4) * fVar27;
    fVar27 = fVar5;
  }
  uVar10 = 0;
  *(float *)(param_1 + 0x748) = fVar27 * fVar29 + fVar28;
  uVar8 = DAT_1403566cc;
  if (lVar9 == 0) {
    return;
  }
  if (DAT_14030cab8 == iVar20) {
    if (((uVar19 == 0) && ((uVar14 & 0xfff00000000) == 0)) &&
       (((uVar13 = *puVar26, uVar7 == ((uint)(uVar13 >> 0x10) & 0x3f) * 0x40 && (uVar18 == 0x1c0))
        || (uVar10 = uVar13 >> 0x1e, (uVar10 & 1) != 0)))) {
      if (((uVar7 == 0x200) || ((uVar13 >> 0x1e & 1) != 0)) &&
         (lVar9 = FUN_140189320(), *(char *)(lVar9 + 0x28) != '\0')) {
        uVar10 = (ulonglong)DAT_1403566d4;
        uVar15 = 0;
        uVar14 = 0;
        uVar7 = DAT_1403566d0;
      }
      else {
        uVar15 = 0;
        if (uVar7 == 0x280) {
          uVar10 = (ulonglong)DAT_1403566d4;
          uVar14 = 0;
          uVar7 = DAT_1403566d0;
        }
        else {
          uVar10 = (ulonglong)DAT_1403566cc;
          uVar14 = CONCAT44(uStack_16c,(int)((float)DAT_1403566c8 * DAT_1402d2018));
          uVar7 = (int)((float)DAT_1403566c8 * DAT_1402d2240);
        }
      }
      goto LAB_1401947ca;
    }
LAB_14019443f:
    if (((uint)*puVar26 >> 0x1e & 1) == 0) {
      if ((((uVar14 & 0xfff00000000) == 0) && (uVar18 == 0x1c0)) &&
         ((((uint)uVar15 & 0xeff) == 0 && ((uVar6 - 0xff & 0xfffffeff) == 0)))) {
        if (uVar19 == 0) {
          uVar18 = 0;
        }
        else {
          uVar18 = DAT_1403566c8 / 2;
        }
        iVar20 = (uVar7 == 0x100) + 1;
        uVar6 = DAT_1403566c8 / iVar20;
        lVar9 = FUN_140189320(DAT_1403566c8,(longlong)DAT_1403566c8 % (longlong)iVar20 & 0xffffffff)
        ;
        if (*(char *)(lVar9 + 0x28) == '\0') {
          if (uVar19 == 0) {
            uVar18 = (uint)((float)DAT_1403566c8 * DAT_1402d2018);
          }
          if (uVar7 == 0x200) {
            uVar6 = (uint)((float)(int)uVar6 - (float)DAT_1403566c8 * DAT_1402d2018);
          }
        }
        uVar10 = (ulonglong)uVar8;
        uVar15 = 0;
        uVar14 = (ulonglong)uVar18;
        uVar7 = uVar6;
      }
      else {
        fVar28 = (float)DAT_1403566c8 * DAT_1402d1de0;
        uVar23 = (undefined4)((ulonglong)local_168 >> 0x20);
        uVar17 = (undefined4)(uVar10 >> 0x20);
        if ((uVar18 != 0x1a5) || ((uVar25 != 0x122 && (uVar25 != 0xd9)))) {
          auVar30 = vcvtdq2ps_avx(ZEXT416(uVar18));
          fVar28 = *(float *)(param_1 + 0x73c);
          fVar37 = (float)DAT_1403566c8 / fVar28;
          auVar35 = vpcmpeqd_avx(ZEXT416(uVar19),SUB6416(ZEXT464(0),0));
          auVar3 = vcvtdq2ps_avx(ZEXT416(uVar19));
          auVar35 = vblendvps_avx(ZEXT416((uint)(auVar3._0_4_ - fVar5)),auVar3,auVar35);
          auVar31 = vpcmpeqd_avx(ZEXT416(uVar25),SUB6416(ZEXT464(0),0));
          auVar36 = vcvtdq2ps_avx(ZEXT416(uVar25));
          auVar36 = vblendvps_avx(ZEXT416((uint)(auVar36._0_4_ - fVar5)),auVar36,auVar31);
          fVar27 = *(float *)(param_1 + 0x740);
          auVar4 = vcvtdq2ps_avx(ZEXT416(uVar7));
          auVar31 = vcmpss_avx(auVar4,ZEXT416((uint)fVar28),0);
          auVar31 = vblendvps_avx(ZEXT416((uint)(auVar4._0_4_ - fVar5)),auVar4,auVar31);
          fVar29 = auVar31._0_4_;
          auVar31 = vcmpss_avx(auVar30,ZEXT416((uint)fVar27),0);
          auVar31 = vblendvps_avx(ZEXT416((uint)(auVar30._0_4_ - fVar5)),auVar30,auVar31);
          auVar30 = vcmpss_avx(auVar3,ZEXT416((uint)(fVar27 * fVar5)),0);
          auVar35 = vblendvps_avx(auVar35,auVar3,auVar30);
          if (auVar4._0_4_ == fVar27 * fVar5) {
            fVar29 = (float)uVar7;
          }
          fVar34 = (float)(int)(fVar37 * auVar35._0_4_ + fVar5);
          fVar33 = (float)(int)(auVar36._0_4_ * ((float)(int)DAT_1403566cc / fVar27) + fVar5);
          auVar35._0_4_ = (float)(int)(fVar37 * fVar29 + fVar5);
          auVar35._4_12_ = SUB1612(ZEXT816(0),4);
          if ((uVar19 == 0) || (fVar34 < 0.0)) {
            fVar34 = 0.0;
          }
          if (((uVar14 & 0xfff00000000) == 0) || (fVar33 < 0.0)) {
            fVar33 = 0.0;
          }
          auVar36 = vcvtdq2ps_avx(ZEXT416(DAT_1403566d4));
          auVar31 = vminss_avx(auVar36,ZEXT416((uint)(float)(int)(auVar31._0_4_ *
                                                                  ((float)(int)DAT_1403566cc /
                                                                  fVar27) + fVar5)));
          auVar36 = vcvtdq2ps_avx(ZEXT416(DAT_1403566d0));
          auVar36 = vminss_avx(auVar36,auVar35);
          auVar35 = vcvtdq2ps_avx(ZEXT416((uint)(int)(fVar37 * (float)(int)((fVar28 - DAT_1402d291c)
                                                                           * fVar5) + fVar5)));
          FUN_14020eeb0(CONCAT44(uStack_16c,(int)(auVar35._0_4_ + fVar34)),
                        CONCAT44(uVar17,(int)fVar33),(int)(auVar36._0_4_ + auVar35._0_4_),
                        CONCAT44(uVar23,(int)auVar31._0_4_));
          return;
        }
        local_158 = _DAT_1402d3da0;
        uStack_150 = _UNK_1402d3da8;
        uStack_148 = _UNK_1402d3db0;
        uStack_140 = _UNK_1402d3db8;
        local_138 = _DAT_1402d3d80;
        uStack_130 = _UNK_1402d3d88;
        uStack_128 = _UNK_1402d3d90;
        uStack_120 = _UNK_1402d3d98;
        local_118 = _DAT_1402d3de0;
        uStack_110 = _UNK_1402d3de8;
        uStack_108 = _UNK_1402d3df0;
        uStack_100 = _UNK_1402d3df8;
        local_f8 = _DAT_1402d3dc0;
        uStack_f0 = _UNK_1402d3dc8;
        uStack_e8 = _UNK_1402d3dd0;
        uStack_e0 = _UNK_1402d3dd8;
        if (uVar19 != 0x1f) {
          if (uVar19 == 0x11f) {
            uVar21 = 1;
          }
          else {
            uVar21 = (uVar19 != 0xf) + 2;
          }
        }
        uVar18 = uVar21 + 4;
        if (uVar25 != 0xd9) {
          uVar18 = uVar21;
        }
        uVar15 = (ulonglong)uVar18;
        uVar10 = CONCAT44(uVar23,(int)((float)*(int *)((longlong)&uStack_150 + uVar15 * 0x10 + 4) *
                                      fVar28));
        uVar7 = (uint)((float)*(int *)(&uStack_150 + uVar15 * 2) * fVar28);
        uVar14 = (ulonglong)(uint)(int)((float)*(int *)(&local_158 + uVar15 * 2) * fVar28);
        uVar15 = CONCAT44(uVar17,(int)((float)*(int *)((longlong)&local_158 + uVar15 * 0x10 + 4) *
                                      fVar28));
      }
      goto LAB_1401947ca;
    }
  }
  else if (DAT_14030cabc == iVar20) goto LAB_14019443f;
  uVar10 = (ulonglong)uVar18;
  uVar15 = (ulonglong)uVar25;
  uVar14 = (ulonglong)uVar19;
LAB_1401947ca:
  FUN_14020eeb0(uVar14,uVar15,uVar7,uVar10);
  return;
}

