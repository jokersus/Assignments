#include <iostream>

int calculate(int a, int b, int c);

int main() {
	int a, b, c = 0;

	while (true) {
		std::cin >> a >> b >> c;
		if (a == b && b == c && c == -1) {
			break;
		}

		std::cout << calculate(a, b, c);
	}

	return 0;
}

int calculate(int a, int b, int c) {
	if ((a <= 0) || (b <= 0) || (c <= 0)) {
		return 1;
	}

	if (a > 20 || b > 20 || c > 20) {
		return calculate(20, 20, 20);
	}

	if (a < b && b < c) {
		return calculate(a, b, c - 1) +
			calculate(a, b - 1, c - 1) - calculate(a, b - 1, c);
	}

	return calculate(a - 1, b, c) +
			calculate(a - 1, b - 1, c) +
			calculate(a - 1, b, c - 1) - calculate(a - 1, b - 1, c - 1);
}
