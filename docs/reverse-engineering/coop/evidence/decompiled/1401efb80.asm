0x1401efb80  MOV qword ptr [RSP + 0x8],RBX
0x1401efb85  MOV qword ptr [RSP + 0x10],RBP
0x1401efb8a  MOV qword ptr [RSP + 0x18],RSI
0x1401efb8f  MOV qword ptr [RSP + 0x20],RDI
0x1401efb94  PUSH R12
0x1401efb96  PUSH R14
0x1401efb98  PUSH R15
0x1401efb9a  SUB RSP,0x30
0x1401efb9e  MOV ESI,dword ptr [R9]
0x1401efba1  LEA RBX,[0x14031dfd0]
0x1401efba8  MOV EBP,dword ptr [R9 + 0x8]
0x1401efbac  MOV EDI,0x10
0x1401efbb1  MOV R14D,dword ptr [R9 + 0x10]
0x1401efbb5  MOV R15D,dword ptr [R9 + 0x18]
0x1401efbb9  MOV R12D,dword ptr [R9 + 0x20]
0x1401efbbd  MOV RCX,qword ptr [RBX]
0x1401efbc0  TEST RCX,RCX
0x1401efbc3  JZ 0x1401efbdd
0x1401efbc5  MOV RAX,qword ptr [RCX]
0x1401efbc8  MOV R9D,R14D
0x1401efbcb  MOV dword ptr [RSP + 0x28],R12D
0x1401efbd0  MOV R8D,EBP
0x1401efbd3  MOV EDX,ESI
0x1401efbd5  MOV dword ptr [RSP + 0x20],R15D
0x1401efbda  CALL qword ptr [RAX + 0x20]
0x1401efbdd  ADD RBX,0x8
0x1401efbe1  SUB RDI,0x1
0x1401efbe5  JNZ 0x1401efbbd
0x1401efbe7  MOV RCX,qword ptr [0x14031dfc8]
0x1401efbee  TEST RCX,RCX
0x1401efbf1  JZ 0x1401efc0b
0x1401efbf3  MOV RAX,qword ptr [RCX]
0x1401efbf6  MOV R9D,R14D
0x1401efbf9  MOV dword ptr [RSP + 0x28],R12D
0x1401efbfe  MOV R8D,EBP
0x1401efc01  MOV EDX,ESI
0x1401efc03  MOV dword ptr [RSP + 0x20],R15D
0x1401efc08  CALL qword ptr [RAX + 0x20]
0x1401efc0b  MOV RBX,qword ptr [RSP + 0x50]
0x1401efc10  MOV RBP,qword ptr [RSP + 0x58]
0x1401efc15  MOV RSI,qword ptr [RSP + 0x60]
0x1401efc1a  MOV RDI,qword ptr [RSP + 0x68]
0x1401efc1f  ADD RSP,0x30
0x1401efc23  POP R15
0x1401efc25  POP R14
0x1401efc27  POP R12
0x1401efc29  RET
