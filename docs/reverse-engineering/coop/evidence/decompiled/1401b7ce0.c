/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b7ce0; RVA 0x1b7ce0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401b7ce0(longlong param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  longlong *plVar4;
  char *pcVar5;
  undefined4 *puVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  longlong unaff_GS_OFFSET;
  longlong *local_res8;
  
  piVar2 = (int *)FUN_140019ef0();
  lVar9 = *(longlong *)(**(longlong **)(param_1 + 0x697b8) + 0x110) + 600;
  pcVar5 = (char *)(param_1 + 0xa87e5);
  do {
    cVar1 = *pcVar5;
    pcVar5[(longlong)piVar2 + (0x328 - (param_1 + 0xa87e5))] = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  piVar2[5] = (uint)*(byte *)(param_1 + 0xa8794);
  *(undefined2 *)(piVar2 + 4) = *(undefined2 *)(param_1 + 0x69818);
  *(ushort *)((longlong)piVar2 + 0x12) = (ushort)*(byte *)(param_1 + 0x697ec);
  piVar3 = (int *)FUN_140019ef0();
  if (*piVar3 < 2) {
    iVar10 = 0;
    plVar4 = *(longlong **)(param_1 + 0x697b8);
    if (*(char *)(param_1 + 0x697ec) != '\0') {
      do {
        lVar9 = *plVar4;
        iVar7 = 0;
        if (0 < *(int *)(lVar9 + 0x118)) {
          puVar6 = (undefined4 *)(*(longlong *)(lVar9 + 0x110) + 0x288);
          do {
            iVar7 = iVar7 + 1;
            *puVar6 = puVar6[-0xc];
            puVar6[1] = puVar6[-0xb];
            puVar6[2] = puVar6[-10];
            puVar6[3] = puVar6[-9];
            puVar6[4] = puVar6[-8];
            puVar6[5] = puVar6[-7];
            puVar6[6] = puVar6[-6];
            puVar6[7] = puVar6[-5];
            puVar6 = puVar6 + 0x148;
          } while (iVar7 < *(int *)(lVar9 + 0x118));
        }
        iVar10 = iVar10 + 1;
        plVar4 = plVar4 + 1;
      } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x697ec));
    }
  }
  else {
    local_res8 = *(longlong **)(param_1 + 0x697b8);
    if ((*(uint *)(param_1 + 0xa8790) & 0x1000000) == 0) {
      iVar10 = 0;
      if (*(char *)(param_1 + 0x697ec) != '\0') {
        do {
          plVar4 = local_res8;
          iVar7 = 0;
          lVar8 = *(longlong *)(*local_res8 + 0x110);
          if (0 < *(int *)(*local_res8 + 0x118)) {
            do {
              FUN_14001a2a0(piVar2,*piVar2,lVar8,&local_res8,lVar9);
              iVar7 = iVar7 + 1;
              *(undefined4 *)(lVar8 + 0x288) = *(undefined4 *)(lVar8 + 600);
              *(undefined4 *)(lVar8 + 0x28c) = *(undefined4 *)(lVar8 + 0x25c);
              *(undefined4 *)(lVar8 + 0x290) = *(undefined4 *)(lVar8 + 0x260);
              *(undefined4 *)(lVar8 + 0x294) = *(undefined4 *)(lVar8 + 0x264);
              *(undefined4 *)(lVar8 + 0x298) = *(undefined4 *)(lVar8 + 0x268);
              *(undefined4 *)(lVar8 + 0x29c) = *(undefined4 *)(lVar8 + 0x26c);
              *(undefined4 *)(lVar8 + 0x2a0) = *(undefined4 *)(lVar8 + 0x270);
              *(undefined4 *)(lVar8 + 0x2a4) = *(undefined4 *)(lVar8 + 0x274);
              lVar8 = lVar8 + 0x520;
            } while (iVar7 < *(int *)(*plVar4 + 0x118));
          }
          local_res8 = plVar4 + 1;
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x697ec));
      }
    }
    else {
      lVar8 = *(longlong *)(*local_res8 + 0x110);
      FUN_14001a2a0(piVar2,*piVar2,lVar8,&local_res8,lVar9);
      *(undefined4 *)(lVar8 + 0x288) = *(undefined4 *)(lVar8 + 600);
      *(undefined4 *)(lVar8 + 0x28c) = *(undefined4 *)(lVar8 + 0x25c);
      *(undefined4 *)(lVar8 + 0x290) = *(undefined4 *)(lVar8 + 0x260);
      *(undefined4 *)(lVar8 + 0x294) = *(undefined4 *)(lVar8 + 0x264);
      *(undefined4 *)(lVar8 + 0x298) = *(undefined4 *)(lVar8 + 0x268);
      *(undefined4 *)(lVar8 + 0x29c) = *(undefined4 *)(lVar8 + 0x26c);
      *(undefined4 *)(lVar8 + 0x2a0) = *(undefined4 *)(lVar8 + 0x270);
      *(undefined4 *)(lVar8 + 0x2a4) = *(undefined4 *)(lVar8 + 0x274);
    }
  }
  if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437d9f84) &&
     (FUN_14022d540(&DAT_1437d9f84), DAT_1437d9f84 == -1)) {
    _DAT_14031e9b0 = 0;
    PTR_LOOP_14031e9a0 = (undefined *)&PTR_LOOP_14031e9a0;
    PTR_LOOP_14031e9a8 = (undefined *)&PTR_LOOP_14031e9a0;
    PTR_LOOP_14031ea18 = (undefined *)&PTR_LOOP_14031ea18;
    PTR_LOOP_14031ea20 = (undefined *)&PTR_LOOP_14031ea18;
    PTR_LOOP_14031eb20 = (undefined *)&PTR_LOOP_14031eb20;
    PTR_LOOP_14031eb28 = (undefined *)&PTR_LOOP_14031eb20;
    PTR_LOOP_14031eb98 = (undefined *)&PTR_LOOP_14031eb98;
    PTR_LOOP_14031eba0 = (undefined *)&PTR_LOOP_14031eb98;
    PTR_LOOP_14031ec10 = (undefined *)&PTR_LOOP_14031ec10;
    PTR_LOOP_14031ec18 = (undefined *)&PTR_LOOP_14031ec10;
    _DAT_14031e9b8 = 0;
    _DAT_14031ea06 = 0xffff;
    _DAT_14031ea10 = 0;
    _DAT_14031ea28 = 0;
    _DAT_14031ea30 = 0;
    _DAT_14031ea7e = 0xffff;
    _DAT_14031ea88 = 0;
    _DAT_14031eb30 = 0;
    _DAT_14031eb38 = 0;
    _DAT_14031eb86 = 0xffff;
    _DAT_14031eb90 = 0;
    _DAT_14031eba8 = 0;
    _DAT_14031ebb0 = 0;
    _DAT_14031ebfe = 0xffff;
    _DAT_14031ec08 = 0;
    _DAT_14031ec20 = (undefined1  [16])0x0;
    _DAT_14031ec76 = 0xffff;
    _DAT_14031ec80 = 0;
    _DAT_14031eda8 = 0;
    DAT_14031eca8 = 0;
    _DAT_14031eb18 = 0;
    _DAT_14031ec88 = 0;
    FUN_140019f80(&DAT_14031e980);
    _Init_thread_footer(&DAT_1437d9f84);
  }
  FUN_14001a0c0(&DAT_14031e980);
  *piVar2 = *piVar2 + 1;
  return;
}

