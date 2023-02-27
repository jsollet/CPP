
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << std::endl << "Default constructor WrongCat" << std::endl;
}

WrongCat::WrongCat(const std::string name): WrongAnimal(name)
{
	std::cout << std::endl << "Constructor dcat type "<< this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs): WrongAnimal(rhs)
{
	std::cout << std::endl << "Copy Constructor cat type "<< this->type << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << std::endl << "(cat) Operator = : " << this->type << " = ";
std::cout << rhs.getType() << std::endl;
	this->type = rhs.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor  WrongCat " << this->type << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << std::endl << this->type <<" meows : Miaou, Miaou" << std::endl;
}
