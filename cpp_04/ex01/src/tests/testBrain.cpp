/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBrain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:47:40 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/23 13:47:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Brain.hpp"
#include "tests.hpp"

static int	testConstruction()
{
	printSection("Test Construction");
	Brain	brain;
	brain.setIdea(0, "bones");
	if (brain.getIdea(0) != "bones")
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printSection("Test Copy Constructor");
	Brain	brain;
	brain.setIdea(0, "bones");
	Brain	copy(brain);
	if (copy.getIdea(0) != "bones")
		return (-1);
	copy.setIdea(0, "play");
	if (brain.getIdea(0) == copy.getIdea(0))
		return (-1);
	return (0);
}

static int	testAssignmentOperator()
{
	printSection("Test Assignment Operator");
	Brain	brain;
	Brain	copy;
	Brain	*result;
	brain.setIdea(0, "bones");
	result = &(copy = brain);
	if (result != &copy || copy.getIdea(0) != "bones")
		return (-1);
	Brain	*self = &copy;
	copy = *self;
	if (copy.getIdea(0) != "bones")
		return (-1);
	return (0);
}

static int	testBounds()
{
	printSection("Test Bounds");
	Brain	brain;
	try
	{
		brain.getIdea(-1);
		return (-1);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		brain.setIdea(MAX_IDEAS, "invalid");
		return (-1);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

int	testBrain()
{
	printHeader("Test Brain");
	if (
		testConstruction() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testBounds() != 0
	)
		return (-1);
	return (0);
}