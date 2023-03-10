#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"


bool	RobotomyRequestForm::debug = false;



RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:Form("Robotomy Creation Form", false, 72, 45), target(target)
{
	if (debug)
		std::cout << "Param Robotomy  Ctor " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Creation Form", false, 72, 45), target("")
{
	if (debug)
		std::cout << "Default Robotomy Ctor " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
:Form("Robotomy Creation Form", false, 72, 45), target(rhs.getTarget())
{
	if (debug)
		std::cout << "Copy.Robotomy  form Ctor " << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
//		this->target = rhs.getTarget();
//		this->name = rhs.getName(); =><= car name const
//		this->is_signed = rhs.getStatus();
//		this->sign_level = rhs.getSignLevel();
//		this->exec_level = rhs.getExecLevel();
	}
	if (debug)
		std::cout << "Copy.Robotomy  form Ctor " << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (debug)
		std::cout << "RobotomyRequestForm Dtor " << std::endl;
}

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (debug)
	{
		//std::srand(std::time(NULL));//s ...
		int random_variable = std::rand();
		std::cout << "Random value on [0 " << RAND_MAX << "]: "  << random_variable << std::endl;
	}
	if (executor.getGrade() > this->getExecLevel())
		throw Form::FormNotExecuted();
	else if (this->getStatus() == false)
		throw Form::FormNotSigned();
	else
	{
		std::cout << " --- high-pitched drill noise --- " << std::endl;
		if (std::rand() % 2)
			std::cout << green << this->getTarget() << " has been successfully robotomized " << reset <<  std::endl;
		else
			std::cout << red << "The robotomy operation on "<< this->getTarget() << " failed, leaving the patient helpless !" << reset << std::endl;
	}
		return (true);
}
