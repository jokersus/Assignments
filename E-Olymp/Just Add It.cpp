#include <iostream>
#include <sstream>

#define MOD_NUM 10000007

int calculate_power(long long base, long long exponent);

int main() {
	//2 * (n - 1)^k + n^k + 2 * (n - 1)^(n - 1) + (n)^n;

	long long n, k;

	std::ostringstream oss;

	while (true) {
		std::cin >> n >> k;
		if (!n && !k) {
			break;
		}

		oss << (2 * (calculate_power(n - 1, k) % MOD_NUM) +
				(calculate_power(n, k) % MOD_NUM) +
				(calculate_power(n - 1, n - 1) % MOD_NUM) * 2 +
				(calculate_power(n, n) % MOD_NUM)) % MOD_NUM << '\n';
	}

	std::cout << oss.str();
}

int calculate_power(long long base, long long exponent) {
	long long result = 1;
	while (exponent) {
		if (exponent & 1) {
			result = result * base % MOD_NUM;
		}

		exponent >>= 1;
		base = base * base % MOD_NUM;
	}

	return result;
}
