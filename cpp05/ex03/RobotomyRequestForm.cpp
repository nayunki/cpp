#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("robotomy request form", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form)
: AForm(form)
{
	*this = form;
}

//copy assignment operator cannot change const member value
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form)
{
	if (this == &form)
		return *this;
	this->setIsSigned(form.getIsSigned());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (AForm::getIsSigned() == false)
			throw NotSignedException();
		if (AForm::getGradeExecutable() < executor.getGrade())
			throw GradeTooLowException();
		std::cout << "DRRRRRRRRRRR\nDRRRRRRRRRRR\nDRRRRRRRRRRR" << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully !" << std::endl;
		else
			std::cout << this->target << " robotomy failed :/" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}