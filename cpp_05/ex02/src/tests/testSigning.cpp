/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testSigning.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:43:39 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 16:37:53 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"

static int	testBeSigned()
{
	printHeader("Test Form::beSigned()", 1);
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

static int	testSignForm()
{
	printHeader("Test Bureaucrat::signForm()", 1);
	Bureaucrat	highB("High Bureaucrat", 1);
	Bureaucrat	lowB("Low Bureaucrat", 150);
	Form		form = Form("Contitution", 5, 50);

	lowB.signForm(form);
	if (form.getIsSigned())
		return (-1);
	highB.signForm(form);
	if (form.getIsSigned() != true)
		return (-1);
	return (0);
}

int	testSigning()
{
	printHeader("Test Signing", 0);
	if (testBeSigned() != 0
		||testSignForm() != 0)
	{
		return (-1);
	}
	return (0);
}
