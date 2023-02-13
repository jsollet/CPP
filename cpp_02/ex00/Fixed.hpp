#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);// ?
		Fixed(const int& a);// est-ce juste ?
		Fixed(const float& f); //ces 2 la^^^des constructeurs de recopie
		Fixed &operator=(const Fixed& rhs);//attn d'autres modele existent 
		//https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom#3279550
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private:
		int					store;
		const static	int	b = 8;
};

#endif
