#include "Point.hpp"

Fixed	my_abs(Fixed m)
{
	const Fixed n(-m.toFloat());
	if (m.toFloat() < 0)
		return (n);
	return (m);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed surface;
	Fixed surface1;
	Fixed surface2;
	Fixed surface3;

	surface = my_abs((a.getfixedx() * (b.getfixedy() - c.getfixedy()) + b.getfixedx() * (c.getfixedy() - a.getfixedy()) + c.getfixedx() * (a.getfixedy() - b.getfixedy()))/2);
	surface1 = my_abs((a.getfixedx() * (b.getfixedy() - point.getfixedy()) + b.getfixedx() * (point.getfixedy() - a.getfixedy()) + point.getfixedx() * (a.getfixedy() - b.getfixedy()))/2);
	surface2 = my_abs((a.getfixedx() * (point.getfixedy() - c.getfixedy()) + point.getfixedx() * (c.getfixedy() - a.getfixedy()) + c.getfixedx() * (a.getfixedy() - point.getfixedy()))/2);
	surface3 = my_abs((point.getfixedx() * (b.getfixedy() - c.getfixedy()) + b.getfixedx() * (c.getfixedy() - point.getfixedy()) + c.getfixedx() * (point.getfixedy() - b.getfixedy()))/2);
	if (surface1 == 0 || surface2 == 0 || surface3 == 0)
		return (false);
	if ((surface1 + surface2 + surface3) != surface)
		return (false);
	return (true);
}
