#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

bool	PresidentialPardonForm::debug = false;

PresidentialPardonForm::PresidentialPardonForm()
	:name("Presidential Pardon Form"), is_signed(false),sign_level(25),
	exec_level(5), target("");
{
	if (debug)
		std::cout << "Default PPF Ctor " << std::endl;
}
// a faire...
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
	:name(rhs.getName()), is_signed(rhs.getStatus()), sign_level(rhs.getSignLevel()), exec_level(rhs.getExecLevel())
{
	if (debug)
		std::cout << "Copy. form Ctor " << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
	//	this->name = rhs.getName(); =><= car name const
		this->is_signed = rhs.getStatus();
		this->sign_level = rhs.getSignLevel();
		this->exec_level = rhs.getExecLevel();
	}
	if (debug)
		std::cout << "Copy. form Ctor " << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (debug)
		std::cout << "PresidentialPardonForm Dtor " << std::endl;
}
