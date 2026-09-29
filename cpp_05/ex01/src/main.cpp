/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/29 16:28:34 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"

int	main(int argc, char *argv[])
{
	int	status = 0;

	if (argc > 1 && std::string(argv[1]) == "-a")
	{
		if (runTest(testBureaucrat, "Test Bureaucrat") != 0)
			status = 1;
	}
	if (runTest(testForm, "Test Form") != 0
		|| runTest(testSigning, "Test Signing") != 0)
	{
		status = 1;
	}
	return (status);
}
