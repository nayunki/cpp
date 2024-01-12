#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, unsigned int gradeSignable, unsigned int gradeExecutable)
: name(name), gradeSignable(gradeSignable), gradeExecutable(gradeExecutable)
{
	if (gradeSignable < 1 || gradeExecutable < 1)
		throw GradeTooHighException();
	if (gradeSignable > 150 || gradeExecutable > 150)
		throw GradeTooLowException();
	this->isSigned = false;
}

AForm::AForm(AForm const &form)
: gradeSignable(form.getGradeSignable()), gradeExecutable(form.getGradeExecutable())
{
	*this = form;
}

//copy assignment operator cannot change const member value
AForm &AForm::operator=(AForm const &form)
{
	if (this == &form)
		return *this;
	this->isSigned = form.isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return (this->name);
}

const unsigned int AForm::getGradeSignable() const
{
	return (this->gradeSignable);
}

const unsigned int AForm::getGradeExecutable() const
{
	return (this->gradeExecutable);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

void AForm::setIsSigned(bool sign)
{
	this->isSigned = sign;
}

void AForm::beSigned(const Bureaucrat &bu)
{
	try
	{
		if (bu.getGrade() > this->gradeSignable)
			throw GradeTooLowException();
		this->isSigned = true;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException\n";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException\n";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "NotSignedException\n";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << ", Form gradeSignable " << form.getGradeSignable() 
		<< ", Form gradeExecutable " << form.getGradeExecutable() << ", Form isSigned " <<
		form.getIsSigned() << ".";
	return (out);
}