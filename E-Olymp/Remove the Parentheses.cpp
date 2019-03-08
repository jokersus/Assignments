#include <iostream>
#include <string>

int main() {
	// C++ std::cin patch
	std::string input;
	std::cin >> input;

	int left = 0, right = 0, removed = 0;

	for (char c : input) {
		if (c == ')') {
			right++;

			if (right > left) {
				right--;
				removed++;
			}

			continue;
		}

		left++;
	}

	printf("%d\n", removed + (left - right));

	return 0;
}
