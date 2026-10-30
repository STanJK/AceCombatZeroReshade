/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140140b50; RVA 0x140b50
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140140b50(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(param_1 + 0x1da38);
  lVar1 = 0x20;
  do {
    if ((undefined8 *)*plVar2 != (undefined8 *)0x0) {
      (*(code *)**(undefined8 **)*plVar2)();
    }
    plVar2 = plVar2 + 1;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  *(undefined8 *)(param_1 + 0x1d998) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9dc) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9a0) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9e4) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9a8) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9ec) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9b0) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9f4) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9b8) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9fc) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9c0) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1da04) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9c8) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1da0c) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1d9d0) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x1da14) = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 0x1d9d8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1da1c) = 0xffffffff;
  return;
}

