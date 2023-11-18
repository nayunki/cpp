#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool	isSigned;
		const unsigned int	gradeSignable;
		const unsigned int	gradeExecutable;
	public:
		Form();
		Form(std::string name, unsigned int gradeSignable, unsigned int gradeExecutable);
		Form(Form const &form);
		Form &operator=(Form const form);
		~Form();
		std::string getName() const;
		unsigned int getGradeSignable() const;
		unsigned int getGradeExecutable() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat &bu);
		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif