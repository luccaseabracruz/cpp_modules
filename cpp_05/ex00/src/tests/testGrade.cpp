/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testGrade.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:54:32 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 10:49:47 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "tests.hpp"

static int	testTooHighGrade()
{
	try
	{
		Bureaucrat("Bob", -1);
		return (-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
}

static int	testTooLowGrade()
{
	try
	{
		Bureaucrat("Bob", 151);
		return (151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
}

static int	testIncrementGrade()
{
	try
	{
		Bureaucrat	b = Bureaucrat("Lula", 150);
		std::cout << "previous grade: " << b.getGrade() << '\n';
		for (int i = 0; i < 100; i++)
		{
			b.incrementGrade();
		}
		std::cout << "current grade: " << b.getGrade() << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testDecrementGrade()
{
	try
	{
		Bureaucrat	b = Bureaucrat("Lula", 1);
		std::cout << "previous grade: " << b.getGrade() << '\n';
		for (int i = 0; i < 100; i++)
		{
			b.decrementGrade();
		}
		std::cout << "current grade: " << b.getGrade() << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testBadIncrementGrade()
{
	try
	{
		Bureaucrat	b = Bureaucrat("Lula", 150);
		std::cout << "previous grade: " << b.getGrade() << '\n';
		std::cout << "increment: " << 150 << '\n';
		for (int i = 0; i < 150; i++)
		{
			b.incrementGrade();
		}
		std::cout << "current grade: " << b.getGrade() << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	return (-1);
}

static int	testBadDecrementGrade()
{
	try
	{
		Bureaucrat	b = Bureaucrat("Lula", 1);
		std::cout << "previous grade: " << b.getGrade() << '\n';
		std::cout << "decrement: " << 150 << '\n';
		for (int i = 0; i < 150; i++)
		{
			b.decrementGrade();
		}
		std::cout << "current grade: " << b.getGrade() << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	return (-1);
}

int	testGrade()
{
	const std::string	testTitles[] = {
		"Test too high grade",
		"Test too low grade",
		"Test increment grade",
		"Test decrement grade",
		"Test bad increment grade",
		"Test bad decrement grade"
	};
	int (*testFunctions[])() = {
		testTooHighGrade,
		testTooLowGrade,
		testIncrementGrade,
		testDecrementGrade,
		testBadIncrementGrade,
		testBadDecrementGrade
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
