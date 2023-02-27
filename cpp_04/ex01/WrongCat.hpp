#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string name);
		WrongCat(const WrongCat &WrongCat);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat();

		void	makeSound() const;
};

#endif
