#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const std::string name, const std::string idea);
		Cat(const Cat &Cat);
		Cat &operator=(const Cat &rhs);
		~Cat();

		void	makeSound() const;
	private:
		Brain*	catBrain;// a voir
};

#endif
