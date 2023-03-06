#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>
#include <stdexcept> // pour les exception...
#include <exception> 
#include "bureaucrat.hpp"

class	Form
{// attn verifie...
	public:
		Form();
		Form(const std::string &Name, bool is, unsigned int sl, unsigned int el);// a voir
		Form(const Form &rhs);
		Form &operator=(const Form &rhs);
		~Form();

		const std::string	&getName() const;//
		bool				getStatus() const;
		unsigned int		getSignLevel() const;
		unsigned int		getExecLevel() const;
		bool				beSigned(Bureaucrat &bureaucrat);



//		unsigned int		getGrade() const;
/*
		Form 			&operator++();
		Form			&operator--();
		Form 			operator++(int);// doit etre  int...
		Form			operator--(int);
*/
		void				check() const;
		static bool			debug;// static-> partout
	private:
		const std::string				name;
		bool							is_signed;
		unsigned int					sign_level;
		unsigned int					exec_level;
//		unsigned int					grade;
//		static const unsigned int		lowest = 150;
//		static const unsigned int		highest = 1;

/*
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
*/
		
	public://nested class, ic c'est standardisé
		class	GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{// definition dans la class "mère"
				return ("Grade: too low for signing");
			}
		} tooLow;


};

std::ostream &operator<<(std::ostream &os, Form const &rhs); // ?

#endif
