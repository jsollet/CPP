#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"), catBrain(new Brain())
{
	std::cout << std::endl << "Default constructor WrongCat" << std::endl;
}

WrongCat::WrongCat(const std::string name, const std::string idea ): WrongAnimal(name), catBrain(new Brain(idea))
{
	std::cout << std::endl << "Constructor Wrongcat type "<< this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs): WrongAnimal(rhs)
{
	this->catBrain = rhs.catBrain;
	std::cout << std::endl << "Copy Constructor Wrongcat type "<< this->type << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
	{
		std::cout << std::endl << "(Wrongcat) Operator = : " << this->type << " = ";
		std::cout << rhs.getType() << std::endl;
		delete (this->catBrain);
		this->type = rhs.getType();
		this->catBrain = rhs.catBrain;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor  WrongCat " << this->type << std::endl;
    delete (this->catBrain);
}
Brain*	WrongCat::getBrain() const
{
	return (this->catBrain);
}
void	WrongCat::makeSound() const
{
	std::cout << std::endl << this->type <<" (wrong) meows : Miaou, Miaou" << std::endl;
}
