/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010c3f0; RVA 0x10c3f0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14010c3f0(longlong param_1)

{
  undefined1 auVar1 [16];
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *puVar5;
  byte bVar6;
  ushort uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auVar11 [64];
  undefined1 auVar12 [64];
  undefined1 auVar13 [64];
  undefined1 auVar14 [64];
  undefined1 local_78 [6] [16];
  
  iVar3 = DAT_14032c480 + 1;
  if (*(char *)(param_1 + 0x278b) == '\0') {
    return;
  }
  DAT_14032c480 = iVar3;
  if ((*(byte *)(param_1 + 0x1863) & 5) != 0) {
    *(undefined2 *)(param_1 + 0x2086) = 0;
    *(undefined2 *)(param_1 + 0x2084) = 0;
  }
  FUN_1401c56d0();
  local_78[0] = *(undefined1 (*) [16])(param_1 + 0x15d0);
  auVar11 = ZEXT1664(local_78[0]);
  uVar7 = *(ushort *)(param_1 + 0x2086);
  uVar9 = 0;
  uVar10 = 0;
  auVar1 = vshufps_avx(local_78[0],local_78[0],0xff);
  auVar12 = ZEXT1664(auVar1);
  auVar1 = vshufps_avx(local_78[0],local_78[0],0xaa);
  auVar13 = ZEXT1664(auVar1);
  auVar1 = vshufps_avx(local_78[0],local_78[0],0x55);
  auVar14 = ZEXT1664(auVar1);
  if (*(float *)(param_1 + 0x1850) <= 0.0) {
    uVar9 = 0;
    if (*(int *)(param_1 + 0x277c) * (uint)*(byte *)(param_1 + 0x20a0) <= (uint)uVar7) {
      cVar2 = *(char *)(param_1 + 0x2094);
      if (cVar2 == '\0') {
        uVar8 = 0xf1;
        cVar2 = FUN_1401c6a00(uVar7,1,0xf1,param_1 + 0x70,local_78,0,0,0,0,0,0);
        uVar9 = uVar10;
        if (cVar2 != '\0') {
          lVar4 = FUN_1401c97a0();
          uVar9 = uVar10;
          if ('\x01' < *(char *)(lVar4 + 0x3dc2)) {
            uVar7 = *(ushort *)(lVar4 + 0x138);
            bVar6 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar7 * 0x18) + 0x4b62);
LAB_14010c662:
            if ((~bVar6 & 1) != 0) {
              puVar5 = (undefined4 *)FUN_1401c9e60(lVar4);
              if (puVar5 != (undefined4 *)0x0) {
                *(ushort *)(puVar5 + 0x11) = uVar7;
                *(undefined2 *)((longlong)puVar5 + 0x46) = uVar8;
                *puVar5 = *(undefined4 *)(param_1 + 0x70);
                puVar5[1] = *(undefined4 *)(param_1 + 0x74);
                puVar5[2] = *(undefined4 *)(param_1 + 0x78);
                puVar5[3] = *(undefined4 *)(param_1 + 0x7c);
                puVar5[4] = auVar11._0_4_;
                puVar5[5] = auVar14._0_4_;
                puVar5[6] = auVar13._0_4_;
                puVar5[7] = auVar12._0_4_;
                *(undefined8 *)(puVar5 + 8) = 0;
                puVar5[10] = 0;
                puVar5[0xb] = 0x3f800000;
                puVar5[0xf] = 0x3f800000;
                *(undefined2 *)((longlong)puVar5 + 0x4a) = 0;
                *(byte *)(puVar5 + 0x1c) = *(byte *)(puVar5 + 0x1c) & 0xee | 6;
                *(code **)(puVar5 + 0xc) = FUN_1401caa00;
              }
            }
          }
        }
      }
      else if (cVar2 == '\x02') {
        uVar8 = 0xf0;
        uVar9 = uVar10;
        cVar2 = FUN_1401c6a00(uVar7,1,0xf0,param_1 + 0x70,local_78,0,0,0,0,0,0);
        if (cVar2 != '\0') {
          lVar4 = FUN_1401c97a0();
          if ('\x01' < *(char *)(lVar4 + 0x3dc2)) {
            uVar7 = *(ushort *)(lVar4 + 0x138);
            bVar6 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar7 * 0x18) + 0x4b12);
            goto LAB_14010c662;
          }
        }
      }
      else if (cVar2 == '\x01') {
        uVar8 = 0xef;
        uVar9 = uVar10;
        cVar2 = FUN_1401c6a00(uVar7,1,0xef,param_1 + 0x70,local_78,0,0,0,0,0,0);
        if (cVar2 != '\0') {
          lVar4 = FUN_1401c97a0();
          if ('\x01' < *(char *)(lVar4 + 0x3dc2)) {
            uVar7 = *(ushort *)(lVar4 + 0x138);
            bVar6 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar7 * 0x18) + 0x4ac2);
            goto LAB_14010c662;
          }
        }
      }
    }
    *(undefined2 *)(param_1 + 0x2086) = 0;
  }
  else if ((uint)uVar7 < (*(int *)(param_1 + 0x277c) + 1) * (uint)*(byte *)(param_1 + 0x20a0)) {
    *(ushort *)(param_1 + 0x2086) = uVar7 + 1;
  }
  uVar7 = *(ushort *)(param_1 + 0x2084);
  if (*(float *)(param_1 + 0x1854) < DAT_1402d2080) {
    if ((uint)uVar7 < (*(int *)(param_1 + 0x2778) + 1) * (uint)*(byte *)(param_1 + 0x20a0)) {
      *(ushort *)(param_1 + 0x2084) = uVar7 + 1;
    }
    goto LAB_14010c715;
  }
  if (*(int *)(param_1 + 0x2778) * (uint)*(byte *)(param_1 + 0x20a0) <= (uint)uVar7) {
    cVar2 = *(char *)(param_1 + 0x2094);
    if (cVar2 == '\0') {
      uVar8 = 0xeb;
      cVar2 = FUN_1401c6a00(uVar7,1,0xeb,param_1 + 0x70,local_78,uVar9,uVar9,uVar9,uVar9,0,0);
      if (cVar2 != '\0') {
        lVar4 = FUN_1401c97a0();
        if ('\x01' < *(char *)(lVar4 + 0x3dc2)) {
          uVar7 = *(ushort *)(lVar4 + 0x138);
          bVar6 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar7 * 0x18) + 0x4982);
LAB_14010c903:
          if ((~bVar6 & 1) != 0) {
            puVar5 = (undefined4 *)FUN_1401c9e60(lVar4);
            if (puVar5 != (undefined4 *)0x0) {
              *(ushort *)(puVar5 + 0x11) = uVar7;
              *(undefined2 *)((longlong)puVar5 + 0x46) = uVar8;
              *puVar5 = *(undefined4 *)(param_1 + 0x70);
              puVar5[1] = *(undefined4 *)(param_1 + 0x74);
              puVar5[2] = *(undefined4 *)(param_1 + 0x78);
              puVar5[3] = *(undefined4 *)(param_1 + 0x7c);
              puVar5[4] = auVar11._0_4_;
              puVar5[5] = auVar14._0_4_;
              puVar5[6] = auVar13._0_4_;
              puVar5[7] = auVar12._0_4_;
              *(undefined8 *)(puVar5 + 8) = 0;
              puVar5[10] = 0;
              puVar5[0xb] = 0x3f800000;
              puVar5[0xf] = 0x3f800000;
              *(undefined2 *)((longlong)puVar5 + 0x4a) = 0;
              *(byte *)(puVar5 + 0x1c) = *(byte *)(puVar5 + 0x1c) & 0xee | 6;
              *(code **)(puVar5 + 0xc) = FUN_1401caa00;
            }
          }
        }
      }
    }
    else if (cVar2 == '\x02') {
      uVar8 = 0xea;
      cVar2 = FUN_1401c6a00(uVar7,1,0xea,param_1 + 0x70,local_78,uVar9,uVar9,uVar9,uVar9,0,0);
      if (cVar2 != '\0') {
        lVar4 = FUN_1401c97a0();
        if ('\x01' < *(char *)(lVar4 + 0x3dc2)) {
          uVar7 = *(ushort *)(lVar4 + 0x138);
          bVar6 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar7 * 0x18) + 0x4932);
          goto LAB_14010c903;
        }
      }
    }
    else if (cVar2 == '\x01') {
      uVar8 = 0xe9;
      cVar2 = FUN_1401c6a00(uVar7,1,0xe9,param_1 + 0x70,local_78,uVar9,uVar9,uVar9,uVar9,0,0);
      if (cVar2 != '\0') {
        lVar4 = FUN_1401c97a0();
        if ('\x01' < *(char *)(lVar4 + 0x3dc2)) {
          uVar7 = *(ushort *)(lVar4 + 0x138);
          bVar6 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar7 * 0x18) + 0x48e2);
          goto LAB_14010c903;
        }
      }
    }
  }
  *(undefined2 *)(param_1 + 0x2084) = 0;
LAB_14010c715:
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

