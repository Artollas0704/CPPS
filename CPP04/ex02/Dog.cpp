/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:17:10 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << "Dog type parameterized constructor called." << std::endl;
}

Dog::Dog(const Dog& to_copy) : Animal(to_copy)
{
	this->type = to_copy.type;
	brain = new Brain(*to_copy.brain);
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& to_copy)
{
	Animal::operator=(to_copy);
	if (this != &to_copy)
	{
		delete brain;
		brain = new Brain(*to_copy.brain);
		this->type = to_copy.type;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}