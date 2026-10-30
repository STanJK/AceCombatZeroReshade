/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140188a80; RVA 0x188a80
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140188a80(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  puVar2 = DAT_14032c8e0;
  FUN_14021d4c0(&DAT_14033abe0);
  fVar6 = DAT_1402d2778;
  *(undefined2 *)(puVar2 + 0x20) = DAT_14033ac08;
  fVar4 = (float)FUN_140243ea0(fVar6 * DAT_14033abe8);
  fVar7 = DAT_1402d277c;
  puVar2[2] = (char)(int)(fVar4 + DAT_1402d277c);
  fVar4 = (float)FUN_140243ea0(fVar6 * DAT_14033abec);
  puVar2[3] = (char)(int)(fVar4 + fVar7);
  fVar4 = (float)FUN_140243ea0(fVar6 * DAT_14033abf0);
  *puVar2 = (char)(int)(fVar4 + fVar7);
  fVar5 = (float)FUN_140243ea0(fVar6 * DAT_14033abf4);
  fVar4 = DAT_1402d2878;
  puVar2[1] = (char)(int)(fVar5 + fVar7);
  puVar2[0xe] = (char)(int)(fVar4 * DAT_14033ac00);
  puVar2[0xf] = (char)(int)(fVar4 * DAT_14033ac04);
  puVar2[0xc] = (char)(int)(fVar4 * DAT_14033abf8);
  puVar2[0xd] = (char)(int)(fVar4 * DAT_14033abfc);
  uVar1 = *(ushort *)(puVar2 + 0x20);
  puVar2[6] = -((uVar1 & 0x10) != 0);
  puVar2[4] = -((uVar1 & 0x20) != 0);
  puVar2[5] = -((uVar1 & 0x80) != 0);
  puVar2[7] = -((uVar1 & 0x40) != 0);
  puVar2[8] = -((uVar1 & 0x1000) != 0);
  puVar2[9] = -((uVar1 & 0x2000) != 0);
  uVar3 = 0;
  if ((short)uVar1 < 0) {
    uVar3 = 0xff;
  }
  puVar2[0xb] = uVar3;
  puVar2[10] = -((uVar1 & 0x4000) != 0);
  if (DAT_14033ac0c == 1) {
    puVar2[0x22] = 0;
  }
  else {
    puVar2[0x22] = (DAT_14033ac0c != 2) + '\x01';
  }
  *(undefined2 *)(puVar2 + 0x44) = DAT_14033ac38;
  fVar5 = (float)FUN_140243ea0(fVar6 * DAT_14033ac18);
  puVar2[0x26] = (char)(int)(fVar5 + fVar7);
  fVar5 = (float)FUN_140243ea0(fVar6 * DAT_14033ac1c);
  puVar2[0x27] = (char)(int)(fVar5 + fVar7);
  fVar5 = (float)FUN_140243ea0(fVar6 * DAT_14033ac20);
  puVar2[0x24] = (char)(int)(fVar5 + fVar7);
  fVar6 = (float)FUN_140243ea0(fVar6 * DAT_14033ac24);
  puVar2[0x25] = (char)(int)(fVar6 + fVar7);
  puVar2[0x32] = (char)(int)(fVar4 * DAT_14033ac30);
  puVar2[0x33] = (char)(int)(fVar4 * DAT_14033ac34);
  puVar2[0x30] = (char)(int)(fVar4 * DAT_14033ac28);
  puVar2[0x31] = (char)(int)(fVar4 * DAT_14033ac2c);
  uVar1 = *(ushort *)(puVar2 + 0x44);
  puVar2[0x2a] = -((uVar1 & 0x10) != 0);
  puVar2[0x28] = -((uVar1 & 0x20) != 0);
  puVar2[0x29] = -((uVar1 & 0x80) != 0);
  puVar2[0x2b] = -((uVar1 & 0x40) != 0);
  puVar2[0x2c] = -((uVar1 & 0x1000) != 0);
  puVar2[0x2d] = -((uVar1 & 0x2000) != 0);
  uVar3 = 0;
  if ((short)uVar1 < 0) {
    uVar3 = 0xff;
  }
  puVar2[0x2f] = uVar3;
  puVar2[0x2e] = -((uVar1 & 0x4000) != 0);
  if (DAT_14033ac3c == 1) {
    puVar2[0x46] = 0;
  }
  else {
    puVar2[0x46] = (DAT_14033ac3c != 2) + '\x01';
  }
  return;
}

