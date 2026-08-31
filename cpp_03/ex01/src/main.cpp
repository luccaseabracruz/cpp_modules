/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:52:04 by lucca             #+#    #+#             */
/*   Updated: 2026/08/31 16:18:55 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main() {
	std::cout << "--- construction order ---" << '\n';
	ScavTrap rex("Rex");			// expect ClapTrap ctor msg THEN ScavTrap ctor msg
	ScavTrap raptor("Raptor");		// expect ClapTrap ctor msg THEN ScavTrap ctor msg

	std::cout << "--- copy semantics ---" << '\n';
	ScavTrap copy(rex);			// copy constructor
	ScavTrap assigned("tmp");
	assigned = raptor;				// copy assignment operator

	std::cout << "--- basic actions ---" << '\n';
	rex.attack(raptor.getName());
	raptor.takeDamage(10);
	raptor.beRepaired(5);
	raptor.guardGate();

	std::cout << "--- edge cases ---" << '\n';
	for (int i = 0; i < 15; i++)
		rex.takeDamage(10);		// drive HP to 0 and below, must not go negative, must print "dead"
	rex.attack("Dummy");			// attacking while dead should do nothing / print dead message
	rex.beRepaired(50);			// repairing while dead — decide/check expected behavior

	std::cout << "--- destruction order ---" << '\n';
	return (0);					// expect ScavTrap dtor msg THEN ClapTrap dtor msg
}
