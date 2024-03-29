#ifndef BASE_HPP
# define BASE_HPP

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

class Base
{
	public:
		virtual ~Base(void);
};

#endif
