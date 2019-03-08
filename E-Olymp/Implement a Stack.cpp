#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <stack>

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
	std::stack<int> stack;

	long n;
	scanf("%ld", &n);

	long instr, val;
	for (long i = 0; i < n; i++) {
		scanf("%ld", &instr);

		if (instr == 1) {
			scanf("%ld", &val);
			stack.push(val);
		} else {
			printf("%ld\n", stack.top());
			stack.pop();
		}
	}
}
