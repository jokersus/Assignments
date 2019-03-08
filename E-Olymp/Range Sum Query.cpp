#include <iostream>
#include <sstream>

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int total;

	std::cin >> total;

	for (int i = 0; i < total; i++) {
		int n, q;

		std::cin >> n >> q;
		auto *nums = new long long[n];

		std::cin >> nums[0];
		for (int i = 1; i < n; i++) {
			long long temp;
			std::cin >> temp;
			nums[i] = nums[i - 1] + temp;
		}

		std::ostringstream oss;
		for (int i = 0; i < q; i++) {
			int a, b;
			std::cin >> a >> b;
			oss << nums[b] - (a ? nums[a - 1] : 0) << '\n';
		}

		std::cout << oss.str() << '\n';
		delete[] nums;
	}
}
