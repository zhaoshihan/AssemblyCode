			;上限=D2H,下限=3FH
BEGIN:	MOV AL,0D2H	;下限值
UP:	OUT 220H,AL
	INC AL
	CMP AL,0D3H	;超过上限
	JNZ UP
	DEC AL
	
KEEPUP:	OUT 220H,AL
	CALL DELAY_20MS	
	
DOWN:	DEC AL
	OUT 220H,AL
	CMP AL,03FH	;低于下限
	JNZ DOWN
	
KEEPDOWN:OUT 220H,AL
	CALL DELAY_20MS
	JMP UP		

