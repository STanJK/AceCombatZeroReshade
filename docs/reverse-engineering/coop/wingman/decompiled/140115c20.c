/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140115c20; RVA 0x115c20
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140115c20(longlong param_1)

{
  int *piVar1;
  undefined1 auVar2 [16];
  ushort uVar3;
  undefined8 *puVar4;
  byte *pbVar5;
  undefined8 *puVar6;
  undefined1 auVar7 [16];
  float fVar8;
  float fVar9;
  char cVar10;
  undefined2 uVar11;
  short sVar12;
  longlong lVar13;
  undefined4 *puVar14;
  longlong *plVar15;
  int iVar16;
  uint uVar17;
  ulonglong uVar18;
  uint uVar19;
  float *pfVar20;
  longlong lVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined4 uVar26;
  undefined8 in_stack_ffffffffffffff48;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  uint local_58;
  
  uVar17 = (uint)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(param_1 + 0x1fc);
  *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(param_1 + 0x204);
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  if ((*(byte *)(param_1 + 0x1f0) & 1) == 0) {
    if (*(longlong **)(param_1 + 0x340) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x340) + 0x18))();
    }
    return 0;
  }
  iVar16 = 0;
  plVar15 = *(longlong **)(param_1 + 0x180);
  lVar13 = **(longlong **)(param_1 + 0x1a0);
  if (*(char *)((longlong)plVar15 + 0x37) != '\0') {
    lVar21 = 0;
    pfVar20 = (float *)(param_1 + 0x20c);
    do {
      iVar16 = iVar16 + 1;
      lVar21 = lVar21 + 8;
      auVar2 = *(undefined1 (*) [16])
                (*(longlong *)(*(longlong *)(*plVar15 + -8 + lVar21) + 0x110) + 600);
      fVar24 = auVar2._0_4_ - *(float *)(param_1 + 600);
      auVar7 = vshufps_avx(auVar2,auVar2,0xaa);
      fVar23 = auVar7._0_4_ - *(float *)(param_1 + 0x260);
      auVar7 = vshufps_avx(auVar2,auVar2,0x55);
      fVar8 = auVar7._0_4_ - *(float *)(param_1 + 0x25c);
      auVar2 = vshufps_avx(auVar2,auVar2,0xff);
      fVar25 = auVar2._0_4_ - *(float *)(param_1 + 0x264);
      *pfVar20 = SQRT(fVar25 * fVar25 + fVar23 * fVar23 + fVar8 * fVar8 + fVar24 * fVar24);
      plVar15 = *(longlong **)(param_1 + 0x180);
      pfVar20 = pfVar20 + 1;
    } while (iVar16 < (int)(uint)*(byte *)((longlong)plVar15 + 0x37));
  }
  cVar10 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
  if ((((cVar10 == '\0') || (cVar10 == '\x02')) && (*(char *)(param_1 + 0x235) != '\0')) &&
     (*(longlong *)(param_1 + 0x10) != 0)) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0xa8) & 0x400) == 0) {
      *(undefined1 *)(lVar13 + 0x6f) = 0;
      *(byte *)(lVar13 + 0x73) = *(byte *)(lVar13 + 0x73) & 0xfe;
    }
    else {
      *(undefined1 *)(lVar13 + 0x6f) = 2;
      *(byte *)(lVar13 + 0x73) = *(byte *)(lVar13 + 0x73) | 1;
    }
  }
  plVar15 = (longlong *)(param_1 + 0x10);
  if ((*(uint *)(param_1 + 0x1f0) & 0x4000) == 0) {
    pfVar20 = (float *)0x0;
    if (((uint)(*(float **)(param_1 + 8))[0x2a] & 0x400) != 0) {
      pfVar20 = *(float **)(param_1 + 8);
    }
  }
  else {
    lVar21 = *plVar15;
    if (lVar21 != 0) {
      uVar17 = *(uint *)(lVar21 + 0xa8) | 0x200;
      if ((*(byte *)(param_1 + 0x1f0) & 1) == 0) {
        uVar17 = *(uint *)(lVar21 + 0xa8) & 0xfffffdff;
      }
      *(uint *)(lVar21 + 0xa8) = uVar17;
      *(uint *)(*plVar15 + 0xa8) = *(uint *)(*plVar15 + 0xa8) | 0x400;
      *(undefined1 *)(*plVar15 + 0xae) = 0;
      lVar21 = *plVar15;
      *(undefined4 *)(lVar21 + 0x20) = *(undefined4 *)(param_1 + 600);
      *(undefined4 *)(lVar21 + 0x24) = *(undefined4 *)(param_1 + 0x25c);
      *(undefined4 *)(lVar21 + 0x28) = *(undefined4 *)(param_1 + 0x260);
      *(undefined4 *)(lVar21 + 0x2c) = *(undefined4 *)(param_1 + 0x264);
      FUN_1401278c0(*plVar15);
      uVar17 = (uint)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
      cVar10 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
      if ((cVar10 == '\0') || (cVar10 == '\x02')) {
        puVar4 = *(undefined8 **)(*plVar15 + 0x60);
        if (puVar4 != (undefined8 *)0x0) {
          pbVar5 = (byte *)*puVar4;
          uVar19 = 0;
          if (*pbVar5 != 0) {
            do {
              puVar6 = *(undefined8 **)(puVar4[1] + 8 + (longlong)(int)uVar19 * 0x10);
              if (*(char *)*puVar6 == '\x01') {
                FUN_140127650(*plVar15,puVar6[2],uVar19 & 0xff);
              }
              uVar17 = (uint)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
              uVar19 = uVar19 + 1;
            } while ((int)uVar19 < (int)(uint)*pbVar5);
          }
        }
        if ((*(byte *)(*plVar15 + 0xae) & 4) != 0) {
          *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xffffbffc;
        }
      }
    }
    pfVar20 = (float *)*plVar15;
  }
  cVar10 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
  if (((cVar10 == '\0') || (cVar10 == '\x02')) && (*(char *)(param_1 + 0x235) == '\0')) {
    lVar21 = *(longlong *)(param_1 + 0x1b8);
    if (lVar21 != 0) {
      *(undefined1 *)(param_1 + 0x236) = *(undefined1 *)(lVar21 + 0x1eec);
      *(undefined1 *)(param_1 + 0x237) = *(undefined1 *)(lVar21 + 0x1eed);
      *(undefined4 *)(param_1 + 600) = *(undefined4 *)(lVar21 + 0x70);
      *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(lVar21 + 0x74);
      *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(lVar21 + 0x78);
      *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(lVar21 + 0x7c);
      lVar21 = *(longlong *)(param_1 + 0x1b8);
      *(undefined4 *)(param_1 + 0x268) = *(undefined4 *)(lVar21 + 0x80);
      *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(lVar21 + 0x84);
      *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(lVar21 + 0x88);
      *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(lVar21 + 0x8c);
    }
    goto LAB_140116464;
  }
  if (pfVar20 == (float *)0x0) {
LAB_140116120:
    puVar4 = *(undefined8 **)(*(longlong *)(param_1 + 0x1a0) + 8);
    if (puVar4 != (undefined8 *)0x0) {
      cVar10 = *(char *)*puVar4;
      if (cVar10 == '\0') {
        FUN_140119a30(param_1);
      }
      else if (cVar10 == '\x01') {
        lVar21 = *(longlong *)(param_1 + 0x368);
        if (lVar21 != 0) {
          FUN_1401153a0(lVar21,param_1);
          *(undefined8 *)(lVar21 + 0x2d0) = *(undefined8 *)(param_1 + 0x390);
          *(undefined4 *)(lVar21 + 600) = *(undefined4 *)(param_1 + 600);
          *(undefined4 *)(lVar21 + 0x25c) = *(undefined4 *)(param_1 + 0x25c);
          *(undefined4 *)(lVar21 + 0x260) = *(undefined4 *)(param_1 + 0x260);
          *(undefined4 *)(lVar21 + 0x264) = *(undefined4 *)(param_1 + 0x264);
          *(undefined4 *)(lVar21 + 0x268) = *(undefined4 *)(param_1 + 0x268);
          *(undefined4 *)(lVar21 + 0x26c) = *(undefined4 *)(param_1 + 0x26c);
          *(undefined4 *)(lVar21 + 0x270) = *(undefined4 *)(param_1 + 0x270);
          *(undefined4 *)(lVar21 + 0x274) = *(undefined4 *)(param_1 + 0x274);
          FUN_14011e140(lVar21);
          FUN_1401153a0(param_1,lVar21);
          *(undefined4 *)(param_1 + 600) = *(undefined4 *)(lVar21 + 600);
          *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(lVar21 + 0x25c);
          *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(lVar21 + 0x260);
          *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(lVar21 + 0x264);
          *(undefined4 *)(param_1 + 0x268) = *(undefined4 *)(lVar21 + 0x268);
          *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(lVar21 + 0x26c);
          *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(lVar21 + 0x270);
          *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(lVar21 + 0x274);
          *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(lVar21 + 0x2c8);
        }
      }
      else if (cVar10 == '\x02') {
        if (*(longlong *)(param_1 + 0x370) != 0) {
          FUN_1401153a0(*(longlong *)(param_1 + 0x370),param_1);
          lVar21 = *(longlong *)(param_1 + 0x370);
          auVar2 = *(undefined1 (*) [16])(param_1 + 0x268);
          auVar7 = *(undefined1 (*) [16])(param_1 + 600);
          *(int *)(lVar21 + 600) = auVar7._0_4_;
          uVar26 = vextractps_avx(auVar7,1);
          *(undefined4 *)(lVar21 + 0x25c) = uVar26;
          uVar26 = vextractps_avx(auVar7,2);
          *(undefined4 *)(lVar21 + 0x260) = uVar26;
          uVar26 = vextractps_avx(auVar7,3);
          *(undefined4 *)(lVar21 + 0x264) = uVar26;
          *(int *)(lVar21 + 0x268) = auVar2._0_4_;
          uVar26 = vextractps_avx(auVar2,1);
          *(undefined4 *)(lVar21 + 0x26c) = uVar26;
          uVar26 = vextractps_avx(auVar2,2);
          *(undefined4 *)(lVar21 + 0x270) = uVar26;
          uVar26 = vextractps_avx(auVar2,3);
          *(undefined4 *)(lVar21 + 0x274) = uVar26;
          FUN_14011f160(*(undefined8 *)(param_1 + 0x370));
          FUN_1401153a0(param_1,*(undefined8 *)(param_1 + 0x370));
          lVar21 = *(longlong *)(param_1 + 0x370);
          *(undefined4 *)(param_1 + 600) = *(undefined4 *)(lVar21 + 600);
          *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(lVar21 + 0x25c);
          *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(lVar21 + 0x260);
          *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(lVar21 + 0x264);
          *(undefined4 *)(param_1 + 0x268) = *(undefined4 *)(lVar21 + 0x268);
          *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(lVar21 + 0x26c);
          *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(lVar21 + 0x270);
          *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(lVar21 + 0x274);
          *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(*(longlong *)(param_1 + 0x370) + 0x288)
          ;
        }
      }
      else if ((cVar10 == '\x03') &&
              (plVar15 = *(longlong **)(param_1 + 0x378), plVar15 != (longlong *)0x0)) {
        (**(code **)(*plVar15 + 0x28))(plVar15,param_1);
      }
    }
  }
  else {
    uVar19 = *(uint *)(param_1 + 0x1f0) | 0x20000;
    if (((uint)pfVar20[0x2a] & 0x40) == 0) {
      uVar19 = *(uint *)(param_1 + 0x1f0) & 0xfffdffff;
    }
    *(uint *)(param_1 + 0x1f0) = uVar19;
    if (((uint)pfVar20[0x2a] & 0x400) == 0) {
      cVar10 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
      if ((((cVar10 == '\0') || (cVar10 == '\x02')) && (*(char *)(param_1 + 0x235) != '\0')) &&
         ((*(longlong *)(param_1 + 0x1c0) != 0 &&
          (plVar15 = *(longlong **)(*(longlong *)(param_1 + 0x1c0) + 0x10),
          plVar15 != (longlong *)0x0)))) {
        lVar21 = *plVar15;
LAB_14011604a:
        (**(code **)(lVar21 + 0x1c8))();
      }
    }
    else {
      FUN_140119950(param_1,pfVar20);
      cVar10 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
      if (((cVar10 == '\0') || (cVar10 == '\x02')) &&
         ((*(char *)(param_1 + 0x235) != '\0' &&
          ((*(longlong *)(param_1 + 0x1c0) != 0 &&
           (plVar15 = *(longlong **)(*(longlong *)(param_1 + 0x1c0) + 0x10),
           plVar15 != (longlong *)0x0)))))) {
        lVar21 = *plVar15;
        if (((uint)pfVar20[0x2a] & 0xc) == 0) goto LAB_14011604a;
        (**(code **)(lVar21 + 0x1c0))();
      }
    }
    if (((uint)pfVar20[0x2a] & 0x440) != 0x400) goto LAB_140116120;
    auVar2 = *(undefined1 (*) [16])(param_1 + 600);
    fVar24 = auVar2._0_4_ - *pfVar20;
    lVar21 = *(longlong *)(param_1 + 0x360);
    auVar7 = vshufps_avx(auVar2,auVar2,0x55);
    fVar23 = auVar7._0_4_ - pfVar20[1];
    auVar7 = vshufps_avx(auVar2,auVar2,0xaa);
    fVar8 = auVar7._0_4_ - pfVar20[2];
    auVar2 = vshufps_avx(auVar2,auVar2,0xff);
    fVar25 = auVar2._0_4_ - pfVar20[3];
    *(float *)(param_1 + 0x1e4) =
         SQRT(fVar25 * fVar25 + fVar8 * fVar8 + fVar23 * fVar23 + fVar24 * fVar24);
    if (lVar21 != 0) {
      *(undefined8 *)(lVar21 + 0x5c0) = 0xffffffffffffffff;
      *(undefined1 *)(lVar21 + 0x5c8) = 0;
      *(undefined8 *)(lVar21 + 0x5cc) = 0;
    }
    *(float *)(param_1 + 600) = *pfVar20;
    *(float *)(param_1 + 0x25c) = pfVar20[1];
    *(float *)(param_1 + 0x260) = pfVar20[2];
    *(float *)(param_1 + 0x264) = pfVar20[3];
    *(float *)(param_1 + 0x268) = pfVar20[4];
    *(float *)(param_1 + 0x26c) = pfVar20[5];
    *(float *)(param_1 + 0x270) = pfVar20[6];
    *(float *)(param_1 + 0x274) = pfVar20[7];
  }
  plVar15 = *(longlong **)(param_1 + 0x3a0);
  if (plVar15 != (longlong *)0x0) {
    (**(code **)(*plVar15 + 0x198))
              (plVar15,*(undefined8 *)(param_1 + 0x198),param_1 + 600,param_1 + 0x268,
               (ulonglong)uVar17 << 0x20);
  }
  lVar21 = 0x390;
  if ((*(uint *)(param_1 + 0x1f0) & 2) == 0) {
    lVar21 = 0x398;
  }
  *(undefined8 *)(param_1 + 0x3a0) = *(undefined8 *)(lVar21 + param_1);
  local_78 = *(undefined8 *)(param_1 + 0x268);
  uStack_70 = *(undefined8 *)(param_1 + 0x270);
  local_68 = *(undefined8 *)(param_1 + 600);
  uStack_60 = *(undefined8 *)(param_1 + 0x260);
  lVar21 = 0x390;
  if ((*(uint *)(param_1 + 0x1f0) & 2) == 0) {
    lVar21 = 0x398;
  }
  FUN_140126430(param_1,&local_68,&local_78,*(undefined4 *)(param_1 + 0x1e4),
                *(undefined8 *)(lVar21 + param_1));
  if ((*(short *)(lVar13 + 0x6c) == 0xb1) && (*(longlong **)(param_1 + 0x3a0) != (longlong *)0x0)) {
    (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x180))();
  }
LAB_140116464:
  fVar8 = DAT_1402d2b60;
  fVar23 = DAT_1402d24d0;
  fVar24 = DAT_1402d1d68;
  if ((*(longlong *)(param_1 + 0x330) != 0) &&
     (((cVar10 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d), cVar10 == '\0' ||
       (cVar10 == '\x02')) && (*(char *)(param_1 + 0x235) == '\0')))) {
    fVar25 = *(float *)(param_1 + 600) - DAT_1402d2b60;
    lVar21 = 3;
    do {
      fVar9 = *(float *)(param_1 + 0x260) - fVar8;
      uVar17 = (uint)(fVar25 * fVar24 + fVar23);
      iVar16 = (int)(fVar9 * fVar24 + fVar23);
      if ((int)uVar17 < 0) {
        uVar19 = 0;
      }
      else {
        uVar19 = uVar17;
        if (0xf < (int)uVar17) {
          uVar19 = 0xf;
        }
      }
      if (iVar16 < 0) {
        iVar16 = 0;
      }
      else if (0xf < iVar16) {
        iVar16 = 0xf;
      }
      fVar9 = fVar9 + fVar8;
      *(ushort *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar16 * 2) =
           *(ushort *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar16 * 2) &
           ~(ushort)(1 << (uVar19 & 0x1f));
      iVar16 = (int)(fVar9 * fVar24 + fVar23);
      if ((int)uVar17 < 0) {
        uVar17 = 0;
      }
      else if (0xf < (int)uVar17) {
        uVar17 = 0xf;
      }
      if (iVar16 < 0) {
        iVar16 = 0;
      }
      else if (0xf < iVar16) {
        iVar16 = 0xf;
      }
      uVar19 = (uint)(fVar25 * fVar24 + fVar23);
      *(ushort *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar16 * 2) =
           *(ushort *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar16 * 2) &
           ~(ushort)(1 << (uVar17 & 0x1f));
      iVar16 = (int)((fVar9 + fVar8) * fVar24 + fVar23);
      if ((int)uVar19 < 0) {
        uVar19 = 0;
      }
      else if (0xf < (int)uVar19) {
        uVar19 = 0xf;
      }
      if (iVar16 < 0) {
        iVar16 = 0;
      }
      else if (0xf < iVar16) {
        iVar16 = 0xf;
      }
      fVar25 = fVar25 + fVar8;
      *(ushort *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar16 * 2) =
           *(ushort *)(*(longlong *)(param_1 + 0x330) + (longlong)iVar16 * 2) &
           ~(ushort)(1 << (uVar19 & 0x1f));
      lVar21 = lVar21 + -1;
    } while (lVar21 != 0);
  }
  uVar26 = 0;
  if ((*(uint *)(param_1 + 0x1f0) & 0x8000000) != 0) {
    uVar22 = 0;
    if (*(longlong *)(param_1 + 0x1b8) == 0) {
      if (*(char *)(param_1 + 0x42b) == '\x01') {
        if (*(longlong *)(param_1 + 0x360) == 0) {
          if (*(longlong *)(param_1 + 0x370) != 0) {
            uVar22 = *(undefined4 *)(*(longlong *)(param_1 + 0x370) + 0x288);
          }
        }
        else {
          uVar22 = *(undefined4 *)(*(longlong *)(param_1 + 0x360) + 0x468);
        }
      }
      else if ((*(char *)(param_1 + 0x42b) == '\x02') && (*(longlong *)(param_1 + 0x368) != 0)) {
        uVar22 = *(undefined4 *)(*(longlong *)(param_1 + 0x368) + 0x2c8);
      }
    }
    else {
      uVar22 = *(undefined4 *)(*(longlong *)(param_1 + 0x1b8) + 0x1848);
    }
    (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x68))(*(longlong **)(param_1 + 0x3a0),uVar22);
  }
  if ((*(uint *)(param_1 + 0x1f0) >> 0x1c & 1) != 0) {
    if ((*(uint *)(param_1 + 0x1f0) >> 0x19 & 1) != 0) {
      (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x70))
                (*(longlong **)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x208));
    }
    if ((*(uint *)(param_1 + 0x1f0) & 0x80000) != 0) {
      lVar21 = **(longlong **)(param_1 + 0x3a0);
      if (*(ushort *)(param_1 + 0x22a) <
          (ushort)(int)((float)*(byte *)(param_1 + 0x24a) * DAT_1402d2504)) {
        fVar24 = (float)*(ushort *)(param_1 + 0x22a) / (float)*(byte *)(param_1 + 0x24a);
        (**(code **)(lVar21 + 0x70))
                  (*(longlong **)(param_1 + 0x3a0),
                   fVar24 * fVar24 * *(float *)(param_1 + 0x208) + *(float *)(param_1 + 0x208));
      }
      else {
        (**(code **)(lVar21 + 0x78))();
      }
    }
  }
  if ((*(uint *)(param_1 + 0x1f0) & 0x21000000) == 0x21000000) {
    (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x58))
              (*(longlong **)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x208));
  }
  if (*(longlong **)(param_1 + 0x3a0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x50))();
  }
  *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xfdffffff;
  FUN_140116c40(param_1,param_1 + 0x20c,*(undefined1 *)(*(longlong *)(param_1 + 0x180) + 0x37),
                lVar13);
  iVar16 = *(int *)(param_1 + 0x214);
  if (-1 < iVar16) {
    if (iVar16 < (int)((uint)*(byte *)(param_1 + 0x24a) * 3)) {
      *(int *)(param_1 + 0x214) = iVar16 + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x214) = 0xffffffff;
    }
  }
  FUN_140118b90(param_1);
  FUN_140119040(param_1);
  fVar24 = DAT_1402d22d0;
  uVar17 = *(uint *)(param_1 + 0x1f0);
  if ((uVar17 >> 0x13 & 1) != 0) {
    if (*(char *)(lVar13 + 0x75) == '\x05') {
      fVar23 = DAT_1402d22d0 / (float)*(byte *)(param_1 + 0x24a);
      *(float *)(param_1 + 0x25c) = -(fVar23 * DAT_1402d250c) + *(float *)(param_1 + 0x25c);
      if (*(float *)(param_1 + 0x270) < DAT_1402d2174) {
        *(float *)(param_1 + 0x270) = fVar23 * DAT_1402d1f38 + *(float *)(param_1 + 0x270);
      }
    }
    uVar3 = *(ushort *)(param_1 + 0x22a);
    if (uVar3 < *(ushort *)(param_1 + 0x22c)) {
      *(ushort *)(param_1 + 0x22a) = uVar3 + 1;
    }
    else if (uVar3 == *(ushort *)(param_1 + 0x22c)) {
      if ((*(char *)(lVar13 + 0x75) == '\0') || (*(char *)(lVar13 + 0x75) == '\x01')) {
        *(uint *)(param_1 + 0x1f0) = uVar17 | 2;
        FUN_140117a10(param_1,CONCAT71((uint7)(uint3)(uVar17 >> 8),3));
        uVar17 = *(uint *)(param_1 + 0x1f0) & 0xfeffffff;
      }
      uVar19 = uVar17 & 0xfffffffc;
      uVar17 = 0;
      *(short *)(param_1 + 0x22a) = *(short *)(param_1 + 0x22a) + 1;
      *(uint *)(param_1 + 0x1f0) = uVar19;
    }
  }
  if (*(char *)(param_1 + 0x24d) != '\0') {
    *(char *)(param_1 + 0x24d) = *(char *)(param_1 + 0x24d) + -1;
  }
  if (((*(uint *)(param_1 + 500) & 0x10) != 0) &&
     (*(short *)(param_1 + 0x232) = *(short *)(param_1 + 0x232) + 1,
     (ushort)((ushort)*(byte *)(param_1 + 0x24a) * 2) <= *(ushort *)(param_1 + 0x232))) {
    *(uint *)(param_1 + 500) = *(uint *)(param_1 + 500) & 0xffffffef;
  }
  if (((uVar17 & 2) == 0) && (*(char *)(lVar13 + 0x7f) == '\x03')) {
    uVar3 = *(ushort *)(param_1 + 0x442);
    if ((uVar17 & 1) == 0) {
      if (uVar3 != 0xffff) {
        lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x198) + 0x66ee0);
        uVar18 = (ulonglong)((uVar3 & 0x3ff) >> 5);
        uVar19 = (uVar3 & 0x3ff) & 0x1f;
        uVar17 = *(uint *)(lVar13 + 0x1bc48 + uVar18 * 4);
        if ((uVar17 >> uVar19 & 1) != 0) {
          *(uint *)(lVar13 + 0x1bc48 + uVar18 * 4) = uVar17 & ~(1 << uVar19);
          piVar1 = (int *)(lVar13 + 0x1bc88);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 0) {
            *(undefined4 *)(lVar13 + 0x1bc88) = 0;
          }
        }
      }
      *(undefined2 *)(param_1 + 0x442) = 0xffff;
    }
    else {
      local_68 = *(undefined8 *)(param_1 + 600);
      uStack_60 = *(undefined8 *)(param_1 + 0x260);
      if (uVar3 == 0xffff) {
        local_58 = (uint)*(byte *)(lVar13 + 0x80);
        uVar11 = FUN_140031f80(*(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0),0x3a,
                               &local_68,0);
        *(undefined2 *)(param_1 + 0x442) = uVar11;
      }
      else {
        local_58 = 0;
        uVar11 = FUN_140035b10(*(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0),0x3a,
                               &local_68,uVar3,0xffff);
        *(undefined2 *)(param_1 + 0x442) = uVar11;
      }
    }
  }
  if ((*(short *)(param_1 + 0x22e) == 0x3f4) && ((*(byte *)(param_1 + 0x1f0) & 2) != 0)) {
    if (*(short *)(param_1 + 0x222) < 0) {
      FUN_1401c56d0();
      local_68 = _DAT_1402d35f0;
      uStack_60 = _UNK_1402d35f8;
      cVar10 = FUN_1401c6a00(_DAT_1402d35f0,2,0,param_1 + 600,&local_68,uVar26,uVar26,uVar26,uVar26,
                             0,0);
      if ((((cVar10 != '\0') && (lVar13 = FUN_1401c97a0(), '\x02' < *(char *)(lVar13 + 0x3dc2))) &&
          (uVar3 = *(ushort *)(lVar13 + 0x150),
          (~*(byte *)(*(longlong *)(&DAT_14032d5a8 + (ulonglong)uVar3 * 0x18) + 0x12) & 1) != 0)) &&
         (puVar14 = (undefined4 *)FUN_1401c9e60(lVar13), puVar14 != (undefined4 *)0x0)) {
        *(ushort *)(puVar14 + 0x11) = uVar3;
        *(undefined2 *)((longlong)puVar14 + 0x46) = 0;
        *puVar14 = *(undefined4 *)(param_1 + 600);
        puVar14[1] = *(undefined4 *)(param_1 + 0x25c);
        puVar14[2] = *(undefined4 *)(param_1 + 0x260);
        puVar14[3] = *(undefined4 *)(param_1 + 0x264);
        *(undefined8 *)(puVar14 + 4) = 0;
        puVar14[6] = 0;
        *(undefined8 *)(puVar14 + 7) = 0x3f800000;
        *(undefined8 *)(puVar14 + 9) = 0;
        puVar14[0xb] = 0x3f800000;
        puVar14[0xf] = 0x3f800000;
        *(undefined2 *)((longlong)puVar14 + 0x4a) = 0;
        *(byte *)(puVar14 + 0x1c) = *(byte *)(puVar14 + 0x1c) & 0xee | 6;
        *(code **)(puVar14 + 0xc) = FUN_1401caa00;
      }
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      if (*(longlong *)(param_1 + 0x198) != 0) {
        local_68 = *(undefined8 *)(param_1 + 600);
        uStack_60 = *(undefined8 *)(param_1 + 0x260);
        local_58 = 0;
        uVar11 = FUN_140031f80(*(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0),0x21,
                               &local_68,0);
        *(undefined2 *)(param_1 + 0x222) = uVar11;
      }
    }
    sVar12 = *(short *)(param_1 + 0x222);
    if ((-1 < sVar12) && (*(float *)(param_1 + 0x1e0) < DAT_1402d25c0)) {
      fVar23 = *(float *)(param_1 + 0x25c) - DAT_1402d23c0;
      *(float *)(param_1 + 0x25c) = fVar23;
      if (*(longlong *)(param_1 + 0x198) != 0) {
        local_68 = CONCAT44(fVar23,*(undefined4 *)(param_1 + 600));
        uStack_60 = *(undefined8 *)(param_1 + 0x260);
        sVar12 = FUN_140035b10(*(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0),0x21,
                               &local_68,sVar12,0xffff);
        *(short *)(param_1 + 0x222) = sVar12;
      }
      lVar13 = FUN_140189320();
      *(float *)(param_1 + 0x1e0) =
           fVar24 / (float)*(int *)(lVar13 + 0xc) + *(float *)(param_1 + 0x1e0);
    }
  }
  return 1;
}

