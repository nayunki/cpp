#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *addr, int len, void *func) {
	for (int i = 0; i < len; i++) {
		func(addr[i]);
		addr++;
	}
}

#endif