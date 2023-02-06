#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;// ?
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << "'s instance definitely killed !" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name=name;
}
