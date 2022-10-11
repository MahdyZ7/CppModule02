
# include "Point.hpp"

Point::Point(void):x(0), y(0)
{
	// std::cout << "Default constructor called\n";
}

Point::Point(const Fixed x_cor, const Fixed y_cor): x(x_cor), y(y_cor)
{
	// std::cout << "Parmeteric constructor called\n";
}

Point::Point(Point const &src):x(src.x), y(src.y)
{
	// std::cout << "copy constructor called\n";
}

Point::~Point(void)
{
	// std::cout << "Destructor called\n";
}

Point &Point::operator=(Point const &cpy)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &cpy)
            {
                Point	tmp(cpy);  // Use copy constructor here
				std::swap(*this, tmp);
                // this->swap(tmp);   // Now Swap
            }
	return (*this);
}

int Point::orintation(Point const &a, Point const &b, Point const &c)
{
	float x = (((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x))).toFloat();
	// std::cout << 
	if (x == 0)
		return (0);
	if (x > 0)
		return (1);
	return (-1);
}

const Fixed &Point::getX(void) const
{
	return (x);
}

const Fixed &Point::getY(void) const
{
	return (y);
}

std::ostream& operator<<(std::ostream &os, Point const &n)
{
	os << "(" << n.getX() << ", " << n.getY()<< ")";
	return (os);
}