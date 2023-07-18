#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc !=2)
	{
		std::cout<< red << "Nothing to compute\n";
		return (-1);
	}
	else
	{
		std::string arg = argv[1];
		RPN rpn(arg);
		return (0);
	}

}
