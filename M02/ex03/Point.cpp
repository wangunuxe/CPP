#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float a, const float b) : x(a), y(b){}

Point::Point(const Point& other)
{
	*this = other;
}
Point& Point::operator=(const Point& other)
{
	// the code is illegal, because x and y are const, C++ forbids assignment to const members.
	// if (this != &other)
	// {
	// 	this->x = other.x;
	// 	this->y = other.y;
	// }
	(void)other;
	return *this;
}

Point::~Point(){}

Fixed Point::getX(void) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return this->y;
}
