/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testRobotomyRequestForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:26:39 by lucca             #+#    #+#             */
/*   Updated: 2026/10/01 15:57:02 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "tests.hpp"

static int	checkAFormAttributes(const RobotomyRequestForm& form)
{
	if (form.getName() != "RobotomyRequestForm"
		|| form.getIsSigned() == true
		|| form.getReqSignGrade() != 72
		|| form.getReqExecGrade() != 45)
	{
		return (-1);
	}
	return (0);
}

static int	testDefaultConstructor()
{
	printHeader("Test Default Constructor", 1);
	RobotomyRequestForm	form;

	if (checkAFormAttributes(form) != 0 || form.getTarget() != "Default")
		return (-1);
	return (0);
}

static int	testConstructor()
{
	printHeader("Test Constructor", 1);
	RobotomyRequestForm	form("target");

	if (checkAFormAttributes(form) != 0 || form.getTarget() != "target")
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printHeader("Test Copy Constructor", 1);
	RobotomyRequestForm	original("Original Target");
	RobotomyRequestForm	copy(original);

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
	RobotomyRequestForm	original("Original");
	RobotomyRequestForm	destination("Destination");

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

static int	testBeSigned()
{
	printHeader("Test ShrubberyCreationForm::beSigned()", 1);
	try
	{
		RobotomyRequestForm	form("target");
		Bureaucrat	highBureaucrat = Bureaucrat("B", 1);
		Bureaucrat	lowBureaucrat = Bureaucrat("B", 150);

		form.beSigned(highBureaucrat);
		try
		{
			form.beSigned(lowBureaucrat);
		}
		catch(RobotomyRequestForm::GradeTooLowException& e)
		{}
		catch(std::exception& e)
		{
			std::cout << "Unexpected Error: bad sign: " << e.what() << '\n';
			return (-1);
		}
		return (0);
	}
	catch(std::exception& e)
	{
		std::cout << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
}

static int	testExecution()
{
	printHeader("Test Form Execution", 1);
	RobotomyRequestForm	form("amazonia");
	Bureaucrat				president("President", 1);
	Bureaucrat				assistent("Assistent", 140);

	president.executeForm(form);

	president.signForm(form);
	assistent.executeForm(form);

	president.executeForm(form);
	return (0);
}

static int	testSignForm()
{
	printHeader("Test Bureaucrat::signForm()", 1);
	Bureaucrat	highB("High Bureaucrat", 1);
	Bureaucrat	lowB("Low Bureaucrat", 150);
	RobotomyRequestForm		form("target");

	lowB.signForm(form);
	if (form.getIsSigned())
		return (-1);
	highB.signForm(form);
	if (form.getIsSigned() != true)
		return (-1);
	return (0);
}

int	testRobotomyRequestForm()
{
	printHeader("Test RobotomyRequestForm", 0);
	if (testDefaultConstructor() != 0
		|| testConstructor() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testBeSigned() != 0
		|| testExecution() != 0
		|| testSignForm() != 0)
	{
		std::cout << "STATUS: Failed\n";
		return (-1);
	}
	return (0);
}
