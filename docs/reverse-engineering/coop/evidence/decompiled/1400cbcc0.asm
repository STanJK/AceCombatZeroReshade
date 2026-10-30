0x1400cbcc0  MOV qword ptr [RSP + 0x10],RBX
0x1400cbcc5  MOV qword ptr [RSP + 0x18],RBP
0x1400cbcca  MOV qword ptr [RSP + 0x20],RSI
0x1400cbccf  PUSH RDI
0x1400cbcd0  PUSH R12
0x1400cbcd2  PUSH R13
0x1400cbcd4  PUSH R14
0x1400cbcd6  PUSH R15
0x1400cbcd8  SUB RSP,0x40
0x1400cbcdc  CMP byte ptr [RCX + 0xa8827],0x0
0x1400cbce3  MOV RBP,RCX
0x1400cbce6  JZ 0x1400cbcef
0x1400cbce8  MOV byte ptr [RCX + 0xa881d],0x2
0x1400cbcef  MOV RBX,qword ptr [RCX + 0x67130]
0x1400cbcf6  CMP qword ptr [RBX + 0x1378],0x0
0x1400cbcfe  JZ 0x1400cbd27
0x1400cbd00  MOV RCX,RBX
0x1400cbd03  CALL 0x140078ed0
0x1400cbd08  MOV RCX,qword ptr [0x14032c8f8]
0x1400cbd0f  MOV R8D,0x10
0x1400cbd15  MOV EDX,EAX
0x1400cbd17  CALL 0x140200de0
0x1400cbd1c  MOV RDX,RAX
0x1400cbd1f  MOV RCX,RBX
0x1400cbd22  CALL 0x140078fb0
0x1400cbd27  MOV RBX,qword ptr [RBP + 0x67148]
0x1400cbd2e  CMP dword ptr [RBX + 0x38],0x0
0x1400cbd32  JZ 0x1400cbd5b
0x1400cbd34  MOV RCX,RBX
0x1400cbd37  CALL 0x14007e230
0x1400cbd3c  MOV RCX,qword ptr [0x14032c8f8]
0x1400cbd43  MOV R8D,0x10
0x1400cbd49  MOV EDX,EAX
0x1400cbd4b  CALL 0x140200de0
0x1400cbd50  MOV RDX,RAX
0x1400cbd53  MOV RCX,RBX
0x1400cbd56  CALL 0x14007e480
0x1400cbd5b  MOV RCX,qword ptr [RBP + 0x67148]
0x1400cbd62  CALL 0x14007ef20
0x1400cbd67  CMP byte ptr [RBP + 0xa8828],0x2
0x1400cbd6e  JNZ 0x1400cbe06
0x1400cbd74  MOV RBX,qword ptr [RBP + 0x67130]
0x1400cbd7b  CMP qword ptr [RBX + 0x2700],0x0
0x1400cbd83  JZ 0x1400cbdb4
0x1400cbd85  LEA RCX,[RBX + 0x1388]
0x1400cbd8c  CALL 0x140078ed0
0x1400cbd91  MOV RCX,qword ptr [0x14032c8f8]
0x1400cbd98  MOV R8D,0x10
0x1400cbd9e  MOV EDX,EAX
0x1400cbda0  CALL 0x140200de0
0x1400cbda5  MOV RDX,RAX
0x1400cbda8  LEA RCX,[RBX + 0x1388]
0x1400cbdaf  CALL 0x140078fb0
0x1400cbdb4  MOV RBX,qword ptr [RBP + 0x67148]
0x1400cbdbb  CMP dword ptr [RBX + 0x178],0x0
0x1400cbdc2  JZ 0x1400cbdf3
0x1400cbdc4  LEA RCX,[RBX + 0x140]
0x1400cbdcb  CALL 0x14007e230
0x1400cbdd0  MOV RCX,qword ptr [0x14032c8f8]
0x1400cbdd7  MOV R8D,0x10
0x1400cbddd  MOV EDX,EAX
0x1400cbddf  CALL 0x140200de0
0x1400cbde4  MOV RDX,RAX
0x1400cbde7  LEA RCX,[RBX + 0x140]
0x1400cbdee  CALL 0x14007e480
0x1400cbdf3  MOV RCX,qword ptr [RBP + 0x67148]
0x1400cbdfa  ADD RCX,0x140
0x1400cbe01  CALL 0x14007ef20
0x1400cbe06  LEA R15,[RBP + 0x6a130]
0x1400cbe0d  LEA R12,[RBP + 0x240]
0x1400cbe14  LEA RCX,[R15 + 0x1b10]
0x1400cbe1b  MOV qword ptr [R15 + 0xca0],R12
0x1400cbe22  MOV RDX,R12
0x1400cbe25  MOV qword ptr [R15],R12
0x1400cbe28  CALL 0x1400c2980
0x1400cbe2d  LEA RSI,[RBP + 0x697b8]
0x1400cbe34  MOV RDX,RSI
0x1400cbe37  MOV qword ptr [RBP + 0x6add8],RSI
0x1400cbe3e  MOV qword ptr [RBP + 0x6a138],RSI
0x1400cbe45  CALL 0x1400c2b90
0x1400cbe4a  MOV RDX,qword ptr [RBP + 0x67170]
0x1400cbe51  MOV qword ptr [RBP + 0x6ade0],RDX
0x1400cbe58  MOV qword ptr [RBP + 0x6a140],RDX
0x1400cbe5f  CALL 0x1400c2da0
0x1400cbe64  MOV RDX,qword ptr [RBP + 0xa82a8]
0x1400cbe6b  CALL 0x1400c2fb0
0x1400cbe70  MOV RDX,qword ptr [RBP + 0xa8318]
0x1400cbe77  CALL 0x1400c31c0
0x1400cbe7c  MOVZX EDX,byte ptr [RBP + 0xa8825]
0x1400cbe83  MOV byte ptr [RBP + 0x6adf8],DL
0x1400cbe89  MOV byte ptr [RBP + 0x6a158],DL
0x1400cbe8f  CALL 0x1400c33d0
0x1400cbe94  XOR EDI,EDI
0x1400cbe96  MOV dword ptr [RBP + 0xa8194],0x1
0x1400cbea0  LEA R13,[RBP + 0xa8328]
0x1400cbea7  MOV dword ptr [RBP + 0xa8160],EDI
0x1400cbead  LEA R14,[RBP + 0x69748]
0x1400cbeb4  MOV qword ptr [RBP + 0xa8174],RDI
0x1400cbebb  MOV RCX,R13
0x1400cbebe  MOV qword ptr [RBP + 0x80108],R14
0x1400cbec5  MOV qword ptr [RBP + 0xa817c],RDI
0x1400cbecc  MOV qword ptr [RBP + 0xa8184],RDI
0x1400cbed3  MOV qword ptr [RBP + 0xa818c],RDI
0x1400cbeda  CALL 0x1400bd780
0x1400cbedf  MOV RBX,qword ptr [0x14032c8f8]
0x1400cbee6  MOV EDX,0x2b0
0x1400cbeeb  MOV RCX,RBX
0x1400cbeee  MOV qword ptr [0x140328418],R13
0x1400cbef5  MOV R8D,0x10
0x1400cbefb  CALL 0x140200de0
0x1400cbf00  LEA RCX,[0x1402ac520]
0x1400cbf07  MOV EDX,0x270
0x1400cbf0c  MOV R8D,0x10
0x1400cbf12  MOV qword ptr [RAX],RCX
0x1400cbf15  MOV RCX,RBX
0x1400cbf18  MOV word ptr [RAX + 0x8],0x1
0x1400cbf1e  MOV byte ptr [RAX + 0xa],DIL
0x1400cbf22  MOV qword ptr [RAX + 0x48],RDI
0x1400cbf26  MOV dword ptr [RAX + 0x50],0x1
0x1400cbf2d  MOV qword ptr [RAX + 0x54],-0x1
0x1400cbf35  MOV qword ptr [RAX + 0x25c],RDI
0x1400cbf3c  MOV byte ptr [RAX + 0x264],DIL
0x1400cbf43  MOV qword ptr [RAX + 0x268],RDI
0x1400cbf4a  MOV qword ptr [RAX + 0x270],RDI
0x1400cbf51  MOV qword ptr [RAX + 0x278],RDI
0x1400cbf58  MOV qword ptr [RAX + 0x280],RDI
0x1400cbf5f  MOV qword ptr [RAX + 0x288],RDI
0x1400cbf66  MOV qword ptr [RAX + 0x290],RDI
0x1400cbf6d  MOV qword ptr [RAX + 0x298],RDI
0x1400cbf74  MOV qword ptr [RAX + 0x2a0],RDI
0x1400cbf7b  MOV qword ptr [RAX + 0x2a8],RDI
0x1400cbf82  MOV qword ptr [RBP + 0x67158],RAX
0x1400cbf89  CALL 0x140200de0
0x1400cbf8e  LEA RCX,[0x1402ac4a8]
0x1400cbf95  MOV EDX,0x338
0x1400cbf9a  MOV R8D,0x10
0x1400cbfa0  MOV qword ptr [RAX],RCX
0x1400cbfa3  MOV RCX,RBX
0x1400cbfa6  MOV word ptr [RAX + 0x8],0x1
0x1400cbfac  MOV byte ptr [RAX + 0xa],DIL
0x1400cbfb0  MOV qword ptr [RAX + 0x48],RDI
0x1400cbfb4  MOV dword ptr [RAX + 0x50],0x1
0x1400cbfbb  MOV qword ptr [RAX + 0x54],-0x1
0x1400cbfc3  MOV qword ptr [RAX + 0x25c],RDI
0x1400cbfca  MOV byte ptr [RAX + 0x264],DIL
0x1400cbfd1  MOV qword ptr [RAX + 0x268],0x10
0x1400cbfdc  MOV qword ptr [RBP + 0x67150],RAX
0x1400cbfe3  CALL 0x140200de0
0x1400cbfe8  MOV word ptr [RAX + 0x8],0x1
0x1400cbfee  LEA RCX,[0x1402ac620]
0x1400cbff5  MOV byte ptr [RAX + 0xa],DIL
0x1400cbff9  MOV qword ptr [RAX],RCX
0x1400cbffc  MOV EDX,0x270
0x1400cc001  MOV qword ptr [RAX + 0x48],RDI
0x1400cc005  MOV RCX,RBX
0x1400cc008  MOV dword ptr [RAX + 0x50],0x1
0x1400cc00f  MOV R8D,0x10
0x1400cc015  MOV qword ptr [RAX + 0x54],-0x1
0x1400cc01d  MOV qword ptr [RAX + 0x25c],RDI
0x1400cc024  MOV byte ptr [RAX + 0x264],DIL
0x1400cc02b  MOV qword ptr [RAX + 0x270],RDI
0x1400cc032  MOV qword ptr [RAX + 0x278],RDI
0x1400cc039  MOV qword ptr [RAX + 0x280],RDI
0x1400cc040  MOV qword ptr [RAX + 0x268],RDI
0x1400cc047  MOV qword ptr [RAX + 0x288],RDI
0x1400cc04e  MOV qword ptr [RAX + 0x290],RDI
0x1400cc055  MOV qword ptr [RAX + 0x298],RDI
0x1400cc05c  MOV dword ptr [RAX + 0x2a0],0x1
0x1400cc066  MOV byte ptr [RAX + 0x2a4],0x1
0x1400cc06d  MOV dword ptr [RAX + 0x2a8],EDI
0x1400cc073  MOV qword ptr [RAX + 0x2b8],RDI
0x1400cc07a  MOV qword ptr [RAX + 0x2c0],RDI
0x1400cc081  MOV qword ptr [RAX + 0x2c8],RDI
0x1400cc088  MOV qword ptr [RAX + 0x2b0],RDI
0x1400cc08f  MOV qword ptr [RAX + 0x2d0],RDI
0x1400cc096  MOV qword ptr [RAX + 0x2d8],RDI
0x1400cc09d  MOV qword ptr [RAX + 0x2e0],RDI
0x1400cc0a4  MOV dword ptr [RAX + 0x2e8],0x1
0x1400cc0ae  MOV byte ptr [RAX + 0x2ec],0x1
0x1400cc0b5  MOV dword ptr [RAX + 0x2f0],EDI
0x1400cc0bb  MOV qword ptr [RAX + 0x2f8],RDI
0x1400cc0c2  MOV qword ptr [RAX + 0x300],RDI
0x1400cc0c9  MOV qword ptr [RAX + 0x308],RDI
0x1400cc0d0  MOV qword ptr [RAX + 0x310],RDI
0x1400cc0d7  MOV qword ptr [RAX + 0x318],RDI
0x1400cc0de  MOV qword ptr [RAX + 0x320],RDI
0x1400cc0e5  MOV qword ptr [RAX + 0x328],RDI
0x1400cc0ec  MOV dword ptr [RAX + 0x333],0x1
0x1400cc0f6  MOV qword ptr [RBP + 0x67160],RAX
0x1400cc0fd  CALL 0x140200de0
0x1400cc102  MOV EDX,0x1
0x1400cc107  LEA RCX,[0x1402ac5a0]
0x1400cc10e  MOV word ptr [RAX + 0x8],0x1
0x1400cc114  MOV byte ptr [RAX + 0xa],DIL
0x1400cc118  MOV qword ptr [RAX + 0x48],RDI
0x1400cc11c  MOV dword ptr [RAX + 0x50],EDX
0x1400cc11f  MOV qword ptr [RAX + 0x54],-0x1
0x1400cc127  MOV qword ptr [RAX + 0x25c],RDI
0x1400cc12e  MOV byte ptr [RAX + 0x264],DIL
0x1400cc135  MOV qword ptr [RAX],RCX
0x1400cc138  MOV dword ptr [RAX + 0x268],0x10
0x1400cc142  MOV dword ptr [RAX + 0x26c],EDX
0x1400cc148  MOV RCX,qword ptr [RBP + 0x67150]
0x1400cc14f  MOV qword ptr [RBP + 0x67168],RAX
0x1400cc156  MOV RAX,qword ptr [RCX]
0x1400cc159  CALL qword ptr [RAX + 0x8]
0x1400cc15c  MOV RDI,qword ptr [RBP + 0x67150]
0x1400cc163  MOV RAX,qword ptr [RDI]
0x1400cc166  MOV RBX,qword ptr [RAX + 0x18]
0x1400cc16a  CALL 0x140189320
0x1400cc16f  MOV RCX,RDI
0x1400cc172  CMP byte ptr [RAX + 0x28],0x0
0x1400cc176  SETNZ DL
0x1400cc179  CALL RBX
0x1400cc17b  MOV RAX,qword ptr [RBP + 0x67150]
0x1400cc182  OR dword ptr [RAX + 0x50],0x1
0x1400cc186  MOV RCX,qword ptr [RBP + 0x67168]
0x1400cc18d  MOV RAX,qword ptr [RCX]
0x1400cc190  CALL qword ptr [RAX + 0x8]
0x1400cc193  MOV RDI,qword ptr [RBP + 0x67168]
0x1400cc19a  MOV RAX,qword ptr [RDI]
0x1400cc19d  MOV RBX,qword ptr [RAX + 0x18]
0x1400cc1a1  CALL 0x140189320
0x1400cc1a6  MOV RCX,RDI
0x1400cc1a9  CMP byte ptr [RAX + 0x28],0x0
0x1400cc1ad  SETNZ DL
0x1400cc1b0  CALL RBX
0x1400cc1b2  MOV RAX,qword ptr [RBP + 0x67168]
0x1400cc1b9  OR dword ptr [RAX + 0x50],0x1
0x1400cc1bd  MOV RAX,qword ptr [RBP + 0x67168]
0x1400cc1c4  OR dword ptr [RAX + 0x50],0x2
0x1400cc1c8  MOV EDX,0x2
0x1400cc1cd  MOV RCX,qword ptr [RBP + 0x67158]
0x1400cc1d4  MOV RAX,qword ptr [RBP + 0xa82c8]
0x1400cc1db  MOV qword ptr [RCX + 0x278],RAX
0x1400cc1e2  MOV RCX,qword ptr [RBP + 0x67158]
0x1400cc1e9  MOV RAX,qword ptr [RBP + 0xa82e0]
0x1400cc1f0  MOV qword ptr [RCX + 0x280],RAX
0x1400cc1f7  CMP byte ptr [RBP + 0xa87e4],0x1
0x1400cc1fe  MOV RCX,qword ptr [RBP + 0x67158]
0x1400cc205  MOV RAX,qword ptr [RCX]
0x1400cc208  JBE 0x1400cc214
0x1400cc20a  MOV R8D,EDX
0x1400cc20d  MOV DL,0x1
0x1400cc20f  CALL qword ptr [RAX + 0x58]
0x1400cc212  JMP 0x1400cc231
0x1400cc214  MOV R9,qword ptr [RAX + 0x58]
0x1400cc218  XOR EDX,EDX
0x1400cc21a  CMP byte ptr [RBP + 0xa8794],0x13
0x1400cc221  JNZ 0x1400cc22b
0x1400cc223  MOV R8D,0x1
0x1400cc229  JMP 0x1400cc22e
0x1400cc22b  XOR R8D,R8D
0x1400cc22e  CALL R9
0x1400cc231  MOV RDI,qword ptr [RBP + 0x67158]
0x1400cc238  MOV RAX,qword ptr [RDI]
0x1400cc23b  MOV RBX,qword ptr [RAX + 0x18]
0x1400cc23f  CALL 0x140189320
0x1400cc244  MOV RCX,RDI
0x1400cc247  CMP byte ptr [RAX + 0x28],0x0
0x1400cc24b  SETNZ DL
0x1400cc24e  CALL RBX
0x1400cc250  MOV RCX,qword ptr [RBP + 0x67160]
0x1400cc257  MOV RAX,qword ptr [RBP + 0xa82d0]
0x1400cc25e  MOV qword ptr [RCX + 0x2f8],RAX
0x1400cc265  MOV RCX,qword ptr [RBP + 0x67160]
0x1400cc26c  MOV RAX,qword ptr [RBP + 0xa82d8]
0x1400cc273  MOV qword ptr [RCX + 0x300],RAX
0x1400cc27a  MOV RDX,qword ptr [RBP + 0xa8248]
0x1400cc281  MOV RCX,qword ptr [RBP + 0x67160]
0x1400cc288  MOV RDX,qword ptr [RDX + 0x1fd8]
0x1400cc28f  CALL 0x1400c5d40
0x1400cc294  CMP dword ptr [RBP + 0xa82f0],0x0
0x1400cc29b  JZ 0x1400cc2b6
0x1400cc29d  MOV RDX,qword ptr [RBP + 0xa82f8]
0x1400cc2a4  MOV RCX,qword ptr [RBP + 0x67160]
0x1400cc2ab  MOV RDX,qword ptr [RDX + 0x40]
0x1400cc2af  CALL 0x1400c5e80
0x1400cc2b4  JMP 0x1400cc2c4
0x1400cc2b6  MOV RAX,qword ptr [RBP + 0x67160]
0x1400cc2bd  MOV byte ptr [RAX + 0x333],0x0
0x1400cc2c4  MOV RCX,qword ptr [RBP + 0x67160]
0x1400cc2cb  MOV RAX,qword ptr [RCX]
0x1400cc2ce  CALL qword ptr [RAX + 0x8]
0x1400cc2d1  MOV RDI,qword ptr [RBP + 0x67160]
0x1400cc2d8  MOV RAX,qword ptr [RDI]
0x1400cc2db  MOV RBX,qword ptr [RAX + 0x18]
0x1400cc2df  CALL 0x140189320
0x1400cc2e4  MOV RCX,RDI
0x1400cc2e7  CMP byte ptr [RAX + 0x28],0x0
0x1400cc2eb  SETNZ DL
0x1400cc2ee  CALL RBX
0x1400cc2f0  MOV RAX,qword ptr [RBP + 0x67160]
0x1400cc2f7  MOV dword ptr [RSP + 0x70],0x0
0x1400cc2ff  OR dword ptr [RAX + 0x50],0x1
0x1400cc303  MOV qword ptr [RBP + 0x671d8],R13
0x1400cc30a  MOV EAX,dword ptr [RBP + 0xa8614]
0x1400cc310  MOV dword ptr [RBP + 0x671d0],EAX
0x1400cc316  MOVZX EAX,byte ptr [RBP + 0xa8825]
0x1400cc31d  MOV byte ptr [RBP + 0x671e6],AL
0x1400cc323  MOVZX EDX,byte ptr [RBP + 0xa87e4]
0x1400cc32a  TEST DL,DL
0x1400cc32c  JZ 0x1400cc88b
0x1400cc332  MOV R15D,dword ptr [RSP + 0x70]
0x1400cc337  LEA R14,[RBP + 0x69798]
0x1400cc33e  MOVSXD RDI,R15D
0x1400cc341  MOV R8D,R15D
0x1400cc344  IMUL RSI,RDI,0x27a0
0x1400cc34b  ADD RSI,qword ptr [RBP + 0xa8248]
0x1400cc352  CMP DL,0x1
0x1400cc355  SETA DL
0x1400cc358  LEA RCX,[RSI + 0x1868]
0x1400cc35f  MOV byte ptr [RSI + 0x20c8],DL
0x1400cc365  CALL 0x1400ade70
0x1400cc36a  MOV RAX,qword ptr [RSI + 0xff8]
0x1400cc371  MOV R8,qword ptr [RSI + 0x1fe0]
0x1400cc378  MOV RDX,qword ptr [RSI + 0x1fe8]
0x1400cc37f  MOVZX ECX,byte ptr [RAX + 0xd]
0x1400cc383  MOV byte ptr [RSI + 0x1c1d],CL
0x1400cc389  MOV RCX,qword ptr [RSI + 0x1890]
0x1400cc390  CALL 0x1400ad7a0
0x1400cc395  MOV R8,qword ptr [RSI + 0x1ff0]
0x1400cc39c  MOV RDX,qword ptr [RSI + 0x1ff8]
0x1400cc3a3  MOV RCX,qword ptr [RSI + 0x1890]
0x1400cc3aa  CALL 0x1400ad900
0x1400cc3af  MOVZX EDX,byte ptr [RSI + 0x279a]
0x1400cc3b6  MOV RCX,qword ptr [RSI + 0x1890]
0x1400cc3bd  MOV R8,qword ptr [RSI + RDX*0x8 + 0x2000]
0x1400cc3c5  MOV RDX,qword ptr [RSI + RDX*0x8 + 0x2018]
0x1400cc3cd  CALL 0x1400adac0
0x1400cc3d2  MOV word ptr [RSI + 0xae2],R15W
0x1400cc3da  LEA RAX,[RBP + 0x697b8]
0x1400cc3e1  MOV qword ptr [RSI + 0x1840],RAX
0x1400cc3e8  MOV qword ptr [RSI + 0x1d50],RAX
0x1400cc3ef  MOV qword ptr [RSI + 0x1ed0],RAX
0x1400cc3f6  MOV qword ptr [RSI + 0x1eb8],RAX
0x1400cc3fd  MOV qword ptr [RSI + 0x2040],RAX
0x1400cc404  MOV qword ptr [RSI + 0x1e38],RAX
0x1400cc40b  MOV qword ptr [RSI + 0x1e58],RAX
0x1400cc412  MOV qword ptr [RSI + 0x1e78],RAX
0x1400cc419  MOV qword ptr [RSI + 0x1e98],RAX
0x1400cc420  MOV RAX,qword ptr [RBP + 0x67140]
0x1400cc427  MOV qword ptr [RSI + 0x2030],RAX
0x1400cc42e  MOV qword ptr [RSI + 0x1628],RAX
0x1400cc435  MOV qword ptr [RSI + 0x1b50],RAX
0x1400cc43c  MOV RAX,qword ptr [RBP + 0x67170]
0x1400cc443  MOV qword ptr [RSI + 0x2038],RAX
0x1400cc44a  MOV qword ptr [RSI + 0x1838],RAX
0x1400cc451  MOV qword ptr [RSI + 0x1620],RAX
0x1400cc458  MOV qword ptr [RSI + 0x1d58],RAX
0x1400cc45f  MOV qword ptr [RSI + 0x1b68],R13
0x1400cc466  MOV qword ptr [RSI + 0x1ae0],R13
0x1400cc46d  MOV EAX,dword ptr [R13 + 0x2d8]
0x1400cc474  MOV dword ptr [RSI + 0x1ac8],EAX
0x1400cc47a  MOV RCX,qword ptr [RSI + 0x1ae0]
0x1400cc481  MOV EAX,dword ptr [RCX + 0x2dc]
0x1400cc487  MOV dword ptr [RSI + 0x1acc],EAX
0x1400cc48d  MOV EAX,dword ptr [RCX + 0x2e0]
0x1400cc493  MOV dword ptr [RSI + 0x1ad0],EAX
0x1400cc499  MOV EAX,dword ptr [RCX + 0x2e4]
0x1400cc49f  MOV dword ptr [RSI + 0x1ad4],EAX
0x1400cc4a5  MOV EAX,dword ptr [RCX + 0x2e8]
0x1400cc4ab  MOV dword ptr [RSI + 0x1ad8],EAX
0x1400cc4b1  MOV RCX,qword ptr [RSI + 0x1b68]
0x1400cc4b8  MOV qword ptr [0x140328418],RCX
0x1400cc4bf  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc4c5  MOV dword ptr [RSI + 0x1a18],EAX
0x1400cc4cb  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc4d1  MOV dword ptr [RSI + 0x1a1c],EAX
0x1400cc4d7  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc4dd  MOV dword ptr [RSI + 0x1a20],EAX
0x1400cc4e3  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc4e9  MOV dword ptr [RSI + 0x1a24],EAX
0x1400cc4ef  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc4f5  MOV dword ptr [RSI + 0x1a28],EAX
0x1400cc4fb  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc501  MOV dword ptr [RSI + 0x1a2c],EAX
0x1400cc507  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc50d  MOV dword ptr [RSI + 0x1a30],EAX
0x1400cc513  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc519  MOV dword ptr [RSI + 0x1a34],EAX
0x1400cc51f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc525  MOV dword ptr [RSI + 0x1a38],EAX
0x1400cc52b  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc531  MOV dword ptr [RSI + 0x1a3c],EAX
0x1400cc537  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc53d  MOV dword ptr [RSI + 0x1a40],EAX
0x1400cc543  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc549  MOV dword ptr [RSI + 0x1a44],EAX
0x1400cc54f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc555  MOV dword ptr [RSI + 0x1a48],EAX
0x1400cc55b  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc561  MOV dword ptr [RSI + 0x1a4c],EAX
0x1400cc567  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc56d  MOV dword ptr [RSI + 0x1a50],EAX
0x1400cc573  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc579  MOV dword ptr [RSI + 0x1a54],EAX
0x1400cc57f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc585  MOV dword ptr [RSI + 0x1a58],EAX
0x1400cc58b  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc591  MOV dword ptr [RSI + 0x1a5c],EAX
0x1400cc597  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc59d  MOV dword ptr [RSI + 0x1a60],EAX
0x1400cc5a3  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5a9  MOV dword ptr [RSI + 0x1a64],EAX
0x1400cc5af  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5b5  MOV dword ptr [RSI + 0x1a68],EAX
0x1400cc5bb  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5c1  MOV dword ptr [RSI + 0x1a6c],EAX
0x1400cc5c7  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5cd  MOV dword ptr [RSI + 0x1a70],EAX
0x1400cc5d3  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5d9  MOV dword ptr [RSI + 0x1a74],EAX
0x1400cc5df  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5e5  MOV dword ptr [RSI + 0x1a78],EAX
0x1400cc5eb  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5f1  MOV dword ptr [RSI + 0x1a7c],EAX
0x1400cc5f7  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc5fd  MOV dword ptr [RSI + 0x1a80],EAX
0x1400cc603  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc609  MOV dword ptr [RSI + 0x1a84],EAX
0x1400cc60f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc615  MOV dword ptr [RSI + 0x1a88],EAX
0x1400cc61b  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc621  MOV dword ptr [RSI + 0x1a8c],EAX
0x1400cc627  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc62d  MOV dword ptr [RSI + 0x1a90],EAX
0x1400cc633  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc639  MOV dword ptr [RSI + 0x1a94],EAX
0x1400cc63f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc645  MOV dword ptr [RSI + 0x1a98],EAX
0x1400cc64b  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc651  MOV dword ptr [RSI + 0x1a9c],EAX
0x1400cc657  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc65d  MOV dword ptr [RSI + 0x1aa0],EAX
0x1400cc663  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc669  MOV dword ptr [RSI + 0x1aa4],EAX
0x1400cc66f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc675  MOV dword ptr [RSI + 0x1aa8],EAX
0x1400cc67b  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc681  MOV dword ptr [RSI + 0x1aac],EAX
0x1400cc687  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc68d  MOV dword ptr [RSI + 0x1ab0],EAX
0x1400cc693  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc699  MOV dword ptr [RSI + 0x1ab4],EAX
0x1400cc69f  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc6a5  MOV dword ptr [RSI + 0x1ab8],EAX
0x1400cc6ab  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc6b1  MOV dword ptr [RSI + 0x1abc],EAX
0x1400cc6b7  MOV EAX,dword ptr [RCX + 0x238]
0x1400cc6bd  MOV dword ptr [RSI + 0x1ac0],EAX
0x1400cc6c3  MOV EAX,dword ptr [RCX + 0x268]
0x1400cc6c9  MOV dword ptr [RSI + 0x1a4c],EAX
0x1400cc6cf  MOV EAX,dword ptr [RCX + 0x26c]
0x1400cc6d5  MOV dword ptr [RSI + 0x1a5c],EAX
0x1400cc6db  MOV EAX,dword ptr [RCX + 0x270]
0x1400cc6e1  MOV dword ptr [RSI + 0x1a50],EAX
0x1400cc6e7  MOV EAX,dword ptr [RCX + 0x240]
0x1400cc6ed  MOV dword ptr [RSI + 0x1a68],EAX
0x1400cc6f3  MOV EAX,dword ptr [RCX + 0x244]
0x1400cc6f9  MOV dword ptr [RSI + 0x1a60],EAX
0x1400cc6ff  MOV EAX,dword ptr [RCX + 0x23c]
0x1400cc705  MOV dword ptr [RSI + 0x1a64],EAX
0x1400cc70b  MOV EAX,dword ptr [RCX + 0x310]
0x1400cc711  MOV dword ptr [RSI + 0x1a90],EAX
0x1400cc717  MOV EAX,dword ptr [RCX + 0x310]
0x1400cc71d  MOV dword ptr [RSI + 0x1a94],EAX
0x1400cc723  MOV EAX,dword ptr [RCX + 0x314]
0x1400cc729  MOV dword ptr [RSI + 0x1a98],EAX
0x1400cc72f  MOV EAX,dword ptr [RCX + 0x318]
0x1400cc735  MOV dword ptr [RSI + 0x1a9c],EAX
0x1400cc73b  MOV EAX,dword ptr [RCX + 0x31c]
0x1400cc741  MOV dword ptr [RSI + 0x1aa0],EAX
0x1400cc747  MOV EAX,dword ptr [RCX + 0x310]
0x1400cc74d  MOV dword ptr [RSI + 0x1aa4],EAX
0x1400cc753  MOV EAX,dword ptr [RCX + 0x314]
0x1400cc759  MOV dword ptr [RSI + 0x1aa8],EAX
0x1400cc75f  MOV EAX,dword ptr [RCX + 0x314]
0x1400cc765  MOV dword ptr [RSI + 0x1aac],EAX
0x1400cc76b  IMUL RAX,RDI,0x70
0x1400cc76f  ADD RAX,qword ptr [RBP + 0x671c0]
0x1400cc776  MOV qword ptr [RSI + 0x1fa8],RAX
0x1400cc77d  MOV qword ptr [RSI + 0x1fc0],R12
0x1400cc784  MOVZX EAX,byte ptr [RBP + 0xa8825]
0x1400cc78b  MOV byte ptr [RSI + 0x20a0],AL
0x1400cc791  MOV byte ptr [RSI + 0x1f01],AL
0x1400cc797  MOV byte ptr [RSI + 0x1f19],AL
0x1400cc79d  MOV byte ptr [RSI + 0x1f31],AL
0x1400cc7a3  MOV byte ptr [RSI + 0x1f49],AL
0x1400cc7a9  MOV byte ptr [RSI + 0x1f61],AL
0x1400cc7af  MOV byte ptr [RSI + 0x1f79],AL
0x1400cc7b5  MOV byte ptr [RSI + 0x1f91],AL
0x1400cc7bb  MOV byte ptr [RSI + 0x1f9f],AL
0x1400cc7c1  MOV byte ptr [RSI + 0x1864],AL
0x1400cc7c7  MOV byte ptr [RSI + 0x1674],AL
0x1400cc7cd  MOV byte ptr [RSI + 0x1c28],AL
0x1400cc7d3  MOV byte ptr [RSI + 0x1aec],AL
0x1400cc7d9  MOV qword ptr [RSI + 0x1b60],R14
0x1400cc7e0  MOV RCX,qword ptr [RBP + 0xa8830]
0x1400cc7e7  MOV EAX,dword ptr [RCX]
0x1400cc7e9  MOV dword ptr [RSI + 0x1070],EAX
0x1400cc7ef  LEA RAX,[RCX + 0x4]
0x1400cc7f3  MOV qword ptr [RSI + 0x1080],RAX
0x1400cc7fa  MOV qword ptr [RSI + 0x1078],RCX
0x1400cc801  CALL 0x140189320
0x1400cc806  MOV ECX,dword ptr [RSI + 0x2058]
0x1400cc80c  MOVZX EDX,byte ptr [RAX + 0x30]
0x1400cc810  MOV EAX,ECX
0x1400cc812  OR ECX,0x4
0x1400cc815  AND EAX,0xfffffffb
0x1400cc818  TEST DL,DL
0x1400cc81a  CMOVZ ECX,EAX
0x1400cc81d  MOV dword ptr [RSI + 0x2058],ECX
0x1400cc823  MOVZX ECX,byte ptr [RSI + 0x1e20]
0x1400cc82a  MOVZX EAX,CL
0x1400cc82d  OR CL,0x1
0x1400cc830  AND AL,0xfe
0x1400cc832  MOVZX ECX,CL
0x1400cc835  TEST DL,DL
0x1400cc837  MOVZX EAX,AL
0x1400cc83a  CMOVZ ECX,EAX
0x1400cc83d  MOV byte ptr [RSI + 0x1e20],CL
0x1400cc843  CALL 0x140189320
0x1400cc848  MOV EDX,dword ptr [RSI + 0x2058]
0x1400cc84e  MOV ECX,EDX
0x1400cc850  OR EDX,0x8
0x1400cc853  AND ECX,0xfffffff7
0x1400cc856  CMP byte ptr [RAX + 0x31],0x0
0x1400cc85a  CMOVZ EDX,ECX
0x1400cc85d  INC R15D
0x1400cc860  MOV dword ptr [RSI + 0x2058],EDX
0x1400cc866  MOVZX EDX,byte ptr [RBP + 0xa87e4]
0x1400cc86d  CMP R15D,EDX
0x1400cc870  JL 0x1400cc33e
0x1400cc876  LEA R14,[RBP + 0x69748]
0x1400cc87d  LEA R15,[RBP + 0x6a130]
0x1400cc884  LEA RSI,[RBP + 0x697b8]
0x1400cc88b  CALL 0x140242630
0x1400cc890  VMOVSS XMM2,dword ptr [0x1402d1cfc]
0x1400cc898  VMOVSS XMM3,dword ptr [0x1402d22d0]
0x1400cc8a0  IMUL EDX,EAX,0xee29
0x1400cc8a6  LEA R8,[0x1403273a0]
0x1400cc8ad  MOV R9D,0x400
0x1400cc8b3  INC EDX
0x1400cc8b5  IMUL ECX,EDX,0x10dcd
0x1400cc8bb  VXORPS XMM0,XMM0,XMM0
0x1400cc8bf  INC ECX
0x1400cc8c1  IMUL EDX,ECX,0x10dcd
0x1400cc8c7  AND ECX,0xffff0000
0x1400cc8cd  INC EDX
0x1400cc8cf  MOV EAX,EDX
0x1400cc8d1  SHR EAX,0x10
0x1400cc8d4  OR EAX,ECX
0x1400cc8d6  VCVTSI2SS XMM0,XMM0,RAX
0x1400cc8db  VMULSS XMM1,XMM0,XMM2
0x1400cc8df  VUCOMISS XMM1,XMM3
0x1400cc8e3  VMOVSS dword ptr [R8],XMM1
0x1400cc8e8  JNZ 0x1400cc8f1
0x1400cc8ea  MOV dword ptr [R8],0x3f7d70a4
0x1400cc8f1  ADD R8,0x4
0x1400cc8f5  SUB R9,0x1
0x1400cc8f9  JNZ 0x1400cc8b5
0x1400cc8fb  CALL 0x140242630
0x1400cc900  MOV EBX,EAX
0x1400cc902  CALL 0x140189320
0x1400cc907  MOV ECX,EBX
0x1400cc909  MOV dword ptr [RAX + 0x8],EBX
0x1400cc90c  CALL 0x14024265c
0x1400cc911  LEA RDI,[RBP + 0xa8280]
0x1400cc918  MOV RAX,qword ptr [RDI]
0x1400cc91b  MOV RDX,qword ptr [RAX + 0x10]
0x1400cc91f  MOV RAX,qword ptr [RBP + 0xa8318]
0x1400cc926  MOV qword ptr [RBP + 0x69758],RAX
0x1400cc92d  MOV qword ptr [R14],RDX
0x1400cc930  MOV qword ptr [RBP + 0x69750],RSI
0x1400cc937  TEST RDX,RDX
0x1400cc93a  JNZ 0x1400cc947
0x1400cc93c  XOR R13D,R13D
0x1400cc93f  MOV EDX,R13D
0x1400cc942  JMP 0x1400cc9d8
0x1400cc947  MOV RAX,qword ptr [RDX]
0x1400cc94a  XOR R9D,R9D
0x1400cc94d  XOR R10D,R10D
0x1400cc950  XOR R13D,R13D
0x1400cc953  MOVZX ECX,word ptr [RAX]
0x1400cc956  MOV EBX,ECX
0x1400cc958  LEA R8D,[RCX + RCX*0x1]
0x1400cc95c  MOV dword ptr [RSP + 0x70],R8D
0x1400cc961  CMP RCX,0x2
0x1400cc965  JC 0x1400cc9ab
0x1400cc967  MOV RSI,qword ptr [RDX + 0x10]
0x1400cc96b  LEA R8,[RCX + -0x2]
0x1400cc96f  SHR R8,0x1
0x1400cc972  MOV RDX,RSI
0x1400cc975  INC R8
0x1400cc978  LEA R11,[R8 + R8*0x1]
0x1400cc97c  NOP dword ptr [RAX]
0x1400cc980  MOV RAX,qword ptr [RDX]
0x1400cc983  LEA RDX,[RDX + 0x20]
0x1400cc987  MOVZX ECX,byte ptr [RAX]
0x1400cc98a  MOV RAX,qword ptr [RDX + -0x10]
0x1400cc98e  ADD R9D,ECX
0x1400cc991  MOVZX ECX,byte ptr [RAX]
0x1400cc994  ADD R10D,ECX
0x1400cc997  SUB R8,0x1
0x1400cc99b  JNZ 0x1400cc980
0x1400cc99d  LEA RDI,[RBP + 0xa8280]
0x1400cc9a4  CMP R11,RBX
0x1400cc9a7  JGE 0x1400cc9c1
0x1400cc9a9  JMP 0x1400cc9b6
0x1400cc9ab  TEST ECX,ECX
0x1400cc9ad  JZ 0x1400cc9c8
0x1400cc9af  MOV RSI,qword ptr [RDX + 0x10]
0x1400cc9b3  XOR R11D,R11D
0x1400cc9b6  ADD R11,R11
0x1400cc9b9  MOV RAX,qword ptr [RSI + R11*0x8]
0x1400cc9bd  MOVZX R13D,byte ptr [RAX]
0x1400cc9c1  LEA RSI,[RBP + 0x697b8]
0x1400cc9c8  MOV EDX,dword ptr [RSP + 0x70]
0x1400cc9cc  ADD EDX,R13D
0x1400cc9cf  ADD EDX,R10D
0x1400cc9d2  ADD EDX,R9D
0x1400cc9d5  XOR R13D,R13D
0x1400cc9d8  MOV RCX,qword ptr [0x14032c8f8]
0x1400cc9df  MOV R8D,0x10
0x1400cc9e5  CALL 0x140200de0
0x1400cc9ea  MOV RCX,qword ptr [R14]
0x1400cc9ed  TEST RCX,RCX
0x1400cc9f0  JZ 0x1400cca0c
0x1400cc9f2  MOV qword ptr [R14 + 0x18],RAX
0x1400cc9f6  MOV RCX,qword ptr [RCX]
0x1400cc9f9  MOVZX EDX,word ptr [RCX]
0x1400cc9fc  MOV RCX,R14
0x1400cc9ff  LEA RAX,[RAX + RDX*0x2]
0x1400cca03  MOV qword ptr [R14 + 0x20],RAX
0x1400cca07  CALL 0x1400a98c0
0x1400cca0c  MOVZX EAX,byte ptr [RBP + 0xa8825]
0x1400cca13  LEA R8,[RBP + 0x695c8]
0x1400cca1a  MOV byte ptr [RBP + 0x69770],AL
0x1400cca20  MOV RDX,qword ptr [RDI]
0x1400cca23  MOV R9,qword ptr [RBP + 0xa8288]
0x1400cca2a  MOV RDX,qword ptr [RDX + 0x8]
0x1400cca2e  CALL 0x140135b50
0x1400cca33  MOV RCX,qword ptr [0x14032c8f8]
0x1400cca3a  MOV R8D,0x10
0x1400cca40  MOV EDX,EAX
0x1400cca42  CALL 0x140200de0
0x1400cca47  MOV RDX,qword ptr [RDI]
0x1400cca4a  LEA RCX,[RBP + 0xa87a0]
0x1400cca51  MOV R9,qword ptr [RBP + 0xa8288]
0x1400cca58  LEA R8,[RBP + 0x695c8]
0x1400cca5f  MOV qword ptr [RSP + 0x30],RAX
0x1400cca64  MOV RAX,qword ptr [RBP + 0xa82e8]
0x1400cca6b  MOV RDX,qword ptr [RDX + 0x8]
0x1400cca6f  MOV qword ptr [RSP + 0x28],RAX
0x1400cca74  MOV qword ptr [RSP + 0x20],RCX
0x1400cca79  MOV RCX,RSI
0x1400cca7c  CALL 0x140135cb0
0x1400cca81  LEA R8,[RBP + 0x697b8]
0x1400cca88  MOV RAX,qword ptr [R8]
0x1400cca8b  MOVZX R9D,byte ptr [R8 + 0x34]
0x1400cca90  LEA RCX,[RAX + R9*0x8]
0x1400cca94  CMP RAX,RCX
0x1400cca97  JZ 0x1400ccb42
0x1400cca9d  MOV RBX,qword ptr [RAX]
0x1400ccaa0  MOV R10D,R13D
0x1400ccaa3  MOV qword ptr [RBX + 0xc0],R8
0x1400ccaaa  CMP dword ptr [RBX + 0x118],0x0
0x1400ccab1  MOV qword ptr [RBX + 0x140],R8
0x1400ccab8  JLE 0x1400ccb29
0x1400ccaba  MOV RCX,R13
0x1400ccabd  MOV R9,qword ptr [RBX + 0x110]
0x1400ccac4  MOV RDX,qword ptr [RCX + R9*0x1 + 0x378]
0x1400ccacc  TEST RDX,RDX
0x1400ccacf  JZ 0x1400ccaf2
0x1400ccad1  MOV R11,qword ptr [RDX + 0x8]
0x1400ccad5  MOV qword ptr [RDX + 0x180],R8
0x1400ccadc  TEST R11,R11
0x1400ccadf  JZ 0x1400ccae5
0x1400ccae1  MOV qword ptr [R11 + 0x78],R8
0x1400ccae5  MOV R11,qword ptr [RDX + 0x10]
0x1400ccae9  TEST R11,R11
0x1400ccaec  JZ 0x1400ccaf2
0x1400ccaee  MOV qword ptr [R11 + 0x78],R8
0x1400ccaf2  MOV RDX,qword ptr [RCX + R9*0x1 + 0x8]
0x1400ccaf7  MOV qword ptr [RCX + R9*0x1 + 0x180],R8
0x1400ccaff  TEST RDX,RDX
0x1400ccb02  JZ 0x1400ccb08
0x1400ccb04  MOV qword ptr [RDX + 0x78],R8
0x1400ccb08  MOV RDX,qword ptr [RCX + R9*0x1 + 0x10]
0x1400ccb0d  TEST RDX,RDX
0x1400ccb10  JZ 0x1400ccb16
0x1400ccb12  MOV qword ptr [RDX + 0x78],R8
0x1400ccb16  INC R10D
0x1400ccb19  ADD RCX,0x520
0x1400ccb20  CMP R10D,dword ptr [RBX + 0x118]
0x1400ccb27  JL 0x1400ccabd
0x1400ccb29  MOVZX R9D,byte ptr [R8 + 0x34]
0x1400ccb2e  ADD RAX,0x8
0x1400ccb32  MOV RCX,qword ptr [R8]
0x1400ccb35  LEA RDX,[RCX + R9*0x8]
0x1400ccb39  CMP RAX,RDX
0x1400ccb3c  JNZ 0x1400cca9d
0x1400ccb42  MOV qword ptr [RBP + 0x697c0],R14
0x1400ccb49  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400ccb50  MOVZX ECX,R9B
0x1400ccb54  LEA RDX,[RAX + RCX*0x8]
0x1400ccb58  CMP RAX,RDX
0x1400ccb5b  JZ 0x1400ccbe0
0x1400ccb61  MOV R10,qword ptr [RAX]
0x1400ccb64  MOV R8D,R13D
0x1400ccb67  MOV qword ptr [R10 + 0xb8],R14
0x1400ccb6e  CMP dword ptr [R10 + 0x118],0x0
0x1400ccb76  MOV qword ptr [R10 + 0x150],R14
0x1400ccb7d  JLE 0x1400ccbc0
0x1400ccb7f  MOV RCX,R13
0x1400ccb82  MOV RDX,qword ptr [R10 + 0x110]
0x1400ccb89  MOV R9,qword ptr [RCX + RDX*0x1 + 0x8]
0x1400ccb8e  MOV qword ptr [RCX + RDX*0x1 + 0x188],R14
0x1400ccb96  TEST R9,R9
0x1400ccb99  JZ 0x1400ccb9f
0x1400ccb9b  MOV qword ptr [R9 + 0x70],R14
0x1400ccb9f  MOV R9,qword ptr [RCX + RDX*0x1 + 0x10]
0x1400ccba4  TEST R9,R9
0x1400ccba7  JZ 0x1400ccbad
0x1400ccba9  MOV qword ptr [R9 + 0x70],R14
0x1400ccbad  INC R8D
0x1400ccbb0  ADD RCX,0x520
0x1400ccbb7  CMP R8D,dword ptr [R10 + 0x118]
0x1400ccbbe  JL 0x1400ccb82
0x1400ccbc0  MOVZX R8D,byte ptr [RBP + 0x697ec]
0x1400ccbc8  ADD RAX,0x8
0x1400ccbcc  MOV RCX,qword ptr [RBP + 0x697b8]
0x1400ccbd3  LEA RDX,[RCX + R8*0x8]
0x1400ccbd7  CMP RAX,RDX
0x1400ccbda  JNZ 0x1400ccb61
0x1400ccbdc  MOVZX R9D,R8B
0x1400ccbe0  MOV qword ptr [RBP + 0x697d0],R15
0x1400ccbe7  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400ccbee  MOVZX ECX,R9B
0x1400ccbf2  LEA RDX,[RAX + RCX*0x8]
0x1400ccbf6  CMP RAX,RDX
0x1400ccbf9  JZ 0x1400ccc94
0x1400ccbff  MOV R10,qword ptr [RAX]
0x1400ccc02  MOV EDX,R13D
0x1400ccc05  CMP dword ptr [R10 + 0x118],0x0
0x1400ccc0d  JLE 0x1400ccc75
0x1400ccc0f  MOV RCX,R13
0x1400ccc12  NOP word ptr [RAX + RAX*0x1]
0x1400ccc21  NOP word ptr [RAX + RAX*0x1]
0x1400ccc30  NOP word ptr [RAX + RAX*0x1]
0x1400ccc3f  NOP
0x1400ccc40  MOV R9,qword ptr [R10 + 0x110]
0x1400ccc47  MOV R8,qword ptr [R9 + RCX*0x1 + 0x378]
0x1400ccc4f  TEST R8,R8
0x1400ccc52  JZ 0x1400ccc5b
0x1400ccc54  MOV qword ptr [R8 + 0x178],R15
0x1400ccc5b  MOV qword ptr [R9 + RCX*0x1 + 0x178],R15
0x1400ccc63  INC EDX
0x1400ccc65  ADD RCX,0x520
0x1400ccc6c  CMP EDX,dword ptr [R10 + 0x118]
0x1400ccc73  JL 0x1400ccc40
0x1400ccc75  MOVZX EDX,byte ptr [RBP + 0x697ec]
0x1400ccc7c  ADD RAX,0x8
0x1400ccc80  MOV RCX,qword ptr [RBP + 0x697b8]
0x1400ccc87  LEA RDX,[RCX + RDX*0x8]
0x1400ccc8b  CMP RAX,RDX
0x1400ccc8e  JNZ 0x1400ccbff
0x1400ccc94  MOV RDX,qword ptr [RBP + 0x67140]
0x1400ccc9b  MOV RCX,RSI
0x1400ccc9e  CALL 0x140138080
0x1400ccca3  MOVZX EDX,byte ptr [RBP + 0x697ec]
0x1400cccaa  MOV qword ptr [RBP + 0x697d8],R12
0x1400cccb1  MOVZX R8D,DL
0x1400cccb5  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400cccbc  LEA RCX,[RAX + RDX*0x8]
0x1400cccc0  CMP RAX,RCX
0x1400cccc3  JZ 0x1400ccd1d
0x1400cccc5  MOV R9,qword ptr [RAX]
0x1400cccc8  MOV R8D,R13D
0x1400ccccb  CMP dword ptr [R9 + 0x118],0x0
0x1400cccd3  JLE 0x1400cccfa
0x1400cccd5  MOV RDX,R13
0x1400cccd8  MOV RCX,qword ptr [R9 + 0x110]
0x1400cccdf  LEA RDX,[RDX + 0x520]
0x1400ccce6  INC R8D
0x1400ccce9  MOV qword ptr [RDX + RCX*0x1 + -0x388],R12
0x1400cccf1  CMP R8D,dword ptr [R9 + 0x118]
0x1400cccf8  JL 0x1400cccd8
0x1400cccfa  MOVZX R8D,byte ptr [RBP + 0x697ec]
0x1400ccd02  ADD RAX,0x8
0x1400ccd06  MOV RDX,qword ptr [RBP + 0x697b8]
0x1400ccd0d  LEA RCX,[RDX + R8*0x8]
0x1400ccd11  CMP RAX,RCX
0x1400ccd14  JNZ 0x1400cccc5
0x1400ccd16  MOV RAX,RDX
0x1400ccd19  MOVZX EDX,R8B
0x1400ccd1d  MOVZX ECX,DL
0x1400ccd20  LEA RDX,[RAX + RCX*0x8]
0x1400ccd24  CMP RAX,RDX
0x1400ccd27  JZ 0x1400ccd81
0x1400ccd29  MOV R9,qword ptr [RAX]
0x1400ccd2c  MOV R8D,R13D
0x1400ccd2f  CMP dword ptr [R9 + 0x118],0x0
0x1400ccd37  JLE 0x1400ccd65
0x1400ccd39  LEA R10,[RBP + 0x69798]
0x1400ccd40  MOV RDX,R13
0x1400ccd43  MOV RCX,qword ptr [R9 + 0x110]
0x1400ccd4a  LEA RDX,[RDX + 0x520]
0x1400ccd51  INC R8D
0x1400ccd54  MOV qword ptr [RCX + RDX*0x1 + -0x1f0],R10
0x1400ccd5c  CMP R8D,dword ptr [R9 + 0x118]
0x1400ccd63  JL 0x1400ccd43
0x1400ccd65  MOVZX R8D,byte ptr [RBP + 0x697ec]
0x1400ccd6d  ADD RAX,0x8
0x1400ccd71  MOV RCX,qword ptr [RBP + 0x697b8]
0x1400ccd78  LEA RDX,[RCX + R8*0x8]
0x1400ccd7c  CMP RAX,RDX
0x1400ccd7f  JNZ 0x1400ccd29
0x1400ccd81  MOVZX R9D,byte ptr [RBP + 0xa8825]
0x1400ccd89  MOV byte ptr [RBP + 0x697ed],R9B
0x1400ccd90  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400ccd97  MOVZX ECX,R8B
0x1400ccd9b  LEA RDX,[RAX + RCX*0x8]
0x1400ccd9f  CMP RAX,RDX
0x1400ccda2  JZ 0x1400cce2d
0x1400ccda8  MOV R11,qword ptr [RAX]
0x1400ccdab  MOV R8D,R13D
0x1400ccdae  MOV byte ptr [R11 + 0xfb],R9B
0x1400ccdb5  CMP dword ptr [R11 + 0x118],0x0
0x1400ccdbd  MOV byte ptr [R11 + 0x15f],R9B
0x1400ccdc4  JLE 0x1400cce0d
0x1400ccdc6  MOV RCX,R13
0x1400ccdc9  MOV RDX,qword ptr [R11 + 0x110]
0x1400ccdd0  MOV R10,qword ptr [RDX + RCX*0x1 + 0x8]
0x1400ccdd5  MOV byte ptr [RDX + RCX*0x1 + 0x24a],R9B
0x1400ccddd  TEST R10,R10
0x1400ccde0  JZ 0x1400ccde9
0x1400ccde2  MOV byte ptr [R10 + 0xb3],R9B
0x1400ccde9  MOV R10,qword ptr [RDX + RCX*0x1 + 0x10]
0x1400ccdee  TEST R10,R10
0x1400ccdf1  JZ 0x1400ccdfa
0x1400ccdf3  MOV byte ptr [R10 + 0xb3],R9B
0x1400ccdfa  INC R8D
0x1400ccdfd  ADD RCX,0x520
0x1400cce04  CMP R8D,dword ptr [R11 + 0x118]
0x1400cce0b  JL 0x1400ccdc9
0x1400cce0d  MOVZX R8D,byte ptr [RBP + 0x697ec]
0x1400cce15  ADD RAX,0x8
0x1400cce19  MOV RDX,qword ptr [RBP + 0x697b8]
0x1400cce20  LEA R8,[RDX + R8*0x8]
0x1400cce24  CMP RAX,R8
0x1400cce27  JNZ 0x1400ccda8
0x1400cce2d  CMP byte ptr [RBP + 0xa8827],0x1
0x1400cce34  MOV RCX,RSI
0x1400cce37  SETZ DL
0x1400cce3a  CALL 0x1401381c0
0x1400cce3f  MOVZX EAX,byte ptr [RBP + 0xa87e4]
0x1400cce46  MOV EDI,R13D
0x1400cce49  TEST AL,AL
0x1400cce4b  JZ 0x1400cd06e
0x1400cce51  VMOVSS XMM2,dword ptr [0x1402d236c]
0x1400cce59  MOV RBX,R13
0x1400cce5c  MOV R10,R13
0x1400cce5f  MOV R14D,0x2
0x1400cce65  MOV R11,qword ptr [RBP + 0xa8248]
0x1400cce6c  MOV R8,qword ptr [R10 + R11*0x1 + 0xfe0]
0x1400cce74  CMP AL,0x1
0x1400cce76  JBE 0x1400ccf67
0x1400cce7c  MOVZX EAX,byte ptr [RBP + 0xa88b0]
0x1400cce83  TEST AL,AL
0x1400cce85  JNZ 0x1400cce8c
0x1400cce87  XOR R9B,R9B
0x1400cce8a  JMP 0x1400ccec0
0x1400cce8c  CMP AL,0x1
0x1400cce8e  JNZ 0x1400cce96
0x1400cce90  MOVZX R9D,AL
0x1400cce94  JMP 0x1400ccec0
0x1400cce96  MOVZX ECX,byte ptr [R8 + 0xa]
0x1400cce9b  IMUL ECX,EAX
0x1400cce9e  MOV EAX,0x51eb851f
0x1400ccea3  MUL ECX
0x1400ccea5  SHR EDX,0x5
0x1400ccea8  CMP EDX,R14D
0x1400cceab  CMOVL EDX,R14D
0x1400cceaf  TEST DL,0x1
0x1400cceb2  LEA EAX,[RDX + 0x1]
0x1400cceb5  MOVZX R9D,AL
0x1400cceb9  MOVZX EAX,DL
0x1400ccebc  CMOVZ R9D,EAX
0x1400ccec0  MOV byte ptr [R8 + 0xa],R9B
0x1400ccec4  MOVZX EAX,byte ptr [RBP + 0xa88b1]
0x1400ccecb  TEST AL,AL
0x1400ccecd  JNZ 0x1400cceda
0x1400ccecf  MOV word ptr [R8 + 0xb],0x0
0x1400cced6  XOR DL,DL
0x1400cced8  JMP 0x1400ccf43
0x1400cceda  MOV ECX,EAX
0x1400ccedc  MOV R9D,0x1
0x1400ccee2  MOVZX EAX,byte ptr [R8 + 0xb]
0x1400ccee7  IMUL ECX,EAX
0x1400cceea  MOV EAX,0x51eb851f
0x1400cceef  MUL ECX
0x1400ccef1  SHR EDX,0x5
0x1400ccef4  CMP EDX,0x1
0x1400ccef7  CMOVL EDX,R9D
0x1400ccefb  MOV byte ptr [R8 + 0xb],DL
0x1400cceff  MOVZX EAX,byte ptr [R8 + 0xc]
0x1400ccf04  MOVZX ECX,byte ptr [RBP + 0xa88b1]
0x1400ccf0b  IMUL ECX,EAX
0x1400ccf0e  MOV EAX,0x51eb851f
0x1400ccf13  MUL ECX
0x1400ccf15  SHR EDX,0x5
0x1400ccf18  CMP EDX,R9D
0x1400ccf1b  CMOVL EDX,R9D
0x1400ccf1f  MOV byte ptr [R8 + 0xc],DL
0x1400ccf23  MOVZX EAX,byte ptr [R8 + 0xd]
0x1400ccf28  MOVZX ECX,byte ptr [RBP + 0xa88b1]
0x1400ccf2f  IMUL ECX,EAX
0x1400ccf32  MOV EAX,0x51eb851f
0x1400ccf37  MUL ECX
0x1400ccf39  SHR EDX,0x5
0x1400ccf3c  CMP EDX,R9D
0x1400ccf3f  CMOVL EDX,R9D
0x1400ccf43  MOV byte ptr [R8 + 0xd],DL
0x1400ccf47  TEST byte ptr [RBP + 0xa88b2],0x1
0x1400ccf4e  JZ 0x1400ccfda
0x1400ccf54  MOV RAX,qword ptr [R10 + R11*0x1 + 0x1fb8]
0x1400ccf5c  MOV byte ptr [RAX + 0x49],0xff
0x1400ccf60  MOV byte ptr [R8 + 0x10],0xff
0x1400ccf65  JMP 0x1400ccfda
0x1400ccf67  MOVZX EAX,byte ptr [RBP + 0xa881d]
0x1400ccf6e  CMP AL,0x1
0x1400ccf70  JZ 0x1400ccf76
0x1400ccf72  TEST AL,AL
0x1400ccf74  JNZ 0x1400ccfda
0x1400ccf76  MOV RCX,qword ptr [R10 + R11*0x1 + 0x1fb8]
0x1400ccf7e  CMP AL,0x1
0x1400ccf80  JNZ 0x1400ccf89
0x1400ccf82  VMULSS XMM1,XMM2,dword ptr [RCX + 0x2c]
0x1400ccf87  JMP 0x1400ccf96
0x1400ccf89  TEST AL,AL
0x1400ccf8b  JNZ 0x1400ccf9b
0x1400ccf8d  VMOVSS XMM0,dword ptr [RCX + 0x2c]
0x1400ccf92  VADDSS XMM1,XMM0,XMM0
0x1400ccf96  VMOVSS dword ptr [RCX + 0x2c],XMM1
0x1400ccf9b  MOVZX R9D,byte ptr [R8 + 0xa]
0x1400ccfa0  TEST R9B,R9B
0x1400ccfa3  JZ 0x1400ccfd6
0x1400ccfa5  MOVZX EAX,byte ptr [RBP + 0xa881d]
0x1400ccfac  TEST AL,AL
0x1400ccfae  JNZ 0x1400ccfb5
0x1400ccfb0  MOV R9B,0x63
0x1400ccfb3  JMP 0x1400ccfd6
0x1400ccfb5  CMP AL,0x1
0x1400ccfb7  JNZ 0x1400ccfd6
0x1400ccfb9  MOV EAX,0x64
0x1400ccfbe  SUB EAX,R9D
0x1400ccfc1  CDQ
0x1400ccfc2  SUB EAX,EDX
0x1400ccfc4  SAR EAX,0x1
0x1400ccfc6  ADD AL,R9B
0x1400ccfc9  MOVZX R9D,AL
0x1400ccfcd  INC R9D
0x1400ccfd0  SHR R9D,0x1
0x1400ccfd3  ADD R9B,R9B
0x1400ccfd6  MOV byte ptr [R8 + 0xa],R9B
0x1400ccfda  MOV RAX,qword ptr [RBP + 0xa8280]
0x1400ccfe1  MOV RCX,qword ptr [RAX]
0x1400ccfe4  MOVZX EAX,byte ptr [RCX]
0x1400ccfe7  CMP AL,R14B
0x1400ccfea  JZ 0x1400ccfff
0x1400ccfec  TEST AL,AL
0x1400ccfee  JNZ 0x1400ccffb
0x1400ccff0  CMP byte ptr [RBP + 0xa881d],R14B
0x1400ccff7  JBE 0x1400ccfff
0x1400ccff9  JMP 0x1400cd006
0x1400ccffb  CMP AL,0x1
0x1400ccffd  JNZ 0x1400cd006
0x1400ccfff  MOV word ptr [R8 + 0x8],0x2710
0x1400cd006  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400cd00d  INC EDI
0x1400cd00f  MOV RCX,qword ptr [RBX + RAX*0x1]
0x1400cd013  MOV RAX,qword ptr [RCX + 0x110]
0x1400cd01a  MOV RCX,qword ptr [RAX + 0x1a0]
0x1400cd021  MOV RAX,qword ptr [RCX]
0x1400cd024  MOV word ptr [RAX + 0x7f],0x101
0x1400cd02a  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400cd031  MOV RCX,qword ptr [RBX + RAX*0x1]
0x1400cd035  ADD RBX,0x8
0x1400cd039  MOV RDX,qword ptr [RCX + 0x110]
0x1400cd040  MOV RCX,qword ptr [RBP + 0xa8248]
0x1400cd047  ADD RCX,R10
0x1400cd04a  ADD R10,0x27a0
0x1400cd051  MOV qword ptr [RDX + 0x1b8],RCX
0x1400cd058  MOV byte ptr [RDX + 0x42b],0x1
0x1400cd05f  MOVZX EAX,byte ptr [RBP + 0xa87e4]
0x1400cd066  CMP EDI,EAX
0x1400cd068  JL 0x1400cce65
0x1400cd06e  MOV EBX,dword ptr [RBP + 0xa82f0]
0x1400cd074  MOV EDI,R13D
0x1400cd077  TEST EBX,EBX
0x1400cd079  JLE 0x1400cd1ab
0x1400cd07f  LEA RSI,[RBP + 0x6a130]
0x1400cd086  MOV R10,R13
0x1400cd089  MOV EDX,0x520
0x1400cd08e  MOV RBX,qword ptr [RBP + 0xa82f8]
0x1400cd095  AND byte ptr [RBX + R10*0x1 + 0x81],0xf9
0x1400cd09e  MOV RAX,qword ptr [RBP + 0x697b8]
0x1400cd0a5  MOV R9,qword ptr [RBP + 0xa82f8]
0x1400cd0ac  ADD R9,R10
0x1400cd0af  MOV R8,qword ptr [RAX]
0x1400cd0b2  LEA EAX,[RDI + 0x1]
0x1400cd0b5  CMP EAX,dword ptr [R8 + 0x118]
0x1400cd0bc  JGE 0x1400cd188
0x1400cd0c2  MOV R8,qword ptr [R8 + 0x110]
0x1400cd0c9  MOV qword ptr [R8 + RDX*0x1 + 0x1c0],R9
0x1400cd0d1  MOV RAX,qword ptr [R9 + 0x48]
0x1400cd0d5  MOV R11,qword ptr [RAX]
0x1400cd0d8  TEST byte ptr [R11 + 0xc],0x2
0x1400cd0dd  JZ 0x1400cd0eb
0x1400cd0df  OR dword ptr [R8 + RDX*0x1 + 0x1f0],0x8000000
0x1400cd0eb  TEST byte ptr [R11 + 0xc],0x4
0x1400cd0f0  JZ 0x1400cd109
0x1400cd0f2  OR dword ptr [R8 + RDX*0x1 + 0x1f0],0x10000000
0x1400cd0fe  MOV EAX,dword ptr [R11]
0x1400cd101  MOV dword ptr [R8 + RDX*0x1 + 0x208],EAX
0x1400cd109  MOV RAX,qword ptr [R9 + 0x10]
0x1400cd10d  TEST RAX,RAX
0x1400cd110  JZ 0x1400cd126
0x1400cd112  MOV qword ptr [R8 + RDX*0x1 + 0x390],RAX
0x1400cd11a  MOV RAX,qword ptr [R9 + 0x10]
0x1400cd11e  MOV qword ptr [R8 + RDX*0x1 + 0x398],RAX
0x1400cd126  MOV RCX,qword ptr [R9 + 0x18]
0x1400cd12a  MOV RAX,R13
0x1400cd12d  TEST RCX,RCX
0x1400cd130  CMOVNZ RAX,RCX
0x1400cd134  MOV qword ptr [R8 + RDX*0x1 + 0x360],RAX
0x1400cd13c  SETNZ AL
0x1400cd13f  MOV byte ptr [R8 + RDX*0x1 + 0x42b],AL
0x1400cd147  MOV RCX,qword ptr [R9 + 0x20]
0x1400cd14b  TEST RCX,RCX
0x1400cd14e  JZ 0x1400cd15c
0x1400cd150  MOV RAX,qword ptr [R8 + RDX*0x1 + 0x1a0]
0x1400cd158  MOV qword ptr [RAX + 0x8],RCX
0x1400cd15c  TEST byte ptr [R11 + 0xc],0x4
0x1400cd161  MOV R8,qword ptr [R8 + RDX*0x1 + 0x1a0]
0x1400cd169  JZ 0x1400cd178
0x1400cd16b  MOV RCX,qword ptr [R8]
0x1400cd16e  MOV byte ptr [RCX + 0x7b],0x1
0x1400cd172  MOV EAX,dword ptr [R11]
0x1400cd175  MOV dword ptr [RCX + 0x4c],EAX
0x1400cd178  MOV RAX,qword ptr [R9 + 0x28]
0x1400cd17c  MOV qword ptr [R8 + 0x20],RAX
0x1400cd180  MOV RAX,qword ptr [R9 + 0x30]
0x1400cd184  MOV qword ptr [R8 + 0x28],RAX
0x1400cd188  MOV qword ptr [RBX + R10*0x1 + 0x70],RSI
0x1400cd18d  INC EDI
0x1400cd18f  MOV EBX,dword ptr [RBP + 0xa82f0]
0x1400cd195  ADD R10,0x108
0x1400cd19c  ADD RDX,0x520
0x1400cd1a3  CMP EDI,EBX
0x1400cd1a5  JL 0x1400cd08e
0x1400cd1ab  MOVZX ECX,byte ptr [RBP + 0xa87e4]
0x1400cd1b2  XOR AL,AL
0x1400cd1b4  XOR DL,DL
0x1400cd1b6  MOV dword ptr [RSP + 0x70],0x0
0x1400cd1be  XOR R8B,R8B
0x1400cd1c1  XOR R9B,R9B
0x1400cd1c4  TEST CL,CL
0x1400cd1c6  JZ 0x1400cd290
0x1400cd1cc  MOV R11,qword ptr [RBP + 0xa8248]
0x1400cd1d3  MOV R9,R13
0x1400cd1d6  MOV RDI,qword ptr [RBP + 0x697b8]
0x1400cd1dd  ADD R11,0xff8
0x1400cd1e4  MOV ESI,ECX
0x1400cd1e6  MOVZX ECX,byte ptr [R11 + 0x17a2]
0x1400cd1ee  MOV RAX,qword ptr [R11]
0x1400cd1f1  MOVZX ECX,byte ptr [RCX + RAX*0x1 + 0x4]
0x1400cd1f6  MOV RAX,qword ptr [RDI]
0x1400cd1f9  MOV byte ptr [RSP + R9*0x1 + 0x70],CL
0x1400cd1fe  INC R9
0x1400cd201  MOV ECX,dword ptr [RAX + 0x118]
0x1400cd207  CMP ECX,EBX
0x1400cd209  CMOVG ECX,EBX
0x1400cd20c  MOVSXD R10,ECX
0x1400cd20f  CMP R10,0x1
0x1400cd213  JLE 0x1400cd265
0x1400cd215  MOV R8,qword ptr [RBP + 0xa82f8]
0x1400cd21c  ADD R8,0x48
0x1400cd220  DEC R10
0x1400cd223  NOP word ptr [RAX + RAX*0x1]
0x1400cd232  NOP dword ptr [RAX + RAX*0x1]
0x1400cd240  MOV RAX,qword ptr [R8]
0x1400cd243  MOVZX EDX,byte ptr [R8 + 0x3d]
0x1400cd248  LEA R8,[R8 + 0x108]
0x1400cd24f  MOV RCX,qword ptr [RAX]
0x1400cd252  MOVZX EAX,byte ptr [RDX + RCX*0x1 + 0x4]
0x1400cd257  MOV byte ptr [RSP + R9*0x1 + 0x70],AL
0x1400cd25c  INC R9
0x1400cd25f  SUB R10,0x1
0x1400cd263  JNZ 0x1400cd240
0x1400cd265  ADD R11,0x27a0
0x1400cd26c  ADD RDI,0x8
0x1400cd270  SUB RSI,0x1
0x1400cd274  JNZ 0x1400cd1e6
0x1400cd27a  MOVZX R9D,byte ptr [RSP + 0x73]
0x1400cd280  MOVZX R8D,byte ptr [RSP + 0x72]
0x1400cd286  MOVZX EDX,byte ptr [RSP + 0x71]
0x1400cd28b  MOVZX EAX,byte ptr [RSP + 0x70]
0x1400cd290  LEA RCX,[RBP + 0x6bc40]
0x1400cd297  MOV byte ptr [RCX + 0x1da20],AL
0x1400cd29d  MOVZX EAX,byte ptr [RBP + 0xa8821]
0x1400cd2a4  MOV byte ptr [RCX + 0x1da21],DL
0x1400cd2aa  MOVZX EDX,byte ptr [RBP + 0xa881e]
0x1400cd2b1  MOV byte ptr [RCX + 0x1da22],R8B
0x1400cd2b8  MOVZX R8D,byte ptr [RBP + 0xa881f]
0x1400cd2c0  MOV byte ptr [RCX + 0x1da23],R9B
0x1400cd2c7  MOVZX R9D,byte ptr [RBP + 0xa8820]
0x1400cd2cf  MOV byte ptr [RSP + 0x20],AL
0x1400cd2d3  CALL 0x140140c60
0x1400cd2d8  MOV RCX,qword ptr [RBP + 0x67170]
0x1400cd2df  LEA RAX,[RBP + 0x697b8]
0x1400cd2e6  MOV qword ptr [RBP + 0xa87a8],RAX
0x1400cd2ed  MOV EDX,0x300
0x1400cd2f2  LEA RAX,[RBP + 0xa8160]
0x1400cd2f9  MOV qword ptr [RBP + 0xa87b8],RCX
0x1400cd300  MOV RCX,qword ptr [0x14032c8f8]
0x1400cd307  MOV R8D,0x10
0x1400cd30d  MOV qword ptr [RBP + 0xa87b0],RAX
0x1400cd314  MOV qword ptr [RBP + 0xa87a0],RBP
0x1400cd31b  MOV dword ptr [RBP + 0xa87c0],R13D
0x1400cd322  MOV qword ptr [RBP + 0xa87c8],R13
0x1400cd329  MOV qword ptr [RBP + 0xa87d0],0x0
0x1400cd334  MOV qword ptr [RBP + 0xa87d8],0x0
0x1400cd33f  CALL 0x140200de0
0x1400cd344  MOV RCX,RAX
0x1400cd347  CALL 0x140141670
0x1400cd34c  MOV RSI,qword ptr [0x14032c8f8]
0x1400cd353  LEA RCX,[RBP + 0x6a130]
0x1400cd35a  MOV qword ptr [RBP + 0xa8298],RAX
0x1400cd361  MOV qword ptr [RAX + 0x280],RCX
0x1400cd368  LEA RCX,[RBP + 0x697b8]
0x1400cd36f  MOV RAX,qword ptr [RBP + 0xa8298]
0x1400cd376  MOV qword ptr [RAX + 0x288],RCX
0x1400cd37d  MOV RCX,qword ptr [RBP + 0xa8298]
0x1400cd384  MOVZX EAX,byte ptr [RBP + 0xa8825]
0x1400cd38b  MOV byte ptr [RCX + 0x2ae],AL
0x1400cd391  MOV RAX,qword ptr [RBP + 0x67170]
0x1400cd398  MOV RCX,qword ptr [RBP + 0xa8298]
0x1400cd39f  MOV qword ptr [RCX + 0x290],RAX
0x1400cd3a6  MOV RAX,qword ptr [RBP + 0xa8298]
0x1400cd3ad  MOV qword ptr [RAX + 0x298],RBP
0x1400cd3b4  MOV RAX,qword ptr [RBP + 0xa8280]
0x1400cd3bb  CMP qword ptr [RAX + 0x28],0x0
0x1400cd3c0  JZ 0x1400cd564
0x1400cd3c6  MOV EDX,0x20
0x1400cd3cb  MOV R8D,0x10
0x1400cd3d1  MOV RCX,RSI
0x1400cd3d4  CALL 0x140200de0
0x1400cd3d9  MOV qword ptr [RAX],R13
0x1400cd3dc  MOV qword ptr [RAX + 0x8],R13
0x1400cd3e0  MOV qword ptr [RAX + 0x10],R13
0x1400cd3e4  MOV qword ptr [RAX + 0x18],R13
0x1400cd3e8  MOV RCX,qword ptr [RBP + 0xa8280]
0x1400cd3ef  MOV qword ptr [RBP + 0xa8320],RAX
0x1400cd3f6  MOV RDX,qword ptr [RCX + 0x28]
0x1400cd3fa  LEA RCX,[RBP + 0x69748]
0x1400cd401  MOV qword ptr [RAX],RDX
0x1400cd404  MOV RAX,qword ptr [RBP + 0xa8320]
0x1400cd40b  MOV qword ptr [RAX + 0x8],RCX
0x1400cd40f  MOV RBX,qword ptr [RBP + 0xa8320]
0x1400cd416  MOV RAX,qword ptr [RBX]
0x1400cd419  TEST RAX,RAX
0x1400cd41c  JNZ 0x1400cd423
0x1400cd41e  MOV EDX,R13D
0x1400cd421  JMP 0x1400cd436
0x1400cd423  MOV RAX,qword ptr [RAX]
0x1400cd426  TEST RAX,RAX
0x1400cd429  JNZ 0x1400cd430
0x1400cd42b  MOV EDX,R13D
0x1400cd42e  JMP 0x1400cd436
0x1400cd430  MOVZX EDX,word ptr [RAX]
0x1400cd433  SHL EDX,0x2
0x1400cd436  MOV R8D,0x10
0x1400cd43c  MOV RCX,RSI
0x1400cd43f  CALL 0x140200de0
0x1400cd444  MOV RCX,RAX
0x1400cd447  TEST RAX,RAX
0x1400cd44a  JZ 0x1400cd550
0x1400cd450  MOV RAX,qword ptr [RBX]
0x1400cd453  TEST RAX,RAX
0x1400cd456  JZ 0x1400cd550
0x1400cd45c  MOV RDX,qword ptr [RAX]
0x1400cd45f  TEST RDX,RDX
0x1400cd462  JZ 0x1400cd550
0x1400cd468  MOVZX R14D,word ptr [RDX]
0x1400cd46c  MOV EDI,R13D
0x1400cd46f  MOV qword ptr [RBX + 0x18],RCX
0x1400cd473  LEA RDX,[RBX + 0x18]
0x1400cd477  TEST R14D,R14D
0x1400cd47a  JZ 0x1400cd4b4
0x1400cd47c  CMP R14D,0x8
0x1400cd480  JC 0x1400cd4b4
0x1400cd482  LEA R8,[RCX + R14*0x4 + -0x4]
0x1400cd487  CMP RCX,RDX
0x1400cd48a  JA 0x1400cd491
0x1400cd48c  CMP R8,RDX
0x1400cd48f  JNC 0x1400cd4b4
0x1400cd491  MOV EAX,R14D
0x1400cd494  AND EAX,0xfffffff8
0x1400cd497  ADD EDI,0x8
0x1400cd49a  CMP EDI,EAX
0x1400cd49c  JL 0x1400cd497
0x1400cd49e  MOV R8D,EAX
0x1400cd4a1  XOR EDX,EDX
0x1400cd4a3  SHR R8,0x3
0x1400cd4a7  SHL R8,0x5
0x1400cd4ab  AND R8,-0x4
0x1400cd4af  CALL 0x1402777e0
0x1400cd4b4  MOVSXD RCX,EDI
0x1400cd4b7  CMP RCX,R14
0x1400cd4ba  JGE 0x1400cd550
0x1400cd4c0  MOV RAX,R14
0x1400cd4c3  SUB RAX,RCX
0x1400cd4c6  CMP RAX,0x4
0x1400cd4ca  JL 0x1400cd540
0x1400cd4cc  LEA R9,[R14 + -0x3]
0x1400cd4d0  LEA RDX,[RCX*0x4]
0x1400cd4d8  NOP word ptr [RAX + RAX*0x1]
0x1400cd4e7  NOP word ptr [RAX + RAX*0x1]
0x1400cd4f6  NOP dword ptr [RAX + RAX*0x1]
0x1400cd500  MOV RAX,qword ptr [RBX + 0x18]
0x1400cd504  LEA RDX,[RDX + 0x10]
0x1400cd508  MOV dword ptr [RDX + RAX*0x1 + -0x10],R13D
0x1400cd50d  MOV RAX,qword ptr [RBX + 0x18]
0x1400cd511  MOV dword ptr [RAX + RCX*0x4 + 0x4],R13D
0x1400cd516  MOV RAX,qword ptr [RBX + 0x18]
0x1400cd51a  MOV dword ptr [RAX + RCX*0x4 + 0x8],R13D
0x1400cd51f  MOV RAX,qword ptr [RBX + 0x18]
0x1400cd523  MOV dword ptr [RAX + RCX*0x4 + 0xc],R13D
0x1400cd528  ADD RCX,0x4
0x1400cd52c  CMP RCX,R9
0x1400cd52f  JL 0x1400cd500
0x1400cd531  CMP RCX,R14
0x1400cd534  JGE 0x1400cd550
0x1400cd536  NOP dword ptr [RAX + RAX*0x1]
0x1400cd540  MOV RAX,qword ptr [RBX + 0x18]
0x1400cd544  MOV dword ptr [RAX + RCX*0x4],R13D
0x1400cd548  INC RCX
0x1400cd54b  CMP RCX,R14
0x1400cd54e  JL 0x1400cd540
0x1400cd550  MOV RAX,qword ptr [RBP + 0xa8320]
0x1400cd557  LEA RCX,[RBP + 0x697b8]
0x1400cd55e  MOV qword ptr [RAX + 0x10],RCX
0x1400cd562  JMP 0x1400cd56b
0x1400cd564  MOV qword ptr [RBP + 0xa8320],R13
0x1400cd56b  MOVSXD R10,dword ptr [RSI + 0x18]
0x1400cd56f  MOV R9,R13
0x1400cd572  TEST R10,R10
0x1400cd575  JLE 0x1400cd59b
0x1400cd577  MOV R8,qword ptr [RSI + 0x10]
0x1400cd57b  NOP dword ptr [RAX + RAX*0x1]
0x1400cd580  MOV RDX,qword ptr [R8 + 0x8]
0x1400cd584  ADD RDX,qword ptr [R8]
0x1400cd587  LEA R8,[R8 + 0x18]
0x1400cd58b  CMP R9,RDX
0x1400cd58e  CMOVNC RDX,R9
0x1400cd592  MOV R9,RDX
0x1400cd595  SUB R10,0x1
0x1400cd599  JNZ 0x1400cd580
0x1400cd59b  MOV EDX,dword ptr [RSI + 0x8]
0x1400cd59e  MOV R8D,0x10
0x1400cd5a4  SUB EDX,dword ptr [RSI + 0xc]
0x1400cd5a7  MOV RCX,RSI
0x1400cd5aa  MOV EAX,dword ptr [RSI]
0x1400cd5ac  SUB EDX,R9D
0x1400cd5af  LEA EBX,[RDX + RAX*0x1 + -0x4000]
0x1400cd5b6  AND EBX,0xfffffff0
0x1400cd5b9  MOV EDX,EBX
0x1400cd5bb  CALL 0x140200de0
0x1400cd5c0  MOV RDI,RAX
0x1400cd5c3  CALL 0x140019ef0
0x1400cd5c8  MOV R8,RAX
0x1400cd5cb  MOVSXD R9,EBX
0x1400cd5ce  MOV RAX,0x2492492492492493
0x1400cd5d8  MUL R9
0x1400cd5db  MOV EAX,0x2000
0x1400cd5e0  MOV qword ptr [R8 + 0x310],RDI
0x1400cd5e7  SUB R9,RDX
0x1400cd5ea  MOV RDI,R8
0x1400cd5ed  SHR R9,0x1
0x1400cd5f0  ADD R9,RDX
0x1400cd5f3  SHR R9,0x6
0x1400cd5f7  CMP R9D,EAX
0x1400cd5fa  JGE 0x1400cd604
0x1400cd5fc  MOV EAX,R9D
0x1400cd5ff  CDQ
0x1400cd600  SUB EAX,EDX
0x1400cd602  SAR EAX,0x1
0x1400cd604  MOV dword ptr [RDI + 0x308],EAX
0x1400cd60a  LEA RBX,[R8 + 0x218]
0x1400cd611  LEA RAX,[R8 + 0x98]
0x1400cd618  MOV qword ptr [RBX],RBX
0x1400cd61b  MOV qword ptr [RAX],RAX
0x1400cd61e  MOV R10D,R13D
0x1400cd621  MOV qword ptr [RAX + 0x8],RAX
0x1400cd625  MOV dword ptr [RAX + 0x70],R13D
0x1400cd629  MOV qword ptr [RBX + 0x8],RBX
0x1400cd62d  MOV dword ptr [RBX + 0x70],R13D
0x1400cd631  MOV R11D,dword ptr [RDI + 0x308]
0x1400cd638  TEST R11D,R11D
0x1400cd63b  JLE 0x1400cd67c
0x1400cd63d  MOV RDX,R13
0x1400cd640  MOV RCX,qword ptr [R8 + 0x310]
0x1400cd647  INC R10D
0x1400cd64a  MOV RAX,qword ptr [R8 + 0x220]
0x1400cd651  ADD RCX,RDX
0x1400cd654  ADD RDX,0x70
0x1400cd658  MOV qword ptr [RAX],RCX
0x1400cd65b  MOV qword ptr [R8 + 0x220],RCX
0x1400cd662  MOV qword ptr [RCX],RBX
0x1400cd665  MOV qword ptr [RCX + 0x8],RAX
0x1400cd669  INC dword ptr [R8 + 0x288]
0x1400cd670  MOV R11D,dword ptr [RDI + 0x308]
0x1400cd677  CMP R10D,R11D
0x1400cd67a  JL 0x1400cd640
0x1400cd67c  SUB R9D,R11D
0x1400cd67f  MOVSXD RAX,R11D
0x1400cd682  MOV dword ptr [R8 + 0x198],R9D
0x1400cd689  LEA R10,[R8 + 0x1a0]
0x1400cd690  IMUL RCX,RAX,0x70
0x1400cd694  MOV R9D,R13D
0x1400cd697  ADD RCX,qword ptr [R8 + 0x310]
0x1400cd69e  MOV qword ptr [R8 + 0x190],RCX
0x1400cd6a5  MOV qword ptr [R10],R10
0x1400cd6a8  MOV qword ptr [R10 + 0x8],R10
0x1400cd6ac  MOV dword ptr [R10 + 0x70],R13D
0x1400cd6b0  CMP dword ptr [R8 + 0x198],0x0
0x1400cd6b8  JBE 0x1400cd6f9
0x1400cd6ba  NOP word ptr [RAX + RAX*0x1]
0x1400cd6c0  MOV EAX,R9D
0x1400cd6c3  INC R9D
0x1400cd6c6  IMUL RDX,RAX,0x70
0x1400cd6ca  MOV RAX,qword ptr [R8 + 0x1a8]
0x1400cd6d1  ADD RDX,qword ptr [R8 + 0x190]
0x1400cd6d8  MOV qword ptr [RAX],RDX
0x1400cd6db  MOV qword ptr [R8 + 0x1a8],RDX
0x1400cd6e2  MOV qword ptr [RDX],R10
0x1400cd6e5  MOV qword ptr [RDX + 0x8],RAX
0x1400cd6e9  INC dword ptr [R8 + 0x210]
0x1400cd6f0  CMP R9D,dword ptr [R8 + 0x198]
0x1400cd6f7  JC 0x1400cd6c0
0x1400cd6f9  MOVZX EAX,byte ptr [RBP + 0xa8825]
0x1400cd700  MOV byte ptr [0x14033d9d1],AL
0x1400cd706  MOV qword ptr [0x14033d9d8],RBP
0x1400cd70d  CALL 0x140019ef0
0x1400cd712  MOV R9D,R13D
0x1400cd715  MOV qword ptr [RAX + 0x428],RBP
0x1400cd71c  CMP byte ptr [RBP + 0x697ec],0x0
0x1400cd723  JBE 0x1400cd788
0x1400cd725  MOV R11,qword ptr [RBP + 0x697b8]
0x1400cd72c  MOV R10,R13
0x1400cd72f  MOV EBX,0x208
0x1400cd734  MOV RAX,qword ptr [R11 + R10*0x1]
0x1400cd738  MOV EDX,R13D
0x1400cd73b  MOV ECX,dword ptr [RAX + 0x118]
0x1400cd741  TEST ECX,ECX
0x1400cd743  JLE 0x1400cd775
0x1400cd745  MOV RAX,qword ptr [RAX + 0x110]
0x1400cd74c  ADD RAX,0x1a0
0x1400cd752  MOV R8,qword ptr [RAX]
0x1400cd755  TEST R8,R8
0x1400cd758  JZ 0x1400cd769
0x1400cd75a  MOV R8,qword ptr [R8]
0x1400cd75d  TEST R8,R8
0x1400cd760  JZ 0x1400cd769
0x1400cd762  CMP word ptr [R8 + 0x6c],BX
0x1400cd767  JZ 0x1400cd7b2
0x1400cd769  INC EDX
0x1400cd76b  ADD RAX,0x520
0x1400cd771  CMP EDX,ECX
0x1400cd773  JL 0x1400cd752
0x1400cd775  MOVZX EAX,byte ptr [RBP + 0x697ec]
0x1400cd77c  INC R9D
0x1400cd77f  ADD R10,0x8
0x1400cd783  CMP R9D,EAX
0x1400cd786  JL 0x1400cd734
0x1400cd788  MOV qword ptr [RBP + 0xa8310],R13
0x1400cd78f  LEA R11,[RSP + 0x40]
0x1400cd794  MOV EAX,0x1
0x1400cd799  MOV RBX,qword ptr [R11 + 0x38]
0x1400cd79d  MOV RBP,qword ptr [R11 + 0x40]
0x1400cd7a1  MOV RSI,qword ptr [R11 + 0x48]
0x1400cd7a5  MOV RSP,R11
0x1400cd7a8  POP R15
0x1400cd7aa  POP R14
0x1400cd7ac  POP R13
0x1400cd7ae  POP R12
0x1400cd7b0  POP RDI
0x1400cd7b1  RET
0x1400cd7b2  MOV RCX,qword ptr [0x14032c8f8]
0x1400cd7b9  MOV EDX,0x34
0x1400cd7be  MOV R8D,0x10
0x1400cd7c4  CALL 0x140200de0
0x1400cd7c9  MOV qword ptr [RAX + 0x28],0x0
0x1400cd7d1  MOV word ptr [RAX + 0x32],0x12c
0x1400cd7d7  MOV dword ptr [RAX + 0x24],R13D
0x1400cd7db  MOV qword ptr [RBP + 0xa8310],RAX
0x1400cd7e2  JMP 0x1400cd78f
