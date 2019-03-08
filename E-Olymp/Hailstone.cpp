#include <iostream>
#include <thread>

int calculate_hailstone(int n, int max = 0, int _ = 0);
void *spawn_hailstone_task(int index, int n, int arr[]);

int main() {
	// C++ std::cin patch
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	int *arr;

	std::cin >> n;
	arr = new int[n + 1];
	std::thread threads[n + 1];

	for (int i = 1, temp_index, temp_value; i <= n; i++) {
		std::cin >> temp_index >> temp_value;
		threads[i] = std::thread(spawn_hailstone_task, temp_index, temp_value, arr);
	}

	for (int i = 1, temp; i <= n; i++) {
		threads[i].join();
	}

	for (int i = 1, temp_index, temp_value; i <= n; i++) {
		std::cin >> temp_index >> temp_value;
		arr[temp_index] = calculate_hailstone(temp_value);
	}
}

int calculate_hailstone(int n, int max, int _) {

	if (max == 0) {
		return calculate_hailstone(n, n, n - 1);
	}

	if (n & (_) == 0) {		// If power of 2
		return max;
	}

	if (n & 1) {			// If odd
		return calculate_hailstone(n * 3 + 1, (n * 3 + 1 > max) ? n * 3 + 1 : max, n * 3);
	}

	return calculate_hailstone(n / 2, (n / 2 > max) ? n / 2 : max, n / 2 - 1);
}

void *spawn_hailstone_task(int index, int n, int arr[]) {
	arr[index] = calculate_hailstone(n);
}
