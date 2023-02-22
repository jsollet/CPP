#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() // HP(100), EP(50), AP(20)
{
	ScavTrap::HP = 100;
	ScavTrap::EP = 50;
	ScavTrap::AP = 20;
	std::cout << "Default ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	ScavTrap::HP = 100;
	ScavTrap::EP = 50;
	ScavTrap::AP = 20;
	std::cout << std::endl << "Constructor ST Name = "<< this->Name << std::endl;
	std::cout << "Constructor ST HP = "<< this->HP << std::endl;
	std::cout << "Constructor ST EP = "<< this->EP << std::endl;
	std::cout << "Constructor ST AP = "<< this->AP << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs): ClapTrap(rhs)//ou Claptrap() ?
{   //	:Name(rhs.getName()), HP(rhs.getHP()), EP(rhs.getEP()), AP(rhs.getAP())
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getEP();
	this->AP = rhs.getAP();
	std::cout << "ScavTrap Copy constructor "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap operator "<< this->Name <<" = "<< rhs.getName() << std::endl;
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getEP();
	this->AP = rhs.getAP();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << /*std::endl  <<*/ "ScavTrap Destructor of  "<< this->Name  <<" (adress = " <<&this->Name << " )"<< std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (ScavTrap::HP == 0)
	{
		std::cout<<ScavTrap::Name << " is destroyed !" << std::endl;
		return ;

	}
	if (ScavTrap::EP == 0)
	{
		std::cout<<ScavTrap::Name << " is depleted" << std::endl;
		return ;
	}
	if (ScavTrap::HP > 0 && ScavTrap::EP > 0)
	{
		ScavTrap::EP--;
		std::cout<<ScavTrap::Name << " fiercefully attack "<< target << " and deleting " << this->AP << " points of damages ! "<< std::endl;
	}
}
void	ScavTrap::guardGate()
{
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");
	std::cout<<red;	
	std::cout<<ScavTrap::Name << " is in Gate keeper mode !!!"<< std::endl;
	std::cout<<reset;
}

