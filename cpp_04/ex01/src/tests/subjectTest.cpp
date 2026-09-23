/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subjectTest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:53:01 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 15:27:29 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "tests.hpp"

static void	deleteArray(Animal **array, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		delete array[i];
		array[i] = NULL;
	}
}

int	subjectTest()
{
	const size_t	len = 10;
	Animal			*array[len];

	printHeader("Subject Test");
	for (size_t i = 0; i < len; i++)
		array[i] = NULL;
	try
	{
		for (size_t i = 0; i < len; i++)
		{
			if (i < (len / 2))
			{
				array[i] = new Dog();
				Dog	*d = static_cast<Dog*>(array[i]);
				d->getBrainPtr()->setIdea(i, "Bones");
			}
			else
				array[i] = new Cat();
		}
		for (size_t i = 0; i < len; i++)
		{
			std::cout << "type: " << array[i]->getType() << '\n';
			std::cout << "sound: ";
			array[i]->makeSound();
			std::cout << '\n';
		}
		deleteArray(array, len);
		return (0);
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		deleteArray(array, len);
		return (-1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		deleteArray(array, len);
		return (-1);
	}
}
