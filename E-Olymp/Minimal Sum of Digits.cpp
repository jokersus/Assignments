#include <iostream>

long calculate_lowest_sod(long arr[], long length, long _index = 0, long _min = std::numeric_limits<long>::max(), int counter = 1);

int main() {
	long *arr;

	long a, b;
	std::cin >> a >> b;

	long length = b - a + 1;
	arr = new long[length];

	for (int i = 0; a <= b; a++, i++) {
		arr[i] = a;
	}

	std::cout << calculate_lowest_sod(arr, length);
	
	return 0;
}

long calculate_sod(long n, long sum = 0) {
	return n < 10 ? n + sum : calculate_sod(n / 10, sum + n % 10);
}

long calculate_lowest_sod(long arr[], long length, long _index, long _min, int counter) {
	if (_index == length) {
		return counter;
	}

	long sod = calculate_sod(arr[_index]);
	if (sod < _min) {
		return calculate_lowest_sod(arr, length, _index + 1, sod, counter ? counter : 0);
	}

	if (sod == _min) {
		return calculate_lowest_sod(arr, length, _index + 1, sod, counter + 1);
	}

	return calculate_lowest_sod(arr, length, _index + 1, _min, counter);
}
