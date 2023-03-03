#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria()
{
	std::cout << "Default constructor AMateria" << std::endl;
}

AMateria::AMateria(const std::string _name): name(_name)
{
	std::cout << "Param constructor AMateria" << std::endl;
}

AMateria::AMateria(const AMateria &mat): name(mat.getType())
{
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

AMateria::~AMateria() {}

std::string const 	&AMateria::getType() const
{
	return (this->name);
}
