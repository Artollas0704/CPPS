/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:53:38 by aralves-          #+#    #+#             */
/*   Updated: 2026/04/16 18:47:07 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) 
{
	const Animal* animals[10];
	
	for (int i = 0; i < 5; i++)
	{
		animals[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 5; i < 10; i++)
	{
		animals[i] = new Cat();
		std::cout << std::endl;
	}
	
	std::cout << "===== TESTING SOUNDS =====" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	
	std::cout << std::endl << "===== DELETING ALL ANIMALS =====" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	Dog originalDog;
	
	Dog copyDog = originalDog;

	Dog anotherCopy;
	anotherCopy = originalDog; 
	
	return (0);
}