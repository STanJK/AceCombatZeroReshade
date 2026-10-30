/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001ddc0; RVA 0x1ddc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14001ddc0(float *param_1,longlong param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = 0.0;
  if (*(char *)(param_2 + 0x6b) == '\0') {
    fVar2 = param_3 * *(float *)(param_2 + 0x24);
    fVar3 = param_3 * *(float *)(param_2 + 0x28);
    fVar4 = param_3 * *(float *)(param_2 + 0x20);
  }
  else {
    fVar2 = 0.0;
    fVar3 = 0.0;
    fVar4 = 0.0;
  }
  *param_1 = fVar4;
  param_1[1] = fVar2;
  param_1[2] = fVar3;
  param_1[3] = 1.0;
  if (*(char *)(param_2 + 0x6b) == '\0') {
    fVar2 = param_3 * *(float *)(param_2 + 0x30);
    fVar3 = param_3 * *(float *)(param_2 + 0x34);
    param_3 = param_3 * *(float *)(param_2 + 0x2c);
  }
  else {
    fVar2 = 0.0;
    fVar3 = 0.0;
    param_3 = 0.0;
  }
  param_1[9] = fVar2;
  fVar2 = DAT_1402d22d0;
  param_1[8] = param_3;
  param_1[10] = fVar3;
  param_1[0xb] = 1.0;
  if (*(char *)(param_2 + 0x6b) == '\0') {
    fVar3 = *(float *)(param_2 + 0x38);
    fVar4 = *(float *)(param_2 + 0x40);
    fVar6 = *(float *)(param_2 + 0x3c);
    fVar5 = fVar2;
  }
  else {
    fVar3 = 0.0;
    fVar4 = 0.0;
    fVar5 = 0.0;
    fVar6 = 0.0;
  }
  param_1[4] = fVar6;
  param_1[5] = fVar3;
  param_1[6] = fVar4;
  param_1[7] = fVar5;
  if (*(char *)(param_2 + 0x6b) == '\0') {
    fVar1 = *(float *)(param_2 + 0x44);
    fVar3 = *(float *)(param_2 + 0x4c);
    fVar4 = *(float *)(param_2 + 0x48);
  }
  else {
    fVar3 = 0.0;
    fVar2 = 0.0;
    fVar4 = 0.0;
  }
  fVar6 = 0.0;
  param_1[0xc] = fVar4;
  param_1[0xd] = fVar1;
  param_1[0xe] = fVar3;
  param_1[0xf] = fVar2;
  if (*(char *)(param_2 + 0x6b) == '\0') {
    fVar1 = *(float *)(param_2 + 0x50);
  }
  else {
    fVar1 = 0.0;
  }
  param_1[0x16] = fVar1;
  if (*(char *)(param_2 + 0x6b) == '\0') {
    fVar6 = (float)(uint)*(ushort *)(param_2 + 0x54);
  }
  param_1[0x17] = fVar6;
  param_1[0x18] = (float)*(int *)(param_2 + 0x60);
  if (*(char *)(param_2 + 0x6b) == '\0') {
    *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_2 + 0x5e);
    return;
  }
  if (*(char *)(param_2 + 0x6b) == '\x01') {
    *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_2 + 0x2e);
    return;
  }
  *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_2 + 0x68);
  return;
}

