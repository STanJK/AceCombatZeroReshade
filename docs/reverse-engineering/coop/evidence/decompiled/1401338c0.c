/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401338c0; RVA 0x1338c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401338c0(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  byte bVar10;
  int iVar11;
  longlong lVar12;
  char cVar13;
  int iVar14;
  ulonglong uVar15;
  uint *puVar16;
  longlong local_res8;
  
  if ((*(byte *)(param_1 + 0x120) & 4) == 0) {
    lVar12 = 0;
    cVar13 = '\0';
    uVar15 = (ulonglong)*(byte *)((longlong)*(longlong **)(param_1 + 0x140) + 0x34);
    if (uVar15 != 0) {
      do {
        lVar3 = *(longlong *)(**(longlong **)(param_1 + 0x140) + lVar12 * 8);
        if (((((((*(uint *)(lVar3 + 0x120) & 2) == 0) && ((*(uint *)(lVar3 + 0x120) & 4) == 0)) &&
              (*(char *)(lVar3 + 0x15c) != *(char *)(param_1 + 0x15c))) &&
             ((bVar10 = *(byte *)(lVar3 + 0x15d), bVar10 != 3 &&
              (bVar1 = *(byte *)(param_1 + 0x15d), bVar10 != bVar1)))) &&
            ((((bVar10 & 0xfd) != 0 && (bVar10 != 1)) || (((bVar1 & 0xfd) != 0 && (bVar1 != 1))))))
           && (fVar4 = *(float *)(lVar3 + 8) - *(float *)(param_1 + 8),
              fVar5 = *(float *)(lVar3 + 0xc) - *(float *)(param_1 + 0xc),
              fVar6 = *(float *)(lVar3 + 0x10) - *(float *)(param_1 + 0x10),
              fVar7 = *(float *)(lVar3 + 0x14) - *(float *)(param_1 + 0x14),
              fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4 <= DAT_1402d2c14)) {
          cVar13 = cVar13 + *(char *)(lVar3 + 0x15e);
        }
        lVar12 = lVar12 + 1;
      } while (lVar12 < (longlong)uVar15);
      if (cVar13 != '\0') {
        puVar8 = operator_new((longlong)*(int *)(param_1 + 0x118));
        iVar14 = *(int *)(param_1 + 0x118);
        iVar11 = 0;
        uVar15 = 0xff;
        if (0 < iVar14) {
          puVar9 = puVar8;
          do {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
            iVar14 = *(int *)(param_1 + 0x118);
            iVar11 = iVar11 + 1;
          } while (iVar11 < iVar14);
        }
        iVar11 = 0;
        if (0 < iVar14) {
          puVar16 = (uint *)(*(longlong *)(param_1 + 0x110) + 0x1f0);
          do {
            uVar2 = *puVar16;
            puVar16 = puVar16 + 0x148;
            bVar10 = (byte)iVar11;
            if ((uVar2 & 0x10002) != 2) {
              bVar10 = (byte)uVar15;
            }
            iVar11 = iVar11 + 1;
            uVar15 = (ulonglong)bVar10;
          } while (iVar11 < iVar14);
          if (bVar10 != 0xff) {
            local_res8 = **(longlong **)(param_1 + 0x140) +
                         (ulonglong)*(byte *)(param_1 + 0x15c) * 8;
            FUN_140118040(uVar15 * 0x520 + *(longlong *)(param_1 + 0x110),&local_res8,puVar8,cVar13,
                          5,0,3);
          }
        }
        thunk_FUN_1402500f0(puVar8);
      }
    }
  }
  return;
}

