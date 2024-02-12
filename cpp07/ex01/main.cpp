#include "iter.hpp"

template <typename T>
void plusOne(T &value) {
	value++;
}

int main( void ) {
	int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char charArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	double doubleArray[10] = {0.00, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09};

	std::cout << "Before iter" << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << charArray[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	::iter(intArray, 10, plusOne);
	::iter(charArray, 10, plusOne);
	::iter(doubleArray, 10, plusOne);

	std::cout << "After iter" << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << charArray[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

    return 0;
}