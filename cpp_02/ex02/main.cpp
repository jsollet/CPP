#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed d, e;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "test officiel"<<std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
		
//	Test operation
	Fixed b1, b2, b3;
	b1 = Fixed(12.4f);
	b2 = Fixed(100.f - 12.4f);
	b3 = Fixed(42);
	std::cout << "Test operation" << std::endl;
	std::cout << "b1 = " << b1 << " b2 = " << b2 << " b3 = " << b3 << std::endl;
	std::cout << "b1 + b2 -b3 =  ?\t" << (b1+b2-b3)<< std::endl;
	std::cout << "b1 + (b2*b3) =  ?\t" << (b1+(b2*b3))<< std::endl;
	std::cout << "b1 / (b2*b3) =  ?\t" << (b1/(b2*b3))<< std::endl;
	std::cout << "(b3*b2) / (b2*b3) =  ?\t" << ((b3*b2)/(b2*b3))<< std::endl;
	std::cout << "(b3*b3)*(b3*b3) =  ?\t" << ((b3*b3)*(b3*b3))<< std::endl;
//	test comparaison
	Fixed A, B;
	A = Fixed(-5);
	B = Fixed(-10);
	std::cout << "Test comparaison" << std::endl;
	std::cout << "A = -5, B = -10" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "A == A ?\t" << (A == A )<< std::endl;
	std::cout << "A == B ?\t" << (A == B )<< std::endl;
	std::cout << "A != A ?\t" << (A != A )<< std::endl;
	std::cout << "A != B ?\t" << (A != B )<< std::endl;
	std::cout << "A >= A ?\t" << (A >= A )<< std::endl;
	std::cout << "A <= B ?\t" << (A <= B )<< std::endl;
	std::cout << "A < A  ?\t" << (A < A )<< std::endl;
	std::cout << "A > B  ?\t" << (A > B )<< std::endl;
	std::cout << std::noboolalpha <<std::endl;
	
	std::cout<<"!! overflow !!"<<std::endl;
	std::cout<<8388607<<"--->"<<Fixed(8388607)<<std::endl;
	std::cout<<8388608<<"--->"<<Fixed(8388608)<<std::endl;
// 

	
	Fixed a1,a2,a3,a4,a5, res;
	a1 = Fixed(20.f);
	a2 = Fixed(30.f);
	a3 = Fixed(40.f);
	a4 = Fixed(100);
	a5 = Fixed(0);
	
	std::cout<<"test a++ et ++a "<< std::endl;
	std::cout << a5 << "\t\ta++ = " << a5++ <<"\t\t -->  " << a5 << std::endl;;
	std::cout << a5 << "\t++a = " << ++a5 <<"\t -->  " << a5 << std::endl;;
	std::cout<<"test a-- et --a "<< std::endl;
	std::cout << a5 << "\ta-- = " << a5-- <<"\t -->  " << a5 << std::endl;;
	std::cout << a5 << "\t--a = " << --a5 <<"\t\t -->  " << a5 << std::endl;;

	// a voir...
//	std::cout<<"test (a--)++ et ++(--a) "<< std::endl;
//	a5 = Fixed(0);
//
//	std::cout << a5 << "\t(a--)= " << (a5--) <<"\t a++  " << a5++ << "  " << a5<< std::endl;;
//	std::cout << a5 << "\t++(--a) = " << ++(--a5) <<"\t\t -->  " << a5 << std::endl;;
	std::cout<<" test min et max "<< std::endl;
	res = Fixed::max(a2, Fixed::min(a1, a4));
	std::cout << "max("<< a2<< ", min("<< a1 << "," << a4 <<") = " << res << std::endl << std::endl;
	res = Fixed::min(a2, Fixed::min(a1, a4));
	std::cout << "min("<< a2<< ", min("<< a1 << "," << a4 <<") = " << res << std::endl << std::endl;
	res = Fixed::min(a2, Fixed::max(a1, a4));
	std::cout << "min("<< a2<< ", max("<< a1 << "," << a4 <<") = " << res << std::endl << std::endl;

	std::cout << Fixed::min( d, e ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	return 0;
}
