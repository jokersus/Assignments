#include <iostream>

long gcd(long a, long b);
long lcm(long arr[], long length);

int main() {
	long a = 1, b, *arr;
	std::cin >> b;

	long length = b - a + 1;
	arr = new long[length];

	for (long i = 0; a <= b; a++, i++) {
		arr[i] = a;
	}

	std::cout << lcm(arr, length);
}

long lcm(long arr[], long length) {

	if (length < 2) {
		return 1;
	}

	long res = arr[0];
	for (int i = 1; i < length; i++) {
		long temp = gcd(res, arr[i]);
		res = temp ? (res / temp * arr[i]) : 0;
	}

	return res;
}

long gcd(long a, long b) {
	if (a == 0) {
		return b;
	}

	if (b == 0) {
		return a;
	}

	if (a >= b) {
		return gcd(a % b, b);
	}

	return gcd(a, b % a);
}
