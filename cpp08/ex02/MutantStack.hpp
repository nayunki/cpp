#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack(){};
    MutantStack(const MutantStack & obj){*this = obj;};
    MutantStack & operator=(const MutantStack & obj){
        if (this != &obj)
            this->c = obj.c;
        return *this;
    };
    ~MutantStack(){};
    typedef typename std::stack<T>::container_type::iterator                iterator;
    typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	iterator begin(void) {return this->c.begin();}
	iterator end(void) {return this->c.end();}
	const_iterator cbegin(void) {return this->c.begin();}
	const_iterator cend(void) {return this->c.end();}
	reverse_iterator rbegin(void) {return this->c.rbegin();}
	reverse_iterator rend(void) {return this->c.rend();}
	const_iterator crbegin(void) {return this->c.rbegin();}
	const_iterator crend(void) {return this->c.rend();}
};

#endif