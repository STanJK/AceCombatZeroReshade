0x1400d4c40  MOV qword ptr [RSP + 0x18],RBX
0x1400d4c45  PUSH RBP
0x1400d4c46  PUSH RSI
0x1400d4c47  PUSH R14
0x1400d4c49  SUB RSP,0x70
0x1400d4c4d  MOV RBX,RCX
0x1400d4c50  MOV RCX,qword ptr [RCX + 0x67160]
0x1400d4c57  MOV RAX,qword ptr [RCX]
0x1400d4c5a  MOV R8,qword ptr [RBX + 0xa82f8]
0x1400d4c61  MOV RDX,qword ptr [RBX + 0xa8248]
0x1400d4c68  CALL qword ptr [RAX + 0x58]
0x1400d4c6b  MOV RAX,qword ptr [RBX + 0x67160]
0x1400d4c72  MOVSXD RCX,dword ptr [RAX + 0x54]
0x1400d4c76  CMP ECX,0x8
0x1400d4c79  JA 0x1400d4fd3
0x1400d4c7f  MOV qword ptr [RSP + 0x98],R15
0x1400d4c87  LEA R15,[0x140000000]
0x1400d4c8e  MOV qword ptr [RSP + 0x90],RDI
0x1400d4c96  MOV EAX,dword ptr [R15 + RCX*0x4 + 0xd5018]
0x1400d4c9e  ADD RAX,R15
0x1400d4ca1  JMP RAX
0x1400d4ca3  XOR EDI,EDI
0x1400d4ca5  MOV EDX,EDI
0x1400d4ca7  CMP byte ptr [RBX + 0xa87e4],DIL
0x1400d4cae  JBE 0x1400d4ceb
0x1400d4cb0  MOV ECX,EDI
0x1400d4cb2  NOP dword ptr [RAX + RAX*0x1]
0x1400d4cc0  MOV RAX,qword ptr [RBX + 0xa8248]
0x1400d4cc7  LEA RCX,[RCX + 0x27a0]
0x1400d4cce  INC EDX
0x1400d4cd0  AND byte ptr [RCX + RAX*0x1 + -0x9f9],0xfe
0x1400d4cd8  MOV qword ptr [RCX + RAX*0x1 + -0xa28],RDI
0x1400d4ce0  MOVZX EAX,byte ptr [RBX + 0xa87e4]
0x1400d4ce7  CMP EDX,EAX
0x1400d4ce9  JL 0x1400d4cc0
0x1400d4ceb  MOV RAX,qword ptr [RBX + 0x697b8]
0x1400d4cf2  MOV RCX,qword ptr [RAX]
0x1400d4cf5  MOV RDX,qword ptr [RCX + 0x110]
0x1400d4cfc  MOV RAX,qword ptr [RDX + 0x1a0]
0x1400d4d03  MOV RCX,qword ptr [RAX]
0x1400d4d06  MOVZX EAX,byte ptr [RCX + 0x6e]
0x1400d4d0a  MOV word ptr [RDX + 0x428],AX
0x1400d4d11  MOV RAX,qword ptr [RBX + 0xa8318]
0x1400d4d18  MOV RCX,qword ptr [RAX + 0x10]
0x1400d4d1c  OR dword ptr [RCX + 0x3a8],0x1000000
0x1400d4d26  JMP 0x1400d4fc3
0x1400d4d2b  XOR DL,DL
0x1400d4d2d  JMP 0x1400d4d35
0x1400d4d2f  MOV DL,0x1
0x1400d4d31  JMP 0x1400d4d35
0x1400d4d33  MOV DL,0x2
0x1400d4d35  MOV RCX,qword ptr [RBX + 0xa8248]
0x1400d4d3c  CALL 0x1400c51e0
0x1400d4d41  MOV RDX,qword ptr [RBX + 0xa8248]
0x1400d4d48  MOVZX ECX,byte ptr [RDX + 0x279a]
0x1400d4d4f  MOV RAX,qword ptr [RDX + 0xff8]
0x1400d4d56  MOVZX ECX,byte ptr [RCX + RAX*0x1 + 0x4]
0x1400d4d5b  MOV R8,qword ptr [RBX + RCX*0x8 + 0x89670]
0x1400d4d63  TEST R8,R8
0x1400d4d66  JZ 0x1400d4d76
0x1400d4d68  MOV RAX,qword ptr [RDX + 0xfd8]
0x1400d4d6f  MOV RCX,qword ptr [RAX]
0x1400d4d72  MOV qword ptr [R8 + 0x68],RCX
0x1400d4d76  MOV RAX,qword ptr [RBX + 0xa8248]
0x1400d4d7d  MOVZX EDX,byte ptr [RAX + 0x279a]
0x1400d4d84  LEA RCX,[RAX + 0x110]
0x1400d4d8b  MOV dword ptr [RCX + 0xaf0],EDX
0x1400d4d91  CALL 0x140158f80
0x1400d4d96  MOV RCX,qword ptr [RBX + 0xa8248]
0x1400d4d9d  CALL 0x14010f560
0x1400d4da2  MOV R9,qword ptr [RBX + 0xa8248]
0x1400d4da9  XOR EDI,EDI
0x1400d4dab  MOV RCX,qword ptr [R9 + 0xfe0]
0x1400d4db2  MOVZX EAX,word ptr [RCX + 0x8]
0x1400d4db6  MOV word ptr [R9 + 0x208e],AX
0x1400d4dbe  MOVZX EAX,byte ptr [RCX + 0xa]
0x1400d4dc2  MOV byte ptr [R9 + 0x2099],AL
0x1400d4dc9  MOVZX EAX,byte ptr [R9 + 0x279a]
0x1400d4dd1  MOVZX ECX,byte ptr [RAX + RCX*0x1 + 0xb]
0x1400d4dd6  MOV byte ptr [R9 + 0x209a],CL
0x1400d4ddd  MOV RAX,qword ptr [RBX + 0xa8248]
0x1400d4de4  MOV dword ptr [RAX + 0x1d90],0xb4
0x1400d4dee  MOV word ptr [RAX + 0x1d94],0x14
0x1400d4df7  MOV dword ptr [RAX + 0x1d98],0x3ca3d70a
0x1400d4e01  MOV qword ptr [RAX + 0x1d9c],0x3f6147ae
0x1400d4e0c  CALL 0x1401c56d0
0x1400d4e11  VMOVDQU XMM0,xmmword ptr [0x1402d35f0]
0x1400d4e19  MOV R14,qword ptr [RBX + 0xa8248]
0x1400d4e20  LEA RAX,[RSP + 0x60]
0x1400d4e25  MOV byte ptr [RSP + 0x50],DIL
0x1400d4e2a  MOV EBP,0x124
0x1400d4e2f  MOV byte ptr [RSP + 0x48],DIL
0x1400d4e34  MOV R8D,EBP
0x1400d4e37  VMOVUPS xmmword ptr [RSP + 0x60],XMM0
0x1400d4e3d  VXORPS XMM0,XMM0,XMM0
0x1400d4e41  VMOVSS dword ptr [RSP + 0x40],XMM0
0x1400d4e47  VMOVSS dword ptr [RSP + 0x38],XMM0
0x1400d4e4d  VMOVSS dword ptr [RSP + 0x30],XMM0
0x1400d4e53  VMOVSS dword ptr [RSP + 0x28],XMM0
0x1400d4e59  MOV EDX,0x1
0x1400d4e5e  MOV qword ptr [RSP + 0x20],RAX
0x1400d4e63  LEA R9,[R14 + 0x70]
0x1400d4e67  CALL 0x1401c6a00
0x1400d4e6c  TEST AL,AL
0x1400d4e6e  JZ 0x1400d4fc3
0x1400d4e74  CALL 0x1401c97a0
0x1400d4e79  CMP byte ptr [RAX + 0x3dc2],0x1
0x1400d4e80  JLE 0x1400d4fc3
0x1400d4e86  MOVZX ESI,word ptr [RAX + 0x138]
0x1400d4e8d  LEA RCX,[RSI + RSI*0x2]
0x1400d4e91  MOV RCX,qword ptr [R15 + RCX*0x8 + 0x32d5a8]
0x1400d4e99  MOVZX EDX,byte ptr [RCX + 0x5b52]
0x1400d4ea0  NOT EDX
0x1400d4ea2  TEST DL,0x1
0x1400d4ea5  JZ 0x1400d4fc3
0x1400d4eab  MOV RCX,RAX
0x1400d4eae  CALL 0x1401c9e60
0x1400d4eb3  MOV R10,RAX
0x1400d4eb6  TEST RAX,RAX
0x1400d4eb9  JZ 0x1400d4fc3
0x1400d4ebf  MOV word ptr [RAX + 0x44],SI
0x1400d4ec3  MOV word ptr [RAX + 0x46],BP
0x1400d4ec7  MOV ECX,dword ptr [R14 + 0x70]
0x1400d4ecb  MOV dword ptr [RAX],ECX
0x1400d4ecd  MOV ECX,dword ptr [R14 + 0x74]
0x1400d4ed1  MOV dword ptr [RAX + 0x4],ECX
0x1400d4ed4  MOV ECX,dword ptr [R14 + 0x78]
0x1400d4ed8  MOV dword ptr [RAX + 0x8],ECX
0x1400d4edb  MOV ECX,dword ptr [R14 + 0x7c]
0x1400d4edf  MOV dword ptr [RAX + 0xc],ECX
0x1400d4ee2  MOV qword ptr [RAX + 0x10],RDI
0x1400d4ee6  MOV dword ptr [RAX + 0x18],EDI
0x1400d4ee9  MOV qword ptr [RAX + 0x1c],0x3f800000
0x1400d4ef1  MOV qword ptr [RAX + 0x24],RDI
0x1400d4ef5  MOV dword ptr [RAX + 0x2c],0x3f800000
0x1400d4efc  MOV dword ptr [RAX + 0x3c],0x3f800000
0x1400d4f03  MOV word ptr [RAX + 0x4a],DI
0x1400d4f07  MOVZX EAX,byte ptr [RAX + 0x70]
0x1400d4f0b  AND AL,0xee
0x1400d4f0d  OR AL,0x6
0x1400d4f0f  MOV byte ptr [R10 + 0x70],AL
0x1400d4f13  LEA RAX,[0x1401caa00]
0x1400d4f1a  MOV qword ptr [R10 + 0x30],RAX
0x1400d4f1e  JMP 0x1400d4fc3
0x1400d4f23  XOR AL,AL
0x1400d4f25  JMP 0x1400d4f2d
0x1400d4f27  MOV AL,0x1
0x1400d4f29  JMP 0x1400d4f2d
0x1400d4f2b  MOV AL,0x2
0x1400d4f2d  MOV RDX,qword ptr [RBX + 0xa82f8]
0x1400d4f34  MOV byte ptr [RDX + 0x85],AL
0x1400d4f3a  MOVZX EAX,AL
0x1400d4f3d  MOV RCX,qword ptr [RDX + RAX*0x8 + 0x50]
0x1400d4f42  MOV qword ptr [RDX + 0x68],RCX
0x1400d4f46  MOV RCX,qword ptr [RBX + 0xa82f8]
0x1400d4f4d  MOV RDX,qword ptr [RCX + 0x68]
0x1400d4f51  TEST RDX,RDX
0x1400d4f54  JNZ 0x1400d4f5a
0x1400d4f56  XOR EDI,EDI
0x1400d4f58  JMP 0x1400d4f6d
0x1400d4f5a  MOVZX EAX,byte ptr [RCX + 0x85]
0x1400d4f61  MOVZX EDX,byte ptr [RDX + 0xd]
0x1400d4f65  MOV RCX,qword ptr [RCX + RAX*0x8 + 0x50]
0x1400d4f6a  MOV RDI,qword ptr [RCX]
0x1400d4f6d  MOVZX EAX,DL
0x1400d4f70  MOV RCX,qword ptr [RBX + RAX*0x8 + 0x89670]
0x1400d4f78  TEST RCX,RCX
0x1400d4f7b  JZ 0x1400d4f81
0x1400d4f7d  MOV qword ptr [RCX + 0x70],RDI
0x1400d4f81  MOV RAX,qword ptr [RBX + 0xa82f8]
0x1400d4f88  MOV RCX,qword ptr [RAX + 0x10]
0x1400d4f8c  MOVZX EDX,byte ptr [RAX + 0x85]
0x1400d4f93  MOV dword ptr [RCX + 0x55c],EDX
0x1400d4f99  CALL 0x14014b4c0
0x1400d4f9e  MOV RDX,qword ptr [RBX + 0xa82f8]
0x1400d4fa5  MOV RAX,qword ptr [RDX + 0x38]
0x1400d4fa9  TEST RAX,RAX
0x1400d4fac  JZ 0x1400d4fc3
0x1400d4fae  MOV RAX,qword ptr [RAX]
0x1400d4fb1  MOVZX ECX,byte ptr [RDX + 0x85]
0x1400d4fb8  MOVZX ECX,byte ptr [RCX + RAX*0x1 + 0xb]
0x1400d4fbd  MOV byte ptr [RDX + 0x83],CL
0x1400d4fc3  MOV RDI,qword ptr [RSP + 0x90]
0x1400d4fcb  MOV R15,qword ptr [RSP + 0x98]
0x1400d4fd3  MOV RAX,qword ptr [RBX + 0x697b8]
0x1400d4fda  LEA R8,[RBX + 0x6a130]
0x1400d4fe1  XOR EDX,EDX
0x1400d4fe3  MOV RCX,qword ptr [RAX]
0x1400d4fe6  MOV RCX,qword ptr [RCX + 0x110]
0x1400d4fed  MOV RCX,qword ptr [RCX + 0x1b8]
0x1400d4ff4  CALL 0x1401040c0
0x1400d4ff9  MOV RCX,qword ptr [RBX + 0x67120]
0x1400d5000  MOV RBX,qword ptr [RSP + 0xa0]
0x1400d5008  ADD RSP,0x70
0x1400d500c  POP R14
0x1400d500e  POP RSI
0x1400d500f  POP RBP
0x1400d5010  JMP 0x140036fe0
