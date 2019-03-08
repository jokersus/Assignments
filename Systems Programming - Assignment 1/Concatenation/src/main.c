#include "concat.h"
#include <stdio.h>

int main() {
	printf("%s\n", concat("%d %d %d %d %d", 1, 2, 3, 4, 5));	// Expected: "1 2 3 4"
	printf("%s\n", concat("%d %d %d %d %d", 1, -2, 3, -4, 5));	// Expected: "1 -2 3 -4 5""
	printf("%s\n", concat("aaaaaaaaa"));						// Expected: "aaaaaaaaa"
	printf("%s\n", concat("%d %d %d %d %d", 1));				// Bad format string - Undefined behavior
	printf("%s\n", concat("%d", 1, 2, 3, 4, 5));				// Expected: "1"
}
