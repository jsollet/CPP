#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const std::string name);
		Cat(const Cat &Cat);
		Cat &operator=(const Cat &rhs);
		~Cat();

		void	makeSound() const;
};

#endif
