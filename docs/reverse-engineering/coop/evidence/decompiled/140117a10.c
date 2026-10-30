/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140117a10; RVA 0x117a10
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140117a10(longlong param_1,byte param_2)

{
  ushort uVar1;
  longlong lVar2;
  char cVar3;
  undefined2 uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  ushort uVar8;
  undefined4 uVar9;
  undefined2 local_res10 [4];
  undefined2 local_res18 [8];
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar11;
  undefined8 *puVar10;
  uint in_stack_ffffffffffffff58;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  uint local_58;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  if ((*(byte *)(param_1 + 0x1f0) & 2) == 0) {
    return;
  }
  lVar5 = **(longlong **)(param_1 + 0x1a0);
  if (param_2 == 3) {
    *(byte *)(param_1 + 0x24b) = *(byte *)(param_1 + 0x24b) | 2;
  }
  else {
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 4;
  }
  lVar2 = *(longlong *)(param_1 + 0x198);
  if (lVar2 != 0) {
    if (param_2 == 3) {
      cVar3 = *(char *)(lVar5 + 0x7f);
      if (cVar3 == '\x01') {
        uVar7 = 3;
      }
      else {
        if (cVar3 != '\x02') {
          if (cVar3 == '\x03') {
            local_68 = *(undefined8 *)(param_1 + 600);
            uStack_60 = *(undefined8 *)(param_1 + 0x260);
            local_58 = (uint)*(byte *)(lVar5 + 0x80);
            uVar4 = FUN_140031f80(*(undefined8 *)(lVar2 + 0x66ee0),0x3a,&local_68,0);
            *(undefined2 *)(param_1 + 0x442) = uVar4;
          }
          goto LAB_140117b43;
        }
        uVar7 = 0x36;
      }
      local_68 = *(undefined8 *)(param_1 + 600);
      uStack_60 = *(undefined8 *)(param_1 + 0x260);
      local_58 = (uint)*(byte *)(lVar5 + 0x80);
    }
    else {
      local_68 = *(undefined8 *)(param_1 + 600);
      uStack_60 = *(undefined8 *)(param_1 + 0x260);
      local_58 = (uint)param_2;
      cVar3 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
      if (((cVar3 != '\0') && (cVar3 != '\x02')) || (*(char *)(param_1 + 0x235) != '\0')) {
        local_58 = param_2 + 3;
      }
      uVar7 = 4;
    }
    FUN_140031f80(*(undefined8 *)(lVar2 + 0x66ee0),uVar7,&local_68,0);
  }
LAB_140117b43:
  uVar9 = 0;
  cVar3 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
  if (((cVar3 == '\0') || (cVar3 == '\x02')) && (*(char *)(param_1 + 0x235) == '\0')) {
    uVar7 = FUN_1401c56d0();
    local_res10[0] = 0x113;
    local_res18[0] = 1;
    FUN_1401c6150(uVar7,local_res18,local_res10);
  }
  else if (*(short *)(lVar5 + 0x6c) == 0x1fd) {
    FUN_1401c56d0();
    uVar7 = CONCAT44(uVar11,uVar9);
    local_78 = _DAT_1402d35f0;
    uStack_70 = _UNK_1402d35f8;
    cVar3 = FUN_1401c6a00(_DAT_1402d35f0,2,1,param_1 + 600,&local_78,uVar7,uVar9,uVar9,uVar9,0,0);
    uVar11 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if (((cVar3 != '\0') && (lVar5 = FUN_1401c97a0(), '\x02' < *(char *)(lVar5 + 0x3dc2))) &&
       ((uVar8 = *(ushort *)(lVar5 + 0x150),
        (~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar8 * 0x18) + 0x62) & 1) != 0 &&
        (puVar6 = (undefined4 *)FUN_1401c9e60(lVar5), puVar6 != (undefined4 *)0x0)))) {
      *(ushort *)(puVar6 + 0x11) = uVar8;
      *(undefined2 *)((longlong)puVar6 + 0x46) = 1;
      *puVar6 = *(undefined4 *)(param_1 + 600);
      puVar6[1] = *(undefined4 *)(param_1 + 0x25c);
      puVar6[2] = *(undefined4 *)(param_1 + 0x260);
      puVar6[3] = *(undefined4 *)(param_1 + 0x264);
      *(undefined8 *)(puVar6 + 4) = 0;
      puVar6[6] = 0;
      *(undefined8 *)(puVar6 + 7) = 0x3f800000;
      *(undefined8 *)(puVar6 + 9) = 0;
      puVar6[0xb] = 0x3f800000;
      puVar6[0xf] = 0x3f800000;
      *(undefined2 *)((longlong)puVar6 + 0x4a) = 0;
      *(byte *)(puVar6 + 0x1c) = *(byte *)(puVar6 + 0x1c) & 0xee | 6;
      *(code **)(puVar6 + 0xc) = FUN_1401caa00;
    }
  }
  else if (*(short *)(lVar5 + 0x6c) == 0x13d) {
    FUN_1401c56d0();
    puVar10 = &local_78;
    local_res10[0] = 0;
    local_res18[0] = 2;
    local_78 = _DAT_1402d35f0;
    uStack_70 = _UNK_1402d35f8;
    local_68 = _DAT_1402d35f0;
    uStack_60 = _UNK_1402d35f8;
    FUN_1401c5d20(_DAT_1402d35f0,local_res18,local_res10,param_1 + 600,&local_68,puVar10,
                  in_stack_ffffffffffffff58 & 0xffffff00);
    uVar11 = (undefined4)((ulonglong)puVar10 >> 0x20);
  }
  else if (*(char *)(lVar5 + 0x7f) != '\0') {
    FUN_1401c56d0();
    local_68 = _DAT_1402d35f0;
    uStack_60 = _UNK_1402d35f8;
    uVar7 = CONCAT44(uVar11,DAT_1402d2100);
    cVar3 = FUN_1401c6a00(DAT_1402d2100,1,0x1f,param_1 + 600,&local_68,uVar7,DAT_1402d236c,
                          DAT_1402d2458,uVar9,0,1);
    uVar11 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if ((((cVar3 != '\0') && (lVar5 = FUN_1401c97a0(), '\x01' < *(char *)(lVar5 + 0x3dc2))) &&
        (uVar8 = *(ushort *)(lVar5 + 0x138),
        (~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar8 * 0x18) + 0x9c2) & 1) != 0)) &&
       (puVar6 = (undefined4 *)FUN_1401c9e60(lVar5), puVar6 != (undefined4 *)0x0)) {
      *(undefined2 *)((longlong)puVar6 + 0x46) = 0x1f;
      *(ushort *)(puVar6 + 0x11) = uVar8;
      *puVar6 = *(undefined4 *)(param_1 + 600);
      puVar6[1] = *(undefined4 *)(param_1 + 0x25c);
      puVar6[2] = *(undefined4 *)(param_1 + 0x260);
      puVar6[3] = *(undefined4 *)(param_1 + 0x264);
      *(undefined8 *)(puVar6 + 4) = 0;
      puVar6[6] = 0;
      puVar6[7] = 0x3f800000;
      puVar6[8] = 0x3ea3d70a;
      puVar6[9] = 0x3fc00000;
      *(undefined8 *)(puVar6 + 10) = 0x40800000;
      puVar6[0xf] = 0x3f800000;
      *(undefined2 *)((longlong)puVar6 + 0x4a) = 0;
      *(byte *)(puVar6 + 0x1c) = *(byte *)(puVar6 + 0x1c) & 0xee | 0x26;
      *(code **)(puVar6 + 0xc) = FUN_1401caa00;
    }
  }
  *(undefined2 *)(param_1 + 0x22a) = 0;
  *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xfffffffd | 0x1080000;
  if (*(short *)(param_1 + 0x22e) == 0x649) {
    uVar8 = 0x130;
  }
  else {
    if (*(short *)(param_1 + 0x22e) != 0x64a) {
      return;
    }
    uVar8 = 0x133;
  }
  FUN_1401c56d0();
  local_68 = _DAT_1402d35f0;
  uStack_60 = _UNK_1402d35f8;
  cVar3 = FUN_1401c6a00(DAT_1402d241c,2,uVar8,param_1 + 600,&local_68,CONCAT44(uVar11,DAT_1402d241c)
                        ,DAT_1402d253c,DAT_1402d25c0,uVar9,1,1);
  if (((cVar3 != '\0') && (lVar5 = FUN_1401c97a0(), '\x02' < *(char *)(lVar5 + 0x3dc2))) &&
     ((uVar1 = *(ushort *)(lVar5 + 0x150),
      (~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar1 * 0x18) + 0x12 +
                 (ulonglong)uVar8 * 0x50) & 1) != 0 &&
      (puVar6 = (undefined4 *)FUN_1401c9e60(lVar5), puVar6 != (undefined4 *)0x0)))) {
    *(ushort *)(puVar6 + 0x11) = uVar1;
    *(ushort *)((longlong)puVar6 + 0x46) = uVar8;
    *puVar6 = *(undefined4 *)(param_1 + 600);
    puVar6[1] = *(undefined4 *)(param_1 + 0x25c);
    puVar6[2] = *(undefined4 *)(param_1 + 0x260);
    puVar6[3] = *(undefined4 *)(param_1 + 0x264);
    *(undefined8 *)(puVar6 + 4) = 0;
    puVar6[6] = 0;
    puVar6[7] = 0x3f800000;
    puVar6[8] = 0x40400000;
    puVar6[9] = 0x41700000;
    *(undefined8 *)(puVar6 + 10) = 0x41f00000;
    puVar6[0xf] = 0x3f800000;
    *(undefined2 *)((longlong)puVar6 + 0x4a) = 0;
    *(byte *)(puVar6 + 0x1c) = *(byte *)(puVar6 + 0x1c) & 0xfe | 0x36;
    *(code **)(puVar6 + 0xc) = FUN_1401caa00;
  }
  return;
}

