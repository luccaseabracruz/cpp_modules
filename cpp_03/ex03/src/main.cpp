/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 16:17:18 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main() {
	std::cout << "--- construction order ---" << '\n';
	DiamondTrap rex("Rex");			// expect ClapTrap ctor msg THEN FlagTrap ctor msg
	DiamondTrap raptor("Raptor");	// expect ClapTrap ctor msg THEN FlagTrap ctor msg

	std::cout << "--- copy semantics ---" << '\n';
	FlagTrap copy(rex);			// copy constructor
	FlagTrap assigned("tmp");
	assigned = raptor;			// copy assignment operator

	std::cout << "--- basic actions ---" << '\n';
	rex.attack(raptor.getName());
	raptor.takeDamage(10);
	raptor.beRepaired(5);
	raptor.whoAmI();
	raptor.guardGate();
	raptor.highFivesGuys();

	std::cout << "--- edge cases ---" << '\n';
	for (int i = 0; i < 15; i++)
		rex.takeDamage(10);		// drive HP to 0 and below, must not go negative, must print "dead"
	rex.attack("Dummy");		// Should call ScavTrap message.
	rex.beRepaired(50);			// repairing while dead — decide/check expected behavior

	std::cout << "--- destruction order ---" << '\n';
	return (0);					// expect FlagTrap dtor msg THEN ClapTrap dtor msg
}
