/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:36:37 by aralves-          #+#    #+#             */
/*   Updated: 2026/02/17 17:53:19 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
private:
	Contact	contacts[8];
	int		index;
	int		nContacts;
	std::string formatField(std::string field) const;
	void	displayContacts(int	index);
	
public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContacts();
};

#endif