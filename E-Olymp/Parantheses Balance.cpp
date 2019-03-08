#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>

int main() {
	int n;
	char c = 1;
	std::string string;
	std::stack<char> st;

	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		std::getline(std::cin, string);

		for (int j = 0; j < string.length(); j++) {
			c = string[j];
			if (c == ')') {
				if (st.empty()) {
					st.push('a');
					break;
				}

				if (st.top() == '(') {
					st.pop();
					continue;
				}
			}

			if (c == ']') {
				if (st.empty()) {
					st.push(-1);
					break;
				}

				if (st.top() == '[') {
					st.pop();
					continue;
				}
			}

			st.push(c);
		}

		printf(st.empty() ? "Yes\n" : "No\n");

		while (!st.empty()) {
			st.pop();
		}
	}
}
