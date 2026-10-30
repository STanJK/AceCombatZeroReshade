/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401040c0; RVA 0x1040c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401040c0(ulonglong param_1,uchar param_2,longlong param_3)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  short *psVar5;
  longlong *plVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  bool bVar9;
  bool bVar10;
  uchar uVar11;
  uchar uVar12;
  uchar uVar13;
  uchar uVar14;
  undefined1 uVar15;
  char cVar16;
  char cVar17;
  byte bVar18;
  char cVar19;
  short sVar20;
  undefined2 uVar21;
  ushort uVar22;
  uint uVar23;
  undefined4 uVar24;
  undefined8 uVar25;
  byte bVar26;
  byte bVar27;
  undefined4 uVar28;
  longlong lVar29;
  ulonglong uVar30;
  int iVar31;
  undefined2 uVar32;
  ushort *puVar33;
  undefined2 uVar34;
  ulonglong uVar35;
  ulonglong uVar36;
  undefined1 **ppuVar37;
  char *pcVar38;
  undefined7 uVar39;
  longlong lVar40;
  longlong lVar41;
  float fVar42;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined1 *puVar45;
  undefined1 *extraout_XMM0_Qa_03;
  float fVar46;
  undefined1 auVar47 [16];
  float fVar48;
  float fVar49;
  undefined1 auVar50 [64];
  float fVar51;
  undefined1 *puVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  undefined1 auVar56 [64];
  undefined1 auVar57 [16];
  undefined1 auVar58 [64];
  undefined1 *local_res8;
  uchar local_res10;
  longlong local_res18;
  char local_res20 [8];
  undefined8 *in_stack_fffffffffffffe08;
  undefined7 uVar59;
  ulonglong in_stack_fffffffffffffe10;
  undefined8 *puVar60;
  ulonglong in_stack_fffffffffffffe18;
  undefined7 uVar61;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  float local_1b8 [4];
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined4 local_198;
  undefined2 local_188 [2];
  float local_184;
  undefined1 local_178 [8];
  float fStack_170;
  float fStack_16c;
  undefined1 auStack_168 [8];
  float fStack_160;
  float fStack_15c;
  undefined1 local_158 [8];
  float fStack_150;
  float fStack_14c;
  undefined1 local_148 [8];
  float fStack_140;
  float fStack_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  float local_118;
  undefined4 local_114;
  undefined1 local_110 [16];
  uint local_100;
  float local_fc;
  undefined1 local_f8 [11] [16];
  
  local_110 = ZEXT816(0);
  local_f8[0] = ZEXT816(0);
  local_res10 = param_2;
  local_res18 = param_3;
  FUN_1401c56d0();
  lVar41 = *(longlong *)
            (*(longlong *)
              (**(longlong **)(param_1 + 0x2040) + (ulonglong)*(byte *)(param_1 + 0x20a1) * 8) +
            0x110) + (ulonglong)*(byte *)(param_1 + 0x20a2) * 0x520;
  *(undefined1 *)(param_1 + 0x1c2b) = 1;
  if ((*(byte *)(lVar41 + 0x1f0) & 2) == 0) {
    FUN_14010e220(param_1,0);
    *(undefined1 *)(param_1 + 0x1c2b) = 0;
  }
  uVar25 = _UNK_1402d35f8;
  puVar52 = _DAT_1402d35f0;
  fVar53 = DAT_1402d1ff8;
  uVar23 = *(uint *)(lVar41 + 0x1f0);
  uVar36 = (ulonglong)uVar23;
  auVar56 = ZEXT464(DAT_1402d22d0);
  local_100 = DAT_1402d22d0;
  auVar58 = ZEXT864(0);
  if ((uVar23 & 1) == 0) {
    fVar53 = DAT_1402d2168;
    if (((*(char *)(param_1 + 0x20a3) == '\"') &&
        (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x14')) && ((uVar23 & 2) == 0)) {
      FUN_1400a94d0(*(longlong *)(param_1 + 0x1fc8) + 0x1d628,*(undefined1 *)(param_1 + 0x20a1),
                    *(undefined1 *)(param_1 + 0x20a2));
    }
LAB_140105f59:
    uVar24 = (undefined4)(in_stack_fffffffffffffe10 >> 0x20);
  }
  else {
    local_fc = DAT_1402d1ff8;
    if ((*(uint *)(param_1 + 0x2058) & 2) == 0) {
      cVar19 = *(char *)(param_1 + 0x2094);
      *(char *)(param_1 + 0x20a5) = cVar19;
      cVar16 = cVar19;
      if ((((*(uint *)(param_1 + 0x2058) >> 0xd & 1) == 0) &&
          (uVar11 = FUN_140187c80(uVar36,param_2,'\"'), uVar11 != '\0')) &&
         (*(char *)(*(longlong *)(param_1 + 0x2040) + 0x37) == '\x01')) {
        if (cVar19 == '\0') {
          *(undefined1 *)(param_1 + 0x2094) = 2;
          cVar16 = '\x02';
        }
        else if (cVar19 == '\x02') {
          *(undefined1 *)(param_1 + 0x2094) = 1;
          cVar16 = '\x01';
        }
        else if (cVar19 == '\x01') {
          *(undefined1 *)(param_1 + 0x2094) = 0;
          cVar16 = '\0';
        }
      }
      cVar2 = *(char *)(param_1 + 0x2096);
      if (cVar2 != -1) {
        *(char *)(param_1 + 0x2094) = cVar2;
        *(undefined1 *)(param_1 + 0x2096) = 0xff;
        cVar16 = cVar2;
      }
      if (cVar16 != cVar19) {
        *(char *)(param_1 + 0x1da6) = cVar16;
        if (cVar16 == '\x01') {
          uVar24 = *(undefined4 *)(param_1 + 0x1d68);
        }
        else if (cVar16 == '\x02') {
          uVar24 = *(undefined4 *)(param_1 + 0x1d6c);
        }
        else {
          uVar24 = *(undefined4 *)(param_1 + 0x1d64);
        }
        *(undefined4 *)(param_1 + 0x1d70) = uVar24;
        *(undefined4 *)(param_1 + 0x1d74) = uVar24;
        *(undefined8 *)(param_1 + 0x1d40) = 0;
        *(undefined8 *)(param_1 + 0x1d48) = 0;
        FUN_1401c6590();
      }
      uVar11 = local_res10;
      *(undefined1 *)(param_1 + 0x20bb) = 0;
      if ((*(uint *)(param_1 + 0x2058) & 0x1000) == 0) {
        uVar15 = *(undefined1 *)(*(longlong *)(param_1 + 0x2040) + 0x69);
        uVar12 = FUN_140187c80(uVar36,local_res10,'\x04');
        uVar13 = FUN_140187c80(uVar36,uVar11,'\x06');
        uVar11 = FUN_140187c80(uVar36,uVar11,'\n');
        uVar14 = FUN_140187c80(uVar36,local_res10,'\b');
        in_stack_fffffffffffffe10 =
             CONCAT71((int7)(in_stack_fffffffffffffe10 >> 8),uVar15) & 0xffffffffffffff01;
        in_stack_fffffffffffffe08 =
             (undefined8 *)CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe08 >> 8),uVar12);
        cVar19 = FUN_1400bbc50(param_1 + 0x1ac8,uVar14,uVar11,uVar13,in_stack_fffffffffffffe08,
                               in_stack_fffffffffffffe10);
        *(char *)(param_1 + 0x20bb) = cVar19;
        uVar43 = extraout_XMM0_Qa;
        if (cVar19 != '\0') {
          lVar29 = *(longlong *)(param_1 + 0x2040);
          uVar15 = FUN_1400bbe00(param_1 + 0x1ac8);
          *(byte *)(lVar29 + 0x69) = *(byte *)(lVar29 + 0x69) | 8;
          *(undefined1 *)(lVar29 + 0x68) = uVar15;
          uVar43 = extraout_XMM0_Qa_00;
          if ((*(byte *)(param_1 + 0x1aed) & 0x20) == 0) {
            pbVar1 = (byte *)(*(longlong *)(param_1 + 0x2040) + 0x69);
            *pbVar1 = *pbVar1 & 0xfe;
          }
          else {
            pbVar1 = (byte *)(*(longlong *)(param_1 + 0x2040) + 0x69);
            *pbVar1 = *pbVar1 | 1;
          }
        }
        param_2 = local_res10;
        uVar43 = FUN_140187ec0(uVar43,local_res10,0x16);
        uVar44 = FUN_140187ec0(uVar43,param_2,0x13);
        fVar55 = (float)uVar43;
        uVar43 = FUN_140187ec0(uVar44,param_2,0x14);
        fVar48 = (float)((uint)((float)uVar43 - (float)uVar44) & _DAT_1402d3760);
        fVar42 = (float)FUN_140187ec0(uVar43,param_2,0x15);
        *(char *)(param_1 + 0x1aee) =
             (char)(int)((fVar48 + (float)((uint)(fVar42 - fVar55) & _DAT_1402d3760)) *
                         (float)*(byte *)(param_1 + 0x1aec) * fVar53 + auVar56._0_4_);
      }
      else {
        *(byte *)(param_1 + 0x1aeb) = *(byte *)(param_1 + 0x1aeb) & 0xf8;
        *(undefined2 *)(param_1 + 0x1ae8) = 0;
      }
      FUN_14010f600(param_1 + 0x1430,param_2,*(undefined1 *)(param_1 + 0x20a1),
                    *(undefined1 *)(param_1 + 0x20a2));
      local_114 = *(undefined4 *)(param_1 + 0x1804);
      local_138 = *(float *)(param_1 + 0x180c);
      local_134 = *(undefined4 *)(param_1 + 0x1810);
      local_130 = *(undefined4 *)(param_1 + 0x1814);
      fVar48 = *(float *)*(undefined1 (*) [16])(param_1 + 0x17f8);
      fVar55 = *(float *)(param_1 + 0x17fc);
      fVar54 = *(float *)(param_1 + 0x1800);
      local_110 = *(undefined1 (*) [16])(param_1 + 0x17f8);
      fVar42 = *(float *)*(undefined1 (*) [16])(param_1 + 0x1808);
      local_f8[0] = *(undefined1 (*) [16])(param_1 + 0x1808);
      *(undefined4 *)(param_1 + 0x7c) = local_114;
      *(float *)(param_1 + 0x84) = local_138;
      *(undefined4 *)(param_1 + 0x88) = local_134;
      *(undefined4 *)(param_1 + 0x8c) = local_130;
      *(float *)(param_1 + 0x70) = fVar48;
      *(float *)(param_1 + 0x74) = fVar55;
      *(float *)(param_1 + 0x78) = fVar54;
      *(float *)(param_1 + 0x80) = fVar42;
      local_res8 = (undefined1 *)CONCAT44(local_res8._4_4_,fVar42);
      *(undefined1 *)(param_1 + 0x20bc) = 0;
      local_1b8[0] = fVar55;
      local_184 = fVar54;
      local_118 = fVar48;
      if (*(char *)(param_1 + 0x2097) == '\0') {
        fVar53 = DAT_1402d2478;
        if ((*(byte *)(param_1 + 0x2058) & 0x20) == 0) {
          pcVar38 = (char *)(param_1 + 0xc3b);
          uVar23 = *(uint *)(param_1 + 0xd48) & 0x10000;
          if (uVar23 == 0) {
            cVar19 = '\x02';
          }
          else {
            cVar19 = *pcVar38;
          }
          uVar36 = DAT_14032c8f0;
          cVar16 = FUN_140187a40(DAT_14032c8f0,param_2,0xd);
          if (cVar16 == '\0') {
            uVar25 = extraout_XMM0_Qa_01;
            if (((byte)(cVar19 - 1U) < 2) && (uVar23 != 0)) {
              *pcVar38 = '\x03';
            }
LAB_140104a86:
            FUN_1401c6490(uVar25,param_1 + 0x205c);
          }
          else if (*(short *)(param_1 + 0x208e) == 0) {
            if (((byte)(cVar19 - 1U) < 2) && (uVar23 != 0)) {
              *pcVar38 = '\x03';
            }
            *(undefined1 *)(param_1 + 0x20bc) = 5;
            FUN_1401c6490(extraout_XMM0_Qa_01,param_1 + 0x205c);
            uVar11 = FUN_140187c80(uVar36,param_2,'\r');
            if (uVar11 != '\0') {
              local_res20[0] = '\x01';
              local_res20[1] = '\0';
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,5);
              FUN_1401c6150();
            }
          }
          else {
            if (((cVar19 == '\x03') || (cVar19 == '\0')) && (uVar23 != 0)) {
              *pcVar38 = '\x01';
            }
            if (cVar19 == '\x02') {
              *(ushort *)(param_1 + 0xae4) = *(ushort *)(param_1 + 0xae4) | 2;
              uVar43 = extraout_XMM0_Qa_01;
              if (*(short *)(param_1 + 0x1ef8) == 0) {
                _local_178 = ZEXT816(0);
                auVar56 = ZEXT464((uint)(((*(float *)(param_1 + 0x1848) * DAT_1402d20dc) /
                                         (float)*(byte *)(param_1 + 0x20a0)) * fVar53));
                _auStack_168 = ZEXT816(0);
                _local_158 = _local_178;
                _local_148 = _auStack_168;
                FUN_140202920(local_178,local_f8);
                uVar23 = DAT_1437d9a50;
                fVar48 = fVar48 + (float)local_148._0_4_;
                fVar42 = (float)local_148._4_4_ + local_1b8[0];
                fVar55 = local_184 + fStack_140;
                fVar54 = 0.0;
                fVar51 = 0.0;
                fVar49 = 0.0;
                fVar46 = 0.0;
                if (0x40 < *(ushort *)(param_1 + 0x1b8)) {
                  if (0x40 < *(ushort *)(param_1 + 0x1bc)) {
                    if (**(int **)(param_1 + 0x1d0) == 1) {
                      FUN_14015e650(param_1 + 0x120,&local_1c8,0x40,0);
                    }
                    else {
                      if (**(int **)(param_1 + 0x1d0) != 2) goto LAB_14010478c;
                      FUN_14015e650(param_1 + 0x120,&local_1c8,0x40,DAT_1437d9a50 & 1);
                      DAT_1437d9a50 = uVar23 + 1;
                    }
                    fVar54 = (float)local_1c8;
                    fVar51 = local_1c8._4_4_;
                    fVar49 = (float)uStack_1c0;
                    fVar46 = uStack_1c0._4_4_;
                  }
                }
LAB_14010478c:
                uVar24 = auVar58._0_4_;
                local_1c8 = (undefined1 *)
                            CONCAT44(uVar24,**(float **)(param_1 + 0xfe0) * DAT_1402d1f38);
                uStack_1c0 = CONCAT44(uVar24,uVar24);
                FUN_140203050(&local_1c8,local_f8,&local_1c8);
                local_1a8 = local_1c8;
                in_stack_fffffffffffffe18 = *(ulonglong *)(param_1 + 0x1fb0);
                auVar47 = vshufps_avx(_local_178,_local_178,0x55);
                auVar57 = vshufps_avx(_local_158,_local_158,0x55);
                local_1c8 = (undefined1 *)
                            CONCAT44(fVar42 * fVar46 +
                                     auVar57._0_4_ * fVar49 +
                                     auVar47._0_4_ * fVar54 + fVar51 * (float)auStack_168._4_4_,
                                     fVar48 * fVar46 +
                                     local_158._0_4_ * fVar49 +
                                     local_178._0_4_ * fVar54 + fVar51 * (float)auStack_168._0_4_);
                auVar47 = vshufps_avx(_local_158,_local_158,0xaa);
                auVar57 = vshufps_avx(_local_158,_local_158,0xff);
                uStack_1a0 = uStack_1c0;
                auVar7 = vshufps_avx(_local_178,_local_178,0xaa);
                auVar8 = vshufps_avx(_local_178,_local_178,0xff);
                uStack_1c0 = CONCAT44(fVar46 * fStack_13c + fVar49 * auVar57._0_4_ +
                                      fVar51 * fStack_15c + auVar8._0_4_ * fVar54,
                                      fVar55 * fVar46 +
                                      auVar47._0_4_ * fVar49 +
                                      fVar54 * auVar7._0_4_ + fVar51 * fStack_160);
                in_stack_fffffffffffffe08 =
                     (undefined8 *)
                     CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe08 >> 8),
                              *(undefined1 *)(param_1 + 0x20a1));
                FUN_14013ace0(local_res18 + 0xca0,&local_1c8,&local_1a8,auVar56._0_8_,
                              in_stack_fffffffffffffe08,*(undefined1 *)(param_1 + 0x20a2),
                              in_stack_fffffffffffffe18,
                              *(byte *)(*(longlong *)(param_1 + 0xff8) + 0xc) >> 7);
                uVar43 = FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),0xd,0);
                *(byte *)(param_1 + 0x1f00) = *(byte *)(param_1 + 0x1f00) | 1;
                sVar20 = *(short *)(param_1 + 0x208e);
                if (sVar20 != 10000) {
                  sVar20 = sVar20 + -1;
                  *(short *)(param_1 + 0x208e) = sVar20;
                }
                uVar25 = _UNK_1402d35f8;
                puVar52 = _DAT_1402d35f0;
                fVar42 = local_res8._0_4_;
                fVar54 = local_184;
                fVar55 = local_1b8[0];
                if (sVar20 == 0) {
                  *(undefined1 *)(param_1 + 0x20bc) = 5;
                }
              }
              uVar36 = param_1 + 0x205c;
              cVar19 = FUN_1401c5910(uVar43,uVar36);
              if (cVar19 == '\0') {
                local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,3);
                if (*(longlong *)(param_1 + 0x1fa8) != 0) {
                  local_res8 = (undefined1 *)
                               CONCAT62(local_res8._2_6_,
                                        (ushort)*(byte *)(*(longlong *)(param_1 + 0x1fa8) + 0x40));
                }
                local_1a8 = puVar52;
                uStack_1a0 = uVar25;
                local_128 = puVar52;
                uStack_120 = uVar25;
                if (*(char *)(param_1 + 0x2094) == '\x01') {
                  local_res20[0] = '\x02';
                  local_res20[1] = '\0';
                  in_stack_fffffffffffffe08 = &local_128;
                  FUN_1401c5c30(extraout_XMM0_Qa_02,&local_res8,local_res20,local_110,
                                in_stack_fffffffffffffe08,&local_1a8,uVar36);
                  in_stack_fffffffffffffe18 = uVar36;
                }
                else {
                  in_stack_fffffffffffffe08 = &local_128;
                  if (*(char *)(param_1 + 0x2094) == '\0') {
                    local_res20[0] = '\0';
                    local_res20[1] = '\0';
                    FUN_1401c5c30(0,&local_res8,local_res20,local_110,in_stack_fffffffffffffe08,
                                  &local_1a8,uVar36);
                    in_stack_fffffffffffffe18 = uVar36;
                  }
                  else {
                    local_res20[0] = '\x01';
                    local_res20[1] = '\0';
                    FUN_1401c5c30(extraout_XMM0_Qa_02,&local_res8,local_res20,local_110,
                                  in_stack_fffffffffffffe08,&local_1a8,uVar36);
                    in_stack_fffffffffffffe18 = uVar36;
                  }
                }
              }
              else {
                uVar25 = extraout_XMM0_Qa_02;
                if (*(char *)(param_1 + 0x2094) != *(char *)(param_1 + 0x20a5)) goto LAB_140104a86;
                FUN_1401c6260(extraout_XMM0_Qa_02,uVar36,local_110);
              }
            }
          }
        }
        uVar36 = param_1 + 0x1ef0;
        FUN_140102540();
        if (((*(byte *)(param_1 + 0x2058) & 0x20) == 0) &&
           (uVar11 = FUN_140187c80(uVar36,param_2,'\x02'), uVar11 != '\0')) {
          *(byte *)(param_1 + 0x1eee) = *(byte *)(param_1 + 0x1eee) & 0xbf;
          if (*(char *)(param_1 + 0x2098) == '\0') {
            if (*(char *)(param_1 + 0x209a) == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,5);
              local_res20[0] = '\x01';
              local_res20[1] = '\0';
              FUN_1401c6150();
              *(undefined1 *)(param_1 + 0x20bc) = 4;
            }
            else {
              *(undefined1 *)(param_1 + 0x2098) = 1;
              uVar25 = FUN_1400c1030(param_1 + 0x1e38);
              *(undefined2 *)(param_1 + 0x1eec) = 0xffff;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,6);
              local_res20[0] = '\x01';
              local_res20[1] = '\0';
              FUN_1401c6150(uVar25,local_res20,&local_res8);
              *(undefined1 *)(param_1 + 0x20bc) = 2;
              bVar18 = *(byte *)(*(longlong *)(param_1 + 0xfd8) + 0xf);
              fVar53 = fVar53 * *(float *)(*(longlong *)(param_1 + 0x1fb8) + 0x10) *
                       *(float *)(*(longlong *)(param_1 + 0xfd8) + 8);
              bVar27 = *(byte *)(param_1 + 0x209a);
              if (bVar18 <= *(byte *)(param_1 + 0x209a)) {
                bVar27 = bVar18;
              }
              FUN_1400c04e0(param_1 + 0x1e38,bVar27);
              *(float *)(param_1 + 0x1ec4) = fVar53;
              *(float *)(param_1 + 0x1e44) = fVar53;
              *(float *)(param_1 + 0x1e64) = fVar53;
              *(float *)(param_1 + 0x1e84) = fVar53;
              *(float *)(param_1 + 0x1ea4) = fVar53;
              FUN_1400c2630(param_1 + 0x1e38,*(byte *)(*(longlong *)(param_1 + 0xfd8) + 0xc) & 1);
              FUN_1400c2680(param_1 + 0x1e38,
                            *(byte *)(*(longlong *)(param_1 + 0xfd8) + 0xc) >> 1 & 1);
            }
          }
          else {
            if ((*(char *)(param_1 + 0x20a3) == '\"') &&
               (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x14')) {
              FUN_1400a94d0(*(longlong *)(param_1 + 0x1fc8) + 0x1d628,
                            *(undefined1 *)(param_1 + 0x20a1),*(undefined1 *)(param_1 + 0x20a2));
            }
            *(undefined1 *)(param_1 + 0x2098) = 0;
            local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,7);
            local_res20[0] = '\x01';
            local_res20[1] = '\0';
            FUN_1401c6150();
            cVar19 = *(char *)(param_1 + 0x2099);
            *(undefined1 *)(param_1 + 0x20bc) = 1;
            FUN_1400c1030(param_1 + 0x1e38);
            *(undefined2 *)(param_1 + 0x1eec) = 0xffff;
            uVar25 = FUN_1400c04e0(param_1 + 0x1e38,cVar19 != '\0');
            fVar53 = fVar53 * *(float *)(*(longlong *)(param_1 + 0x1fb8) + 0x10);
            *(float *)(param_1 + 0x1ec4) = fVar53;
            *(float *)(param_1 + 0x1e44) = fVar53;
            *(float *)(param_1 + 0x1e64) = fVar53;
            *(float *)(param_1 + 0x1e84) = fVar53;
            *(float *)(param_1 + 0x1ea4) = fVar53;
            *(byte *)(param_1 + 0x1eee) = *(byte *)(param_1 + 0x1eee) & 0xf3;
            *(byte *)(param_1 + 0x1ecd) = *(byte *)(param_1 + 0x1ecd) & 0xfc;
            if (*(char *)(param_1 + 0x2099) == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,5);
              local_res20[0] = '\x01';
              local_res20[1] = '\0';
              FUN_1401c6150(uVar25,local_res20,&local_res8);
              *(undefined1 *)(param_1 + 0x20bc) = 3;
            }
          }
        }
        lVar29 = *(longlong *)(param_1 + 0x1fd0);
        if (lVar29 != 0) {
          bVar18 = *(byte *)(lVar29 + 0x2a6);
          cVar19 = FUN_140187a40(DAT_14032c8f0,param_2,0xc);
          if (cVar19 == '\0') {
            if (bVar18 != 0) {
              bVar18 = bVar18 | 0x40;
              *(int *)(lVar29 + 0x2b0) =
                   (int)(longlong)((float)*(byte *)(lVar29 + 0x2ae) * DAT_1402d2168);
LAB_140104d9b:
              *(byte *)(lVar29 + 0x2a6) = bVar18;
            }
          }
          else if ((bVar18 & 0x40) != 0) {
            iVar31 = *(int *)(lVar29 + 0x2b0);
            if (iVar31 != 0) {
              iVar31 = iVar31 + -1;
              *(int *)(lVar29 + 0x2b0) = iVar31;
            }
            if ((bVar18 != 0) && (iVar31 == 0)) {
              bVar18 = bVar18 & 0xbf;
              goto LAB_140104d9b;
            }
          }
        }
        cVar19 = *(char *)(param_1 + 0x2098);
        FUN_1401031b0(param_1);
        lVar29 = param_1 + 0x1f38;
        uVar36 = 4;
        do {
          FUN_140102540(lVar29);
          lVar29 = lVar29 + 0x18;
          uVar36 = uVar36 - 1;
        } while (uVar36 != 0);
        FUN_1401024c0(param_1 + 0x1f98);
        uVar23 = *(uint *)(param_1 + 0xd48) & 0x40000;
        if (uVar23 == 0) {
          cVar16 = '\x02';
        }
        else {
          cVar16 = *(char *)(param_1 + 0xc3d);
        }
        cVar2 = *(char *)(param_1 + 0x20a3);
        uVar30 = (ulonglong)((byte)(*(uint *)(param_1 + 0x2058) >> 5) & 1);
        if (*(char *)(param_1 + 0x2098) != '\x01') {
          uVar30 = 1;
        }
        uVar35 = uVar30;
        if (*(char *)(param_1 + 0x209a) == '\0') {
          uVar35 = 1;
        }
        if (cVar2 == '\"') {
          if (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x14') {
            uVar36 = 0;
            uVar30 = *(longlong *)(param_1 + 0x1fc8) + 0x1d628;
            cVar17 = FUN_1400a9700();
            if (cVar17 == '\0') goto LAB_1401052d3;
            goto LAB_140104e74;
          }
          cVar16 = '\x02';
LAB_1401052e7:
          if (uVar23 != 0) {
            *(undefined1 *)(param_1 + 0xc3d) = 3;
          }
LAB_140104e8a:
          if ((cVar2 == '\"') && (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x14')) {
            uVar30 = param_1;
            FUN_14010bc20();
          }
        }
        else {
LAB_1401052d3:
          if ((char)uVar35 == '\0') {
LAB_140104e74:
            if ((cVar16 == '\x03') || (cVar16 == '\0')) {
              if (uVar23 != 0) {
                *(undefined1 *)(param_1 + 0xc3d) = 1;
              }
              goto LAB_140104e8a;
            }
          }
          else if ((byte)(cVar16 - 1U) < 2) goto LAB_1401052e7;
        }
        ppuVar37 = (undefined1 **)(uVar36 & 0xffffffffffffff00);
        bVar10 = false;
        local_res8 = (undefined1 *)((ulonglong)local_res8 & 0xffffffffffffff00);
        if ((cVar19 == '\x01') && ((*(byte *)(param_1 + 0x2058) & 0x20) == 0)) {
          pcVar38 = (char *)CONCAT71((int7)(uVar36 >> 8),0xc);
          uVar11 = FUN_140187c80(uVar30,local_res10,'\f');
          if ((uVar11 != '\0') && (bVar10 = true, *(char *)(param_1 + 0x209a) == '\0')) {
            *(undefined1 *)(param_1 + 0x20bc) = 4;
            local_res20[0] = '\x05';
            local_res20[1] = '\0';
            pcVar38 = local_res20;
            local_188[0] = 1;
            FUN_1401c6150();
          }
          ppuVar37 = (undefined1 **)((ulonglong)pcVar38 & 0xffffffffffffff00);
        }
        if (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\b') {
          bVar9 = false;
          if (*(char *)(param_1 + 0x1fa1) == '\0') {
            bVar9 = bVar10;
          }
          bVar10 = bVar9;
          if ((*(short *)(param_1 + 0x1f9c) == 0) && (*(char *)(param_1 + 0x1fa1) != '\0')) {
            ppuVar37 = (undefined1 **)CONCAT71((int7)((ulonglong)ppuVar37 >> 8),1);
            local_res8 = (undefined1 *)CONCAT71(local_res8._1_7_,1);
          }
        }
        if ((((bVar10) || ((char)ppuVar37 != '\0')) && (*(char *)(param_1 + 0x209a) != '\0')) &&
           ((cVar16 == '\x02' && (bVar18 = *(byte *)(param_1 + 0x20b4), bVar18 != 0)))) {
          bVar27 = *(byte *)(param_1 + 0x1ec8);
          uVar23 = 0;
          if (bVar27 == 0) {
LAB_140104ff1:
            local_res20[0] = 0xff;
            bVar26 = 1;
            local_188[0] = CONCAT11(local_188[0]._1_1_,0xff);
          }
          else {
            bVar3 = *(byte *)(param_1 + 0x1ec8);
            uVar36 = 0;
            do {
              uVar30 = uVar36;
              if (((byte)uVar23 < bVar3) &&
                 (lVar29 = (ulonglong)(uVar23 & 0xff) * 0x20,
                 (*(byte *)(lVar29 + 0x1e55 + param_1) & 2) != 0)) {
                cVar19 = *(char *)(lVar29 + 0x1e53 + param_1);
                cVar16 = *(char *)(lVar29 + 0x1e54 + param_1);
                ppuVar37 = (undefined1 **)0x0;
                if ((cVar19 != -1) && (cVar16 != -1)) {
                  uVar30 = (ulonglong)(byte)((char)uVar36 + 1);
                  local_res20[uVar36] = cVar19;
                  *(char *)((longlong)local_188 + uVar36) = cVar16;
                }
              }
              bVar26 = (byte)uVar30;
              uVar23 = uVar23 + 1;
              uVar36 = uVar30;
            } while ((int)uVar23 < (int)(uint)bVar27);
            if (bVar26 == 0) goto LAB_140104ff1;
          }
          auVar47 = local_110;
          if (bVar18 < bVar26) {
            bVar26 = bVar18;
          }
          bVar9 = false;
          local_110._1_7_ = 0;
          local_110[0] = bVar26;
          local_110._8_8_ = auVar47._8_8_;
          if (bVar26 == 0) goto LAB_14010598e;
          lVar29 = 0;
          fVar53 = DAT_1402d1d18;
          do {
            ppuVar37 = *(undefined1 ***)(param_1 + 0xfd8);
            cVar19 = local_res20[lVar29];
            uVar15 = *(undefined1 *)((longlong)local_188 + lVar29);
            if (*(char *)((longlong)ppuVar37 + 0xd) == '\x13') {
              *(undefined1 *)(param_1 + 0x209d) = 0;
            }
            uVar36 = (ulonglong)*(byte *)(param_1 + 0x209d);
            if (*(byte *)(param_1 + 0x20b4) <= *(byte *)(param_1 + 0x209d)) {
              *(undefined1 *)(param_1 + 0x209d) = 0;
              uVar36 = 0;
            }
            sVar20 = *(short *)(uVar36 * 0x18 + 8000 + param_1);
            if (*(char *)((longlong)ppuVar37 + 0xd) == '\x15') {
              sVar20 = *(short *)(param_1 + uVar36 * -0x18 + 0x1f58);
            }
            if (((sVar20 == 0) && (bVar10)) || ((char)local_res8 != '\0')) {
              _local_178 = ZEXT816(0);
              _auStack_168 = ZEXT816(0);
              fVar49 = fVar42;
              _local_158 = _local_178;
              _local_148 = _auStack_168;
              FUN_14015e650(param_1 + 0x120,&local_1c8,
                            (int)uVar36 + 0x43 + (uint)*(byte *)(param_1 + 0x279a) * 4,0);
              FUN_140202920(local_178,local_f8);
              auVar50 = ZEXT464((uint)local_138);
              fVar48 = uStack_1c0._4_4_ * fStack_13c + (float)uStack_1c0 * fStack_14c +
                       (float)local_1c8 * fStack_16c + local_1c8._4_4_ * fStack_15c;
              fVar54 = (fVar54 + fStack_140) * uStack_1c0._4_4_ + (float)uStack_1c0 * fStack_150 +
                       local_1c8._4_4_ * fStack_160 + (float)local_1c8 * fStack_170;
              fVar55 = (fVar55 + (float)local_148._4_4_) * uStack_1c0._4_4_ +
                       (float)uStack_1c0 * (float)local_158._4_4_ +
                       local_1c8._4_4_ * (float)auStack_168._4_4_ +
                       (float)local_1c8 * (float)local_178._4_4_;
              auVar56 = ZEXT464(*(uint *)(param_1 + 0x1848));
              uVar36 = (ulonglong)*(uint *)(param_1 + 0x1848);
              fVar51 = (local_118 + (float)local_148._0_4_) * uStack_1c0._4_4_ +
                       (float)uStack_1c0 * (float)local_158._0_4_ +
                       local_1c8._4_4_ * (float)auStack_168._0_4_ +
                       (float)local_1c8 * (float)local_178._0_4_;
              fVar42 = fVar49;
              fVar46 = local_138;
              if (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\b') {
                iVar31 = FUN_140242630();
                fVar49 = (float)(iVar31 + -0x3fff) * fVar53 + fVar49;
                iVar31 = FUN_140242630();
                uVar36 = auVar56._0_8_;
                fVar46 = (float)(iVar31 + -0x3fff) * fVar53 + auVar50._0_4_;
              }
              cVar16 = *(char *)(*(longlong *)(param_1 + 0xff8) + 4 +
                                (ulonglong)*(byte *)(param_1 + 0x279a));
              if (*(char *)(param_1 + 0x20a3) == '#') {
                if (cVar16 == '\x14') {
                  cVar16 = '\x16';
                }
              }
              ppuVar37 = (undefined1 **)&local_128;
              in_stack_fffffffffffffe18 = CONCAT71((int7)(in_stack_fffffffffffffe18 >> 8),cVar19);
              in_stack_fffffffffffffe08 =
                   (undefined8 *)
                   CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe08 >> 8),
                            *(undefined1 *)(param_1 + 0x20a1));
              local_128 = (undefined1 *)CONCAT44(fVar46,fVar49);
              uStack_120 = CONCAT44(local_130,local_134);
              local_1a8 = (undefined1 *)CONCAT44(fVar55,fVar51);
              uStack_1a0 = CONCAT44(fVar48,fVar54);
              iVar31 = FUN_140141200(local_res18 + 0x1b10,&local_1a8,ppuVar37,uVar36,
                                     in_stack_fffffffffffffe08,*(undefined1 *)(param_1 + 0x20a2),
                                     in_stack_fffffffffffffe18,uVar15,
                                     *(undefined8 *)(param_1 + 0x1fb8),cVar16);
              if (iVar31 < 0) {
                if (iVar31 == -1) goto LAB_1401054f7;
              }
              else {
                *(undefined1 *)(local_res18 + 0x1fd90) = 1;
              }
              lVar40 = *(longlong *)(param_1 + 0xfd8);
              uVar39 = (undefined7)((ulonglong)ppuVar37 >> 8);
              uVar61 = (undefined7)(in_stack_fffffffffffffe18 >> 8);
              uVar59 = (undefined7)((ulonglong)in_stack_fffffffffffffe08 >> 8);
              if (*(char *)(lVar40 + 0xd) == '\b') {
                if ((*(short *)(param_1 + 8000 + (ulonglong)*(byte *)(param_1 + 0x209d) * 0x18) == 0
                    ) && (bVar10)) {
                  *(undefined1 *)(param_1 + 0x1fa1) = *(undefined1 *)(param_1 + 0x1fa0);
                  *(undefined2 *)(param_1 + 0x1f9c) = 0;
                  *(undefined1 *)(param_1 + 0x1f9e) = 0;
                }
                if (*(char *)(param_1 + 0x1fa1) == *(char *)(param_1 + 0x1fa0)) {
                  *(int *)(param_1 + 0x20c4) = iVar31;
                }
                *(byte *)(param_1 + 0x1f9e) = *(byte *)(param_1 + 0x1f9e) | 1;
                if (*(char *)(param_1 + 0x1fa1) == '\x01') {
                  *(char *)(param_1 + 0x209a) = *(char *)(param_1 + 0x209a) + -1;
                  *(byte *)(param_1 + 0x1f48) = *(byte *)(param_1 + 0x1f48) | 1;
                  *(byte *)(param_1 + 0x1f60) = *(byte *)(param_1 + 0x1f60) | 1;
                  *(byte *)(param_1 + 0x1f78) = *(byte *)(param_1 + 0x1f78) | 1;
                  *(byte *)(param_1 + 0x1f90) = *(byte *)(param_1 + 0x1f90) | 1;
                  if (*(longlong *)(param_1 + 0x1fd0) != 0) {
                    ppuVar37 = (undefined1 **)CONCAT71(uVar39,1);
                    in_stack_fffffffffffffe18 = CONCAT71(uVar61,cVar19);
                    in_stack_fffffffffffffe08 =
                         (undefined8 *)CONCAT71(uVar59,*(undefined1 *)(param_1 + 0x20a1));
                    FUN_1401417e0(*(longlong *)(param_1 + 0x1fd0),iVar31,ppuVar37,
                                  *(undefined1 *)(lVar40 + 0xd),in_stack_fffffffffffffe08,
                                  *(undefined1 *)(param_1 + 0x20a2),in_stack_fffffffffffffe18,uVar15
                                 );
                  }
                }
              }
              else {
                *(char *)(param_1 + 0x209a) = *(char *)(param_1 + 0x209a) + -1;
                if ((*(longlong *)(param_1 + 0x1fd0) != 0) && (lVar29 == 0)) {
                  if ((*(char *)(param_1 + 0x20a3) == '#') && (*(char *)(lVar40 + 0xd) == '\x14')) {
                    uVar36 = CONCAT71((int7)((ulonglong)lVar40 >> 8),0x16);
                  }
                  else {
                    uVar36 = (ulonglong)*(byte *)(lVar40 + 0xd);
                  }
                  ppuVar37 = (undefined1 **)CONCAT71(uVar39,1);
                  in_stack_fffffffffffffe18 = CONCAT71(uVar61,cVar19);
                  in_stack_fffffffffffffe08 =
                       (undefined8 *)CONCAT71(uVar59,*(undefined1 *)(param_1 + 0x20a1));
                  FUN_1401417e0(*(longlong *)(param_1 + 0x1fd0),iVar31,ppuVar37,uVar36,
                                in_stack_fffffffffffffe08,*(undefined1 *)(param_1 + 0x20a2),
                                in_stack_fffffffffffffe18,uVar15);
                }
                if ((*(short *)(param_1 + 8000 + (ulonglong)*(byte *)(param_1 + 0x209d) * 0x18) == 0
                    ) && (bVar10)) {
                  pbVar1 = (byte *)(param_1 + 0x1f48 + (ulonglong)*(byte *)(param_1 + 0x209d) * 0x18
                                   );
                  *pbVar1 = *pbVar1 | 1;
                }
              }
              *(char *)(param_1 + 0x209d) = *(char *)(param_1 + 0x209d) + '\x01';
              if (*(byte *)(param_1 + 0x20b4) <= *(byte *)(param_1 + 0x209d)) {
                *(undefined1 *)(param_1 + 0x209d) = 0;
              }
              bVar9 = true;
              if ((*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x13') &&
                 (*(char *)(param_1 + 0x209a) == '\0')) {
                psVar5 = (short *)(*(undefined8 **)(local_res18 + 0x15fd8))[3];
                if ((psVar5 != (short *)0x0) &&
                   (((puVar60 = (undefined8 *)**(undefined8 **)(local_res18 + 0x15fd8),
                     puVar60 != (undefined8 *)0x0 && (*(short *)*puVar60 != 0)) && (*psVar5 == 0))))
                {
                  *psVar5 = 99;
                }
              }
              if (*(char *)(param_1 + 0x209a) == '\0') goto LAB_140105518;
            }
LAB_1401054f7:
            lVar29 = lVar29 + 1;
            fVar54 = local_184;
            fVar55 = local_1b8[0];
          } while (lVar29 < (longlong)local_110._0_8_);
          if (!bVar9) goto LAB_14010598e;
LAB_140105518:
          switch(*(undefined1 *)
                  ((ulonglong)*(byte *)(param_1 + 0x279a) + 4 + *(longlong *)(param_1 + 0xff8))) {
          case 1:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x67);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x68);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x69);
            }
            break;
          case 2:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x6a);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x6b);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x6c);
            }
            break;
          case 3:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x6d);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x6e);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x6f);
            }
            break;
          case 4:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x70);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x71);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x72);
            }
            break;
          case 5:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x73);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x74);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x75);
            }
            break;
          case 6:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x76);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x77);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x78);
            }
            break;
          case 7:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x79);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x7a);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x7b);
            }
            break;
          case 8:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x7c);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x7d);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x7e);
            }
            break;
          case 9:
          case 10:
          case 0xd:
          case 0xe:
          case 0xf:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,100);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x65);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x66);
            }
            break;
          case 0xb:
          case 0xc:
          case 0x10:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x61);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x62);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,99);
            }
            break;
          default:
            goto switchD_14010554b_caseD_11;
          case 0x12:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x82);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x83);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x84);
            }
            break;
          case 0x14:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x8e);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x8f);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x90);
            }
            break;
          case 0x15:
            cVar19 = *(char *)(param_1 + 0x2094);
            if (cVar19 == '\0') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x92);
            }
            else if (cVar19 == '\x02') {
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x93);
            }
            else {
              if (cVar19 != '\x01') goto switchD_14010554b_caseD_11;
              local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,0x94);
            }
          }
          in_stack_fffffffffffffe18 = in_stack_fffffffffffffe18 & 0xffffffffffffff00;
          local_res20[0] = '\x01';
          local_res20[1] = '\0';
          in_stack_fffffffffffffe08 = (undefined8 *)(param_1 + 0x15d0);
          ppuVar37 = &local_res8;
          local_1a8 = _DAT_1402d35f0;
          uStack_1a0 = _UNK_1402d35f8;
          FUN_1401c5d20(&local_1a8,local_res20,ppuVar37,param_1 + 0x70,in_stack_fffffffffffffe08,
                        &local_1a8,in_stack_fffffffffffffe18);
switchD_14010554b_caseD_11:
          if (*(char *)(param_1 + 0x2098) == '\0') {
            bVar18 = *(char *)(param_1 + 0x2099) != '\0';
          }
          else {
            bVar18 = *(byte *)(*(longlong *)(param_1 + 0xfd8) + 0xf);
            if (*(byte *)(param_1 + 0x209a) < bVar18) {
              bVar18 = *(byte *)(param_1 + 0x209a);
            }
          }
          FUN_1400c04e0(param_1 + 0x1e38,bVar18);
          *(uint *)(lVar41 + 0x1fc) = *(uint *)(lVar41 + 0x1fc) | 2;
        }
LAB_14010598e:
        if ((*(byte *)(param_1 + 0x1676) & 8) != 0) {
          cVar19 = *(char *)(param_1 + 0x2094);
          if (cVar19 == '\0') {
            uVar21 = 0xe1;
          }
          else if (cVar19 == '\x02') {
            uVar21 = 0xe2;
          }
          else {
            if (cVar19 != '\x01') goto LAB_1401059ee;
            uVar21 = 0xe3;
          }
          local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,uVar21);
          ppuVar37 = &local_res8;
          local_res20[0] = '\x01';
          local_res20[1] = '\0';
          FUN_1401c6150();
        }
LAB_1401059ee:
        param_2 = local_res10;
        uVar36 = DAT_14032c8f0;
        uVar25 = CONCAT71((int7)((ulonglong)ppuVar37 >> 8),0xe);
        bVar18 = *(byte *)(param_1 + 0x20a6);
        iVar31 = (int)((float)*(byte *)(param_1 + 0x20a0) * DAT_1402d2168);
        uVar30 = DAT_14032c8f0;
        cVar19 = FUN_140187a40(DAT_14032c8f0,local_res10,uVar25);
        if (cVar19 == '\0') {
          if ((bVar18 != 0) && ((int)(uint)bVar18 < iVar31)) {
            *(byte *)(param_1 + 0x1eee) = *(byte *)(param_1 + 0x1eee) & 0x3e | 1;
          }
          *(undefined1 *)(param_1 + 0x20a6) = 0;
        }
        else if ((int)(uint)bVar18 < iVar31) {
          *(byte *)(param_1 + 0x20a6) = bVar18 + 1;
        }
        uVar39 = (undefined7)((ulonglong)uVar25 >> 8);
        uVar11 = FUN_140187c80(uVar30,param_2,'\x0f');
        pbVar1 = (byte *)(param_1 + 0x1eee);
        if (uVar11 != '\0') {
          *pbVar1 = *pbVar1 & 0x3d | 2;
        }
        *(undefined1 *)(param_1 + 0x20a7) = 0;
        cVar19 = FUN_140187a40(uVar36,param_2,CONCAT71(uVar39,0x26));
        if (cVar19 == '\0') {
          if ((*(char *)(param_1 + 0x20a8) != '\0') &&
             (lVar29 = FUN_140189320(),
             (int)(uint)*(byte *)(param_1 + 0x20a8) < *(int *)(lVar29 + 0xc) / 2)) {
            bVar18 = *pbVar1;
            if ((char)bVar18 < '\0') {
              bVar18 = bVar18 & 0x7f;
            }
            else if ((bVar18 & 0x40) == 0) {
              if ((*(char *)(param_1 + 0x2098) != '\0') &&
                 ((*(char *)(param_1 + 0x2098) != '\x01' ||
                  (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xf) != '\x01')))) goto LAB_140105b34;
              bVar18 = bVar18 | 0x40;
              *(undefined1 *)(param_1 + 0x20a7) = 1;
            }
            else {
              bVar18 = bVar18 & 0xbf;
            }
            *(byte *)(param_1 + 0x1eee) = bVar18;
          }
LAB_140105b34:
          *(undefined1 *)(param_1 + 0x20a8) = 0;
        }
        else {
          lVar29 = FUN_140189320();
          if ((int)(uint)*(byte *)(param_1 + 0x20a8) < *(int *)(lVar29 + 0xc) / 2) {
            *(byte *)(param_1 + 0x20a8) = *(byte *)(param_1 + 0x20a8) + 1;
          }
          FUN_140189320();
        }
        FUN_1400c11c0(param_1 + 0x1e38);
        uVar36 = param_1;
        FUN_14010b000();
        in_stack_fffffffffffffe10 = param_1 + 0x10b0;
        bVar18 = FUN_140187c80(uVar36,param_2,'\x10');
        auVar47._0_4_ = (float)bVar18;
        auVar47._4_12_ = SUB1612(ZEXT816(0),4);
        FUN_1400b7b40(param_1 + 0x1868,*(undefined8 *)(param_1 + 0x2040),
                      *(undefined8 *)(param_1 + 0x1fc8),auVar47._0_8_,
                      (ulonglong)in_stack_fffffffffffffe08 & 0xffffffffffffff00,
                      in_stack_fffffffffffffe10);
        auVar56 = ZEXT464(local_100);
        fVar53 = local_fc;
        puVar52 = _DAT_1402d35f0;
        uVar25 = _UNK_1402d35f8;
      }
      uVar24 = local_114;
      fVar48 = local_138;
      fVar55 = local_1b8[0];
      fVar54 = local_184;
      fVar51 = local_118;
    }
    else {
      local_134 = *(undefined4 *)(param_1 + 0x1810);
      fVar42 = *(float *)(param_1 + 0x1808);
      local_130 = *(undefined4 *)(param_1 + 0x1814);
      uVar24 = *(undefined4 *)(param_1 + 0x1804);
      fVar48 = *(float *)(param_1 + 0x180c);
      fVar55 = *(float *)(param_1 + 0x17fc);
      fVar54 = *(float *)(param_1 + 0x1800);
      fVar51 = *(float *)(param_1 + 0x17f8);
    }
    *(float *)(param_1 + 0x1d80) =
         (*(float *)(param_1 + 0x1650) - *(float *)(param_1 + 0x1d80)) * fVar53 +
         *(float *)(param_1 + 0x1d80);
    *(float *)(param_1 + 0x1d84) =
         (*(float *)(param_1 + 0x1654) - *(float *)(param_1 + 0x1d84)) * fVar53 +
         *(float *)(param_1 + 0x1d84);
    *(float *)(param_1 + 0x1d88) =
         (*(float *)(param_1 + 0x1658) - *(float *)(param_1 + 0x1d88)) * fVar53 +
         *(float *)(param_1 + 0x1d88);
    *(float *)(param_1 + 0x1d8c) =
         (*(float *)(param_1 + 0x165c) - *(float *)(param_1 + 0x1d8c)) * DAT_1402d1fa8 +
         *(float *)(param_1 + 0x1d8c);
    *(float *)(param_1 + 0x1ce4) = fVar55;
    *(float *)(param_1 + 0x1ce0) = fVar51;
    *(float *)(param_1 + 0x1ce8) = fVar54;
    *(undefined4 *)(param_1 + 0x1cec) = uVar24;
    *(undefined4 *)(param_1 + 0x1cf8) = local_134;
    *(float *)(param_1 + 0x1cf0) = fVar42;
    *(undefined4 *)(param_1 + 0x1cfc) = local_130;
    *(float *)(param_1 + 0x1cf4) = fVar48;
    *(undefined1 *)(param_1 + 0x1da9) = *(undefined1 *)(param_1 + 0x1eed);
    *(undefined1 *)(param_1 + 0x1da8) = *(undefined1 *)(param_1 + 0x1eec);
    if ((*(byte *)(param_1 + 0x1676) & 1) == 0) {
      bVar18 = *(byte *)(param_1 + 0x1da7) & 0xfd;
    }
    else {
      bVar18 = *(byte *)(param_1 + 0x1da7) | 2;
    }
    *(byte *)(param_1 + 0x1da7) = bVar18;
    FUN_140111d40(param_1 + 0x1c50,param_2,*(undefined1 *)(param_1 + 0x2097));
    if ((*(byte *)(param_1 + 0x2058) & 2) == 0) {
      fVar53 = *(float *)(param_1 + 0x1850);
      if ((*(byte *)(*(longlong *)(param_1 + 0xff8) + 0xc) & 1) == 0) {
        fVar53 = auVar58._0_4_;
      }
      *(uint *)(param_1 + 0xc18) = *(uint *)(param_1 + 0x1650) ^ DAT_1402d3770;
      fVar42 = *(float *)(param_1 + 0x1664) * DAT_1402d2dbc;
      *(undefined4 *)(param_1 + 0xc1c) = *(undefined4 *)(param_1 + 0x1654);
      *(undefined4 *)(param_1 + 0xc20) = *(undefined4 *)(param_1 + 0x1658);
      *(undefined4 *)(param_1 + 0xc24) = *(undefined4 *)(param_1 + 0x1640);
      *(undefined4 *)(param_1 + 0xaf4) = *(undefined4 *)(param_1 + 0x1640);
      *(undefined4 *)(param_1 + 0xc28) = *(undefined4 *)(param_1 + 0x1854);
      *(float *)(param_1 + 0xc2c) = fVar53;
      *(undefined4 *)(param_1 + 0xc30) = *(undefined4 *)(param_1 + 0x1858);
      *(float *)(param_1 + 0xc34) = fVar42;
      if (auVar58._0_4_ <= fVar42) {
        if (auVar56._0_4_ < fVar42) {
          *(undefined4 *)(param_1 + 0xc34) = 0x3f800000;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0xc34) = 0;
      }
      lVar29 = param_1 + 0x110;
      if ((*(byte *)(param_1 + 0x1676) & 1) == 0) {
        uVar23 = *(uint *)(param_1 + 0xd48) & 0xffffefff;
      }
      else {
        uVar23 = *(uint *)(param_1 + 0xd48) | 0x1000;
      }
      *(uint *)(param_1 + 0xd48) = uVar23;
      FUN_140155ec0(param_1 + 0x110);
      cVar19 = *(char *)(param_1 + 0x2094);
      if (cVar19 == '\0') {
        FUN_140156b40(param_1 + 0x110);
      }
      else if (cVar19 == '\x01') {
        FUN_140156b40(lVar29);
        if (((byte)DAT_14032844c & 1) != 0) {
          FUN_140156ce0(lVar29);
        }
      }
      else if (cVar19 == '\x02') {
        FUN_140156bf0(lVar29);
      }
    }
    uVar24 = (undefined4)(in_stack_fffffffffffffe10 >> 0x20);
    lVar29 = *(longlong *)(param_1 + 0x1fc0);
    if ((lVar29 == 0) || (((byte)*(undefined4 *)(lVar41 + 0x1f0) & 3) != 1)) {
LAB_140105f4b:
      fVar53 = DAT_1402d2168;
      goto LAB_140105f59;
    }
    local_1a8 = *(undefined1 **)(param_1 + 0x70);
    uStack_1a0 = *(undefined8 *)(param_1 + 0x78);
    if (*(short *)(lVar41 + 0x442) != -1) {
      uVar21 = FUN_140035b10(*(undefined8 *)(lVar29 + 0x66ee0),2,&local_1a8,
                             *(short *)(lVar41 + 0x442),0xffff);
      *(undefined2 *)(lVar41 + 0x442) = uVar21;
      goto LAB_140105f4b;
    }
    local_198 = 0;
    uVar21 = FUN_140031f80(*(undefined8 *)(lVar29 + 0x66ee0),2,&local_1a8,0);
    fVar53 = DAT_1402d2168;
    *(undefined2 *)(lVar41 + 0x442) = uVar21;
  }
  if ((*(uint *)(param_1 + 0x2058) >> 0x18 & 1) == 0) {
    if ((*(char *)(param_1 + 0x2094) == '\x02') || ((*(uint *)(param_1 + 0x2058) >> 10 & 1) != 0)) {
      auVar50 = ZEXT1664(auVar56._0_16_);
    }
    else {
      auVar50 = ZEXT464((uint)(*(float *)(param_1 + 0x1d70) * DAT_1402d1ef4));
    }
    auVar47 = *(undefined1 (*) [16])(param_1 + 0x1d10);
    *(int *)(param_1 + 0x10e0) = auVar47._0_4_;
    uVar28 = vextractps_avx(auVar47,1);
    *(undefined4 *)(param_1 + 0x10e4) = uVar28;
    uVar28 = vextractps_avx(auVar47,2);
    *(undefined4 *)(param_1 + 0x10e8) = uVar28;
    uVar28 = vextractps_avx(auVar47,3);
    *(undefined4 *)(param_1 + 0x10ec) = uVar28;
    auVar47 = *(undefined1 (*) [16])(param_1 + 0x1d20);
    *(int *)(param_1 + 0x10f0) = auVar47._0_4_;
    uVar28 = vextractps_avx(auVar47,1);
    *(undefined4 *)(param_1 + 0x10f4) = uVar28;
    uVar28 = vextractps_avx(auVar47,2);
    *(undefined4 *)(param_1 + 0x10f8) = uVar28;
    uVar28 = vextractps_avx(auVar47,3);
    *(undefined4 *)(param_1 + 0x10fc) = uVar28;
    *(int *)(param_1 + 0x10bc) = auVar50._0_4_;
    *(undefined4 *)(param_1 + 0x10b8) = *(undefined4 *)(param_1 + 0x1d70);
    FUN_1401fbec0();
    auVar47 = *(undefined1 (*) [16])(param_1 + 0x1d00);
    *(int *)(param_1 + 0x12a0) = auVar47._0_4_;
    uVar28 = vextractps_avx(auVar47,1);
    *(undefined4 *)(param_1 + 0x12a4) = uVar28;
    uVar28 = vextractps_avx(auVar47,2);
    *(undefined4 *)(param_1 + 0x12a8) = uVar28;
    uVar28 = vextractps_avx(auVar47,3);
    *(undefined4 *)(param_1 + 0x12ac) = uVar28;
    auVar47 = *(undefined1 (*) [16])(param_1 + 0x1d20);
    *(int *)(param_1 + 0x12b0) = auVar47._0_4_;
    uVar28 = vextractps_avx(auVar47,1);
    *(undefined4 *)(param_1 + 0x12b4) = uVar28;
    uVar28 = vextractps_avx(auVar47,2);
    *(undefined4 *)(param_1 + 0x12b8) = uVar28;
    uVar28 = vextractps_avx(auVar47,3);
    *(undefined4 *)(param_1 + 0x12bc) = uVar28;
    *(undefined4 *)(param_1 + 0x1278) = *(undefined4 *)(param_1 + 0x1d70);
    *(int *)(param_1 + 0x127c) = auVar50._0_4_;
  }
  else {
    auVar47 = *(undefined1 (*) [16])(param_1 + 0x90);
    *(int *)(param_1 + 0x10e0) = auVar47._0_4_;
    uVar28 = vextractps_avx(auVar47,1);
    *(undefined4 *)(param_1 + 0x10e4) = uVar28;
    uVar28 = vextractps_avx(auVar47,2);
    *(undefined4 *)(param_1 + 0x10e8) = uVar28;
    uVar28 = vextractps_avx(auVar47,3);
    *(undefined4 *)(param_1 + 0x10ec) = uVar28;
    auVar47 = *(undefined1 (*) [16])(param_1 + 0xa0);
    *(int *)(param_1 + 0x10f0) = auVar47._0_4_;
    uVar28 = vextractps_avx(auVar47,1);
    *(undefined4 *)(param_1 + 0x10f4) = uVar28;
    uVar28 = vextractps_avx(auVar47,2);
    *(undefined4 *)(param_1 + 0x10f8) = uVar28;
    uVar28 = vextractps_avx(auVar47,3);
    *(undefined4 *)(param_1 + 0x10fc) = uVar28;
    *(undefined4 *)(param_1 + 0x10b8) = 0x44000000;
  }
  FUN_1401fbec0();
  if ((*(byte *)(lVar41 + 0x1f0) & 1) != 0) {
    lVar29 = *(longlong *)(param_1 + 0x1fa8);
    uVar15 = *(undefined1 *)(param_1 + 0x2094);
    pbVar1 = (byte *)(lVar29 + 0x44);
    *pbVar1 = *pbVar1 & 0xfd;
    *(undefined1 *)(lVar29 + 0x41) = uVar15;
    lVar29 = *(longlong *)(param_1 + 0x1fa8);
    *(undefined4 *)(lVar29 + 0x4c) = *(undefined4 *)(param_1 + 0x70);
    *(undefined4 *)(lVar29 + 0x50) = *(undefined4 *)(param_1 + 0x74);
    *(undefined4 *)(lVar29 + 0x54) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(lVar29 + 0x58) = *(undefined4 *)(param_1 + 0x7c);
    lVar29 = *(longlong *)(param_1 + 0x1fa8);
    *(undefined4 *)(lVar29 + 0x5c) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(lVar29 + 0x60) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(lVar29 + 100) = *(undefined4 *)(param_1 + 0x88);
    *(undefined4 *)(lVar29 + 0x68) = *(undefined4 *)(param_1 + 0x8c);
    FUN_1401c81f0(*(undefined8 *)(param_1 + 0x1fa8),*(undefined4 *)(param_1 + 0x1850),
                  *(undefined4 *)(param_1 + 0x1854));
    plVar6 = *(longlong **)(param_1 + 0x1fa8);
    if (((*(byte *)((longlong)plVar6 + 0x44) & 1) == 0) || ((*(byte *)(lVar41 + 0x1f0) & 2) == 0)) {
      (**(code **)(*plVar6 + 0x10))();
    }
    else {
      *(undefined4 *)(param_1 + 0x2084) = 0;
      (**(code **)*plVar6)();
    }
    FUN_14010c9a0(param_1,0);
    FUN_14010c3f0(param_1);
    if (((*(byte *)(lVar41 + 0x1f0) & 2) != 0) &&
       (FUN_14010be70(param_1), (*(byte *)(lVar41 + 0x1f0) & 2) != 0)) {
      FUN_14010dec0(param_1);
    }
    bVar18 = FUN_140078e50(*(undefined8 *)(param_1 + 0x2038),(undefined4 *)(param_1 + 0x70),
                           DAT_1402d20d0);
    bVar27 = (bVar18 ^ *(byte *)(param_1 + 0x20c3)) << 4;
    *(byte *)(param_1 + 0x20c3) = bVar27 | bVar18;
    if (bVar27 != 0 || (bVar18 & 0xf0) != 0) {
      DAT_140310a8c = 500;
      DAT_140310a98 = 2;
      _DAT_140310aac = 500;
      DAT_140310ab8 = 2;
      if (bVar18 == 0) {
        DAT_140310a90 = DAT_1402d2778 * DAT_1437decf8;
        DAT_140310a94 = (DAT_140310a90 - DAT_140310a84) * DAT_1402d1e6c;
        _DAT_140310ab0 = DAT_1402d2778 * DAT_1437decfc;
        _DAT_140310ab4 = (_DAT_140310ab0 - DAT_140310aa4) * DAT_1402d1e6c;
      }
      else {
        DAT_140310a94 = (DAT_1402d2778 - DAT_140310a84) * DAT_1402d1e6c;
        _DAT_140310ab4 = (DAT_1402d2778 - DAT_140310aa4) * DAT_1402d1e6c;
        DAT_140310a90 = DAT_1402d2778;
        _DAT_140310ab0 = DAT_1402d2778;
      }
    }
    cVar19 = *(char *)(param_1 + 0x2094);
    uVar32 = 0x101;
    uVar34 = 0x107;
    uVar21 = 0x10a;
    if (cVar19 == '\x02') {
      uVar32 = 0x102;
      uVar34 = 0x108;
      uVar21 = 0x10b;
    }
    else if (cVar19 == '\x01') {
      uVar32 = 0x103;
      uVar34 = 0x109;
      uVar21 = 0x10c;
    }
    puVar45 = *(undefined1 **)(param_1 + 0x15d0);
    uStack_120 = *(undefined8 *)(param_1 + 0x15d8);
    local_128 = puVar45;
    if (*(short *)(param_1 + 0xb48) == 1) {
      local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,uVar21);
      puVar60 = &local_1a8;
      local_res20[0] = '\x01';
      local_res20[1] = '\0';
      local_1a8 = puVar52;
      uStack_1a0 = uVar25;
      puVar45 = (undefined1 *)
                FUN_1401c5d20(cVar19,local_res20,&local_res8,param_1 + 0x70,&local_128,puVar60,
                              in_stack_fffffffffffffe18 & 0xffffffffffffff00);
      uVar24 = (undefined4)((ulonglong)puVar60 >> 0x20);
    }
    sVar20 = *(short *)(lVar41 + 0x428);
    if ((sVar20 <= *(char *)(param_1 + 0x20c1)) && (0 < sVar20)) {
      local_res8 = (undefined1 *)CONCAT62(local_res8._2_6_,uVar32);
      local_res20[0] = '\x01';
      local_res20[1] = '\0';
      puVar45 = (undefined1 *)FUN_1401c6150(sVar20,local_res20,&local_res8);
      *(char *)(param_1 + 0x20c1) = *(char *)(lVar41 + 0x428) + -1;
    }
    if ((*(float *)(param_1 + 0x207c) <= auVar58._0_4_) || ((*(byte *)(lVar41 + 0x1f0) & 2) == 0)) {
LAB_1401064aa:
      FUN_1401c6490(puVar45,param_1 + 0x2068);
    }
    else {
      uVar36 = (ulonglong)local_res8 >> 0x10;
      local_res8 = (undefined1 *)((ulonglong)local_res8 & 0xffffffffffff0000);
      if (*(char *)(param_1 + 0x20c2) == '\x01') {
        local_res8 = (undefined1 *)CONCAT62((int6)uVar36,0xfd44);
      }
      lVar29 = param_1 + 0x2068;
      cVar19 = FUN_1401c5910(puVar45,lVar29);
      if (cVar19 == '\0') {
        local_res20[0] = '\0';
        local_res20[1] = '\0';
        local_1b8[0] = (float)CONCAT22(local_1b8[0]._2_2_,1);
        local_188[0] = uVar34;
        uVar25 = FUN_1401c97a0();
        ppuVar37 = &local_res8;
        FUN_1401ca240(uVar25,local_1b8,local_188,param_1 + 0x207c,local_res20,ppuVar37,lVar29);
        uVar24 = (undefined4)((ulonglong)ppuVar37 >> 0x20);
      }
      else {
        puVar45 = extraout_XMM0_Qa_03;
        if (*(char *)(param_1 + 0x2094) != *(char *)(param_1 + 0x20a5)) goto LAB_1401064aa;
        local_res20[0] = '\0';
        local_res20[1] = '\0';
        FUN_1401c63a0(extraout_XMM0_Qa_03,lVar29,param_1 + 0x207c,local_res20,&local_res8);
      }
    }
  }
  if ((((*(byte *)(param_1 + 0x2058) & 2) == 0) && ((*(byte *)(lVar41 + 0x1f0) & 1) != 0)) &&
     (*(longlong *)(param_1 + 0x1fc0) != 0)) {
    lVar29 = *(longlong *)(*(longlong *)(param_1 + 0x1fc0) + 0x66ee0);
    if (*(char *)(param_1 + 0x2094) == '\x01') {
      *(undefined2 *)(lVar29 + 0x336d4) = 1;
    }
    else if (*(char *)(param_1 + 0x2094) == '\x02') {
      *(undefined2 *)(lVar29 + 0x336d4) = 2;
    }
    else {
      *(undefined2 *)(lVar29 + 0x336d4) = 0;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x1fd0) + 0x2a6) & 0x42) == 2) {
      *(undefined2 *)(*(longlong *)(*(longlong *)(param_1 + 0x1fc0) + 0x66ee0) + 0x336d4) = 1;
    }
    uVar23 = *(uint *)(param_1 + 0x2058);
    if ((uVar23 & 4) != 0) {
      local_1a8 = *(undefined1 **)(param_1 + 0x15e0);
      uStack_1a0 = *(undefined8 *)(param_1 + 0x15e8);
      FUN_140102710(param_1 + 0x1db0,&local_1a8,*(undefined4 *)(param_1 + 0x1640));
      *(undefined4 *)(param_1 + 0xb24) = *(undefined4 *)(param_1 + 0x1e24);
      *(undefined4 *)(param_1 + 0xb30) = *(undefined4 *)(param_1 + 0x1e28);
      uVar23 = *(uint *)(param_1 + 0x2058);
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0xff8) + 0xc) & 1) == 0) {
      uVar28 = auVar58._0_4_;
    }
    else {
      uVar28 = *(undefined4 *)(param_1 + 0x1850);
    }
    *(undefined4 *)(param_1 + 0xb00) = *(undefined4 *)(param_1 + 0x1854);
    *(undefined4 *)(param_1 + 0xb04) = uVar28;
    if ((uVar23 & 8) != 0) {
      *(ushort *)(param_1 + 0xae4) = *(ushort *)(param_1 + 0xae4) | 1;
      *(undefined4 *)(param_1 + 0xb20) = *(undefined4 *)(param_1 + 0x1854);
    }
    if ((uVar23 & 0x10) == 0) {
      uVar28 = 0;
      if (*(char *)(param_1 + 0x2094) == '\x02') {
        iVar31 = 3;
      }
      else {
        iVar31 = (*(char *)(param_1 + 0x2094) == '\x01') + 1;
      }
    }
    else {
      uVar28 = 1;
      iVar31 = 0;
    }
    FUN_14000eb50(param_1 + 0x110,*(undefined8 *)(param_1 + 0x1fc0),param_1 + 0x70,param_1 + 0x80,
                  uVar28,CONCAT44(uVar24,iVar31));
    local_1c8 = (undefined1 *)0x0;
    uStack_1c0 = 0;
    FUN_140102590(*(undefined8 *)(param_1 + 0x1fc8),&local_1c8,&local_res8);
    FUN_140158ee0(param_1 + 0x110,(ulonglong)local_res8 & 0xffffffff);
    if ((*(byte *)(param_1 + 0x2058) & 0x10) == 0) {
      local_1a8 = local_1c8;
      uStack_1a0 = uStack_1c0;
    }
    else {
      _auStack_168 = ZEXT816(0);
      _local_178 = ZEXT816(0);
      _local_158 = ZEXT816(0);
      _local_148 = _auStack_168;
      FUN_140202920(local_178,param_1 + 0x80);
      auVar47 = vshufps_avx(_local_148,_local_148,0x55);
      auVar57 = vshufps_avx(_auStack_168,_auStack_168,0x55);
      local_1a8 = (undefined1 *)
                  CONCAT44(uStack_1c0._4_4_ * auVar47._0_4_ +
                           (float)uStack_1c0 * (float)local_158._4_4_ +
                           local_1c8._4_4_ * auVar57._0_4_ +
                           (float)local_1c8 * (float)local_178._4_4_,
                           uStack_1c0._4_4_ * local_148._0_4_ +
                           (float)uStack_1c0 * (float)local_158._0_4_ +
                           local_1c8._4_4_ * auStack_168._0_4_ +
                           (float)local_1c8 * (float)local_178._0_4_);
      auVar47 = vshufps_avx(_local_148,_local_148,0xaa);
      auVar57 = vshufps_avx(_auStack_168,_auStack_168,0xaa);
      auVar7 = vshufps_avx(_local_148,_local_148,0xff);
      auVar8 = vshufps_avx(_auStack_168,_auStack_168,0xff);
      uStack_1a0 = CONCAT44(uStack_1c0._4_4_ * auVar7._0_4_ + (float)uStack_1c0 * fStack_14c +
                            local_1c8._4_4_ * auVar8._0_4_ + (float)local_1c8 * fStack_16c,
                            uStack_1c0._4_4_ * auVar47._0_4_ + (float)uStack_1c0 * fStack_150 +
                            local_1c8._4_4_ * auVar57._0_4_ + (float)local_1c8 * fStack_170);
    }
    FUN_140158e70(param_1 + 0x110,&local_1a8);
    auVar47 = auVar56._0_16_;
    auVar57 = auVar58._0_16_;
    if ((*(byte *)(param_1 + 0x2058) & 0x80) == 0) {
      local_1a8 = *(undefined1 **)(param_1 + 0x70);
      uStack_1a0 = *(undefined8 *)(param_1 + 0x78);
      local_res8 = (undefined1 *)((ulonglong)local_res8 & 0xffffffff00000000);
      fVar42 = (float)FUN_140078db0(*(undefined8 *)(param_1 + 0x2038),&local_1a8,&local_res8);
      auVar57 = _local_158;
      auVar47 = *(undefined1 (*) [16])(param_1 + 0x15d0);
      _local_178 = *(undefined1 (*) [16])(param_1 + 0x70);
      auStack_168._4_4_ = vextractps_avx(auVar47,1);
      auStack_168._0_4_ = auVar47._0_4_;
      fStack_160 = (float)vextractps_avx(auVar47,2);
      fStack_15c = (float)vextractps_avx(auVar47,3);
      local_158._4_4_ = 0;
      local_158._0_4_ = *(float *)(param_1 + 0x74) - fVar42;
      fStack_14c = auVar57._12_4_;
      fStack_150 = local_res8._0_4_;
      FUN_140031f80(*(undefined8 *)(*(longlong *)(param_1 + 0x1fc0) + 0x66ee0),5,local_178,0);
      auVar47 = auVar56._0_16_;
      auVar57 = auVar58._0_16_;
    }
    _local_178 = *(undefined1 (*) [16])(param_1 + 0x70);
    _auStack_168 = *(undefined1 (*) [16])(param_1 + 0x80);
    _local_158 = ZEXT816(0);
    auVar7 = vmaxss_avx(ZEXT416((uint)((*(float *)(param_1 + 0x1848) - DAT_1402d295c) *
                                      DAT_1402d1e48)),auVar57);
    vminss_avx(auVar7,auVar47);
    auVar56 = ZEXT1664(auVar47);
    auVar58 = ZEXT1664(auVar57);
    fVar42 = (float)FUN_140275650();
    auVar47 = _local_148;
    fStack_140 = fVar42 * DAT_1402d2134;
    local_148._0_4_ = auVar47._0_4_;
    local_148._4_4_ = auVar56._0_4_;
    fStack_13c = 5.90052e-39;
    uVar21 = FUN_140035b10(*(undefined8 *)(*(longlong *)(param_1 + 0x1fc0) + 0x66ee0),0x79,local_178
                           ,*(undefined2 *)(lVar41 + 0x444),0xffff);
    *(undefined2 *)(lVar41 + 0x444) = uVar21;
  }
  FUN_140103e40(param_1);
  if (((*(byte *)(param_1 + 0x2058) & 0x40) != 0) && (0 < *(short *)(param_1 + 0x1860))) {
    if (*(short *)(lVar41 + 0x428) < 1) {
      uVar24 = FUN_140079920(*(undefined8 *)(param_1 + 0x2030),lVar41 + 600);
      FUN_140117a10(lVar41,uVar24);
      *(uint *)(lVar41 + 0x1f0) = *(uint *)(lVar41 + 0x1f0) & 0xfffffffe;
    }
    else {
      local_res8 = (undefined1 *)0x0;
      FUN_140118040(lVar41,&local_res8,0,*(short *)(param_1 + 0x1860),5,0,
                    *(undefined1 *)(param_1 + 0x1865));
    }
  }
  if ((*(byte *)(param_1 + 0x2058) & 2) != 0) {
    return;
  }
  FUN_14010ead0(param_1);
  uVar25 = auVar56._0_8_;
  if ((*(byte *)(param_1 + 0x2058) & 2) != 0) {
    return;
  }
  puVar33 = (ushort *)(param_1 + 0x2090);
  lVar40 = (ulonglong)*(byte *)(param_1 + 0x20a2) * 0x520;
  lVar41 = *(longlong *)
            (**(longlong **)(param_1 + 0x2040) + (ulonglong)*(byte *)(param_1 + 0x20a1) * 8);
  uVar22 = *puVar33;
  lVar29 = *(longlong *)(lVar41 + 0x110);
  uVar39 = (undefined7)((ulonglong)lVar41 >> 8);
  if (*(short *)(lVar40 + 0x428 + lVar29) < 1) {
    if ((uVar22 & 0x10) == 0) {
      FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),CONCAT71(uVar39,6),
                    auVar58._0_8_);
      *puVar33 = *puVar33 | 0x10;
    }
  }
  else {
    *puVar33 = uVar22 & 0xffef;
    if ((uVar22 >> 8 & 1) == 0) {
      uVar4 = *(ushort *)(param_1 + 0x2792);
      if (uVar4 == 0) {
        *puVar33 = uVar22 & 0xfeef;
        uVar21 = 0;
      }
      else {
        if (0x77 < uVar4) {
          auVar47 = vmaxss_avx(ZEXT416((uint)(-((float)(uVar4 - 0x78) * DAT_1402d1e90) +
                                             auVar56._0_4_)),auVar58._0_16_);
          uVar25 = auVar47._0_8_;
        }
        FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),0,uVar25);
        *(undefined1 *)(param_1 + 0x1dae) = 5;
        *puVar33 = *puVar33 & 0xfeff;
        if (*(ushort *)(param_1 + 0x2792) < 0x1a4) {
          uVar21 = (undefined2)((*(ushort *)(param_1 + 0x2792) + 1) % 0xffff);
        }
        else {
          uVar21 = 0;
        }
      }
    }
    else {
      FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),CONCAT71(uVar39,6),
                    auVar58._0_8_);
      *(undefined1 *)(param_1 + 0x1dae) = 5;
      uVar21 = 1;
      *puVar33 = *puVar33 & 0xfeff;
    }
    puVar33 = (ushort *)(param_1 + 0x2090);
    *(undefined2 *)(param_1 + 0x2792) = uVar21;
    if ((*(byte *)puVar33 & 0x23) != 0) {
      FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),8,auVar58._0_8_);
      *(undefined1 *)(param_1 + 0x1dae) = 5;
      *puVar33 = *puVar33 & 0xffdc;
    }
    if (auVar58._0_4_ < *(float *)(param_1 + 0x1850)) {
      FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),1,auVar58._0_8_);
      *(undefined1 *)(param_1 + 0x1dae) = 1;
    }
    fVar42 = DAT_1402d2638;
    if ((*(float *)(param_1 + 0x1858) <= auVar58._0_4_) ||
       (*(float *)(param_1 + 0x1848) <= DAT_1402d2638)) {
      *(undefined4 *)(param_1 + 0x2794) = 0;
    }
    else {
      if ((*(float *)(param_1 + 0x184c) <= auVar58._0_4_) && (*(uint *)(param_1 + 0x2794) < 0x12d))
      {
        FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),0);
        *(undefined1 *)(param_1 + 0x1dae) = 2;
      }
      *(int *)(param_1 + 0x2794) = *(int *)(param_1 + 0x2794) + 1;
    }
    puVar52 = (undefined1 *)(param_1 + 0x20b3);
    if ((*(uint *)(lVar40 + 0x1f8 + lVar29) & 0x20000000) != 0) {
      FUN_140188d80(param_1 + 0x1010,*puVar52,4,auVar58._0_8_);
      *(undefined1 *)(param_1 + 0x1dae) = 10;
    }
    if ((*(uint *)(lVar40 + 0x1f8 + lVar29) & 0x10000000) != 0) {
      FUN_140188d80(param_1 + 0x1010,*puVar52,5,auVar58._0_8_);
      *(undefined1 *)(param_1 + 0x1dae) = 0x1e;
    }
    local_res8 = (undefined1 *)(param_1 + 0x1dae);
    if ((*(uint *)(lVar40 + 0x1f8 + lVar29) & 0x40000000) != 0) {
      FUN_140188d80(param_1 + 0x1010,*puVar52,5,auVar58._0_8_);
      *(undefined1 *)(param_1 + 0x1dae) = 0x1e;
    }
    if (*(int *)(lVar40 + 0x1f8 + lVar29) < 0) {
      FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),7,auVar58._0_8_);
      *local_res8 = 10;
    }
    lVar41 = param_1 + 0x1010;
    bVar18 = *(byte *)(param_1 + 0x1676);
    uVar25 = auVar58._0_8_;
    if ((bVar18 & 1) == 0) {
      *(undefined2 *)(param_1 + 0x2798) = 0;
      if (auVar58._0_4_ < *(float *)(param_1 + 0x184c)) {
        if (bVar18 == 0) {
          if (*(float *)(param_1 + 0x184c) <= fVar53) {
            if ((*(ushort *)(param_1 + 0x2090) & 0x400) == 0) {
              FUN_140188d80(lVar41,*(undefined1 *)(param_1 + 0x20b3),9,uVar25);
              *(undefined1 *)(param_1 + 0x1dae) = 5;
            }
          }
          else {
            FUN_140188d80(lVar41,*(undefined1 *)(param_1 + 0x20b3),10,uVar25);
            *(undefined1 *)(param_1 + 0x1dae) = 10;
            *(ushort *)(param_1 + 0x2090) = *(ushort *)(param_1 + 0x2090) | 0x400;
          }
        }
        goto LAB_140106e78;
      }
      uVar22 = 0xfbff;
    }
    else {
      if (((bVar18 & 8) != 0) && (DAT_1402d24d0 < *(float *)(param_1 + 0x1848))) {
        FUN_140188d80(lVar41,*(undefined1 *)(param_1 + 0x20b3),2,uVar25);
        *(undefined1 *)(param_1 + 0x1dae) = 5;
      }
      uVar25 = auVar58._0_8_;
      if (*(float *)(param_1 + 0x1848) <= fVar42) {
        sVar20 = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x1dae) = 5;
        if (*(ushort *)(param_1 + 0x2798) < (ushort)((ushort)*(byte *)(param_1 + 0x20a0) * 5)) {
          FUN_140188d80(lVar41,*(undefined1 *)(param_1 + 0x20b3),3);
          uVar25 = auVar58._0_8_;
        }
        sVar20 = *(ushort *)(param_1 + 0x2798) + 1;
        if ((ushort)((ushort)*(byte *)(param_1 + 0x20a0) * 6) <= *(ushort *)(param_1 + 0x2798)) {
          sVar20 = 0;
        }
      }
      *(short *)(param_1 + 0x2798) = sVar20;
      uVar22 = *(ushort *)(param_1 + 0x2090);
      if ((uVar22 & 4) != 0) {
        FUN_140188d80(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3),6,uVar25);
        *(undefined1 *)(param_1 + 0x1dae) = 10;
        uVar22 = *(ushort *)(param_1 + 0x2090) & 0xfffb;
        *(ushort *)(param_1 + 0x2090) = uVar22;
      }
      if ((uVar22 & 8) == 0) goto LAB_140106e78;
      *(undefined1 *)(param_1 + 0x1dae) = 10;
      uVar22 = 0xfff7;
    }
    *(ushort *)(param_1 + 0x2090) = *(ushort *)(param_1 + 0x2090) & uVar22;
  }
LAB_140106e78:
  FUN_140188fb0(param_1 + 0x1010,*(undefined1 *)(param_1 + 0x20b3));
  return;
}

