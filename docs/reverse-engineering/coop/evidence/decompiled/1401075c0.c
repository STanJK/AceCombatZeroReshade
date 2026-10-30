/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401075c0; RVA 0x1075c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401075c0(longlong param_1,undefined8 param_2)

{
  byte *pbVar1;
  char *pcVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  float fVar7;
  byte bVar8;
  char cVar9;
  char cVar10;
  undefined1 uVar11;
  short sVar12;
  uint uVar13;
  longlong lVar14;
  undefined4 *puVar15;
  longlong lVar16;
  char *pcVar17;
  byte bVar18;
  byte bVar19;
  int iVar20;
  ushort uVar21;
  undefined4 uVar22;
  uint uVar23;
  ushort uVar24;
  undefined2 uVar25;
  undefined1 (*pauVar26) [16];
  longlong lVar27;
  longlong unaff_GS_OFFSET;
  undefined8 uVar28;
  ulonglong extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  ulonglong extraout_XMM0_Qa_01;
  ulonglong extraout_XMM0_Qa_02;
  ulonglong extraout_XMM0_Qa_03;
  ulonglong uVar29;
  undefined8 extraout_XMM0_Qa_04;
  undefined4 uVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [64];
  undefined1 auVar33 [64];
  undefined4 local_res8;
  undefined8 local_res10;
  undefined2 local_res18 [4];
  longlong local_res20;
  undefined8 in_stack_fffffffffffffee8;
  undefined8 *puVar34;
  undefined1 *puVar35;
  undefined8 in_stack_fffffffffffffef0;
  undefined4 uVar36;
  undefined8 in_stack_fffffffffffffef8;
  undefined8 uVar37;
  uint *puVar38;
  undefined8 local_d8;
  uint local_d0;
  undefined4 local_cc;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [16];
  undefined4 local_98;
  float local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  undefined4 local_74;
  uint local_70;
  
  uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
  uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
  uVar22 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  DAT_14032c480 = DAT_14032c480 + 1;
  *(undefined1 *)(param_1 + 0x20a5) = *(undefined1 *)(param_1 + 0x2094);
  local_res10 = param_2;
  uVar28 = FUN_1401c56d0();
  uVar23 = 0;
  local_c8 = *(undefined1 (*) [16])(param_1 + 0x70);
  auVar32 = ZEXT1664(local_c8);
  auVar33 = ZEXT864(0);
  lVar27 = (ulonglong)*(byte *)(param_1 + 0x20a2) * 0x520;
  lVar14 = *(longlong *)
            (*(longlong *)
              (**(longlong **)(param_1 + 0x2040) + (ulonglong)*(byte *)(param_1 + 0x20a1) * 8) +
            0x110);
  local_res20 = lVar27;
  local_d8 = lVar14;
  if ((*(byte *)(lVar14 + 0x1f0 + lVar27) & 1) == 0) {
    FUN_14010e220(param_1,1);
  }
  else {
    if (0 < *(short *)(param_1 + 0x208c)) {
      if (1 < *(short *)(param_1 + 0x208c)) {
        FUN_14010e220(param_1,1);
      }
      uVar28 = FUN_14010f500();
      *(uint *)(param_1 + 0x2058) = *(uint *)(param_1 + 0x2058) | 0x200;
    }
    *(short *)(param_1 + 0x208c) = *(short *)(param_1 + 0x208c) + -1;
    if (*(short *)(param_1 + 0x208c) < -0xff) {
      *(undefined2 *)(param_1 + 0x208c) = 0xff01;
    }
    pcVar17 = (char *)(param_1 + 0xc3b);
    if ((*(uint *)(param_1 + 0xd48) & 0x10000) == 0) {
      cVar10 = '\x02';
    }
    else {
      cVar10 = *pcVar17;
    }
    pcVar2 = (char *)(param_1 + 0x272f);
    *pcVar2 = *pcVar2 + -1;
    puVar38 = (uint *)(param_1 + 0x205c);
    if (*pcVar2 < '\0') {
      *(undefined1 *)(param_1 + 0x272f) = 0;
      uVar28 = FUN_1401c56d0();
      FUN_1401c6490(uVar28,puVar38);
      if (((byte)(cVar10 - 1U) < 2) && ((*(uint *)(param_1 + 0xd48) & 0x10000) != 0)) {
        *pcVar17 = '\x03';
      }
    }
    else {
      cVar9 = FUN_1401c5910(uVar28,puVar38);
      if (cVar9 == '\0') {
        uVar21 = 3;
        local_res8 = CONCAT22(local_res8._2_2_,3);
        if (*(longlong *)(param_1 + 0x1fa8) != 0) {
          uVar21 = (ushort)*(byte *)(*(longlong *)(param_1 + 0x1fa8) + 0x40);
          local_res8 = CONCAT22(local_res8._2_2_,uVar21);
        }
        local_b8 = _DAT_1402d35f0;
        uStack_b0 = _UNK_1402d35f8;
        uVar30 = auVar33._0_4_;
        if (*(char *)(param_1 + 0x2094) == '\x01') {
          puVar34 = &local_b8;
          uVar37 = CONCAT44(uVar22,uVar30);
          uVar28 = CONCAT44(uVar36,uVar30);
          cVar9 = FUN_1401c6a00(_DAT_1402d35f0,uVar21,2,local_c8,puVar34,uVar28,uVar37,uVar30,uVar30
                                ,0,0);
          uVar30 = (undefined4)((ulonglong)puVar34 >> 0x20);
          uVar36 = (undefined4)((ulonglong)uVar28 >> 0x20);
          uVar22 = (undefined4)((ulonglong)uVar37 >> 0x20);
          if (cVar9 != '\0') {
            lVar14 = FUN_1401c97a0();
            uVar13 = *puVar38;
            if ((((uVar13 == 0) || (0x7f < (ushort)uVar13)) ||
                ((short)(uVar13 >> 0x10) !=
                 *(short *)(lVar14 + 2 + (ulonglong)(uVar13 & 0xffff) * 2))) &&
               ((int)(uint)uVar21 < (int)*(char *)(lVar14 + 0x3dc2))) {
              uVar21 = *(ushort *)(lVar14 + ((ulonglong)uVar21 * 3 + 0x24) * 8);
              bVar8 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar21 * 0x18) + 0xb2);
              puVar15 = (undefined4 *)FUN_1401c9e60(lVar14);
              auVar31 = auVar32._0_16_;
              if (puVar15 != (undefined4 *)0x0) {
                *(undefined2 *)((longlong)puVar15 + 0x46) = 2;
LAB_140107a15:
                *(ushort *)(puVar15 + 0x11) = uVar21;
                *puVar15 = auVar31._0_4_;
                uVar4 = vextractps_avx(auVar31,1);
                puVar15[1] = uVar4;
                uVar4 = vextractps_avx(auVar31,2);
                puVar15[2] = uVar4;
                uVar4 = vextractps_avx(auVar31,3);
                puVar15[3] = uVar4;
                *(undefined8 *)(puVar15 + 4) = 0;
                puVar15[6] = 0;
                *(undefined8 *)(puVar15 + 7) = 0x3f800000;
                *(undefined8 *)(puVar15 + 9) = 0;
                puVar15[0xb] = 0x3f800000;
                puVar15[0xf] = 0x3f800000;
                *(undefined2 *)((longlong)puVar15 + 0x4a) = 0;
                *(byte *)(puVar15 + 0x1c) = *(byte *)(puVar15 + 0x1c) & 0xef | 2;
                *puVar38 = puVar15[0xe];
                if ((bVar8 & 1) == 0) {
                  *(byte *)(puVar15 + 0x1c) = *(byte *)(puVar15 + 0x1c) & 0xfa;
                  *(code **)(puVar15 + 0xc) = FUN_1401caa00;
                }
                else {
                  *(byte *)(puVar15 + 0x1c) = *(byte *)(puVar15 + 0x1c) & 0xfb | 1;
                  *(code **)(puVar15 + 0xc) = FUN_1401ca740;
                }
              }
            }
          }
        }
        else {
          puVar34 = &local_b8;
          if (*(char *)(param_1 + 0x2094) == '\0') {
            uVar37 = CONCAT44(uVar22,uVar30);
            uVar28 = CONCAT44(uVar36,uVar30);
            cVar9 = FUN_1401c6a00(_DAT_1402d35f0,uVar21,0,local_c8,puVar34,uVar28,uVar37,uVar30,
                                  uVar30,0,0);
            uVar30 = (undefined4)((ulonglong)puVar34 >> 0x20);
            uVar36 = (undefined4)((ulonglong)uVar28 >> 0x20);
            uVar22 = (undefined4)((ulonglong)uVar37 >> 0x20);
            if (cVar9 != '\0') {
              lVar14 = FUN_1401c97a0();
              uVar13 = *puVar38;
              if ((((uVar13 == 0) || (0x7f < (ushort)uVar13)) ||
                  ((short)(uVar13 >> 0x10) !=
                   *(short *)(lVar14 + 2 + (ulonglong)(uVar13 & 0xffff) * 2))) &&
                 ((int)(uint)uVar21 < (int)*(char *)(lVar14 + 0x3dc2))) {
                uVar21 = *(ushort *)(lVar14 + ((ulonglong)uVar21 * 3 + 0x24) * 8);
                bVar8 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar21 * 0x18) + 0x12);
                puVar15 = (undefined4 *)FUN_1401c9e60(lVar14);
                auVar31 = auVar32._0_16_;
                if (puVar15 != (undefined4 *)0x0) {
                  *(undefined2 *)((longlong)puVar15 + 0x46) = 0;
                  goto LAB_140107a15;
                }
              }
            }
          }
          else {
            puVar35 = local_a8;
            local_a8._8_8_ = _UNK_1402d35f8;
            local_a8._0_8_ = _DAT_1402d35f0;
            local_res18[0] = 1;
            FUN_1401c5c30(_DAT_1402d35f0,&local_res8,local_res18,local_c8,puVar35,puVar34,puVar38);
            uVar30 = (undefined4)((ulonglong)puVar35 >> 0x20);
            uVar36 = (undefined4)((ulonglong)puVar34 >> 0x20);
            uVar22 = (undefined4)((ulonglong)puVar38 >> 0x20);
          }
        }
      }
      else if (*(char *)(param_1 + 0x2094) == *(char *)(param_1 + 0x20a5)) {
        FUN_1401c6260(extraout_XMM0_Qa_00,puVar38,local_c8);
      }
      else {
        FUN_1401c6490();
      }
      if (((cVar10 == '\x03') || (cVar10 == '\0')) && ((*(uint *)(param_1 + 0xd48) & 0x10000) != 0))
      {
        *pcVar17 = '\x01';
      }
    }
    if ((*(char *)(param_1 + 0x20a3) == '\"') &&
       (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x14')) {
      if ((*(uint *)(param_1 + 0xd48) & 0x40000) == 0) {
LAB_14010775d:
        if ((*(float *)(param_1 + 0xcb4) <= DAT_1402d264c) ||
           (DAT_1402d2674 <= *(float *)(param_1 + 0xcb4))) goto LAB_140107781;
      }
      else {
        cVar10 = *(char *)(param_1 + 0xc3d);
        if ((((cVar10 != '\x03') && (cVar10 != '\0')) ||
            (DAT_1402d271c <= *(float *)(param_1 + 0xcb4))) ||
           (*(float *)(param_1 + 0xcb4) <= DAT_1402d26f8)) {
          if (1 < (byte)(cVar10 - 1U)) goto LAB_140107781;
          goto LAB_14010775d;
        }
      }
      FUN_14010bc20(param_1);
    }
LAB_140107781:
    lVar14 = *(longlong *)(param_1 + 0x1fa8);
    uVar11 = *(undefined1 *)(param_1 + 0x2094);
    pbVar1 = (byte *)(lVar14 + 0x44);
    *pbVar1 = *pbVar1 & 0xfd;
    *(undefined1 *)(lVar14 + 0x41) = uVar11;
    lVar14 = *(longlong *)(param_1 + 0x1fa8);
    *(undefined4 *)(lVar14 + 0x4c) = *(undefined4 *)(param_1 + 0x70);
    *(undefined4 *)(lVar14 + 0x50) = *(undefined4 *)(param_1 + 0x74);
    *(undefined4 *)(lVar14 + 0x54) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(lVar14 + 0x58) = *(undefined4 *)(param_1 + 0x7c);
    lVar14 = *(longlong *)(param_1 + 0x1fa8);
    *(undefined4 *)(lVar14 + 0x5c) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(lVar14 + 0x60) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(lVar14 + 100) = *(undefined4 *)(param_1 + 0x88);
    *(undefined4 *)(lVar14 + 0x68) = *(undefined4 *)(param_1 + 0x8c);
    FUN_1401c81f0(*(undefined8 *)(param_1 + 0x1fa8),*(undefined4 *)(param_1 + 0x1850),
                  *(undefined4 *)(param_1 + 0x1854));
    (**(code **)(**(longlong **)(param_1 + 0x1fa8) + 0x10))();
    FUN_14010c9a0(param_1,local_res10);
    FUN_14010c3f0(param_1);
    FUN_14010be70(param_1);
    FUN_14010dec0(param_1);
    bVar8 = FUN_140078e50(*(undefined8 *)(param_1 + 0x2038),param_1 + 0x70,DAT_1402d20d0);
    bVar18 = (bVar8 ^ *(byte *)(param_1 + 0x20c3)) << 4;
    bVar19 = bVar18 | bVar8;
    *(byte *)(param_1 + 0x20c3) = bVar19;
    uVar29 = extraout_XMM0_Qa;
    if (bVar18 != 0 || (bVar8 & 0xf0) != 0) {
      DAT_140310a8c = 500;
      DAT_140310a98 = 2;
      _DAT_140310aac = 500;
      DAT_140310ab8 = 2;
      if (bVar8 == 0) {
        DAT_140310a90 = DAT_1402d2778 * DAT_1437decf8;
        DAT_140310a94 = (DAT_140310a90 - DAT_140310a84) * DAT_1402d1e6c;
        _DAT_140310ab0 = DAT_1402d2778 * DAT_1437decfc;
        _DAT_140310ab4 = (_DAT_140310ab0 - DAT_140310aa4) * DAT_1402d1e6c;
        uVar29 = (ulonglong)(uint)_DAT_140310ab4;
      }
      else {
        DAT_140310a94 = (DAT_1402d2778 - DAT_140310a84) * DAT_1402d1e6c;
        uVar29 = (ulonglong)(uint)(DAT_1402d2778 - DAT_140310aa4);
        _DAT_140310ab4 = (DAT_1402d2778 - DAT_140310aa4) * DAT_1402d1e6c;
        DAT_140310a90 = DAT_1402d2778;
        _DAT_140310ab0 = DAT_1402d2778;
      }
    }
    uVar21 = 0x10a;
    uVar25 = 0x101;
    uVar24 = 0x107;
    if (*(char *)(param_1 + 0x2094) == '\x02') {
      uVar21 = 0x10b;
      uVar25 = 0x102;
      uVar24 = 0x108;
    }
    else if (*(char *)(param_1 + 0x2094) == '\x01') {
      uVar21 = 0x10c;
      uVar25 = 0x103;
      uVar24 = 0x109;
    }
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x15d0);
    auVar32 = ZEXT1664(local_a8);
    if (*(short *)(param_1 + 0xb48) == 1) {
      puVar35 = local_a8;
      uVar30 = auVar33._0_4_;
      uVar28 = CONCAT44(uVar36,uVar30);
      cVar10 = FUN_1401c6a00(bVar19,1,uVar21,param_1 + 0x70,puVar35,uVar28,CONCAT44(uVar22,uVar30),
                             uVar30,uVar30,0,0);
      uVar30 = (undefined4)((ulonglong)puVar35 >> 0x20);
      uVar36 = (undefined4)((ulonglong)uVar28 >> 0x20);
      uVar29 = extraout_XMM0_Qa_01;
      if (cVar10 != '\0') {
        lVar14 = FUN_1401c97a0();
        uVar29 = extraout_XMM0_Qa_02;
        if (('\x01' < *(char *)(lVar14 + 0x3dc2)) &&
           (uVar3 = *(ushort *)(lVar14 + 0x138),
           (*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar3 * 0x18) + 0x12 +
                     (ulonglong)uVar21 * 0x50) & 1) == 0)) {
          puVar15 = (undefined4 *)FUN_1401c9e60(lVar14);
          uVar29 = extraout_XMM0_Qa_03;
          if (puVar15 != (undefined4 *)0x0) {
            *(ushort *)(puVar15 + 0x11) = uVar3;
            *(ushort *)((longlong)puVar15 + 0x46) = uVar21;
            *puVar15 = *(undefined4 *)(param_1 + 0x70);
            puVar15[1] = *(undefined4 *)(param_1 + 0x74);
            puVar15[2] = *(undefined4 *)(param_1 + 0x78);
            uVar22 = *(undefined4 *)(param_1 + 0x7c);
            puVar15[4] = auVar32._0_4_;
            auVar31 = auVar32._0_16_;
            uVar4 = vextractps_avx(auVar31,1);
            puVar15[5] = uVar4;
            uVar4 = vextractps_avx(auVar31,2);
            puVar15[6] = uVar4;
            uVar4 = vextractps_avx(auVar31,3);
            puVar15[7] = uVar4;
            puVar15[3] = uVar22;
            *(undefined8 *)(puVar15 + 8) = 0;
            puVar15[10] = 0;
            puVar15[0xb] = 0x3f800000;
            puVar15[0xf] = 0x3f800000;
            *(undefined2 *)((longlong)puVar15 + 0x4a) = 0;
            *(byte *)(puVar15 + 0x1c) = *(byte *)(puVar15 + 0x1c) & 0xee | 6;
            *(code **)(puVar15 + 0xc) = FUN_1401caa00;
          }
        }
      }
    }
    lVar14 = local_d8;
    lVar27 = local_res20;
    sVar12 = *(short *)(local_res20 + 0x428 + local_d8);
    if ((sVar12 <= *(char *)(param_1 + 0x20c1)) && (0 < sVar12)) {
      local_res8 = CONCAT22(local_res8._2_2_,uVar25);
      local_res18[0] = 1;
      uVar29 = FUN_1401c6150(sVar12,local_res18,&local_res8);
      *(char *)(param_1 + 0x20c1) = *(char *)(lVar27 + 0x428 + lVar14) + -1;
    }
    if (*(float *)(param_1 + 0x207c) <= auVar33._0_4_) {
      FUN_1401c6490(uVar29,param_1 + 0x2068);
    }
    else {
      uVar25 = 0;
      uVar13 = local_res8 >> 0x10;
      local_res8 = local_res8 & 0xffff0000;
      if (*(char *)(param_1 + 0x20c2) == '\x01') {
        uVar25 = 0xfd44;
        local_res8 = CONCAT22((short)uVar13,0xfd44);
      }
      cVar10 = FUN_1401c5910(uVar29,param_1 + 0x2068);
      if (cVar10 == '\0') {
        if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
           (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
          FUN_1401c93c0();
          _Init_thread_footer(&DAT_1437daf04);
        }
        uVar13 = *(uint *)(param_1 + 0x2068);
        if ((((uVar13 != 0) && ((ushort)uVar13 < 0x80)) &&
            ((short)(uVar13 >> 0x10) ==
             *(short *)(&DAT_1437daf22 + (ulonglong)(uVar13 & 0xffff) * 2))) ||
           (DAT_1437dece2 < '\x02')) goto LAB_140107e21;
        local_res8 = CONCAT22(local_res8._2_2_,DAT_1437db058);
        bVar8 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)DAT_1437db058 * 0x18) + 0x12 +
                         (ulonglong)uVar24 * 0x50);
        lVar16 = FUN_1401c9e60(&DAT_1437daf20);
        lVar14 = local_d8;
        if (lVar16 != 0) {
          *(undefined2 *)(lVar16 + 0x44) = (undefined2)local_res8;
          *(ushort *)(lVar16 + 0x46) = uVar24;
          uVar22 = *(undefined4 *)(param_1 + 0x207c);
          *(undefined2 *)(lVar16 + 0x4a) = uVar25;
          *(undefined4 *)(lVar16 + 0x3c) = uVar22;
          *(undefined2 *)(lVar16 + 0x48) = 0;
          *(byte *)(lVar16 + 0x70) = *(byte *)(lVar16 + 0x70) & 0xfd;
          *(undefined4 *)(param_1 + 0x2068) = *(undefined4 *)(lVar16 + 0x38);
          if ((bVar8 & 1) == 0) {
            *(byte *)(lVar16 + 0x70) = *(byte *)(lVar16 + 0x70) & 0xfa;
            *(code **)(lVar16 + 0x30) = FUN_1401cae80;
          }
          else {
            *(byte *)(lVar16 + 0x70) = *(byte *)(lVar16 + 0x70) & 0xfb | 1;
            *(code **)(lVar16 + 0x30) = FUN_1401cad40;
          }
          goto LAB_140107f85;
        }
      }
      else if (*(char *)(param_1 + 0x2094) == *(char *)(param_1 + 0x20a5)) {
        puVar15 = &local_res8;
        local_res18[0] = 0;
        FUN_1401c63a0(extraout_XMM0_Qa_04,param_1 + 0x2068,param_1 + 0x207c,local_res18,puVar15);
        uVar30 = (undefined4)((ulonglong)puVar15 >> 0x20);
      }
      else {
        FUN_1401c6490();
LAB_140107e21:
      }
    }
  }
LAB_140107f85:
  pauVar26 = (undefined1 (*) [16])(param_1 + 0x70);
  uVar22 = 1;
  if ((*(byte *)(param_1 + 0x2058) & 2) != 0) goto LAB_1401085c0;
  if (((*(byte *)(lVar14 + 0x1f0 + lVar27) & 1) != 0) && (*(longlong *)(param_1 + 0x1fc0) != 0)) {
    lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x1fc0) + 0x66ee0);
    cVar10 = *(char *)(param_1 + 0x20a1);
    if (*(char *)(param_1 + 0x2094) == '\x01') {
      if (cVar10 == '\0') {
        *(undefined2 *)(lVar14 + 0x336d4) = 1;
      }
      else {
        *(undefined2 *)(lVar14 + 0x336d6) = 1;
      }
    }
    else if (*(char *)(param_1 + 0x2094) == '\x02') {
      if (cVar10 == '\0') {
        *(undefined2 *)(lVar14 + 0x336d4) = 2;
      }
      else {
        *(undefined2 *)(lVar14 + 0x336d6) = 2;
      }
    }
    else if (cVar10 == '\0') {
      *(undefined2 *)(lVar14 + 0x336d4) = 0;
    }
    else {
      *(undefined2 *)(lVar14 + 0x336d6) = 0;
    }
    uVar4 = *(undefined4 *)(param_1 + 0xb00);
    *(undefined4 *)(param_1 + 0xb00) = uVar4;
    if ((*(uint *)(param_1 + 0x2058) & 8) != 0) {
      *(ushort *)(param_1 + 0xae4) = *(ushort *)(param_1 + 0xae4) | 1;
      *(undefined4 *)(param_1 + 0xb20) = uVar4;
    }
    if ((*(uint *)(param_1 + 0x2058) & 0x10) == 0) {
      uVar22 = 0;
      if (*(char *)(param_1 + 0x2094) == '\x02') {
        iVar20 = 3;
      }
      else {
        iVar20 = (*(char *)(param_1 + 0x2094) == '\x01') + 1;
      }
    }
    else {
      iVar20 = 0;
    }
    FUN_14000eb50(param_1 + 0x110,*(undefined8 *)(param_1 + 0x1fc0),pauVar26,param_1 + 0x80,
                  CONCAT44(uVar30,uVar22),CONCAT44(uVar36,iVar20));
    local_d0 = auVar33._0_4_;
    local_d8 = CONCAT44(local_d0,local_d0);
    FUN_140102590(*(undefined8 *)(param_1 + 0x1fc8),&local_d8,&local_res8);
    uVar13 = DAT_1402d3770;
    fVar7 = DAT_1402d1e98;
    *(float *)(param_1 + 0xd60) = (float)(local_res8 & 0xff) * DAT_1402d1e98;
    *(undefined4 *)(param_1 + 0xd6c) = 0;
    *(float *)(param_1 + 0xd64) = (float)(local_res8 >> 8 & 0xff) * fVar7;
    *(float *)(param_1 + 0xd68) = (float)(local_res8 >> 0x10 & 0xff) * fVar7;
    *(uint *)(param_1 + 0xd50) = (uint)local_d8 ^ uVar13;
    *(uint *)(param_1 + 0xd58) = local_d0 ^ uVar13;
    *(uint *)(param_1 + 0xd54) = local_d8._4_4_ ^ uVar13;
    *(undefined4 *)(param_1 + 0xd5c) = 0;
    FUN_1400141a0();
    *(undefined4 *)(param_1 + 0xd5c) = 0x3f800000;
    if ((*(byte *)(param_1 + 0x2058) & 0x80) == 0) {
      auVar31 = *pauVar26;
      auVar5 = vshufps_avx(auVar31,auVar31,0xaa);
      local_b8 = 0;
      uStack_b0 = 0;
      auVar6 = vshufps_avx(auVar31,auVar31,0xff);
      uVar30 = auVar31._0_4_;
      local_c8._0_4_ = uVar30;
      auVar31 = vshufps_avx(auVar31,auVar31,0x55);
      local_cc = auVar6._0_4_;
      local_d0 = auVar5._0_4_;
      local_c8._8_4_ = local_d0;
      local_c8._12_4_ = local_cc;
      local_res8 = 0;
      local_d8 = CONCAT44(auVar31._0_4_ + DAT_1402d2698,uVar30);
      local_c8._4_4_ = DAT_1402d2e2c;
      uVar13 = FUN_1400782c0(*(undefined8 *)(param_1 + 0x2038),&local_b8,&local_res8,&local_d8,
                             local_c8);
      auVar31 = *(undefined1 (*) [16])(param_1 + 0x15d0);
      auVar5 = vpcmpeqd_avx(ZEXT416(uVar13),SUB6416(ZEXT464(0),0));
      local_98 = *(undefined4 *)*pauVar26;
      local_90 = *(undefined4 *)(param_1 + 0x78);
      auVar5 = vblendvps_avx(ZEXT416(local_b8._4_4_),auVar33._0_16_,auVar5);
      local_94 = *(float *)(param_1 + 0x74);
      local_8c = *(undefined4 *)(param_1 + 0x7c);
      local_78 = local_94 - auVar5._0_4_;
      local_88 = auVar31._0_4_;
      local_84 = vextractps_avx(auVar31,1);
      local_80 = vextractps_avx(auVar31,2);
      local_7c = vextractps_avx(auVar31,3);
      local_74 = 0;
      local_70 = local_res8;
      FUN_140031f80(*(undefined8 *)(*(longlong *)(param_1 + 0x1fc0) + 0x66ee0),5,&local_98,0);
    }
  }
  FUN_14010ead0(param_1);
  if (*(char *)(param_1 + 0x20a3) == '\"') {
    lVar14 = *(longlong *)(param_1 + 0x1fc8);
    pcVar17 = (char *)(lVar14 + 0x1dab1);
    do {
      if ((((*(uint *)(lVar14 + 0x1d684) >> (uVar23 & 0x1f) & 1) != 0) &&
          (pcVar17[-1] == *(char *)(param_1 + 0x20a1))) && (*pcVar17 == *(char *)(param_1 + 0x20a2))
         ) {
        if (((*(uint *)(param_1 + 0xd48) & 0x40000) != 0) &&
           ((*(char *)(param_1 + 0xc3d) == '\x03' || (*(char *)(param_1 + 0xc3d) == '\0')))) {
          FUN_1400a94d0(lVar14 + 0x1d628);
        }
        break;
      }
      uVar23 = uVar23 + 1;
      pcVar17 = pcVar17 + 0xa8;
    } while ((int)uVar23 < 0x10);
  }
  if (*(short *)(param_1 + 0x1f10) == 0) {
    if ((*(byte *)(param_1 + 0x1f18) & 1) != 0) {
      sVar12 = (short)(int)(*(float *)(param_1 + 0x1f14) *
                            *(float *)(*(longlong *)(param_1 + 0x1f08) + 0x24) *
                           (float)*(byte *)(param_1 + 0x1f19));
      goto LAB_14010835c;
    }
  }
  else {
    sVar12 = *(short *)(param_1 + 0x1f10) + -1;
LAB_14010835c:
    *(short *)(param_1 + 0x1f10) = sVar12;
    *(byte *)(param_1 + 0x1f18) = *(byte *)(param_1 + 0x1f18) & 0xfe;
  }
  if (*(short *)(param_1 + 0x1f28) == 0) {
    if ((*(byte *)(param_1 + 0x1f30) & 1) != 0) {
      sVar12 = (short)(int)(*(float *)(param_1 + 0x1f2c) *
                            *(float *)(*(longlong *)(param_1 + 0x1f20) + 0x24) *
                           (float)*(byte *)(param_1 + 0x1f31));
      goto LAB_1401083b4;
    }
  }
  else {
    sVar12 = *(short *)(param_1 + 0x1f28) + -1;
LAB_1401083b4:
    *(short *)(param_1 + 0x1f28) = sVar12;
    *(byte *)(param_1 + 0x1f30) = *(byte *)(param_1 + 0x1f30) & 0xfe;
  }
  *(undefined1 *)(param_1 + 0x209e) = 0;
  if (*(char *)(param_1 + 0x2099) != '\0') {
    if (*(char *)(param_1 + 0x2099) == '\x01') {
      if (*(char *)(param_1 + 0x209c) == '\0') {
        if (*(short *)(param_1 + 0x1f10) == 0) {
          *(undefined1 *)(param_1 + 0x209e) = 1;
        }
      }
      else if ((*(char *)(param_1 + 0x209c) == '\x01') && (*(short *)(param_1 + 0x1f28) == 0)) {
        *(undefined1 *)(param_1 + 0x209e) = 2;
      }
    }
    else {
      if (*(short *)(param_1 + 0x1f10) == 0) {
        *(undefined1 *)(param_1 + 0x209e) = 1;
        uVar11 = 3;
      }
      else {
        uVar11 = 2;
      }
      if (*(short *)(param_1 + 0x1f28) == 0) {
        *(undefined1 *)(param_1 + 0x209e) = uVar11;
      }
    }
  }
  if (*(short *)(param_1 + 8000) == 0) {
    if ((*(byte *)(param_1 + 0x1f48) & 1) != 0) {
      sVar12 = (short)(int)(*(float *)(param_1 + 0x1f44) *
                            *(float *)(*(longlong *)(param_1 + 0x1f38) + 0x24) *
                           (float)*(byte *)(param_1 + 0x1f49));
      goto LAB_14010847e;
    }
  }
  else {
    sVar12 = *(short *)(param_1 + 8000) + -1;
LAB_14010847e:
    *(short *)(param_1 + 8000) = sVar12;
    *(byte *)(param_1 + 0x1f48) = *(byte *)(param_1 + 0x1f48) & 0xfe;
  }
  if (*(short *)(param_1 + 0x1f58) == 0) {
    if ((*(byte *)(param_1 + 0x1f60) & 1) != 0) {
      *(short *)(param_1 + 0x1f58) =
           (short)(int)(*(float *)(param_1 + 0x1f5c) *
                        *(float *)(*(longlong *)(param_1 + 0x1f50) + 0x24) *
                       (float)*(byte *)(param_1 + 0x1f61));
      *(byte *)(param_1 + 0x1f60) = *(byte *)(param_1 + 0x1f60) & 0xfe;
    }
  }
  else {
    *(short *)(param_1 + 0x1f58) = *(short *)(param_1 + 0x1f58) + -1;
    *(byte *)(param_1 + 0x1f60) = *(byte *)(param_1 + 0x1f60) & 0xfe;
  }
  if (*(short *)(param_1 + 0x1f70) == 0) {
    if ((*(byte *)(param_1 + 0x1f78) & 1) != 0) {
      *(short *)(param_1 + 0x1f70) =
           (short)(int)(*(float *)(param_1 + 0x1f74) *
                        *(float *)(*(longlong *)(param_1 + 0x1f68) + 0x24) *
                       (float)*(byte *)(param_1 + 0x1f79));
      *(byte *)(param_1 + 0x1f78) = *(byte *)(param_1 + 0x1f78) & 0xfe;
    }
  }
  else {
    *(short *)(param_1 + 0x1f70) = *(short *)(param_1 + 0x1f70) + -1;
    *(byte *)(param_1 + 0x1f78) = *(byte *)(param_1 + 0x1f78) & 0xfe;
  }
  if (*(short *)(param_1 + 0x1f88) == 0) {
    if ((*(byte *)(param_1 + 0x1f90) & 1) != 0) {
      *(short *)(param_1 + 0x1f88) =
           (short)(int)(*(float *)(param_1 + 0x1f8c) *
                        *(float *)(*(longlong *)(param_1 + 0x1f80) + 0x24) *
                       (float)*(byte *)(param_1 + 0x1f91));
      *(byte *)(param_1 + 0x1f90) = *(byte *)(param_1 + 0x1f90) & 0xfe;
    }
  }
  else {
    *(short *)(param_1 + 0x1f88) = *(short *)(param_1 + 0x1f88) + -1;
    *(byte *)(param_1 + 0x1f90) = *(byte *)(param_1 + 0x1f90) & 0xfe;
  }
LAB_1401085c0:
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

