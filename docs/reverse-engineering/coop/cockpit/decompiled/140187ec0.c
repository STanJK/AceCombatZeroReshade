/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140187ec0; RVA 0x187ec0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float FUN_140187ec0(ulonglong context_or_unused,uchar logical_slot,uchar action)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  uchar uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong lVar13;
  float fVar14;
  undefined1 auVar15 [64];
  
  uVar10 = DAT_14032c8f0;
  uVar12 = (ulonglong)logical_slot;
  fVar14 = 0.0;
  auVar15 = ZEXT864(0);
  if (*(char *)(uVar12 + 0x2b6 + DAT_14032c8f0) != -1) {
    lVar3 = *(longlong *)(DAT_14032c8f0 + uVar12 * 8);
    lVar11 = ((ulonglong)*(byte *)(lVar3 + 0x2e) + uVar12 * 4) * 0x2a;
    lVar13 = (ulonglong)action + lVar11;
    bVar1 = *(byte *)(lVar13 + 0x160 + DAT_14032c8f0);
    if (bVar1 == 1) {
      cVar2 = *(char *)(lVar13 + 0x10 + DAT_14032c8f0);
      if (cVar2 != -1) {
        return (float)*(byte *)(cVar2 + lVar3) * DAT_1402d1e98;
      }
    }
    else {
      cVar2 = *(char *)(lVar11 + (ulonglong)action + 0x161 + DAT_14032c8f0);
      uVar7 = (uint)bVar1;
      if (cVar2 == '\x01') {
        iVar9 = 1;
        if (1 < uVar7) {
          do {
            uVar5 = FUN_140187a40(uVar10,logical_slot,
                                  *(uchar *)((int)((uint)action + iVar9) + lVar11 + 0x10 + uVar10));
            if (uVar5 == '\0') {
              return auVar15._0_4_;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)bVar1);
        }
        return (float)*(byte *)(*(char *)(lVar13 + 0x10 + uVar10) + lVar3) * DAT_1402d1e98;
      }
      if (cVar2 == '\x02') {
        iVar9 = 0;
        if (bVar1 < 4) {
          if (bVar1 == 0) {
            return 0.0;
          }
        }
        else {
          pcVar8 = (char *)((ulonglong)action + lVar11 + 0x11 + DAT_14032c8f0);
          uVar6 = (uVar7 - 4 >> 2) + 1;
          uVar10 = (ulonglong)uVar6;
          iVar9 = uVar6 * 4;
          do {
            if (pcVar8[-1] != -1) {
              auVar4 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(pcVar8[-1] + lVar3) *
                                                DAT_1402d1e98)),auVar15._0_16_);
              auVar15 = ZEXT1664(auVar4);
            }
            if (*pcVar8 != -1) {
              auVar4 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(*pcVar8 + lVar3) * DAT_1402d1e98))
                                  ,auVar15._0_16_);
              auVar15 = ZEXT1664(auVar4);
            }
            if (pcVar8[1] != -1) {
              auVar4 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(pcVar8[1] + lVar3) * DAT_1402d1e98
                                                )),auVar15._0_16_);
              auVar15 = ZEXT1664(auVar4);
            }
            if (pcVar8[2] != -1) {
              auVar4 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(pcVar8[2] + lVar3) * DAT_1402d1e98
                                                )),auVar15._0_16_);
              auVar15 = ZEXT1664(auVar4);
            }
            pcVar8 = pcVar8 + 4;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
          if ((int)uVar7 <= iVar9) {
            return auVar15._0_4_;
          }
        }
        uVar10 = (ulonglong)(uVar7 - iVar9);
        pcVar8 = (char *)((int)((uint)action + iVar9) + lVar11 + 0x10 + DAT_14032c8f0);
        do {
          if (*pcVar8 != -1) {
            auVar4 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(*pcVar8 + lVar3) * DAT_1402d1e98)),
                                auVar15._0_16_);
            auVar15 = ZEXT1664(auVar4);
          }
          fVar14 = auVar15._0_4_;
          pcVar8 = pcVar8 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      else if (cVar2 == '\x03') {
        iVar9 = 1;
        if (1 < bVar1) {
          do {
            cVar2 = *(char *)((int)((uint)action + iVar9) + lVar11 + 0x10 + DAT_14032c8f0);
            if ((cVar2 != -1) && (0.0 < (float)*(byte *)(cVar2 + lVar3) * DAT_1402d1e98)) {
              return 0.0;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar7);
        }
        cVar2 = *(char *)(lVar13 + 0x10 + DAT_14032c8f0);
        if (cVar2 != -1) {
          return (float)*(byte *)(cVar2 + lVar3) * DAT_1402d1e98;
        }
      }
    }
  }
  return fVar14;
}

