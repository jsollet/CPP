#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		Dog(const std::string name, const std::string idea);
		Dog(const Dog &Dog);
		Dog &operator=(const Dog &rhs);
		~Dog();

		void		makeSound() const;
	private:
		Brain*	dogBrain;
};

#endif
