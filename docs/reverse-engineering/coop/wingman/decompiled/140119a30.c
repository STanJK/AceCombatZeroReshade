/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140119a30; RVA 0x119a30
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140119a30(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined1 auVar3 [16];
  undefined1 uVar4;
  undefined2 uVar5;
  longlong lVar6;
  float fVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [64];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  
  lVar1 = *(longlong *)(param_1 + 0x360);
  if (lVar1 != 0) {
    lVar6 = param_1;
    FUN_1401153a0(lVar1);
    *(undefined4 *)(lVar1 + 0x3d8) = *(undefined4 *)(lVar6 + 600);
    *(undefined4 *)(lVar1 + 0x3dc) = *(undefined4 *)(lVar6 + 0x25c);
    *(undefined4 *)(lVar1 + 0x3e0) = *(undefined4 *)(lVar6 + 0x260);
    *(undefined4 *)(lVar1 + 0x3e4) = *(undefined4 *)(lVar6 + 0x264);
    *(undefined4 *)(lVar1 + 1000) = *(undefined4 *)(lVar6 + 0x268);
    *(undefined4 *)(lVar1 + 0x3ec) = *(undefined4 *)(lVar6 + 0x26c);
    *(undefined4 *)(lVar1 + 0x3f0) = *(undefined4 *)(lVar6 + 0x270);
    *(undefined4 *)(lVar1 + 0x3f4) = *(undefined4 *)(lVar6 + 0x274);
    if ((*(byte *)(lVar6 + 500) & 8) != 0) {
      auVar3 = vcmpss_avx(ZEXT816(0),ZEXT416(*(uint *)(lVar1 + 0x4a8)),2);
      auVar8 = ZEXT416(DAT_1402d2edc);
      auVar9 = ZEXT416(DAT_1402d2bd0);
      auVar3 = vblendvps_avx(auVar8,auVar9,auVar3);
      *(int *)(lVar1 + 0x4a8) = auVar3._0_4_;
      auVar3 = vcmpss_avx(ZEXT816(0),ZEXT416(*(uint *)(lVar1 + 0x4b0)),2);
      auVar3 = vblendvps_avx(auVar8,auVar9,auVar3);
      *(int *)(lVar1 + 0x4b0) = auVar3._0_4_;
      *(float *)(lVar1 + 0x4ac) =
           (*(float *)(lVar1 + 0x1ec) + *(float *)(lVar1 + 0x1e8)) * DAT_1402d2168;
      auVar3 = vcvtdq2ps_avx(ZEXT116(*(byte *)(lVar1 + 0x49c)));
      auVar8 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(lVar1 + 0x26c)));
      auVar10 = ZEXT464((uint)((DAT_1402d235c / auVar3._0_4_) * auVar8._0_4_));
      fVar7 = (float)FUN_140128d90(*(undefined4 *)(lVar1 + 0x3dc));
      *(float *)(lVar1 + 0x218) =
           auVar10._0_4_ *
           (-(SQRT(fVar7 / *(float *)(lVar1 + 0x470)) * DAT_1402d20f0) + DAT_1402d20f0) +
           auVar10._0_4_;
    }
    if ((*(byte *)(lVar1 + 0x1f0) & 1) != 0) {
      *(byte *)(lVar1 + 0x49e) = *(byte *)(lVar1 + 0x49e) & 0x7f;
      FUN_140121880(lVar1);
      if (1 < *(byte *)(lVar1 + 0x24c)) {
        FUN_140121eb0(lVar1);
      }
      if ((*(uint *)(lVar1 + 0x1f0) & 0x20000) != 0) {
        FUN_1401228b0(lVar1);
        if ((*(uint *)(lVar1 + 0x1f0) & 0x20000) != 0) {
          FUN_14012aa30(lVar1 + 600);
        }
      }
      if ((((byte)*(undefined4 *)(lVar1 + 0x1f0) & 3) == 1) && (*(longlong *)(lVar1 + 400) != 0)) {
        fVar7 = (float)FUN_140079410(*(longlong *)(lVar1 + 400),*(undefined4 *)(lVar1 + 0x3d8),
                                     *(undefined4 *)(lVar1 + 0x3e0));
        if (*(float *)(lVar1 + 0x3dc) < fVar7) {
          *(byte *)(lVar1 + 0x61c) = *(byte *)(lVar1 + 0x61c) | 1;
        }
      }
      FUN_1401295b0(lVar1 + 600);
      local_48 = *(undefined8 *)(lVar1 + 0x408);
      uStack_40 = *(undefined8 *)(lVar1 + 0x410);
      FUN_140102710(lVar1 + 0x558,&local_48,*(undefined4 *)(lVar1 + 0x468));
    }
    FUN_1401153a0(param_1,lVar1);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(lVar1 + 0x3d8);
    *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(lVar1 + 0x3dc);
    *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(lVar1 + 0x3e0);
    *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(lVar1 + 0x3e4);
    *(undefined4 *)(param_1 + 0x268) = *(undefined4 *)(lVar1 + 1000);
    *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(lVar1 + 0x3ec);
    *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(lVar1 + 0x3f0);
    *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(lVar1 + 0x3f4);
    plVar2 = *(longlong **)(param_1 + 0x3a0);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x138))(plVar2,*(undefined4 *)(lVar1 + 0x484),0);
      (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x158))();
      (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x140))
                (*(longlong **)(param_1 + 0x3a0),*(undefined4 *)(lVar1 + 0x5cc));
    }
    if ((*(byte *)(lVar1 + 0x61c) & 1) != 0) {
      uVar4 = FUN_140079920(*(undefined8 *)(param_1 + 400),param_1 + 600);
      *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) | 2;
      FUN_140117a10(param_1,uVar4);
      *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xfefffffe;
      *(byte *)(lVar1 + 0x61c) = *(byte *)(lVar1 + 0x61c) & 0xfe;
    }
    lVar6 = *(longlong *)(param_1 + 0x198);
    if (((lVar6 != 0) && (((byte)*(undefined4 *)(param_1 + 0x1f0) & 3) == 1)) &&
       (*(longlong *)(param_1 + 0x3a0) != 0)) {
      local_48 = *(undefined8 *)(param_1 + 600);
      uStack_40 = *(undefined8 *)(param_1 + 0x260);
      if (*(short *)(param_1 + 0x442) == -1) {
        local_38 = 0;
        uVar5 = FUN_140031f80(*(undefined8 *)(lVar6 + 0x66ee0),2,&local_48,0);
        *(undefined2 *)(param_1 + 0x442) = uVar5;
        if (*(longlong **)(param_1 + 0x398) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0x398) + 0x160))();
        }
      }
      else {
        uVar5 = FUN_140035b10(*(undefined8 *)(lVar6 + 0x66ee0),2,&local_48,
                              *(short *)(param_1 + 0x442),0xffff);
        *(undefined2 *)(param_1 + 0x442) = uVar5;
      }
    }
    *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(lVar1 + 0x468);
  }
  return;
}

