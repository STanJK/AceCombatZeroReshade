/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d4c40; RVA 0xd4c40
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d4c40(longlong param_1)

{
  uint *puVar1;
  byte *pbVar2;
  ushort uVar3;
  char cVar4;
  byte bVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong lVar8;
  int iVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 local_28;
  undefined8 uStack_20;
  
  (**(code **)(**(longlong **)(param_1 + 0x67160) + 0x58))
            (*(longlong **)(param_1 + 0x67160),*(undefined8 *)(param_1 + 0xa8248),
             *(undefined8 *)(param_1 + 0xa82f8));
  switch(*(undefined4 *)(*(longlong *)(param_1 + 0x67160) + 0x54)) {
  case 0:
    iVar9 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      lVar8 = 0;
      do {
        lVar6 = *(longlong *)(param_1 + 0xa8248);
        iVar9 = iVar9 + 1;
        pbVar2 = (byte *)(lVar8 + 0x1da7 + lVar6);
        *pbVar2 = *pbVar2 & 0xfe;
        *(undefined8 *)(lVar8 + 0x1d78 + lVar6) = 0;
        lVar8 = lVar8 + 0x27a0;
      } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
    }
    lVar8 = *(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110);
    *(ushort *)(lVar8 + 0x428) = (ushort)*(byte *)(**(longlong **)(lVar8 + 0x1a0) + 0x6e);
    puVar1 = (uint *)(*(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10) + 0x3a8);
    *puVar1 = *puVar1 | 0x1000000;
  case 1:
  case 2:
    goto switchD_1400d4ca1_caseD_1;
  case 3:
    uVar10 = 0;
    break;
  case 4:
    uVar10 = 1;
    break;
  case 5:
    uVar10 = 2;
    break;
  case 6:
    bVar5 = 0;
    goto LAB_1400d4f2d;
  case 7:
    bVar5 = 1;
    goto LAB_1400d4f2d;
  case 8:
    bVar5 = 2;
LAB_1400d4f2d:
    lVar8 = *(longlong *)(param_1 + 0xa82f8);
    *(byte *)(lVar8 + 0x85) = bVar5;
    *(undefined8 *)(lVar8 + 0x68) = *(undefined8 *)(lVar8 + 0x50 + (ulonglong)bVar5 * 8);
    lVar8 = *(longlong *)(param_1 + 0xa82f8);
    if (*(longlong *)(lVar8 + 0x68) == 0) {
      uVar10 = 0;
      uVar11 = 0;
    }
    else {
      uVar11 = (ulonglong)*(byte *)(*(longlong *)(lVar8 + 0x68) + 0xd);
      uVar10 = **(undefined8 **)(lVar8 + 0x50 + (ulonglong)*(byte *)(lVar8 + 0x85) * 8);
    }
    lVar8 = *(longlong *)(param_1 + 0x89670 + uVar11 * 8);
    if (lVar8 != 0) {
      *(undefined8 *)(lVar8 + 0x70) = uVar10;
    }
    *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0xa82f8) + 0x10) + 0x55c) =
         (uint)*(byte *)(*(longlong *)(param_1 + 0xa82f8) + 0x85);
    FUN_14014b4c0();
    lVar8 = *(longlong *)(param_1 + 0xa82f8);
    if (*(longlong **)(lVar8 + 0x38) != (longlong *)0x0) {
      *(undefined1 *)(lVar8 + 0x83) =
           *(undefined1 *)((ulonglong)*(byte *)(lVar8 + 0x85) + 0xb + **(longlong **)(lVar8 + 0x38))
      ;
    }
    goto switchD_1400d4ca1_caseD_1;
  default:
    goto switchD_1400d4ca1_default;
  }
  FUN_1400c51e0(*(undefined8 *)(param_1 + 0xa8248),uVar10);
  lVar8 = *(longlong *)(param_1 + 0xa8248);
  lVar6 = *(longlong *)
           (param_1 + 0x89670 +
           (ulonglong)
           *(byte *)((ulonglong)*(byte *)(lVar8 + 0x279a) + 4 + *(longlong *)(lVar8 + 0xff8)) * 8);
  if (lVar6 != 0) {
    *(undefined8 *)(lVar6 + 0x68) = **(undefined8 **)(lVar8 + 0xfd8);
  }
  *(uint *)(*(longlong *)(param_1 + 0xa8248) + 0xc00) =
       (uint)*(byte *)(*(longlong *)(param_1 + 0xa8248) + 0x279a);
  FUN_140158f80();
  FUN_14010f560(*(undefined8 *)(param_1 + 0xa8248));
  lVar8 = *(longlong *)(param_1 + 0xa8248);
  lVar6 = *(longlong *)(lVar8 + 0xfe0);
  *(undefined2 *)(lVar8 + 0x208e) = *(undefined2 *)(lVar6 + 8);
  *(undefined1 *)(lVar8 + 0x2099) = *(undefined1 *)(lVar6 + 10);
  *(undefined1 *)(lVar8 + 0x209a) =
       *(undefined1 *)((ulonglong)*(byte *)(lVar8 + 0x279a) + 0xb + lVar6);
  lVar8 = *(longlong *)(param_1 + 0xa8248);
  *(undefined4 *)(lVar8 + 0x1d90) = 0xb4;
  *(undefined2 *)(lVar8 + 0x1d94) = 0x14;
  *(undefined4 *)(lVar8 + 0x1d98) = 0x3ca3d70a;
  *(undefined8 *)(lVar8 + 0x1d9c) = 0x3f6147ae;
  FUN_1401c56d0();
  lVar8 = *(longlong *)(param_1 + 0xa8248);
  local_28 = _DAT_1402d35f0;
  uStack_20 = _UNK_1402d35f8;
  cVar4 = FUN_1401c6a00(0,1,0x124,lVar8 + 0x70,&local_28,0,0,0,0,0,0);
  if ((((cVar4 != '\0') && (lVar6 = FUN_1401c97a0(), '\x01' < *(char *)(lVar6 + 0x3dc2))) &&
      (uVar3 = *(ushort *)(lVar6 + 0x138),
      (~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar3 * 0x18) + 0x5b52) & 1) != 0)) &&
     (puVar7 = (undefined4 *)FUN_1401c9e60(lVar6), puVar7 != (undefined4 *)0x0)) {
    *(ushort *)(puVar7 + 0x11) = uVar3;
    *(undefined2 *)((longlong)puVar7 + 0x46) = 0x124;
    *puVar7 = *(undefined4 *)(lVar8 + 0x70);
    puVar7[1] = *(undefined4 *)(lVar8 + 0x74);
    puVar7[2] = *(undefined4 *)(lVar8 + 0x78);
    puVar7[3] = *(undefined4 *)(lVar8 + 0x7c);
    *(undefined8 *)(puVar7 + 4) = 0;
    puVar7[6] = 0;
    *(undefined8 *)(puVar7 + 7) = 0x3f800000;
    *(undefined8 *)(puVar7 + 9) = 0;
    puVar7[0xb] = 0x3f800000;
    puVar7[0xf] = 0x3f800000;
    *(undefined2 *)((longlong)puVar7 + 0x4a) = 0;
    *(byte *)(puVar7 + 0x1c) = *(byte *)(puVar7 + 0x1c) & 0xee | 6;
    *(code **)(puVar7 + 0xc) = FUN_1401caa00;
  }
switchD_1400d4ca1_caseD_1:
switchD_1400d4ca1_default:
  FUN_1401040c0(*(undefined8 *)(*(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110) + 0x1b8),0
                ,param_1 + 0x6a130);
  FUN_140036fe0(*(undefined8 *)(param_1 + 0x67120));
  return;
}

