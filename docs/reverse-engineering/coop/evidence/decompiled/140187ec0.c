/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140187ec0; RVA 0x187ec0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ulonglong FUN_140187ec0(undefined8 param_1,byte param_2,byte param_3)

{
  byte bVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  longlong lVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  undefined1 auVar14 [64];
  
  lVar4 = DAT_14032c8f0;
  uVar11 = (ulonglong)param_2;
  uVar10 = 0;
  auVar14 = ZEXT864(0);
  if (*(char *)(uVar11 + 0x2b6 + DAT_14032c8f0) != -1) {
    lVar2 = *(longlong *)(DAT_14032c8f0 + uVar11 * 8);
    lVar12 = ((ulonglong)*(byte *)(lVar2 + 0x2e) + uVar11 * 4) * 0x2a;
    lVar13 = (ulonglong)param_3 + lVar12;
    bVar1 = *(byte *)(lVar13 + 0x160 + DAT_14032c8f0);
    if (bVar1 == 1) {
      cVar5 = *(char *)(lVar13 + 0x10 + DAT_14032c8f0);
      if (cVar5 != -1) {
        return (ulonglong)(uint)((float)*(byte *)(cVar5 + lVar2) * DAT_1402d1e98);
      }
    }
    else {
      cVar5 = *(char *)(lVar12 + (ulonglong)param_3 + 0x161 + DAT_14032c8f0);
      uVar7 = (uint)bVar1;
      if (cVar5 == '\x01') {
        iVar9 = 1;
        if (1 < uVar7) {
          do {
            cVar5 = FUN_140187a40(lVar4,uVar11,
                                  *(undefined1 *)
                                   ((int)((uint)param_3 + iVar9) + lVar12 + 0x10 + lVar4));
            if (cVar5 == '\0') {
              return auVar14._0_8_;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)bVar1);
        }
        return (ulonglong)
               (uint)((float)*(byte *)(*(char *)(lVar13 + 0x10 + lVar4) + lVar2) * DAT_1402d1e98);
      }
      if (cVar5 == '\x02') {
        iVar9 = 0;
        if (bVar1 < 4) {
          if (bVar1 == 0) {
            return 0;
          }
        }
        else {
          pcVar8 = (char *)((ulonglong)param_3 + lVar12 + 0x11 + DAT_14032c8f0);
          uVar6 = (uVar7 - 4 >> 2) + 1;
          uVar10 = (ulonglong)uVar6;
          iVar9 = uVar6 * 4;
          do {
            if (pcVar8[-1] != -1) {
              auVar3 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(pcVar8[-1] + lVar2) *
                                                DAT_1402d1e98)),auVar14._0_16_);
              auVar14 = ZEXT1664(auVar3);
            }
            if (*pcVar8 != -1) {
              auVar3 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(*pcVar8 + lVar2) * DAT_1402d1e98))
                                  ,auVar14._0_16_);
              auVar14 = ZEXT1664(auVar3);
            }
            if (pcVar8[1] != -1) {
              auVar3 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(pcVar8[1] + lVar2) * DAT_1402d1e98
                                                )),auVar14._0_16_);
              auVar14 = ZEXT1664(auVar3);
            }
            if (pcVar8[2] != -1) {
              auVar3 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(pcVar8[2] + lVar2) * DAT_1402d1e98
                                                )),auVar14._0_16_);
              auVar14 = ZEXT1664(auVar3);
            }
            pcVar8 = pcVar8 + 4;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
          if ((int)uVar7 <= iVar9) {
            return auVar14._0_8_;
          }
        }
        uVar11 = (ulonglong)(uVar7 - iVar9);
        pcVar8 = (char *)((int)((uint)param_3 + iVar9) + lVar12 + 0x10 + DAT_14032c8f0);
        do {
          if (*pcVar8 != -1) {
            auVar3 = vmaxss_avx(ZEXT416((uint)((float)*(byte *)(*pcVar8 + lVar2) * DAT_1402d1e98)),
                                auVar14._0_16_);
            auVar14 = ZEXT1664(auVar3);
          }
          uVar10 = auVar14._0_8_;
          pcVar8 = pcVar8 + 1;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      else if (cVar5 == '\x03') {
        iVar9 = 1;
        if (1 < bVar1) {
          do {
            cVar5 = *(char *)((int)((uint)param_3 + iVar9) + lVar12 + 0x10 + DAT_14032c8f0);
            if ((cVar5 != -1) && (0.0 < (float)*(byte *)(cVar5 + lVar2) * DAT_1402d1e98)) {
              return 0;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar7);
        }
        cVar5 = *(char *)(lVar13 + 0x10 + DAT_14032c8f0);
        if (cVar5 != -1) {
          return (ulonglong)(uint)((float)*(byte *)(cVar5 + lVar2) * DAT_1402d1e98);
        }
      }
    }
  }
  return uVar10;
}

