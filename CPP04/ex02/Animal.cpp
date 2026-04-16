/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:17:10 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{
	this->type = "Default";
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) 
{
	this->type = type;
	std::cout << "Animal type parameterized constructor called." << std::endl;
}

Animal::Animal(const Animal& to_copy)
{
	this->type = to_copy.type;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& to_copy)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		this->type = to_copy.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}