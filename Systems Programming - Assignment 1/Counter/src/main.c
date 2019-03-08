#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFSIZ			4096
#define LOGFILE			"counter.log"
#define LOGFILE_BUFFSIZ		256
#define YEAR_OFFSET		1900

int main(int argc, char *argv[]) {

	if (argc < 2) {
		fprintf(stderr, "Not enough arguments. Expected 1, found 0.\n");
		exit(EXIT_FAILURE);
	}

	int fd = openat(AT_FDCWD, argv[1], O_RDONLY);

	if (fd == -1) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	// Check if directory
	struct stat buf;
	if (fstat(fd, &buf) != 0) {
		perror("File checking failed");
		exit(EXIT_FAILURE);
	}

	if (S_ISDIR(buf.st_mode)) {
		fprintf(stderr, "Error: Path %s refers to a directory\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Open/create log file
	int log_fd = openat(AT_FDCWD, LOGFILE, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);

	if (log_fd == -1) {
		perror("Error opening log file");
		exit(EXIT_FAILURE);
	}

	char buff[BUFFSIZ];

	ssize_t bytes_read;

	// Probably unnecessarily large, but just in case
	size_t line_count, longest_line, shortest_line, current_line;
	line_count = longest_line = shortest_line = current_line = 0;

	// Unsigned underflow is well-defined and gives max value
	shortest_line--;

	while (bytes_read = read(fd, &buff, BUFFSIZ), bytes_read != 0) {
		for (ssize_t i = 0; i < bytes_read; i++) {
			if (buff[i] == '\n') {
				line_count++;
				if (current_line > longest_line) {
					longest_line = current_line;
				}

				if (current_line < shortest_line) {
					shortest_line = current_line;
				}

				current_line = 0;

				continue;
			}

			current_line++;
		}
	}

	if (bytes_read == -1) {
		perror("Error reading file");
		exit(EXIT_FAILURE);
	}

	time_t now;
	time(&now);
	struct tm *local = localtime(&now);

	// Buffer for log file
	char *log_text = malloc(sizeof(char) * LOGFILE_BUFFSIZ);

	// Write log file entry to buffer
	int log_text_len = snprintf(log_text, LOGFILE_BUFFSIZ, "[%02d.%02d.%02d/%02d:%02d:%02d] %zu %zu %zu\n",
								local->tm_mday, local->tm_mon, local->tm_year + YEAR_OFFSET, local->tm_hour,
								local->tm_min, local->tm_sec,
								line_count, longest_line, shortest_line
	);

	// Increase buffer size and rewrite, if not large enough
	if (log_text_len > LOGFILE_BUFFSIZ) {
		log_text = realloc(log_text, sizeof(char) * log_text_len);

		sprintf(log_text, "[%02d.%02d.%02d/%02d:%02d:%02d] %zu %zu %zu\n",
				local->tm_mday, local->tm_mon, local->tm_year + YEAR_OFFSET, local->tm_hour, local->tm_min,
				local->tm_sec,
				line_count, longest_line, shortest_line
		);
	}

	// Write log
	if (write(log_fd, log_text, (size_t) log_text_len) < 0) {
		perror("Error writing to log file");
		exit(EXIT_FAILURE);
	}

	// Output stats
	printf("Line count: %zu\n", line_count);
	printf("Longest line: %zu\n", longest_line);
	printf("Shortest line: %zu\n", shortest_line);

	exit(EXIT_SUCCESS);
}
