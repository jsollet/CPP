#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon
{
		public:
			Weapon(std::string _weapon);
			~Weapon();
			std::string	const &	getType();
			void	setType(std::string _weapon);
		private:
			std::string	_type;
};

#endif
