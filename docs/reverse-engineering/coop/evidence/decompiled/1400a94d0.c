/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a94d0; RVA 0xa94d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a94d0(longlong param_1,char param_2,char param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  ulonglong uVar4;
  char *pcVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 *puVar8;
  longlong unaff_GS_OFFSET;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined1 auVar12 [64];
  
  auVar12 = ZEXT464(DAT_1402d24a4);
  pcVar5 = (char *)(param_1 + 0x489);
  uVar7 = 1;
  lVar6 = 0x10;
  fVar10 = DAT_1402d2034;
  fVar11 = DAT_1402d23c0;
  do {
    if ((((*(uint *)(param_1 + 0x5c) & uVar7) != 0) && (pcVar5[-1] == param_2)) &&
       (*pcVar5 == param_3)) {
      fVar2 = *(float *)(*(longlong *)(pcVar5 + -0x11) + 0x28) - fVar11;
      fVar9 = *(float *)(pcVar5 + 3);
      if (*(float *)(pcVar5 + 3) <= fVar2) {
        *(float *)(pcVar5 + 3) = fVar2;
        fVar9 = fVar2;
      }
      *(float *)(param_1 + 0xf34) =
           (*(float *)(*(longlong *)(pcVar5 + -0x11) + 0x28) - fVar9) *
           (auVar12._0_4_ / (float)*(byte *)(param_1 + 0x30));
      FUN_1401c56d0();
      if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
        FUN_14022d540(&DAT_1437daf04);
        if (DAT_1437daf04 == -1) {
          FUN_1401c93c0();
          _Init_thread_footer(&DAT_1437daf04);
        }
      }
      if (((DAT_14032d560 != 0) && ((ushort)DAT_14032d560 < 0x80)) &&
         (uVar4 = (ulonglong)(DAT_14032d560 & 0xffff),
         DAT_14032d560._2_2_ == *(short *)(&DAT_1437daf22 + uVar4 * 2))) {
        puVar8 = &DAT_1437db0c0 + uVar4 * 0xf;
        uVar1 = (&DAT_1437db0f8)[uVar4 * 0x1e];
        if (((uVar1 != 0) && ((ushort)uVar1 < 0x80)) &&
           ((short)(uVar1 >> 0x10) == *(short *)(&DAT_1437daf22 + (ulonglong)(uVar1 & 0xffff) * 2)))
        {
          if (((&DAT_1437db130)[uVar4 * 0x78] & 8) != 0) {
            iVar3 = FUN_140184120(uVar4 * 0x78 + 0x1437db10c);
            if (iVar3 != 0) goto LAB_1400a962f;
          }
          FUN_1401c9330(&DAT_1437daf20,puVar8);
        }
      }
LAB_1400a962f:
      *(int *)(param_1 + 0xf30) = (int)(longlong)((float)*(byte *)(param_1 + 0x30) * fVar10);
      *(undefined1 *)(param_1 + 0xf38) = 1;
    }
    uVar7 = uVar7 << 1 | (uint)((int)uVar7 < 0);
    pcVar5 = pcVar5 + 0xa8;
    lVar6 = lVar6 + -1;
    if (lVar6 == 0) {
      return;
    }
  } while( true );
}

