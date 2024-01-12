#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &form);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;
};

#endif