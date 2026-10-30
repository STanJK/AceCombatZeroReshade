/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c9690; RVA 0xc9690
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c9690(longlong param_1,byte param_2)

{
  undefined4 uVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  plVar2 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar2 + 0x7a4) != 0) && (*(int *)((longlong)plVar2 + 0x7a4) == 1)) {
    plVar2 = plVar2 + 0x66;
  }
  (**(code **)(*plVar2 + 0x38))(plVar2,param_2 + 0x4c);
  plVar2 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar2 + 0x7a4) != 0) && (*(int *)((longlong)plVar2 + 0x7a4) == 1)) {
    plVar2 = plVar2 + 0x66;
  }
  uVar1 = (**(code **)(*plVar2 + 0x18))();
  uVar3 = FUN_140200de0(DAT_14032c8f8,uVar1,0x10);
  plVar2 = (longlong *)FUN_1402014c0();
  if ((*(int *)((longlong)plVar2 + 0x7a4) != 0) && (*(int *)((longlong)plVar2 + 0x7a4) == 1)) {
    plVar2 = plVar2 + 0x66;
  }
  (**(code **)(*plVar2 + 0x48))(plVar2,uVar3);
  *(byte *)(param_1 + 0xa8794) = param_2;
  *(undefined1 *)(param_1 + 0xa8824) = 0;
  return;
}

