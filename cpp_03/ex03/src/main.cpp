/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 16:39:25 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

//============================================================================//
//                                  DEBUG                                     //
//============================================================================//

static void	displayInfo(const ClapTrap& clapTrap)
{
	std::cout	<< "INFO\n"
				<< "Name: " << clapTrap.getName() << '\n'
				<< "Hit Points: " << clapTrap.getHitPoints() << '\n'
				<< "Energy Points: " << clapTrap.getEnergyPoints() << '\n'
				<< "Attack Damage: " << clapTrap.getAttackDamage() << '\n';
}

//============================================================================//
//                                  MAIN                                      //
//============================================================================//

int main() {
	std::cout << "--- construction order ---" << '\n';
	std::cout << "> CT" << '\n';
	ClapTrap	clap("Clappy");		// expect ctor order: ClapTrap
	std::cout << "> ST" << '\n';
	ScavTrap	scav("Scavy");		// expect ctor order: ClapTrap -> ScavTrap
	std::cout << "> FT" << '\n';
	FlagTrap	flag("Flaggy");		// expect ctor order: ClapTrap -> FlagTrap
	std::cout << "> DT" << '\n';
	DiamondTrap	diamond("Didi");	// expect ctor order: ClapTrap -> FlagTrap and ScavTrap -> DiamondTrap
	
	std::cout << "--- Objects info ---" << '\n';
	std::cout << "> CT" << '\n';
	displayInfo(clap);				// expect: hp(10) | ep(10) | ad(0)
	std::cout << "> ST" << '\n';
	displayInfo(scav);				// expect: hp(100) | ep(50) | ad(20)
	std::cout << "> FT" << '\n';
	displayInfo(flag);				// expect: hp(100) | ep(100) | ad(30)
	std::cout << "> DT" << '\n';
	displayInfo(diamond);			// expect: hp(100) | ep(50) | ad(30)

	std::cout << "--- copy semantics ---" << '\n';
	DiamondTrap copy(diamond);			// copy constructor
	DiamondTrap assigned("tmp");	// constructor
	assigned = diamond;			// copy assignment operator

	std::cout << "--- basic actions ---" << '\n';
	diamond.attack(flag.getName());	// expect ScavTrap output
	scav.attack(diamond.getName());	// expect ScavTrap output
	flag.attack(diamond.getName());	// expect ClapTrap output
	scav.attack(diamond.getName());	// expect ClapTrap output
	scav.takeDamage(10);

	std::cout << "--- edge cases ---" << '\n';
	for (int i = 0; i < 15; i++)
		diamond.takeDamage(10);		// drive HP to 0 and below, must not go negative, must print "dead"
	diamond.attack(scav.getName());	// Should call ScavTrap message, but cannot attack while dead.
	diamond.beRepaired(50);			// repairing while dead — decide/check expected behavior

	std::cout << "--- destruction order ---" << '\n';
	return (0);					// expect DiamondTrap -> ScavTrap and FlagTrap -> ClapTrap
}
