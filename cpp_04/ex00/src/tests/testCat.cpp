/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testCat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:00:03 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 12:46:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "tests.hpp"

static int	checkType(const Cat& cat)
{
	if (cat.getType() != "Cat")
		return (-1);
	return (0);
}

static int	testConstruction()
{
	printSection("Test Construction");
	Cat	cat;
	if (checkType(cat) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Cat	cat;
	Cat	copy(cat);
	if (&cat == &copy || checkType(cat) != 0 || checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Cat	cat;
	Cat	copy;
	Cat	*result = &(copy = cat);
	if (result != &copy || checkType(copy) != 0)
		return (-1);
	Cat	*self = &copy;
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
		animal = new Cat();
		animal->makeSound();
		if (animal->getType() != "Cat")
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

int	testCat()
{
	printHeader("Test Cat");
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
