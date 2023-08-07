DATA   SEGMENT
       INFOR1 DB 0AH,0DH, "Please Press Any Key to input a letter:$"
       INFOR2 DB 0AH,0DH, "You Input a Lowercase Letter! $"
       INFOR3 DB 0AH,0DH, "You Input a Uppercase Letter! $"
       INFOR4 DB 0AH,0DH, "You Input a Digit!$"
       INFOR5 DB 0AH,0DH, "You Input Other Letter!$" 
DATA   ENDS 
CODE   SEGMENT
       ASSUME CS:CODE,DS:DATA   

START: MOV AX,DATA
       MOV DS,AX
       ;��ʾ��Ϣ��Please PressAny Key to inputa letter����ָ������
       MOV DX,OFFSET INFOR1
       MOV AH,09H
       INT 21H 
       ;���մӼ�������һ���ַ���ָ������
       MOV AH,01H
       INT 21H

       CMP AL,'0'
       JB  OTHER 

       CMP AL,'9'
       JBE DIGIT 

       CMP AL,'A'

       JB  OTHER

       CMP AL,'Z' 
       JBE UPPER 

       CMP AL,'a'
       JB  OTHER 

       CMP AL,'z'
       JBE  LOWER
       JMP PEND

LOWER: ;��ʾ��You InputaLowercase Letter!����ָ������    
       MOV DX,OFFSET INFOR2
       MOV AH,09H
       INT 21H 
       JMP PEND  ;ע��ִ����һ����֧��Ӧʹ��������


UPPER: ;��ʾ��YouInputa Uppercase Letter����ָ������
       MOV DX,OFFSET INFOR3
       MOV AH,09H
       INT 21H 
       JMP PEND


DIGIT: ;��ʾ��You Inputa Digit!����ָ������
       MOV DX, OFFSET INFOR4      
       MOV AH,09H
       INT 21H 
       JMP PEND


OTHER: ;��ʾ��You Input Other Letter!����ָ������
       MOV DX, OFFSET INFOR5      
       MOV AH,09H
       INT 21H 
       JMP PEND


PEND:  MOV AH,4CH
       INT 21H
CODE   ENDS
       END START