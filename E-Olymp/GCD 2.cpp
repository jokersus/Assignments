#include <iostream>

template <typename ...Ints>
int gcd(Ints... ints);
int gcd(int a, int b);


int main() {
	int n, *arr;
	std::cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::cout << gcd(arr);
}

template <typename ...Ints>
int gcd(Ints... ints) {
	int temp[] = {ints...};
	return gcd(temp);
}

int gcd(int arr[], int length) {

	if (length < 2) {
		return 0;
	}

	int res = arr[0];
	for (int i = 1; i < length; i++) {
		res = gcd(res, arr[i]);
	}

	return res;
}

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}

	if (b == 0) {
		return a;
	}

	if (a >= b) {
		return gcd(a % b, b);
	}

	if (a < b) {
		return gcd(a, b % a);
	}
}
