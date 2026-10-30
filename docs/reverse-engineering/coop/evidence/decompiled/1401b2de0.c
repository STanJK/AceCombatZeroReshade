/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401b2de0; RVA 0x1b2de0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

bool FUN_1401b2de0(float *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auVar7 [16];
  undefined4 uVar8;
  byte bVar9;
  ushort uVar10;
  uint uVar11;
  float *pfVar12;
  int iVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float local_res8;
  undefined1 local_58 [48];
  
  if (((uint)param_1[0x19f] & 1) != 0) {
    param_1[0x19f] = (float)((uint)param_1[0x19f] & 0xfffffffe);
  }
  uVar16 = 0xff;
  uVar17 = 0xff;
  lVar5 = *(longlong *)
           (*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + (ulonglong)DAT_14033d9d2 * 8) +
           0x110);
  lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x1ae) + 0xa8318) + 0x10);
  if (((*(longlong *)(lVar6 + 0x2d8) != 0) &&
      (lVar15 = *(longlong *)(*(longlong *)(lVar6 + 0x2d8) + 8), lVar15 != 0)) &&
     ((*(byte *)(lVar6 + 0x3a8) & 1) == 0)) {
    lVar6 = **(longlong **)(lVar15 + 0x20 + (ulonglong)*(byte *)(lVar6 + 0x3c9) * 0x48);
    uVar16 = (ulonglong)*(byte *)(lVar6 + 0x20);
    uVar17 = (ulonglong)*(byte *)(lVar6 + 0x21);
  }
  iVar13 = DAT_14033bd7c - DAT_14033bd74;
  lVar15 = uVar17 * 0x520;
  lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(DAT_14033d9d8 + 0x697b8) + uVar16 * 8) + 0x110);
  fVar20 = *(float *)(lVar5 + 0x260) - *(float *)(lVar15 + 0x260 + lVar6);
  cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0xff8) + 10);
  if (iVar13 < 0xf0) {
    if (*(char *)((longlong)param_1 + 0x6ea) == '\x05') {
      uVar10 = *(ushort *)(param_1 + 0x1ba);
    }
    else {
      *(undefined2 *)(param_1 + 0x1ba) = 0;
      uVar10 = 0;
    }
    fVar4 = DAT_1402d2cf8;
    local_res8 = DAT_1402d2600;
    *(undefined1 *)((longlong)param_1 + 0x6ea) = 5;
    fVar20 = *(float *)(lVar15 + 600 + lVar6);
    param_1[4] = fVar20;
    fVar1 = *(float *)(lVar15 + 0x25c + lVar6);
    param_1[5] = fVar1;
    fVar2 = *(float *)(lVar15 + 0x260 + lVar6);
    fVar21 = (float)uVar10;
    fVar19 = fVar21 * DAT_1402d2d88 - DAT_1402d25bc;
    param_1[4] = fVar21 * fVar4 + DAT_1402d2740 + fVar20;
    fVar20 = fVar21 * DAT_1402d24dc - DAT_1402d2860;
    param_1[5] = fVar19 + fVar1;
    param_1[6] = fVar20 + fVar2;
    param_1[7] = 1.0;
    fVar20 = *(float *)(lVar15 + 600 + lVar6);
    *param_1 = fVar20;
    fVar1 = *(float *)(lVar15 + 0x25c + lVar6);
    fVar20 = fVar20 + DAT_1402d2504;
    param_1[1] = fVar1;
    fVar2 = *(float *)(lVar15 + 0x260 + lVar6);
    fVar1 = fVar1 + DAT_1402d2548;
    param_1[2] = fVar2;
    fVar4 = *(float *)(lVar15 + 0x264 + lVar6);
    *param_1 = fVar20;
    param_1[2] = fVar2 + DAT_1402d27cc;
    param_1[1] = fVar1;
    param_1[3] = fVar4;
    FUN_1401b4060(param_1);
    param_1[10] = -0.24736375;
  }
  else {
    if (fVar20 <= DAT_1402d2974) {
      if (DAT_1402d28d4 < fVar20) {
        if (*(char *)((longlong)param_1 + 0x6ea) != '\x02') {
          iVar13 = FUN_140242630();
          *(undefined2 *)(param_1 + 0x1ba) = 0;
          *(char *)((longlong)param_1 + 0x6eb) = (char)iVar13 + (char)(iVar13 / 3) * -3;
        }
        *(undefined1 *)((longlong)param_1 + 0x6ea) = 2;
        if (299 < *(ushort *)(param_1 + 0x1ba)) {
          *(char *)((longlong)param_1 + 0x6eb) = *(char *)((longlong)param_1 + 0x6eb) + '\x01';
          *(undefined2 *)(param_1 + 0x1ba) = 0;
          *(byte *)((longlong)param_1 + 0x6eb) = *(byte *)((longlong)param_1 + 0x6eb) % 3;
        }
        local_res8 = DAT_1402d2674;
        fVar20 = DAT_1402d263c;
        if (*(char *)((longlong)param_1 + 0x6eb) == '\x02') {
          param_1[4] = *(float *)(lVar15 + 600 + lVar6);
          param_1[5] = *(float *)(lVar15 + 0x25c + lVar6);
          param_1[6] = *(float *)(lVar15 + 0x260 + lVar6);
          param_1[7] = *(float *)(lVar15 + 0x264 + lVar6);
          param_1[5] = param_1[5] + DAT_1402d2830;
          fVar2 = DAT_1402d2474;
          param_1[6] = param_1[6] + DAT_1402d2630;
          *param_1 = *(float *)(lVar5 + 600);
          param_1[1] = *(float *)(lVar5 + 0x25c);
          fVar1 = *(float *)(lVar5 + 0x260);
          param_1[2] = fVar1;
          fVar1 = fVar1 - DAT_1402d26f4;
          param_1[3] = *(float *)(lVar5 + 0x264);
          param_1[2] = fVar1;
          local_res8 = fVar20;
          uVar18 = FUN_1401aa420(param_1,fVar2,0x1e);
          pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
          fVar20 = *pfVar12 + *param_1;
        }
        else {
          if (*(char *)((longlong)param_1 + 0x6eb) == '\x01') {
            param_1[4] = *(float *)(lVar5 + 600);
            param_1[5] = *(float *)(lVar5 + 0x25c);
            param_1[6] = *(float *)(lVar5 + 0x260);
            param_1[7] = *(float *)(lVar5 + 0x264);
            param_1[5] = param_1[5] - DAT_1402d26a4;
            param_1[6] = param_1[6] - DAT_1402d254c;
            *param_1 = *(float *)(lVar15 + 600 + lVar6);
            fVar1 = *(float *)(lVar15 + 0x25c + lVar6);
            param_1[1] = fVar1;
            fVar2 = *(float *)(lVar15 + 0x260 + lVar6);
            fVar1 = fVar1 - DAT_1402d24e8;
            param_1[2] = fVar2;
            fVar2 = fVar2 + DAT_1402d275c;
            param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
            param_1[2] = fVar2;
            uVar8 = DAT_1402d2168;
            param_1[1] = fVar1;
            local_res8 = fVar20;
          }
          else {
            fVar20 = *(float *)(lVar15 + 600 + lVar6);
            param_1[4] = fVar20;
            fVar20 = fVar20 + DAT_1402d2518;
            param_1[5] = *(float *)(lVar15 + 0x25c + lVar6);
            param_1[6] = *(float *)(lVar15 + 0x260 + lVar6);
            param_1[7] = *(float *)(lVar15 + 0x264 + lVar6);
            param_1[4] = fVar20;
            uVar8 = DAT_1402d22d0;
            param_1[5] = param_1[5] - DAT_1402d24cc;
            param_1[6] = param_1[6] + DAT_1402d2770;
            *param_1 = *(float *)(lVar5 + 600);
            param_1[1] = *(float *)(lVar5 + 0x25c);
            param_1[2] = *(float *)(lVar5 + 0x260);
            param_1[3] = *(float *)(lVar5 + 0x264);
          }
          uVar18 = FUN_1401aa420(param_1,uVar8,2);
          pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
          fVar20 = *param_1 + *pfVar12;
        }
        *param_1 = fVar20;
        param_1[1] = pfVar12[1] + param_1[1];
        param_1[2] = pfVar12[2] + param_1[2];
        param_1[3] = pfVar12[3] + param_1[3];
        FUN_1401b4060(param_1);
        goto LAB_1401b3fcd;
      }
    }
    else if (fVar20 <= DAT_1402d29c8) {
      if (*(char *)((longlong)param_1 + 0x6ea) != '\x01') {
        bVar9 = FUN_140242630();
        *(undefined2 *)(param_1 + 0x1ba) = 0;
        *(byte *)((longlong)param_1 + 0x6eb) = bVar9 & 1;
      }
      pfVar12 = param_1 + 2;
      *(undefined1 *)((longlong)param_1 + 0x6ea) = 1;
      fVar20 = *(float *)(lVar15 + 600 + lVar6);
      param_1[4] = fVar20;
      param_1[5] = *(float *)(lVar15 + 0x25c + lVar6);
      param_1[6] = *(float *)(lVar15 + 0x260 + lVar6);
      param_1[7] = *(float *)(lVar15 + 0x264 + lVar6);
      local_res8 = DAT_1402d2678;
      fVar1 = DAT_1402d2620;
      if ((*(byte *)((longlong)param_1 + 0x6eb) & 1) == 0) {
        fVar1 = param_1[5] + DAT_1402d283c;
        param_1[4] = fVar20 - DAT_1402d287c;
        param_1[6] = param_1[6] - DAT_1402d28f8;
        param_1[5] = fVar1;
        *param_1 = *(float *)(lVar5 + 600);
        param_1[1] = *(float *)(lVar5 + 0x25c);
        fVar20 = *(float *)(lVar5 + 0x260);
        *pfVar12 = fVar20;
        fVar20 = fVar20 - DAT_1402d2890;
        param_1[3] = *(float *)(lVar5 + 0x264);
        *pfVar12 = fVar20;
        uVar14 = ((uint)DAT_14033d9d1 * 0x1e) / 0x3c;
        if (uVar14 == 0) {
          uVar14 = 1;
        }
        if ((*(byte *)((longlong)param_1 + 0x6ed) != uVar14) || (DAT_1402d2474 != param_1[0x1bc])) {
          *(char *)((longlong)param_1 + 0x6ed) = (char)uVar14;
          *(undefined1 *)((longlong)param_1 + 0x6ee) = 0;
          param_1[0x1bc] = 5.0;
          param_1[0x176] = 0.0;
          param_1[0x177] = 0.0;
          param_1[0x178] = 0.0;
          param_1[0x179] = 0.0;
          param_1[0x17e] = 0.0;
          param_1[0x17f] = 0.0;
          param_1[0x180] = 0.0;
          param_1[0x181] = 0.0;
          param_1[0x17a] = 0.0;
          param_1[0x17b] = 0.0;
          param_1[0x17c] = 0.0;
          param_1[0x17d] = 0.0;
        }
        pfVar12 = (float *)FUN_1401aa540(param_1,local_58);
        fVar20 = *param_1 + *pfVar12;
      }
      else {
        fVar2 = param_1[5] - DAT_1402d2800;
        param_1[4] = fVar20 + DAT_1402d28ac;
        param_1[6] = param_1[6] + DAT_1402d29e0;
        param_1[5] = fVar2;
        *param_1 = *(float *)(lVar5 + 600);
        param_1[1] = *(float *)(lVar5 + 0x25c);
        fVar20 = *(float *)(lVar5 + 0x260);
        *pfVar12 = fVar20;
        fVar20 = fVar20 - DAT_1402d27bc;
        param_1[3] = *(float *)(lVar5 + 0x264);
        *pfVar12 = fVar20;
        uVar14 = ((uint)DAT_14033d9d1 * 0x1e) / 0x3c;
        if (uVar14 == 0) {
          uVar14 = 1;
        }
        if ((*(byte *)((longlong)param_1 + 0x6ed) != uVar14) || (DAT_1402d2474 != param_1[0x1bc])) {
          *(char *)((longlong)param_1 + 0x6ed) = (char)uVar14;
          *(undefined1 *)((longlong)param_1 + 0x6ee) = 0;
          param_1[0x1bc] = 5.0;
          param_1[0x176] = 0.0;
          param_1[0x177] = 0.0;
          param_1[0x178] = 0.0;
          param_1[0x179] = 0.0;
          param_1[0x17e] = 0.0;
          param_1[0x17f] = 0.0;
          param_1[0x180] = 0.0;
          param_1[0x181] = 0.0;
          param_1[0x17a] = 0.0;
          param_1[0x17b] = 0.0;
          param_1[0x17c] = 0.0;
          param_1[0x17d] = 0.0;
        }
        local_res8 = fVar1;
        pfVar12 = (float *)FUN_1401aa540(param_1,local_58);
        fVar20 = *pfVar12 + *param_1;
      }
      *param_1 = fVar20;
      param_1[1] = pfVar12[1] + param_1[1];
      param_1[2] = pfVar12[2] + param_1[2];
      param_1[3] = pfVar12[3] + param_1[3];
      FUN_1401b4060(param_1);
      goto LAB_1401b3fcd;
    }
    if (iVar13 < 0x1e0) {
      if (*(char *)((longlong)param_1 + 0x6ea) == '\x04') {
        uVar10 = *(ushort *)(param_1 + 0x1ba);
      }
      else {
        bVar9 = FUN_140242630();
        *(undefined2 *)(param_1 + 0x1ba) = 0;
        *(byte *)((longlong)param_1 + 0x6eb) = bVar9 & 1;
        uVar10 = 0;
      }
      *(undefined1 *)((longlong)param_1 + 0x6ea) = 4;
      param_1[4] = *(float *)(lVar15 + 600 + lVar6);
      param_1[5] = *(float *)(lVar15 + 0x25c + lVar6);
      param_1[6] = *(float *)(lVar15 + 0x260 + lVar6);
      param_1[7] = *(float *)(lVar15 + 0x264 + lVar6);
      fVar20 = DAT_1402d2d28;
      local_res8 = DAT_1402d26b8;
      fVar1 = DAT_1402d2678;
      if (cVar3 == '\x01') {
        param_1[4] = (float)uVar10 * DAT_1402d21f4 + DAT_1402d2700 + param_1[4];
        param_1[5] = param_1[5] - DAT_1402d288c;
        param_1[6] = param_1[6] + DAT_1402d2744;
        param_1[7] = 1.0;
        fVar1 = *(float *)(lVar15 + 600 + lVar6);
        *param_1 = fVar1;
        fVar2 = *(float *)(lVar15 + 0x25c + lVar6);
        fVar1 = fVar1 + DAT_1402d24d4;
        param_1[1] = fVar2;
        fVar4 = *(float *)(lVar15 + 0x260 + lVar6);
        fVar2 = fVar2 - DAT_1402d21a4;
        param_1[2] = fVar4;
        param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
        *param_1 = fVar1;
        param_1[2] = fVar4 + DAT_1402d2768;
        param_1[1] = fVar2;
      }
      else {
        param_1[4] = param_1[4] - DAT_1402d27b4;
        fVar20 = (float)uVar10 * DAT_1402d2070 + DAT_1402d2864;
        param_1[5] = param_1[5] - DAT_1402d27ec;
        param_1[6] = fVar20 + param_1[6];
        param_1[7] = 1.0;
        fVar20 = *(float *)(lVar15 + 600 + lVar6);
        *param_1 = fVar20;
        fVar2 = *(float *)(lVar15 + 0x25c + lVar6);
        fVar20 = fVar20 - DAT_1402d24d4;
        param_1[1] = fVar2;
        fVar4 = *(float *)(lVar15 + 0x260 + lVar6);
        fVar2 = fVar2 - DAT_1402d21a4;
        param_1[2] = fVar4;
        param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
        *param_1 = fVar20;
        fVar4 = fVar4 + DAT_1402d2758;
        param_1[1] = fVar2;
        uVar8 = DAT_1402d241c;
        param_1[2] = fVar4;
        local_res8 = fVar1;
        uVar18 = FUN_1401aa420(param_1,uVar8,0x1e);
        pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
        fVar20 = DAT_1402d212c;
        *param_1 = *pfVar12 + *param_1;
        param_1[1] = pfVar12[1] + param_1[1];
        param_1[2] = pfVar12[2] + param_1[2];
        param_1[3] = pfVar12[3] + param_1[3];
      }
      FUN_1401b4060(param_1);
      param_1[10] = fVar20;
    }
    else if ((fVar20 <= DAT_1402d26d4) || (DAT_1402d28d4 < fVar20)) {
      if (*(char *)((longlong)param_1 + 0x6ea) != '\0') {
        bVar9 = FUN_140242630();
        *(undefined2 *)(param_1 + 0x1ba) = 0;
        *(byte *)((longlong)param_1 + 0x6eb) = bVar9 & 1;
      }
      *(undefined1 *)((longlong)param_1 + 0x6ea) = 0;
    }
    else {
      if (*(char *)((longlong)param_1 + 0x6ea) == '\x03') {
        uVar10 = *(ushort *)(param_1 + 0x1ba);
      }
      else {
        *(undefined1 *)((longlong)param_1 + 0x6eb) = 0;
        uVar10 = 0;
        *(undefined2 *)(param_1 + 0x1ba) = 0;
      }
      *(undefined1 *)((longlong)param_1 + 0x6ea) = 3;
      local_res8 = DAT_1402d269c;
      fVar20 = DAT_1402d24c4;
      if (iVar13 - 0x2d1U < 300) {
        fVar20 = *(float *)(lVar15 + 600 + lVar6);
        param_1[4] = fVar20;
        param_1[5] = *(float *)(lVar15 + 0x25c + lVar6);
        param_1[6] = *(float *)(lVar15 + 0x260 + lVar6);
        param_1[7] = *(float *)(lVar15 + 0x264 + lVar6);
        fVar1 = DAT_1402d2678;
        local_res8 = DAT_1402d2674;
        if (cVar3 == '\0') {
          fVar1 = param_1[5] - DAT_1402d25cc;
          param_1[4] = fVar20 - DAT_1402d26c4;
          fVar20 = param_1[6] + DAT_1402d285c;
          param_1[5] = fVar1;
          param_1[6] = fVar20;
          *param_1 = *(float *)(lVar15 + 600 + lVar6);
          fVar20 = *(float *)(lVar15 + 0x25c + lVar6);
          param_1[1] = fVar20;
          fVar1 = *(float *)(lVar15 + 0x260 + lVar6);
          fVar20 = fVar20 - DAT_1402d2608;
          param_1[2] = fVar1;
          fVar1 = fVar1 + DAT_1402d280c;
          param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
          param_1[2] = fVar1;
          uVar8 = DAT_1402d241c;
          param_1[1] = fVar20;
          uVar18 = FUN_1401aa420(param_1,uVar8,0xf);
          pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
          *param_1 = *pfVar12 + *param_1;
          param_1[1] = pfVar12[1] + param_1[1];
          param_1[2] = pfVar12[2] + param_1[2];
          param_1[3] = pfVar12[3] + param_1[3];
          FUN_1401b4060(param_1);
          *(undefined2 *)(param_1 + 0x1ba) = 0;
        }
        else {
          fVar2 = param_1[5] - DAT_1402d25fc;
          param_1[4] = fVar20 + DAT_1402d26ac;
          fVar20 = param_1[6] + DAT_1402d28a8;
          param_1[5] = fVar2;
          param_1[6] = fVar20;
          *param_1 = *(float *)(lVar15 + 600 + lVar6);
          fVar20 = *(float *)(lVar15 + 0x25c + lVar6);
          param_1[1] = fVar20;
          fVar2 = *(float *)(lVar15 + 0x260 + lVar6);
          fVar20 = fVar20 - DAT_1402d2628;
          param_1[2] = fVar2;
          fVar2 = fVar2 + DAT_1402d2850;
          param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
          param_1[2] = fVar2;
          uVar8 = DAT_1402d236c;
          param_1[1] = fVar20;
          local_res8 = fVar1;
          uVar18 = FUN_1401aa420(param_1,uVar8,0xf);
          pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
          *param_1 = *pfVar12 + *param_1;
          param_1[1] = pfVar12[1] + param_1[1];
          param_1[2] = pfVar12[2] + param_1[2];
          param_1[3] = pfVar12[3] + param_1[3];
          FUN_1401b4060(param_1);
          param_1[10] = param_1[10] - DAT_1402d2088;
          *(undefined2 *)(param_1 + 0x1ba) = 0;
        }
      }
      else if (iVar13 - 0x1e1U < 0xf0) {
        fVar1 = *(float *)(lVar15 + 600 + lVar6);
        param_1[4] = fVar1;
        fVar2 = *(float *)(lVar15 + 0x25c + lVar6);
        param_1[5] = fVar2;
        fVar4 = *(float *)(lVar15 + 0x260 + lVar6);
        fVar21 = (float)uVar10;
        fVar19 = fVar21 * DAT_1402d2d38 + DAT_1402d2888;
        param_1[4] = (fVar21 * fVar20 - DAT_1402d298c) + fVar1;
        uVar14 = DAT_1402d2594;
        fVar20 = fVar21 * DAT_1402d2450 - DAT_1402d27c4;
        param_1[5] = fVar19 + fVar2;
        param_1[6] = fVar20 + fVar4;
        param_1[7] = 1.0;
        *param_1 = *(float *)(lVar15 + 600 + lVar6);
        fVar20 = *(float *)(lVar15 + 0x25c + lVar6);
        param_1[1] = fVar20;
        fVar1 = *(float *)(lVar15 + 0x260 + lVar6);
        param_1[2] = fVar1;
        param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
        uVar11 = (uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x1a8) + 0xff8) + 10);
        auVar7 = vpcmpeqd_avx(ZEXT416(uVar11),SUB6416(ZEXT464(0),0));
        auVar7 = vblendvps_avx(ZEXT416(DAT_1402d25d0),ZEXT416(uVar14),auVar7);
        param_1[1] = auVar7._0_4_ + fVar20;
        auVar7 = vpcmpeqd_avx(ZEXT416(uVar11),SUB6416(ZEXT464(0),0));
        auVar7 = vblendvps_avx(ZEXT416(DAT_1402d2810),ZEXT416(DAT_1402d2794),auVar7);
        param_1[2] = auVar7._0_4_ + fVar1;
        uVar18 = FUN_1401aa420(param_1,DAT_1402d241c,0x14);
        pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
        *param_1 = *pfVar12 + *param_1;
        param_1[1] = pfVar12[1] + param_1[1];
        param_1[2] = pfVar12[2] + param_1[2];
        param_1[3] = pfVar12[3] + param_1[3];
        FUN_1401b4060(param_1);
        param_1[10] = -0.21;
      }
      else {
        fVar20 = *(float *)(lVar15 + 600 + lVar6);
        param_1[4] = fVar20;
        fVar1 = *(float *)(lVar15 + 0x25c + lVar6);
        param_1[5] = fVar1;
        fVar2 = *(float *)(lVar15 + 0x260 + lVar6);
        param_1[6] = fVar2;
        param_1[7] = *(float *)(lVar15 + 0x264 + lVar6);
        fVar19 = DAT_1402d2674;
        local_res8 = DAT_1402d263c;
        fVar4 = DAT_1402d25d4;
        if (*(char *)((longlong)param_1 + 0x6eb) == '\0') {
          fVar1 = fVar1 - DAT_1402d258c;
          param_1[4] = fVar20 + DAT_1402d2910;
          fVar2 = fVar2 + DAT_1402d27d4;
          param_1[5] = fVar1;
          param_1[6] = fVar2;
          *param_1 = *(float *)(lVar15 + 600 + lVar6);
          fVar20 = *(float *)(lVar15 + 0x25c + lVar6);
          param_1[1] = fVar20;
          fVar1 = *(float *)(lVar15 + 0x260 + lVar6);
          fVar20 = fVar20 - DAT_1402d245c;
          param_1[2] = fVar1;
          fVar1 = fVar1 + DAT_1402d27b8;
          param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
          param_1[2] = fVar1;
          uVar8 = DAT_1402d241c;
          param_1[1] = fVar20;
          local_res8 = fVar19;
          uVar18 = FUN_1401aa420(param_1,uVar8,0x1e);
          pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
          *param_1 = *pfVar12 + *param_1;
          param_1[1] = pfVar12[1] + param_1[1];
          param_1[2] = pfVar12[2] + param_1[2];
          param_1[3] = pfVar12[3] + param_1[3];
          FUN_1401b4060(param_1);
          param_1[10] = -0.3;
          if (300 < *(ushort *)(param_1 + 0x1ba)) {
            *(undefined1 *)((longlong)param_1 + 0x6eb) = 1;
            *(undefined2 *)(param_1 + 0x1ba) = 0;
          }
        }
        else {
          if (cVar3 == '\0') {
            fVar1 = param_1[5] - DAT_1402d24e0;
            param_1[4] = fVar20 - DAT_1402d23d0;
            param_1[6] = param_1[6] + DAT_1402d2754;
            param_1[5] = fVar1;
            fVar20 = *(float *)(lVar15 + 600 + lVar6);
            *param_1 = fVar20;
            fVar1 = *(float *)(lVar15 + 0x25c + lVar6);
            fVar20 = fVar20 + DAT_1402d2398;
            param_1[1] = fVar1;
            fVar2 = *(float *)(lVar15 + 0x260 + lVar6);
            fVar1 = fVar1 - DAT_1402d2664;
            param_1[2] = fVar2;
            param_1[3] = *(float *)(lVar15 + 0x264 + lVar6);
            *param_1 = fVar20;
            fVar2 = fVar2 + DAT_1402d2828;
            param_1[1] = fVar1;
            uVar8 = DAT_1402d2080;
            param_1[2] = fVar2;
            uVar18 = FUN_1401aa420(param_1,uVar8,1);
            pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
            *param_1 = *pfVar12 + *param_1;
            param_1[1] = pfVar12[1] + param_1[1];
            param_1[2] = pfVar12[2] + param_1[2];
            param_1[3] = pfVar12[3] + param_1[3];
            FUN_1401b4060(param_1);
            param_1[10] = 0.27999;
          }
          else {
            fVar1 = param_1[5] - DAT_1402d259c;
            param_1[4] = fVar20 + DAT_1402d24b8;
            fVar20 = param_1[6] + DAT_1402d27d8;
            param_1[5] = fVar1;
            param_1[6] = fVar20;
            *param_1 = *(float *)(lVar5 + 600);
            fVar20 = *(float *)(lVar5 + 0x25c);
            param_1[1] = fVar20;
            fVar1 = *(float *)(lVar5 + 0x260);
            fVar20 = fVar20 - DAT_1402d2388;
            param_1[2] = fVar1;
            fVar1 = fVar1 - DAT_1402d25f4;
            param_1[3] = *(float *)(lVar5 + 0x264);
            param_1[2] = fVar1;
            uVar8 = DAT_1402d23f0;
            param_1[1] = fVar20;
            local_res8 = fVar4;
            uVar18 = FUN_1401aa420(param_1,uVar8,0x1e);
            pfVar12 = (float *)FUN_1401aa540(uVar18,local_58);
            *param_1 = *pfVar12 + *param_1;
            param_1[1] = pfVar12[1] + param_1[1];
            param_1[2] = pfVar12[2] + param_1[2];
            param_1[3] = pfVar12[3] + param_1[3];
            FUN_1401b4060(param_1);
          }
          if (0x1a4 < *(ushort *)(param_1 + 0x1ba)) {
            *(undefined1 *)((longlong)param_1 + 0x6eb) = 0;
            *(undefined2 *)(param_1 + 0x1ba) = 0;
          }
        }
      }
    }
  }
LAB_1401b3fcd:
  fVar20 = (float)FUN_140275cc0(local_res8 * DAT_1402d1eec);
  fVar20 = DAT_1402d28b8 / fVar20;
  if ((*(byte *)(*(longlong *)(param_1 + 0x1ae) + 0xa8790) & 0x10) != 0) {
    fVar20 = fVar20 * DAT_1402d2258;
  }
  param_1[0x10c] = fVar20;
  FUN_1401b5120(param_1,param_1 + 4,param_1 + 8);
  *(short *)(param_1 + 0x1ba) = *(short *)(param_1 + 0x1ba) + 1;
  iVar13 = FUN_1401b2ce0(param_1);
  return iVar13 == 0;
}

