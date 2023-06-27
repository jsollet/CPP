#ifndef ARRAY_HPP
# define  ARRAY_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

template<typename T>
class Array
{
	private:
		T*				elem;
		unsigned int	sz;
	public:
		Array();
		Array(unsigned int s);
		Array(const Array &rhs);
		~Array();

		Array	&operator=(const Array &rhs);
		
		T		&operator[](unsigned int i);
		const T	&operator[](unsigned int i) const;
		unsigned int size() const;
		
		class invalidIndex: public std::exception
		{
			public:
			virtual const char * what() const throw()
			{
				return "Error: out of range index\n";
			}
		};
};

#include "Array.tpp"
#endif
