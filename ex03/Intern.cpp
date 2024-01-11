#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
	(void)intern;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formType[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i = 0;
	while (i < 3)
	{
		if (name == formType[i])
		{
			std::cout << "Intern creates " << formType[i] << std::endl;
			break;
		}
		i++;
	}
	switch (i)
	{
	case 0:
		return new ShrubberyCreationForm(target);
	case 1:
		return new RobotomyRequestForm(target);
	case 2:
		return new PresidentialPardonForm(target);
	default:
		throw InvalidName();
	}
}

const char *Intern::InvalidName::what() const throw()
{
	return "InvalidName\n";
}