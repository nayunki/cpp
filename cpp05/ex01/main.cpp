#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("a", 1);
    Bureaucrat b("b", 10);

	Form e("e", 1, 1);
	Form f("f", 100, 100);

	std::cout << e << std::endl;

	a.signForm(e);
	b.signForm(e);
	b.signForm(f);

    return 0;
}