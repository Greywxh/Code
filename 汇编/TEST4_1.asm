DATA   SEGMENT
       INF1 DB "Please input a number(0-65535):$" 
       IBUF DB 7,0,6 DUP(?)
DATA   ENDS
CODE   SEGMENT
ASSUME CS:CODE, DS:DATA
START: MOV AX, DATA
       MOV DS,AX
       MOV DX, OFFSET INF1
       MOV AH, 09H
       INT 21H

       MOV DX, OFFSET IBUF ;input a decimal number(<65535)
       MOV AH, 0AH
       INT 21H
       MOV CL,IBUF+1 ;十进制数的位数送CX,参考10号功能中字符串结构
       MOV CH,0  ;指向输入的第一个字符(最高位)
       MOV SI,OFFSET IBUF+2 ; 开始将十进制数转换为二进制数
       MOV AX, 0

AGAIN: MOV DX, 10  ; ((0×10+a4) ×10+...)×10+a0
       MUL DX
       AND BYTE PTR [SI], 0FH
       ADD AL,[SI]
       ADC AH,0
       INC SI
       LOOP AGAIN
       MOV AH, 4CH
       INT 21H
CODE   ENDS
END    START