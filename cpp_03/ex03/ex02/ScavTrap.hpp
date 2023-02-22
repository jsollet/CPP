#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

// derived class from ClapTrap, modified
class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap &operator=(const ScavTrap &rhs); // ajout 2002
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();

};

#endif
