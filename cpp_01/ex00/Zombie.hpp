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
		void	announce(void);// public sinon impossible depuis main ?

	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
