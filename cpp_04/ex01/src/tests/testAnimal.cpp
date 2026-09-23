/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAnimal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:47:36 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 13:47:37 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <new>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "tests.hpp"

static int	checkType(const Animal& animal, const std::string& type)
{
	if (animal.getType() != type)
		return (-1);
	return (0);
}

static void	deleteArray(Animal **array, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		delete array[i];
		array[i] = NULL;
	}
}

static int	testConstruction()
{
	printSection("Test Construction");
	Animal	animal;
	if (checkType(animal, "Animal") != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Animal	animal;
	Animal	copy(animal);
	if (&animal == &copy || checkType(copy, "Animal") != 0)
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Animal	animal;
	Animal	copy;
	Animal	*result = &(copy = animal);
	if (result != &copy || checkType(copy, "Animal") != 0)
		return (-1);
	return (0);
}

static int	testPolymorphicArray()
{
	const size_t	len = 10;
	Animal			*array[len];
	printSection("Test Polymorphic Array");
	for (size_t i = 0; i < len; i++)
		array[i] = NULL;
	try
	{
		for (size_t i = 0; i < len; i++)
		{
			if (i < len / 2)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		deleteArray(array, len);
		return (-1);
	}
	for (size_t i = 0; i < len; i++)
	{
		if (checkType(*array[i], i < len / 2 ? "Dog" : "Cat") != 0)
		{
			deleteArray(array, len);
			return (-1);
		}
		array[i]->makeSound();
	}
	deleteArray(array, len);
	return (0);
}

int	testAnimal()
{
	printHeader("Test Animal");
	if (
		testConstruction() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testPolymorphicArray() != 0
	)
		return (-1);
	return (0);
}