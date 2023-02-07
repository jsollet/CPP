#ifndef HUMANB_HPP
# define HUMANB_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string _name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &_weapon);
	private:
		std::string _name;
		Weapon*	_weapon;
};

#endif
