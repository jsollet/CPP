#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->store = 0;
}
// pas sur...
Fixed::Fixed(const int& a)
{// faut il <<fixed::b ?
	std::cout << "Int constructor called" << std::endl;
	this->store = a << Fixed::b;
}

Fixed::Fixed(const float& a)
{
	std::cout << "Float constructor called" << std::endl;
	this->store = a* pow(2, Fixed::b);
}
// est-ce qu'il faut constructeur copie avec Fixed
Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->store = fixed.getRawBits();
}

//  ??
Fixed	&Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->store = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return Fixed::store;
}
// ??
void	Fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member function called" << std::endl;
	this->store = raw << Fixed::b;
}

