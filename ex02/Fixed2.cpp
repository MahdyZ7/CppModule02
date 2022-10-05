/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:08:51 by ayassin           #+#    #+#             */
/*   Updated: 2022/10/05 10:58:21 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator++() //prefix
{
	++num;
	return (*this);
}

Fixed Fixed::operator++(int) //postfix
{
	Fixed temp;
	temp.num = ++num;
	return (temp);
}

Fixed &Fixed::operator--() //prefix
{
	--num;
	return (*this);
}

Fixed Fixed::operator--(int) //postfix
{
	Fixed temp;
	temp.num = --num;
	return (temp);
}

Fixed Fixed::operator+(Fixed const &alu)
{
	Fixed temp;
	temp.num = this->num + alu.num;
	return (temp);
}

Fixed Fixed::operator-(Fixed const &alu)
{
	Fixed temp;
	temp.num = this->num - alu.num;
	return (temp);
}

Fixed Fixed::operator*(Fixed const &alu)
{
	Fixed temp;
	long prod = long (this->num) * long (alu.num);
	temp.num = prod >> frac;
	return (temp);
}

Fixed Fixed::operator/(Fixed const &alu)
{
	Fixed temp;
	temp.num = long ((this->num) * (1 << 16)) / long (alu.num);
	return (temp);
}