/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:38 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:53:16 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap clap("ClapBot");
	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << std::endl << "=== Testing ScavTrap ===" << std::endl;
	ScavTrap scav("ScavBot");
	scav.attack("Enemy");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();
	
	std::cout << std::endl << "=== Testing FragTrap ===" << std::endl;
	FragTrap frag("FragBot");
	frag.attack("Enemy");
	frag.takeDamage(15);
	frag.beRepaired(10);
	frag.highFivesGuys();
	
	return (0);
}