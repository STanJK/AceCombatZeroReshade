/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140135b50; RVA 0x135b50
 * Ghidra-generated research pseudocode, inferred types, not original source. */

int FUN_140135b50(ulonglong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  ulonglong local_res8;
  
  lVar7 = 0;
  DAT_140326f81 = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  if ((param_2 == (undefined8 *)0x0) || ((byte *)*param_2 == (byte *)0x0)) {
    return 0;
  }
  bVar1 = *(byte *)*param_2;
  uVar6 = (ulonglong)bVar1;
  uVar5 = (uint)bVar1 * 8 + 8;
  if ((uVar5 & 0xf) != 0) {
    uVar5 = uVar5 + (0x10 - (uVar5 & 0xf));
  }
  iVar3 = 0;
  if (bVar1 != 0) {
    do {
      plVar8 = (longlong *)(param_2[1] + lVar7);
      cVar2 = *(char *)(*plVar8 + 0x12);
      if (cVar2 == '\x01') {
        iVar3 = FUN_14012c410(plVar8,param_3,param_4,&local_res8);
        if (*plVar8 != 0) {
          uVar4 = (uint)*(byte *)(*plVar8 + 0xc) * 8;
          if ((uVar4 & 0xf) != 0) {
            uVar4 = uVar4 + (0x10 - (uVar4 & 0xf));
          }
          iVar3 = iVar3 + uVar4;
        }
        uVar5 = uVar5 + 0x1b0 + iVar3;
      }
      else if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
        iVar3 = FUN_14012c410(plVar8,param_3,param_4,&local_res8);
        if (*plVar8 != 0) {
          uVar4 = (uint)*(byte *)(*plVar8 + 0xc) * 8;
          if ((uVar4 & 0xf) != 0) {
            uVar4 = uVar4 + (0x10 - (uVar4 & 0xf));
          }
          iVar3 = iVar3 + uVar4;
        }
        uVar5 = uVar5 + 0x1d0 + iVar3;
      }
      else {
        iVar3 = FUN_14012c410(plVar8,param_3,param_4,&local_res8);
        uVar5 = uVar5 + 0x180 + iVar3;
      }
      lVar7 = lVar7 + 0x20;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
    iVar3 = (int)local_res8;
  }
  DAT_14032c920 = iVar3;
  return iVar3 + uVar5;
}

