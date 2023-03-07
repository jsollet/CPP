#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept> // pour les exception...
#include <exception> 

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &Name, unsigned int Grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		const std::string	&getName() const;//
		unsigned int		getGrade() const;

		Bureaucrat 			&operator++();
		Bureaucrat			&operator--();
		Bureaucrat 			operator++(int);// doit etre  int...
		Bureaucrat			operator--(int);

		void				check() const;
		static bool			debug;// static-> partout
		
		static const unsigned int		lowest = 150;
		static const unsigned int		highest = 1;
	private:
		const std::string				name;
		unsigned int					grade;


	public://nested class, ic c'est standardisé
		class	GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{// definition dans la class "mère"
				return ("Grade: too high");
			}
		} tooHigh;
	
	public://nested class, ic c'est standardisé
		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{// definition dans la class "mère"
				return ("Grade: too low");
			}
		} tooLow;

};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs); // ?

#endif
