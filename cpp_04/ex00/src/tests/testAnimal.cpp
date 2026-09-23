/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAnimal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:09:45 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 11:53:04 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "tests.hpp"

static int	checkType(const Animal& animal)
{
	if (animal.getType() != "Animal")
		return (-1);
	return (0);
}

static int	testConstruction()
{
	printSection("Test Construction");
	Animal	animal;
	if (checkType(animal) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Animal	animal;
	Animal	copy(animal);
	if (&animal == &copy || checkType(animal) != 0 || checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Animal	animal;
	Animal	copy;
	Animal	*result = &(copy = animal);
	if (result != &copy || checkType(copy) != 0)
		return (-1);
	Animal	*self = &copy;
	copy = *self;
	if (checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testMakeSound()
{
	printSection("Test Make Sound");
	Animal	animal;
	animal.makeSound();
	return (0);
}

int	testAnimal()
{
	printHeader("Test Animal");
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
