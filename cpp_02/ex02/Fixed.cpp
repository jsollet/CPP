#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->store = 0;
}
// pas sur...entier cte pas ref entier cte
Fixed::Fixed(const int a)
{// faut il <<fixed::b ?
	std::cout << "Int constructor called" << std::endl;
	this->store = a << Fixed::b;
}
// faut-il mettre roundf() ? voir remarque dessus
Fixed::Fixed(const float a)
{
	std::cout << "Float constructor called" << std::endl;
	this->store = roundf(a* pow(2, Fixed::b));
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

std::ostream	&operator<<(std::ostream &os, Fixed const& rhs)
{
	os << rhs.toFloat();
	return (os);
}
// arithm op
Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed result(this->toFloat() + rhs.toFloat());
	return (result);
}


Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed result(this->toFloat() + rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed result(this->toFloat() * rhs.toFloat());
	return (result); // ??
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed result(this->toFloat() / rhs.toFloat());
	return (result); // ??
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->store > rhs.store);
}


int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return Fixed::store;
}
// ??*******************3a modifier avant aussi ***********************
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->store = raw << Fixed::b;
}

int		Fixed::toInt(void) const
{
	return (this->store>>Fixed::b);
}

float	Fixed::toFloat(void) const
{
	return (this->store / pow(2, Fixed::b));
}
