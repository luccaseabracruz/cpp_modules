/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDog.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:59:55 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 12:46:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <new>
#include "Dog.hpp"
#include "tests.hpp"

static int	checkType(const Dog& dog)
{
	if (dog.getType() != "Dog")
		return (-1);
	return (0);
}

static int	testConstruction()
{
	printSection("Test Construction");
	Dog	dog;
	if (checkType(dog) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Dog	dog;
	Dog	copy(dog);
	if (&dog == &copy || checkType(dog) != 0 || checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Dog	dog;
	Dog	copy;
	Dog	*result = &(copy = dog);
	if (result != &copy || checkType(copy) != 0)
		return (-1);
	Dog	*self = &copy;
	copy = *self;
	if (checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testMakeSound()
{
	printSection("Test Make Sound");
	Animal	*animal = NULL;
	try
	{
		animal = new Dog();
		animal->makeSound();
		if (animal->getType() != "Dog")
		{
			delete animal;
			return (-1);
		}
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	delete animal;
	return (0);
}

int	testDog()
{
	printHeader("Test Dog");
	if (
		testConstruction() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testMakeSound() != 0
	)
	{
		return (-1);
	}
	return (0);
}
