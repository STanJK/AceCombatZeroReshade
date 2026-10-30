/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14001adc0; RVA 0x1adc0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14001adc0(longlong param_1,undefined4 param_2,longlong param_3,undefined8 *param_4,
                  undefined1 param_5)

{
  undefined1 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  char cVar6;
  longlong lVar7;
  
  plVar2 = *(longlong **)(param_1 + 0x1a8);
  if (plVar2 == (longlong *)(param_1 + 0x1a0)) {
    return;
  }
  plVar3 = (longlong *)plVar2[1];
  lVar7 = *plVar2;
  *plVar3 = lVar7;
  *(longlong **)(lVar7 + 8) = plVar3;
  *plVar2 = (longlong)plVar2;
  plVar2[1] = (longlong)plVar2;
  *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + -1;
  *(longlong **)(param_3 + 0x3d0) = plVar2;
  uVar1 = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
  *(undefined4 *)(plVar2 + 0xc) = param_2;
  *(undefined2 *)((longlong)plVar2 + 100) = *(undefined2 *)(param_3 + 0x228);
  *(undefined1 *)((longlong)plVar2 + 0x66) = *(undefined1 *)(param_3 + 0x234);
  *(undefined1 *)((longlong)plVar2 + 0x67) = *(undefined1 *)(param_3 + 0x235);
  *(undefined1 *)((longlong)plVar2 + 0x6a) = param_5;
  *(undefined1 *)(plVar2 + 0xd) = uVar1;
  *(undefined1 *)((longlong)plVar2 + 0x69) = 0;
  *(undefined1 *)((longlong)plVar2 + 0x6b) = 1;
  if (*(longlong **)(param_3 + 0x1a0) == (longlong *)0x0) {
    lVar7 = 0;
  }
  else {
    lVar7 = **(longlong **)(param_3 + 0x1a0);
  }
  *(undefined2 *)(plVar2 + 4) = *(undefined2 *)(lVar7 + 0x5c);
  auVar5 = vroundss_avx(ZEXT816(0),ZEXT416(*(uint *)(param_3 + 0x41c)),2);
  *(short *)((longlong)plVar2 + 0x22) = (short)(int)auVar5._0_4_;
  *(undefined2 *)((longlong)plVar2 + 0x24) = *(undefined2 *)(lVar7 + 0x5e);
  *(undefined2 *)((longlong)plVar2 + 0x26) = *(undefined2 *)(lVar7 + 0x60);
  *(undefined2 *)(plVar2 + 5) = *(undefined2 *)(lVar7 + 0x6c);
  auVar5 = vroundss_avx(ZEXT816(0),ZEXT416(*(uint *)(param_3 + 0x410)),2);
  *(short *)((longlong)plVar2 + 0x2a) = (short)(int)auVar5._0_4_;
  *(undefined1 *)((longlong)plVar2 + 0x2d) = *(undefined1 *)(lVar7 + 0x75);
  *(undefined1 *)((longlong)plVar2 + 0x2c) = *(undefined1 *)(param_3 + 0x42b);
  *(undefined1 *)((longlong)plVar2 + 0x2e) = *(undefined1 *)(*(longlong *)*param_4 + 0x15d);
  *(undefined1 *)((longlong)plVar2 + 0x2f) = *(undefined1 *)(lVar7 + 0x6e);
  *(undefined1 *)(plVar2 + 6) = *(undefined1 *)(lVar7 + 0x6f);
  *(undefined1 *)((longlong)plVar2 + 0x31) = *(undefined1 *)(lVar7 + 0x70);
  if (**(longlong **)(param_3 + 0x1a0) != 0) {
    cVar6 = *(char *)(**(longlong **)(param_3 + 0x1a0) + 0x71);
    if (cVar6 != '\0') goto LAB_14001af27;
    if (*(char *)(param_3 + 0x42b) == '\x01') {
      cVar6 = '\x01';
      goto LAB_14001af27;
    }
    cVar6 = '\x02';
    if (*(char *)(param_3 + 0x42b) == '\x02') goto LAB_14001af27;
  }
  cVar6 = '\x03';
LAB_14001af27:
  *(char *)((longlong)plVar2 + 0x32) = cVar6;
  *(undefined1 *)((longlong)plVar2 + 0x33) = *(undefined1 *)(lVar7 + 0x72);
  *(undefined1 *)((longlong)plVar2 + 0x34) = *(undefined1 *)(lVar7 + 0x73);
  *(undefined1 *)((longlong)plVar2 + 0x35) = *(undefined1 *)(lVar7 + 0x74);
  *(undefined1 *)((longlong)plVar2 + 0x36) = *(undefined1 *)(lVar7 + 0x77);
  *(undefined1 *)((longlong)plVar2 + 0x37) = *(undefined1 *)(lVar7 + 0x78);
  *(undefined1 *)(plVar2 + 7) = *(undefined1 *)(lVar7 + 0x79);
  *(undefined1 *)((longlong)plVar2 + 0x39) = *(undefined1 *)(lVar7 + 0x7a);
  *(undefined1 *)((longlong)plVar2 + 0x3a) = *(undefined1 *)(lVar7 + 0x7b);
  *(undefined1 *)((longlong)plVar2 + 0x3b) = *(undefined1 *)(lVar7 + 0x7f);
  *(undefined1 *)((longlong)plVar2 + 0x3c) = *(undefined1 *)(lVar7 + 0x80);
  *(undefined4 *)((longlong)plVar2 + 0x3d) = 0xffffffff;
  *(undefined1 *)((longlong)plVar2 + 0x41) = 0xff;
  *(bool *)((longlong)plVar2 + 0x42) = *(longlong *)(param_3 + 0x390) != 0;
  *(undefined1 *)((longlong)plVar2 + 0x43) = *(undefined1 *)(lVar7 + 0x88);
  *(undefined2 *)((longlong)plVar2 + 0x44) = *(undefined2 *)(lVar7 + 0x82);
  *(undefined2 *)((longlong)plVar2 + 0x46) = *(undefined2 *)(lVar7 + 0x84);
  lVar7 = *(longlong *)(param_3 + 0x3d8);
  if (lVar7 == 0) {
    plVar2[3] = 0;
  }
  else {
    plVar2[3] = lVar7;
    *(longlong **)(lVar7 + 0x10) = plVar2;
  }
  plVar2[2] = 0;
  *(longlong **)(param_3 + 0x3d8) = plVar2;
  puVar4 = *(undefined8 **)(param_1 + 0x28);
  *puVar4 = plVar2;
  *(longlong **)(param_1 + 0x28) = plVar2;
  *plVar2 = param_1 + 0x20;
  plVar2[1] = (longlong)puVar4;
  *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
  return;
}

