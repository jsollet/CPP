#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception> 
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const std::string &Name, bool is, unsigned int sl, unsigned int el);
		Form(const Form &rhs);
		Form &operator=(const Form &rhs);
		virtual ~Form();

		const std::string	&getName() const;
		bool				getStatus() const;
		unsigned int		getSignLevel() const;
		unsigned int		getExecLevel() const;
		bool				beSigned(const Bureaucrat &bureaucrat);

		virtual bool		execute(const Bureaucrat &executor) const = 0;

		void				check() const;
		static bool			debug;
	private:
		const std::string				name;
		bool							is_signed;
		unsigned int					sign_level;
		unsigned int					exec_level;


	public:
		class	GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade: too high for signing");
			}
		} tooHigh;
	

		
	public:
		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade: too low for signing");
			}
		} tooLow;

	public:
		class	FormNotSigned: public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Form: not signed");
			}
		} notSigned;

	public:
		class	FormNotExecuted: public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Form: Bureaucrat level too low");
			}
		} FormNotExec;
	

};

std::ostream &operator<<(std::ostream &os, Form const &rhs);

#endif
