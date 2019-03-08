#include <stdio.h>
#include <fcntl.h>
#include "filedesc.h"

int main() {
	fdinfo(openat(AT_FDCWD, "./badfile", O_TRUNC));
	putchar('\n');

	fdinfo(openat(AT_FDCWD, "./goodfile", O_WRONLY | O_CREAT | O_TRUNC));
	putchar('\n');

	fdinfo(openat(AT_FDCWD, "/", O_RDONLY));
	putchar('\n');

	fdinfo(openat(AT_FDCWD, "./main.c", O_RDWR | O_APPEND | O_NDELAY));
	putchar('\n');
}
