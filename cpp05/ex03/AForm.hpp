#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool	isSigned;
	const unsigned int	gradeSignable;
	const unsigned int	gradeExecutable;
public:
	AForm(std::string name, unsigned int gradeSignable, unsigned int gradeExecutable);
	AForm(AForm const &form);
	AForm &operator=(AForm const &form);
	virtual ~AForm();
	const std::string getName() const;
	const unsigned int getGradeSignable() const;
	const unsigned int getGradeExecutable() const;
	bool getIsSigned() const;
	void setIsSigned(bool sign);
	void beSigned(const Bureaucrat &bu);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class	GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class	NotSignedException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif