.MODEL SMALL
.STACK 100H

.DATA
    ; No data required

.CODE
MAIN PROC

    ; Step 2: Initialize data segment
    MOV AX, @DATA
    MOV DS, AX

    ; Step 5: Move 00H to BL
    MOV BL, 00H

    ; Step 6: Move 00H to CH
    MOV CH, 00H

    ; Step 7: Move 0AH to CL (Loop 10 times)
    MOV CL, 0AH

L1:
    ; Step 8: Move 00H to DH (not mandatory, but as per algorithm)
    MOV DH, 00H

    ; Step 9: Move BL to DL
    MOV DL, BL

    ; Step 10: Convert number to ASCII
    ADD DL, 30H

    ; Step 11: Print character using INT 21H
    MOV AH, 02H
    INT 21H

    ; Step 12: Increment BL
    INC BL

    ; Step 13: Loop back
    LOOP L1

    ; Step 14: Exit program
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
