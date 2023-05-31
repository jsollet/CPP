#include "Argument.hpp"

int main(int argc, const char *argv[])
{
	if (argc == 2)
	{
		Argument	arg(argv[1]);
		std::cout << arg.getArgv()<<std::endl;
		std::cout << std::boolalpha << arg.is_char_print() << '\n';
	}
	else
	{
		std::cout<< " bad number arguments "<< std::endl;
	}
	return (0);
}	
