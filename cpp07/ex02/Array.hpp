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
    Array() : array(NULL), sizeOfArray(0) {
	}
    Array(int n) {
        if (n < 0)
            throw std::exception();
        sizeOfArray = n;
		array = new T[sizeOfArray];
	}
    Array & operator=(const Array & obj) {
        if (this != &obj) {
            if (this->sizeOfArray)
                delete[] this->array;
            this->sizeOfArray = obj.size();
            this->array = new T[sizeOfArray];
            for (unsigned int i = 0; i < sizeOfArray; i++) {
                this->array[i] = obj.array[i];
            }
        }
		return (*this);
	}
    Array(const Array & obj) : array(NULL), sizeOfArray(0) {
		*this = obj;
	}
    ~Array() {
		delete[] this->array;
        this->array = NULL;
        this->sizeOfArray = 0;
	}
	unsigned int size() const {
		return (this->sizeOfArray);
	}
	T & operator[](unsigned int index) const {
		if (index >= this->sizeOfArray)
			throw std::exception();
		return (this->array[index]);
	}
};

// # include "Array.tpp"
// declaration and definition of template class/function both should be in header file.
// in case you want to separate them, you can include .tpp file at the end of the header file. 

#endif