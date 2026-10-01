/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:07 by lucca             #+#    #+#             */
/*   Updated: 2026/10/01 15:16:07 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"

int	main(int argc, char *argv[])
{
	int	status = 0;

	if (argc > 1 && std::string(argv[1]) == "-a")
	{
		if (runTest(testBureaucrat, "Test Bureaucrat") != 0)
			status = 1;
	}
	if (runTest(testShrubberyCreationForm, "Test Form") != 0
		|| runTest(testRobotomyRequestForm, "Test Form") != 0
		|| runTest(testPresidentialPardonForm, "Test Form") != 0)
	{
		status = 1;
	}
	return (status);
}
