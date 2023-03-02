#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	public:
	AMateria();
	AMateria(const std::string name);
	AMateria(const AMateria &mat);
	AMateria &operator=(const AMateria &rhs);
	~AMateria();
	// a completer
	
	std::string const	&getType() const;// est-ce le name ?

	virtual AMateria		*clone() const = 0;// defini plus tard, AMateria abst
	virtual void			use(ICharacter &target);// nvelle interface classe...

	protected:
		std::string		name;

	// a completer
};


#endif

// clone et use definit dans Ice et Cure
