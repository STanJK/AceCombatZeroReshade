0x1401c6a00  MOV qword ptr [RSP + 0x8],RBX
0x1401c6a05  MOV qword ptr [RSP + 0x10],RSI
0x1401c6a0a  PUSH RDI
0x1401c6a0b  SUB RSP,0x20
0x1401c6a0f  CMP dword ptr [0x14032c480],0x0
0x1401c6a16  MOV RBX,R9
0x1401c6a19  MOVZX EDI,R8W
0x1401c6a1d  MOVZX ESI,DX
0x1401c6a20  SETG AL
0x1401c6a23  CMP byte ptr [0x14033bd60],0x0
0x1401c6a2a  JNZ 0x1401c6b56
0x1401c6a30  TEST AL,AL
0x1401c6a32  JNZ 0x1401c6b44
0x1401c6a38  CALL 0x140019ef0
0x1401c6a3d  MOV RCX,RAX
0x1401c6a40  MOV R10,RAX
0x1401c6a43  CALL 0x14001b280
0x1401c6a48  MOV R9,RAX
0x1401c6a4b  TEST RAX,RAX
0x1401c6a4e  JZ 0x1401c6b44
0x1401c6a54  MOV RCX,qword ptr [R10 + 0x428]
0x1401c6a5b  VMOVSS XMM0,dword ptr [RSP + 0x58]
0x1401c6a61  VMOVSS XMM1,dword ptr [RSP + 0x60]
0x1401c6a67  MOV RDX,qword ptr [RCX + 0x697b8]
0x1401c6a6e  MOV RCX,qword ptr [RDX]
0x1401c6a71  MOV RAX,qword ptr [RCX + 0x110]
0x1401c6a78  MOVZX EDX,byte ptr [RCX + 0x15d]
0x1401c6a7f  MOV ECX,dword ptr [R10]
0x1401c6a82  MOV dword ptr [R9 + 0x60],ECX
0x1401c6a86  MOVZX ECX,word ptr [RAX + 0x228]
0x1401c6a8d  MOV word ptr [R9 + 0x64],CX
0x1401c6a92  MOVZX ECX,byte ptr [RAX + 0x234]
0x1401c6a99  MOV byte ptr [R9 + 0x66],CL
0x1401c6a9d  MOVZX EAX,byte ptr [RAX + 0x235]
0x1401c6aa4  MOV RCX,qword ptr [RSP + 0x50]
0x1401c6aa9  MOV byte ptr [R9 + 0x67],AL
0x1401c6aad  MOV byte ptr [R9 + 0x68],DL
0x1401c6ab1  MOV word ptr [R9 + 0x69],0x0
0x1401c6ab8  MOV byte ptr [R9 + 0x6b],0x7
0x1401c6abd  MOV word ptr [R9 + 0x48],SI
0x1401c6ac2  MOV word ptr [R9 + 0x4a],DI
0x1401c6ac7  MOV EAX,dword ptr [RBX]
0x1401c6ac9  MOV dword ptr [R9 + 0x20],EAX
0x1401c6acd  MOV EAX,dword ptr [RBX + 0x4]
0x1401c6ad0  MOV dword ptr [R9 + 0x24],EAX
0x1401c6ad4  MOV EAX,dword ptr [RBX + 0x8]
0x1401c6ad7  MOV dword ptr [R9 + 0x28],EAX
0x1401c6adb  MOV EAX,dword ptr [RCX]
0x1401c6add  MOV dword ptr [R9 + 0x2c],EAX
0x1401c6ae1  MOV EAX,dword ptr [RCX + 0x4]
0x1401c6ae4  MOV dword ptr [R9 + 0x30],EAX
0x1401c6ae8  MOV EAX,dword ptr [RCX + 0x8]
0x1401c6aeb  LEA RCX,[R10 + 0x98]
0x1401c6af2  MOV dword ptr [R9 + 0x34],EAX
0x1401c6af6  MOVZX EAX,byte ptr [RSP + 0x78]
0x1401c6afb  MOV byte ptr [R9 + 0x4d],AL
0x1401c6aff  MOVZX EAX,byte ptr [RSP + 0x80]
0x1401c6b07  VMOVSS dword ptr [R9 + 0x38],XMM0
0x1401c6b0d  VMOVSS XMM0,dword ptr [RSP + 0x68]
0x1401c6b13  VMOVSS dword ptr [R9 + 0x3c],XMM1
0x1401c6b19  VMOVSS XMM1,dword ptr [RSP + 0x70]
0x1401c6b1f  MOV byte ptr [R9 + 0x4c],AL
0x1401c6b23  VMOVSS dword ptr [R9 + 0x40],XMM0
0x1401c6b29  VMOVSS dword ptr [R9 + 0x44],XMM1
0x1401c6b2f  MOV RAX,qword ptr [RCX + 0x8]
0x1401c6b33  MOV qword ptr [RAX],R9
0x1401c6b36  MOV qword ptr [RCX + 0x8],R9
0x1401c6b3a  MOV qword ptr [R9],RCX
0x1401c6b3d  MOV qword ptr [R9 + 0x8],RAX
0x1401c6b41  INC dword ptr [RCX + 0x70]
0x1401c6b44  MOV AL,0x1
0x1401c6b46  MOV RBX,qword ptr [RSP + 0x30]
0x1401c6b4b  MOV RSI,qword ptr [RSP + 0x38]
0x1401c6b50  ADD RSP,0x20
0x1401c6b54  POP RDI
0x1401c6b55  RET
0x1401c6b56  MOV RBX,qword ptr [RSP + 0x30]
0x1401c6b5b  TEST AL,AL
0x1401c6b5d  MOV RSI,qword ptr [RSP + 0x38]
0x1401c6b62  SETNZ AL
0x1401c6b65  ADD RSP,0x20
0x1401c6b69  POP RDI
0x1401c6b6a  RET
