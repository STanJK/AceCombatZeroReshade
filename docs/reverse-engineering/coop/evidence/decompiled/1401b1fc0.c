/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b1fc0; RVA 0x1b1fc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401b1fc0(float *param_1)

{
  undefined1 auVar1 [16];
  short sVar2;
  undefined1 auVar3 [16];
  byte bVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  longlong lVar12;
  bool bVar13;
  float fVar14;
  undefined8 uVar15;
  undefined1 auVar16 [64];
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float local_d8;
  float local_d4;
  undefined1 local_c8 [8];
  float fStack_c0;
  float fStack_bc;
  undefined1 local_a0 [136];
  
  if (((uint)param_1[0x19f] & 1) != 0) {
    param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffe);
  }
  iVar7 = DAT_14033bdac - DAT_14033bd74;
  iVar10 = DAT_14033bda8 - DAT_14033bd74;
  lVar12 = *(longlong *)
            (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
            0x110);
  local_a0._0_32_ = ZEXT832(0);
  FUN_1401b71e0(*(longlong *)(DAT_14033d9d8 + 0x697b8),local_a0,lVar12);
  if (((float)local_a0._8_4_ < DAT_1402d2b08) || (DAT_1402d2b10 <= (float)local_a0._8_4_)) {
LAB_1401b211a:
    auVar16 = ZEXT864(0);
    fVar20 = 0.0;
    fVar19 = 0.0;
    fVar18 = 0.0;
    fVar17 = 0.0;
    bVar13 = false;
    uVar9 = 0;
    if (iVar7 < 0x79) {
      if (*(char *)((longlong)param_1 + 0x6ea) != '\f') {
        _local_c8 = ZEXT432(0);
        bVar13 = true;
        auVar16 = ZEXT1664(auVar16._0_16_);
        FUN_1401b71e0();
        fVar19 = fStack_bc;
        fVar20 = (float)local_c8._4_4_;
        fVar17 = fStack_c0;
        fVar18 = (float)local_c8._0_4_;
        if ((fStack_c0 < DAT_14030cb80) || (DAT_14030cb84 < fStack_c0)) {
          FUN_140189320();
          iVar7 = FUN_140242630();
          *(char *)((longlong)param_1 + 0x6eb) = (char)iVar7 + (char)(iVar7 / 3) * -3;
        }
        else {
          FUN_140189320();
          uVar9 = FUN_140242630();
          uVar9 = uVar9 & 0x80000001;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
          }
          *(char *)((longlong)param_1 + 0x6eb) = (char)uVar9;
        }
      }
      *(undefined1 *)((longlong)param_1 + 0x6ea) = 0xc;
      if (*(char *)((longlong)param_1 + 0x6eb) == '\x01') {
        uVar9 = 0x13;
      }
      else if (*(char *)((longlong)param_1 + 0x6eb) == '\x02') {
        uVar9 = 0xe;
      }
      else {
        uVar9 = 0x14;
      }
    }
    else {
      uVar8 = 1;
      if (iVar10 + 0xb4U < 0x12d) {
        bVar13 = *(char *)((longlong)param_1 + 0x6ea) != '\v';
        if (bVar13) {
          bVar4 = FUN_140242630();
          *(byte *)((longlong)param_1 + 0x6eb) = bVar4 & 1;
          _local_c8 = ZEXT832(0);
          auVar16 = ZEXT1664(auVar16._0_16_);
          FUN_1401b71e0();
          fVar19 = fStack_bc;
          fVar20 = (float)local_c8._4_4_;
          fVar17 = fStack_c0;
          fVar18 = (float)local_c8._0_4_;
        }
        *(undefined1 *)((longlong)param_1 + 0x6ea) = 0xb;
        if ((*(byte *)((longlong)param_1 + 0x6eb) & 1) == 0) {
          uVar9 = 9;
        }
        else {
          uVar9 = 1;
          if (*(char *)(param_1 + 0x1bb) != '\b') {
            uVar9 = 8;
          }
        }
      }
      else {
        pfVar11 = (float *)&DAT_14030caf0;
        do {
          sVar2 = *(short *)((longlong)pfVar11 + 0xe);
          if (((sVar2 != 0) && (*pfVar11 < *(float *)(lVar12 + 0x260))) &&
             (*(float *)(lVar12 + 0x260) <= pfVar11[1])) {
            if (sVar2 == 1) {
              uVar9 = (uint)*(ushort *)(pfVar11 + 2);
              if ((ushort)*(byte *)(param_1 + 0x1bb) == *(ushort *)(pfVar11 + 2)) {
LAB_1401b2331:
                uVar9 = (uint)*(ushort *)((longlong)pfVar11 + 10);
              }
            }
            else if (sVar2 == 2) {
              if (*(byte *)((longlong)param_1 + 0x6ea) != uVar8) {
                bVar4 = FUN_140242630();
                *(byte *)((longlong)param_1 + 0x6eb) = bVar4 & 1;
              }
              if ((*(byte *)((longlong)param_1 + 0x6eb) & 1) == 0) goto LAB_1401b2331;
              uVar9 = (uint)*(ushort *)(pfVar11 + 2);
            }
            *(char *)((longlong)param_1 + 0x6ea) = (char)uVar8;
            break;
          }
          uVar8 = uVar8 + 1;
          pfVar11 = pfVar11 + 4;
        } while ((int)uVar8 < 0xc);
      }
    }
  }
  else {
    fVar14 = *(float *)(lVar12 + 0x260);
    auVar16 = ZEXT864(0);
    bVar13 = false;
    fVar18 = 0.0;
    fVar20 = 0.0;
    fVar17 = 0.0;
    fVar19 = 0.0;
    if ((fVar14 < DAT_1402d2b08) || ((DAT_1402d2b10 <= fVar14 || (0 < iVar10)))) goto LAB_1401b211a;
    uVar9 = (fVar14 < DAT_1402d2b0c) + 0xc;
  }
  lVar5 = (longlong)(int)uVar9;
  switch(*(undefined4 *)(&DAT_14031dbc0 + lVar5 * 0x30)) {
  case 1:
    FUN_1401b2820(param_1,uVar9,lVar12);
    break;
  case 2:
    param_1[4] = *(float *)(&DAT_14031dba0 + lVar5 * 0x30);
    param_1[5] = *(float *)(&DAT_14031dba4 + lVar5 * 0x30);
    param_1[6] = *(float *)(&DAT_14031dba8 + lVar5 * 0x30);
    param_1[7] = *(float *)(&DAT_14031dbac + lVar5 * 0x30);
    *param_1 = *(float *)(lVar12 + 600);
    param_1[1] = *(float *)(lVar12 + 0x25c);
    param_1[2] = *(float *)(lVar12 + 0x260);
    param_1[3] = *(float *)(lVar12 + 0x264);
    uVar15 = FUN_1401aa420(param_1,*(undefined4 *)(&DAT_14031dbc8 + lVar5 * 0x30),
                           *(undefined4 *)(&DAT_14031dbcc + lVar5 * 0x30));
    pfVar11 = (float *)FUN_1401aa540(uVar15,&local_d8);
    *param_1 = *param_1 + *pfVar11;
    param_1[1] = pfVar11[1] + param_1[1];
    param_1[2] = pfVar11[2] + param_1[2];
    param_1[3] = pfVar11[3] + param_1[3];
    FUN_1401b4060(param_1);
    fVar14 = (float)FUN_140275cc0(*(float *)(&DAT_14031dbc4 + lVar5 * 0x30) * DAT_1402d1eec);
    fVar14 = DAT_1402d28b8 / fVar14;
    param_1[0x10c] = fVar14;
    if ((*(byte *)(*(longlong *)(param_1 + 0x1ae) + 0xa8790) & 0x10) != 0) {
      param_1[0x10c] = fVar14 * DAT_1402d2258;
    }
    auVar1 = *(undefined1 (*) [16])(param_1 + 4);
    fVar14 = auVar1._0_4_ - *(float *)(lVar12 + 600);
    auVar3 = vshufps_avx(auVar1,auVar1,0xaa);
    fVar19 = auVar3._0_4_ - *(float *)(lVar12 + 0x260);
    auVar3 = vshufps_avx(auVar1,auVar1,0x55);
    fVar20 = auVar3._0_4_ - *(float *)(lVar12 + 0x25c);
    auVar1 = vshufps_avx(auVar1,auVar1,0xff);
    fVar17 = auVar1._0_4_ - *(float *)(lVar12 + 0x264);
    if (*(float *)(&DAT_14031dbbc + lVar5 * 0x30) <
        SQRT(fVar17 * fVar17 + fVar19 * fVar19 + fVar20 * fVar20 + fVar14 * fVar14)) break;
    goto LAB_1401b26f6;
  case 3:
    FUN_1401b2ab0(param_1,uVar9);
    break;
  case 4:
    lVar12 = (ulonglong)uVar9 * 0x30;
    if (bVar13) {
      fVar14 = *(float *)(&DAT_14031dba8 + lVar12);
      fVar20 = *(float *)(&DAT_14031dbac + lVar12);
      param_1[4] = fVar18 + *(float *)(&DAT_14031dba0 + lVar12);
      param_1[6] = fVar17 + fVar14;
      param_1[7] = fVar19 + fVar20;
      param_1[5] = 1847.0;
    }
    param_1[8] = *(float *)(&DAT_14031dbb0 + lVar12);
    param_1[9] = *(float *)(&DAT_14031dbb4 + lVar12);
    param_1[10] = *(float *)(&DAT_14031dbb8 + lVar12);
    param_1[0xb] = 0.0;
    uVar15 = FUN_1401aa420(param_1,*(undefined4 *)(&DAT_14031dbc8 + lVar12),
                           *(undefined4 *)(&DAT_14031dbcc + lVar12));
    FUN_1401aa540(uVar15,&local_d8);
    param_1[8] = local_d8 + param_1[8];
    param_1[9] = local_d4 + param_1[9];
    fVar14 = *(float *)(&DAT_14031dbc4 + lVar12) * DAT_1402d1eec;
    goto LAB_1401b2750;
  case 5:
    uVar6 = (ulonglong)uVar9;
    if (bVar13) {
      param_1[4] = fVar18 - *(float *)(&DAT_14031dba0 + uVar6 * 0x30);
      bVar13 = fVar20 + *(float *)(&DAT_14031dba4 + uVar6 * 0x30) < DAT_1402d29f8;
      param_1[5] = fVar20 + *(float *)(&DAT_14031dba4 + uVar6 * 0x30);
      param_1[6] = fVar17 - *(float *)(&DAT_14031dba8 + uVar6 * 0x30);
      if (bVar13) {
        param_1[5] = 1844.0;
      }
    }
    *param_1 = *(float *)(lVar12 + 600);
    param_1[1] = *(float *)(lVar12 + 0x25c);
    param_1[2] = *(float *)(lVar12 + 0x260);
    param_1[3] = *(float *)(lVar12 + 0x264);
    uVar15 = FUN_1401aa420(param_1,*(undefined4 *)(&DAT_14031dbc8 + uVar6 * 0x30),
                           *(undefined4 *)(&DAT_14031dbcc + uVar6 * 0x30));
    pfVar11 = (float *)FUN_1401aa540(uVar15,&local_d8);
    *param_1 = *pfVar11 + *param_1;
    param_1[1] = pfVar11[1] + param_1[1];
    param_1[2] = pfVar11[2] + param_1[2];
    param_1[3] = pfVar11[3] + param_1[3];
    FUN_1401b4060(param_1);
    fVar14 = (float)FUN_140275cc0(*(float *)(&DAT_14031dbc4 + uVar6 * 0x30) * DAT_1402d1eec);
    fVar14 = DAT_1402d28b8 / fVar14;
    param_1[0x10c] = fVar14;
    if ((*(byte *)(*(longlong *)(param_1 + 0x1ae) + 0xa8790) & 0x10) != 0) {
      param_1[0x10c] = fVar14 * DAT_1402d2258;
    }
    if (*(float *)(&DAT_14031dbbc + uVar6 * 0x30) == auVar16._0_4_) break;
    auVar1 = *(undefined1 (*) [16])(param_1 + 4);
    fVar14 = auVar1._0_4_ - *(float *)(lVar12 + 600);
    auVar3 = vshufps_avx(auVar1,auVar1,0xaa);
    fVar19 = auVar3._0_4_ - *(float *)(lVar12 + 0x260);
    auVar3 = vshufps_avx(auVar1,auVar1,0x55);
    fVar20 = auVar3._0_4_ - *(float *)(lVar12 + 0x25c);
    auVar1 = vshufps_avx(auVar1,auVar1,0xff);
    fVar17 = auVar1._0_4_ - *(float *)(lVar12 + 0x264);
    if (*(float *)(&DAT_14031dbbc + uVar6 * 0x30) <
        SQRT(fVar17 * fVar17 + fVar19 * fVar19 + fVar20 * fVar20 + fVar14 * fVar14)) break;
LAB_1401b26f6:
    *(char *)(param_1 + 0x1bb) = (char)uVar9;
    break;
  case 6:
    param_1[4] = *(float *)(&DAT_14031dba0 + lVar5 * 0x30);
    param_1[5] = *(float *)(&DAT_14031dba4 + lVar5 * 0x30);
    param_1[6] = *(float *)(&DAT_14031dba8 + lVar5 * 0x30);
    fVar14 = *(float *)(&DAT_14031dbac + lVar5 * 0x30);
    param_1[4] = (float)local_a0._0_4_;
    param_1[7] = fVar14;
    param_1[8] = *(float *)(&DAT_14031dbb0 + lVar5 * 0x30);
    param_1[9] = *(float *)(&DAT_14031dbb4 + lVar5 * 0x30);
    param_1[10] = *(float *)(&DAT_14031dbb8 + lVar5 * 0x30);
    param_1[0xb] = 0.0;
    fVar14 = *(float *)(&DAT_14031dbc4 + lVar5 * 0x30) * DAT_1402d1eec;
LAB_1401b2750:
    fVar14 = (float)FUN_140275cc0(fVar14);
    fVar14 = DAT_1402d28b8 / fVar14;
    param_1[0x10c] = fVar14;
    if ((*(byte *)(*(longlong *)(param_1 + 0x1ae) + 0xa8790) & 0x10) != 0) {
      param_1[0x10c] = fVar14 * DAT_1402d2258;
    }
  }
  *(short *)(param_1 + 0x1ba) = *(short *)(param_1 + 0x1ba) + 1;
  FUN_1401b5120(param_1,param_1 + 4,param_1 + 8);
  iVar7 = FUN_1401b1f20();
  return iVar7 == 0;
}

