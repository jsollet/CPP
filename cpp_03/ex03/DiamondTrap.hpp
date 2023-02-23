#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string _name);
		DiamondTrap(const DiamondTrap &diamond);
		DiamondTrap &operator=(const DiamondTrap &rhs);
		~DiamondTrap();
		void whoAmI();
		void attack(std::string const &target);
	private:
		std::string Name;
};

#endif

