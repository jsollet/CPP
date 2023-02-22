#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	print(ClapTrap ct)
{
	std::cout << std::endl;
	std::cout << ct.getName() << " has :" << std::endl;
	std::cout << ct.getHP() << " Hit Points" << std::endl;
	std::cout << ct.getEP() << " Energy Points" << std::endl;
	std::cout << ct.getAP() << " Attack Points" << std::endl;
	std::cout << std::endl;
}

void	print(FragTrap ft)
{
	std::cout << std::endl;
	std::cout << ft.getName() << " has :" << std::endl;
	std::cout << ft.getHP() << " Hit Points" << std::endl;
	std::cout << ft.getEP() << " Energy Points" << std::endl;
	std::cout << ft.getAP() << " Attack Points" << std::endl;
	std::cout << std::endl;
}

void	print(ScavTrap st)
{
	std::cout << std::endl;
	std::cout << st.getName() << " has :" << std::endl;
	std::cout << st.getHP() << " Hit Points" << std::endl;
	std::cout << st.getEP() << " Energy Points" << std::endl;
	std::cout << st.getAP() << " Attack Points" << std::endl;
	std::cout << std::endl;
}

void	print(DiamondTrap dt)
{
	std::cout << std::endl;
	std::cout << dt.DiamondTrap::getName() << " has :" << std::endl;
	std::cout << dt.getHP() << " Hit Points" << std::endl;
	std::cout << dt.getEP() << " Energy Points" << std::endl;
	std::cout << dt.getAP() << " Attack Points" << std::endl;
	std::cout << std::endl;
}


int main()
{
/*	FragTrap	Rambo("Rambo");
	FragTrap	Alien("Alien");
	FragTrap	ET("ET");
	FragTrap	Alf("Alf");
	ET.highFivesGuys();
	Alf = ET;
	Rambo.highFivesGuys();
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
	Alien.highFivesGuys();
*/	
	ClapTrap	Rambo("Rambo");
	FragTrap	Tiger("Tiger");
	ScavTrap	HAL("HAL");
	DiamondTrap Eloise("Eloise");
	print(Rambo);// pas une bonne idee introduit copy constructor
//	print(Tiger);
//	print(HAL);
//	print(Eloise);
	Eloise.whoAmI();
	Eloise.highFivesGuys();
	Eloise.guardGate();
//	Eloise.attack("Rambo");
//	Rambo.takeDamage(Eloise.getAP());
//	Rambo.attack("Eloise");
//	Eloise.takeDamage(Rambo.getAP());
	return (0);
}
