#include <iostream>

int fibonacci(int n);
int find_nth_fibonacci(int n, int _index = 0, int _sum = 1, int _prev = 0);

int main() {
	int n;

	std::cin >> n;
	std::cout << find_nth_fibonacci(n);
}

int find_nth_fibonacci(int n, int _index, int _sum, int _prev) {
	if (n == 0) {
		return _sum;
	}

	return find_nth_fibonacci(n - 1, 0, _sum + _prev, _sum);
}
