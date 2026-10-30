/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401ef720; RVA 0x1ef720
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401ef720(longlong param_1,longlong *param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = *param_4;
  lVar2 = FUN_140271d98(*(undefined8 *)(param_1 + 0x1b8),0,&PTR_PTR_140324098,&PTR_PTR_1403240c0,0);
  if (lVar2 == 0) {
    *param_2 = 1;
    return;
  }
  *param_2 = (longlong)
             *(char *)(*(longlong *)(*(longlong *)(lVar2 + 0x48) + 0x30) + 0x721 +
                      (ulonglong)uVar1 * 0x14);
  return;
}

