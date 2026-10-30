/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140080620; RVA 0x80620
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140080620(longlong param_1)

{
  longlong lVar1;
  byte *pbVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined1 auStack_b8 [32];
  undefined2 local_98;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  ulonglong local_68;
  
  local_68 = DAT_140309040 ^ (ulonglong)auStack_b8;
  fVar7 = *(float *)(param_1 + 0x10);
  fVar9 = *(float *)(*(longlong *)(param_1 + 0xd08) + 0x1c);
  fVar6 = 0.0;
  if (fVar7 < fVar9) {
    if (fVar9 < *(float *)(param_1 + 0x14)) {
      lVar1 = *(longlong *)(param_1 + 8);
      fVar8 = *(float *)(param_1 + 0xc80);
      fVar10 = (fVar9 - fVar7) / (*(float *)(param_1 + 0x14) - fVar7);
      fVar7 = fVar8 * (*(float *)(lVar1 + 0x124) - *(float *)(lVar1 + 0x84)) +
              *(float *)(lVar1 + 0x84);
      fVar7 = -(fVar7 * fVar10) + fVar7;
      *(float *)(param_1 + 0xcdc) = fVar7;
      fVar9 = fVar8 * (*(float *)(lVar1 + 0x130) - *(float *)(lVar1 + 0x90)) +
              *(float *)(lVar1 + 0x90);
      fVar9 = -(fVar10 * fVar9) + fVar9;
      *(float *)(param_1 + 0xce8) = fVar9;
      fVar8 = fVar8 * (*(float *)(lVar1 + 300) - *(float *)(lVar1 + 0x8c)) +
              *(float *)(lVar1 + 0x8c);
      fVar8 = -(fVar10 * fVar8) + fVar8;
    }
    else {
      *(undefined4 *)(param_1 + 0xcdc) = 0;
      *(undefined4 *)(param_1 + 0xce8) = 0;
      fVar7 = 0.0;
      fVar8 = 0.0;
      fVar9 = 0.0;
    }
  }
  else {
    lVar1 = *(longlong *)(param_1 + 8);
    fVar8 = *(float *)(param_1 + 0xc80);
    fVar7 = fVar8 * (*(float *)(lVar1 + 0x124) - *(float *)(lVar1 + 0x84)) +
            *(float *)(lVar1 + 0x84);
    *(float *)(param_1 + 0xcdc) = fVar7;
    fVar9 = fVar8 * (*(float *)(lVar1 + 0x130) - *(float *)(lVar1 + 0x90)) +
            *(float *)(lVar1 + 0x90);
    *(float *)(param_1 + 0xce8) = fVar9;
    fVar8 = fVar8 * (*(float *)(lVar1 + 300) - *(float *)(lVar1 + 0x8c)) + *(float *)(lVar1 + 0x8c);
  }
  *(float *)(param_1 + 0xce4) = fVar8;
  lVar1 = *(longlong *)(param_1 + 8);
  fVar10 = *(float *)(param_1 + 0xc80) * (*(float *)(lVar1 + 0x128) - *(float *)(lVar1 + 0x88)) +
           *(float *)(lVar1 + 0x88);
  *(float *)(param_1 + 0xce0) = fVar10;
  local_78 = FUN_140022d10(*(undefined4 *)(lVar1 + 0x94),*(undefined4 *)(lVar1 + 0x134));
  *(undefined4 *)(param_1 + 0xcec) = local_78;
  if (((*(byte *)(param_1 + 0xc84) & 1) != 0) || (fVar7 <= fVar6)) {
    iVar4 = -1;
  }
  else {
    local_74 = 0;
    local_98 = 0xffff;
    local_88 = fVar7;
    local_84 = fVar9;
    local_80 = fVar10;
    local_7c = fVar8;
    local_70 = fVar6;
    sVar3 = FUN_140035b10(*(undefined8 *)(*(longlong *)(param_1 + 0xa98) + 0x66ee0),0x78,&local_88,
                          *(undefined2 *)(param_1 + 0xcd8));
    iVar4 = (int)sVar3;
  }
  *(int *)(param_1 + 0xcd8) = iVar4;
  pbVar2 = *(byte **)(param_1 + 0x7f8);
  uVar5 = *(int *)(param_1 + 0x930) + 1;
  *(uint *)(param_1 + 0x930) = uVar5;
  *(undefined4 *)(param_1 + 0x954) = 0;
  *(undefined4 *)(param_1 + 0x94c) = 0;
  if ((*pbVar2 & 8) == 0) {
    *(undefined4 *)(param_1 + 0x948) = 0;
  }
  else {
    fVar7 = (float)uVar5 * DAT_1402d1f20;
    *(uint *)(param_1 + 0x948) = (uint)(fVar7 * *(float *)(pbVar2 + 0x10)) ^ DAT_1402d3770;
    fVar6 = (float)((uint)(fVar7 * *(float *)(pbVar2 + 0x14)) ^ DAT_1402d3770);
  }
  *(float *)(param_1 + 0x950) = fVar6;
  if (0 < *(int *)(param_1 + 0xa80)) {
    *(uint *)(param_1 + 0xa90) = *(uint *)(param_1 + 0xa90) | 1;
  }
  *(undefined4 *)(param_1 + 0xc84) = 0;
  return;
}

