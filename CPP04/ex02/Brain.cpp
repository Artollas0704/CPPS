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
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& to_copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = to_copy.ideas[i];
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& to_copy)
{
	if (this != &to_copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = to_copy.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return ("");
}