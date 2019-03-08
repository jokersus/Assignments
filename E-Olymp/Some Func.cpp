#include <stdio.h>

#define MAX 501
#define MOD 9929

long long func(int n, int k);

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%lld", func(n, k));
}

long long func(int n, int k) {
	static long long arr[MAX][MAX];

	if (n == k) {
		return 1;
	}

	if (k == 0) {
		return 1;
	}

	if (arr[n][k]) {
		return arr[n][k];
	}

	return arr[n][k] = (func(n - 1, k - 1) + func(n - 1, k)) % MOD;
}