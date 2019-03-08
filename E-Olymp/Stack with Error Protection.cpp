#include <stdio.h>
#include <cstdlib>
#include <cstring>

template <class T>
class Stack {
private:
	T *arr;
	size_t capacity;
	size_t current;

	void expand() {
		this->arr = (T *) realloc(this->arr, sizeof(T) * this->capacity * 2);
	}

public:
	Stack() {
		this->current = 0;
		this->capacity = 1;
		this->arr = new T[this->capacity];
	}

	int push(T val) {
		current++;
		if (this->current < this->capacity) {
			this->expand();
		}

		this->arr[current] = val;

		return val;
	}

	T pop() {
		if (this->empty()) {
			throw "Popped from empty Stack";
		}

		return this->arr[this->current--];
	}

	T top() {
		return arr[this->current];
	}

	bool empty() {
		return this->current == 0;
	}

	size_t size() {
		return this->current;
	}

	size_t clear() {
		size_t max = this->size();
		for (int i = 0; i < max; i++) {
			this->pop();
		}

		return max;
	}
};

int main() {
	Stack<int> stack;

	char arr[100];

	while(scanf("%s", arr)) {

		switch (arr[1]) {
			case 'x' : {
				printf("bye\n");
				return 0;
			}

			case 'o': {
				if (stack.empty()) {
					printf("error\n");
					break;
				}

				printf("%d\n", stack.pop());
				break;
			}

			case 'a': {
				if (stack.empty()) {
					printf("error\n");
					break;
				}

				printf("%d\n", stack.top());
				break;
			}

			case 'i': {
				printf("%d\n", stack.size());
				break;
			}

			case 'l': {
				stack.clear();
				printf("ok\n");
				break;
			}

			default: {
				int val;
				scanf("%d", &val);

				stack.push(val);

				printf("ok\n");
			}
		}
	}
}
