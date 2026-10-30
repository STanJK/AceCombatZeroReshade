/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401363c0; RVA 0x1363c0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1401363c0(longlong *param_1,undefined1 param_2)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  int iVar7;
  ulonglong uVar8;
  
  plVar6 = (longlong *)*param_1;
  if ((*(byte *)((longlong)param_1 + 0x6d) & 1) == 0) {
    uVar8 = (ulonglong)*(byte *)((longlong)param_1 + 0x34);
    plVar5 = plVar6;
    if (plVar6 != plVar6 + uVar8) {
      do {
        lVar2 = *plVar5;
        iVar7 = 0;
        if (0 < *(int *)(lVar2 + 0x118)) {
          uVar3 = *(uint *)(param_1 + 6);
          lVar4 = 0;
          do {
            iVar7 = iVar7 + 1;
            *(uint *)(lVar4 + 0x21c + *(longlong *)(lVar2 + 0x110)) = (uint)(byte)uVar3;
            lVar4 = lVar4 + 0x520;
          } while (iVar7 < *(int *)(lVar2 + 0x118));
        }
        (**(code **)(*(longlong *)*plVar5 + 0x10))((longlong *)*plVar5,param_2);
        plVar5 = plVar5 + 1;
        plVar6 = (longlong *)*param_1;
      } while (plVar5 != plVar6 + *(byte *)((longlong)param_1 + 0x34));
      uVar8 = (ulonglong)*(byte *)((longlong)param_1 + 0x34);
    }
    if ((*(uint *)(param_1 + 6) % (uint)*(byte *)((longlong)param_1 + 0x35) == 0) &&
       (plVar6 != plVar6 + uVar8)) {
      do {
        FUN_1401338c0(*plVar6);
        plVar6 = plVar6 + 1;
      } while (plVar6 != (longlong *)(*param_1 + (ulonglong)*(byte *)((longlong)param_1 + 0x34) * 8)
              );
    }
    *(int *)(param_1 + 6) = (int)param_1[6] + 1;
  }
  else {
    lVar2 = *plVar6;
    iVar7 = 0;
    if (0 < *(int *)(lVar2 + 0x118)) {
      bVar1 = *(byte *)(param_1 + 6);
      lVar4 = 0;
      do {
        lVar4 = lVar4 + 0x520;
        iVar7 = iVar7 + 1;
        *(uint *)(*(longlong *)(lVar2 + 0x110) + -0x304 + lVar4) = (uint)bVar1;
      } while (iVar7 < *(int *)(lVar2 + 0x118));
    }
    (**(code **)(**(longlong **)*param_1 + 0x10))(*(longlong **)*param_1,param_2);
  }
  return 1;
}

