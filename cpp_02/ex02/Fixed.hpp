#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);// ?constructeur de copie
		Fixed(const int a);// est-ce juste ?
		Fixed(const float f); //ces 2 la^^^des constructeurs de recopie
		Fixed &operator=(const Fixed& rhs);//attn d'autres modele existent 
		~Fixed();// verifie coplien ?
		//https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom#3279550
		// v.p 142 c++ tour
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
	// prefix and postfix increment
		Fixed &operator++();
		Fixed operator++(int);
	// prefix and postfix decrement
		Fixed &operator--();
		Fixed operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	// les fonction statiques... A VERIFIER:bien lire... (surrout retour ?
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
