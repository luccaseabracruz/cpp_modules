/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDiamondTrap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:00:00 by lseabra-          #+#    #+#             */
/*   Updated: 2026/09/22 16:04:00 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <limits.h>
#include "tests.hpp"
#include "DiamondTrap.hpp"

//============================================================================//
//                                  HELPERS                                   //
//============================================================================//
static void	assertDefaultState(const DiamondTrap& diamondTrap)
{
	assert(diamondTrap.getHitPoints() == 100);
	assert(diamondTrap.getEnergyPoints() == 50);
	assert(diamondTrap.getAttackDamage() == 30);
}

//============================================================================//
//                                  TEST                                      //
//============================================================================//
static void	testConstructors(void)
{
	printSection("Constructors");
	DiamondTrap defaultTrap;
	DiamondTrap namedTrap("Named DiamondTrap");

	assert(defaultTrap.getName() == "Noname");
	assert(defaultTrap.getClapName() == "Noname_clap_name");
	assert(namedTrap.getName() == "Named DiamondTrap");
	assert(namedTrap.getClapName() == "Named DiamondTrap_clap_name");
	assertDefaultState(defaultTrap);
	assertDefaultState(namedTrap);
}

static void	testCopyConstructor(void)
{
	printSection("Copy Constructor");
	DiamondTrap original("Original");
	original.takeDamage(25);
	original.attack("Target");
	DiamondTrap copy(original);

	assert(copy.getName() == original.getName());
	assert(copy.getClapName() == original.getClapName());
	assert(copy.getHitPoints() == original.getHitPoints());
	assert(copy.getEnergyPoints() == original.getEnergyPoints());
	assert(copy.getAttackDamage() == original.getAttackDamage());
}

static void	testCopyAssignment(void)
{
	printSection("Copy Assignment");
	DiamondTrap original("Original");
	DiamondTrap assigned("Assigned");
	original.takeDamage(25);
	original.attack("Target");

	assigned = original;
	assert(assigned.getName() == original.getName());
	assert(assigned.getClapName() == original.getClapName());
	assert(assigned.getHitPoints() == 75);
	assert(assigned.getEnergyPoints() == 49);
	assert(assigned.getAttackDamage() == 30);
	assigned.operator=(assigned);
	assert(assigned.getName() == "Original");
	assert(assigned.getClapName() == "Original_clap_name");
	assert(assigned.getHitPoints() == 75);
	assert(assigned.getEnergyPoints() == 49);
	assert(assigned.getAttackDamage() == 30);
}

static void	testActionsAndAbilities(void)
{
	printSection("Actions and Abilities");
	DiamondTrap attacker("Attacker");
	DiamondTrap target("Target");

	attacker.attack(target.getName());
	assert(attacker.getEnergyPoints() == 49);
	target.takeDamage(10);
	assert(target.getHitPoints() == 90);
	target.beRepaired(5);
	assert(target.getHitPoints() == 95);
	assert(target.getEnergyPoints() == 49);
	target.guardGate();
	target.highFivesGuys();
	target.whoAmI();
}

static void	testEnergyExhaustion(void)
{
	printSection("Energy Exhaustion");
	DiamondTrap trap("Energy Trap");

	for (int i = 0; i < 50; ++i)
		trap.attack("Target");
	assert(trap.getEnergyPoints() == 0);
	trap.attack("Target");
	assert(trap.getEnergyPoints() == 0);
}

static void	testDamageAndDeadBehavior(void)
{
	printSection("Damage and Dead Behavior");
	DiamondTrap trap("Damage Trap");

	trap.takeDamage(0);
	assert(trap.getHitPoints() == 100);
	trap.takeDamage(100);
	assert(trap.getHitPoints() == 0);
	trap.takeDamage(1);
	assert(trap.getHitPoints() == 0);
	trap.attack("Target");
	trap.beRepaired(50);
	assert(trap.getHitPoints() == 0);

	DiamondTrap overkill("Overkill Trap");
	overkill.takeDamage(UINT_MAX);
	assert(overkill.getHitPoints() == 0);
}

void	testDiamondTrap(void)
{
	printHeader("Test DiamondTrap");
	testConstructors();
	testCopyConstructor();
	testCopyAssignment();
	testActionsAndAbilities();
	testEnergyExhaustion();
	testDamageAndDeadBehavior();
}
