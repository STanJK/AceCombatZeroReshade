/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a5490; RVA 0xa5490
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 * FUN_1400a5490(longlong param_1,undefined8 *param_2)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  undefined4 uVar6;
  short *psVar7;
  longlong lVar8;
  longlong lVar9;
  float fVar10;
  float fVar11;
  
  psVar7 = (short *)(param_1 + 0xce);
  lVar9 = param_1 + 0xa4;
  lVar8 = 2;
  fVar10 = 0.0;
  fVar11 = DAT_1402d277c;
  do {
    if (fVar10 < *(float *)(psVar7 + 0xcb)) {
      param_2 = (undefined8 *)FUN_1401fc350(lVar9,param_2);
      bVar2 = *(byte *)(psVar7 + 0xcd);
      sVar4 = psVar7[-1];
      bVar3 = *(byte *)(psVar7 + 0xce);
      sVar5 = *psVar7;
      *(uint *)(param_1 + 0x88) = (uint)*(byte *)((longlong)psVar7 + 0x19b);
      *(uint *)(param_1 + 0x84) = (uint)bVar2;
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(uint *)(param_1 + 0x8c) = (uint)bVar3;
      fVar1 = *(float *)(psVar7 + 0xcb);
      *(uint *)(param_1 + 0x80) = (uint)(longlong)(fVar11 * fVar1) & 0xff;
      if ((char)(longlong)(fVar11 * fVar1) != '\0') {
        *param_2 = 0x10000007;
        *(undefined4 *)(param_2 + 1) = 0;
        *(undefined4 *)((longlong)param_2 + 0xc) = 0x50000007;
        *(undefined4 *)(param_2 + 2) = 4;
        *(undefined4 *)((longlong)param_2 + 0x14) = 0x11234000;
        param_2[3] = 0xe;
        uVar6 = *(undefined4 *)(param_1 + 0x80);
        *(uint *)(param_2 + 4) =
             ((*(int *)(param_1 + 0x9c) << 2 | *(uint *)(param_1 + 0x98)) << 2 |
             *(uint *)(param_1 + 0x94)) << 2 | *(uint *)(param_1 + 0x90);
        *(undefined4 *)((longlong)param_2 + 0x24) = uVar6;
        *(undefined4 *)(param_2 + 5) = 0x43;
        *(undefined4 *)(param_2 + 6) = *(undefined4 *)(param_1 + 0xa0);
        *(undefined4 *)(param_2 + 7) = 0x46;
        *(uint *)(param_2 + 8) =
             ((*(int *)(param_1 + 0x80) << 8 | *(uint *)(param_1 + 0x8c)) << 8 |
             *(uint *)(param_1 + 0x88)) << 8 | *(uint *)(param_1 + 0x84);
        *(undefined4 *)((longlong)param_2 + 0x44) = 0x3f800000;
        *(int *)(param_2 + 0xe) =
             (0x7f8 - (int)sVar5 / 2) * 0x100000 | (0x7f8 - (int)sVar4 / 2) * 0x10;
        *(undefined4 *)(param_2 + 9) = 1;
        *(int *)(param_2 + 0xf) =
             ((int)sVar5 / 2 + 0x808) * 0x100000 | ((int)sVar4 / 2 + 0x808) * 0x10;
        *(undefined4 *)(param_2 + 10) = 0x33001;
        *(undefined4 *)(param_2 + 0xb) = 0x48;
        *(undefined4 *)(param_2 + 0xc) = 0x8001;
        *(undefined4 *)((longlong)param_2 + 100) = 0x24000000;
        param_2[0xd] = 0x55;
        *(undefined4 *)((longlong)param_2 + 0x74) = 0xfffffff;
        *(undefined4 *)((longlong)param_2 + 0x7c) = 0xfffffff;
        param_2 = param_2 + 0x10;
      }
    }
    psVar7[0xcb] = 0;
    psVar7[0xcc] = 0;
    lVar9 = lVar9 + 0x1c8;
    psVar7 = psVar7 + 0xe4;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  return param_2;
}

