0x1400cd880  MOV R11,RSP
0x1400cd883  PUSH RBP
0x1400cd884  PUSH RSI
0x1400cd885  LEA RBP,[R11 + -0x138]
0x1400cd88c  SUB RSP,0x228
0x1400cd893  MOV RAX,qword ptr [0x140309040]
0x1400cd89a  XOR RAX,RSP
0x1400cd89d  MOV qword ptr [RBP + 0xe0],RAX
0x1400cd8a4  MOV qword ptr [R11 + 0x10],RBX
0x1400cd8a8  LEA RDX,[RCX + 0x69798]
0x1400cd8af  MOV qword ptr [R11 + 0x18],RDI
0x1400cd8b3  MOV RSI,RCX
0x1400cd8b6  XOR EDI,EDI
0x1400cd8b8  MOV qword ptr [R11 + 0x20],R12
0x1400cd8bc  MOV dword ptr [RCX + 0xa878c],EDI
0x1400cd8c2  MOV word ptr [RDX],DI
0x1400cd8c5  MOV qword ptr [RCX + 0x6979a],RDI
0x1400cd8cc  MOV qword ptr [RCX + 0x697a2],RDI
0x1400cd8d3  MOV qword ptr [RCX + 0x697aa],RDI
0x1400cd8da  MOV dword ptr [RCX + 0x697b2],EDI
0x1400cd8e0  MOV word ptr [RCX + 0x697b6],DI
0x1400cd8e7  MOV RAX,qword ptr [RCX + 0xa8318]
0x1400cd8ee  MOV qword ptr [R11 + -0x20],R14
0x1400cd8f2  MOV qword ptr [R11 + -0x28],R15
0x1400cd8f6  MOV qword ptr [RAX + 0x8],RDX
0x1400cd8fa  MOV RAX,qword ptr [RCX + 0xa8280]
0x1400cd901  MOV RBX,qword ptr [RCX + 0xa8318]
0x1400cd908  MOV RCX,qword ptr [RAX + 0x18]
0x1400cd90c  TEST RCX,RCX
0x1400cd90f  JZ 0x1400cd983
0x1400cd911  MOV qword ptr [RBX],RCX
0x1400cd914  XOR R8D,R8D
0x1400cd917  MOV byte ptr [RBX + 0x20],DIL
0x1400cd91b  MOV RDI,qword ptr [RCX + 0x8]
0x1400cd91f  MOV RCX,qword ptr [RBX + 0x10]
0x1400cd923  MOV RDX,qword ptr [RDI + 0x10]
0x1400cd927  CALL 0x1400f5af0
0x1400cd92c  MOV RDX,qword ptr [RBX + 0x8]
0x1400cd930  TEST RDX,RDX
0x1400cd933  JZ 0x1400cd981
0x1400cd935  MOV R8,qword ptr [RDI + 0x8]
0x1400cd939  TEST R8,R8
0x1400cd93c  JZ 0x1400cd981
0x1400cd93e  MOV R8,qword ptr [R8]
0x1400cd941  LEA RCX,[RDX + 0x1e]
0x1400cd945  LEA RAX,[R8 + 0x1e]
0x1400cd949  CMP RDX,RAX
0x1400cd94c  JA 0x1400cd978
0x1400cd94e  CMP RCX,R8
0x1400cd951  JC 0x1400cd978
0x1400cd953  XOR EDI,EDI
0x1400cd955  SUB R8,RDX
0x1400cd958  LEA RCX,[RDX + RDI*0x2]
0x1400cd95c  MOV EDX,0x10
0x1400cd961  SUB RDX,RDI
0x1400cd964  MOVZX EAX,word ptr [RCX + R8*0x1]
0x1400cd969  MOV word ptr [RCX],AX
0x1400cd96c  LEA RCX,[RCX + 0x2]
0x1400cd970  SUB RDX,0x1
0x1400cd974  JNZ 0x1400cd964
0x1400cd976  JMP 0x1400cd983
0x1400cd978  VMOVUPS YMM0,ymmword ptr [R8]
0x1400cd97d  VMOVUPS ymmword ptr [RDX],YMM0
0x1400cd981  XOR EDI,EDI
0x1400cd983  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cd98a  MOV RCX,qword ptr [RAX + 0x10]
0x1400cd98e  TEST RCX,RCX
0x1400cd991  JZ 0x1400cd9a1
0x1400cd993  LEA RAX,[RSI + 0x69748]
0x1400cd99a  MOV qword ptr [RCX + 0x300],RAX
0x1400cd9a1  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cd9a8  MOV RCX,qword ptr [RAX + 0x10]
0x1400cd9ac  TEST RCX,RCX
0x1400cd9af  JZ 0x1400cd9bf
0x1400cd9b1  LEA RAX,[RSI + 0x697b8]
0x1400cd9b8  MOV qword ptr [RCX + 0x2f8],RAX
0x1400cd9bf  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cd9c6  MOV RDX,qword ptr [RSI + 0xa82a8]
0x1400cd9cd  MOV RCX,qword ptr [RAX + 0x10]
0x1400cd9d1  TEST RCX,RCX
0x1400cd9d4  JZ 0x1400cd9dd
0x1400cd9d6  MOV qword ptr [RCX + 0x308],RDX
0x1400cd9dd  MOV RCX,qword ptr [RSI + 0xa8318]
0x1400cd9e4  MOV RDX,qword ptr [RCX + 0x10]
0x1400cd9e8  TEST RDX,RDX
0x1400cd9eb  JZ 0x1400cda02
0x1400cd9ed  LEA RAX,[RSI + 0x240]
0x1400cd9f4  MOV qword ptr [RDX + 0x338],RAX
0x1400cd9fb  MOV RCX,qword ptr [RSI + 0xa8318]
0x1400cda02  MOV RAX,qword ptr [RSI + 0xa82b0]
0x1400cda09  TEST RAX,RAX
0x1400cda0c  JZ 0x1400cda6c
0x1400cda0e  MOV RDX,qword ptr [RCX + 0x10]
0x1400cda12  TEST RDX,RDX
0x1400cda15  JZ 0x1400cda25
0x1400cda17  MOV qword ptr [RDX + 0x320],RAX
0x1400cda1e  MOV RCX,qword ptr [RSI + 0xa8318]
0x1400cda25  MOV RAX,qword ptr [RSI + 0xa82b0]
0x1400cda2c  MOV RDX,qword ptr [RAX + 0x10]
0x1400cda30  TEST RDX,RDX
0x1400cda33  JZ 0x1400cda4c
0x1400cda35  MOV RAX,qword ptr [RCX + 0x10]
0x1400cda39  TEST RAX,RAX
0x1400cda3c  JZ 0x1400cda4c
0x1400cda3e  MOV qword ptr [RAX + 0x310],RDX
0x1400cda45  MOV RCX,qword ptr [RSI + 0xa8318]
0x1400cda4c  MOV RAX,qword ptr [RSI + 0xa82b0]
0x1400cda53  MOV RDX,qword ptr [RAX + 0x18]
0x1400cda57  TEST RDX,RDX
0x1400cda5a  JZ 0x1400cda6c
0x1400cda5c  MOV RAX,qword ptr [RCX + 0x10]
0x1400cda60  TEST RAX,RAX
0x1400cda63  JZ 0x1400cda6c
0x1400cda65  MOV qword ptr [RAX + 0x318],RDX
0x1400cda6c  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cda73  MOV RDX,qword ptr [RSI + 0xa8270]
0x1400cda7a  MOV RCX,qword ptr [RAX + 0x10]
0x1400cda7e  TEST RCX,RCX
0x1400cda81  JZ 0x1400cda8a
0x1400cda83  MOV qword ptr [RCX + 0x328],RDX
0x1400cda8a  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cda91  MOVZX EDX,byte ptr [RSI + 0xa8825]
0x1400cda98  MOV RCX,qword ptr [RAX + 0x10]
0x1400cda9c  TEST RCX,RCX
0x1400cda9f  JZ 0x1400cdaa7
0x1400cdaa1  MOV byte ptr [RCX + 0x3d1],DL
0x1400cdaa7  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cdaae  MOVZX ECX,byte ptr [RSI + 0xa8795]
0x1400cdab5  MOV RDX,qword ptr [RAX + 0x10]
0x1400cdab9  MOV byte ptr [RAX + 0x22],CL
0x1400cdabc  TEST RDX,RDX
0x1400cdabf  JZ 0x1400cdac7
0x1400cdac1  MOV byte ptr [RDX + 0x3d6],CL
0x1400cdac7  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cdace  MOVZX EDX,byte ptr [RSI + 0xa8827]
0x1400cdad5  MOV RCX,qword ptr [RAX + 0x10]
0x1400cdad9  TEST RCX,RCX
0x1400cdadc  JZ 0x1400cdae4
0x1400cdade  MOV byte ptr [RCX + 0x3da],DL
0x1400cdae4  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cdaeb  MOVZX EDX,byte ptr [RSI + 0xa881d]
0x1400cdaf2  MOV RCX,qword ptr [RAX + 0x10]
0x1400cdaf6  TEST RCX,RCX
0x1400cdaf9  JZ 0x1400cdb01
0x1400cdafb  MOV byte ptr [RCX + 0x3db],DL
0x1400cdb01  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cdb08  MOV RCX,qword ptr [RAX + 0x10]
0x1400cdb0c  TEST RCX,RCX
0x1400cdb0f  JZ 0x1400cdb18
0x1400cdb11  MOV qword ptr [RCX + 0x340],RSI
0x1400cdb18  TEST dword ptr [RSI + 0xa8790],0x800000
0x1400cdb22  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cdb29  MOV RCX,qword ptr [RAX + 0x10]
0x1400cdb2d  JZ 0x1400cdb40
0x1400cdb2f  TEST RCX,RCX
0x1400cdb32  JZ 0x1400cdb4f
0x1400cdb34  OR dword ptr [RCX + 0x3a8],0x2000
0x1400cdb3e  JMP 0x1400cdb4f
0x1400cdb40  TEST RCX,RCX
0x1400cdb43  JZ 0x1400cdb4f
0x1400cdb45  AND dword ptr [RCX + 0x3a8],0xffffdfff
0x1400cdb4f  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400cdb56  MOV R14D,0xffffffff
0x1400cdb5c  MOV RCX,qword ptr [RAX + 0x10]
0x1400cdb60  MOV word ptr [RAX + 0x20],0x0
0x1400cdb66  MOV byte ptr [RAX + 0x23],0xff
0x1400cdb6a  TEST RCX,RCX
0x1400cdb6d  JZ 0x1400cdbd5
0x1400cdb6f  MOV qword ptr [RCX + 0x3b0],RDI
0x1400cdb76  MOV byte ptr [RCX + 0x3d7],0xff
0x1400cdb7d  MOV word ptr [RCX + 0x3c0],R14W
0x1400cdb85  MOV dword ptr [RCX + 0x3dc],0xffff0000
0x1400cdb8f  MOV word ptr [RCX + 0x3e9],0x4
0x1400cdb98  MOV qword ptr [RCX + 0x3a0],0x3f800000
0x1400cdba3  MOV qword ptr [RCX + 0x394],0x0
0x1400cdbae  MOV dword ptr [RCX + 0x2a0],0x80
0x1400cdbb8  MOV dword ptr [RCX + 0x3e0],0x6464ffff
0x1400cdbc2  MOV dword ptr [RCX + 0x3ac],EDI
0x1400cdbc8  MOV byte ptr [RCX + 0x3c8],0x0
0x1400cdbcf  MOV dword ptr [RCX + 0x3c4],EDI
0x1400cdbd5  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400cdbdc  MOVZX ECX,byte ptr [RSI + 0x697ec]
0x1400cdbe3  MOV R8,qword ptr [RSI + 0xa8318]
0x1400cdbea  LEA RDX,[RAX + RCX*0x8]
0x1400cdbee  CMP RAX,RDX
0x1400cdbf1  JZ 0x1400cdc6f
0x1400cdbf3  MOV R11,qword ptr [RAX]
0x1400cdbf6  MOV R9D,EDI
0x1400cdbf9  MOV qword ptr [R11 + 0xd0],R8
0x1400cdc00  CMP dword ptr [R11 + 0x118],0x0
0x1400cdc08  JLE 0x1400cdc51
0x1400cdc0a  MOV RCX,RDI
0x1400cdc0d  MOV RDX,qword ptr [R11 + 0x110]
0x1400cdc14  MOV R10,qword ptr [RDX + RCX*0x1 + 0x8]
0x1400cdc19  MOV qword ptr [RDX + RCX*0x1 + 0x1c8],R8
0x1400cdc21  TEST R10,R10
0x1400cdc24  JZ 0x1400cdc2d
0x1400cdc26  MOV qword ptr [R10 + 0x88],R8
0x1400cdc2d  MOV R10,qword ptr [RDX + RCX*0x1 + 0x10]
0x1400cdc32  TEST R10,R10
0x1400cdc35  JZ 0x1400cdc3e
0x1400cdc37  MOV qword ptr [R10 + 0x88],R8
0x1400cdc3e  INC R9D
0x1400cdc41  ADD RCX,0x520
0x1400cdc48  CMP R9D,dword ptr [R11 + 0x118]
0x1400cdc4f  JL 0x1400cdc0d
0x1400cdc51  MOV R9,qword ptr [RSI + 0x697b8]
0x1400cdc58  ADD RAX,0x8
0x1400cdc5c  MOVZX ECX,byte ptr [RSI + 0x697ec]
0x1400cdc63  LEA RDX,[R9 + RCX*0x8]
0x1400cdc67  CMP RAX,RDX
0x1400cdc6a  JNZ 0x1400cdbf3
0x1400cdc6c  MOV RAX,R9
0x1400cdc6f  MOV RCX,qword ptr [RSI + 0xa8308]
0x1400cdc76  MOVZX R10D,byte ptr [RSI + 0xa881d]
0x1400cdc7e  MOV qword ptr [RSI + 0x697e0],RCX
0x1400cdc85  MOVZX ECX,byte ptr [RSI + 0x697ec]
0x1400cdc8c  LEA RDX,[RAX + RCX*0x8]
0x1400cdc90  CMP RAX,RDX
0x1400cdc93  JZ 0x1400cdcfd
0x1400cdc95  MOV R9,qword ptr [RAX]
0x1400cdc98  MOV R8D,EDI
0x1400cdc9b  MOV byte ptr [R9 + 0x100],R10B
0x1400cdca2  CMP dword ptr [R9 + 0x118],0x0
0x1400cdcaa  JLE 0x1400cdce2
0x1400cdcac  MOV RDX,RDI
0x1400cdcaf  NOP word ptr [RAX + RAX*0x1]
0x1400cdcbe  NOP
0x1400cdcc0  MOV RCX,qword ptr [R9 + 0x110]
0x1400cdcc7  LEA RDX,[RDX + 0x520]
0x1400cdcce  INC R8D
0x1400cdcd1  MOV byte ptr [RDX + RCX*0x1 + -0x2d4],R10B
0x1400cdcd9  CMP R8D,dword ptr [R9 + 0x118]
0x1400cdce0  JL 0x1400cdcc0
0x1400cdce2  MOVZX EDX,byte ptr [RSI + 0x697ec]
0x1400cdce9  ADD RAX,0x8
0x1400cdced  MOV RCX,qword ptr [RSI + 0x697b8]
0x1400cdcf4  LEA RDX,[RCX + RDX*0x8]
0x1400cdcf8  CMP RAX,RDX
0x1400cdcfb  JNZ 0x1400cdc95
0x1400cdcfd  LEA RCX,[RSI + 0x69748]
0x1400cdd04  VZEROUPPER
0x1400cdd07  CALL 0x1400a98c0
0x1400cdd0c  MOV RCX,qword ptr [RSI + 0x67148]
0x1400cdd13  CMP dword ptr [RCX + 0x38],0x0
0x1400cdd17  JZ 0x1400cdd1e
0x1400cdd19  CALL 0x14007f380
0x1400cdd1e  MOV RCX,qword ptr [RSI + 0x67130]
0x1400cdd25  MOV qword ptr [RSP + 0x220],R13
0x1400cdd2d  CALL 0x14007fbe0
0x1400cdd32  LEA RCX,[RSI + 0x697b8]
0x1400cdd39  CALL 0x140136040
0x1400cdd3e  MOV EDX,dword ptr [RSI + 0xa8790]
0x1400cdd44  LEA RCX,[RSI + 0x697b8]
0x1400cdd4b  SHR EDX,0x17
0x1400cdd4e  AND DL,0x1
0x1400cdd51  CALL 0x1400c3680
0x1400cdd56  MOV RAX,qword ptr [RSI + 0x67130]
0x1400cdd5d  MOV RBX,qword ptr [RSI + 0x697b8]
0x1400cdd64  MOV RCX,qword ptr [RAX]
0x1400cdd67  MOVZX EAX,byte ptr [RSI + 0x697ec]
0x1400cdd6e  TEST byte ptr [RCX + 0x10],0x2
0x1400cdd72  LEA RCX,[RBX + RAX*0x8]
0x1400cdd76  JZ 0x1400cddf6
0x1400cdd78  CMP RBX,RCX
0x1400cdd7b  JZ 0x1400cde74
0x1400cdd81  MOV R13,qword ptr [RBX]
0x1400cdd84  MOV R14D,EDI
0x1400cdd87  CMP dword ptr [R13 + 0x118],0x0
0x1400cdd8f  JLE 0x1400cddd9
0x1400cdd91  MOV R15,qword ptr [R13 + 0x110]
0x1400cdd98  MOV RCX,qword ptr [RDI + R15*0x1 + 0x390]
0x1400cdda0  TEST RCX,RCX
0x1400cdda3  JZ 0x1400cddae
0x1400cdda5  MOV RAX,qword ptr [RCX]
0x1400cdda8  CALL qword ptr [RAX + 0x1d0]
0x1400cddae  MOV RCX,qword ptr [RDI + R15*0x1 + 0x398]
0x1400cddb6  TEST RCX,RCX
0x1400cddb9  JZ 0x1400cddc4
0x1400cddbb  MOV RAX,qword ptr [RCX]
0x1400cddbe  CALL qword ptr [RAX + 0x1d0]
0x1400cddc4  INC R14D
0x1400cddc7  ADD RDI,0x520
0x1400cddce  CMP R14D,dword ptr [R13 + 0x118]
0x1400cddd5  JL 0x1400cdd91
0x1400cddd7  XOR EDI,EDI
0x1400cddd9  MOVZX ECX,byte ptr [RSI + 0x697ec]
0x1400cdde0  ADD RBX,0x8
0x1400cdde4  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400cddeb  LEA RCX,[RAX + RCX*0x8]
0x1400cddef  CMP RBX,RCX
0x1400cddf2  JNZ 0x1400cdd81
0x1400cddf4  JMP 0x1400cde6e
0x1400cddf6  CMP RBX,RCX
0x1400cddf9  JZ 0x1400cde74
0x1400cddfb  MOV R13,qword ptr [RBX]
0x1400cddfe  MOV R14D,EDI
0x1400cde01  CMP dword ptr [R13 + 0x118],0x0
0x1400cde09  JLE 0x1400cde53
0x1400cde0b  MOV R15,qword ptr [R13 + 0x110]
0x1400cde12  MOV RCX,qword ptr [RDI + R15*0x1 + 0x390]
0x1400cde1a  TEST RCX,RCX
0x1400cde1d  JZ 0x1400cde28
0x1400cde1f  MOV RAX,qword ptr [RCX]
0x1400cde22  CALL qword ptr [RAX + 0x1d8]
0x1400cde28  MOV RCX,qword ptr [RDI + R15*0x1 + 0x398]
0x1400cde30  TEST RCX,RCX
0x1400cde33  JZ 0x1400cde3e
0x1400cde35  MOV RAX,qword ptr [RCX]
0x1400cde38  CALL qword ptr [RAX + 0x1d8]
0x1400cde3e  INC R14D
0x1400cde41  ADD RDI,0x520
0x1400cde48  CMP R14D,dword ptr [R13 + 0x118]
0x1400cde4f  JL 0x1400cde0b
0x1400cde51  XOR EDI,EDI
0x1400cde53  MOVZX ECX,byte ptr [RSI + 0x697ec]
0x1400cde5a  ADD RBX,0x8
0x1400cde5e  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400cde65  LEA RCX,[RAX + RCX*0x8]
0x1400cde69  CMP RBX,RCX
0x1400cde6c  JNZ 0x1400cddfb
0x1400cde6e  MOV R14D,0xffffffff
0x1400cde74  CALL 0x140019ef0
0x1400cde79  MOV RCX,RAX
0x1400cde7c  CALL 0x140019f80
0x1400cde81  MOV dword ptr [RSI + 0x6a818],EDI
0x1400cde87  LEA RCX,[RSI + 0x6bc40]
0x1400cde8e  MOV dword ptr [RSI + 0x6a820],R14D
0x1400cde95  MOV word ptr [RSI + 0x6a824],DI
0x1400cde9c  MOV dword ptr [RSI + 0x6b508],EDI
0x1400cdea2  MOV dword ptr [RSI + 0x6b510],EDI
0x1400cdea8  MOV qword ptr [RSI + 0x6b514],-0x1
0x1400cdeb3  MOV word ptr [RSI + 0x6b51c],R14W
0x1400cdebb  CALL 0x140140b50
0x1400cdec0  MOV byte ptr [RSI + 0x89ec0],0x0
0x1400cdec7  MOV RDX,qword ptr [RSI + 0xa8240]
0x1400cdece  MOV RCX,qword ptr [RSI + 0xa8298]
0x1400cded5  CALL 0x140014960
0x1400cdeda  MOV RDX,qword ptr [RSI + 0xa8240]
0x1400cdee1  LEA RCX,[RSI + 0x69ab0]
0x1400cdee8  CALL 0x140014960
0x1400cdeed  MOV RDX,qword ptr [RSI + 0xa8240]
0x1400cdef4  LEA RCX,[RSI + 0x69c70]
0x1400cdefb  CALL 0x140014960
0x1400cdf00  MOV RCX,qword ptr [RSI + 0xa82a8]
0x1400cdf07  TEST RCX,RCX
0x1400cdf0a  JZ 0x1400cdf30
0x1400cdf0c  CALL 0x1401a5fc0
0x1400cdf11  MOV RCX,qword ptr [RSI + 0xa82b0]
0x1400cdf18  TEST RCX,RCX
0x1400cdf1b  JZ 0x1400cdf30
0x1400cdf1d  MOV R8,qword ptr [RSI + 0xa82a8]
0x1400cdf24  LEA RDX,[RSI + 0x697b8]
0x1400cdf2b  CALL 0x1401a8b40
0x1400cdf30  CMP byte ptr [RSI + 0xa87e4],0x0
0x1400cdf37  MOV R14D,EDI
0x1400cdf3a  MOV dword ptr [0x14032c480],EDI
0x1400cdf40  JBE 0x1400cdf9e
0x1400cdf42  XOR EDX,EDX
0x1400cdf44  MOV R15D,EDX
0x1400cdf47  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400cdf4e  MOV RBX,qword ptr [RSI + 0xa8248]
0x1400cdf55  MOV RCX,qword ptr [RAX + R15*0x1]
0x1400cdf59  MOV RAX,qword ptr [RCX + 0x110]
0x1400cdf60  OR dword ptr [RAX + 0x1f0],0x1
0x1400cdf67  MOV RCX,qword ptr [RDI + RBX*0x1 + 0x1fa8]
0x1400cdf6f  MOV RAX,qword ptr [RCX]
0x1400cdf72  CALL qword ptr [RAX + 0x8]
0x1400cdf75  LEA RCX,[RDI + RBX*0x1 + 0x1868]
0x1400cdf7d  CALL 0x1400b95a0
0x1400cdf82  MOVZX EAX,byte ptr [RSI + 0xa87e4]
0x1400cdf89  LEA R15,[R15 + 0x8]
0x1400cdf8d  INC R14D
0x1400cdf90  LEA RDI,[RDI + 0x27a0]
0x1400cdf97  CMP R14D,EAX
0x1400cdf9a  JL 0x1400cdf47
0x1400cdf9c  XOR EDI,EDI
0x1400cdf9e  LEA RCX,[RSI + 0x697b8]
0x1400cdfa5  CALL 0x140138120
0x1400cdfaa  MOV RAX,qword ptr GS:[0x58]
0x1400cdfb3  MOV EDX,0x4
0x1400cdfb8  MOV RCX,qword ptr [RAX]
0x1400cdfbb  MOV EAX,dword ptr [RDX + RCX*0x1]
0x1400cdfbe  CMP dword ptr [0x1437dad18],EAX
0x1400cdfc4  JG 0x1400ce6b2
0x1400cdfca  LEA RCX,[0x1437daee0]
0x1400cdfd1  CALL 0x1401c5740
0x1400cdfd6  CALL 0x140189320
0x1400cdfdb  CMP qword ptr [RSI + 0xa82a8],0x0
0x1400cdfe3  VMOVD XMM1,EDI
0x1400cdfe7  VXORPS XMM2,XMM2,XMM2
0x1400cdfeb  MOVZX EAX,byte ptr [RAX + 0x28]
0x1400cdfef  VMOVD XMM0,EAX
0x1400cdff3  VPCMPEQD XMM3,XMM0,XMM1
0x1400cdff7  VMOVSS XMM0,dword ptr [0x1402d1f90]
0x1400cdfff  VBLENDVPS XMM0,XMM0,XMM2,XMM3
0x1400ce005  VMOVSS dword ptr [0x140328448],XMM0
0x1400ce00d  JZ 0x1400ce030
0x1400ce00f  CALL 0x140189320
0x1400ce014  MOV RDX,qword ptr [RSI + 0xa82a8]
0x1400ce01b  CMP byte ptr [RAX + 0x28],0x0
0x1400ce01f  MOVZX ECX,byte ptr [RDX + 0x52]
0x1400ce023  JZ 0x1400ce02a
0x1400ce025  OR CL,0x4
0x1400ce028  JMP 0x1400ce02d
0x1400ce02a  AND CL,0xfb
0x1400ce02d  MOV byte ptr [RDX + 0x52],CL
0x1400ce030  CMP byte ptr [RSI + 0xa87e4],0x0
0x1400ce037  MOV R15D,EDI
0x1400ce03a  MOV RAX,qword ptr [RSI + 0x67130]
0x1400ce041  MOV RCX,qword ptr [RAX + 0x1380]
0x1400ce048  MOV qword ptr [0x140328440],RCX
0x1400ce04f  JBE 0x1400ce499
0x1400ce055  VMOVAPS xmmword ptr [RSP + 0x200],XMM6
0x1400ce05e  VMOVAPS xmmword ptr [RSP + 0x1f0],XMM7
0x1400ce067  LEA R12,[RSI + 0x240]
0x1400ce06e  LEA R13,[RSI + 0x6a130]
0x1400ce075  LEA RCX,[RSP + 0x20]
0x1400ce07a  CALL 0x140004e80
0x1400ce07f  OR dword ptr [RBP + 0xc0],0x3
0x1400ce086  LEA RCX,[RSP + 0x20]
0x1400ce08b  MOV dword ptr [RBP + 0xd0],0x15000000
0x1400ce095  MOV word ptr [RBP + 0xd4],0x100
0x1400ce09e  CALL 0x1401fbec0
0x1400ce0a3  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400ce0aa  MOV R10,qword ptr [RSI + 0xa8240]
0x1400ce0b1  MOVZX R8D,byte ptr [RSI + 0xa87e4]
0x1400ce0b9  MOVSXD RDX,R15D
0x1400ce0bc  IMUL R14,RDX,0x27a0
0x1400ce0c3  MOV RCX,qword ptr [RAX + RDX*0x8]
0x1400ce0c7  MOV RDX,R10
0x1400ce0ca  ADD R14,qword ptr [RSI + 0xa8248]
0x1400ce0d1  MOV RBX,qword ptr [RCX + 0x110]
0x1400ce0d8  LEA RCX,[RSP + 0x20]
0x1400ce0dd  CALL 0x140014960
0x1400ce0e2  MOVSX EAX,word ptr [R10 + 0x28]
0x1400ce0e7  MOVZX ECX,word ptr [R10 + 0x2a]
0x1400ce0ec  CDQ
0x1400ce0ed  VMOVSS XMM1,dword ptr [R10 + 0x20]
0x1400ce0f3  VMOVSS XMM0,dword ptr [R10 + 0x1c]
0x1400ce0f9  VMOVUPS XMM2,xmmword ptr [R10 + 0x4]
0x1400ce0ff  VMOVSS XMM3,dword ptr [RBX + 0x264]
0x1400ce107  VMOVSS XMM4,dword ptr [RBX + 0x268]
0x1400ce10f  VMOVSS XMM5,dword ptr [RBX + 0x26c]
0x1400ce117  VMOVSS XMM6,dword ptr [RBX + 0x270]
0x1400ce11f  VMOVSS XMM7,dword ptr [RBX + 0x274]
0x1400ce127  IDIV R8D
0x1400ce12a  VMOVSS dword ptr [RSP + 0x40],XMM1
0x1400ce130  MOV word ptr [RSP + 0x48],AX
0x1400ce135  CWDE
0x1400ce136  VXORPS XMM1,XMM1,XMM1
0x1400ce13a  MOV word ptr [RSP + 0x4a],CX
0x1400ce13f  VCVTSI2SS XMM1,XMM1,R8D
0x1400ce144  VMOVSS dword ptr [RSP + 0x3c],XMM0
0x1400ce14a  VMOVSS XMM0,dword ptr [R10]
0x1400ce14f  VDIVSS XMM1,XMM0,XMM1
0x1400ce153  VMOVSS XMM0,dword ptr [RBX + 0x258]
0x1400ce15b  VMOVSS dword ptr [RSP + 0x20],XMM1
0x1400ce161  VMOVSS XMM1,dword ptr [R10 + 0x2c]
0x1400ce167  MOVZX EDI,R15B
0x1400ce16b  MOV ECX,EDI
0x1400ce16d  IMUL ECX,EAX
0x1400ce170  MOVZX EAX,word ptr [R10 + 0x26]
0x1400ce175  MOV word ptr [RSP + 0x46],AX
0x1400ce17a  MOVZX EAX,word ptr [R10 + 0x14]
0x1400ce17f  MOV word ptr [RSP + 0x34],AX
0x1400ce184  MOVZX EAX,word ptr [R10 + 0x16]
0x1400ce189  ADD CX,word ptr [R10 + 0x24]
0x1400ce18e  MOV word ptr [RSP + 0x36],AX
0x1400ce193  MOVZX EAX,word ptr [R10 + 0x18]
0x1400ce198  MOV word ptr [RSP + 0x38],AX
0x1400ce19d  MOVZX EAX,word ptr [R10 + 0x1a]
0x1400ce1a2  VMOVSS dword ptr [RSP + 0x4c],XMM1
0x1400ce1a8  VMOVSS XMM1,dword ptr [RBX + 0x260]
0x1400ce1b0  VMOVUPS xmmword ptr [RSP + 0x24],XMM2
0x1400ce1b6  VMOVSS XMM2,dword ptr [RBX + 0x25c]
0x1400ce1be  VMOVSS dword ptr [R14 + 0x10e0],XMM0
0x1400ce1c7  VMOVSS dword ptr [R14 + 0x10e4],XMM2
0x1400ce1d0  VMOVSS dword ptr [R14 + 0x10e8],XMM1
0x1400ce1d9  VMOVSS dword ptr [R14 + 0x10ec],XMM3
0x1400ce1e2  VMOVSS dword ptr [R14 + 0x10f0],XMM4
0x1400ce1eb  VMOVSS dword ptr [R14 + 0x10f4],XMM5
0x1400ce1f4  VMOVSS dword ptr [R14 + 0x10f8],XMM6
0x1400ce1fd  VMOVSS dword ptr [R14 + 0x10fc],XMM7
0x1400ce206  MOV dword ptr [R14 + 0x12ac],0x3f800000
0x1400ce211  MOV word ptr [RSP + 0x3a],AX
0x1400ce216  XOR EAX,EAX
0x1400ce218  MOV qword ptr [R14 + 0x12a0],RAX
0x1400ce21f  MOV dword ptr [R14 + 0x12a8],EAX
0x1400ce226  VMOVSS dword ptr [R14 + 0x12b0],XMM4
0x1400ce22f  VMOVSS dword ptr [R14 + 0x12b4],XMM5
0x1400ce238  VMOVSS dword ptr [R14 + 0x12b8],XMM6
0x1400ce241  VMOVSS dword ptr [R14 + 0x12bc],XMM7
0x1400ce24a  VMOVSS dword ptr [R14 + 0x70],XMM0
0x1400ce250  VMOVSS dword ptr [R14 + 0x74],XMM2
0x1400ce256  VMOVSS dword ptr [R14 + 0x78],XMM1
0x1400ce25c  VMOVSS dword ptr [R14 + 0x7c],XMM3
0x1400ce262  MOV word ptr [RSP + 0x44],CX
0x1400ce267  VMOVSS dword ptr [R14 + 0x80],XMM4
0x1400ce270  VMOVSS dword ptr [R14 + 0x84],XMM5
0x1400ce279  VMOVSS dword ptr [R14 + 0x88],XMM6
0x1400ce282  VMOVSS dword ptr [R14 + 0x8c],XMM7
0x1400ce28b  LEA RCX,[R14 + 0x10b0]
0x1400ce292  LEA RDX,[RSP + 0x20]
0x1400ce297  VMOVSS dword ptr [R14 + 0x17f8],XMM0
0x1400ce2a0  VMOVSS dword ptr [R14 + 0x17fc],XMM2
0x1400ce2a9  VMOVSS dword ptr [R14 + 0x1800],XMM1
0x1400ce2b2  VMOVSS dword ptr [R14 + 0x1804],XMM3
0x1400ce2bb  VMOVSS dword ptr [R14 + 0x1808],XMM4
0x1400ce2c4  VMOVSS dword ptr [R14 + 0x180c],XMM5
0x1400ce2cd  VMOVSS dword ptr [R14 + 0x1810],XMM6
0x1400ce2d6  VMOVSS dword ptr [R14 + 0x1814],XMM7
0x1400ce2df  CALL 0x140014960
0x1400ce2e4  OR dword ptr [RCX + 0x1a0],0x3
0x1400ce2eb  CALL 0x1401fbec0
0x1400ce2f0  LEA RCX,[R14 + 0x1270]
0x1400ce2f7  LEA RDX,[RSP + 0x20]
0x1400ce2fc  CALL 0x140014960
0x1400ce301  OR dword ptr [RCX + 0x1a0],0x3
0x1400ce308  CALL 0x1401fbec0
0x1400ce30d  MOV qword ptr [R14 + 0x1fc0],R12
0x1400ce314  MOV EDX,0x1676
0x1400ce319  MOV qword ptr [R14 + 0x1fc8],R13
0x1400ce320  CMP byte ptr [0x14031cf18],0x0
0x1400ce327  MOV EAX,dword ptr [0x140316e48]
0x1400ce32d  CMOVNZ EAX,dword ptr [0x14031ce00]
0x1400ce334  TEST EAX,EAX
0x1400ce336  SETZ AL
0x1400ce339  MOV byte ptr [R14 + 0x10a5],AL
0x1400ce340  MOV RAX,qword ptr [RSI + 0xa8298]
0x1400ce347  MOV qword ptr [R14 + 0x1fd0],RAX
0x1400ce34e  MOV RAX,qword ptr [RSI + 0xa82a0]
0x1400ce355  MOV qword ptr [R14 + 0x2050],RAX
0x1400ce35c  MOVZX ECX,byte ptr [RBX + 0x235]
0x1400ce363  MOVZX EAX,byte ptr [RBX + 0x234]
0x1400ce36a  MOV byte ptr [R14 + 0x20a2],CL
0x1400ce371  MOV byte ptr [R14 + 0x20a1],AL
0x1400ce378  MOV byte ptr [R14 + 0x1eeb],CL
0x1400ce37f  MOV byte ptr [R14 + 0x1eea],AL
0x1400ce386  MOV byte ptr [R14 + 0x1eca],CL
0x1400ce38d  MOV byte ptr [R14 + 0x1ec9],AL
0x1400ce394  MOV byte ptr [R14 + 0x1e52],CL
0x1400ce39b  MOV byte ptr [R14 + 0x1e51],AL
0x1400ce3a2  MOV byte ptr [R14 + 0x1e71],AL
0x1400ce3a9  MOV byte ptr [R14 + 0x1e72],CL
0x1400ce3b0  MOV byte ptr [R14 + 0x1e91],AL
0x1400ce3b7  MOV byte ptr [R14 + 0x1e92],CL
0x1400ce3be  MOV byte ptr [R14 + 0x1eb1],AL
0x1400ce3c5  MOV byte ptr [R14 + 0x1eb2],CL
0x1400ce3cc  MOV RCX,R14
0x1400ce3cf  MOV byte ptr [R14 + 0x20b3],DIL
0x1400ce3d6  TEST dword ptr [RSI + 0xa8790],0x100000
0x1400ce3e0  MOVZX EAX,byte ptr [R14 + 0x1676]
0x1400ce3e8  JZ 0x1400ce3ee
0x1400ce3ea  OR AL,0x20
0x1400ce3ec  JMP 0x1400ce3f0
0x1400ce3ee  AND AL,0xdf
0x1400ce3f0  MOV byte ptr [RDX + RCX*0x1],AL
0x1400ce3f3  MOV DL,0x1
0x1400ce3f5  LEA RCX,[R14 + 0x1868]
0x1400ce3fc  CALL 0x1400ae310
0x1400ce401  MOV RCX,qword ptr [R14 + 0x1888]
0x1400ce408  MOV RAX,qword ptr [RCX]
0x1400ce40b  CALL qword ptr [RAX + 0x40]
0x1400ce40e  MOV RCX,R14
0x1400ce411  CALL 0x140102ab0
0x1400ce416  CALL 0x140189320
0x1400ce41b  LEA RCX,[R14 + 0x1868]
0x1400ce422  CMP byte ptr [RAX + 0x28],0x0
0x1400ce426  JZ 0x1400ce439
0x1400ce428  MOV DL,0x1
0x1400ce42a  CALL 0x1400bab90
0x1400ce42f  OR byte ptr [R14 + 0x1da7],0x4
0x1400ce437  JMP 0x1400ce448
0x1400ce439  XOR EDX,EDX
0x1400ce43b  CALL 0x1400bab90
0x1400ce440  AND byte ptr [R14 + 0x1da7],0xfb
0x1400ce448  TEST dword ptr [RSI + 0xa8790],0x8000000
0x1400ce452  MOVZX EAX,word ptr [R14 + 0x1c20]
0x1400ce45a  JZ 0x1400ce466
0x1400ce45c  MOV ECX,0xff7f
0x1400ce461  AND AX,CX
0x1400ce464  JMP 0x1400ce46a
0x1400ce466  OR AX,0x80
0x1400ce46a  MOV ECX,0x1c20
0x1400ce46f  INC R15D
0x1400ce472  MOV word ptr [R14 + RCX*0x1],AX
0x1400ce477  MOVZX EAX,byte ptr [RSI + 0xa87e4]
0x1400ce47e  CMP R15D,EAX
0x1400ce481  JL 0x1400ce075
0x1400ce487  VMOVAPS XMM7,xmmword ptr [RSP + 0x1f0]
0x1400ce490  VMOVAPS XMM6,xmmword ptr [RSP + 0x200]
0x1400ce499  MOV RDX,qword ptr [RSI + 0xa8318]
0x1400ce4a0  MOV R15,qword ptr [RSP + 0x210]
0x1400ce4a8  MOV R14,qword ptr [RSP + 0x218]
0x1400ce4b0  MOV R13,qword ptr [RSP + 0x220]
0x1400ce4b8  MOV R12,qword ptr [RSP + 0x258]
0x1400ce4c0  TEST RDX,RDX
0x1400ce4c3  JZ 0x1400ce540
0x1400ce4c5  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400ce4cc  MOV R8,qword ptr [RSI + 0xa8248]
0x1400ce4d3  MOV RCX,qword ptr [RAX]
0x1400ce4d6  MOV RCX,qword ptr [RCX + 0x110]
0x1400ce4dd  TEST RCX,RCX
0x1400ce4e0  JZ 0x1400ce505
0x1400ce4e2  MOV RAX,qword ptr [RDX + 0x10]
0x1400ce4e6  MOVZX ECX,byte ptr [RCX + 0x428]
0x1400ce4ed  TEST RAX,RAX
0x1400ce4f0  JZ 0x1400ce505
0x1400ce4f2  MOV byte ptr [RAX + 0x3e2],CL
0x1400ce4f8  MOV byte ptr [RAX + 0x3e3],CL
0x1400ce4fe  MOV RDX,qword ptr [RSI + 0xa8318]
0x1400ce505  TEST R8,R8
0x1400ce508  JZ 0x1400ce540
0x1400ce50a  MOV RCX,qword ptr [RDX + 0x10]
0x1400ce50e  MOVZX R9D,byte ptr [R8 + 0x209a]
0x1400ce516  MOVZX R10D,byte ptr [R8 + 0x2099]
0x1400ce51e  TEST RCX,RCX
0x1400ce521  JZ 0x1400ce540
0x1400ce523  MOVZX EAX,word ptr [R8 + 0x208e]
0x1400ce52b  MOV word ptr [RCX + 0x3c2],AX
0x1400ce532  MOV byte ptr [RCX + 0x3e4],R10B
0x1400ce539  MOV byte ptr [RCX + 0x3e5],R9B
0x1400ce540  MOV RBX,qword ptr [RSI + 0xa8248]
0x1400ce547  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400ce54e  LEA RCX,[RBX + 0x10b0]
0x1400ce555  MOV RDI,qword ptr [RAX + 0x10]
0x1400ce559  CALL 0x1401fbec0
0x1400ce55e  LEA RCX,[RDI + 0xe0]
0x1400ce565  LEA RDX,[RBX + 0x10b0]
0x1400ce56c  CALL 0x140014960
0x1400ce571  OR dword ptr [RCX + 0x1a0],0x3
0x1400ce578  CALL 0x1401fbec0
0x1400ce57d  MOV RAX,qword ptr [RSI + 0xa8298]
0x1400ce584  XOR EDX,EDX
0x1400ce586  MOV RDI,qword ptr [RSP + 0x250]
0x1400ce58e  MOV RBX,qword ptr [RSP + 0x248]
0x1400ce596  VPXOR XMM0,XMM0,XMM0
0x1400ce59a  MOV qword ptr [RAX + 0x2a0],0x0
0x1400ce5a5  MOV dword ptr [RAX + 0x2a8],0xffff0000
0x1400ce5af  MOV word ptr [RAX + 0x2ac],0xffff
0x1400ce5b8  MOV dword ptr [RAX + 0x26c],0xffff
0x1400ce5c2  MOV qword ptr [RAX + 0x2b0],RDX
0x1400ce5c9  MOV byte ptr [RSI + 0xa8781],DL
0x1400ce5cf  MOV RAX,qword ptr [RSI + 0x697b8]
0x1400ce5d6  MOV RCX,qword ptr [RAX]
0x1400ce5d9  MOV RAX,qword ptr [RCX + 0x110]
0x1400ce5e0  OR dword ptr [RAX + 0x1f0],0x3
0x1400ce5e7  MOV RAX,qword ptr [RSI + 0x67120]
0x1400ce5ee  VMOVUPS ymmword ptr [RAX + 0x1bc48],YMM0
0x1400ce5f6  VMOVUPS ymmword ptr [RAX + 0x1bc68],YMM0
0x1400ce5fe  INC dword ptr [RAX + 0x1bc8c]
0x1400ce604  CMP dword ptr [RAX + 0x1bc8c],0xf
0x1400ce60b  MOV dword ptr [RAX + 0x1bc88],EDX
0x1400ce611  JL 0x1400ce619
0x1400ce613  MOV dword ptr [RAX + 0x1bc8c],EDX
0x1400ce619  CMP byte ptr [RSI + 0xa8822],0x7
0x1400ce620  JNZ 0x1400ce649
0x1400ce622  MOV RCX,qword ptr [RSI + 0xa8318]
0x1400ce629  MOVZX EDX,byte ptr [RCX + 0x20]
0x1400ce62d  INC DL
0x1400ce62f  VZEROUPPER
0x1400ce632  CALL 0x14012c0a0
0x1400ce637  MOV RAX,qword ptr [RSI + 0xa8318]
0x1400ce63e  MOV RCX,qword ptr [RAX + 0x10]
0x1400ce642  MOV byte ptr [RCX + 0x3ea],0x2
0x1400ce649  MOV RCX,qword ptr [RSI + 0x67158]
0x1400ce650  MOV RAX,qword ptr [RCX]
0x1400ce653  VZEROUPPER
0x1400ce656  CALL qword ptr [RAX + 0x60]
0x1400ce659  MOV byte ptr [0x14033bd60],0x0
0x1400ce660  MOV RCX,qword ptr [RSI + 0xa8310]
0x1400ce667  MOV byte ptr [0x140326f80],0x0
0x1400ce66e  TEST RCX,RCX
0x1400ce671  JZ 0x1400ce67b
0x1400ce673  MOV RDX,RSI
0x1400ce676  CALL 0x140113820
0x1400ce67b  AND dword ptr [RSI + 0xa8790],0xbfffffff
0x1400ce685  MOVZX EAX,byte ptr [RSI + 0xa87e4]
0x1400ce68c  MOV byte ptr [RSI + 0x697ef],AL
0x1400ce692  MOV byte ptr [RSI + 0xa8822],0x1
0x1400ce699  MOV RCX,qword ptr [RBP + 0xe0]
0x1400ce6a0  XOR RCX,RSP
0x1400ce6a3  CALL 0x14022d480
0x1400ce6a8  ADD RSP,0x228
0x1400ce6af  POP RSI
0x1400ce6b0  POP RBP
0x1400ce6b1  RET
0x1400ce6b2  LEA RCX,[0x1437dad18]
0x1400ce6b9  CALL 0x14022d540
0x1400ce6be  CMP dword ptr [0x1437dad18],-0x1
0x1400ce6c5  JNZ 0x1400cdfca
0x1400ce6cb  VMOVDQU XMM0,xmmword ptr [0x1402d3500]
0x1400ce6d3  LEA RCX,[0x1437dad18]
0x1400ce6da  MOV dword ptr [0x1437daef0],EDI
0x1400ce6e0  VMOVDQU xmmword ptr [0x1437daee0],XMM0
0x1400ce6e8  MOV byte ptr [0x1437daef4],0x0
0x1400ce6ef  CALL 0x14022d4d4
0x1400ce6f4  JMP 0x1400cdfca
