/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140036fe0; RVA 0x36fe0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140036fe0(longlong param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  short *psVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  ushort uVar7;
  float *pfVar8;
  longlong lVar9;
  bool bVar10;
  float fVar11;
  undefined1 auVar12 [16];
  short sVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  ulonglong uVar19;
  ushort uVar20;
  longlong lVar21;
  char cVar22;
  float fVar23;
  float fVar24;
  undefined1 auVar25 [16];
  float fVar26;
  float fVar27;
  float local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float local_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  
  uVar19 = 0;
  fVar27 = 0.0;
  fVar26 = DAT_1402d22d0;
  do {
    uVar20 = (ushort)uVar19;
    if ((*(uint *)(param_1 + 0x1bc48 + (uVar19 >> 5) * 4) >> ((uint)uVar19 & 0x1f) & 1) != 0) {
      lVar21 = uVar19 * 0xa0;
      puVar2 = (undefined2 *)(lVar21 + 0x1bca0 + param_1);
      switch(*puVar2) {
      case 2:
        piVar1 = (int *)(lVar21 + 0x1bcfc + param_1);
        *piVar1 = *piVar1 + 1;
        if (*(int *)(lVar21 + 0x1bcfc + param_1) <
            *(int *)(*(longlong *)(lVar21 + 0x1bca8 + param_1) + 0x33708)) {
          fVar23 = *(float *)(lVar21 + 0x1bd0c + param_1) + *(float *)(lVar21 + 0x1bd10 + param_1);
          *(float *)(lVar21 + 0x1bd10 + param_1) = fVar23;
          if (fVar26 < fVar23) {
            piVar1 = (int *)(lVar21 + 0x1bd14 + param_1);
            *piVar1 = *piVar1 + 1;
            *(float *)(lVar21 + 0x1bd10 + param_1) = fVar23 - fVar26;
          }
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 3:
      case 4:
      case 0x10:
      case 0x11:
      case 0x22:
      case 0x23:
      case 0x2a:
      case 0x33:
      case 0x36:
      case 0x39:
      case 0x3a:
      case 0x7b:
        if (*(int *)(lVar21 + 0x1bca4 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bca4 + param_1) = 1;
LAB_1400370b0:
          cVar22 = '\0';
        }
        else {
LAB_14003709f:
          cVar22 = '\x01';
        }
        break;
      case 5:
      case 0x41:
      case 0x53:
        uVar7 = *(ushort *)(lVar21 + 0x1bca8 + param_1);
        *(ushort *)(lVar21 + 0x1bca8 + param_1) = uVar7 + 1;
        cVar22 = *(ushort *)(lVar21 + 0x1bcaa + param_1) < uVar7;
        break;
      case 6:
        cVar22 = FUN_14002c1a0(puVar2);
        break;
      case 7:
        if (*(int *)(lVar21 + 0x1bcf8 + param_1) < 1) {
          fVar23 = *(float *)(lVar21 + 0x1bcec + param_1) + *(float *)(lVar21 + 0x1bce8 + param_1);
          *(float *)(lVar21 + 0x1bce8 + param_1) = fVar23;
          if (fVar26 < fVar23) {
            piVar1 = (int *)(lVar21 + 0x1bcf0 + param_1);
            *piVar1 = *piVar1 + 1;
            *(float *)(lVar21 + 0x1bce8 + param_1) = fVar23 - fVar26;
          }
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 8:
        if (*(int *)(lVar21 + 0x1bcb0 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcb0 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 9:
        iVar18 = *(int *)(lVar21 + 0x1bcf8 + param_1);
        *(int *)(lVar21 + 0x1bcf8 + param_1) = iVar18 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcf0 + param_1) < iVar18;
        break;
      case 10:
        if (*(int *)(lVar21 + 0x1bcf4 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcf4 + param_1) = 1;
          uVar17 = FUN_140242630();
          uVar17 = uVar17 & 0x800000ff;
          if ((int)uVar17 < 0) {
            uVar17 = (uVar17 - 1 | 0xffffff00) + 1;
          }
          uVar14 = *(uint *)(*(longlong *)(lVar21 + 0x1bca8 + param_1) + 0x33704);
          piVar1 = (int *)(lVar21 + 0x1bcec + param_1);
          *piVar1 = *piVar1 + 1;
          iVar18 = uVar14 % 0x169f + uVar17;
          *(int *)(lVar21 + 0x1bca4 + param_1) = iVar18;
          fVar23 = DAT_1402d277c;
          if (*(int *)(lVar21 + 0x1bcf0 + param_1) <= *(int *)(lVar21 + 0x1bcec + param_1)) {
            *(undefined4 *)(lVar21 + 0x1bcec + param_1) = 0;
            uVar17 = (int)((float)(&DAT_1403273a0)[(ulonglong)(iVar18 + 1) & 0x3ff] * fVar23 +
                          fVar23) & 0x8000001f;
            if ((int)uVar17 < 0) {
              uVar17 = (uVar17 - 1 | 0xffffffe0) + 1;
            }
            *(uint *)(lVar21 + 0x1bcf0 + param_1) = uVar17 + 4;
          }
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0xb:
        iVar18 = *(int *)(lVar21 + 0x1bce0 + param_1);
        iVar16 = *(int *)(*(longlong *)(lVar21 + 0x1bca8 + param_1) + 0x33708);
        *(int *)(lVar21 + 0x1bce0 + param_1) = iVar18 + 1;
        if (iVar16 < iVar18) {
          cVar22 = '\x01';
        }
        else {
          fVar23 = *(float *)(lVar21 + 0x1bcf8 + param_1) + *(float *)(lVar21 + 0x1bcf4 + param_1);
          *(float *)(lVar21 + 0x1bcf4 + param_1) = fVar23;
          if (fVar26 < fVar23) {
            piVar1 = (int *)(lVar21 + 0x1bcfc + param_1);
            *piVar1 = *piVar1 + 1;
            *(float *)(lVar21 + 0x1bcf4 + param_1) = fVar23 - fVar26;
          }
          cVar22 = '\0';
        }
        break;
      case 0xc:
        if (*(int *)(lVar21 + 0x1bcf4 + param_1) == 0) {
          piVar1 = (int *)(lVar21 + 0x1bcd8 + param_1);
          *piVar1 = *piVar1 + 1;
          cVar22 = '\0';
          *(undefined4 *)(lVar21 + 0x1bcf4 + param_1) = 1;
        }
        else {
          cVar22 = '\x01';
        }
        break;
      default:
        goto switchD_140037093_caseD_d;
      case 0xf:
        piVar1 = (int *)(lVar21 + 0x1bcec + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcf0 + param_1) < *(int *)(lVar21 + 0x1bcec + param_1);
        break;
      case 0x12:
        iVar18 = *(int *)(lVar21 + 0x1bd04 + param_1);
        *(int *)(lVar21 + 0x1bd04 + param_1) = iVar18 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bd0c + param_1) + *(int *)(lVar21 + 0x1bd08 + param_1) <
                 iVar18;
        break;
      case 0x13:
        piVar1 = (int *)(lVar21 + 0x1bd20 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bd24 + param_1) < *(int *)(lVar21 + 0x1bd20 + param_1);
        break;
      case 0x14:
      case 0x17:
      case 0x19:
      case 0x1c:
      case 0x4b:
        iVar18 = *(int *)(lVar21 + 0x1bcd0 + param_1);
        *(int *)(lVar21 + 0x1bcd0 + param_1) = iVar18 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcd4 + param_1) < iVar18;
        break;
      case 0x16:
      case 0x18:
      case 0x75:
      case 0x76:
        piVar1 = (int *)(lVar21 + 0x1bcd0 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcd4 + param_1) < *(int *)(lVar21 + 0x1bcd0 + param_1);
        break;
      case 0x1b:
        piVar1 = (int *)(lVar21 + 0x1bcec + param_1);
        *piVar1 = *piVar1 + 1;
        if (*(int *)(lVar21 + 0x1bcec + param_1) < *(int *)(lVar21 + 0x1bce0 + param_1)) {
          piVar1 = (int *)(lVar21 + 0x1bce8 + param_1);
          *piVar1 = *piVar1 + 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x20:
        iVar18 = *(int *)(lVar21 + 0x1bcb0 + param_1);
        if (iVar18 < 1) {
          *(int *)(lVar21 + 0x1bcb0 + param_1) = iVar18 + 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x21:
        if (*(short *)(lVar21 + 0x1bcb0 + param_1) == 0) {
          *(float *)(lVar21 + 0x1bd28 + param_1) = fVar26 + *(float *)(lVar21 + 0x1bd28 + param_1);
          *(undefined2 *)(lVar21 + 0x1bcb0 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x24:
        iVar18 = *(int *)(lVar21 + 0x1bce4 + param_1);
        if ((2 < iVar18) || (*(int *)(lVar21 + 0x1bce8 + param_1) != 0)) goto LAB_14003709f;
        *(undefined4 *)(lVar21 + 0x1bce8 + param_1) = 1;
        *(int *)(lVar21 + 0x1bce4 + param_1) = iVar18 + 1;
        cVar22 = '\0';
        break;
      case 0x25:
        if (*(int *)(lVar21 + 0x1bcf0 + param_1) == 0) {
          piVar1 = (int *)(lVar21 + 0x1bcec + param_1);
          *piVar1 = *piVar1 + 1;
          iVar18 = *(int *)(lVar21 + 0x1bce0 + param_1);
          *(undefined4 *)(lVar21 + 0x1bcf0 + param_1) = 1;
          if (iVar18 == 1) {
            piVar1 = (int *)(lVar21 + 0x1bce4 + param_1);
            *piVar1 = *piVar1 + 8;
          }
          else if (iVar18 == 0) {
            piVar1 = (int *)(lVar21 + 0x1bce4 + param_1);
            *piVar1 = *piVar1 + -8;
          }
          iVar18 = *(int *)(lVar21 + 0x1bce4 + param_1);
          if (iVar18 < 0x80) {
            if (iVar18 < 0) {
              *(undefined4 *)(lVar21 + 0x1bce4 + param_1) = 0;
            }
            cVar22 = '\0';
          }
          else {
            *(undefined4 *)(lVar21 + 0x1bce4 + param_1) = 0x7f;
            cVar22 = '\0';
          }
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x26:
      case 0x40:
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x49:
      case 0x4f:
      case 0x50:
        psVar3 = (short *)(lVar21 + 0x1bca8 + param_1);
        *psVar3 = *psVar3 + 1;
        cVar22 = *(ushort *)(lVar21 + 0x1bcaa + param_1) < *(ushort *)(lVar21 + 0x1bca8 + param_1);
        break;
      case 0x2c:
        piVar1 = (int *)(lVar21 + 0x1bcd8 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcdc + param_1) < *(int *)(lVar21 + 0x1bcd8 + param_1);
        break;
      case 0x2d:
        piVar1 = (int *)(lVar21 + 0x1bcd8 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcdc + param_1) <= *(int *)(lVar21 + 0x1bcd8 + param_1);
        break;
      case 0x30:
        uVar17 = *(uint *)(lVar21 + 0x1bcf8 + param_1);
        uVar14 = *(int *)(lVar21 + 0x1bcf4 + param_1) + 1;
        *(uint *)(lVar21 + 0x1bcf4 + param_1) = uVar14;
        if ((uVar17 == 0) || (uVar14 <= uVar17)) goto LAB_1400370b0;
        cVar22 = '\x01';
        break;
      case 0x31:
        piVar1 = (int *)(lVar21 + 0x1bcd0 + param_1);
        *piVar1 = *piVar1 + 1;
        uVar7 = *(ushort *)(lVar21 + 0x1bcd6 + param_1);
        if ((int)(uint)uVar7 < *(int *)(lVar21 + 0x1bd08 + param_1)) {
          *(ushort *)(lVar21 + 0x1bcd6 + param_1) = uVar7 + 1;
          cVar22 = '\0';
          *(float *)(lVar21 + 0x1bcd8 + param_1) =
               -((float)uVar7 * *(float *)(lVar21 + 0x1bd0c + param_1)) + fVar26;
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x32:
        if (*(int *)(lVar21 + 0x1bcb4 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcb4 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x34:
        goto switchD_140037093_caseD_34;
      case 0x3e:
        piVar1 = (int *)(lVar21 + 0x1bcdc + param_1);
        iVar18 = *(int *)(lVar21 + 0x1bcd8 + param_1) + 1;
        piVar4 = (int *)(lVar21 + 0x1bce0 + param_1);
        *(int *)(lVar21 + 0x1bcd8 + param_1) = iVar18;
        if ((iVar18 < *(int *)(lVar21 + 0x1bcac + param_1)) ||
           (*piVar1 = *piVar1 + 1, *piVar1 < *piVar4)) {
          iVar16 = *piVar4;
          iVar15 = iVar18 / iVar16;
          iVar18 = iVar18 % iVar16;
          iVar16 = *piVar1;
LAB_140037657:
          fVar23 = *(float *)(lVar21 + 0x1bce4 + param_1);
          *(float *)(lVar21 + 0x1bcf0 + param_1) = (float)iVar16 * fVar23;
          *(int *)(lVar21 + 0x1bce8 + param_1) = iVar15;
          *(float *)(lVar21 + 0x1bcec + param_1) = (float)iVar18 * fVar23;
LAB_140037689:
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x3f:
        if (*(short *)(lVar21 + 0x1bcf8 + param_1) != 0) {
          if (*(short *)(lVar21 + 0x1bcfa + param_1) != 0) {
            cVar22 = '\x01';
            break;
          }
          *(undefined2 *)(lVar21 + 0x1bcfa + param_1) = 1;
        }
        iVar18 = *(int *)(lVar21 + 0x1bcd8 + param_1) + 1;
        *(int *)(lVar21 + 0x1bcd8 + param_1) = iVar18;
        if ((iVar18 < *(int *)(lVar21 + 0x1bcac + param_1)) ||
           (piVar1 = (int *)(lVar21 + 0x1bcdc + param_1), *piVar1 = *piVar1 + 1,
           *(int *)(lVar21 + 0x1bcdc + param_1) < *(int *)(lVar21 + 0x1bce0 + param_1))) {
          iVar16 = *(int *)(lVar21 + 0x1bce0 + param_1);
          iVar15 = iVar18 / iVar16;
          iVar18 = iVar18 % iVar16;
          iVar16 = *(int *)(lVar21 + 0x1bcdc + param_1);
          goto LAB_140037657;
        }
        cVar22 = '\x01';
        break;
      case 0x45:
        piVar1 = (int *)(lVar21 + 0x1bca4 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(uint *)(lVar21 + 0x1bca8 + param_1) < *(uint *)(lVar21 + 0x1bca4 + param_1);
        break;
      case 0x47:
        piVar1 = (int *)(lVar21 + 0x1bca8 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bcac + param_1) < *(int *)(lVar21 + 0x1bca8 + param_1);
        break;
      case 0x48:
      case 0x4c:
      case 0x4d:
        if (((*(byte *)(*(longlong *)(lVar21 + 0x1bd28 + param_1) + 0x33704) & 1) != 0) ||
           (piVar1 = (int *)(lVar21 + 0x1bca8 + param_1), *piVar1 = *piVar1 + 1,
           *(int *)(lVar21 + 0x1bca8 + param_1) < 0x81)) goto LAB_1400370b0;
        cVar22 = '\x01';
        break;
      case 0x4a:
        piVar1 = (int *)(lVar21 + 0x1bcc8 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bccc + param_1) < *(int *)(lVar21 + 0x1bcc8 + param_1);
        break;
      case 0x4e:
        if (((*(byte *)(*(longlong *)(lVar21 + 0x1bcb0 + param_1) + 0x33704) & 1) != 0) ||
           (piVar1 = (int *)(lVar21 + 0x1bca8 + param_1), *piVar1 = *piVar1 + 1,
           *(int *)(lVar21 + 0x1bca8 + param_1) < 0x81)) goto LAB_1400370b0;
        cVar22 = '\x01';
        break;
      case 0x51:
        piVar1 = (int *)(lVar21 + 0x1bce0 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bce4 + param_1) < *(int *)(lVar21 + 0x1bce0 + param_1);
        break;
      case 0x52:
        if (*(int *)(lVar21 + 0x1bcb8 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcb8 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x54:
        iVar18 = *(int *)(lVar21 + 0x1bcd4 + param_1);
        iVar16 = *(int *)(lVar21 + 0x1bcd0 + param_1) + 1;
        *(int *)(lVar21 + 0x1bcd0 + param_1) = iVar16;
        if (iVar16 < iVar18) {
          piVar1 = (int *)(lVar21 + 0x1bccc + param_1);
          *piVar1 = *piVar1 + 1;
          fVar23 = *(float *)(lVar21 + 0x1bcd8 + param_1);
          iVar15 = *(int *)(lVar21 + 0x1bccc + param_1);
          *(float *)(lVar21 + 0x1bce4 + param_1) = (float)iVar16 * fVar23;
          *(int *)(lVar21 + 0x1bcdc + param_1) = iVar15 / iVar18;
          cVar22 = '\0';
          *(float *)(lVar21 + 0x1bce0 + param_1) = (float)(iVar15 % iVar18) * fVar23;
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x55:
        fVar24 = fVar26 + *(float *)(lVar21 + 0x1bccc + param_1);
        fVar23 = *(float *)(lVar21 + 0x1bcd0 + param_1);
        *(float *)(lVar21 + 0x1bccc + param_1) = fVar24;
        if (fVar24 < fVar23) {
          fVar6 = fVar26 + *(float *)(lVar21 + 0x1bcc8 + param_1);
          fVar5 = *(float *)(lVar21 + 0x1bcd4 + param_1);
          fVar24 = -(fVar5 * fVar24) + fVar26;
          *(float *)(lVar21 + 0x1bcdc + param_1) = fVar24;
          *(float *)(lVar21 + 0x1bcc8 + param_1) = fVar6;
          if (fVar23 <= fVar6) goto LAB_140037689;
          *(float *)(lVar21 + 0x1bcdc + param_1) = fVar5 * fVar6 * fVar24;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x56:
        iVar18 = *(int *)(lVar21 + 0x1bcd0 + param_1);
        iVar16 = *(int *)(lVar21 + 0x1bccc + param_1) + 1;
        *(int *)(lVar21 + 0x1bccc + param_1) = iVar16;
        if (iVar16 < iVar18) {
          piVar1 = (int *)(lVar21 + 0x1bcc8 + param_1);
          *piVar1 = *piVar1 + 1;
          fVar23 = *(float *)(lVar21 + 0x1bcd4 + param_1);
          iVar15 = *(int *)(lVar21 + 0x1bcc8 + param_1);
          *(float *)(lVar21 + 0x1bce0 + param_1) = (float)iVar16 * fVar23;
          *(int *)(lVar21 + 0x1bcd8 + param_1) = iVar15 / iVar18;
          cVar22 = '\0';
          *(float *)(lVar21 + 0x1bcdc + param_1) = (float)(iVar15 % iVar18) * fVar23;
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x57:
        piVar1 = (int *)(lVar21 + 0x1bcdc + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bce0 + param_1) < *(int *)(lVar21 + 0x1bcdc + param_1);
        break;
      case 0x58:
        if (*(int *)(lVar21 + 0x1bce8 + param_1) == 0) {
          fVar23 = *(float *)(lVar21 + 0x1bce4 + param_1);
          fVar24 = *(float *)(lVar21 + 0x1bce0 + param_1);
          fVar5 = fVar24 - fVar23;
          *(undefined4 *)(lVar21 + 0x1bce8 + param_1) = 1;
          if (fVar5 < fVar27) {
            *(float *)(lVar21 + 0x1bce4 + param_1) = fVar24;
          }
          else {
            fVar23 = fVar5 * DAT_1402d1ff8 + fVar23;
            bVar10 = DAT_1402d22bc <= fVar23;
            *(float *)(lVar21 + 0x1bce4 + param_1) = fVar23;
            if (bVar10) {
              *(undefined4 *)(lVar21 + 0x1bce4 + param_1) = 0x3f800000;
            }
          }
          piVar1 = (int *)(lVar21 + 0x1bcec + param_1);
          *piVar1 = *piVar1 + 1;
LAB_140037a06:
          uVar17 = FUN_140242630();
          uVar17 = uVar17 & 0x800000ff;
          if ((int)uVar17 < 0) {
            uVar17 = (uVar17 - 1 | 0xffffff00) + 1;
          }
          *(uint *)(lVar21 + 0x1bcb0 + param_1) = uVar17;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x59:
        if (*(int *)(lVar21 + 0x1bcdc + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcdc + param_1) = 1;
          uVar17 = FUN_140242630();
          uVar17 = uVar17 & 0x800000ff;
          if ((int)uVar17 < 0) {
            uVar17 = (uVar17 - 1 | 0xffffff00) + 1;
          }
          *(uint *)(lVar21 + 0x1bcb8 + param_1) = uVar17;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x5a:
      case 0x77:
        if (*(int *)(lVar21 + 0x1bcd0 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcd0 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 99:
        if (*(int *)(lVar21 + 0x1bcf4 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcf4 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 100:
        if (*(int *)(lVar21 + 0x1bcd8 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcd8 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x65:
        piVar1 = (int *)(lVar21 + 0x1bcdc + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bccc + param_1) < *(int *)(lVar21 + 0x1bcdc + param_1);
        break;
      case 0x66:
        piVar1 = (int *)(lVar21 + 0x1bcd0 + param_1);
        *piVar1 = *piVar1 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bccc + param_1) < *(int *)(lVar21 + 0x1bcd0 + param_1);
        break;
      case 0x67:
        if (*(short *)(lVar21 + 0x1bd14 + param_1) == 0) {
          *(undefined2 *)(lVar21 + 0x1bd14 + param_1) = 1;
          goto LAB_140037a06;
        }
        cVar22 = '\x01';
        break;
      case 0x68:
      case 0x74:
        if (*(int *)(lVar21 + 0x1bcd4 + param_1) == 0) {
          *(undefined4 *)(lVar21 + 0x1bcd4 + param_1) = 1;
          goto LAB_140037a06;
        }
        cVar22 = '\x01';
        break;
      case 0x69:
        fVar23 = *(float *)(lVar21 + 0x1bcbc + param_1);
        iVar18 = *(int *)(lVar21 + 0x1bce0 + param_1);
        fVar24 = *(float *)(lVar21 + 0x1bcc4 + param_1);
        fVar5 = *(float *)(lVar21 + 0x1bcc8 + param_1);
        fVar6 = *(float *)(lVar21 + 0x1bcd8 + param_1);
        pfVar8 = *(float **)(lVar21 + 0x1bcb0 + param_1);
        fVar11 = (float)(*(int *)(lVar21 + 0x1bce4 + param_1) + iVar18) *
                 *(float *)(lVar21 + 0x1bce8 + param_1);
        _local_78 = CONCAT44(fVar11 * *(float *)(lVar21 + 0x1bcd0 + param_1) +
                             *(float *)(lVar21 + 0x1bcc0 + param_1),
                             fVar11 * *(float *)(lVar21 + 0x1bccc + param_1) + fVar23);
        _fStack_70 = CONCAT44(fVar11 * fVar6 + fVar5,
                              fVar11 * *(float *)(lVar21 + 0x1bcd4 + param_1) + fVar24);
        fVar11 = fVar11 + *pfVar8;
        _local_68 = CONCAT44(fVar11 * *(float *)(lVar21 + 0x1bcd0 + param_1) +
                             *(float *)(lVar21 + 0x1bcc0 + param_1),
                             fVar11 * *(float *)(lVar21 + 0x1bccc + param_1) + fVar23);
        _fStack_60 = CONCAT44(fVar11 * fVar6 + fVar5,
                              fVar11 * *(float *)(lVar21 + 0x1bcd4 + param_1) + fVar24);
        auVar12._8_8_ = 0;
        auVar12._0_8_ = SUB648(ZEXT1264((undefined1  [12])0x0),4);
        auVar25._0_4_ = (float)iVar18 / (float)*(int *)(lVar21 + 0x1bcdc + param_1);
        auVar25._4_12_ = SUB1612(auVar12 << 0x40,4);
        local_58 = fVar26;
        local_54 = FUN_140022e40(pfVar8 + 4,auVar25._0_8_);
        local_50 = (int)*(short *)((longlong)pfVar8 + 0x22);
        local_4c = 0;
        sVar13 = FUN_140035b10(*(undefined8 *)(lVar21 + 0x1bca8 + param_1),0x67,&local_78,
                               *(undefined2 *)(lVar21 + 0x1bcec + param_1),0xffff);
        iVar18 = *(int *)(lVar21 + 0x1bce0 + param_1);
        *(short *)(lVar21 + 0x1bcec + param_1) = sVar13;
        *(int *)(lVar21 + 0x1bce0 + param_1) = iVar18 + 1;
        if (*(int *)(lVar21 + 0x1bcdc + param_1) < iVar18) {
          cVar22 = '\x01';
        }
        else {
          cVar22 = sVar13 == 0;
        }
        break;
      case 0x6a:
        iVar18 = *(int *)(lVar21 + 0x1bce8 + param_1);
        *(int *)(lVar21 + 0x1bce8 + param_1) = iVar18 + 1;
        cVar22 = *(int *)(lVar21 + 0x1bce4 + param_1) < iVar18;
        break;
      case 0x6b:
        iVar18 = *(int *)(lVar21 + 0x1bccc + param_1);
        if (iVar18 < 1) {
          cVar22 = '\x01';
        }
        else {
          *(int *)(lVar21 + 0x1bccc + param_1) = iVar18 + -1;
          cVar22 = '\0';
        }
        break;
      case 0x78:
        cVar22 = FUN_14003b480(puVar2);
        break;
      case 0x79:
        if (*(int *)(lVar21 + 0x1bd08 + param_1) == 0) {
          *(undefined8 *)(lVar21 + 0x1bd08 + param_1) = 1;
          cVar22 = '\0';
        }
        else {
          cVar22 = '\x01';
        }
        break;
      case 0x7a:
        cVar22 = FUN_14003da20(puVar2);
        break;
      case 0x7c:
        iVar18 = *(int *)(lVar21 + 0x1bcc4 + param_1);
        lVar9 = *(longlong *)(*(longlong *)(lVar21 + 0x1bca8 + param_1) + 0x1bc40);
        *(int *)(lVar21 + 0x1bcc4 + param_1) = iVar18 + 1;
        if (*(int *)(lVar21 + 0x1bcc0 + param_1) < iVar18) {
          *(undefined1 *)(lVar9 + 0x29) = 0;
          cVar22 = '\x01';
        }
        else {
          piVar1 = (int *)(lVar21 + 0x1bcc8 + param_1);
          *piVar1 = *piVar1 + 1;
          if (*(uint *)(lVar21 + 0x1bcc8 + param_1) < *(uint *)(lVar21 + 0x1bcd0 + param_1))
          goto LAB_140037689;
          *(undefined4 *)(lVar21 + 0x1bcc8 + param_1) = 0;
          iVar18 = FUN_140242630();
          *(int *)(lVar21 + 0x1bcd0 + param_1) = iVar18 % 0x78 + 0x3c;
          cVar22 = '\0';
        }
        break;
      case 0x7f:
        cVar22 = *(int *)(lVar21 + 0x1bcc8 + param_1) != 0;
      }
      if (cVar22 != '\0') {
switchD_140037093_caseD_34:
        uVar19 = (ulonglong)((uVar20 & 0x3ff) >> 5);
        uVar17 = *(uint *)(param_1 + 0x1bc48 + uVar19 * 4);
        if ((uVar17 >> (uVar20 & 0x1f) & 1) != 0) {
          *(uint *)(param_1 + 0x1bc48 + uVar19 * 4) = uVar17 & ~(1 << (uVar20 & 0x1f));
          piVar1 = (int *)(param_1 + 0x1bc88);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 0) {
            *(undefined4 *)(param_1 + 0x1bc88) = 0;
          }
        }
      }
    }
switchD_140037093_caseD_d:
    uVar19 = (ulonglong)(ushort)(uVar20 + 1);
    if (0x1ff < (short)(uVar20 + 1)) {
      *(int *)(param_1 + 0x33704) = *(int *)(param_1 + 0x33704) + 1;
      return;
    }
  } while( true );
}

