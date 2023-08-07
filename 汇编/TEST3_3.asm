PRINT  MACRO PARA
       MOV DX,OFFSET PARA
       MOV AH,09H
       INT 21H
       ENDM

DATA   SEGMENT
       INFOR1 DB 0AH,0DH, "1------------------------Panda$"
       INFOR2 DB 0AH,0DH, "2------------------------Cat$"
       INFOR3 DB 0AH,0DH, "3------------------------Rabbit$"
       INFOR4 DB 0AH,0DH, "4------------------------Pig$"
       INFOR5 DB 0AH,0DH, "5------------------------EXIT$"
       INFOR6 DB 0AH,0DH, "(Please choose 1,2,3,4or5)-----$"
       INFOR7 DB 0AH,0DH, "I like panda$"
       INFOR8 DB 0AH,0DH, "I like cat$"
       INFOR9 DB 0AH,0DH, "I like rabbit$"
       INFORA DB 0AH,0DH, "I don't like pig$"
       INFORB DB 0AH,0DH, "You press an error key!$"

DATA   ENDS 
CODE   SEGMENT
       ASSUME CS:CODE,DS:DATA   

START: MOV AX,DATA
       MOV DS,AX
       ;��ӡǰ����Ϣ
       PRINT INFOR1
       PRINT INFOR2
       PRINT INFOR3
       PRINT INFOR4
       PRINT INFOR6

       ;���մӼ�������һ���ַ��� 
       MOV AH,01H
       INT 21H

       CMP AL,'1'
       JZ  PANDA

       CMP AL,'2'
       JZ  Cat

       CMP AL,'3'
       JZ  Rabbit

       CMP AL,'4' 
       JZ  Pig

       CMP AL,'5' 
       JZ  PEND

       PRINT INFORB 

       JMP PEND

PANDA :PRINT INFOR7
       JMP PEND

Cat   :PRINT INFOR8
       JMP PEND

Rabbit:PRINT INFOR9
       JMP PEND

Pig   :PRINT INFORA
       JMP PEND

PEND  :MOV AH,4CH
       INT 21H

CODE   ENDS
       END START