#include <iostream>

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n;
	bool zero = false;

	std::cin >> n;
	if (!n) {
		std::cout << 0 << '\n';
		return 0;
	}
	auto arr = new long long[n + 1];

	// Input
	arr[n] = 1;
	for (long long i = 0; i < n; i++) {
		std::cin >> arr[i];
		if (!arr[i]) {
			if (zero) {
				arr[n] = 0;
				continue;
			}
			zero = true;
			continue;
		}

		arr[n] *= arr[i];
	}

	// Actual calculations. Should be O(n) in constant space
	for (long long i = 0; i < n; i++) {
		std::cout << (zero ? (arr[i] ? 0 : arr[n]) : (arr[n] / arr[i])) << ' ';
	}

	delete[] arr;

	return 0;

}