#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(const float a, const float b);
		Point(const Point &obj);
		Point &operator=(const Point &obj);
		~Point(void);
		const Fixed &getfixedx(void) const;
		const Fixed &getfixedy(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif