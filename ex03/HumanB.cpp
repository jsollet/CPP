#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	_name(name)
{
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their ";
	if (!this->_weapon->getType().empty())
	{
		std::cout << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << "feet"<< std::endl;
}

void HumanB::setWeapon(Weapon& _weapon)
{
	this->_weapon = &_weapon;
}
