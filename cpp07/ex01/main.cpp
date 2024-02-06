#include "iter.hpp"

void function(int &a) {
	a++;
}

int main( void ) {
	int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char charArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	double doubleArray[10] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09};

	::iter(intArray, 10, function);
	::iter(charArray, 10, function);
	::iter(doubleArray, 10, function);

    return 0;
}