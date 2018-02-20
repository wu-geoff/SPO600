/* Hello World using a direct kernel system call to write to 
   file descriptor 1 (stdout) */

#include <unistd.h>
#include <sys/syscall.h>

int main() {
	syscall(__NR_write,1,"Hello World!\n",13);
}

