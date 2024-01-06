#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 10);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		Form e("e", 1, 1);
		Form f("f", 100, 100);

		std::cout << e << std::endl;
		std::cout << f << std::endl;
	
		a.signForm(e); // 얘 때문에 아래는 실행안댐 ㅎ
		b.signForm(e);
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}