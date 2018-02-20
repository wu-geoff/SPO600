BINARIES=lab3

all:	${BINARIES}
AS_ARGS=-g

all:	lab3

lab3:	lab3.s
		as 	${AS_ARGS} 	-o lab3.o	 	lab3.s
		ld 	 		-o lab3	 		lab3.o


clean:	
		rm ${BINARIES} *.o || true



