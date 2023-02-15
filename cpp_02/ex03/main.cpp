#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	const Point a(2.4f, 0.f);
	Point b(2.4f, 2.f);
	Point c = b;
  //
  //	c = b;
	Fixed x, y;
	x = a.getX();
	y = a.getY();
	std::cout<< c.getX() << "  " << c.getY() << std::endl;

	std::cout<< Fixed(10)*x << " <-x, y->  " << Fixed(10)*y << std::endl;
	Point d = translate(a, b);
	
	std::cout<< d.getX() << " <-x, y->  " << d.getY() << std::endl;
	std::cout<< "test cross product \n" << std::endl;
	std::cout<< cross(a,b) << "axb   bxa" << cross(b,a)<<std::endl;
	std::cout<< cross(a,a) << "axa" << std::endl;
	
	
	
	
	
	return 0;
}
