			;上限=107H,下限=0H
BEGIN:	MOV AX,0H	;下限值
UP:	OUT 220H,AX
	INC AX
	CMP AX,108H	;超过上限
	JNZ UP
	DEC AX
	
DOWN:	OUT 220H,AX
	DEC AX
	CMP AX,FFFFH	;低于下限
	JNZ DOWN
	JMP BEGIN		

