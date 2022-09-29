/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:53 by ayassin           #+#    #+#             */
/*   Updated: 2022/09/29 17:29:49 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x)
{
	int temp = x, sign, exp = 0;
	int i = 0;
	
	sign = x >> 31;
		
	temp = temp & 0x7fff;
	while (temp > 0 && temp >> i != 1)
		++i;
	exp = 127 + i;
	
	temp = temp ^ (1 << i);
	if (i >= 23)
		temp = temp >> (i - 23);
	else
    	temp =  temp << (23 - i);
	num = sign << 31 | exp << 23 | temp;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float x):num(*((int *)(&x)))
{
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
	std::cout<< "getRawBits member function called\n";
	return(num);
}

void Fixed::setRawBits(int const raw)
{
	std::cout<< "setRawBits member function called\n";
	num = raw;
}

float Fixed::toFloat(void) const
{
	return(*(float *)(&num));
}

int Fixed::toInt(void) const
{
	return(roundf(*((float *)(&num))));
}

std::ostream& operator<<(std::ostream &os, Fixed const &n)
{
	os << n.toFloat();
	return (os);
}