#include "Form.hpp"

bool	Form::debug = false; 

Form::Form():name(""), is_signed(false), sign_level(150), exec_level(150)
{
	if (debug)
		std::cout << "Default form Ctor " << std::endl;
}


Form::Form(const std::string &Name, bool is, unsigned int sl, unsigned int el)
	:name(Name), is_signed(is), sign_level(sl), exec_level(el)
{
	check();
	if (debug)
		std::cout << "Param. form Ctor " << std::endl;
}

Form::Form(const Form &rhs)
	:name(rhs.getName()), is_signed(rhs.getStatus()), sign_level(rhs.getSignLevel()), exec_level(rhs.getExecLevel())
{
	if (debug)
		std::cout << "Copy. form Ctor " << std::endl;
}

Form	&Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->is_signed = rhs.getStatus();
		this->sign_level = rhs.getSignLevel();
		this->exec_level = rhs.getExecLevel();
	}
	if (debug)
		std::cout << "Copy. form Ctor " << std::endl;
	return (*this);
}

Form::~Form()
{
	if (debug)
		std::cout << "Form Dtor " << std::endl;
}

// les getter...

const std::string		&Form::getName() const
{
	return (this->name);
}

bool					getStatus() const
{
	return (this->is_signed);
}

unsigned int			getSignLevel() const
{
	return (this->sign_level);
}

unsigned int			getExecLevel() const
{
	return (this->exec_level);
}
// verifie (bool)
bool					beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < this->getSignLevel())
		this->is_signed = true;
	else throw Form::tooLow;
}
// attn
void	Form::check() const
{
	if (this->sign_level < Bureaucrate::highest || this->sign_level > Bureaucrat::lowest)
		throw Bureaucrat::tooHigh;
	if (this->exec_level < Bureaucrate::highest || this->exec_level > Bureaucrat::lowest)
		throw Bureaucrat::tooHigh;
}

std::ostream	&operator<<(std::ostream &os, Form const &rhs)
{
	os <<"Form:\t"<< rhs.getName() << std::endl << "Signed\t"<< rhs.getStatus() << std::endl;
	os << "Sign level:\t" << rhs.getSignLevel() << std::endl << "Exec level:\t" <<rhs.getExecLevel() <<std::endl;
	return (os);
}

