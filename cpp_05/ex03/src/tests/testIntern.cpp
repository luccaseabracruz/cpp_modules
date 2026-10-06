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
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "tests.hpp"

static int	testDefaultConstructor()
{
	printHeader("Test Default Constructor", 1);

	try
	{
		Intern	intern;
	}
	catch (std::exception& e)
	{
		std::cerr << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testCopyConstructor()
{
	printHeader("Test Copy Constructor", 1);
	try
	{
		Intern	original;
		Intern	copy(original);
	}
	catch (std::exception& e)
	{
		std::cerr << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testAssignmentOperator()
{
	printHeader("Test Assignment Operator", 1);
	
	try
	{
		Intern	original;
		Intern	copy;

		copy = original;
	}
	catch (std::exception& e)
	{
		std::cerr << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int	testMakeForm()
{
	Intern		intern;
	AForm		*form;
	Bureaucrat	president("President", 1);
	std::string	validNames[3] = {
		"presidential pardon",
		"shrubbery creation",
		"robotomy request"
	};

	try
	{
		intern.makeForm("Unkown", "target?");
	}
	catch(Intern::UnkownFormException&)
	{}
	catch(std::exception& e)
	{
		std::cerr << "Unkknown Exeption: " << e.what() << '\n';
		return (-1);
	}
	try
	{
		for (int i = 0; i < 3; i++)
		{
			std:: cout << "> testing makeForm(\"" << validNames[i] << "\")\n";
			form = intern.makeForm(validNames[i], "friend");
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Unkknown Exeption: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

int	testIntern()
{
	printHeader("Test Intern", 0);
	if (testDefaultConstructor() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testMakeForm() != 0)
	{
		std::cout << "STATUS: Failed\n";
		return (-1);
	}
	return (0);
}
