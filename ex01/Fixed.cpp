/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:53 by ayassin           #+#    #+#             */
/*   Updated: 2022/09/30 18:44:32 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void printbits(int x)
{
	for (int i = 31; i > 0 ; --i)
		std::cout << ((x >> i) & 1);
	std::cout << std::endl;
}
Fixed::Fixed(void):num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x)
{
	// int temp = x, sign, exp = 0;
	// int i = 0;
	
	// sign = x >> 31;
		
	// temp = temp & 0x7fff;
	// while (temp > 0 && temp >> i != 1)
	// 	++i;
	// exp = 127 + i;
	
	// temp = temp ^ (1 << i);
	// if (i >= 23)
	// 	temp = temp >> (i - 23);
	// else
    // 	temp =  temp << (23 - i);
	// num = sign << 31 | exp << 23 | temp;
	num = x << frac;
	if (x < 0)
		num = num | 0x80000000;
	else
		num =  num & 0x7fffffff;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float x)
{
	// num = roundf(x);
	// num = num << frac;
	// if (x < 0)
	// 	num = num | 0x80000000;
	// else
	// 	num =  num & 0x7fffffff;
	num = 0;
	num = (x * (1 << frac));
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
	return(*(float *)(&num));
}

int Fixed::toInt(void) const
{
	return(num >> frac);
}

std::ostream& operator<<(std::ostream &os, Fixed const &n)
{
	int raw = n.getRawBits();
	int int_part = raw >> 8;
	if (raw >> 31)
	{
		std::cout << "green\n";
		int_part = int_part | 0xff000000;
	}
	os << int_part << "." << (raw & 0xFF) * 1000 / (1<<8);
	return (os);
}