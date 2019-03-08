#include <stdio.h>

#define MAX 51

long long func(int a, int b, int c);

int main() {
	int x, y, z;

	while (true) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == y && y == z && z == -1) {
			break;
		}

		printf("w(%d, %d, %d) = %lld\n", x, y, z, func(x, y, z));
	}
}

long long func(int a, int b, int c) {
	static long long arr[MAX][MAX][MAX];

	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (arr[a][b][c]) {
		return arr[a][b][c];
	}

	if (a > 20 || b > 20 || c > 20) {
		return arr[a][b][c] = func(20, 20, 20);
	}

	if (a < b && b < c) {
		return arr[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
	}

	return arr[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) +
							func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
}
