#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string name, const std::string idea);
		WrongCat(const WrongCat &WrongCat);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat();

		Brain*	getBrain() const;
		void	makeSound() const;
	private:
		Brain*	catBrain;
};

#endif
