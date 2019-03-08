#include <iostream>

template <typename ...LLongs>
long long gcd(LLongs... llongs);
long long gcd(long long arr[], int length);
long long gcd(long long a, long long b);

int main() {
	int n;
	long long *arr;

	std::cin >> n;
	arr = new long long[n];

	long long temp, current_gcd = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::cout << gcd(arr, n);
}

template <typename ...LLongs>
long long gcd(LLongs... llongs) {
	long long temp[] = {llongs...};
	return gcd(temp);
}

long long gcd(long long arr[], int length) {

	if (length < 2) {
		return 1;
	}

	long long res = 0;
	for (int i = 0; i < length; i++) {
		res = gcd(res, arr[i]);
	}

	return res;
}

long long gcd(long long a, long long b) {
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
