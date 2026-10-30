/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140201dc0; RVA 0x201dc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140201dc0(void)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  
  FUN_140188a80();
  FUN_140188180();
  lVar3 = DAT_14032c8e8;
  plVar1 = DAT_14032c8c0;
  iVar7 = 0;
  lVar5 = *(longlong *)(DAT_14032c8e8 + 0x140);
  if (lVar5 == 0) {
    *(undefined1 *)(DAT_14032c8c0 + 0x10) = 0xff;
    lVar5 = 0;
    uVar4 = 0xff;
  }
  else {
    *(undefined1 *)(DAT_14032c8c0 + 0x10) = *(undefined1 *)(lVar5 + 0x2e);
    uVar4 = *(undefined1 *)(lVar5 + 0x36);
  }
  *(undefined1 *)((longlong)plVar1 + 0x82) = uVar4;
  *plVar1 = lVar5;
  lVar5 = *(longlong *)(lVar3 + 0x148);
  if (lVar5 == 0) {
    *(undefined1 *)((longlong)plVar1 + 0x81) = 0xff;
    lVar5 = 0;
    uVar4 = 0xff;
  }
  else {
    *(undefined1 *)((longlong)plVar1 + 0x81) = *(undefined1 *)(lVar5 + 0x2e);
    uVar4 = *(undefined1 *)(lVar5 + 0x36);
  }
  *(undefined1 *)((longlong)plVar1 + 0x83) = uVar4;
  plVar1[1] = lVar5;
  plVar1 = DAT_14032c8f0;
  uVar4 = 0xff;
  lVar5 = *(longlong *)(lVar3 + 0x140);
  if (lVar5 != 0) {
    uVar4 = *(undefined1 *)(lVar5 + 0x2e);
  }
  *(undefined1 *)((longlong)DAT_14032c8f0 + 0x2b6) = uVar4;
  uVar4 = 0xff;
  *plVar1 = lVar5;
  lVar5 = *(longlong *)(lVar3 + 0x148);
  if (lVar5 != 0) {
    uVar4 = *(undefined1 *)(lVar5 + 0x2e);
  }
  *(undefined1 *)((longlong)plVar1 + 0x2b7) = uVar4;
  uVar4 = 0xff;
  plVar1[1] = lVar5;
  plVar2 = DAT_14032c8d8;
  lVar5 = *(longlong *)(lVar3 + 0x140);
  if (lVar5 != 0) {
    uVar4 = *(undefined1 *)(lVar5 + 0x2e);
  }
  *(undefined1 *)((longlong)DAT_14032c8d8 + 0x74) = uVar4;
  uVar4 = 0xff;
  *plVar2 = lVar5;
  lVar5 = *(longlong *)(lVar3 + 0x148);
  if (lVar5 != 0) {
    uVar4 = *(undefined1 *)(lVar5 + 0x2e);
  }
  *(undefined1 *)((longlong)plVar2 + 0x75) = uVar4;
  plVar2[1] = lVar5;
  lVar5 = *(longlong *)(lVar3 + 0x140);
  if (lVar5 != 0) {
    uVar4 = *(undefined1 *)((longlong)plVar1 + 0x2b1);
    *(char *)(lVar5 + 0x33) = (char)plVar1[0x56];
    *(undefined1 *)(lVar5 + 0x34) = uVar4;
    *(undefined1 *)(lVar5 + 0x35) = *(undefined1 *)((longlong)plVar1 + 0x2b2);
    *(undefined2 *)(plVar1 + 0x56) = 0;
    *(undefined1 *)((longlong)plVar1 + 0x2b2) = 0xff;
  }
  lVar5 = *(longlong *)(lVar3 + 0x148);
  if (lVar5 != 0) {
    uVar4 = *(undefined1 *)((longlong)plVar1 + 0x2b4);
    *(undefined1 *)(lVar5 + 0x33) = *(undefined1 *)((longlong)plVar1 + 0x2b3);
    *(undefined1 *)(lVar5 + 0x34) = uVar4;
    *(undefined1 *)(lVar5 + 0x35) = *(undefined1 *)((longlong)plVar1 + 0x2b5);
    *(undefined2 *)((longlong)plVar1 + 0x2b3) = 0;
    *(undefined1 *)((longlong)plVar1 + 0x2b5) = 0xff;
  }
  iVar8 = 0;
  if (*(char *)(lVar3 + 0x150) != '\0') {
    puVar6 = (undefined1 *)(lVar3 + 0x33);
    do {
      if (puVar6[-5] == '\0') {
        if (puVar6[-7] == '\0') {
          DAT_14033abe1 = *puVar6;
          DAT_14033abe0 = puVar6[1];
        }
        else if (puVar6[-7] == '\x01') {
          DAT_14033ac11 = *puVar6;
          DAT_14033ac10 = puVar6[1];
        }
      }
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + 0x50;
    } while (iVar8 < (int)(uint)*(byte *)(lVar3 + 0x150));
    if (*(byte *)(lVar3 + 0x150) != 0) {
      lVar5 = lVar3 + 0x34;
      do {
        *(undefined2 *)(lVar5 + -1) = 0;
        iVar7 = iVar7 + 1;
        *(undefined1 *)(lVar5 + 1) = 0xff;
        lVar5 = lVar5 + 0x50;
      } while (iVar7 < (int)(uint)*(byte *)(lVar3 + 0x150));
    }
  }
  return;
}

