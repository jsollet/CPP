#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("bestiole")
{
	std::cout << std::endl << "Default constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string name): type(name)
{
	std::cout << std::endl << "Constructor animal type "<< this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs): type(rhs.type)
{
	std::cout << std::endl << "Copy Constructor animal type "<< this->type << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << std::endl << "(WrongAnimal) Operator = : " << this->type << " = ";
	std::cout << rhs.getType() << std::endl;
	this->type = rhs.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<  "Destructor  WrongAnimal " << this->type << std::endl;
}

const std::string	WrongAnimal::getType(void) const {return (this->type); }

void  WrongAnimal::makeSound(void) const 
{
	std::cout << std::endl << "(Wrong Animal) Slackk " << std::endl;
}
