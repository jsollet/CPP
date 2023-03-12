#include "ScalarConversion.hpp"

bool	ScalarConversion::debug = false;

// getter

const std:string	getArg() const
{
	return (this->arg);
}

// coplien
ScalarConversion::ScalarConversion():arg("")
{
	if (ScalarConversion::debug)
		std::cout << "Default constructor scalar " << std::endl;
}

ScalarConversion::ScalarConversion(const ScalarConversion &rhs)
: arg(rhs.getArg();
{
	if (ScalarConversion::debug)
		std::cout << "Copy constructor scalar " << std::endl;
}

ScalarConversion::ScalarConversion(const std::string &Arg):arg(Arg)
{
	if (ScalarConversion::debug)
		std::cout << "Param. constructor scalar " << std::endl;
}

ScalarConversion::~ScalarConversion(){}

ScalarConversion	&operator=(const ScalarConversion &rhs)
{
}


// converter
