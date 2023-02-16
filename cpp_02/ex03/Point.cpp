#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() :x(Fixed(0)), y(Fixed(0))
{
}

Point::~Point() {}

Point::Point(const Fixed x,const Fixed y) :x(x), y(y)
{
}

Point::Point(const Point &point) :x(point.getX()), y(point.getY())
{
}

Point	&Point::operator=(const Point &rhs)
{
	(void)rhs;
	return (*this);
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}

Point	translate(Point const base, Point const arrow)
{
	
	Fixed	delta_x, delta_y;
	
	delta_x = arrow.getX() - base.getX();
	delta_y = arrow.getY() - base.getY();
	Point result(delta_x, delta_y);
	return (result);
}

Fixed	cross(Point const a, Point const b)
{
	Fixed result;

	result = (a.getX()*b.getY()) - (a.getY()*b.getX());
	return (result);
}

