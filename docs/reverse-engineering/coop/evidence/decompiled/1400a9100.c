/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a9100; RVA 0xa9100
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a9100(longlong param_1)

{
  uint uVar1;
  float fVar2;
  
  FUN_1400a4a20();
  fVar2 = DAT_1402d22d0;
  uVar1 = *(uint *)(param_1 + 0x5c);
  if (((uVar1 & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x48c) =
         (*(float *)(param_1 + 0xf34) - DAT_1402d22d0 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x48c);
  }
  if (((uVar1 & 2) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x534) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x534);
  }
  if (((uVar1 & 4) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x5dc) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x5dc);
  }
  if (((uVar1 & 8) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x684) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x684);
  }
  if (((uVar1 & 0x10) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x72c) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x72c);
  }
  if (((uVar1 & 0x20) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x7d4) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x7d4);
  }
  if (((uVar1 & 0x40) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x87c) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x87c);
  }
  if (((char)uVar1 < '\0') && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x924) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x924);
  }
  if (((uVar1 >> 8 & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0x9cc) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0x9cc);
  }
  if (((uVar1 >> 9 & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xa74) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xa74);
  }
  if (((uVar1 >> 10 & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xb1c) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xb1c);
  }
  if (((uVar1 >> 0xb & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xbc4) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xbc4);
  }
  if (((uVar1 >> 0xc & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xc6c) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xc6c);
  }
  if (((uVar1 >> 0xd & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xd14) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xd14);
  }
  if (((uVar1 >> 0xe & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xdbc) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xdbc);
  }
  if (((uVar1 >> 0xf & 1) != 0) && (*(char *)(param_1 + 0xf38) == '\x01')) {
    *(float *)(param_1 + 0xe64) =
         (*(float *)(param_1 + 0xf34) - fVar2 / (float)*(byte *)(param_1 + 0x30)) +
         *(float *)(param_1 + 0xe64);
  }
  return;
}

