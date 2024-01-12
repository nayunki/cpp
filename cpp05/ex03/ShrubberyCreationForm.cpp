#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("shrubbery creation form", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form)
: AForm(form)
{
	*this = form;
}

//copy assignment operator cannot change const member value
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form)
{
	if (this == &form)
		return *this;
	this->setIsSigned(form.getIsSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (AForm::getIsSigned() == false)
			throw NotSignedException();
		if (AForm::getGradeExecutable() < executor.getGrade())
			throw GradeTooLowException();
		std::string name = target + "_shrubbery";
		std::ofstream ofs(name);
		ofs << "	*\n   /.\\\\\n  /o..\\\\\n  /..o\\\\\n /.o..o\\\\\n /...o.\\\\\n/..o....\\\\\n^^^[_]^^^";
		ofs << std::endl;
		ofs.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}