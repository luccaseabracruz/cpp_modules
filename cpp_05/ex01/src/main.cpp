/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:07 by lucca             #+#    #+#             */
/*   Updated: 2026/09/18 14:02:48 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "tests.hpp"

int	main()
{
	const std::string	testTitles[] = {
		"Test Grade",
		"Test Member Functions",
		"Test Special Members"
	};
	int (*testFunctions[])() = {
		testGrade,
		testMemberFunctions,
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
