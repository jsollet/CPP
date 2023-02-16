#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	std::cout << std::boolalpha;
	std::cout<< " Test bsp: p sur sommet A " << std::endl;
	std::cout << bsp(Point(0.0f,0.0f), Point(4, 0), Point(4,4), Point(0,0)) << std::endl; ;
	std::cout<< " Test bsp: p sur arete AC " << std::endl;
	std::cout << bsp(Point(0.0f,0.0f), Point(4, 0), Point(4,4), Point(2,2)) << std::endl; ;
	std::cout << " Test bsp: hors ABC" << std::endl;
	std::cout << bsp(Point(0.0f,0.0f), Point(4, 0), Point(4,4), Point(12,2))<< std::endl ;
	std::cout << " Test bsp: p interieur " << std::endl;
	std::cout << bsp(Point(0.0f,0.0f), Point(4, 0), Point(4,4), Point(2,1)) << std::endl;;
	std::cout << std::noboolalpha <<std::endl;	
	return 0;
}
