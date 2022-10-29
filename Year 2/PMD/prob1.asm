.model :small 

.data
    N db 5
    M db 0
    C db 1
    S db ?
.code 
     main proc 
        MOV AX,@data
        MOV DS,AX
        MOV AH,2
        MOV DL,M
        ADD DL,30H
        INT 21H 
        MOV AH,2
        MOV DL,c
        ADD DL,30H
        INT 21H
     while:
        CMP N,0
        JZ final
        mov AL,M
        ADD AL,C
        MOV DL,AL
        MOV S,DL
        ADD DL,30h
        MOV AH,2
        MOV BL,C
        MOV M,BL
        MOV C,AL
        INT 21H
        DEC N
        JMP while
     final:
        NOP
     main endp
    end
