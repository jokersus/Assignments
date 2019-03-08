#include <iostream>

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	long long arr[n + 1];
	arr[0] = arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[n % i] *
				 (n - n / i) % n;
	}

	for (int i = 1; i < n; i++) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}
