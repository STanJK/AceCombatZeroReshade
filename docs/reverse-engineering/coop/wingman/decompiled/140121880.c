/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140121880; RVA 0x121880
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_140121880(longlong param_1)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  byte bVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  ushort uVar13;
  longlong lVar14;
  longlong lVar15;
  float fVar16;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xff7fffff;
  lVar14 = (ulonglong)*(byte *)(param_1 + 0x235) * 0x520 +
           *(longlong *)
            (*(longlong *)
              (**(longlong **)(param_1 + 0x180) + (ulonglong)*(byte *)(param_1 + 0x234) * 8) + 0x110
            );
  if (((*(byte *)(param_1 + 0x1f0) & 2) != 0) && ((*(byte *)(lVar14 + 500) & 8) == 0)) {
    lVar6 = *(longlong *)(param_1 + 0x1c0);
    if ((lVar6 != 0) &&
       ((*(short *)(lVar6 + 0x86) != 0 &&
        (*(short *)(lVar6 + 0x86) = *(short *)(lVar6 + 0x86) + -1,
        *(short *)(*(longlong *)(param_1 + 0x1c0) + 0x86) == 0)))) {
      *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xffffff7f;
      *(undefined2 *)(param_1 + 0x236) = 0xffff;
      *(undefined1 *)(param_1 + 0x249) = 0;
    }
    local_48 = *(undefined8 *)(param_1 + 1000);
    uStack_40 = *(undefined8 *)(param_1 + 0x3f0);
    local_38 = *(undefined8 *)(param_1 + 0x3d8);
    uStack_30 = *(undefined8 *)(param_1 + 0x3e0);
    FUN_140125400(param_1,&local_38,&local_48);
    fVar16 = DAT_1402d241c;
    if ((*(byte *)(param_1 + 0x236) != 0xff) && (*(byte *)(param_1 + 0x237) != 0xff)) {
      lVar15 = (ulonglong)*(byte *)(param_1 + 0x237) * 0x520;
      puVar7 = *(undefined8 **)(*(longlong *)(param_1 + 0x1a0) + 0x28);
      lVar6 = *(longlong *)
               (*(longlong *)
                 (**(longlong **)(param_1 + 0x180) + (ulonglong)*(byte *)(param_1 + 0x236) * 8) +
               0x110);
      if ((*(longlong *)(param_1 + 0x1c0) == 0) ||
         ((*(byte *)(*(longlong *)(param_1 + 0x1c0) + 0x81) & 2) == 0)) {
        if (puVar7 != (undefined8 *)0x0) {
          uVar8 = *puVar7;
          *(undefined8 *)(param_1 + 0x88) = uVar8;
          *(undefined1 *)(param_1 + 0x99) = *(undefined1 *)(param_1 + 0x24a);
          if ((*(char *)(param_1 + 0x236) == '\0') && (*(char *)(param_1 + 0x237) == '\0')) {
            uVar9 = *(undefined1 *)
                     (*(longlong *)(*(longlong *)(lVar6 + 0x1b8 + lVar15) + 0xfe0) + 0xe);
          }
          else {
            uVar9 = 0;
          }
          *(undefined1 *)(param_1 + 0xd2) = uVar9;
          auVar2 = *(undefined1 (*) [16])(lVar6 + 600 + lVar15);
          *(int *)(param_1 + 0xc0) = auVar2._0_4_;
          uVar5 = vextractps_avx(auVar2,1);
          *(undefined4 *)(param_1 + 0xc4) = uVar5;
          uVar5 = vextractps_avx(auVar2,2);
          *(undefined4 *)(param_1 + 200) = uVar5;
          uVar5 = vextractps_avx(auVar2,3);
          *(undefined4 *)(param_1 + 0xcc) = uVar5;
          auVar2 = *(undefined1 (*) [16])(param_1 + 1000);
          auVar3 = *(undefined1 (*) [16])(param_1 + 0x3d8);
          *(int *)(param_1 + 0xa0) = auVar3._0_4_;
          uVar5 = vextractps_avx(auVar3,1);
          *(undefined4 *)(param_1 + 0xa4) = uVar5;
          uVar5 = vextractps_avx(auVar3,2);
          *(undefined4 *)(param_1 + 0xa8) = uVar5;
          uVar5 = vextractps_avx(auVar3,3);
          *(undefined4 *)(param_1 + 0xac) = uVar5;
          *(int *)(param_1 + 0xb0) = auVar2._0_4_;
          uVar5 = vextractps_avx(auVar2,1);
          *(undefined4 *)(param_1 + 0xb4) = uVar5;
          uVar5 = vextractps_avx(auVar2,2);
          *(undefined4 *)(param_1 + 0xb8) = uVar5;
          uVar5 = vextractps_avx(auVar2,3);
          *(undefined4 *)(param_1 + 0xbc) = uVar5;
          FUN_14013aa20(param_1 + 0x88);
          if (*(short *)(param_1 + 0xd0) != -1) {
            puVar1 = (uint *)(lVar6 + 0x1fc + lVar15);
            *puVar1 = *puVar1 | 0x8000000;
          }
          cVar10 = FUN_14013ac90(param_1 + 0x88);
          if (cVar10 != '\0') {
            puVar1 = (uint *)(lVar14 + 0x1fc);
            *puVar1 = *puVar1 | 8;
            puVar1 = (uint *)(lVar6 + 0x1fc + lVar15);
            *puVar1 = *puVar1 | 0x100;
          }
          cVar10 = '\x01';
          if ((*(longlong *)(param_1 + 0x1c0) != 0) &&
             (cVar10 = '\x01', *(char *)(*(longlong *)(param_1 + 0x180) + 0x6b) != '\0')) {
            cVar10 = '\0';
          }
          cVar11 = FUN_14013ac40(param_1 + 0x88);
          if ((cVar11 != '\0') && (cVar10 != '\0')) {
            lVar14 = *(longlong *)(param_1 + 0x178);
            local_38 = *(undefined8 *)(param_1 + 1000);
            uStack_30 = *(undefined8 *)(param_1 + 0x3f0);
            local_48 = *(undefined8 *)(param_1 + 0x3d8);
            uStack_40 = *(undefined8 *)(param_1 + 0x3e0);
            iVar12 = FUN_14013d140(lVar14,&local_48,&local_38,*(undefined4 *)(param_1 + 0x468),
                                   *(undefined1 *)(param_1 + 0x234),*(undefined1 *)(param_1 + 0x235)
                                   ,*(undefined1 *)(param_1 + 0x236),
                                   *(undefined1 *)(param_1 + 0x237),uVar8,2);
            if (-1 < iVar12) {
              *(undefined1 *)(lVar14 + 0x1fd90) = 0;
            }
            *(byte *)(param_1 + 0x98) = *(byte *)(param_1 + 0x98) | 1;
            *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) | 0x800000;
            *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 1;
            uVar9 = *(undefined1 *)(param_1 + 0x235);
            *(undefined1 *)(lVar6 + 0x238 + lVar15) = *(undefined1 *)(param_1 + 0x234);
            *(undefined1 *)(lVar6 + 0x239 + lVar15) = uVar9;
            bVar4 = *(byte *)(param_1 + 0x24a);
            lVar14 = *(longlong *)(param_1 + 0x1c0);
            *(char *)(param_1 + 0x24d) = (char)(int)((float)bVar4 * fVar16);
            if (lVar14 != 0) {
              if (*(short *)(lVar14 + 0x86) == 0) {
                if ((short)(ushort)*(byte *)(*(longlong *)(param_1 + 0x88) + 0x49) <
                    *(short *)(lVar6 + 0x428 + lVar15)) {
                  *(ushort *)(lVar14 + 0x86) = (ushort)bVar4 * 2 + (ushort)bVar4;
                  *(undefined1 *)(*(longlong *)(param_1 + 0x180) + 0x6b) = 0;
                  bVar4 = *(byte *)(param_1 + 0x24a);
                  if (*(char *)(*(longlong *)(param_1 + 0x1c0) + 0x88) == '\0') {
                    uVar13 = (ushort)(bVar4 >> 1);
                  }
                  else {
                    uVar13 = (ushort)(bVar4 >> 1) + (ushort)bVar4;
                  }
                  *(ushort *)(param_1 + 0x90) = uVar13;
                  *(ushort *)(param_1 + 0xd0) =
                       (short)(int)((float)bVar4 * *(float *)(*(longlong *)(param_1 + 0x88) + 0x1c))
                       - uVar13;
                }
                else {
                  *(byte *)(*(longlong *)(param_1 + 0x180) + 0x6b) = bVar4;
                }
              }
              else {
                *(undefined2 *)(lVar14 + 0x86) = 0;
                *(undefined1 *)(*(longlong *)(param_1 + 0x180) + 0x6b) =
                     *(undefined1 *)(param_1 + 0x24a);
              }
            }
          }
        }
        puVar7 = *(undefined8 **)(*(longlong *)(param_1 + 0x1a0) + 0x20);
        if (puVar7 != (undefined8 *)0x0) {
          uVar8 = *puVar7;
          *(undefined8 *)(param_1 + 0xd8) = uVar8;
          *(undefined1 *)(param_1 + 0xe9) = *(undefined1 *)(param_1 + 0x24a);
          auVar2 = *(undefined1 (*) [16])(lVar6 + 600 + lVar15);
          *(int *)(param_1 + 0x110) = auVar2._0_4_;
          uVar5 = vextractps_avx(auVar2,1);
          *(undefined4 *)(param_1 + 0x114) = uVar5;
          uVar5 = vextractps_avx(auVar2,2);
          *(undefined4 *)(param_1 + 0x118) = uVar5;
          uVar5 = vextractps_avx(auVar2,3);
          *(undefined4 *)(param_1 + 0x11c) = uVar5;
          auVar2 = *(undefined1 (*) [16])(param_1 + 1000);
          auVar3 = *(undefined1 (*) [16])(param_1 + 0x3d8);
          *(int *)(param_1 + 0xf0) = auVar3._0_4_;
          uVar5 = vextractps_avx(auVar3,1);
          *(undefined4 *)(param_1 + 0xf4) = uVar5;
          uVar5 = vextractps_avx(auVar3,2);
          *(undefined4 *)(param_1 + 0xf8) = uVar5;
          uVar5 = vextractps_avx(auVar3,3);
          *(undefined4 *)(param_1 + 0xfc) = uVar5;
          *(int *)(param_1 + 0x100) = auVar2._0_4_;
          uVar5 = vextractps_avx(auVar2,1);
          *(undefined4 *)(param_1 + 0x104) = uVar5;
          uVar5 = vextractps_avx(auVar2,2);
          *(undefined4 *)(param_1 + 0x108) = uVar5;
          uVar5 = vextractps_avx(auVar2,3);
          *(undefined4 *)(param_1 + 0x10c) = uVar5;
          FUN_14013aa20(param_1 + 0xd8);
          cVar10 = '\x01';
          if ((*(longlong *)(param_1 + 0x1c0) != 0) &&
             (cVar10 = '\x01',
             *(char *)(*(longlong *)(param_1 + 0x180) + 0x6c) != *(char *)(param_1 + 0x235))) {
            cVar10 = '\0';
          }
          cVar11 = FUN_14013ac40(param_1 + 0xd8);
          if ((cVar11 != '\0') && (cVar10 != '\0')) {
            local_38 = *(undefined8 *)(param_1 + 1000);
            uStack_30 = *(undefined8 *)(param_1 + 0x3f0);
            local_48 = *(undefined8 *)(param_1 + 0x3d8);
            uStack_40 = *(undefined8 *)(param_1 + 0x3e0);
            FUN_14013ace0(*(longlong *)(param_1 + 0x178) + 0xca0,&local_48,&local_38,
                          *(undefined4 *)(param_1 + 0x468),*(undefined1 *)(param_1 + 0x234),
                          *(undefined1 *)(param_1 + 0x235),uVar8,0);
            *(byte *)(param_1 + 0xe8) = *(byte *)(param_1 + 0xe8) | 1;
            *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x10;
            *(char *)(param_1 + 0x24d) = (char)(int)((float)*(byte *)(param_1 + 0x24a) * fVar16);
          }
        }
      }
    }
  }
  return;
}

