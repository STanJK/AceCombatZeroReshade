/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400ce880; RVA 0xce880
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ce880(longlong param_1)

{
  ushort *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  longlong lVar4;
  float fVar5;
  undefined1 auVar6 [16];
  byte bVar7;
  longlong lVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  char cVar14;
  uchar uVar15;
  char cVar16;
  undefined1 uVar17;
  byte bVar18;
  longlong lVar19;
  ulonglong uVar20;
  undefined1 (*pauVar21) [16];
  longlong *plVar22;
  longlong *plVar23;
  short sVar24;
  uint uVar25;
  char *pcVar26;
  int iVar27;
  undefined8 *puVar28;
  byte *pbVar29;
  undefined1 uVar30;
  int iVar31;
  uint uVar32;
  longlong lVar33;
  longlong unaff_GS_OFFSET;
  bool bVar34;
  undefined4 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 extraout_XMM0_Qa;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined1 auVar44 [64];
  float fVar45;
  undefined4 uVar46;
  undefined1 auVar47 [64];
  undefined1 auVar48 [64];
  undefined1 auVar49 [64];
  undefined1 auVar50 [64];
  undefined1 auVar51 [64];
  byte local_res8 [8];
  char local_res10;
  undefined1 local_res18;
  undefined2 local_res20 [4];
  undefined2 local_158 [2];
  int local_154;
  byte *local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined1 local_122;
  undefined1 local_121;
  undefined1 local_120;
  undefined1 local_11f;
  undefined1 local_11e;
  undefined1 local_11d;
  undefined1 local_11c;
  undefined1 local_11b;
  undefined1 local_11a;
  undefined1 local_119;
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined1 local_d8 [32];
  undefined8 local_b8;
  undefined8 uStack_b0;
  
  *(undefined1 *)(param_1 + 0xa8796) = *(undefined1 *)(*(longlong *)(param_1 + 0xa8318) + 0x20);
  DAT_14033bd60 = 0;
  FUN_140019ef0();
  lVar19 = FUN_140189320();
  iVar31 = 0;
  iVar27 = 0;
  lVar33 = (longlong)*(char *)(param_1 + 0xa8829) * 0xd10 + *(longlong *)(param_1 + 0x67138);
  auVar9 = vpcmpeqd_avx(ZEXT416((uint)*(byte *)(lVar19 + 0x28)),SUB6416(ZEXT464(0),0));
  auVar9 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar9);
  auVar51 = ZEXT1664(auVar9);
  auVar9 = vpcmpeqd_avx(ZEXT416((uint)*(byte *)(lVar19 + 0x28)),SUB6416(ZEXT464(0),0));
  fVar5 = *(float *)(lVar33 + 0xcdc);
  auVar9 = vblendvps_avx(ZEXT416(DAT_1402d2928),ZEXT416(DAT_1402d293c),auVar9);
  auVar44 = ZEXT1664(auVar9);
  fVar45 = -(fVar5 * *(float *)(lVar33 + 0xce0)) + fVar5;
  auVar47 = ZEXT464((uint)fVar45);
  fVar5 = *(float *)(lVar33 + 0xce0) * fVar5;
  auVar49 = ZEXT464((uint)fVar5);
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    fVar5 = fVar5 * DAT_1402d21c0;
    auVar48 = ZEXT464((uint)fVar5);
    auVar50 = ZEXT464(DAT_1402d20d0);
    lVar19 = 0;
    do {
      lVar8 = *(longlong *)(param_1 + 0xa8248);
      auVar9 = vcmpss_avx(auVar48._0_16_,auVar47._0_16_,1);
      auVar9 = vblendvps_avx(auVar49._0_16_,auVar47._0_16_,auVar9);
      uVar35 = auVar44._0_4_;
      *(undefined4 *)(lVar19 + 0x1d64 + lVar8) = uVar35;
      *(int *)(lVar19 + 0x1d68 + lVar8) = auVar51._0_4_;
      *(undefined4 *)(lVar19 + 0x1d6c + lVar8) = uVar35;
      *(undefined4 *)(lVar19 + 0x1bd0 + lVar8) = uVar35;
      *(bool *)(lVar19 + 0x20c2 + lVar8) = fVar45 <= fVar5;
      *(int *)(lVar19 + 0x207c + lVar8) = auVar9._0_4_;
      cVar14 = FUN_140078e50(*(undefined8 *)(lVar19 + 0x2038 + lVar8),lVar19 + 0x70 + lVar8,
                             auVar50._0_8_);
      if (cVar14 != '\0') {
        *(uint *)(lVar33 + 0xc84) = *(uint *)(lVar33 + 0xc84) | 1;
      }
      iVar27 = iVar27 + 1;
      lVar19 = lVar19 + 0x27a0;
    } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  if ((((DAT_140328440 != 0) &&
       (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10), lVar19 != 0)) &&
      (*(longlong *)(lVar19 + 0x2d8) != 0)) &&
     ((lVar33 = *(longlong *)(*(longlong *)(lVar19 + 0x2d8) + 8), lVar33 != 0 &&
      (uVar20 = (ulonglong)*(byte *)(lVar19 + 0x3c9), (*(byte *)(lVar19 + 0x3a8) & 1) == 0)))) {
    cVar14 = **(char **)(lVar33 + uVar20 * 0x48);
    if (cVar14 == '\x04') {
      plVar22 = *(longlong **)(lVar33 + 0x10 + uVar20 * 0x48);
      if ((plVar22 != (longlong *)0x0) && (lVar33 = *plVar22, (*(byte *)(lVar33 + 0x30) & 4) != 0))
      {
        bVar18 = *(byte *)(lVar33 + 0x31);
        bVar7 = *(byte *)(lVar33 + 0x32);
LAB_1400ceadc:
        if ((bVar18 != 0xff) && (bVar7 != 0xff)) {
          lVar19 = *(longlong *)
                    (*(longlong *)(**(longlong **)(lVar19 + 0x2f8) + (ulonglong)bVar18 * 8) + 0x110)
          ;
          puVar28 = (undefined8 *)(lVar19 + 600 + (ulonglong)bVar7 * 0x520);
          _DAT_14033bb80 = *puVar28;
          _DAT_14033bb88 = puVar28[1];
          _DAT_14033bb90 = *(undefined1 (*) [16])(lVar19 + 0x268 + (ulonglong)bVar7 * 0x520);
        }
      }
    }
    else if (((cVar14 == '\x05') &&
             (plVar22 = *(longlong **)(lVar33 + 0x18 + uVar20 * 0x48), plVar22 != (longlong *)0x0))
            && (lVar33 = *plVar22, (*(byte *)(lVar33 + 0x2e) & 4) != 0)) {
      bVar18 = *(byte *)(lVar33 + 0x2f);
      bVar7 = *(byte *)(lVar33 + 0x30);
      goto LAB_1400ceadc;
    }
  }
  uVar25 = *(uint *)(param_1 + 0xa8790);
  uVar32 = uVar25 | 4;
  *(uint *)(param_1 + 0xa8790) = uVar32;
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if ((lVar19 != 0) && (*(char *)(lVar19 + 0x3cc) == '\0')) {
    uVar32 = uVar25 | 0x10004;
    *(uint *)(param_1 + 0xa8790) = uVar32;
  }
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if ((lVar19 != 0) && ((*(byte *)(lVar19 + 0x3a8) & 0x20) != 0)) {
    uVar32 = uVar32 | 0x10000;
    *(uint *)(param_1 + 0xa8790) = uVar32;
  }
  if ((((uVar32 & 3) == 0) && (DAT_14032c8e8[0x28] == 0)) ||
     ((bVar18 = *(byte *)(param_1 + 0xa87e4), (uVar32 & 3) == 0 &&
      ((((1 < bVar18 && (DAT_14032c8e8[0x29] == 0)) || (DAT_14032c93d != '\0')) ||
       (DAT_14032c93b != '\0')))))) {
LAB_1400ceb9d:
    plVar22 = *(longlong **)(param_1 + 0x67158);
    (**(code **)(*plVar22 + 0x28))();
    uVar32 = *(uint *)(param_1 + 0xa8790);
    if ((uVar32 >> 0x10 & 1) != 0) goto LAB_1400cec79;
    uVar32 = uVar32 & 0x7ffffffe | 1;
LAB_1400cec69:
    *(uint *)(param_1 + 0xa8790) = uVar32;
LAB_1400cec6f:
    if ((uVar32 >> 0x10 & 1) != 0) goto LAB_1400cec79;
  }
  else {
    plVar22 = DAT_14032c8e8;
    if (((uVar32 >> 1 & 1) == 0) &&
       (uVar15 = FUN_140187c80((ulonglong)DAT_14032c8e8,'\0','\0'), uVar15 != '\0')) {
      if ((uVar32 & 1) != 0) {
        uVar32 = uVar32 | 0x80000000;
        goto LAB_1400cec69;
      }
      goto LAB_1400ceb9d;
    }
    if (((bVar18 < 2) || ((uVar32 & 1) != 0)) ||
       (uVar15 = FUN_140187c80((ulonglong)plVar22,'\x01','\0'), uVar15 == '\0')) goto LAB_1400cec6f;
    if ((uVar32 >> 1 & 1) != 0) {
      uVar32 = uVar32 | 0x80000000;
      goto LAB_1400cec69;
    }
    plVar22 = *(longlong **)(param_1 + 0x67158);
    (**(code **)(*plVar22 + 0x28))();
    uVar32 = *(uint *)(param_1 + 0xa8790);
    if ((uVar32 >> 0x10 & 1) == 0) {
      uVar32 = uVar32 & 0x7ffffffd | 2;
      goto LAB_1400cec69;
    }
LAB_1400cec79:
    lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if (lVar19 != 0) {
      puVar28 = *(undefined8 **)(lVar19 + 0x2d8);
      if ((puVar28 == (undefined8 *)0x0) ||
         (plVar23 = (longlong *)(ulonglong)*(byte *)(lVar19 + 0x3c9), plVar22 = plVar23,
         *(byte *)*puVar28 <= *(byte *)(lVar19 + 0x3c9))) {
LAB_1400cecbc:
        plVar22 = (longlong *)CONCAT71((int7)((ulonglong)plVar22 >> 8),0xff);
      }
      else {
        plVar22 = (longlong *)((longlong)plVar23 * 9);
        puVar28 = (undefined8 *)(puVar28[1] + (longlong)plVar23 * 0x48);
        if (puVar28 == (undefined8 *)0x0) goto LAB_1400cecbc;
        plVar22 = (longlong *)(ulonglong)*(byte *)*puVar28;
      }
      cVar14 = *(char *)(lVar19 + 0x3cc);
      cVar16 = (char)plVar22;
      if (cVar16 == '\0') {
        if (cVar14 == '\t') goto LAB_1400cece3;
      }
      else if (cVar16 == '\x04') {
        if (cVar14 == '\b') {
LAB_1400cece3:
          if (*(char *)(param_1 + 0xa8820) != '\0') {
            *(uint *)(param_1 + 0xa8790) = uVar32 & 0x7ffffffc;
          }
        }
      }
      else if ((cVar16 == '\x06') && (cVar14 == '\a')) goto LAB_1400cece3;
    }
    uVar15 = FUN_140187c80((ulonglong)plVar22,'\0','\0');
    if ((uVar15 != '\0') &&
       (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10), lVar19 != 0)) {
      puVar28 = *(undefined8 **)(lVar19 + 0x2d8);
      if ((puVar28 == (undefined8 *)0x0) ||
         ((*(byte *)*puVar28 <= *(byte *)(lVar19 + 0x3c9) ||
          (puVar28 = (undefined8 *)(puVar28[1] + (ulonglong)*(byte *)(lVar19 + 0x3c9) * 0x48),
          puVar28 == (undefined8 *)0x0)))) {
        cVar14 = -1;
      }
      else {
        cVar14 = *(char *)*puVar28;
      }
      bVar34 = cVar14 == '\x04';
      if ((cVar14 != '\x05') && (cVar14 != '\x06')) {
        if (cVar14 == '\0') {
          puVar28 = *(undefined8 **)(lVar19 + 0x2d8);
          if ((((puVar28 == (undefined8 *)0x0) || (*(byte *)*puVar28 <= *(byte *)(lVar19 + 0x3c9)))
              || (puVar28 = (undefined8 *)(puVar28[1] + (ulonglong)*(byte *)(lVar19 + 0x3c9) * 0x48)
                 , puVar28 == (undefined8 *)0x0)) ||
             ((*(char *)*puVar28 != '\0' ||
              ((*(char *)(lVar19 + 0x3cc) != '\f' && (4 < (byte)(*(char *)(lVar19 + 0x3cc) - 0xdU)))
              )))) {
            lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
            puVar28 = *(undefined8 **)(lVar19 + 0x2d8);
            if ((puVar28 == (undefined8 *)0x0) ||
               ((*(byte *)*puVar28 <= *(byte *)(lVar19 + 0x3c9) ||
                (puVar28 = (undefined8 *)(puVar28[1] + (ulonglong)*(byte *)(lVar19 + 0x3c9) * 0x48),
                puVar28 == (undefined8 *)0x0)))) goto LAB_1400cee5f;
          }
          else {
            bVar34 = true;
            lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
            puVar28 = (undefined8 *)
                      (*(longlong *)(*(longlong *)(lVar19 + 0x2d8) + 8) +
                      (ulonglong)*(byte *)(lVar19 + 0x3c9) * 0x48);
          }
          if ((*(char *)*puVar28 == '\0') &&
             ((*(char *)(lVar19 + 0x3cc) == '\x14' ||
              ((byte)(*(char *)(lVar19 + 0x3cc) - 0x15U) < 5)))) goto LAB_1400cee64;
        }
LAB_1400cee5f:
        if (!bVar34) goto LAB_1400cee6c;
      }
LAB_1400cee64:
      FUN_1400c5c00(*(undefined8 *)(param_1 + 0xa8318));
    }
  }
LAB_1400cee6c:
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (((((lVar19 != 0) && (puVar28 = *(undefined8 **)(lVar19 + 0x2d8), puVar28 != (undefined8 *)0x0)
        ) && (*(byte *)(lVar19 + 0x3c9) < *(byte *)*puVar28)) &&
      ((puVar28 = (undefined8 *)(puVar28[1] + (ulonglong)*(byte *)(lVar19 + 0x3c9) * 0x48),
       puVar28 != (undefined8 *)0x0 && (*(char *)*puVar28 == '\0')))) &&
     (*(char *)(lVar19 + 0x3cc) == '\x06')) {
    *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) | 0x10000;
  }
  uVar25 = *(uint *)(param_1 + 0xa8790);
  uVar32 = uVar25 & 0xfffeffff;
  *(uint *)(param_1 + 0xa8790) = uVar32;
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
  if (lVar19 == 0) {
    cVar14 = -1;
    bVar18 = 0xff;
  }
  else {
    puVar28 = *(undefined8 **)(lVar19 + 0x2d8);
    if (((puVar28 == (undefined8 *)0x0) || (*(byte *)*puVar28 <= *(byte *)(lVar19 + 0x3c9))) ||
       (puVar28 = (undefined8 *)(puVar28[1] + (ulonglong)*(byte *)(lVar19 + 0x3c9) * 0x48),
       puVar28 == (undefined8 *)0x0)) {
      cVar14 = -1;
    }
    else {
      cVar14 = *(char *)*puVar28;
    }
    bVar18 = *(byte *)(lVar19 + 0x3cc);
  }
  local_res8[0] = bVar18;
  local_res10 = cVar14;
  if ((uVar25 & 3) == 0) {
    if (cVar14 != '\0') {
      if (cVar14 == '\x04') {
        if (bVar18 == 6) {
LAB_1400cf296:
          DAT_14032c933 = 0;
          DAT_14033dab0 = 0;
          uVar36 = FUN_1401c56d0();
          if ((DAT_14031f8b1 & 1) == 0) {
            FUN_140187190(uVar36,1);
          }
          if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
             (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
            FUN_1401c93c0();
            _Init_thread_footer(&DAT_1437daf04);
          }
          DAT_1437dece0 = DAT_1437dece0 | 2;
          if (DAT_14033b1b0 != 1) {
            DAT_14033b1b0 = 1;
            puVar28 = &DAT_1403569c0;
            pcVar26 = &DAT_14032dba1;
            do {
              if ((*pcVar26 != '\0') && (*pcVar26 != '\x02')) {
                FUN_140229640(*puVar28,1);
              }
              pcVar26 = pcVar26 + 0x90;
              puVar28 = puVar28 + 1;
            } while ((longlong)pcVar26 < 0x140336ba1);
          }
          if (*(longlong *)(param_1 + 0xa82a8) != 0) {
            puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa82a8) + 0x90c);
            *puVar1 = *puVar1 | 0x10;
          }
          plVar22 = *(longlong **)(param_1 + 0x67150);
          if (DAT_1437da3c2 == '\0') {
            (**(code **)(*plVar22 + 0x58))(plVar22,0);
            iVar27 = *(int *)((longlong)*(longlong **)(param_1 + 0x67150) + 0x54);
            if (iVar27 == 1) {
              DAT_1437da3c2 = '\x01';
            }
            else if (iVar27 == 4) {
              (**(code **)(**(longlong **)(param_1 + 0x67150) + 0x28))();
              *(undefined1 *)(param_1 + 0xa8822) = 6;
            }
          }
          else {
            (**(code **)(*plVar22 + 0x58))(plVar22,1);
            if (((((char)DAT_14032c8c0[0x10] == -1) ||
                 (bVar18 = *(byte *)((longlong)*(char *)(*DAT_14032c8c0 + 0x2e) * 0x1b + 0x16 +
                                    (longlong)DAT_14032c8c0),
                 (*(uint *)(*DAT_14032c8c0 + 0x38 + (ulonglong)(bVar18 >> 5) * 4) >> (bVar18 & 0x1f)
                 & 1) == 0)) && (cVar16 = FUN_140201fd0(0,7), cVar16 == '\0')) &&
               (cVar16 = FUN_140201fd0(0,0), cVar16 == '\0')) {
              iVar27 = 0;
              if (*(char *)(param_1 + 0xa87e4) != '\0') {
                do {
                  if ((longlong)iVar27 * 0x27a0 + *(longlong *)(param_1 + 0xa8248) != 0) {
                    FUN_1400c5160();
                  }
                  iVar27 = iVar27 + 1;
                } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
              }
              (**(code **)(**(longlong **)(param_1 + 0x67150) + 0x28))();
              FUN_1400cd880(param_1);
              DAT_1437da3c2 = '\0';
            }
          }
          iVar27 = 0;
          *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xfffffffb | 0x10000;
          if (*(char *)(param_1 + 0xa87e4) != '\0') {
            lVar19 = 0;
            do {
              iVar27 = iVar27 + 1;
              puVar1 = (ushort *)(lVar19 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
              *puVar1 = *puVar1 | 4;
              puVar1 = (ushort *)(lVar19 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
              *puVar1 = *puVar1 | 8;
              puVar1 = (ushort *)(lVar19 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
              *puVar1 = *puVar1 | 0x10;
              lVar19 = lVar19 + 0x27a0;
            } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
          }
          goto LAB_1400cff26;
        }
        DAT_14032c933 = 1;
        DAT_14033dab0 = 0;
      }
      else {
        if ((cVar14 == '\x06') && (bVar18 == 5)) goto LAB_1400cf296;
LAB_1400cf4a4:
        DAT_14032c933 = 1;
        DAT_14033dab0 = 0;
        if ((cVar14 == '\0') && (bVar18 == 0x12)) {
          (**(code **)(**(longlong **)(param_1 + 0x67160) + 0x28))();
        }
      }
      uVar36 = FUN_1401c56d0();
      if ((DAT_14031f8b1 & 1) == 0) {
        FUN_140187190(uVar36,0);
      }
      if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
         (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
        FUN_1401c93c0();
        _Init_thread_footer(&DAT_1437daf04);
      }
      DAT_1437dece0 = DAT_1437dece0 & 0xfd;
      if (DAT_14033b1b0 != 0) {
        DAT_14033b1b0 = 0;
        puVar28 = &DAT_1403569c0;
        pcVar26 = &DAT_14032dba1;
        do {
          if ((*pcVar26 != '\0') && (*pcVar26 != '\x02')) {
            FUN_140229640(*puVar28,0);
          }
          pcVar26 = pcVar26 + 0x90;
          puVar28 = puVar28 + 1;
        } while ((longlong)pcVar26 < 0x140336ba1);
      }
      if (*(longlong *)(param_1 + 0xa82a8) != 0) {
        puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa82a8) + 0x90c);
        *puVar1 = *puVar1 & 0xffef;
      }
      FUN_140080620((longlong)*(char *)(param_1 + 0xa8829) * 0xd10 +
                    *(longlong *)(param_1 + 0x67138));
      FUN_14007b080((longlong)*(char *)(param_1 + 0xa8829) * 0x1c8 +
                    *(longlong *)(param_1 + 0x67140));
      iVar27 = 0;
      bVar18 = 0;
      if (*(byte *)(param_1 + 0xa87e4) != 0) {
        lVar19 = 0;
        do {
          lVar33 = *(longlong *)(param_1 + 0xa8248);
          lVar19 = lVar19 + 0x27a0;
          iVar27 = iVar27 + 1;
          puVar3 = (uint *)(lVar33 + -0x748 + lVar19);
          *puVar3 = *puVar3 & 0xfffffffd;
          puVar1 = (ushort *)(lVar33 + -0xb80 + lVar19);
          *puVar1 = *puVar1 & 0xffbf;
          bVar18 = *(byte *)(param_1 + 0xa87e4);
        } while (iVar27 < (int)(uint)bVar18);
      }
      pbVar29 = (byte *)(param_1 + 0xa87e4);
      local_150 = pbVar29;
      if ((*(uint *)(param_1 + 0xa8790) & 0x10000000) == 0) {
        uVar25 = 0;
        if (bVar18 != 0) {
          do {
            lVar33 = (longlong)(int)uVar25 * 0x27a0;
            lVar19 = *(longlong *)(param_1 + 0xa8248) + lVar33;
            bVar34 = *(char *)(param_1 + 0xa87e1) != '\0';
            if (bVar34) {
              uVar17 = 2;
            }
            else {
              uVar17 = 0;
            }
            *(bool *)(lVar19 + 0x2097) = !bVar34;
            *(undefined1 *)(lVar19 + 0x1862) = uVar17;
            lVar19 = *(longlong *)(param_1 + 0xa8248);
            lVar8 = *(longlong *)
                     (*(longlong *)(*(longlong *)(param_1 + 0x697b8) + (longlong)(int)uVar25 * 8) +
                     0x110);
            uVar17 = *(undefined1 *)(lVar8 + 0x235);
            uVar30 = *(undefined1 *)(lVar8 + 0x234);
            *(undefined1 *)(lVar33 + 0x20a2 + lVar19) = uVar17;
            *(undefined1 *)(lVar33 + 0x20a1 + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1eeb + lVar19) = uVar17;
            *(undefined1 *)(lVar33 + 0x1eea + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1eca + lVar19) = uVar17;
            *(undefined1 *)(lVar33 + 0x1ec9 + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1e52 + lVar19) = uVar17;
            *(undefined1 *)(lVar33 + 0x1e51 + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1e71 + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1e72 + lVar19) = uVar17;
            *(undefined1 *)(lVar33 + 0x1e91 + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1e92 + lVar19) = uVar17;
            *(undefined1 *)(lVar33 + 0x1eb1 + lVar19) = uVar30;
            *(undefined1 *)(lVar33 + 0x1eb2 + lVar19) = uVar17;
            auVar9 = *(undefined1 (*) [16])(lVar8 + 600);
            auVar6 = *(undefined1 (*) [16])(lVar8 + 0x268);
            lVar19 = *(longlong *)(param_1 + 0xa8248);
            auVar10 = vshufps_avx(auVar6,auVar6,0x55);
            auVar11 = vshufps_avx(auVar6,auVar6,0xaa);
            auVar12 = vshufps_avx(auVar6,auVar6,0xff);
            uVar43 = auVar9._0_4_;
            *(undefined4 *)(lVar33 + 0x10e0 + lVar19) = uVar43;
            auVar13 = vshufps_avx(auVar9,auVar9,0x55);
            uVar42 = auVar13._0_4_;
            *(undefined4 *)(lVar33 + 0x10e4 + lVar19) = uVar42;
            auVar13 = vshufps_avx(auVar9,auVar9,0xaa);
            uVar41 = auVar13._0_4_;
            *(undefined4 *)(lVar33 + 0x10e8 + lVar19) = uVar41;
            auVar9 = vshufps_avx(auVar9,auVar9,0xff);
            uVar40 = auVar9._0_4_;
            *(undefined4 *)(lVar33 + 0x10ec + lVar19) = uVar40;
            uVar46 = auVar6._0_4_;
            *(undefined4 *)(lVar33 + 0x10f0 + lVar19) = uVar46;
            uVar39 = auVar10._0_4_;
            *(undefined4 *)(lVar33 + 0x10f4 + lVar19) = uVar39;
            uVar38 = auVar11._0_4_;
            *(undefined4 *)(lVar33 + 0x10f8 + lVar19) = uVar38;
            uVar35 = auVar12._0_4_;
            *(undefined4 *)(lVar33 + 0x10fc + lVar19) = uVar35;
            *(undefined8 *)(lVar33 + 0x12a0 + lVar19) = 0;
            *(undefined4 *)(lVar33 + 0x12a8 + lVar19) = 0;
            *(undefined4 *)(lVar33 + 0x12ac + lVar19) = 0x3f800000;
            *(undefined4 *)(lVar33 + 0x12b0 + lVar19) = uVar46;
            *(undefined4 *)(lVar33 + 0x12b4 + lVar19) = uVar39;
            *(undefined4 *)(lVar33 + 0x12b8 + lVar19) = uVar38;
            *(undefined4 *)(lVar33 + 0x12bc + lVar19) = uVar35;
            *(undefined4 *)(lVar33 + 0x70 + lVar19) = uVar43;
            *(undefined4 *)(lVar33 + 0x74 + lVar19) = uVar42;
            *(undefined4 *)(lVar33 + 0x78 + lVar19) = uVar41;
            *(undefined4 *)(lVar33 + 0x7c + lVar19) = uVar40;
            *(undefined4 *)(lVar33 + 0x80 + lVar19) = uVar46;
            *(undefined4 *)(lVar33 + 0x84 + lVar19) = uVar39;
            *(undefined4 *)(lVar33 + 0x88 + lVar19) = uVar38;
            *(undefined4 *)(lVar33 + 0x8c + lVar19) = uVar35;
            *(undefined4 *)(lVar33 + 0x17f8 + lVar19) = uVar43;
            *(undefined4 *)(lVar33 + 0x17fc + lVar19) = uVar42;
            *(undefined4 *)(lVar33 + 0x1800 + lVar19) = uVar41;
            *(undefined4 *)(lVar33 + 0x1804 + lVar19) = uVar40;
            *(undefined4 *)(lVar33 + 0x1808 + lVar19) = uVar46;
            *(undefined4 *)(lVar33 + 0x180c + lVar19) = uVar39;
            *(undefined4 *)(lVar33 + 0x1810 + lVar19) = uVar38;
            *(undefined4 *)(lVar33 + 0x1814 + lVar19) = uVar35;
            FUN_1401040c0(*(longlong *)(param_1 + 0xa8248) + lVar33,uVar25 & 0xff);
            uVar25 = uVar25 + 1;
          } while ((int)uVar25 < (int)(uint)*pbVar29);
        }
        local_150 = (byte *)(param_1 + 0xa87e4);
        if ((*(uint *)(param_1 + 0xa8790) & 0x10000000) == 0) {
          FUN_140141550(param_1 + 0x6a130);
        }
      }
      pbVar29 = (byte *)(param_1 + 0xa87e4);
      local_154 = 0;
      if (*pbVar29 != 0) {
        plVar22 = (longlong *)(param_1 + 0x697b8);
        lVar19 = 0;
        do {
          lVar33 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
          if (lVar33 != 0) {
            puVar28 = *(undefined8 **)(lVar33 + 0x2d8);
            if (((puVar28 != (undefined8 *)0x0) && (*(byte *)(lVar33 + 0x3c9) < *(byte *)*puVar28))
               && (puVar2 = (undefined8 *)(puVar28[1] + (ulonglong)*(byte *)(lVar33 + 0x3c9) * 0x48)
                  , puVar2 != (undefined8 *)0x0)) {
              cVar14 = *(char *)*puVar2;
              if (cVar14 == '\0') {
                if (*(char *)(lVar33 + 0x3cc) == '\x02') {
                  puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa8248) + 0x1c20 + lVar19);
                  *puVar1 = *puVar1 & 0xfffd;
                  puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa8248) + 0x1c20 + lVar19);
                  *puVar1 = *puVar1 & 0xfffb;
                  puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa8248) + 0x1c20 + lVar19);
                  *puVar1 = *puVar1 & 0xfff7;
                  puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa8248) + 0x1c20 + lVar19);
                  *puVar1 = *puVar1 & 0xffef;
                }
                lVar33 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
                puVar28 = *(undefined8 **)(lVar33 + 0x2d8);
                if (puVar28 == (undefined8 *)0x0) {
                  lVar33 = 0;
                }
                else {
                  bVar18 = *(byte *)(lVar33 + 0x3c9);
                  if (bVar18 < *(byte *)*puVar28) {
                    lVar33 = puVar28[1] + (ulonglong)bVar18 * 0x48;
                  }
                  else {
                    lVar33 = 0;
                  }
                }
                if (**(longlong **)(lVar33 + 8) != 0) {
                  local_res18 = *(undefined1 *)(**(longlong **)(lVar33 + 8) + 0x6b);
                }
                *(undefined1 *)(*(longlong *)(param_1 + 0xa8248) + 0x1c2e + lVar19) = local_res18;
              }
              else if (cVar14 != '\x04') {
                if (cVar14 == '\x06') {
                  uVar17 = 0xff;
                  uVar30 = 0xff;
                  if ((puVar28[1] != 0) && ((*(byte *)(lVar33 + 0x3a8) & 1) == 0)) {
                    lVar8 = **(longlong **)
                              (puVar28[1] + 0x20 + (ulonglong)*(byte *)(lVar33 + 0x3c9) * 0x48);
                    uVar17 = *(undefined1 *)(lVar8 + 0x20);
                    uVar30 = *(undefined1 *)(lVar8 + 0x21);
                  }
                  pauVar21 = (undefined1 (*) [16])FUN_140101a80(lVar33,local_118);
                  auVar44 = ZEXT1664(*pauVar21);
                  puVar28 = (undefined8 *)FUN_140101cc0(lVar33,local_108);
                  lVar8 = *(longlong *)(param_1 + 0xa8248);
                  uVar36 = *puVar28;
                  uVar37 = puVar28[1];
                  *(undefined4 *)(lVar8 + 0x1a08 + lVar19) = *(undefined4 *)(lVar33 + 0x388);
                  *(undefined1 *)(lVar8 + 0x1a0d + lVar19) = uVar30;
                  *(undefined1 (*) [16])(lVar8 + 0x19e8 + lVar19) = auVar44._0_16_;
                  puVar28 = (undefined8 *)(lVar8 + 0x19f8 + lVar19);
                  *puVar28 = uVar36;
                  puVar28[1] = uVar37;
                  *(undefined1 *)(lVar8 + 0x1a0c + lVar19) = uVar17;
                  *(undefined1 *)(lVar8 + 0x1a0e + lVar19) = local_122;
                  *(undefined1 *)(lVar8 + 0x1a0f + lVar19) = local_121;
                  *(undefined1 *)(lVar8 + 0x1a10 + lVar19) = local_120;
                  *(undefined1 *)(lVar8 + 0x1a11 + lVar19) = local_11f;
                  *(undefined1 *)(lVar8 + 0x1a12 + lVar19) = local_11e;
                  *(undefined1 *)(lVar8 + 0x1a13 + lVar19) = local_11d;
                  *(undefined1 *)(lVar8 + 0x1a14 + lVar19) = local_11c;
                  *(undefined1 *)(lVar8 + 0x1a15 + lVar19) = local_11b;
                  *(undefined1 *)(lVar8 + 0x1a16 + lVar19) = local_11a;
                  *(undefined1 *)(lVar8 + 0x1a17 + lVar19) = local_119;
                  pbVar29 = local_150;
                }
                goto LAB_1400cfb34;
              }
              FUN_1400d4080(param_1,&local_148);
              lVar33 = *(longlong *)(param_1 + 0xa8248);
              puVar28 = (undefined8 *)(lVar33 + 0x1980 + lVar19);
              *puVar28 = local_148;
              puVar28[1] = uStack_140;
              *(undefined8 *)(lVar33 + 0x1990 + lVar19) = local_138;
            }
LAB_1400cfb34:
            FUN_1400d3ec0(param_1,&local_f8);
            lVar33 = *(longlong *)(param_1 + 0xa8248);
            puVar28 = (undefined8 *)(lVar33 + 0x1998 + lVar19);
            *puVar28 = local_f8;
            puVar28[1] = uStack_f0;
            puVar28[2] = uStack_e8;
            puVar28[3] = uStack_e0;
            *(undefined1 (*) [32])(lVar33 + 0x19b8 + lVar19) = local_d8;
            puVar28 = (undefined8 *)(lVar33 + 0x19d8 + lVar19);
            *puVar28 = local_b8;
            puVar28[1] = uStack_b0;
          }
          lVar33 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
          bVar18 = 0;
          if (lVar33 != 0) {
            bVar18 = (byte)((uint)*(undefined4 *)(lVar33 + 0x3a8) >> 0x10) & 1;
          }
          if (plVar22 != (longlong *)0x0) {
            FUN_1400b8920(lVar19 + 0x1868 + *(longlong *)(param_1 + 0xa8248),plVar22,
                          param_1 + 0x6a130,*(undefined1 *)(lVar33 + 0x3e6),bVar18);
          }
          lVar33 = *(longlong *)(param_1 + 0xa8248) + 0x1868 + lVar19;
          if (*(char *)(*(longlong *)(param_1 + 0xa8248) + 0x1c2b + lVar19) == '\x01') {
            FUN_1400b9220(lVar33);
            uVar36 = *(undefined8 *)
                      (*(longlong *)(*plVar22 + (ulonglong)*(byte *)(lVar33 + 0x3ca) * 8) + 0x110);
            if (*(char *)(lVar33 + 0x3b2) == '\x0f') {
              uVar37 = FUN_1401c56d0();
              if (*(char *)(lVar33 + 0xfc) == '\x01') {
                cVar14 = '\0';
                if (*(longlong *)(lVar33 + 0x328) != 0) {
                  cVar14 = FUN_14009eea0(uVar37,uVar36);
                  uVar37 = extraout_XMM0_Qa;
                }
                if (*(char *)(lVar33 + 0x3bf) != cVar14) {
                  uVar36 = FUN_1401c6490(uVar37,lVar33 + 0x310);
                  local_res20[0] = 0xe;
                  if (cVar14 == '\0') {
                    local_res20[0] = 0xf;
                  }
                  local_158[0] = 1;
                  FUN_1401c5fe0(uVar36,local_158,local_res20,lVar33 + 0x310);
                  *(char *)(lVar33 + 0x3bf) = cVar14;
                }
              }
              else {
                FUN_1401c6490(uVar37,lVar33 + 0x310);
              }
            }
            cVar14 = FUN_1400b7690(lVar33,plVar22);
            if (cVar14 == '\0') {
              uVar36 = FUN_1401c56d0();
              FUN_1401c6490(uVar36,lVar33 + 0x31c);
            }
            else {
              uVar36 = FUN_1401c56d0();
              local_res20[0] = 0x11e;
              local_158[0] = 1;
              FUN_1401c5fe0(uVar36,local_158,local_res20,lVar33 + 0x31c);
            }
            pbVar29 = local_150;
          }
          lVar19 = lVar19 + 0x27a0;
          local_154 = local_154 + 1;
        } while (local_154 < (int)(uint)*pbVar29);
        cVar14 = local_res10;
      }
      lVar19 = FUN_140189320();
      if (*(char *)(lVar19 + 0x32) != '\0') {
        FUN_1400781c0(param_1 + 0x69598 + (longlong)*(char *)(param_1 + 0xa8829) * 0x18,
                      param_1 + 0x68f72,param_1 + 0x240);
      }
      FUN_140036fe0(*(undefined8 *)(param_1 + 0x67120));
      if ((*(uint *)(param_1 + 0xa8790) & 0x10000000) == 0) {
        FUN_1401363c0(param_1 + 0x697b8,0);
      }
      lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
      if ((lVar19 != 0) && ((*(uint *)(lVar19 + 0x3a8) & 0x8000) != 0)) {
        FUN_1400a9c40(param_1 + 0x69748);
      }
      if (*(longlong *)(param_1 + 0xa8320) != 0) {
        FUN_14008fe80();
      }
      if (cVar14 == '\0') {
        if (local_res8[0] < 8) {
LAB_1400cfdde:
          FUN_1401b7ce0(param_1);
        }
      }
      else if ((cVar14 - 4U & 0xfd) == 0) goto LAB_1400cfdde;
      lVar19 = *(longlong *)(param_1 + 0xa82a8);
      if ((lVar19 != 0) && (plVar22 = *(longlong **)(param_1 + 0xa82b0), plVar22 != (longlong *)0x0)
         ) {
        if (plVar22[2] != 0) {
          FUN_1401a3ce0(plVar22[2],lVar19,param_1 + 0x697b8);
        }
        if (plVar22[3] != 0) {
          FUN_1401a45c0(plVar22[3],param_1 + 0x697b8,lVar19);
        }
        if (plVar22[1] != 0) {
          uVar25 = (uint)*(ushort *)(lVar19 + 0x132);
          iVar27 = 0;
          if (0 < (short)*(ushort *)(lVar19 + 0x132)) {
            do {
              if (((*(longlong *)(lVar19 + 0x120) == 0) || (sVar24 = (short)iVar27, sVar24 < 0)) ||
                 ((short)uVar25 <= sVar24)) {
                plVar23 = (longlong *)0x0;
              }
              else {
                plVar23 = *(longlong **)(*(longlong *)(lVar19 + 0x120) + (longlong)sVar24 * 8);
              }
              if ((plVar23[2] != 0) && (*(char *)(plVar23[2] + 1) == '\x01')) {
                (**(code **)(*plVar23 + 0x10))();
              }
              uVar25 = (uint)*(short *)(lVar19 + 0x132);
              iVar27 = iVar27 + 1;
            } while (iVar27 < (int)uVar25);
          }
        }
        puVar28 = (undefined8 *)(param_1 + 0x697b8);
        if (*plVar22 != 0) {
          FUN_1401a4280(*plVar22,plVar22,lVar19,puVar28,param_1 + 0x69748);
        }
        FUN_1401a8ec0(plVar22,param_1 + 0x69748,puVar28,lVar19);
        FUN_1401a6f30(*(undefined8 *)(param_1 + 0xa82a8),
                      *(undefined8 *)(*(longlong *)*puVar28 + 0x110),param_1 + 0x69748,
                      *(undefined8 *)(param_1 + 0xa8318));
        cVar14 = local_res10;
      }
      *(int *)(param_1 + 0xa878c) = *(int *)(param_1 + 0xa878c) + 1;
      goto LAB_1400cff26;
    }
    if (bVar18 == 6) goto LAB_1400cf296;
    if (bVar18 == 7) {
      DAT_14032c933 = 0;
      DAT_14033dab0 = 0;
      uVar36 = FUN_1401c56d0();
      local_res8[0] = 1;
      FUN_1401c68d0(uVar36,local_res8);
      if (*(longlong *)(param_1 + 0xa82a8) != 0) {
        puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa82a8) + 0x90c);
        *puVar1 = *puVar1 | 0x10;
      }
      plVar22 = *(longlong **)(param_1 + 0x67168);
      if (DAT_1437da3c0 == '\0') {
        (**(code **)(*plVar22 + 0x58))(plVar22,0);
        iVar27 = *(int *)(*(longlong *)(param_1 + 0x67168) + 0x54);
        if (iVar27 == 1) {
          DAT_1437da3c0 = '\x01';
        }
        else if (iVar27 == 4) {
          FUN_14018d2d0(&PTR_PTR_14031ce40,param_1);
          (**(code **)(**(longlong **)(param_1 + 0x67168) + 0x28))();
          *(undefined1 *)(param_1 + 0xa8822) = 4;
        }
      }
      else {
        (**(code **)(*plVar22 + 0x58))(plVar22,1);
        cVar16 = FUN_140201fd0(0,6);
        if ((cVar16 == '\0') && (cVar16 = FUN_140201fd0(0,7), cVar16 == '\0')) {
          cVar16 = FUN_140201fd0(0,0);
          if (cVar16 == '\0') {
            cVar16 = FUN_140201fd0(1,6);
            if (((cVar16 == '\0') && (cVar16 = FUN_140201fd0(1,7), cVar16 == '\0')) &&
               (cVar16 = FUN_140201fd0(1,0), cVar16 == '\0')) {
              FUN_14018d2d0(&PTR_PTR_14031ce40,param_1);
              (**(code **)(**(longlong **)(param_1 + 0x67168) + 0x28))();
              FUN_1400cd880(param_1);
              DAT_1437da3c0 = '\0';
            }
          }
        }
      }
      iVar27 = 0;
      *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xfffffffb | 0x10000;
      if (*(char *)(param_1 + 0xa87e4) != '\0') {
        lVar19 = 0;
        do {
          iVar27 = iVar27 + 1;
          puVar1 = (ushort *)(lVar19 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
          *puVar1 = *puVar1 | 4;
          puVar1 = (ushort *)(lVar19 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
          *puVar1 = *puVar1 | 8;
          puVar1 = (ushort *)(lVar19 + 0x1c20 + *(longlong *)(param_1 + 0xa8248));
          *puVar1 = *puVar1 | 0x10;
          lVar19 = lVar19 + 0x27a0;
        } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      }
    }
    else {
      if (bVar18 != 0x13) goto LAB_1400cf4a4;
      DAT_14032c933 = 0;
      DAT_14033dab0 = 0;
      FUN_1400d4c40(param_1);
    }
  }
  else {
    DAT_14033dab0 = ~uVar32 & 1;
    DAT_14032c933 = 0;
    lVar19 = **(longlong **)(unaff_GS_OFFSET + 0x58);
    if ((*(int *)(lVar19 + 4) < DAT_1437dad18) &&
       (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
      _DAT_1437daef0 = 0;
      _DAT_1437daee0 = _DAT_1402d3500;
      uRam00000001437daee8 = _UNK_1402d3508;
      DAT_1437daef4 = 0;
      _Init_thread_footer(&DAT_1437dad18);
    }
    if ((DAT_14031f8b1 & 1) == 0) {
      FUN_140187190();
    }
    if ((*(int *)(lVar19 + 4) < DAT_1437daf04) &&
       (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
      FUN_1401c93c0();
      _Init_thread_footer(&DAT_1437daf04);
    }
    DAT_1437dece0 = DAT_1437dece0 | 2;
    if (DAT_14033b1b0 != 1) {
      DAT_14033b1b0 = 1;
      puVar28 = &DAT_1403569c0;
      pcVar26 = &DAT_14032dba1;
      do {
        if ((*pcVar26 != '\0') && (*pcVar26 != '\x02')) {
          FUN_140229640(*puVar28,1);
        }
        pcVar26 = pcVar26 + 0x90;
        puVar28 = puVar28 + 1;
      } while ((longlong)pcVar26 < 0x140336ba1);
    }
    if (*(longlong *)(param_1 + 0xa82a8) != 0) {
      puVar1 = (ushort *)(*(longlong *)(param_1 + 0xa82a8) + 0x90c);
      *puVar1 = *puVar1 | 0x10;
    }
    uVar25 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      do {
        lVar33 = (longlong)(int)uVar25 * 0x27a0;
        lVar19 = *(longlong *)(param_1 + 0xa8248);
        puVar3 = (uint *)(lVar33 + 0x2058 + lVar19);
        *puVar3 = *puVar3 | 2;
        puVar1 = (ushort *)(lVar33 + 0x1c20 + lVar19);
        *puVar1 = *puVar1 | 0x40;
        FUN_1401040c0(lVar33 + *(longlong *)(param_1 + 0xa8248),uVar25 & 0xff,param_1 + 0x6a130);
        uVar25 = uVar25 + 1;
      } while ((int)uVar25 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
    }
    if ((*(byte *)(param_1 + 0xa8790) & 1) == 0) {
      if ((*(uint *)(param_1 + 0xa8790) >> 1 & 1) != 0) {
        FUN_1400d4940(param_1,1);
      }
    }
    else {
      FUN_1400d4940(param_1,0);
    }
LAB_1400cff26:
    bVar18 = local_res8[0];
  }
  iVar27 = 0;
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    lVar19 = 0;
    do {
      lVar19 = lVar19 + 0x27a0;
      iVar27 = iVar27 + 1;
      puVar3 = (uint *)(*(longlong *)(param_1 + 0xa8248) + -0x748 + lVar19);
      *puVar3 = *puVar3 & 0xffffffef;
    } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  if ((cVar14 == '\0') || (cVar14 == '\x04')) {
    if (bVar18 != 6) goto LAB_1400cfff9;
  }
  else if ((cVar14 != '\x06') || (bVar18 != 5)) {
LAB_1400cfff9:
    FUN_140141950(*(undefined8 *)(param_1 + 0xa8298),0);
    goto LAB_1400d0007;
  }
  lVar19 = *(longlong *)(param_1 + 0xa8298);
  *(undefined4 *)(lVar19 + 8) = *(undefined4 *)(lVar19 + 0x260);
  auVar9 = *(undefined1 (*) [16])(lVar19 + 0x1c0);
  *(int *)(lVar19 + 0x30) = auVar9._0_4_;
  uVar35 = vextractps_avx(auVar9,1);
  *(undefined4 *)(lVar19 + 0x34) = uVar35;
  uVar35 = vextractps_avx(auVar9,2);
  *(undefined4 *)(lVar19 + 0x38) = uVar35;
  uVar35 = vextractps_avx(auVar9,3);
  *(undefined4 *)(lVar19 + 0x3c) = uVar35;
  auVar9 = *(undefined1 (*) [16])(lVar19 + 0x1d0);
  *(int *)(lVar19 + 0x40) = auVar9._0_4_;
  uVar35 = vextractps_avx(auVar9,1);
  *(undefined4 *)(lVar19 + 0x44) = uVar35;
  uVar35 = vextractps_avx(auVar9,2);
  *(undefined4 *)(lVar19 + 0x48) = uVar35;
  uVar35 = vextractps_avx(auVar9,3);
  *(undefined4 *)(lVar19 + 0x4c) = uVar35;
  FUN_1401fbec0();
LAB_1400d0007:
  if ((*(byte *)(param_1 + 0xa8790) & 0x20) == 0) {
    lVar19 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if ((*(byte *)(lVar19 + 0x3a8) & 8) == 0) {
      if ((*(byte *)(*(longlong *)(param_1 + 0xa8298) + 0x2a6) & 0x42) == 2) {
        iVar27 = 0;
        if (*(char *)(param_1 + 0xa87e4) != '\0') {
          lVar19 = 0;
          do {
            lVar19 = lVar19 + 0x27a0;
            iVar27 = iVar27 + 1;
            puVar3 = (uint *)(*(longlong *)(param_1 + 0xa8248) + -0x748 + lVar19);
            *puVar3 = *puVar3 | 0x10;
          } while (iVar27 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
        }
        uVar36 = *(undefined8 *)(param_1 + 0xa8298);
        if (*(int *)(param_1 + 0x67230) < 4) {
          *(undefined8 *)(param_1 + 0x671f0 + (longlong)*(int *)(param_1 + 0x67230) * 8) = uVar36;
          *(undefined8 *)(param_1 + 0x67210 + (longlong)*(int *)(param_1 + 0x67230) * 8) = uVar36;
          *(undefined4 *)(param_1 + 0x67234 + (longlong)*(int *)(param_1 + 0x67230) * 4) = 0;
          *(int *)(param_1 + 0x67230) = *(int *)(param_1 + 0x67230) + 1;
        }
      }
      else if ((*(char *)(param_1 + 0xa8794) != '\x1f') && (*(char *)(param_1 + 0xa87e4) != '\0')) {
        do {
          lVar33 = *(longlong *)(param_1 + 0xa8248);
          lVar19 = (longlong)iVar31 * 0x27a0 + 0x10b0 + lVar33;
          FUN_1401fbec0(lVar19);
          lVar33 = (longlong)iVar31 * 0x27a0 + 0x1270 + lVar33;
          FUN_1401fbec0(lVar33);
          if (*(int *)(param_1 + 0x67230) < 4) {
            *(longlong *)(param_1 + 0x671f0 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar19;
            *(longlong *)(param_1 + 0x67210 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar33;
            *(int *)(param_1 + 0x67234 + (longlong)*(int *)(param_1 + 0x67230) * 4) = iVar31;
            *(int *)(param_1 + 0x67230) = *(int *)(param_1 + 0x67230) + 1;
          }
          iVar31 = iVar31 + 1;
        } while (iVar31 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      }
    }
    else if (*(char *)(param_1 + 0xa87e4) != '\0') {
      lVar19 = lVar19 + 0xe0;
      lVar33 = 0;
      do {
        puVar3 = (uint *)(*(longlong *)(param_1 + 0xa8248) + 0x2058 + lVar33);
        *puVar3 = *puVar3 | 0x10;
        if (*(int *)(param_1 + 0x67230) < 4) {
          *(longlong *)(param_1 + 0x671f0 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar19;
          *(longlong *)(param_1 + 0x67210 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar19;
          *(int *)(param_1 + 0x67234 + (longlong)*(int *)(param_1 + 0x67230) * 4) = iVar31;
          *(int *)(param_1 + 0x67230) = *(int *)(param_1 + 0x67230) + 1;
        }
        iVar31 = iVar31 + 1;
        lVar33 = lVar33 + 0x27a0;
      } while (iVar31 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
    }
  }
  else if (*(char *)(param_1 + 0xa87e4) != '\0') {
    lVar19 = 0;
    lVar33 = 0;
    do {
      puVar3 = (uint *)(*(longlong *)(param_1 + 0xa8248) + 0x2058 + lVar33);
      *puVar3 = *puVar3 | 0x10;
      lVar8 = *(longlong *)(param_1 + 0xa8218) + 0x20 + lVar19;
      FUN_1401fbec0(lVar8);
      lVar4 = *(longlong *)(param_1 + 0xa8218) + 0x1e0 + lVar19;
      FUN_1401fbec0(lVar4);
      if (*(int *)(param_1 + 0x67230) < 4) {
        *(longlong *)(param_1 + 0x671f0 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar8;
        *(longlong *)(param_1 + 0x67210 + (longlong)*(int *)(param_1 + 0x67230) * 8) = lVar4;
        *(int *)(param_1 + 0x67234 + (longlong)*(int *)(param_1 + 0x67230) * 4) = iVar31;
        *(int *)(param_1 + 0x67230) = *(int *)(param_1 + 0x67230) + 1;
      }
      iVar31 = iVar31 + 1;
      lVar33 = lVar33 + 0x27a0;
      lVar19 = lVar19 + 0x3a0;
    } while (iVar31 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  if ((*(longlong *)(param_1 + 0xa8310) != 0) && ((*(byte *)(param_1 + 0x69825) & 2) != 0)) {
    *(undefined4 *)(*(longlong *)(param_1 + 0xa8310) + 0x28) = 1;
  }
  return;
}

