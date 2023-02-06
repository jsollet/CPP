#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <string>


class Zombie
{
	public:
		Zombie(); // constructeur par défaut
		Zombie(std::string name); //constructeur parametré
		~Zombie();
		// getter
		void	announce(void) const;
		// setter
		void	setName(std::string name);

	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
