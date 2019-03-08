#include <iostream>

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t n, *arr;

	std::cin >> n;
	arr = new size_t[n + 1]{0};

	for (size_t i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}

	for (size_t i = 2; i <= n; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	std::cin >> n;
	for (size_t i = 0, a, b; i < n; i++) {
		std::cin >> a >> b;
		std::cout << arr[b] - arr[a - 1] << '\n';
	}

	delete[] arr;

	return 0;
}
