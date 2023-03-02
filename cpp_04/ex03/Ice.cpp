#include "Ice.hpp"
#include <iostream>
#include <string>

// peut etre pas besoin du constructeur parametré...
// ice n'a pas d'attribut..

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

// cree une nvlle instancei (ptr) dont le contenu est celui de l'original
Amateria	*Ice::clone() const
{
	return(new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << "  *" << std::endl;
}
