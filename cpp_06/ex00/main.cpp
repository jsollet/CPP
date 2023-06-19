#include "ScalarConverter.hpp"


int main(int argc, const char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::cout<< " bad number arguments "<< std::endl;
	}
	return (0);
}
