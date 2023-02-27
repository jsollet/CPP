#include "Animal.hpp"

Animal::Animal(): type("bestiole")
{
	std::cout << std::endl << "Default constructor Animal" << std::endl;
}

Animal::Animal(const std::string name): type(name)
{
	std::cout << std::endl << "Constructor animal type "<< this->type << std::endl;
}

Animal::Animal(const Animal &rhs): type(rhs.type)
{
	std::cout << std::endl << "Copy Constructor animal type "<< this->type << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << std::endl << "(Animal) Operator = : " << this->type << " = ";
	std::cout << rhs.getType() << std::endl;
	this->type = rhs.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor  Animal " << this->type << std::endl;
}

const std::string	Animal::getType(void) const {return (this->type); }

void  Animal::makeSound(void) const 
{
	std::cout << std::endl << "Huuuuu " << std::endl;
}

