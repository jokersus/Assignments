#include <iostream>

size_t calculate_exponent(size_t n, size_t m, size_t a);

int main() {
	long long a, b, m;
	std::cin >> a >> b >> m;
	std::cout << calculate_exponent(a, b, m);

	return 0;
}

size_t calculate_exponent(size_t n, size_t m, size_t a) {
	if(m == 0) {
		return 1;
	}

	if (m % 2 == 0) {
		return calculate_exponent((n * n) % a, m / 2, a);
	}

	return (n * calculate_exponent(n, m - 1, a)) % a;
}
