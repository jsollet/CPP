#include "Bureaucrat.hpp"

bool	Bureaucrat::debug = false;

Bureaucrat::Bureaucrat(): name(""), grade(150)
{
	if (Bureaucrat::debug)
		std::cout << "Default constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name, unsigned int Grade)
	:name(Name), grade(Grade)
{
	check();
	if (Bureaucrat::debug)
		std::cout << "Param. constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs): name(rhs.getName()),
grade(rhs.getGrade())
{
	if (Bureaucrat::debug)
		std::cout << "Copy. constructor Bureaucrat" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->grade = rhs.getGrade();
	}
	if (Bureaucrat::debug)
		std::cout << "Op =  Bureaucrat" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (Bureaucrat::debug)
		std::cout << "Destructor  Bureaucrat" << std::endl;
}

const std::string	&Bureaucrat::getName() const
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->grade);
}

Bureaucrat	&Bureaucrat::operator++()
{
	--grade;
	check();
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--()
{
	++grade;
	check();
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat tmp(*this);
	operator++();
	return (tmp);
}


Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat tmp(*this);
	operator--();
	return (tmp);
}

void	Bureaucrat::check() const
{
	if (this->grade < Bureaucrat::highest)
		throw Bureaucrat::tooHigh;
	if (this->grade > Bureaucrat::lowest)
		throw Bureaucrat::tooLow;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		std::cout << magenta;
		if (form.beSigned(*this) == false)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		std::cout << reset;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " could't sign " << form.getName() \
		<< " because " << e.what() << reset << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form &form)
{
	try
	{
		std::cout << cyan;
		if (form.getStatus() == false)
			throw Form::FormNotSigned(); 
		if (form.execute(*this) == false)
			throw Form::FormNotExecuted();
		std::cout << this->getName() << " executed " << form.getName() \
		   	<< reset << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " could't execute " << form.getName() \
		<< " because " << e.what() << reset << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << yellow << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() <<
	reset;
	return (os);
}

