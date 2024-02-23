#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

// container에서 처음으로 등장하는 value 찾기
template <typename T>
typename T::iterator EasyFind(T &ctn, int value) {
    for (typename T::iterator it = ctn.begin(); it != ctn.end(); it++) {
        if (*it == value)
            return (it);
    }
    throw std::exception();
}

#endif