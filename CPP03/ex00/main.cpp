/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:38 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/14 21:45:15 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main(void) 
{
	ClapTrap a("Bot 1");
	ClapTrap b("Bot 2");

	for (int i = 0; i <= 12; i++)
	{
		std::cout << "Loop iteration " << i << std::endl;
		a.attack("Enemy");
	}
	b.takeDamage(10);
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(10);
	b.beRepaired(5);
	return (0);
}