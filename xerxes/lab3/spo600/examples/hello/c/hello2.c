/* Hello World with a direct write to stdout (file descriptor 1) */

#include <unistd.h>

int main() {
	write(1,"Hello World!\n",13);
}

