/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/08/27 16:50:24 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include "ClapTrap.hpp"

//============================================================================//
//                                  DEBUG                                     //
//============================================================================//
static void	displayInfo(const ClapTrap& clapTrap)
{
	std::cout	<< CT_PREFIX << "INFO\n"
				<< "Name: " << clapTrap.getName() << '\n'
				<< "Hit Points: " << clapTrap.getHitPoints() << '\n'
				<< "Energy Points: " << clapTrap.getEnergyPoints() << '\n'
				<< "Attack Damage: " << clapTrap.getAttackDamage() << '\n';
}

static void	printSection(const std::string& title)
{
	std::cout	<< "===================================================================\n"
				<< "= " << title << "\n"
				<< "===================================================================\n";
}

//============================================================================//
//                                  TEST                                      //
//============================================================================//
static void	testDefaultConstructor(void)
{
	printSection("Test Default Constructor");
	ClapTrap trap;
	displayInfo(trap);
}

static void	testCopyConstructor(void)
{
	printSection("Test Copy Constructor");
	ClapTrap original("Trap");
	ClapTrap copy(original);

	displayInfo(original);
	displayInfo(copy);
}

static void	testCopyAssignment(void)
{
	printSection("Test Copy Assignment");
	ClapTrap original("Trap");
	ClapTrap copy;

	copy = original;
	displayInfo(original);
	displayInfo(copy);
}

static void	testActions(void)
{
	printSection("Test Actions");
	ClapTrap attacker("Trap 1");
	ClapTrap target("Trap 2");

	for (int i = 0; i < 11; ++i)
	{
		attacker.attack(target.getName());
		target.takeDamage(1);
	}
	displayInfo(attacker);
	displayInfo(target);

	target.attack(attacker.getName());
	attacker.takeDamage(UINT_MAX);
	target.beRepaired(1);
	target.beRepaired(UINT_MAX);
	displayInfo(attacker);
	displayInfo(target);
}

int	main(void)
{
	testDefaultConstructor();
	testCopyConstructor();
	testCopyAssignment();
	testActions();
	std::cout << "SUCCESS :)\n";
	return (0);
}
