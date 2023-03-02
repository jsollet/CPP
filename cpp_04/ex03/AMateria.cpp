#include "AMateria.hpp"
#include <iostream>
#include <string>

// pas sur...

AMateria::AMateria()
{
	std::cout << "Default constructor AMateria" << std::endl;
}

AMateria::AMateria(const std::string _name): name(_name)
{
	std::cout << "Param constructor AMateria" << std::endl;
}
// a voir
AMateria::AMateria(const AMateria &mat): name(mat.getType())
{
//	this->name = mat.getType();
	std::cout << "Copy constructor AMateria" << std::endl;
}

AMateria 	&AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getType();
	}
	std::cout << "Op = AMateria" << std::endl;
	return (*this);
}

std::string	AMateria::getType()
{
	return (this->name);
}
// les deux virtuals dans ice et cure
