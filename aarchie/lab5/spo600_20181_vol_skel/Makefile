# list all binaries in this next line
BINARIES = vol1 vol2 vol3
CCOPTS = -g -O3

all:	${BINARIES}

vol1:	vol1.c vol.h
	gcc ${CCOPTS} vol1.c -o vol1

vol2:	vol2.c vol.h
	gcc ${CCOPTS} vol2.c -o vol2

vol3:	vol3.c vol.h
	gcc ${CCOPTS} vol3.c -o vol3

test1:	vol1
	bash -c "time ./vol1"

test2:	vol2
	bash -c "time ./vol2"

# target to test all binaries
test:	test1 

gdb1:	vol1
	gdb vol1

clean:	
	rm ${BINARIES} || true


