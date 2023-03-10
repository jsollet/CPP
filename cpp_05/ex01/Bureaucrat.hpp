#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception> 

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &Name, unsigned int Grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		const std::string	&getName() const;
		unsigned int		getGrade() const;

		Bureaucrat 			&operator++();
		Bureaucrat			&operator--();
		Bureaucrat 			operator++(int);
		Bureaucrat			operator--(int);

		void				check() const;
		static bool			debug;
		
		static const unsigned int		lowest = 150;
		static const unsigned int		highest = 1;
	private:
		const std::string				name;
		unsigned int					grade;


	public:
		class	GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade: too high");
			}
		} tooHigh;
	
	public:
		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade: too low");
			}
		} tooLow;

};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif
