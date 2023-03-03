#include "Cure.hpp"
#include <iostream>
#include <string>

Cure::Cure():AMateria("cure")
{
	std::cout << "Default constructor Cure" << std::endl;
}

Cure::Cure(const std::string type):AMateria(type)
{
	std::cout << "Param constructor Cure" << std::endl;
}

Cure::Cure(const Cure &rhs):AMateria(rhs)
{
	std::cout << "Copy constructor Cure" << std::endl;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getType();
	}
	std::cout << "Op = Cure" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor  Cure" << std::endl;
}

AMateria	*Cure::clone() const
{
	return(new Cure(*this));
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals "<< target.getName() << "'s wounds  *" << std::endl;
}
