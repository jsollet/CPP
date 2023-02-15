#include "Fixed.hpp"

Fixed::Fixed()
{
	this->store = 0;
}

Fixed::Fixed(const int a)
{
	this->store = a << Fixed::b;
}

Fixed::Fixed(const float a)
{
	this->store = roundf(a* std::pow(2, Fixed::b));
}

Fixed::Fixed(const Fixed& fixed)
{
	this->store = fixed.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed& rhs)
{
	this->store = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &os, Fixed const& rhs)
{
	os << rhs.toFloat();
	return (os);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed result(this->toFloat() + rhs.toFloat());
	return (result);
}


Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed result(this->toFloat() - rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed result(this->toFloat() * rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed result(this->toFloat() / rhs.toFloat());
	return (result);
}

Fixed::~Fixed()
{
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
	return Fixed::store;
}

void	Fixed::setRawBits(int const raw)
{
	this->store = raw;
}

int		Fixed::toInt(void) const
{
	return (this->store>>Fixed::b);
}

float	Fixed::toFloat(void) const
{
	return (this->store / std::pow(2, Fixed::b));
}
