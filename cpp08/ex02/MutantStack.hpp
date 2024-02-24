#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack(){};
    MutantStack(const MutantStack & obj): std::stack<T>(obj) {};
    MutantStack & operator=(const MutantStack & obj){
        *this = obj;
        return *this;
    };
    ~MutantStack(){};
    typedef typename std::stack<T>::container_type::iterator                iterator;
    typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	iterator begin(void) {return this->c.begin();}
	iterator end(void) {return this->c.end();}
	const_iterator cbegin(void) {return this->c.cbegin();}
	const_iterator cend(void) {return this->c.cend();}
	reverse_iterator rbegin(void) {return this->c.rbegin();}
	reverse_iterator rend(void) {return this->c.rend();}
	const_iterator crbegin(void) {return this->c.crbegin();}
	const_iterator crend(void) {return this->c.crend();}
};

#endif