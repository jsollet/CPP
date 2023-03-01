#ifndef IMATERIASOURCE.HPP
# define IMATERIASOURCE.HPP
#include <iostream>
#include <string>
#include "Amateria.hpp"

// pas sur....

class IMateriaSource
{
	public:
		virtual 			~ImateriaSource() {};
		virtual void		learnMateria(AMateria*) = 0;
		virtual Amateria*	createMateria(std::string const & type) = 0;


	private:

};

#endif
