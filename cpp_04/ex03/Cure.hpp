#ifndef CURE_HPP
# define CURE_HPP
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const std::string name);
		Cure(const Cure &ice);
		Cure &operator=(const Cure &rhs);
		~Cure();

		AMateria	*clone() const;
		void		use(ICharacter &target);
	private:
};
#endif
