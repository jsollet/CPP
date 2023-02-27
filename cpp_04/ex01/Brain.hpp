#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>
#include <string>

class	Brain
{
	public:
		Brain();
		Brain(const std::string idea);
		Brain(const Brain &Brain);
		Brain &operator=(const Brain &rhs);
		~Brain();
		
		std::string	getIdea(int index) const;
	private:
		static const int	size = 100;
		std::string	ideas[size];

};

#endif
