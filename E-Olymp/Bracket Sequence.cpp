#include <iostream>
#include <string>

int main() {
	int counter = 0;
	std::string input;

	std::cin >> input;

	if (input.length() & 1) {
		printf("NO\n");
		return 0;
	}

	for (char i : input) {

		if (i == '(') {
			counter++;
		} else {
			counter--;
		}

		if (counter < 0) {    // Goddamnit
			printf("NO\n");
			return 0;
		}
	}

	printf(counter ? "NO\n" : "YES\n");
}
