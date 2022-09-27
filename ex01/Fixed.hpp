/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:09:01 by ayassin           #+#    #+#             */
/*   Updated: 2022/09/27 17:37:24 by ayassin          ###   ########.fr       */
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
		Fixed(Fixed &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &cpy);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void);
		int		toInt(void);
		private:
			int int_value;
			static const int frac = 8;
};
#endif 