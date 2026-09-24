/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:57:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/24 15:01:49 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "tests.hpp"

int	main(int argc, char *argv[])
{
	int	status = 0;

	if (argc > 1 && std::string(argv[1]) == "-a")
	{
		if (test(testAnimal, "Test Animal") != 0)
			status = 1;
		if (test(testDog, "Test Dog") != 0)
			status = 1;
		if (test(testCat, "Test Cat") != 0)
			status = 1;
		if (test(testWrongAnimal, "Test WrongAnimal") != 0)
			status = 1;
	}
	if (test(subjectTests, "Subject Tests") != 0)
		status = 1;
	return (status);
}
