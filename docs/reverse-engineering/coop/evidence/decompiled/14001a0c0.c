/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001a0c0; RVA 0x1a0c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

int FUN_14001a0c0(int *param_1)

{
  longlong *plVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  uint uVar8;
  int iVar9;
  longlong *plVar10;
  uint uVar11;
  char cVar12;
  uint uVar13;
  longlong *plVar14;
  int iVar15;
  
  plVar14 = *(longlong **)(param_1 + 0xc6);
  plVar1 = (longlong *)(param_1 + 8);
  if (plVar14 == (longlong *)0x0) {
    if (param_1[0x24] == 0) {
      return 0;
    }
    plVar14 = (longlong *)*plVar1;
    *(longlong **)(param_1 + 0xc6) = plVar14;
  }
  uVar13 = param_1[2] + 1;
  if (0x10 < (int)uVar13) {
    uVar13 = 0x10;
  }
  iVar3 = *param_1;
  uVar11 = param_1[3] + 1;
  if (0x10 < (int)uVar11) {
    uVar11 = 0x10;
  }
  iVar15 = 0;
  if (plVar14 != plVar1) {
    iVar9 = (int)plVar14[0xc];
    plVar6 = (longlong *)*plVar14;
    while (plVar10 = plVar6, iVar9 < iVar3 + -0x438) {
      bVar2 = *(byte *)((longlong)plVar14 + 0x6b);
      if (bVar2 == 0) {
        cVar12 = *(char *)((longlong)plVar14 + 0x5e);
      }
      else if (bVar2 == 1) {
        cVar12 = *(char *)((longlong)plVar14 + 0x2e);
      }
      else {
        cVar12 = (char)plVar14[0xd];
      }
      if (cVar12 == '\0') {
LAB_14001a1a2:
        uVar8 = uVar11;
      }
      else {
        if (bVar2 == 0) {
          cVar12 = *(char *)((longlong)plVar14 + 0x5e);
        }
        else if (bVar2 == 1) {
          cVar12 = *(char *)((longlong)plVar14 + 0x2e);
        }
        else {
          cVar12 = (char)plVar14[0xd];
        }
        uVar8 = uVar13;
        if (cVar12 == '\x02') goto LAB_14001a1a2;
      }
      if (((((bVar2 & 0xfa) == 0) && (bVar2 != 1)) &&
          ((*(byte *)((longlong)plVar14 + 0x6a) & 1) == 0)) &&
         (((uint)*(ushort *)((longlong)plVar14 + 100) + iVar9 & (1 << (uVar8 & 0x1f)) - 1U) != 1)) {
        lVar4 = plVar14[2];
        for (lVar5 = lVar4; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x10)) {
          if (*(char *)(lVar5 + 0x6b) == '\0') {
            lVar5 = plVar14[3];
            *(longlong *)(lVar5 + 0x10) = lVar4;
            *(longlong *)(lVar4 + 0x18) = lVar5;
            plVar14 = *(longlong **)(param_1 + 0xc6);
            if (plVar14 != plVar1) {
              plVar6 = (longlong *)plVar14[1];
              lVar4 = *plVar14;
              *plVar6 = lVar4;
              *(longlong **)(lVar4 + 8) = plVar6;
              *plVar14 = (longlong)plVar14;
              plVar14[1] = (longlong)plVar14;
              param_1[0x24] = param_1[0x24] + -1;
            }
            plVar14 = *(longlong **)(param_1 + 0xc6);
            puVar7 = *(undefined8 **)(param_1 + 0x6a);
            iVar15 = iVar15 + 1;
            *puVar7 = plVar14;
            *(longlong **)(param_1 + 0x6a) = plVar14;
            *plVar14 = (longlong)(param_1 + 0x68);
            plVar14[1] = (longlong)puVar7;
            param_1[0x84] = param_1[0x84] + 1;
            if (0x1f < iVar15) {
              *(longlong **)(param_1 + 0xc6) = plVar10;
              return iVar15;
            }
            break;
          }
        }
      }
      *(longlong **)(param_1 + 0xc6) = plVar10;
      if (plVar10 == plVar1) {
        return iVar15;
      }
      plVar6 = (longlong *)*plVar10;
      plVar14 = plVar10;
      iVar9 = (int)plVar10[0xc];
    }
  }
  return iVar15;
}

