#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat"), catBrain(new Brain())
{
//	this->catBrain = new Brain();// Juste ?
	std::cout << std::endl << "Default constructor Cat" << std::endl;
}
//
Cat::Cat(const std::string name, const std::string idea): Animal(name), catBrain(new Brain(idea))
{
	std::cout << std::endl << "Constructor cat type "<< this->type << std::endl;
}
// Leak ?, copie il n' existe pas (recipent).
Cat::Cat(const Cat &rhs): Animal(rhs)// , catBrain(new Brain(*rhs.catBrain))
{
//	delete (this->catBrain);
	this->catBrain = new Brain(*rhs.catBrain);
	std::cout << std::endl << "Copy Constructor cat type "<< this->type << std::endl;
}
// faux?
Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << std::endl << "(cat) Operator = : " << this->type << " = ";
std::cout << rhs.getType() << std::endl;
	delete (this->catBrain);
	this->type = rhs.getType();
	this->catBrain = new Brain(*rhs.catBrain);//de quoi ?
	return (*this);
}
// modif, ce n'est pas un array dynamique, la taille connue...
Cat::~Cat()
{
	delete (this->catBrain);
	std::cout <<  "Destructor  Cat " << this->type << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << std::endl << this->type <<" meows : Miaou, Miaou" << std::endl;
}
