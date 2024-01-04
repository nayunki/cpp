#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bu("bu", 1);
    Bureaucrat cu("cu", 100);
    Bureaucrat du("du", 150);
	// Bureaucrat eu("eu", 151);
	// Bureaucrat fu("fu", 0);
	// grade가 문자열로 들어오는 거, 이름이 숫자로 들어오는 거 어케잡음 -> 못잡겠오 ㅎㅎ
	// 생성자 내부에서 try catch 썼는데 생성이 왜됨 .............

	std::cout << bu << std::endl;
	// std::cout << eu << std::endl;
	// std::cout << fu << std::endl;
	
	cu.increment();
	std::cout << cu << std::endl;

	bu.increment();
	std::cout << bu << std::endl;

	du.decrement();
	std::cout << du << std::endl;

	du.increment();
	std::cout << du << std::endl;

    return 0;
}