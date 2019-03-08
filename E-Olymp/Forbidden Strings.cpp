#include <stdio.h>

#define MAX 46

long long calculate(long long n);

int main() {
	long long n;
	while (scanf("%lld", &n) == 1) {
		printf("%lld\n", calculate(n));
	}
}

long long calculate(long long n) {
	static long long arr[MAX];

	if (n == 1) {
		return 3;
	}

	if (n == 2) {
		return 9;
	}

	if (arr[n] != 0) return arr[n];

	return arr[n] = 2 * calculate(n - 1) + calculate(n - 2);
}
