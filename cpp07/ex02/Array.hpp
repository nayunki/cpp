#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
    T *array;
public:
    Array() {
		T *array = new T();
	}
    Array(unsigned int n) {
		T *array = new T[n];
	}
    Array(const Array & obj) {
		*this = obj;
	}
    Array & operator=(const Array & obj) {
		for (size_t i = 0; i < obj.size(); i++) {
			this->array[i] = obj.array[i];
		}
		return (*this);
	}
    ~Array() {
		delete[] array;
	}
	size_t size() const {
		return (this->array.length());
	}
	T & operator[](size_t index) {
		if (index >= this->size())
			throw std::exception();
		return (this->array[index]);
	}
};

// # include "Array.tpp"
// declaration and definition of template class/function both should be in header file.
// in case you want to separate them, you can include .tpp file at the end of the header file. 

#endif