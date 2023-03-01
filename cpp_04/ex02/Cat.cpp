#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat"), catBrain(new Brain())
{
	std::cout << std::endl << "Default constructor Cat" << std::endl;
}

Cat::Cat(const std::string name, const std::string idea): Animal(name), catBrain(new Brain(idea))
{
	std::cout << std::endl << "Constructor cat type "<< this->type << std::endl;
}

Cat::Cat(const Cat &rhs): Animal(rhs)
{
	this->catBrain = new Brain(*rhs.catBrain);
	std::cout << std::endl << "Copy Constructor cat type "<< this->type << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		std::cout << std::endl << "(cat) Operator = : " << this->type << " = ";
		std::cout << rhs.getType() << std::endl;
		delete (this->catBrain);
		this->type = rhs.getType();
		this->catBrain = new Brain(*rhs.catBrain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete (this->catBrain);
	std::cout <<  "Destructor  Cat " << this->type << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->catBrain);
}

void	Cat::makeSound() const
{
	std::cout << std::endl << this->type <<" meows : Miaou, Miaou" << std::endl;
}
