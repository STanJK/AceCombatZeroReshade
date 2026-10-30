/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140188180; RVA 0x188180
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140188180(void)

{
  uchar uVar1;
  uchar *arg3;
  uchar *arg2;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  uchar uVar5;
  int iVar6;
  uchar *puVar7;
  longlong lVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  longlong lVar12;
  byte *pbVar13;
  
  arg3 = DAT_14032c8e8;
  arg2 = DAT_14032c8e0;
  uVar5 = '\0';
  uVar11 = 0;
  DAT_14032c8e8[0x150] = '\0';
  uVar1 = arg2[0x22];
  puVar7 = arg3;
  if (DAT_14033abe4 == 0) {
    arg3[0x2e] = '\0';
    if (uVar1 == '\0') {
      uVar5 = '\0';
    }
    else {
      uVar5 = '\x04';
      if (uVar1 == '\x01') {
        uVar5 = '\x01';
      }
    }
    arg3[0x36] = uVar5;
    arg3[0x2c] = '\0';
    arg3[0x2d] = '\0';
    FUN_140188550(*(ushort *)(arg2 + 0x20),arg2,arg3);
    arg3[0x2f] = '\0';
    puVar7 = arg3 + 0x50;
    arg3[0x150] = arg3[0x150] + '\x01';
    uVar5 = arg3[0x150];
  }
  uVar1 = arg2[0x46];
  if (DAT_14033ac14 == 0) {
    puVar7[0x2e] = '\0';
    if (uVar1 == '\0') {
      uVar5 = '\0';
    }
    else {
      uVar5 = '\x04';
      if (uVar1 == '\x01') {
        uVar5 = '\x01';
      }
    }
    puVar7[0x36] = uVar5;
    puVar7[0x2c] = '\x01';
    puVar7[0x2d] = '\0';
    FUN_140188550(*(ushort *)(arg2 + 0x44),arg2 + 0x24,puVar7);
    puVar7[0x2f] = '\0';
    arg3[0x150] = arg3[0x150] + '\x01';
    uVar5 = arg3[0x150];
  }
  iVar9 = 0;
  bVar2 = 0;
  if (uVar5 != '\0') {
    do {
      FUN_140187390(arg3 + (longlong)iVar9 * 0x50);
      bVar2 = arg3[0x150];
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)bVar2);
  }
  arg3[0x140] = '\0';
  arg3[0x141] = '\0';
  arg3[0x142] = '\0';
  arg3[0x143] = '\0';
  arg3[0x144] = '\0';
  arg3[0x145] = '\0';
  arg3[0x146] = '\0';
  arg3[0x147] = '\0';
  iVar10 = -1;
  iVar9 = -1;
  iVar6 = 0;
  if (bVar2 != 0) {
    lVar12 = 0;
    pbVar13 = arg3 + 0x2d;
    lVar8 = -1;
    iVar9 = -1;
    do {
      if (pbVar13[-1] == 3) {
        if (*pbVar13 == 0) {
          *(uchar **)(arg3 + 0x140) = arg3 + (longlong)iVar6 * 0x50;
          break;
        }
        if ((lVar8 == -1) || (*pbVar13 < arg3[lVar8 * 0x50 + 0x2d])) {
          lVar8 = lVar12;
          iVar9 = iVar6;
        }
      }
      iVar6 = iVar6 + 1;
      lVar12 = lVar12 + 1;
      pbVar13 = pbVar13 + 0x50;
    } while (iVar6 < (int)(uint)bVar2);
  }
  if ((*(longlong *)(arg3 + 0x140) == 0) &&
     ((iVar9 == -1 ||
      (*(uchar **)(arg3 + 0x140) = arg3 + (longlong)iVar9 * 0x50,
      arg3 + (longlong)iVar9 * 0x50 == (uchar *)0x0)))) {
    uVar4 = 0;
    if (arg3[0x150] != 0) {
      puVar7 = arg3 + 0x2c;
      do {
        if (*puVar7 == '\0') {
          *(uchar **)(arg3 + 0x140) = arg3 + uVar4 * 0x50;
          break;
        }
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar3;
        puVar7 = puVar7 + 0x50;
      } while ((int)uVar3 < (int)(uint)arg3[0x150]);
    }
  }
  arg3[0x148] = '\0';
  arg3[0x149] = '\0';
  arg3[0x14a] = '\0';
  arg3[0x14b] = '\0';
  arg3[0x14c] = '\0';
  arg3[0x14d] = '\0';
  arg3[0x14e] = '\0';
  arg3[0x14f] = '\0';
  iVar9 = 0;
  if (arg3[0x150] != 0) {
    lVar12 = 0;
    pbVar13 = arg3 + 0x2d;
    lVar8 = -1;
    do {
      if (pbVar13[-1] == 2) {
        if (*pbVar13 == 0) {
          *(uchar **)(arg3 + 0x148) = arg3 + (longlong)iVar9 * 0x50;
          break;
        }
        if ((lVar8 == -1) || (*pbVar13 < arg3[lVar8 * 0x50 + 0x2d])) {
          lVar8 = lVar12;
          iVar10 = iVar9;
        }
      }
      iVar9 = iVar9 + 1;
      lVar12 = lVar12 + 1;
      pbVar13 = pbVar13 + 0x50;
    } while (iVar9 < (int)(uint)arg3[0x150]);
  }
  if (((*(longlong *)(arg3 + 0x148) == 0) &&
      ((((iVar10 == -1 || (lVar8 = *(longlong *)(arg3 + 0x140), lVar8 == 0)) ||
        ((arg3[(longlong)iVar9 * 0x50 + 0x2c] == *(uchar *)(lVar8 + 0x2c) &&
         (arg3[(longlong)iVar9 * 0x50 + 0x2d] == *(uchar *)(lVar8 + 0x2d))))) ||
       (*(uchar **)(arg3 + 0x148) = arg3 + (longlong)iVar10 * 0x50,
       arg3 + (longlong)iVar10 * 0x50 == (uchar *)0x0)))) && (arg3[0x150] != 0)) {
    puVar7 = arg3 + 0x2c;
    do {
      if (*puVar7 == '\x01') {
        *(uchar **)(arg3 + 0x148) = arg3 + (ulonglong)uVar11 * 0x50;
        return;
      }
      uVar11 = uVar11 + 1;
      puVar7 = puVar7 + 0x50;
    } while ((int)uVar11 < (int)(uint)arg3[0x150]);
  }
  return;
}

