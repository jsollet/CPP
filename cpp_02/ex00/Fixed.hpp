#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed& rhs); 
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private:
		int					store;
		const static	int	b = 8;
};

#endif
