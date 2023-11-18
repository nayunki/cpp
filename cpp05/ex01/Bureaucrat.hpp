#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>
# include "Form.hpp"

class	Bureaucrat
{
	private:
		const std::string name;
		unsigned int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &bu);
		Bureaucrat &operator=(Bureaucrat const bu);
		~Bureaucrat();
		std::string getName() const;
		unsigned int getGrade() const;
		void increment();
		void decrement();
		void signForm(Form &formToBeSigned);
		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bu);

#endif