#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
: name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &bu)
{
	*this = bu;
}

//copy assignment operator cannot change const member value
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bu)
{
	if (this == &bu)
		return *this;
	this->grade = bu.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

const unsigned int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increment()
{
	try {
		if (this->grade <= 1)
			throw GradeTooHighException();
		this->grade--;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrement()
{
	try {
		if (this->grade >= 150)
			throw GradeTooLowException();
		this->grade++;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException\n";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bu)
{
	out << bu.getName() << ", bureaucrat grade " << bu.getGrade() << ".";
	return (out);
}