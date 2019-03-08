#include <iostream>
#include <sstream>

int highest_common_factor(int a, int b);
int recursive_hack(int arr[], size_t length, int _index = 0, int _value = -1);

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::ostringstream oss;

	int temp;
	while (true) {
		std::cin >> temp;
		if (!temp) {
			break;
		}

		while (true) {
			std::cin >> temp;
			if (!temp) {
				break;
			}

			vec.push_back(std::abs(temp));
		}

		oss << recursive_hack(vec.data(), vec.size()) << '\n';
	}

	std::cout << oss.str() << '\n';
}

int recursive_hack(int arr[], size_t length, int _index, int _value) {
	if (_index == length) {
		return _value;
	}

	if (_value == -1) {
		return recursive_hack(arr, length, _index, arr[0]);
	}

	return recursive_hack(arr, length, _index + 1, highest_common_factor(_value, arr[_index]));

}

int highest_common_factor(int a, int b) {
	if(a > b) {
		return highest_common_factor(a - b,b);
	} else if(b > a){
		return highest_common_factor(a,b - a);
	} else {
		return a;
	}
}
