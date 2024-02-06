#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T1, typename T2, typename T3>
void iter(T1 addr, T2 len, T3 func) { // type T1, T2, T3 are different
	for (int i = 0; i < len; i++) {
		func(*addr);
		addr++;
	}
}

template <>
void iter(int *addr, int len, int (*func)(int)) {
	for (int i = 0; i < len; i++) {
		func(addr[i]);
	}
}

template <typename T>
void plusOne(T &value) {
	value++;
}

#endif