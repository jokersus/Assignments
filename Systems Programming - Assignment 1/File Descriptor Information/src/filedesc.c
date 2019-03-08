#include <fcntl.h>
#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include "filedesc.h"

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_color(char *text);

int fdinfo(int fd) {
	int flags;

	// Check if fd is valid and active
	if (fd == -1 || (flags = fcntl(fd, F_GETFL), flags == -1)) {
		fprintf(stderr, "Error checking file %d: %s\n", fd, strerror(errno));
		return -1;
	}

	printf(ANSI_COLOR_GREEN "Flags for file descriptor %d\n" ANSI_COLOR_RESET, fd);

	printf("=== Operating Modes ===\n");

	if (flags & O_APPEND) {
		print_color("O_APPEND");
	}

	if (flags & O_NONBLOCK) {
		print_color("O_NONBLOCK");
	}

	if (flags & O_NDELAY) {
		print_color("O_NDELAY");
	}

	if (flags & O_ASYNC) {
		print_color("O_ASYNC");
	}

	if (flags & O_FSYNC) {
		print_color("O_FSYNC");
	}

	if (flags & O_SYNC) {
		print_color("O_SYNC");
	}

	flags &= O_ACCMODE;
	printf("\n=== Access modes ===\n");

	switch (flags) {
		case O_RDONLY:
			print_color("O_RDONLY");
			break;

		case O_WRONLY:
			print_color("O_WRONLY");
			break;

		case O_RDWR:
			print_color("O_RDWR");
			break;
		case O_APPEND:
			print_color("O_APPEND");
			break;
	}

	return flags;
}

void print_color(char *text) {
	printf(ANSI_COLOR_CYAN" %s\n" ANSI_COLOR_RESET, text);
}
