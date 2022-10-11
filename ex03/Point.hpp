
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"
class Point{
	public:
		Point(void);
		Point(const Fixed x_cor, const Fixed y_cor);
		Point(Point const &src);
		~Point(void);

		Point &operator=(Point const &cpy);
		static int	orintation(Point const &a, Point const &b, Point const &c);
		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream &os, Point const &n);

#endif