#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	const std::string target;
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &form);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &form);
	~PresidentialPardonForm();
	void execute(Bureaucrat const &executor) const;
};

#endif