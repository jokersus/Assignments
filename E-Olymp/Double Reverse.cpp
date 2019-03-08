// This does not work properly

#include <iostream>
#include <set>

int main() {
	int counter = 0;
	int limit, a, b, c, d;
	std::set<int> set;

	std::cin >> limit >> a >> b >> c >> d;

	// Print lone values
	for (int i = 1; i < a; i++) {
		counter++;
		set.insert(i);
		std::cout << i << ' ';
	}

	// For later use
//	for (int i = d; i <= limit; i++) {
//		std::cout << i << ' ';
//	}
	// ----------------------------------------------

	if (c - b <= 0) {    // If there is an overlap
		for (int i = a, overlap = b; i < c; i++, overlap--) {    // OVERLAP OUT
			counter++;
			set.insert(overlap);
			std::cout << overlap << ' ';
		}

		// 2 OUT
		for (int i = d; i > b; i--) {
			counter++;
			set.insert(i);
			std::cout << i << ' ';
		}

		// 1 OUT
		for (int i = 0, it = a; i <= d - b - 1; i++, it++) {
			counter++;
			set.insert(it);
			std::cout << it << ' ';
		}

		// I don't know what this does
//		if ((b - a) - ((d - c) - (b - a))) {
//			for (int i = 0, it = c; i <= (b - a) - ((d - c) - (b - a)); i++, it++) {
////				std::cout << "yes" << '\n';
//				std::cout << it << ' ';
//			}
//		}

//		for (int i = 0, it = c - 1; i <= (limit - counter) - (limit - d); i++, it++) {
//		for (int i = 0, it = d; i < limit - counter - 1; i++, it++) {
//			std::cout << it << ' ';
//		}

		for (int i = 1; i <= limit; i++) {
			if (set.find(i) == set.end()) {
				std::cout << i << ' ';
			}
		}

		// REST
		for (int i = d + 1; i <= limit; i++) {
//			std::cout << i << ' ';
		}

		// OVERLAP REST
//		for (int i = a; i < ; i++) {
//			std::cout << i << ' ';
//		}

		// LONE 2
//		for (int i = d; i < limit; i++) {
//			std::cout << i << ' ';
//		}

		return 0;

	} else {
		for (int i = b; i >= a; i--) {
			std::cout << i << ' ';
		}

		for (int i = d; i >= c; i--) {
			std::cout << i << ' ';
		}

		for (int i = d + 1; i <= limit; i++) {
			std::cout << i << ' ';
		}

		return 0;
	}
}
