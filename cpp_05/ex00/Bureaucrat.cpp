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

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}

