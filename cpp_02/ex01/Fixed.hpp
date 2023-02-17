#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int& a);
		Fixed(const float& f);
		Fixed &operator=(const Fixed& rhs); 
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
