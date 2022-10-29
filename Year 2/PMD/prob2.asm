.model small

.data
    N db ?
    
.code
    main proc
    MOV AX,@data
    MOV DS,AX
    MOV CX,3
    MOV BL,0
    while:
        CMP CX,0
        JZ final
        MOV AH,1
        INT 21H
        MOV N,AL
        SUB N,30H
        ADD BL,N
        DEC CX
        JMP while
    final:
        NOP
    main endp
    end




