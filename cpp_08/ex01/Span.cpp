#include "Span.hpp"

static int random(int min, int max)
{
	static bool start = true;
	if (start)
	{
		srand(time(NULL));
		start = false;
	}
	return (min + rand() % (1 + max - min));
}

Span::Span(){}

Span::Span(unsigned int sz)
{
	Elem = new std::vector<int>[sz];
	N = sz;
}

Span::Span(const Span &rhs):N(rhs.N),Elem(new std::vector<int>[rhs.N])
{
	for (unsigned int i = 0; i < rhs.N; ++i)
	{
		Elem[i] = rhs.Elem[i];
	}
}

Span::~Span()
{
	delete[] (Elem);
}

Span	&Span::operator=(const Span &rhs)
{
	std::vector<int>	*tmp = new std::vector<int>[rhs.N];
	std::vector<int>::iterator	it;

	for (it = rhs.Elem->begin(); it != rhs.Elem->end(); ++it)
	{
		tmp->push_back(*it);
	}
	delete [] Elem;
	Elem = tmp;
	N = rhs.N;
	return (*this);
}

unsigned int	Span::getSize() const
{
	return (N);
}

std::vector<int>	Span::getVector() const
{
	return (*Elem);
}

void	Span::addNumber(int number)
{
	try
	{
		if (Elem->size() >= this->N)
		{
			throw std::length_error("Span is full");
		}
		else
		{
			Elem->push_back(number);
		}
	}
	catch (const std::length_error &e)
	{
		std::cerr << magenta <<e.what() << reset << std::endl;
	}
}

void	Span::print(std::string start, std::string end) const
{
	std::cout << start;
	for (unsigned int i= 0; i < Elem->size(); ++i)
		std::cout << this->getVector()[i] << " ";
	std::cout << end << std::endl;
}

void	Span::populate(int min, int max, int size)
{
	if (size < 0 || min >= max)
		throw invalidArgument();
	else
	if (static_cast<unsigned int>(size) > this->N - Elem->size())
		throw lengthError();
	else
	{
		std::vector<int>::iterator	start= Elem->begin() + Elem->size() -1;
		std::vector<int>::iterator	stop = start + size;
		while (start != stop)
		{
			Elem->push_back(random(min, max));
			++start;
		}
	}
}

int		Span::min() const
{
	int	result = INT_MAX;
	std::vector<int>::iterator	start = this->Elem->begin();
	std::vector<int>::iterator	stop  = this->Elem->end();
	while (start != stop)
	{
		if (*start < result)
			result = *start;
		++start;
	}
	return (result);
}

int		Span::max() const
{
	int	result = INT_MIN;
	std::vector<int>::iterator	start = this->Elem->begin();
	std::vector<int>::iterator	stop  = this->Elem->end();
	while (start != stop)
	{
		if (*start > result)
			result = *start;
		++start;
	}
	return (result);
}

unsigned int	Span::shortestSpan() const
{
	int	result = INT_MAX;
	if (this->Elem->size() < 2)
		throw logicError();
	else
	{
		std::vector<int>::iterator	start = this->Elem->begin();
		std::vector<int>::iterator	stop  = this->Elem->end();
		std::sort(start, stop);
		while (start != stop - 1)
		{
		if (*(start + 1) - *start <  result)
			result = *(start + 1) - *start;
		++start;
		}
	return (result);
	}
}

unsigned int	Span::longestSpan() const
{
	{
		if (this->Elem->size() < 2)
			throw logicError();
		else
		{
		return (max() - min());
		}
	}
}

const char*	Span::invalidArgument::what() const throw()
{
	return "Populate: Invalid argument";
}
const char*	Span::lengthError::what() const throw()
{
	return "Populate: not enough space left";
}
const char*	Span::logicError::what() const throw()
{
	return "Span: cannot compute span (size() < 2";
}
