/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140093390; RVA 0x93390
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8
FUN_140093390(longlong *param_1,undefined1 (*param_2) [16],undefined8 *param_3,undefined4 *param_4,
             undefined8 param_5)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined4 local_res8 [2];
  undefined1 local_38 [16];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [16];
  
  iVar2 = (**(code **)(*param_1 + 0x10))(param_1,param_2,param_3,param_4,param_5);
  if (iVar2 == 0) {
    local_18 = *param_2;
    local_28 = local_18._0_4_ + *(float *)param_2[2];
    auVar1 = vshufps_avx(local_18,local_18,0x55);
    local_24 = auVar1._0_4_ + *(float *)(param_2[2] + 4);
    auVar1 = vshufps_avx(local_18,local_18,0xaa);
    local_20 = auVar1._0_4_ + *(float *)(param_2[2] + 8);
    auVar1 = vshufps_avx(local_18,local_18,0xff);
    local_1c = auVar1._0_4_ + *(float *)(param_2[2] + 0xc);
    local_38 = ZEXT816(0);
    iVar2 = FUN_1400782c0(param_1[3],local_38,local_res8,local_18,&local_28);
    if (iVar2 == 0) {
      return 0;
    }
    *param_3 = local_38._0_8_;
    param_3[1] = local_38._8_8_;
    *param_4 = local_res8[0];
  }
  return 1;
}

