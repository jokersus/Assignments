#include <stack>
#include <string>
#include <iostream>
#include <map>
#include <functional>

int main() {
	std::map<char, std::function<int(int, int)>> operations;

	operations['-'] = [](int x, int y) -> int { return y - x; };
	operations['+'] = [](int x, int y) -> int { return x + y; };
	operations['*'] = [](int x, int y) -> int { return x * y; };
	operations['/'] = [](int x, int y) -> int { return y / x; };

	std::stack<int> stack;

	char s[200];

	while (scanf("%s", s) == 1) {

		char temp = s[0];

		if (operations.find(temp) != operations.end()) {
			int x = stack.top(); stack.pop();
			int y = stack.top(); stack.pop();
			stack.push(operations[temp](x, y));
			continue;
		}

		stack.push(std::stoi(s));
	}

	printf("%d\n", stack.top());
}
