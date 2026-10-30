/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140116e10; RVA 0x116e10
 * Ghidra-generated research pseudocode, inferred types, not original source. */

undefined8 FUN_140116e10(longlong param_1)

{
  undefined1 auVar1 [16];
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  longlong *plVar5;
  undefined1 auVar6 [16];
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  longlong lVar12;
  uint uVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  float fVar16;
  float local_res8 [2];
  ulonglong in_stack_ffffffffffffff98;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  uint local_38;
  
  uVar13 = *(uint *)(param_1 + 0x1f0);
  if ((uVar13 & 1) == 0) {
    if (((uVar13 >> 0x13 & 1) != 0) && (*(short *)(param_1 + 0x22a) == *(short *)(param_1 + 0x22c)))
    {
      *(short *)(param_1 + 0x22a) = *(short *)(param_1 + 0x22c) + 1;
      cVar2 = *(char *)(**(longlong **)(param_1 + 0x1a0) + 0x75);
      if ((cVar2 == '\0') || (cVar2 == '\x01')) {
        *(uint *)(param_1 + 0x1f0) = uVar13 | 2;
        FUN_140117a10(param_1,CONCAT71((uint7)(uint3)(uVar13 >> 8),3));
        uVar13 = *(uint *)(param_1 + 0x1f0) & 0xfeffffff;
      }
      *(uint *)(param_1 + 0x1f0) = uVar13 & 0xfffffffc;
    }
    if (*(longlong **)(param_1 + 0x340) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x340) + 0x18))();
    }
    return 0;
  }
  local_res8[0] = 0.0;
  if (((*(longlong *)(param_1 + 0x1c8) != 0) &&
      (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x1c8) + 0x10), lVar12 != 0)) &&
     (lVar12 = *(longlong *)(lVar12 + 0x340), lVar12 != 0)) {
    auVar1 = *(undefined1 (*) [16])(lVar12 + 0x69ae0);
    fVar16 = auVar1._0_4_ - *(float *)(param_1 + 600);
    auVar6 = vshufps_avx(auVar1,auVar1,0xaa);
    fVar7 = auVar6._0_4_ - *(float *)(param_1 + 0x260);
    auVar6 = vshufps_avx(auVar1,auVar1,0x55);
    fVar8 = auVar6._0_4_ - *(float *)(param_1 + 0x25c);
    auVar1 = vshufps_avx(auVar1,auVar1,0xff);
    fVar9 = auVar1._0_4_ - *(float *)(param_1 + 0x264);
    local_res8[0] = SQRT(fVar9 * fVar9 + fVar7 * fVar7 + fVar8 * fVar8 + fVar16 * fVar16);
  }
  cVar2 = *(char *)(**(longlong **)(param_1 + 0x388) + 0x15d);
  if (((cVar2 == '\0') || (cVar2 == '\x02')) && (*(char *)(param_1 + 0x235) == '\0')) {
    lVar12 = *(longlong *)(param_1 + 0x198);
    if ((lVar12 != 0) && ((uVar13 & 2) == 0)) {
      local_48 = *(undefined8 *)(param_1 + 600);
      uStack_40 = *(undefined8 *)(param_1 + 0x260);
      if (*(short *)(param_1 + 0x442) == -1) {
        local_38 = 0;
        uVar11 = FUN_140031f80(*(undefined8 *)(lVar12 + 0x66ee0),2,&local_48,0);
        *(undefined2 *)(param_1 + 0x442) = uVar11;
      }
      else {
        uVar11 = FUN_140035b10(*(undefined8 *)(lVar12 + 0x66ee0),2,&local_48,
                               *(short *)(param_1 + 0x442),0xffff);
        *(undefined2 *)(param_1 + 0x442) = uVar11;
      }
    }
  }
  else {
    puVar14 = *(undefined8 **)(*(longlong *)(param_1 + 0x1a0) + 8);
    if (puVar14 != (undefined8 *)0x0) {
      cVar2 = *(char *)*puVar14;
      if (cVar2 == '\0') {
        lVar12 = *(longlong *)(param_1 + 0x360);
        if (lVar12 != 0) {
          *(undefined4 *)(lVar12 + 0x3d8) = *(undefined4 *)(param_1 + 600);
          *(undefined4 *)(lVar12 + 0x3dc) = *(undefined4 *)(param_1 + 0x25c);
          *(undefined4 *)(lVar12 + 0x3e0) = *(undefined4 *)(param_1 + 0x260);
          *(undefined4 *)(lVar12 + 0x3e4) = *(undefined4 *)(param_1 + 0x264);
          *(undefined4 *)(lVar12 + 1000) = *(undefined4 *)(param_1 + 0x268);
          *(undefined4 *)(lVar12 + 0x3ec) = *(undefined4 *)(param_1 + 0x26c);
          *(undefined4 *)(lVar12 + 0x3f0) = *(undefined4 *)(param_1 + 0x270);
          *(undefined4 *)(lVar12 + 0x3f4) = *(undefined4 *)(param_1 + 0x274);
          plVar5 = *(longlong **)(param_1 + 0x3a0);
          if (plVar5 != (longlong *)0x0) {
            (**(code **)(*plVar5 + 0x138))(plVar5,*(undefined4 *)(lVar12 + 0x484),0);
            (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x158))();
            (**(code **)(**(longlong **)(param_1 + 0x3a0) + 0x140))
                      (*(longlong **)(param_1 + 0x3a0),*(undefined4 *)(lVar12 + 0x5cc));
          }
          if ((*(byte *)(lVar12 + 0x61c) & 1) != 0) {
            uVar10 = FUN_140079920(*(undefined8 *)(param_1 + 400),param_1 + 600);
            *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) | 2;
            FUN_140117a10(param_1,uVar10);
            *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xfefffffe;
            *(byte *)(lVar12 + 0x61c) = *(byte *)(lVar12 + 0x61c) & 0xfe;
          }
          lVar12 = *(longlong *)(param_1 + 0x198);
          if (((lVar12 != 0) && (((byte)*(undefined4 *)(param_1 + 0x1f0) & 3) == 1)) &&
             (*(longlong *)(param_1 + 0x3a0) != 0)) {
            local_48 = *(undefined8 *)(param_1 + 600);
            uStack_40 = *(undefined8 *)(param_1 + 0x260);
            if (*(short *)(param_1 + 0x442) == -1) {
              local_38 = 0;
              uVar11 = FUN_140031f80(*(undefined8 *)(lVar12 + 0x66ee0),2,&local_48,0);
              *(undefined2 *)(param_1 + 0x442) = uVar11;
              if (*(longlong **)(param_1 + 0x398) != (longlong *)0x0) {
                (**(code **)(**(longlong **)(param_1 + 0x398) + 0x160))();
              }
            }
            else {
              in_stack_ffffffffffffff98 = CONCAT62((int6)(in_stack_ffffffffffffff98 >> 0x10),0xffff)
              ;
              uVar11 = FUN_140035b10(*(undefined8 *)(lVar12 + 0x66ee0),2,&local_48,
                                     *(short *)(param_1 + 0x442),in_stack_ffffffffffffff98);
              *(undefined2 *)(param_1 + 0x442) = uVar11;
            }
          }
        }
      }
      else if (cVar2 == '\x01') {
        lVar12 = *(longlong *)(param_1 + 0x368);
        if (lVar12 != 0) {
          *(undefined4 *)(lVar12 + 600) = *(undefined4 *)(param_1 + 600);
          *(undefined4 *)(lVar12 + 0x25c) = *(undefined4 *)(param_1 + 0x25c);
          *(undefined4 *)(lVar12 + 0x260) = *(undefined4 *)(param_1 + 0x260);
          *(undefined4 *)(lVar12 + 0x264) = *(undefined4 *)(param_1 + 0x264);
          *(undefined4 *)(lVar12 + 0x268) = *(undefined4 *)(param_1 + 0x268);
          *(undefined4 *)(lVar12 + 0x26c) = *(undefined4 *)(param_1 + 0x26c);
          *(undefined4 *)(lVar12 + 0x270) = *(undefined4 *)(param_1 + 0x270);
          *(undefined4 *)(lVar12 + 0x274) = *(undefined4 *)(param_1 + 0x274);
        }
      }
      else if ((cVar2 == '\x02') && (lVar12 = *(longlong *)(param_1 + 0x370), lVar12 != 0)) {
        auVar1 = *(undefined1 (*) [16])(param_1 + 0x268);
        auVar6 = *(undefined1 (*) [16])(param_1 + 600);
        *(int *)(lVar12 + 600) = auVar6._0_4_;
        uVar4 = vextractps_avx(auVar6,1);
        *(undefined4 *)(lVar12 + 0x25c) = uVar4;
        uVar4 = vextractps_avx(auVar6,2);
        *(undefined4 *)(lVar12 + 0x260) = uVar4;
        uVar4 = vextractps_avx(auVar6,3);
        *(undefined4 *)(lVar12 + 0x264) = uVar4;
        *(int *)(lVar12 + 0x268) = auVar1._0_4_;
        uVar4 = vextractps_avx(auVar1,1);
        *(undefined4 *)(lVar12 + 0x26c) = uVar4;
        uVar4 = vextractps_avx(auVar1,2);
        *(undefined4 *)(lVar12 + 0x270) = uVar4;
        uVar4 = vextractps_avx(auVar1,3);
        *(undefined4 *)(lVar12 + 0x274) = uVar4;
      }
    }
    plVar5 = *(longlong **)(param_1 + 0x3a0);
    if (plVar5 != (longlong *)0x0) {
      (**(code **)(*plVar5 + 0x198))
                (plVar5,*(undefined8 *)(param_1 + 0x198),param_1 + 600,param_1 + 0x268,
                 in_stack_ffffffffffffff98 & 0xffffffff00000000);
    }
    lVar12 = 0x390;
    if ((*(uint *)(param_1 + 0x1f0) & 2) == 0) {
      lVar12 = 0x398;
    }
    *(undefined8 *)(param_1 + 0x3a0) = *(undefined8 *)(lVar12 + param_1);
    local_58 = *(undefined8 *)(param_1 + 0x268);
    uStack_50 = *(undefined8 *)(param_1 + 0x270);
    local_48 = *(undefined8 *)(param_1 + 600);
    uStack_40 = *(undefined8 *)(param_1 + 0x260);
    lVar12 = 0x390;
    if ((*(uint *)(param_1 + 0x1f0) & 2) == 0) {
      lVar12 = 0x398;
    }
    FUN_140126430(param_1,&local_48,&local_58,*(undefined4 *)(param_1 + 0x1e4),
                  *(undefined8 *)(lVar12 + param_1));
  }
  puVar14 = (undefined8 *)(param_1 + 0x3a0);
  if ((*(uint *)(param_1 + 0x1f0) & 0x8000000) != 0) {
    uVar15 = FUN_140118ab0(param_1);
    (**(code **)(*(longlong *)*puVar14 + 0x68))((longlong *)*puVar14,uVar15);
  }
  if ((*(uint *)(param_1 + 0x1f0) >> 0x1c & 1) != 0) {
    if ((*(uint *)(param_1 + 0x1f0) >> 0x19 & 1) != 0) {
      (**(code **)(*(longlong *)*puVar14 + 0x70))
                ((longlong *)*puVar14,*(undefined4 *)(param_1 + 0x208));
    }
    if ((*(uint *)(param_1 + 0x1f0) & 0x1000000) != 0) {
      (**(code **)(*(longlong *)*puVar14 + 0x78))();
    }
  }
  if ((*(uint *)(param_1 + 0x1f0) & 0x21000000) == 0x21000000) {
    plVar5 = *(longlong **)(param_1 + 0x3a0);
    (**(code **)(*plVar5 + 0x58))(plVar5,*(undefined4 *)(param_1 + 0x208));
  }
  plVar5 = *(longlong **)(param_1 + 0x3a0);
  if (plVar5 != (longlong *)0x0) {
    (**(code **)(*plVar5 + 0x50))();
  }
  if ((*(longlong **)(param_1 + 0x1a0) != (longlong *)0x0) &&
     (**(longlong **)(param_1 + 0x1a0) != 0)) {
    DAT_14032c480 = DAT_14032c480 + 1;
    FUN_140116c40(param_1,local_res8,1);
    DAT_14032c480 = DAT_14032c480 + -1;
  }
  uVar13 = *(uint *)(param_1 + 0x1f0);
  if ((uVar13 >> 0x13 & 1) != 0) {
    if (*(char *)(**(longlong **)(param_1 + 0x1a0) + 0x75) == '\x05') {
      fVar16 = DAT_1402d22d0 / (float)*(byte *)(param_1 + 0x24a);
      *(float *)(param_1 + 0x25c) = -(fVar16 * DAT_1402d250c) + *(float *)(param_1 + 0x25c);
      if (*(float *)(param_1 + 0x270) < DAT_1402d2174) {
        *(float *)(param_1 + 0x270) = fVar16 * DAT_1402d1f38 + *(float *)(param_1 + 0x270);
      }
    }
    if (*(ushort *)(param_1 + 0x22a) < *(ushort *)(param_1 + 0x22c)) {
      *(ushort *)(param_1 + 0x22a) = *(ushort *)(param_1 + 0x22a) + 1;
    }
  }
  if (((uVar13 & 2) == 0) && (*(char *)(**(longlong **)(param_1 + 0x1a0) + 0x7f) == '\x03')) {
    sVar3 = *(short *)(param_1 + 0x442);
    if ((uVar13 & 1) != 0) {
      local_48 = *(undefined8 *)(param_1 + 600);
      uStack_40 = *(undefined8 *)(param_1 + 0x260);
      if (sVar3 == -1) {
        local_38 = (uint)*(byte *)(**(longlong **)(param_1 + 0x1a0) + 0x80);
        uVar11 = FUN_140031f80(*(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0),0x3a,
                               &local_48,0);
        *(undefined2 *)(param_1 + 0x442) = uVar11;
        return 1;
      }
      local_38 = 0;
      uVar11 = FUN_140035b10(*(undefined8 *)(*(longlong *)(param_1 + 0x198) + 0x66ee0),0x3a,
                             &local_48,sVar3,0xffff);
      *(undefined2 *)(param_1 + 0x442) = uVar11;
      return 1;
    }
    if (sVar3 != -1) {
      FUN_140090300(*(undefined8 *)(param_1 + 0x198),sVar3);
    }
    *(undefined2 *)(param_1 + 0x442) = 0xffff;
  }
  return 1;
}

