#include "Form.hpp"

Form::Form()
{
	name = "";
	isSigned = false;
	gradeSignable = 1;
	gradeExecutable = 1;
}

Form::Form(std::string name, unsigned int gradeSignable, unsigned int gradeExecutable)
{
	try
	{
		if (gradeSignable < 1 || gradeExecutable < 1)
			throw GradeTooHighException();
		if (gradeSignable > 150 || gradeExecutable > 150)
			throw GradeTooLowException();
		this->name = name;
		this->gradeSignable = gradeSignable;
		this->gradeExecutable = gradeExecutable;
		this->isSigned = false;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(Form const &form)
{
	*this = form;
}

Form &Form::operator=(Form const form)
{
	if (this == &form)
		return *this;
	this->name = form.name;
	this->gradeSignable = form.gradeSignable;
	this->gradeExecutable = form.gradeExecutable;
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
		if (bu.getGrade() < this->gradeSignable)
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
	return ("grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", Form gradeSignable " << form.getGradeSignable() 
		<< ", Form gradeExecutable " << form.getGradeExecutable() << ", Form isSigned " <<
		form.getIsSigned() << ".";
	return (out);
}