/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:57:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/07 15:08:26 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	testBrainShallowCopy(Animal	*animal)
{
	Dog	*original;
	Dog	*copy;
	std::string	ogIdea;
	std::string	cpIdea;

	original = static_cast<Dog *>(animal);
	original->getBrainPtr()->setIdea(0, "bones");
	copy = new Dog(*original);
	if (original->getBrainPtr() == copy->getBrainPtr())
	{
		delete copy;
		return (-1);
	}
	copy->getBrainPtr()->setIdea(0, "play");
	ogIdea = original->getBrainPtr()->getIdea(0);
	cpIdea = copy->getBrainPtr()->getIdea(0);
	if (ogIdea == cpIdea)
	{
		delete copy;
		return (-1);
	}
	delete copy;
	return (0);
}

int main()
{
	size_t	len = 10;
	Animal*	array[10];

	for (size_t i = 0; i < len; i++)
	{
		if (i < (len / 2))
		{
			array[i] = new Dog();
			Dog *d = static_cast<Dog*>(array[i]);
			d->getBrainPtr()->setIdea(i, "Bones");
		}
		else
			array[i] = new Cat();
		if (array[i] == NULL)
		{
			std::cerr << "Error: allocation failed.\n";
			while ( --i <= 0)
				delete (array[i]);
			return (1);
		}
	}
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "type: " << array[i]->getType() << '\n';
		std::cout << "sound: ";
		array[i]->makeSound();
		std::cout << '\n';
	}
	
	if (testBrainShallowCopy(array[0]) != 0)
	{
		std::cout << "Test Brain Shallow Copy: FAILED\n";
		for (size_t i = 0; i < len; i++)
			delete (array[i]);
		return (1);
	}
	else
		std::cout << "Test Brain Shallow Copy: SUCCESS\n";
	for (size_t i = 0; i < len; i++)
		delete (array[i]);
	return (0);
}
