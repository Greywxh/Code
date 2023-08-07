DATA   SEGMENT
       OBUF DB 6 DUP(?)    
DATA   ENDS
CODE   SEGMENT
ASSUME CS: CODE, DS: DATA
START: MOV AX, DATA
       MOV DS,AX 
       ;MOV AX,0FH
       MOV BX, OFFSET OBUF+5
       MOV BYTE PTR [BX],'$'
       MOV CX,10
LOOP1: 
       MOV DX,0
       DIV CX
       DEC BX
       ADD DL,30H
       MOV [BX], DL
       OR AX,AX
       JNZ  LOOP1
       MOV DX, BX
       MOV AH, 09H
       INT 21H
       MOV AH, 4CH
       INT 21H
CODE ENDS
END START