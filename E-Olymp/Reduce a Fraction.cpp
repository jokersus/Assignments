#include <iostream>
#include <algorithm>

long long highest_common_factor(long long a, long long b);

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long num, denom;
	std::cin >> num >> denom;

	long long mod = std::abs(std::__gcd(num, denom));

	std::cout << num / mod << ' ' << denom / mod << '\n';

	return 0;
}
