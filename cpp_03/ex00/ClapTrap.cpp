#include "ClapTrap.hpp"

ClapTrap::ClapTrap()//: HP(10), EP(10), AP(0)
{
	std::cout << "Default constructor with HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}
// a changer ap
ClapTrap::ClapTrap(const std::string name): Name(name), HP(10), EP(10), AP(3)
{
	std::cout << "Constructor of "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs): Name(rhs.getName()), HP(rhs.getHP()), EP(rhs.getEP()), AP(rhs.getAP())
{
	std::cout << "Copy constructor "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getEP();
	this->AP = rhs.getAP();

	std::cout << "Operator = : "<< this->Name <<" = "<< rhs.getName() << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of  "<< this->Name << std::endl;
}

unsigned int	ClapTrap::getHP(void) const
{
	return (this->HP);
}

unsigned int	ClapTrap::getEP(void) const
{
	return (this->EP);
}

unsigned int	ClapTrap::getAP(void) const
{
	return (this->AP);
}

std::string		ClapTrap::getName(void) const
{
	return (this->Name);
}

void	ClapTrap::attack(const std::string& target)
{
	if (ClapTrap::HP == 0)
	{
		std::cout<<ClapTrap::Name << " is already dead !" << std::endl;
		return ;
	}
	if (ClapTrap::EP == 0)
	{
		std::cout<<ClapTrap::Name << " has no more energy to attack " << std::endl;
		return ;
	}
	if (ClapTrap::HP > 0 && ClapTrap::EP > 0)
	{
		ClapTrap::EP--;
		std::cout<<ClapTrap::Name << " attack "<< target << " blowing " << this->AP << " points of damages ! "<< std::endl;
	}

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (ClapTrap::HP > amount)
	{
		ClapTrap::HP-=amount;
		std::cout<<ClapTrap::Name << " lost  " << amount << " Hit points" << std::endl;
	}
	else
	{
		ClapTrap::HP = 0;
		std::cout<<ClapTrap::Name << " is dead " << std::endl;

	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (ClapTrap::EP && ClapTrap::HP)
	{
		ClapTrap::EP--;
		ClapTrap::HP+=amount;
		std::cout<<ClapTrap::Name << " gained  " << amount << " Hit points" << std::endl;
	}
	else if (ClapTrap::EP && ClapTrap::HP == 0)
		std::cout<<ClapTrap::Name << " is dead " << std::endl;
	else
		std::cout<<ClapTrap::Name << " no more energy point " << std::endl;

}
