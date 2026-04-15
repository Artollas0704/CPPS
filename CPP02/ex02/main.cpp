/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:38 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/13 20:03:07 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	Fixed e(5.5f);
	Fixed f(3.2f);
	
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "e > f: " << (e > f) << std::endl;
	std::cout << "e < f: " << (e < f) << std::endl;
	std::cout << "e >= f: " << (e >= f) << std::endl;
	std::cout << "e <= f: " << (e <= f) << std::endl;
	std::cout << "e == f: " << (e == f) << std::endl;
	std::cout << "e != f: " << (e != f) << std::endl;
	
	Fixed g(5.5f);
	std::cout << "\ne == g (same value): " << (e == g) << std::endl;
	std::cout << "e != g (same value): " << (e != g) << std::endl;

	Fixed h(10.5f);
	Fixed i(2.5f);
	
	std::cout << "h = " << h << ", i = " << i << std::endl;
	std::cout << "h + i = " << (h + i) << std::endl;
	std::cout << "h - i = " << (h - i) << std::endl;
	std::cout << "h * i = " << (h * i) << std::endl;
	std::cout << "h / i = " << (h / i) << std::endl;
	
	Fixed j(5.0f);
	std::cout << "j = " << j << std::endl;
	std::cout << "++j = " << ++j << std::endl;
	std::cout << "j after ++j = " << j << std::endl;

	Fixed k(5.0f);
	std::cout << "k = " << k << std::endl;
	std::cout << "k++ = " << k++ << std::endl;
	std::cout << "k after k++ = " << k << std::endl;

	Fixed l(5.0f);
	std::cout << "l = " << l << std::endl;
	std::cout << "--l = " << --l << std::endl;
	std::cout << "l after --l = " << l << std::endl;

	Fixed m(5.0f);
	std::cout << "m = " << m << std::endl;
	std::cout << "m-- = " << m-- << std::endl;
	std::cout << "m after m-- = " << m << std::endl;

	Fixed n(7.5f);
	Fixed o(3.2f);
	
	std::cout << "min(n, o) = " << Fixed::min(n, o) << std::endl;
	
	const Fixed p(12.0f);
	const Fixed q(8.5f);
	std::cout << "min(p, q) = " << Fixed::min(p, q) << std::endl;
	std::cout << "max(n, o) = " << Fixed::max(n, o) << std::endl;
	std::cout << "max(p, q) = " << Fixed::max(p, q) << std::endl;

	return (0);
}
