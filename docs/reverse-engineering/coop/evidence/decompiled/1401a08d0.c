/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1401a08d0; RVA 0x1a08d0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1401a08d0(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  short *psVar10;
  uint uVar11;
  bool bVar12;
  undefined1 in_ZMM0 [64];
  undefined1 auStack_c8 [32];
  longlong *local_a8;
  undefined1 *local_a0;
  undefined1 *local_98;
  undefined1 local_90;
  undefined2 local_88 [2];
  undefined1 local_84 [4];
  undefined1 local_80 [32];
  undefined1 local_60 [16];
  undefined2 local_50 [4];
  ulonglong local_48;
  
  local_48 = DAT_140309040 ^ (ulonglong)auStack_c8;
  lVar1 = *(longlong *)(*(longlong *)*param_3 + 0x110);
  if (lVar1 == 0) {
    return;
  }
  local_50[0] = 0xffff;
  local_80 = vpcmpeqd_avx2(in_ZMM0._0_32_,in_ZMM0._0_32_);
  local_60 = local_80._0_16_;
  if (*(short *)param_1[3] < 1) {
    FUN_140189320();
    iVar4 = FUN_140242630();
    if (iVar4 % 100 <= (int)*(char *)param_1[1]) {
      if (((*(uint *)(lVar1 + 0x424) >> 0x17 & 1) == 0) ||
         ((*(uint *)(param_1 + 8) >> 0x17 & 1) != 0)) {
        if (((*(uint *)(lVar1 + 0x424) >> 0x18 & 1) == 0) ||
           ((*(uint *)(param_1 + 8) >> 0x18 & 1) != 0)) goto LAB_1401a09ea;
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x1000000;
        lVar7 = FUN_140189320();
        uVar8 = 1;
      }
      else {
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x800000;
        lVar7 = FUN_140189320();
        uVar8 = 0;
      }
      *(short *)param_1[3] = (short)*(char *)param_1[2] * *(short *)(lVar7 + 0xc);
      (**(code **)(*param_1 + 0x10))(param_1,0,uVar8,local_80);
    }
  }
LAB_1401a09ea:
  local_a8 = param_3;
  FUN_1401a1620(param_1,local_80 + 0x14);
  local_a8 = param_3;
  FUN_1401a1820(param_1,local_80 + 10);
  local_a8 = param_3;
  FUN_1401a19e0(param_1,local_80 + 2);
  local_a8 = param_3;
  FUN_1401a1cf0(param_1,local_80 + 6);
  iVar4 = 0;
  if (*(short *)(param_1[3] + 8) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (((iVar5 % 100 <= (int)*(char *)(param_1[1] + 4)) && ((*(byte *)(lVar1 + 0x1f0) & 2) != 0))
       && ((*(uint *)(lVar1 + 0x1f8) & 0x10000000) != 0)) {
      cVar2 = (**(code **)(*param_1 + 0x10))(param_1,0,5,local_88);
      bVar12 = cVar2 != '\0';
      cVar2 = (**(code **)(*param_1 + 0x10))(param_1,1,5,local_88 + bVar12);
      uVar11 = bVar12 + 1;
      if (cVar2 == '\0') {
        uVar11 = (uint)bVar12;
      }
      if (uVar11 != 0) {
        FUN_140189320();
        iVar5 = FUN_140242630();
        local_80._8_2_ = local_88[iVar5 % (int)uVar11];
        FUN_14019fc40(param_1,4);
      }
    }
  }
  if (*(short *)(param_1[3] + 0x10) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (iVar5 % 100 <= (int)*(char *)(param_1[1] + 8)) {
      if ((*(byte *)(lVar1 + 0x236) == 0xff) || (*(byte *)(lVar1 + 0x237) == 0xff)) {
        uVar11 = *(uint *)(param_1 + 8);
      }
      else {
        uVar11 = *(uint *)(param_1 + 8);
        if ((*(byte *)(*(longlong *)
                        (*(longlong *)
                          (**(longlong **)(lVar1 + 0x180) + (ulonglong)*(byte *)(lVar1 + 0x236) * 8)
                        + 0x110) + 0x1f0 + (ulonglong)*(byte *)(lVar1 + 0x237) * 0x520) & 0x10) != 0
           ) {
          if ((uVar11 & 8) == 0) {
            *(uint *)(param_1 + 8) = uVar11 | 8;
            lVar7 = FUN_140189320();
            *(short *)(param_1[3] + 0x10) =
                 (short)*(char *)(param_1[2] + 8) * *(short *)(lVar7 + 0xc);
            (**(code **)(*param_1 + 0x10))(param_1,0,0xb,local_80 + 0x10);
          }
          goto LAB_1401a0be2;
        }
      }
      *(uint *)(param_1 + 8) = uVar11 & 0xfffffff7;
    }
  }
LAB_1401a0be2:
  local_a8 = param_3;
  FUN_1401a2650(param_1,local_80 + 0x10);
  if (*(short *)(param_1[3] + 4) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (iVar5 % 100 <= (int)*(char *)(param_1[1] + 2)) {
      uVar11 = *(uint *)(param_1 + 8);
      if ((*(uint *)(lVar1 + 0x1f8) & 0x100) == 0) {
        *(uint *)(param_1 + 8) = uVar11 & 0xffffbfff;
      }
      else if ((uVar11 >> 0xe & 1) == 0) {
        *(uint *)(param_1 + 8) = uVar11 | 0x4000;
        lVar7 = FUN_140189320();
        *(short *)(param_1[3] + 4) = (short)*(char *)(param_1[2] + 2) * *(short *)(lVar7 + 0xc);
        cVar2 = (**(code **)(*param_1 + 0x10))(param_1,0,3,local_88);
        bVar12 = cVar2 != '\0';
        cVar2 = (**(code **)(*param_1 + 0x10))(param_1,1,3,local_88 + bVar12);
        uVar11 = bVar12 + 1;
        if (cVar2 == '\0') {
          uVar11 = (uint)bVar12;
        }
        if (uVar11 != 0) {
          FUN_140189320();
          iVar5 = FUN_140242630();
          local_80._4_2_ = local_88[iVar5 % (int)uVar11];
        }
      }
    }
  }
  local_a8 = param_3;
  FUN_1401a2290(param_1,local_80 + 0xe);
  local_a8 = param_3;
  FUN_1401a20f0(param_1,local_80 + 0xc);
  local_a8 = param_3;
  FUN_1401a2930(param_1,local_80 + 0x1a);
  local_a8 = param_3;
  FUN_1401a27a0(param_1,local_80 + 0x16);
  if (*(short *)(param_1[3] + 0x18) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if ((((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0xc)) &&
         (uVar11 = *(uint *)(lVar1 + 0x1f8), (uVar11 >> 0x14 & 1) != 0)) &&
        (((uVar11 >> 0x15 & 1) == 0 &&
         ((((uVar11 >> 9 & 1) == 0 && ((uVar11 >> 10 & 1) == 0)) &&
          (*(byte *)(lVar1 + 0x240) != 0xff)))))) &&
       ((*(byte *)(lVar1 + 0x241) != 0xff &&
        ((*(byte *)(*(longlong *)
                     (*(longlong *)(*param_3 + (ulonglong)*(byte *)(lVar1 + 0x240) * 8) + 0x110) +
                    0x1f0 + (ulonglong)*(byte *)(lVar1 + 0x241) * 0x520) & 3) != 0)))) {
      FUN_14019fc40(param_1,0xc);
      (**(code **)(*param_1 + 0x10))(param_1,0,0x28,local_80 + 0x18);
    }
  }
  if (*(short *)(param_1[3] + 0x1c) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0xe)) && ((*(byte *)(lVar1 + 0x1f8) & 1) != 0))
       && (uVar11 = *(uint *)(param_1 + 8), (uVar11 & 0x20) == 0)) {
      lVar7 = *(longlong *)(*(longlong *)(lVar1 + 0x1b8) + 0xfe0);
      bVar3 = 0;
      if (lVar7 != 0) {
        bVar3 = *(byte *)(lVar7 + 10);
      }
      if (bVar3 / 10 < *(byte *)(*(longlong *)(lVar1 + 0x1b8) + 0x2099)) {
        *(uint *)(param_1 + 8) = uVar11 & 0xffffffef;
      }
      else if ((uVar11 & 0x10) == 0) {
        *(uint *)(param_1 + 8) = uVar11 | 0x10;
        FUN_14019fc40(param_1,0xe);
        (**(code **)(*param_1 + 0x10))(param_1,0,0x3a,local_80 + 0x1c);
      }
    }
  }
  if (*(short *)(param_1[3] + 0x1e) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if ((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0xf)) && ((*(byte *)(lVar1 + 0x1f8) & 1) != 0))
    {
      uVar11 = *(uint *)(param_1 + 8);
      if (*(char *)(*(longlong *)(lVar1 + 0x1b8) + 0x2099) == '\0') {
        if ((uVar11 & 0x20) == 0) {
          *(uint *)(param_1 + 8) = uVar11 | 0x20;
          FUN_14019fc40(param_1,0xf);
          (**(code **)(*param_1 + 0x10))(param_1,0,0x39,local_80 + 0x1e);
        }
      }
      else {
        *(uint *)(param_1 + 8) = uVar11 & 0xffffffdf;
      }
    }
  }
  if (*(short *)(param_1[3] + 0x20) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0x10)) &&
        ((*(byte *)(lVar1 + 0x1f8) & 0x10) != 0)) &&
       (uVar11 = *(uint *)(param_1 + 8), -1 < (char)uVar11)) {
      lVar7 = *(longlong *)(*(longlong *)(lVar1 + 0x1b8) + 0xfe0);
      uVar6 = 0;
      if (lVar7 != 0) {
        uVar6 = (uint)*(byte *)(lVar7 + 8);
      }
      if ((int)(uVar6 / 10) < (int)*(short *)(*(longlong *)(lVar1 + 0x1b8) + 0x208e)) {
        *(uint *)(param_1 + 8) = uVar11 & 0xffffffbf;
      }
      else if ((uVar11 & 0x40) == 0) {
        *(uint *)(param_1 + 8) = uVar11 | 0x40;
        FUN_14019fc40(param_1,0x10);
        (**(code **)(*param_1 + 0x10))(param_1,0,0x3c,local_60);
      }
    }
  }
  if (*(short *)(param_1[3] + 0x22) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if ((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0x11)) &&
       ((*(byte *)(lVar1 + 0x1f8) & 0x10) != 0)) {
      uVar11 = *(uint *)(param_1 + 8);
      if (*(short *)(*(longlong *)(lVar1 + 0x1b8) + 0x208e) < 1) {
        if (-1 < (char)uVar11) {
          *(uint *)(param_1 + 8) = uVar11 | 0x80;
          FUN_14019fc40(param_1,0x11);
          (**(code **)(*param_1 + 0x10))(param_1,0,0x3b,local_60 + 2);
        }
      }
      else {
        *(uint *)(param_1 + 8) = uVar11 & 0xffffff7f;
      }
    }
  }
  if (*(short *)(param_1[3] + 0x24) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0x12)) && ((*(byte *)(lVar1 + 0x1f8) & 2) != 0)
        ) && (uVar11 = *(uint *)(param_1 + 8), (uVar11 >> 9 & 1) == 0)) {
      lVar7 = *(longlong *)(lVar1 + 0x1b8);
      if (*(longlong *)(lVar7 + 0xfe0) == 0) {
        bVar3 = 0;
      }
      else {
        bVar3 = *(byte *)((ulonglong)*(byte *)(lVar7 + 0x279a) + 0xb + *(longlong *)(lVar7 + 0xfe0))
        ;
      }
      if ((byte)((bVar3 >> 2) + 1) < *(byte *)(lVar7 + 0x209a)) {
        *(uint *)(param_1 + 8) = uVar11 & 0xfffffeff;
      }
      else if ((uVar11 >> 8 & 1) == 0) {
        uVar9 = 0x40;
        *(uint *)(param_1 + 8) = uVar11 | 0x100;
        if (*(char *)(*(longlong *)(lVar7 + 0xff8) + 4 + (ulonglong)*(byte *)(lVar7 + 0x279a)) !=
            '\x11') {
          uVar9 = 0x3e;
        }
        FUN_14019fc40(param_1,0x12);
        (**(code **)(*param_1 + 0x10))(param_1,0,uVar9,local_60 + 4);
      }
    }
  }
  if (*(short *)(param_1[3] + 0x26) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if ((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0x13)) && ((*(byte *)(lVar1 + 0x1f8) & 2) != 0))
    {
      lVar7 = *(longlong *)(lVar1 + 0x1b8);
      uVar11 = *(uint *)(param_1 + 8);
      if (*(char *)(lVar7 + 0x209a) == '\0') {
        if ((uVar11 >> 9 & 1) == 0) {
          uVar9 = 0x3f;
          *(uint *)(param_1 + 8) = uVar11 | 0x200;
          if (*(char *)((ulonglong)*(byte *)(lVar7 + 0x279a) + 4 + *(longlong *)(lVar7 + 0xff8)) !=
              '\x11') {
            uVar9 = 0x3d;
          }
          FUN_14019fc40(param_1,0x13);
          (**(code **)(*param_1 + 0x10))(param_1,0,uVar9,local_60 + 6);
        }
      }
      else {
        *(uint *)(param_1 + 8) = uVar11 & 0xfffffdff;
      }
    }
  }
  FUN_1401a2d50(param_1,local_80 + 0x12);
  if (*(short *)(param_1[3] + 0x30) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (iVar5 % 100 <= (int)*(char *)(param_1[1] + 0x18)) {
      if (((*(uint *)(*(longlong *)(lVar1 + 0x1b8) + 0x1bb4) & 0x100000) == 0) ||
         ((*(uint *)(param_1 + 8) & 0x2000000) != 0)) {
        cVar2 = FUN_1400b7690(*(longlong *)(lVar1 + 0x1b8) + 0x1868,param_3);
        if (cVar2 == '\0') {
          *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfdffffff;
        }
        else {
          cVar2 = (**(code **)(*param_1 + 0x10))(param_1,0,0x42,local_88);
          bVar12 = cVar2 != '\0';
          cVar2 = (**(code **)(*param_1 + 0x10))(param_1,1,0x42,local_88 + bVar12);
          uVar11 = bVar12 + 1;
          if (cVar2 == '\0') {
            uVar11 = (uint)bVar12;
          }
          if (uVar11 != 0) {
            iVar5 = FUN_140242630();
            local_50[0] = local_88[iVar5 % (int)uVar11];
            lVar7 = FUN_140189320();
            *(short *)(param_1[3] + 0x30) =
                 (short)*(char *)(param_1[2] + 0x18) * *(short *)(lVar7 + 0xc);
          }
        }
      }
      else {
        lVar7 = FUN_140189320();
        *(short *)(param_1[3] + 0x30) =
             (short)*(char *)(param_1[2] + 0x18) * *(short *)(lVar7 + 0xc);
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x2000000;
        (**(code **)(*param_1 + 0x10))(param_1,0,0x54,local_50);
      }
    }
  }
  local_a8 = param_3;
  FUN_1401a2e80(param_1,local_60 + 8);
  local_a8 = param_3;
  FUN_1401a30e0(param_1,local_60 + 10);
  if (0 < *(short *)(param_1[3] + 0x2c)) goto LAB_1401a14f1;
  FUN_140189320();
  iVar5 = FUN_140242630();
  if ((int)*(char *)(param_1[1] + 0x16) < iVar5 % 100) goto LAB_1401a14f1;
  if ((((((((*(uint *)(param_1 + 8) & 1) != 0) && ((*(uint *)(param_1 + 8) & 4) == 0)) &&
         (lVar7 = FUN_140189320(),
         (int)*(short *)((longlong)param_1 + 0x2aa) < *(int *)(lVar7 + 0xc) * 2)) &&
        ((*(byte *)(lVar1 + 0x244) != 0xff && (*(byte *)(lVar1 + 0x245) != 0xff)))) &&
       ((lVar7 = *(longlong *)
                  (*(longlong *)(*param_3 + (ulonglong)*(byte *)(lVar1 + 0x244) * 8) + 0x110) +
                 (ulonglong)*(byte *)(lVar1 + 0x245) * 0x520, lVar7 != 0 &&
        (((*(byte *)(lVar7 + 0x1f0) & 2) != 0 && (*(longlong **)(lVar7 + 0x1a0) != (longlong *)0x0))
        )))) && (lVar7 = **(longlong **)(lVar7 + 0x1a0), lVar7 != 0)) &&
     ((*(char *)(lVar7 + 0x7e) == '\x01' || (*(char *)(lVar7 + 0x7e) == '\x02')))) {
    if (*(char *)(lVar7 + 0x7c) == '\x01') {
      uVar8 = 5;
    }
    else {
      if (*(char *)(lVar7 + 0x7c) != '\x02') goto LAB_1401a14d3;
      uVar8 = 6;
    }
    if ((*(uint *)(param_1 + 8) & 0x2000) == 0) {
      (**(code **)(*param_1 + 0x10))(param_1,uVar8,0x48,local_60 + 0xc);
    }
  }
LAB_1401a14d3:
  lVar7 = FUN_140189320();
  *(short *)(param_1[3] + 0x2c) = (short)*(char *)(param_1[2] + 0x16) * *(short *)(lVar7 + 0xc);
LAB_1401a14f1:
  if (*(short *)(param_1[3] + 0x2e) < 1) {
    FUN_140189320();
    iVar5 = FUN_140242630();
    if (((iVar5 % 100 <= (int)*(char *)(param_1[1] + 0x17)) && (*(char *)(lVar1 + 0x23f) != -1)) &&
       (*(char *)(lVar1 + 0x23e) != -1)) {
      if ((*(byte *)(lVar1 + 0x1f8) & 0x10) != 0) {
        local_84[0] = 0;
        local_90 = 1 < *(byte *)((longlong)param_1 + 0x45);
        local_98 = local_84;
        local_a0 = local_60 + 0xe;
        local_a8 = (longlong *)CONCAT62(local_a8._2_6_,0x4a);
        FUN_1401a0810(param_1,param_3);
      }
      if (-1 < (short)local_60._14_2_) {
        FUN_14019fc40(param_1,0x17);
      }
    }
  }
  psVar10 = (short *)local_80;
LAB_1401a15a7:
  do {
    if (-1 < *psVar10) {
      if (iVar4 == 5) {
        if ((*(uint *)(param_1 + 8) >> 0x1a & 1) == 0) {
          FUN_1401a63e0(param_2);
        }
        iVar4 = 6;
        psVar10 = psVar10 + 1;
        goto LAB_1401a15a7;
      }
      if ((*(uint *)(param_1 + 8) >> 0x14 & 1) == 0) {
        FUN_1401a63e0(param_2);
      }
    }
    iVar4 = iVar4 + 1;
    psVar10 = psVar10 + 1;
    if (0x18 < iVar4) {
      return;
    }
  } while( true );
}

