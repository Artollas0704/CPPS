/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/13 18:00:26 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
	raw_bits = 0;
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called." << std::endl;
		this->raw_bits = n << Fixed::fractional;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called." << std::endl;
	this->raw_bits = roundf(f * (1  << Fixed::fractional));
}

Fixed::Fixed(const Fixed& to_copy)
{
	std::cout << "Copy constructor called." << std::endl;
	raw_bits = to_copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		this->raw_bits = to_copy.raw_bits;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called." << std::endl;
	return (this->raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}

int Fixed::toInt(void) const
{
	return (this->raw_bits >> Fixed::fractional);
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw_bits / (1 << Fixed::fractional));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}