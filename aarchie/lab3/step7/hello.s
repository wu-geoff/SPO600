.text
.globl _start

start = 0
max = 10

_start:
        mov     x9,start

_loop: 
	mov     x0, 1           /* file descriptor: 1 is stdout */
	adr     x1, msg   	/* message location (memory address) */
	mov     x2, len   	/* message length (bytes) */
	
	add	x3,x9,0x30
	strb	w3,[x1,6]	

	mov     x8, 64     	/* write is syscall #64 */
	svc     0          	/* invoke syscall */
        
	add     x9,x9,1
	cmp     x9,max
	b.ne    _loop
 
	mov     x0, 0     	/* status -> 0 */
	mov     x8, 93    	/* exit is syscall #93 */
	svc     0          	/* invoke syscall */
 
.data
msg: 	.ascii      "Loop:  \n"
len= 	. - msg

