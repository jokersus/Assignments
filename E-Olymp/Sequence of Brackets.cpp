#include <stdio.h>
#include <stack>

#define SIZE 256

int main() {
	char arr[SIZE];

	std::stack<char> st;

	char c = 1;

	while (scanf("%c", &c), c != 10) {
		if (c == ')') {
			if (st.empty()) {
				printf("no");
				return 0;
			}

			if (st.top() == '(') {
				st.pop();
				continue;
			}
		}

		if (c == '}') {
			if (st.empty()) {
				printf("no");
				return 0;
			}

			if (st.top() == '{') {
				st.pop();
				continue;
			}
		}

		if (c == ']') {
			if (st.empty()) {
				printf("no");
				return 0;
			}

			if (st.top() == '[') {
				st.pop();
				continue;
			}
		}

		st.push(c);
	}

	printf(st.empty() ? "yes" : "no");
}
