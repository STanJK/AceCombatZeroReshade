/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b7480; RVA 0x1b7480
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1401b7480(longlong param_1)

{
  longlong *plVar1;
  uint *puVar2;
  byte *pbVar3;
  ushort *puVar4;
  char cVar5;
  undefined8 *puVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  uint uVar9;
  int iVar10;
  uint uVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  int *piVar15;
  int iVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong unaff_GS_OFFSET;
  undefined4 uVar20;
  int local_res8;
  undefined1 local_res10 [8];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar11 = *(uint *)(param_1 + 0xa8790);
  iVar10 = 0;
  local_res8 = 0x7fffffff;
  if ((uVar11 >> 9 & 1) == 0) {
    iVar16 = 0;
    auVar7 = vpcmpeqd_avx(ZEXT416(uVar11 & 0x10),SUB6416(ZEXT464(0),0));
    auVar7 = vblendvps_avx(ZEXT416(DAT_1402d2940),ZEXT416(DAT_1402d2950),auVar7);
    auVar8 = vpcmpeqd_avx(ZEXT416(uVar11 & 0x10),SUB6416(ZEXT464(0),0));
    plVar1 = (longlong *)(param_1 + 0xa8248);
    auVar8 = vblendvps_avx(ZEXT416(DAT_1402d2928),ZEXT416(DAT_1402d293c),auVar8);
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      lVar13 = 0;
      do {
        lVar14 = *plVar1;
        lVar13 = lVar13 + 0x27a0;
        iVar16 = iVar16 + 1;
        uVar20 = auVar8._0_4_;
        *(undefined4 *)(lVar14 + -0xa3c + lVar13) = uVar20;
        *(int *)(lVar14 + -0xa38 + lVar13) = auVar7._0_4_;
        *(undefined4 *)(lVar14 + -0xa34 + lVar13) = uVar20;
        *(undefined4 *)(lVar14 + -0xbd0 + lVar13) = uVar20;
      } while (iVar16 < (int)(uint)*(byte *)(param_1 + 0xa87e4));
      uVar12 = 0;
      if (*(byte *)(param_1 + 0xa87e4) != 0) {
        do {
          uVar11 = (int)uVar12 + 1;
          lVar14 = uVar12 * 0x27a0;
          puVar2 = (uint *)(lVar14 + 0x2058 + *plVar1);
          *puVar2 = *puVar2 | 0x10;
          puVar2 = (uint *)(lVar14 + 0x2058 + *plVar1);
          *puVar2 = *puVar2 & 0xffefffff;
          lVar13 = *plVar1;
          pbVar3 = (byte *)(lVar14 + 0x1863 + lVar13);
          *pbVar3 = *pbVar3 | 1;
          *(undefined4 *)(lVar14 + 0x185c + lVar13) = 0;
          lVar13 = *plVar1;
          pbVar3 = (byte *)(lVar14 + 0x1da7 + lVar13);
          *pbVar3 = *pbVar3 | 1;
          *(undefined8 *)(lVar14 + 0x1d78 + lVar13) = 0;
          puVar2 = (uint *)(lVar14 + 0x2058 + *plVar1);
          *puVar2 = *puVar2 | 0x20;
          uVar12 = (ulonglong)uVar11;
        } while (uVar11 < *(byte *)(param_1 + 0xa87e4));
      }
    }
    *(uint *)(param_1 + 0xa8790) = *(uint *)(param_1 + 0xa8790) & 0xfffffffb;
    FUN_140080620((longlong)*(char *)(param_1 + 0xa8829) * 0xd10 + *(longlong *)(param_1 + 0x67138))
    ;
    FUN_14007b080((longlong)*(char *)(param_1 + 0xa8829) * 0x1c8 + *(longlong *)(param_1 + 0x67140))
    ;
    uVar12 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      do {
        uVar11 = (int)uVar12 + 1;
        lVar13 = *(longlong *)(param_1 + 0xa8248);
        puVar2 = (uint *)(uVar12 * 0x27a0 + 0x2058 + lVar13);
        *puVar2 = *puVar2 & 0xfffffffd;
        puVar4 = (ushort *)(uVar12 * 0x27a0 + 0x1c20 + lVar13);
        *puVar4 = *puVar4 & 0xffbf;
        uVar12 = (ulonglong)uVar11;
      } while (uVar11 < *(byte *)(param_1 + 0xa87e4));
    }
    lVar13 = FUN_140189320();
    if (*(char *)(lVar13 + 0x32) != '\0') {
      FUN_1400781c0(param_1 + 0x69598 + (longlong)*(char *)(param_1 + 0xa8829) * 0x18,
                    param_1 + 0x68f72,param_1 + 0x240);
    }
    FUN_140036fe0(*(undefined8 *)(param_1 + 0x67120));
    local_res8 = FUN_1401b9400(param_1 + 0x697b8,param_1);
    uVar11 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      lVar13 = *(longlong *)(param_1 + 0x697b8);
      do {
        lVar14 = *(longlong *)(param_1 + 0xa8248);
        lVar19 = *(longlong *)(lVar13 + (longlong)(int)uVar11 * 8);
        uVar12 = (ulonglong)uVar11;
        uVar11 = uVar11 + 1;
        lVar18 = uVar12 * 0x27a0;
        lVar17 = *(longlong *)(lVar19 + 0x110);
        *(undefined4 *)(lVar14 + 0x70 + lVar18) = *(undefined4 *)(lVar17 + 600);
        *(undefined4 *)(lVar14 + 0x74 + lVar18) = *(undefined4 *)(lVar17 + 0x25c);
        *(undefined4 *)(lVar14 + 0x78 + lVar18) = *(undefined4 *)(lVar17 + 0x260);
        *(undefined4 *)(lVar14 + 0x7c + lVar18) = *(undefined4 *)(lVar17 + 0x264);
        lVar14 = *(longlong *)(lVar19 + 0x110);
        lVar19 = *(longlong *)(param_1 + 0xa8248);
        *(undefined4 *)(lVar19 + 0x80 + lVar18) = *(undefined4 *)(lVar14 + 0x268);
        *(undefined4 *)(lVar19 + 0x84 + lVar18) = *(undefined4 *)(lVar14 + 0x26c);
        *(undefined4 *)(lVar19 + 0x88 + lVar18) = *(undefined4 *)(lVar14 + 0x270);
        *(undefined4 *)(lVar19 + 0x8c + lVar18) = *(undefined4 *)(lVar14 + 0x274);
      } while (uVar11 < *(byte *)(param_1 + 0xa87e4));
    }
    FUN_140141550(param_1 + 0x6a130);
    DAT_14033bd64 = *(undefined4 *)(param_1 + 0x69ae0);
    DAT_14033bd68 = *(undefined4 *)(param_1 + 0x69ae4);
    DAT_14033bd6c = *(undefined4 *)(param_1 + 0x69ae8);
    DAT_14033bd70 = *(undefined4 *)(param_1 + 0x69aec);
    lVar19 = (ulonglong)DAT_14033d9d2 * 0x27a0 + *(longlong *)(param_1 + 0xa8248);
    *(longlong *)(param_1 + 0x6a0b0) = lVar19;
    *(longlong *)(param_1 + 0x6a0b8) = param_1 + 0x6a130;
    *(longlong *)(param_1 + 0x6a0c8) = param_1;
    lVar13 = *(longlong *)(param_1 + 0x67170) + (longlong)*(char *)(param_1 + 0xa8829) * 0x18;
    *(longlong *)(param_1 + 0x6a0c0) = lVar13;
    lVar14 = *(longlong *)(*(longlong *)(param_1 + 0xa8318) + 0x10);
    if (((((lVar14 == 0) || (puVar6 = *(undefined8 **)(lVar14 + 0x2d8), puVar6 == (undefined8 *)0x0)
          ) || (*(byte *)*puVar6 <= *(byte *)(lVar14 + 0x3c9))) ||
        (puVar6 = (undefined8 *)(puVar6[1] + (ulonglong)*(byte *)(lVar14 + 0x3c9) * 0x48),
        puVar6 == (undefined8 *)0x0)) ||
       ((cVar5 = *(char *)*puVar6, cVar5 != '\x06' && (cVar5 != '\x04')))) {
      auVar7 = *(undefined1 (*) [16])(lVar19 + 0x70);
      local_38 = 0;
      uStack_30 = 0;
      auVar8 = vshufps_avx(auVar7,auVar7,0xaa);
      local_58 = auVar7._0_4_;
      auVar7 = vshufps_avx(auVar7,auVar7,0x55);
      local_50 = auVar8._0_4_;
      local_44 = auVar7._0_4_ + DAT_1402d2a34;
      local_4c = DAT_1402d22d0;
      local_3c = DAT_1402d22d0;
      local_54 = DAT_1402d2e9c;
      local_48 = local_58;
      local_40 = local_50;
      uVar9 = FUN_1400782c0(lVar13,&local_38,local_res10,&local_48,&local_58);
      uVar11 = *(uint *)(param_1 + 0x6a08c);
      auVar7 = vpcmpeqd_avx(ZEXT416(uVar9),SUB6416(ZEXT464(0),0));
      auVar7 = vblendvps_avx(ZEXT416(local_38._4_4_),ZEXT816(0),auVar7);
      if (auVar7._0_4_ <= *(float *)(*(longlong *)(param_1 + 0x6a0b0) + 0x74)) {
        uVar11 = uVar11 & 0xfffeffff;
      }
      else {
        uVar11 = uVar11 | 0x10000;
      }
      *(uint *)(param_1 + 0x6a08c) = uVar11;
    }
    else {
      *(uint *)(param_1 + 0x6a08c) = *(uint *)(param_1 + 0x6a08c) & 0xfffeffff;
    }
    FUN_1401aa060(param_1 + 0x69a10);
    if (*(char *)(param_1 + 0xa8827) == '\0') {
      FUN_1401bac40(param_1 + 0x671d0);
    }
    FUN_1401a9ba0(param_1 + 0x69a10,param_1);
    if (((*(char *)(param_1 + 0x671ea) == '\x01') || ((*(uint *)(param_1 + 0x6a08c) & 0x400) != 0))
       || (*(int *)(param_1 + 0x6a070) == 1)) {
      *(undefined2 *)((ulonglong)DAT_14033d9d2 * 0x27a0 + 0x208c + *(longlong *)(param_1 + 0xa8248))
           = 2;
    }
    cVar5 = *(char *)((ulonglong)DAT_14033d9d2 * 0x27a0 + 0x2094 + *(longlong *)(param_1 + 0xa8248))
    ;
    if (cVar5 == '\0') {
      if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437dad18) &&
         (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
        _DAT_1437daef0 = 0;
        _DAT_1437daee0 = _DAT_1402d3500;
        uRam00000001437daee8 = _UNK_1402d3508;
        DAT_1437daef4 = 0;
        _Init_thread_footer(&DAT_1437dad18);
      }
      DAT_1437dece8 = 0;
    }
    else if (cVar5 == '\x01') {
      if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437dad18) &&
         (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
        _DAT_1437daef0 = 0;
        _DAT_1437daee0 = _DAT_1402d3500;
        uRam00000001437daee8 = _UNK_1402d3508;
        DAT_1437daef4 = 0;
        _Init_thread_footer(&DAT_1437dad18);
      }
      DAT_1437dece8 = 2;
    }
    else if (cVar5 == '\x02') {
      if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437dad18) &&
         (FUN_14022d540(&DAT_1437dad18), DAT_1437dad18 == -1)) {
        _DAT_1437daef0 = 0;
        _DAT_1437daee0 = _DAT_1402d3500;
        uRam00000001437daee8 = _UNK_1402d3508;
        DAT_1437daef4 = 0;
        _Init_thread_footer(&DAT_1437dad18);
      }
      DAT_1437dece8 = 1;
    }
    uVar11 = 0;
    if (*(char *)(param_1 + 0xa87e4) != '\0') {
      do {
        lVar17 = (ulonglong)uVar11 * 0x27a0;
        FUN_1401075c0(*(longlong *)(param_1 + 0xa8248) + lVar17,param_1 + 0x69a10);
        lVar13 = (longlong)(int)uVar11;
        uVar11 = uVar11 + 1;
        lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x697b8) + lVar13 * 8);
        lVar14 = *(longlong *)(param_1 + 0xa8248);
        lVar19 = *(longlong *)(lVar13 + 0x110);
        *(undefined4 *)(lVar17 + 0x70 + lVar14) = *(undefined4 *)(lVar19 + 600);
        *(undefined4 *)(lVar17 + 0x74 + lVar14) = *(undefined4 *)(lVar19 + 0x25c);
        *(undefined4 *)(lVar17 + 0x78 + lVar14) = *(undefined4 *)(lVar19 + 0x260);
        *(undefined4 *)(lVar17 + 0x7c + lVar14) = *(undefined4 *)(lVar19 + 0x264);
        lVar13 = *(longlong *)(lVar13 + 0x110);
        lVar14 = *(longlong *)(param_1 + 0xa8248);
        *(undefined4 *)(lVar17 + 0x80 + lVar14) = *(undefined4 *)(lVar13 + 0x268);
        *(undefined4 *)(lVar17 + 0x84 + lVar14) = *(undefined4 *)(lVar13 + 0x26c);
        *(undefined4 *)(lVar17 + 0x88 + lVar14) = *(undefined4 *)(lVar13 + 0x270);
        *(undefined4 *)(lVar17 + 0x8c + lVar14) = *(undefined4 *)(lVar13 + 0x274);
      } while (uVar11 < *(byte *)(param_1 + 0xa87e4));
    }
  }
  else {
    *(uint *)(param_1 + 0xa8790) = uVar11 & 0xfffffdff;
    FUN_1401b8130(param_1,0);
  }
  if ((DAT_14033bd7c - _DAT_14033bd78) / 2 < (int)(uint)DAT_14033d9d1) {
    iVar10 = DAT_14033bd7c - _DAT_14033bd78;
    return (ulonglong)CONCAT31((int3)(iVar10 - (iVar10 >> 0x1f) >> 9),local_res8 < iVar10 / 2);
  }
  lVar13 = FUN_140019ef0();
  piVar15 = (int *)(lVar13 + 0x110);
  do {
    if ((*piVar15 + -0x5c <= DAT_14033bd74) &&
       (uVar11 = *piVar15 + 0x20, DAT_14033bd74 < (int)uVar11)) goto LAB_1401b7bce;
    iVar10 = iVar10 + 1;
    piVar15 = piVar15 + 1;
  } while (iVar10 < 0x20);
  uVar11 = (uint)(DAT_14033d9d1 >> 1);
  if ((int)uVar11 <= DAT_14033bd74 - _DAT_14033bd78) {
    return (ulonglong)(local_res8 < (int)((uint)(DAT_14033d9d1 >> 1) + (uint)DAT_14033d9d1));
  }
LAB_1401b7bce:
  return CONCAT71((uint7)(uint3)(uVar11 >> 8),1);
}

