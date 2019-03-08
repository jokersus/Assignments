#include "concat.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE		32								// Main buffer size
#define INT_CHAR_LEN	11								// Max length of int with negative (-) char
#define BUFF_EXP_CONST	2								// Geometrical growtch factor

char *concat(char *format, ...) {
	va_list va;

	va_start(va, format);

	size_t size = sizeof(char) * BUFFSIZE;				// Initially reserved size
	char *buff = malloc(size);
	size_t len = 0;										// Current size

	// Go through format string one byte at a time
	while (*format) {

		if (*format == '%') {							// If format specifier found (only accepts int)
			format++;									// Skip next byte

			int temp_val = va_arg(va, int);				// Get next arg
			char temp_buff[INT_CHAR_LEN];				// Temp buffer for string conversion

			len += sprintf(temp_buff, "%d", temp_val);	// Convert string and add to total length
			strcat(buff, temp_buff);					// Write to main buffer
		} else {										// If not format specifier
			buff[len] = *format;
			len++;
		}

		format++;

		if (len + INT_CHAR_LEN > size) {				// If next write can overflow
			size *= BUFF_EXP_CONST;						// Increase buffer size by a factor
			buff = realloc(buff, size);
		}
	}

	va_end(va);

	// Truncate unallocated memory
	buff = realloc(buff, size);

	return buff;
}
