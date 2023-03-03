#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include <string>
#include "Character.hpp"


class ICharacter;
class Character;
class IMateriaSource;
class MateriaSource;

class AMateria
{
	public:
	AMateria();
	AMateria(const std::string name);
	AMateria(const AMateria &mat);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria();
	
	std::string const	&getType() const;

	virtual AMateria		*clone() const = 0;
	virtual void			use(ICharacter &target) = 0;

	protected:
		std::string		name;
};


#endif
