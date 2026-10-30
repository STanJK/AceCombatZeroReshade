/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140187a40; RVA 0x187a40
 * Ghidra-generated research pseudocode, inferred types, not original source. */

ulonglong FUN_140187a40(longlong param_1,byte param_2,byte param_3)

{
  longlong lVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong in_RAX;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  
  uVar7 = (ulonglong)param_2;
  if (*(char *)(uVar7 + 0x2b6 + param_1) == -1) goto LAB_140187aad;
  lVar4 = *(longlong *)(param_1 + uVar7 * 8);
  lVar10 = ((longlong)*(char *)(lVar4 + 0x2e) + uVar7 * 4) * 0x2a;
  lVar1 = lVar10 + (ulonglong)param_3;
  bVar2 = *(byte *)(lVar1 + 0x160 + param_1);
  if (bVar2 == 1) {
    cVar3 = *(char *)(lVar1 + 0x10 + param_1);
    uVar5 = (uint)cVar3;
    in_RAX = (ulonglong)uVar5;
    if (cVar3 == -1) goto LAB_140187aad;
    uVar8 = (int)uVar5 >> 0x1f & 0x1f;
    uVar5 = uVar5 + uVar8;
    uVar8 = (uVar5 & 0x1f) - uVar8;
    uVar5 = *(uint *)(lVar4 + 0x38 + (longlong)((int)uVar5 >> 5) * 4) >> (uVar8 & 0x1f);
  }
  else {
    in_RAX = lVar10 + (ulonglong)param_3;
    cVar3 = *(char *)(in_RAX + 0x161 + param_1);
    if (cVar3 == '\x01') {
      iVar9 = 0;
      if (bVar2 != 0) {
        while( true ) {
          cVar3 = *(char *)((int)((uint)param_3 + iVar9) + lVar10 + 0x10 + param_1);
          uVar5 = (uint)cVar3;
          in_RAX = (ulonglong)uVar5;
          if (cVar3 == -1) break;
          uVar8 = uVar5 & 0x1f;
          if ((int)uVar5 < 0) {
            uVar5 = uVar5 + 0x1f;
            uVar8 = uVar8 - 0x20;
          }
          uVar5 = *(uint *)(lVar4 + 0x38 + (longlong)((int)uVar5 >> 5) * 4);
          in_RAX = (ulonglong)uVar5;
          if ((uVar5 >> (uVar8 & 0x1f) & 1) == 0) break;
          iVar9 = iVar9 + 1;
          if ((int)(uint)bVar2 <= iVar9) {
            return CONCAT71((uint7)(uint3)(uVar5 >> 8),1);
          }
        }
        goto LAB_140187aad;
      }
      goto LAB_140187c4e;
    }
    uVar5 = (uint)bVar2;
    if (cVar3 == '\x02') {
      iVar9 = 0;
      if (uVar5 != 0) {
        while( true ) {
          cVar3 = *(char *)((int)((uint)param_3 + iVar9) + lVar10 + 0x10 + param_1);
          uVar8 = (uint)cVar3;
          in_RAX = (ulonglong)uVar8;
          if (cVar3 == -1) break;
          uVar6 = uVar8 & 0x1f;
          if ((int)uVar8 < 0) {
            uVar8 = uVar8 + 0x1f;
            uVar6 = uVar6 - 0x20;
          }
          uVar8 = *(uint *)(lVar4 + 0x38 + (longlong)((int)uVar8 >> 5) * 4);
          in_RAX = (ulonglong)uVar8;
          if ((uVar8 >> (uVar6 & 0x1f) & 1) != 0) goto LAB_140187c4e;
          iVar9 = iVar9 + 1;
          if ((int)uVar5 <= iVar9) {
            return (ulonglong)(uint3)(uVar8 >> 8) << 8;
          }
        }
      }
      goto LAB_140187aad;
    }
    if (cVar3 != '\x03') goto LAB_140187aad;
    iVar9 = 1;
    if (1 < uVar5) {
      do {
        cVar3 = *(char *)((int)((uint)param_3 + iVar9) + lVar10 + 0x10 + param_1);
        uVar8 = (uint)cVar3;
        in_RAX = (ulonglong)uVar8;
        if (cVar3 == -1) goto LAB_140187aad;
        uVar6 = uVar8 & 0x1f;
        if ((int)uVar8 < 0) {
          uVar8 = uVar8 + 0x1f;
          uVar6 = uVar6 - 0x20;
        }
        uVar8 = *(uint *)(lVar4 + 0x38 + (longlong)((int)uVar8 >> 5) * 4);
        in_RAX = (ulonglong)uVar8;
        if ((uVar8 >> (uVar6 & 0x1f) & 1) != 0) goto LAB_140187aad;
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)uVar5);
    }
    cVar3 = *(char *)(lVar1 + 0x10 + param_1);
    uVar5 = (uint)cVar3;
    in_RAX = (ulonglong)uVar5;
    if (cVar3 == -1) goto LAB_140187aad;
    uVar8 = (int)uVar5 >> 0x1f & 0x1f;
    uVar5 = uVar5 + uVar8;
    uVar8 = (uVar5 & 0x1f) - uVar8;
    uVar5 = *(uint *)(lVar4 + 0x38 + (longlong)((int)uVar5 >> 5) * 4) >> (uVar8 & 0x1f);
  }
  in_RAX = (ulonglong)uVar8;
  if ((uVar5 & 1) == 0) {
LAB_140187aad:
    return in_RAX & 0xffffffffffffff00;
  }
LAB_140187c4e:
  return CONCAT71((int7)(in_RAX >> 8),1);
}

