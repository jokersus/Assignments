#include <iostream>
#include <sstream>

std::string find_nth_fibonacci(int n, const std::string &_sum = "b", const std::string &_prev = "a");

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> nn;

	std::cout << find_nth_fibonacci(n);

	return 0;
}

std::string find_nth_fibonacci(int n, const std::string &_sum, const std::string &_prev) {
	if (n == 0) {
		return "a";
	}

	if (n == 1) {
		return _sum;
	}

	return find_nth_fibonacci(n - 1, _sum + _prev, _sum);
}
