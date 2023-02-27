#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog"), dogBrain(new Brain())
{
	std::cout << std::endl << "Default constructor Dog" << std::endl;
}

Dog::Dog(const std::string name, const std::string idea): Animal(name), dogBrain(new Brain(idea))
{
	std::cout << std::endl << "Constructor dog type "<< this->type << std::endl;
}

Dog::Dog(const Dog &rhs): Animal(rhs)
{
	this->dogBrain = new Brain(*rhs.dogBrain);
	std::cout << std::endl << "Copy Constructor dog type "<< this->type << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << std::endl << "(Dog) Operator = : " << this->type << " = ";
	std::cout << rhs.getType() << std::endl;
	delete (this->dogBrain);
	this->type = rhs.getType();
	this->dogBrain = new Brain(*rhs.dogBrain);
	return (*this);
}

Dog::~Dog()
{
	delete (this->dogBrain);
	std::cout << "Destructor  Dog " << this->type << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << std::endl << this->type << " balks : Wouaff, Wouaff" << std::endl;
}
