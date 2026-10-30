0x14001aac0  MOV RAX,RSP
0x14001aac3  PUSH RBX
0x14001aac4  PUSH RBP
0x14001aac5  PUSH RDI
0x14001aac6  PUSH R12
0x14001aac8  PUSH R13
0x14001aaca  SUB RSP,0x70
0x14001aace  MOV RDI,R8
0x14001aad1  MOV R12,R9
0x14001aad4  LEA R8,[RCX + 0x1a0]
0x14001aadb  MOV R13D,EDX
0x14001aade  MOV RBX,qword ptr [R8 + 0x8]
0x14001aae2  MOV RBP,RCX
0x14001aae5  CMP RBX,R8
0x14001aae8  JZ 0x14001adb2
0x14001aaee  MOV R9,qword ptr [RBX + 0x8]
0x14001aaf2  MOV qword ptr [RAX + 0x10],R14
0x14001aaf6  MOVZX R14D,byte ptr [RSP + 0xc0]
0x14001aaff  MOV qword ptr [RAX + 0x18],R15
0x14001ab03  VMOVAPS xmmword ptr [RAX + -0x38],XMM6
0x14001ab08  VMOVAPS xmmword ptr [RAX + -0x48],XMM7
0x14001ab0d  VMOVAPS xmmword ptr [RAX + -0x58],XMM8
0x14001ab12  VMOVAPS xmmword ptr [RAX + -0x68],XMM9
0x14001ab17  VMOVAPS xmmword ptr [RAX + -0x78],XMM10
0x14001ab1c  MOV RAX,qword ptr [RBX]
0x14001ab1f  MOV qword ptr [R9],RAX
0x14001ab22  MOV qword ptr [RAX + 0x8],R9
0x14001ab26  LEA R9,[RDI + 0x1f0]
0x14001ab2d  MOV qword ptr [RBX],RBX
0x14001ab30  MOV qword ptr [RBX + 0x8],RBX
0x14001ab34  DEC dword ptr [R8 + 0x70]
0x14001ab38  TEST R14B,R14B
0x14001ab3b  JZ 0x14001ab46
0x14001ab3d  MOV EAX,dword ptr [R9]
0x14001ab40  MOV dword ptr [RDI + 0x3c4],EAX
0x14001ab46  VMOVUPS XMM9,xmmword ptr [RDI + 0x258]
0x14001ab4e  VMOVUPS XMM10,xmmword ptr [RDI + 0x268]
0x14001ab56  VMOVUPS XMM1,XMM9
0x14001ab5b  VSUBSS XMM6,XMM1,dword ptr [RDI + 0x288]
0x14001ab63  VSHUFPS XMM0,XMM1,XMM1,0x55
0x14001ab68  VSUBSS XMM7,XMM0,dword ptr [RDI + 0x28c]
0x14001ab70  VMULSS XMM0,XMM6,XMM6
0x14001ab74  VSHUFPS XMM1,XMM1,XMM1,0xaa
0x14001ab79  VSUBSS XMM8,XMM1,dword ptr [RDI + 0x290]
0x14001ab81  VFMADD231SS XMM0,XMM7,XMM7
0x14001ab86  VFMADD231SS XMM0,XMM8,XMM8
0x14001ab8b  VCOMISS XMM0,dword ptr [0x1402d2bec]
0x14001ab93  MOV qword ptr [RSP + 0xa0],RSI
0x14001ab9b  JBE 0x14001abe3
0x14001ab9d  MOV EAX,dword ptr [RDI + 0x268]
0x14001aba3  LEA RSI,[RDI + 0x1f0]
0x14001abaa  MOV dword ptr [RDI + 0x298],EAX
0x14001abb0  MOV EAX,dword ptr [RDI + 0x26c]
0x14001abb6  MOV dword ptr [RDI + 0x29c],EAX
0x14001abbc  MOV EAX,dword ptr [RDI + 0x270]
0x14001abc2  MOV dword ptr [RDI + 0x2a0],EAX
0x14001abc8  MOV EAX,dword ptr [RDI + 0x274]
0x14001abce  MOV dword ptr [RDI + 0x2a4],EAX
0x14001abd4  VXORPS XMM6,XMM6,XMM6
0x14001abd8  VXORPS XMM7,XMM7,XMM7
0x14001abdc  VXORPS XMM8,XMM8,XMM8
0x14001abe1  JMP 0x14001abe6
0x14001abe3  MOV RSI,R9
0x14001abe6  MOV RCX,qword ptr [RDI + 0x398]
0x14001abed  XOR EAX,EAX
0x14001abef  MOVZX R15D,AX
0x14001abf3  TEST RCX,RCX
0x14001abf6  JZ 0x14001ac13
0x14001abf8  CMP qword ptr [RDI + 0x1c0],RAX
0x14001abff  JNZ 0x14001ac13
0x14001ac01  MOV RAX,qword ptr [RCX]
0x14001ac04  MOV EDX,0x1
0x14001ac09  CALL qword ptr [RAX + 0x48]
0x14001ac0c  VCVTTSS2SI R15D,XMM0
0x14001ac10  MOV R9,RSI
0x14001ac13  MOV RAX,qword ptr [RDI + 0x360]
0x14001ac1a  XOR R10B,R10B
0x14001ac1d  MOV RSI,qword ptr [RSP + 0xa0]
0x14001ac25  XOR R11B,R11B
0x14001ac28  TEST RAX,RAX
0x14001ac2b  JZ 0x14001ac4d
0x14001ac2d  VMOVSS XMM2,dword ptr [0x1402d286c]
0x14001ac35  VMULSS XMM0,XMM2,dword ptr [RAX + 0x490]
0x14001ac3d  VCVTTSS2SI R10D,XMM0
0x14001ac41  VMULSS XMM0,XMM2,dword ptr [RAX + 0x494]
0x14001ac49  VCVTTSS2SI R11D,XMM0
0x14001ac4d  MOV RAX,qword ptr [RDI + 0x3d0]
0x14001ac54  MOVZX R8D,byte ptr [RAX + 0x3f]
0x14001ac59  MOV RAX,qword ptr [R12]
0x14001ac5d  MOV RCX,qword ptr [RAX]
0x14001ac60  MOVZX EDX,byte ptr [RCX + 0x15d]
0x14001ac67  MOV dword ptr [RBX + 0x60],R13D
0x14001ac6b  MOVZX EAX,word ptr [RDI + 0x228]
0x14001ac72  MOV word ptr [RBX + 0x64],AX
0x14001ac76  MOVZX EAX,byte ptr [RDI + 0x234]
0x14001ac7d  MOV byte ptr [RBX + 0x66],AL
0x14001ac80  MOVZX EAX,byte ptr [RDI + 0x235]
0x14001ac87  VMOVSS dword ptr [RBX + 0x20],XMM9
0x14001ac8c  VEXTRACTPS dword ptr [RBX + 0x24],XMM9,0x1
0x14001ac93  VEXTRACTPS dword ptr [RBX + 0x28],XMM9,0x2
0x14001ac9a  VMOVAPS XMM9,xmmword ptr [RSP + 0x30]
0x14001aca0  VMOVSS dword ptr [RBX + 0x2c],XMM6
0x14001aca5  VMOVAPS XMM6,xmmword ptr [RSP + 0x60]
0x14001acab  VMOVSS dword ptr [RBX + 0x30],XMM7
0x14001acb0  VMOVAPS XMM7,xmmword ptr [RSP + 0x50]
0x14001acb6  VMOVSS dword ptr [RBX + 0x34],XMM8
0x14001acbb  VMOVAPS XMM8,xmmword ptr [RSP + 0x40]
0x14001acc1  VMOVSS dword ptr [RBX + 0x3c],XMM10
0x14001acc6  VEXTRACTPS dword ptr [RBX + 0x38],XMM10,0x1
0x14001accd  VEXTRACTPS dword ptr [RBX + 0x40],XMM10,0x2
0x14001acd4  VMOVAPS XMM10,xmmword ptr [RSP + 0x20]
0x14001acda  MOV byte ptr [RBX + 0x6a],R14B
0x14001acde  MOV R14,qword ptr [RSP + 0xa8]
0x14001ace6  MOV byte ptr [RBX + 0x67],AL
0x14001ace9  MOV byte ptr [RBX + 0x68],DL
0x14001acec  MOV byte ptr [RBX + 0x69],R8B
0x14001acf0  MOV byte ptr [RBX + 0x6b],0x0
0x14001acf4  MOV EAX,dword ptr [RDI + 0x298]
0x14001acfa  MOV dword ptr [RBX + 0x48],EAX
0x14001acfd  MOV EAX,dword ptr [RDI + 0x29c]
0x14001ad03  MOV dword ptr [RBX + 0x44],EAX
0x14001ad06  MOV EAX,dword ptr [RDI + 0x2a0]
0x14001ad0c  MOV dword ptr [RBX + 0x4c],EAX
0x14001ad0f  MOV EAX,dword ptr [R9]
0x14001ad12  MOV dword ptr [RBX + 0x50],EAX
0x14001ad15  MOVZX EAX,word ptr [RDI + 0x1f4]
0x14001ad1c  MOV word ptr [RBX + 0x54],AX
0x14001ad20  MOV RAX,qword ptr [R12]
0x14001ad24  MOV RCX,qword ptr [RAX]
0x14001ad27  MOVZX EAX,word ptr [RCX + 0x120]
0x14001ad2e  MOV word ptr [RBX + 0x58],R15W
0x14001ad33  MOV R15,qword ptr [RSP + 0xb0]
0x14001ad3b  MOV word ptr [RBX + 0x56],AX
0x14001ad3f  MOV byte ptr [RBX + 0x5a],R10B
0x14001ad43  MOV byte ptr [RBX + 0x5b],R11B
0x14001ad47  MOVZX EAX,byte ptr [RDI + 0x236]
0x14001ad4e  MOV byte ptr [RBX + 0x5c],AL
0x14001ad51  MOVZX EAX,byte ptr [RDI + 0x237]
0x14001ad58  MOV byte ptr [RBX + 0x5d],AL
0x14001ad5b  MOV RAX,qword ptr [R12]
0x14001ad5f  MOV RCX,qword ptr [RAX]
0x14001ad62  MOVZX EAX,byte ptr [RCX + 0x15d]
0x14001ad69  MOV byte ptr [RBX + 0x5e],AL
0x14001ad6c  MOV RAX,qword ptr [RDI + 0x3d8]
0x14001ad73  TEST RAX,RAX
0x14001ad76  JZ 0x14001ad82
0x14001ad78  MOV qword ptr [RBX + 0x18],RAX
0x14001ad7c  MOV qword ptr [RAX + 0x10],RBX
0x14001ad80  JMP 0x14001ad8a
0x14001ad82  MOV qword ptr [RBX + 0x18],0x0
0x14001ad8a  MOV qword ptr [RBX + 0x10],0x0
0x14001ad92  LEA RCX,[RBP + 0x20]
0x14001ad96  MOV qword ptr [RDI + 0x3d8],RBX
0x14001ad9d  MOV RAX,qword ptr [RCX + 0x8]
0x14001ada1  MOV qword ptr [RAX],RBX
0x14001ada4  MOV qword ptr [RCX + 0x8],RBX
0x14001ada8  MOV qword ptr [RBX],RCX
0x14001adab  MOV qword ptr [RBX + 0x8],RAX
0x14001adaf  INC dword ptr [RCX + 0x70]
0x14001adb2  ADD RSP,0x70
0x14001adb6  POP R13
0x14001adb8  POP R12
0x14001adba  POP RDI
0x14001adbb  POP RBP
0x14001adbc  POP RBX
0x14001adbd  RET
