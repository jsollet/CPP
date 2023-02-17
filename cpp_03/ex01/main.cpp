#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	Rambo("Rambo");
	ScavTrap	Alien("Alien");
	Rambo.attack("Alien");
	Alien.takeDamage(Rambo.getAP());
	Alien.attack("Rambo");
	Rambo.takeDamage(Alien.getAP());
	Alien.attack("Rambo");
	Rambo.takeDamage(Alien.getAP());
	Rambo.attack("Alien");
	Alien.takeDamage(Rambo.getAP());
	for (int i= 0; i< 10; i++)
		Rambo.beRepaired(2);
	for (int i= 0; i< 10; i++)
	{
		Alien.attack("Rambo");
		Rambo.takeDamage(Alien.getAP());

	}
	return (0);
}
