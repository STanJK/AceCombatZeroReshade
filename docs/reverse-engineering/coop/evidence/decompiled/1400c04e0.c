/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x1400c04e0; RVA 0xc04e0
 * Ghidra-generated research pseudocode, inferred types, not original source. */

void FUN_1400c04e0(undefined8 *param_1,char param_2)

{
  uint *puVar1;
  byte bVar2;
  
  *(char *)(param_1 + 0x12) = param_2;
  bVar2 = 0;
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    if (param_2 == '\0') {
      if ((*(byte *)((longlong)param_1 + 0x1b) != 0xff) &&
         (*(byte *)((longlong)param_1 + 0x1c) != 0xff)) {
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (*(longlong *)*param_1 +
                             (ulonglong)*(byte *)((longlong)param_1 + 0x1b) * 8) + 0x110) + 0x1f0 +
                         (ulonglong)*(byte *)((longlong)param_1 + 0x1c) * 0x520);
        *puVar1 = *puVar1 & 0xffffffef;
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (*(longlong *)*param_1 +
                             (ulonglong)*(byte *)((longlong)param_1 + 0x1b) * 8) + 0x110) + 500 +
                         (ulonglong)*(byte *)((longlong)param_1 + 0x1c) * 0x520);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      *(undefined2 *)((longlong)param_1 + 0x1b) = 0xffff;
      param_1[2] = 0;
      *(undefined1 *)((longlong)param_1 + 0x1d) = 0;
    }
    else {
      bVar2 = 1;
    }
  }
  if ((*(byte *)((longlong)param_1 + 0x3d) & 1) != 0) {
    if (bVar2 < *(byte *)(param_1 + 0x12)) {
      bVar2 = bVar2 + 1;
    }
    else {
      if ((*(byte *)((longlong)param_1 + 0x3b) != 0xff) &&
         (*(byte *)((longlong)param_1 + 0x3c) != 0xff)) {
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (*(longlong *)param_1[4] +
                             (ulonglong)*(byte *)((longlong)param_1 + 0x3b) * 8) + 0x110) + 0x1f0 +
                         (ulonglong)*(byte *)((longlong)param_1 + 0x3c) * 0x520);
        *puVar1 = *puVar1 & 0xffffffef;
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (*(longlong *)param_1[4] +
                             (ulonglong)*(byte *)((longlong)param_1 + 0x3b) * 8) + 0x110) + 500 +
                         (ulonglong)*(byte *)((longlong)param_1 + 0x3c) * 0x520);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      *(undefined2 *)((longlong)param_1 + 0x3b) = 0xffff;
      param_1[6] = 0;
      *(undefined1 *)((longlong)param_1 + 0x3d) = 0;
    }
  }
  if ((*(byte *)((longlong)param_1 + 0x5d) & 1) != 0) {
    if (bVar2 < *(byte *)(param_1 + 0x12)) {
      bVar2 = bVar2 + 1;
    }
    else {
      if ((*(byte *)((longlong)param_1 + 0x5b) != 0xff) &&
         (*(byte *)((longlong)param_1 + 0x5c) != 0xff)) {
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (*(longlong *)param_1[8] +
                             (ulonglong)*(byte *)((longlong)param_1 + 0x5b) * 8) + 0x110) + 0x1f0 +
                         (ulonglong)*(byte *)((longlong)param_1 + 0x5c) * 0x520);
        *puVar1 = *puVar1 & 0xffffffef;
        puVar1 = (uint *)(*(longlong *)
                           (*(longlong *)
                             (*(longlong *)param_1[8] +
                             (ulonglong)*(byte *)((longlong)param_1 + 0x5b) * 8) + 0x110) + 500 +
                         (ulonglong)*(byte *)((longlong)param_1 + 0x5c) * 0x520);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      *(undefined2 *)((longlong)param_1 + 0x5b) = 0xffff;
      param_1[10] = 0;
      *(undefined1 *)((longlong)param_1 + 0x5d) = 0;
    }
  }
  if (((*(byte *)((longlong)param_1 + 0x7d) & 1) != 0) && (*(byte *)(param_1 + 0x12) <= bVar2)) {
    if ((*(byte *)((longlong)param_1 + 0x7b) != 0xff) &&
       (*(byte *)((longlong)param_1 + 0x7c) != 0xff)) {
      puVar1 = (uint *)(*(longlong *)
                         (*(longlong *)
                           (*(longlong *)param_1[0xc] +
                           (ulonglong)*(byte *)((longlong)param_1 + 0x7b) * 8) + 0x110) + 0x1f0 +
                       (ulonglong)*(byte *)((longlong)param_1 + 0x7c) * 0x520);
      *puVar1 = *puVar1 & 0xffffffef;
      puVar1 = (uint *)(*(longlong *)
                         (*(longlong *)
                           (*(longlong *)param_1[0xc] +
                           (ulonglong)*(byte *)((longlong)param_1 + 0x7b) * 8) + 0x110) + 500 +
                       (ulonglong)*(byte *)((longlong)param_1 + 0x7c) * 0x520);
      *puVar1 = *puVar1 & 0xffffffdf;
    }
    *(undefined2 *)((longlong)param_1 + 0x7b) = 0xffff;
    param_1[0xe] = 0;
    *(undefined1 *)((longlong)param_1 + 0x7d) = 0;
  }
  return;
}

