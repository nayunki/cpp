#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
private:
    std::stack<int> numbers;
    int topAndPop();
    int calculate(int a, int b, char oper);
    void printStack();
public:
    RPN();
    RPN(const RPN & obj);
    RPN & operator=(const RPN & obj);
    ~RPN();
    void execute(const std::string & input);
	class	invalidInput : public std::exception {
		const char *what() const throw();
	};
	class	divideByZero : public std::exception {
		const char *what() const throw();
	};
};

#endif