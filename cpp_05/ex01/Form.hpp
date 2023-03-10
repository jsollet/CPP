#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception> 
#include "bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const std::string &Name, bool is, unsigned int sl, unsigned int el);
		Form(const Form &rhs);
		Form &operator=(const Form &rhs);
		~Form();

		const std::string	&getName() const;
		bool				getStatus() const;
		unsigned int		getSignLevel() const;
		unsigned int		getExecLevel() const;
		bool				beSigned(Bureaucrat &bureaucrat);

		void				check() const;
		static bool			debug;
	private:
		const std::string				name;
		bool							is_signed;
		unsigned int					sign_level;
		unsigned int					exec_level;
		
	public:
		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade: too low for signing");
			}
		} tooLow;


};

std::ostream &operator<<(std::ostream &os, Form const &rhs);

#endif
