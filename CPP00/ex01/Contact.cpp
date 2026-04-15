/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:36:55 by aralves-          #+#    #+#             */
/*   Updated: 2025/11/19 15:40:37 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() 
{
	fName = "";
	lName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::~Contact()
{	
}

void	Contact::set_fName(std::string str)
{
	fName = str;
}

void	Contact::set_lName(std::string str)
{
	lName = str;
}

void	Contact::set_Nickname(std::string str)
{
	nickname = str;
}

void	Contact::set_phoneNumber(std::string str)
{
	phoneNumber = str;
}

void	Contact::set_darkestSecret(std::string str)
{
	darkestSecret = str;
}

std::string Contact::get_firstName() const 
{
	return fName;
}

std::string Contact::get_lastName() const 
{
	return lName;
}

std::string Contact::get_Nickname() const 
{
	return nickname;
}

std::string Contact::get_phoneNumber() const 
{
	return phoneNumber;
}

std::string Contact::get_darkestSecret() const 
{
	return darkestSecret;
}

void	Contact::displayContact() const
{
	std::cout << "First Name: " << fName << std::endl;
	std::cout << "Last Name: " << lName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Secret: " << darkestSecret << std::endl;
}

bool	Contact::isEmpty() const
{
	if (fName.empty() || lName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
		return (1);
	return (0);
}