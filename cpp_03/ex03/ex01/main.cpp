#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	Rambo("Rambo");
	ScavTrap	Alien("Alien");
	ScavTrap	ET("ET");
	ScavTrap	Alf("Alf");
	ET.guardGate();
	Alf = ET;
	Rambo.guardGate();
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
	Alien.guardGate();
	return (0);
}
