#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &ms);
		MateriaSource &operator=(const MateriaSource &rhs);
		~MateriaSource();

		void		learnMateria(AMateria *aMateria);
		AMateria	*createMateria(std::string const& type);

	private:
		static const int	size = 4;
		AMateria			*MatSource[size];
};
#endif
