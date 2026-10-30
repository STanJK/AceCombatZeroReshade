/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14012c520; RVA 0x12c520
 * Ghidra-generated research pseudocode, inferred types, not original source. */

longlong FUN_14012c520(longlong param_1,longlong *param_2,undefined8 *param_3,longlong param_4,
                      undefined8 param_5,undefined8 param_6,longlong param_7)

{
  longlong lVar1;
  byte *pbVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  
  *(longlong **)(param_1 + 0x130) = param_2;
  lVar1 = *param_2;
  if (*(byte *)(lVar1 + 0xe) == 0xff) {
    param_4 = 0;
  }
  else {
    param_4 = param_4 + (ulonglong)*(byte *)(lVar1 + 0xe) * 0x28;
  }
  lVar7 = param_2[1];
  iVar3 = *(int *)(param_1 + 0x118);
  *(longlong *)(param_1 + 0x110) = param_7;
  *(longlong *)(param_1 + 0xa8) = lVar7;
  lVar7 = param_7 + (longlong)iVar3 * 0x520;
  puVar10 = (undefined8 *)param_2[1];
  if (puVar10 != (undefined8 *)0x0) {
    pbVar2 = (byte *)*puVar10;
    iVar5 = 0;
    *(longlong *)(param_1 + 0xb0) = lVar7;
    if (*pbVar2 != 0) {
      lVar8 = 0;
      do {
        iVar5 = iVar5 + 1;
        *(undefined1 *)(lVar8 + *(longlong *)(param_1 + 0xb0)) = 0;
        lVar8 = lVar8 + 1;
      } while (iVar5 < (int)(uint)*pbVar2);
      iVar3 = *(int *)(param_1 + 0x118);
    }
  }
  *(undefined8 **)(param_1 + 0xa8) = puVar10;
  uVar4 = 0;
  if (((undefined8 *)param_2[1] != (undefined8 *)0x0) &&
     (pbVar2 = *(byte **)param_2[1], pbVar2 != (byte *)0x0)) {
    uVar4 = (ulonglong)*pbVar2 + 0xf & 0xfffffffffffffff0;
  }
  lVar7 = lVar7 + uVar4;
  iVar5 = 0;
  *(undefined1 *)(param_1 + 0x15d) = *(undefined1 *)(lVar1 + 0xd);
  if (0 < iVar3) {
    do {
      lVar8 = (longlong)iVar5;
      lVar9 = lVar8 * 0x38;
      if (*(longlong *)(lVar9 + param_2[3]) != 0) {
        lVar6 = lVar8 * 0x520 + *(longlong *)(param_1 + 0x110);
        puVar10 = param_3;
        FUN_14012c1a0(lVar6);
        *(undefined1 *)(lVar6 + 0x234) = *(undefined1 *)(param_1 + 0x15c);
        *(char *)(lVar6 + 0x235) = (char)iVar5;
        *(longlong *)(lVar6 + 0x1a0) = param_2[3] + lVar9;
        *(longlong *)(lVar6 + 0x1a8) = lVar8 * 0x10 + param_2[2];
        *(longlong *)(lVar6 + 0x18) = param_1 + 0x48;
        *(undefined4 *)(lVar6 + 0x1e8) = *(undefined4 *)(lVar1 + 4);
        *(undefined4 *)(lVar6 + 0x1ec) = *(undefined4 *)(lVar1 + 8);
        param_7._0_4_ = 0;
        FUN_140114180(lVar6,param_2[1],puVar10,param_4,*(undefined1 *)(lVar1 + 0xe),param_5,param_6,
                      lVar7);
        iVar3 = FUN_140113ca0(lVar6,param_2[1],*param_3,param_4,(char)iVar5,&param_7);
        lVar7 = lVar7 + iVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x118));
  }
  return lVar7;
}

