#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	aZombie(name);

	aZombie.announce();
}
