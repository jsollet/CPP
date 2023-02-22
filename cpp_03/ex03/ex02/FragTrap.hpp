#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &fragtrap);
		FragTrap &operator=(const FragTrap &rhs);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFivesGuys(void);

	private:

};

#endif
