/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/08/27 14:21:24 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include "ClapTrap.hpp"

//============================================================================//
//                                  DEBUG                                     //
//============================================================================//
static void	displayInfo(const ClapTrap& c)
{
	std::cout 	<< CT_PREFIX << "INFO\n"
				<< "Name: " << c.getName() << '\n'
				<< "Hit Points: " << c.getHitPoints() << '\n'
				<< "Energy Points: " << c.getEnergyPoints() << '\n'
				<< "Attack Damage: " << c.getAttackDamage() << '\n';
}

//============================================================================//
//                                  TEST                                      //
//============================================================================//
static bool	testDefaultConstructor(void)
{
	bool	status = 1;
	std::cout	<< "===================================================================\n"
				<< "=                     Test Default Constructor                     \n"
				<< "===================================================================\n";
	ClapTrap trap1("Trap");
	ClapTrap trap2(trap1);

	displayInfo(trap1);
	displayInfo(trap2);
	return (status);
}

static bool	testCopyConstructor(void)
{
	bool	status = 1;
	std::cout	<< "===================================================================\n"
				<< "=                      Test Copy Constructor                      =\n"
				<< "===================================================================\n";
	ClapTrap trap1("Trap");
	ClapTrap trap2(trap1);

	displayInfo(trap1);
	displayInfo(trap2);
	return (status);
}

static bool	testCopyAsignment(void)
{
	std::cout	<< "===================================================================\n"
				<< "=                      Test Copy Assingment                       =\n"
				<< "===================================================================\n";
	bool	status = 1;
	ClapTrap trap1("Trap");
	ClapTrap trap2;

	trap2 = trap1;
	displayInfo(trap1);
	displayInfo(trap2);
	return (status);
}

static bool	testActions(void)
{
	std::cout	<< "===================================================================\n"
				<< "=                          Test Actions                           =\n"
				<< "===================================================================\n";
	bool	status = 1;
	ClapTrap trap1("Trap 1");
	ClapTrap trap2("Trap 2");

	for(int i = 0; i < 11; i++)
	{
		trap1.attack(trap2.getName());
		trap2.takeDamage(1);
	}
	std::cout << "Out of the for loop\n";
	displayInfo(trap1);
	displayInfo(trap2);
	trap2.attack(trap1.getName());
	trap1.takeDamage(UINT_MAX);
	trap2.beRepaired(1);
	trap2.beRepaired(UINT_MAX);
	displayInfo(trap1);
	displayInfo(trap2);
	return (status);
}

int	main(void)
{
	if (!testDefaultConstructor()
		|| !testCopyConstructor()
		|| !testCopyAsignment()
		|| !testActions())
	{
		std::cout << "!!!!!!!!!!!!!!!!!!!!!!!FAILURE!!!!!!!!!!!!!!!!!!!!!!!!\n";
		return (1);
	}
	else
		std::cout << "SUCCESS :)\n";	
}
