#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <limits> // a voir

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class ScalarConversion
{
	public:
		ScalarConversion();
		ScalarConversion(const ScalarConversion &rhs);
		ScalarConversion(const std::string &arg);
		~ScalarConversion();

	// conversion
	char	toChar()	const;
	int		toInt()		const;
	float	toFloat()	const;
	double	toDouble()	const;

	// getter
	const std::string			&getArg() const;

	static bool					debug;

	private:
		const	std::string		arg;

	public:
		class InvalidArgument : public std::exception
		{
			virtual const char *what() const throw()
			{
				return (" Usage: ./convert arg1 ");
			}
		}
		
	public:
		class NonDisplayable : public std::exception
		{
			virtual const char *what() const throw()
			{
				return (" Non displayable ");
			}
		}
	
	public:
		class Impossible : public std::exception
		{
			virtual const char *what() const throw()
			{
				return (" Impossible  ");
			}
		}
};

#endif

