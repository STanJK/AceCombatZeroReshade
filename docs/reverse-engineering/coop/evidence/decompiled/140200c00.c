/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140200c00; RVA 0x200c00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140200c00(void)

{
  char cVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  longlong *local_148;
  undefined **local_140;
  undefined8 local_138;
  undefined1 local_130;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_140 = &PTR_FUN_1402ab9f8;
  local_138 = 0;
  local_28 = _DAT_1402d31e0;
  uStack_20 = _UNK_1402d31e8;
  local_18 = 0;
  local_130 = 0;
  local_148 = (longlong *)0x0;
  FUN_1401ff340(&local_148);
  if (DAT_14032c93c == '\0') {
    puVar2 = (undefined8 *)FUN_140200de0(DAT_14032c8f8,0x48,0x10);
    *puVar2 = &PTR_FUN_1402adeb0;
    (**(code **)(*local_148 + 8))(local_148,puVar2);
    do {
      cVar1 = FUN_1401ff820(&local_148);
    } while (cVar1 == '\0');
    FUN_1401c56d0();
    iVar3 = 0;
    plVar4 = &DAT_1403569c0;
    do {
      if (*plVar4 != 0) {
        FUN_140217a90(iVar3);
      }
      iVar3 = iVar3 + 1;
      plVar4 = plVar4 + 1;
    } while (iVar3 < 0x400);
    DAT_14032d150 = 1;
    if (DAT_140359220 != (longlong *)0x0) {
      (**(code **)(*DAT_140359220 + 8))();
      if (DAT_140359220 != (longlong *)0x0) {
        (**(code **)*DAT_140359220)(DAT_140359220,1);
      }
    }
    plVar4 = DAT_14033b9a8;
    if (DAT_14033b9a8 != (longlong *)0x0) {
      DAT_14033b9a8 = (longlong *)0x0;
      (**(code **)(*plVar4 + 0x10))();
    }
    plVar4 = DAT_14033b9b0;
    if (DAT_14033b9b0 != (longlong *)0x0) {
      DAT_14033b9b0 = (longlong *)0x0;
      (**(code **)(*plVar4 + 0x10))();
    }
    if (DAT_140359228 != (undefined8 *)0x0) {
      (**(code **)*DAT_140359228)(DAT_140359228,1);
    }
    if (DAT_140358a18 != (HANDLE)0x0) {
      CloseHandle(DAT_140358a18);
    }
    if (DAT_1403589c0 != (undefined8 *)0x0) {
      (**(code **)*DAT_1403589c0)(DAT_1403589c0,1);
    }
    if (DAT_140326f82 != '\0') {
      DAT_140326f82 = '\0';
    }
    FUN_140201c00();
    FUN_14018e520();
  }
  return 0;
}

