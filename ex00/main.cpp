#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bu("bu", 1);
		Bureaucrat cu("cu", 100);
		Bureaucrat du("du", 150);
		Bureaucrat eu("eu", 151); // 여기서 catch문으로 넘어감

		std::cout << bu << std::endl;
		std::cout << fu << std::endl;
		
		cu.increment();
		std::cout << cu << std::endl;

		bu.increment();
		std::cout << bu << std::endl;

		du.decrement();
		std::cout << du << std::endl;

		du.increment();
		std::cout << du << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}