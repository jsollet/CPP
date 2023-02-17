#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// ClapTrap() devrait ? (par defuat aucune valeur ?
ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default ScavTrap constructor with HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}
/*
// bon claptrap doit avoir ses propres valeurs... alors l ligne 11 est fausse pour ce contexte
ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap Constructor of "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &rhs): ClapTrap(rhs)
{   //	:Name(rhs.getName()), HP(rhs.getHP()), EP(rhs.getEP()), AP(rhs.getAP())
	std::cout << "ScavTrap Copy constructor "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}
*/

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	ScavTrap::HP = 100;
	ScavTrap::EP = 50;
	ScavTrap::AP = 20;
	std::cout << "ScavTrap Constructor of "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs): ClapTrap(rhs)//ou Claptrap() ?
{   //	:Name(rhs.getName()), HP(rhs.getHP()), EP(rhs.getEP()), AP(rhs.getAP())
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getEP();
	this->AP = rhs.getAP();
	std::cout << "ScavTrap Copy constructor "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor of  "<< this->Name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (ScavTrap::HP == 0)
	{
		std::cout<<ClapTrap::Name << " is destroyed !" << std::endl;
		return ;

	}
	if (ScavTrap::EP == 0)
	{
		std::cout<<ClapTrap::Name << " is depleted" << std::endl;
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
		std::cout<<ScavTrap::Name << " is in Gate keeper mode !!!"<< std::endl;
}

