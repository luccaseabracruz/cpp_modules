/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:57:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/23 15:24:01 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "tests.hpp"

int	main(int argc, char* argv[])
{
	// Animal a; // uncomment to prove it won't compile: error, Animal is abstract
	int	status = 0;

	if (argc > 1 && std::string(argv[1]) == "-a")
	{
		if (test(testBrain, "Test Brain") != 0)
			status = 1;
		if (test(testDog, "Test Dog") != 0)
			status = 1;
		if (test(testCat, "Test Cat") != 0)
			status = 1;
	}
	if (test(subjectTest, "Subject Test") != 0)
		status = 1;
	return (status);
}
