0x1401b7ce0  PUSH R13
0x1401b7ce2  PUSH R15
0x1401b7ce4  SUB RSP,0x48
0x1401b7ce8  MOV qword ptr [RSP + 0x70],RBP
0x1401b7ced  MOV RBP,RCX
0x1401b7cf0  MOV qword ptr [RSP + 0x38],R12
0x1401b7cf5  CALL 0x140019ef0
0x1401b7cfa  MOV R15,RAX
0x1401b7cfd  MOV RAX,qword ptr [RBP + 0x697b8]
0x1401b7d04  MOV RCX,R15
0x1401b7d07  MOV RDX,qword ptr [RAX]
0x1401b7d0a  MOV R12,qword ptr [RDX + 0x110]
0x1401b7d11  LEA RDX,[RBP + 0xa87e5]
0x1401b7d18  ADD R12,0x258
0x1401b7d1f  SUB RCX,RDX
0x1401b7d22  MOVZX EAX,byte ptr [RDX]
0x1401b7d25  MOV byte ptr [RCX + RDX*0x1 + 0x328],AL
0x1401b7d2c  LEA RDX,[RDX + 0x1]
0x1401b7d30  TEST AL,AL
0x1401b7d32  JNZ 0x1401b7d22
0x1401b7d34  MOVZX EAX,byte ptr [RBP + 0xa8794]
0x1401b7d3b  MOV dword ptr [R15 + 0x14],EAX
0x1401b7d3f  MOVZX EAX,word ptr [RBP + 0x69818]
0x1401b7d46  MOV word ptr [R15 + 0x10],AX
0x1401b7d4b  MOVZX EAX,byte ptr [RBP + 0x697ec]
0x1401b7d52  MOV word ptr [R15 + 0x12],AX
0x1401b7d57  CALL 0x140019ef0
0x1401b7d5c  XOR R13D,R13D
0x1401b7d5f  CMP dword ptr [RAX],0x2
0x1401b7d62  JL 0x1401b7f4b
0x1401b7d68  TEST dword ptr [RBP + 0xa8790],0x1000000
0x1401b7d72  MOV qword ptr [RSP + 0x68],RBX
0x1401b7d77  MOV RBX,qword ptr [RBP + 0x697b8]
0x1401b7d7e  MOV qword ptr [RSP + 0x60],RBX
0x1401b7d83  JZ 0x1401b7e10
0x1401b7d89  MOV RAX,qword ptr [RBX]
0x1401b7d8c  LEA R9,[RSP + 0x60]
0x1401b7d91  MOV EDX,dword ptr [R15]
0x1401b7d94  MOV RCX,R15
0x1401b7d97  MOV qword ptr [RSP + 0x20],R12
0x1401b7d9c  MOV RBX,qword ptr [RAX + 0x110]
0x1401b7da3  MOV R8,RBX
0x1401b7da6  CALL 0x14001a2a0
0x1401b7dab  MOV EAX,dword ptr [RBX + 0x258]
0x1401b7db1  MOV dword ptr [RBX + 0x288],EAX
0x1401b7db7  MOV EAX,dword ptr [RBX + 0x25c]
0x1401b7dbd  MOV dword ptr [RBX + 0x28c],EAX
0x1401b7dc3  MOV EAX,dword ptr [RBX + 0x260]
0x1401b7dc9  MOV dword ptr [RBX + 0x290],EAX
0x1401b7dcf  MOV EAX,dword ptr [RBX + 0x264]
0x1401b7dd5  MOV dword ptr [RBX + 0x294],EAX
0x1401b7ddb  MOV EAX,dword ptr [RBX + 0x268]
0x1401b7de1  MOV dword ptr [RBX + 0x298],EAX
0x1401b7de7  MOV EAX,dword ptr [RBX + 0x26c]
0x1401b7ded  MOV dword ptr [RBX + 0x29c],EAX
0x1401b7df3  MOV EAX,dword ptr [RBX + 0x270]
0x1401b7df9  MOV dword ptr [RBX + 0x2a0],EAX
0x1401b7dff  MOV EAX,dword ptr [RBX + 0x274]
0x1401b7e05  MOV dword ptr [RBX + 0x2a4],EAX
0x1401b7e0b  JMP 0x1401b7f04
0x1401b7e10  MOV qword ptr [RSP + 0x30],R14
0x1401b7e15  MOV R14D,R13D
0x1401b7e18  CMP byte ptr [RBP + 0x697ec],R13B
0x1401b7e1f  JBE 0x1401b7eff
0x1401b7e25  MOV qword ptr [RSP + 0x78],RSI
0x1401b7e2a  MOV qword ptr [RSP + 0x40],RDI
0x1401b7e2f  MOV RAX,qword ptr [RBX]
0x1401b7e32  MOV ESI,R13D
0x1401b7e35  MOV RDI,qword ptr [RAX + 0x110]
0x1401b7e3c  CMP dword ptr [RAX + 0x118],R13D
0x1401b7e43  JLE 0x1401b7ed9
0x1401b7e49  MOV EDX,dword ptr [R15]
0x1401b7e4c  LEA R9,[RSP + 0x60]
0x1401b7e51  MOV R8,RDI
0x1401b7e54  MOV qword ptr [RSP + 0x20],R12
0x1401b7e59  MOV RCX,R15
0x1401b7e5c  CALL 0x14001a2a0
0x1401b7e61  MOV EAX,dword ptr [RDI + 0x258]
0x1401b7e67  INC ESI
0x1401b7e69  MOV dword ptr [RDI + 0x288],EAX
0x1401b7e6f  MOV EAX,dword ptr [RDI + 0x25c]
0x1401b7e75  MOV dword ptr [RDI + 0x28c],EAX
0x1401b7e7b  MOV EAX,dword ptr [RDI + 0x260]
0x1401b7e81  MOV dword ptr [RDI + 0x290],EAX
0x1401b7e87  MOV EAX,dword ptr [RDI + 0x264]
0x1401b7e8d  MOV dword ptr [RDI + 0x294],EAX
0x1401b7e93  MOV EAX,dword ptr [RDI + 0x268]
0x1401b7e99  MOV dword ptr [RDI + 0x298],EAX
0x1401b7e9f  MOV EAX,dword ptr [RDI + 0x26c]
0x1401b7ea5  MOV dword ptr [RDI + 0x29c],EAX
0x1401b7eab  MOV EAX,dword ptr [RDI + 0x270]
0x1401b7eb1  MOV dword ptr [RDI + 0x2a0],EAX
0x1401b7eb7  MOV EAX,dword ptr [RDI + 0x274]
0x1401b7ebd  MOV dword ptr [RDI + 0x2a4],EAX
0x1401b7ec3  ADD RDI,0x520
0x1401b7eca  MOV RAX,qword ptr [RBX]
0x1401b7ecd  CMP ESI,dword ptr [RAX + 0x118]
0x1401b7ed3  JL 0x1401b7e49
0x1401b7ed9  MOVZX EAX,byte ptr [RBP + 0x697ec]
0x1401b7ee0  ADD RBX,0x8
0x1401b7ee4  INC R14D
0x1401b7ee7  MOV qword ptr [RSP + 0x60],RBX
0x1401b7eec  CMP R14D,EAX
0x1401b7eef  JL 0x1401b7e2f
0x1401b7ef5  MOV RDI,qword ptr [RSP + 0x40]
0x1401b7efa  MOV RSI,qword ptr [RSP + 0x78]
0x1401b7eff  MOV R14,qword ptr [RSP + 0x30]
0x1401b7f04  MOV RBX,qword ptr [RSP + 0x68]
0x1401b7f09  MOV RAX,qword ptr GS:[0x58]
0x1401b7f12  MOV R12,qword ptr [RSP + 0x38]
0x1401b7f17  MOV RBP,qword ptr [RSP + 0x70]
0x1401b7f1c  MOV ECX,0x4
0x1401b7f21  MOV RAX,qword ptr [RAX]
0x1401b7f24  MOV EAX,dword ptr [RCX + RAX*0x1]
0x1401b7f27  CMP dword ptr [0x1437d9f84],EAX
0x1401b7f2d  JG 0x1401b7fd5
0x1401b7f33  LEA RCX,[0x14031e980]
0x1401b7f3a  CALL 0x14001a0c0
0x1401b7f3f  INC dword ptr [R15]
0x1401b7f42  ADD RSP,0x48
0x1401b7f46  POP R15
0x1401b7f48  POP R13
0x1401b7f4a  RET
0x1401b7f4b  MOV R10D,R13D
0x1401b7f4e  MOV RAX,qword ptr [RBP + 0x697b8]
0x1401b7f55  CMP byte ptr [RBP + 0x697ec],R13B
0x1401b7f5c  JBE 0x1401b7f09
0x1401b7f5e  MOV R9,qword ptr [RAX]
0x1401b7f61  MOV R8D,R13D
0x1401b7f64  MOV RDX,qword ptr [R9 + 0x110]
0x1401b7f6b  CMP dword ptr [R9 + 0x118],R13D
0x1401b7f72  JLE 0x1401b7fbd
0x1401b7f74  ADD RDX,0x288
0x1401b7f7b  MOV ECX,dword ptr [RDX + -0x30]
0x1401b7f7e  INC R8D
0x1401b7f81  MOV dword ptr [RDX],ECX
0x1401b7f83  MOV ECX,dword ptr [RDX + -0x2c]
0x1401b7f86  MOV dword ptr [RDX + 0x4],ECX
0x1401b7f89  MOV ECX,dword ptr [RDX + -0x28]
0x1401b7f8c  MOV dword ptr [RDX + 0x8],ECX
0x1401b7f8f  MOV ECX,dword ptr [RDX + -0x24]
0x1401b7f92  MOV dword ptr [RDX + 0xc],ECX
0x1401b7f95  MOV ECX,dword ptr [RDX + -0x20]
0x1401b7f98  MOV dword ptr [RDX + 0x10],ECX
0x1401b7f9b  MOV ECX,dword ptr [RDX + -0x1c]
0x1401b7f9e  MOV dword ptr [RDX + 0x14],ECX
0x1401b7fa1  MOV ECX,dword ptr [RDX + -0x18]
0x1401b7fa4  MOV dword ptr [RDX + 0x18],ECX
0x1401b7fa7  MOV ECX,dword ptr [RDX + -0x14]
0x1401b7faa  MOV dword ptr [RDX + 0x1c],ECX
0x1401b7fad  LEA RDX,[RDX + 0x520]
0x1401b7fb4  CMP R8D,dword ptr [R9 + 0x118]
0x1401b7fbb  JL 0x1401b7f7b
0x1401b7fbd  MOVZX ECX,byte ptr [RBP + 0x697ec]
0x1401b7fc4  INC R10D
0x1401b7fc7  ADD RAX,0x8
0x1401b7fcb  CMP R10D,ECX
0x1401b7fce  JL 0x1401b7f5e
0x1401b7fd0  JMP 0x1401b7f09
0x1401b7fd5  LEA RCX,[0x1437d9f84]
0x1401b7fdc  CALL 0x14022d540
0x1401b7fe1  CMP dword ptr [0x1437d9f84],-0x1
0x1401b7fe8  JNZ 0x1401b7f33
0x1401b7fee  LEA RAX,[0x14031e9a0]
0x1401b7ff5  MOV qword ptr [0x14031e9b0],R13
0x1401b7ffc  MOV qword ptr [0x14031e9a0],RAX
0x1401b8003  LEA RCX,[0x14031e980]
0x1401b800a  MOV qword ptr [0x14031e9a8],RAX
0x1401b8011  LEA RAX,[0x14031ea18]
0x1401b8018  MOV qword ptr [0x14031ea18],RAX
0x1401b801f  MOV qword ptr [0x14031ea20],RAX
0x1401b8026  LEA RAX,[0x14031eb20]
0x1401b802d  MOV qword ptr [0x14031eb20],RAX
0x1401b8034  MOV qword ptr [0x14031eb28],RAX
0x1401b803b  LEA RAX,[0x14031eb98]
0x1401b8042  MOV qword ptr [0x14031eb98],RAX
0x1401b8049  MOV qword ptr [0x14031eba0],RAX
0x1401b8050  LEA RAX,[0x14031ec10]
0x1401b8057  VPXOR XMM0,XMM0,XMM0
0x1401b805b  MOV qword ptr [0x14031ec10],RAX
0x1401b8062  MOV qword ptr [0x14031ec18],RAX
0x1401b8069  MOV qword ptr [0x14031e9b8],R13
0x1401b8070  MOV dword ptr [0x14031ea06],0xffff
0x1401b807a  MOV dword ptr [0x14031ea10],R13D
0x1401b8081  MOV qword ptr [0x14031ea28],R13
0x1401b8088  MOV qword ptr [0x14031ea30],R13
0x1401b808f  MOV dword ptr [0x14031ea7e],0xffff
0x1401b8099  MOV dword ptr [0x14031ea88],R13D
0x1401b80a0  MOV qword ptr [0x14031eb30],R13
0x1401b80a7  MOV qword ptr [0x14031eb38],R13
0x1401b80ae  MOV dword ptr [0x14031eb86],0xffff
0x1401b80b8  MOV dword ptr [0x14031eb90],R13D
0x1401b80bf  MOV qword ptr [0x14031eba8],R13
0x1401b80c6  MOV qword ptr [0x14031ebb0],R13
0x1401b80cd  MOV dword ptr [0x14031ebfe],0xffff
0x1401b80d7  MOV dword ptr [0x14031ec08],R13D
0x1401b80de  VMOVDQU xmmword ptr [0x14031ec20],XMM0
0x1401b80e6  MOV dword ptr [0x14031ec76],0xffff
0x1401b80f0  MOV dword ptr [0x14031ec80],R13D
0x1401b80f7  MOV qword ptr [0x14031eda8],R13
0x1401b80fe  MOV byte ptr [0x14031eca8],R13B
0x1401b8105  MOV dword ptr [0x14031eb18],R13D
0x1401b810c  MOV dword ptr [0x14031ec88],R13D
0x1401b8113  CALL 0x140019f80
0x1401b8118  LEA RCX,[0x1437d9f84]
0x1401b811f  CALL 0x14022d4d4
0x1401b8124  JMP 0x1401b7f33
