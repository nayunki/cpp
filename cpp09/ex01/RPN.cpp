#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & obj) {
    *this = obj;
}

RPN & RPN::operator=(const RPN & obj) {
    if (this != &obj)
        this->numbers = obj.numbers;
    return *this;
}

RPN::~RPN() {}

const char *RPN::invalidInput::what() const throw() {
	return "Error";
}

int RPN::calculate(int b, int a, char oper) {
    if (oper == '+')
        return (a + b);
    else if (oper == '-')
        return (a - b);
    else if (oper == '*')
        return (a * b);
    else if (oper == '/')
        return (a / b);
    else
        throw invalidInput();
}

int RPN::topAndPop() {
    if (this->numbers.empty())
        throw invalidInput();
    int ret = this->numbers.top();
    this->numbers.pop();
    return ret;
}

void RPN::printStack() {
    std::stack<int> dup = this->numbers;
    while (!dup.empty()) {
        std::cout << dup.top() << " ";
        dup.pop();
    }
    std::cout << std::endl;
}

// 0으로 나누면 0됨 ;; c++엔 inf 있지않나?.......
void RPN::execute(const std::string & input) {
    // "7 7 * 7 -"
    // 숫자 : 스택에 push
    // 연산자 : 숫자 두개 꺼내서 계산 후, 결과를 다시 push

    // 홀수인덱스는 띄어쓰기인지 검사하는 로직 추가 ㅠㅠ

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ')
            ;
        else if ('0' <= input[i] && input[i] <= '9')
            this->numbers.push(input[i] - '0');
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            this->numbers.push(calculate(topAndPop(), topAndPop(), input[i]));
        else
            throw invalidInput();
    }
    if (this->numbers.size() % 2 != 1)
        throw invalidInput();
    std::cout << this->numbers.top() << std::endl;
}