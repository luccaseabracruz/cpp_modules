/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testScavTrap.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/09/22 15:12:10 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <cassert>
#include "tests.hpp"
#include "ScavTrap.hpp"

//============================================================================//
//                                  HELPERS                                   //
//============================================================================//
static void	assertDefaultState(const ScavTrap& scavTrap)
{
	assert(scavTrap.getHitPoints() == 100);
	assert(scavTrap.getEnergyPoints() == 50);
	assert(scavTrap.getAttackDamage() == 20);
}

//============================================================================//
//                                  TEST                                      //
//============================================================================//
static void	testConstructors(void)
{
	printSection("Constructors");
	const std::string	name = "Named ScavTrap";
	ScavTrap defaultTrap;
	ScavTrap namedTrap(name);

	assert(defaultTrap.getName() == "Noname");
	assert(namedTrap.getName() == name);
	assertDefaultState(defaultTrap);
	assertDefaultState(namedTrap);
}

static void	testCopyConstructor(void)
{
	printSection("Copy Constructor");
	ScavTrap original("Original");
	original.takeDamage(25);
	original.attack("Target");
	ScavTrap copy(original);

	assert(copy.getName() == original.getName());
	assert(copy.getHitPoints() == original.getHitPoints());
	assert(copy.getEnergyPoints() == original.getEnergyPoints());
	assert(copy.getAttackDamage() == original.getAttackDamage());
}

static void	testCopyAssignment(void)
{
	printSection("Copy Assignment");
	ScavTrap original("Original");
	ScavTrap assigned("Assigned");
	original.takeDamage(25);
	original.attack("Target");

	assigned = original;
	assert(assigned.getName() == original.getName());
	assert(assigned.getHitPoints() == original.getHitPoints());
	assert(assigned.getEnergyPoints() == original.getEnergyPoints());
	assert(assigned.getAttackDamage() == original.getAttackDamage());
	assigned.operator=(assigned);
	assert(assigned.getName() == "Original");
	assert(assigned.getHitPoints() == 75);
	assert(assigned.getEnergyPoints() == 49);
	assert(assigned.getAttackDamage() == 20);
}

static void	testActions(void)
{
	printSection("Actions and Ability");
	ScavTrap attacker("Attacker");
	ScavTrap target("Target");

	attacker.attack(target.getName());
	assert(attacker.getEnergyPoints() == 49);
	target.takeDamage(10);
	assert(target.getHitPoints() == 90);
	target.beRepaired(5);
	assert(target.getHitPoints() == 95);
	assert(target.getEnergyPoints() == 49);
	target.guardGate();

	ScavTrap overflow("Overflow Trap");
	overflow.takeDamage(1);
	overflow.beRepaired(UINT_MAX);
	assert(overflow.getHitPoints() == UINT_MAX);
	assert(overflow.getEnergyPoints() == 49);
}

static void	testEnergyExhaustion(void)
{
	printSection("Energy Exhaustion");
	ScavTrap trap("Energy Trap");

	for (int i = 0; i < 50; ++i)
		trap.attack("Target");
	assert(trap.getEnergyPoints() == 0);
	trap.attack("Target");
	assert(trap.getEnergyPoints() == 0);
}

static void	testDamageAndDeadBehavior(void)
{
	printSection("Damage and Dead Behavior");
	ScavTrap trap("Damage Trap");

	trap.takeDamage(0);
	assert(trap.getHitPoints() == 100);
	trap.takeDamage(100);
	assert(trap.getHitPoints() == 0);
	trap.takeDamage(1);
	assert(trap.getHitPoints() == 0);
	trap.attack("Target");
	trap.beRepaired(50);
	assert(trap.getHitPoints() == 0);

	ScavTrap overkill("Overkill Trap");
	overkill.takeDamage(UINT_MAX);
	assert(overkill.getHitPoints() == 0);
}

void	testScavTrap(void)
{
	printHeader("Test ScavTrap");
	testConstructors();
	testCopyConstructor();
	testCopyAssignment();
	testActions();
	testEnergyExhaustion();
	testDamageAndDeadBehavior();
	std::cout << "SUCCESS :)\n";
}
