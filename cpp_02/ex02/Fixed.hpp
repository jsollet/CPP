#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);// ?
		Fixed(const int a);// est-ce juste ?
		Fixed(const float f); //ces 2 la^^^des constructeurs de recopie
		Fixed &operator=(const Fixed& rhs);//attn d'autres modele existent 
		//https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom#3279550
		// v.p 142 c++ tour
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;
	// a verifier faux bool
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					store;
		const static	int	b = 8;
};

		std::ostream &operator<<(std::ostream& os, Fixed const& rhs);
#endif
