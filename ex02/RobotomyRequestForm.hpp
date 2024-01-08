#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>

class	RobotomyRequestForm : public AForm
{
private:
	const std::string target;
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &form);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &form);
	~RobotomyRequestForm();
	void execute(Bureaucrat const &executor) const;
};

#endif