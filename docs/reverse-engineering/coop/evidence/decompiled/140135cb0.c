/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140135cb0; RVA 0x135cb0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140135cb0(longlong *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,longlong param_7)

{
  char cVar1;
  longlong *plVar2;
  byte bVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined **ppuVar12;
  undefined **ppuVar13;
  ulonglong uVar14;
  undefined8 local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  
  if ((param_2 != (undefined8 *)0x0) && ((byte *)*param_2 != (byte *)0x0)) {
    DAT_14032c918 = param_7;
    lVar4 = (ulonglong)DAT_14032c920 + param_7;
    _DAT_14032c910 = param_7;
    bVar3 = *(byte *)*param_2;
    *(byte *)((longlong)param_1 + 0x34) = bVar3;
    *param_1 = lVar4;
    *(undefined8 *)(lVar4 + (ulonglong)bVar3 * 8) = 0;
    puVar5 = (undefined8 *)(lVar4 + 8 + (ulonglong)*(byte *)((longlong)param_1 + 0x34) * 8);
    if (((ulonglong)puVar5 & 0xf) != 0) {
      puVar5 = (undefined8 *)(((ulonglong)puVar5 & 0xfffffffffffffff0) + 0x10);
    }
    iVar7 = 0;
    bVar3 = 0;
    if (*(byte *)((longlong)param_1 + 0x34) != 0) {
      do {
        uVar9 = 0;
        ppuVar13 = &PTR_FUN_1402acd80;
        ppuVar12 = &PTR_FUN_1402acda8;
        lVar4 = *(longlong *)((longlong)iVar7 * 0x20 + param_2[1]);
        if (lVar4 != 0) {
          cVar1 = *(char *)(lVar4 + 0x12);
          if (cVar1 == '\x01') {
            FUN_140135aa0(puVar5);
            *puVar5 = ppuVar13;
            puVar5[0x35] = 0;
            puVar5[0x2f] = uVar9;
            *(undefined4 *)((longlong)puVar5 + 0x184) = 0xffff;
            puVar5[0x34] = 0;
            *(int *)(puVar5 + 0x30) = (int)uVar9;
            puVar6 = puVar5 + 0x36;
          }
          else if (cVar1 == '\x02') {
            FUN_140135aa0(puVar5);
            puVar5[0x2f] = uVar9;
            *(int *)(puVar5 + 0x30) = (int)uVar9;
            *(undefined4 *)((longlong)puVar5 + 0x184) = 0xffff;
            *puVar5 = ppuVar12;
            *(undefined1 *)((longlong)puVar5 + 0x1c1) = 0;
            puVar6 = puVar5 + 0x3a;
          }
          else if (cVar1 == '\x03') {
            FUN_1402777e0(puVar5,0,0x1d0);
            FUN_140135aa0(puVar5);
            *(undefined4 *)((longlong)puVar5 + 0x184) = 0xffff;
            *(undefined1 *)((longlong)puVar5 + 0x1c1) = 0;
            *puVar5 = &PTR_FUN_1402acd58;
            puVar5[0x2f] = 0;
            *(undefined4 *)(puVar5 + 0x30) = 0;
            puVar6 = puVar5 + 0x3a;
          }
          else {
            FUN_140135aa0();
            puVar6 = puVar5 + 0x30;
          }
          *(char *)(puVar5 + 0x2c) = cVar1;
          *(undefined8 **)(*param_1 + (longlong)iVar7 * 8) = puVar5;
          *(uint *)(puVar5 + 0x23) = (uint)*(byte *)(lVar4 + 0xc);
          *(char *)((longlong)puVar5 + 0x15c) = (char)iVar7;
          local_50 = param_1[8];
          local_48 = param_1[9];
          local_40 = param_1[0xb];
          local_58 = param_3;
          puVar5 = (undefined8 *)
                   (**(code **)*puVar5)
                             (puVar5,param_2[1] + (longlong)iVar7 * 0x20,&local_58,param_4,param_5,
                              param_6,puVar6);
        }
        bVar3 = *(byte *)((longlong)param_1 + 0x34);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(uint)bVar3);
    }
    plVar2 = (longlong *)*param_1;
    if (plVar2 != plVar2 + bVar3) {
      do {
        uVar10 = 0;
        lVar4 = *plVar2;
        if (0 < *(int *)(lVar4 + 0x118)) {
          uVar14 = uVar10;
          do {
            lVar4 = *(longlong *)(lVar4 + 0x110) + uVar14;
            if ((((*(longlong **)(lVar4 + 0x1a0) != (longlong *)0x0) &&
                 (lVar8 = **(longlong **)(lVar4 + 0x1a0), lVar8 != 0)) &&
                (*(byte *)(lVar8 + 0x77) != 0xff)) && (*(byte *)(lVar8 + 0x78) != 0xff)) {
              lVar8 = *(longlong *)
                       (*(longlong *)(*param_1 + (ulonglong)*(byte *)(lVar8 + 0x77) * 8) + 0x110) +
                      (ulonglong)*(byte *)(lVar8 + 0x78) * 0x520;
              *(longlong *)(lVar4 + 0x3a8) = lVar8;
              *(longlong *)(lVar8 + 0x3b0) = lVar4;
            }
            lVar4 = *plVar2;
            uVar11 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar11;
            uVar14 = uVar14 + 0x520;
          } while ((int)uVar11 < *(int *)(lVar4 + 0x118));
        }
        plVar2 = plVar2 + 1;
      } while (plVar2 != (longlong *)(*param_1 + (ulonglong)*(byte *)((longlong)param_1 + 0x34) * 8)
              );
    }
  }
  return;
}

