/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testShrubberyCreationForm.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:26:39 by lucca             #+#    #+#             */
/*   Updated: 2026/09/30 17:03:24 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "tests.hpp"

static int	checkAFormAttributes(const ShrubberyCreationForm& form)
{
	if (form.getName() != "ShrubberyCreationForm"
		|| form.getIsSigned() == true
		|| form.getReqSignGrade() != 147
		|| form.getReqExecGrade() != 137)
	{
		return (-1);
	}
	return (0);
}

static int	testDefaultConstructor()
{
	printHeader("Test Default Constructor", 1);
	ShrubberyCreationForm	form;

	if (checkAFormAttributes(form) != 0 || form.getTarget() != "Default")
		return (-1);
	return (0);
}

static int	testConstructor()
{
	printHeader("Test Constructor", 1);
	ShrubberyCreationForm	form("target");

	if (checkAFormAttributes(form) != 0 || form.getTarget() != "target")
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printHeader("Test Copy Constructor", 1);
	ShrubberyCreationForm	original("Original Target");
	ShrubberyCreationForm	copy(original);

	if (copy.getName() != original.getName()
		|| copy.getIsSigned() != original.getIsSigned()
		|| copy.getReqSignGrade() != original.getReqSignGrade()
		|| copy.getReqExecGrade() != original.getReqExecGrade()
		|| copy.getTarget() != original.getTarget())
	{
		return (-1);
	}
	return (0);
}

static int	testAssignmentOperator()
{
	printHeader("Test Assignment Operator", 1);
	ShrubberyCreationForm	original("Original");
	ShrubberyCreationForm	destination("Destination");

	destination = original;
	destination = destination;
	if (destination.getName() != original.getName()
		|| destination.getIsSigned() != original.getIsSigned()
		|| destination.getReqSignGrade() != original.getReqSignGrade()
		|| destination.getReqExecGrade() != original.getReqExecGrade()
		|| destination.getTarget() != original.getTarget())
		return (-1);
	return (0);
}

static int	testExecution()
{
	printHeader("Test Form Execution", 1);
	ShrubberyCreationForm	form("amazonia");
	Bureaucrat				high("President", 1);
	Bureaucrat				assistent("Assistent", 140);

	try
	{
		form.execute(high);
	}
	catch (AForm::FormNotSignedException& e)
	{}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	try
	{
		form.beSigned(high);
		form.execute(assistent);
	}
	catch (AForm::GradeTooLowException& e)
	{}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	try
	{
		form.execute(high);
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

int	testShrubberyCreationForm()
{
	printHeader("Test ShrubberyCreationForm", 0);
	if (testDefaultConstructor() != 0
		|| testConstructor() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testExecution() != 0)
	{
		std::cout << "STATUS: Failed\n";
		return (-1);
	}
	return (0);
}
