/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:58:35 by ayassin           #+#    #+#             */
/*   Updated: 2022/10/05 09:01:57 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator>(Fixed const &cpy)
{
	if (this->num > cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator>=(Fixed const &cpy)
{
	if (this->num >= cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator<(Fixed const &cpy)
{
	if (this->num < cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator<=(Fixed const &cpy)
{
	if (this->num <= cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator==(Fixed const &cpy)
{
	if (this->num == cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator!=(Fixed const &cpy)
{
	if (this->num != cpy.num)
		return (true);
	return(false);
}

