#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice():AMateria("ice")
{
	std::cout << "Default constructor Ice" << std::endl;
}

Ice::Ice(const std::string type):AMateria(type)
{
	std::cout << "Param constructor Ice" << std::endl;
}

Ice::Ice(const Ice &rhs):AMateria(rhs)
{
	std::cout << "Copy constructor Ice" << std::endl;
}

Ice	&Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getType();
	}
	std::cout << "Op = Ice" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor  Ice" << std::endl;
}

AMateria	*Ice::clone() const
{
	return(new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << "  *" << std::endl;
}
