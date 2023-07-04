#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <vector>
#include <deque>
#include <list>


const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");


template<typename T>
void stat(T  &v)
{
	std::cout << "empty:" <<  v.empty() << std::endl;
	std::cout << "size:" <<  v.size() << std::endl;
	std::cout << "max_size:" << v.max_size() << std::endl;
}

template<typename T>
void print(T &v)
{
	for(typename T::iterator it=begin(v); it !=end(v); ++it)
		std::cout <<green << *it << " ";
	std::cout << reset <<std::endl;
}

template<typename T>
typename T::iterator  easyfind(T &container, int tbs)
{
	typename T::iterator it= find(begin(container), end(container), tbs);
	try
	{
		if (it == container.end())
		{
			throw std::out_of_range("Element not found");
		}
		else
		return (it);
	}
	catch (const std::out_of_range & exc)
	{
		 std::cerr << magenta << exc.what() << reset <<'\n';
		 return (end(container));
	}
}

#endif
