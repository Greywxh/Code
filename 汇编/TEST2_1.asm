DATA SEGMENT

INFOR1  DB 0DH, 0AH,"Please Input the First Data(<10):$"
INFOR2  DB 0DH, 0AH, "Please Input the Second Data(<10):$"
INFOR3  DB 0DH, 0AH, "The Result Is:$"

DATA ENDS

CODE SEGMENT
ASSUME CS: CODE, DS: DATA

START:
        MOV     AX, DATA
        MOV     DS, AX
        LEA     DX, INFOR1
        MOV     AH, 09H
        INT     21H
        MOV     AH, 01H
        INT     21H
        SUB     AL, 30H
        MOV     BL, AL
        LEA     DX, INFOR2
        MOV     AH, 09H
        INT     21H
        MOV     AH, 01H
        INT     21H
        SUB     AL, 30H
        XOR     AH, AH
        ADD     AL, BL
        AAA
        PUSH    AX
        LEA     DX, INFOR3
        MOV     AH, 09H
        INT     21H
        POP     AX
        PUSH    AX
        MOV     DL, AH
        ADD     DL, 30H
        MOV     AH, 02H
        INT     21H
        POP     AX
        MOV     DL, AL
        ADD     DL, 30H
        MOV     AH, 02H
        INT     21H
        PUSH    AX
        MOV     AH, 4CH
        INT     21H
        CODE ENDS
        END     START