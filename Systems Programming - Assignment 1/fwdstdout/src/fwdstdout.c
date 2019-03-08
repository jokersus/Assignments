#include "fwdstdout.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void fwdstdout(char *path) {

	int fd = openat(AT_FDCWD, path,
			O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR
	);

	if (fd == -1) {
		fprintf(stderr, "Error opening file %s: ", path);
		perror("");
		exit(EXIT_FAILURE);
	}

	// Check if file is a directory
	struct stat buf;
	if (fstat(fd, &buf) != 0) {
		perror("File checking failed");
		exit(EXIT_FAILURE);
	}

	if (S_ISDIR(buf.st_mode)) {
		fprintf(stderr, "Path %s refers to a directory\n", path);
		exit(EXIT_FAILURE);
	}

	if (close(STDOUT_FILENO) == -1) {
		perror("Error closing STDOUT");
		exit(EXIT_FAILURE);
	}

	if (dup(fd) == -1) {
		perror("Error forwarding STDOUT");
		exit(EXIT_FAILURE);
	}
}