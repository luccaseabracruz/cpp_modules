/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBureaucrat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29                             #+#    #+#             */
/*   Updated: 2026/09/29                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "tests.hpp"

static int	testDefaultConstructor()
{
	printHeader("Test Default Constructor", 1);
	Bureaucrat	bureaucrat;

	if (bureaucrat.getName() != "NoName" || bureaucrat.getGrade() != 150)
		return (-1);
	return (0);
}

static int	testConstructor()
{
	printHeader("Test Constructor", 1);
	Bureaucrat	bureaucrat("Test", 42);

	if (bureaucrat.getName() != "Test" || bureaucrat.getGrade() != 42)
		return (-1);
	return (0);
}

static int	testInvalidGrades()
{
	printHeader("Test Invalid Constructor Grades", 1);
	try
	{
		Bureaucrat("TooHigh", 0);
		return (-1);
	}
	catch (const Bureaucrat::GradeTooHighException&)
	{}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	try
	{
		Bureaucrat("TooLow", 151);
		return (-1);
	}
	catch (const Bureaucrat::GradeTooLowException&)
	{}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testCopyConstructor()
{
	printHeader("Test Copy Constructor", 1);
	Bureaucrat	original("Original", 42);
	Bureaucrat	copy(original);

	if (copy.getName() != original.getName()
		|| copy.getGrade() != original.getGrade())
	{
		return (-1);
	}
	return (0);
}

static int	testAssignmentOperator()
{
	printHeader("Test Assignment Operator", 1);
	Bureaucrat	original("Original", 42);
	Bureaucrat	destination("Destination", 10);

	destination = original;
	destination = destination;
	if (destination.getName() != "Destination"
		|| destination.getGrade() != original.getGrade())
		return (-1);
	return (0);
}

static int	testGradeChanges()
{
	printHeader("Test Grade Changes", 1);
	Bureaucrat	bureaucrat("Test", 50);

	bureaucrat.incrementGrade();
	if (bureaucrat.getGrade() != 49)
		return (-1);
	bureaucrat.decrementGrade();
	if (bureaucrat.getGrade() != 50)
		return (-1);
	return (0);
}

static int	testGradeBoundaries()
{
	printHeader("Test Grade Boundaries", 1);
	try
	{
		Bureaucrat highest("Highest", 1);
		highest.incrementGrade();
		return (-1);
	}
	catch (const Bureaucrat::GradeTooHighException&)
	{}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	try
	{
		Bureaucrat lowest("Lowest", 150);
		lowest.decrementGrade();
		return (-1);
	}
	catch (const Bureaucrat::GradeTooLowException&)
	{}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testStreamOperator()
{
	printHeader("Test Stream Operator", 1);
	const std::string	expected = "Test, bureaucrat grade 42.";
	std::ostringstream	output;
	Bureaucrat			bureaucrat("Test", 42);

	output << bureaucrat;
	if (output.str() != expected)
		return (-1);
	return (0);
}

int	testBureaucrat()
{
	printHeader("Test Bureaucrat", 0);
	if (testDefaultConstructor() != 0
		|| testConstructor() != 0
		|| testInvalidGrades() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testGradeChanges() != 0
		|| testGradeBoundaries() != 0
		|| testStreamOperator() != 0)
	{
		std::cout << "STATUS: Failed\n";
		return (-1);
	}
	return (0);
}
