#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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

int main()
{
	std::cout << std::endl  << "--- Constructor  ---" << std::endl;
	ClapTrap	Rambo("Rambo");
	FragTrap	HAL("HAL");
	FragTrap	Tiger("Tiger");
	FragTrap	Alien("Alien");
	std::cout << std::endl  << "--- Operator =  ---" << std::endl;
	Alien = Tiger;
	std::cout << std::endl  << "--- Attack  ---" << std::endl;
	for (int i=0; i< 3; i++)
	{
		HAL.attack("Tiger");
		Tiger.takeDamage(HAL.getAP());
		Tiger.beRepaired(15);
		HAL.attack("Alien");
		Alien.takeDamage(HAL.getAP());
		Alien.attack("Rambo");
		Rambo.takeDamage(Alien.getAP());
		Tiger.attack("HAL");
		HAL.takeDamage(Tiger.getAP());
	}
	print(Rambo);
	std::cout << std::endl  << "--- Special Function ---" << std::endl;
	Alien.highFivesGuys();
	std::cout << std::endl  << "--- Destructor  ---" << std::endl;
	return (0);
}
