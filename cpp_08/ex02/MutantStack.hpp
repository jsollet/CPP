#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <stack>
#include <list>
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(){};

		MutantStack<T>(const MutantStack<T> &rhs): std::stack<T>(rhs){};// ok
		~MutantStack<T>(){};// doute
		MutantStack	&operator=(const MutantStack &rhs)// ok
		{
			std::stack<T>::operator=(rhs);
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator		begin() {return (std::stack<T>::c.begin());}
		iterator		end() {return (std::stack<T>::c.end());}
};


#endif
