#include <stdio.h>

int f(int n);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}

int f(int n) {
	static int _memo[100001] { 0, 2, 4, 7 };
	if (_memo[n] != 0) return _memo[n];
	return _memo[n] = (f(n-1) + f(n-2) + f(n-3)) % 12345;
}
