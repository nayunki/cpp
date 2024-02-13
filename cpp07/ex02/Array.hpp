#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
    T *array;
	unsigned int sizeOfArray;
public:
    Array() {
		T *array = new T[0];
		sizeOfArray = 0;
	}
    Array(unsigned int n) {
		T *array = new T[n];
		sizeOfArray = n;
		std::cout << array << std::endl;
	}
    Array & operator=(const Array & obj) {
		delete[] this->array;
		this->array = new T[obj.size()];
		for (unsigned int i = 0; i < obj.size(); i++) {
			this->array[i] = obj.array[i];
		}
		this->sizeOfArray = obj.size();
		return (*this);
	}
    Array(const Array & obj) {
		*this = obj;
	}
    ~Array() {
		delete[] array;
	}
	unsigned int size() const {
		return (this->sizeOfArray);
	}
	T & operator[](unsigned int index) {
		if (index >= this->sizeOfArray)
			throw std::exception();
		return (this->array[index]);
	}
};

// # include "Array.tpp"
// declaration and definition of template class/function both should be in header file.
// in case you want to separate them, you can include .tpp file at the end of the header file. 

#endif