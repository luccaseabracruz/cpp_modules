/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:57:23 by lucca             #+#    #+#             */
/*   Updated: 2026/09/23 12:33:33 by lseabra-         ###   ########.fr       */
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

int	test(int (*f)(void), const std::string& title)
{
	if (f() != 0)
	{
		std::cout << title << ": >>> STATUS: FAIL\n";
		return (-1);
	}
	std::cout << title << ": >>> STATUS: SUCCESS\n";
	return (0);
}

int	main(void)
{
	int	status = 0;

	if (test(testAnimal, "Test Animal") != 0)
		status = 1;
	if (test(testDog, "Test Dog") != 0)
		status = 1;
	if (test(testCat, "Test Cat") != 0)
		status = 1;
	if (test(testWrongAnimal, "Test WrongAnimal") != 0)
		status = 1;
	return (status);
}
