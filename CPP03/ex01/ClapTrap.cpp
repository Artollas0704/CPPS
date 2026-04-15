/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:36 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:37:27 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
	this->name = "Default";
	this->ad = 0;
	this->energy_pts = 10;
	this->hit_pts = 10;
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
{
	this->name = name;
	this->ad = 0;
	this->energy_pts = 10;
	this->hit_pts = 10;
	std::cout << "ClapTrap name parameterized constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy)
{
	this->name = to_copy.name;
	this->ad = to_copy.ad;
	this->energy_pts = to_copy.energy_pts;
	this->hit_pts = to_copy.hit_pts;
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& to_copy)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		this->name = to_copy.name;
		this->ad = to_copy.ad;
		this->energy_pts = to_copy.energy_pts;
		this->hit_pts = to_copy.hit_pts;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (this->energy_pts == 0 || this->hit_pts == 0)
		return;
	this->energy_pts--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " 
		<< this->ad << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_pts == 0 || this->hit_pts == 0)
		return;
	this->hit_pts += amount;
	this->energy_pts--;
	std::cout << "Claptrap " << this->name << " repairs itself for " << amount << " hp, it now has " 
		<<  this->hit_pts << " HP" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_pts == 0)
		return;
	if (amount >= this->hit_pts)
		this->hit_pts = 0;
	else
		this->hit_pts -= amount;
		
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage, it now has " 
		<< this->hit_pts << " HP"	<< std::endl;
	if (this->hit_pts == 0)
		std::cout << "ClapTrap " << this->name << " has died." << std::endl;
}