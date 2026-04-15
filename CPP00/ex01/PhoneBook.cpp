/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:36:44 by aralves-          #+#    #+#             */
/*   Updated: 2026/02/17 18:01:01 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	nContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::formatField(std::string field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

static std::string getInput(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return ("");
		if (!input.empty())
			return (input);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

void PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	input = getInput("First Name: ");
	if (input.empty())
		return ;
	newContact.set_fName(input);

	input = getInput("Last Name: ");
	if (input.empty())
		return ;
	newContact.set_lName(input);

	input = getInput("Nickname: ");
	if (input.empty())
		return ;
	newContact.set_Nickname(input);

	input = getInput("Phone Number: ");
	if (input.empty())
		return ;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Phone number must contain only digits." << std::endl;
			return ;
		}
	}
	newContact.set_phoneNumber(input);

	input = getInput("Darkest Secret: ");
	if (input.empty())
		return ;
	newContact.set_darkestSecret(input);

	contacts[index % 8] = newContact;
	index++;
	if (nContacts < 8)
		nContacts++;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContacts(int idx)
{
	if (idx < 0 || idx >= nContacts)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	contacts[idx].displayContact();
}

void PhoneBook::searchContacts()
{
	if (nContacts == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i < nContacts; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatField(contacts[i].get_firstName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].get_lastName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].get_Nickname()) << std::endl;
	}
	std::cout << "Enter index to display: ";
	std::string input;
	if (!std::getline(std::cin, input) || input.empty())
		return ;
	int idx = std::atoi(input.c_str());
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	displayContacts(idx);
}
