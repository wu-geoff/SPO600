.text
.globl _start

start = 0                       /* starting value for the loop index; note that this is a symbol (constant), not a variable */
max = 31                        /* loop exits when the index hits this number (loop condition is i<max) */

_start:
    mov     $start,%r15         /* loop index */

loop:
    /* ... body of the loop ... do something useful here ... */
    mov     $48,%r11
    mov     $48,%r12
    mov     $0,%rdx
    mov     $10,%r13
    mov     %r15,%rax
    idiv    %r13
    add     %rax,%r11
    add     %rdx,%r12

    mov     %r11b,msg+6
    mov     %r12b,msg+7

    movq    $len,%rdx
    movq    $msg,%rsi
 
    mov     $1,%rdi                    /* file descriptor stdout */
    mov     $1,%rax                         /* syscall sys_write */
    syscall

    inc     %r15                /* increment index */
    cmp     $max,%r15           /* see if we're done */
    jne     loop                /* loop if we're not */

    mov     $0,%rdi             /* exit status */
    mov     $60,%rax            /* syscall sys_exit */
    syscall

.section .data
msg: .ascii "Loop:   \n"
.set len , . - msg
