#include "Intern.hpp"
#include <iostream>


bool	Intern::debug = false;

Intern::Intern()
{
//	this->formName[0] = "shrubbery creation";
//	this->formName[1] = "robotomy request";
//	this->formName[2] = "presidential pardon";
	if (Intern::debug)
		std::cout << "Default constructor Intern" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	*this = rhs;//https://stackoverflow.com/questions/21614491/utilizing-copy-constructor-for-overloading
	if (Intern::debug)
		std::cout << "Copy. constructor Intern" << std::endl;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	if (Intern::debug)
		std::cout << "Op =  Intern" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	if (Intern::debug)
		std::cout << "Destructor  Intern" << std::endl;
}

Form	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int		index = 0;
	Form 	*notDefined = NULL;
	while (index < 3)
	{
		if (form.compare(formName[index]) == 0)
			break;
		index++;
	}
	switch(index){
		case 0:
		{
			std::cout << "Intern creates "<< formName[0] << std::endl;
			return(new ShrubberyCreationForm(target));
		}
		break ;
		case 1:
		{
			std::cout << "Intern creates "<< formName[1] << std::endl;
			return(new RobotomyRequestForm(target));
		}
		break;
		case 2:
		{
			std::cout << "Intern creates "<< formName[2] << std::endl;
			return(new PresidentialPardonForm(target));
		}
		break;
		default:
		{
			std::cout << "Form "<< form<< " has not been created because it doesn't exist"<< std::endl;
			return (notDefined);
		}
	}
}
