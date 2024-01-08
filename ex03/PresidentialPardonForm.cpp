#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm(target, 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form)
: AForm(form)
{
	*this = form;
}

//copy assignment operator cannot change const member value
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &form)
{
	if (this == &form)
		return *this;
	this->setIsSigned(form.getIsSigned());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (AForm::getIsSigned() == false)
			throw NotSignedException();
		if (AForm::getGradeExecutable() < executor.getGrade())
			throw GradeTooLowException();
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}