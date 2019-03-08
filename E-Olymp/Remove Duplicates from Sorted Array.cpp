#include <iostream>

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int prev = -101;
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;

		if (temp == prev) {
			prev = temp;
			while (temp == prev && i < n - 1) {
				std::cin >> temp;
				i++;
			}
		}

		if (prev == temp) {
			break;
		}

		prev = temp;
		std::cout << temp << ' ';
	}

	std::cout << '\n';

	return 0;
}
