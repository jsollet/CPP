

#include "Zombie.hpp"
// test pas sur
Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *lots  = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		lots[i].setName(name + std::to_string(i));
		//std::cout << lots[i]->name << std::endl;
		lots[i].announce();
	}
	return (lots);
}
