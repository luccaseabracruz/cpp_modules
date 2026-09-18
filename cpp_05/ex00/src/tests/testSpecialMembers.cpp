/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testSpecialMembers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 10:43:44 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 12:31:49 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "tests.hpp"
#include <iostream>

static int	testDefaultContructor()
{
	int	status = 0;

	try
	{
		Bureaucrat b = Bureaucrat();
		std::cout << "name: " << b.getName() << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		status = -1;
	}
	return (status);
}

static int	testContructor()
{
	int	status = 0;
	std::string name = "Test";
	const int	grade = 42;

	try
	{
		Bureaucrat b = Bureaucrat(name, grade);
		if (name != b.getName() || grade != b.getGrade())
			status = -1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		status = -1;
	}
	return (status);
}

static int	testCopyContructor()
{
	int	status = 0;
	std::string name = "Test";
	const int	grade = 42;

	try
	{
		Bureaucrat a = Bureaucrat(name, grade);
		Bureaucrat b(a);
		if (a.getName() != b.getName() || a.getGrade() != b.getGrade())
			status = -1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		status = -1;
	}
	return (status);
}

static int	testAssignmentOperator()
{
	int	status = 0;
	std::string aName = "A";
	std::string bName = "B";
	const int	aGrade = 42;
	const int	bGrade = 10;

	try
	{
		Bureaucrat a = Bureaucrat(aName, aGrade);
		Bureaucrat b = Bureaucrat(bName, bGrade);
		b = a;
		if ((aName != bName && a.getName() == b.getName()) || a.getGrade() != b.getGrade())
			status = -1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		status = -1;
	}
	return (status);
}

int	testSpecialMembers()
{
	int	status = 0;
	int	testCount;
	std::string	titles[] = {
		"Test Default Constructor",
		"Test Constructor",
		"Test Copy Constructor",
		"Test Assignment Operator"
	};
	int (*testFunctions[])() = {
		testDefaultContructor,
		testContructor,
		testCopyContructor,
		testAssignmentOperator
	};

	testCount = sizeof(testFunctions) / sizeof(testFunctions[0]);
	for (int i = 0; i < testCount; ++i)
	{
		if (test(titles[i], testFunctions[i], 1) != 0)
			status = -1;
	}
	return (status);
}
