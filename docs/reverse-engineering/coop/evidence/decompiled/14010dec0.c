/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010dec0; RVA 0x10dec0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14010dec0(longlong param_1)

{
  uint *puVar1;
  float fVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  char cVar7;
  longlong lVar8;
  undefined4 *puVar9;
  short sVar10;
  int iVar11;
  longlong unaff_GS_OFFSET;
  undefined8 uVar12;
  float fVar13;
  float fVar14;
  undefined8 local_38;
  undefined8 uStack_30;
  
  auVar6 = vmaxss_avx(ZEXT416(*(uint *)(param_1 + 0x1e28)),ZEXT416(*(uint *)(param_1 + 0x1e24)));
  auVar6 = vmaxss_avx(ZEXT416((uint)(auVar6._0_4_ * DAT_1402d21c0)),
                      ZEXT416(*(uint *)(param_1 + 0x1858)));
  DAT_14032c480 = DAT_14032c480 + 1;
  sVar10 = *(short *)(param_1 + 0x2082);
  fVar14 = 0.0;
  iVar11 = (int)((float)*(byte *)(param_1 + 0x20a0) * *(float *)(param_1 + 0x2774));
  if (auVar6._0_4_ <= 0.0) {
    if (0 < sVar10) {
      sVar10 = sVar10 + -1;
      goto LAB_14010df3e;
    }
  }
  else if (sVar10 < iVar11) {
    sVar10 = sVar10 + 1;
LAB_14010df3e:
    *(short *)(param_1 + 0x2082) = sVar10;
  }
  fVar13 = ((float)(int)sVar10 / (float)iVar11) * auVar6._0_4_;
  fVar2 = *(float *)(param_1 + 0x1848);
  if (DAT_1402d264c <= fVar2) {
    if (fVar2 < DAT_1402d2914) {
      fVar13 = fVar13 * fVar2 * DAT_1402d1e6c;
    }
  }
  else {
    fVar13 = 0.0;
  }
  if (*(char *)(param_1 + 0x278a) == '\0') {
    uVar12 = FUN_1401c56d0();
  }
  else {
    uVar12 = FUN_1401c56d0();
    puVar1 = (uint *)(param_1 + 0x2074);
    if (fVar14 < fVar13) {
      cVar7 = FUN_1401c6260(uVar12,puVar1,param_1 + 0x70);
      if (cVar7 == '\0') {
        local_38 = _DAT_1402d35f0;
        uStack_30 = _UNK_1402d35f8;
        cVar7 = FUN_1401c6a00(_DAT_1402d35f0,1,0xe7,param_1 + 0x70,&local_38,fVar14,fVar14,fVar14,
                              fVar13,0,0);
        if (cVar7 != '\0') {
          lVar8 = FUN_1401c97a0();
          uVar5 = *puVar1;
          if ((((uVar5 == 0) || (0x7f < (ushort)uVar5)) ||
              ((short)(uVar5 >> 0x10) != *(short *)(lVar8 + 2 + (ulonglong)(uVar5 & 0xffff) * 2)))
             && ('\x01' < *(char *)(lVar8 + 0x3dc2))) {
            uVar4 = *(ushort *)(lVar8 + 0x138);
            bVar3 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar4 * 0x18) + 0x4842);
            puVar9 = (undefined4 *)FUN_1401c9e60(lVar8);
            if (puVar9 != (undefined4 *)0x0) {
              *(ushort *)(puVar9 + 0x11) = uVar4;
              *(undefined2 *)((longlong)puVar9 + 0x46) = 0xe7;
              *puVar9 = *(undefined4 *)(param_1 + 0x70);
              puVar9[1] = *(undefined4 *)(param_1 + 0x74);
              puVar9[2] = *(undefined4 *)(param_1 + 0x78);
              puVar9[3] = *(undefined4 *)(param_1 + 0x7c);
              *(undefined8 *)(puVar9 + 4) = 0;
              puVar9[6] = 0;
              *(undefined8 *)(puVar9 + 9) = 0;
              *(undefined2 *)((longlong)puVar9 + 0x4a) = 0;
              *(undefined8 *)(puVar9 + 7) = 0x3f800000;
              puVar9[0xb] = 0x3f800000;
              puVar9[0xf] = fVar13;
              *(byte *)(puVar9 + 0x1c) = *(byte *)(puVar9 + 0x1c) & 0xef | 2;
              *puVar1 = puVar9[0xe];
              if ((bVar3 & 1) == 0) {
                *(byte *)(puVar9 + 0x1c) = *(byte *)(puVar9 + 0x1c) & 0xfa;
                *(code **)(puVar9 + 0xc) = FUN_1401caa00;
              }
              else {
                *(byte *)(puVar9 + 0x1c) = *(byte *)(puVar9 + 0x1c) & 0xfb | 1;
                *(code **)(puVar9 + 0xc) = FUN_1401ca740;
              }
            }
          }
        }
      }
      else {
        if (*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) {
          FUN_14022d540(&DAT_1437daf04);
          if (DAT_1437daf04 == -1) {
            FUN_1401c93c0();
            _Init_thread_footer(&DAT_1437daf04);
          }
        }
        uVar5 = *puVar1;
        if (((uVar5 != 0) && ((ushort)uVar5 < 0x80)) &&
           ((short)(uVar5 >> 0x10) == *(short *)(&DAT_1437daf22 + (ulonglong)(uVar5 & 0xffff) * 2)))
        {
          *(float *)(&DAT_1437db0fc + (ulonglong)(uVar5 & 0xffff) * 0xf) = fVar13;
        }
      }
      goto LAB_14010dfcb;
    }
  }
  FUN_1401c6490(uVar12,param_1 + 0x2074);
LAB_14010dfcb:
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

