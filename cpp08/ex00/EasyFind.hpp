#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>

template <typename T>
int EasyFind(T container, int value) {
    for (T::iterator it = T.begin(); it != T.end(); it++) {
        if (it == value)
            return (it);
    }
    throw std::exception();
}

#endif