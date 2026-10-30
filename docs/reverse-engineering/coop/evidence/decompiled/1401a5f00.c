/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401a5f00; RVA 0x1a5f00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1401a5f00(longlong *param_1)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((longlong)param_1 + 0x90c);
  FUN_1401a5ae0();
  *(ushort *)((longlong)param_1 + 0x90c) = (ushort)(bVar1 & 0xec);
  lVar2 = FUN_1401c56d0();
  if ((DAT_14031f8b1 & 1) == 0) {
    FUN_140187110((int)(char)(&DAT_14031f8a8)
                             [(longlong)
                              *(short *)(lVar2 + (ulonglong)*(byte *)((longlong)param_1 + 0x91a) * 2
                                        ) + (ulonglong)DAT_14031f8b0 * 4],0);
    if ((DAT_14031f8b1 & 1) == 0) {
      FUN_140187110((int)(char)(&DAT_14031f8a8)
                               [(longlong)
                                *(short *)(lVar2 + (ulonglong)*(byte *)((longlong)param_1 + 0x91b) *
                                                   2) + (ulonglong)DAT_14031f8b0 * 4],0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001401a5fb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x48))(param_1);
  return;
}

