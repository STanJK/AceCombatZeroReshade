/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001a2a0; RVA 0x1a2a0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14001a2a0(int *param_1,undefined4 param_2,longlong param_3,undefined8 *param_4,
                  float *param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong *plVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  uint uVar11;
  byte bVar12;
  ushort uVar13;
  ushort uVar14;
  undefined1 uVar15;
  
  plVar10 = (longlong *)0x0;
  uVar15 = 0;
  bVar12 = *(byte *)(param_3 + 0x1f0) & 1;
  uVar14 = 0;
  if (*(longlong *)(param_3 + 0x3d0) == 0) {
    uVar14 = 3;
LAB_14001a323:
    uVar15 = 3;
  }
  else if ((((*(uint *)(param_3 + 0x3c4) ^ *(uint *)(param_3 + 0x1f0)) & 0x80003) == 0) &&
          ((*(byte *)(param_3 + 0x200) & 1) == 0)) {
    if (bVar12 == 0) {
      return;
    }
  }
  else if (*(int *)(param_3 + 0x408) < 100) {
    uVar14 = 2;
    *(int *)(param_3 + 0x408) = *(int *)(param_3 + 0x408) + 1;
    goto LAB_14001a323;
  }
  bVar1 = *(byte *)(**(longlong **)(param_3 + 0x388) + 0x15d);
  if ((bVar1 == 0) || (bVar1 == 2)) {
    uVar7 = param_1[3];
  }
  else {
    iVar8 = (int)((float)((uint)(param_5[2] - *(float *)(param_3 + 0x260)) & _DAT_1402d3760) +
                 (float)((uint)(*param_5 - *(float *)(param_3 + 600)) & _DAT_1402d3760)) >> 0xf;
    if (9 < iVar8) {
      iVar8 = 9;
    }
    iVar6 = 0;
    if ((*(byte *)(param_3 + 500) & 0x80) == 0) {
      iVar6 = iVar8;
    }
    uVar7 = iVar6 + param_1[2];
    if (bVar12 == 0) goto LAB_14001a3e7;
    bVar12 = *(byte *)(*(longlong *)*param_4 + 0x120) & 1;
  }
  if ((bVar12 != 0) &&
     (((uint)*(ushort *)(param_3 + 0x228) + *param_1 & (1 << (uVar7 & 0x1f)) - 1U) == 1)) {
    uVar14 = uVar14 | 2;
  }
LAB_14001a3e7:
  if (*(char *)(param_3 + 0x40c) != '\0') {
    uVar15 = 3;
  }
  uVar13 = uVar14 | 2;
  if (*(char *)(param_3 + 0x40c) == '\0') {
    uVar13 = uVar14;
  }
  if ((uVar13 & 2) != 0) {
    if (((bVar1 & 0xfd) == 0) && (*(char *)(param_3 + 0x235) == '\0')) {
      uVar13 = uVar13 | 0x10;
    }
    if ((*(longlong *)(param_3 + 0x368) != 0) &&
       (*(char *)(*(longlong *)(param_3 + 0x368) + 0x230) != '\0')) {
      uVar13 = uVar13 | 8;
    }
  }
  if (*(char *)(param_3 + 0x40d) != '\0') {
    plVar5 = (longlong *)(param_1 + 0xa4);
    plVar9 = (longlong *)*plVar5;
    if (plVar9 != plVar5) {
      do {
        if ((*(char *)((longlong)plVar9 + 0x66) == *(char *)(param_3 + 0x234)) &&
           (*(char *)((longlong)plVar9 + 0x67) == *(char *)(param_3 + 0x235))) {
          uVar13 = uVar13 | 6;
          plVar10 = plVar9;
          break;
        }
        plVar9 = (longlong *)*plVar9;
      } while (plVar9 != plVar5);
    }
  }
  if (uVar13 != 0) {
    uVar14 = uVar13 & 1;
    uVar7 = uVar14 + 1;
    if ((uVar13 & 2) == 0) {
      uVar7 = (uint)uVar14;
    }
    uVar11 = uVar7 + 1;
    if ((uVar13 & 4) == 0) {
      uVar11 = uVar7;
    }
    uVar7 = uVar11 + 1;
    if ((uVar13 & 8) == 0) {
      uVar7 = uVar11;
    }
    uVar11 = uVar7 + 1;
    if ((uVar13 & 0x10) == 0) {
      uVar11 = uVar7;
    }
    uVar11 = uVar11 + 2;
    uVar7 = param_1[0x84];
    while (uVar7 < uVar11) {
      iVar8 = FUN_14001a0c0(param_1);
      if (iVar8 == 0) {
        if ((uint)param_1[0x84] < uVar11) {
          param_1[2] = param_1[2] + 1;
          if (0x10 < (uint)param_1[2]) {
            param_1[2] = 0x10;
          }
          param_1[3] = param_1[3] + 1;
          if (0x10 < (uint)param_1[3]) {
            param_1[3] = 0x10;
          }
          *(undefined8 *)(param_1 + 0xc6) = *(undefined8 *)(param_1 + 8);
          FUN_14001a0c0(param_1);
          uVar7 = param_1[0x84];
          while ((uVar7 < uVar11 && (iVar8 = FUN_14001a0c0(param_1), iVar8 != 0))) {
            uVar7 = param_1[0x84];
          }
        }
        break;
      }
      uVar7 = param_1[0x84];
    }
    if (uVar14 != 0) {
      FUN_14001adc0(param_1,param_2,param_3,param_4,uVar15);
    }
    if ((uVar13 & 2) != 0) {
      FUN_14001aac0(param_1,param_2,param_3,param_4,uVar15);
    }
    if ((uVar13 & 4) != 0) {
      while (plVar5 = plVar10, plVar5 != (longlong *)(param_1 + 0xa4)) {
        plVar10 = (longlong *)*plVar5;
        if ((*(char *)((longlong)plVar5 + 0x66) == *(char *)(param_3 + 0x234)) &&
           (*(char *)((longlong)plVar5 + 0x67) == *(char *)(param_3 + 0x235))) {
          puVar3 = (undefined8 *)plVar5[1];
          *puVar3 = plVar10;
          plVar10[1] = (longlong)puVar3;
          *plVar5 = (longlong)plVar5;
          plVar5[1] = (longlong)plVar5;
          param_1[0xc0] = param_1[0xc0] + -1;
          *(undefined4 *)(plVar5 + 0xc) = param_2;
          *(undefined1 *)(plVar5 + 0xd) = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
          *(undefined1 *)((longlong)plVar5 + 0x6a) = uVar15;
          lVar4 = *(longlong *)(param_3 + 0x3d8);
          if (lVar4 == 0) {
            plVar5[3] = 0;
          }
          else {
            plVar5[3] = lVar4;
            *(longlong **)(lVar4 + 0x10) = plVar5;
          }
          plVar5[2] = 0;
          *(longlong **)(param_3 + 0x3d8) = plVar5;
          puVar3 = *(undefined8 **)(param_1 + 10);
          *puVar3 = plVar5;
          *(longlong **)(param_1 + 10) = plVar5;
          *plVar5 = (longlong)(param_1 + 8);
          plVar5[1] = (longlong)puVar3;
          param_1[0x24] = param_1[0x24] + 1;
        }
      }
    }
    if (((uVar13 & 8) != 0) &&
       (plVar10 = *(longlong **)(param_1 + 0x6a), plVar10 != (longlong *)(param_1 + 0x68))) {
      plVar5 = (longlong *)plVar10[1];
      lVar4 = *plVar10;
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      *plVar10 = (longlong)plVar10;
      plVar10[1] = (longlong)plVar10;
      param_1[0x84] = param_1[0x84] + -1;
      uVar2 = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
      *(undefined4 *)(plVar10 + 0xc) = param_2;
      *(undefined2 *)((longlong)plVar10 + 100) = *(undefined2 *)(param_3 + 0x228);
      *(undefined1 *)((longlong)plVar10 + 0x66) = *(undefined1 *)(param_3 + 0x234);
      *(undefined1 *)((longlong)plVar10 + 0x67) = *(undefined1 *)(param_3 + 0x235);
      *(undefined1 *)(plVar10 + 0xd) = uVar2;
      *(undefined1 *)((longlong)plVar10 + 0x69) = 0;
      *(undefined1 *)((longlong)plVar10 + 0x6a) = uVar15;
      *(undefined1 *)((longlong)plVar10 + 0x6b) = 5;
      *(undefined4 *)(plVar10 + 4) = *(undefined4 *)(*(longlong *)(param_3 + 0x368) + 0x278);
      *(undefined4 *)((longlong)plVar10 + 0x24) =
           *(undefined4 *)(*(longlong *)(param_3 + 0x368) + 0x27c);
      *(undefined4 *)(plVar10 + 5) = *(undefined4 *)(*(longlong *)(param_3 + 0x368) + 0x280);
      *(undefined4 *)((longlong)plVar10 + 0x2c) =
           *(undefined4 *)(*(longlong *)(param_3 + 0x368) + 0x288);
      *(undefined4 *)(plVar10 + 6) = *(undefined4 *)(*(longlong *)(param_3 + 0x368) + 0x28c);
      *(undefined4 *)((longlong)plVar10 + 0x34) =
           *(undefined4 *)(*(longlong *)(param_3 + 0x368) + 0x290);
      lVar4 = *(longlong *)(param_3 + 0x3d8);
      if (lVar4 == 0) {
        plVar10[3] = 0;
      }
      else {
        plVar10[3] = lVar4;
        *(longlong **)(lVar4 + 0x10) = plVar10;
      }
      plVar10[2] = 0;
      *(longlong **)(param_3 + 0x3d8) = plVar10;
      puVar3 = *(undefined8 **)(param_1 + 10);
      *puVar3 = plVar10;
      *(longlong **)(param_1 + 10) = plVar10;
      *plVar10 = (longlong)(param_1 + 8);
      plVar10[1] = (longlong)puVar3;
      param_1[0x24] = param_1[0x24] + 1;
    }
    if ((uVar13 & 0x10) != 0) {
      FUN_14001b010(param_1,param_2,param_3,param_4,uVar15);
    }
  }
  *(undefined2 *)(param_3 + 0x40c) = 0;
  return;
}

