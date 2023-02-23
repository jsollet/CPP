#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	FragTrap::HP = 100;
	FragTrap::EP = 100;
	this->AP = 30;
	std::cout << "Default FragTrap constructor "<< std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	FragTrap::HP = 100;
	FragTrap::EP = 100;
	this->AP = 30;
	std::cout << std::endl << "Constructor FT Name = "<< this->Name << std::endl;
	std::cout << "Constructor FT HP = "<< this->HP << std::endl;
	std::cout << "Constructor FT EP = "<< this->EP << std::endl;
	std::cout << "Constructor FT AP = "<< this->AP << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs): ClapTrap(rhs)
{
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getEP();
	this->AP = rhs.getAP();
	std::cout << "FragTrap Copy constructor "<< this->Name <<" HP = "<< HP << " EP = " << EP << " and AP = " << AP << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap operator "<< this->Name <<" = "<< rhs.getName() << std::endl;
	this->Name = rhs.getName();
	this->HP = rhs.getHP();
	this->EP = rhs.getEP();
	this->AP = rhs.getAP();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor of  "<< this->Name <<  " (adress = "<< &this->Name << " )" <<std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (FragTrap::HP == 0)
	{
		std::cout<<FragTrap::Name << " is terminated !" << std::endl;
		return ;

	}
	if (FragTrap::EP == 0)
	{
		std::cout<<FragTrap::Name << " has no more energy" << std::endl;
		return ;
	}
	if (FragTrap::HP > 0 && FragTrap::EP > 0)
	{
		FragTrap::EP--;
		std::cout<<FragTrap::Name << " powerfully attack "<< target << " and removed " << this->AP << " points of damages ! "<< std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");
	std::cout<<red;
	std::cout<<FragTrap::Name << " I would like to  high five everyone  !"<< std::endl;
	std::cout<<reset;
}
