#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Character: public ICharacter
{
	public:
		Character();
		Character(const std::string name);
		Character(const Character &character);
		Character &operator=(const Character &rhs);
		~Character();

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);


	private:
		std::string			name;
		static const int	size = 4;
		AMateria			*stock[size];

	static int				instance;
	static AMateria			*left[100];
};

#endif
