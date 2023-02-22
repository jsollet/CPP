#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
// impro. FAUX segfault ??????.

void	DiamondTrap::whoAmI()
{
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");
	std::cout <<red;
	std::cout << "My name is " << this->Name << " and the name of ClapTrap is " << this->ClapTrap::Name << std::endl;
	std::cout<<reset;
}

// a voir idem en bas ??
DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap()
{
	std::cout<<" DiamondTrap default constructor "<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string Name)
  // 	:ClapTrap(Name + "_clap_name"),
  // 	FragTrap(), ScavTrap(),
  // 	HP(FragTrap::HP),
// EP(ScavTrap::EP),
//	AP(FragTrap::AP),
//	attack(&ScavTrap::attack)
{
	{	
		FragTrap Frag("Frag");
		ScavTrap Scav("Scav");
		ClapTrap::Name= Name + "_clap_name";
		this->HP = Frag.getHP();
		this->EP = Scav.getEP();
		this->AP = Frag.getAP();
		this->Name = Name;
	}
	std::cout << std::endl << "Constructor DT Name = "<< this->Name << std::endl;
	std::cout << "Constructor DT HP = "<< this->HP << std::endl;
	std::cout << "Constructor DT EP = "<< this->EP << std::endl;
	std::cout << "Constructor DT AP = "<< this->AP << std::endl;
}

// ??
DiamondTrap::DiamondTrap(const DiamondTrap &rhs): ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getHP();
	this->AP = rhs.getAP();
	std::cout << "DiamondTrap  Copy constructor "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}

DiamondTrap		&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap operator "<< this->Name <<" = "<< rhs.getName() << std::endl;
// essai
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getHP();
	this->AP = rhs.getAP();
	return (*this);
}


DiamondTrap::~DiamondTrap()
{// Pb ici ?
	std::cout << "Diamond  Destructor of  "<< this->Name <<  " (adress = "<< &this->Name << " )" <<std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	DiamondTrap::ScavTrap::attack(target);
}
