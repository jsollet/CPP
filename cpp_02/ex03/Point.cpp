#include "Fixed.hpp"
#include "Point.hpp"
// pas sur...

Point::Point() :x(Fixed(0)), y(Fixed(0))
{
}
// la bonne maniere de le faire ^^
Point::~Point() {}

Point::Point(const Fixed x,const Fixed y) :x(x), y(y)
{
//	this->x = Fixed(x);
//	this->y = Fixed(y);
}

Point::Point(const Point &point) :x(point.getX()), y(point.getY())
{
//	this->x = point.getX();
//	this->y = point.getY();
}
// Pb avec operator=()
Point	&Point::operator=(const Point &rhs)
{
	(void)rhs;
//	this->x = rhs.x;
//	this->y = rhs.y;
	return (*this);
}
/*
void	Point::setX(const Fixed x)
{
	this->x = x;
}


void	Point::setY(const Fixed y)
{
	this->y = y;
}
*/
Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
//  a tester
Point	translate(Point const base, Point const arrow)
{
	
	Fixed	delta_x, delta_y;
	
//	delta_x = arrow.x - base.x;
//	delta_y = arrow.y - base.y;
	Fixed test = base.getX();
	std::cout << "test =" << test << std::endl;
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

