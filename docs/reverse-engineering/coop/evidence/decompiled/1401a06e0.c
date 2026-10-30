/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401a06e0; RVA 0x1a06e0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8
FUN_1401a06e0(longlong param_1,undefined8 param_2,undefined8 param_3,uint *param_4,
             undefined8 param_5,undefined1 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  
  uVar3 = FUN_14019f6c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (((param_4 != (uint *)0x0) && (*(longlong *)(param_1 + 8) != 0)) &&
     (*(longlong *)(param_1 + 0x10) != 0)) {
    if (*param_4 == 0) {
      puVar4 = (undefined8 *)0x0;
    }
    else {
      puVar4 = (undefined8 *)((ulonglong)*param_4 + (longlong)param_4);
    }
    lVar6 = 4;
    puVar2 = (undefined8 *)(param_1 + 0x50);
    do {
      puVar7 = puVar2;
      puVar5 = puVar4;
      uVar1 = puVar5[1];
      *puVar7 = *puVar5;
      puVar7[1] = uVar1;
      uVar1 = puVar5[3];
      puVar7[2] = puVar5[2];
      puVar7[3] = uVar1;
      uVar1 = puVar5[5];
      puVar7[4] = puVar5[4];
      puVar7[5] = uVar1;
      uVar1 = puVar5[7];
      puVar7[6] = puVar5[6];
      puVar7[7] = uVar1;
      uVar1 = puVar5[9];
      puVar7[8] = puVar5[8];
      puVar7[9] = uVar1;
      uVar1 = puVar5[0xb];
      puVar7[10] = puVar5[10];
      puVar7[0xb] = uVar1;
      uVar1 = puVar5[0xd];
      puVar7[0xc] = puVar5[0xc];
      puVar7[0xd] = uVar1;
      uVar1 = puVar5[0xf];
      puVar7[0xe] = puVar5[0xe];
      puVar7[0xf] = uVar1;
      lVar6 = lVar6 + -1;
      puVar4 = puVar5 + 0x10;
      puVar2 = puVar7 + 0x10;
    } while (lVar6 != 0);
    uVar1 = puVar5[0x11];
    puVar7[0x10] = puVar5[0x10];
    puVar7[0x11] = uVar1;
    uVar1 = puVar5[0x13];
    puVar7[0x12] = puVar5[0x12];
    puVar7[0x13] = uVar1;
    uVar1 = puVar5[0x15];
    puVar7[0x14] = puVar5[0x14];
    puVar7[0x15] = uVar1;
    uVar1 = puVar5[0x17];
    puVar7[0x16] = puVar5[0x16];
    puVar7[0x17] = uVar1;
    uVar1 = puVar5[0x19];
    puVar7[0x18] = puVar5[0x18];
    puVar7[0x19] = uVar1;
    puVar7[0x1a] = puVar5[0x1a];
    FUN_14019ff00(param_1);
  }
  return uVar3;
}

