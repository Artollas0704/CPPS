/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:50:40 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/12 18:22:02 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Enter 4 arguments" << std::endl;
		return (0);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cout << "Argument 3 is empty." << std::endl;
		return (0);
	}
	else if (s2.empty())
	{
		std::cout << "Argument 4 is empty, nothing to replace" << std::endl;
		return (0);
	}
	else if (s1 == s2)
	{
		std::cout << "Argument 3 and 4 are the same, nothing to replace." << std::endl;
		return (0);
	}
	std::ifstream infile;
	
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Error, could not open file." << std::endl;
		return (1);
	}
	else
	{
		std::string line;
		std::string filename = argv[1];
		filename += ".replace";
		std::ofstream outputfile(filename.c_str());
		if (!outputfile.is_open())
		{
			std::cout << "Error, could not open file." << std::endl;
			return (1);
		}
		size_t pos;
		while (std::getline(infile, line))
		{
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos) 
			{
				line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
				pos += s2.length();
			}
			outputfile << line << std::endl;
		}
		infile.close();
		outputfile.close();
	}
	return (0);
}