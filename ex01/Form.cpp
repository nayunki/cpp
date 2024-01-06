#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
: gradeSignable(150), gradeExecutable(150)
{
}

Form::Form(std::string name, unsigned int gradeSignable, unsigned int gradeExecutable)
: name(name), gradeSignable(gradeSignable), gradeExecutable(gradeExecutable)
{
	if (gradeSignable < 1 || gradeExecutable < 1)
		throw GradeTooHighException();
	if (gradeSignable > 150 || gradeExecutable > 150)
		throw GradeTooLowException();
	this->isSigned = false;
}

Form::Form(Form const &form)
: gradeSignable(form.getGradeSignable()), gradeExecutable(form.getGradeExecutable())
{
	*this = form;
}

//copy assignment operator cannot change const member value
Form &Form::operator=(Form const form)
{
	if (this == &form)
		return *this;
	this->isSigned = form.isSigned;
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->name);
}

unsigned int Form::getGradeSignable() const
{
	return (this->gradeSignable);
}

unsigned int Form::getGradeExecutable() const
{
	return (this->gradeExecutable);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat &bu)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException\n";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", Form gradeSignable " << form.getGradeSignable() 
		<< ", Form gradeExecutable " << form.getGradeExecutable() << ", Form isSigned " <<
		form.getIsSigned() << ".";
	return (out);
}