#include <cstdio>
#include <stack>

int main() {
	int n;
	std::stack<int> stack;

	scanf("%d", &n);

	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		if (stack.empty()) {
			stack.push(temp);
			continue;
		}

		if (temp == stack.top()) {
			stack.push(temp);
			continue;
		}

		stack.pop();
	}

	if (stack.empty()) {
		printf("-1\n");
		return 0;
	}

	int count = 0;
	int max = stack.top();
	for (int i = 0; i < n; i++) {
		if (max == arr[i]) {
			count++;
		}
	}

	if (count * 2 > n) {
		printf("%d\n", max);
	} else {
		printf("-1\n");
	}

	return 0;
}
