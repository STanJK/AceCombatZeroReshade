/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140141200; RVA 0x141200
 * Ghidra-generated research pseudocode, inferred types, not original source. */

int FUN_140141200(longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined4 param_4,
                 byte param_5,byte param_6,undefined1 param_7,undefined1 param_8,longlong param_9,
                 byte param_10)

{
  uint *puVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  undefined8 *puVar6;
  char cVar7;
  int iVar8;
  undefined4 *puVar9;
  longlong *plVar10;
  byte bVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong lVar14;
  char cVar15;
  undefined8 in_R9;
  longlong lVar16;
  char cVar17;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  cVar3 = DAT_14033bd60;
  plVar10 = *(longlong **)(param_1 + 0x1da30 + (ulonglong)param_10 * 8);
  if (plVar10 == (longlong *)0x0) {
    iVar8 = 0;
  }
  else {
    local_48 = *param_2;
    uStack_40 = param_2[1];
    local_58 = *param_3;
    uStack_50 = param_3[1];
    iVar8 = (**(code **)(*plVar10 + 0x38))
                      (plVar10,&local_48,&local_58,in_R9,param_5,param_6,param_7,param_8,param_9);
    if (((cVar3 == '\0') && (iVar8 != -1)) && (param_10 != 0x1f)) {
      puVar9 = (undefined4 *)FUN_140019ef0();
      plVar10 = (longlong *)FUN_14001b280(puVar9);
      if (plVar10 != (longlong *)0x0) {
        lVar16 = (ulonglong)param_6 * 0x520;
        lVar14 = *(longlong *)
                  (*(longlong *)(*(longlong *)(puVar9 + 0x10a) + 0x697b8) + (ulonglong)param_5 * 8);
        lVar12 = *(longlong *)(lVar14 + 0x110);
        uVar2 = *(undefined1 *)(lVar14 + 0x15d);
        *(undefined4 *)(plVar10 + 0xc) = *puVar9;
        *(undefined2 *)((longlong)plVar10 + 100) = *(undefined2 *)(lVar16 + 0x228 + lVar12);
        *(undefined1 *)((longlong)plVar10 + 0x66) = *(undefined1 *)(lVar16 + 0x234 + lVar12);
        *(undefined1 *)((longlong)plVar10 + 0x67) = *(undefined1 *)(lVar16 + 0x235 + lVar12);
        *(undefined4 *)((longlong)plVar10 + 0x34) = *(undefined4 *)param_2;
        *(undefined4 *)(plVar10 + 7) = *(undefined4 *)((longlong)param_2 + 4);
        *(undefined4 *)((longlong)plVar10 + 0x3c) = *(undefined4 *)(param_2 + 1);
        *(undefined4 *)(plVar10 + 8) = *(undefined4 *)param_3;
        *(undefined4 *)((longlong)plVar10 + 0x44) = *(undefined4 *)((longlong)param_3 + 4);
        *(undefined4 *)(plVar10 + 9) = *(undefined4 *)(param_3 + 1);
        *(undefined1 *)((longlong)plVar10 + 0x22) = param_7;
        *(undefined1 *)((longlong)plVar10 + 0x23) = param_8;
        plVar10[5] = param_9;
        *(undefined4 *)((longlong)plVar10 + 0x4c) = param_4;
        *(undefined1 *)(plVar10 + 0xd) = uVar2;
        *(undefined2 *)((longlong)plVar10 + 0x69) = 0;
        *(undefined1 *)((longlong)plVar10 + 0x6b) = 2;
        *(undefined2 *)(plVar10 + 4) = 1;
        *(byte *)(plVar10 + 10) = param_10;
        *(int *)(plVar10 + 6) = iVar8;
        puVar6 = *(undefined8 **)(puVar9 + 0x28);
        *puVar6 = plVar10;
        *(longlong **)(puVar9 + 0x28) = plVar10;
        *plVar10 = (longlong)(puVar9 + 0x26);
        plVar10[1] = (longlong)puVar6;
        puVar9[0x42] = puVar9[0x42] + 1;
      }
    }
    if (*(char *)((ulonglong)*(byte *)(param_1 + 0x1da20) + 0x1db44 + param_1) != '\0') {
      lVar12 = (ulonglong)param_6 * 0x520;
      lVar14 = *(longlong *)
                (*(longlong *)(**(longlong **)(param_1 + 8) + (ulonglong)param_5 * 8) + 0x110);
      cVar3 = *(char *)(**(longlong **)(lVar14 + 0x388 + lVar12) + 0x15d);
      if (((cVar3 == '\0') || (cVar3 == '\x02')) &&
         ((*(char *)(lVar14 + 0x235 + lVar12) == '\0' && (-1 < iVar8)))) {
        cVar3 = *(char *)(*(longlong *)(*(longlong *)(lVar14 + 0x1b8 + lVar12) + 0xfd8) + 0xe);
        bVar11 = 1;
        do {
          uVar13 = (ulonglong)bVar11;
          if (*(int *)(param_1 + 0x1d998 + uVar13 * 4) == -1) {
            *(int *)(param_1 + 0x1d998 + uVar13 * 4) = iVar8;
            *(undefined4 *)(param_1 + 0x1d9dc + uVar13 * 4) = *(undefined4 *)(param_1 + 0x1d9dc);
            *(uint *)(param_1 + 0x1d9dc) = (uint)bVar11;
            break;
          }
          bVar11 = bVar11 + 1;
        } while ((char)bVar11 < '\x10');
        cVar15 = '\0';
        cVar4 = *(char *)(param_1 + 0x1d9dc);
        cVar7 = '\0';
        while (cVar17 = cVar4, cVar17 != -1) {
          lVar14 = (longlong)cVar17;
          cVar4 = *(char *)(param_1 + 0x1d9dc + lVar14 * 4);
          if ((char)(cVar3 * '\x02') <= cVar15) {
            uVar5 = *(uint *)(param_1 + 0x1d998 + lVar14 * 4);
            if (-1 < (int)uVar5) {
              puVar1 = (uint *)(*(longlong *)
                                 (param_1 + 0x1da30 + (ulonglong)*(byte *)(param_1 + 0x1da20) * 8) +
                               0x5c);
              *puVar1 = *puVar1 & ~(1 << (uVar5 & 0x1f));
              *(undefined4 *)(param_1 + 0x1d998 + lVar14 * 4) = 0xffffffff;
            }
            *(undefined4 *)(param_1 + 0x1d9dc + (longlong)cVar7 * 4) =
                 *(undefined4 *)(param_1 + 0x1d9dc + lVar14 * 4);
            cVar17 = cVar7;
          }
          cVar15 = cVar15 + '\x01';
          cVar7 = cVar17;
        }
      }
    }
  }
  return iVar8;
}

