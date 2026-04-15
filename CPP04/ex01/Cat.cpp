/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:17:10 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "Cat type parameterized constructor called." << std::endl;
}

Cat::Cat(const Cat& to_copy) : Animal(to_copy)
{
	this->type = to_copy.type;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& to_copy)
{
	Animal::operator=(to_copy);
	if (this != &to_copy)
	{
		this->type = to_copy.type;
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}