#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "Amateria.hpp"  // ?
#include "IMateriaSource.hpp" // abstrac class


class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
//		MateriaSource(const std::string name);
		MateriaSource(const MateriaSource &ms);
		MateriaSource &operator=(const MateriaSource &rhs);
		~MateriaSource();

		void		learnMateria(AMateria *aMateria);
		AMateria	*createMateria(std::string const& type);

	private:
// doit avoir un array de 4 materia ?
		static const int	size = 4;
		AMateria			*MatSource[size]; //peut être mieux  *
	//	std::string			MatSource[size];//Materia pas string...

#endif
