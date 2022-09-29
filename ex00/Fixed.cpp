/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:53 by ayassin           #+#    #+#             */
/*   Updated: 2022/09/29 09:23:03 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &src)
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