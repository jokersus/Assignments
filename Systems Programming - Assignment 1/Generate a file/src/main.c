#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	if (argc < 3) {
		fprintf(stderr, "Not enough arguments. Required 2 got %d\n", argc - 1);
		exit(EXIT_FAILURE);
	}

	// Convert second argument to long
	char *endptr = NULL;
	errno = 0;
	off_t size = strtol(argv[2], &endptr, 10);

	// If the input is too large or too small
	if ((errno == ERANGE && (size == LONG_MAX || size == LONG_MIN))
		|| (errno != 0 && size == 0)) {
		perror("Bad input");
		exit(EXIT_FAILURE);
	}

	// If input is malformed
	if (*endptr) {
		fprintf(stderr, "Bad input: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	// If input is 0 or negative
	if (size < 1) {
		fprintf(stderr, "Cannot create file of size 0 or lower\n");
		exit(EXIT_FAILURE);
	}

	int fd = openat(AT_FDCWD, argv[1], O_CREAT | O_WRONLY | O_TRUNC);

	if (fd == -1) {
		perror("Error creating file");
		exit(EXIT_FAILURE);
	}

	// Reserve 1 byte to write after offset
	off_t offset = lseek(fd, size - 1, SEEK_SET);

	if (offset != size - 1) {
		perror("Error setting the file offset");
		exit(EXIT_FAILURE);
	}

	// Write 1 byte to set file size
	if (write(fd, "", 1) < 0) {
		perror("Error setting file content");
		exit(EXIT_FAILURE);
	}

	printf("Created file %s of size %ld\n", argv[1], size);

	exit(EXIT_SUCCESS);
}
