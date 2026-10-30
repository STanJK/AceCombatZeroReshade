/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b0900; RVA 0x1b0900
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_1401b0900(longlong param_1,float *param_2)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  float fVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined1 auVar12 [64];
  float local_98;
  float local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [8];
  float fStack_80;
  undefined1 auStack_78 [16];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x6b8) + 0xa8790) & 0x1000000) == 0) {
    lVar3 = *(longlong *)
             (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
             0x110);
    bVar1 = *(byte *)(lVar3 + 0x237);
    bVar2 = *(byte *)(lVar3 + 0x236);
    if (bVar2 != 0xff && bVar1 != 0xff) {
      lVar3 = *(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)bVar2 * 8);
      lVar10 = (ulonglong)bVar1 * 0x520 + *(longlong *)(lVar3 + 0x110);
      if ((lVar10 != 0) &&
         (iVar8 = FUN_1401b7140(lVar3,lVar10,(float)DAT_14033d9d1 * DAT_1402d23a4),
         iVar8 != -0x80000000)) {
        local_48 = 0;
        uStack_40 = 0;
        uStack_38 = 0;
        uStack_30 = 0;
        _local_88 = ZEXT832(0);
        auVar12 = ZEXT1664(CONCAT124(SUB1612(ZEXT816(0),4),(float)iVar8));
        uVar11 = FUN_1401b71e0();
        FUN_1401b71e0(uVar11,local_88,lVar10,auVar12._0_8_);
        if (((float)uStack_40 - fStack_80) * ((float)uStack_40 - fStack_80) +
            (local_48._4_4_ - (float)local_88._4_4_) * (local_48._4_4_ - (float)local_88._4_4_) +
            ((float)local_48 - (float)local_88._0_4_) * ((float)local_48 - (float)local_88._0_4_) <
            DAT_1402d2c00) {
          local_58 = ZEXT416(0);
          _local_88 = ZEXT816(0);
          auStack_78 = local_58;
          local_68 = 0;
          uStack_60 = 0;
          iVar9 = FUN_140242630();
          local_98 = (float)(iVar9 % 0x2711) * DAT_1402d2c64;
          iVar9 = FUN_140242630();
          local_90 = 0;
          local_8c = 0;
          local_94 = (float)(iVar9 % 0x2711) * DAT_1402d1e18;
          FUN_140202920(local_88,&local_98);
          fVar7 = DAT_1402d2994;
          auVar6._8_8_ = uStack_60;
          auVar6._0_8_ = local_68;
          auVar4 = vshufps_avx(auVar6,auVar6,0x55);
          *param_2 = (float)local_68 * DAT_1402d2994 + local_58._0_4_;
          auVar5 = vshufps_avx(local_58,local_58,0x55);
          param_2[1] = auVar4._0_4_ * fVar7 + auVar5._0_4_;
          auVar4 = vshufps_avx(local_58,local_58,0xaa);
          auVar5 = vshufps_avx(auVar6,auVar6,0xaa);
          param_2[2] = auVar5._0_4_ * fVar7 + auVar4._0_4_;
          auVar4 = vshufps_avx(local_58,local_58,0xff);
          auVar5 = vshufps_avx(auVar6,auVar6,0xff);
          param_2[3] = auVar5._0_4_ * fVar7 + auVar4._0_4_;
          param_2[0xb] = (float)(longlong)((float)DAT_14033d9d1 * DAT_1402d2458);
          iVar9 = *(int *)(param_1 + 0x660);
          *(longlong *)(param_2 + 8) = lVar10;
          param_2[10] = (float)(iVar9 + iVar8);
          return 1;
        }
      }
    }
  }
  return 0;
}

