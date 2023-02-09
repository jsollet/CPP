#include <iostream>
#include <string>
#include "Harl.hpp"


int main(int argc, char *argv[])
{
	Harl	moi;

	if (argc == 2)
	{
		moi.escalate(argv[1]);
	}
	else
	{
		std::cerr<< "Number of arguments non valid (Harl only wants ONE argument !)"<< std::endl;
	}
	return (0);
}
