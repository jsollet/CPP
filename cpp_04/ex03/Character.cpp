#include "Character.hpp"

	int Character::instance = 0;
	AMateria *Character::left[100] = {NULL};

Character::Character(): name("")
{
	for (int i = 0; i < Character::size; i++)
	{
		Character::stock[i] = NULL;
	}
	instance++;
	std::cout << "Default constructor Character" << std::endl;
	std::cout << "Number of remaining instance = "<<instance << std::endl;
}

Character::Character(const std::string Name): name(Name)
{
	for (int i = 0; i < Character::size; i++)
	{
		Character::stock[i] = NULL;
	}
	instance++;
	std::cout << "Param constructor Character" << std::endl;
	std::cout << "Number of remaining instance = "<<instance << std::endl;
}

Character::Character(const Character &character): name(character.getName())
{
	for (int i = 0; i < Character::size; i++)
	{
		Character::stock[i] = NULL;
	}
/*	for (int i = 0; i < Character::size; i++)
	{
		if (this->stock[i])
			delete (this->stock[i]);
	}
*/	for (int i = 0; i < Character::size; i++)
	{
		if (character.stock[i])
			this->stock[i] = character.stock[i]->clone();
	}
	instance++;
	std::cout << "Copy constructor Character" << std::endl;
	std::cout << "Number of remaining instance = "<<instance << std::endl;
}

Character	&Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getName();// segfaul
	for (int i = 0; i < Character::size; i++)
	{
		Character::stock[i] = NULL;
	}
		for (int i = 0; i < Character::size; i++)
		{
			if (this->stock[i])
				delete (this->stock[i]);
		}
		for (int i = 0; i < Character::size; i++)
		{
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
			delete (this->stock[i]);
	}
	instance--;
	std::cout << "destructor  Character" << std::endl;
	std::cout << "Number of remaining instance = "<<instance << std::endl;
	if (instance == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			if (left[i])
			{
				delete left[i];
				left[i] = NULL;
			}
		}
	}

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
			this->stock[i] = m;
			//break ;
			return ;
		}
		i++;
	}
	// si pas de place on le met dans left
	i = 0;
	while (i < 100)
	{
		if (left[i] == NULL)
		{
			left[i] = m;
			break;
		}
		i++;
	}
	if (i == 100)
	{
		std::cout << "too much on the floor !" << std::endl;
		delete m;
	}

}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < Character::size)
	{
		int i = 0;
		while (i < 100)
		{
			if (left[i] == NULL)
			{
				left[i] = this->stock[i];
				break ;
			}
			i++;
		}
		if (i == 100)
		{
			std::cout << "TOO much unequipped on floor " << std::endl;
			return ;
		}
		else
			this->stock[idx] = NULL;
	}
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < Character::size && this->stock[idx])
	{
		this->stock[idx]->use(target);
		this->unequip(idx);
	}
}
