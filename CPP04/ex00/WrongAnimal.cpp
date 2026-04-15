/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:17:10 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
	this->type = "Default";
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) 
{
	this->type = type;
	std::cout << "WrongAnimal type parameterized constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy)
{
	this->type = to_copy.type;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& to_copy)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		this->type = to_copy.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random WrongAnimal sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}