/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400d0c40; RVA 0xd0c40
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1400d0c40(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  int *piVar5;
  longlong lVar6;
  int iVar7;
  longlong unaff_GS_OFFSET;
  
  plVar3 = *(longlong **)(param_1 + 0x697b8);
  if (plVar3 != plVar3 + *(byte *)(param_1 + 0x697ec)) {
    do {
      lVar6 = *plVar3;
      iVar7 = 0;
      if (0 < *(int *)(lVar6 + 0x118)) {
        do {
          FUN_140115a70((longlong)iVar7 * 0x520 + *(longlong *)(lVar6 + 0x110));
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(lVar6 + 0x118));
      }
      plVar3 = plVar3 + 1;
    } while (plVar3 != (longlong *)
                       (*(longlong *)(param_1 + 0x697b8) +
                       (ulonglong)*(byte *)(param_1 + 0x697ec) * 8));
  }
  iVar7 = 0;
  if (*(char *)(param_1 + 0xa87e4) != '\0') {
    lVar6 = 0;
    do {
      lVar4 = *(longlong *)(param_1 + 0xa8248) + lVar6;
      FUN_14010e220(lVar4,0);
      if ((*(longlong *)(lVar4 + 0xfd8) != 0) &&
         (*(char *)(*(longlong *)(lVar4 + 0xfd8) + 0xd) == '\b')) {
        *(undefined1 *)(lVar4 + 0x1fa1) = 0;
        *(undefined2 *)(lVar4 + 0x1f9c) = 0;
        *(undefined1 *)(lVar4 + 0x1f9e) = 0;
      }
      iVar7 = iVar7 + 1;
      lVar6 = lVar6 + 0x27a0;
    } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
  }
  piVar5 = (int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4);
  if ((*piVar5 < DAT_1437dad18) && (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  if ((*piVar5 < DAT_1437daf04) && (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
    FUN_1401c93c0();
    _Init_thread_footer(&DAT_1437daf04);
  }
  FUN_1401cb090(&DAT_1437daf20);
  if ((*piVar5 < DAT_1437dad18) && (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  if ((DAT_14031f8b1 & 1) == 0) {
    FUN_140187110((int)(char)(&DAT_14031f8a8)
                             [(longlong)DAT_1437daee6 + (ulonglong)DAT_14031f8b0 * 4],0);
  }
  if ((*piVar5 < DAT_1437dad18) && (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  if ((DAT_14031f8b1 & 1) == 0) {
    FUN_140187110((int)(char)(&DAT_14031f8a8)
                             [(longlong)DAT_1437daee0 + (ulonglong)DAT_14031f8b0 * 4],0);
  }
  if ((*piVar5 < DAT_1437dad18) && (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
    _DAT_1437daef0 = 0;
    _DAT_1437daee0 = _DAT_1402d3500;
    uRam00000001437daee8 = _UNK_1402d3508;
    DAT_1437daef4 = 0;
    _Init_thread_footer(&DAT_1437dad18);
  }
  if ((DAT_14031f8b1 & 1) == 0) {
    FUN_140187110((int)(char)(&DAT_14031f8a8)
                             [(longlong)DAT_1437daee2 + (ulonglong)DAT_14031f8b0 * 4],0);
  }
  if (*(longlong *)(param_1 + 0xa82a8) != 0) {
    FUN_1401a5f00();
  }
  FUN_1400d1110(param_1);
  *(undefined4 *)(param_1 + 0xa87c0) = 0;
  *(undefined1 *)(param_1 + 0xa87da) = 0;
  *(undefined1 *)(param_1 + 0xa87d8) = 0;
  *(undefined8 *)(param_1 + 0xa87c8) = 0;
  lVar6 = *(longlong *)(param_1 + 0x67120);
  *(undefined8 *)(lVar6 + 0x1bc48) = 0;
  *(undefined8 *)(lVar6 + 0x1bc50) = 0;
  *(undefined8 *)(lVar6 + 0x1bc58) = 0;
  *(undefined8 *)(lVar6 + 0x1bc60) = 0;
  *(undefined8 *)(lVar6 + 0x1bc68) = 0;
  *(undefined8 *)(lVar6 + 0x1bc70) = 0;
  *(undefined8 *)(lVar6 + 0x1bc78) = 0;
  *(undefined8 *)(lVar6 + 0x1bc80) = 0;
  *(int *)(lVar6 + 0x1bc8c) = *(int *)(lVar6 + 0x1bc8c) + 1;
  *(undefined4 *)(lVar6 + 0x1bc88) = 0;
  if (0xe < *(int *)(lVar6 + 0x1bc8c)) {
    *(undefined4 *)(lVar6 + 0x1bc8c) = 0;
  }
  *(undefined1 *)(*(longlong *)(param_1 + 0xa8248) + 0x60) = 0;
  plVar3 = *(longlong **)(param_1 + 0x697b8);
  lVar6 = (longlong)*(int *)(*plVar3 + 0x118);
  if (1 < lVar6) {
    lVar4 = 0x520;
    lVar6 = lVar6 + -1;
    do {
      lVar2 = *(longlong *)(*(longlong *)(*plVar3 + 0x110) + 0x1c0 + lVar4);
      if (lVar2 != 0) {
        *(undefined1 *)(lVar2 + 0xf8) = 0;
        if (*(longlong *)(lVar2 + 0x10) != 0) {
          puVar1 = (uint *)(*(longlong *)(lVar2 + 0x10) + 0x558);
          *puVar1 = *puVar1 & 0xfffffdff;
        }
      }
      lVar4 = lVar4 + 0x520;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  *(undefined4 *)(param_1 + 0x6a818) = 0;
  *(undefined4 *)(param_1 + 0x6a820) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x6a824) = 0;
  *(undefined4 *)(param_1 + 0x6b508) = 0;
  *(undefined4 *)(param_1 + 0x6b510) = 0;
  *(undefined8 *)(param_1 + 0x6b514) = 0xffffffffffffffff;
  *(undefined2 *)(param_1 + 0x6b51c) = 0xffff;
  FUN_140140b50(param_1 + 0x6bc40);
  *(undefined1 *)(param_1 + 0x89ec0) = 0;
  FUN_140103080(*(undefined8 *)(param_1 + 0xa8248));
  plVar3 = *(longlong **)(param_1 + 0xa8760);
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x18))(plVar3,*(undefined1 *)(param_1 + 0xa87e0));
    lVar6 = FUN_140189320();
    if (*(char *)(lVar6 + 0x2a) != '\0') {
      return (*(byte *)(*(longlong *)(param_1 + 0xa8760) + 0x1e) & 4) == 0;
    }
  }
  return false;
}

