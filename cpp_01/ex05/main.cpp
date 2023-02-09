#include <iostream>
#include <string>
#include "Harl.hpp"


int main()
{
	Harl	moi;

	std::cout<<std::endl;	
	moi.complain("DEBUG");
	std::cout<<std::endl;	
	moi.complain("INFO");
	std::cout<<std::endl;	
	moi.complain("WARNING");
	std::cout<<std::endl;	
	moi.complain("ERROR");
	std::cout<<std::endl;	
	moi.complain("???");
	return (0);
}
