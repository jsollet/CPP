#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed const a( Fixed (-5.05f ) + Fixed ( 2));
	Fixed const b( Fixed( -5.05f ) + Fixed( 2.0f ) );
	Fixed d, e;

	d = Fixed(10.3f) + Fixed(55.8f) + Fixed(-10.3f);	
	e = Fixed(1.0f) / Fixed(0.0f);
	std::cout << d << std::endl;
//	std::cout << ++a << std::endl;
	std::cout << e << std::endl;
//	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
		
	std::cout << b << std::endl;
	std::cout << 0 - Fixed(0).toFloat() << std::endl;
//	test comparaison
	std::cout << (Fixed(-5) > Fixed(0) )<< std::endl;
	std::cout << (Fixed(-5) > Fixed(-5) )<< std::endl;
	std::cout << (Fixed(-5) > Fixed(-10)) << std::endl;
//	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
