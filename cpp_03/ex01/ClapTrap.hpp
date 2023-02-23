#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string>

class	ClapTrap
{
	public:
		ClapTrap();									
		ClapTrap(const std::string name); 	
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &rhs);
		virtual ~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		unsigned int		getHP(void) const;
		unsigned int		getEP(void) const;
		unsigned int		getAP(void) const;
		std::string			getName(void) const;

	protected:
		std::string			Name;
		unsigned int		HP;
		unsigned int		EP;	
		unsigned int		AP; 
};

#endif
