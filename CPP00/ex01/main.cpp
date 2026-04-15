/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:36:47 by aralves-          #+#    #+#             */
/*   Updated: 2026/02/17 17:56:31 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << std::endl << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Unknown command. Use ADD, SEARCH or EXIT." << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return (0);
}

