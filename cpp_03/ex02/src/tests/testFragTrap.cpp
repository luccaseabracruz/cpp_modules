/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testFragTrap.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:30:00 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/22 17:40:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <limits.h>
#include "tests.hpp"
#include "FragTrap.hpp"

//============================================================================//
//                                  HELPERS                                   //
//============================================================================//
static void	assertDefaultState(const FragTrap& fragTrap)
{
	assert(fragTrap.getHitPoints() == 100);
	assert(fragTrap.getEnergyPoints() == 100);
	assert(fragTrap.getAttackDamage() == 30);
}

//============================================================================//
//                                  TEST                                      //
//============================================================================//
static void	testConstructors(void)
{
	printSection("Constructors");
	FragTrap defaultTrap;
	FragTrap namedTrap("Named FragTrap");

	assert(defaultTrap.getName() == "Noname");
	assert(namedTrap.getName() == "Named FragTrap");
	assertDefaultState(defaultTrap);
	assertDefaultState(namedTrap);
}

static void	testCopyConstructor(void)
{
	printSection("Copy Constructor");
	FragTrap original("Original");
	original.takeDamage(25);
	original.attack("Target");
	FragTrap copy(original);

	assert(copy.getName() == original.getName());
	assert(copy.getHitPoints() == original.getHitPoints());
	assert(copy.getEnergyPoints() == original.getEnergyPoints());
	assert(copy.getAttackDamage() == original.getAttackDamage());
}

static void	testCopyAssignment(void)
{
	printSection("Copy Assignment");
	FragTrap original("Original");
	FragTrap assigned("Assigned");
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
	assert(assigned.getEnergyPoints() == 99);
	assert(assigned.getAttackDamage() == 30);
}

static void	testActions(void)
{
	printSection("Actions and Ability");
	FragTrap attacker("Attacker");
	FragTrap target("Target");

	attacker.attack(target.getName());
	assert(attacker.getEnergyPoints() == 99);
	target.takeDamage(10);
	assert(target.getHitPoints() == 90);
	target.beRepaired(5);
	assert(target.getHitPoints() == 95);
	assert(target.getEnergyPoints() == 99);
	target.highFivesGuys();
}

static void	testEnergyExhaustion(void)
{
	printSection("Energy Exhaustion");
	FragTrap trap("Energy Trap");

	for (int i = 0; i < 100; ++i)
		trap.attack("Target");
	assert(trap.getEnergyPoints() == 0);
	trap.attack("Target");
	assert(trap.getEnergyPoints() == 0);
}

static void	testDamageAndDeadBehavior(void)
{
	printSection("Damage and Dead Behavior");
	FragTrap trap("Damage Trap");

	trap.takeDamage(0);
	assert(trap.getHitPoints() == 100);
	trap.takeDamage(100);
	assert(trap.getHitPoints() == 0);
	trap.takeDamage(1);
	assert(trap.getHitPoints() == 0);
	trap.attack("Target");
	trap.beRepaired(50);
	assert(trap.getHitPoints() == 0);

	FragTrap overkill("Overkill Trap");
	overkill.takeDamage(UINT_MAX);
	assert(overkill.getHitPoints() == 0);
}

void	testFragTrap(void)
{
	printHeader("Test FragTrap");
	testConstructors();
	testCopyConstructor();
	testCopyAssignment();
	testActions();
	testEnergyExhaustion();
	testDamageAndDeadBehavior();
}
