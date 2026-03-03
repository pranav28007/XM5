.MODEL SMALL
.STACK 100H

.DATA
    message1 DB "Enter a number (0-9): $"
    message2 DB 0DH,0AH,"Number is EVEN.$"
    message3 DB 0DH,0AH,"Number is ODD.$"

.CODE
MAIN PROC

    ; Step 3 & 4: Initialize Data Segment
    MOV AX, @DATA
    MOV DS, AX

    ; Step 5: Display message1
    LEA DX, message1
    MOV AH, 09H
    INT 21H

    ; Step 7: Read a character
    MOV AH, 01H
    INT 21H          ; Input stored in AL

    ; Step 8: Convert ASCII to number
    SUB AL, 30H

    ; Step 9: Move 02H to BL
    MOV BL, 02H

    ; Step 10: Divide AL by 2
    MOV AH, 00H      ; Clear AH before DIV
    DIV BL           ; AL = Quotient, AH = Remainder

    ; Step 11: Compare remainder with 0
    CMP AH, 00H

    ; Step 12: Jump if not zero (Odd)
    JNE ODD

EVEN:
    ; Step 13: Load message2
    LEA DX, message2
    MOV AH, 09H
    INT 21H
    JMP EXIT

ODD:
    ; Step 16: Load message3
    LEA DX, message3
    MOV AH, 09H
    INT 21H

EXIT:
    ; Step 18: Exit program
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
