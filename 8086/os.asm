ASSUME CS:CODE, DS:DATA, ES:DATA

DATA SEGMENT
    STR1 DB "oscaalp$"
    COUNT EQU ($-STR1)

    STR2 DB COUNT DUP(0)
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX
    MOV ES, AX

    MOV CX, COUNT-1        ; exclude '$'

    LEA SI, STR1
    LEA DI, STR2

    ADD SI, COUNT-2        ; point to last character before '$'

    STD                    ; backward direction for LODSB

L1:
    LODSB                  ; AL = [SI], SI--
    CLD                    ; forward direction for STOSB
    STOSB                  ; [DI] = AL, DI++
    STD                    ; again backward for next LODSB
    LOOP L1

    CLD                    ; restore forward direction
    MOV AL, 24H            ; '$'
    STOSB

    MOV AH, 09H
    LEA DX, STR2
    INT 21H

    INT 3H

CODE ENDS
END START
