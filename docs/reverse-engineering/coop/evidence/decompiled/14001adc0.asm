0x14001adc0  MOV qword ptr [RSP + 0x8],RBX
0x14001adc5  MOV qword ptr [RSP + 0x10],RSI
0x14001adca  MOV qword ptr [RSP + 0x18],RDI
0x14001adcf  LEA RBX,[RCX + 0x1a0]
0x14001add6  MOV ESI,EDX
0x14001add8  MOV R11,qword ptr [RBX + 0x8]
0x14001addc  MOV RDI,RCX
0x14001addf  CMP R11,RBX
0x14001ade2  JZ 0x14001affa
0x14001ade8  MOV R10,qword ptr [R11 + 0x8]
0x14001adec  MOV RAX,qword ptr [R11]
0x14001adef  MOV qword ptr [R10],RAX
0x14001adf2  MOV qword ptr [RAX + 0x8],R10
0x14001adf6  XOR R10D,R10D
0x14001adf9  MOV qword ptr [R11],R11
0x14001adfc  MOV qword ptr [R11 + 0x8],R11
0x14001ae00  DEC dword ptr [RBX + 0x70]
0x14001ae03  MOV qword ptr [R8 + 0x3d0],R11
0x14001ae0a  MOV RAX,qword ptr [R9]
0x14001ae0d  MOV RCX,qword ptr [RAX]
0x14001ae10  MOVZX EDX,byte ptr [RCX + 0x15d]
0x14001ae17  MOV dword ptr [R11 + 0x60],ESI
0x14001ae1b  MOVZX EAX,word ptr [R8 + 0x228]
0x14001ae23  MOV word ptr [R11 + 0x64],AX
0x14001ae28  MOVZX EAX,byte ptr [R8 + 0x234]
0x14001ae30  MOV byte ptr [R11 + 0x66],AL
0x14001ae34  MOVZX EAX,byte ptr [R8 + 0x235]
0x14001ae3c  MOV byte ptr [R11 + 0x67],AL
0x14001ae40  MOVZX EAX,byte ptr [RSP + 0x28]
0x14001ae45  MOV byte ptr [R11 + 0x6a],AL
0x14001ae49  MOV byte ptr [R11 + 0x68],DL
0x14001ae4d  MOV byte ptr [R11 + 0x69],0x0
0x14001ae52  MOV byte ptr [R11 + 0x6b],0x1
0x14001ae57  MOV RDX,qword ptr [R8 + 0x1a0]
0x14001ae5e  TEST RDX,RDX
0x14001ae61  JNZ 0x14001ae68
0x14001ae63  MOV EDX,R10D
0x14001ae66  JMP 0x14001ae6b
0x14001ae68  MOV RDX,qword ptr [RDX]
0x14001ae6b  MOVZX EAX,word ptr [RDX + 0x5c]
0x14001ae6f  MOV word ptr [R11 + 0x20],AX
0x14001ae74  VXORPS XMM0,XMM0,XMM0
0x14001ae78  VROUNDSS XMM0,XMM0,dword ptr [R8 + 0x41c],0x2
0x14001ae82  VCVTTSS2SI EAX,XMM0
0x14001ae86  MOV word ptr [R11 + 0x22],AX
0x14001ae8b  MOVZX EAX,word ptr [RDX + 0x5e]
0x14001ae8f  MOV word ptr [R11 + 0x24],AX
0x14001ae94  MOVZX EAX,word ptr [RDX + 0x60]
0x14001ae98  MOV word ptr [R11 + 0x26],AX
0x14001ae9d  MOVZX EAX,word ptr [RDX + 0x6c]
0x14001aea1  MOV word ptr [R11 + 0x28],AX
0x14001aea6  VXORPS XMM0,XMM0,XMM0
0x14001aeaa  VROUNDSS XMM0,XMM0,dword ptr [R8 + 0x410],0x2
0x14001aeb4  VCVTTSS2SI EAX,XMM0
0x14001aeb8  MOV word ptr [R11 + 0x2a],AX
0x14001aebd  MOVZX EAX,byte ptr [RDX + 0x75]
0x14001aec1  MOV byte ptr [R11 + 0x2d],AL
0x14001aec5  MOVZX EAX,byte ptr [R8 + 0x42b]
0x14001aecd  MOV byte ptr [R11 + 0x2c],AL
0x14001aed1  MOV RAX,qword ptr [R9]
0x14001aed4  MOV RCX,qword ptr [RAX]
0x14001aed7  MOVZX EAX,byte ptr [RCX + 0x15d]
0x14001aede  MOV byte ptr [R11 + 0x2e],AL
0x14001aee2  MOVZX EAX,byte ptr [RDX + 0x6e]
0x14001aee6  MOV byte ptr [R11 + 0x2f],AL
0x14001aeea  MOVZX EAX,byte ptr [RDX + 0x6f]
0x14001aeee  MOV byte ptr [R11 + 0x30],AL
0x14001aef2  MOVZX EAX,byte ptr [RDX + 0x70]
0x14001aef6  MOV byte ptr [R11 + 0x31],AL
0x14001aefa  MOV RAX,qword ptr [R8 + 0x1a0]
0x14001af01  MOV RAX,qword ptr [RAX]
0x14001af04  TEST RAX,RAX
0x14001af07  JZ 0x14001af25
0x14001af09  MOVZX EAX,byte ptr [RAX + 0x71]
0x14001af0d  TEST AL,AL
0x14001af0f  JNZ 0x14001af27
0x14001af11  MOVZX EAX,byte ptr [R8 + 0x42b]
0x14001af19  CMP AL,0x1
0x14001af1b  JNZ 0x14001af1f
0x14001af1d  JMP 0x14001af27
0x14001af1f  CMP AL,0x2
0x14001af21  MOV AL,0x2
0x14001af23  JZ 0x14001af27
0x14001af25  MOV AL,0x3
0x14001af27  MOV byte ptr [R11 + 0x32],AL
0x14001af2b  MOVZX EAX,byte ptr [RDX + 0x72]
0x14001af2f  MOV byte ptr [R11 + 0x33],AL
0x14001af33  MOVZX EAX,byte ptr [RDX + 0x73]
0x14001af37  MOV byte ptr [R11 + 0x34],AL
0x14001af3b  MOVZX EAX,byte ptr [RDX + 0x74]
0x14001af3f  MOV byte ptr [R11 + 0x35],AL
0x14001af43  MOVZX EAX,byte ptr [RDX + 0x77]
0x14001af47  MOV byte ptr [R11 + 0x36],AL
0x14001af4b  MOVZX EAX,byte ptr [RDX + 0x78]
0x14001af4f  MOV byte ptr [R11 + 0x37],AL
0x14001af53  MOVZX EAX,byte ptr [RDX + 0x79]
0x14001af57  MOV byte ptr [R11 + 0x38],AL
0x14001af5b  MOVZX EAX,byte ptr [RDX + 0x7a]
0x14001af5f  MOV byte ptr [R11 + 0x39],AL
0x14001af63  MOVZX EAX,byte ptr [RDX + 0x7b]
0x14001af67  MOV byte ptr [R11 + 0x3a],AL
0x14001af6b  MOVZX EAX,byte ptr [RDX + 0x7f]
0x14001af6f  MOV byte ptr [R11 + 0x3b],AL
0x14001af73  MOVZX EAX,byte ptr [RDX + 0x80]
0x14001af7a  MOV byte ptr [R11 + 0x3c],AL
0x14001af7e  MOV dword ptr [R11 + 0x3d],0xffffffff
0x14001af86  MOV byte ptr [R11 + 0x41],0xff
0x14001af8b  CMP qword ptr [R8 + 0x390],R10
0x14001af92  SETNZ AL
0x14001af95  MOV byte ptr [R11 + 0x42],AL
0x14001af99  MOVZX EAX,byte ptr [RDX + 0x88]
0x14001afa0  MOV byte ptr [R11 + 0x43],AL
0x14001afa4  MOVZX EAX,word ptr [RDX + 0x82]
0x14001afab  MOV word ptr [R11 + 0x44],AX
0x14001afb0  MOVZX EAX,word ptr [RDX + 0x84]
0x14001afb7  MOV word ptr [R11 + 0x46],AX
0x14001afbc  MOV RAX,qword ptr [R8 + 0x3d8]
0x14001afc3  TEST RAX,RAX
0x14001afc6  JZ 0x14001afd2
0x14001afc8  MOV qword ptr [R11 + 0x18],RAX
0x14001afcc  MOV qword ptr [RAX + 0x10],R11
0x14001afd0  JMP 0x14001afd6
0x14001afd2  MOV qword ptr [R11 + 0x18],R10
0x14001afd6  MOV qword ptr [R11 + 0x10],R10
0x14001afda  LEA RCX,[RDI + 0x20]
0x14001afde  MOV qword ptr [R8 + 0x3d8],R11
0x14001afe5  MOV RAX,qword ptr [RCX + 0x8]
0x14001afe9  MOV qword ptr [RAX],R11
0x14001afec  MOV qword ptr [RCX + 0x8],R11
0x14001aff0  MOV qword ptr [R11],RCX
0x14001aff3  MOV qword ptr [R11 + 0x8],RAX
0x14001aff7  INC dword ptr [RCX + 0x70]
0x14001affa  MOV RBX,qword ptr [RSP + 0x8]
0x14001afff  MOV RSI,qword ptr [RSP + 0x10]
0x14001b004  MOV RDI,qword ptr [RSP + 0x18]
0x14001b009  RET
