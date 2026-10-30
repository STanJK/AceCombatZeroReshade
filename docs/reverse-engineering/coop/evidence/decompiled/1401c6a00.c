/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401c6a00; RVA 0x1c6a00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401c6a00(undefined8 param_1,undefined2 param_2,undefined2 param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  
  if (DAT_14033bd60 != '\0') {
    return 0 < DAT_14032c480;
  }
  if (0 >= DAT_14032c480) {
    puVar4 = (undefined4 *)FUN_140019ef0();
    plVar5 = (longlong *)FUN_14001b280(puVar4);
    if (plVar5 != (longlong *)0x0) {
      lVar2 = *(longlong *)(**(longlong **)(*(longlong *)(puVar4 + 0x10a) + 0x697b8) + 0x110);
      uVar1 = *(undefined1 *)(**(longlong **)(*(longlong *)(puVar4 + 0x10a) + 0x697b8) + 0x15d);
      *(undefined4 *)(plVar5 + 0xc) = *puVar4;
      *(undefined2 *)((longlong)plVar5 + 100) = *(undefined2 *)(lVar2 + 0x228);
      *(undefined1 *)((longlong)plVar5 + 0x66) = *(undefined1 *)(lVar2 + 0x234);
      *(undefined1 *)((longlong)plVar5 + 0x67) = *(undefined1 *)(lVar2 + 0x235);
      *(undefined1 *)(plVar5 + 0xd) = uVar1;
      *(undefined2 *)((longlong)plVar5 + 0x69) = 0;
      *(undefined1 *)((longlong)plVar5 + 0x6b) = 7;
      *(undefined2 *)(plVar5 + 9) = param_2;
      *(undefined2 *)((longlong)plVar5 + 0x4a) = param_3;
      *(undefined4 *)(plVar5 + 4) = *param_4;
      *(undefined4 *)((longlong)plVar5 + 0x24) = param_4[1];
      *(undefined4 *)(plVar5 + 5) = param_4[2];
      *(undefined4 *)((longlong)plVar5 + 0x2c) = *param_5;
      *(undefined4 *)(plVar5 + 6) = param_5[1];
      *(undefined4 *)((longlong)plVar5 + 0x34) = param_5[2];
      *(undefined1 *)((longlong)plVar5 + 0x4d) = param_10;
      *(undefined4 *)(plVar5 + 7) = param_6;
      *(undefined4 *)((longlong)plVar5 + 0x3c) = param_7;
      *(undefined1 *)((longlong)plVar5 + 0x4c) = param_11;
      *(undefined4 *)(plVar5 + 8) = param_8;
      *(undefined4 *)((longlong)plVar5 + 0x44) = param_9;
      puVar3 = *(undefined8 **)(puVar4 + 0x28);
      *puVar3 = plVar5;
      *(longlong **)(puVar4 + 0x28) = plVar5;
      *plVar5 = (longlong)(puVar4 + 0x26);
      plVar5[1] = (longlong)puVar3;
      puVar4[0x42] = puVar4[0x42] + 1;
    }
  }
  return true;
}

