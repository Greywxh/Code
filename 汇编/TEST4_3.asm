DATA  SEGMENT
      CHANGELINE DB 13,10,'$'
      INF1 DB "Please input a number(1-361):$",0AH,0DH
      IBUF DB 7,0,6 DUP(?)
      OBUF DB 6 DUP(?)
DATA  ENDS

CODE  SEGMENT
      ASSUME CS:CODE,DS:DATA
START:MOV AX,DATA
      MOV DS,AX
      ;接收一个十进制数
      MOV DX, OFFSET INF1
      MOV AH, 09H
      INT 21H
      MOV DX, OFFSET IBUF
      MOV AH, 0AH
      INT 21H

      MOV CL,IBUF+1 ;十进制数的位数送CX,参考10号功能中字符串结构
      MOV CH,0  ;指向输入的第一个字符(最高位)
      MOV SI,OFFSET IBUF+2 ; 开始将十进制数转换为二进制数
      MOV AX, 0

AGAIN:MOV DX, 10
      MUL DX
      AND BYTE PTR [SI], 0FH
      ADD AL,[SI]
      ADC AH,0
      INC SI
      LOOP AGAIN

      MOV CX,AX
      MOV AX,0 
      MOV BX,1

      LOOP2: ADD AX,BX
      	   INC BX
      	   LOOP LOOP2
             MOV BX, OFFSET OBUF+5

      MOV BYTE PTR[BX],'$'
      MOV CX,10
LOOP1:MOV DX,0
      DIV CX
      DEC BX
      ADD DL,30H
      MOV [BX], DL
      OR AX,AX
      JNZ  LOOP1

      MOV DX,OFFSET CHANGELINE
      MOV AH,09H
      INT 21H
      
      MOV DX, BX
      MOV AH, 09H
      INT 21H
      MOV AH, 4CH
      INT 21H
CODE ENDS
END START