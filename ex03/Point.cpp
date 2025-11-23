#include "Point.hpp"

Point::Point(void)
	:x(0), y(0)
{
	// std::cout << "Default Constructor called.\n";
}

Point::Point(const float a, const float b)
	:x(a), y(b)
{
	// std::cout << "Constructor called.\n";
}

Point::Point(const Point &obj)
	:x(obj.x), y(obj.y)
{
	*this = obj;
}

Point &Point::operator=(const Point &obj)
{
	// std::cout << "Copy assignement operator called.\n";
	obj.getfixedx();
	return (*this);
}

Point::~Point(void)
{
	// std::cout << "Destructor called.\n";
}

const Fixed &Point::getfixedx(void) const
{
	return (x);
}

const Fixed &Point::getfixedy(void) const
{
	return (y);
}