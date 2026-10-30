0x1400a8fb0  SUB RSP,0x78
0x1400a8fb4  VMOVAPS YMM0,ymmword ptr [0x1402d39c0]
0x1400a8fbc  VMOVSS XMM1,dword ptr [0x1402d24fc]
0x1400a8fc4  MOV EAX,dword ptr [RDX]
0x1400a8fc6  LEA R10,[0x14030f690]
0x1400a8fcd  VMOVSS XMM3,dword ptr [0x1402d2a30]
0x1400a8fd5  VMOVUPS ymmword ptr [0x14030f690],YMM0
0x1400a8fdd  VMOVDQU XMM0,xmmword ptr [0x1402d31c0]
0x1400a8fe5  VMOVUPS xmmword ptr [0x14030f6b0],XMM0
0x1400a8fed  VMOVSS XMM0,dword ptr [0x1402d2474]
0x1400a8ff5  VMOVSS dword ptr [0x14030f6c0],XMM0
0x1400a8ffd  VMOVUPS XMM0,xmmword ptr [R8]
0x1400a9002  VMOVSS dword ptr [0x14030f6c4],XMM1
0x1400a900a  VMOVUPS XMM1,xmmword ptr [RDX]
0x1400a900e  MOV dword ptr [0x14030f6d4],0xbb8
0x1400a9018  MOV R9,RCX
0x1400a901b  MOV word ptr [0x14030f6d8],0x50fe
0x1400a9024  MOV byte ptr [0x14030f6da],0xb4
0x1400a902b  MOV dword ptr [RCX + 0xec8],EAX
0x1400a9031  MOV EAX,dword ptr [RDX + 0x4]
0x1400a9034  MOV dword ptr [RCX + 0xecc],EAX
0x1400a903a  MOV EAX,dword ptr [RDX + 0x8]
0x1400a903d  MOV dword ptr [RCX + 0xed0],EAX
0x1400a9043  MOV EAX,dword ptr [RDX + 0xc]
0x1400a9046  LEA RDX,[RSP + 0x60]
0x1400a904b  MOV dword ptr [RCX + 0xed4],EAX
0x1400a9051  MOV EAX,dword ptr [R8]
0x1400a9054  MOV dword ptr [RCX + 0xed8],EAX
0x1400a905a  MOV EAX,dword ptr [R8 + 0x4]
0x1400a905e  MOV dword ptr [RCX + 0xedc],EAX
0x1400a9064  MOV EAX,dword ptr [R8 + 0x8]
0x1400a9068  MOV dword ptr [RCX + 0xee0],EAX
0x1400a906e  MOV EAX,dword ptr [R8 + 0xc]
0x1400a9072  LEA R8,[RSP + 0x50]
0x1400a9077  MOV qword ptr [RSP + 0x40],R10
0x1400a907c  MOV dword ptr [RCX + 0xee4],EAX
0x1400a9082  MOVZX EAX,byte ptr [RSP + 0xa8]
0x1400a908a  MOV byte ptr [RSP + 0x38],0x0
0x1400a908f  MOV dword ptr [RCX + 0xf14],0x453b8000
0x1400a9099  MOVZX ECX,byte ptr [RSP + 0xa0]
0x1400a90a1  MOV byte ptr [RSP + 0x30],0x0
0x1400a90a6  MOV byte ptr [RSP + 0x28],AL
0x1400a90aa  MOV byte ptr [RSP + 0x20],CL
0x1400a90ae  MOV byte ptr [R9 + 0xf18],CL
0x1400a90b5  MOV RCX,R9
0x1400a90b8  MOV byte ptr [R9 + 0xf19],AL
0x1400a90bf  MOV word ptr [R9 + 0xf1a],0x0
0x1400a90c9  MOV qword ptr [R9 + 0xf08],R10
0x1400a90d0  MOV byte ptr [R9 + 0xf38],0x0
0x1400a90d8  VMOVUPS xmmword ptr [RSP + 0x50],XMM0
0x1400a90de  VMOVUPS xmmword ptr [RSP + 0x60],XMM1
0x1400a90e4  VZEROUPPER
0x1400a90e7  CALL 0x1400a43c0
0x1400a90ec  ADD RSP,0x78
0x1400a90f0  RET
