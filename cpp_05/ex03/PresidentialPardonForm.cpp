#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

bool	PresidentialPardonForm::debug = false;

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:Form("Presidential Pardon Form", false, 25, 5), target(target)
{
	if (debug)
		std::cout << "Param PPF Ctor " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", false, 25, 5), target("")
{
	if (debug)
		std::cout << "Default PPF Ctor " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
:Form("Presidential Pardon Form", false, 25, 5), target(rhs.getTarget())
{
	if (debug)
		std::cout << "Copy. form Ctor " << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
//		this->name = rhs.getName(); =><= car name const
//		this->is_signed = rhs.getStatus();
//		this->sign_level = rhs.getSignLevel();
//		this->exec_level = rhs.getExecLevel();
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

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecLevel())
		throw Form::FormNotExecuted();
	else if (this->getStatus() == false)
		throw Form::FormNotSigned();
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
		return (true);
}
