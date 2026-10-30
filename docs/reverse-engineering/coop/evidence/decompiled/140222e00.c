/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x140222e00; RVA 0x222e00
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140222e00(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  undefined1 auStack_148 [32];
  uint local_128;
  uint local_124 [3];
  char local_118 [5];
  char local_113;
  char local_112;
  char acStack_110 [248];
  ulonglong local_18;
  
  local_18 = DAT_140309040 ^ (ulonglong)auStack_148;
  lVar4 = FUN_1402430d8("settings/setting.ini",&DAT_1402cf404);
  if (lVar4 != 0) {
    iVar7 = 0;
    do {
      lVar5 = thunk_FUN_14024fb08(local_118,200,lVar4);
      if (lVar5 == 0) break;
      iVar2 = strncmp(local_118,"Resolution=",0xb);
      lVar5 = 0xb;
      if (iVar2 == 0) {
        local_124[0] = 0;
        puVar9 = local_124;
        local_128 = 0;
        do {
          cVar1 = local_118[lVar5];
          if ((byte)(cVar1 - 0x30U) < 10) {
            *puVar9 = cVar1 + -0x30 + *puVar9 * 10;
          }
          else {
            if (cVar1 != 'x') break;
            puVar9 = &local_128;
          }
          lVar5 = lVar5 + 1;
        } while (lVar5 < 0x14);
        if (((((local_128 == 0x870) || (local_128 == 0x708)) || (local_128 == 0x5a0)) ||
            ((local_128 == 0x480 || (local_128 == 0x438)))) ||
           ((local_128 == 900 || (local_128 == 0x2d0)))) {
          DAT_14030f278 = local_128;
          DAT_14030f274 = local_124[0];
        }
        else {
          DAT_14030f278 = 0;
          DAT_14030f274 = 0;
        }
        if (((DAT_14030f274 != (int)(DAT_14030f278 << 4) / 9) &&
            (DAT_14030f274 !=
             (int)(DAT_14030f278 * 4) / 3 + ((int)(DAT_14030f278 * 4) >> 0x1f) +
             ((DAT_14030f278 & 0x3fffffff) >> 0x1d))) ||
           ((DAT_14030f274 == 0 || (DAT_14030f278 == 0)))) {
          DAT_14030f274 = 0x500;
          DAT_14030f278 = 0x2d0;
        }
        uVar8 = DAT_14030f274;
        if ((int)DAT_14030f274 < 0) {
          uVar8 = DAT_14030f274 + 3;
        }
        DAT_14032c937 = ((int)uVar8 >> 2) * 3 == DAT_14030f278;
      }
      else {
        iVar2 = strncmp(local_118,"ScreenMode=",0xb);
        if (iVar2 == 0) {
          iVar2 = strncmp(acStack_110 + 3,"Borderless",10);
          DAT_14032c938 = iVar2 == 0;
        }
        else {
          iVar2 = strncmp(local_118,"SystemLanguage=",0xf);
          if (iVar2 == 0) {
            iVar2 = strncmp(acStack_110 + 7,"JP",2);
            if (iVar2 == 0) {
              DAT_140356750 = 1;
            }
            else {
              iVar2 = strncmp(acStack_110 + 7,"US",2);
              if (iVar2 == 0) {
                DAT_140356750 = 2;
              }
              else {
                iVar2 = strncmp(acStack_110 + 7,"UK",2);
                if (iVar2 == 0) {
                  DAT_140356750 = 3;
                }
                else {
                  iVar2 = strncmp(acStack_110 + 7,"DE",2);
                  if (iVar2 == 0) {
                    DAT_140356750 = 4;
                  }
                  else {
                    iVar2 = strncmp(acStack_110 + 7,"FR",2);
                    if (iVar2 == 0) {
                      DAT_140356750 = 5;
                    }
                    else {
                      iVar2 = strncmp(acStack_110 + 7,"IT",2);
                      if (iVar2 == 0) {
                        DAT_140356750 = 6;
                      }
                      else {
                        iVar2 = strncmp(acStack_110 + 7,"ES",2);
                        if (iVar2 == 0) {
                          DAT_140356750 = 7;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            iVar2 = strncmp(local_118,"SkipLauncher=",0xd);
            if (iVar2 == 0) {
              iVar2 = strncmp(acStack_110 + 5,"True",4);
              DAT_14032c939 = iVar2 == 0;
            }
            else {
              iVar2 = strncmp(local_118,"Player1=",8);
              if (iVar2 != 0) {
                iVar2 = strncmp(local_118,"Player2=",8);
                if (iVar2 != 0) {
                  iVar2 = strncmp(local_118,"Msaa=",5);
                  if (iVar2 == 0) {
                    iVar2 = strncmp(&local_113,"x2",2);
                    if (iVar2 == 0) {
                      DAT_14030f27c = 2;
                    }
                    else {
                      iVar2 = strncmp(&local_113,"x4",2);
                      if (iVar2 == 0) {
                        DAT_14030f27c = 4;
                      }
                      else {
                        iVar2 = strncmp(&local_113,"x8",2);
                        if (iVar2 == 0) {
                          DAT_14030f27c = 8;
                        }
                        else {
                          iVar2 = strncmp(&local_113,"x16",3);
                          if (iVar2 == 0) {
                            DAT_14030f27c = 0x10;
                          }
                        }
                      }
                    }
                  }
                  goto LAB_1402232cf;
                }
              }
              iVar2 = 8;
              uVar6 = 0;
              lVar5 = 8;
              do {
                cVar1 = local_118[lVar5];
                if ((byte)(cVar1 - 0x30U) < 10) {
                  iVar3 = cVar1 + -0x30;
                }
                else {
                  if (5 < (byte)(cVar1 + 0x9fU)) break;
                  iVar3 = cVar1 + -0x57;
                }
                iVar2 = iVar2 + 1;
                lVar5 = lVar5 + 1;
                uVar6 = uVar6 << 4 | (longlong)iVar3;
              } while (lVar5 < 0x18);
              if (iVar2 != 8) {
                if (local_112 == '1') {
                  DAT_14031e498 = uVar6;
                }
                else {
                  DAT_14031e4a0 = uVar6;
                }
              }
            }
          }
        }
      }
LAB_1402232cf:
      iVar7 = iVar7 + 1;
    } while (iVar7 < 7);
    FUN_140243208(lVar4);
  }
  return;
}

