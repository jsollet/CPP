//#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < Brain::size; i++)
	{
		Brain::ideas[i] = "";
	}	
	std::cout << std::endl << "Default constructor Brain" << std::endl;
}

Brain::Brain(const std::string idea)
{
	for (int i = 0; i < Brain::size; i++)
	{
		Brain::ideas[i] = idea;
	}
	std::cout << std::endl << "Constructor Brain" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	for (int i = 0; i < Brain::size; i++)
	{
		this->ideas[i] = brain.getIdea(i);
	}	
	std::cout << std::endl << "Copy constructor Brain" <<  std::endl;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i=0; i < Brain::size; i++)
		{
			this->ideas[i] = rhs.getIdea(i);;
		}
		std::cout << std::endl << "Assignment operator = (Brain)" << std::endl;
	}
	return (*this);
}

Brain::~Brain()
{

	std::cout << std::endl << "Destructor (Brain)" <<  std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	else
		return(NULL);
}

void		Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
	else 
	{
		std::cout << "out of range" << std::endl;
	}
}
