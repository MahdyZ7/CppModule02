/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:53 by ayassin           #+#    #+#             */
/*   Updated: 2022/09/27 17:29:25 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):int_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x):int_value(x)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float x):int_value(static_cast<int>(x))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(Fixed &src)
{
	*this = src;
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	this->int_value = cpy.int_value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout<< "getRawBits member function called\n";
	return(int_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout<< "setRawBits member function called\n";
	int_value = raw;
}