#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T &ctn, int value) {
	typename T::iterator res = std::find(ctn.begin(), ctn.end(), value);
    if (res == ctn.end())
        throw std::exception();
    return (res);
}

#endif