/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140106f30; RVA 0x106f30
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140106f30(ulonglong param_1)

{
  float *pfVar1;
  byte bVar2;
  ulonglong arg1;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  undefined4 uVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  if ((*(byte *)(*(longlong *)
                  (*(longlong *)
                    (**(longlong **)(param_1 + 0x2040) + (ulonglong)*(byte *)(param_1 + 0x20a1) * 8)
                  + 0x110) + 0x1f0 + (ulonglong)*(byte *)(param_1 + 0x20a2) * 0x520) & 1) == 0) {
    uVar3 = FUN_1401c56d0();
    FUN_1401c6490(uVar3,param_1 + 0x205c);
  }
  else {
    *(undefined1 *)(param_1 + 0x20a5) = *(undefined1 *)(param_1 + 0x2094);
    FUN_14010f600(param_1 + 0x1430);
    uVar5 = *(undefined4 *)(param_1 + 0x17f8);
    uVar7 = *(undefined4 *)(param_1 + 0x17fc);
    uVar8 = *(undefined4 *)(param_1 + 0x1800);
    uVar9 = *(undefined4 *)(param_1 + 0x1804);
    uVar10 = *(undefined4 *)(param_1 + 0x1808);
    uVar11 = *(undefined4 *)(param_1 + 0x180c);
    uVar12 = *(undefined4 *)(param_1 + 0x1810);
    uVar13 = *(undefined4 *)(param_1 + 0x1814);
    *(undefined4 *)(param_1 + 0x70) = uVar5;
    *(undefined4 *)(param_1 + 0x74) = uVar7;
    *(undefined4 *)(param_1 + 0x78) = uVar8;
    *(undefined4 *)(param_1 + 0x7c) = uVar9;
    *(undefined4 *)(param_1 + 0x80) = uVar10;
    *(undefined4 *)(param_1 + 0x84) = uVar11;
    *(undefined4 *)(param_1 + 0x88) = uVar12;
    *(undefined4 *)(param_1 + 0x8c) = uVar13;
    if (*(char *)(param_1 + 0x2097) == '\0') {
      arg1 = param_1;
      FUN_14010b000();
      bVar2 = FUN_140187c80(arg1,'\0','\x10');
      auVar4._0_4_ = (float)bVar2;
      auVar4._4_12_ = SUB1612(ZEXT816(0),4);
      FUN_1400b7b40(param_1 + 0x1868,*(undefined8 *)(param_1 + 0x2040),
                    *(undefined8 *)(param_1 + 0x1fc8),auVar4._0_8_,0,param_1 + 0x10b0);
    }
    fVar6 = DAT_1402d1ff8;
    *(float *)(param_1 + 0x1d80) =
         (*(float *)(param_1 + 0x1650) - *(float *)(param_1 + 0x1d80)) * DAT_1402d1ff8 +
         *(float *)(param_1 + 0x1d80);
    *(float *)(param_1 + 0x1d84) =
         (*(float *)(param_1 + 0x1654) - *(float *)(param_1 + 0x1d84)) * fVar6 +
         *(float *)(param_1 + 0x1d84);
    *(float *)(param_1 + 0x1d88) =
         (*(float *)(param_1 + 0x1658) - *(float *)(param_1 + 0x1d88)) * fVar6 +
         *(float *)(param_1 + 0x1d88);
    *(float *)(param_1 + 0x1d8c) =
         (*(float *)(param_1 + 0x165c) - *(float *)(param_1 + 0x1d8c)) * DAT_1402d1fa8 +
         *(float *)(param_1 + 0x1d8c);
    *(undefined4 *)(param_1 + 0x1ce0) = uVar5;
    *(undefined4 *)(param_1 + 0x1ce4) = uVar7;
    *(undefined4 *)(param_1 + 0x1ce8) = uVar8;
    *(undefined4 *)(param_1 + 0x1cec) = uVar9;
    *(undefined4 *)(param_1 + 0x1cf0) = uVar10;
    *(undefined4 *)(param_1 + 0x1cf4) = uVar11;
    *(undefined4 *)(param_1 + 0x1cf8) = uVar12;
    *(undefined4 *)(param_1 + 0x1cfc) = uVar13;
    *(undefined1 *)(param_1 + 0x1da9) = *(undefined1 *)(param_1 + 0x1eed);
    *(undefined1 *)(param_1 + 0x1da8) = *(undefined1 *)(param_1 + 0x1eec);
    FUN_140111d40(param_1 + 0x1c50,0,*(undefined1 *)(param_1 + 0x2097));
    FUN_140155a00(param_1 + 0x110);
  }
  pfVar1 = (float *)(param_1 + 0x1d70);
  if (*(char *)(param_1 + 0x2094) == '\x02') {
    fVar6 = DAT_1402d22d0;
  }
  else {
    fVar6 = *pfVar1 * DAT_1402d1ef4;
  }
  auVar4 = *(undefined1 (*) [16])(param_1 + 0x1d10);
  *(int *)(param_1 + 0x10e0) = auVar4._0_4_;
  uVar5 = vextractps_avx(auVar4,1);
  *(undefined4 *)(param_1 + 0x10e4) = uVar5;
  uVar5 = vextractps_avx(auVar4,2);
  *(undefined4 *)(param_1 + 0x10e8) = uVar5;
  uVar5 = vextractps_avx(auVar4,3);
  *(undefined4 *)(param_1 + 0x10ec) = uVar5;
  auVar4 = *(undefined1 (*) [16])(param_1 + 0x1d20);
  *(int *)(param_1 + 0x10f0) = auVar4._0_4_;
  uVar5 = vextractps_avx(auVar4,1);
  *(undefined4 *)(param_1 + 0x10f4) = uVar5;
  uVar5 = vextractps_avx(auVar4,2);
  *(undefined4 *)(param_1 + 0x10f8) = uVar5;
  uVar5 = vextractps_avx(auVar4,3);
  *(undefined4 *)(param_1 + 0x10fc) = uVar5;
  *(float *)(param_1 + 0x10bc) = fVar6;
  *(float *)(param_1 + 0x10b8) = *pfVar1;
  FUN_1401fbec0(param_1 + 0x10b0);
  auVar4 = *(undefined1 (*) [16])(param_1 + 0x1d00);
  *(int *)(param_1 + 0x12a0) = auVar4._0_4_;
  uVar5 = vextractps_avx(auVar4,1);
  *(undefined4 *)(param_1 + 0x12a4) = uVar5;
  uVar5 = vextractps_avx(auVar4,2);
  *(undefined4 *)(param_1 + 0x12a8) = uVar5;
  uVar5 = vextractps_avx(auVar4,3);
  *(undefined4 *)(param_1 + 0x12ac) = uVar5;
  auVar4 = *(undefined1 (*) [16])(param_1 + 0x1d20);
  *(int *)(param_1 + 0x12b0) = auVar4._0_4_;
  uVar5 = vextractps_avx(auVar4,1);
  *(undefined4 *)(param_1 + 0x12b4) = uVar5;
  uVar5 = vextractps_avx(auVar4,2);
  *(undefined4 *)(param_1 + 0x12b8) = uVar5;
  uVar5 = vextractps_avx(auVar4,3);
  *(undefined4 *)(param_1 + 0x12bc) = uVar5;
  *(float *)(param_1 + 0x1278) = *pfVar1;
  *(float *)(param_1 + 0x127c) = fVar6;
  FUN_1401fbec0();
  return;
}

