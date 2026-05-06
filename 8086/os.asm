ASSUME CS:CODE,DS:DATA

DATA SEGMENT
SRC DB "OSALP LAB$"
REV DB 10 DUP(?)
DATA ENDS

CODE SEGMENT
START:
MOV AX,DATA
MOV DS,AX
MOV ES,AX

; Point to source string
LEA SI,SRC

; Find end of string before $
L1:
MOV AL,[SI]
CMP AL,'$'
JE BACK
INC SI
JMP L1

BACK:
DEC SI            ; Move to last character before $

; Point to destination
LEA DI,REV

L2:
MOV AL,[SI]       ; Copy reverse character
MOV [DI],AL

DEC SI
INC DI

CMP SI,OFFSET SRC
JAE L2

; Add string terminator
MOV AL,'$'
MOV [DI],AL

MOV AH,4CH
 Explain INT 21H

CODE ENDS
END START
