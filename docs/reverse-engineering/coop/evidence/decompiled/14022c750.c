/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14022c750; RVA 0x22c750
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_14022c750(longlong param_1,HWND param_2,int param_3,undefined8 param_4,int param_5)

{
  LRESULT LVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  char *pcVar7;
  ulonglong uVar8;
  undefined *local_48 [4];
  undefined *local_28;
  undefined *local_20;
  undefined *local_18;
  undefined *local_10;
  
  if ((param_3 == 2) || (param_3 == 3)) {
    if (param_5 == 1) {
      FUN_14022ab80(param_1,param_3);
      return;
    }
  }
  else if (param_3 == 4) {
    if (param_5 == 0) {
      LVar1 = SendMessageA(*(HWND *)(param_1 + 0x38),0x147,0,0);
      iVar4 = 0;
      if ((ulonglong)(longlong)(int)LVar1 <
          (ulonglong)(*(longlong *)(param_1 + 0x18) - *(longlong *)(param_1 + 0x10) >> 2)) {
        iVar4 = (int)LVar1;
      }
      lVar6 = (longlong)*(int *)(*(longlong *)(param_1 + 0x10) + (longlong)iVar4 * 4);
      LVar1 = SendMessageA(*(HWND *)(param_1 + 0x30),0x147,0,0);
      uVar2 = SendMessageA(*(HWND *)(param_1 + 0x40),0x147,0,0);
      uVar3 = SendMessageA(*(HWND *)(param_1 + 0x48),0x147,0,0);
      uVar8 = uVar3 & 0xffffffff;
      if ((int)uVar2 == (int)uVar3) {
        uVar8 = 0xffffffff;
      }
      DAT_14030f278 = (&DAT_1402d1944)[lVar6 * 4];
      DAT_14030f274 = (&DAT_1402d1940)[lVar6 * 4];
      uVar5 = DAT_14030f274 >> 0x1f & 3;
      DAT_14032c937 = ((int)(DAT_14030f274 + uVar5) >> 2) * 3 == DAT_14030f278;
      DAT_14032c938 = (int)LVar1 == 1;
      DAT_14031e498 = FUN_14021eae0(uVar2 & 0xffffffff,uVar5,DAT_14030f278,uVar8);
      DAT_14031e4a0 = FUN_14021eae0(uVar8 & 0xffffffff);
      FUN_14024fd88("settings");
      lVar6 = FUN_1402430d8("settings/setting.ini",&DAT_1402cf574);
      if (lVar6 != 0) {
        FUN_140223310(lVar6,
                      "Resolution=%dx%d\t;3840x2160 3200x1800 2560x1440 2048x1152 1920x1080 1600x900 1280x720   2880x2160 2400x1800 1920x1440 1536x1152 1440x1080 1200x900 960x720\n"
                      ,DAT_14030f274,DAT_14030f278);
        pcVar7 = "Windowed";
        if (DAT_14032c938 != '\0') {
          pcVar7 = "Borderless";
        }
        FUN_140223310(lVar6,"ScreenMode=%s\t\t;Windowed Borderless\n",pcVar7);
        local_48[0] = &DAT_1402906f2;
        local_48[1] = &DAT_1402cdcd4;
        local_48[2] = &DAT_1402cdcec;
        local_48[3] = &DAT_1402cf4a0;
        local_28 = &DAT_1402cf4a4;
        local_20 = &DAT_1402cf464;
        local_18 = &DAT_1402cf468;
        local_10 = &DAT_1402cf46c;
        FUN_140223310(lVar6,"SystemLanguage=%s\t\t;JP US UK DE FR IT ES\n",local_48[DAT_140356750]);
        pcVar7 = "False";
        if (DAT_14032c939 != '\0') {
          pcVar7 = "True";
        }
        FUN_140223310(lVar6,"SkipLauncher=%s\t\t;True False\n",pcVar7);
        FUN_140223310(lVar6,"Player1=%llx\n",DAT_14031e498);
        FUN_140223310(lVar6,"Player2=%llx\n",DAT_14031e4a0);
        FUN_140223310(lVar6,"Msaa=x%d\t\t\t\t\t;(Experimental) x1 x2 x4 x8 x16\n",DAT_14030f27c);
        FUN_140243208(lVar6);
      }
      *(undefined1 *)(param_1 + 0xd8) = 1;
                    /* WARNING: Could not recover jumptable at 0x00014022ca14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DestroyWindow(param_2);
      return;
    }
    if (param_5 == 6) {
      FUN_14022b510(param_1,4);
      return;
    }
  }
  if ((param_5 == 3) && ((((param_3 == 0 || (param_3 == 1)) || (param_3 == 2)) || (param_3 == 3))))
  {
    *(int *)(param_1 + 0xe0) = param_3;
    SetWindowTextW(*(HWND *)(param_1 + 0x78),
                   (LPCWSTR)(&PTR_DAT_1402d1b38)
                            [(longlong)*(int *)(param_1 + 0xdc) + (longlong)param_3 * 7]);
    InvalidateRect(*(HWND *)(param_1 + 0x28),(RECT *)(param_1 + 0xa8),0);
  }
  return;
}

