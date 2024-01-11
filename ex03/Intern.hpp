#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class	Intern
{
public:
	Intern();
	Intern(Intern const &intern);
	Intern &operator=(Intern const &intern);
	~Intern();
	AForm *makeForm(std::string name, std::string target);
	class	InvalidName : public std::exception {
		const char *what() const throw();
	};
};

#endif