/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:09:01 by ayassin           #+#    #+#             */
/*   Updated: 2022/09/29 12:58:05 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	public:
		Fixed(void);
		Fixed(const int x);
		Fixed(const float x);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &cpy);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
		private:
			int num;
			static const int frac = 8;
};

std::ostream& operator<<(std::ostream &os, Fixed const &n);

#endif 