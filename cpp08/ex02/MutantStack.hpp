#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack {
private:
    std::stack<T> ms;
public:
    MutantStack();
    MutantStack(const MutantStack & obj);
    MutantStack & operator=(const MutantStack & obj);
    ~MutantStack();
    push(int num);
    pop();
    size();
    top();
    begin();
    end();
};

#endif