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
	std::cout << dt.DiamondTrap::getHP() << " Hit Points" << std::endl;
	std::cout << dt.DiamondTrap::getEP() << " Energy Points" << std::endl;
	std::cout << dt.DiamondTrap::getAP() << " Attack Points" << std::endl;
	std::cout << std::endl;
}


int main()
{
	std::cout << std::endl  << "--- Constructor  ---" << std::endl;
	ClapTrap	Rambo("Rambo");
	ScavTrap	HAL("HAL");
	FragTrap	Tiger("Tiger");
	DiamondTrap Alien("Alien");
	DiamondTrap	No("No");

	std::cout << std::endl  << "--- Operator =  ---" << std::endl;
	No = Alien;
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
	Alien.whoAmI();
	Alien.highFivesGuys();
	Alien.guardGate();
	std::cout<<std::endl;
	HAL.guardGate();
	Tiger.highFivesGuys();

	std::cout << std::endl  << "--- Destructor  ---" << std::endl;
	return (0);
}
