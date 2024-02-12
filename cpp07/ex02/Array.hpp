#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
    T array[];
public:
    Array();
    Array(unsigned int n);
    Array(const Array & obj);
    Array & operator=(const Array & obj);
    ~Array();
};

#endif