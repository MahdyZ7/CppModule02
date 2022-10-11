/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:35:22 by ayassin           #+#    #+#             */
/*   Updated: 2022/10/05 10:43:20 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

void judge(Point a, Point b, Point c, Point t)
{
	std::cout << "For point " << t << " in the case for triangle ";
	std::cout << a << ", " << b << ", " << c << " the verdic is:\n";
	if (bsp(a, b, c, t))
		std::cout<< "\033[0;32min\033[0m\n";
	else
		std::cout<< "\033[0;31mout\n\033[0m";
}
int main(void)
{
	// point in
	Fixed ax(-1), ay(0), bx(1), by(0), cx(0), cy(2), px(0), py(1.99f);
	Point a(ax, ay), b(bx, by), c(cx, cy), pin(px, py);
	judge(a, b, c, pin);
	
	// point out 
	Point a1 = a, b1 = b, c1 = c, pout(px + 1, py - 1);
	judge(a1, b1, c1, pout);

	// point on edge
	px = Fixed(0.5f);
	py = Fixed(0);
	Point a2(a), b2(b), c2(c), byline(px, py);
	judge(a2, b2, c2, byline);
}