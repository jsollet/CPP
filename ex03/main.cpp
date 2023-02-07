#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
	   	bob.attack();
	}
   	{
	//	Weapon club = Weapon("crude spiked mass");
		HumanB jim("Jim");
	//	jim.setWeapon(club);
		jim.attack();
		Weapon epee = Weapon("falcata");
		jim.setWeapon(epee);
		//club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
