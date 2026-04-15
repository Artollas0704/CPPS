/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:36:52 by aralves-          #+#    #+#             */
/*   Updated: 2025/11/19 15:40:46 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
class Contact 
{
private:
	std::string fName;
	std::string lName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	
public:
	Contact();
	~Contact();
	
	void set_fName(std::string fname);
	void set_lName(std::string lname);
	void set_Nickname(std::string nickname);
	void set_phoneNumber(std::string phoneNumber);
	void set_darkestSecret(std::string darkestSecret);

	std::string get_firstName() const;
	std::string get_lastName() const;
	std::string get_Nickname() const;
	std::string get_phoneNumber() const;
	std::string get_darkestSecret() const;

	void displayContact() const;
	bool isEmpty() const;
};

#endif