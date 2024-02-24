#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

// container에서 처음으로 등장하는 value 찾기
template <typename T>
typename T::iterator EasyFind(T &ctn, int value) {
    if (std::find(ctn.begin(), ctn.end(), value) == ctn.end())
        throw std::exception();
    return (std::find(ctn.begin(), ctn.end(), value));
}

#endif