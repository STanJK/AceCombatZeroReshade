/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d1300; RVA 0xd1300
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400d1300(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong lVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  longlong lVar10;
  bool bVar11;
  
  if ((*(longlong *)(param_1 + 0xa8318) != 0) &&
     (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10), lVar10 != 0)) {
    plVar1 = *(longlong **)(param_1 + 0xa8760);
    bVar11 = (*(uint *)(lVar10 + 0x3a8) & 0x4002) != 0x4000;
    uVar5 = 500;
    if (bVar11) {
      uVar5 = 0;
    }
    uVar8 = 1000;
    if (bVar11) {
      uVar8 = 0;
    }
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x30))(plVar1,2,uVar8,uVar8);
    }
    plVar1 = *(longlong **)(param_1 + 0xa8278);
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x30))(plVar1,3,uVar5,uVar5);
    }
  }
  lVar10 = *(longlong *)(param_1 + 0x67120);
  *(undefined8 *)(lVar10 + 0x1bc48) = 0;
  *(undefined8 *)(lVar10 + 0x1bc50) = 0;
  *(undefined8 *)(lVar10 + 0x1bc58) = 0;
  *(undefined8 *)(lVar10 + 0x1bc60) = 0;
  *(undefined8 *)(lVar10 + 0x1bc68) = 0;
  *(undefined8 *)(lVar10 + 0x1bc70) = 0;
  *(undefined8 *)(lVar10 + 0x1bc78) = 0;
  *(undefined8 *)(lVar10 + 0x1bc80) = 0;
  *(int *)(lVar10 + 0x1bc8c) = *(int *)(lVar10 + 0x1bc8c) + 1;
  *(undefined4 *)(lVar10 + 0x1bc88) = 0;
  if (0xe < *(int *)(lVar10 + 0x1bc8c)) {
    *(undefined4 *)(lVar10 + 0x1bc8c) = 0;
  }
  *(undefined4 *)(param_1 + 0xa87c0) = 0;
  iVar9 = 0;
  *(undefined8 *)(param_1 + 0xa87d0) = 0;
  *(undefined2 *)(param_1 + 0xa87da) = 0;
  *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) | 4;
  DAT_140326f80 = 0;
  if (*(char *)(param_1 + 0x697ec) != '\0') {
    lVar10 = 0;
    do {
      lVar2 = *(longlong *)(param_1 + 0x697b8);
      iVar7 = 0;
      *(undefined4 *)(*(longlong *)(lVar10 + lVar2) + 0x120) =
           *(undefined4 *)(*(longlong *)(lVar10 + lVar2) + 0x168);
      lVar3 = *(longlong *)(lVar10 + lVar2);
      if (0 < *(int *)(lVar3 + 0x118)) {
        lVar6 = 0;
        do {
          lVar3 = *(longlong *)(lVar3 + 0x110);
          *(undefined4 *)(lVar3 + 0x1f0 + lVar6) = *(undefined4 *)(lVar3 + 0x448 + lVar6);
          lVar3 = *(longlong *)(lVar3 + 0x3c8 + lVar6);
          if (lVar3 != 0) {
            FUN_140010340(lVar3,0);
          }
          lVar3 = *(longlong *)(lVar10 + lVar2);
          iVar7 = iVar7 + 1;
          lVar6 = lVar6 + 0x520;
        } while (iVar7 < *(int *)(lVar3 + 0x118));
      }
      iVar9 = iVar9 + 1;
      lVar10 = lVar10 + 8;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x697ec));
  }
  FUN_1400c5160(*(undefined8 *)(param_1 + 0xa8248));
  if (*(longlong *)(param_1 + 0xa82a8) != 0) {
    FUN_1401a5f00();
  }
  if ((*(longlong *)(param_1 + 0xa8318) != 0) &&
     (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10), lVar10 != 0)) {
    uVar4 = 0;
    do {
      if ((*(char *)(param_1 + 0xa8794) == (&DAT_1402ab970)[(ulonglong)uVar4 * 2]) &&
         (*(byte *)(param_1 + 0xa87e0) + 1 == (uint)(byte)(&DAT_1402ab971)[(ulonglong)uVar4 * 2])) {
        if (*(byte *)(lVar10 + 0x3c8) < 8) {
          *(undefined1 *)(lVar10 + 0x3c8) = 8;
        }
        break;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 2);
  }
  iVar9 = 0;
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    lVar10 = 0;
    do {
      lVar2 = *(longlong *)(param_1 + 0xa8248);
      *(undefined4 *)(lVar10 + 0x2084 + lVar2) = 0;
      (**(code **)**(undefined8 **)(lVar10 + 0x1fa8 + lVar2))();
      lVar10 = lVar10 + 0x27a0;
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  return;
}

