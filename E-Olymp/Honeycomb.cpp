#include <stdio.h>

int fibo_honeycomb(int n, int _sum = 1, int _prev = 0);

int main() {
	int n, result;
	scanf("%d", &n);
	result = fibo_honeycomb(n);
	printf("%d", result);
}

int fibo_honeycomb(int n, int _sum, int _prev) {
	if (n < 2) {
		return _sum;
	}

	return fibo_honeycomb(n - 1, _sum + _prev, _sum);
}
