/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testClapTrap.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 15:14:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <cassert>
#include "ClapTrap.hpp"

//============================================================================//
//                                  HELPERS                                    //
//============================================================================//
static void	assertDefaultState(const ClapTrap& clapTrap)
{
	assert(clapTrap.getHitPoints() == 10);
	assert(clapTrap.getEnergyPoints() == 10);
	assert(clapTrap.getAttackDamage() == 0);
}

void	printSection(const std::string& title)
{
	std::cout	<< "------------------------------------------\n"
				<< "--- " << title << "\n"
				<< "------------------------------------------\n";
}

void	printHeader(const std::string& title)
{
	std::cout	<< "===================================================================\n"
				<< "= " << title << "\n"
				<< "===================================================================\n";
}

//============================================================================//
//                                  TEST                                      //
//============================================================================//
static void	testConstructors(void)
{
	printSection("Constructors");
	ClapTrap defaultTrap;
	ClapTrap namedTrap("Named Trap");
	assert(defaultTrap.getName() == "Noname");
	assert(namedTrap.getName() == "Named Trap");
	assertDefaultState(defaultTrap);
	assertDefaultState(namedTrap);
}

static void	testCopyConstructor(void)
{
	printSection("Test Copy Constructor");
	ClapTrap original("Trap");
	ClapTrap copy(original);

	assert(copy.getName() == original.getName());
	assert(copy.getHitPoints() == original.getHitPoints());
	assert(copy.getEnergyPoints() == original.getEnergyPoints());
	assert(copy.getAttackDamage() == original.getAttackDamage());
}

static void	testCopyAssignment(void)
{
	printSection("Test Copy Assignment");
	ClapTrap original("Trap");
	ClapTrap copy;

	copy = original;
	assert(copy.getName() == original.getName());
	assert(copy.getHitPoints() == original.getHitPoints());
	assert(copy.getEnergyPoints() == original.getEnergyPoints());
	assert(copy.getAttackDamage() == original.getAttackDamage());
	copy.operator=(copy);
	assert(copy.getName() == "Trap");
}

static void	testDamage(void)
{
	printSection("Damage Boundaries");
	ClapTrap trap("Damage Trap");
	trap.takeDamage(0);
	assert(trap.getHitPoints() == 10);
	trap.takeDamage(10);
	assert(trap.getHitPoints() == 0);
	trap.takeDamage(1);
	assert(trap.getHitPoints() == 0);
	ClapTrap overkill("Overkill Trap");
	overkill.takeDamage(UINT_MAX);
	assert(overkill.getHitPoints() == 0);
}

static void	testRepair(void)
{
	printSection("Repair Energy and Overflow");
	ClapTrap trap("Repair Trap");
	trap.takeDamage(5);
	trap.beRepaired(2);
	assert(trap.getHitPoints() == 7);
	assert(trap.getEnergyPoints() == 9);
	for (int i = 0; i < 9; ++i)
		trap.beRepaired(0);
	assert(trap.getEnergyPoints() == 0);
	trap.beRepaired(1);
	assert(trap.getHitPoints() == 7);
	assert(trap.getEnergyPoints() == 0);

	ClapTrap overflow("Overflow Trap");
	overflow.takeDamage(1);
	overflow.beRepaired(UINT_MAX);
	assert(overflow.getHitPoints() == UINT_MAX);
}

static void	testDeadBehavior(void)
{
	printSection("Dead ClapTrap Behavior");
	ClapTrap dead("Dead Trap");
	dead.takeDamage(UINT_MAX);
	dead.attack("target");
	dead.beRepaired(1);
	assert(dead.getHitPoints() == 0);
	assert(dead.getEnergyPoints() == 10);
}

void	testClapTrap(void)
{
	printHeader("Test ClapTrap");
	testConstructors();
	testCopyConstructor();
	testCopyAssignment();
	testDamage();
	testRepair();
	testDeadBehavior();
}
