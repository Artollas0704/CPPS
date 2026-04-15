/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:41:42 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "Default";
	this->ad = 20;
	this->energy_pts = 50;
	this->hit_pts = 100;
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->ad = 20;
	this->energy_pts = 50;
	this->hit_pts = 100;
	std::cout << "ScavTrap name parameterized constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& to_copy)
{
	ClapTrap::operator=(to_copy);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	if (this->energy_pts == 0 || this->hit_pts == 0)
		return;
	this->energy_pts--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " 
		<< this->ad << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now guarding the gate." << std::endl;
}