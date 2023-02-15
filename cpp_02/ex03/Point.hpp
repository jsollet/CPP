#ifndef POINT_HPP
# define POINT_HPP
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &point);
		Point &operator=(const Point& rhs);
		~Point();


//		void	setX(const Fixed x);
//		void	setY(const Fixed y);
		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		const Fixed	x;
		const Fixed	y;
};
Point	translate( Point const base, Point const arrow);
Fixed	cross(Point const a, Point const b);
bool	bsp( Point const a, Point const b, Point const c, Point const point);
#endif
