#include <stdio.h>

#define MAX 46

long long func(long long n);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lld", func(n));

}

long long func(long long n) {
	static long long arr[MAX] { 1, 3 };

	if (arr[n]) {
		return arr[n];
	}

	return arr[n] = 3 * func(n - 1) - func(n - 2);
}
