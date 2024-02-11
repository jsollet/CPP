#include "Zombie.hpp"
// 
int main()
{
	Zombie zombie_1("Freddy");
	Zombie *zombie_2 = newZombie("Frankenstein");
	randomChump("Vampirella");
	zombie_1.announce();
	zombie_2->announce();
	delete zombie_2;
}
