#include "Fixed.hpp"

Fixed::Fixed()
{
//	std::cout << "Default constructor called" << std::endl;
	this->store = 0;
}
// pas sur...entier cte pas ref entier cte
Fixed::Fixed(const int a)
{// faut il <<fixed::b ?
//	std::cout << "Int constructor called" << std::endl;
	this->store = a << Fixed::b;
}
// faut-il mettre roundf() ? voir remarque dessus
Fixed::Fixed(const float a)
{
//	std::cout << "Float constructor called" << std::endl;
	this->store = roundf(a* std::pow(2, Fixed::b));
}
// est-ce qu'il faut constructeur copie avec Fixed
Fixed::Fixed(const Fixed& fixed)
{
//	std::cout << "Copy constructor called" << std::endl;
	this->store = fixed.getRawBits();
}

//  ??
Fixed	&Fixed::operator=(const Fixed& rhs)
{
//	std::cout << "Copy assignment operator called" << std::endl;
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
//	std::cout << "Destructor called" << std::endl;
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->store < rhs.store);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->store > rhs.store);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->store >= rhs.store);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->store <= rhs.store);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->store == rhs.store);
}


bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->store != rhs.store);
}

// increment ??
Fixed	&Fixed::operator++()
{
	++store;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}
// decrement
Fixed	&Fixed::operator--()
{
	--store;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
// static min et max a voir si & ou pas ?
// avant lhs.getRawBits()
Fixed	Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	const Fixed::min(const Fixed &lhs,const Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	const Fixed::max(const Fixed &lhs,const Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return Fixed::store;
}
// ??*******************3a modifier avant aussi ***********************
void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
	this->store = raw;// << Fixed::b;
}

int		Fixed::toInt(void) const
{
	return (this->store>>Fixed::b);
}

float	Fixed::toFloat(void) const
{
	return (this->store / std::pow(2, Fixed::b));
}
