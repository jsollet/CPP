#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"
// a modifier

bool	isNumber(std::string str)
{
	size_t	i=0;
	while (i< str.length())
	{
		if (std::isdigit(str[i]))
		{
			i++;
			continue ;
		}
		else
			return (false);
	}
	return (true);
}




int main()
{
	// demande N et name
	Zombie		*zombie_arr;
	std::string	name;
	int			N;
	do{
		std::cout << "Donner le nom de tous ces clones de Zombies:" << std::endl;
		std::getline(std::cin, name);
	} while(name.empty());
	std::string	ans;
	while (true)
	{
		std::cout << "Et combien en voulez-vous ? "<< std::endl;
		std::getline(std::cin, ans);
		if (!isNumber(ans))
			continue ;
		else
		{
			N = atoi(ans.c_str());
			break ;
		}
	}	

	
	// creation
	zombie_arr = zombieHorde(N, name);
	// delete
	delete[] zombie_arr;
}
