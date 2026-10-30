/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400a4ea0; RVA 0xa4ea0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400a4ea0(longlong *param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  longlong unaff_GS_OFFSET;
  undefined8 uVar10;
  float fVar11;
  undefined2 local_res10 [4];
  undefined2 local_res18 [4];
  uint local_res20;
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  
  local_res20 = 1;
  local_78 = 0x10;
  local_70 = 0;
  fVar11 = DAT_1402d2478;
  do {
    uVar7 = local_res20;
    if (((*(uint *)((longlong)param_1 + 0x5c) & local_res20) != 0) &&
       (puVar1 = (undefined8 *)(local_70 + 0x438 + (longlong)param_1),
       *(char *)(local_70 + 0x4d8 + (longlong)param_1) == '\x01')) {
      local_68 = puVar1[0xd];
      uStack_60 = puVar1[0xe];
      local_58 = *puVar1;
      uStack_50 = puVar1[1];
      bVar6 = (**(code **)(*param_1 + 0x20))
                        (param_1,param_1[2],puVar1,&local_58,&local_68,
                         fVar11 * *(float *)(puVar1[8] + 0x18));
      if ((*(char *)(puVar1 + 10) != -1) && (*(char *)((longlong)puVar1 + 0x51) != -1)) {
        iVar8 = 0;
        lVar9 = 0;
        bVar2 = *(byte *)(param_1[2] + 0x37);
        if ((ulonglong)bVar2 != 0) {
          do {
            lVar4 = *(longlong *)(*(longlong *)(*(longlong *)param_1[2] + lVar9 * 8) + 0x110);
            lVar5 = *(longlong *)(lVar4 + 0x1b8);
            if (((lVar5 != 0) && (bVar6 != 0)) && (iVar8 == bVar6 - 1)) {
              if (0 < *(short *)(lVar4 + 0x428)) {
                uVar10 = FUN_1401c56d0();
                cVar3 = *(char *)(lVar5 + 0x2094);
                if (cVar3 == '\0') {
                  local_res10[0] = 0x12d;
                }
                else if (cVar3 == '\x02') {
                  local_res10[0] = 0x12e;
                }
                else {
                  if (cVar3 != '\x01') goto LAB_1400a5016;
                  local_res10[0] = 0x12f;
                }
                local_res18[0] = 1;
                FUN_1401c6150(uVar10,local_res18,local_res10);
              }
LAB_1400a5016:
              if (*(short *)(lVar4 + 0x428) < 1) {
                FUN_1401c56d0();
                if ((*(int *)(**(longlong **)(unaff_GS_OFFSET + 0x58) + 4) < DAT_1437daf04) &&
                   (FUN_14022d540(&DAT_1437daf04), DAT_1437daf04 == -1)) {
                  FUN_1401c93c0();
                  _Init_thread_footer(&DAT_1437daf04);
                }
                FUN_1401cb010(&DAT_1437daf20,puVar1 + 0x13);
              }
            }
            iVar8 = iVar8 + 1;
            lVar9 = lVar9 + 1;
            uVar7 = local_res20;
          } while (lVar9 < (longlong)(ulonglong)bVar2);
        }
      }
    }
    local_res20 = uVar7 << 1 | (uint)((int)uVar7 < 0);
    local_70 = local_70 + 0xa8;
    local_78 = local_78 + -1;
    if (local_78 == 0) {
      return;
    }
  } while( true );
}

