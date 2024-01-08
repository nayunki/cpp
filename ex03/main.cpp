#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 140);
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		//Shrubbery sign : 145, exec : 137
		//Robotomy sign : 72, exec : 45
		//Presidential sign : 25, exec : 5

		ShrubberyCreationForm shu("tar");
		//b는 사인 가능, 실행 불가능
		b.signForm(shu);
		shu.execute(b);

		RobotomyRequestForm rob("rob");
		a.signForm(rob);
		rob.execute(a);

		PresidentialPardonForm pre("tod");
		a.signForm(pre);
		pre.execute(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}