/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:17:10 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	this->type = "Brain";
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& to_copy)
{
	this->type = to_copy.type;
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& to_copy)
{
	if (this != &to_copy)
	{
		this->type = to_copy.type;
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}