/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010be70; RVA 0x10be70
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14010be70(longlong param_1)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  longlong lVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  longlong unaff_GS_OFFSET;
  float fVar11;
  ulonglong uVar12;
  ulonglong extraout_XMM0_Qa;
  ulonglong extraout_XMM0_Qa_00;
  ulonglong extraout_XMM0_Qa_01;
  undefined1 auVar13 [16];
  undefined1 auVar14 [64];
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  undefined1 auVar18 [64];
  float fVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined2 local_res8 [4];
  undefined2 local_res10 [4];
  undefined4 local_b8;
  float local_b4;
  undefined4 local_b0;
  float local_ac;
  undefined1 local_a8 [8] [16];
  
  DAT_14032c480 = DAT_14032c480 + 1;
  uVar20 = *(undefined4 *)(param_1 + 0x70);
  uVar21 = *(undefined4 *)(param_1 + 0x78);
  fVar11 = (float)FUN_140079410(*(undefined8 *)(param_1 + 0x2030),uVar20,uVar21);
  fVar19 = *(float *)(param_1 + 0x1848) - DAT_1402d271c;
  fVar15 = DAT_1402d22d0;
  cVar7 = FUN_140078e50(*(undefined8 *)(param_1 + 0x2038),param_1 + 0x70,DAT_1402d20d0);
  fVar16 = DAT_1402d2034;
  if (cVar7 == '\0') {
    fVar16 = (*(float *)(param_1 + 0x74) - fVar11) * DAT_1402d1dd0;
  }
  auVar18 = ZEXT464((uint)fVar16);
  local_b8 = uVar20;
  local_b4 = fVar11;
  local_b0 = uVar21;
  local_ac = fVar15;
  uVar12 = FUN_1401c56d0();
  fVar16 = auVar18._0_4_;
  if (*(float *)(param_1 + 0x2764) <= fVar16) {
    uVar12 = FUN_1401c6490(uVar12,param_1 + 0x206c);
  }
  else if (*(char *)(param_1 + 0x278e) != '\0') {
    fVar1 = *(float *)(param_1 + 0x2768);
    uVar12 = (ulonglong)(uint)fVar1;
    local_a8[0] = *(undefined1 (*) [16])(param_1 + 0x15d0);
    auVar14 = ZEXT1664(local_a8[0]);
    if (fVar16 < fVar1) {
      auVar13._0_4_ = fVar16 / fVar1;
      auVar13._4_12_ = auVar18._4_12_;
      uVar12 = auVar13._0_8_;
      fVar15 = -(*(float *)(param_1 + 0x276c) * auVar13._0_4_) + *(float *)(param_1 + 0x276c) +
               fVar15;
    }
    uVar17 = 0;
    if (0.0 <= fVar19) {
      if (fVar19 < DAT_1402d271c) {
        uVar12 = (ulonglong)(uint)(fVar19 * DAT_1402d1ef4);
        fVar15 = fVar15 * fVar19 * DAT_1402d1ef4;
      }
    }
    else {
      fVar15 = 0.0;
    }
    if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
       (uVar17 = 0, uVar12 = FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
      FUN_1401c93c0();
      uVar12 = _Init_thread_footer(&DAT_1437daf04);
    }
    uVar5 = *(uint *)(param_1 + 0x206c);
    if ((((uVar5 == 0) || (0x7f < (ushort)uVar5)) ||
        (uVar10 = (ulonglong)(uVar5 & 0xffff),
        (short)(uVar5 >> 0x10) != *(short *)(&DAT_1437daf22 + uVar10 * 2))) ||
       (lVar8 = uVar10 * 0x78, ((&DAT_1437db130)[lVar8] & 2) == 0)) {
      cVar7 = FUN_1401c6a00(uVar12,1,0xe8,&local_b8,local_a8,uVar17,uVar17,uVar17,fVar15,0,0);
      uVar12 = extraout_XMM0_Qa;
      if (cVar7 != '\0') {
        lVar8 = FUN_1401c97a0();
        uVar5 = *(uint *)(param_1 + 0x206c);
        uVar12 = extraout_XMM0_Qa_00;
        if ((((uVar5 == 0) || (0x7f < (ushort)uVar5)) ||
            ((short)(uVar5 >> 0x10) != *(short *)(lVar8 + 2 + (ulonglong)(uVar5 & 0xffff) * 2))) &&
           ('\x01' < *(char *)(lVar8 + 0x3dc2))) {
          uVar3 = *(ushort *)(lVar8 + 0x138);
          bVar2 = *(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar3 * 0x18) + 0x4892);
          puVar9 = (undefined4 *)FUN_1401c9e60(lVar8);
          uVar12 = extraout_XMM0_Qa_01;
          if (puVar9 != (undefined4 *)0x0) {
            *puVar9 = uVar20;
            puVar9[1] = fVar11;
            puVar9[2] = uVar21;
            puVar9[4] = auVar14._0_4_;
            auVar13 = auVar14._0_16_;
            uVar20 = vextractps_avx(auVar13,1);
            puVar9[5] = uVar20;
            uVar20 = vextractps_avx(auVar13,2);
            puVar9[6] = uVar20;
            uVar20 = vextractps_avx(auVar13,3);
            puVar9[7] = uVar20;
            puVar9[0xf] = fVar15;
            *(ushort *)(puVar9 + 0x11) = uVar3;
            *(undefined2 *)((longlong)puVar9 + 0x46) = 0xe8;
            puVar9[3] = 0x3f800000;
            *(undefined8 *)(puVar9 + 8) = 0;
            puVar9[10] = 0;
            puVar9[0xb] = 0x3f800000;
            *(undefined2 *)((longlong)puVar9 + 0x4a) = 0;
            *(byte *)(puVar9 + 0x1c) = *(byte *)(puVar9 + 0x1c) & 0xef | 2;
            *(undefined4 *)(param_1 + 0x206c) = puVar9[0xe];
            if ((bVar2 & 1) == 0) {
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
      *(undefined4 *)(&DAT_1437db0c0 + uVar10 * 0xf) = uVar20;
      *(float *)((longlong)&DAT_1437db0c0 + lVar8 + 4) = fVar11;
      (&DAT_1437db0c8)[uVar10 * 0x1e] = uVar21;
      *(int *)((longlong)&DAT_1437db0cc + lVar8 + 4) = auVar14._0_4_;
      auVar13 = auVar14._0_16_;
      uVar20 = vextractps_avx(auVar13,1);
      *(undefined4 *)(&DAT_1437db0d4 + uVar10 * 0xf) = uVar20;
      uVar20 = vextractps_avx(auVar13,2);
      *(undefined4 *)((longlong)&DAT_1437db0d4 + lVar8 + 4) = uVar20;
      uVar20 = vextractps_avx(auVar13,3);
      *(undefined4 *)(&DAT_1437db0dc + uVar10 * 0xf) = uVar20;
      *(float *)(&DAT_1437db0fc + uVar10 * 0xf) = fVar15;
      *(undefined4 *)(&DAT_1437db0cc + uVar10 * 0xf) = 0x3f800000;
      *(undefined8 *)((longlong)&DAT_1437db0dc + lVar8 + 4) = 0;
      *(undefined4 *)((longlong)&DAT_1437db0e4 + lVar8 + 4) = 0;
      (&DAT_1437db0ec)[uVar10 * 0x1e] = 0x3f800000;
      *(undefined2 *)((longlong)&DAT_1437db104 + lVar8 + 6) = 0;
    }
  }
  if (((*(uint *)(param_1 + 0x1bb4) & 0x400000) == 0) || (*(char *)(param_1 + 0x2790) == '\0')) {
    *(undefined2 *)(param_1 + 0x2080) = 0xffff;
    FUN_1401c6490(uVar12,param_1 + 0x2070);
    goto LAB_14010c3a6;
  }
  sVar4 = *(short *)(param_1 + 0x2080);
  if (-1 < sVar4) {
    iVar6 = (uint)*(byte *)(param_1 + 0x20a0) * 2;
    if (iVar6 < sVar4) {
      if (*(char *)(param_1 + 0x2094) != *(char *)(param_1 + 0x20a5)) {
        uVar12 = FUN_1401c6490(iVar6,param_1 + 0x2070);
      }
      cVar7 = *(char *)(param_1 + 0x2094);
      if (cVar7 == '\0') {
        local_res10[0] = 1;
        local_res8[0] = 0xf5;
        FUN_1401c5fe0(uVar12,local_res10,local_res8,param_1 + 0x2070);
      }
      else if (cVar7 == '\x02') {
        local_res10[0] = 1;
        local_res8[0] = 0xf6;
        FUN_1401c5fe0(uVar12,local_res10,local_res8,param_1 + 0x2070);
      }
      else if (cVar7 == '\x01') {
        local_res10[0] = 1;
        local_res8[0] = 0xf7;
        FUN_1401c5fe0(uVar12,local_res10,local_res8,param_1 + 0x2070);
      }
    }
    else {
      *(short *)(param_1 + 0x2080) = sVar4 + 1;
    }
    goto LAB_14010c3a6;
  }
  cVar7 = *(char *)(param_1 + 0x2094);
  if (cVar7 == '\0') {
    local_res8[0] = 0xfe;
LAB_14010c2b6:
    local_res10[0] = 1;
    FUN_1401c6150(uVar12,local_res10,local_res8);
  }
  else {
    if (cVar7 == '\x02') {
      local_res8[0] = 0xff;
      goto LAB_14010c2b6;
    }
    if (cVar7 == '\x01') {
      local_res8[0] = 0x100;
      goto LAB_14010c2b6;
    }
  }
  *(undefined2 *)(param_1 + 0x2080) = 0;
LAB_14010c3a6:
  DAT_14032c480 = DAT_14032c480 + -1;
  return;
}

