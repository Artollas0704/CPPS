/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/13 20:03:38 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
	raw_bits = 0;
}

Fixed::Fixed(const int n)
{
		this->raw_bits = n << Fixed::fractional;
}

Fixed::Fixed(const float f)
{
	this->raw_bits = roundf(f * (1  << Fixed::fractional));
}

Fixed::Fixed(const Fixed& to_copy)
{
	raw_bits = to_copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& to_copy)
{
	if (this != &to_copy)
	{
		this->raw_bits = to_copy.raw_bits;
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const {
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

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{
	return (this->raw_bits > other.raw_bits);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->raw_bits < other.raw_bits);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->raw_bits >= other.raw_bits);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->raw_bits <= other.raw_bits);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->raw_bits == other.raw_bits);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->raw_bits != other.raw_bits);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->raw_bits + other.raw_bits);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->raw_bits - other.raw_bits);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->raw_bits * other.raw_bits) >> Fixed::fractional);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->raw_bits << Fixed::fractional) / other.raw_bits);
	return (result);
}

Fixed& Fixed::operator++()
{
	this->raw_bits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->raw_bits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}