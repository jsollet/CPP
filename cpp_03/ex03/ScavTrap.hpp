#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	ScavTrap: public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap &operator=(const ScavTrap &rhs);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();

};

#endif
