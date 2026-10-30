/* ACZ SHA256: 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
 * VA 0x14010b000; RVA 0x10b000
 * Ghidra-generated research pseudocode, inferred types, not original source. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14010b000(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char cVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 uVar20;
  undefined1 uVar21;
  byte bVar22;
  longlong lVar23;
  byte bVar24;
  uint uVar25;
  uint uVar26;
  ulonglong uVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  byte bVar30;
  undefined8 *puVar31;
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  undefined8 local_13c;
  undefined8 uStack_134;
  undefined8 uStack_12c;
  undefined8 uStack_124;
  undefined2 local_11c;
  undefined2 local_11a;
  undefined2 local_118;
  undefined2 local_116;
  undefined2 local_114;
  undefined2 local_112;
  undefined2 local_110;
  undefined2 local_10e;
  undefined1 local_10c [4];
  undefined1 local_108 [4];
  undefined1 local_104 [7];
  undefined1 local_fd [4];
  undefined1 local_f9 [5];
  undefined2 local_f4;
  undefined1 local_f2;
  undefined1 local_f1;
  undefined1 local_f0;
  undefined1 local_ef;
  undefined1 local_ee;
  undefined1 local_e9;
  undefined1 local_e8;
  undefined1 local_e7;
  undefined1 local_e6;
  undefined1 local_e5;
  undefined1 local_e4;
  undefined1 local_e3;
  undefined1 local_e2;
  undefined1 local_e1;
  undefined1 local_e0;
  undefined1 local_df;
  undefined1 local_de;
  undefined1 local_dd;
  undefined1 local_dc;
  undefined1 local_db;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1854);
  uVar2 = *(undefined4 *)(param_1 + 0x1848);
  uVar3 = *(undefined4 *)(param_1 + 0x17f8);
  uVar4 = *(undefined4 *)(param_1 + 0x17fc);
  uVar5 = *(undefined4 *)(param_1 + 0x1800);
  uVar6 = *(undefined4 *)(param_1 + 0x1818);
  uVar7 = *(undefined4 *)(param_1 + 0x181c);
  uVar8 = *(undefined4 *)(param_1 + 0x1820);
  uVar9 = *(undefined4 *)(param_1 + 0x1808);
  uVar10 = *(undefined4 *)(param_1 + 0x180c);
  uVar11 = *(undefined4 *)(param_1 + 0x1810);
  local_f4 = *(undefined2 *)(param_1 + 0x208e);
  local_f2 = *(undefined1 *)(param_1 + 0x2099);
  local_f1 = *(undefined1 *)(param_1 + 0x209a);
  local_f0 = *(undefined1 *)(param_1 + 0x2098);
  local_ef = *(undefined1 *)(param_1 + 0x1da6);
  uVar12 = *(undefined4 *)(param_1 + 0x1850);
  uVar13 = *(undefined4 *)(param_1 + 0x1858);
  uVar14 = *(undefined4 *)(param_1 + 0x184c);
  if ((char)*(byte *)(param_1 + 0x1eee) < '\0') {
    local_ee = 2;
  }
  else if (((*(byte *)(param_1 + 0x1eee) & 0x40) == 0) && (*(char *)(param_1 + 0x20a7) == '\0')) {
    local_ee = 0;
  }
  else {
    local_ee = 1;
    *(undefined1 *)(param_1 + 0x20a7) = 0;
  }
  bVar22 = *(byte *)(param_1 + 0x1ec8);
  uVar27 = 0;
  if (bVar22 == 0) {
    bVar22 = 0;
  }
  else {
    puVar28 = local_108;
    puVar29 = (undefined1 *)(param_1 + 0x1e53);
    puVar31 = &uStack_12c;
    do {
      lVar23 = (uVar27 & 0xff) * 0x20;
      uVar26 = (int)uVar27 + 1;
      uVar27 = (ulonglong)uVar26;
      *(undefined4 *)(puVar31 + -2) = *(undefined4 *)(lVar23 + 0x1e48 + param_1);
      *(undefined4 *)puVar31 = *(undefined4 *)(lVar23 + 0x1e4c + param_1);
      puVar28[-4] = puVar29[2];
      *puVar28 = *puVar29;
      puVar28[4] = puVar29[1];
      puVar28 = puVar28 + 1;
      puVar29 = puVar29 + 0x20;
      puVar31 = (undefined8 *)((longlong)puVar31 + 4);
      uVar25 = 0;
    } while ((int)uVar26 < (int)(uint)bVar22);
    do {
      if (((byte)uVar25 < *(byte *)(param_1 + 0x1ec8)) &&
         (lVar23 = (ulonglong)(uVar25 & 0xff) * 0x20,
         (*(byte *)(lVar23 + 0x1e55 + param_1) & 2) != 0)) {
        uVar21 = *(undefined1 *)(lVar23 + 0x1e54 + param_1);
        uVar20 = *(undefined1 *)(lVar23 + 0x1e53 + param_1);
      }
      else {
        uVar21 = 0xff;
        uVar20 = 0xff;
      }
      local_fd[(int)uVar25] = uVar20;
      uVar26 = uVar25 + 1;
      local_f9[(int)uVar25] = uVar21;
      bVar22 = *(byte *)(param_1 + 0x1ec8);
      uVar25 = uVar26;
    } while ((int)uVar26 < (int)(uint)bVar22);
  }
  cVar15 = *(char *)(param_1 + 0x2098);
  if (cVar15 == '\0') {
    local_e9 = *(undefined1 *)(param_1 + 0x209c);
    auVar16 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 0x1f10)));
    auVar17 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x1f19)));
    local_188 = DAT_1402d22d0 -
                auVar16._0_4_ /
                (*(float *)(param_1 + 0x1f14) * *(float *)(*(longlong *)(param_1 + 0x1f08) + 0x24) *
                auVar17._0_4_);
    auVar16 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 0x1f28)));
    auVar17 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x1f31)));
    local_184 = DAT_1402d22d0 -
                auVar16._0_4_ /
                (*(float *)(param_1 + 0x1f2c) * *(float *)(*(longlong *)(param_1 + 0x1f20) + 0x24) *
                auVar17._0_4_);
  }
  else if (cVar15 == '\x01') {
    if (*(char *)(*(longlong *)(param_1 + 0xfd8) + 0xd) == '\x15') {
      local_e9 = *(undefined1 *)(param_1 + 0x209d);
      lVar23 = 0x14e - (ulonglong)*(byte *)(param_1 + 0x209d);
      local_188 = DAT_1402d22d0 -
                  (float)*(ushort *)(param_1 + 8 + lVar23 * 0x18) /
                  (*(float *)(param_1 + 0xc + lVar23 * 0x18) *
                   *(float *)(*(longlong *)(param_1 + lVar23 * 0x18) + 0x24) *
                  (float)*(byte *)(param_1 + 0x11 + lVar23 * 0x18));
    }
    else {
      local_e9 = *(undefined1 *)(param_1 + 0x209d);
      auVar16 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 8000)));
      auVar17 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x1f49)));
      auVar18 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x1f61)));
      local_188 = DAT_1402d22d0 -
                  auVar16._0_4_ /
                  (*(float *)(*(longlong *)(param_1 + 0x1f38) + 0x24) * *(float *)(param_1 + 0x1f44)
                  * auVar17._0_4_);
      auVar16 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 0x1f70)));
      auVar17 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 0x1f58)));
      auVar19 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x1f79)));
      local_184 = DAT_1402d22d0 -
                  auVar17._0_4_ /
                  (*(float *)(*(longlong *)(param_1 + 0x1f50) + 0x24) * *(float *)(param_1 + 0x1f5c)
                  * auVar18._0_4_);
      local_180 = DAT_1402d22d0 -
                  auVar16._0_4_ /
                  (*(float *)(*(longlong *)(param_1 + 0x1f68) + 0x24) * *(float *)(param_1 + 0x1f74)
                  * auVar19._0_4_);
      auVar16 = vcvtdq2ps_avx(ZEXT216(*(ushort *)(param_1 + 0x1f88)));
      auVar17 = vcvtdq2ps_avx(ZEXT116(*(byte *)(param_1 + 0x1f91)));
      local_17c = DAT_1402d22d0 -
                  auVar16._0_4_ /
                  (*(float *)(*(longlong *)(param_1 + 0x1f80) + 0x24) * *(float *)(param_1 + 0x1f8c)
                  * auVar17._0_4_);
    }
  }
  if (cVar15 == '\0') {
    bVar30 = 1;
    bVar24 = 1;
  }
  else {
    bVar24 = *(byte *)(*(longlong *)(param_1 + 0xfd8) + 0xc);
    bVar30 = bVar24 & 1;
    bVar24 = bVar24 >> 1 & 1;
  }
  *(undefined4 *)(param_1 + 0x18bc) = *(undefined4 *)(param_1 + 0x1d40);
  *(undefined4 *)(param_1 + 0x18c0) = *(undefined4 *)(param_1 + 0x1d44);
  *(undefined4 *)(param_1 + 0x18c4) = *(undefined4 *)(param_1 + 0x1d48);
  *(undefined4 *)(param_1 + 0x18c8) = *(undefined4 *)(param_1 + 0x1d4c);
  *(undefined4 *)(param_1 + 0x18ac) = *(undefined4 *)(param_1 + 0x15d0);
  *(undefined4 *)(param_1 + 0x18b0) = *(undefined4 *)(param_1 + 0x15d4);
  *(undefined4 *)(param_1 + 0x18b4) = *(undefined4 *)(param_1 + 0x15d8);
  *(undefined4 *)(param_1 + 0x18b8) = *(undefined4 *)(param_1 + 0x15dc);
  *(float *)(param_1 + 0x18cc) = local_188;
  *(float *)(param_1 + 0x18d0) = local_184;
  *(float *)(param_1 + 0x18d4) = local_180;
  *(float *)(param_1 + 0x18d8) = local_17c;
  *(undefined4 *)(param_1 + 0x1900) = uVar2;
  *(undefined4 *)(param_1 + 0x1904) = uVar1;
  *(undefined4 *)(param_1 + 0x190c) = uVar13;
  *(undefined4 *)(param_1 + 0x18dc) = uVar3;
  *(undefined4 *)(param_1 + 0x18e0) = uVar4;
  *(undefined4 *)(param_1 + 0x18e4) = uVar5;
  *(undefined4 *)(param_1 + 0x18e8) = uVar6;
  *(undefined4 *)(param_1 + 0x18ec) = uVar7;
  *(undefined4 *)(param_1 + 0x18f0) = uVar8;
  *(undefined4 *)(param_1 + 0x18f4) = uVar9;
  *(undefined4 *)(param_1 + 0x18f8) = uVar10;
  *(undefined4 *)(param_1 + 0x18fc) = uVar11;
  *(undefined4 *)(param_1 + 0x1908) = uVar12;
  *(undefined4 *)(param_1 + 0x1910) = uVar14;
  *(undefined4 *)(param_1 + 0x1914) = *(undefined4 *)(param_1 + 0x1ec4);
  *(undefined8 *)(param_1 + 0x1918) = local_13c;
  *(undefined8 *)(param_1 + 0x1920) = uStack_134;
  *(undefined8 *)(param_1 + 0x1928) = uStack_12c;
  *(undefined8 *)(param_1 + 0x1930) = uStack_124;
  *(undefined2 *)(param_1 + 0x1938) = local_11c;
  *(undefined2 *)(param_1 + 0x193a) = local_11a;
  *(undefined2 *)(param_1 + 0x193c) = local_118;
  *(undefined2 *)(param_1 + 0x193e) = local_116;
  *(undefined2 *)(param_1 + 0x1940) = local_114;
  *(undefined2 *)(param_1 + 0x1942) = local_112;
  *(undefined2 *)(param_1 + 0x1944) = local_110;
  *(undefined2 *)(param_1 + 0x1946) = local_10e;
  *(undefined1 *)(param_1 + 0x1948) = local_10c[0];
  *(undefined1 *)(param_1 + 0x1949) = local_10c[1];
  *(undefined1 *)(param_1 + 0x194a) = local_10c[2];
  *(undefined1 *)(param_1 + 0x194b) = local_10c[3];
  *(undefined1 *)(param_1 + 0x194c) = local_108[0];
  *(undefined1 *)(param_1 + 0x194d) = local_108[1];
  *(undefined1 *)(param_1 + 0x194e) = local_108[2];
  *(undefined1 *)(param_1 + 0x194f) = local_108[3];
  *(undefined1 *)(param_1 + 0x1950) = local_104[0];
  *(undefined1 *)(param_1 + 0x1951) = local_104[1];
  *(undefined1 *)(param_1 + 0x1952) = local_104[2];
  *(undefined1 *)(param_1 + 0x1953) = local_104[3];
  *(undefined1 *)(param_1 + 0x1956) = *(undefined1 *)(param_1 + 0x1eed);
  *(byte *)(param_1 + 0x1954) = bVar22;
  *(undefined1 *)(param_1 + 0x1955) = *(undefined1 *)(param_1 + 0x1eec);
  *(undefined1 *)(param_1 + 0x1957) = local_fd[0];
  *(undefined1 *)(param_1 + 0x1958) = local_fd[1];
  *(undefined1 *)(param_1 + 0x1959) = local_fd[2];
  *(undefined1 *)(param_1 + 0x195a) = local_fd[3];
  *(undefined1 *)(param_1 + 0x195b) = local_f9[0];
  *(undefined1 *)(param_1 + 0x195c) = local_f9[1];
  *(undefined1 *)(param_1 + 0x195d) = local_f9[2];
  *(undefined1 *)(param_1 + 0x195e) = local_f9[3];
  *(undefined1 *)(param_1 + 0x1967) = *(undefined1 *)(param_1 + 0x20bc);
  *(byte *)(param_1 + 0x1969) = bVar24;
  *(byte *)(param_1 + 0x196a) = *(byte *)(param_1 + 0x1863) >> 1 & 1;
  *(undefined2 *)(param_1 + 0x1960) = local_f4;
  *(undefined1 *)(param_1 + 0x1962) = local_f2;
  *(undefined1 *)(param_1 + 0x1963) = local_f1;
  *(undefined1 *)(param_1 + 0x1964) = local_f0;
  *(undefined1 *)(param_1 + 0x1965) = local_ef;
  *(undefined1 *)(param_1 + 0x1966) = local_ee;
  *(byte *)(param_1 + 0x1968) = bVar30;
  *(undefined1 *)(param_1 + 0x196b) = local_e9;
  *(undefined1 *)(param_1 + 0x196c) = local_e8;
  *(undefined1 *)(param_1 + 0x196d) = local_e7;
  *(undefined1 *)(param_1 + 0x196e) = local_e6;
  *(undefined1 *)(param_1 + 0x196f) = local_e5;
  *(undefined1 *)(param_1 + 0x1970) = local_e4;
  *(undefined1 *)(param_1 + 0x1971) = local_e3;
  *(undefined1 *)(param_1 + 0x1972) = local_e2;
  *(undefined1 *)(param_1 + 0x1973) = local_e1;
  *(undefined1 *)(param_1 + 0x1974) = local_e0;
  *(undefined1 *)(param_1 + 0x1975) = local_df;
  *(undefined1 *)(param_1 + 0x1976) = local_de;
  *(undefined1 *)(param_1 + 0x1977) = local_dd;
  *(undefined1 *)(param_1 + 0x1978) = local_dc;
  *(undefined1 *)(param_1 + 0x1979) = local_db;
  bVar22 = *(byte *)(param_1 + 0x1aed) & 0xe0;
  cVar15 = *(char *)(*(longlong *)(param_1 + 0x2040) + 0x68);
  *(byte *)(param_1 + 0x1aed) = bVar22;
  if (cVar15 == '\0') {
    bVar22 = bVar22 | 1;
  }
  else if (cVar15 == '\x01') {
    bVar22 = bVar22 | 2;
  }
  else if (cVar15 == '\x02') {
    bVar22 = bVar22 | 4;
  }
  else if (cVar15 == '\x03') {
    bVar22 = bVar22 | 8;
  }
  else {
    if (cVar15 != '\x04') goto LAB_14010ba0a;
    bVar22 = bVar22 | 0x10;
  }
  *(byte *)(param_1 + 0x1aed) = bVar22;
LAB_14010ba0a:
  *(byte *)(param_1 + 0x1aed) =
       ((~*(byte *)(*(longlong *)(param_1 + 0x2040) + 0x69) & 1) + 1) * ' ' | bVar22 & 0x9f;
  return;
}

