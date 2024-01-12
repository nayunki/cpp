#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 1);
		std::cout << a << std::endl;

		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		//Shrubbery sign : 145, exec : 137
		//Robotomy sign : 72, exec : 45
		//Presidential sign : 25, exec : 5

		a.signForm(*rrf);
		rrf->execute(a);

		AForm *err;
		err = someRandomIntern.makeForm("is not a form", "Bender");
		// a.signForm(err);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}