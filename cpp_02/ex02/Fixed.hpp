#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int a);
		Fixed(const float f);
		Fixed &operator=(const Fixed& rhs); 
		~Fixed();
		
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		static Fixed		min(Fixed &lhs, Fixed &rhs);
		const static Fixed	min(const Fixed &lhs, const Fixed &rhs);
		static Fixed		max(Fixed &lhs, Fixed &rhs);
		const static Fixed	max(const Fixed &lhs, const Fixed &rhs);


	private:
		int					store;
		const static	 	int	b = 8;
};

		std::ostream &operator<<(std::ostream& os, Fixed const& rhs);
#endif
