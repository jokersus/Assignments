#include <iostream>

long long gcd(long long a, long long b);

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long points[4];

	std::cin >> points[0] >> points[1] >> points[2] >> points[3];

	std::cout << gcd(points[2] - points[0], points[3] - points[1]) + 1;
}

long long gcd(long long a, long long b) {
	if (!a) {
		return b;
	}

	if (!b) {
		return a;
	}

	if (a >= b) {
		return gcd(a % b, b);
	}

	return gcd(a, b % a);
}
