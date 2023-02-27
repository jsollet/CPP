#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		Dog(const std::string name);
		Dog(const Dog &Dog);
		Dog &operator=(const Dog &rhs);
		~Dog();

		void		makeSound() const;
};

#endif
