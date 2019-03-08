#include <stdio.h>
#include <algorithm>

int main() {
	int n, *arr;

	scanf("%d", &n);
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int count = 0;
	int temp, temp_op;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1] && arr[i] < arr[i + 1]) {
			count += arr[i] - arr[i - 1];
		} else {
			temp = std::abs(arr[i + 1] - arr[i]) + std::abs(arr[i + 2] - arr[i + 1]);
			temp_op = 3 * std::abs(arr[i + 2] - arr[i]);
			if (temp_op < temp) {
				count += temp_op;
			} else {
				count += temp;
			}

			i += 2;
		}
	}

	printf("%d\n", count);
}
