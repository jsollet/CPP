#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "Amateria.hpp"

// pas sur...
// Abstract class --> pas de definition (pas de .cpp) !

class IMateriaSource
{
	public:
		virtual 			~ImateriaSource() {};
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;


	private:

};

#endif
