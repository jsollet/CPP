#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string _weapon) :
_type(_weapon)
{
}

Weapon::~Weapon()
{

}

std::string	const &	Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string _weapon)
{
	this->_type = _weapon;
}

