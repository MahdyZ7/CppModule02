/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:53 by ayassin           #+#    #+#             */
/*   Updated: 2022/10/04 16:56:02 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// void printbits(int x)
// {
// 	for (int i = 31; i >= 0 ; --i)
// 	{
// 		std::cout << ((x >> i) & 1);
// 		if (i % 4 == 0)
// 			std::cout << " ";
// 	}
// 	std::cout << std::endl;
// }

Fixed::Fixed(void):num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x)
{	
	std::cout << "Int constructor called\n";
	num = x << frac;
	if (x < 0)
		num = num | 0x80000000;
	else
		num =  num & 0x7fffffff;
}

Fixed::Fixed(const float x)
{
	num = 0;
	num = num | ((int) roundf(x * (1 << frac)));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	this->num = cpy.num;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return(num);
}

void Fixed::setRawBits(int const raw)
{
	num = raw;
}

float Fixed::toFloat(void) const
{
	return(float (num) / float (1u << frac));
}

int Fixed::toInt(void) const
{
	return((num >> frac) + ((num & ((2 << frac) - 1)) && (num < 0)));
}

std::ostream& operator<<(std::ostream &os, Fixed const &n)
{
	os << n.toFloat();
	return (os);
}