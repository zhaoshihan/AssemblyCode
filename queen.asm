DATA	SEGMENT
INITIAL	DB	-1
QUEEN	DB	8 DUP(-1)
;NUMBER	DW	8
NUMBER	EQU	LENGTH QUEEN
RESULT	DB	0
OPCODE1	DB	0
OPCODE2	DB	0
TEMP	DW	0
DATA	ENDS

CODE	SEGMENT
ASSUME	CS:CODE,DS:DATA
START:	MOV AX,DATA
	MOV DS,AX
	MOV DI,OFFSET RESULT
	;SUB AX,AX
	;SUB CX,CX
	
	CALL FIND
	;SUB AX,AX
	;SUB BX,BX
	;SUB CX,CX
	;SUB DX,DX
	
	MOV AL,[DI]
	CALL PRINT
	
	MOV AX,4C00H
	INT 21H
FIND PROC NEAR
	SUB BX,BX
	SUB DX,DX	;BL=ROW NUM,DL=COLUMN NUM

ROWLOOP:CMP BL,NUMBER
	JAE EXIT	;ROW < QUEEN NUM,CONTINUE
COLLOOP:CMP DL,NUMBER 
	JAE INIT	;DL=COLUMN >= QUEEN NUMBER
	CALL VALID	
	
	;MOV AH,0
	;MOV SI,OFFSET TEMP
	;MOV [TEMP],DX
	;MOV AL,DL
	;MOV DL,CL
	;ADD DL,30H
	;MOV AH,2
	;INT 21H
	;MOV DL,32
	;MOV AH,2
	;INT 21H	
	;MOV DL,AL
	;MOV DX,[TEMP]
	
	CMP CX,1	;IF TRUE
	JNE NOVALID
	MOV QUEEN[BX],DL
	MOV DL,0
	JMP INIT
NOVALID:INC DL	
	JMP COLLOOP
	
INIT:	MOV AL,QUEEN[BX]
	CMP AL,INITIAL
	JNE FINAL
	CMP BL,0
	JE EXIT
	DEC BL
	MOV AL,QUEEN[BX]
	INC AL
	MOV DL,AL
	MOV AL,INITIAL
	MOV QUEEN[BX],AL
	JMP ROWLOOP
	
FINAL:	MOV AL,NUMBER
	DEC AL
	CMP BL,AL	;BL=ROW == QUEEN-1 ?
	JNE ROWCOM
	MOV AH,0
	MOV AL,[DI]
	INC AL
	MOV [DI],AL	;RESULT + 1
	MOV AL,QUEEN[BX]
	INC AL
	MOV DL,AL	;COL=QUEEN[ROW]+1
	MOV AL,INITIAL
	MOV QUEEN[BX],AL	;QUEEN[ROW]=INITIAL
	JMP ROWLOOP
	
ROWCOM:	INC BL
	JMP ROWLOOP
	
EXIT:	ret
FIND endp

VALID PROC NEAR
	SUB AX,AX	;判断第row行第col列是否可以放置皇后
AGAIN:	CMP AL,NUMBER
	JAE SUCCESS	;AX<QUEEN NUM,CONTINUE
	
	;MOV SI,OFFSET TEMP
	;MOV [SI],BX
	XCHG AX,BX
	MOV CL,QUEEN[BX]
	XCHG AX,BX
	;MOV BX,[SI]
	
	CMP CL,INITIAL
	JE INCREASE
	
	;MOV SI,OFFSET TEMP
	;MOV [SI],BX
	XCHG AX,BX
	MOV CL,QUEEN[BX]
	XCHG AX,BX
	;MOV BX,[SI]
		
	CMP CL,DL
	JE FAIL
	MOV SI,OFFSET OPCODE1
	MOV [SI],AL	;abs(i-row) == abs(array[i]-col) ? ABS(AX-BX) == ABS(QUEEN[AX]-DX)
	SUB [SI],BL
	MOV SI,OFFSET OPCODE2
	
	;MOV DI,OFFSET TEMP
	;MOV [DI],BX
	XCHG AX,BX
	MOV CL,QUEEN[BX]
	XCHG AX,BX
	;MOV BX,[DI]
	
	MOV [SI],CL
	SUB [SI],DL
	MOV CL,OPCODE2
	CMP OPCODE1,CL
	JE FAIL
	NEG CL
	CMP OPCODE1,CL
	JE FAIL
	NEG OPCODE1
	CMP OPCODE1,CL
	JE FAIL
	MOV CL,[SI]
	CMP OPCODE1,CL
	JE FAIL
INCREASE:	INC AL
	JMP AGAIN
	
SUCCESS:MOV CX,1
	ret	
FAIL:	MOV CX,0
	ret	;CX=1 TRUE; CX=0 FALSE
VALID endp

PRINT PROC NEAR
	MOV AH,0	;十进制打印AL中的数字
	
	MOV BL,10
	DIV BL
	XCHG AH,AL
	ADD AX,3030H
	MOV CX,AX
	MOV DL,CH
	MOV AH,2
	INT 21H
	MOV DL,CL
	MOV AH,2
	INT 21H
	ret
PRINT endp

CODE	ENDS
END	START
