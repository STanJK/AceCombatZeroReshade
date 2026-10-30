/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14012c740; RVA 0x12c740
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14012c740(longlong param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  byte *pbVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  
  iVar7 = 0;
  bVar1 = *(byte *)(param_1 + 0x15c);
  *(undefined4 *)(param_1 + 0x120) = 0;
  lVar5 = **(longlong **)(param_1 + 0x140);
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    lVar8 = 0;
    do {
      *(ulonglong *)(lVar8 + 0x388 + *(longlong *)(param_1 + 0x110)) = lVar5 + (ulonglong)bVar1 * 8;
      FUN_140114c30((longlong)iVar6 * 0x520 + *(longlong *)(param_1 + 0x110));
      iVar6 = iVar6 + 1;
      lVar8 = lVar8 + 0x520;
    } while (iVar6 < *(int *)(param_1 + 0x118));
  }
  *(undefined4 *)(param_1 + 0xf7) = 0xffffff;
  *(undefined8 *)(param_1 + 0xec) = 0;
  *(undefined1 *)(param_1 + 0xf6) = 0;
  *(undefined8 *)(param_1 + 0xdc) = 0;
  *(undefined2 *)(param_1 + 0xf4) = 0;
  *(undefined2 *)(param_1 + 0xfe) = 0xffff;
  if ((((*(longlong *)(param_1 + 0xb0) != 0) &&
       (puVar2 = *(undefined8 **)(param_1 + 0xa8), puVar2 != (undefined8 *)0x0)) && (puVar2[1] != 0)
      ) && (pbVar3 = (byte *)*puVar2, *pbVar3 != 0)) {
    lVar5 = 0;
    lVar8 = 0;
    do {
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0xa8) + 8);
      puVar2 = *(undefined8 **)(lVar4 + 8 + lVar8);
      if (((puVar2 != (undefined8 *)0x0) && (**(char **)(lVar4 + lVar8) != '\0')) &&
         ((*(char *)*puVar2 == '\0' && ((longlong *)puVar2[1] != (longlong *)0x0)))) {
        lVar4 = *(longlong *)puVar2[1];
        bVar1 = *(byte *)(lVar4 + 0x3d);
        if ((bVar1 & 2) == 0) {
          *(undefined1 *)(lVar5 + *(longlong *)(param_1 + 0xb0)) = 1;
        }
        else if ((bVar1 & 4) == 0) {
          *(undefined1 *)(lVar5 + *(longlong *)(param_1 + 0xb0)) = *(undefined1 *)(lVar4 + 0x40);
        }
        else {
          *(undefined1 *)(lVar5 + *(longlong *)(param_1 + 0xb0)) = 0xff;
        }
      }
      iVar7 = iVar7 + 1;
      lVar5 = lVar5 + 1;
      lVar8 = lVar8 + 0x10;
    } while (iVar7 < (int)(uint)*pbVar3);
  }
  return;
}

