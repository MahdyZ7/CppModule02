#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int p = Point::orintation(a, b, point) + Point::orintation(b, c, point) + Point::orintation(c, a, point);
	if (p == 3 || p == -3)
		return (true);
	return(false);
}