#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include <string>

class	Animal
{
	public:
		Animal();
		Animal(const std::string name);
		Animal(const Animal &animal);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal();

		virtual	const std::string		getType(void) const;
		virtual void					makeSound(void) const=0;

	protected:
		std::string	type;
};

#endif
