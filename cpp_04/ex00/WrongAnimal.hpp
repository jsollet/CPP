
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const std::string name);
		WrongAnimal(const WrongAnimal &animal);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		virtual ~WrongAnimal();

		const std::string		getType(void) const;
		void					makeSound(void) const;

	protected:
		std::string	type;
};

#endif
