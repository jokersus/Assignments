#include <iostream>

int calculate_lowest_sod(int arr[], int length, int _index = 0, int _min = std::numeric_limits<int>::max(), int _min_index = 0);

int main() {
	int n, *arr;

	std::cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::cout << calculate_lowest_sod(arr, n);

	delete[] arr;
	return 0;
}

int calculate_sod(int n, int sum = 0) {
	return n < 10 ? n + sum : calculate_sod(n / 10, sum + n % 10);
}

int calculate_lowest_sod(int arr[], int length, int _index, int _min, int _min_index) {
	if (_index == length) {
		return arr[_min_index];
	}

	int sod = calculate_sod(arr[_index]);
	if (sod <= _min) {
		return calculate_lowest_sod(arr, length, _index + 1, sod, _index);
	}

	return calculate_lowest_sod(arr, length, _index + 1, _min, _min_index);
}
