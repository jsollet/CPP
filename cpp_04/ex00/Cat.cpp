#include "Animal.hpp"
#include "Cat.hpp"


Cat::Cat(): Animal("Cat")
{
	std::cout << std::endl << "Default constructor Cat" << std::endl;
}

Cat::Cat(const std::string name): Animal(name)
{
	std::cout << std::endl << "Constructor dcat type "<< this->type << std::endl;
}

Cat::Cat(const Cat &rhs): Animal(rhs)
{
	std::cout << std::endl << "Copy Constructor cat type "<< this->type << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << std::endl << "(cat) Operator = : " << this->type << " = ";
std::cout << rhs.getType() << std::endl;
	this->type = rhs.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout <<  "Destructor  Cat " << this->type << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << std::endl << this->type <<" meows : Miaou, Miaou" << std::endl;
}
