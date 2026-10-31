/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140132240; RVA 0x132240
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140132240(longlong param_1,char param_2)

{
  undefined1 auVar1 [16];
  char cVar2;
  byte bVar3;
  char cVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  float fVar10;
  bool bVar11;
  bool bVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  longlong *plVar16;
  byte *pbVar17;
  longlong lVar18;
  longlong lVar19;
  ulonglong uVar20;
  longlong lVar21;
  ulonglong uVar22;
  float *pfVar23;
  undefined8 *puVar24;
  int iVar25;
  longlong lVar26;
  undefined4 *puVar27;
  longlong lVar28;
  uint *puVar29;
  ulonglong uVar30;
  byte bVar31;
  int iVar32;
  byte *unaff_R13;
  byte bVar33;
  uint uVar34;
  bool bVar35;
  float fVar36;
  undefined4 uVar38;
  undefined4 uVar37;
  float fVar39;
  undefined8 unaff_XMM6_Qa;
  undefined8 unaff_XMM6_Qb;
  float fVar40;
  undefined8 unaff_XMM7_Qa;
  undefined8 unaff_XMM7_Qb;
  float fVar41;
  undefined8 unaff_XMM8_Qa;
  undefined8 unaff_XMM8_Qb;
  float fVar42;
  undefined8 unaff_XMM9_Qa;
  undefined8 unaff_XMM9_Qb;
  float fVar43;
  undefined8 unaff_XMM10_Qa;
  undefined8 unaff_XMM10_Qb;
  float fVar44;
  undefined8 unaff_XMM11_Qa;
  undefined8 unaff_XMM11_Qb;
  undefined8 unaff_XMM12_Qa;
  undefined8 unaff_XMM12_Qb;
  float fVar45;
  undefined8 unaff_XMM13_Qa;
  undefined8 unaff_XMM13_Qb;
  float fVar46;
  undefined8 unaff_XMM14_Qa;
  undefined8 unaff_XMM14_Qb;
  float fVar47;
  undefined8 unaff_XMM15_Qa;
  undefined8 unaff_XMM15_Qb;
  undefined1 auStack_1d8 [32];
  undefined1 local_1b8;
  ulonglong local_1b0;
  undefined1 local_1a8;
  char local_198;
  undefined8 *local_190;
  undefined8 local_188;
  float local_180;
  undefined4 local_17c;
  undefined1 local_178 [8];
  float fStack_170;
  float fStack_16c;
  undefined1 local_168 [8];
  float fStack_160;
  float fStack_15c;
  undefined1 local_158 [8];
  float fStack_150;
  float fStack_14c;
  undefined1 local_148 [8];
  float fStack_140;
  float fStack_13c;
  byte *local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined8 local_ec;
  ulonglong local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_d8 = DAT_140309040 ^ (ulonglong)auStack_1d8;
  uVar13 = *(uint *)(param_1 + 0x118);
  puVar24 = (undefined8 *)(*(longlong **)(param_1 + 0x130))[1];
  lVar28 = **(longlong **)(param_1 + 0x130);
  *(undefined1 *)(param_1 + 0x15e) = 0;
  if ((int)uVar13 < 1) {
    uVar34 = uVar13;
  }
  else {
    uVar20 = (ulonglong)uVar13;
    plVar16 = (longlong *)(*(longlong *)(param_1 + 0x110) + 0x1a0);
    do {
      if (((*(byte *)(plVar16 + 10) & 2) != 0) &&
         ((*(longlong *)(*plVar16 + 0x20) != 0 || (*(longlong *)(*plVar16 + 0x28) != 0)))) {
        *(char *)(param_1 + 0x15e) = *(char *)(param_1 + 0x15e) + '\x01';
      }
      plVar16 = plVar16 + 0xa4;
      uVar20 = uVar20 - 1;
    } while (uVar20 != 0);
    uVar34 = *(uint *)(param_1 + 0x118);
  }
  *(undefined8 **)(param_1 + 0xa8) = puVar24;
  if (((*(byte *)(param_1 + 0x120) & 0x10) != 0) && (iVar32 = 0, 0 < (int)uVar13)) {
    lVar26 = 0;
    do {
      lVar21 = *(longlong *)(param_1 + 0x110);
      bVar33 = *(byte *)(lVar26 + 0x236 + lVar21);
      if ((((bVar33 != 0xff) && (*(char *)(lVar26 + 0x237 + lVar21) == -1)) &&
          ((*(uint *)(lVar26 + 0x1f8 + lVar21) & 0x100) != 0)) &&
         (lVar19 = *(longlong *)
                    (*(longlong *)(**(longlong **)(lVar26 + 0x180 + lVar21) + (ulonglong)bVar33 * 8)
                    + 0x110), lVar19 != -0x51ae0)) {
        *(uint *)(lVar19 + 0x51cdc) = *(uint *)(lVar19 + 0x51cdc) | 0x10;
        *(undefined1 *)(lVar19 + 0x51d1e) = *(undefined1 *)(lVar26 + 0x234 + lVar21);
        *(undefined1 *)(lVar19 + 0x51d1f) = *(undefined1 *)(lVar26 + 0x235 + lVar21);
      }
      *(undefined2 *)(lVar26 + 0x236 + lVar21) = 0xffff;
      iVar32 = iVar32 + 1;
      uVar34 = *(uint *)(param_1 + 0x118);
      lVar26 = lVar26 + 0x520;
    } while (iVar32 < (int)uVar34);
  }
  *(undefined1 *)(param_1 + 0xf6) = 0;
  local_198 = param_2;
  local_190 = puVar24;
  if (*(char *)(lVar28 + 0xd) == '\0') {
    *(undefined4 *)(param_1 + 0x124) = 0;
    *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 4;
    FUN_14012f340(param_1);
    iVar32 = 0;
    if (0 < *(int *)(param_1 + 0x118)) {
      do {
        FUN_140115c20((longlong)iVar32 * 0x520 + *(longlong *)(param_1 + 0x110));
        iVar32 = iVar32 + 1;
      } while (iVar32 < *(int *)(param_1 + 0x118));
    }
    lVar28 = *(longlong *)(param_1 + 0x110);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(lVar28 + 600);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(lVar28 + 0x25c);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(lVar28 + 0x260);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(lVar28 + 0x264);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(lVar28 + 0x268);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(lVar28 + 0x26c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(lVar28 + 0x270);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(lVar28 + 0x274);
    goto LAB_1401336f3;
  }
  bVar35 = false;
  bVar12 = false;
  bVar11 = true;
  if ((int)uVar34 < 1) {
LAB_1401324b1:
    uVar13 = *(uint *)(param_1 + 0x120);
    if ((uVar13 & 2) != 0) {
      if (bVar11) {
        uVar13 = uVar13 | 8;
      }
      *(uint *)(param_1 + 0x120) = uVar13 & 0xfffffffd;
    }
  }
  else {
    puVar29 = (uint *)(*(longlong *)(param_1 + 0x110) + 0x1f0);
    uVar20 = (ulonglong)uVar34;
    bVar11 = true;
    do {
      uVar13 = *puVar29;
      puVar29 = puVar29 + 0x148;
      if ((uVar13 & 2) != 0) {
        bVar35 = true;
      }
      if ((uVar13 & 1) != 0) {
        bVar12 = true;
      }
      if ((uVar13 >> 0x13 & 1) == 0) {
        bVar11 = false;
      }
      uVar20 = uVar20 - 1;
    } while (uVar20 != 0);
    if (!bVar35) goto LAB_1401324b1;
  }
  if ((!bVar12) && ((*(uint *)(param_1 + 0x120) & 1) != 0)) {
    *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) & 0xfffffffe;
  }
  if ((*(byte *)(param_1 + 0x120) & 1) == 0) {
    *(uint *)(param_1 + 0xf0) = *(uint *)(param_1 + 0xf0) & 0xfffffdff;
    *(undefined1 *)(param_1 + 0xf8) = 0xff;
  }
  else {
    *(uint *)(param_1 + 0xf0) = *(uint *)(param_1 + 0xf0) | 0x200;
  }
  if (puVar24 != (undefined8 *)0x0) {
    unaff_R13 = (byte *)*puVar24;
    uVar13 = 0;
    local_138 = unaff_R13;
    if (*unaff_R13 != 0) {
      do {
        uVar20 = 0;
        puVar5 = *(undefined8 **)(puVar24[1] + 8 + (longlong)(int)uVar13 * 0x10);
        if (*(char *)*puVar5 == '\0') {
          local_1b0 = local_1b0 & 0xffffffffffffff00;
          local_1b8 = 0;
          FUN_140126fd0(param_1 + 0x48,puVar5[1],uVar13 & 0xff,1);
        }
        else if (*(char *)*puVar5 == '\x01') {
          FUN_140127650(param_1 + 0x48,puVar5[2]);
        }
        if ((*(byte *)(param_1 + 0xf6) & 2) != 0) {
          FUN_140133cd0(param_1,1);
        }
        if ((*(byte *)(param_1 + 0xf6) & 4) != 0) {
          cVar4 = *(char *)(param_1 + 0xfc);
          uVar22 = uVar20;
          if (0 < *(int *)(param_1 + 0x118)) {
            do {
              lVar28 = *(longlong *)(param_1 + 0x110) + uVar20;
              if (cVar4 == '\0') {
                local_1b0 = 0;
                if ((*(uint *)(param_1 + 0xf0) >> 0x14 & 1) != 0) {
                  plVar16 = (longlong *)**(longlong **)(param_1 + 0x140) + 1;
                  if ((*(uint *)(param_1 + 0xf0) >> 0x15 & 1) == 0) {
                    plVar16 = (longlong *)**(longlong **)(param_1 + 0x140);
                  }
                  local_1b0 = *(ulonglong *)(*plVar16 + 0x110);
                  if ((lVar28 != 0) && (*(short *)(**(longlong **)(lVar28 + 0x1a0) + 0x6c) == 0x1fd)
                     ) {
                    *(uint *)(local_1b0 + 0x204) = *(uint *)(local_1b0 + 0x204) | 0x80;
                  }
                }
                local_1a8 = 3;
                local_1b8 = 6;
                local_188 = **(longlong **)(param_1 + 0x140) +
                            (ulonglong)*(byte *)(param_1 + 0x15c) * 8;
                FUN_140118040(lVar28,&local_188,0,1000);
                *(uint *)(lVar28 + 0x1f0) = *(uint *)(lVar28 + 0x1f0) & 0xffff7fff;
              }
              else if (cVar4 == '\x01') {
                *(uint *)(lVar28 + 0x1f0) = *(uint *)(lVar28 + 0x1f0) & 0xfffffffc;
              }
              else if (cVar4 == '\x02') {
                *(uint *)(lVar28 + 0x1f0) = *(uint *)(lVar28 + 0x1f0) | 0x2000;
                *(undefined2 *)(lVar28 + 0x236) = 0xffff;
              }
              uVar34 = (int)uVar22 + 1;
              uVar20 = uVar20 + 0x520;
              uVar22 = (ulonglong)uVar34;
            } while ((int)uVar34 < *(int *)(param_1 + 0x118));
            unaff_R13 = local_138;
          }
          puVar24 = local_190;
        }
        if ((*(byte *)(param_1 + 0xf6) & 1) != 0) {
          FUN_140133ae0(param_1);
        }
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < (int)(uint)*unaff_R13);
    }
  }
  plVar16 = *(longlong **)(param_1 + 0x140);
  iVar32 = 0;
  if (*(char *)((longlong)plVar16 + 0x37) != '\0') {
    lVar28 = 0;
    pfVar23 = (float *)(param_1 + 0x124);
    do {
      iVar32 = iVar32 + 1;
      auVar1 = *(undefined1 (*) [16])(*(longlong *)(lVar28 + *plVar16) + 8);
      fVar36 = auVar1._0_4_ - *(float *)(param_1 + 8);
      auVar7 = vshufps_avx(auVar1,auVar1,0xaa);
      fVar44 = auVar7._0_4_ - *(float *)(param_1 + 0x10);
      auVar7 = vshufps_avx(auVar1,auVar1,0x55);
      fVar43 = auVar7._0_4_ - *(float *)(param_1 + 0xc);
      auVar1 = vshufps_avx(auVar1,auVar1,0xff);
      fVar42 = auVar1._0_4_ - *(float *)(param_1 + 0x14);
      *pfVar23 = SQRT(fVar42 * fVar42 + fVar44 * fVar44 + fVar43 * fVar43 + fVar36 * fVar36);
      plVar16 = *(longlong **)(param_1 + 0x140);
      lVar28 = lVar28 + 8;
      pfVar23 = pfVar23 + 1;
    } while (iVar32 < (int)(uint)*(byte *)((longlong)plVar16 + 0x37));
  }
  FUN_140135500(param_1);
  iVar32 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    lVar28 = 0;
    do {
      lVar26 = *(longlong *)(param_1 + 0x110) + lVar28;
      uVar13 = *(uint *)(lVar26 + 0x1f0);
      if ((*(uint *)(param_1 + 0xf0) & 0x2000) == 0) {
        uVar13 = uVar13 & 0xffff7fff;
      }
      else {
        uVar13 = uVar13 | 0x8000;
      }
      iVar32 = iVar32 + 1;
      *(uint *)(lVar26 + 0x1f0) = uVar13;
      lVar28 = lVar28 + 0x520;
    } while (iVar32 < *(int *)(param_1 + 0x118));
  }
  if (*(char *)(param_1 + 0xf8) != -1) {
    uVar20 = (ulonglong)unaff_R13 & 0xffffffffffffff00;
    local_38 = unaff_XMM6_Qa;
    uStack_30 = unaff_XMM6_Qb;
    local_48 = unaff_XMM7_Qa;
    uStack_40 = unaff_XMM7_Qb;
    local_58 = unaff_XMM8_Qa;
    uStack_50 = unaff_XMM8_Qb;
    local_68 = unaff_XMM9_Qa;
    uStack_60 = unaff_XMM9_Qb;
    local_78 = unaff_XMM10_Qa;
    uStack_70 = unaff_XMM10_Qb;
    local_88 = unaff_XMM11_Qa;
    uStack_80 = unaff_XMM11_Qb;
    bVar33 = *(byte *)(**(longlong **)(param_1 + 0x130) + 0x10);
    local_138 = (byte *)CONCAT44(local_138._4_4_,(int)uVar20);
    local_98 = unaff_XMM12_Qa;
    uStack_90 = unaff_XMM12_Qb;
    local_a8 = unaff_XMM13_Qa;
    uStack_a0 = unaff_XMM13_Qb;
    local_b8 = unaff_XMM14_Qa;
    uStack_b0 = unaff_XMM14_Qb;
    local_c8 = unaff_XMM15_Qa;
    uStack_c0 = unaff_XMM15_Qb;
    uVar37 = 0;
    uVar38 = 0;
    if (bVar33 == 0xff) {
      if (puVar24 != (undefined8 *)0x0) {
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x14);
        FUN_1401344c0(param_1,puVar24);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x48);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x4c);
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x50);
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x54);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x58);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x5c);
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 100);
        if ((*(byte *)(param_1 + 0xf6) & 1) != 0) {
          FUN_140133ae0(param_1);
        }
        uVar20 = (ulonglong)((*(byte *)(param_1 + 0xf0) & 0x40) == 0);
      }
    }
    else {
      lVar28 = **(longlong **)(param_1 + 0x140);
      bVar31 = *(byte *)(**(longlong **)(param_1 + 0x130) + 0x11);
      lVar26 = *(longlong *)(lVar28 + (ulonglong)bVar33 * 8);
      if (bVar31 == 0xff) {
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(lVar26 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(lVar26 + 0xc);
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(lVar26 + 0x10);
        uVar14 = *(undefined4 *)(lVar26 + 0x14);
        puVar27 = (undefined4 *)(lVar26 + 0x18);
      }
      else {
        lVar26 = *(longlong *)(lVar26 + 0x110);
        lVar21 = (ulonglong)bVar31 * 0x520;
        puVar27 = (undefined4 *)(lVar21 + 0x268 + lVar26);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(lVar21 + 600 + lVar26);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(lVar21 + 0x25c + lVar26);
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(lVar21 + 0x260 + lVar26);
        uVar14 = *(undefined4 *)(lVar21 + 0x264 + lVar26);
      }
      *(undefined4 *)(param_1 + 0x14) = uVar14;
      *(undefined4 *)(param_1 + 0x18) = *puVar27;
      *(undefined4 *)(param_1 + 0x1c) = puVar27[1];
      *(undefined4 *)(param_1 + 0x20) = puVar27[2];
      *(undefined4 *)(param_1 + 0x24) = puVar27[3];
      lVar26 = param_1 + 0x48;
      uVar13 = *(uint *)(param_1 + 0x120) | 4;
      if ((*(uint *)(*(longlong *)(lVar28 + (ulonglong)bVar33 * 8) + 0x120) & 4) == 0) {
        uVar13 = *(uint *)(param_1 + 0x120) & 0xfffffffb;
      }
      *(uint *)(param_1 + 0x120) = uVar13;
      if (*(longlong *)(param_1 + 0xa8) != 0) {
        lVar21 = (ulonglong)*(byte *)(param_1 + 0xf7) * 0x40;
        lVar28 = *(longlong *)
                  (*(longlong *)(*(longlong *)(param_1 + 0xa8) + 8) + 8 +
                  (ulonglong)*(byte *)(param_1 + 0xf8) * 0x10);
        cVar4 = **(char **)(lVar28 + lVar21);
        if (cVar4 == '\x02') {
          uVar37 = uVar38;
          FUN_140127940(lVar26,*(undefined8 *)(lVar28 + 0x18 + lVar21));
        }
        else if (cVar4 == '\x03') {
          uVar37 = uVar38;
          FUN_140128500(lVar26,**(undefined8 **)(lVar28 + 0x20 + lVar21));
        }
        else if (cVar4 != '\x04') {
          if (cVar4 == '\x05') {
            uVar37 = uVar38;
            FUN_140128880(lVar26,**(undefined8 **)(lVar28 + 0x30 + lVar21));
          }
          else if (cVar4 == '\x06') {
            uVar37 = uVar38;
            FUN_140128740(lVar26,**(undefined8 **)(lVar28 + 0x38 + lVar21));
          }
        }
      }
      uVar20 = 0;
      local_128 = (undefined8 *)CONCAT44(0xffff,uVar37);
      local_120 = uVar37;
      local_118 = uVar37;
      local_110 = uVar37;
      local_108 = uVar37;
      local_100 = uVar37;
      local_f8 = uVar37;
      local_f0 = uVar37;
      uStack_11c = 0xffff;
      local_114 = 0xffff;
      local_10c = 0xffff;
      local_104 = 0xffff;
      local_fc = 0xffff;
      local_f4 = 0xffff;
      local_ec = 0xffff;
      if (((*(byte *)(param_1 + 0xf0) & 0x80) != 0) && ((*(byte *)(param_1 + 0x120) & 0x10) == 0)) {
        plVar16 = *(longlong **)(param_1 + 0x140);
        iVar32 = 0;
        if (*(char *)((longlong)plVar16 + 0x34) != '\0') {
          lVar28 = 0;
          do {
            uVar22 = 0;
            lVar26 = *plVar16;
            lVar21 = *(longlong *)(lVar28 + lVar26);
            if ((((*(byte *)(lVar21 + 0x120) & 2) != 0) &&
                (bVar33 = *(byte *)(param_1 + 0x15d),
                (&DAT_1402accc0)[(ulonglong)*(byte *)(lVar21 + 0x15d) + (ulonglong)bVar33 * 8] !=
                '\0')) && (0 < *(int *)(lVar21 + 0x118))) {
              uVar30 = uVar22;
              do {
                lVar19 = *(longlong *)(lVar21 + 0x110);
                if ((*(byte *)(lVar19 + 0x1f0 + uVar30) & 2) != 0) {
                  auVar1 = *(undefined1 (*) [16])(lVar19 + 600 + uVar30);
                  fVar36 = auVar1._0_4_ - *(float *)(param_1 + 8);
                  auVar7 = vshufps_avx(auVar1,auVar1,0xaa);
                  fVar44 = auVar7._0_4_ - *(float *)(param_1 + 0x10);
                  auVar7 = vshufps_avx(auVar1,auVar1,0x55);
                  fVar43 = auVar7._0_4_ - *(float *)(param_1 + 0xc);
                  auVar1 = vshufps_avx(auVar1,auVar1,0xff);
                  fVar42 = auVar1._0_4_ - *(float *)(param_1 + 0x14);
                  fVar36 = SQRT(fVar42 * fVar42 +
                                fVar44 * fVar44 + fVar43 * fVar43 + fVar36 * fVar36);
                  if (fVar36 < *(float *)(param_1 + 0xdc)) {
                    cVar4 = *(char *)(lVar19 + 0x235 + uVar30);
                    local_190 = (undefined8 *)
                                (ulonglong)
                                CONCAT34(CONCAT12(*(undefined1 *)(lVar21 + 0x15d),
                                                  CONCAT11(cVar4,*(undefined1 *)
                                                                  (lVar19 + 0x234 + uVar30))),fVar36
                                        );
                    if (((((byte)(bVar33 - 4) < 2) && ((char)plVar16[0xd] != '\x01')) &&
                        ((*(char *)(**(longlong **)(lVar19 + 0x1a0 + uVar30) + 0x70) != '\x02' &&
                         ((cVar2 = *(char *)(**(longlong **)(lVar19 + 0x388 + uVar30) + 0x15d),
                          cVar2 == '\0' || (cVar2 == '\x02')))))) && (cVar4 == '\0')) {
                      local_128 = local_190;
                      local_ec = CONCAT44(1,(undefined4)local_ec);
                      goto LAB_140132bf4;
                    }
                    iVar15 = 0;
                    lVar21 = 0;
                    iVar25 = (int)uVar20;
                    if (0 < iVar25) {
LAB_140132b80:
                      if (*(float *)(&local_128 + lVar21) <= fVar36) goto code_r0x000140132b8c;
                      for (lVar19 = (longlong)(iVar25 + -1); lVar21 < lVar19; lVar19 = lVar19 + -1)
                      {
                        (&local_128)[lVar19] = (&uStack_130)[lVar19];
                      }
                      (&local_128)[lVar21] = local_190;
                      uVar20 = (ulonglong)(int)local_ec._4_4_;
                      if ((int)local_ec._4_4_ < 8) {
                        (&local_128)[uVar20] = (&local_128)[(int)(local_ec._4_4_ + -1)];
                        goto LAB_140132ba9;
                      }
                      goto LAB_140132bb4;
                    }
LAB_140132b96:
                    if (iVar25 < 8) {
                      (&local_128)[iVar25] = local_190;
LAB_140132ba9:
                      uVar20 = (ulonglong)(local_ec._4_4_ + 1);
                      local_ec = CONCAT44(local_ec._4_4_ + 1,(undefined4)local_ec);
                    }
                  }
                }
LAB_140132bb4:
                lVar21 = *(longlong *)(lVar28 + lVar26);
                uVar13 = (int)uVar22 + 1;
                uVar22 = (ulonglong)uVar13;
                uVar30 = uVar30 + 0x520;
              } while ((int)uVar13 < *(int *)(lVar21 + 0x118));
            }
            iVar32 = iVar32 + 1;
            lVar28 = lVar28 + 8;
          } while (iVar32 < (int)(uint)*(byte *)((longlong)plVar16 + 0x34));
        }
      }
LAB_140132bf4:
      _local_178 = ZEXT816(0);
      _local_168 = ZEXT816(0);
      _local_158 = _local_178;
      _local_148 = _local_168;
      FUN_140202920(local_178,param_1 + 0x18);
      fVar36 = (float)local_148._0_4_ + *(float *)(param_1 + 8);
      fVar44 = fStack_140 + *(float *)(param_1 + 0x10);
      fVar43 = (float)local_148._4_4_ + *(float *)(param_1 + 0xc);
      iVar32 = 0;
      if (0 < *(int *)(param_1 + 0x118)) {
        lVar28 = 0;
        fVar42 = DAT_1402d1f38;
        fVar45 = fStack_13c;
        fVar46 = fStack_14c;
        fVar47 = fStack_150;
        do {
          lVar26 = *(longlong *)(param_1 + 0x110);
          if (((*(longlong *)(*(longlong *)(lVar26 + 0x1a0 + lVar28) + 8) != 0) ||
              (*(byte *)(param_1 + 0xf8) == 0xff)) ||
             (**(char **)((ulonglong)*(byte *)(param_1 + 0xf7) * 0x40 +
                         *(longlong *)
                          (*(longlong *)(*(longlong *)(param_1 + 0xa8) + 8) + 8 +
                          (ulonglong)*(byte *)(param_1 + 0xf8) * 0x10)) != '\x03')) {
            pfVar23 = (float *)**(undefined8 **)(lVar26 + 0x1a8 + lVar28);
            local_180 = fVar42 * pfVar23[5];
            fVar40 = *pfVar23;
            fVar39 = pfVar23[1];
            fVar41 = pfVar23[2];
            local_17c = 0;
            local_188 = CONCAT44(fVar42 * pfVar23[4],fVar42 * pfVar23[3]);
            FUN_140203050(lVar26 + 0x268 + lVar28,param_1 + 0x18);
            *(float *)(lVar26 + 600 + lVar28) =
                 fVar39 * (float)local_168._0_4_ + fVar40 * (float)local_178._0_4_ +
                 fVar41 * (float)local_158._0_4_ + fVar36;
            *(float *)(lVar26 + 0x25c + lVar28) =
                 fVar39 * (float)local_168._4_4_ + fVar40 * (float)local_178._4_4_ +
                 fVar41 * (float)local_158._4_4_ + fVar43;
            *(float *)(lVar26 + 0x260 + lVar28) =
                 fVar39 * fStack_160 + fVar40 * fStack_170 + fVar47 * fVar41 + fVar44;
            *(float *)(lVar26 + 0x264 + lVar28) =
                 fVar39 * fStack_15c + fVar40 * fStack_16c + fVar46 * fVar41 + fVar45;
            if (((*(byte *)(param_1 + 0xf0) & 0x80) != 0) &&
               ((*(byte *)(param_1 + 0x120) & 0x10) == 0)) {
              bVar33 = *(byte *)(lVar26 + 0x236 + lVar28);
              lVar21 = **(longlong **)(lVar26 + 0x1a0 + lVar28);
              if ((bVar33 == 0xff) && (*(char *)(lVar26 + 0x237 + lVar28) == -1)) {
                bVar33 = *(byte *)(param_1 + 0xfe);
                uVar20 = (ulonglong)bVar33;
                if (bVar33 != 0xff) {
                  bVar31 = *(byte *)(param_1 + 0xff);
                  lVar19 = **(longlong **)(param_1 + 0x140);
                  if (bVar31 == 0xff) {
                    iVar15 = 0;
                    if (0 < (int)local_ec._4_4_) {
                      pfVar23 = (float *)&local_128;
                      do {
                        bVar31 = *(byte *)(pfVar23 + 1);
                        if (bVar31 == bVar33) {
                          bVar3 = *(byte *)((longlong)pfVar23 + 5);
                          lVar19 = (ulonglong)bVar3 * 0x520 +
                                   *(longlong *)
                                    (*(longlong *)
                                      (**(longlong **)(param_1 + 0x140) + (ulonglong)bVar31 * 8) +
                                    0x110);
                          cVar4 = *(char *)(**(longlong **)(lVar26 + 0x388 + lVar28) + 0x15d);
                          if ((cVar4 != '\0') && (cVar4 != '\x02')) {
                            if (*(char *)(lVar21 + 0x70) == '\x01') {
                              bVar35 = *(char *)(lVar19 + 0x42b) == '\x02';
LAB_140133101:
                              if (bVar35) goto LAB_140133110;
                            }
                            else if (*(char *)(lVar21 + 0x70) == '\x02') {
                              bVar35 = *(char *)(lVar19 + 0x42b) == '\x01';
                              goto LAB_140133101;
                            }
                            if (*(float *)(lVar21 + 0x44) < *pfVar23) goto LAB_140133110;
                          }
                          if (((((bVar31 == 0xff) && (bVar3 == 0xff)) &&
                               (bVar33 = *(byte *)(lVar26 + 0x236 + lVar28), bVar33 != 0xff)) &&
                              ((*(char *)(lVar26 + 0x237 + lVar28) == -1 &&
                               ((*(uint *)(lVar26 + 0x1f8 + lVar28) & 0x100) != 0)))) &&
                             (lVar19 = *(longlong *)
                                        (*(longlong *)
                                          (**(longlong **)(lVar26 + 0x180 + lVar28) +
                                          (ulonglong)bVar33 * 8) + 0x110), lVar19 != -0x51ae0)) {
                            *(uint *)(lVar19 + 0x51cdc) = *(uint *)(lVar19 + 0x51cdc) | 0x10;
                            *(undefined1 *)(lVar19 + 0x51d1e) =
                                 *(undefined1 *)(lVar26 + 0x234 + lVar28);
                            *(undefined1 *)(lVar19 + 0x51d1f) =
                                 *(undefined1 *)(lVar26 + 0x235 + lVar28);
                          }
                          puVar29 = (uint *)(lVar26 + 0x1f0 + lVar28);
                          *puVar29 = *puVar29 | 8;
                          *(byte *)(lVar26 + 0x236 + lVar28) = bVar31;
                          *(byte *)(lVar26 + 0x237 + lVar28) = bVar3;
                          break;
                        }
LAB_140133110:
                        iVar15 = iVar15 + 1;
                        pfVar23 = pfVar23 + 2;
                      } while (iVar15 < (int)local_ec._4_4_);
                    }
                  }
                  else {
                    lVar18 = (ulonglong)bVar31 * 0x520;
                    lVar6 = *(longlong *)(*(longlong *)(lVar19 + uVar20 * 8) + 0x110);
                    if ((*(byte *)(lVar18 + 0x1f0 + lVar6) & 2) != 0) {
                      auVar1 = *(undefined1 (*) [16])(lVar26 + 600 + lVar28);
                      fVar40 = auVar1._0_4_ - *(float *)(lVar18 + 600 + lVar6);
                      auVar7 = vshufps_avx(auVar1,auVar1,0x55);
                      fVar39 = auVar7._0_4_ - *(float *)(lVar18 + 0x25c + lVar6);
                      auVar7 = vshufps_avx(auVar1,auVar1,0xaa);
                      fVar41 = auVar7._0_4_ - *(float *)(lVar18 + 0x260 + lVar6);
                      auVar1 = vshufps_avx(auVar1,auVar1,0xff);
                      fVar10 = auVar1._0_4_ - *(float *)(lVar18 + 0x264 + lVar6);
                      bVar35 = *(float *)(param_1 + 0xdc) <=
                               SQRT(fVar10 * fVar10 +
                                    fVar41 * fVar41 + fVar40 * fVar40 + fVar39 * fVar39);
                      if (bVar35) {
                        bVar31 = 0xff;
                        bVar33 = 0xff;
                      }
                      *(byte *)(lVar26 + 0x236 + lVar28) = bVar33;
                      uVar22 = 0;
                      *(byte *)(lVar26 + 0x237 + lVar28) = bVar31;
                      lVar19 = *(longlong *)(lVar19 + uVar20 * 8);
                      iVar15 = *(int *)(lVar19 + 0x118);
                      if (0 < iVar15) {
                        do {
                          if ((*(byte *)(uVar22 * 0x520 + 0x1f0 + *(longlong *)(lVar19 + 0x110)) & 2
                              ) != 0) {
                            cVar4 = *(char *)(param_1 + 0xfe);
                            if (((cVar4 == -1) && ((char)uVar22 == -1)) &&
                               ((bVar33 != 0xff &&
                                (((bVar31 == 0xff &&
                                  ((*(uint *)(lVar26 + 0x1f8 + lVar28) & 0x100) != 0)) &&
                                 (lVar21 = *(longlong *)
                                            (*(longlong *)
                                              (**(longlong **)(lVar26 + 0x180 + lVar28) +
                                              (ulonglong)bVar33 * 8) + 0x110), lVar21 != -0x51ae0)))
                                ))) {
                              *(uint *)(lVar21 + 0x51cdc) = *(uint *)(lVar21 + 0x51cdc) | 0x10;
                              *(undefined1 *)(lVar21 + 0x51d1e) =
                                   *(undefined1 *)(lVar26 + 0x234 + lVar28);
                              *(undefined1 *)(lVar21 + 0x51d1f) =
                                   *(undefined1 *)(lVar26 + 0x235 + lVar28);
                            }
                            *(char *)(lVar26 + 0x236 + lVar28) = cVar4;
                            *(char *)(lVar26 + 0x237 + lVar28) = (char)uVar22;
                            goto LAB_140132f77;
                          }
                          uVar13 = (int)uVar22 + 1;
                          uVar22 = (ulonglong)uVar13;
                        } while ((int)uVar13 < iVar15);
                      }
                      if (!bVar35) goto LAB_140132f77;
                    }
                  }
                }
                iVar15 = 0;
                if (0 < (int)local_ec._4_4_) {
                  pfVar23 = (float *)&local_128;
                  do {
                    bVar33 = *(byte *)((longlong)pfVar23 + 5);
                    bVar31 = *(byte *)(pfVar23 + 1);
                    lVar19 = (ulonglong)bVar33 * 0x520 +
                             *(longlong *)
                              (*(longlong *)
                                (**(longlong **)(param_1 + 0x140) + (ulonglong)bVar31 * 8) + 0x110);
                    if ((*(byte *)(**(longlong **)(lVar26 + 0x388 + lVar28) + 0x15d) & 0xfd) == 0) {
LAB_140133251:
                      if (((bVar31 == 0xff) && (bVar33 == 0xff)) &&
                         ((bVar3 = *(byte *)(lVar26 + 0x236 + lVar28), bVar3 != 0xff &&
                          (((*(char *)(lVar26 + 0x237 + lVar28) == -1 &&
                            ((*(uint *)(lVar26 + 0x1f8 + lVar28) & 0x100) != 0)) &&
                           (lVar21 = *(longlong *)
                                      (*(longlong *)
                                        (**(longlong **)(lVar26 + 0x180 + lVar28) +
                                        (ulonglong)bVar3 * 8) + 0x110), lVar21 != -0x51ae0)))))) {
                        *(uint *)(lVar21 + 0x51cdc) = *(uint *)(lVar21 + 0x51cdc) | 0x10;
                        *(undefined1 *)(lVar21 + 0x51d1e) = *(undefined1 *)(lVar26 + 0x234 + lVar28)
                        ;
                        *(undefined1 *)(lVar21 + 0x51d1f) = *(undefined1 *)(lVar26 + 0x235 + lVar28)
                        ;
                      }
                      puVar29 = (uint *)(lVar26 + 0x1f0 + lVar28);
                      *puVar29 = *puVar29 | 8;
                      *(byte *)(lVar26 + 0x236 + lVar28) = bVar31;
                      *(byte *)(lVar26 + 0x237 + lVar28) = bVar33;
                      break;
                    }
                    if (*(char *)(lVar21 + 0x70) == '\x02') {
                      bVar35 = *(char *)(lVar19 + 0x42b) == '\x01';
LAB_14013321f:
                      if (!bVar35) goto LAB_140133221;
                    }
                    else {
                      if (*(char *)(lVar21 + 0x70) == '\x01') {
                        bVar35 = *(char *)(lVar19 + 0x42b) == '\x02';
                        goto LAB_14013321f;
                      }
LAB_140133221:
                      if (((*pfVar23 <= *(float *)(lVar21 + 0x44)) &&
                          ((*(uint *)(lVar19 + 0x1f0) & 0x10000) == 0)) &&
                         ((*(byte *)(lVar21 + 0x73) & 8) == 0)) goto LAB_140133251;
                    }
                    iVar15 = iVar15 + 1;
                    pfVar23 = pfVar23 + 2;
                  } while (iVar15 < (int)local_ec._4_4_);
                }
              }
              else {
                bVar31 = *(byte *)(lVar26 + 0x237 + lVar28);
                if ((*(byte *)(*(longlong *)
                                (*(longlong *)
                                  (**(longlong **)(param_1 + 0x140) + (ulonglong)bVar33 * 8) + 0x110
                                ) + 0x1f0 + (ulonglong)bVar31 * 0x520) & 2) != 0) {
                  if (*(byte *)(param_1 + 0xfe) == bVar33) goto LAB_140132f77;
                  uVar20 = (ulonglong)local_ec._4_4_;
                  bVar11 = false;
                  bVar35 = false;
                  if (0 < (int)local_ec._4_4_) {
                    pbVar17 = (byte *)((longlong)&local_128 + 5);
                    do {
                      if (pbVar17[-1] == bVar33) {
                        bVar35 = bVar11;
                        if (*pbVar17 == bVar31) {
                          bVar35 = true;
                          bVar11 = true;
                        }
                      }
                      pbVar17 = pbVar17 + 8;
                      uVar20 = uVar20 - 1;
                    } while (uVar20 != 0);
                    if (bVar35) goto LAB_140132f77;
                  }
                }
                puVar29 = (uint *)(lVar26 + 0x1f0 + lVar28);
                *puVar29 = *puVar29 & 0xffffff77;
                *(undefined2 *)(lVar26 + 0x236 + lVar28) = 0xffff;
                *(undefined1 *)(lVar26 + 0x249 + lVar28) = 0;
              }
            }
          }
LAB_140132f77:
          iVar32 = iVar32 + 1;
          lVar28 = lVar28 + 0x520;
        } while (iVar32 < *(int *)(param_1 + 0x118));
      }
      uVar20 = (ulonglong)local_138 & 0xffffffff;
    }
    iVar32 = 0;
    if ((local_198 == '\x01') && ((*(uint *)(param_1 + 0x120) & 4) == 0)) {
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 4;
    }
    if ((*(uint *)(param_1 + 0x120) & 4) == 0) {
      if (((*(uint *)(param_1 + 0x120) & 1) != 0) &&
         ((*(byte *)(param_1 + 0xf8) == 0xff ||
          (**(char **)((ulonglong)*(byte *)(param_1 + 0xf7) * 0x40 +
                      *(longlong *)
                       (*(longlong *)(*(longlong *)(param_1 + 0xa8) + 8) + 8 +
                       (ulonglong)*(byte *)(param_1 + 0xf8) * 0x10)) != '\x03')))) {
        _local_178 = ZEXT816(0);
        _local_168 = ZEXT816(0);
        _local_158 = _local_178;
        _local_148 = _local_168;
        FUN_140202920(local_178,param_1 + 0x18);
        fVar36 = (float)local_148._0_4_ + *(float *)(param_1 + 8);
        fVar44 = fStack_140 + *(float *)(param_1 + 0x10);
        fVar43 = (float)local_148._4_4_ + *(float *)(param_1 + 0xc);
        if (0 < *(int *)(param_1 + 0x118)) {
          lVar28 = 0;
          lVar26 = 0;
          fVar42 = fStack_13c;
          fVar45 = fStack_14c;
          fVar46 = fStack_150;
          fVar47 = (float)local_158._4_4_;
          do {
            lVar21 = *(longlong *)(param_1 + 0x110);
            pfVar23 = *(float **)(lVar26 + *(longlong *)(*(longlong *)(param_1 + 0x130) + 0x10));
            lVar19 = *(longlong *)(lVar21 + 0x368 + lVar28);
            if ((lVar19 == 0) || ((*(byte *)(lVar19 + 0x2e9) & 1) == 0)) {
              local_188 = *(longlong *)(pfVar23 + 3);
              fVar40 = *pfVar23;
              fVar39 = pfVar23[1];
              fVar41 = pfVar23[2];
              local_180 = pfVar23[5];
              local_17c = 0;
              FUN_140203050(lVar21 + 0x268 + lVar28,param_1 + 0x18);
              *(float *)(lVar21 + 600 + lVar28) =
                   fVar39 * (float)local_168._0_4_ + fVar40 * (float)local_178._0_4_ +
                   fVar41 * (float)local_158._0_4_ + fVar36;
              fVar10 = fVar39 * (float)local_168._4_4_ + fVar40 * (float)local_178._4_4_ +
                       fVar47 * fVar41 + fVar43;
              *(float *)(lVar21 + 0x260 + lVar28) =
                   fVar39 * fStack_160 + fVar40 * fStack_170 + fVar46 * fVar41 + fVar44;
              *(float *)(lVar21 + 0x264 + lVar28) =
                   fVar39 * fStack_15c + fVar40 * fStack_16c + fVar45 * fVar41 + fVar42;
              *(float *)(lVar21 + 0x25c + lVar28) = fVar10;
              if ((*(longlong *)(lVar21 + 0x360 + lVar28) != 0) &&
                 (((*(uint *)(param_1 + 0xf0) & 0x400) != 0 &&
                  (fVar40 = *(float *)(**(longlong **)(param_1 + 0x130) + 8), fVar10 < fVar40)))) {
                *(float *)(lVar21 + 0x25c + lVar28) = fVar40;
              }
            }
            iVar32 = iVar32 + 1;
            lVar26 = lVar26 + 0x10;
            lVar28 = lVar28 + 0x520;
          } while (iVar32 < *(int *)(param_1 + 0x118));
        }
      }
    }
    else {
      iVar32 = 0;
      if (0 < *(int *)(param_1 + 0x118)) {
        lVar28 = 0;
        do {
          lVar26 = *(longlong *)(param_1 + 0x110) + lVar28;
          uVar13 = *(uint *)(lVar26 + 0x1f0);
          if ((char)uVar20 == '\0') {
            uVar13 = uVar13 | 0x20000;
          }
          else {
            uVar13 = uVar13 & 0xfffdffff;
          }
          *(uint *)(lVar26 + 0x1f0) = uVar13;
          FUN_140115c20();
          iVar32 = iVar32 + 1;
          lVar28 = lVar28 + 0x520;
        } while (iVar32 < *(int *)(param_1 + 0x118));
      }
      if (((char)uVar20 != '\0') &&
         ((*(byte *)(param_1 + 0xf8) == 0xff ||
          (**(char **)((ulonglong)*(byte *)(param_1 + 0xf7) * 0x40 +
                      *(longlong *)
                       (*(longlong *)(*(longlong *)(param_1 + 0xa8) + 8) + 8 +
                       (ulonglong)*(byte *)(param_1 + 0xf8) * 0x10)) != '\x03')))) {
        FUN_140133cd0(param_1,0);
      }
    }
  }
LAB_1401336f3:
  iVar32 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    lVar28 = 0;
    do {
      lVar26 = *(longlong *)(param_1 + 0x110);
      lVar21 = *(longlong *)(lVar26 + 0x360 + lVar28);
      if (lVar21 != 0) {
        auVar1 = *(undefined1 (*) [16])(lVar26 + 600 + lVar28);
        auVar7 = vshufps_avx(auVar1,auVar1,0x55);
        fVar36 = *(float *)(lVar26 + 0x27c + lVar28);
        auVar8 = vshufps_avx(auVar1,auVar1,0xaa);
        fVar44 = *(float *)(lVar26 + 0x280 + lVar28);
        auVar9 = vshufps_avx(auVar1,auVar1,0xff);
        fVar43 = *(float *)(lVar26 + 0x284 + lVar28);
        *(float *)(lVar21 + 0x3f8) = auVar1._0_4_ - *(float *)(lVar26 + 0x278 + lVar28);
        *(float *)(lVar21 + 0x3fc) = auVar7._0_4_ - fVar36;
        *(float *)(lVar21 + 0x400) = auVar8._0_4_ - fVar44;
        *(float *)(lVar21 + 0x404) = auVar9._0_4_ - fVar43;
        *(undefined4 *)(*(longlong *)(lVar26 + 0x360 + lVar28) + 0x404) = 0;
        *(undefined4 *)(lVar26 + 0x278 + lVar28) = *(undefined4 *)(lVar26 + 600 + lVar28);
        *(undefined4 *)(lVar26 + 0x27c + lVar28) = *(undefined4 *)(lVar26 + 0x25c + lVar28);
        *(undefined4 *)(lVar26 + 0x280 + lVar28) = *(undefined4 *)(lVar26 + 0x260 + lVar28);
        *(undefined4 *)(lVar26 + 0x284 + lVar28) = *(undefined4 *)(lVar26 + 0x264 + lVar28);
        bVar33 = *(byte *)(lVar26 + 0x236 + lVar28);
        if ((bVar33 == 0xff) || (bVar31 = *(byte *)(lVar26 + 0x237 + lVar28), bVar31 == 0xff)) {
          if (*(char *)(*(longlong *)(lVar26 + 0x360 + lVar28) + 0x4ca) != '\0') goto LAB_140133852;
        }
        else {
          plVar16 = *(longlong **)
                     (*(longlong *)
                       (*(longlong *)(**(longlong **)(param_1 + 0x140) + (ulonglong)bVar33 * 8) +
                       0x110) + 0x1a0 + (ulonglong)bVar31 * 0x520);
          if ((plVar16 != (longlong *)0x0) &&
             ((cVar4 = *(char *)(*plVar16 + 0x75), cVar4 == '\x01' || (cVar4 == '\0')))) {
LAB_140133852:
            puVar29 = (uint *)(lVar26 + 0x1f0 + lVar28);
            *puVar29 = *puVar29 & 0xffffff7f;
          }
        }
      }
      iVar32 = iVar32 + 1;
      lVar28 = lVar28 + 0x520;
    } while (iVar32 < *(int *)(param_1 + 0x118));
  }
  return;
code_r0x000140132b8c:
  iVar15 = iVar15 + 1;
  lVar21 = lVar21 + 1;
  if (iVar25 <= iVar15) goto LAB_140132b96;
  goto LAB_140132b80;
}

