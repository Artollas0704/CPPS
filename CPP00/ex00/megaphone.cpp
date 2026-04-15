/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:30:51 by aralves-          #+#    #+#             */
/*   Updated: 2026/02/17 17:43:47 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **argv)
{
	(void)argv;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int str = 0; argv[i][str]; str++)
			{
				if (std::isalpha(argv[i][str]))
					std::cout << (char)std::toupper(argv[i][str]);
				else
					std::cout << argv[i][str];
			}
		}
		std::cout << std::endl;
	}
}