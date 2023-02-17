#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->store = 0;
}

Fixed::Fixed(const int& a)
{
	std::cout << "Int constructor called" << std::endl;
	this->store = a << Fixed::b;
}

Fixed::Fixed(const float& a)
{
	std::cout << "Float constructor called" << std::endl;
	this->store = roundf(a* pow(2, Fixed::b));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->store = fixed.getRawBits();
}

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

std::ostream	&operator<<(std::ostream &os, Fixed const& rhs)
{
	os << rhs.toFloat();
	return (os);
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return Fixed::store;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member function called" << std::endl;
	this->store = raw;
}

int		Fixed::toInt(void) const
{
	return (this->store>>Fixed::b);
}

float	Fixed::toFloat(void) const
{
	return (this->store / pow(2, Fixed::b));
}
