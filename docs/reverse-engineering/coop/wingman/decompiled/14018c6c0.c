/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14018c6c0; RVA 0x18c6c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14018c6c0(longlong param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined8 *puVar15;
  char cVar16;
  int iVar17;
  undefined4 uVar18;
  undefined1 (*pauVar19) [16];
  undefined **ppuVar20;
  undefined *puVar21;
  undefined4 *puVar22;
  int *piVar23;
  uint *puVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  undefined1 *puVar28;
  ulonglong uVar29;
  uint uVar30;
  undefined **ppuVar31;
  byte bVar32;
  char cVar33;
  longlong lVar34;
  longlong lVar35;
  undefined *puVar36;
  int iVar37;
  longlong lVar38;
  undefined *puVar39;
  uint *puVar40;
  longlong lVar41;
  longlong lVar42;
  bool bVar43;
  undefined4 local_58;
  int iStack_54;
  
  cVar16 = DAT_14031cf18;
  uVar30 = 2;
  iVar17 = DAT_14031cde4;
  uVar25 = DAT_14031cde0;
  iVar9 = (int)DAT_14031cdd8;
  iVar10 = (int)DAT_14031cdec;
  if (DAT_14031cf18 == '\0') {
    iVar17 = DAT_140316e2c;
    uVar25 = DAT_140316e28;
    iVar9 = (int)DAT_140316e20;
    iVar10 = (int)DAT_140316e34;
  }
  uVar29 = 0;
  if (iVar17 == 0) {
    if (*(int *)(param_1 + 0x80) < 0x29) {
      uVar25 = (uint)(-0x29 < *(int *)(param_1 + 0x80));
    }
    else {
      uVar25 = 2;
    }
  }
  uVar27 = 0;
  if (iVar9 != 0x12) {
    uVar27 = uVar25;
  }
  if (DAT_14031cf18 != '\0') {
    uVar18 = DAT_1403170d8;
    uVar11 = DAT_1403170d0;
    iVar17 = DAT_1403170c8;
    uVar12 = DAT_1403170d4;
    uVar13 = DAT_1403170cc;
    iVar14 = DAT_1403170c4;
  }
  else {
    uVar18 = DAT_140311120;
    uVar11 = DAT_140311118;
    iVar17 = DAT_140311110;
    uVar12 = DAT_14031111c;
    uVar13 = DAT_140311114;
    iVar14 = DAT_14031110c;
  }
  pauVar19 = (undefined1 (*) [16])&DAT_14031cdec;
  if (DAT_14031cf18 == '\0') {
    pauVar19 = (undefined1 (*) [16])&DAT_140316e34;
  }
  auVar2 = *pauVar19;
  uVar1 = *(undefined8 *)pauVar19[1];
  uVar25 = *(uint *)((longlong)pauVar19[1] + 8);
  uVar26 = *(uint *)(param_1 + 200) & 0x400;
  if (uVar26 != 0) {
    DAT_14031cf18 = '\0';
  }
  lVar41 = (longlong)iVar9;
  puVar39 = &DAT_140316e78;
  cVar33 = '\0';
  if (uVar26 == 0) {
    cVar33 = cVar16;
  }
  ppuVar31 = &PTR_PTR_140317918;
  lVar34 = (longlong)(int)uVar27;
  if (cVar33 == '\0') {
    puVar39 = &DAT_140310ec0;
    ppuVar31 = (undefined **)&DAT_140311960;
  }
  lVar38 = (longlong)iVar10 * 0x13 + lVar41;
  lVar35 = lVar34 + (lVar38 + 0x22) * 3;
  if (*(int *)(param_1 + 0x98) < *(int *)((longlong)ppuVar31 + lVar35 * 4)) {
    *(int *)((longlong)ppuVar31 + lVar35 * 4) = *(int *)(param_1 + 0x98);
  }
  lVar35 = lVar34 + lVar38 * 3;
  iVar37 = 0;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 8 + (longlong)ppuVar31) = 1;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 0x41 + (longlong)ppuVar31) = 1;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 0x7a + (longlong)ppuVar31) = 1;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 0xb3 + (longlong)ppuVar31) = 1;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 0xec + (longlong)ppuVar31) = 1;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 0x125 + (longlong)ppuVar31) = 1;
  *(undefined1 *)(lVar34 + lVar41 * 3 + 0x15e + (longlong)ppuVar31) = 1;
  iVar3 = *(int *)(param_1 + 0x88);
  lVar34 = 0;
  iVar8 = *(int *)(param_1 + 0x94) / 0x3c;
  if ((*(uint *)(param_1 + 200) & 0x800) == 0) {
    ppuVar20 = ppuVar31 + lVar35 * 3 + 0xfb;
LAB_14018c980:
    iVar4 = *(int *)((longlong)ppuVar20 + -4);
    if (((iVar4 != -1) && (iVar4 <= iVar8)) && ((iVar4 != iVar8 || (iVar3 <= *(int *)ppuVar20))))
    goto LAB_14018c994;
    lVar34 = (longlong)(2 - iVar37);
    if (0 < 2 - iVar37) {
      ppuVar20 = ppuVar31 + lVar35 * 3 + 0xfd;
      do {
        *(undefined4 *)ppuVar20 = *(undefined4 *)(ppuVar20 + -1);
        *(undefined4 *)((longlong)ppuVar20 + -4) = *(undefined4 *)((longlong)ppuVar20 + -0xc);
        ppuVar20 = ppuVar20 + -1;
        lVar34 = lVar34 + -1;
      } while (lVar34 != 0);
    }
LAB_14018c9d5:
    lVar34 = lVar35 * 3 + (longlong)iVar37;
    *(int *)((longlong)ppuVar31 + lVar34 * 8 + 0x7d4) = iVar8;
    *(int *)(ppuVar31 + lVar34 + 0xfb) = iVar3;
    goto LAB_14018c9f4;
  }
  piVar23 = (int *)((longlong)ppuVar31 + lVar35 * 0x18 + 0x7d4);
  do {
    iVar4 = piVar23[1];
    if (((iVar4 == -1) || (iVar4 < iVar3)) || ((iVar4 == iVar3 && (iVar8 < *piVar23)))) {
      lVar34 = (longlong)(2 - iVar37);
      if (0 < 2 - iVar37) {
        ppuVar20 = ppuVar31 + lVar35 * 3 + 0xfd;
        do {
          *(undefined4 *)ppuVar20 = *(undefined4 *)(ppuVar20 + -1);
          *(undefined4 *)((longlong)ppuVar20 + -4) = *(undefined4 *)((longlong)ppuVar20 + -0xc);
          ppuVar20 = ppuVar20 + -1;
          lVar34 = lVar34 + -1;
        } while (lVar34 != 0);
      }
      goto LAB_14018c9d5;
    }
    iVar37 = iVar37 + 1;
    lVar34 = lVar34 + 1;
    piVar23 = piVar23 + 2;
  } while (lVar34 < 3);
LAB_14018c9f4:
  if ((*(uint *)(param_1 + 200) & 0x400) == 0) {
    iVar3 = *(int *)(param_1 + 0x94);
    uVar5 = *(undefined4 *)(param_1 + 0x98);
    uVar6 = *(undefined4 *)(param_1 + 0x84);
    uVar7 = *(undefined4 *)(param_1 + 0x88);
    lVar35 = lVar41 * 3 + 3;
    lVar34 = lVar35 * 8;
    bVar43 = cVar33 == '\0';
    puVar21 = &DAT_14031cbf8;
    if (bVar43) {
      puVar21 = &DAT_140316c40;
    }
    *(int *)(puVar21 + lVar34) = iVar14;
    puVar21 = &DAT_14031cbfc;
    if (bVar43) {
      puVar21 = &DAT_140316c44;
    }
    *(undefined4 *)(puVar21 + lVar34) = uVar7;
    puVar21 = &DAT_14031cc00;
    if (bVar43) {
      puVar21 = &DAT_140316c48;
    }
    *(int *)(puVar21 + lVar34) = iVar3 / 0x3c;
    puVar22 = &DAT_14031cc04;
    if (bVar43) {
      puVar22 = &DAT_140316c4c;
    }
    puVar22[lVar35 * 2] = uVar6;
    puVar21 = &DAT_14031cc08;
    if (bVar43) {
      puVar21 = &DAT_140316c50;
    }
    *(undefined4 *)(puVar21 + lVar34) = uVar5;
    puVar21 = &DAT_14031cc0c;
    if (bVar43) {
      puVar21 = &DAT_140316c54;
    }
    puVar21[lVar34] = (char)uVar27;
    puVar22 = &DAT_14031cde8;
    uVar5 = *(undefined4 *)(param_1 + 0x84);
    if (bVar43) {
      puVar22 = &DAT_140316e30;
    }
    *puVar22 = uVar5;
    lVar34 = FUN_140189320();
    *(char *)(lVar34 + 0x3a) = (char)uVar5;
  }
  lVar34 = (longlong)iVar14;
  iVar3 = DAT_14031cbc0;
  if (cVar33 == '\0') {
    iVar3 = DAT_140316c08;
  }
  piVar23 = &DAT_14031cbc0;
  if (cVar33 == '\0') {
    piVar23 = &DAT_140316c08;
  }
  *piVar23 = *(int *)(param_1 + 0x94) / 0x3c + iVar3;
  *(uint *)(puVar39 + lVar34 * 4 + 0x5c4) =
       *(int *)(puVar39 + lVar34 * 4 + 0x5c4) + (uint)*(ushort *)(param_1 + 0xc0);
  *(uint *)(puVar39 + lVar34 * 4 + 0x774) =
       *(int *)(puVar39 + lVar34 * 4 + 0x774) + (uint)*(ushort *)(param_1 + 0xc2);
  *(int *)(puVar39 + lVar34 * 4 + 0x264) =
       *(int *)(puVar39 + lVar34 * 4 + 0x264) + *(int *)(param_1 + 0xb8);
  *(int *)(puVar39 + lVar34 * 4 + 0x414) = *(int *)(puVar39 + lVar34 * 4 + 0x414) + 1;
  if (iVar9 < 0x13) {
    piVar23 = (int *)(&DAT_1402a9ac0 + lVar41 * 8);
  }
  else {
    piVar23 = (int *)0x0;
  }
  if (*piVar23 == 0) {
    lVar41 = 0x195;
    lVar34 = 0x201;
    lVar35 = 0xbd;
    lVar38 = 0x129;
  }
  else {
    if (*piVar23 != 1) goto LAB_14018cc35;
    lVar41 = 0x1b9;
    lVar34 = 0x225;
    lVar35 = 0xe1;
    lVar38 = 0x14d;
  }
  lVar42 = (longlong)iVar17;
  *(uint *)(puVar39 + (lVar41 + lVar42) * 4) =
       *(int *)(puVar39 + (lVar41 + lVar42) * 4) + (uint)*(ushort *)(param_1 + 0xc4);
  *(uint *)(puVar39 + (lVar34 + lVar42) * 4) =
       *(int *)(puVar39 + (lVar34 + lVar42) * 4) + (uint)*(ushort *)(param_1 + 0xc6);
  *(uint *)(puVar39 + (lVar35 + lVar42) * 4) =
       *(int *)(puVar39 + (lVar35 + lVar42) * 4) +
       (uint)*(ushort *)(param_1 + 0xc4) + (uint)*(ushort *)(param_1 + 0xc6);
  *(int *)(puVar39 + (lVar38 + lVar42) * 4) = *(int *)(puVar39 + (lVar38 + lVar42) * 4) + 1;
LAB_14018cc35:
  uVar27 = 0;
  puVar21 = puVar39 + 0x10;
  bVar32 = 1;
  puVar36 = puVar39 + 0xc2;
  do {
    if (uVar27 == 0x21) {
      if ((*(uint *)(param_1 + 200) & 0x1000) != 0) goto LAB_14018cc7d;
LAB_14018cc78:
      if ((*(byte *)((ulonglong)(uVar27 >> 3) + 0x50 + param_1) & bVar32) != 0) goto LAB_14018cc7d;
    }
    else {
      if ((uVar27 != 0x22) || ((*(uint *)(param_1 + 200) & 0x2000) == 0)) goto LAB_14018cc78;
LAB_14018cc7d:
      puVar21[-4] = 1;
      *(undefined2 *)(puVar36 + -2) = 0x101;
      *puVar36 = 1;
      puVar36[0x11e] = 1;
    }
    if ((*(byte *)((ulonglong)(uVar27 >> 3) + 0x55 + param_1) & bVar32) != 0) {
      *puVar21 = 1;
      puVar21[0x120] = 1;
    }
    if ((*(byte *)(param_1 + 0xd0) & 1) != 0) {
      puVar21[-3] = 1;
      puVar21[0x11d] = 1;
    }
    if ((*(byte *)(param_1 + 0xd0) & 2) != 0) {
      puVar21[-2] = 1;
      puVar21[0x11e] = 1;
    }
    if ((*(byte *)(param_1 + 0xd0) & 4) != 0) {
      puVar21[-1] = 1;
      puVar21[0x11f] = 1;
    }
    uVar27 = uVar27 + 1;
    bVar32 = bVar32 << 1 | (char)bVar32 < '\0';
    puVar36 = puVar36 + 3;
    puVar21 = puVar21 + 5;
    if (0x23 < (int)uVar27) {
      puVar22 = &DAT_140317910;
      *(undefined4 *)(puVar39 + 8) = *(undefined4 *)(param_1 + 0x90);
      puVar28 = &DAT_140317851;
      if (cVar33 == '\0') {
        puVar22 = &DAT_140311958;
      }
      *puVar22 = *(undefined4 *)(param_1 + 0xbc);
      if (cVar33 == '\0') {
        puVar28 = &DAT_140311899;
      }
      bVar32 = 1;
      do {
        if ((*(byte *)((uVar29 >> 3) + 0x5f + param_1) & bVar32) != 0) {
          puVar28[-0xa9] = 1;
          *puVar28 = 1;
        }
        uVar27 = (int)uVar29 + 1;
        uVar29 = (ulonglong)uVar27;
        bVar32 = bVar32 << 1 | (char)bVar32 < '\0';
        puVar28 = puVar28 + 1;
      } while ((int)uVar27 < 0xa9);
      puVar28 = &DAT_1403178fb;
      bVar32 = 1;
      if (cVar33 == '\0') {
        puVar28 = &DAT_140311943;
      }
      lVar41 = 2;
      do {
        if ((*(byte *)((ulonglong)(uVar30 - 2 >> 3) + 0x75 + param_1) & bVar32) != 0) {
          puVar28[-1] = 1;
        }
        uVar27 = uVar30 - 1;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 6;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            *puVar28 = 1;
          }
        }
        if (uVar30 < 0x14) {
          uVar26 = uVar30 & 7;
          uVar27 = uVar30;
          if ((int)uVar30 < 0) {
            uVar27 = uVar30 + 7;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[1] = 1;
          }
        }
        uVar27 = uVar30 + 1;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 8;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[2] = 1;
          }
        }
        uVar27 = uVar30 + 2;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 9;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[3] = 1;
          }
        }
        uVar27 = uVar30 + 3;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 10;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[4] = 1;
          }
        }
        uVar27 = uVar30 + 4;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 0xb;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[5] = 1;
          }
        }
        uVar27 = uVar30 + 5;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 0xc;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[6] = 1;
          }
        }
        uVar27 = uVar30 + 6;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 0xd;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[7] = 1;
          }
        }
        uVar27 = uVar30 + 7;
        if ((-1 < (int)uVar27) && ((int)uVar27 < 0x14)) {
          uVar26 = uVar27 & 7;
          if ((int)uVar27 < 0) {
            uVar27 = uVar30 + 0xe;
            uVar26 = uVar26 - 8;
          }
          if (((byte)(1 << (uVar26 & 0x1f)) &
              *(byte *)((longlong)((int)uVar27 >> 3) + 0x75 + param_1)) != 0) {
            puVar28[8] = 1;
          }
        }
        uVar30 = uVar30 + 10;
        bVar32 = bVar32 << 2 | bVar32 >> 6;
        puVar28 = puVar28 + 10;
        lVar41 = lVar41 + -1;
      } while (lVar41 != 0);
      if ((*(byte *)(param_1 + 0x78) & 8) != 0) {
        DAT_140310e74 = 1;
      }
      if ((*(uint *)(param_1 + 200) & 0x100) != 0) {
        piVar23 = &DAT_14031cbbc;
        if (cVar33 == '\0') {
          piVar23 = &DAT_140316c04;
        }
        *piVar23 = *piVar23 + 1;
        puVar28 = &DAT_14031cbea;
        if (DAT_14031cf18 == '\0') {
          puVar28 = &DAT_140316c32;
        }
        *puVar28 = 1;
      }
      if (*(int *)(param_1 + 0xcc) != -1) {
        piVar23 = (int *)&DAT_14031cbc4;
        if (cVar33 == '\0') {
          piVar23 = (int *)&DAT_140316c0c;
        }
        *piVar23 = *(int *)(param_1 + 0xcc);
      }
      if ((*(byte *)(param_1 + 0x78) & 2) != 0) {
        *(undefined1 *)((longlong)ppuVar31 + 0x3e) = 1;
        *(undefined1 *)((longlong)ppuVar31 + 0x77) = 1;
        *(undefined1 *)(ppuVar31 + 0x16) = 1;
        *(undefined1 *)((longlong)ppuVar31 + 0xe9) = 1;
        *(undefined1 *)((longlong)ppuVar31 + 0x122) = 1;
        *(undefined1 *)((longlong)ppuVar31 + 0x15b) = 1;
        *(undefined1 *)((longlong)ppuVar31 + 0x194) = 1;
      }
      piVar23 = &DAT_1403170c4;
      if (DAT_14031cf18 == '\0') {
        piVar23 = &DAT_14031110c;
      }
      puVar40 = &DAT_14031cdf4;
      *piVar23 = iVar14;
      puVar22 = &DAT_1403170cc;
      if (DAT_14031cf18 == '\0') {
        puVar22 = &DAT_140311114;
      }
      *puVar22 = uVar13;
      puVar22 = &DAT_1403170d4;
      if (DAT_14031cf18 == '\0') {
        puVar22 = &DAT_14031111c;
      }
      *puVar22 = uVar12;
      if (DAT_14031cf18 == '\0') {
        puVar24 = &DAT_140316e3c;
        uVar30 = DAT_140316e3c;
      }
      else {
        puVar24 = &DAT_14031cdf4;
        uVar30 = DAT_14031cdf4;
      }
      uVar27 = auVar2._8_4_ & 0xf;
      *puVar24 = uVar30 & 0xf0 | uVar27;
      lVar41 = FUN_140189320();
      *(char *)(lVar41 + 0x36) = (char)uVar27;
      if (DAT_14031cf18 == '\0') {
        puVar40 = &DAT_140316e3c;
        uVar30 = DAT_140316e3c;
      }
      else {
        uVar30 = DAT_14031cdf4;
      }
      uVar27 = auVar2._8_4_ & 0xf0;
      *puVar40 = uVar30 & 0xf | uVar27;
      lVar41 = FUN_140189320();
      puVar15 = &DAT_14031cdec;
      *(char *)(lVar41 + 0x37) = (char)uVar27;
      if (DAT_14031cf18 == '\0') {
        puVar15 = &DAT_140316e34;
      }
      *(int *)((longlong)puVar15 + 4) = auVar2._4_4_;
      if (DAT_14031cf18 == '\0') {
        puVar40 = &DAT_140316e4c;
        uVar30 = DAT_140316e4c;
      }
      else {
        puVar40 = &DAT_14031ce04;
        uVar30 = DAT_14031ce04;
      }
      uVar27 = uVar25 & 0xf;
      *puVar40 = uVar30 & 0xf0 | uVar27;
      if (uVar27 == 0) {
        lVar41 = FUN_140189320();
        *(undefined1 *)(lVar41 + 0x35) = 0;
      }
      else if (uVar27 == 1) {
        lVar41 = FUN_140189320();
        *(undefined1 *)(lVar41 + 0x35) = 1;
      }
      ppuVar31 = &PTR_PTR_140316e70;
      if (DAT_14031cf18 == '\0') {
        ppuVar31 = &PTR_PTR_140310eb8;
      }
      FUN_14018a160(ppuVar31,uVar25);
      puVar22 = &DAT_14031cdf8;
      if (DAT_14031cf18 == '\0') {
        puVar22 = &DAT_140316e40;
      }
      *puVar22 = auVar2._12_4_;
      puVar22 = &DAT_14031cdfc;
      if (DAT_14031cf18 == '\0') {
        puVar22 = &DAT_140316e44;
      }
      local_58 = (undefined4)uVar1;
      *puVar22 = local_58;
      piVar23 = &DAT_14031ce00;
      if (DAT_14031cf18 == '\0') {
        piVar23 = &DAT_140316e48;
      }
      iStack_54 = (int)((ulonglong)uVar1 >> 0x20);
      *piVar23 = iStack_54;
      lVar41 = FUN_140189320();
      *(bool *)(lVar41 + 0x38) = iStack_54 == 0;
      if ((*(uint *)(param_1 + 200) & 0x400) != 0) {
        FUN_140164290(&DAT_140310e60);
      }
      piVar23 = (int *)&DAT_14031cdec;
      if (DAT_14031cf18 == '\0') {
        piVar23 = (int *)&DAT_140316e34;
      }
      *piVar23 = iVar10;
      if (iVar10 - 6U < 2) {
        lVar41 = FUN_140189320();
        *(undefined1 *)(lVar41 + 0x2f) = 0;
      }
      else {
        lVar41 = FUN_140189320();
        *(char *)(lVar41 + 0x2f) = (char)iVar10;
      }
      piVar23 = &DAT_1403170c8;
      if (DAT_14031cf18 == '\0') {
        piVar23 = &DAT_140311110;
      }
      *piVar23 = iVar17;
      puVar22 = &DAT_1403170d0;
      if (DAT_14031cf18 == '\0') {
        puVar22 = &DAT_140311118;
      }
      *puVar22 = uVar11;
      puVar22 = &DAT_1403170d8;
      if (DAT_14031cf18 == '\0') {
        puVar22 = &DAT_140311120;
      }
      *puVar22 = uVar18;
      return;
    }
  } while( true );
LAB_14018c994:
  iVar37 = iVar37 + 1;
  lVar34 = lVar34 + 1;
  ppuVar20 = ppuVar20 + 1;
  if (2 < lVar34) goto LAB_14018c9f4;
  goto LAB_14018c980;
}

