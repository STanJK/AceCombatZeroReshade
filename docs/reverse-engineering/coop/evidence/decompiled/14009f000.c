/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14009f000; RVA 0x9f000
 * Ghidra-generated research pseudocode, inferred types, not original source. */

uint FUN_14009f000(longlong param_1,undefined1 (*param_2) [16],undefined1 (*param_3) [16],
                  undefined4 param_4,char param_5,char param_6,byte param_7,byte param_8,
                  undefined8 param_9)

{
  undefined1 (*pauVar1) [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined4 uVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar9 = 0;
  do {
    uVar10 = 1 << (uVar9 & 0x1f);
    if ((*(uint *)(param_1 + 0x5c) & uVar10) == 0) {
      auVar2 = *param_3;
      auVar3 = *param_2;
      pauVar1 = (undefined1 (*) [16])((ulonglong)uVar9 * 0x68 + 0x80 + param_1);
      pauVar1[5][0] = param_5;
      pauVar1[5][1] = param_6;
      *(undefined8 *)pauVar1[4] = param_9;
      *(undefined4 *)(pauVar1[4] + 8) = 0;
      *(undefined8 *)(pauVar1[5] + 4) = 0;
      *(int *)*pauVar1 = auVar3._0_4_;
      uVar4 = vextractps_avx(auVar3,1);
      *(undefined4 *)(*pauVar1 + 4) = uVar4;
      uVar4 = vextractps_avx(auVar3,2);
      *(undefined4 *)(*pauVar1 + 8) = uVar4;
      uVar4 = vextractps_avx(auVar3,3);
      *(undefined4 *)(*pauVar1 + 0xc) = uVar4;
      *(int *)pauVar1[1] = auVar2._0_4_;
      uVar4 = vextractps_avx(auVar2,1);
      *(undefined4 *)(pauVar1[1] + 4) = uVar4;
      uVar4 = vextractps_avx(auVar2,2);
      *(undefined4 *)(pauVar1[1] + 8) = uVar4;
      uVar4 = vextractps_avx(auVar2,3);
      *(undefined4 *)(pauVar1[1] + 0xc) = uVar4;
      pauVar1[5][2] = param_7;
      pauVar1[5][3] = param_8;
      *(undefined4 *)(pauVar1[4] + 0xc) = param_4;
      if ((param_5 == '\0') && (param_6 == '\0')) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      pauVar1[5][0xe] = uVar6;
      *(undefined2 *)(pauVar1[5] + 0xc) = 0xffff;
      if ((param_7 != 0xff) && (param_8 != 0xff)) {
        lVar8 = (ulonglong)param_8 * 0x520;
        lVar5 = *(longlong *)
                 (*(longlong *)(**(longlong **)(param_1 + 0x10) + (ulonglong)param_7 * 8) + 0x110);
        *(undefined4 *)pauVar1[3] = *(undefined4 *)(lVar5 + 600 + lVar8);
        *(undefined4 *)(pauVar1[3] + 4) = *(undefined4 *)(lVar5 + 0x25c + lVar8);
        *(undefined4 *)(pauVar1[3] + 8) = *(undefined4 *)(lVar5 + 0x260 + lVar8);
        *(undefined4 *)(pauVar1[3] + 0xc) = *(undefined4 *)(lVar5 + 0x264 + lVar8);
      }
      FUN_1400903a0(param_1,pauVar1);
      auVar2 = *pauVar1;
      if (*(longlong *)(param_1 + 8) != 0) {
        local_2c = DAT_1402d22d0;
        local_38 = auVar2._0_4_;
        local_34 = vextractps_avx(auVar2,1);
        local_30 = vextractps_avx(auVar2,2);
        local_28 = 1;
        uVar7 = FUN_140031f80(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x66ee0),0x30,&local_38,0
                             );
        *(undefined2 *)(pauVar1[5] + 0xc) = uVar7;
      }
      if ((param_5 == '\0') && (param_6 == '\0')) {
        *(uint *)(param_1 + 0x60) = uVar9;
      }
      *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | uVar10;
      return uVar9;
    }
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 0x10);
  return 0xffffffff;
}

