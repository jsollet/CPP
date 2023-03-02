#include "Character.hpp"

	int	instance_def = 0;
	int	instance_par = 0;
	int	instance_cpy = 0;
	Amateria *left = {};

Character::Character(): name("")
{
	for (int i = 0; i < Character::size; i++)
	{
		Character::stock[i] = NULL;
	}
	instance_def++;
	std::cout << "Default constructor Character" << std::endl;
	std::cout << "Number of Default constructor call = "<<instance_def << std::endl
}

Character::Character(const std::string Name): name(Name)
{
	for (int i = 0; i < Character::size; i++)
	{
		Character::stock[i] = NULL;
	}
	instance_par++;
	std::cout << "Param constructor Character" << std::endl;
	std::cout << "Number of par constructor call = "<<instance_par << std::endl
}

Character::Character(const Character &character): name(character.getName())
{
	for (int i = 0; i < Character::size; i++)
	{// A<--B Pas sur qu'il faut effecer...
	// effacement A (suppose ont été new...
		if (this->stock[i])
			delete (this->stock[i]);
	}
	for (int i = 0; i < Character::size; i++)
	{
	// clonage... B-->A (si non null)
	// clone dans Ice ou Cure...
		if (character.stock[i])
			this->stock[i] = character.stock[i]->clone(); //stock un ptr
	}
	instance_cpy++;
	std::cout << "Copy constructor Character" << std::endl;
	std::cout << "Number of copyconstructor call = "<<instance_cpy << std::endl
}

Character	&Character::operator=(const Character &rhs)
{// 1 test "automorphe"
	if (this != rhs)
	{
		this->name = rhs.getName();
		for (int i = 0; i < Character::size; i++)
		{// effacement
			if (this->stock[i])
				delete (this->stock);
		}
		for (int i = 0; i < Character::size; i++)
		{// Clonage...
			if (this->stock[i])
				this->stock[i] = rhs.stock[i]->clone();
			else
				this->stock[i] = NULL;
		}
	}
	std::cout << "op = Character" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < Character::size; i++)
	{
		if (this->stock[i])
			delete (this->stock);
	}
	instance_def--;
	std::cout << "destructor  Character" << std::endl;
	std::cout << "Number of Default constructor call = "<<instance_def << std::endl

}

const std::string	&Character::getName() const
{
	return (this->name);
}

void				Character::equip(AMateria *m)
{
	int	i = 0;
	while (i < Character::size)
	{
		if (this->stock[i] == NULL)
		{
			this->stcok[i] = m;
			break ;
		}
		i++;
	}
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < Character::size)
	{
		// comment stoker ce qu'on va enlever ??
		this->stock[idx] = NULL;
	}
}

void				Character::use(int idx, ICharacter &target)
{// comment vérifier l'existence d'un target ?
	if (idx >= 0 && idx < Character::size && this->stock[idx])
	{
		this->stock[i]->use(target);
		this->unequip(idx);
	}
}
