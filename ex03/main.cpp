#include "Point.hpp"

int main()
{
	const Point a(1, 7);
	const Point b(7, 4);
	const Point c(9, 11);
	const Point p(-9,11);

	if (bsp(a,b,c,p))
		std::cout << "true\n";
	else
		std::cout << "false\n";
}