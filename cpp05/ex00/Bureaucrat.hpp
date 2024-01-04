#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <exception>

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
		class	GradeTooHighException : public std::exception {
			const char *what() const noexcept
			{
				return "GradeTooHighException\n";
			}
		};
		class	GradeTooLowException : public std::exception {
			const char *what() const noexcept
			{
				return "GradeTooLowException\n";
			}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bu);

#endif