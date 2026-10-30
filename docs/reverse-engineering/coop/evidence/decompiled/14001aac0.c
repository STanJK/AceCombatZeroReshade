/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001aac0; RVA 0x1aac0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14001aac0(longlong param_1,undefined4 param_2,longlong param_3,undefined8 *param_4,
                  char param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined1 auVar10 [16];
  undefined1 uVar11;
  undefined1 uVar12;
  undefined2 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [64];
  undefined1 auVar20 [16];
  undefined1 auVar21 [64];
  
  plVar6 = *(longlong **)(param_1 + 0x1a8);
  if (plVar6 != (longlong *)(param_1 + 0x1a0)) {
    plVar7 = (longlong *)plVar6[1];
    lVar8 = *plVar6;
    *plVar7 = lVar8;
    *(longlong **)(lVar8 + 8) = plVar7;
    *plVar6 = (longlong)plVar6;
    plVar6[1] = (longlong)plVar6;
    *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + -1;
    if (param_5 != '\0') {
      *(undefined4 *)(param_3 + 0x3c4) = *(undefined4 *)(param_3 + 0x1f0);
    }
    auVar18 = *(undefined1 (*) [16])(param_3 + 600);
    auVar19 = ZEXT1664(auVar18);
    auVar20 = *(undefined1 (*) [16])(param_3 + 0x268);
    auVar21 = ZEXT1664(auVar20);
    fVar15 = auVar18._0_4_ - *(float *)(param_3 + 0x288);
    auVar10 = vshufps_avx(auVar18,auVar18,0x55);
    fVar16 = auVar10._0_4_ - *(float *)(param_3 + 0x28c);
    auVar10 = vshufps_avx(auVar18,auVar18,0xaa);
    fVar17 = auVar10._0_4_ - *(float *)(param_3 + 0x290);
    if (DAT_1402d2bec < fVar17 * fVar17 + fVar16 * fVar16 + fVar15 * fVar15) {
      *(undefined4 *)(param_3 + 0x298) = *(undefined4 *)(param_3 + 0x268);
      *(undefined4 *)(param_3 + 0x29c) = *(undefined4 *)(param_3 + 0x26c);
      *(undefined4 *)(param_3 + 0x2a0) = *(undefined4 *)(param_3 + 0x270);
      *(undefined4 *)(param_3 + 0x2a4) = *(undefined4 *)(param_3 + 0x274);
      fVar15 = 0.0;
      fVar16 = 0.0;
      fVar17 = 0.0;
    }
    plVar7 = *(longlong **)(param_3 + 0x398);
    uVar13 = 0;
    if ((plVar7 != (longlong *)0x0) && (*(longlong *)(param_3 + 0x1c0) == 0)) {
      fVar14 = (float)(**(code **)(*plVar7 + 0x48))(plVar7,1);
      auVar20 = auVar21._0_16_;
      auVar18 = auVar19._0_16_;
      uVar13 = (undefined2)(int)fVar14;
    }
    lVar8 = *(longlong *)(param_3 + 0x360);
    uVar11 = 0;
    uVar12 = 0;
    if (lVar8 != 0) {
      uVar11 = (undefined1)(int)(DAT_1402d286c * *(float *)(lVar8 + 0x490));
      uVar12 = (undefined1)(int)(DAT_1402d286c * *(float *)(lVar8 + 0x494));
    }
    uVar1 = *(undefined1 *)(*(longlong *)(param_3 + 0x3d0) + 0x3f);
    uVar2 = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
    *(undefined4 *)(plVar6 + 0xc) = param_2;
    *(undefined2 *)((longlong)plVar6 + 100) = *(undefined2 *)(param_3 + 0x228);
    *(undefined1 *)((longlong)plVar6 + 0x66) = *(undefined1 *)(param_3 + 0x234);
    uVar3 = *(undefined1 *)(param_3 + 0x235);
    *(int *)(plVar6 + 4) = auVar18._0_4_;
    uVar5 = vextractps_avx(auVar18,1);
    *(undefined4 *)((longlong)plVar6 + 0x24) = uVar5;
    uVar5 = vextractps_avx(auVar18,2);
    *(undefined4 *)(plVar6 + 5) = uVar5;
    *(float *)((longlong)plVar6 + 0x2c) = fVar15;
    *(float *)(plVar6 + 6) = fVar16;
    *(float *)((longlong)plVar6 + 0x34) = fVar17;
    *(int *)((longlong)plVar6 + 0x3c) = auVar20._0_4_;
    uVar5 = vextractps_avx(auVar20,1);
    *(undefined4 *)(plVar6 + 7) = uVar5;
    uVar5 = vextractps_avx(auVar20,2);
    *(undefined4 *)(plVar6 + 8) = uVar5;
    *(char *)((longlong)plVar6 + 0x6a) = param_5;
    *(undefined1 *)((longlong)plVar6 + 0x67) = uVar3;
    *(undefined1 *)(plVar6 + 0xd) = uVar2;
    *(undefined1 *)((longlong)plVar6 + 0x69) = uVar1;
    *(undefined1 *)((longlong)plVar6 + 0x6b) = 0;
    *(undefined4 *)(plVar6 + 9) = *(undefined4 *)(param_3 + 0x298);
    *(undefined4 *)((longlong)plVar6 + 0x44) = *(undefined4 *)(param_3 + 0x29c);
    *(undefined4 *)((longlong)plVar6 + 0x4c) = *(undefined4 *)(param_3 + 0x2a0);
    *(undefined4 *)(plVar6 + 10) = *(undefined4 *)(param_3 + 0x1f0);
    *(undefined2 *)((longlong)plVar6 + 0x54) = *(undefined2 *)(param_3 + 500);
    uVar4 = *(undefined2 *)(*(longlong *)*param_4 + 0x120);
    *(undefined2 *)(plVar6 + 0xb) = uVar13;
    *(undefined2 *)((longlong)plVar6 + 0x56) = uVar4;
    *(undefined1 *)((longlong)plVar6 + 0x5a) = uVar11;
    *(undefined1 *)((longlong)plVar6 + 0x5b) = uVar12;
    *(undefined1 *)((longlong)plVar6 + 0x5c) = *(undefined1 *)(param_3 + 0x236);
    *(undefined1 *)((longlong)plVar6 + 0x5d) = *(undefined1 *)(param_3 + 0x237);
    *(undefined1 *)((longlong)plVar6 + 0x5e) = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
    lVar8 = *(longlong *)(param_3 + 0x3d8);
    if (lVar8 == 0) {
      plVar6[3] = 0;
    }
    else {
      plVar6[3] = lVar8;
      *(longlong **)(lVar8 + 0x10) = plVar6;
    }
    plVar6[2] = 0;
    *(longlong **)(param_3 + 0x3d8) = plVar6;
    puVar9 = *(undefined8 **)(param_1 + 0x28);
    *puVar9 = plVar6;
    *(longlong **)(param_1 + 0x28) = plVar6;
    *plVar6 = param_1 + 0x20;
    plVar6[1] = (longlong)puVar9;
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
  }
  return;
}

