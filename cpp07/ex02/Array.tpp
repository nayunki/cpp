#include "Array.hpp"

Array::Array() {
	T *array = new T[];
}

Array::Array(unsigned int n) {
	T *array = new T[n];

}

Array & Array::operator=(const Array & obj) {
	for (size_t i = 0; i < obj.size(); i++) {
		this->array[i] = obj.array[i];
	}
	return (*this);
}

Array::Array(const Array & obj) {
	*this = obj;
}

Array::~Array() {
	delete[] array;
}

size_t Array::size() const {
	return (this->array.size());
}

T & Array::operator[](const size_t index) {
	if (index >= this->size())
		throw();
	return (this->array[index]);
}