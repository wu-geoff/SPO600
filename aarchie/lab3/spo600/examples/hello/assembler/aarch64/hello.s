.text
.globl _start
_start:
 
	mov     x0, 1           /* file descriptor: 1 is stdout */
	adr     x1, msg   	/* message location (memory address) */
	mov     x2, len   	/* message length (bytes) */

	mov     x8, 64     	/* write is syscall #64 */
	svc     0          	/* invoke syscall */
 
	mov     x0, 0     	/* status -> 0 */
	mov     x8, 93    	/* exit is syscall #93 */
	svc     0          	/* invoke syscall */
 
.data
msg: 	.ascii      "Hello, world!\n"
len= 	. - msg

