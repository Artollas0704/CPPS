/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:06:34 by aralves-          #+#    #+#             */
/*   Updated: 2026/02/17 22:16:11 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main()
{
    Zombie *horde = zombieHorde(5, "Horde");
    for (int i = 0; i < 5; i++)
    {
        horde[i].announce();
    }
   delete[]horde;
}