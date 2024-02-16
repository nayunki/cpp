#include "iter.hpp"

template <typename T>
void plusOne(T &value) {
	value++;
}

template <typename T>
void printArray(const T &value) {
	std::cout << "this is const " << value << ", ";
}

int main( void ) {
	int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char charArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	double doubleArray[10] = {0.00, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09};

	std::cout << "\nBefore iter" << std::endl;

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

	// plue one

	::iter(intArray, 10, plusOne<int>);
	::iter(charArray, 10, plusOne<char>);
	::iter(doubleArray, 10, plusOne<double>);

	std::cout << "\nAfter iter" << std::endl;

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

	// print array

	std::cout << "\nAfter second iter" << std::endl;

	::iter(intArray, 10, printArray<int>);
	std::cout << std::endl;
	::iter(charArray, 10, printArray<char>);
	std::cout << std::endl;
	::iter(doubleArray, 10, printArray<double>);
	std::cout << std::endl;

    return 0;
}