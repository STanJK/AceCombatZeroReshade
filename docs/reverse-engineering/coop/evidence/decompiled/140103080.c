/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140103080; RVA 0x103080
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140103080(longlong param_1)

{
  undefined1 uVar1;
  short sVar2;
  
  if (*(short *)(param_1 + 0x1f10) == 0) {
    if ((*(byte *)(param_1 + 0x1f18) & 1) != 0) {
      sVar2 = (short)(int)(*(float *)(param_1 + 0x1f14) *
                           *(float *)(*(longlong *)(param_1 + 0x1f08) + 0x24) *
                          (float)*(byte *)(param_1 + 0x1f19));
      goto LAB_1401030c8;
    }
  }
  else {
    sVar2 = *(short *)(param_1 + 0x1f10) + -1;
LAB_1401030c8:
    *(short *)(param_1 + 0x1f10) = sVar2;
    *(byte *)(param_1 + 0x1f18) = *(byte *)(param_1 + 0x1f18) & 0xfe;
  }
  if (*(short *)(param_1 + 0x1f28) == 0) {
    if ((*(byte *)(param_1 + 0x1f30) & 1) == 0) goto LAB_140103130;
    sVar2 = (short)(int)(*(float *)(*(longlong *)(param_1 + 0x1f20) + 0x24) *
                         *(float *)(param_1 + 0x1f2c) * (float)*(byte *)(param_1 + 0x1f31));
  }
  else {
    sVar2 = *(short *)(param_1 + 0x1f28) + -1;
  }
  *(short *)(param_1 + 0x1f28) = sVar2;
  *(byte *)(param_1 + 0x1f30) = *(byte *)(param_1 + 0x1f30) & 0xfe;
LAB_140103130:
  *(undefined1 *)(param_1 + 0x209e) = 0;
  if (*(char *)(param_1 + 0x2099) != '\0') {
    if (*(char *)(param_1 + 0x2099) == '\x01') {
      if (*(char *)(param_1 + 0x209c) == '\0') {
        if (*(short *)(param_1 + 0x1f10) == 0) {
          *(undefined1 *)(param_1 + 0x209e) = 1;
          return;
        }
      }
      else if ((*(char *)(param_1 + 0x209c) == '\x01') && (*(short *)(param_1 + 0x1f28) == 0)) {
        *(undefined1 *)(param_1 + 0x209e) = 2;
        return;
      }
    }
    else {
      if (*(short *)(param_1 + 0x1f10) == 0) {
        *(undefined1 *)(param_1 + 0x209e) = 1;
        uVar1 = 3;
      }
      else {
        uVar1 = 2;
      }
      if (*(short *)(param_1 + 0x1f28) == 0) {
        *(undefined1 *)(param_1 + 0x209e) = uVar1;
      }
    }
  }
  return;
}

