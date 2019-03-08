#include <stdio.h.

#define MAX 1000000

int main() {
	static long memo[MAX + 1];

	memo[1] = 0;
	for (size_t i = 2; i <= MAX; i++) {
		memo[i] = memo[i - 1];
		if (i % 2 == 0 && memo[i / 2] < memo[i]) {
			memo[i] = memo[i / 2];
		}

		if (i % 3 == 0 && memo[i / 3] < memo[i]) {
			memo[i] = memo[i / 3];
		}

		memo[i]++;
	}

	long n;
	while (scanf("%ld", &n) == 1) {
		printf("%ld\n", memo[n]);
	}
}
