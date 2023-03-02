#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MateriaSource::size; i++)
	{
		this->MatSource[i] = NULL;
	}
	std::cout << "Default constructor Materia..." << std::endl;
}


MateriaSource::MateriaSource(const MateriaSource &ms)
{
	for (int i = 0; i < MateriaSource::size; i++)
	{
		if (ms.MatSource[i])
			this->MatSource[i] = ms.MatSource[i]->clone();
	}
	std::cout << "Copy constructor Materia..." << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != rhs)
	{
		for (int i = 0; i < MateriaSource::size; i++)
		{
			if (this->MatSource[i])
				delete (this->MatSource[i]);
		}
		for (int i = 0; i < MateriaSource::size; i++)
		{
			if (rhs.MatSource[i])
				this->MatSource[i] = rhs.MatSource[i]->clone();
			else
				this->MatSource[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MateriaSource::size; i++)
	{
		if (this->MatSource[i])
			delete (this->MatSource[i]);
	}
}
