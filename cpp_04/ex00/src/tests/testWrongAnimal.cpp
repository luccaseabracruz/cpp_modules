/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testWrongAnimal.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:09:45 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 12:35:37 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "tests.hpp"

static int	checkType(const WrongAnimal& animal)
{
	if (animal.getType() != "Wrong Animal")
		return (-1);
	return (0);
}

static int	testConstruction()
{
	printSection("Test Construction");
	WrongAnimal	animal;
	if (checkType(animal) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	WrongAnimal	animal;
	WrongAnimal	copy(animal);
	if (&animal == &copy || checkType(animal) != 0 || checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	WrongAnimal	animal;
	WrongAnimal	copy;
	WrongAnimal	*result = &(copy = animal);
	if (result != &copy || checkType(copy) != 0)
		return (-1);
	WrongAnimal	*self = &copy;
	copy = *self;
	if (checkType(copy) != 0)
		return (-1);
	return (0);
}

static int	testMakeSound()
{
	printSection("Test Make Sound");
	WrongAnimal	animal;
	WrongCat	wrongCat;
	WrongAnimal	*base = &wrongCat;
	animal.makeSound();
	base->makeSound();
	wrongCat.makeSound();
	if (checkType(animal) != 0 || base->getType() != "Wrong Cat")
		return (-1);
	return (0);
}

int	testWrongAnimal()
{
	printHeader("Test WrongAnimal");
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
