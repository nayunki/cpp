#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T1, typename T2>
void iter(T1 *addr, size_t len, T2 func) {
	for (size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
}

#endif