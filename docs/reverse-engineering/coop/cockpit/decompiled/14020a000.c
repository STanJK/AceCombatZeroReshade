/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14020a000; RVA 0x20a000
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14020a000(longlong param_1,int param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  int *piVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined4 uVar9;
  undefined1 auStack_c8 [32];
  longlong *local_a8;
  int local_98 [2];
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  undefined1 local_70 [16];
  undefined1 local_60 [12];
  float fStack_54;
  longlong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = DAT_140309040 ^ (ulonglong)auStack_c8;
  local_98[0] = param_2;
  FUN_14020eeb0(0xffffffff,0xffffffff,0xffffffff,0xffffffff);
  piVar5 = DAT_14033da48;
  plVar2 = *(longlong **)(DAT_14033da48 + 4);
  if (local_98[0] == -1) {
    plVar8 = (longlong *)
             (**(code **)(**(longlong **)(DAT_14033da48 + 0x26) + 0x48))
                       (*(longlong **)(DAT_14033da48 + 0x26),&local_88);
    local_a8 = (longlong *)0x0;
    local_90 = (ulonglong)(uint)(piVar5[0x2a] * *piVar5) + *plVar8;
    (**(code **)(*plVar2 + 0x170))(plVar2,1,&local_90,0);
    _local_60 = *(undefined1 (*) [16])(DAT_14033da48 + 0x2b);
    local_50 = *(longlong *)(DAT_14033da48 + 0x2f);
    local_48 = *(undefined8 *)(DAT_14033da48 + 0x31);
    uStack_40 = *(undefined8 *)(DAT_14033da48 + 0x33);
    (**(code **)(*plVar2 + 0xa8))(plVar2,1,local_60);
    (**(code **)(*plVar2 + 0xb0))(plVar2,1,&local_48);
    piVar5 = DAT_14033da48;
    *(int *)(param_1 + 0x10) = (int)(float)local_60._8_4_;
    *(int *)(param_1 + 0x14) = (int)fStack_54;
    *(int *)(param_1 + 0x1c) = piVar5[0x3a];
    *(int *)(param_1 + 0x20) = piVar5[0x3b];
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  else {
    plVar8 = (longlong *)FUN_140211b80(param_1 + 0x28,local_70,local_98);
    puVar6 = DAT_14033da68;
    lVar3 = *plVar8;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(lVar3 + 0x98);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(lVar3 + 0x9c);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(lVar3 + 0x48);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(lVar3 + 0xa0);
    plVar8 = (longlong *)*puVar6;
    iVar1 = *(int *)(lVar3 + 0x8c);
    (**(code **)(*plVar8 + 0x48))(plVar8,&local_80);
    puVar7 = DAT_14033da70;
    uVar9 = 0;
    local_90 = iVar1 * *(int *)(puVar6 + 1) + local_80;
    iVar1 = *(int *)(lVar3 + 0x90);
    if (iVar1 == -1) {
      local_a8 = (longlong *)0x0;
      (**(code **)(*plVar2 + 0x170))(plVar2,1,&local_90,0);
    }
    else {
      (**(code **)(*(longlong *)*DAT_14033da70 + 0x48))((longlong *)*DAT_14033da70,&local_78);
      local_a8 = &local_88;
      local_88 = iVar1 * *(int *)(puVar7 + 1) + local_78;
      (**(code **)(*plVar2 + 0x170))(plVar2,1,&local_90,0);
      uVar9 = 0x14;
    }
    *(undefined4 *)(param_1 + 0x20) = uVar9;
    auVar4._4_4_ = (float)*(int *)(lVar3 + 0x9c);
    auVar4._0_4_ = (float)*(int *)(lVar3 + 0x98);
    auVar4._8_8_ = 0;
    _local_60 = auVar4 << 0x40;
    local_50 = (ulonglong)DAT_1402d22d0 << 0x20;
    (**(code **)(*plVar2 + 0xa8))(plVar2,1,local_60);
    local_48 = 0;
    uStack_40 = *(undefined8 *)(lVar3 + 0x98);
    (**(code **)(*plVar2 + 0xb0))(plVar2,1,&local_48);
  }
  return;
}

