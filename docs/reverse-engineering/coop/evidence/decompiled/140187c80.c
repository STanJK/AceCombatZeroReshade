/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140187c80; RVA 0x187c80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uchar FUN_140187c80(ulonglong arg1,uchar arg2,uchar arg3)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  
  uVar4 = (ulonglong)arg2;
  if (*(char *)(uVar4 + 0x2b6 + DAT_14032c8f0) == -1) {
    return '\0';
  }
  lVar3 = *(longlong *)(DAT_14032c8f0 + uVar4 * 8);
  lVar11 = ((longlong)*(char *)(lVar3 + 0x2e) + uVar4 * 4) * 0x2a;
  lVar10 = lVar11 + (ulonglong)arg3 + DAT_14032c8f0;
  bVar1 = *(byte *)(lVar10 + 0x160);
  if (bVar1 == 1) {
    cVar2 = *(char *)(lVar10 + 0x10);
    if (cVar2 == -1) {
      return '\0';
    }
    uVar7 = (int)cVar2 >> 0x1f & 0x1f;
    uVar5 = (int)cVar2 + uVar7;
    uVar5 = *(uint *)(lVar3 + 0x40 + (longlong)((int)uVar5 >> 5) * 4) >>
            ((uVar5 & 0x1f) - uVar7 & 0x1f);
  }
  else {
    cVar2 = *(char *)(lVar11 + (ulonglong)arg3 + 0x161 + DAT_14032c8f0);
    uVar5 = (uint)arg3;
    if (cVar2 == '\x01') {
      uVar8 = (int)*(char *)(lVar10 + 0x10) >> 0x1f & 0x1f;
      uVar7 = (int)*(char *)(lVar10 + 0x10) + uVar8;
      if ((*(uint *)(lVar3 + 0x40 + (longlong)((int)uVar7 >> 5) * 4) >>
           ((uVar7 & 0x1f) - uVar8 & 0x1f) & 1) == 0) {
        return '\0';
      }
      iVar9 = 1;
      if (bVar1 < 2) {
        return '\x01';
      }
      while( true ) {
        cVar2 = *(char *)((int)(uVar5 + iVar9) + lVar11 + 0x10 + DAT_14032c8f0);
        uVar7 = (uint)cVar2;
        if (cVar2 == -1) {
          return '\0';
        }
        uVar8 = uVar7 & 0x1f;
        if ((int)uVar7 < 0) {
          uVar7 = uVar7 + 0x1f;
          uVar8 = uVar8 - 0x20;
        }
        if ((*(uint *)(lVar3 + 0x38 + (longlong)((int)uVar7 >> 5) * 4) >> (uVar8 & 0x1f) & 1) == 0)
        break;
        iVar9 = iVar9 + 1;
        if ((int)(uint)bVar1 <= iVar9) {
          return '\x01';
        }
      }
      return '\0';
    }
    uVar7 = (uint)bVar1;
    if (cVar2 == '\x02') {
      iVar9 = 0;
      if (uVar7 == 0) {
        return '\0';
      }
      while( true ) {
        cVar2 = *(char *)((int)(uVar5 + iVar9) + lVar11 + 0x10 + DAT_14032c8f0);
        uVar8 = (uint)cVar2;
        if (cVar2 == -1) {
          return '\0';
        }
        uVar6 = uVar8 & 0x1f;
        if ((int)uVar8 < 0) {
          uVar8 = uVar8 + 0x1f;
          uVar6 = uVar6 - 0x20;
        }
        if ((*(uint *)(lVar3 + 0x40 + (longlong)((int)uVar8 >> 5) * 4) >> (uVar6 & 0x1f) & 1) != 0)
        break;
        iVar9 = iVar9 + 1;
        if ((int)uVar7 <= iVar9) {
          return '\0';
        }
      }
      return '\x01';
    }
    if (cVar2 != '\x03') {
      return '\0';
    }
    iVar9 = 1;
    if (1 < uVar7) {
      do {
        cVar2 = *(char *)((int)(uVar5 + iVar9) + lVar11 + 0x10 + DAT_14032c8f0);
        uVar8 = (uint)cVar2;
        if (cVar2 == -1) {
          return '\0';
        }
        uVar6 = uVar8 & 0x1f;
        if ((int)uVar8 < 0) {
          uVar8 = uVar8 + 0x1f;
          uVar6 = uVar6 - 0x20;
        }
        if ((*(uint *)(lVar3 + 0x38 + (longlong)((int)uVar8 >> 5) * 4) >> (uVar6 & 0x1f) & 1) != 0)
        {
          return '\0';
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)uVar7);
    }
    cVar2 = *(char *)(lVar10 + 0x10);
    if (cVar2 == -1) {
      return '\0';
    }
    uVar7 = (int)cVar2 >> 0x1f & 0x1f;
    uVar5 = (int)cVar2 + uVar7;
    uVar5 = *(uint *)(lVar3 + 0x40 + (longlong)((int)uVar5 >> 5) * 4) >>
            ((uVar5 & 0x1f) - uVar7 & 0x1f);
  }
  if ((uVar5 & 1) == 0) {
    return '\0';
  }
  return '\x01';
}

