/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMemberFunctions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:16:02 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 14:00:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "tests.hpp"
#include <sstream>

static int	testGetName()
{
	try
	{
		std::string name = "Obama";
		Bureaucrat	b(name, 150);
		std::string getterOutput = b.getName();
		if (name != getterOutput)
			return (-1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testGetGrade()
{
	try
	{
		std::string	name = "Obama";
		int			grade = 42;
		Bureaucrat	b(name, grade);
		int getterOutput = b.getGrade();
		if (grade != getterOutput)
			return (-1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testStreamOperator()
{
	const std::string	expectedOutput = "Test, bureaucrat grade 42.";
	std::ostringstream	output;

	try
	{
		Bureaucrat	bureaucrat("Test", 42);
		output << bureaucrat;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	if (output.str() != expectedOutput)
		return (-1);
	return (0);
}

int	testMemberFunctions()
{
	const std::string	testTitles[] = {
		"Test name getter",
		"Test grade getter",
		"Test stream operator"
	};
	int (*testFunctions[])() = {
		testGetName,
		testGetGrade,
		testStreamOperator
	};
	const int	testCount = sizeof(testFunctions) / sizeof(testFunctions[0]);
	int			status = 0;

	for (int i = 0; i < testCount; ++i)
	{
		if (test(testTitles[i], testFunctions[i], 1) != 0)
			status = -1;
	}
	return (status);
}
