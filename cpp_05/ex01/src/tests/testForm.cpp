/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:29:03 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 13:24:48 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "tests.hpp"
#include <iostream>
#include <sstream>

static int	testDefaultConstructor()
{
	printHeader("Test Default Constructor", 1);
	Form	form;

	if (form.getIsSigned() != false
		|| form.getReqSignGrade() != 150
		|| form.getReqExecGrade() != 150)
	{
		return (-1);
	}
	return (0);
}

static int	testConstructor()
{
	printHeader("Test Construction", 1);
	const std::string	name = "B";
	const int			reqSignGrade = 100;
	const int			reqExecGrade = 42;
	Form				form = Form(name, reqSignGrade, reqExecGrade);

	if (form.getIsSigned() != false
		|| form.getName() != name
		|| form.getReqSignGrade() != reqSignGrade
		|| form.getReqExecGrade() != reqExecGrade)
	{
		return (-1);
	}
	return (0);
}

static int	testInvalidGrade(int signGrade, int execGrade, bool tooHigh)
{
	try
	{
		Form	form("B", signGrade, execGrade);
		(void)form;
		return (-1);
	}
	catch (const Form::GradeTooHighException&)
	{
		return (tooHigh ? 0 : -1);
	}
	catch (const Form::GradeTooLowException&)
	{
		return (tooHigh ? -1 : 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
	return (-1);
}

static int	testBadConstructor()
{
	printHeader("Test Invalid Constructor Grades", 1);
	if (testInvalidGrade(0, 100, true) != 0
		|| testInvalidGrade(100, 0, true) != 0
		|| testInvalidGrade(151, 150, false) != 0
		|| testInvalidGrade(150, 151, false) != 0)
		return (-1);
	return (0);
}

static int	testCopyConstructor()
{
	printHeader("Test Copy Constructor", 1);
	Form				form = Form("B", 100, 42);
	Form				copy(form);
	if (form.getIsSigned() != false
		|| form.getName() != copy.getName()
		|| form.getReqSignGrade() != copy.getReqSignGrade()
		|| form.getReqExecGrade() != copy.getReqExecGrade())
	{
		return (-1);
	}
	return (0);
}

static int	testAssignmentOperator()
{
	printHeader("Test Assignment Operator", 1);
	Form				form("B", 100, 42);
	Form				copy;
	Bureaucrat		bureaucrat("Signer", 1);

	form.beSigned(bureaucrat);
	copy = form;
	if (!copy.getIsSigned()
		|| copy.getName() != "Default"
		|| copy.getReqSignGrade() != 150
		|| copy.getReqExecGrade() != 150)
	{
		return (-1);
	}
	return (0);
}

static int	testBeSigned()
{
	try
	{
		Form	form = Form("B", 100, 42);
		Bureaucrat	bureaucrat = Bureaucrat("B", 100);
		Bureaucrat	badBureaucrat = Bureaucrat("B", 150);

		form.beSigned(bureaucrat);
		try
		{
			form.beSigned(badBureaucrat);
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cout << "Expected Error: bad sign: " << e.what() << '\n';
			return (0);
		}
		catch(std::exception& e)
		{
			std::cout << "Unexpected Error: bad sign: " << e.what() << '\n';
			return (-1);
		}
		return (-1);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
	catch(std::exception& e)
	{
		std::cout << "Unexpected Error: " << e.what() << '\n';
		return (-1);
	}
}

static int	testStreamOperator()
{
	printHeader("Test Stream Operator", 1);
	Form				form("Test", 5, 42);
	std::ostringstream	out;
	const std::string	expected = "Name: Test; Is Signed: False; Required Grade to Sign: 5; Required Grade to Exec: 42\n";

	out << form;
	std::cout << form;
	if (out.str() != expected)
		return (-1);
	return (0);
}

int	testForm()
{
	printHeader("Test Form", 0);
	if (testDefaultConstructor() != 0
		|| testConstructor() != 0
		|| testBadConstructor() != 0
		|| testCopyConstructor() != 0
		|| testAssignmentOperator() != 0
		|| testBeSigned() != 0
		|| testStreamOperator() != 0)
	{
		return (-1);
	}
	return (0);
}

