/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 11:56:30 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "tests.hpp"

// int	testGetters()
// {
	// const std::string	testTitles[] = {
		// "Test name getter",
		// "Test grade getter"
	// };
	// int (*testFunctions[])() = {
		// testGetName,
		// testGetGrade
	// };
	// const int	testCount = sizeof(testFunctions) / sizeof(testFunctions[0]);
	// int			failed = 0;
// 
	// printHeader("Test Grade", 0);
	// for (int i = 0; i < testCount; i++)
	// {
		// if (test(testTitles[i], testFunctions[i]) != 0)
			// failed = -1;
	// }
	// return (failed);
// }

int	main()
{
	const std::string	testTitles[] = {
		"Test Grade",
		"Test Getters",
		"Test Special Members"
	};
	int (*testFunctions[])() = {
		testGrade,
		testGetters,
		testSpecialMembers
	};
	
	const int	testCount = sizeof(testFunctions) / sizeof(testFunctions[0]);
	int			failed = 0;

	for (int i = 0; i < testCount; ++i)
	{
		if (test(testTitles[i], testFunctions[i], 0) != 0)
			failed = 1;
	}
	return (failed);
}
