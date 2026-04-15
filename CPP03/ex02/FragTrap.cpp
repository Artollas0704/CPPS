/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:52:25 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "Default";
	this->ad = 30;
	this->energy_pts = 100;
	this->hit_pts = 100;
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->ad = 20;
	this->energy_pts = 50;
	this->hit_pts = 100;
	std::cout << "FragTrap name parameterized constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& to_copy)
{
	ClapTrap::operator=(to_copy);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::attack(const std::string& target)
{
	if (this->energy_pts == 0 || this->hit_pts == 0)
		return;
	this->energy_pts--;
	std::cout << "FragTrap " << this->name << " attacks " << target << " causing " 
		<< this->ad << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " High Fives everyone." << std::endl;
}