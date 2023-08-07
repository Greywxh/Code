DATA   SEGMENT
       INFOR1 DB 0AH,0DH, "Are you really want to exit?$"
       INFOR2 DB 0AH,0DH, "Thank you for your using!$"
       INFOR3 DB 0AH,0DH, "Let's continue!$"
       INFOR4 DB 0AH,0DH, "You press an error key!$" 
DATA   ENDS 
CODE   SEGMENT
       ASSUME CS:CODE,DS:DATA   

START: MOV AX,DATA
       MOV DS,AX
       ;打印INFOR1
       MOV DX,OFFSET INFOR1
       MOV AH,09H
       INT 21H 
       ;接收从键盘输入一个字符， 
       MOV AH,01H
       INT 21H

       CMP AL,'N'
       JZ  OTHERN 

       CMP AL,'n'
       JZ  OTHERN

       CMP AL,'Y'
       JZ  OTHERY

       CMP AL,'y' 
       JZ  OTHERY 
       MOV DX,OFFSET INFOR4
       MOV AH,09H
       INT 21H 

       JMP PEND

OTHERY:
       MOV DX,OFFSET INFOR2
       MOV AH,09H
       INT 21H 
       JMP PEND


OTHERN: 
       MOV DX,OFFSET INFOR3
       MOV AH,09H
       INT 21H 
       JMP PEND

PEND:  MOV AH,4CH
       INT 21H
CODE   ENDS
       END START