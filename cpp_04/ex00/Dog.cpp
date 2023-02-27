#include "Animal.hpp"
#include "Dog.hpp"


Dog::Dog(): Animal("Dog")
{
	std::cout << std::endl << "Default constructor Dog" << std::endl;
}

Dog::Dog(const std::string name): Animal(name)
{
	std::cout << std::endl << "Constructor dog type "<< this->type << std::endl;
}

Dog::Dog(const Dog &rhs): Animal(rhs)
{
	std::cout << std::endl << "Copy Constructor dog type "<< this->type << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << std::endl << "(Dog) Operator = : " << this->type << " = ";
	std::cout << rhs.getType() << std::endl;
	this->type = rhs.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor  Dog " << this->type << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << std::endl << this->type << " balks : Wouaff, Wouaff" << std::endl;
}
