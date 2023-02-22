#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string>

class	ClapTrap
{
	public:
		ClapTrap();											// specialisation
		ClapTrap(const std::string name); 					// specialisation
		ClapTrap(const ClapTrap &claptrap); 				// specialisation
		ClapTrap &operator=(const ClapTrap &rhs);			//
		~ClapTrap();										// specialisation

		void	attack(const std::string& target);			// specialisation
		void	takeDamage(unsigned int amount);			//
		void	beRepaired(unsigned int amount);			//

		unsigned int		getHP(void) const;				//
		unsigned int		getEP(void) const;				//
		unsigned int		getAP(void) const;				//
		std::string			getName(void) const;			//
	protected:												// visible+
		std::string			Name;							//
		unsigned int		HP;								// 		
		unsigned int		EP;								// 
		unsigned int		AP;								// 
};

#endif
