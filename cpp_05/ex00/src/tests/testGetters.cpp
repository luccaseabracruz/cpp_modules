/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testGetters.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:16:02 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 10:49:58 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "tests.hpp"

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

int	testGetters()
{
	const std::string	testTitles[] = {
		"Test name getter",
		"Test grade getter"
	};
	int (*testFunctions[])() = {
		testGetName,
		testGetGrade
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
